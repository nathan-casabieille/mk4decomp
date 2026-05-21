#!/usr/bin/env python3
"""Extract function-by-function content from a misc_matches*.c file.

Outputs: for each function in the file, prints its name, group, address,
size, and the source span (start_line, end_line) within the input file.

Used to drive the misc_matches reorganization: pipe output into manual
or scripted file-moves.
"""
import sys, re, yaml, os

def main():
    if len(sys.argv) != 2:
        print('usage: extract_misc_funcs.py <src/engine/misc_matchesXX.c>', file=sys.stderr)
        sys.exit(1)
    path = sys.argv[1]

    with open('config/symbols.yaml') as f:
        syms = yaml.safe_load(f)
    name_to_group = {s['name']: s.get('group', 'unknown') for s in syms['functions']}
    name_to_size = {s['name']: s.get('size', 0) for s in syms['functions']}
    name_to_addr = {s['name']: s.get('addr', 0) for s in syms['functions']}
    name_to_file = {s['name']: s.get('file', '') for s in syms['functions']}

    with open(path) as f:
        lines = f.readlines()

    # Find each function definition (both naked and pure-C/hybrid)
    fn_pattern = re.compile(r'^(?:__declspec\(naked\)\s+)?(?:static\s+)?(?:extern\s+)?(?:unsigned\s+)?(\w+\s*\**)\s+(\w+_[0-9a-fA-F]{8})\s*\(')
    funcs = []
    i = 0
    while i < len(lines):
        m = fn_pattern.match(lines[i])
        if m and m.group(2) in name_to_file and name_to_file[m.group(2)] == path:
            name = m.group(2)
            start = i
            # Walk forward to find end of function (matching closing brace at column 0)
            depth = 0
            j = i
            opened = False
            while j < len(lines):
                line = lines[j]
                # Count { and } at all positions (rough but works)
                for ch in line:
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
            end = j
            funcs.append({
                'name': name,
                'group': name_to_group.get(name, 'unknown'),
                'addr': name_to_addr.get(name, 0),
                'size': name_to_size.get(name, 0),
                'start_line': start + 1,
                'end_line': end + 1,
            })
            i = end + 1
        else:
            i += 1

    for fn in funcs:
        print(f"{fn['name']:<55} {fn['group']:<22} addr=0x{fn['addr']:x} size={fn['size']:>4}b lines={fn['start_line']}..{fn['end_line']}")
    print(f"\nTotal: {len(funcs)} functions in {path}")

if __name__ == '__main__':
    main()
