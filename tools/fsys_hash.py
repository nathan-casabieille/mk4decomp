#!/usr/bin/env python3
"""FILESYS.DAT hash function and asset table reader.

Reverse-engineered from MK4.EXE:
- FSYS_NormalizePath @ 0x004b1ec0 - uppercase the path; require X:\\ prefix
- FSYS_HashName     @ 0x004b1f50 - sum chars shifted into byte positions 0/1/2/3 cycling

Usage:
    python3 tools/fsys_hash.py hash 'c:\\source\\mk4\\win\\menu.tga'
    python3 tools/fsys_hash.py table game/FILESYS.DAT
    python3 tools/fsys_hash.py find game/FILESYS.DAT 'c:\\source\\mk4\\win\\menu.tga'
"""
import struct
import sys
from pathlib import Path


def fsys_normalize(path: str) -> str:
    """Uppercase the path. Validates the X:\\ prefix."""
    upper = path.upper()
    if len(upper) < 3 or upper[1] != ':' or upper[2] != '\\':
        raise ValueError(f"not a full Windows path (need X:\\...): {path!r}")
    return upper


def fsys_hash(path: str) -> int:
    """Reproduce FUN_004b1f50.

    Each char is signed-extended and shifted into one of 4 byte positions
    (0, 8, 16, 24), cycling every 4 chars. Final result is sum + length.
    """
    normalized = fsys_normalize(path)
    h = 0
    shift = 0
    for ch in normalized:
        # Match C signed-char-to-int sign extension.
        b = ord(ch)
        if b >= 0x80:
            b -= 0x100
        h = (h + (b << shift)) & 0xFFFFFFFF
        shift += 8
        if shift > 24:
            shift = 0
    h = (h + len(normalized)) & 0xFFFFFFFF
    return h


def read_table(filesys_dat: Path):
    """Yield (hash, offset, size) entries from the 12 KB header table."""
    with open(filesys_dat, 'rb') as f:
        header = f.read(0x3000)
    for i in range(0, len(header), 12):
        h, off, size = struct.unpack_from('<III', header, i)
        if h == 0:
            return
        yield h, off, size


def cmd_hash(args):
    path = args[0]
    print(f"input    : {path!r}")
    print(f"normalized: {fsys_normalize(path)!r}")
    print(f"hash      : 0x{fsys_hash(path):08x}")


def cmd_table(args):
    filesys_dat = Path(args[0])
    for i, (h, off, size) in enumerate(read_table(filesys_dat)):
        print(f"{i:4d}  hash=0x{h:08x}  offset=0x{off:08x}  size=0x{size:08x} ({size:>10d} B)")
    # also print stats
    entries = list(read_table(filesys_dat))
    print(f"\n{len(entries)} entries total")
    if entries:
        sizes = [e[2] for e in entries]
        print(f"min size: {min(sizes)} B")
        print(f"max size: {max(sizes)} B")
        print(f"sum size: {sum(sizes)} B")


def cmd_find(args):
    filesys_dat = Path(args[0])
    candidate = args[1]
    target_hash = fsys_hash(candidate)
    print(f"candidate : {candidate!r}")
    print(f"normalized: {fsys_normalize(candidate)!r}")
    print(f"hash      : 0x{target_hash:08x}")
    for i, (h, off, size) in enumerate(read_table(filesys_dat)):
        if h == target_hash:
            print(f"\n*** MATCH at entry {i}: offset=0x{off:08x} size=0x{size:08x} ***")
            return
    print("\n(no match in table)")


COMMANDS = {'hash': cmd_hash, 'table': cmd_table, 'find': cmd_find}


def main():
    if len(sys.argv) < 2 or sys.argv[1] not in COMMANDS:
        print(__doc__)
        sys.exit(1)
    COMMANDS[sys.argv[1]](sys.argv[2:])


if __name__ == '__main__':
    main()
