#!/usr/bin/env python3
"""Dump one animation frame's per-node record - by RUNNING the engine's own
Anim_AcquireFrameData (0x00401000) under Unicorn rather than reimplementing it.

That turns an inference into a check: the tool asserts the returned value equals
`(data >> 2) + node_count * frame`, which is the uncompressed fast path, and
then reads the record the way the transform setters do. Confirmed on the real
pack for several frames.

The setters (NodeApplyTransform_*_Direct, 0x004bdc00 and friends) read
    cx = word [g_xformEntityIdx*4 + 0]
    dx = word [g_xformEntityIdx*4 + 4]
    ax = word [g_xformEntityIdx*4 + 8]
i.e. a PACKED pointer to three consecutive DWORDS, taking the low 16 bits of
each as a BAM angle (and negating them). Anim_AcquireFrameData returns exactly
such a packed pointer, which is what ties an animation frame to a node's
rotation. The non-_Direct setters read the same three dwords as 16.16 radians
instead and convert with `bam = ((x >> 2) * 10430) >> 18`.

Only UNCOMPRESSED animations (41 of the 612 - see tools/anim_pack.py) work
here; the other 571 go through Anim_DecodeBitstream, which is not decoded yet.

  build/venv/bin/python tools/anim_frame.py AP0 AP1 ANIM_ID [FRAME]
"""
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / 'tools' / 'decomp'))
sys.path.insert(0, str(ROOT / 'tools'))
import verify_twin as vt
import verify_coexec as vc
from anim_pack import parse_index


def s16(v):
    v &= 0xffff
    return v - 0x10000 if v & 0x8000 else v


def main():
    if len(sys.argv) < 4:
        print(__doc__)
        return 2
    ap0 = Path(sys.argv[1]).read_bytes()
    ap1 = Path(sys.argv[2]).read_bytes()
    aid = int(sys.argv[3])
    frame = int(sys.argv[4]) if len(sys.argv) > 4 else 0

    fn_va, gl_va = vt.load_maps()
    arena = bytearray(vc.ARENA.read_bytes())
    ents = {e[0]: e for e in parse_index(ap0)}
    if aid not in ents:
        print('no such animation id')
        return 1
    _, flag, size, off = ents[aid]

    tbl = 0x4ffdec - vc.BASE
    frames = struct.unpack_from('<i', arena, tbl + aid * 12 + 4)[0]
    nodes = struct.unpack_from('<I', arena, tbl + aid * 12 + 8)[0] >> 16
    if flag:
        print('anim %d is COMPRESSED (bit 15) - needs Anim_DecodeBitstream, '
              'which is not decoded yet' % aid)
        return 1

    # park the blob past the image, still inside the emulated arena
    pad = (-len(arena)) % 0x1000
    arena += b'\x00' * pad
    data_va = vc.BASE + len(arena)
    arena += ap1[off:off + size]
    arena += b'\x00' * ((-len(arena)) % 0x1000)
    struct.pack_into('<I', arena, tbl + aid * 12, data_va)

    desc = 0x4ffdec + aid * 12
    uc, full = vc.uc_new(arena)
    _, term, eax = vc.run_at(uc, fn_va['Anim_AcquireFrameData'], full, 3,
                             (desc >> 2, frame, 0))
    eax &= 0xffffffff
    exp = ((data_va >> 2) + nodes * frame) & 0xffffffff
    print('anim %d: frames=%d nodes=%d size=%d' % (aid, frames, nodes, size))
    print('  Anim_AcquireFrameData -> 0x%08x (expected 0x%08x) %s, terminated=%d'
          % (eax, exp, 'OK' if eax == exp else 'MISMATCH', term))
    if eax != exp:
        return 1

    rec = eax * 4 - vc.BASE
    print('  frame %d, %d dwords = %d node records of 3:' % (frame, nodes, nodes // 3))
    for n in range(nodes // 3):
        g = [struct.unpack_from('<i', arena, rec + (n * 3 + k) * 4)[0] for k in range(3)]
        print('    node %-2d  raw=(%11d,%11d,%11d)  bam(low16)=(%6d,%6d,%6d)'
              % (n, g[0], g[1], g[2], s16(g[0]), s16(g[1]), s16(g[2])))
    return 0


if __name__ == '__main__':
    sys.exit(main())
