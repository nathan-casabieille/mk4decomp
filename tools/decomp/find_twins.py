#!/usr/bin/env python3
"""Find structurally-identical naked functions ("twins").

Two naked functions are twins if they have the same instruction shape
(same opcodes in the same order) but differ only in constants/addresses.
Converting one twin to pure C gives a template that should work on all
its twins.

Usage:
    python3 tools/decomp/find_twins.py            # report all twin groups
    python3 tools/decomp/find_twins.py --min 2    # only groups of >= 2
    python3 tools/decomp/find_twins.py --grep X   # filter group by name match
"""
import argparse
import collections
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent.parent
SRC = ROOT / "src"

NAKED_RE = re.compile(
    r'__declspec\s*\(\s*naked\s*\)\s+\w+\s+(\w+)\s*\([^)]*\)\s*\{\s*'
    r'__asm\s*\{([^}]*)\}\s*\}',
    re.DOTALL,
)


def fingerprint(asm_body):
    """Reduce an asm body to its structural fingerprint.

    Drops:
      - whitespace / comments
      - constants (literals like 0xABCD, decimal numbers)
      - addresses inside memory operands (0x004XXXXX style)
      - symbol references (replaced by a generic token)

    Keeps:
      - mnemonic sequence
      - operand register names
      - operand kinds ([reg], [reg+disp], imm, mem, etc.)
    """
    out = []
    for raw in asm_body.split("\n"):
        line = re.sub(r";.*$", "", raw).strip()
        if not line:
            continue
        parts = line.split(None, 1)
        mnemonic = parts[0].lower()
        if len(parts) < 2:
            out.append(mnemonic)
            continue
        ops = parts[1]
        # Normalize constants
        ops = re.sub(r"\b0x[0-9a-fA-F]+\b", "IMM", ops)
        ops = re.sub(r"\b\d+h?\b", "IMM", ops)
        # Normalize symbol references inside memory ops: [name + N] or [reg*4 + name]
        ops = re.sub(r"\b(g_\w+|func_\w+|[A-Z]\w+_[0-9a-f]{8})\b", "SYM", ops)
        # Normalize whitespace inside operands
        ops = re.sub(r"\s+", " ", ops)
        out.append(f"{mnemonic} {ops}")
    return "\n".join(out)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--min", type=int, default=2, help="minimum group size")
    ap.add_argument("--grep", default=None, help="filter by name substring")
    args = ap.parse_args()

    groups = collections.defaultdict(list)
    for src_file in SRC.rglob("*.c"):
        try:
            text = src_file.read_text()
        except Exception:
            continue
        for m in NAKED_RE.finditer(text):
            name = m.group(1)
            if args.grep and args.grep not in name:
                continue
            fp = fingerprint(m.group(2))
            groups[fp].append((name, src_file.relative_to(ROOT).as_posix()))

    big = [(fp, members) for fp, members in groups.items()
           if len(members) >= args.min]
    big.sort(key=lambda x: -len(x[1]))

    total_members = sum(len(m) for _, m in big)
    print(f"Twin groups (>= {args.min} members): {len(big)} groups, "
          f"{total_members} naked functions covered\n")
    for fp, members in big[:50]:
        lines = fp.split("\n")
        opc = " ".join(l.split()[0] for l in lines[:6])
        print(f"=== {len(members)} twins, {len(lines)} lines: {opc} ...")
        for name, path in members[:10]:
            print(f"    {name}    [{path}]")
        if len(members) > 10:
            print(f"    ... +{len(members) - 10} more")
        print()


if __name__ == "__main__":
    main()
