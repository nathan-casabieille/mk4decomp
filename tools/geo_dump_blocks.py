#!/usr/bin/env python3
"""Dump the mesh-block table from a .geo file.

The mesh portion of a .geo (bytes 0x0C to tex_table_offset) starts with a
table of 16-byte block headers, each:

    struct geo_block {
        uint16_t type;        // observed: always 1 in character files
        uint16_t count;       // varies per block - per-block element count
        uint32_t ofs_a;       // offset into the file
        uint32_t ofs_b;       // offset into the file (slightly less than ofs_a)
        uint32_t ofs_c;       // offset into the file (between ofs_a and ofs_a + work_size)
    };

The block table runs until ofs_b crosses past the start of meaningful
data (heuristic: until ofs_b would land inside the table itself). The
exact terminator is not yet known - we walk until we hit an entry whose
ofs values are >= tex_table_offset or ofs_b < current_block_offset.

Element semantics (count, ofs_a, ofs_b, ofs_c) are NOT yet decoded;
finding the renderer code is the next step.

Usage:
    python3 tools/geo_dump_blocks.py game/path-to-extracted.geo
"""
import struct
import sys
from pathlib import Path


def parse_blocks(data, tex_table_offset):
    """Yield block records as long as the offsets look sane.

    Heuristic terminator: a block whose ofs_a/ofs_b/ofs_c is past the
    texture table or wraps backward.
    """
    p = 0x0C
    while p + 16 <= tex_table_offset:
        block = struct.unpack_from("<HHIII", data, p)
        type_, count, oa, ob, oc = block
        # Sanity: all offsets must point inside the mesh region
        if not (0x0C <= ob < tex_table_offset and
                0x0C <= oa <= tex_table_offset and
                0x0C <= oc <= tex_table_offset):
            break
        # Sanity: ofs_b must be past the current block-header position
        if ob < p + 16:
            break
        yield p, block
        p += 16


def main():
    if len(sys.argv) != 2:
        print(__doc__)
        sys.exit(1)
    path = Path(sys.argv[1])
    data = path.read_bytes()
    if data[:4] != b"0.1v":
        print(f"not a 0.1v geo file: {path}")
        sys.exit(1)
    tex_off, file_size = struct.unpack_from("<II", data, 4)
    print(f"file       : {path}")
    print(f"tex_table  : 0x{tex_off:x}  (mesh region: 0x0C..0x{tex_off:x} = "
          f"{tex_off - 0x0C} bytes)")
    print(f"file_size  : {file_size}")
    print()

    blocks = list(parse_blocks(data, tex_off))
    print(f"blocks recovered: {len(blocks)}")
    print(f"{'idx':>4}  {'@hdr':>6}  {'type':>4}  {'count':>6}  "
          f"{'ofs_a':>8}  {'ofs_b':>8}  {'ofs_c':>8}  {'a-b':>6}  {'c-a':>8}")
    for i, (p, (type_, count, oa, ob, oc)) in enumerate(blocks):
        print(f"{i:4d}  0x{p:04x}  {type_:4d}  {count:6d}  "
              f"0x{oa:06x}  0x{ob:06x}  0x{oc:06x}  {oa - ob:6d}  {oc - oa:8d}")

    if blocks:
        first_data = min(b[1][2] for b in blocks)
        print(f"\nFirst block-data offset: 0x{first_data:x}")
        print(f"Block-header table size: {first_data - 0x0C} bytes "
              f"= {(first_data - 0x0C) / 16:.1f} entries (16 bytes each)")


if __name__ == "__main__":
    main()
