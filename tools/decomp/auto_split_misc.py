#!/usr/bin/env python3
"""Auto-process a misc_matches*.c file end-to-end.

For each function in the file, infers a target filename from its name
(e.g., CallPauseScaledStoreJmp_004XXXXX -> call_pause_scaled_store_jmp.c)
and groups by `group` field from symbols.yaml:
  - boot     -> src/boot/
  - audio    -> src/audio/
  - crt      -> src/crt/
  - other groups -> src/engine/

Sister functions (same base name, different hex suffix) are grouped into
one cluster file named <base>_variants.c.

Usage: auto_split_misc.py <input.c> [--dry-run]
"""
import sys, re, json, os, yaml, subprocess

def to_snake(name):
    """Convert CamelCase function name to snake_case filename."""
    # Drop the _HHHHHHHH suffix
    base = re.sub(r'_[0-9a-fA-F]{8}$', '', name)
    # Convert CamelCase to snake_case
    out = re.sub(r'([A-Z]+)([A-Z][a-z])', r'\1_\2', base)
    out = re.sub(r'([a-z0-9])([A-Z])', r'\1_\2', out)
    return out.lower()

def group_to_dir(group):
    if group == 'boot':
        return 'src/boot'
    if group == 'audio':
        return 'src/audio'
    if group == 'crt':
        return 'src/crt'
    if group == 'platform.win32':
        return 'src/platform/win32'
    if group == 'platform.install':
        return 'src/platform/install'
    if group == 'game.menu':
        return 'src/game'
    # everything else -> src/engine
    return 'src/engine'

def main():
    if len(sys.argv) < 2:
        print('usage: auto_split_misc.py <input.c> [--dry-run]', file=sys.stderr)
        sys.exit(1)
    input_path = sys.argv[1]
    dry_run = '--dry-run' in sys.argv

    with open('config/symbols.yaml') as f:
        syms = yaml.safe_load(f)
    name_to_group = {s['name']: s.get('group', 'unknown') for s in syms['functions']}
    name_to_file = {s['name']: s.get('file', '') for s in syms['functions']}

    # Find all functions in input_path
    with open(input_path) as f:
        content = f.read()
    # Allow multi-word return types like `unsigned int`, `unsigned short`, `unsigned char`
    fn_pattern = re.compile(r'^(?:__declspec\(naked\)\s+)?(?:static\s+)?(?:extern\s+)?(?:(?:unsigned|signed)\s+)?(?:\w+\s+\**)?\s*(\w+_[0-9a-fA-F]{8})\s*\(', re.MULTILINE)
    file_fns = []
    seen = set()
    for m in fn_pattern.finditer(content):
        name = m.group(1)
        if name in seen: continue
        if name_to_file.get(name) != input_path: continue
        # Check the line is actually a function definition, not a declaration
        # Look back to see if line ends with ;
        end_of_line = content.find('\n', m.end())
        if end_of_line == -1: end_of_line = len(content)
        line = content[m.start():end_of_line]
        if line.endswith(';'): continue  # declaration
        seen.add(name)
        file_fns.append(name)

    if not file_fns:
        print(f'No functions found in {input_path}', file=sys.stderr)
        sys.exit(1)

    # Group sister functions by snake_case base name + group
    base_groups = {}
    for fn in file_fns:
        snake = to_snake(fn)
        group = name_to_group.get(fn, 'unknown')
        key = (snake, group)
        base_groups.setdefault(key, []).append(fn)

    mapping = {}
    for (snake, group), fns in base_groups.items():
        out_dir = group_to_dir(group)
        if len(fns) > 1:
            # Sister cluster
            out_path = f'{out_dir}/{snake}_variants.c'
        else:
            out_path = f'{out_dir}/{snake}.c'
        for fn in fns:
            mapping[fn] = out_path

    # Print plan
    print(f'\nPlan for {input_path}:')
    out_files = {}
    for fn, out in mapping.items():
        out_files.setdefault(out, []).append(fn)
    for out_path, fns in sorted(out_files.items()):
        print(f'  {out_path:<60} {len(fns)} fn(s)')

    if dry_run:
        return

    # Write mapping json
    map_path = '/tmp/auto_mapping.json'
    with open(map_path, 'w') as f:
        json.dump(mapping, f, indent=2)

    # Invoke split_misc.py
    print(f'\nInvoking split_misc.py...')
    r = subprocess.run(['python3', 'tools/decomp/split_misc.py', input_path, '.', map_path],
                       capture_output=True, text=True)
    print(r.stdout)
    if r.returncode != 0:
        print('FAIL:', r.stderr, file=sys.stderr)
        sys.exit(1)

    # Delete input file + its .obj
    os.remove(input_path)
    obj_path = input_path.replace('src/', 'build/obj/').replace('.c', '.obj')
    if os.path.exists(obj_path):
        os.remove(obj_path)
    print(f'  deleted {input_path} and {obj_path}')

if __name__ == '__main__':
    main()
