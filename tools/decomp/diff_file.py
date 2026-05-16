#!/usr/bin/env python3
"""
Recompile a single src/.../foo.c and diff every function declared to be
in that file against orig. Reports diff counts per function.

Usage:
    python3 tools/decomp/diff_file.py src/engine/foo.c
"""
import os, subprocess, sys, yaml, struct

def get_pe_text(path):
    with open(path, 'rb') as f: d = f.read()
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
    raise SystemExit('.text not found in PE')

def diff_fn(obj_path, sym_name, addr, size, orig_d, orig_r_off, orig_v_addr, orig_ib):
    fo = (addr - orig_ib - orig_v_addr) + orig_r_off
    orig = bytearray(orig_d[fo:fo+size])

    with open(obj_path, 'rb') as f: obj = f.read()
    n_secs = struct.unpack_from('<H', obj, 2)[0]
    sym_tbl = struct.unpack_from('<I', obj, 8)[0]
    n_syms  = struct.unpack_from('<I', obj, 12)[0]
    opt     = struct.unpack_from('<H', obj, 16)[0]
    str_tbl_off = sym_tbl + n_syms * 18

    def read_sym_name(off):
        s_short = obj[off:off+8]
        if s_short[0:4] == b'\0\0\0\0':
            soff = struct.unpack_from('<I', obj, off+4)[0]
            end = obj.find(b'\0', str_tbl_off + soff)
            return obj[str_tbl_off + soff:end].decode('latin1')
        return s_short.rstrip(b'\0').decode('latin1')

    target_names = (f'_{sym_name}', sym_name)
    target = None
    i = 0
    while i < n_syms:
        soff = sym_tbl + i*18
        nm = read_sym_name(soff)
        sclass = obj[soff+16]
        sect = struct.unpack_from('<h', obj, soff+12)[0]
        aux = obj[soff+17]
        if nm in target_names and sect > 0 and sclass in (2, 3):
            target = (i, soff, sect, struct.unpack_from('<I', obj, soff+8)[0])
            break
        i += 1 + aux
    if target is None:
        return None
    i, soff, sect, val = target
    sym_off_in_section = val

    sec_hdr_off = 20 + opt
    sec_hdr = sec_hdr_off + (sect-1)*40
    raw_data_ptr = struct.unpack_from('<I', obj, sec_hdr+20)[0]
    rloc = struct.unpack_from('<I', obj, sec_hdr+24)[0]
    nr = struct.unpack_from('<H', obj, sec_hdr+32)[0]

    rebuilt = bytearray(obj[raw_data_ptr+sym_off_in_section:raw_data_ptr+sym_off_in_section+size])

    rel_offsets = []
    for r in range(nr):
        rva = struct.unpack_from('<I', obj, rloc + r*10)[0]
        if sym_off_in_section <= rva < sym_off_in_section + size:
            rel_offsets.append(rva - sym_off_in_section)
    def mask(buf, offs):
        for v in offs:
            for k in range(4):
                if v+k < len(buf): buf[v+k] = 0
    mask(rebuilt, rel_offsets)
    mask(orig,    rel_offsets)

    diffs = [(j, orig[j], rebuilt[j]) for j in range(min(len(rebuilt), len(orig))) if rebuilt[j] != orig[j]]
    return diffs, bytes(orig), bytes(rebuilt)

def main():
    if len(sys.argv) < 2:
        print(__doc__); sys.exit(2)
    src = sys.argv[1]
    if not src.startswith('src/') or not src.endswith('.c'):
        print('expected src/*.c'); sys.exit(2)
    rel = src[len('src/'):-len('.c')]
    obj = f'build/obj/{rel}.obj'

    if os.path.exists(obj):
        os.remove(obj)
    r = subprocess.run(['make', obj], capture_output=True, text=True)
    if r.returncode != 0:
        print('BUILD FAILED:')
        print(r.stdout); print(r.stderr)
        sys.exit(1)

    with open('config/symbols.yaml') as f:
        cfg = yaml.safe_load(f)
    funcs = [fn for fn in cfg['functions'] if fn.get('file') == src]
    if not funcs:
        print(f'No symbols in {src}'); sys.exit(0)

    orig_d, orig_r_off, orig_v_addr, orig_ib = get_pe_text('game/MK4.EXE')
    ok = 0
    bad = 0
    for fn in funcs:
        name = fn['name']
        addr = int(fn['addr'], 0) if isinstance(fn['addr'], str) else fn['addr']
        size = fn['size']
        res = diff_fn(obj, name, addr, size, orig_d, orig_r_off, orig_v_addr, orig_ib)
        if res is None:
            print(f'  ?? {name} @ {addr:#x} - NOT FOUND IN OBJ')
            bad += 1
            continue
        diffs, _, _ = res
        if not diffs:
            print(f'  OK {name} @ {addr:#x} size={size}')
            ok += 1
        else:
            print(f'  X  {name} @ {addr:#x} size={size}: {len(diffs)} diffs')
            bad += 1
    print(f'--- {ok}/{ok+bad} match ---')
    sys.exit(0 if bad == 0 else 1)

if __name__ == '__main__':
    main()
