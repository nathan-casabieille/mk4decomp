#!/usr/bin/env python3
"""Auto-try C-source variants on a manually-written conversion that's
currently failing the per-OBJ diff.

Given a source file and a function name (already partially converted —
i.e., not __declspec(naked) anymore), this script applies a series of
small textual mutations to the function body and runs fast_try.py for
each, reporting which variation reduces or zeros the diff count.

Mutations tried (in order):
    base       -- the unmodified current source
    int_ret    -- change `void Name(` to `int Name(` AND replace each
                  `return;` (and trailing `}` with no return) with
                  `return g_framePauseFlag;`
    uint_arg   -- change every `int X` in the signature to `unsigned int X`
    swap_pair  -- for each pair of consecutive top-level global-store
                  statements, try swapping their order
    invert_if  -- for each `if (cond)` with both branches present, try
                  rewriting as `if (!cond)` with branches swapped
    tail_cast  -- replace the LAST call before `}` with
                  `return ((int(*)())F)();` (requires int_ret)

For each mutation, the script:
    1. Backs up the source file
    2. Applies the mutation
    3. Runs fast_try.py
    4. Reports diff count
    5. Restores the source
After all mutations, prints a ranked report. The BEST variant (lowest
diff count) is left applied so you can iterate; pass --keep-base to
restore.

Usage:
    python3 tools/decomp/try_variants.py <src_file> <func_name>
    python3 tools/decomp/try_variants.py <src_file> <func_name> --mutations int_ret,uint_arg
    python3 tools/decomp/try_variants.py <src_file> <func_name> --keep-base
"""
import argparse
import re
import shutil
import subprocess
import sys
import time
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent.parent


def extract_function(src, func_name):
    """Return (before, fn_text, after) where fn_text is the full
    `<ret> Name(...)\n{ ... }\n` block for the named function.

    Handles both `__declspec(naked) ret Name(...) { __asm { ... } }`
    and plain `ret Name(...) { ... }`.
    """
    # Try naked first
    pat = re.compile(
        r'(__declspec\s*\(\s*naked\s*\)\s+\w+(?:\s*\*)?\s+'
        + re.escape(func_name)
        + r'\s*\([^)]*\)\s*\{[\s\S]*?\n\}\n)',
        re.MULTILINE,
    )
    m = pat.search(src)
    if m:
        return src[:m.start()], m.group(1), src[m.end():]

    # Plain function — find `[type] NAME(args) {` and matching `}`.
    pat = re.compile(
        r'((?:^|\n)[a-zA-Z_]\w*(?:\s*\*)?\s+' + re.escape(func_name) + r'\s*\([^)]*\)\s*\{)',
        re.MULTILINE,
    )
    m = pat.search(src)
    if not m:
        return None, None, None
    open_brace = m.end() - 1
    depth = 1
    i = open_brace + 1
    while i < len(src) and depth > 0:
        c = src[i]
        if c == '{':
            depth += 1
        elif c == '}':
            depth -= 1
            if depth == 0:
                # consume trailing newline
                end = i + 1
                if end < len(src) and src[end] == '\n':
                    end += 1
                return src[:m.start()], src[m.start():end], src[end:]
        i += 1
    return None, None, None


# --- Mutations ------------------------------------------------------

def mut_int_ret(fn_text):
    """Change `void Name(` -> `int Name(` and replace trailing fall-through
    `}` with `return g_framePauseFlag; }`. Also convert each bare `return;`
    statement to `return g_framePauseFlag;`."""
    # Replace return type (first `void` followed by name pattern)
    new = re.sub(
        r'((?:^|\n)(?:\s*extern\s+)?)void(\s+\w+\s*\([^)]*\)\s*\{)',
        r'\1int \2',
        fn_text, count=1,
    )
    if new == fn_text:
        # Maybe already int? Just continue.
        new = fn_text
    # Replace bare `return;` -> `return g_framePauseFlag;`
    new = re.sub(r'\breturn\s*;', 'return g_framePauseFlag;', new)
    # If the function ends with `\n}\n` (no explicit return), add one
    if not re.search(r'return[^\n;]*;\s*\n\}\n?$', new):
        new = re.sub(r'\n\}\n?$', '\n    return g_framePauseFlag;\n}\n', new)
    return new


def mut_uint_arg(fn_text):
    """Replace each `int ARG` with `unsigned int ARG` in the signature."""
    def patch(match):
        sig = match.group(0)
        # Replace `int <ident>` (whole-word) but skip if already unsigned int
        sig = re.sub(r'(?<!unsigned\s)\bint\s+(\w+)', r'unsigned int \1', sig)
        return sig
    return re.sub(r'\w+\s+\w+\s*\([^)]*\)', patch, fn_text, count=1)


def mut_tail_cast(fn_text):
    """Replace the LAST `F();` statement before `}` with `return ((int(*)())F)();`.
    Requires int_ret to have been applied first (signature is int)."""
    # Find the last line that looks like `NAME(args);` before the closing brace.
    lines = fn_text.rstrip().split('\n')
    if lines and lines[-1].strip() == '}':
        body = lines[:-1]
        for i in range(len(body) - 1, -1, -1):
            line = body[i].rstrip()
            m = re.match(r'^(\s*)(\w+)\(([^;]*)\)\s*;\s*$', line)
            if not m or m.group(2) in ('return', 'if', 'while', 'for', 'do'):
                continue
            indent, fname, args = m.groups()
            body[i] = f'{indent}return ((int (*)({args.strip() or "void"}))){fname}({args});'
            return '\n'.join(body + [lines[-1]]) + '\n'
    return fn_text


def mut_invert_first_if(fn_text):
    """For the FIRST `if (X) { ... } else { ... }` (or `if/early-return`),
    invert the condition and swap branches. Trivial cases only."""
    # Match `if (cond) { A; } else { B; }` or `if (cond) { A; }`.
    # Simple form: `if (X == Y) { ... return; } [...]`.
    # We only handle the simplest case.
    pat = re.compile(
        r'(if\s*\()([^()]+?)(\)\s*\{)',  # if (cond) {
    )
    m = pat.search(fn_text)
    if not m:
        return fn_text
    cond = m.group(2).strip()
    # Try to invert the condition
    if cond.startswith('!'):
        new_cond = cond[1:].strip()
        if new_cond.startswith('(') and new_cond.endswith(')'):
            new_cond = new_cond[1:-1].strip()
    elif '==' in cond:
        new_cond = cond.replace('==', '!=', 1)
    elif '!=' in cond:
        new_cond = cond.replace('!=', '==', 1)
    elif '<=' in cond:
        new_cond = cond.replace('<=', '>', 1)
    elif '>=' in cond:
        new_cond = cond.replace('>=', '<', 1)
    elif '<' in cond:
        new_cond = cond.replace('<', '>=', 1)
    elif '>' in cond:
        new_cond = cond.replace('>', '<=', 1)
    else:
        new_cond = '!(' + cond + ')'
    return fn_text[:m.start(2)] + new_cond + fn_text[m.end(2):]


def mut_swap_pair_statements(fn_text):
    """Swap the FIRST pair of consecutive global-store statements that
    look like simple assignments (no side effects).

    Heuristic: lines of form `<global_or_*ptr> = <expr>;` at the same
    indentation level."""
    lines = fn_text.split('\n')
    pat = re.compile(r'^(\s+)([\w*]+[^=]*=[^=][^;]*);\s*$')
    for i in range(len(lines) - 1):
        m1 = pat.match(lines[i])
        m2 = pat.match(lines[i + 1])
        if m1 and m2 and m1.group(1) == m2.group(1):
            lines[i], lines[i + 1] = lines[i + 1], lines[i]
            return '\n'.join(lines)
    return fn_text


MUTATIONS = {
    'int_ret': mut_int_ret,
    'uint_arg': mut_uint_arg,
    'tail_cast': mut_tail_cast,
    'invert_if': mut_invert_first_if,
    'swap_pair': mut_swap_pair_statements,
}

COMBOS = [
    ('base', []),
    ('int_ret', ['int_ret']),
    ('uint_arg', ['uint_arg']),
    ('int_ret+tail_cast', ['int_ret', 'tail_cast']),
    ('invert_if', ['invert_if']),
    ('swap_pair', ['swap_pair']),
    ('int_ret+invert_if', ['int_ret', 'invert_if']),
    ('int_ret+invert_if+tail_cast', ['int_ret', 'invert_if', 'tail_cast']),
    ('uint_arg+int_ret', ['uint_arg', 'int_ret']),
]


def apply_mutations(fn_text, names):
    for n in names:
        fn_text = MUTATIONS[n](fn_text)
    return fn_text


def run_fast_try(src_path, func_name):
    fast = ROOT / 'tools' / 'decomp' / 'fast_try.py'
    res = subprocess.run(
        ['python3', str(fast), str(src_path), func_name],
        capture_output=True, text=True, timeout=180,
    )
    out = res.stdout + res.stderr
    # Parse `diffs=N` or `MATCH` marker
    if 'MATCH (per-OBJ diff)' in out:
        return 0, out
    for line in out.split('\n'):
        m = re.search(r'diffs=(\d+)', line)
        if m:
            return int(m.group(1)), out
        if 'exceed section size' in line:
            return -1, out  # size mismatch (very bad)
        if 'BUILD FAIL' in line:
            return -2, out
    return -3, out


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('src')
    ap.add_argument('func')
    ap.add_argument('--mutations', help='Comma-separated combos to run (default: all)')
    ap.add_argument('--keep-base', action='store_true', help='Always restore the original source')
    args = ap.parse_args()

    src_path = Path(args.src).resolve()
    if not src_path.exists():
        print(f'ERROR: {src_path} not found', file=sys.stderr)
        sys.exit(2)

    original = src_path.read_text()
    before, fn_text, after = extract_function(original, args.func)
    if fn_text is None:
        print(f'ERROR: function {args.func} not found in {src_path}', file=sys.stderr)
        sys.exit(2)

    if fn_text.lstrip().startswith('__declspec'):
        print('WARNING: function is still __declspec(naked). try_variants needs a partially-converted (pure-C) function to mutate.', file=sys.stderr)
        sys.exit(2)

    combos = COMBOS
    if args.mutations:
        wanted = set(args.mutations.split(','))
        combos = [(n, m) for n, m in combos if n in wanted]
        # Also allow specifying a single ad-hoc mutation
        for w in wanted:
            if w not in {n for n, _ in COMBOS} and w in MUTATIONS:
                combos.append((w, [w]))

    results = []
    best = None
    print(f'try_variants: {args.func} in {src_path.relative_to(ROOT)}')
    print(f'baseline + {len(combos)-1} variants\n')

    for name, mutations in combos:
        t0 = time.time()
        if mutations:
            new_fn = apply_mutations(fn_text, mutations)
        else:
            new_fn = fn_text
        if new_fn == fn_text and mutations:
            print(f'  {name:<32}  (no-op, skipped)')
            continue
        # Apply
        src_path.write_text(before + new_fn + after)
        diffs, out = run_fast_try(src_path, args.func)
        dt = time.time() - t0
        results.append((diffs, name, mutations, new_fn))
        marker = 'MATCH' if diffs == 0 else (f'{diffs} diffs' if diffs > 0 else f'err({diffs})')
        print(f'  {name:<32}  {marker:<15}  ({dt:.1f}s)')
        if diffs == 0:
            best = (diffs, name, mutations, new_fn)
            break

    if best is None:
        # Pick lowest diff count
        valid = [r for r in results if r[0] >= 0]
        if valid:
            best = min(valid, key=lambda r: r[0])
        else:
            best = (results[0] if results else (None, 'base', [], fn_text))

    print()
    if best[0] == 0:
        print(f'BEST: {best[1]} -> MATCH. Source left applied; run try_conv.py to confirm.')
    elif best[0] > 0:
        print(f'BEST: {best[1]} -> {best[0]} diffs. Source left applied for inspection.')
    else:
        print('No working variant found.')

    if args.keep_base:
        src_path.write_text(original)
        print('Restored original source.')
    else:
        src_path.write_text(before + best[3] + after)


if __name__ == '__main__':
    main()
