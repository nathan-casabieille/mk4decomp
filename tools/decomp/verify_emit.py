#!/usr/bin/env python3
"""Seeded co-exec verification for the tristrip EMITTERS - the layer that turns
a .geo strip mesh into DrawEntries and enqueues them via Helper_DrawCursor.

This is the bridge between the (verified) projection helpers and the (verified)
draw-queue pipeline: TristripBatchEmit walks a strip list, projects each vertex
through ProjectTwoVertices / ProjectVertex / AdvanceTriStripRing, does a
backface test from the cross product of the two screen edges, and for each
front-facing triangle fills a 28-byte DrawEntry at g_dualC+4 + i*0x1c (sort key
via MinOfThree/MaxOfThree, shading via Vec3ColorShiftClamp) before calling
Helper_DrawCursor.

Stock verify_coexec reports these as a vacuous "VERIFIED (0 writes)": the strip
pointer lands in the self-referential arg scratch, whose second word reads as a
negative count, so the walk terminates on its first iteration. This harness
builds a REAL mesh in the arena so the emitter actually emits.

Mesh layout, read off the emitter itself:
    M+4  : s32 vtxOff    -> vertices  at M + 4 + vtxOff
    M+8  : s32 stripOff  -> strip list at M + 8 + stripOff
  strip list : (u16 flags, s16 count) pairs, terminated by a NEGATIVE count
  vertices   : 6 s16 each (x, y, z, + 3 payload); a strip opens by consuming
               two vertices (12 s16) then walks count+1 more

  build/venv/bin/python tools/decomp/verify_emit.py [NAME ...]
"""
import struct
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import verify_twin as vt
import verify_coexec as vc
import verify_project as vp

BASE = vc.BASE
MESH_VA = 0x00f40000        # in-arena scratch: the mesh blob
ENTRIES_VA = 0x00f50000     # DrawEntry staging (g_dualC + 4 points here)
LUT_VA = 0x00b0d008         # g_zSortKeyLUT[65536] (u16) - Helper_DrawCursor
QSIZE_VA = 0x00f85b40       # g_drawQueueSize


def setw(a, va, v):
    struct.pack_into('<h', a, va - BASE, v if v >= -0x8000 else -0x8000)


def setdw(a, va, v):
    struct.pack_into('<i', a, va - BASE, v)


# Five vertices forming a two-triangle strip, in front of the camera (positive
# Z after the transform) and inside the 320x240 envelope once projected.
VERTS = [
    (-0x60, -0x40, 0x300),
    (0x60, -0x40, 0x300),
    (-0x60,  0x40, 0x320),
    (0x60,  0x40, 0x320),
    (0x00,  0x80, 0x340),
]


def build_mesh(a, nstrips=1, count=2, flags=0x0001):
    """Write the mesh at MESH_VA and return its VA."""
    vtx_va = MESH_VA + 0x100
    strip_va = MESH_VA + 0x800
    setdw(a, MESH_VA + 4, vtx_va - (MESH_VA + 4))
    setdw(a, MESH_VA + 8, strip_va - (MESH_VA + 8))
    # vertices: 6 s16 each; payload words are distinct so a wrong stride shows up
    for i, (x, y, z) in enumerate(VERTS):
        v = vtx_va + i * 12
        setw(a, v + 0, x); setw(a, v + 2, y); setw(a, v + 4, z)
        setw(a, v + 6, 0x100 + i); setw(a, v + 8, 0x200 + i); setw(a, v + 10, 0x300 + i)
    # strip list, then the negative-count terminator
    for s in range(nstrips):
        setw(a, strip_va + s * 4 + 0, flags)
        setw(a, strip_va + s * 4 + 2, count)
    setw(a, strip_va + nstrips * 4 + 0, 0)
    setw(a, strip_va + nstrips * 4 + 2, -1)
    return MESH_VA


def seed(a, **mesh_kw):
    vp.seed_common(a)
    setdw(a, 0x7af92c, 0)                 # g_inLoopStep = 0 (the emitter gate)
    setdw(a, 0x54204c, ENTRIES_VA - 4)    # g_dualC: entries live at g_dualC + 4
    setdw(a, QSIZE_VA, 0)                 # start from an empty draw queue
    for k in range(0, 0x1000):            # distinct sort-key LUT (downstream)
        struct.pack_into('<H', a, LUT_VA + k * 2 - BASE, (k ^ 0x5a5a) & 0xffff)
    build_mesh(a, **mesh_kw)


# (label, argvals, mesh kwargs) - param_2 flips the strip parity, param_3
# picks MinOfThree vs MaxOfThree for the sort key.
SCEN = [
    ('p2=0,p3=0',   (MESH_VA, 0, 0), {}),
    ('p2=1,p3=0',   (MESH_VA, 1, 0), {}),
    ('p2=0,p3=1',   (MESH_VA, 0, 1), {}),
    ('p2=1,p3=1',   (MESH_VA, 1, 1), {}),
    ('flags=0x100', (MESH_VA, 0, 0), dict(flags=0x0100)),
    ('long-strip',  (MESH_VA, 0, 0), dict(count=3)),
    ('two-strips',  (MESH_VA, 0, 0), dict(nstrips=2)),
]


def main():
    names = sys.argv[1:] or ['TristripBatchEmit', 'TristripBatchEmit3Cap']
    fn_va, gl_va = vt.load_maps()
    base = bytearray(vc.ARENA.read_bytes())
    vc.ARG_BASE = 0x7af800
    rc = 0
    for name in names:
        print(name)
        for label, argvals, mesh_kw in SCEN:
            arena = bytearray(base)
            seed(arena, **mesh_kw)
            res = vc.verify(name, fn_va, gl_va, fn_va, arena,
                            width16=vp.WIDTH16, argvals=argvals)
            weak = 'VERIFIED (0 writes' in res
            print('  %-14s %s%s' % (label, res,
                                    '  WEAK(emitter never fired)' if weak else ''))
            if res.startswith('MISMATCH'):
                rc = 1
    return rc


if __name__ == '__main__':
    sys.exit(main())
