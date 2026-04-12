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

    pattern = re.finditer(r'enum\s+(class\s+)?(\w+)\s*\{(.*?)\};', content, re.DOTALL)

    for match in pattern:
        is_class = match.group(1) is not None
        name = match.group(2)
        body = match.group(3)

        values = []

        for line in body.split(","):
            line = line.strip()

            if not line:
                continue

            # remove comments
            line = re.sub(r'//.*', '', line).strip()

            if '=' in line:
                key, val = line.split("=", 1)
                values.append({
                    "name": key.strip(),
                    "value": val.strip()
                })
            else:
                values.append({
                    "name": line.strip(),
                    "value": None
                })

        enums.append({
            "name": name,
            "is_class": is_class,
            "values": values
        })

    return enums


def parse_cpp_file(content):
    classes = []

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

                methods.append({
                    "name": name,
                    "return": ret.strip(),
                    "params": params_list,
                    "doc": current_doc or {}
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