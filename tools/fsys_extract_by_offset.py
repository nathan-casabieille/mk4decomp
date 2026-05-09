#!/usr/bin/env python3
"""Extract a FILESYS.DAT entry by offset and size (bypasses the hash lookup).

Usage:
    python3 tools/fsys_extract_by_offset.py <filesys.dat> <offset_hex> <size> <out>
"""
import sys
from pathlib import Path


def main():
    if len(sys.argv) != 5:
        print(__doc__)
        sys.exit(1)
    src = Path(sys.argv[1])
    off = int(sys.argv[2], 16) if sys.argv[2].startswith("0x") else int(sys.argv[2], 16)
    size = int(sys.argv[3])
    out = Path(sys.argv[4])
    with open(src, "rb") as f:
        f.seek(off)
        data = f.read(size)
    if len(data) != size:
        raise SystemExit(f"short read: got {len(data)} of {size} bytes")
    out.parent.mkdir(parents=True, exist_ok=True)
    out.write_bytes(data)
    print(f"OK  off=0x{off:x}  size={size}  -> {out}")


if __name__ == "__main__":
    main()
