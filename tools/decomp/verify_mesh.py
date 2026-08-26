#!/usr/bin/env python3
"""Seeded co-exec verification for DrawMeshBlock - the .geo MAIN-PATH emitter.

Same shape as TristripBatchEmit (verify_emit.py) but it also shades every
vertex through TransformVertex, applies a depth attenuation to the three vertex
colours, folds g_dispatchSave1559 into the sort key, and optionally clamps the
entry's Y fields to the horizon.

It needs everything verify_emit seeds (a real strip mesh, the emitter gate, a
DrawEntry staging area, the sort-key LUT) PLUS:
  - g_menuRestoreSlot != 0, or the function takes the TristripBatchEmit3Cap
    fast path and never touches the mesh at all;
  - the light matrices / colour / RGB-scale bytes TransformVertex reads;
  - g_dispatchSave1570 / 1574 / 1576 / 1559 / 1501 (alt camera, attenuation,
    sort-key bias, horizon clamp).

  build/venv/bin/python tools/decomp/verify_mesh.py
"""
import struct
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import verify_twin as vt
import verify_coexec as vc
import verify_project as vp
import verify_emit as ve

BASE = vc.BASE


def setdw(a, va, v):
    struct.pack_into('<i', a, va - BASE, v)


def setw(a, va, v):
    struct.pack_into('<h', a, va - BASE, v)


def seed(a, atten=0x40, alt=0, bias=3, **mesh_kw):
    ve.seed(a, **mesh_kw)                 # mesh + gate + g_dualC + LUT + matrix
    vp.seed_common(a, **vp.SEEDS['pos'])  # projection matrix + lights
    # ve.seed already built the mesh; seed_common must not undo the gate
    setdw(a, 0x7af92c, 0)                 # g_inLoopStep
    setdw(a, 0x543aa8, 1)                 # g_menuRestoreSlot != 0 -> MESH path
    setdw(a, 0xab4e60, atten)             # g_dispatchSave1576 (attenuation src)
    setdw(a, 0xab4d9c, bias)              # g_dispatchSave1559 (sort-key bias)
    setdw(a, 0xab4e28, alt)               # g_dispatchSave1570 (alt cam + clamp)
    setdw(a, 0xab4e3c, -1)                # g_dispatchSave1574 (< 0 -> alt cam)
    for k in range(3):                    # g_dispatchSave1501: the alt-cam vec3
        setdw(a, 0xab4398 + k * 4, (0x40, 0x30, 0x300)[k])
    setw(a, 0x4f623c, 0x1e0)              # g_screenH (horizon)
    # TransformVertex inputs: colours are PACKED words, scales are PACKED bytes
    setw(a, 0x7af9f0, 0x3def)             # g_vtxColorPrev
    setw(a, 0x7af9fc, 0x1234)             # g_vtxColor
    setw(a, 0x7af9f8, 0x0abc)             # g_vtxColorCopy
    setw(a, 0x7af9fa, 0x0def)             # g_vtxColorSaved
    for va, v in ((0x7af9f2, 0x40), (0x7af9f3, 0x22), (0x7af9f4, 0x60),
                  (0x7af9f5, 0x33), (0x7af9f6, 0x80), (0x7af9f7, 0x55)):
        a[va - BASE] = v


SCEN = [
    ('a1=0,a2=0',   (ve.MESH_VA, 0, 0), dict()),
    ('a1=1,a2=0',   (ve.MESH_VA, 1, 0), dict()),
    ('a1=0,a2=1',   (ve.MESH_VA, 0, 1), dict()),
    ('atten-on',    (ve.MESH_VA, 0, 0), dict(atten=0x18)),   # < 0x20 -> scale
    ('atten-hi',    (ve.MESH_VA, 0, 0), dict(atten=0x200)),
    ('altcam+clamp',(ve.MESH_VA, 0, 0), dict(alt=1)),
    ('flags=0x100', (ve.MESH_VA, 0, 0), dict(flags=0x0100)),
    ('long-strip',  (ve.MESH_VA, 0, 0), dict(count=3)),
    ('two-strips',  (ve.MESH_VA, 0, 0), dict(nstrips=2)),
    # EXPECTED SKIP: the twin is placed at DrawMeshBlock's own VA and is 16
    # bytes longer than the original, so it clobbers the start of
    # TristripBatchEmit3Cap - which sits immediately after it and is exactly
    # what this path calls. The harness says so. That emitter is verified on
    # its own in verify_emit.py, and the path is a plain 3-arg forward.
    ('fastpath',    (ve.MESH_VA, 0, 0), dict(menu=0)),
]


def main():
    names = sys.argv[1:] or ['DrawMeshBlock']
    fn_va, gl_va = vt.load_maps()
    base = bytearray(vc.ARENA.read_bytes())
    vc.ARG_BASE = 0x7af800
    rc = 0
    for name in names:
        print(name)
        for label, argvals, kw in SCEN:
            arena = bytearray(base)
            menu = kw.pop('menu', 1)
            seed(arena, **kw)
            setdw(arena, 0x543aa8, menu)
            res = vc.verify(name, fn_va, gl_va, fn_va, arena,
                            width16=vp.WIDTH16, argvals=argvals)
            weak = 'VERIFIED (0 writes' in res
            print('  %-14s %s%s' % (label, res,
                                    '  WEAK(nothing emitted)' if weak else ''))
            if res.startswith('MISMATCH'):
                rc = 1
    return rc


if __name__ == '__main__':
    sys.exit(main())
