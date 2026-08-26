#!/usr/bin/env python3
"""Seeded co-exec verification for the BAM rotation-matrix builders.

BuildRotMatrix_OrderA / B / C turn three 16-bit BAM Euler angles into a packed
3x3 s16 matrix. They read g_sinTable, which is 4096 s32 entries indexed by BAM
(0x1000 = 2 PI) - and which is ALL-ZERO in the static image, because the engine
builds it at runtime (the third such table, after g_zSortKeyLUT and
g_div3Table). Without seeding it every matrix comes out zero and the check is
vacuous.

Scale: the builders read each entry `>> 16` and multiply with `>> 12`, so the
table holds sin * 2^28 and the working values are Q12 - the matrix's own fixed
point. The engine's identity is cos(a) = -sinTable[(a - 0x400) & 0xfff].

  build/venv/bin/python tools/decomp/verify_rot.py [NAME ...]
"""
import math
import struct
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import verify_twin as vt
import verify_coexec as vc

BASE = vc.BASE
SIN_VA = 0x007b01a0        # g_sinTable[4096], s32
ANG_VA = 0x007af800        # three s16 BAM angles (the arg scratch region)
MAT_VA = 0x007af840        # nine s16 output


def seed(a, ax, ay, az):
    for k in range(4096):
        struct.pack_into('<i', a, SIN_VA - BASE + k * 4,
                         int(round(math.sin(k * 2.0 * math.pi / 4096.0) * (1 << 28))))
    for i, v in enumerate((ax, ay, az)):
        struct.pack_into('<h', a, ANG_VA - BASE + i * 2, v)
    for i in range(9):                       # poison the output
        struct.pack_into('<h', a, MAT_VA - BASE + i * 2, -0x2222)


# BAM: 0x1000 = full turn, 0x400 = 90 degrees
ANGLES = [
    ('zero',      (0x000, 0x000, 0x000)),
    ('yaw-45',    (0x000, 0x200, 0x000)),
    ('pitch-90',  (0x400, 0x000, 0x000)),
    ('mixed',     (0x123, 0x456, 0x789)),
    ('negative',  (-0x123, -0x456, -0x789)),
    ('near-full', (0xfff, 0xffe, 0xffd)),
]


def main():
    names = sys.argv[1:] or ['BuildRotMatrix_OrderA', 'BuildRotMatrix_OrderB',
                             'BuildRotMatrix_OrderC']
    fn_va, gl_va = vt.load_maps()
    base = bytearray(vc.ARENA.read_bytes())
    vc.ARG_BASE = ANG_VA
    rc = 0
    for name in names:
        print(name)
        for label, ang in ANGLES:
            arena = bytearray(base)
            seed(arena, *ang)
            res = vc.verify(name, fn_va, gl_va, fn_va, arena,
                            argvals=(ANG_VA, MAT_VA))
            weak = 'VERIFIED (0 writes' in res
            print('  %-11s %s%s' % (label, res,
                                    '  WEAK(no matrix written)' if weak else ''))
            if res.startswith('MISMATCH'):
                rc = 1
    return rc


if __name__ == '__main__':
    sys.exit(main())
