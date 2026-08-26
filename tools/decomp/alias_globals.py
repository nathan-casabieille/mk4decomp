#!/usr/bin/env python3
"""Give a converted file's globals ARENA ALIASES for the relocated targets.

native-full defines every fixed-VA global as a separate weak C variable, but
the engine relies on their ADJACENCY: FlushDrawQueue walks the draw queue as
`&g_dispatchSave1398 + i*0x1c`, the projection reads nine packed s16 from
`&g_mat3x3_007af990`, the triangle twins index `(&g_dispatchSave1378)[i]`.
Separate variables make all of that compute garbage - silently.

The fix is the memory model mem_model.h flags as the open decision: under
MK4_ARENA a fixed-VA global is an ALIAS at its true VA inside the arena, not a
C variable. That is exactly what the wasm/native demo generator does, which is
why those demos render correctly, so a file rewritten this way behaves the same
natively as the bundle that was co-exec verified.

Per file this tool:
  1. wraps the file's own `extern ... g_*;` lines in `#ifndef MK4_ARENA`
  2. appends an `#ifdef MK4_ARENA` block of `#define g_x (*(T *)MK4_VA(...))`
     aliases, typed the same usage-aware way verify_coexec's gdef types them

The matching build never defines MK4_ARENA, so it keeps the externs and sees no
aliases at all - `make matching` stays byte-identical.

  build/venv/bin/python tools/decomp/alias_globals.py FILE FN [FN ...]
"""
import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import verify_twin as vt
import verify_coexec as vc

BEGIN = '/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */'


def gdef(g, va, text):
    """Usage-aware alias - mirrors verify_coexec.gdef / gen_wasm_render.gdef_arena."""
    if re.search(r'\(\s*\*\s*%s\s*\)\s*\(' % g, text) or re.search(r'\b%s\s*\(' % g, text):
        return '#define %s (*(unsigned int (**)())MK4_VA(unsigned int, 0x%xu))' % (g, va)
    if re.search(r'\b%s\s*\[' % g, text):
        return '#define %s ((unsigned int *)MK4_VA(unsigned int, 0x%xu))' % (g, va)
    deref = False
    for m in re.finditer(r'\*\s*%s\b' % g, text):
        j = m.start() - 1
        while j >= 0 and text[j] in ' \t':
            j -= 1
        if j < 0 or (text[j] not in '_)]' and not text[j].isalnum()):
            deref = True
    if deref:
        return '#define %s (*(unsigned int **)MK4_VA(unsigned int, 0x%xu))' % (g, va)
    return '#define %s (*(unsigned int *)MK4_VA(unsigned int, 0x%xu))' % (g, va)


def main():
    if len(sys.argv) < 3:
        print(__doc__)
        return 2
    path = Path(sys.argv[1])
    names = sys.argv[2:]
    fn_va, gl_va = vt.load_maps()
    src = path.read_text()
    if BEGIN in src:
        print('%s: already aliased' % path)
        return 0

    # a file may hold a NON_MATCHING twin or already-unconditional pure C
    import importlib.util
    spec = importlib.util.spec_from_file_location(
        'gen', str(Path(__file__).resolve().parent / 'gen_wasm_render.py'))
    gen = importlib.util.module_from_spec(spec); spec.loader.exec_module(gen)
    text = ''
    for n in names:
        t = vc.extract_twin_any(n)
        if t:
            text += '\n' + t[0]
        else:
            pure = gen.extract_pure_c(n)
            if pure:
                text += '\n' + pure
    if not text:
        print('%s: no twin bodies for %s' % (path, names))
        return 1
    globs = [g for g in sorted(set(re.findall(r'\bg_\w+', text))) if g in gl_va]

    # 1. guard the file's own extern declarations - ONLY the variable ones.
    #    Guarding everything between the first and last `extern` swallows the
    #    function declarations sitting between them (74 of them in one file),
    #    which then vanish under MK4_ARENA. Guard each contiguous RUN of
    #    variable externs instead, and only for globals we actually alias.
    lines = src.split('\n')
    alias_set = set(globs)
    is_var = []
    for l in lines:
        m = re.match(r'^extern [^;()]*\b(g_\w+)\s*(\[[^\]]*\])?\s*;', l)
        is_var.append(bool(m) and m.group(1) in alias_set)
    # A file may declare none of its globals itself (they come from headers).
    # The aliases still apply: the header's declaration is already parsed, and
    # the macro governs every use below it.
    out_lines, i, n_guard = [], 0, 0
    while i < len(lines):
        if is_var[i]:
            j = i
            while j < len(lines) and is_var[j]:
                j += 1
            out_lines.append('#ifndef MK4_ARENA   /* aliased below for the relocated targets */')
            out_lines.extend(lines[i:j])
            out_lines.append('#endif')
            n_guard += j - i
            i = j
        else:
            out_lines.append(lines[i])
            i += 1
    lines = out_lines
    last = len(lines) - 1
    first = 0
    guarded = []

    # 2. the alias block
    alias = ['', BEGIN,
             '#ifdef MK4_ARENA',
             '#include "portable/mem_model.h"']
    for g in globs:
        alias.append(gdef(g, gl_va[g], text))
    alias += ['#endif', '']

    # 2. place the alias block after the last guarded run, or after the last
    #    #include when the file declares none of its globals itself
    cand = [k for k, l in enumerate(lines) if l == '#endif' and
            k and lines[k - 1].startswith('extern')]
    if cand:
        ins = max(cand) + 1
    else:
        ins = max(k for k, l in enumerate(lines) if l.startswith('#include')) + 1
    out = lines[:ins] + alias + lines[ins:]
    path.write_text('\n'.join(out))
    print('%s: %d variable externs guarded, %d aliases' % (path, n_guard, len(globs)))
    return 0


if __name__ == '__main__':
    sys.exit(main())
