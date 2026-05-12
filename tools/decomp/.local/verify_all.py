#!/usr/bin/env python3
"""Verify every matched function in symbols.yaml is still byte-perfect.

For each .c file referenced by matched symbols:
  - rebuild it (cl.sh /c)
  - parse the resulting .obj
  - reloc-aware diff every matched function pointing at that file
"""
import os, sys, struct, subprocess
from pathlib import Path
from collections import defaultdict

ROOT = Path(__file__).resolve().parent.parent.parent.parent

def get_pe_text(exe_path):
    with open(exe_path, 'rb') as f: d = f.read()
    pe = struct.unpack_from('<I', d, 0x3c)[0]
    ib = struct.unpack_from('<I', d, pe+24+28)[0]
    n  = struct.unpack_from('<H', d, pe+6)[0]
    sz = struct.unpack_from('<H', d, pe+20)[0]
    s0 = pe + 24 + sz
    for i in range(n):
        s = s0 + i*40
        if d[s:s+8].rstrip(b'\0') == b'.text':
            va = struct.unpack_from('<I', d, s+12)[0]
            ro = struct.unpack_from('<I', d, s+20)[0]
            return d, ro, va, ib
    raise RuntimeError('.text not found')

def parse_obj(obj_path):
    with open(obj_path, 'rb') as f: obj = f.read()
    n_secs = struct.unpack_from('<H', obj, 2)[0]
    sym_off = struct.unpack_from('<I', obj, 8)[0]
    sym_count = struct.unpack_from('<I', obj, 12)[0]
    opt = struct.unpack_from('<H', obj, 16)[0]
    string_off = sym_off + sym_count * 18

    def read_symname(idx):
        e_off = sym_off + idx * 18
        name = obj[e_off:e_off+8]
        if struct.unpack_from('<I', name, 0)[0] == 0:
            s = string_off + struct.unpack_from('<I', name, 4)[0]
            end = obj.index(b'\0', s)
            return obj[s:end].decode()
        return name.rstrip(b'\0').decode()

    fn2sec = {}
    i = 0
    while i < sym_count:
        e = sym_off + i * 18
        name = read_symname(i)
        sec_num = struct.unpack_from('<h', obj, e+12)[0]
        storage = obj[e+16]
        aux = obj[e+17]
        if name.startswith('_') and storage == 2 and sec_num > 0:
            fn2sec[name[1:]] = sec_num
        i += 1 + aux

    secs = []
    for i in range(n_secs):
        s = 20 + opt + i*40
        raw_size = struct.unpack_from('<I', obj, s+16)[0]
        raw_off = struct.unpack_from('<I', obj, s+20)[0]
        reloc_off = struct.unpack_from('<I', obj, s+24)[0]
        n_relocs = struct.unpack_from('<H', obj, s+32)[0]
        secs.append((raw_off, raw_size, reloc_off, n_relocs))
    return obj, fn2sec, secs

def diff_one(obj, fn2sec, secs, exe_data, r_off, v_addr, ib, va, size, name):
    secidx = fn2sec.get(name)
    if secidx is None:
        # Try stdcall decoration: name@N for some N divisible by 4.
        for cand in fn2sec:
            if cand.startswith(name + '@'):
                secidx = fn2sec[cand]
                break
    if secidx is None:
        return -1, 'NOT_IN_OBJ'
    raw_off, raw_size, reloc_off, n_relocs = secs[secidx-1]
    text = obj[raw_off:raw_off+size]
    rebuilt = bytearray(text)
    relocs = [struct.unpack_from('<I', obj, reloc_off + r*10)[0] for r in range(n_relocs)]
    fo = (va - ib - v_addr) + r_off
    orig = bytearray(exe_data[fo:fo+size])
    for v in relocs:
        for k in range(4):
            if v+k < len(rebuilt): rebuilt[v+k] = 0
            if v+k < len(orig):    orig[v+k] = 0
    diffs = sum(1 for j in range(min(len(rebuilt), len(orig))) if rebuilt[j] != orig[j])
    return diffs, ''

def main():
    import yaml
    with open(ROOT / 'config' / 'symbols.yaml') as f:
        data = yaml.safe_load(f)
    rows = data['functions']

    # Group matched symbols by source file
    by_file = defaultdict(list)
    for s in rows:
        if s.get('status') != 'matched':
            continue
        src = s.get('file')
        if not src:
            continue
        by_file[src].append((int(s['addr'], 16) if isinstance(s['addr'], str) else s['addr'],
                              s.get('size', 0), s['name']))

    print(f'matched files:    {len(by_file)}')
    print(f'matched functions: {sum(len(v) for v in by_file.values())}')
    print()

    exe_data, r_off, v_addr, ib = get_pe_text(ROOT / 'game' / 'MK4.EXE')

    all_ok = True
    file_results = []
    rebuild = '--rebuild' in sys.argv

    for src_path, fns in sorted(by_file.items()):
        full_src = ROOT / src_path
        if not full_src.exists():
            print(f'MISSING SOURCE: {src_path}')
            all_ok = False
            continue
        # Map to obj path: src/foo/bar.c → build/obj/foo/bar.obj
        rel = Path(src_path)
        obj_path = ROOT / 'build' / 'obj' / rel.relative_to('src').with_suffix('.obj')
        if rebuild or not obj_path.exists():
            obj_path.parent.mkdir(parents=True, exist_ok=True)
            cl = ROOT / 'tools' / 'decomp' / 'cl.sh'
            args = [str(cl), '/nologo', '/O2', '/Gy', '/Iinclude', '/c',
                    str(rel), '/Fo' + str(obj_path)]
            r = subprocess.run(args, cwd=ROOT, capture_output=True, text=True)
            if r.returncode != 0:
                print(f'CL FAIL {src_path}:')
                print(r.stderr)
                all_ok = False
                continue
        if not obj_path.exists():
            print(f'NO OBJ for {src_path}')
            all_ok = False
            continue

        try:
            obj, fn2sec, secs = parse_obj(obj_path)
        except Exception as e:
            print(f'PARSE FAIL {obj_path}: {e}')
            all_ok = False
            continue

        bad = 0
        missing = 0
        diff_total = 0
        for va, size, name in fns:
            if size == 0: continue
            n, msg = diff_one(obj, fn2sec, secs, exe_data, r_off, v_addr, ib, va, size, name)
            if n == -1:
                missing += 1
            elif n > 0:
                bad += 1
                diff_total += n
                print(f'  BAD  {src_path}: {name} @ {va:#x} sz={size} diffs={n}')
        status = 'OK ' if (bad == 0 and missing == 0) else 'FAIL'
        if bad or missing:
            all_ok = False
        file_results.append((src_path, len(fns), bad, missing, status))

    # Print summary
    print()
    print('=' * 78)
    print(f'{"FILE":50}{"FNS":>6}{"BAD":>5}{"MISS":>6}  STATUS')
    print('-' * 78)
    bad_files = 0
    for src, total, bad, missing, status in file_results:
        if bad or missing:
            bad_files += 1
            print(f'{src:50}{total:>6}{bad:>5}{missing:>6}  {status}')
    print('-' * 78)
    print(f'files with issues: {bad_files} / {len(file_results)}')
    print(f'overall: {"OK" if all_ok else "FAIL"}')
    return 0 if all_ok else 1

if __name__ == '__main__':
    sys.exit(main())
