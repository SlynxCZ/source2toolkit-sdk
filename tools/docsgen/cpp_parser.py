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

A small C++ header scanner for the documentation generator.

It is not a C++ parser. It walks a header once, keeps track of comments,
strings, brackets and access specifiers, and hands back the declarations a
reader of the SDK cares about -- classes and structs with their public fields
and methods, enums, type aliases, macros and free functions -- each with the
doc comment that precedes it (or the `///<` comment that trails it).
"""

import re

# --------------------------------------------------------------------------- #
# Doc comments
# --------------------------------------------------------------------------- #

_TAG_RE = re.compile(r'^[@\\](\w+)\b\s*(.*)$')


def _clean_comment(raw):
    """Comment text without the comment markers and the leading '*' gutter."""
    text = raw.strip()
    if text.startswith('/**') or text.startswith('/*!'):
        text = text[3:]
    elif text.startswith('/*'):
        text = text[2:]
    if text.endswith('*/'):
        text = text[:-2]

    lines = []
    for line in text.split('\n'):
        s = line.strip()
        if s.startswith('///<') or s.startswith('//!<'):
            s = s[4:]
        elif s.startswith('///') or s.startswith('//!'):
            s = s[3:]
        elif s.startswith('*') and not s.startswith('*/'):
            s = s[1:]
        # one leading space is the gutter; keep deeper indentation (code, lists)
        if s.startswith(' '):
            s = s[1:]
        lines.append(s.rstrip())

    # drop leading/trailing blank lines
    while lines and not lines[0].strip():
        lines.pop(0)
    while lines and not lines[-1].strip():
        lines.pop()
    return lines


def _xml_to_tags(lines):
    """Turn C#-style XML doc comments into the @tag form."""
    text = '\n'.join(lines)
    if '<summary>' not in text and '<param' not in text and '<returns>' not in text:
        return lines
    text = re.sub(r'<summary>\s*', '@brief ', text)
    text = re.sub(r'\s*</summary>', '\n', text)
    text = re.sub(r'<param\s+name="([^"]+)">\s*', r'\n@param \1 ', text)
    text = re.sub(r'\s*</param>', '\n', text)
    text = re.sub(r'<typeparam\s+name="([^"]+)">\s*', r'\n@tparam \1 ', text)
    text = re.sub(r'\s*</typeparam>', '\n', text)
    text = re.sub(r'<returns>\s*', '\n@return ', text)
    text = re.sub(r'\s*</returns>', '\n', text)
    text = re.sub(r'<remarks>\s*', '\n', text)
    text = re.sub(r'\s*</remarks>', '\n', text)
    text = re.sub(r'<see\s+cref="([^"]+)"\s*/>', r'`\1`', text)
    text = re.sub(r'<c>(.*?)</c>', r'`\1`', text)
    return text.split('\n')


def parse_doc(raw):
    """Parse a doc comment into its parts.

    Returns a dict with: brief, body (list of markdown paragraphs/blocks),
    params {name: text}, tparams, returns, notes, warnings, see, deprecated.
    """
    doc = {
        'brief': '', 'body': [], 'params': {}, 'tparams': {}, 'returns': '',
        'notes': [], 'warnings': [], 'see': [], 'deprecated': '',
    }
    if not raw:
        return doc

    lines = _xml_to_tags(_clean_comment(raw))

    body_lines = []
    current = None  # (kind, key) of the tag being continued
    in_code = False
    code_lines = []

    def append_to_current(text):
        kind, key = current
        if kind in ('params', 'tparams'):
            doc[kind][key] = (doc[kind][key] + ' ' + text).strip()
        elif kind in ('notes', 'warnings', 'see'):
            doc[kind][-1] = (doc[kind][-1] + ' ' + text).strip()
        else:
            doc[kind] = (doc[kind] + ' ' + text).strip()

    for line in lines:
        stripped = line.strip()

        if in_code:
            if re.match(r'^[@\\]endcode\b', stripped):
                in_code = False
                # common indentation of the block
                indents = [len(l) - len(l.lstrip()) for l in code_lines if l.strip()]
                cut = min(indents) if indents else 0
                block = '\n'.join(l[cut:] for l in code_lines).strip('\n')
                body_lines.append('```cpp\n' + block + '\n```')
                code_lines = []
            else:
                code_lines.append(line)
            continue

        if re.match(r'^[@\\]code\b', stripped):
            in_code = True
            current = None
            continue

        if re.match(r'^[@\\](file|class|struct|fn|def|var|typedef|defgroup|ingroup|internal)\b', stripped):
            current = None
            continue

        m = _TAG_RE.match(stripped)
        if m:
            tag, rest = m.group(1).lower(), m.group(2).strip()
            if tag == 'brief':
                doc['brief'] = rest
                current = ('brief', None)
            elif tag in ('param', 'tparam'):
                rest = re.sub(r'^\[(in|out|in,out)\]\s*', '', rest)
                parts = rest.split(None, 1)
                name = parts[0] if parts else ''
                kind = 'params' if tag == 'param' else 'tparams'
                doc[kind][name] = parts[1] if len(parts) > 1 else ''
                current = (kind, name)
            elif tag in ('return', 'returns', 'retval'):
                doc['returns'] = rest
                current = ('returns', None)
            elif tag in ('note', 'remark', 'remarks', 'attention'):
                doc['notes'].append(rest)
                current = ('notes', None)
            elif tag in ('warning', 'bug'):
                doc['warnings'].append(rest)
                current = ('warnings', None)
            elif tag in ('see', 'sa'):
                doc['see'].append(rest)
                current = ('see', None)
            elif tag == 'deprecated':
                doc['deprecated'] = rest or 'Deprecated.'
                current = ('deprecated', None)
            else:
                body_lines.append(stripped)
                current = None
            continue

        if not stripped:
            current = None
            body_lines.append('')
            continue

        if current is not None:
            append_to_current(stripped)
        else:
            body_lines.append(line)

    # the text before any tag and without @brief: first paragraph is the brief
    paragraphs = _paragraphs(body_lines)
    if not doc['brief'] and paragraphs and not paragraphs[0].startswith('```') \
            and not paragraphs[0].lstrip().startswith(('* ', '- ')):
        doc['brief'] = paragraphs.pop(0)
    doc['body'] = paragraphs
    return doc


def _paragraphs(lines):
    """Group lines into markdown blocks: paragraphs, lists and code fences."""
    blocks = []
    current = []

    def flush():
        if current:
            blocks.append(_join_block(current))
            current.clear()

    for line in lines:
        if line.startswith('```'):
            flush()
            blocks.append(line)
            continue
        if not line.strip():
            flush()
            continue
        current.append(line)
    flush()
    return [b for b in blocks if b.strip()]


def _join_block(lines):
    """Join wrapped lines; keep list items (`* x`, `- x`, `1. x`) on their own lines."""
    out = []
    for line in lines:
        s = line.strip()
        is_item = re.match(r'^([*\-+]|\d+\.)\s+', s)
        if is_item or not out:
            out.append(re.sub(r'^\*\s+', '- ', s) if is_item else s)
        elif out and re.match(r'^(- |\d+\. )', out[-1]) and line.startswith('  '):
            out[-1] += ' ' + s          # continuation of a list item
        elif out and re.match(r'^(- |\d+\. )', out[-1]):
            out[-1] += ' ' + s
        else:
            out[-1] += ' ' + s
    return '\n'.join(out)


def is_empty_doc(doc):
    return not (doc['brief'] or doc['body'] or doc['params'] or doc['returns']
                or doc['notes'] or doc['warnings'])


# --------------------------------------------------------------------------- #
# Scanner
# --------------------------------------------------------------------------- #

class _Scanner:
    def __init__(self, text):
        self.t = text
        self.n = len(text)

    def skip_string(self, i):
        q = self.t[i]
        i += 1
        while i < self.n:
            c = self.t[i]
            if c == '\\':
                i += 2
                continue
            if c == q:
                return i + 1
            i += 1
        return i

    def skip_raw_string(self, i):
        # R"delim( ... )delim"
        m = re.match(r'R"([^(]*)\(', self.t[i:i + 20])
        if not m:
            return i + 1
        end = self.t.find(')' + m.group(1) + '"', i)
        return self.n if end < 0 else end + len(m.group(1)) + 2

    def match_brace(self, i):
        """Index just past the '}' matching the '{' at i."""
        depth = 0
        while i < self.n:
            c = self.t[i]
            if self.t.startswith('//', i):
                j = self.t.find('\n', i)
                i = self.n if j < 0 else j
                continue
            if self.t.startswith('/*', i):
                j = self.t.find('*/', i + 2)
                i = self.n if j < 0 else j + 2
                continue
            if c in '"\'':
                if c == '"' and i > 0 and self.t[i - 1] == 'R':
                    i = self.skip_raw_string(i - 1)
                else:
                    i = self.skip_string(i)
                continue
            if c == '{':
                depth += 1
            elif c == '}':
                depth -= 1
                if depth == 0:
                    return i + 1
            i += 1
        return self.n


def _items(text, start, end):
    """Yield ('doc', raw) / ('trail', raw) / ('pp', line) / ('stmt', text, term, pos_after)
    for the scope text[start:end]. term is ';' or '{' (or ':' for access labels, None at EOF).
    For '{' statements pos_after points at the '{'.
    """
    s = _Scanner(text)
    i = start
    stmt_start = None
    paren = 0
    angle_hint = 0
    last_stmt_line_end = -1

    while i < end:
        c = text[i]

        # ---------- comments ----------
        if text.startswith('//', i):
            j = text.find('\n', i)
            j = end if j < 0 or j > end else j
            comment = text[i:j]
            if stmt_start is None:
                # a trailing comment on the line of the previous statement
                line_start = text.rfind('\n', 0, i) + 1
                if last_stmt_line_end >= line_start:
                    yield ('trail', comment)
                elif comment.startswith('///') or comment.startswith('//!'):
                    # gather consecutive /// lines
                    k = j
                    block = [comment]
                    while True:
                        m = re.match(r'\n[ \t]*(///[^\n]*|//![^\n]*)', text[k:end])
                        if not m:
                            break
                        block.append(m.group(1))
                        k += m.end()
                    yield ('doc', '\n'.join(block))
                    j = k
            elif comment.startswith('///<'):
                pass  # inside a statement; rare
            i = j
            continue

        if text.startswith('/*', i):
            j = text.find('*/', i + 2)
            j = end if j < 0 else j + 2
            if stmt_start is None:
                raw = text[i:j]
                if raw.startswith('/**') or raw.startswith('/*!'):
                    line_start = text.rfind('\n', 0, i) + 1
                    if raw.startswith('/**<') and last_stmt_line_end >= line_start:
                        yield ('trail', raw)
                    else:
                        yield ('doc', raw)
            i = j
            continue

        # ---------- preprocessor ----------
        if c == '#' and stmt_start is None:
            j = i
            while True:
                k = text.find('\n', j)
                if k < 0 or k >= end:
                    k = end
                    break
                if text[k - 1] == '\\':
                    j = k + 1
                    continue
                break
            yield ('pp', text[i:k])
            i = k
            continue

        if c in ' \t\r\n':
            i += 1
            continue

        # ---------- statements ----------
        if stmt_start is None:
            stmt_start = i
            paren = 0
            m = re.match(r'(public|private|protected)\s*:(?!:)', text[i:end])
            if m:
                yield ('stmt', m.group(1), ':', i + m.end())
                i += m.end()
                stmt_start = None
                continue

        if c in '"\'':
            if c == '"' and i > 0 and text[i - 1] == 'R':
                i = s.skip_raw_string(i - 1)
            else:
                i = s.skip_string(i)
            continue
        if c in '([':
            paren += 1
        elif c in ')]':
            paren -= 1
        elif c == ';' and paren <= 0:
            stmt = text[stmt_start:i]
            last_stmt_line_end = i
            yield ('stmt', stmt, ';', i + 1)
            stmt_start = None
            i += 1
            continue
        elif c == '{' and paren <= 0:
            stmt = text[stmt_start:i]
            # the consumer tells us where to continue (past the body) through .send()
            nxt = yield ('stmt', stmt, '{', i)
            stmt_start = None
            last_stmt_line_end = -1
            i = nxt if nxt is not None else s.match_brace(i)
            continue
        elif c == '}' and paren <= 0:
            # stray closing brace (end of an enclosing scope we were not given)
            i += 1
            stmt_start = None
            continue
        i += 1

    if stmt_start is not None and text[stmt_start:end].strip():
        yield ('stmt', text[stmt_start:end], None, end)


# --------------------------------------------------------------------------- #
# Declarations
# --------------------------------------------------------------------------- #

_SPECIFIERS = ('virtual', 'static', 'inline', 'constexpr', 'explicit', 'extern',
               'friend', 'consteval', 'constinit', 'mutable', 'FORCEINLINE')


def _norm(s):
    return re.sub(r'\s+', ' ', s).strip()


def _strip_attributes(s):
    s = re.sub(r'\[\[.*?\]\]', ' ', s)
    s = re.sub(r'__declspec\s*\([^)]*\)', ' ', s)
    s = re.sub(r'__attribute__\s*\(\(.*?\)\)', ' ', s)
    return _norm(s)


def _split_template(s):
    """('template<...>', rest) when s starts with a template header."""
    m = re.match(r'template\s*<', s)
    if not m:
        return '', s
    depth = 0
    for i in range(m.end() - 1, len(s)):
        if s[i] == '<':
            depth += 1
        elif s[i] == '>':
            depth -= 1
            if depth == 0:
                return _norm(s[:i + 1]), s[i + 1:].strip()
    return '', s


def split_params(params):
    result, current, depth = [], '', 0
    for c in params:
        if c in '<([{':
            depth += 1
        elif c in '>)]}':
            depth -= 1
        if c == ',' and depth == 0:
            result.append(current.strip())
            current = ''
        else:
            current += c
    if current.strip():
        result.append(current.strip())
    return result


def _parse_param(p):
    p = _norm(p)
    default = ''
    # split off a default value (first top-level '=')
    depth = 0
    for i, c in enumerate(p):
        if c in '<([{':
            depth += 1
        elif c in '>)]}':
            depth -= 1
        elif c == '=' and depth == 0:
            default = p[i + 1:].strip()
            p = p[:i].strip()
            break
    if p in ('void', '...'):
        return {'type': p, 'name': '', 'default': ''} if p == '...' else None
    # function pointer parameter: R (*name)(args)
    m = re.match(r'^(.*?\(\s*[*&]\s*)(\w+)(\s*\).*)$', p)
    if m:
        return {'type': _norm(m.group(1) + m.group(3)), 'name': m.group(2), 'default': default}
    m = re.match(r'^(.+?[\s*&>])(\w+)(\s*\[[^\]]*\])?$', p)
    if m and m.group(1).strip() not in ('const', 'unsigned', 'signed', 'struct', 'class', 'enum'):
        return {'type': _norm(m.group(1) + (m.group(3) or '')), 'name': m.group(2), 'default': default}
    return {'type': p, 'name': '', 'default': default}


def _find_call_paren(s):
    """Index of the '(' that opens the parameter list of a function declaration."""
    depth_angle = 0
    i = 0
    while i < len(s):
        c = s[i]
        if c == '<':
            depth_angle += 1
        elif c == '>':
            depth_angle = max(0, depth_angle - 1)
        elif c == '(' and depth_angle == 0:
            before = s[:i].rstrip()
            # `(*name)` is a function pointer, not a call
            if re.search(r'(operator\s*(\(\)|[^\w\s(]+|\w[\w\s]*))$', before) or re.search(r'[\w~>]$', before):
                return i
        i += 1
    return -1


def _match_paren(s, i):
    depth = 0
    for j in range(i, len(s)):
        if s[j] == '(':
            depth += 1
        elif s[j] == ')':
            depth -= 1
            if depth == 0:
                return j
    return len(s) - 1


def parse_function(stmt, class_name=None):
    """A function/method/constructor declaration, or None."""
    s = _strip_attributes(stmt)
    template, s = _split_template(s)
    # function pointer variable: R (*name)(args)
    if re.match(r'^[^(]*\(\s*[*&]\s*\w+\s*\)\s*\(', s):
        return None
    p = _find_call_paren(s)
    if p < 0:
        return None
    head = s[:p].rstrip()
    close = _match_paren(s, p)
    params_text = s[p + 1:close]
    tail = s[close + 1:]

    m = re.search(r'(operator\s*(?:\(\)|[^\w\s(]+|\w[\w\s:*&<>]*)|~?\w+)$', head)
    if not m:
        return None
    name = _norm(m.group(1))
    ret = head[:m.start()].strip()

    specs = []
    while True:
        mm = re.match(r'^(%s)\b\s*' % '|'.join(_SPECIFIERS), ret)
        if not mm:
            break
        specs.append(mm.group(1))
        ret = ret[mm.end():]
    ret = _norm(ret)

    # a statement like `return Foo(x)` or a macro call is not a declaration
    if ret in ('return', 'else', 'if', 'while', 'for', 'do', 'switch', 'case', 'delete', 'new', 'throw'):
        return None
    is_ctor = class_name is not None and name in (class_name, '~' + class_name)
    if not ret and not is_ctor and not name.startswith('operator'):
        return None  # macro invocation or similar

    params = []
    if params_text.strip() and params_text.strip() != 'void':
        for part in split_params(params_text):
            prm = _parse_param(part)
            if prm:
                params.append(prm)

    qual = []
    if re.search(r'\bconst\b', tail.split('=')[0]):
        qual.append('const')
    if 'noexcept' in tail:
        qual.append('noexcept')
    pure = bool(re.search(r'=\s*0\s*$', tail.strip()))
    deleted = bool(re.search(r'=\s*delete', tail))

    # signature: everything up to the parameter list's ')' plus the qualifiers,
    # without a constructor's initialiser list or an inline body
    tail_clean = re.split(r'(?<!:):(?!:)', tail)[0].strip()
    # `s` still carries the specifiers (they were only stripped from `ret`)
    signature = (template + ' ' if template else '') + s[:close + 1]
    if tail_clean:
        signature += ' ' + tail_clean
    return {
        'kind': 'function', 'name': name, 'return': ret, 'params': params,
        'specifiers': specs, 'template': template, 'qualifiers': qual,
        'pure': pure, 'deleted': deleted, 'is_ctor': is_ctor,
        'signature': _pretty_signature(signature),
    }


def _pretty_signature(sig):
    sig = _strip_attributes(sig)
    sig = re.sub(r'\s*\boverride\b', ' override', sig)
    sig = re.sub(r'\s+', ' ', sig).strip()
    sig = re.sub(r'\(\s+', '(', sig)
    sig = re.sub(r'\s+\)', ')', sig)
    sig = re.sub(r'\s*,\s*', ', ', sig)
    return sig.rstrip(';').rstrip() + ';'


def parse_variable(stmt):
    """A data member / variable declaration: {'type','name','array','default'} or None."""
    s = _strip_attributes(stmt)
    if not s or s.startswith(('using ', 'typedef ', 'friend ', 'static_assert', 'template')):
        return None
    specs = []
    while True:
        mm = re.match(r'^(%s)\b\s*' % '|'.join(_SPECIFIERS), s)
        if not mm:
            break
        specs.append(mm.group(1))
        s = s[mm.end():]
    init = ''
    depth = 0
    for i, c in enumerate(s):
        if c in '<([{':
            depth += 1
        elif c in '>)]}':
            depth -= 1
        elif c == '=' and depth == 0:
            init = s[i + 1:].strip()
            s = s[:i].strip()
            break
    m = re.match(r'^(?:.*?\(\s*\*\s*(\w+)\s*\).*)$', s)
    if m and '(' in s:
        return {'type': _norm(s.replace(m.group(1), '', 1)), 'name': m.group(1), 'array': '',
                'default': init, 'specifiers': specs}
    m = re.match(r'^(.+?[\s*&>])(\w+)\s*((?:\[[^\]]*\]\s*)*)(?::\s*\d+)?$', s)
    if not m:
        return None
    typ = _norm(m.group(1))
    if typ in ('return', 'goto', 'case', 'else', 'using', 'namespace'):
        return None
    return {'type': typ, 'name': m.group(2), 'array': _norm(m.group(3)),
            'default': init, 'specifiers': specs}


def _trail_text(raw):
    """Text of a trailing comment, or '' when it is only an offset annotation."""
    t = raw.strip()
    if t.startswith('///<') or t.startswith('//!<'):
        return t[4:].strip()
    if t.startswith('/**<'):
        return t[4:].rstrip('*/').strip()
    if t.startswith('//'):
        t = t.lstrip('/').strip()
        # `// 0x8 | 8`, `// 0x55`, `// +0x10` -- layout notes, not documentation
        if re.match(r'^[+]?(0x[0-9a-fA-F]+|\d+)\b', t):
            return ''
        return t
    return ''


# --------------------------------------------------------------------------- #
# Scopes
# --------------------------------------------------------------------------- #

_RECORD_RE = re.compile(
    r'^(?:template\s*<.*?>\s*)?(class|struct|union)\s+'
    r'(?:\w+\s+)*?'                           # attributes/macros like TOOLKIT_API
    r'(\w+)\s*(?:final\s*)?'
    r'(?::\s*(.+))?$', re.S)
_ENUM_RE = re.compile(r'^enum\s+(class\s+|struct\s+)?(\w+)?\s*(?::\s*([\w:\s]+))?$', re.S)


def _parse_bases(text):
    bases = []
    for part in split_params(text or ''):
        part = re.sub(r'\b(public|private|protected|virtual)\b', '', part)
        part = _norm(part)
        if part:
            bases.append(part)
    return bases


def _parse_enum_body(text, name, is_class, underlying, doc):
    values = []
    pending_doc = None
    # split into entries on top-level commas, keeping comments with their entry
    entries = []
    current = ''
    depth = 0
    i = 0
    while i < len(text):
        if text.startswith('//', i):
            j = text.find('\n', i)
            j = len(text) if j < 0 else j
            current += text[i:j] + '\n'
            i = j
            continue
        if text.startswith('/*', i):
            j = text.find('*/', i + 2)
            j = len(text) if j < 0 else j + 2
            current += text[i:j] + '\n'
            i = j
            continue
        c = text[i]
        if c in '([{':
            depth += 1
        elif c in ')]}':
            depth -= 1
        if c == ',' and depth == 0:
            # a trailing comment on the same line belongs to this entry
            k = i + 1
            m = re.match(r'[ \t]*(//[^\n]*|/\*.*?\*/)', text[k:], re.S)
            if m:
                current += ',' + m.group(1)
                i = k + m.end()
            else:
                i += 1
            entries.append(current)
            current = ''
            continue
        current += c
        i += 1
    if current.strip():
        entries.append(current)

    for entry in entries:
        docs = []
        trail = ''
        code = []
        for line in entry.split('\n'):
            s = line.strip()
            if not s:
                continue
            m = re.match(r'^(.*?)(,)?\s*(///<.*|//!<.*|//.*|/\*\*<.*)$', s)
            if s.startswith(('///', '/**', '//!', '/*!')) and not s.startswith(('///<', '/**<')):
                docs.append(s)
            elif s.startswith('//') or s.startswith('/*'):
                docs.append('/// ' + s.lstrip('/*').rstrip('*/').strip()) if not docs else None
            elif m and m.group(3):
                code.append(m.group(1))
                trail = _trail_text(m.group(3))
            else:
                code.append(s)
        decl = _norm(' '.join(code)).rstrip(',').strip()
        if not decl:
            continue
        m = re.match(r'^(\w+)\s*(?:=\s*(.+))?$', decl)
        if not m:
            continue
        vdoc = parse_doc('\n'.join(docs)) if docs else parse_doc('')
        if trail and not vdoc['brief']:
            vdoc['brief'] = trail
        values.append({'name': m.group(1), 'value': (m.group(2) or '').strip(), 'doc': vdoc})

    return {'kind': 'enum', 'name': name, 'is_class': is_class,
            'underlying': underlying, 'values': values, 'doc': doc}


def parse_scope(text, start, end, record=None):
    """Parse a scope. `record` is the class dict when parsing a class body."""
    out = {'classes': [], 'enums': [], 'typedefs': [], 'functions': [],
           'macros': [], 'variables': []}
    access = 'public'
    if record is not None:
        access = 'private' if record['keyword'] == 'class' else 'public'

    pending_doc = None
    last_decl = None
    gen = _items(text, start, end)
    to_send = None
    scanner = _Scanner(text)

    while True:
        try:
            item = gen.send(to_send)
        except StopIteration:
            break
        to_send = None
        if item is None:
            continue
        kind = item[0]

        if kind == 'doc':
            raw = item[1]
            # license / editor-modeline blocks are not documentation
            if re.search(r'vim:\s*set|GNU General Public License|Copyright \(C\)|Copyright ©', raw):
                pending_doc = None
            else:
                pending_doc = raw
            continue
        if kind == 'trail':
            if last_decl is not None:
                t = _trail_text(item[1])
                if t and not last_decl['doc']['brief']:
                    last_decl['doc']['brief'] = t
            continue
        if kind == 'pp':
            line = item[1]
            m = re.match(r'#\s*define\s+(\w+)(\([^)]*\))?\s*(.*)$', line, re.S)
            if not m:
                # #include / #pragma / #if...: a doc comment above them documented
                # the file, not whatever comes next
                if not re.match(r'#\s*(if|ifdef|ifndef|else|elif|endif)\b', line):
                    pending_doc = None
                continue
            if record is None and (m.group(1).endswith('_H') or m.group(1).startswith('_')):
                continue  # include guards
            if record is None:
                name = m.group(1)
                body = m.group(3).replace('\\\n', '\n')
                macro = {'kind': 'macro', 'name': name, 'params': m.group(2) or '',
                         'value': body.strip(), 'doc': parse_doc(pending_doc),
                         'raw_doc': pending_doc}
                out['macros'].append(macro)
                last_decl = macro
                # an interface's doc sits on the TOOLKIT_*_INTERFACE define right
                # above the class; let it fall through to the class as well
                if not name.endswith('_INTERFACE'):
                    pending_doc = None
            continue

        _, stmt, term, pos = item
        doc_raw = pending_doc
        pending_doc = None
        s = _norm(stmt)

        if term == ':':
            if record is not None:
                access = s
            continue

        if term == '{':
            body_end = scanner.match_brace(pos)
            head = _strip_attributes(s)
            rec = _RECORD_RE.match(head)
            en = _ENUM_RE.match(head)
            if en and head.startswith('enum'):
                e = _parse_enum_body(text[pos + 1:body_end - 1], en.group(2) or '',
                                     bool(en.group(1)), _norm(en.group(3) or ''), parse_doc(doc_raw))
                if record is None or access == 'public':
                    (record['enums'] if record is not None else out['enums']).append(e) if e['name'] else None
                last_decl = None
            elif rec and not re.search(r'\)\s*$', head.split(':')[0]):
                cls = {'kind': 'record', 'keyword': rec.group(1), 'name': rec.group(2),
                       'bases': _parse_bases(rec.group(3)), 'template': _split_template(head)[0],
                       'doc': parse_doc(doc_raw), 'fields': [], 'methods': [],
                       'schema_fields': [], 'enums': [], 'typedefs': [], 'nested': [],
                       'schema_class': False}
                inner = parse_scope(text, pos + 1, body_end - 1, cls)
                cls['nested'] = inner['classes']
                if record is None:
                    out['classes'].append(cls)
                elif access == 'public':
                    record['nested'].append(cls)
                last_decl = None
            elif head.startswith('namespace') or head.startswith('extern "C"') or head.startswith("extern"):
                inner = parse_scope(text, pos + 1, body_end - 1, None)
                for k in out:
                    out[k].extend(inner[k])
                last_decl = None
            else:
                # a function definition (or an initialiser); the body is skipped
                f = parse_function(stmt, record['name'] if record else None)
                if f and (record is None or access == 'public'):
                    f['doc'] = parse_doc(doc_raw)
                    f['inline'] = True
                    (record['methods'] if record is not None else out['functions']).append(f)
                    last_decl = f
                else:
                    last_decl = None
            # continue after the body, and after a trailing `;` of a record
            to_send = body_end
            m = re.match(r'\s*(\w[\w\s,*&]*)?;', text[body_end:body_end + 200])
            if (rec or en) and m:
                to_send = body_end + m.end()
            continue

        if term != ';':
            continue

        # ----- a statement ending in ';' -----
        if record is not None and access != 'public':
            last_decl = None
            continue

        # schema fields
        m = re.match(r'^SCHEMA_FIELD(_POINTER)?\s*\((.*),\s*(\w+)\s*\)$', s)
        if m and record is not None:
            fld = {'type': _norm(m.group(2)), 'name': m.group(3), 'pointer': bool(m.group(1)),
                   'doc': parse_doc(doc_raw)}
            record['schema_fields'].append(fld)
            last_decl = fld
            continue
        if re.match(r'^DECLARE_SCHEMA_CLASS', s):
            if record is not None:
                record['schema_class'] = True
            continue
        if re.match(r'^[A-Z_][A-Z0-9_]*\s*\(', s) and not re.match(r'^[A-Z_][A-Z0-9_]*\s*\([^)]*\)\s*\w', s):
            last_decl = None
            continue  # macro invocation

        # aliases
        m = re.match(r'^(?:template\s*<.*?>\s*)?using\s+(\w+)\s*=\s*(.+)$', s, re.S)
        if m:
            td = {'kind': 'typedef', 'name': m.group(1), 'target': _norm(m.group(2)),
                  'decl': _pretty_signature(s), 'doc': parse_doc(doc_raw)}
            (record['typedefs'] if record is not None else out['typedefs']).append(td)
            last_decl = td
            continue
        if s.startswith('typedef '):
            mm = re.search(r'(\w+)\s*(\[[^\]]*\])?\s*$', s) or None
            fp = re.search(r'\(\s*[A-Z_]*\s*\*\s*(\w+)\s*\)', s)
            name = fp.group(1) if fp else (mm.group(1) if mm else '')
            if name:
                td = {'kind': 'typedef', 'name': name, 'target': _norm(s[8:]),
                      'decl': _pretty_signature(s), 'doc': parse_doc(doc_raw)}
                (record['typedefs'] if record is not None else out['typedefs']).append(td)
                last_decl = td
            continue
        if s.startswith(('using namespace', 'using ', 'static_assert', 'friend ', 'template class')):
            continue
        if re.match(r'^(class|struct|enum|union)\s+[\w:]+$', s):
            continue  # forward declaration

        f = parse_function(stmt, record['name'] if record else None)
        if f:
            f['doc'] = parse_doc(doc_raw)
            f['inline'] = False
            (record['methods'] if record is not None else out['functions']).append(f)
            last_decl = f
            continue

        v = parse_variable(stmt)
        if v:
            v['doc'] = parse_doc(doc_raw)
            v['decl'] = _pretty_signature(s)
            (record['fields'] if record is not None else out['variables']).append(v)
            last_decl = v
            continue
        last_decl = None

    return out


def _file_doc(content):
    """The @file block (or the first doc comment before any declaration)."""
    for m in re.finditer(r'/\*\*.*?\*/', content, re.S):
        raw = m.group(0)
        if re.search(r'[@\\]file\b', raw):
            return parse_doc(raw)
    return parse_doc('')


def parse_header(content):
    content = content.lstrip('\ufeff')
    result = parse_scope(content, 0, len(content))
    result['file_doc'] = _file_doc(content)
    # interface ids: #define TOOLKIT_X_INTERFACE "IToolkitX001"
    result['interfaces'] = {
        m.group(1): m.group(2)
        for m in re.finditer(r'#\s*define\s+(TOOLKIT_\w+_INTERFACE)\s+"([^"]+)"', content)
    }
    return result
