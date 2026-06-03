#!/usr/bin/env python3
"""Dump bytes/strings from MK4.EXE at a list of VA addresses (for naming .rdata constants)."""
import struct, sys

def parse_pe_sections(data):
    pe_off = struct.unpack_from('<I', data, 0x3c)[0]
    nsec = struct.unpack_from('<H', data, pe_off+6)[0]
    opthdr_size = struct.unpack_from('<H', data, pe_off+20)[0]
    ib = struct.unpack_from('<I', data, pe_off+24+28)[0]
    sections = []
    for i in range(nsec):
        s = pe_off + 24 + opthdr_size + i*40
        name = data[s:s+8].rstrip(b'\x00').decode('latin1')
        vsize = struct.unpack_from('<I', data, s+8)[0]
        vaddr = struct.unpack_from('<I', data, s+12)[0] + ib
        rsize = struct.unpack_from('<I', data, s+16)[0]
        raddr = struct.unpack_from('<I', data, s+20)[0]
        sections.append({'name': name, 'vaddr': vaddr, 'vsize': vsize, 'rsize': rsize, 'raddr': raddr})
    return ib, sections

def va_to_raw(sections, va):
    for s in sections:
        if s['vaddr'] <= va < s['vaddr'] + s['vsize']:
            return s['raddr'] + (va - s['vaddr']), s['name']
    return None, None

def dump_at(data, sections, va, size=64):
    raw, sec = va_to_raw(sections, va)
    if raw is None:
        return f"{va:08x}: <not in any section>"
    chunk = data[raw:raw+size]
    # try ascii string
    nul = chunk.find(b'\x00')
    ascii_str = None
    if nul > 0 and all(32 <= b < 127 or b in (9, 10, 13) for b in chunk[:nul]):
        ascii_str = chunk[:nul].decode('latin1')
    hex_dump = ' '.join(f'{b:02x}' for b in chunk[:32])
    # try float
    f1 = struct.unpack_from('<f', chunk, 0)[0] if len(chunk) >= 4 else None
    d1 = struct.unpack_from('<d', chunk, 0)[0] if len(chunk) >= 8 else None
    u1 = struct.unpack_from('<I', chunk, 0)[0] if len(chunk) >= 4 else None
    out = [f"{va:08x} ({sec}):"]
    out.append(f"  hex : {hex_dump}")
    if ascii_str is not None:
        out.append(f"  str : {ascii_str!r}")
    if f1 is not None:
        out.append(f"  u32 : {u1} (0x{u1:x})   f32: {f1:g}   f64: {d1:g}")
    return '\n'.join(out)

if __name__ == "__main__":
    with open('game/MK4.EXE', 'rb') as f:
        data = f.read()
    _, sections = parse_pe_sections(data)
    for arg in sys.argv[1:]:
        va = int(arg, 16)
        print(dump_at(data, sections, va))
        print()
