#!/usr/bin/env python3
"""Consistency checks for symbols.yaml and the source tree.

Run by .github/workflows/ci.yml on every push and PR. Exits non-zero
on any inconsistency.

Strict checks (fail the build):
- every functions[] entry has addr, name, size
- no duplicate function names
- no duplicate addresses
- every entry's `file:` points to a real file under src/
- every entry's `name:` appears textually in that file

Lenient checks (warn but don't fail):
- overlapping address ranges (a small number are intentional - see
  feedback_packed_helpers_one_naked.md - "packed helpers under one
  naked body")
"""
import sys
from pathlib import Path

try:
    import yaml
except ImportError:
    print("ERROR: install pyyaml (pip install pyyaml)")
    sys.exit(1)

ROOT = Path(__file__).resolve().parent.parent.parent


def main():
    errors = []
    warnings = []

    with open(ROOT / "config" / "symbols.yaml") as f:
        data = yaml.safe_load(f)
    funcs = data.get("functions", [])

    def to_int(a):
        return int(a, 0) if isinstance(a, str) else a

    # Required fields + uniqueness.
    by_name = {}
    by_addr = {}
    for fn in funcs:
        name = fn.get("name")
        addr = fn.get("addr")
        size = fn.get("size")

        if not name:
            errors.append(f"entry missing name: {fn}")
            continue
        if addr is None:
            errors.append(f"{name}: missing addr")
            continue
        if size is None:
            errors.append(f"{name}: missing size")

        if name in by_name:
            errors.append(f"duplicate name: {name}")
        by_name[name] = fn

        ai = to_int(addr)
        if ai in by_addr:
            errors.append(
                f"duplicate addr: {ai:#x} ({name} vs {by_addr[ai]['name']})"
            )
        by_addr[ai] = fn

    # File and name-in-file consistency.
    file_cache = {}
    for fn in funcs:
        name = fn.get("name")
        path = fn.get("file")
        if not name or not path:
            continue
        full = ROOT / path
        if not full.exists():
            errors.append(f"{name}: file {path} does not exist")
            continue
        if path not in file_cache:
            file_cache[path] = full.read_text()
        if name not in file_cache[path]:
            errors.append(f"{name}: name not found in {path}")

    # Lenient: overlapping ranges.
    items = sorted(
        (to_int(fn["addr"]), fn["size"], fn["name"])
        for fn in funcs
        if fn.get("addr") is not None and fn.get("size") is not None
    )
    for i in range(len(items) - 1):
        a, sz, n1 = items[i]
        b, _, n2 = items[i + 1]
        if a + sz > b:
            warnings.append(
                f"overlap: {n1} @ {a:#x}+{sz} overlaps {n2} @ {b:#x}"
            )

    if warnings:
        print(f"WARN: {len(warnings)} overlapping address ranges")
        for w in warnings[:5]:
            print(f"  {w}")
        if len(warnings) > 5:
            print(f"  ... and {len(warnings) - 5} more")
        print()

    if errors:
        print(f"FAIL: {len(errors)} errors")
        for e in errors[:50]:
            print(f"  {e}")
        if len(errors) > 50:
            print(f"  ... and {len(errors) - 50} more")
        sys.exit(1)

    print(f"OK: {len(funcs)} symbols, all consistent")


if __name__ == "__main__":
    main()
