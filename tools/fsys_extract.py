#!/usr/bin/env python3
"""Extract an asset from FILESYS.DAT by name (full c:\\source\\mk4\\... path).

Usage:
    python3 tools/fsys_extract.py game/FILESYS.DAT 'c:\\source\\mk4\\win\\menu.tga' out/menu.tga
"""
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
from fsys_hash import fsys_hash, read_table


def extract(filesys_dat: Path, asset_path: str, out_path: Path):
    target = fsys_hash(asset_path)
    for i, (h, off, size) in enumerate(read_table(filesys_dat)):
        if h == target:
            with open(filesys_dat, 'rb') as f:
                f.seek(off)
                data = f.read(size)
            out_path.parent.mkdir(parents=True, exist_ok=True)
            out_path.write_bytes(data)
            print(f"OK  entry {i}  off=0x{off:08x}  size={size}  -> {out_path}")
            return
    raise SystemExit(f"hash 0x{target:08x} not in table - name {asset_path!r} not in archive")


if __name__ == '__main__':
    if len(sys.argv) != 4:
        print(__doc__)
        sys.exit(1)
    extract(Path(sys.argv[1]), sys.argv[2], Path(sys.argv[3]))
