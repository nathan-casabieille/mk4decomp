#!/usr/bin/env python3
"""Brute-force asset name discovery against FILESYS.DAT.

The hash function and path-prefix convention are known (see fsys_hash.py).
Generate candidate names and look for hits in the table.
"""
import sys
from pathlib import Path

# import siblings
sys.path.insert(0, str(Path(__file__).parent))
from fsys_hash import fsys_hash, read_table


# Build a hash → entry index map once.
def build_index(filesys_dat: Path):
    return {h: (i, off, size) for i, (h, off, size) in enumerate(read_table(filesys_dat))}


def gen_pcmk_sounds():
    """c:\\source\\mk4\\win\\sound\\pcmkNNNN.esf - try 0..9999"""
    for n in range(10000):
        yield f"c:\\source\\mk4\\win\\sound\\pcmk{n:04d}.esf"


def gen_geogfx(seeds):
    """c:\\source\\mk4\\win\\geogfx\\<seed>.<ext>"""
    exts = ["geo", "tga", "bmp", "pal", "raw", "spr", "tex", "img", "fnt"]
    for seed in seeds:
        for ext in exts:
            yield f"c:\\source\\mk4\\win\\geogfx\\{seed}.{ext}"


def gen_anim(seeds):
    """c:\\source\\mk4\\win\\anim\\<seed>.<ext>"""
    exts = ["anm", "ani", "anim", "spr", "tga", "geo", "raw", "dat"]
    for seed in seeds:
        for ext in exts:
            yield f"c:\\source\\mk4\\win\\anim\\{seed}.{ext}"


def gen_top_level_assets(seeds):
    """c:\\source\\mk4\\win\\<seed>.<ext>"""
    exts = ["tga", "bmp", "raw", "geo", "dat", "fnt", "pal"]
    for seed in seeds:
        for ext in exts:
            yield f"c:\\source\\mk4\\win\\{seed}.{ext}"


def gen_explicit_filenames(filenames):
    """Try each explicit filename in geogfx/, anim/, and top-level."""
    for fn in filenames:
        for folder in ["geogfx\\", "anim\\", ""]:
            yield f"c:\\source\\mk4\\win\\{folder}{fn}"


def load_asset_names_from(path):
    return [line.strip() for line in open(path) if line.strip()]


# Common MK4 asset name guesses
KOMBATANT_NAMES = [
    "scorpion", "subzero", "raiden", "lukang", "lui_kang",
    "johnny", "jncage", "sonya", "jax", "kano", "shang",
    "shao_kahn", "shaokahn", "kitana", "mileena", "jade",
    "reptile", "smoke", "noob", "ermac", "rain",
    "kabal", "stryker", "cyrax", "sektor",
    "fujin", "tanya", "reiko", "shinok", "shinnok",
    "quanchi", "quan_chi", "kai", "jarek", "goro",
    "scorp", "sub",
]

GENERIC_SEEDS = [
    "menu", "main", "title", "logo", "intro", "credits",
    "select", "select1", "select2", "char_sel", "charsel",
    "vs", "versus", "fight", "round", "win", "lose",
    "midway", "midway_g", "logo", "loading",
    "options", "settings", "config", "controls",
    "background", "bg", "bg1", "bg2", "ground",
    "stage", "stage1", "stage2", "tomb", "well", "prison",
    "kombatzone", "kz1", "kz2", "kz3",
    "blood", "fatality",
]


def brute(name, generator, table_index, max_print=20):
    hits = []
    tried = 0
    for path in generator:
        tried += 1
        h = fsys_hash(path)
        if h in table_index:
            i, off, size = table_index[h]
            hits.append((path, i, off, size))
    print(f"\n=== {name} ===")
    print(f"tried {tried} candidates, {len(hits)} hits")
    for path, i, off, size in hits[:max_print]:
        print(f"  entry {i:4d}  off=0x{off:08x}  size={size:>10d}  {path}")
    if len(hits) > max_print:
        print(f"  ... and {len(hits) - max_print} more")
    return hits


def main():
    if len(sys.argv) != 2:
        print("usage: fsys_bruteforce.py <FILESYS.DAT>")
        sys.exit(1)
    table = build_index(Path(sys.argv[1]))
    print(f"loaded {len(table)} entries from FILESYS.DAT")

    seeds = KOMBATANT_NAMES + GENERIC_SEEDS

    all_hits = []
    all_hits += brute("pcmkNNNN.esf",  gen_pcmk_sounds(),       table)
    all_hits += brute("geogfx\\<x>",   gen_geogfx(seeds),       table)
    all_hits += brute("anim\\<x>",     gen_anim(seeds),         table)
    all_hits += brute("win\\<x>",      gen_top_level_assets(seeds), table)

    # Try every filename literal we found in MK4.EXE strings, in each folder.
    explicit_path = Path('/tmp/asset_names.txt')
    if explicit_path.exists():
        names = load_asset_names_from(explicit_path)
        all_hits += brute(
            f"explicit names ({len(names)})",
            gen_explicit_filenames(names),
            table,
            max_print=200,
        )

    print(f"\n\nTotal hits found: {len(all_hits)}")
    print(f"Coverage: {len(all_hits)} / {len(table)} = {100*len(all_hits)/len(table):.1f}%")

    # List unmatched entries (sorted by size, smallest first - fonts/palettes)
    matched_hashes = set()
    for path, _, _, _ in all_hits:
        matched_hashes.add(fsys_hash(path))
    unmatched = [(i, off, size) for h, (i, off, size) in table.items() if h not in matched_hashes]
    print(f"\n\nUnmatched: {len(unmatched)} entries")
    unmatched.sort(key=lambda x: x[2])
    print("Smallest 20 (likely fonts / palettes / small data):")
    for i, off, size in unmatched[:20]:
        print(f"  entry {i:4d}  off=0x{off:08x}  size={size:>10d}")
    print("Largest 10 (likely backgrounds / textures):")
    for i, off, size in unmatched[-10:]:
        print(f"  entry {i:4d}  off=0x{off:08x}  size={size:>10d}")


if __name__ == '__main__':
    main()
