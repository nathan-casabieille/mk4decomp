#!/usr/bin/env python3
"""Print MK4 matching-decomp progress.

Reports two metrics:
- Byte-perfect rebuild: functions whose compiled bytes match the orig .text.
  This is the floor of the project (`make matching` must always be 100%).
- Decompiled to C: functions whose source is real C (not a
  `__declspec(naked)` __asm wrapper). This is the real work-in-progress.

For per-function diff, see diff.py / diff_fn_obj.py.
"""
import os
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent.parent
SYMBOLS_FILE = ROOT / "config" / "symbols.yaml"
SVG_FILE     = ROOT / ".github" / "progress.svg"

# Match `__declspec(naked) <return_type ...> NAME(` and capture NAME.
# Tolerates whitespace, multiple modifiers, multi-line return types.
NAKED_DEF_RE = re.compile(
    r'__declspec\s*\(\s*naked\s*\)'   # __declspec(naked)
    r'[^{;]*?'                         # any return type / qualifiers (non-greedy, no { or ;)
    r'\b([A-Za-z_]\w*)\s*\(',          # captured: function name + (
    re.MULTILINE | re.DOTALL,
)


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


def naked_names_in(path):
    """Return the set of function names defined as __declspec(naked) in `path`."""
    try:
        with open(path) as f:
            src = f.read()
    except FileNotFoundError:
        return set()
    return set(NAKED_DEF_RE.findall(src))


def render_svg(percent, out_path):
    """Re-emit the progress bar SVG at the new percent.

    Keeps the visual style of the existing one (gradient flame fill, dark
    border, Impact-style centered numeric label) and just resizes the
    filled portion and updates the text.
    """
    pct = max(0.0, min(100.0, percent))
    fill_w = 592 * pct / 100.0
    svg = f'''<svg xmlns="http://www.w3.org/2000/svg" width="600" height="44" viewBox="0 0 600 44" role="img" aria-label="Progress {pct:.1f}%">
  <title>Progress: {pct:.1f}%</title>
  <defs>
    <linearGradient id="fillGrad" x1="0" y1="0" x2="0" y2="1">
      <stop offset="0%"   stop-color="#ffd24a"/>
      <stop offset="45%"  stop-color="#f59e0b"/>
      <stop offset="80%"  stop-color="#b91c1c"/>
      <stop offset="100%" stop-color="#7f1d1d"/>
    </linearGradient>
    <linearGradient id="borderGrad" x1="0" y1="0" x2="0" y2="1">
      <stop offset="0%" stop-color="#fde68a"/>
      <stop offset="100%" stop-color="#92400e"/>
    </linearGradient>
  </defs>

  <!-- Outer track -->
  <rect x="1" y="1" width="598" height="42" rx="6" ry="6"
        fill="#0a0a0a" stroke="url(#borderGrad)" stroke-width="2"/>

  <!-- Filled portion -->
  <rect x="4" y="4" width="{fill_w:.2f}" height="36" rx="4" ry="4"
        fill="url(#fillGrad)"/>

  <!-- Top highlight on filled portion only -->
  <rect x="4" y="4" width="{fill_w:.2f}" height="8" rx="4" ry="4"
        fill="#ffffff" opacity="0.18"/>

  <!-- Percent text -->
  <text x="300" y="29"
        font-family="Impact, 'Arial Black', sans-serif"
        font-size="20" font-weight="900"
        text-anchor="middle"
        fill="#fff8e1"
        stroke="#1a0a0a" stroke-width="1.2"
        paint-order="stroke fill"
        letter-spacing="2">
    {pct:.1f}%
  </text>
</svg>
'''
    out_path.write_text(svg)


def main():
    syms = load_symbols()

    total = len(syms)
    if total == 0:
        print("No symbols loaded - run from project root.")
        sys.exit(1)

    # --- Byte-perfect: status == matched (set by hand when a function diffs clean).
    matched = sum(1 for s in syms if s.get("status") == "matched")

    # --- Decompiled to C: source is not __declspec(naked).
    # Build a per-file naked-name cache so we only parse each .c once.
    file_naked_cache = {}
    decompiled = 0
    naked = 0
    missing_file = 0
    for s in syms:
        f = s.get("file")
        name = s.get("name")
        if not f or not name:
            missing_file += 1
            continue
        path = ROOT / f
        if path not in file_naked_cache:
            file_naked_cache[path] = naked_names_in(path)
        if name in file_naked_cache[path]:
            naked += 1
        else:
            decompiled += 1

    def pct(n, d): return 100.0 * n / d if d else 0.0

    print("MK4 matching decomp - progress")
    print("=" * 64)
    print()
    print(f"  Byte-perfect rebuild   {pct(matched, total):>6.1f}%   "
          f"({matched} / {total} functions)")
    print(f"  Decompiled to C        {pct(decompiled, total):>6.1f}%   "
          f"({decompiled} / {total} functions)")
    print()
    print(f"      still __declspec(naked) : {naked}")
    if missing_file:
        print(f"      no file: in symbols.yaml: {missing_file}")
    print()

    # Per-group breakdown of "decompiled to C".
    by_group = {}
    for s in syms:
        g = s.get("group", "ungrouped")
        by_group.setdefault(g, {"total": 0, "c": 0})
        by_group[g]["total"] += 1
        f = s.get("file")
        name = s.get("name")
        if f and name:
            path = ROOT / f
            if name not in file_naked_cache.get(path, set()):
                by_group[g]["c"] += 1

    if by_group:
        print("  Per-subsystem (decompiled to C):")
        for g, v in sorted(by_group.items(),
                           key=lambda kv: -pct(kv[1]["c"], kv[1]["total"])):
            t, c = v["total"], v["c"]
            bar_w = 30
            filled = int(bar_w * c / t) if t else 0
            bar = "#" * filled + "-" * (bar_w - filled)
            print(f"    {g:<20s} [{bar}] {pct(c, t):>5.1f}%  ({c}/{t})")
        print()

    # Update the README progress.svg to the "decompiled to C" percent.
    if "--no-svg" not in sys.argv:
        render_svg(pct(decompiled, total), SVG_FILE)
        print(f"  Wrote {SVG_FILE.relative_to(ROOT)} "
              f"({pct(decompiled, total):.1f}%)")


if __name__ == "__main__":
    main()
