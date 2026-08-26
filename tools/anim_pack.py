#!/usr/bin/env python3
"""Decode MK4's animation pack - the two FILESYS.DAT entries that were the
archive's last unidentified files.

They are `<anim-dir><name>.AP0` and `.AP1`, loaded by Anim_LoadPackFile
(0x00401120). The exact <name> is still unknown (it is built at runtime with
sprintf from the prefix at 0x4d506c, so it never appears as a whole string, and
the trailing 0/1 digit puts its hash delta at 0x10000 only for names whose
length is a multiple of 4 - an exhaustive [a-z0-9_] sweep of length 4 found
nothing). The DATA needs no name: extract both by offset.

  AP0 - the directory
      0x000 .. 0x1ff   512-byte header (contents not yet decoded)
      0x200 ..         records of  { u16 id_and_flag; u16 size; }
                       id   = id_and_flag & 0x7fff
                       flag = id_and_flag & 0x8000  -> descriptor +8 bit 15
                       terminated by a record whose first word is 0xffff
  AP1 - the data
      the per-id blobs, concatenated in index order

Proof: the 612 record sizes sum to exactly 1,138,516 bytes = AP1's size, and
the ids are 0..611 with no repeats. (An earlier note summed the file from
offset 0 and got 1,269,068, which is why it looked like the two were
unrelated - the records start after the 512-byte header.)

At load time Anim_LoadPackFile turns the directory into a 12-byte descriptor
per id at 0x004ffdec { +0 data pointer, +4 ?, +8 flags }, running the offsets
cumulatively, and then reads AP1 over the same buffer - so the pointers land in
the animation data.

DESCRIPTOR TABLE (static, in the EXE at 0x004ffdec, 612 x 12 bytes, +0 == -1
terminates - exactly the 612 animations in the directory):

    +0  s32  data pointer  (0 in the image; the loader fills it)
    +4  s32  FRAME COUNT   (1..519, median ~30)
    +8  u32  (node_count << 16) | flags   node_count is 18 for 575 of the 612
                                          animations; bit 15 = compressed

UNCOMPRESSED animations (41 of 612) need no decoder at all. Anim_AcquireFrameData
(0x00401000) returns `(data >> 2) + node_count * frame` - a PACKED pointer - so
the payload is simply

    s32 data[frame_count][node_count]

PROVEN: for all 41 of them, size == 4 * node_count * frame_count exactly.

Compressed ones go through Anim_DecodeBitstream (0x004013a0) into a 128-byte
cache slot at 0x523b58 + slot*128, with 12 slots tracked at 0x523b28.

  build/venv/bin/python tools/anim_pack.py AP0 AP1 [--dump ID [out.bin]]
"""
import struct
import sys
from pathlib import Path

HEADER_SIZE = 0x200


def parse_index(ap0):
    """Yield (id, flag, size, offset_into_ap1)."""
    p, off = HEADER_SIZE, 0
    while p + 4 <= len(ap0):
        rec, size = struct.unpack_from('<HH', ap0, p)
        if rec == 0xffff:
            return
        yield (rec & 0x7fff, bool(rec & 0x8000), size, off)
        off += size
        p += 4


def main():
    if len(sys.argv) < 3:
        print(__doc__)
        return 2
    ap0 = Path(sys.argv[1]).read_bytes()
    ap1 = Path(sys.argv[2]).read_bytes()
    entries = list(parse_index(ap0))
    total = sum(e[2] for e in entries)
    print('AP0: %d bytes, %d records; AP1: %d bytes' % (len(ap0), len(entries), len(ap1)))
    print('  sizes sum to %d  (%s)' % (total, 'MATCHES AP1' if total == len(ap1) else 'MISMATCH'))
    print('  ids %d..%d, %d distinct, %d flagged'
          % (min(e[0] for e in entries), max(e[0] for e in entries),
             len({e[0] for e in entries}), sum(1 for e in entries if e[1])))

    if '--dump' in sys.argv:
        i = sys.argv.index('--dump')
        want = int(sys.argv[i + 1])
        out = Path(sys.argv[i + 2]) if len(sys.argv) > i + 2 else None
        for aid, flag, size, off in entries:
            if aid == want:
                blob = ap1[off:off + size]
                print('  anim %d: flag=%d size=%d @0x%06x' % (aid, flag, size, off))
                print('    head:', ' '.join('%02x' % b for b in blob[:48]))
                if out:
                    out.parent.mkdir(parents=True, exist_ok=True)
                    out.write_bytes(blob)
                    print('    wrote %s' % out)
                return 0
        print('  no such id')
        return 1

    print('\n  first 12 records:')
    for aid, flag, size, off in entries[:12]:
        print('    id=%-4d flag=%d size=%-6d off=0x%06x' % (aid, flag, size, off))
    return 0


if __name__ == '__main__':
    sys.exit(main())
