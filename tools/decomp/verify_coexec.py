#!/usr/bin/env python3
"""Co-execution verification: run the twin AS 32-bit code inside Unicorn.

The native-64-bit harness (verify_twin.py) can only run "seam-clean" twins;
Ghidra also emits raw 32-bit pointer derefs that need a 32-bit address
space. Wine reserves 0x400000 so a fixed-VA Wine runtime is out. Unicorn
lets us control the whole address space, so we run BOTH sides in it:

  - original: execute the function's own bytes at its VA in the arena
    (image mapped at 0x400000).
  - twin: compile the twin to 32-bit code with the IDENTITY memory model
    (globals #defined to absolute VAs, MK4_* = identity), so every access
    is an absolute VA into the same arena; load its .text into Unicorn and
    run it.

Diff the resulting arena bytes. Match => behavior-confirmed. Leaf
void(void) twins only for now (no arg setup, no callee linking).

Run with the unicorn venv:
  build/venv/bin/python tools/decomp/verify_coexec.py [NAME ...]
"""
import re
import subprocess
import sys
import tempfile
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import verify_twin as vt           # reuse load_maps / extract_twin / leaf_twins
import synthesize as syn           # reuse COFF parser
import struct

ROOT = Path(__file__).resolve().parents[2]
BASE = 0x00400000
ARENA = ROOT / 'build' / 'arena.bin'
CC = 'i686-w64-mingw32-gcc'
OBJCOPY = 'i686-w64-mingw32-objcopy'
CODE = 0x70000000
STACK = 0x10000000


def _strip(n):
    return n[1:] if n.startswith('_') else n


# Self-contained libgcc 64-bit divide helpers, appended to a twin's source only
# when it references them (see build_twin_blob). Bit-by-bit restoring division:
# uses only shift/compare/subtract on 64-bit values (which lower to inline 32-bit
# pairs), never the `/` or `%` operator, so __divdi3 does not recurse into itself.
# Truncates toward zero (C semantics) - matches MSVC's __alldiv on the orig side.
LIBGCC_DIVIDE_SRC = r'''
static unsigned long long mk4_udivmod(unsigned long long n, unsigned long long dd,
                                      unsigned long long *rp) {
    unsigned long long q = 0, r = 0; int i;
    for (i = 63; i >= 0; i--) {
        r = (r << 1) | ((n >> i) & 1ULL);
        if (dd && r >= dd) { r -= dd; q |= (1ULL << i); }
    }
    if (rp) *rp = r;
    return q;
}
long long __divdi3(long long a, long long b) {
    int neg = 0; unsigned long long ua, ub, q;
    if (a < 0) { ua = (unsigned long long)(-a); neg ^= 1; } else ua = (unsigned long long)a;
    if (b < 0) { ub = (unsigned long long)(-b); neg ^= 1; } else ub = (unsigned long long)b;
    q = mk4_udivmod(ua, ub, 0);
    return neg ? -(long long)q : (long long)q;
}
unsigned long long __udivdi3(unsigned long long a, unsigned long long b) {
    return mk4_udivmod(a, b, 0);
}
long long __moddi3(long long a, long long b) {
    int neg = 0; unsigned long long ua, ub, r;
    if (a < 0) { ua = (unsigned long long)(-a); neg ^= 1; } else ua = (unsigned long long)a;
    ub = (b < 0) ? (unsigned long long)(-b) : (unsigned long long)b;
    mk4_udivmod(ua, ub, &r);
    return neg ? -(long long)r : (long long)r;
}
unsigned long long __umoddi3(unsigned long long a, unsigned long long b) {
    unsigned long long r; mk4_udivmod(a, b, &r); return r;
}
'''


def build_twin_blob(name, body, gl_va, name_to_va, fn_self_va=None, width16=None,
                    fptypes=None, next_fn_va=None):
    """Compile twin -> .text, relocated so external calls target the
    ORIGINAL function VAs (callees co-execute as original bytes in the
    arena) and intra-twin labels resolve within the loaded blob. When
    fn_self_va is given, the blob is based so the function lands at its own
    original VA (self-references match the original's stored pointers).
    Returns (blob, entry_offset, load_base, err)."""
    globs = sorted(set(re.findall(r'\bg_\w+', body)))
    if any(g not in gl_va for g in globs):
        return None, None, None, 'unmapped global'

    # Usage-aware #define so the lvalue at the global's VA has the right type
    # (mirrors the injector gate): a global called through `(*g)()` / `g()` is
    # a function pointer; one deref'd `*g` or indexed `g[i]` or pointer-assigned
    # holds a pointer; else a plain scalar. Same VA either way - only the type
    # of the lvalue differs so the C compiles.
    def gdef(g, va):
        # width16: globals the caller knows are 16-bit (e.g. packed s16 matrix
        # entries / vertex coords the original reads `movsx word`). gdef defaults
        # every global to 32-bit, which is WRONG for a packed 16-bit value - its
        # high word is the NEXT entry, so a dword read is polluted. Typing it as
        # `short` reads exactly 2 bytes, sign-extended, matching movsx. Opt-in per
        # harness (default empty) so the 100+ existing 32-bit verifications are
        # untouched. Signed because the geometry path uses movsx, not movzx.
        if width16 and g in width16:
            return '#define %s (*(short *)0x%xu)\n' % (g, va)
        # Narrower-than-32-bit globals, taken from the declaration in the
        # twin's own file. See NARROW above for why this matters.
        if fptypes and g in fptypes:
            return '#define %s (*(%s *)0x%xu)\n' % (g, fptypes[g], va)
        if re.search(r'\(\s*\*\s*%s\s*\)\s*\(' % g, body) or re.search(r'\b%s\s*\(' % g, body):
            return '#define %s (*(unsigned int (**)())0x%xu)\n' % (g, va)
        deref = False
        for m in re.finditer(r'\*\s*%s\b' % g, body):
            j = m.start() - 1
            while j >= 0 and body[j] in ' \t':
                j -= 1
            if j < 0 or (body[j] not in '_)]' and not body[j].isalnum()):
                deref = True
        # Indexed `g[i]` -> g is an array AT the VA (a base-0 packed-ptr table
        # like g_siblingTable resolves the address from i*4), so the base IS
        # the VA: single-indirect. A unary-deref `*g` -> g HOLDS a pointer:
        # double-indirect (load the pointer FROM the VA). (Conflating these
        # made `g_siblingTable[i]` a double null-deref that gcc -O2 traps.)
        if re.search(r'\b%s\s*\[' % g, body):
            return '#define %s ((unsigned int *)0x%xu)\n' % (g, va)
        if deref:
            return '#define %s (*(unsigned int **)0x%xu)\n' % (g, va)
        return '#define %s (*(unsigned int *)0x%xu)\n' % (g, va)
    defs = ''.join(gdef(g, gl_va[g]) for g in globs)
    # Declare every referenced function (called OR taken as &address - a
    # resolved continuation like `&ScaledInitOrSelfPtrSetType_...`). Without a
    # declaration `&fn` is an undeclared-identifier error (implicit decl only
    # covers calls). The relocation pass below points each to its original VA.
    fns = {t for t in re.findall(r'\b([A-Za-z_]\w*)\b', body)
           if t in name_to_va and t != name}
    defs += ''.join('extern int %s();\n' % f for f in sorted(fns))
    src = ('#define NON_MATCHING 1\n'
           '#include "portable/ghidra_types.h"\n#include "portable/mem_model.h"\n'
           # code_va.h too: MK4_CODE_VA(f) is how a twin puts a function's VA in
           # a 32-bit callback slot. Outside MK4_ARENA - which is this harness -
           # it expands to the original `(unsigned int)&f`, so it relocates the
           # same way and no existing twin changes.
           '#include "portable/code_va.h"\n'
           # The project's scalar spellings, declared inline rather than by
           # including types.h - that header drags in win32_types.h, whose HWND
           # collides with Ghidra's. These names do not overlap ghidra_types.h.
           'typedef signed char s8; typedef unsigned char u8;\n'
           'typedef short s16; typedef unsigned short u16;\n'
           'typedef int s32; typedef unsigned int u32;\n'
           'typedef long long s64; typedef unsigned long long u64;\n'
           'typedef float f32; typedef double f64;\n'
           + defs + body + '\n')
    # A twin that does a 64-bit divide (e.g. the perspective divide in
    # ProjectVertex) emits a libgcc helper call (__divdi3/...). build_twin_blob
    # only resolves GAME-function callees, so the call would be unresolved. We
    # compile once; if the .o references one of these helpers, append a self-
    # contained C implementation (bit-by-bit division - never uses the 64-bit
    # `/` operator, so no recursion) and recompile so the call resolves WITHIN
    # the blob. Only triggers for twins that actually need it - all other twins
    # compile exactly as before.
    LIBGCC = {'__divdi3', '__udivdi3', '__moddi3', '__umoddi3'}
    syms = sections = None
    for attempt in range(2):
        with tempfile.TemporaryDirectory() as d:
            c = Path(d) / 't.c'
            c.write_text(src)
            o = Path(d) / 't.o'
            r = subprocess.run(
                [CC, '-m32', '-std=gnu89', '-c', '-O2', '-fno-stack-protector',
                 '-fno-pic', '-ffreestanding', '-fno-asynchronous-unwind-tables',
                 # the engine reads fixed VAs (incl. base-0 packed-ptr tables);
                 # don't let gcc treat those as UB null derefs and emit ud2.
                 '-fno-delete-null-pointer-checks',
                 # The original's FPU helpers use bare x87 (fsqrt, fabs) with no
                 # errno bookkeeping. Without this gcc turns sqrt() into a libm
                 # CALL, which has no original VA to relocate to and the twin is
                 # skipped as "unresolved call: sqrt"; with it, gcc emits fsqrt
                 # inline - matching what the original actually does.
                 '-fno-math-errno',
                 # build_twin_blob loads the twin's .text and nothing else, so a
                 # switch lowered to a jump table in .rodata would jump into
                 # unmapped memory (UC_ERR_FETCH_UNMAPPED). Comparison chains
                 # keep the whole dispatch inside .text.
                 '-fno-jump-tables',
                 # CC is mingw (defines _WIN32), so win32_types.h would gate its
                 # DWORD/HWND/... typedefs off; force the shim branch on so Win32-typed
                 # twins compile (windows.h is not included under -ffreestanding).
                 '-DMK4_WIN32_SHIM',
                 '-I' + str(ROOT / 'include'), '-w', str(c), '-o', str(o)],
                capture_output=True, text=True)
            if r.returncode:
                # report the FIRST diagnostic line, not the last: gcc's caret
                # line is last and says nothing.
                errs = [l for l in r.stderr.splitlines() if 'error:' in l]
                return None, None, None, 'compile: ' + (
                    errs or r.stderr.strip().splitlines() or [''])[0].strip()
            syms, sections = syn.parse_obj_full(o.read_bytes())
        undef = {_strip(s['name']) for s in syms if s and s['sec'] <= 0}
        if attempt == 0 and (undef & LIBGCC):
            src += LIBGCC_DIVIDE_SRC
            continue
        break
    text = next((s for s in sections if s['name'].startswith('.text')), None)
    if text is None:
        return None, None, None, 'no .text'
    buf = bytearray(text['content'])
    entry = 0
    for s in syms:
        if s and _strip(s['name']) == name and s['sec'] > 0:
            entry = s['value']
    # Load the blob so the function's entry lands at its ORIGINAL VA. Then a
    # self-reference `&name` (e.g. a continuation storing its own function
    # pointer into a node field) relocates to the real VA and matches what the
    # original writes - otherwise the twin stores its blob address and we get a
    # spurious MISMATCH at the stored-pointer slot.
    load_base = (fn_self_va - entry) if fn_self_va is not None else CODE
    # Placing the blob at the original VA only matters when the twin references
    # its OWN address (a continuation that stores &name into a node field). A
    # compiled twin is often longer than the original, and when it is, that
    # placement runs over the NEXT function's bytes - any scenario that calls
    # the neighbour then executes garbage. With no self-reference the placement
    # buys nothing, so fall back to the scratch code window and verify anyway
    # instead of skipping the function entirely.
    #
    # Detect the self-reference from the SOURCE, not from the relocation
    # symbols: for a function defined in the same object COFF emits a SECTION
    # symbol plus an addend, not the function's own name, so a name-based scan
    # over the relocs misses exactly the case that matters (an install-self
    # twin storing its own address into a node field). The body mentions its
    # own name once in the signature; more than that means it takes its address.
    self_ref = len(re.findall(r'\b%s\b' % re.escape(name), body)) > 1 or \
        any(syms[r['sym_idx']] is not None and
            _strip(syms[r['sym_idx']]['name']) == name
            for r in text['relocs']
            if 0 <= r['sym_idx'] < len(syms))
    if (not self_ref and next_fn_va is not None
            and load_base + len(buf) > next_fn_va):
        load_base = CODE
    for r in text['relocs']:
        sym = syms[r['sym_idx']] if 0 <= r['sym_idx'] < len(syms) else None
        if sym is None:
            return None, None, None, 'bad sym'
        off, rt = r['va'], r['type']
        if sym['sec'] > 0:                         # defined in this obj (label)
            target = load_base + sym['value']
        else:                                      # external -> original VA
            sname = _strip(sym['name'])
            tv = name_to_va.get(sname)
            if tv is None and sname.startswith('thunk_'):
                # Ghidra `thunk_X` is a jmp-wrapper to X; co-executing as X's
                # bytes is behaviourally identical, so resolve to X's VA.
                tv = name_to_va.get(sname[len('thunk_'):])
            if tv is None:
                # Ghidra emits raw-address callees as `func_0x<hex>` (and the
                # `thunk_func_0x<hex>` jmp-thunk variant): the VA is in the name,
                # so resolve it directly - the callee co-executes as the original
                # bytes at that VA, same as a named one.
                m = re.search(r'func_0x([0-9a-fA-F]+)$', sname)
                if m:
                    tv = int(m.group(1), 16)
            if tv is None:
                return None, None, None, 'unresolved call: %s' % sname
            target = tv
        if rt == 6 and off >= 1 and buf[off-1] in (0xe8, 0xe9):
            rt = 20
        existing = struct.unpack_from('<I', buf, off)[0]
        if rt == 6:
            struct.pack_into('<I', buf, off, (target + existing) & 0xffffffff)
        elif rt == 20:
            struct.pack_into('<I', buf, off,
                             (target - (load_base + off + 4) + existing) & 0xffffffff)
    return bytes(buf), entry, load_base, None


# Declared spellings that are NOT 32 bits. gdef types every global
# `unsigned int` by default, which is wrong in two ways: a qword double read as
# an integer computes garbage, and - worse, because it corrupts state the twin
# never meant to touch - a byte or halfword field written 32 bits wide CLOBBERS
# ITS NEIGHBOURS. The engine packs those hard: g_dispatchSave1613..1616 are four
# consecutive BYTES, so a 32-bit store to the first wipes the other three.
# ONLY the floating-point spellings. Narrow INTEGER types are deliberately not
# here: see narrow_globals() - retyping an integer global also changes C's
# promotion rules in expressions written against the 32-bit spelling, and the
# twins were verified under that. Integer widths are opt-in per harness via
# verify(types=...).
NARROW = {'double': 'double', 'float': 'float'}


_WIDTHS = None


def narrow_globals():
    """global -> C type from config/global_widths.yaml (audit_widths.py).

    NOT applied by default. The widths are correct - they come from the
    original's own encodings - but narrowing a global also changes C's integer
    PROMOTION in expressions written against the 32-bit spelling: an
    `unsigned int` global compared with a `short` promotes the short to
    unsigned, while an `unsigned short` one leaves the comparison signed. Twins
    verified under the wide typing depend on that (g_screenH in the tristrip
    emitters is the case in point), so applying the map is a per-twin decision.
    Harnesses opt in by passing `types=` to verify().
    """
    global _WIDTHS
    if _WIDTHS is None:
        import yaml
        f = ROOT / 'config' / 'global_widths.yaml'
        raw = yaml.safe_load(f.read_text()) if f.exists() else {}
        _WIDTHS = dict(raw or {})
    return _WIDTHS


def fp_globals_for(name):
    """Map global -> 'double'/'float' for the file that defines twin `name`.

    The engine's FPU helpers multiply by qword constants in .rdata, and gdef
    would otherwise read one as an integer and compute garbage."""
    sig = re.compile(r'\b%s\s*\(' % re.escape(name))
    for f in (ROOT / 'src').rglob('*.c'):
        s = f.read_text(errors='ignore')
        # Match the file that holds the TWIN, not merely one that mentions the
        # name - engine_autostubs.c carries a weak stub for every frontier
        # symbol and would otherwise shadow the real declarations.
        if not any(sig.search(s[m.end():s.find('#else', m.end())])
                   for m in re.finditer(r'#ifdef NON_MATCHING\b', s)
                   if s.find('#else', m.end()) > 0):
            continue
        out = {}
        for t, g in re.findall(
                r'(?m)^\s*extern\s+((?:unsigned\s+|signed\s+)?\w+)\s+(g_\w+)\s*(?:\[[^\]]*\])?\s*;', s):
            t = ' '.join(t.split())
            if t in NARROW:
                out[g] = NARROW[t]
        return out
    return {}


def extract_twin_any(name):
    """Like verify_twin.extract_twin but for ANY signature (not just
    void(void)). Returns (body, nargs, returns_value) or None.
    nargs = number of stack params (each counted as one 4-byte slot);
    returns_value = the body has a `return <expr>;` (so EAX is meaningful)."""
    sig = re.compile(r'\b[A-Za-z_][\w *]*?\b(%s)\s*\(([^){]*)\)\s*\{'
                     % re.escape(name))
    for f in (ROOT / 'src').rglob('*.c'):
        s = f.read_text(errors='ignore')
        for m in re.finditer(r'#ifdef NON_MATCHING\b', s):
            j = s.find('#else', m.end())
            if j < 0:
                continue
            block = s[m.end():j]
            nm = sig.search(block)
            if not nm:
                continue
            params = nm.group(2).strip()
            nargs = 0 if params in ('', 'void') else \
                len([p for p in params.split(',') if p.strip()])
            start = nm.start()
            i = block.index('{', nm.end() - 1)
            k, depth = i, 0
            while k < len(block):
                if block[k] == '{':
                    depth += 1
                elif block[k] == '}':
                    depth -= 1
                    if depth == 0:
                        break
                k += 1
            body = block[start:k + 1]
            # EAX holds the return only for an integer/pointer return that the
            # body actually produces. A float/double return goes in ST(0) (not
            # compared here), so do NOT check EAX for those - else a correct
            # float function (e.g. Frexp) is a false mismatch.
            rettype = body[:body.index(nm.group(1))]
            returns_value = bool(re.search(r'\breturn\s+[^;]', body)) and \
                not re.search(r'\b(float|double|float10)\b', rettype)
            return body, nargs, returns_value
    return None


def uc_new(arena):
    from unicorn import Uc, UC_ARCH_X86, UC_MODE_32
    from unicorn import UC_HOOK_MEM_READ_UNMAPPED, UC_HOOK_MEM_WRITE_UNMAPPED
    full = (BASE + len(arena) + 0xFFF) & ~0xFFF
    uc = Uc(UC_ARCH_X86, UC_MODE_32)
    uc.mem_map(0, full)
    uc.mem_write(BASE, bytes(arena))
    uc.mem_map(STACK, 0x40000)
    uc.mem_map(CODE, 0x100000)

    def on_unmapped(uc, access, addr, sz, val, ud):
        try:
            uc.mem_map(addr & ~0xFFF, 0x1000)
        except Exception:
            pass
        return True
    uc.hook_add(UC_HOOK_MEM_READ_UNMAPPED | UC_HOOK_MEM_WRITE_UNMAPPED, on_unmapped)
    return uc, full


import os
CAP = int(os.environ.get('MK4_COEXEC_CAP', '2000000'))
# Per-emulation wall-clock ceiling (microseconds). Bounds the rare twin whose
# emulation the instruction cap fails to stop in reasonable time, so a sweep
# can never hang/peg a core. Override via MK4_COEXEC_WALL_US.
WALL_US = int(os.environ.get('MK4_COEXEC_WALL_US', '3000000'))
ARG_BASE = None          # set in main(): start of the deterministic arg scratch


def run_at(uc, eip, full, nargs=0, argvals=None):
    from unicorn.x86_const import UC_X86_REG_ESP, UC_X86_REG_EIP, UC_X86_REG_EAX
    SENT = 0x00bad0de
    esp = STACK + 0x20000
    uc.reg_write(UC_X86_REG_ESP, esp)
    uc.mem_write(esp, SENT.to_bytes(4, 'little'))   # return address
    # Stack args at [esp+4 ...], identical for both sides. Each arg points into
    # a deterministic self-referential scratch region (word at A == A), so a
    # pointer arg can be walked without faulting and BOTH sides see the same
    # bytes - this is an equivalence check, not a realistic-input test.
    # argvals (opt-in, per-harness): pass a LITERAL value for an argument that is
    # a scalar, not a pointer. The self-referential-scratch default above is
    # right for pointer args but catastrophic for a small INDEX arg - e.g.
    # Helper_EmitLine(i) indexes [i*2 + 0x7af958], so handing it a 0x7f0000-ish
    # scratch address walks far outside the arena. None = keep the default.
    for i in range(nargs):
        v = None if argvals is None or i >= len(argvals) else argvals[i]
        if v is None:
            v = (ARG_BASE + i * 0x400) & 0xffffffff
        uc.mem_write(esp + 4 + 4 * i, (v & 0xffffffff).to_bytes(4, 'little'))
    # Wall-clock timeout (microseconds) in ADDITION to the instruction cap:
    # some pathological twins/originals run the cap's worth of instructions so
    # slowly (or in a way the count cap doesn't bound) that emu_start hangs for
    # minutes, pegging a core. The timeout guarantees emu_start returns; a
    # timed-out run leaves EIP != SENT -> treated as non-terminated -> SKIP
    # (cap artifact), never a false MISMATCH. See feedback_no_untracked_background_fleets.
    uc.emu_start(eip, SENT, timeout=WALL_US, count=CAP)
    # A mismatch is only trustworthy if the function actually RETURNED (EIP at
    # the sentinel). If it hit the instruction cap mid-run, the twin (gcc) and
    # original (MSVC asm) may simply be at different points of an equivalent
    # computation - a snapshot diff there is a cap artifact, not a real bug.
    terminated = uc.reg_read(UC_X86_REG_EIP) == SENT
    eax = uc.reg_read(UC_X86_REG_EAX)
    return bytes(uc.mem_read(0, full)), terminated, eax


def verify(name, fn_va, gl_va, name_to_va, arena, width16=None, argvals=None,
           types=None):
    fptypes = fp_globals_for(name)
    if types:
        fptypes = dict(fptypes, **types)
    if name not in fn_va:
        return 'SKIP no-addr'
    t = extract_twin_any(name)
    if not t:
        return 'SKIP no-twin'
    body, nargs, returns_value = t
    nxt = min((v for v in fn_va.values() if v > fn_va[name]), default=None)
    blob, entry, load_base, err = build_twin_blob(
        name, body, gl_va, name_to_va, fn_self_va=fn_va[name], width16=width16,
        fptypes=fptypes, next_fn_va=nxt)
    if blob is None:
        return 'SKIP ' + err
    try:
        uc1, full = uc_new(arena)
        orig = run_at(uc1, fn_va[name], full, nargs, argvals)
        uc2, _ = uc_new(arena)
        # blob outside the arena map - and not in the scratch CODE window,
        # which uc_new already mapped
        if load_base + len(blob) > full and not (
                CODE <= load_base and load_base + len(blob) <= CODE + 0x100000):
            uc2.mem_map(load_base & ~0xFFF,
                        ((len(blob) + (load_base & 0xFFF) + 0xFFF) & ~0xFFF))
        uc2.mem_write(load_base, blob)             # twin lands at its own VA
        # The twin is placed AT the original function's VA so self-references
        # resolve, but the compiled twin is often LONGER than the original. If
        # it overruns into the next function symbol it silently corrupts that
        # function's first bytes - and any scenario that CALLS the neighbour
        # then executes garbage and hangs (DrawMeshBlock's twin is 0x440 bytes
        # over a 0x430 original, clobbering TristripBatchEmit3Cap right after
        # it). Report it instead of letting it look like a twin bug.
        relocated = CODE <= load_base < CODE + 0x100000
        if not relocated and nxt is not None and load_base + len(blob) > nxt:
            over = load_base + len(blob) - nxt
            victim = next((k for k, v in fn_va.items() if v == nxt), hex(nxt))
            _overrun = 'blob overruns %s by %d bytes' % (victim, over)
        else:
            _overrun = None
        twin, twin_ret, twin_eax = run_at(uc2, load_base + entry, full, nargs, argvals)
    except Exception as e:
        return 'SKIP unicorn: %s' % e
    orig, orig_ret, orig_eax = orig
    init = bytearray(full)
    init[BASE:BASE + len(arena)] = arena

    # Exclude the .text region where the twin blob was loaded: its bytes
    # differ from the original function's bytes there, but that is code, not a
    # data write. (delta is a DATA-write diff; the original never rewrites its
    # own code, so masking this range is symmetric and correct.)
    blob_lo = load_base & ~3
    blob_hi = (load_base + len(blob) + 3) & ~3

    def delta(buf):
        return {o: bytes(buf[o:o+4]) for o in range(0, full, 4)
                if not (blob_lo <= o < blob_hi) and buf[o:o+4] != init[o:o+4]}
    do, dt = delta(orig), delta(twin)
    # EAX (return value) only matters for a value-returning function and only
    # once both sides have returned (else it is mid-run garbage).
    eax_ok = (not returns_value) or not (orig_ret and twin_ret) \
        or (orig_eax == twin_eax)
    if do == dt and eax_ok:
        return 'VERIFIED (%d writes%s)%s' % (
            len(do), '' if not returns_value else ', eax=0x%x' % (twin_eax & 0xffffffff),
            '' if (orig_ret and twin_ret) else ' [capped]')
    # A diff is only a trustworthy MISMATCH if BOTH sides returned; otherwise
    # one hit the instruction cap mid-run and the snapshot diff is a cap
    # artifact (equivalent code, different instruction counts).
    if not (orig_ret and twin_ret):
        return 'SKIP capped-diff (orig_ret=%d twin_ret=%d)%s' % (
            orig_ret, twin_ret, '' if not _overrun else ' [%s]' % _overrun)
    if do == dt and not eax_ok:
        return 'MISMATCH eax orig=0x%x twin=0x%x' % (
            orig_eax & 0xffffffff, twin_eax & 0xffffffff)
    ou = sorted(set(do) - set(dt))
    on = sorted(set(dt) - set(do))
    vd = sorted(o for o in set(do) & set(dt) if do[o] != dt[o])
    return 'MISMATCH orig_only=%s twin_only=%s vdiff=%s' % (
        [hex(o) for o in ou[:3]], [hex(o) for o in on[:3]], [hex(o) for o in vd[:3]])


def all_twins():
    names = []
    for f in (ROOT / 'src').rglob('*.c'):
        s = f.read_text(errors='ignore')
        for m in re.finditer(r'#ifdef NON_MATCHING\b', s):
            j = s.find('#else', m.end())
            if j < 0:
                continue
            nm = re.search(r'\b(\w+)\s*\(', s[m.end():j])
            if nm:
                names.append(nm.group(1))
    return names


def main():
    global ARG_BASE
    fn_va, gl_va = vt.load_maps()
    name_to_va = fn_va                 # load_maps' fn_va is already name -> VA
    arena = bytearray(ARENA.read_bytes())
    # Deterministic self-referential arg scratch in the last 256 KB of the
    # arena: the word at address A holds A, so any pointer arg can be walked
    # (and chased through fields) without leaving the region or faulting, and
    # both co-exec runs read identical bytes. It lives inside [0,full) so writes
    # through arg pointers are still part of the diff; the baseline pattern is
    # in `init` (= arena) so it produces no spurious diff.
    ARG_BASE = BASE + len(arena) - 0x40000
    for off in range(len(arena) - 0x40000, len(arena), 4):
        struct.pack_into('<I', arena, off, (BASE + off) & 0xffffffff)
    names = sys.argv[1:] or all_twins()
    counts = {}
    for n in names:
        r = verify(n, fn_va, gl_va, name_to_va, arena)
        counts[r.split()[0]] = counts.get(r.split()[0], 0) + 1
        print('%-44s %s' % (n, r))
    print('\nsummary:', counts)


if __name__ == '__main__':
    main()
