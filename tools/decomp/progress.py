#!/usr/bin/env python3
"""Print MK4 matching-decomp progress.

Reads:
- config/symbols.yaml      - full function inventory + match status
- src/**/*.c               - written-and-claimed source

Reports:
- Total functions identified vs total in binary
- Per-subsystem progress
- Bytes of .text covered vs total

This is a quick at-a-glance dashboard. For per-function diff, see
diff.py.
"""
import os
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent.parent
SYMBOLS_FILE = ROOT / "config" / "symbols.yaml"


def load_symbols():
    if not SYMBOLS_FILE.exists():
        return []
    try:
        import yaml
    except ImportError:
        print("ERROR: install pyyaml - `pip install pyyaml`")
        sys.exit(1)
    with open(SYMBOLS_FILE) as f:
        data = yaml.safe_load(f)
    return data.get("functions", [])


def count_lines_of_c():
    total = 0
    for c in (ROOT / "src").rglob("*.c"):
        total += sum(1 for _ in open(c))
    return total


def main():
    syms = load_symbols()

    total_known      = len(syms)
    total_matched    = sum(1 for s in syms if s.get("status") == "matched")
    total_equivalent = sum(1 for s in syms if s.get("status") == "equivalent")
    total_drafted    = sum(1 for s in syms if s.get("status") == "drafted")
    total_stub       = sum(1 for s in syms if s.get("status") == "stub")
    total_unknown    = (total_known - total_matched - total_equivalent
                        - total_drafted - total_stub)

    bytes_total   = sum(s.get("size", 0) for s in syms)
    bytes_matched = sum(s.get("size", 0) for s in syms
                        if s.get("status") in ("matched", "equivalent"))

    # Estimate of total functions in MK4.EXE (.text = 0xd02e4 bytes,
    # avg function ~500 bytes → ~1700 fns).
    ESTIMATED_TOTAL_FNS = 1700

    print("MK4 matching decomp - progress")
    print("=" * 58)
    print(f"  Functions identified : {total_known:>5d} "
          f"(~{100*total_known/ESTIMATED_TOTAL_FNS:.1f}% of estimated total)")
    print(f"  Status:")
    print(f"    matched (byte-perfect)  : {total_matched:>5d}")
    print(f"    equivalent (sem. ident) : {total_equivalent:>5d}")
    print(f"    drafted (functional)    : {total_drafted:>5d}")
    print(f"    stub (asm-only)         : {total_stub:>5d}")
    print(f"    unimplemented           : {total_unknown:>5d}")
    print()
    print(f"  Bytes of .text covered   : {bytes_matched:>7d} / {bytes_total:>7d} "
          f"({100*bytes_matched/(bytes_total or 1):.1f}% of identified)")
    print()
    print(f"  Lines of C source        : {count_lines_of_c():>5d}")
    print()

    # Per-subsystem breakdown (by group name in symbols.yaml).
    by_group = {}
    for s in syms:
        g = s.get("group", "ungrouped")
        by_group.setdefault(g, [0, 0])
        by_group[g][0] += 1
        if s.get("status") in ("matched", "equivalent"):
            by_group[g][1] += 1
    if by_group:
        print("  Per-subsystem:")
        for g, (total, matched) in sorted(by_group.items()):
            bar_w = 30
            filled = int(bar_w * matched / total) if total else 0
            bar = "#" * filled + "-" * (bar_w - filled)
            print(f"    {g:<24s} [{bar}] {matched:>4d}/{total:<4d}")


if __name__ == "__main__":
    main()
