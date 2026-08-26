#!/usr/bin/env python3
"""Decode the MESH portion of a .geo asset.

tools/geo_decode.py mapped the texture half; the mesh half was left as "NOT yet
decoded; finding the renderer code is the next step". This is that step: the
layout below is read straight off the co-exec-verified tristrip emitters
(TristripBatchEmit @0x4bbb80 and friends, see tools/decomp/verify_emit.py), and
it round-trips on the real character assets.

  .geo header
    0x00  char[4]  magic '0.1v'
    0x04  u32      tex_table_offset  (start of the texture half)
    0x08  u32      file_size
    0x0c  ...      mesh block table

  mesh block (16 bytes each, table runs from 0x0c)
    +0x00 u16 type      1 for the first set of blocks, 0 for a SECOND parallel
                        set that repeats the same per-part triangle counts
                        (63/112/47/25/... appear twice in sc_geo) - an LOD or
                        variant set, NOT a validity flag: every invariant below
                        holds for both.
    +0x02 u16 count     TOTAL TRIANGLE count of the block = sum(n_i + 1)
    +0x04 s32 ofs_a     vertices,   RELATIVE TO THE FIELD (block + 4 + ofs_a)
    +0x08 s32 ofs_b     strip list, RELATIVE TO THE FIELD (block + 8 + ofs_b)
    +0x0c s32 ofs_c     END of the vertex data (block + 12 + ofs_c), also relative

  The RELATIVE reading is what the emitter does - `*(int *)(param_1 + 4)` added
  to `param_1 + 4`. Reading ofs_a/ofs_b as absolute file offsets (the earlier
  guess) yields garbage: strip counts like -26555 and vertex coordinates in the
  tens of thousands.

  strip list : (u16 flags, s16 count) pairs, a NEGATIVE count terminates.
               A strip opens on 2 vertices then walks count+1 more, and strips
               consume the vertex array STRICTLY sequentially. Two independent
               invariants pin this down on the real assets:
                 sum(n_i + 1) == the block's `count` field   (triangles)
                 vtx_off + 12 * sum(n_i + 3) == block + 12 + ofs_c  (end of verts)
  vertices   : 12 bytes = 3x s16 position + 3x s16 normal.

Usage:
    build/venv/bin/python tools/geo_mesh.py build/assets/sc_geo.geo [--blocks]
"""
import struct
import sys
from pathlib import Path


class Block:
    __slots__ = ('idx', 'off', 'type', 'count', 'ofs_a', 'ofs_b', 'ofs_c',
                 'vtx_off', 'strip_off', 'strips', 'nvert')


def parse(data):
    if data[:4] != b'0.1v':
        raise SystemExit('not a .geo (magic %r)' % data[:4])
    tex_off, size = struct.unpack_from('<II', data, 4)
    blocks = []
    o = 0x0c
    while o + 16 <= tex_off:
        typ, cnt, a, b, c = struct.unpack_from('<HHiii', data, o)
        if typ not in (0, 1) or cnt == 0:
            break
        bl = Block()
        bl.idx, bl.off, bl.type, bl.count = len(blocks), o, typ, cnt
        bl.ofs_a, bl.ofs_b, bl.ofs_c = a, b, c
        bl.vtx_off, bl.strip_off = o + 4 + a, o + 8 + b
        if not (0 < bl.strip_off < tex_off and 0 < bl.vtx_off < tex_off):
            break
        # walk the strip list
        bl.strips, s, total, nvert = [], bl.strip_off, 0, 0
        while s + 4 <= tex_off:
            f, n = struct.unpack_from('<Hh', data, s)
            s += 4
            if n < 0:
                break
            bl.strips.append((f, n))
            total += n + 1                        # triangles
            nvert += n + 3                        # vertices the emitter consumes
            if len(bl.strips) > 256:
                break
        if total != bl.count:            # triangles must match the header
            break
        if bl.vtx_off + 12 * nvert != o + 12 + bl.ofs_c:   # verts must end at ofs_c
            break
        bl.nvert = nvert
        blocks.append(bl)
        o += 16
    return tex_off, size, blocks


def main():
    if len(sys.argv) < 2:
        print(__doc__)
        return 2
    p = Path(sys.argv[1])
    data = p.read_bytes()
    tex_off, size, blocks = parse(data)
    n1 = sum(1 for b in blocks if b.type == 1)
    print('%s: %d bytes (header says %d), tex table @0x%x, %d mesh blocks '
          '(%d type-1 + %d type-0)'
          % (p.name, len(data), size, tex_off, len(blocks), n1, len(blocks) - n1))
    allv = []
    for bl in blocks:
        for k in range(bl.nvert):
            allv.append(struct.unpack_from('<3h', data, bl.vtx_off + k * 12))
    if allv:
        xs, ys, zs = zip(*allv)
        print('  %d vertices total; bbox x[%d..%d] y[%d..%d] z[%d..%d]'
              % (len(allv), min(xs), max(xs), min(ys), max(ys), min(zs), max(zs)))
    if '--blocks' in sys.argv:
        for bl in blocks:
            print('  blk%-3d @0x%05x tris=%-5d verts=%-5d strips=%-3d verts@0x%05x strips@0x%05x'
                  % (bl.idx, bl.off, bl.count, bl.nvert, len(bl.strips),
                     bl.vtx_off, bl.strip_off))
    return 0


if __name__ == '__main__':
    sys.exit(main())
