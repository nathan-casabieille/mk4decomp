#!/usr/bin/env python3
"""Split a misc_matches*.c file into per-function (or per-cluster) files.

Usage: split_misc.py <input.c> <output_dir> <mapping.json>

mapping.json: { "FunctionName_HHHHHHHH": "output_filename.c", ... }
              functions with same output_filename go in same file.

Extracts the function definition (with preceding comment block + externs)
and writes each output file with a header doc-comment.

Also updates symbols.yaml `file:` entries for each function.
Does NOT delete the input file (caller handles that).
"""
import sys, re, json, os

def find_func_span(lines, fn_name):
    """Find the line span of fn_name's definition in `lines`.
    Returns (preceding_comment_start, fn_start, fn_end) all inclusive 0-indexed.
    """
    # Find the function definition line (handle multi-word return types)
    pat = re.compile(r'^(?:__declspec\(naked\)\s+)?(?:static\s+)?(?:extern\s+)?(?:(?:unsigned|signed)\s+)?\w+(?:\s*\*)?\s+' + re.escape(fn_name) + r'\s*\(')
    fn_start = None
    for i, line in enumerate(lines):
        if pat.match(line):
            fn_start = i
            break
    if fn_start is None:
        return None
    # Walk forward to find end of function body
    depth = 0
    opened = False
    j = fn_start
    while j < len(lines):
        for ch in lines[j]:
            if ch == '{':
                depth += 1
                opened = True
            elif ch == '}':
                depth -= 1
                if opened and depth == 0:
                    break
        if opened and depth == 0:
            break
        j += 1
    fn_end = j
    # Find preceding comment block: walk backward from fn_start over extern declarations and /* */ blocks
    # The block ends at fn_start - 1. The block starts where the previous block ends + 1.
    # Heuristic: scan upward from fn_start - 1, skipping extern lines and /* */ comments,
    # stopping at a blank line or a non-extern-non-comment line.
    k = fn_start - 1
    while k >= 0:
        line = lines[k].strip()
        # Allow: extern decls, /* */ comments (single line or end of block)
        if line.startswith('extern ') and line.endswith(';'):
            k -= 1
            continue
        if line.endswith('*/'):
            # Walk up to start of comment block
            while k >= 0 and not lines[k].lstrip().startswith('/*'):
                k -= 1
            if k >= 0:
                k -= 1  # skip the /* line too
            continue
        # If line is empty, stop (separator between functions)
        if line == '':
            break
        # Anything else (e.g., closing brace of prior function): stop
        break
    comment_start = k + 1
    return (comment_start, fn_start, fn_end)

def main():
    if len(sys.argv) != 4:
        print('usage: split_misc.py <input.c> <output_dir> <mapping.json>', file=sys.stderr)
        sys.exit(1)
    input_path, output_dir, mapping_path = sys.argv[1:]
    with open(mapping_path) as f:
        mapping = json.load(f)
    with open(input_path) as f:
        lines = f.readlines()

    # Pull the header (#include lines + shared externs at top, before any function)
    header_end = 0
    pat = re.compile(r'^(?:__declspec\(naked\)\s+)?(?:static\s+)?(?:extern\s+)?(?:(?:unsigned|signed)\s+)?\w+(?:\s*\*)?\s+(\w+_[0-9a-fA-F]{8})\s*\(')
    for i, line in enumerate(lines):
        if pat.match(line) and pat.match(line).group(1) in mapping:
            header_end = i
            break
    # Walk back to find shared externs that belong to NO specific function
    # (extern lines that come right before the first function)
    # Simplest: include everything from line 0 to first function comment
    # Actually take everything from line 0 up to (first comment block start of first function)
    first_span = find_func_span(lines, list(mapping.keys())[0])
    if first_span:
        header_end = first_span[0]
    header = ''.join(lines[:header_end])
    # Strip trailing blank lines from header
    header = header.rstrip() + '\n'

    # Group functions by output file
    by_file = {}
    for fn, out in mapping.items():
        by_file.setdefault(out, []).append(fn)

    # Process each output file
    for out_path, fns in by_file.items():
        spans = []
        for fn in fns:
            s = find_func_span(lines, fn)
            if s is None:
                print(f'WARN: {fn} not found in {input_path}', file=sys.stderr)
                continue
            spans.append((s, fn))
        # Sort by source order
        spans.sort(key=lambda x: x[0][0])
        # Build the new file content
        parts = []
        # Use the original header (includes + shared externs)
        parts.append('/**\n * Auto-extracted from ' + os.path.basename(input_path) + ' during misc_matches reorganization.\n */\n')
        parts.append(header[len('/**\n'):] if header.startswith('/**\n') else header)
        # Strip leading /** ... */ doc comment from header if present
        # (keep includes + externs only)
        clean_header = header
        # If header starts with /** ... */, drop that
        m = re.match(r'^/\*\*[\s\S]*?\*/\s*\n', header)
        if m:
            clean_header = header[m.end():]
        # Rebuild parts
        parts = []
        parts.append('/**\n * Auto-split from ' + os.path.basename(input_path) + '\n */\n')
        parts.append(clean_header.rstrip() + '\n\n')
        for span, fn in spans:
            cs, fs, fe = span
            block = ''.join(lines[cs:fe+1])
            parts.append(block)
            if not block.endswith('\n'):
                parts.append('\n')
            parts.append('\n')
        full = ''.join(parts).rstrip() + '\n'
        # Write the file - APPEND if exists, write fresh if not
        os.makedirs(os.path.dirname(out_path), exist_ok=True)
        if os.path.exists(out_path):
            # Append only the function bodies (skip header)
            append_parts = []
            for span, fn in spans:
                cs, fs, fe = span
                block = ''.join(lines[cs:fe+1])
                append_parts.append('\n')
                append_parts.append(block)
                if not block.endswith('\n'):
                    append_parts.append('\n')
            with open(out_path, 'a') as f:
                f.write(''.join(append_parts))
            print(f'  appended to {out_path} ({len(fns)} fns)')
        else:
            with open(out_path, 'w') as f:
                f.write(full)
            print(f'  wrote {out_path} ({len(fns)} fns)')

    # Update symbols.yaml
    print('updating symbols.yaml...')
    with open('config/symbols.yaml') as f:
        sym_content = f.read()
    count = 0
    src_re = input_path.replace('.', r'\.')
    for fname, new_path in mapping.items():
        pattern = re.compile(r'(name:\s+' + re.escape(fname) + r'\n(?:    [^\n]*\n)*?    file: )' + src_re)
        new_sym, n = pattern.subn(r'\g<1>' + new_path, sym_content)
        sym_content = new_sym
        count += n
    with open('config/symbols.yaml', 'w') as f:
        f.write(sym_content)
    print(f'  updated {count} entries')

if __name__ == '__main__':
    main()
