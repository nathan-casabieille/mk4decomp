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

  build/venv/bin/python tools/decomp/alias_globals.py FILE [FN ...]
    with no FN, every function the file defines is used
"""
import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import verify_twin as vt
import verify_coexec as vc

BEGIN = '/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */'


# The declared type MATTERS. Defaulting every alias to `unsigned int` turns a
# 16-bit store into a 32-bit one that clobbers the neighbouring global - and in
# this engine the neighbours are real data (g_triStripX0/1/2 sit 6 bytes apart,
# the 3x3 matrix entries 2 bytes apart). AdvanceTriStripRing assigns
# g_triStripX0 directly, so it has to be a `short` alias.
CTYPE = {
    's16': 'short', 'short': 'short', 'u16': 'unsigned short',
    'unsigned short': 'unsigned short',
    's8': 'signed char', 'u8': 'unsigned char', 'char': 'char',
    'unsigned char': 'unsigned char', 'byte': 'unsigned char',
    's32': 'int', 'int': 'int', 'u32': 'unsigned int',
    'unsigned int': 'unsigned int', 'undefined4': 'unsigned int',
    'undefined2': 'unsigned short', 'float': 'float', 'double': 'double',
}


# Globals whose DECLARED type in the sources is wrong. The auto-generated
# externs call the packed s16 matrix / vertex-input words `unsigned int`, but
# the original reads them `movsx word` and they sit 2 or 6 bytes apart - a
# 32-bit alias is polluted by the neighbour and the geometry comes out as
# vertical smears. Same opt-in set the co-exec harness uses (verify_project's
# WIDTH16), which is why the verified bundle renders correctly.
WIDTH16 = {
    'g_mat3x3_007af990', 'g_mat3x3_007af992', 'g_mat3x3_007af994',
    'g_mat3x3_007af996', 'g_mat3x3_007af998', 'g_mat3x3_007af99a',
    'g_mat3x3_007af99c', 'g_mat3x3_007af99e', 'g_mat3x3_007af9a0',
    'g_vtxMat', 'g_wtMatExtraWord',
    'g_triStripX0', 'g_triStripX1', 'g_triStripX2',
    'g_dispatchSave1626', 'g_vtxIn1_y', 'g_vtxIn1_z',
    'g_vtxIn2_x', 'g_vtxIn2_y', 'g_vtxIn2_z',
}


# The mirror case: names that are declared s16 but are really the DWORD base of
# a packed (X:lo, Y:hi) screen pair. DrawMeshBlock stores them whole -
#     *(unsigned int *)(entry + 0) = g_vtxScreenP1X;
# - so a 16-bit alias silently drops every Y and the geometry collapses into
# vertical smears. The matching Y names (…P1Y, …P2Y, g_vtxScreenY) really are
# the 16-bit halves and stay narrow.
WIDTH32 = {'g_vtxScreenP1X', 'g_vtxScreenP2X', 'g_vtxScreenX'}


def _strip_decls(text):
    """Drop `extern ...;` lines and comments - what is left is real code."""
    text = re.sub(r'/\*.*?\*/', '', text, flags=re.S)
    return '\n'.join(l for l in text.split('\n')
                     if not l.lstrip().startswith('extern'))


def declared_type(g, src):
    """Base type from the file's own `extern <type> g;` line, if it has one."""
    if g in WIDTH16:
        return 'short'          # authoritative; the source declaration is wrong
    if g in WIDTH32:
        return 'unsigned int'   # packed X|Y pair, stored as one dword
    m = re.search(r'(?m)^extern\s+((?:unsigned\s+|signed\s+)?\w+)\s+\**%s\b' % re.escape(g), src)
    if not m:
        return None
    return CTYPE.get(m.group(1).strip())


def gdef(g, va, text, ctype=None):
    """Usage-aware alias - mirrors verify_coexec.gdef / gen_wasm_render.gdef_arena."""
    t = ctype or 'unsigned int'
    if re.search(r'\(\s*\*\s*%s\s*\)\s*\(' % g, text) or re.search(r'\b%s\s*\(' % g, text):
        return '#define %s (*(unsigned int (**)())MK4_VA(unsigned int, 0x%xu))' % (g, va)
    if re.search(r'\b%s\s*\[' % g, text):
        return '#define %s ((%s *)MK4_VA(%s, 0x%xu))' % (g, t, t, va)
    deref = False
    for m in re.finditer(r'\*\s*%s\b' % g, text):
        j = m.start() - 1
        while j >= 0 and text[j] in ' \t':
            j -= 1
        if j < 0 or (text[j] not in '_)]' and not text[j].isalnum()):
            deref = True
    if deref:
        return '#define %s (*(%s **)MK4_VA(%s, 0x%xu))' % (g, t, t, va)
    return '#define %s (*(%s *)MK4_VA(%s, 0x%xu))' % (g, t, t, va)


def main():
    if len(sys.argv) < 2:
        print(__doc__)
        return 2
    path = Path(sys.argv[1])
    names = sys.argv[2:]
    if not names:
        # Discover every function the file defines - both NON_MATCHING twins and
        # unconditional pure C - so a whole TU can be aliased without naming
        # each one. Aliasing must cover the WHOLE file: an aliased TU and a
        # non-aliased TU see DIFFERENT storage for the same global.
        src0 = path.read_text()
        names = sorted(set(
            re.findall(r'(?m)^[A-Za-z_][\w \*]*?\b(\w+)\s*\([^;{)]*\)\s*$', src0) +
            re.findall(r'(?m)^[A-Za-z_][\w \*]*?\b(\w+)\s*\([^;{)]*\)\s*\{', src0)))
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
        text = src          # fall back to the whole file for usage inference
    # Alias every global the twin touches AND every one the file declares
    # itself. Leaving a declared-but-unaliased extern behind is an undefined
    # symbol at link time: the variable no longer exists anywhere, because the
    # whole point is that these live in the arena now.
    declared = set(re.findall(r'(?m)^extern [^;()]*\b(g_\w+)\s*(?:\[[^\]]*\])?\s*;', src))
    globs = sorted({g for g in set(re.findall(r'\bg_\w+', text)) | declared if g in gl_va})

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
        alias.append(gdef(g, gl_va[g], text, declared_type(g, src)))
    alias += ['#endif', '']

    # 2. place the alias block after the last guarded run, or after the last
    #    #include when the file declares none of its globals itself
    cand = [k for k, l in enumerate(lines) if l == '#endif' and
            k and lines[k - 1].startswith('extern')]
    if cand:
        ins = max(cand) + 1
    else:
        # Only includes in the file's HEADER region count. A twin body often
        # pulls in mem_model.h itself, and that include sits BELOW every
        # function - anchoring the alias block to it would put the aliases
        # after all the code that needs them.
        stop = next((k for k, l in enumerate(lines)
                     if l.startswith('#ifdef NON_MATCHING')
                     or re.match(r'^[A-Za-z_][\w *]*\w\s*\(', l)), len(lines))
        head = [k for k, l in enumerate(lines[:stop]) if l.startswith('#include')]
        ins = (max(head) + 1) if head else stop
    out = lines[:ins] + alias + lines[ins:]
    path.write_text('\n'.join(out))
    print('%s: %d variable externs guarded, %d aliases' % (path, n_guard, len(globs)))

    # The block goes after the LAST guarded extern run, so a function written
    # ABOVE that point does not see the aliases. When the global has no other
    # declaration that is a compile error, but when a header also declares it
    # the file silently SPLITS: early uses hit the plain C variable, later ones
    # hit the arena. Both halves then read different storage for one global.
    # (Appending a twin whose own externs form a new trailing run is the usual
    # way this happens - move those externs up into the file's main run.)
    head = '\n'.join(out[:ins])
    early = sorted(g for g in globs
                   if re.search(r'\b%s\b' % re.escape(g), _strip_decls(head)))
    if early:
        print('  WARNING: used before the alias block, so NOT aliased there: %s'
              % ', '.join(early))
    return 0


if __name__ == '__main__':
    sys.exit(main())
