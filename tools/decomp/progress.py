#!/usr/bin/env python3
"""Print MK4 matching-decomp progress across multiple orthogonal axes.

The decomp project moves along several independent dimensions, and a single
"pure C %" number conflates them. The metrics reported here:

- **Byte-perfect rebuild** - functions whose compiled bytes match orig `.text`.
  This is the foundation of the project (`make matching` must always be 100%).
  Locked at 100% since the rebuild matched.

- **Portable C (pure C + twins)** - functions with no x86 `__asm` in the path
  a port compiles: pure-C bodies PLUS naked/hybrid functions that now carry a
  behaviour-equivalent `#ifdef NON_MATCHING` twin. This is the axis the
  asm->C / twin conversion work actually moves (toward a native/WASM port) and
  it IS in the composite. (Distinct from bare "Pure C" below.)

- **Pure C (no `__asm`)** - functions whose body contains no `__asm` block at
  all (so it serves BOTH builds with no twin). Has a **practical ceiling
  around 49%** with MSVC 5.0 SP3 - remaining naked functions hit codegen
  quirks pure C cannot reproduce. Shown for the matching build; NOT in the
  composite (asymptotic) and superseded by Portable C for port-readiness.

- **Symbol naming** - % of functions AND `g_*` globals whose name carries
  semantic content beyond a generic-prefix placeholder (the two naming axes
  merged - they move together). A name counts as "named" with no address
  suffix (`LoadGeoAsset_Textures`, `g_framePauseFlag`) or with a suffix but a
  specific identifier (`Wrapper_OrListLoop_004de3f8`, `PendingMatch_004013a0`).
  Bare placeholders like `func_00411f0` / `g_table_004ab4e78` are not named.

- **Struct field coverage** - % of fields in `typedef struct` blocks under
  `include/` that have a real name (not `_NN` / `_NN[K]` placeholders). This
  is what struct reconstruction moves: each newly-named ScenegraphNode /
  FightGroupNode / DrawEntry slot ticks it up.

- **Functional understanding** (composite) - arithmetic mean of symbol naming,
  struct-field coverage, and portable-C. Byte-match is excluded (always 100%,
  doesn't move); bare pure-C is excluded (asymptote ~49%). This is the
  headline number reflecting *current* contribution velocity - now including
  the portability work.

For per-function byte-diff, see diff.py / diff_fn_obj.py.
"""
import os
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent.parent
SYMBOLS_FILE = ROOT / "config" / "symbols.yaml"
INCLUDE_DIR  = ROOT / "include"
SRC_DIR      = ROOT / "src"
SVG_FILE     = ROOT / ".github" / "progress.svg"

# Match a top-level function definition (return type, optional ptr, name, args, brace).
FN_DEF_RE = re.compile(
    r'(?:^|\n)'
    r'(?:static\s+)?'
    r'(__declspec\s*\(\s*naked\s*\)\s*)?'
    r'(?:void|int|short|char|long|unsigned|signed|float|double|'
    r'size_t|BOOL|HRESULT|DWORD|WORD|BYTE|HWND|HINSTANCE|HMODULE|LRESULT|CALLBACK|'
    r'u8|u16|u32|u64|s8|s16|s32|s64|'
    r'[A-Z][A-Za-z0-9_]*)'
    r'(?:\s+(?:void|int|short|char|long|unsigned|signed))*'
    r'(?:\s*\*+\s*|\s+)'
    r'([A-Za-z_]\w*)'
    r'\s*\([^;{]*?\)'
    r'\s*\{',
)

ASM_BLOCK_RE  = re.compile(r'\b__asm\b')
NAKED_DECL_RE = re.compile(r'__declspec\s*\(\s*naked\s*\)')

# An address-suffix name like `Helper_00412ff0` or `g_audioBank_005433c0`.
ADDR_SUFFIX_RE = re.compile(r'_00[0-9a-fA-F]{6,}$')

# Generic prefixes that, paired with only an address suffix, leave a name
# with no semantic content. Names like `func_00411f0` or `g_table_004ab4e7`
# are pure placeholders; names with any additional segment beyond
# `<generic_prefix>_<addr>` (e.g. `Wrapper_OrListLoop_004de3f8` or
# `g_dispatchSave1000`) carry semantic information and count as named.
GENERIC_FN_PREFIXES = {'func', 'Helper', 'Sub', 'Lab', 'sub'}
GENERIC_G_PREFIXES  = {
    'g_table', 'g_byte', 'g_const', 'g_word', 'g_lit',
    'g_arr', 'g_fp', 'g_struct', 'g_iface', 'g_data',
    'g_x', 'g_state', 'g_zero', 'g_load',
}


def is_semantically_named(name):
    """A name is semantically named if it carries information beyond a generic
    prefix + address suffix.

    Examples:
      - `g_baseSel`               -> True  (no addr suffix at all)
      - `Wrapper_OrListLoop_004de3f8` -> True  (target name in the middle)
      - `MStackCall_MStackPush2ChainInsert_00406250` -> True
      - `PendingMatch_004013a0`   -> True  (specific FSM-family prefix)
      - `func_00411f0`            -> False (generic prefix + addr only)
      - `g_table_004ab4e78`       -> False (generic prefix + addr only)
      - `g_dispatchSave1000`      -> True  (no addr suffix, has slot ID)
    """
    if not ADDR_SUFFIX_RE.search(name):
        return True
    parts = name.split('_')
    non_hex = [p for p in parts if not re.fullmatch(r'[0-9a-fA-F]+', p)]
    if name.startswith('g_'):
        # For globals, the leading `g_<word>` is the prefix group; check if
        # that combined prefix is in the generic set, and require additional
        # semantic content beyond it.
        if len(non_hex) >= 2:
            head = '_'.join(non_hex[:2])
            if head in GENERIC_G_PREFIXES:
                return len(non_hex) >= 3
            return True
        return False
    else:
        # For functions, the first segment is the family prefix.
        if not non_hex:
            return False
        if non_hex[0] in GENERIC_FN_PREFIXES:
            return len(non_hex) >= 2
        return True


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

    Returns (per_fn, file_has_asm, file_has_naked) where per_fn maps function
    name to 'pure_c' | 'hybrid' | 'naked'. Callers use the file-level flags
    as a fallback for macro-defined helpers the regex misses.
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
        body_start = m.end()
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


def collect_twins():
    """Return the set of function names that have a portable `#ifdef
    NON_MATCHING` twin (a behaviour-equivalent C body used by every port
    target). A twin'd function's matching body is still naked, but it now
    has a portable form - so it counts toward portable-C coverage."""
    names = set()
    if not SRC_DIR.exists():
        return names
    for c in SRC_DIR.rglob("*.c"):
        try:
            s = c.read_text()
        except (OSError, UnicodeDecodeError):
            continue
        for m in re.finditer(r'#ifdef NON_MATCHING\b', s):
            j = s.find('#else', m.end())
            if j < 0:
                continue
            nm = re.search(r'\b([A-Za-z_]\w*)\s*\(', s[m.end():j])
            if nm:
                names.add(nm.group(1))
    return names


def count_function_naming(syms):
    """Return (named, total). 'named' = carries semantic content beyond
    `<generic_prefix>_<addr>` (see is_semantically_named)."""
    total = 0
    named = 0
    for s in syms:
        name = s.get("name")
        if not name:
            continue
        total += 1
        if is_semantically_named(name):
            named += 1
    return (named, total)


# Global declarations to harvest: any `extern <type> g_NAME` line (including
# array forms `g_NAME[N]` and function-pointer typedefs). We only count
# unique global names.
EXTERN_G_RE = re.compile(
    r'^\s*extern\s+[^;]*?\bg_([A-Za-z_][A-Za-z0-9_]*)',
    re.MULTILINE,
)
# `g_*` use sites in source, even if no extern declaration exists yet.
G_REF_RE = re.compile(r'\bg_([A-Za-z_][A-Za-z0-9_]*)')


def count_global_naming():
    """Return (named, total). Discovers `g_*` from extern decls in include/
    and use sites in src/. 'named' = carries semantic content beyond a
    `<generic_prefix>_<addr>` placeholder (see is_semantically_named)."""
    seen = set()
    for h in INCLUDE_DIR.rglob("*.h"):
        try:
            text = h.read_text()
        except (OSError, UnicodeDecodeError):
            continue
        for m in EXTERN_G_RE.finditer(text):
            seen.add("g_" + m.group(1))
    if SRC_DIR.exists():
        for c in SRC_DIR.rglob("*.c"):
            try:
                text = c.read_text()
            except (OSError, UnicodeDecodeError):
                continue
            for m in G_REF_RE.finditer(text):
                seen.add("g_" + m.group(1))
    total = len(seen)
    named = sum(1 for n in seen if is_semantically_named(n))
    return (named, total)


# Struct field grammar: lines inside `typedef struct NAME { ... } NAME;`.
# We extract simple field declarations of the form
#     TYPE name;
#     TYPE name[N];        (counted as N slots)
# Function pointers, nested struct unions, and bitfields are skipped (rare in
# this corpus). Field names starting with `_` are unnamed placeholders.
STRUCT_BLOCK_RE = re.compile(
    r'typedef\s+struct\s+(\w+)\s*\{([^{}]*(?:\{[^}]*\}[^{}]*)*)\}\s*\1\s*;',
    re.DOTALL,
)
FIELD_LINE_RE = re.compile(
    r'^\s*(?:struct\s+\w+\s+|\w[\w\s\*]*?)'
    r'\b([A-Za-z_]\w*)'
    r'\s*(?:\[\s*(0x[0-9a-fA-F]+|\d+)\s*\])?'
    r'\s*;',
    re.MULTILINE,
)


def count_struct_field_coverage():
    """Return (named, total) slot counts across every `typedef struct` in
    include/. Array fields contribute their declared length (so `u32 _48[3]`
    counts as 3 unnamed slots; `u32 _88[19]` as 19). Field names starting
    with `_` are placeholders."""
    named = 0
    total = 0
    if not INCLUDE_DIR.exists():
        return (0, 0)
    for h in INCLUDE_DIR.rglob("*.h"):
        try:
            text = h.read_text()
        except (OSError, UnicodeDecodeError):
            continue
        # Strip C comments so they don't poison the field regex.
        text_nc = re.sub(r'/\*.*?\*/', '', text, flags=re.DOTALL)
        text_nc = re.sub(r'//[^\n]*', '', text_nc)
        for blk in STRUCT_BLOCK_RE.finditer(text_nc):
            body = blk.group(2)
            for fld in FIELD_LINE_RE.finditer(body):
                fname = fld.group(1)
                arr_n = fld.group(2)
                slots = int(arr_n, 0) if arr_n else 1
                total += slots
                if not fname.startswith('_'):
                    named += slots
    return (named, total)


# ----------------------------------------------------------------------------
# SVG rendering
# ----------------------------------------------------------------------------

def render_svg(rows, composite_pct, out_path):
    """Multi-bar SVG: composite bar at top, then one mini-bar per metric.

    `rows` is a list of (label, percent, note) tuples drawn below the composite.
    `note` is shown in parentheses next to the percent (e.g. "ceiling reached").
    """
    width = 720
    composite_h = 36
    row_h = 28
    pad_top = 14
    pad_bottom = 14
    height = pad_top + composite_h + 14 + row_h * len(rows) + pad_bottom

    composite_pct = max(0.0, min(100.0, composite_pct))
    composite_fill_w = (width - 24) * composite_pct / 100.0

    bars_x = 200
    bars_w = width - bars_x - 20

    bar_rects = []
    for i, (label, pct, note) in enumerate(rows):
        pct_clamped = max(0.0, min(100.0, pct))
        y = pad_top + composite_h + 14 + i * row_h
        fill = bars_w * pct_clamped / 100.0
        note_txt = f' ({note})' if note else ''
        bar_rects.append(f'''
  <text x="14" y="{y + 16}" font-family="'DejaVu Sans', Verdana, sans-serif"
        font-size="13" fill="#fde68a">{label}</text>
  <rect x="{bars_x}" y="{y + 5}" width="{bars_w}" height="16" rx="3" ry="3"
        fill="#1a1a1a" stroke="#3a2a14" stroke-width="1"/>
  <rect x="{bars_x}" y="{y + 5}" width="{fill:.2f}" height="16" rx="3" ry="3"
        fill="url(#rowGrad)"/>
  <text x="{bars_x + bars_w - 6}" y="{y + 17}" font-family="'DejaVu Sans Mono', monospace"
        font-size="12" fill="#fff8e1" text-anchor="end" font-weight="bold">{pct_clamped:.1f}%{note_txt}</text>''')

    svg = f'''<svg xmlns="http://www.w3.org/2000/svg" width="{width}" height="{height}" viewBox="0 0 {width} {height}" role="img" aria-label="MK4 decomp progress {composite_pct:.1f}%">
  <title>MK4 decomp progress: {composite_pct:.1f}% functional understanding (composite)</title>
  <defs>
    <linearGradient id="fillGrad" x1="0" y1="0" x2="0" y2="1">
      <stop offset="0%"   stop-color="#ffd24a"/>
      <stop offset="45%"  stop-color="#f59e0b"/>
      <stop offset="80%"  stop-color="#b91c1c"/>
      <stop offset="100%" stop-color="#7f1d1d"/>
    </linearGradient>
    <linearGradient id="rowGrad" x1="0" y1="0" x2="0" y2="1">
      <stop offset="0%"   stop-color="#ffd24a"/>
      <stop offset="100%" stop-color="#b91c1c"/>
    </linearGradient>
    <linearGradient id="borderGrad" x1="0" y1="0" x2="0" y2="1">
      <stop offset="0%" stop-color="#fde68a"/>
      <stop offset="100%" stop-color="#92400e"/>
    </linearGradient>
  </defs>

  <!-- Outer card -->
  <rect x="1" y="1" width="{width - 2}" height="{height - 2}" rx="8" ry="8"
        fill="#0a0a0a" stroke="url(#borderGrad)" stroke-width="2"/>

  <!-- Composite track -->
  <rect x="12" y="{pad_top}" width="{width - 24}" height="{composite_h}" rx="6" ry="6"
        fill="#1a1a1a" stroke="#3a2a14" stroke-width="1"/>

  <!-- Composite filled portion -->
  <rect x="12" y="{pad_top}" width="{composite_fill_w:.2f}" height="{composite_h}" rx="6" ry="6"
        fill="url(#fillGrad)"/>

  <!-- Top highlight on composite -->
  <rect x="12" y="{pad_top}" width="{composite_fill_w:.2f}" height="8" rx="6" ry="6"
        fill="#ffffff" opacity="0.18"/>

  <!-- Composite label + percent (single line) -->
  <text x="{width / 2}" y="{pad_top + composite_h / 2 + 6}"
        font-family="Impact, 'Arial Black', sans-serif" font-size="18" font-weight="900"
        text-anchor="middle" fill="#fff8e1"
        stroke="#1a0a0a" stroke-width="1.2" paint-order="stroke fill"
        letter-spacing="1.5">FUNCTIONAL UNDERSTANDING - {composite_pct:.1f}%</text>
{''.join(bar_rects)}
</svg>
'''
    out_path.write_text(svg)


# ----------------------------------------------------------------------------
# Main
# ----------------------------------------------------------------------------

def main():
    syms = load_symbols()

    total = len(syms)
    if total == 0:
        print("No symbols loaded - run from project root.")
        sys.exit(1)

    matched = sum(1 for s in syms if s.get("status") == "matched")

    file_cache = {}
    counts = {'pure_c': 0, 'hybrid': 0, 'naked': 0, 'absent': 0}
    per_sym = {}
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

    fn_named,  fn_total  = count_function_naming(syms)
    gv_named,  gv_total  = count_global_naming()
    st_named,  st_total  = count_struct_field_coverage()

    # Symbol naming: function + global naming merged into one axis (they move
    # together and are both at their ceiling, so one combined bar is clearer
    # than two near-identical ones).
    nm_named = fn_named + gv_named
    nm_total = fn_total + gv_total
    nm_pct = pct(nm_named, nm_total)
    st_pct = pct(st_named, st_total)

    # Portable C: functions with NO x86 __asm in the path a port compiles -
    # pure-C bodies plus naked/hybrid functions that now carry a portable
    # `#ifdef NON_MATCHING` twin. This is the axis the asm->C / twin work
    # actually moves (the bare "pure C" number below excludes twins and is
    # capped ~49% by MSVC codegen, so it never reflected that work).
    twins = collect_twins()
    portable = sum(1 for s in syms
                   if per_sym.get(s.get("name")) == 'pure_c'
                   or s.get("name") in twins)
    portable_pct = pct(portable, total)

    # Composite now reflects CURRENT contribution velocity across the three
    # moving axes: symbol naming, struct-field coverage, and portable-C.
    # (Byte-match excluded - always 100%; bare pure-C excluded - asymptotic.)
    composite = (nm_pct + st_pct + portable_pct) / 3.0

    print("MK4 matching decomp - progress")
    print("=" * 72)
    print()
    print(f"  Functional understanding (composite)  {composite:>6.1f}%")
    print(f"    = mean of symbol-naming, struct-field coverage, portable-C")
    print()
    print(f"  Byte-perfect rebuild                  {pct(matched, total):>6.1f}%   "
          f"({matched} / {total} functions)")
    print(f"  Portable C (pure C + twins)           {portable_pct:>6.1f}%   "
          f"({portable} / {total} functions; {len(twins)} twins)")
    print(f"  Pure C  (no __asm; ceiling ~49%)      {pct(pure_c, total):>6.1f}%   "
          f"({pure_c} / {total} functions)")
    print(f"  Hybrid  (no naked, body still __asm)  {pct(hybrid, total):>6.1f}%   "
          f"({hybrid} / {total} functions)")
    print(f"  Still __declspec(naked)               {pct(naked,  total):>6.1f}%   "
          f"({naked} / {total} functions)")
    print()
    print(f"  Symbol naming    (semantically named) {nm_pct:>6.1f}%   "
          f"({nm_named} / {nm_total} fns+globals)")
    print(f"  Struct field coverage (named slots)   {st_pct:>6.1f}%   "
          f"({st_named} / {st_total} slots in include/)")
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

    if "--no-svg" not in sys.argv:
        rows = [
            ("Byte-perfect rebuild",  pct(matched, total), None),
            ("Portable C (+twins)",   portable_pct,        f"{len(twins)} twins"),
            ("Symbol naming",         nm_pct,              None),
            ("Struct field coverage", st_pct,              None),
        ]
        render_svg(rows, composite, SVG_FILE)
        print(f"  Wrote {SVG_FILE.relative_to(ROOT)} "
              f"({composite:.1f}% composite)")


if __name__ == "__main__":
    main()
