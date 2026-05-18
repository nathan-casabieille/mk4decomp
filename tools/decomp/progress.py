#!/usr/bin/env python3
"""Print MK4 matching-decomp progress.

Reports three metrics:
- Byte-perfect rebuild: functions whose compiled bytes match the orig .text.
  This is the floor of the project (`make matching` must always be 100%).
- Pure C: functions whose body contains no `__asm` block at all. This is the
  metric that matters for portability (e.g. a future WASM/Emscripten port,
  where x86 inline asm is unusable).
- Hybrid: functions no longer `__declspec(naked)` but whose body still
  contains at least one `__asm` block. These are intermediate - they're easier
  to convert piecewise to C than naked functions, but they remain x86-bound
  and don't unblock any non-x86 build target.

The remainder are `__declspec(naked)`, which is the starting state.

For per-function diff, see diff.py / diff_fn_obj.py.
"""
import os
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent.parent
SYMBOLS_FILE = ROOT / "config" / "symbols.yaml"
SVG_FILE     = ROOT / ".github" / "progress.svg"

# Match a top-level function definition:
#   [__declspec(naked)] <return-type> <ptr*> NAME (<args>) {
# Captures: group 1 = "naked" if present, group 2 = NAME.
# The return-type token list covers the C primitive types we actually use in
# this corpus plus any CamelCase typedef.
FN_DEF_RE = re.compile(
    r'(?:^|\n)'                                         # start of line
    r'(?:static\s+)?'                                   # optional static
    r'(__declspec\s*\(\s*naked\s*\)\s*)?'              # group 1: naked
    r'(?:void|int|short|char|long|unsigned|signed|float|double|'
    r'size_t|BOOL|HRESULT|DWORD|WORD|BYTE|HWND|HINSTANCE|HMODULE|LRESULT|CALLBACK|'
    r'u8|u16|u32|u64|s8|s16|s32|s64|'
    r'[A-Z][A-Za-z0-9_]*)'                              # primary return type
    r'(?:\s+(?:void|int|short|char|long|unsigned|signed))*'  # extra qualifiers ("unsigned int")
    r'(?:\s*\*+\s*|\s+)'                                # ptr stars OR whitespace separator
    r'([A-Za-z_]\w*)'                                   # group 2: function name
    r'\s*\([^;{]*?\)'                                   # arg list
    r'\s*\{',                                           # opening brace
)

ASM_BLOCK_RE  = re.compile(r'\b__asm\b')
NAKED_DECL_RE = re.compile(r'__declspec\s*\(\s*naked\s*\)')


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


def classify_file(path):
    """Classify every function defined in `path`.

    Returns a tuple `(per_fn, file_has_asm, file_has_naked)`:
    - `per_fn` is a dict {function_name: 'pure_c' | 'hybrid' | 'naked'} for
      every function whose definition the regex could anchor on.
    - `file_has_asm` is True if any `__asm` block appears anywhere in the file.
    - `file_has_naked` is True if any `__declspec(naked)` qualifier appears.

    Callers use the file-level flags as a fallback for functions whose
    definition isn't captured by the regex (e.g. macro-defined helpers like
    `DECL_SETTER(addr, name, val)`). If the file has no asm and no naked at
    all, any uncovered function in it is safely `pure_c`.
    """
    try:
        with open(path) as f:
            src = f.read()
    except FileNotFoundError:
        return ({}, False, False)

    file_has_asm   = bool(ASM_BLOCK_RE.search(src))
    file_has_naked = bool(NAKED_DECL_RE.search(src))

    per_fn = {}
    for m in FN_DEF_RE.finditer(src):
        is_naked = bool(m.group(1))
        name = m.group(2)
        # Walk braces to find the matching close brace.
        body_start = m.end()  # right after the opening {
        depth = 1
        i = body_start
        n = len(src)
        while i < n and depth > 0:
            c = src[i]
            if c == '{':
                depth += 1
            elif c == '}':
                depth -= 1
            i += 1
        body = src[body_start:i - 1] if depth == 0 else src[body_start:]
        has_asm = bool(ASM_BLOCK_RE.search(body))
        if is_naked:
            per_fn[name] = 'naked'
        elif has_asm:
            per_fn[name] = 'hybrid'
        else:
            per_fn[name] = 'pure_c'
    return (per_fn, file_has_asm, file_has_naked)


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

    # --- Build a per-file classification cache: each file is parsed once.
    file_cache = {}  # path -> (per_fn, file_has_asm, file_has_naked)
    counts = {'pure_c': 0, 'hybrid': 0, 'naked': 0, 'absent': 0}
    per_sym = {}  # name -> category, for per-group breakdown
    for s in syms:
        f = s.get("file")
        name = s.get("name")
        if not f or not name:
            counts['absent'] += 1
            continue
        path = ROOT / f
        if path not in file_cache:
            file_cache[path] = classify_file(path)
        per_fn, file_has_asm, file_has_naked = file_cache[path]
        if name in per_fn:
            cat = per_fn[name]
        elif not file_has_asm and not file_has_naked:
            # Function's definition wasn't caught by the regex (e.g. macro-
            # generated), but the file is asm-free and naked-free, so any
            # function defined here is safely pure C.
            cat = 'pure_c'
        else:
            cat = 'absent'
        counts[cat] += 1
        per_sym[name] = cat

    def pct(n, d): return 100.0 * n / d if d else 0.0

    pure_c = counts['pure_c']
    hybrid = counts['hybrid']
    naked  = counts['naked']
    absent = counts['absent']

    print("MK4 matching decomp - progress")
    print("=" * 64)
    print()
    print(f"  Byte-perfect rebuild   {pct(matched, total):>6.1f}%   "
          f"({matched} / {total} functions)")
    print(f"  Pure C (no __asm)      {pct(pure_c, total):>6.1f}%   "
          f"({pure_c} / {total} functions)")
    print(f"  Hybrid (no naked, asm) {pct(hybrid, total):>6.1f}%   "
          f"({hybrid} / {total} functions)")
    print(f"  Still __declspec(naked){pct(naked,  total):>6.1f}%   "
          f"({naked} / {total} functions)")
    if absent:
        print(f"      no file/name in symbols.yaml or not found in source: {absent}")
    print()

    # Per-group breakdown of "pure C" (the WASM-relevant metric).
    by_group = {}
    for s in syms:
        g = s.get("group", "ungrouped")
        by_group.setdefault(g, {"total": 0, "c": 0, "h": 0, "n": 0})
        by_group[g]["total"] += 1
        name = s.get("name")
        cat = per_sym.get(name)
        if cat == 'pure_c':
            by_group[g]["c"] += 1
        elif cat == 'hybrid':
            by_group[g]["h"] += 1
        elif cat == 'naked':
            by_group[g]["n"] += 1

    if by_group:
        print("  Per-subsystem (pure C / hybrid / naked):")
        for g, v in sorted(by_group.items(),
                           key=lambda kv: -pct(kv[1]["c"], kv[1]["total"])):
            t, c, h, n = v["total"], v["c"], v["h"], v["n"]
            bar_w = 30
            filled = int(bar_w * c / t) if t else 0
            bar = "#" * filled + "-" * (bar_w - filled)
            print(f"    {g:<20s} [{bar}] {pct(c, t):>5.1f}%  "
                  f"(C:{c} H:{h} N:{n} / {t})")
        print()

    # Update the README progress.svg to the "pure C" percent.
    # This is the metric that maps to actual decompilation progress (the
    # hybrid count is interesting separately but isn't real C source).
    if "--no-svg" not in sys.argv:
        render_svg(pct(pure_c, total), SVG_FILE)
        print(f"  Wrote {SVG_FILE.relative_to(ROOT)} "
              f"({pct(pure_c, total):.1f}%)")


if __name__ == "__main__":
    main()
