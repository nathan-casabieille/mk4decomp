#!/usr/bin/env python3
"""Extract the mapped PE image of MK4.EXE into a flat arena blob.

The portable / WASM build relocates the engine's absolute-VA memory model
into a single reserved linear region (see
tools/decomp/AGENT_PORTABLE_WASM_MIGRATION.md, Phase 1). This tool
produces that region's initial contents:

    arena.bin[ va - image_base ] == the byte the original process sees at va

so that MK4_PTR(va) = g_mk4Arena + (va - MK4_ORIG_IMAGE_BASE) (see
include/portable/mem_model.h) reads exactly what the original binary's
flat address space held. Section gaps + .bss are zero-filled.

Usage:
    python3 tools/decomp/extract_arena.py [game/MK4.EXE] [build/arena.bin]
"""
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]


def parse_pe_sections(data):
    pe_off = struct.unpack_from('<I', data, 0x3c)[0]
    nsec = struct.unpack_from('<H', data, pe_off + 6)[0]
    opthdr_size = struct.unpack_from('<H', data, pe_off + 20)[0]
    image_base = struct.unpack_from('<I', data, pe_off + 24 + 28)[0]
    size_of_headers = struct.unpack_from('<I', data, pe_off + 24 + 60)[0]
    sections = []
    for i in range(nsec):
        s = pe_off + 24 + opthdr_size + i * 40
        name = data[s:s + 8].rstrip(b'\x00').decode('latin1')
        vsize = struct.unpack_from('<I', data, s + 8)[0]
        vaddr = struct.unpack_from('<I', data, s + 12)[0]   # RVA
        rsize = struct.unpack_from('<I', data, s + 16)[0]
        raddr = struct.unpack_from('<I', data, s + 20)[0]
        sections.append({'name': name, 'vaddr': vaddr, 'vsize': vsize,
                         'rsize': rsize, 'raddr': raddr})
    return image_base, size_of_headers, sections


def main():
    exe = Path(sys.argv[1]) if len(sys.argv) > 1 else ROOT / 'game' / 'MK4.EXE'
    out = Path(sys.argv[2]) if len(sys.argv) > 2 else ROOT / 'build' / 'arena.bin'

    data = exe.read_bytes()
    image_base, size_of_headers, sections = parse_pe_sections(data)

    image_end = max(s['vaddr'] + s['vsize'] for s in sections)
    # Round up to a page so the arena size is clean.
    arena_size = (image_end + 0xFFF) & ~0xFFF
    arena = bytearray(arena_size)

    # PE headers occupy the start of the image (RVA 0 .. size_of_headers).
    arena[0:size_of_headers] = data[0:size_of_headers]

    for s in sections:
        if s['rsize'] == 0:
            continue  # pure .bss section: stays zero-filled
        src = data[s['raddr']:s['raddr'] + s['rsize']]
        dst = s['vaddr']
        arena[dst:dst + len(src)] = src

    out.parent.mkdir(parents=True, exist_ok=True)
    out.write_bytes(arena)

    print(f"image_base   = 0x{image_base:08x}")
    print(f"arena size   = 0x{arena_size:08x} ({arena_size/1e6:.1f} MB)")
    print(f"sections     = {', '.join(s['name'] for s in sections)}")
    print(f"wrote        = {out}  (index as arena[VA - 0x{image_base:08x}])")


if __name__ == '__main__':
    main()
