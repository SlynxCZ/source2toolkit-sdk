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
"""

import re

def extract_classes(content):
    classes = []

    pattern = re.finditer(r'class\s+(\w+)(?:\s*:\s*public\s+(\w+))?\s*\{', content)

    for match in pattern:
        name = match.group(1)
        parent = match.group(2)

        start = match.end()
        brace_count = 1
        i = start

        while i < len(content):
            if content[i] == '{':
                brace_count += 1
            elif content[i] == '}':
                brace_count -= 1
                if brace_count == 0:
                    break
            i += 1

        body = content[start:i]

        classes.append((name, parent, body))

    return classes

def split_params(params):
    result = []
    current = ""
    depth_angle = 0
    depth_paren = 0

    for c in params:
        if c == '<':
            depth_angle += 1
        elif c == '>':
            depth_angle -= 1
        elif c == '(':
            depth_paren += 1
        elif c == ')':
            depth_paren -= 1

        if c == ',' and depth_angle == 0 and depth_paren == 0:
            result.append(current.strip())
            current = ""
        else:
            current += c

    if current.strip():
        result.append(current.strip())

    return result

def parse_free_functions(content):
    functions = []

    lines = content.splitlines()
    current_doc = None
    in_block_comment = False

    for line in lines:
        line = line.strip()

        if line.startswith("///"):
            text = re.sub(r'<.*?>', '', line.replace("///", "").strip())

            if current_doc is None:
                current_doc = {"brief": "", "params": {}}

            current_doc["brief"] += text + " "
            continue

        if line.startswith("/**"):
            current_doc = {"brief": "", "params": {}}
            in_block_comment = True
            continue

        if in_block_comment:
            if "*/" in line:
                in_block_comment = False
                continue

            line = line.strip("* ").strip()

            if line.startswith("@brief"):
                current_doc["brief"] = line.replace("@brief", "").strip()

            elif line.startswith("@param"):
                parts = line.split(" ", 2)
                if len(parts) >= 3:
                    current_doc["params"][parts[1]] = parts[2]

            continue

        m = re.match(r'(.+?)\s+(UTIL_\w+)\((.*?)\)\s*;', line)

        if m:
            ret, name, params = m.groups()

            param_list = []

            if params and params.strip():
                for p in split_params(params):
                    p = p.split("=")[0].strip()
                    match = re.match(r'(.+?[\*&]?)\s*(\w+)$', p)
                    if match:
                        type_token = match.group(1).strip()
                        name_token = match.group(2).strip()
                    else:
                        type_token = p.strip()
                        name_token = ""

                    param_list.append({
                        "name": name_token,
                        "type": type_token
                    })

            functions.append({
                "name": name,
                "return": ret.strip(),
                "params": param_list,
                "doc": current_doc or {}
            })

            current_doc = None

    return functions

def parse_enums(content):
    enums = []

    pattern = re.finditer(r'enum\s+(class\s+)?(\w+)(?:\s*:\s*[\w:]+)?\s*\{(.*?)\};', content, re.DOTALL)

    for match in pattern:
        is_class = match.group(1) is not None
        name = match.group(2)
        body = match.group(3)

        values = []

        for line in re.split(r',\s*(?![^{}]*\})', body):
            line = line.strip()

            if not line:
                continue

            line = re.sub(r'//.*', '', line)

            line = re.sub(r'/\*.*?\*/', '', line, flags=re.DOTALL)

            line = line.strip()

            # remove /* */ comments (multi-line safe)
            line = re.sub(r'/\*.*?\*/', '', line, flags=re.DOTALL)

            # remove // comments
            line = re.sub(r'//.*', '', line)

            line = line.strip()

            if not line:
                continue

            # robust parsing
            match = re.match(r'^(\w+)\s*(?:=\s*(.+))?$', line)
            if not match:
                continue

            key = match.group(1)
            val = match.group(2)

            values.append({
                "name": key,
                "value": val.strip() if val else None
            })

        enums.append({
            "name": name,
            "is_class": is_class,
            "values": values
        })

    return enums

def parse_typedef_docs(content):
    """Collect @brief docs from `using SomeName_t = ...` typedef declarations."""
    docs = {}
    lines = content.splitlines()
    current_doc = None
    in_block_comment = False

    for line in lines:
        line = line.strip()

        if line.startswith("/**"):
            current_doc = {"brief": "", "params": {}}
            in_block_comment = True
            continue

        if in_block_comment:
            if "*/" in line:
                in_block_comment = False
                continue
            line_inner = line.strip("* ").strip()
            if line_inner.startswith("@brief"):
                current_doc["brief"] = line_inner.replace("@brief", "").strip()
            elif line_inner.startswith("@param"):
                parts = line_inner.split(" ", 2)
                if len(parts) >= 3:
                    current_doc["params"][parts[1]] = parts[2]
            continue

        m = re.match(r'using\s+(\w+_t)\s*=', line)
        if m and current_doc:
            typedef_name = m.group(1)
            # Strip trailing _t to get base name: CBaseEntity_CreateEntityByName_t -> CBaseEntity_CreateEntityByName
            base = typedef_name[:-2] if typedef_name.endswith("_t") else typedef_name
            docs[base] = current_doc
            current_doc = None
        elif not line.startswith("//") and line and not line.startswith("/*"):
            current_doc = None

    return docs


def parse_cpp_file(content):
    classes = []
    typedef_docs = parse_typedef_docs(content)

    for class_name, parent, body in extract_classes(content):

        methods = []
        fields = []

        field_matches = re.findall(
            r'SCHEMA_FIELD(?:_POINTER)?\((.*?),\s*(.*?)\);',
            body
        )

        for field_type, field_name in field_matches:
            fields.append({
                "name": field_name.strip(),
                "type": field_type.strip()
            })

        lines = body.splitlines()
        current_doc = None
        in_block_comment = False

        for line in lines:
            line = line.strip()

            if line.startswith("///"):
                text = line.replace("///", "").strip()
                text = re.sub(r'<.*?>', '', text)

                if current_doc is None:
                    current_doc = {"brief": "", "params": {}}

                current_doc["brief"] += text + " "
                continue

            if line.startswith("/**"):
                current_doc = {"brief": "", "params": {}}
                in_block_comment = True
                continue

            if in_block_comment:
                if "*/" in line:
                    in_block_comment = False
                    continue

                line = line.strip("* ").strip()

                if line.startswith("@brief"):
                    current_doc["brief"] = line.replace("@brief", "").strip()

                elif line.startswith("@param"):
                    parts = line.split(" ", 2)
                    if len(parts) >= 3:
                        current_doc["params"][parts[1]] = parts[2]

                continue

            if current_doc and line.startswith("*"):
                line = line.strip("* ").strip()

                if line.startswith("@brief"):
                    current_doc["brief"] = line.replace("@brief", "").strip()

                elif line.startswith("@param"):
                    parts = line.split(" ", 2)
                    if len(parts) >= 3:
                        current_doc["params"][parts[1]] = parts[2]

                continue

            m = re.match(
                r'(?:virtual\s+|static\s+)?(.+?)\s+(\w+)\((.*?)\)\s*(?:const)?\s*(?:=\s*0)?\s*;',
                line
            )

            if m:
                ret, name, params = m.groups()

                params_list = []

                if params.strip():
                    for p in split_params(params):
                        p = p.split("=")[0].strip()

                        match = re.match(r'(.+?[\*&]?)\s*(\w+)$', p)
                        if match:
                            type_token = match.group(1).strip()
                            name_token = match.group(2).strip()
                        else:
                            type_token = p.strip()
                            name_token = ""

                        params_list.append({
                            "name": name_token,
                            "type": type_token
                        })

                doc = current_doc or typedef_docs.get(name, {})
                methods.append({
                    "name": name,
                    "return": ret.strip(),
                    "params": params_list,
                    "doc": doc
                })

                current_doc = None

        classes.append({
            "name": class_name,
            "parent": parent,
            "methods": methods,
            "fields": fields,
            "doc": {}
        })

    return classes