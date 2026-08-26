#!/usr/bin/env python3
"""Dump MK4's .geo asset tables: which character uses which mesh files.

Two static tables in the EXE, found by locating the `*.geo` name strings and
searching for dwords that point at them:

  0x004f65a0  the ASSET table - 121 records of { char *name; u32 a; u32 b; }
              `a` = (slot << 16) | 2, and the records come in groups of FOUR
              (base / _a_ / _g_ / _a_ variants) sharing one slot number.
              This is what LoadGeoAsset_Textures (0x004bd6e0) indexes: it does
              `edx = node[+0]`, `ecx = arg0 * 3`, `name = [edx + ecx*4]`, then
              sprintf's "c:\\source\\mk4\\win\\geogfx\\%s" and Mem_Mallocs the
              file into node[+4].

  0x00516d2c  the ROSTER table - 12-byte records whose first dword points at
              every FOURTH asset record, i.e. at one character's group of
              variants. 16 valid entries (the pairs look like two slots per
              character) before the data stops being pointers.

Neither table is referenced by any instruction directly - the code reaches the
asset table through node[+0], so a plain xref search for the address finds
nothing. The roster table is what holds the only pointers to it.

  build/venv/bin/python tools/geo_roster.py [--assets]
"""
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / 'tools' / 'decomp'))
import verify_coexec as vc

ASSETS = 0x004f65a0
ROSTER = 0x00516d2c


def main():
    img = vc.ARENA.read_bytes()

    def cstr(va):
        o = va - vc.BASE
        if not (0 <= o < len(img)):
            return None
        e = o
        while e < len(img) and img[e] and e - o < 32:
            e += 1
        return img[o:e].decode('latin1')

    if '--assets' in sys.argv:
        print('asset table @0x%x  { char *name; u32 slot_and_kind; u32 }' % ASSETS)
        for k in range(121):
            p, a, b = struct.unpack_from('<III', img, ASSETS - vc.BASE + k * 12)
            nm = cstr(p)
            if not nm or not nm.endswith('.geo'):
                break
            print('  [%3d] %-14s slot=%-3d kind=%d' % (k, nm, a >> 16, a & 0xffff))
        return 0

    print('roster @0x%x -> asset groups of four' % ROSTER)
    for k in range(24):
        p, b, c = struct.unpack_from('<III', img, ROSTER - vc.BASE + k * 12)
        if not (ASSETS <= p < ASSETS + 121 * 12):
            print('  [%2d] (end of pointer records)' % k)
            break
        idx = (p - ASSETS) // 12
        names = []
        for j in range(4):
            q = struct.unpack_from('<I', img, p - vc.BASE + j * 12)[0]
            nm = cstr(q)
            names.append(nm if nm and nm.endswith('.geo') else '?')
        print('  [%2d] asset[%3d..%3d]  %s' % (k, idx, idx + 3, ', '.join(names)))
    return 0


if __name__ == '__main__':
    sys.exit(main())
