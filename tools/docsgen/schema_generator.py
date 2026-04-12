TYPE_MAP = {}

def link_type(type_name):
    if not type_name:
        return ""

    base = type_name.replace("*", "").replace("&", "").strip()

    if base in TYPE_MAP:
        url = TYPE_MAP[base]

        url = url.replace(".mdx", "")   # remove extension

        return f"[{base}]({url})" + type_name[len(base):]

    return type_name

def schema_class_to_yaml(cls):
    class_name = cls.get("name", "Unknown")
    parent = cls.get("parent")
    methods = cls.get("methods", [])
    fields = cls.get("fields", [])
    class_doc = cls.get("doc", {})

    body = []

    body.append({
        "api1": class_name
    })

    facts = []
    if parent:
        facts.append({
            "name": "Inheritance",
            "value": link_type(parent)
        })

    if facts:
        body.append({
            "facts": facts
        })

    brief = class_doc.get("brief", "")
    if brief:
        body.append({
            "markdown": brief
        })

    if fields:
        body.append({
            "h2": "Fields"
        })

        field_list = []

        for f in fields:
            field_list.append({
                "name": f["name"],
                "type": link_type(f["type"]),
                "description": ""
            })

        body.append({
            "parameters": field_list   # reuse ApiParam renderer
        })

    if methods:
        body.append({
            "h2": "Methods"
        })

    for m in methods:
        method_name = m.get("name", "Unknown")
        params = m.get("params", [])
        doc = m.get("doc", {})

        param_names = [p['name'] for p in params]
        signature = f"{method_name}({', '.join(param_names)})"
        signature = signature.replace('<', '&lt;').replace('>', '&gt;')

        body.append({
            "api3": signature
        })

        brief = doc.get("brief", "")
        if brief:
            body.append({
                "markdown": brief
            })

        param_docs = doc.get("params", {}) if isinstance(doc, dict) else {}

        if params:
            body.append({
                "h4": "Parameters"
            })

            param_list = []

            for p in params:
                name = p.get("name", "")
                param_list.append({
                    "name": name,
                    "type": p.get("type", ""),
                    "description": param_docs.get(name, "")
                })

            body.append({
                "parameters": param_list
            })

    return {
        "title": class_name,
        "body": body
    }


def schema_enums_to_yaml(enums, filename):
    body = []

    body.append({
        "api1": filename.replace(".h", "")
    })

    body.append({
        "h2": "Enums"
    })

    for enum in enums:
        enum_name = enum["name"]

        body.append({
            "api3": enum_name
        })

        values = enum.get("values", [])

        if values:
            body.append({
                "h4": "Values"
            })

            body.append({
                "parameters": [
                    {
                        "name": v["name"],
                        "type": "",
                        "description": f"= {v['value']}" if v["value"] else ""
                    }
                    for v in values
                ]
            })

    return {
        "title": filename,
        "body": body
    }


def schema_functions_to_yaml(functions, filename):
    body = []

    body.append({
        "api1": filename.replace(".h", "")
    })

    body.append({
        "h2": "Functions"
    })

    for f in functions:
        param_names = [p["name"] for p in f["params"]]
        signature = f"{f['name']}({', '.join(param_names)})"

        body.append({
            "api3": signature
        })

        brief = f["doc"].get("brief", "")
        if brief:
            body.append({
                "markdown": brief
            })

        if f["params"]:
            body.append({
                "h4": "Parameters"
            })

            body.append({
                "parameters": [
                    {
                        "name": p["name"],
                        "type": p["type"],
                        "description": f["doc"]["params"].get(p["name"], "")
                    }
                    for p in f["params"]
                ]
            })

    return {
        "title": filename,
        "body": body
    }