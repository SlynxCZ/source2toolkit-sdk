"""
Source2Toolkit
Copyright (C) 2025-2026 Michal "Slynx (˙·٠● S l y n x ●٠·˙)" Přikryl,
AlliedModders LLC. All rights reserved.

This program is free software; you can redistribute it and/or modify it under
the terms of the GNU General Public License, version 3.0, as published by the
Free Software Foundation.

This program is distributed in the hope that it will be useful, but WITHOUT
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
details.

You should have received a copy of the GNU General Public License along with
this program. If not, see <http://www.gnu.org/licenses/>.

As a special exception, Michal "Slynx (˙·٠● S l y n x ●٠·˙)" Přikryl and
AlliedModders LLC give you permission to link the code of this program
(as well as its derivative works) to "Counter-Strike 2," "Source 2,"
"Steam," and any Game MODs or server software running on software by
Valve Corporation. You must obey the GNU General Public License in all
respects for all other code used.

Additionally, this exception applies to all derivative works unless
otherwise stated in LICENSE.txt.

Authors:
    - Michal "Slynx (˙·٠● S l y n x ●٠·˙)" Přikryl
    - AlliedModders LLC

Project: Source2Toolkit

Public schemagen - generates pure virtual IXxx interface headers (SDK) and
CXxxImpl implementation headers (core).

Reads server.json from schemagen_core (sibling directory in core repo).

Usage:
    python generator.py [sdk_output] [core_output]

    sdk_output   Base path for SDK public outputs (enums/ and classes/ written here).
                 Default: ../../public/source2toolkit/schema/entity

    core_output  Base path for core-private outputs (classes/ written here).
                 Default: ../../../source2toolkit/src/schema/entity
"""

from __future__ import annotations

import json
import os
import re
import sys
from typing import Optional

# ---------------------------------------------------------------------------
# Import shared schema model from schemagen_core
# ---------------------------------------------------------------------------

_SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.join(_SCRIPT_DIR, "../../..", "source2toolkit/tools/", "schemagen_core"))

from generator import (  # noqa: E402
    SchemaTypeCategory,
    SchemaAtomicCategory,
    SchemaFieldType,
    SchemaField,
    SchemaClass,
    SchemaEnum,
    _parse_schema_defs,
    convert_new_schema_to_old,
    build_graph_and_bfs,
    NETWORK_CLASSES,
    EXTRA_WHITELIST,
    HARD_SKIP_CLASSES,
    HARD_SKIP_ENUMS,
    IGNORE_CLASSES,
    IGNORE_CLASS_WILDCARDS,
    contains_ignored_type,
    _field_has_ignored_wildcard,
    sanitise_type_name,
    collect_referenced_types,
    inherits_from_base_entity,
    LICENSE_HEADER,
    make_header_guard,
    write_enum,
    MANUAL_METHODS,
)

# ---------------------------------------------------------------------------
# Hungarian notation stripping
# ---------------------------------------------------------------------------

_HUNGARIAN_RE = re.compile(
    r"^(isz|vec|arr|ang|clr|bv|ub|un|us|af|fl|ch|sz|a|n|i|b|f|h|q|p|v|e|u|s)([A-Z])"
)


def to_pascal_case(field_name: str) -> str:
    name = field_name
    if name.startswith("m_"):
        name = name[2:]
    m = _HUNGARIAN_RE.match(name)
    if m:
        name = name[len(m.group(1)):]
    if name and name[0].islower():
        name = name[0].upper() + name[1:]
    return name


# ---------------------------------------------------------------------------
# Field categorisation helpers
# ---------------------------------------------------------------------------

def _is_pointer_field(field: SchemaField) -> bool:
    return (
        field.type.category == SchemaTypeCategory.FixedArray
        or field.type.name == "CUtlStringToken"
    )


def _virtual_return_type(field: SchemaField) -> str:
    if _is_pointer_field(field):
        return f"{field.type.cpp_type_name}*"
    return f"{field.type.cpp_type_name}&"


# ---------------------------------------------------------------------------
# Effective parent resolution
# ---------------------------------------------------------------------------

def _is_entity_class(class_name: str) -> bool:
    return len(class_name) >= 2 and class_name[0] == "C" and class_name[1].isupper()


def _interface_name(class_name: str) -> str:
    if _is_entity_class(class_name):
        return "I" + class_name[1:]
    return "I" + class_name


def _effective_parent(
    schema_class: SchemaClass,
    generated: set[str],
) -> Optional[str]:
    p = schema_class.parent
    if p is None or p in HARD_SKIP_CLASSES or p not in generated:
        return None
    if not _is_entity_class(p):
        return None
    return p


# Game SDK headers always included in interface files
_IFACE_SDK_INCLUDES = [
    '#include "igameevents.h"',
    '#include "ehandle.h"',
    '#include "entityhandle.h"',
    '#include "vector.h"',
    '#include "utlsymbol.h"',
    '#include "utlsymbollarge.h"',
    '#include "utlstring.h"',
    '#include "utlstringtoken.h"',
    '#include "source2toolkit/IToolkitTypes.h"',
    '#include "source2toolkit/schema/entityio.h"',
    "#include <cstdint>",
]

# Extra forward declarations needed in IXxx headers for non-schema types
# referenced by manual methods (types not found in all_classes via substring scan).
_EXTRA_IFACE_FWD_DECLS: dict[str, list[str]] = {
    "CBaseEntity": [
        "CEntityInstance",
        "CEntityIOListenerHandle",
        "CEntitySubclassVDataBase",
        "CEntityKeyValues",
    ],
    "CBasePlayerController": ["CBasePlayerPawn"],
    "CBasePlayerPawn": ["CBasePlayerWeapon"],
    "CBasePlayerWeapon": ["CCSWeaponBaseVData"],
    "CCSGameRules": ["CBasePlayerController", "CCSPlayerController"],
    "CCSPlayerController": ["CCSPlayerPawn", "CCSObserverPawn"],
    "CCSPlayerPawn": ["CCSPlayerController"],
    "CCSPlayer_ItemServices": ["CBasePlayerWeapon"],
    "CCSPlayer_WeaponServices": ["CBasePlayerWeapon"],
    "CPlayerControllerComponent": ["CCSPlayerController"],
    "CPlayerPawnComponent": ["CCSPlayerPawn"],
}

# Extra raw #include lines to inject into IXxx headers for non-schema types.
_EXTRA_IFACE_INCLUDES: dict[str, list[str]] = {
    "CBaseEntity": ["#include <functional>"],
}


# ---------------------------------------------------------------------------
# Manual method string parsing
# ---------------------------------------------------------------------------

def _split_param_list(params_str: str) -> list[str]:
    """Split comma-separated params respecting <> and () nesting."""
    params: list[str] = []
    angle_depth = 0
    paren_depth = 0
    current = ""
    for ch in params_str:
        if ch == "<":
            angle_depth += 1
            current += ch
        elif ch == ">":
            angle_depth -= 1
            current += ch
        elif ch == "(":
            paren_depth += 1
            current += ch
        elif ch == ")":
            paren_depth -= 1
            current += ch
        elif ch == "," and angle_depth == 0 and paren_depth == 0:
            params.append(current.strip())
            current = ""
        else:
            current += ch
    if current.strip():
        params.append(current.strip())
    return params


def _param_arg_name(param: str) -> str:
    eq_idx = param.find(" = ")
    if eq_idx != -1:
        param = param[:eq_idx]
    return param.split()[-1].lstrip("*&")


def _param_no_default(param: str) -> str:
    eq_idx = param.find(" = ")
    if eq_idx != -1:
        return param[:eq_idx].strip()
    return param.strip()


def _parse_manual_method(method_str: str) -> Optional[dict]:
    """Parse a raw method declaration string from MANUAL_METHODS.

    Returns None for comments, static methods, and templates
    (none of which can be pure virtual interface methods).
    """
    s = method_str.strip()

    if s.startswith("//"):
        return None
    if s.startswith("static ") or re.match(r"static\s", s):
        return None
    if s.startswith("template"):
        return None

    s = s.rstrip(";").strip()

    is_const = False
    if s.endswith(" const"):
        is_const = True
        s = s[:-6].rstrip()

    paren_pos = s.find("(")
    if paren_pos == -1:
        return None

    # Find matching closing paren
    depth = 0
    close_pos = -1
    for i in range(paren_pos, len(s)):
        if s[i] == "(":
            depth += 1
        elif s[i] == ")":
            depth -= 1
            if depth == 0:
                close_pos = i
                break
    if close_pos == -1:
        return None

    params_str = s[paren_pos + 1 : close_pos].strip()
    sig_prefix = s[:paren_pos].strip()

    tokens = sig_prefix.split()
    if len(tokens) < 2:
        return None

    name = tokens[-1].lstrip("*&")
    return_type = " ".join(tokens[:-1])

    raw_params = _split_param_list(params_str) if params_str else []

    return {
        "return_type": return_type,
        "name": name,
        "params_with_defaults": [p.strip() for p in raw_params],
        "params_no_defaults": [_param_no_default(p) for p in raw_params],
        "args": [_param_arg_name(p) for p in raw_params],
        "is_const": is_const,
    }


def _manual_method_virtual_decl(m: dict) -> str:
    const = " const" if m["is_const"] else ""
    params = ", ".join(m["params_with_defaults"])
    return f"    virtual {m['return_type']} {m['name']}({params}){const} = 0;"


def _manual_method_override_impl(m: dict) -> str:
    const = " const" if m["is_const"] else ""
    params = ", ".join(m["params_no_defaults"])
    args = ", ".join(m["args"])
    if m["return_type"] == "void":
        body = "{ Real()->" + m["name"] + "(" + args + "); }"
    else:
        body = "{ return Real()->" + m["name"] + "(" + args + "); }"
    return f"    {m['return_type']} {m['name']}({params}){const} override {body}"


# ---------------------------------------------------------------------------
# Interface header generation
# ---------------------------------------------------------------------------

def _collect_interface_refs(
    t: SchemaFieldType,
    all_enums: dict[str, SchemaEnum],
    enum_includes: set[str],
    forwards: set[str],
) -> None:
    if t.category == SchemaTypeCategory.DeclaredEnum:
        if t.name not in HARD_SKIP_ENUMS:
            enum_includes.add(t.name)
    elif t.category == SchemaTypeCategory.DeclaredClass:
        if t.name not in HARD_SKIP_CLASSES:
            forwards.add(t.name)
    if t.inner is not None:
        _collect_interface_refs(t.inner, all_enums, enum_includes, forwards)


def write_interface_header(
    class_name: str,
    schema_class: SchemaClass,
    all_enums: dict[str, SchemaEnum],
    all_classes: dict[str, SchemaClass],
    generated: set[str],
) -> str:
    """Generate IFoo.h - a pure virtual interface for class_name."""

    i_class_name = _interface_name(class_name)
    parent = _effective_parent(schema_class, generated)
    i_parent_name = _interface_name(parent) if parent else None

    enum_includes: set[str] = set()
    forwards: set[str] = set()

    # Collect from schema fields
    for f in schema_class.fields:
        if f.type.category == SchemaTypeCategory.Bitfield:
            continue
        if _field_has_ignored_wildcard(f.type):
            continue
        if contains_ignored_type(f.type):
            continue
        _collect_interface_refs(f.type, all_enums, enum_includes, forwards)

    # Collect from manual methods: scan strings for known schema class/enum names
    for method_str in MANUAL_METHODS.get(class_name, []):
        for enum_name in all_enums:
            if enum_name not in HARD_SKIP_ENUMS and enum_name in method_str:
                enum_includes.add(enum_name)
        for cls_name in all_classes:
            if cls_name not in HARD_SKIP_CLASSES and cls_name in method_str:
                forwards.add(cls_name)

    # Extra forward declarations for non-schema types
    for fwd in _EXTRA_IFACE_FWD_DECLS.get(class_name, []):
        forwards.add(fwd)

    forwards.discard(class_name)

    guard = make_header_guard(i_class_name)
    lines = [
        f"#ifndef {guard}",
        f"#define {guard}",
        "",
        "#pragma once",
        "",
    ]

    lines += _IFACE_SDK_INCLUDES

    # Extra includes (e.g. <functional> for std::function)
    extra_incs = _EXTRA_IFACE_INCLUDES.get(class_name, [])
    if extra_incs:
        for inc in extra_incs:
            lines.append(inc)
    lines.append("")

    if i_parent_name:
        lines.append(f'#include "{i_parent_name}.h"')
        lines.append("")

    for e in sorted(enum_includes):
        lines.append(f'#include "../enums/{sanitise_type_name(e)}.h"')
    if enum_includes:
        lines.append("")

    for fwd in sorted(forwards):
        lines.append(f"class {fwd};")
    if forwards:
        lines.append("")

    if i_parent_name:
        lines.append(f"class {i_class_name} : public virtual {i_parent_name}")
    else:
        lines.append(f"class {i_class_name}")

    lines += ["{", "public:", f"    virtual ~{i_class_name}() = default;", ""]

    # Schema field pure virtuals
    for f in schema_class.fields:
        if f.type.category == SchemaTypeCategory.Bitfield:
            continue
        if _field_has_ignored_wildcard(f.type):
            continue
        if contains_ignored_type(f.type):
            continue

        method_name = to_pascal_case(f.name)
        ret = _virtual_return_type(f)
        lines.append(f"    virtual {ret} {method_name}() = 0;")
        if not _is_pointer_field(f):
            lines.append(f"    virtual void {method_name}Updated() = 0;")

    # Manual method pure virtuals
    parsed_manual = [_parse_manual_method(m) for m in MANUAL_METHODS.get(class_name, [])]
    parsed_manual = [m for m in parsed_manual if m is not None]
    if parsed_manual:
        lines.append("")
        for m in parsed_manual:
            lines.append(_manual_method_virtual_decl(m))

    lines.append("};")
    lines.append("")
    lines.append(f"#endif // {guard}")
    lines.append("")
    return LICENSE_HEADER + "\r\n".join(lines)


# ---------------------------------------------------------------------------
# Implementation header generation
# ---------------------------------------------------------------------------

def write_impl_header(
    class_name: str,
    schema_class: SchemaClass,
    all_enums: dict[str, SchemaEnum],
    all_classes: dict[str, SchemaClass],
    generated: set[str],
) -> str:
    """Generate CXxxImpl.h - concrete implementation of IXxx for the core."""

    i_class_name = _interface_name(class_name)
    impl_class_name = f"{class_name}Impl"

    parent = _effective_parent(schema_class, generated)
    parent_impl_name = f"{parent}Impl" if parent else None

    is_root = parent_impl_name is None

    guard = make_header_guard(impl_class_name)
    lines = [
        f"#ifndef {guard}",
        f"#define {guard}",
        "",
        "#pragma once",
        "",
        f'#include "source2toolkit/schema/entity/classes/{i_class_name}.h"',
        f'#include "schema/entity/classes/{sanitise_type_name(class_name)}.h"',
    ]

    if parent_impl_name:
        lines.append(f'#include "{sanitise_type_name(parent_impl_name)}.h"')

    lines.append("")

    if parent_impl_name:
        lines.append(
            f"class {impl_class_name} : public {parent_impl_name}, public {i_class_name}"
        )
    else:
        lines.append(f"class {impl_class_name} : public virtual {i_class_name}")

    lines += ["{", ""]

    if is_root:
        lines += [
            "protected:",
            "    void* m_pReal;",
            "",
            "public:",
            f"    explicit {impl_class_name}(void* p) : m_pReal(p) {{}}",
        ]
    else:
        lines += [
            "public:",
            f"    explicit {impl_class_name}({class_name}* p) : {parent_impl_name}(p) {{}}",
        ]

    lines += [
        "",
        "private:",
        f"    {class_name}* Real() {{ return static_cast<{class_name}*>(m_pReal); }}",
        "",
        "public:",
    ]

    # Schema field overrides
    for f in schema_class.fields:
        if f.type.category == SchemaTypeCategory.Bitfield:
            continue
        if _field_has_ignored_wildcard(f.type):
            continue
        if contains_ignored_type(f.type):
            continue

        method_name = to_pascal_case(f.name)
        ret = _virtual_return_type(f)

        if _is_pointer_field(f):
            lines.append(
                f"    {ret} {method_name}() override"
                f" {{ return Real()->{f.name}(); }}"
            )
        else:
            lines.append(
                f"    {ret} {method_name}() override"
                f" {{ return Real()->{f.name}(); }}"
            )
            lines.append(
                f"    void {method_name}Updated() override"
                f" {{ Real()->{f.name}.NetworkStateChanged(); }}"
            )

    # Manual method overrides
    parsed_manual = [_parse_manual_method(m) for m in MANUAL_METHODS.get(class_name, [])]
    parsed_manual = [m for m in parsed_manual if m is not None]
    if parsed_manual:
        lines.append("")
        for m in parsed_manual:
            lines.append(_manual_method_override_impl(m))

    lines.append("};")
    lines.append("")
    lines.append(f"#endif // {guard}")
    lines.append("")
    return LICENSE_HEADER + "\r\n".join(lines)


# ---------------------------------------------------------------------------
# Main
# ---------------------------------------------------------------------------

def main() -> None:
    script_dir = _SCRIPT_DIR

    sdk_output = sys.argv[1] if len(sys.argv) > 1 else os.path.join(
        script_dir, "../../public/source2toolkit/schema/entity"
    )
    core_output = sys.argv[2] if len(sys.argv) > 2 else os.path.join(
        script_dir, "../../../source2toolkit/src/schema/entity"
    )

    schema_path = os.path.join(script_dir, "../../../source2toolkit/tools/schemagen_core/server.json")
    with open(schema_path, encoding="utf-8") as fh:
        raw = json.load(fh)

    defs = _parse_schema_defs(raw["defs"])
    enums, classes = convert_new_schema_to_old(defs)

    all_enums: dict[str, SchemaEnum] = {
        k: v for k, v in sorted(enums.items()) if k not in IGNORE_CLASSES
    }
    all_classes: dict[str, SchemaClass] = {
        k: v for k, v in sorted(classes.items()) if k not in IGNORE_CLASSES
    }

    visited = build_graph_and_bfs(all_classes)
    visited |= EXTRA_WHITELIST

    def should_generate(name: str) -> bool:
        if name in HARD_SKIP_CLASSES:
            return False
        if name not in visited and "VData" not in name:
            return False
        return True

    generated: set[str] = {
        n for n in all_classes if should_generate(n) and _is_entity_class(n)
    }

    sdk_ifaces_dir = os.path.join(sdk_output, "classes")
    sdk_enums_dir  = os.path.join(sdk_output, "enums")
    core_impl_dir  = os.path.join(core_output, "classes")

    # Clear SDK outputs fully; do NOT clear core_impl_dir (shared with schemagen_core).
    for out_dir in (sdk_ifaces_dir, sdk_enums_dir):
        if os.path.isdir(out_dir):
            for fname in os.listdir(out_dir):
                if fname.endswith(".h"):
                    os.remove(os.path.join(out_dir, fname))
        os.makedirs(out_dir, exist_ok=True)
    os.makedirs(core_impl_dir, exist_ok=True)

    # Enum headers
    for enum_name, schema_enum in all_enums.items():
        if enum_name in HARD_SKIP_ENUMS:
            continue
        content = write_enum(enum_name, schema_enum)
        out_file = os.path.join(sdk_enums_dir, f"{sanitise_type_name(enum_name)}.h")
        with open(out_file, "w", encoding="utf-8", newline="") as fh:
            fh.write(content)

    sdk_written = 0
    core_written = 0

    for class_name, schema_class in all_classes.items():
        if not should_generate(class_name):
            continue
        if not _is_entity_class(class_name):
            continue

        i_name = _interface_name(class_name)

        content = write_interface_header(
            class_name, schema_class, all_enums, all_classes, generated
        )
        out_file = os.path.join(sdk_ifaces_dir, f"{sanitise_type_name(i_name)}.h")
        with open(out_file, "w", encoding="utf-8", newline="") as fh:
            fh.write(content)
        sdk_written += 1

        impl_name = f"{class_name}Impl"
        content = write_impl_header(
            class_name, schema_class, all_enums, all_classes, generated
        )
        out_file = os.path.join(core_impl_dir, f"{sanitise_type_name(impl_name)}.h")
        with open(out_file, "w", encoding="utf-8", newline="") as fh:
            fh.write(content)
        core_written += 1

    print(
        f"Done.\n"
        f"  Enums      ({len(all_enums)}): {sdk_enums_dir}\n"
        f"  Interfaces ({sdk_written}): {sdk_ifaces_dir}\n"
        f"  Impls      ({core_written}): {core_impl_dir}"
    )


if __name__ == "__main__":
    main()
