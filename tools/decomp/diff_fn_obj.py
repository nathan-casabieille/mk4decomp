#!/usr/bin/env python3
"""
Per-function reloc-aware diff between a freshly built .obj and the
bytes inside game/MK4.EXE.

Usage:
    python3 tools/decomp/diff_fn_obj.py <obj> <symbol> <addr> <size>

Locates `<symbol>` (with COFF '_' prefix) inside `<obj>`, reads the
function's .text bytes, lists the relocations that fall inside that
range, masks the 4-byte windows around each reloc on both sides,
then byte-compares against the function bytes extracted from
game/MK4.EXE at <addr> for <size> bytes.

Prints diff count and the first 30 mismatches.
"""
import struct, sys, os

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

def main():
    if len(sys.argv) != 5:
        print(__doc__); sys.exit(2)
    obj_path = sys.argv[1]
    sym_name = sys.argv[2]
    addr = int(sys.argv[3], 0)
    size = int(sys.argv[4], 0)

    # Read original bytes from the linked exe.
    d, r_off, v_addr, ib = get_pe_text('game/MK4.EXE')
    fo = (addr - ib - v_addr) + r_off
    orig = bytearray(d[fo:fo+size])

    # Parse the COFF .obj.
    with open(obj_path, 'rb') as f: obj = f.read()
    n_secs = struct.unpack_from('<H', obj, 2)[0]
    sym_tbl = struct.unpack_from('<I', obj, 8)[0]
    n_syms  = struct.unpack_from('<I', obj, 12)[0]
    opt     = struct.unpack_from('<H', obj, 16)[0]

    # String table follows symbol table (each symtab entry = 18 bytes).
    str_tbl_off = sym_tbl + n_syms * 18

    def read_sym_name(off):
        s_short = obj[off:off+8]
        if s_short[0:4] == b'\0\0\0\0':
            soff = struct.unpack_from('<I', obj, off+4)[0]
            end = obj.find(b'\0', str_tbl_off + soff)
            return obj[str_tbl_off + soff:end].decode('latin1')
        return s_short.rstrip(b'\0').decode('latin1')

    # Find symbol by name (try with and without leading '_').
    target_names = (f'_{sym_name}', sym_name)
    target = None
    i = 0
    while i < n_syms:
        off = sym_tbl + i*18
        nm = read_sym_name(off)
        if nm in target_names:
            value = struct.unpack_from('<I', obj, off+8)[0]
            sec   = struct.unpack_from('<h', obj, off+12)[0]
            target = (nm, value, sec)
            break
        n_aux = obj[off+17]
        i += 1 + n_aux
    if target is None:
        raise SystemExit(f'symbol {sym_name!r} not found in {obj_path}')

    sym_off_in_section = target[1]
    sec_idx = target[2]  # 1-based

    # Locate that section header.
    s_hdr = 20 + opt + (sec_idx - 1) * 40
    sec_name = obj[s_hdr:s_hdr+8].rstrip(b'\0').decode('latin1')
    if sec_name != '.text':
        raise SystemExit(f'symbol is in section {sec_name!r}, expected .text')
    rs    = struct.unpack_from('<I', obj, s_hdr+16)[0]
    ro    = struct.unpack_from('<I', obj, s_hdr+20)[0]
    rloc  = struct.unpack_from('<I', obj, s_hdr+24)[0]
    nr    = struct.unpack_from('<H', obj, s_hdr+32)[0]

    text = obj[ro:ro+rs]
    if sym_off_in_section + size > len(text):
        raise SystemExit(f'function bytes {sym_off_in_section:#x}+{size} exceed section size {rs:#x}')
    rebuilt = bytearray(text[sym_off_in_section:sym_off_in_section+size])

    # Collect relocs that fall inside our function range.
    rel_offsets = []
    for r in range(nr):
        rva = struct.unpack_from('<I', obj, rloc + r*10)[0]
        if sym_off_in_section <= rva < sym_off_in_section + size:
            rel_offsets.append(rva - sym_off_in_section)

    # Mask the 4-byte windows on both sides.
    def mask(buf, offs):
        for v in offs:
            for k in range(4):
                if v+k < len(buf): buf[v+k] = 0
    mask(rebuilt, rel_offsets)
    mask(orig,    rel_offsets)

    diffs = [(j, orig[j], rebuilt[j]) for j in range(min(len(rebuilt), len(orig))) if rebuilt[j] != orig[j]]
    print(f'{sym_name} @ {addr:#x} size={size}: rebuilt_len={len(rebuilt)} orig_len={len(orig)} relocs_in_fn={len(rel_offsets)} diffs={len(diffs)}')
    print(f'  orig    : {bytes(orig).hex()}')
    print(f'  rebuilt : {bytes(rebuilt).hex()}')
    for j,o,n in diffs[:30]:
        print(f'  +{j:#06x}: orig={o:02x} new={n:02x}')

if __name__ == '__main__':
    main()
