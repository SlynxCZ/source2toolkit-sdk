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

Public schemagen – generates pure virtual IXxx interface headers (SDK) and
CXxxImpl implementation headers (core).

Reads server.json from ../schemagen_core/server.json (sibling tool directory).

Usage:
    python generator.py [sdk_iclasses_output] [core_iclasses_output]

    sdk_iclasses_output  Path where IXxx interface headers are written.
                         Default: ../../public/source2toolkit/schema/entity/iclasses

    core_iclasses_output Path where CXxxImpl headers are written.
                         Default: ../../../source2toolkit/src/schema/entity/iclasses
                         (assumes source2toolkit and source2toolkit-sdk are siblings)
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
sys.path.insert(0, os.path.join(_SCRIPT_DIR, "..", "schemagen_core"))

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
)

# ---------------------------------------------------------------------------
# Hungarian notation stripping
# ---------------------------------------------------------------------------

_HUNGARIAN_RE = re.compile(
    r"^(isz|vec|arr|ang|clr|bv|ub|un|us|af|fl|ch|sz|a|n|i|b|f|h|q|p|v|e|u|s)([A-Z])"
)


def to_pascal_case(field_name: str) -> str:
    """Convert a schema field name to PascalCase method name.

    Examples:
        m_iHealth      -> Health
        m_bIsAlive     -> IsAlive
        m_szPlayerName -> PlayerName
        m_hOwnerEntity -> OwnerEntity
        m_vecOrigin    -> Origin
        m_flSpeed      -> Speed
    """
    name = field_name
    if name.startswith("m_"):
        name = name[2:]
    m = _HUNGARIAN_RE.match(name)
    if m:
        name = name[len(m.group(1)):]
    # Capitalize first letter if still lowercase (no Hungarian prefix matched)
    if name and name[0].islower():
        name = name[0].upper() + name[1:]
    return name


# ---------------------------------------------------------------------------
# Field categorisation helpers
# ---------------------------------------------------------------------------

def _is_pointer_field(field: SchemaField) -> bool:
    """True for SCHEMA_FIELD_POINTER fields (fixed arrays, CUtlStringToken)."""
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
    """True for C-prefixed entity classes: C followed by uppercase (CBaseEntity, CCSPlayerController)."""
    return len(class_name) >= 2 and class_name[0] == "C" and class_name[1].isupper()


def _interface_name(class_name: str) -> str:
    """CBaseEntity -> IBaseEntity (replace leading C with I for entity classes)."""
    if _is_entity_class(class_name):
        return "I" + class_name[1:]
    return "I" + class_name


def _effective_parent(
    schema_class: SchemaClass,
    generated: set[str],
) -> Optional[str]:
    """Return the first C-prefixed ancestor present in the generated set, or None."""
    p = schema_class.parent
    if p is None or p in HARD_SKIP_CLASSES or p not in generated:
        return None
    if not _is_entity_class(p):
        return None
    return p


# ---------------------------------------------------------------------------
# Interface header generation
# ---------------------------------------------------------------------------

def write_interface_header(
    class_name: str,
    schema_class: SchemaClass,
    all_enums: dict[str, SchemaEnum],
    all_classes: dict[str, SchemaClass],
    generated: set[str],
) -> str:
    """Generate IFoo.h – a pure virtual interface for class_name."""

    i_class_name = _interface_name(class_name)

    parent = _effective_parent(schema_class, generated)
    i_parent_name = _interface_name(parent) if parent else None

    includes: set[str] = set()
    forwards: set[str] = set()

    if i_parent_name:
        includes.add(f"_iface_{parent}")  # sentinel for interface include

    for f in schema_class.fields:
        if f.type.category == SchemaTypeCategory.Bitfield:
            continue
        if _field_has_ignored_wildcard(f.type):
            continue
        if contains_ignored_type(f.type):
            continue
        collect_referenced_types(
            f.type,
            includes,
            forwards,
            _is_pointer_field(f) or f.type.category == SchemaTypeCategory.Ptr,
        )

    includes.discard(class_name)
    forwards.discard(class_name)
    forwards -= includes

    guard = make_header_guard(i_class_name)
    lines = [
        f"#ifndef {guard}",
        f"#define {guard}",
        "",
        "#pragma once",
        "",
        "#include <cstdint>",
        "",
    ]

    if i_parent_name:
        lines.append(f'#include "{i_parent_name}.h"')
        lines.append("")

    for inc in sorted(includes):
        if inc.startswith("_iface_"):
            continue
        if inc in all_enums and inc not in HARD_SKIP_ENUMS:
            lines.append(f'#include "../enums/{sanitise_type_name(inc)}.h"')
        elif inc in all_classes:
            lines.append(f'#include "{sanitise_type_name(inc)}.h"')

    has_regular_includes = any(
        not inc.startswith("_iface_") for inc in includes
    )
    if has_regular_includes:
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
    """Generate CXxxImpl.h – concrete implementation of IXxx for the core."""

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
        f'#include "source2toolkit/schema/entity/iclasses/{i_class_name}.h"',
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
        script_dir, "../../public/source2toolkit/schema/entity/iclasses"
    )
    core_output = sys.argv[2] if len(sys.argv) > 2 else os.path.join(
        script_dir, "../../../source2toolkit/src/schema/entity/iclasses"
    )

    schema_path = os.path.join(script_dir, "../schemagen_core/server.json")
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

    # Only C-prefixed entity classes get IXxx interfaces + impls
    generated: set[str] = {
        n for n in all_classes if should_generate(n) and _is_entity_class(n)
    }

    # Clear existing .h files in both output dirs
    for out_dir in (sdk_output, core_output):
        if os.path.isdir(out_dir):
            for fname in os.listdir(out_dir):
                if fname.endswith(".h"):
                    os.remove(os.path.join(out_dir, fname))
        os.makedirs(out_dir, exist_ok=True)

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
        out_file = os.path.join(sdk_output, f"{sanitise_type_name(i_name)}.h")
        with open(out_file, "w", encoding="utf-8", newline="") as fh:
            fh.write(content)
        sdk_written += 1

        impl_name = f"{class_name}Impl"
        content = write_impl_header(
            class_name, schema_class, all_enums, all_classes, generated
        )
        out_file = os.path.join(core_output, f"{sanitise_type_name(impl_name)}.h")
        with open(out_file, "w", encoding="utf-8", newline="") as fh:
            fh.write(content)
        core_written += 1

    print(
        f"Done.\n"
        f"  Interfaces ({sdk_written}): {sdk_output}\n"
        f"  Impls     ({core_written}): {core_output}"
    )


if __name__ == "__main__":
    main()
