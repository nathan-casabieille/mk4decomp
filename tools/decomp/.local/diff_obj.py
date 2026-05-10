#!/usr/bin/env python3
"""Per-function reloc-aware diff.

Usage:
    python3 diff_obj.py <obj-path> [VA1:size1:name1 ...]
    python3 diff_obj.py <obj-path> --auto    # parse symbols.yaml file: <obj>
"""
import struct, sys, os
from pathlib import Path

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

def parse_obj(obj_path):
    with open(obj_path,'rb') as f: obj = f.read()
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
        return -1, f'{name}: not found in obj'
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
    diffs = [(j, orig[j], rebuilt[j])
             for j in range(min(len(rebuilt), len(orig)))
             if rebuilt[j] != orig[j]]
    return len(diffs), diffs

ROOT = Path(__file__).resolve().parent.parent.parent.parent

def main():
    if len(sys.argv) < 2:
        print(__doc__)
        sys.exit(1)
    obj_path = sys.argv[1]
    obj, fn2sec, secs = parse_obj(obj_path)
    exe_data, r_off, v_addr, ib = get_pe_text(ROOT / 'game' / 'MK4.EXE')

    if len(sys.argv) > 2 and sys.argv[2] == '--auto':
        # Look up entries from symbols.yaml that point to this file
        import yaml
        with open(ROOT / 'config' / 'symbols.yaml') as f:
            data = yaml.safe_load(f)
        rel_obj = os.path.basename(obj_path).replace('.obj', '.c')
        targets = []
        for s in data['functions']:
            f = s.get('file')
            if f and os.path.basename(f) == rel_obj:
                targets.append((s['addr'], s['size'], s['name']))
    else:
        targets = []
        for spec in sys.argv[2:]:
            va, size, name = spec.split(':')
            targets.append((int(va, 0), int(size), name))

    total = 0
    for va, size, name in targets:
        n, diffs = diff_one(obj, fn2sec, secs, exe_data, r_off, v_addr, ib, va, size, name)
        if n < 0:
            print(f'{va:#010x} {name[:40]:40} sz={size}  {diffs}')
            continue
        status = 'OK' if not n else 'BAD'
        print(f'{va:#010x} {name[:40]:40} sz={size:3} diffs={n:3} {status}')
        total += n
        if 0 < n < 20 and isinstance(diffs, list):
            for j,o,r in diffs[:20]:
                print(f'   +{j:#04x}: orig={o:02x} new={r:02x}')
    print(f'\ntotal diffs={total}')

if __name__ == '__main__':
    main()
