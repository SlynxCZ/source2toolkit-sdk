import os
import re
import yaml
import shutil
import cpp_parser
import schema_generator

SOURCE_DIR = "../../public"
DEST_DIR = "../../docs"


os.makedirs(DEST_DIR, exist_ok=True)


def format_title(name):
    if any(c.isupper() for c in name[1:]):
        return name

    return name[:1].upper() + name[1:]


def escape_generics(text):
    """Escape < and > in generic types for MDX compatibility."""
    if not text:
        return text
    return text.replace('<', '&lt;').replace('>', '&gt;')


def fix_html_for_jsx(text):
    """Convert HTML to Markdown for MDX compatibility."""
    if not text:
        return text

    # Convert pre/code blocks to markdown code fences first
    def convert_code_block(match):
        lang = ''
        lang_match = re.search(r'class(?:Name)?="lang-(\w+)"', match.group(0))
        if lang_match:
            lang = lang_match.group(1)
        code_match = re.search(r'<code[^>]*>(.*?)</code>', match.group(0), re.DOTALL)
        if code_match:
            content = code_match.group(1)
            content = content.replace('&gt;', '>').replace('&lt;', '<').replace('&amp;', '&')
            return f'\n\n```{lang}\n{content}\n```\n\n'
        return match.group(0)
    text = re.sub(r'<pre><code[^>]*>.*?</code></pre>', convert_code_block, text, flags=re.DOTALL)

    # Convert inline code tags to backticks
    text = re.sub(r'<code>(.*?)</code>', r'`\1`', text)

    # Remove XML doc tags like <param>, <returns>, <typeparam>, etc.
    text = re.sub(r'<param\s+name="([^"]+)">(.*?)</param>', r'- `\1`: \2', text)
    text = re.sub(r'<typeparam\s+name="([^"]+)">(.*?)</typeparam>', r'- `\1`: \2', text)
    text = re.sub(r'<returns>(.*?)</returns>', r'Returns: \1', text)
    text = re.sub(r'<see\s+cref="([^"]+)"\s*/>', r'`\1`', text)
    text = re.sub(r'<seealso\s+cref="([^"]+)"\s*/>', r'`\1`', text)

    # Fix HTML entities
    text = text.replace('&gt;', '>').replace('&lt;', '<').replace('&amp;', '&')

    # Convert HTML lists to Markdown lists
    if '<ul>' in text or '<li>' in text:
        # Process nested lists
        def convert_list(html):
            result = []
            depth = 0
            parts = re.split(r'(</?(?:ul|li)>)', html)
            current = ''
            for part in parts:
                if part == '<ul>':
                    depth += 1
                elif part == '</ul>':
                    depth = max(0, depth - 1)
                elif part == '<li>':
                    current = ''
                elif part == '</li>':
                    if current.strip():
                        indent = '  ' * max(0, depth - 1)
                        result.append(f'{indent}- {current.strip()}')
                    current = ''
                else:
                    current += part
            return '\n'.join(result)
        text = convert_list(text)

    # Convert p tags to paragraphs
    def convert_p(match):
        content = match.group(1)
        # Don't collapse if contains code block
        if '```' in content:
            return f'{content.strip()}\n\n'
        # Collapse whitespace for regular text
        content = ' '.join(content.split())
        return f'{content}\n\n'
    text = re.sub(r'<p>\s*(.*?)\s*</p>', convert_p, text, flags=re.DOTALL)

    # Clean up extra newlines
    text = re.sub(r'\n{3,}', '\n\n', text)

    return text.strip()


def escape_generics_in_link_text(text):
    """Escape generics in markdown link text only."""
    if not text:
        return text
    return text.replace('<', '\\<').replace('>', '\\>')


def get_namespace(yaml_data):
    """Extract namespace from the YAML data."""
    for item in yaml_data.get('body', []):
        if 'facts' in item:
            for fact in item['facts']:
                if fact.get('name') == 'Namespace':
                    if isinstance(fact.get('value'), dict):
                        return fact['value'].get('text', '')
                    return fact.get('value', '')
    return ''


def extract_metadata(yaml_data, is_index=False):
    """Extract front-matter metadata from DocFX ApiPage YAML."""
    title = yaml_data.get('title', '')
    if not title:
        return {}

    # First remove generics and brackets from the full title
    clean_title = re.sub(r'<[^>]+>', '', title)
    clean_title = re.sub(r'\[[^\]]+\]', '', clean_title)

    if is_index:
        clean_title = clean_title.split(".")[-1]
    else:
        words = clean_title.split()
        clean_title = words[-1] if words else ''

    return {'title': clean_title}


def transform_filename(base_name):
    """
    If filename ends with -NUMBER, replace with NUMBER times 't'.
    Example: class-3 -> classttt
    """
    match = re.match(r"^(.*?)-(\d+)$", base_name)
    if match:
        name, num = match.groups()
        num = int(num)
        return name + ("t" * num)
    return base_name


def generate_markdown(yaml_data):
    """Generate MDX content from DocFX ApiPage YAML."""
    md = ""
    namespace = get_namespace(yaml_data)

    for item in yaml_data.get('body', []):
        if 'api1' in item:
            api1_title = str(item.get('api1', ''))
            api1_title = re.sub(r'<[^>]+>', '', api1_title)
            md += f"# {api1_title}\n\n"
            if 'src' in item:
                src = item['src'].replace('/blob/main', '/blob/master')
                md += f'<ViewSource href="{src}" />\n\n'

        if 'facts' in item:
            for fact in item['facts']:
                fact_name = fact.get('name', '')
                fact_value = fact.get('value', '')
                if isinstance(fact_value, dict):
                    fact_text = fact_value.get('text', '')
                    fact_url = fact_value.get('url', '')
                    if fact_url and fact_url.endswith('.html'):
                        fact_url = "/docs/source2toolkit/" + convert_to_path(fact_url)
                        fact_url = fact_url.replace('/api/shared/', '/api/').replace('/api/core/', '/api/')
                        md += f"**{fact_name}**: [{escape_generics_in_link_text(fact_text)}]({fact_url})\n\n"
                    else:
                        md += f"**{fact_name}**: {fact_text}\n\n"
                else:
                    md += f"**{fact_name}**: {fact_value}\n\n"

        if 'markdown' in item:
            safe_md = fix_html_for_jsx(item['markdown'])
            safe_md = safe_md.replace('<', '&lt;').replace('>', '&gt;')
            md += f"{safe_md}\n\n"

        if 'h2' in item:
            md += f"## {item['h2']}\n\n"

        if 'h4' in item:
            h4_text = item['h4']
            if h4_text in ['Parameters', 'Returns', 'Field Value', 'Property Value', 'Type Parameters', 'Exceptions', 'Remarks', 'Event Type']:
                md += f"<ApiLabel>{h4_text}</ApiLabel>\n\n"
            else:
                md += f"#### {h4_text}\n\n"

        if 'code' in item:
            md += "```csharp\n" + item['code'] + "\n```\n\n"

        if 'inheritance' in item:
            for inherit in item['inheritance']:
                inherit_text = inherit.get('text', '')
                inherit_url = inherit.get('url', '')
                if inherit_url:
                    if inherit_url.endswith('.html'):
                        inherit_url = "/docs/api/" + convert_to_path(inherit_url)
                        inherit_url = inherit_url.replace('/api/shared/', '/api/').replace('/api/core/', '/api/')
                    md += f"- [{escape_generics_in_link_text(inherit_text)}]({inherit_url})\n"
                else:
                    md += f"- {inherit_text}\n"
            md += "\n"

        if 'list' in item:
            for list_item in item['list']:
                list_text = list_item.get('text', '')
                list_url = list_item.get('url', '')
                if list_url:
                    if list_url.endswith('.html'):
                        list_url = "/docs/api/" + convert_to_path(list_url)
                        list_url = list_url.replace('/api/shared/', '/api/').replace('/api/core/', '/api/')
                    md += f"- [{escape_generics_in_link_text(list_text)}]({list_url})\n"
                else:
                    md += f"- {list_text}\n"
            md += "\n"

        if 'parameters' in item:
            for param in item['parameters']:
                param_name = param.get('name', '')
                param_default = param.get('default', '')
                param_description = param.get('description', '')

                type_text = schema_generator.link_type(param.get("type", ""))
                type_text_escaped = type_text

                parts = []
                if param_name:
                    parts.append(f'name="{param_name}"')
                if type_text_escaped:
                    safe_type = type_text.replace('<', '&lt;').replace('>', '&gt;')
                    if "[" not in type_text:
                        safe_type = type_text.replace('<', '&lt;').replace('>', '&gt;')
                    else:
                        safe_type = type_text
                    parts.append(f'type="{safe_type}"')

                api_param = f"<ApiParam {' '.join(parts)} />"

                if param_description:
                    md += f"- {api_param} — {fix_html_for_jsx(param_description).replace('<', '&lt;').replace('>', '&gt;')}\n"
                elif param_default != '':
                    md += f"- {api_param} = {param_default}\n"
                else:
                    md += f"- {api_param}\n"
            md += "\n"

        if 'api3' in item:
            src = item.get('src', '')
            api3_title = str(item.get('api3', ''))
            # Escape generics for markdown heading (use backslash)
            api3_title = re.sub(r'<[^>]+>', '', api3_title)
            api3_title = re.sub(r'\[[^\]]+\]', '', api3_title)
            md += f"### {api3_title}\n\n"
            if src != '':
                src = src.replace('/blob/main', '/blob/master')
                md += f'<ViewSource href="{src}" />\n\n'

    return md


def resolve_output_path(root, file):
    rel = os.path.relpath(root, SOURCE_DIR).replace("\\", "/")

    if rel == ".":
        parts = []
    else:
        parts = rel.split("/")
        if parts[0] == "source2toolkit":
            parts = parts[1:]

    name = file.replace(".h", "")
    slug = name
    slug = slug.replace("itoolkit-", "")

    root_clean = root.replace("\\", "/")

    is_core = "core-api" in root_clean
    is_schema = "schema" in root_clean

    is_entity = name.lower() in ["entity", "entities"]
    is_enum = name.endswith("_t")

    def to_pascal_case(s):
        return ''.join(word.capitalize() for word in s.split('-'))

    if (is_core or is_schema) and not is_entity and not is_enum:
        slug = to_pascal_case(slug)

    if file.startswith("IToolkit"):
        return os.path.join(
            DEST_DIR,
            "core-api",
            "low-level",
            f"{slug}.mdx"
        )

    if "schema" in rel and file in ["entity.h", "schema.h"]:
        return os.path.join(
            DEST_DIR,
            "core-api",
            "high-level",
            f"{slug}.mdx"
        )

    if "utils" in rel:
        return os.path.join(
            DEST_DIR,
            "core-api",
            "high-level",
            f"{slug}.mdx"
        )

    parts = rel.split("/")
    if parts[0] == "source2toolkit":
        parts = parts[1:]

    rel_clean = "/".join(parts)

    return os.path.join(
        DEST_DIR,
        rel_clean,
        f"{slug}.mdx"
    )


if __name__ == "__main__":
    for root, dirs, files in os.walk(SOURCE_DIR):
        for file in files:
            if not file.endswith(".h"):
                continue

            path = os.path.join(root, file)

            with open(path, "r", encoding="utf-8") as f:
                content = f.read()

            classes = cpp_parser.parse_cpp_file(content)
            enums = cpp_parser.parse_enums(content)
            functions = cpp_parser.parse_free_functions(content)

            output_path = resolve_output_path(root, file)
            web_path = output_path.replace("\\", "/").replace(DEST_DIR, "/docs")

            for cls in classes:
                schema_generator.TYPE_MAP[cls["name"]] = web_path

            for enum in enums:
                rel = os.path.relpath(root, SOURCE_DIR).replace("\\", "/")

                parts = rel.split("/")
                if parts[0] == "source2toolkit":
                    parts = parts[1:]

                url = "/docs/" + "/".join(parts) + f"/enums/{enum['name']}"

                schema_generator.TYPE_MAP[enum["name"]] = url

            print(f"\nFILE: {file}")
            print(f"CLASSES FOUND: {len(classes)}")
            print(f"ENUMS FOUND: {len(enums)}")

            dest_file = resolve_output_path(root, file)

            if file.endswith(".h") and enums and not classes and not functions:
                dest_file = None

            if dest_file:
                os.makedirs(os.path.dirname(dest_file), exist_ok=True)

            has_content = False
            title_written = False
            body = []

            # ===== CLASSES =====
            if classes:
                has_content = True
                for cls in classes:
                    yaml_data = schema_generator.schema_class_to_yaml(cls)
                    if not title_written:
                        body.extend(yaml_data["body"])
                        title_written = True
                    else:
                        body.extend([b for b in yaml_data["body"] if "api1" not in b])

            # ===== ENUMS =====
            if enums:
                has_content = True
                rel = os.path.relpath(root, SOURCE_DIR).replace("\\", "/")

                parts = rel.split("/")
                if parts[0] == "source2toolkit":
                    parts = parts[1:]

                for enum in enums:
                    enum_name = enum["name"]

                    enum_yaml = schema_generator.schema_enums_to_yaml([enum], enum_name)

                    if parts and parts[-1] == "enums":
                        enum_path = os.path.join(
                            DEST_DIR,
                            *parts,
                            f"{enum_name}.mdx"
                        )
                    else:
                        enum_path = os.path.join(
                            DEST_DIR,
                            *parts,
                            "enums",
                            f"{enum_name}.mdx"
                        )

                    os.makedirs(os.path.dirname(enum_path), exist_ok=True)

                    md_content = "---\n"
                    md_content += yaml.safe_dump({"title": enum_name}, sort_keys=False)
                    md_content += "---\n\n"
                    md_content += generate_markdown(enum_yaml)

                    with open(enum_path, "w", encoding="utf-8") as out:
                        out.write(md_content)

            # ===== FUNCTIONS =====
            if functions:
                has_content = True
                yaml_data = schema_generator.schema_functions_to_yaml(functions, file)
                if not title_written:
                    body.extend(yaml_data["body"])
                    title_written = True
                else:
                    body.extend([b for b in yaml_data["body"] if "api1" not in b])

            if has_content and dest_file:
                name = file.replace(".h", "")
                clean_name = format_title(name)

                md_content = "---\n"
                md_content += yaml.safe_dump({"title": clean_name}, sort_keys=False)
                md_content += "---\n\n"
                md_content += generate_markdown({
                    "title": clean_name,
                    "body": body
                })

                with open(dest_file, "w", encoding="utf-8") as out:
                    out.write(md_content)

    script_dir = os.path.dirname(os.path.abspath(__file__))
    index_source = os.path.join(script_dir, "index.mdx")
    index_dest = os.path.join(DEST_DIR, "index.mdx")

    if os.path.exists(index_source):
        shutil.copy2(index_source, index_dest)
        print(f"Copied index.mdx to {index_dest}")
    else:
        print(f"Warning: index.mdx not found at {index_source}")

    print("MDX generation complete!")