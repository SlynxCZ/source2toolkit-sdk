/**
 * This project has been copied & modified from the demofile-net project under the MIT license.
 * See ACKNOWLEDGEMENTS file for more information.
 * https://github.com/saul/demofile-net
 */

using System.Collections.Immutable;
using System.Text;
using System.Text.Json;
using QuickGraph;
using QuickGraph.Algorithms.Search;

namespace Source2Toolkit.SchemaGen;

internal static partial class Program
{
    private static readonly IReadOnlySet<string> IgnoreClasses = new HashSet<string>
    {
        "GameTime_t",
        "GameTick_t",
        "AttachmentHandle_t",
        "CGameSceneNodeHandle",
        "HSequence",
        "CAttributeManager::cached_attribute_float_t",
        "QuestProgress::Reason",
        "IChoreoServices::ScriptState_t",
        "IChoreoServices::ChoreoState_t",
        "SpawnPointCoopEnemy::BotDefaultBehavior_t",
        "CLogicBranchList::LogicBranchListenerLastState_t",
        "SimpleConstraintSoundProfile::SimpleConstraintsSoundProfileKeypoints_t",
        "MoodAnimationLayer_t",
        "SoundeventPathCornerPairNetworked_t",
        "AISound_t",
        "CAttachmentNameSymbolWithStorage",
        "CAnimGraph2ParamAutoResetOptionalRef"
    };

    private static readonly IReadOnlySet<string> IgnoreClassWildcards = new HashSet<string>
    {
        "CResourceNameTyped",
        "CEntityOutputTemplate",
        "CVariantBase",
        "HSCRIPT",
        "KeyValues3",
        "Unknown",
        "CUtlOrderedMap",
        "CAnimGraph2ParamOptionalRef",
        "CUtlHashtable",
        "CSmartPtr"
    };

    private static readonly HashSet<string> HardSkipClasses = new()
    {
        "CEntityComponent",
        "CEntityIOOutput",
        "CEntityIdentity",
        "CEntityInstance"
    };

    private static readonly HashSet<string> HardSkipEnums = new()
    {
        "HitGroup_t",
        "MoveCollide_t",
        "MoveType_t",
        "RenderFx_t",
        "RenderMode_t",
        "SolidType_t"
    };

    public static string SanitiseTypeName(string typeName) =>
        typeName.Replace(":", "")
            .Replace("< ", "<")
            .Replace(" >", ">");

    private static bool ContainsIgnoredType(SchemaFieldType type)
    {
        if (IgnoreClasses.Contains(type.Name))
            return true;

        if (type.Inner != null)
            return ContainsIgnoredType(type.Inner);

        return false;
    }

    private static (Dictionary<string, SchemaEnum>, Dictionary<string, SchemaClass>) ConvertNewSchemaToOld(
        NewSchemaModule newSchema)
    {
        var enums = new Dictionary<string, SchemaEnum>();
        var classes = new Dictionary<string, SchemaClass>();

        var defLookup = newSchema.defs.Select((def, idx) => new { def, idx }).ToDictionary(x => x.idx, x => x.def);

        for (int i = 0; i < newSchema.defs.Length; i++)
        {
            var def = newSchema.defs[i];
            if (def.type == "enum" && def.traits?.fields != null)
            {
                var enumItems = def.traits.fields.Select(f => new SchemaEnumItem(f.name, f.value)).ToList();
                enums[def.name] = new SchemaEnum(def.alignment ?? 4, enumItems);
            }
        }

        for (int i = 0; i < newSchema.defs.Length; i++)
        {
            var def = newSchema.defs[i];
            if (def.type == "class" && def.traits != null)
            {
                string? parentName = null;

                if (def.traits.baseclasses != null && def.traits.baseclasses.Length > 0)
                {
                    var parentIdx = def.traits.baseclasses[0].ref_idx;
                    if (defLookup.TryGetValue(parentIdx, out var parentDef))
                    {
                        parentName = parentDef.name;
                    }
                }

                var fields = new List<SchemaField>();

                if (def.traits.members != null)
                {
                    foreach (var member in def.traits.members)
                    {
                        if (member.traits?.subtype != null)
                        {
                            var fieldType = ConvertSubtypeToFieldType(member.traits.subtype, defLookup);
                            var metadata = member.traits.metatags?.ToDictionary(m => m.name, m => m.value ?? "") ??
                                           new Dictionary<string, string>();
                            fields.Add(new SchemaField(member.name, fieldType, metadata));
                        }
                    }
                }

                classes[def.name] = new SchemaClass(i, def.name, parentName, fields);
            }
        }

        return (enums, classes);
    }

    private static SchemaFieldType ConvertSubtypeToFieldType(SchemaSubtype subtype,
        Dictionary<int, SchemaDef> defLookup)
    {
        if (subtype.type == "ref" && subtype.ref_idx.HasValue)
        {
            if (defLookup.TryGetValue(subtype.ref_idx.Value, out var referencedDef))
            {
                return ConvertSubtypeToFieldType(new SchemaSubtype(
                    referencedDef.type == "class"
                        ? "declared_class"
                        : (referencedDef.type == "enum" ? "declared_enum" : referencedDef.type),
                    referencedDef.name,
                    referencedDef.size,
                    referencedDef.alignment,
                    null,
                    null,
                    null,
                    null,
                    null
                ), defLookup);
            }
        }

        SchemaTypeCategory category = subtype.type switch
        {
            "builtin" => SchemaTypeCategory.Builtin,
            "atomic" => SchemaTypeCategory.Atomic,
            "ptr" => SchemaTypeCategory.Ptr,
            "fixed_array" => SchemaTypeCategory.FixedArray,
            "declared_class" => SchemaTypeCategory.DeclaredClass,
            "declared_enum" => SchemaTypeCategory.DeclaredEnum,
            "bitfield" => SchemaTypeCategory.Bitfield,
            _ => SchemaTypeCategory.None
        };

        SchemaAtomicCategory? atomic = null;
        if (subtype.type == "atomic" && subtype.name != null)
        {
            if (subtype.name.Contains("CUtlVector") || subtype.name.Contains("CNetworkUtlVectorBase"))
            {
                atomic = SchemaAtomicCategory.Collection;
            }
            else if (subtype.name.Contains("CHandle") || subtype.name.Contains("CWeakHandle"))
            {
                atomic = SchemaAtomicCategory.T;
            }
            else
            {
                atomic = SchemaAtomicCategory.Basic;
            }
        }

        SchemaFieldType? innerType = null;

        if (subtype.template != null && subtype.template.Length > 0)
        {
            innerType = ConvertSubtypeToFieldType(subtype.template[0], defLookup);
        }
        else if (subtype.subtype != null)
        {
            innerType = ConvertSubtypeToFieldType(subtype.subtype, defLookup);
        }

        string typeName = subtype.name ?? "unknown";
        if (category == SchemaTypeCategory.FixedArray && subtype.count.HasValue && innerType != null)
        {
            typeName = $"{innerType.Name}[{subtype.count.Value}]";
        }

        return new SchemaFieldType(
            typeName,
            category,
            atomic,
            innerType
        );
    }

    public static void Main(string[] args)
    {
        var outputPath = args.FirstOrDefault() ?? "../../../../../src/schema/entity";

        // Concat together all enums and classes
        var allEnums = new SortedDictionary<string, SchemaEnum>();
        var allClasses = new SortedDictionary<string, SchemaClass>();

        var schemaFiles = new[] { "server.json" };

        foreach (var schemaFile in schemaFiles)
        {
            var schemaPath = Path.Combine(AppDomain.CurrentDomain.BaseDirectory, "../../../", schemaFile);

            var newSchema = JsonSerializer.Deserialize<NewSchemaModule>(
                File.ReadAllText(schemaPath),
                SerializerOptions)!;

            var (enums, classes) = ConvertNewSchemaToOld(newSchema);

            foreach (var (enumName, schemaEnum) in enums)
            {
                if (IgnoreClasses.Contains(enumName))
                    continue;

                allEnums[enumName] = schemaEnum;
            }

            foreach (var (className, schemaClass) in classes)
            {
                if (IgnoreClasses.Contains(className))
                    continue;

                allClasses[className] = schemaClass with { Name = className };
            }
        }

        var parentToChildMap = allClasses.Where(kvp => kvp.Value.Parent != null)
            .GroupBy(kvp => kvp.Value.Parent!)
            .ToDictionary(g => g.Key, g => g.ToImmutableList());

        // Generate graph of classes -> fields
        var graph = new AdjacencyGraph<string, Edge<string>>();

        // Types used as pointers
        var pointeeTypes = new HashSet<string>();

        foreach (var (className, schemaClass) in allClasses)
        {
            if (schemaClass.Parent != null)
                graph.AddVerticesAndEdge(new Edge<string>(className, schemaClass.Parent));

            foreach (var field in schemaClass.Fields)
            {
                var currentType = field.Type;
                while (currentType != null)
                {
                    if (currentType.IsDeclared)
                    {
                        graph.AddVerticesAndEdge(new Edge<string>(className, currentType.Name));
                    }

                    currentType = currentType.Inner;
                }

                // Pointers mean we need to add references to the child classes of referenced type
                if (field.Type.Category == SchemaTypeCategory.Ptr)
                {
                    var childClasses = parentToChildMap.GetValueOrDefault(
                        field.Type.Inner!.Name,
                        ImmutableList<KeyValuePair<string, SchemaClass>>.Empty);

                    var queue = new Queue<(string, string)>(childClasses.Select(x => (className, x.Key)));

                    while (queue.Count > 0)
                    {
                        var (parent, childClass) = queue.Dequeue();

                        graph.AddVerticesAndEdge(new Edge<string>(parent, childClass));

                        var myChildren = parentToChildMap.GetValueOrDefault(
                            childClass,
                            ImmutableList<KeyValuePair<string, SchemaClass>>.Empty);
                        foreach (var (toAdd, _) in myChildren)
                        {
                            queue.Enqueue((childClass, toAdd));
                        }
                    }

                    pointeeTypes.Add(field.Type.Inner!.Name);
                }
            }
        }

        // Do a search from NetworkClasses.Names
        var visited = new HashSet<string>();
        var search = new BreadthFirstSearchAlgorithm<string, Edge<string>>(graph);
        search.FinishVertex += node => { visited.Add(node); };

        foreach (var networkClassName in NetworkClasses.Names)
        {
            search.Compute(networkClassName);
        }

        // Clear output directory
        if (Directory.Exists(outputPath))
        {
            foreach (var file in Directory.EnumerateFiles(outputPath, "*", SearchOption.AllDirectories))
            {
                if (Path.GetExtension(file) == ".h")
                {
                    File.Delete(file);
                }
            }
        }

        Directory.CreateDirectory(Path.Combine(outputPath, "enums"));
        Directory.CreateDirectory(Path.Combine(outputPath, "classes"));

        foreach (var (enumName, schemaEnum) in allEnums)
        {
            if (HardSkipEnums.Contains(enumName))
                continue;

            var builder = new StringBuilder();
            builder.AppendLine("#pragma once");
            builder.AppendLine("#include <cstdint>");
            builder.AppendLine();

            WriteEnum(builder, enumName, schemaEnum);

            File.WriteAllText(
                Path.Combine(outputPath, "enums", $"{SanitiseTypeName(enumName)}.h"),
                builder.ToString().ReplaceLineEndings("\r\n"));
        }

        // Manually whitelist some classes
        visited.Add("CTakeDamageInfo");
        visited.Add("CTakeDamageResult");
        visited.Add("CEntitySubclassVDataBase");
        visited.Add("CFiringModeFloat");
        visited.Add("CFiringModeInt");
        visited.Add("CSkillFloat");
        visited.Add("CSkillInt");
        visited.Add("CRangeFloat");
        visited.Add("CNavLinkAnimgraphVar");
        visited.Add("DecalGroupOption_t");
        visited.Add("DestructibleHitGroupToDestroy_t");

        foreach (var (className, schemaClass) in allClasses)
        {
            if (HardSkipClasses.Contains(className))
                continue;

            if (!visited.Contains(className) && !className.Contains("VData"))
                continue;

            var builder = new StringBuilder();
            WriteClass(builder, className, schemaClass, allEnums, allClasses);

            File.WriteAllText(
                Path.Combine(outputPath, "classes", $"{SanitiseTypeName(className)}.h"),
                builder.ToString().ReplaceLineEndings("\r\n"));
        }
    }

    private static IEnumerable<(SchemaClass clazz, SchemaField field)> GetAllParentFields(
        SchemaClass schemaClass,
        SortedDictionary<string, SchemaClass> allClasses)
    {
        while (schemaClass.Parent != null)
        {
            allClasses.TryGetValue(schemaClass.Parent, out var parentClass);
            if (parentClass == null)
                break;

            foreach (var field in parentClass.Fields)
            {
                yield return (parentClass, field);
            }

            schemaClass = parentClass;
        }
    }

    private static readonly JsonSerializerOptions SerializerOptions = new()
    {
        PropertyNamingPolicy = JsonNamingPolicy.CamelCase,
        AllowTrailingCommas = true
    };

    private static void CollectReferencedTypes(
        SchemaFieldType type,
        HashSet<string> includes,
        HashSet<string> forwards,
        bool isPointerContext)
    {
        if (type.Category == SchemaTypeCategory.DeclaredEnum &&
            HardSkipEnums.Contains(type.Name))
        {
            return;
        }

        bool isHandleTemplate =
            type.Atomic == SchemaAtomicCategory.T;

        bool isCollectionTemplate =
            type.Atomic == SchemaAtomicCategory.Collection;

        if (type.IsDeclared && !HardSkipClasses.Contains(type.Name))
        {
            if (isPointerContext || isHandleTemplate)
            {
                forwards.Add(type.Name);
            }
            else
            {
                includes.Add(type.Name);
            }
        }

        if (type.Inner != null)
        {
            bool innerIsPointer = type.Category == SchemaTypeCategory.Ptr || isHandleTemplate;

            CollectReferencedTypes(
                type.Inner,
                includes,
                forwards,
                innerIsPointer);
        }
    }

    private static void CollectTypesFromMethods(
        IEnumerable<string> methods,
        IReadOnlyDictionary<string, SchemaEnum> allEnums,
        IReadOnlyDictionary<string, SchemaClass> allClasses,
        HashSet<string> includes,
        HashSet<string> forwards)
    {
        foreach (var method in methods)
        {
            foreach (var clazz in allClasses.Keys)
            {
                if (method.Contains(clazz))
                {
                    if (!includes.Contains(clazz))
                        forwards.Add(clazz);
                }
            }

            foreach (var enm in allEnums.Keys)
            {
                if (method.Contains(enm))
                {
                    includes.Add(enm);
                }
            }
        }
    }

    private static bool InheritsFromBaseEntity(
        string className,
        IReadOnlyDictionary<string, SchemaClass> allClasses)
    {
        while (true)
        {
            if (!allClasses.TryGetValue(className, out var clazz))
                return false;

            if (clazz.Parent == null)
                return false;

            if (clazz.Parent == "CBaseEntity")
                return true;

            className = clazz.Parent;
        }
    }

    private static void WriteClass(
        StringBuilder builder,
        string className,
        SchemaClass schemaClass,
        IReadOnlyDictionary<string, SchemaEnum> allEnums,
        IReadOnlyDictionary<string, SchemaClass> allClasses)
    {
        var includes = new HashSet<string>();
        var forwards = new HashSet<string>();

        // Parent MUST be include
        if (schemaClass.Parent != null &&
            !HardSkipClasses.Contains(schemaClass.Parent))
        {
            includes.Add(schemaClass.Parent);
        }

        foreach (var field in schemaClass.Fields)
        {
            if (field.Type.Category == SchemaTypeCategory.Bitfield ||
                IgnoreClassWildcards.Any(y => field.Type.Name.Contains(y)))
                continue;

            if (ContainsIgnoredType(field.Type))
                continue;

            CollectReferencedTypes(
                field.Type,
                includes,
                forwards,
                field.Type.Category == SchemaTypeCategory.Ptr);
        }

        if (CustomMethods.ManualMethods.TryGetValue(className, out var methods))
        {
            CollectTypesFromMethods(methods, allEnums, allClasses, includes, forwards);
        }

        includes.Remove(className);
        forwards.Remove(className);

        forwards.ExceptWith(includes);

        builder.AppendLine("#pragma once");
        if ((className == "CBaseEntity" || InheritsFromBaseEntity(className, allClasses)) && className != "CBaseEntity")
        {
            builder.AppendLine("#include \"CBaseEntity.h\"");
        }
        builder.AppendLine("#include \"igameevents.h\"");
        builder.AppendLine("#include \"ehandle.h\"");
        builder.AppendLine("#include \"entityhandle.h\"");
        builder.AppendLine("#include \"vector.h\"");
        builder.AppendLine("#include \"utlsymbol.h\"");
        builder.AppendLine("#include \"utlsymbollarge.h\"");
        builder.AppendLine("#include \"utlstring.h\"");
        builder.AppendLine("#include \"utlstringtoken.h\"");
        builder.AppendLine("#include \"schema/entityio.h\"");
        builder.AppendLine("#include \"schema/schema.h\"");
        builder.AppendLine("#include <cstdint>");
        builder.AppendLine();

        // Includes
        foreach (var inc in includes.OrderBy(x => x))
        {
            if (allEnums.ContainsKey(inc) && !HardSkipEnums.Contains(inc))
            {
                builder.AppendLine($"#include \"../enums/{SanitiseTypeName(inc)}.h\"");
            }
            else if (allClasses.ContainsKey(inc))
            {
                builder.AppendLine($"#include \"{SanitiseTypeName(inc)}.h\"");
            }
        }

        if (includes.Count > 0)
            builder.AppendLine();

        // Forward declarations
        foreach (var fwd in forwards.OrderBy(x => x))
        {
            builder.AppendLine($"class {fwd};");
        }

        if (forwards.Count > 0)
            builder.AppendLine();

        bool inheritsFromBaseEntity =
            className == "CBaseEntity" ||
            InheritsFromBaseEntity(className, allClasses);

        if (className == "CBaseEntity")
        {
            builder.AppendLine(
                $"class {className}" +
                (schemaClass.Parent != null
                    ? $" : public {schemaClass.Parent}"
                    : ""));
        }
        else if (schemaClass.Parent != null)
        {
            builder.AppendLine(
                $"class {className} : public {schemaClass.Parent}");
        }
        else
        {
            if (inheritsFromBaseEntity)
            {
                builder.AppendLine(
                    $"class {className} : public CBaseEntity::Factory<{className}>");
            }
            else
            {
                builder.AppendLine(
                    $"class {className}");
            }
        }

        builder.AppendLine("{");
        builder.AppendLine("public:");
        builder.AppendLine($"    DECLARE_SCHEMA_CLASS({className});");
        builder.AppendLine();

        foreach (var field in schemaClass.Fields)
        {
            if (field.Type.Category == SchemaTypeCategory.Bitfield ||
                IgnoreClassWildcards.Any(y => field.Type.Name.Contains(y)))
                continue;

            if (ContainsIgnoredType(field.Type))
                continue;

            if (field.Type.Category == SchemaTypeCategory.FixedArray ||
                field.Type.Name == "CUtlStringToken")
            {
                builder.AppendLine(
                    $"    SCHEMA_FIELD_POINTER({field.Type.CppTypeName}, {field.Name});");
            }
            else
            {
                builder.AppendLine(
                    $"    SCHEMA_FIELD({field.Type.CppTypeName}, {field.Name});");
            }
        }

        if (CustomMethods.ManualMethods.TryGetValue(className, out methods))
        {
            builder.AppendLine();
            builder.AppendLine("public:");

            foreach (var method in methods)
            {
                builder.AppendLine($"    {method}");
            }
        }

        if (inheritsFromBaseEntity && className != "CBaseEntity")
        {
            builder.AppendLine();
            builder.AppendLine("public:");
            builder.AppendLine($"    static {className}* New(const char* className)");
            builder.AppendLine("    {");
            builder.AppendLine($"        return CBaseEntity::New<{className}>(className);");
            builder.AppendLine("    }");
            builder.AppendLine();
            builder.AppendLine($"    static {className}* FromIndex(int iIndex)");
            builder.AppendLine("    {");
            builder.AppendLine($"        return CBaseEntity::FromIndex<{className}>(iIndex);");
            builder.AppendLine("    }");
            builder.AppendLine();
            builder.AppendLine($"    static {className}* FromIndex(CEntityIndex index)");
            builder.AppendLine("    {");
            builder.AppendLine("        return FromIndex(index.Get());");
            builder.AppendLine("    }");
        }

        builder.AppendLine("};");
    }

    private static string EnumTypeCpp(int align, IReadOnlyList<SchemaEnumItem> items)
    {
        bool isSigned = items.Any(x => x.Value < 0);

        return (align, isSigned) switch
        {
            (1, true) => "int8_t",
            (1, false) => "uint8_t",
            (2, true) => "int16_t",
            (2, false) => "uint16_t",
            (4, true) => "int32_t",
            (4, false) => "uint32_t",
            (8, true) => "int64_t",
            (8, false) => "uint64_t",
            _ => "int32_t"
        };
    }

    private static void WriteEnum(
        StringBuilder builder,
        string enumName,
        SchemaEnum schemaEnum)
    {
        builder.AppendLine($"enum class {enumName} : {EnumTypeCpp(schemaEnum.Align, schemaEnum.Items)}");
        builder.AppendLine("{");

        foreach (var item in schemaEnum.Items)
        {
            builder.AppendLine($"    {item.Name} = {item.Value},");
        }

        builder.AppendLine("};");
    }
}