namespace Source2Toolkit.SchemaGen;

public record SchemaModule(
    IReadOnlyDictionary<string, SchemaEnum> Enums,
    IReadOnlyDictionary<string, SchemaClass> Classes);
