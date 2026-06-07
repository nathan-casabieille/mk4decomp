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
# `code` was here but is now typedef'd (unsigned char) in ghidra_types.h:
# code-pointer store/loads compile, while a genuine indirect call through a
# `code *` stays a compile error -> the compile gate bails on it for us.
# CONCAT<a><b> bit-concat intrinsics are defined as macros in
# ghidra_types.h (verified semantics); a too-wide variant with no integer
# result type stays undefined and the compile gate drops its function.
BAIL_TOKENS = ('SUB4', 'SUB8', 'SUB2', 'ZEXT', 'SEXT',
               'in_EAX', 'in_ECX', 'unaff_', 'extraout_', 'halt_baddata',
               'undefined3', 'undefined5', 'undefined6', 'undefined7')
# Leftover Ghidra placeholders (unmapped global/func, jump table, or a
# PTR_<sym> indirect thunk) -> bail, keep the function naked. LAB_ is NOT
# here: a LAB_<va> used as a `goto`/label is ordinary structured control
# flow and compiles fine; only LAB_ used as an *address value* (an FSM
# `node->resume = &label` continuation) must bail - see lab_as_value().
UNMAPPED = re.compile(
    r'\b(FUN|DAT|UNK|switchD|JUMP)_?[0-9a-fA-F]{4,}\b|\bPTR_\w+'
    r'|\bUNRESOLVED_[0-9a-fA-F]{8}\b')
LAB = re.compile(r'\bLAB_[0-9a-fA-F]{4,}\b')


def lab_as_value(c):
    """True if any LAB_<va> is used as an address value rather than as a
    plain goto label/target. `LAB_x:` (definition) and `goto LAB_x;`
    (target) are fine; anything else (`= LAB_x`, `(code *)LAB_x`, ...) is an
    FSM continuation address and must stay naked for the Phase-C cluster."""
    for m in LAB.finditer(c):
        if c[m.end():m.end() + 1] == ':':
            continue                            # label definition
        if re.search(r'goto\s*$', c[:m.start()]):
            continue                            # goto target
        return True
    return False


def has_bail(c):
    if UNMAPPED.search(c) or lab_as_value(c):
        return True
    return any(re.search(r'\b%s' % re.escape(t), c) for t in BAIL_TOKENS)


CC = 'i686-w64-mingw32-gcc'


_FN_NAMES = None


def _fn_names():
    """Set of all our function names (from the symbol maps), cached. Lets the
    gate extern functions used as *values* (function pointers, e.g.
    `g_dispatch = SomeFn;`), which the call-only `Name(` scan below misses."""
    global _FN_NAMES
    if _FN_NAMES is None:
        fn_by_va, _ = gp.load_maps()
        _FN_NAMES = set(fn_by_va.values())
    return _FN_NAMES


def compile_ok(twin, name):
    """Isolation syntax-check: a clean twin must compile with permissive
    externs for the globals/functions it references. Guards against shapes
    the token bail misses (floats, local arrays, strings, ...)."""
    globs = sorted(set(re.findall(r'\bg_[A-Za-z]\w*', twin)))
    # Don't emit a bogus `extern int F();` for things that are actually
    # macros from ghidra_types.h (CONCAT<a><b> bit-concat) - a function-style
    # extern of a 2-arg macro fails to preprocess ("requires 2 arguments").
    calls = set(re.findall(r'\b([A-Z]\w+)\s*\(', twin)) - {name}
    # Also extern any known function name used as a bare value (taken as a
    # function pointer): `g_x = SomeFn;`. Portable - a fn pointer is just a
    # table index under WASM/clang.
    calls |= ({t for t in re.findall(r'\b([A-Za-z_]\w*)\b', twin) if t in _fn_names()}
              - {name})
    calls = [f for f in sorted(calls)
             if not f.startswith('MK4_') and not re.match(r'CONCAT\d\d$', f)]
    # MK4_WIN32_SHIM activates win32_types.h's portable Win32 typedefs here
    # without pulling in the real <windows.h> (whose API prototypes would
    # clash with the permissive `extern int F();` externs below). The real
    # portable build instead uses <windows.h> via types.h (_WIN32 set), where
    # win32_types.h stays inert - so the gate and the build agree on types.
    h = ('#define NON_MATCHING 1\n#define MK4_WIN32_SHIM 1\n'
         '#include "portable/ghidra_types.h"\n'
         '#include "portable/mem_model.h"\n')
    # Type each global extern by how the body uses it, so the isolation
    # gate matches what the real headers would accept in-context: a global
    # dereferenced/indexed (`*g`, `g[i]`) needs array/pointer type, one
    # called through (`(*g)()`, `g()`) needs a function-pointer type.
    # Scalar `unsigned int` is the default. (A wrong guess only fails the
    # gate conservatively; matching is unaffected either way.)
    for g in globs:
        if re.search(r'\b%s\s*\[' % g, twin) or re.search(r'\*\s*%s\b' % g, twin):
            h += 'extern unsigned int %s[];\n' % g
        elif re.search(r'\(\s*\*\s*%s\s*\)\s*\(' % g, twin) or re.search(r'\b%s\s*\(' % g, twin):
            h += 'extern int (*%s)();\n' % g
        else:
            h += 'extern unsigned int %s;\n' % g
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
        # strip any leading Ghidra block comments (e.g. the "WARNING:
        # Globals starting with '_' overlap..." analysis notes) so the
        # signature regex below sees the function, not the comment.
        c = re.sub(r'\A\s*(?:/\*.*?\*/\s*)+', '', c, flags=re.DOTALL)
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
