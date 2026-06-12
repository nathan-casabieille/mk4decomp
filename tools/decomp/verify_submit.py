#!/usr/bin/env python3
"""Seeded co-exec verification for Helper_DrawCursor @0x4c3360 (SubmitDraw): the
UPSTREAM enqueue that FlushDrawQueue later sorts + dispatches.

It bounds-checks a 28-byte DrawEntry (the arg pointer) against the viewport
envelope (Y fields +2/+6/+0xa, then X fields +0/+4/+8), skipping vertex 1 when
flag (+0x1a) bit 0x20 is set; rejects out-of-envelope entries; otherwise copies
the entry into g_drawQueue[g_drawQueueSize], rewrites the sort key at +0x12
through g_zSortKeyLUT, and bumps g_drawQueueSize.

The harness seeds a DrawEntry at an in-arena scratch VA (run_at points arg0
there via ARG_BASE), a populated g_zSortKeyLUT, g_drawQueueSize, then runs the
original bytes vs the compiled twin in Unicorn and diffs the whole arena (the
queue slot, sort-key patch, clip scratch, and the size counter).

  build/venv/bin/python tools/decomp/verify_submit.py
"""
import struct
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import verify_twin as vt
import verify_coexec as vc

BASE = vc.BASE
ENTRY_VA = 0x00f60000          # in-arena scratch for the DrawEntry (below the queue)
DQ_VA = 0x00f71310             # g_drawQueue base
QSIZE_VA = 0x00f85b40          # g_drawQueueSize
LUT_VA = 0x00b0d008            # g_zSortKeyLUT[65536] (u16)
CLIPMIN_VA = 0x00f70f70
CLIPMAX_VA = 0x00f70f78


def setw(a, va, v):
    struct.pack_into('<H', a, va - BASE, v & 0xffff)


def setb(a, va, v):
    a[va - BASE] = v & 0xff


def setdw(a, va, v):
    struct.pack_into('<I', a, va - BASE, v & 0xffffffff)


def seed_entry(a, x0, y0, x1, y1, x2, y2, flags, key):
    e = ENTRY_VA
    setw(a, e + 0, x0);  setw(a, e + 2, y0)        # v0
    setw(a, e + 4, x1);  setw(a, e + 6, y1)        # v1 (skipped if flag 0x20)
    setw(a, e + 8, x2);  setw(a, e + 0xa, y2)      # v2
    for o in range(0xc, 0x1c, 2):                  # uv/color/etc marker payload
        setw(a, e + o, (0x1100 + o) & 0xffff)
    setw(a, e + 0x12, key)                         # sort key (LUT input)
    setb(a, e + 0x1a, flags)


SCEN = [
    ('in-bounds',   dict(x0=20,  y0=20,  x1=160, y1=40,  x2=80,  y2=120, flags=0,    key=5)),
    ('flag-0x20',   dict(x0=20,  y0=20,  x1=999, y1=999, x2=80,  y2=120, flags=0x20, key=9)),
    ('reject-y-hi', dict(x0=20,  y0=600, x1=160, y1=40,  x2=80,  y2=700, flags=0,    key=1)),
    ('reject-x-hi', dict(x0=900, y0=20,  x1=160, y1=40,  x2=950, y2=120, flags=0,    key=2)),
    ('neg-margin',  dict(x0=-50, y0=-50, x1=10,  y1=10,  x2=-80, y2=-90, flags=0,    key=7)),
    ('key-zero',    dict(x0=30,  y0=30,  x1=120, y1=60,  x2=70,  y2=100, flags=0,    key=0)),
    ('key-large',   dict(x0=30,  y0=30,  x1=120, y1=60,  x2=70,  y2=100, flags=0,    key=0xfffe)),
    ('reject-all',  dict(x0=600, y0=600, x1=620, y1=620, x2=640, y2=660, flags=0,    key=3)),
    ('reject-negx', dict(x0=-200,y0=30,  x1=-210,y1=60,  x2=-220,y2=100, flags=0,    key=4)),
]


def main():
    name = 'Helper_DrawCursor'
    fn_va, gl_va = vt.load_maps()
    base = bytearray(vc.ARENA.read_bytes())

    t = vc.extract_twin_any(name)
    if not t:
        print(name, 'SKIP no-twin')
        return 1
    body, nargs, _ = t
    blob, entry, lb, err = vc.build_twin_blob(name, body, gl_va, fn_va,
                                              fn_self_va=fn_va[name])
    if blob is None:
        print(name, 'SKIP build:', err)
        return 1
    vc.ARG_BASE = ENTRY_VA                          # arg0 -> our seeded DrawEntry
    blob_lo, blob_hi = lb & ~3, (lb + len(blob) + 3) & ~3

    def run(load_twin, qsize, scen):
        arena = bytearray(base)
        setdw(arena, QSIZE_VA, qsize)
        # distinct LUT so the +0x12 patch is observable: LUT[k] = k ^ 0x5a5a
        for k in (scen['key'], 0, 0xfffe):
            setw(arena, LUT_VA + k * 2, (k ^ 0x5a5a) & 0xffff)
        seed_entry(arena, **scen)
        uc, full = vc.uc_new(arena)
        if load_twin:
            if lb + len(blob) > full:
                uc.mem_map(lb & ~0xFFF,
                           ((len(blob) + (lb & 0xFFF) + 0xFFF) & ~0xFFF))
            uc.mem_write(lb, blob)
        return vc.run_at(uc, fn_va[name], full, nargs)

    rc = 0
    print(name)
    inv = {v: k for k, v in gl_va.items()}
    for label, scen in SCEN:
        qsize = 4                                   # enqueue into a non-empty queue
        o_buf, o_term, _ = run(False, qsize, scen)
        t_buf, t_term, _ = run(True, qsize, scen)
        diffs = [o for o in range(0, len(o_buf), 4)
                 if not (blob_lo <= o < blob_hi) and o_buf[o:o+4] != t_buf[o:o+4]]
        # did the enqueue happen? (size bumped) - o_buf is indexed from addr 0.
        bumped = o_buf[QSIZE_VA:QSIZE_VA+4] != bytes([qsize, 0, 0, 0])
        ok = o_term and t_term and not diffs
        print('  %-12s term=%d/%d enqueued=%s diffs=%-3d %s'
              % (label, o_term, t_term, bumped, len(diffs), 'OK' if ok else 'FAIL'))
        if not ok:
            rc = 1
            for o in diffs[:10]:
                va = o + BASE
                where = ('DQ+0x%x' % (va - DQ_VA)) if DQ_VA <= va < DQ_VA + 0x200 \
                    else inv.get(va, '0x%x' % va)
                print('      diff @%s: orig=%s twin=%s'
                      % (where, o_buf[o:o+4].hex(), t_buf[o:o+4].hex()))
    print('  =>', 'VERIFIED (all scenarios)' if rc == 0 else 'MISMATCH')
    return rc


if __name__ == '__main__':
    sys.exit(main())
