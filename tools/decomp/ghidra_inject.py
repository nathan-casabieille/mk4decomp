#!/usr/bin/env python3
"""Inject clean Ghidra-decompiled twins into source as NON_MATCHING bodies.

Stage 3 of the Ghidra pipeline. For each decompiled function in <decompdir>
that is SAFE to drop in (signature exactly `void NAME(void)` and the
post-processed C is fully compilable - no `code` fn-ptrs, no CONCAT/SUBxx
intrinsics, no unmapped FUN_/DAT_), wrap the matching naked body:

    #include "portable/ghidra_types.h"   (added once per file)
    ...
    #ifdef NON_MATCHING
    /* Ghidra-decompiled twin - behavior not yet runtime-verified */
    void NAME(void) { <lifted C> }
    #else
    __declspec(naked) void NAME(void) { __asm { ... } }   (frozen)
    #endif

SAFETY: matching is untouched (the #else is preserved), so this can never
break the oracle. Portable behavior rests on Ghidra + review; every batch
must still pass `make matching` (MD5-identical) and `make portable-check`.

Usage:
  python3 tools/decomp/ghidra_inject.py <decompdir> <map.json> [--apply]
"""
import json
import re
import subprocess
import tempfile
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import ghidra_postprocess as gp

ROOT = Path(__file__).resolve().parents[2]
# Word-boundary tokens that mean the twin can't compile cleanly / portably:
# Ghidra sub-register intrinsics, register-input artifacts, code fn-ptrs,
# odd-width undefineds, and C99 bool/true/false (not assumed available).
BAIL_TOKENS = ('code', 'CONCAT', 'SUB4', 'SUB8', 'SUB2', 'ZEXT', 'SEXT',
               'in_EAX', 'in_ECX', 'unaff_', 'extraout_', 'halt_baddata',
               'undefined3', 'undefined5', 'undefined6', 'undefined7')
# Leftover Ghidra placeholders (unmapped global/func, code label, jump
# table, or a PTR_<sym> indirect thunk) -> bail, keep the function naked.
UNMAPPED = re.compile(
    r'\b(FUN|DAT|LAB|UNK|switchD|JUMP)_?[0-9a-fA-F]{4,}\b|\bPTR_\w+'
    r'|\bUNRESOLVED_[0-9a-fA-F]{8}\b')


def has_bail(c):
    if UNMAPPED.search(c):
        return True
    return any(re.search(r'\b%s' % re.escape(t), c) for t in BAIL_TOKENS)


CC = 'i686-w64-mingw32-gcc'


def compile_ok(twin, name):
    """Isolation syntax-check: a clean twin must compile with permissive
    externs for the globals/functions it references. Guards against shapes
    the token bail misses (floats, local arrays, strings, ...)."""
    globs = sorted(set(re.findall(r'\bg_[A-Za-z]\w*', twin)))
    calls = [f for f in sorted(set(re.findall(r'\b([A-Z]\w+)\s*\(', twin)) - {name})
             if not f.startswith('MK4_')]
    h = ('#define NON_MATCHING 1\n#include "portable/ghidra_types.h"\n'
         '#include "portable/mem_model.h"\n')
    h += ''.join('extern unsigned int %s;\n' % g for g in globs)
    h += ''.join('extern int %s();\n' % f for f in calls)
    h += twin + '\n'
    with tempfile.NamedTemporaryFile('w', suffix='.c', delete=False) as t:
        t.write(h)
        tn = t.name
    r = subprocess.run([CC, '-std=gnu89', '-DNON_MATCHING',
                        '-I' + str(ROOT / 'include'), '-w', '-fsyntax-only', tn],
                       capture_output=True, text=True)
    return r.returncode == 0


def fn_body_span(src, brace_idx):
    depth, i = 1, brace_idx
    while i < len(src) and depth:
        if src[i] == '{':
            depth += 1
        elif src[i] == '}':
            depth -= 1
        i += 1
    return i - 1


def main():
    decompdir = Path(sys.argv[1])
    vamap = json.loads(Path(sys.argv[2]).read_text())   # "<hex8>": [name, file]
    apply = '--apply' in sys.argv
    fn_by_va, gl_by_va = gp.load_maps()

    injected = skipped = 0
    by_file = {}
    for va_hex, (name, srcfile) in vamap.items():
        dpath = decompdir / (va_hex + '.c')
        if not dpath.exists():
            continue
        c = gp.postprocess(dpath.read_text(), fn_by_va, gl_by_va)
        # strip the "/* ghidra name */" comment line
        c = re.sub(r'^/\* ghidra name:.*\*/\n', '', c)
        # Accept any return type / signature (Ghidra recovers args for
        # arg-taking functions); capture the function name. The #else keeps
        # our void(void) naked decl, so matching is unaffected; cross-file
        # signature consistency is a Phase-B follow-up (callers reconcile as
        # they convert). The compile gate still vets each twin.
        m = re.match(r'\s*[A-Za-z_][\w ]*?\b(\w+)\s*\(', c)
        if not m or m.group(1) != name:
            skipped += 1
            continue
        if has_bail(c):
            skipped += 1
            continue
        if not compile_ok(c.strip(), name):
            skipped += 1
            continue
        by_file.setdefault(srcfile, []).append((name, c.strip()))

    for srcfile, fns in by_file.items():
        path = ROOT / srcfile
        src = path.read_text()
        changed = False
        for name, twin in fns:
            decl = re.search(
                r'(?P<indent>[ \t]*)__declspec\(\s*naked\s*\)\s+void\s+'
                + re.escape(name) + r'\s*\(\s*void\s*\)\s*\{', src)
            if not decl:
                skipped += 1
                continue
            if src[:decl.start()].rstrip().endswith('#else'):
                continue                       # already wrapped
            end = fn_body_span(src, decl.end())
            naked = src[decl.start():end + 1]
            indent = decl.group('indent')
            wrapped = (indent + '#ifdef NON_MATCHING\n'
                       + '/* Ghidra-decompiled twin - behavior not yet runtime-verified */\n'
                       + twin + '\n#else\n' + naked.lstrip() + '\n#endif')
            src = src[:decl.start()] + wrapped + src[end + 1:]
            injected += 1
            changed = True
        if changed and 'portable/ghidra_types.h' not in src:
            src = re.sub(r'(#include "[^"]+"\n)',
                         r'\1#include "portable/ghidra_types.h"\n', src, count=1)
        if apply and changed:
            path.write_text(src)

    print('%s: injected %d, skipped %d'
          % ('APPLIED' if apply else 'DRY-RUN', injected, skipped))


if __name__ == '__main__':
    main()
