#!/usr/bin/env python3
"""Seeded co-exec verification for the integer projection/transform twins that
feed the draw-queue emitters (ProjectVertex, ProjectTwoVertices, MatVec2Multiply,
TransformVertex, AltCamMatrixProject).

Stock verify_coexec reports these as "VERIFIED (0 writes) [capped]" - a FALSE
positive: with the input globals all zero the function takes a trivial path and
writes nothing, so equivalence is vacuous. This harness seeds a non-trivial 3x3
matrix (0x7af990, nine s16 at +2 stride), input vertices (g_triStripX0/1/2), a
light matrix + light vector, and assorted scratch so the function does REAL work
and writes its output globals; then it runs the original bytes vs the compiled
twin in Unicorn and diffs the whole arena. Non-zero writes + diffs==0 = real.

  build/venv/bin/python tools/decomp/verify_project.py [NAME ...]
"""
import struct
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import verify_twin as vt
import verify_coexec as vc

BASE = vc.BASE
MAT = 0x7af990        # g_mat3x3_007af990: nine s16, +2 stride (projection matrix)
LIGHTMAT = 0x7af9c0   # g_lightMat00.. (dword-spaced)


def setw(a, va, v):
    struct.pack_into('<h', a, va - BASE, v & 0xffff if v >= 0 else v)


def setdw(a, va, v):
    struct.pack_into('<i', a, va - BASE, v)


# A mild rotation-ish fixed-point matrix (Q12: 0x1000 == 1.0) - non-degenerate,
# keeps projected Z positive so the near-plane validity checks pass.
MATRIX = [0x0f00, 0x0200, 0x0080,
          -0x0180, 0x0ec0, 0x0140,
          0x0040, -0x0120, 0x0fa0]


# 16-bit globals the originals read `movsx word` (confirmed by disassembling
# ProjectVertex): the packed 3x3 matrix (+2 stride) and the three vertex coords.
# gdef must type these as `short`, else a 32-bit read is polluted by the neighbor.
WIDTH16 = {'g_mat3x3_007af990', 'g_mat3x3_007af992', 'g_mat3x3_007af994',
           'g_mat3x3_007af996', 'g_mat3x3_007af998', 'g_mat3x3_007af99a',
           'g_mat3x3_007af99c', 'g_mat3x3_007af99e', 'g_mat3x3_007af9a0',
           'g_triStripX0', 'g_triStripX1', 'g_triStripX2',
           'g_vtxIn1_y', 'g_vtxIn1_z', 'g_vtxIn2_x', 'g_vtxIn2_y', 'g_vtxIn2_z'}


def seed_common(a):
    # projection matrix (nine s16, +2 stride)
    for i, v in enumerate(MATRIX):
        setw(a, MAT + i * 2, v)
    # the input vertex = three s16 components (x,y,z) in g_triStripX0/1/2, which
    # are 6 bytes apart (0x7af95c/962/968) - each a single word, NOT a 3-word group.
    setw(a, 0x7af95c, 0x0040)                  # g_triStripX0 (x)
    setw(a, 0x7af962, 0x0030)                  # g_triStripX1 (y)
    setw(a, 0x7af968, 0x0500)                  # g_triStripX2 (z)
    setdw(a, 0x7af9a4, 0x0010)                 # g_vtxTransX (32-bit translation)
    setdw(a, 0x7af9a8, 0x0020)                 # g_vtxTransY
    setdw(a, 0x7af9ac, 0x0040)                 # g_vtxTransZ (keep projected Z > 1)
    setdw(a, 0x7af98c, 0x0200)                 # g_min_007af98c (scratch input)
    # light matrix (g_lightMat00/01/02/20/21/22, dword slots) + light vector
    lm = {0x7af9c0: 0x0f00, 0x7af9c4: 0x0100, 0x7af9c8: 0x0080,
          0x7af9d8: 0x0040, 0x7af9dc: -0x0120, 0x7af9e0: 0x0fa0}
    for va, v in lm.items():
        setdw(a, va, v)
    setdw(a, 0x7af9e4, 0x0050)                 # g_vtxLight1_x
    setdw(a, 0x7af9ec, 0x0030)                 # g_vtxLight1_y
    setdw(a, 0x7af9e8, 0x0400)                 # g_vtxLight1_z (note: y/z swapped VAs)


# Scalar (non-pointer) arguments, per function. verify_coexec's default hands
# every arg a self-referential scratch ADDRESS, which is right for a pointer but
# catastrophic for a small index: Helper_EmitLine(i) indexes [i*2 + 0x7af958].
# A tuple entry of None keeps the default pointer-scratch for that slot.
ARGVALS = {
    'Helper_EmitLine': (0,),          # vertex slot; 0/1/2 are the real callers
    'Helper_EmitLine#1': (1,),
    'Helper_EmitLine#2': (2,),
    'AltCamMatrixProject': (None, 0),  # (vec3 *, mode) - mode 0 = no alt matrix
    'AltCamMatrixProject#1': (None, 1),
}


def main():
    names = sys.argv[1:] or ['MatVec2Multiply', 'ProjectVertex',
                             'ProjectTwoVertices', 'TransformVertex',
                             'AltCamMatrixProject', 'Helper_EmitLine',
                             'Helper_EmitLine#1', 'Helper_EmitLine#2',
                             'AltCamMatrixProject#1']
    fn_va, gl_va = vt.load_maps()
    base = bytearray(vc.ARENA.read_bytes())
    # Set ARG_BASE for the (rare) functions taking pointer args - point at a
    # benign in-arena scratch so a pointer walk does not fault.
    vc.ARG_BASE = 0x7af800
    rc = 0
    for spec in names:
        # "NAME#k" = the same function under argument variant k (see ARGVALS).
        name = spec.split('#')[0]
        seeded = bytearray(base)
        seed_common(seeded)
        res = vc.verify(name, fn_va, gl_va, fn_va, seeded, width16=WIDTH16,
                        argvals=ARGVALS.get(spec))
        weak = 'VERIFIED (0 writes' in res
        flag = 'WEAK(no writes - seed missed inputs)' if weak else ''
        print('  %-22s %s %s' % (spec, res, flag))
        if res.startswith('MISMATCH'):
            rc = 1
    return rc


if __name__ == '__main__':
    sys.exit(main())
