# Matching workflow

How to take a function from `stub` → `drafted` → `matched`. Read
top-to-bottom on first pass; later use the **Cookbook** at the
bottom as a reference for specific MASM/MSVC quirks.

---

## 1. Pick a function

Open `config/symbols.yaml`, find an entry with `status: stub`. Good
first targets: leaf functions (no callees, or only thoroughly-
matched callees) and small functions (size < 200 bytes).

```yaml
- addr: 0x004acc50
  name: CheckInstallPath
  size: 129
  group: engine.install
  status: stub
```

`symbols.yaml` is auto-extended by `tools/decomp/discover_functions.py`
which BFS-walks every CALL target from the known set. Functions
discovered that way get an auto-generated name like
`func_004acc50` — rename them as you go.

## 2. Read the original

Two options:

- **Ghidra**: open `analysis/ghidra/MK4` project, navigate to the
  VA, study Listing + Decompiler panes
- **objdump**: extract the function bytes from `game/MK4.EXE` and
  pipe through `i686-w64-mingw32-objdump -d -b binary -m i386 -M intel`

A typical extraction snippet (save as `tools/decomp/dump_fn.py` if
you do this often):

```python
import struct
with open('game/MK4.EXE','rb') as f: d = f.read()
pe = struct.unpack_from('<I', d, 0x3c)[0]
ib = struct.unpack_from('<I', d, pe + 24 + 28)[0]
n_sec = struct.unpack_from('<H', d, pe + 6)[0]
opt = struct.unpack_from('<H', d, pe + 20)[0]
for i in range(n_sec):
    s = pe + 24 + opt + i*40
    if d[s:s+8].rstrip(b'\0') == b'.text':
        v_addr = struct.unpack_from('<I', d, s+12)[0]
        r_off  = struct.unpack_from('<I', d, s+20)[0]
        break
ADDR, SIZE = 0x004acc50, 129          # <-- pick from symbols.yaml
fo = (ADDR - ib - v_addr) + r_off
import sys; sys.stdout.buffer.write(d[fo:fo+SIZE])
```

```sh
python3 tools/decomp/dump_fn.py | i686-w64-mingw32-objdump -d \
    -b binary -m i386 -M intel --adjust-vma=0x004acc50 /dev/stdin
```

## 3. Write a draft

Place the C source in `src/<group>/<file>.c` (consult `group:` in
`symbols.yaml`). Add the `@addr 0x........` comment. Use globals
already declared in `include/<group>/*.h`; add new ones there.

Set `status: drafted`.

## 4. Build & diff

```sh
./tools/decomp/cl.sh /Iinclude /c src/<group>/<file>.c \
    /Fobuild/obj/<file>.obj
```

For per-function reloc-aware diff (compares the function bytes in
the rebuilt .obj against the original .text bytes, masking the
4-byte windows around relocations):

```python
# tools/decomp/diff_one.py — call as: python3 diff_one.py <addr> <size> <obj>
import struct, sys

ADDR, SIZE, OBJ = int(sys.argv[1], 0), int(sys.argv[2], 0), sys.argv[3]

def get_pe_text(p):
    with open(p,'rb') as f: d = f.read()
    pe = struct.unpack_from('<I', d, 0x3c)[0]
    ib = struct.unpack_from('<I', d, pe+24+28)[0]
    n  = struct.unpack_from('<H', d, pe+6)[0]
    sz = struct.unpack_from('<H', d, pe+20)[0]
    s0 = pe + 24 + sz
    for i in range(n):
        s = s0 + i*40
        if d[s:s+8].rstrip(b'\0') == b'.text':
            va = struct.unpack_from('<I', d, s+12)[0]
            ro = struct.unpack_from('<I', d, s+20)[0]
            return d, ro, va, ib

data, r_off, v_addr, ib = get_pe_text('game/MK4.EXE')
fo = (ADDR - ib - v_addr) + r_off
orig = data[fo:fo+SIZE]

with open(OBJ,'rb') as f: obj = f.read()
n_secs = struct.unpack_from('<H', obj, 2)[0]
opt = struct.unpack_from('<H', obj, 16)[0]
for i in range(n_secs):
    s = 20 + opt + i*40
    if obj[s:s+8].rstrip(b'\0') == b'.text':
        ro = struct.unpack_from('<I', obj, s+20)[0]
        rs = struct.unpack_from('<I', obj, s+16)[0]
        nr = struct.unpack_from('<H', obj, s+32)[0]
        roff = struct.unpack_from('<I', obj, s+24)[0]
        break

text = obj[ro:ro+rs]
rebuilt = bytearray(text[:SIZE])
relocs = [struct.unpack_from('<I', obj, roff + r*10)[0] for r in range(nr)]
mo = bytearray(orig)
for v in relocs:
    for k in range(4):
        if v+k < len(rebuilt): rebuilt[v+k] = 0
        if v+k < len(mo):      mo[v+k]      = 0
diffs = [(j, mo[j], rebuilt[j])
         for j in range(min(len(rebuilt), len(mo)))
         if rebuilt[j] != mo[j]]
print(f'rebuilt={len(rebuilt)} orig={len(mo)} diffs: {len(diffs)}')
for j,o,r in diffs[:30]:
    print(f'  +{j:#06x}: orig={o:02x} new={r:02x}')
```

Iterate until `diffs: 0`. Then:

1. Set `status: matched` in `symbols.yaml`
2. Add `file: src/<group>/<file>.c` to the entry
3. Run `python3 tools/decomp/progress.py` to confirm the bar moved

---

## Cookbook — MSVC 5.0 SP3 + MASM `__asm` quirks

This is the meat. Skim once now; come back when a diff doesn't
converge.

### A. MASM ignores `SHORT` on forward `jcc`

The MSVC inline assembler emits **long-form** for forward
conditional jumps regardless of the `SHORT` qualifier:

```asm
jne     SHORT exit         ; MASM emits 0f 85 + 4-byte offset
                           ; even if exit is 30 bytes ahead!
```

**Workaround:** emit the bytes by hand. Compute the signed-byte
offset: `(target_va - (jne_va + 2))`.

```asm
cmp     dword ptr [g_framePauseFlag], ebx
; orig: 75 7d   (jne SHORT, +0x7d)
_emit   75h
_emit   7dh
```

Forward `jmp SHORT label` (unconditional) usually works, only
`jcc` is broken. Backward jcc emits short form correctly.

### B. `[absolute_address]` produces `mov reg, imm32`

```asm
mov     edx, dword ptr [0x6f7680]   ; MASM emits ba 80 76 6f 00
                                     ; = mov edx, 0x6f7680  (5 bytes)
                                     ; instead of  8b 15 80 76 6f 00
                                     ; = mov edx, [m32]     (6 bytes)
```

**Fix:** declare the address as an `extern` symbol and reference
it by name. The linker fills the address; reloc-mask hides it
in the diff.

```c
extern u32 g_ecmInputBuf;          /* 0x006f7680 */
```

```asm
mov     edx, dword ptr [g_ecmInputBuf]   ; correct: 8b 15 + reloc
```

### C. `[reg + symbol + offset]` may collapse to `[m32]`

When MASM sees `mov [edx + g_nodeSlotsArea + 0xd8], eax` it
sometimes drops the register and emits `mov ds:[m32], eax`
(EAX-form, 5 bytes) — wrong encoding.

**Fix:** declare a separate extern at the resolved address rather
than do the arithmetic inside the brackets.

```c
extern u32 g_nodeSlotsHdr_ptrField;   /* 0x0053e440 */
```

```asm
mov     dword ptr [edx + g_nodeSlotsHdr_ptrField], eax
;       89 82 + 4-byte reloc  (correct, 6 bytes)
```

### D. Asymmetric epilogue (early-out via partial pops)

Pattern: function pushes ebx/esi/edi, but an early-out `ret`
**skips the pops** and only does `add esp, frame; ret`. The full
epilogue (with pops) lives later for the success path.

```asm
        push    ebx
        push    esi
        push    edi
        ...
        je      early_out
        ; main path
        ...
        pop     edi
        pop     esi
        pop     ebx
        ret
early_out:
        add     esp, 0x20
        ret               ; <-- no pops! caller's regs are gone
```

Never matches as plain C. Write the function `__declspec(naked)`
and emit the asymmetric tails by hand.

### E. Fail-tail-before-success-tail layout

When the original lays the failure path **before** the success
path inside the function body (rather than the natural
"if-success-return; failure-return" order), an `if/else` in C
won't reproduce it. Use:

```c
do {
    if (cond_a) break;     // jump to fail-tail
    if (cond_b) break;
    /* success body */
    return SUCCESS;
} while (0);
/* fail-tail here */
return FAIL;
```

### F. Use the global, not a local that aliases it

If the original reloads a global from memory across a call:

```asm
mov     eax, dword ptr [g_x]
call    Helper
mov     eax, dword ptr [g_x]    ; reload (Helper might have stomped)
```

…then in C, **read the global directly twice**, don't bind it to
a local. MSVC SP3 will promote the local to a callee-saved
register and steal an extra push from your prologue.

```c
do_thing(g_x);
helper();
also(g_x);            /* not: int x = g_x; do_thing(x); helper(); also(x); */
```

### G. Minimize explicit locals when matching

Each extra `int local` in MSVC's SP3 stack frame typically forces
an extra push of a callee-saved register (ebx/esi/edi) — which
shows up in the prologue and shifts every byte after.

**Fix:** inline expressions. Compute things in arguments to calls
when you can. Use `(u32)x` casts at use sites.

### H. Scaled-base addressing trick (`[reg*4 + 0]`)

The binary uses a peculiar pattern where a global stores
`addr_of_table >> 2` and then accesses are `[reg*4 + 0]` (SIB,
no base register, disp32 = 0). Equivalent C is hard to coax. Use
`__declspec(naked)` and emit:

```asm
mov     ecx, dword ptr [g_currentNodeIdx]   ; ecx = base/4
mov     eax, dword ptr [ecx*4]              ; ecx*4 = base
                                            ; SIB+disp32=0 form
```

MASM emits the encoding `8b 04 8d 00 00 00 00` for `[ecx*4]`
which is what we want.

### I. Switch dispatch with byte-table + jump-table

MSVC SP3's sparse-switch idiom:

```asm
        cmp     ecx, 0x1c
        ja      default
        xor     eax, eax
        mov     al, byte ptr [ecx + g_switchByteTable]
        jmp     dword ptr [eax*4 + g_switchJumpTable]
```

The two tables are emitted **as data in `.text`** by the linker,
right after the function. To match, declare both as extern arrays
(in `.text` again — link script handles placement):

```c
extern u8  g_switchByteTable[];     /* N entries */
extern u32 g_switchJumpTable[];     /* M entries */
```

The function bytes only reference the symbols by relocation — the
tables themselves can live in any source file (or be elided
entirely if you're only diffing the function's body).

### J. SEH-wrapped functions (`__try`/`__except`)

The `entry`/CRT-startup function pushes a manual SEH frame:

```asm
push    -1
push    offset g_seh_scope_table
push    offset _except_handler3
mov     eax, fs:[0]
push    eax
mov     fs:[0], esp
```

Don't try to write this with `__try`/`__except` in C — MSVC SP3
generates a different scope table layout. Use `__declspec(naked)`
and emit the bytes verbatim. The scope table itself lives in
`.rdata` and can be a bare `extern u32 g_seh_scope_table[]` — the
linker resolves it.

### K. `add esp, -X` vs `sub esp, X`

These produce different bytes:

```
add esp, -0x58   →   83 c4 a8     (3 bytes)
sub esp, 0x58    →   83 ec 58     (3 bytes - same length but different)
```

MSVC SP3's CRT prologue uses `add esp, -X`. To match, write
exactly that in `__asm`.

### L. Stack-probe `__chkstk` for large frames

For stack frames ≥ 4 KB, MSVC SP3 generates a `__chkstk` call
*before* the standard prologue:

```asm
mov     eax, 0x4010
call    __chkstk          ; e8 + reloc — adjusts esp by eax
push    ebx
push    ebp
push    esi
push    edi
mov     dword ptr [ebp-0x18], esp
```

For naked functions, declare `void Helper_ChkStk(void);` and call
it manually. The CALL is reloc-masked in the diff.

### M. The `mov eax, ds:0xVA` / `mov ds:0xVA, eax` short form

When the source/dest is `eax` and the addressing is plain
absolute, the encoding is the **special EAX form** (`a1`/`a3`,
5 bytes total) rather than the general form (`8b 05`/`89 05`,
6 bytes).

```
mov eax, [g_x]    →  a1 + 4-byte reloc      (5 bytes)
mov ecx, [g_x]    →  8b 0d + 4-byte reloc   (6 bytes)
mov [g_x], eax    →  a3 + 4-byte reloc      (5 bytes)
mov [g_x], ecx    →  89 0d + 4-byte reloc   (6 bytes)
```

MASM picks the right form automatically based on register. Don't
fight this.

### N. WORD-prefix encoding ordering

When `rep stosw` or similar uses a 16-bit operand override
(`66`), the prefix can come before or after `f3` (rep). MSVC SP3
sometimes emits `66 f3 ab` where MASM defaults to `f3 66 ab`.
The bytes must match the original.

**Fix:** force the order with `_emit`:

```asm
_emit   66h        ; force orig order
_emit   0F3h
_emit   0ABh
```

### O. Forcing the `lea ecx, [esp+0]` 4-byte form

MASM compresses `[esp+0]` to `[esp]` (3-byte encoding). If the
original has the 4-byte form (with explicit disp8=0):

```asm
_emit   8Dh
_emit   4Ch       ; or 44h for [esp+0] depending on register
_emit   24h
_emit   00h
```

### P. `cmp reg, imm8` sign-extended quirks

`83 fa 9c` is `cmp edx, -100` (imm8 sign-extended), **not**
`cmp edx, 0x9c`. If the original uses `0x9c` as an unsigned
constant, MSVC SP3 will emit the long form `81 fa 9c 00 00 00`
(7 bytes). Match what's there.

```c
if (x == -100) ...     /* matches 83 fa 9c form */
if (x == 0x9c) ...     /* matches 81 fa 9c 00 00 00 form */
```

### Q. SIB base/index swap (`[base+index*1+disp]`)

If the inner loop's offsets shift by 1 byte, the most likely
cause is a `lea esi, [eax+esi*1-8]` vs `lea esi, [esi+eax-8]`
SIB swap. Forcing `[base+index*1+disp]` (with explicit `*1`)
pins the encoding:

```asm
lea     esi, [eax + esi*1 - 8]    ; SIB: scale=00, idx=esi, base=eax
                                  ; → 8d 74 30 f8
```

vs

```asm
lea     esi, [esi + eax - 8]      ; might pick: SIB: idx=eax, base=esi
                                  ; → 8d 74 06 f8  (different!)
```

When in doubt, use `*1` to disambiguate.

---

## Common debugging patterns

**One-byte cumulative shift starting from offset N:** you have an
extra byte somewhere between the prologue and offset N. Usually
either an extra NOP, a wrong-form jne (long where it should be
short), or a missed `_emit` for an exact byte sequence. Hex-diff
around N to spot the discrepancy.

**Offset value differs but other bytes match:** a label is at the
wrong position, but the surrounding code is right. Look at the
label name in the diff and check whether your label matches
ORIG's label position. (Common mistake: in DSound_Init's outer
loop, putting `outer_loop:` after the entry `cmp+jg` instead of
before, so the bottom `jle outer_loop` lands one cmp later.)

**Structural divergence (random bytes):** a whole block is in the
wrong place. Re-examine the control flow — usually a mis-labeled
jump target. Compare the diff fragments to specific disasm
sections and look for "jumps land at offset X but I expected Y".

**Size mismatch by 1 byte:** look for an `_emit`-vs-actual-instruction
disagreement, or a 5-byte vs 6-byte mov form (EAX-vs-general).

---

## Don't break other matches

Rebuild `make matching` after every header change. If a
previously-matched function regresses, that's a problem: the
change you made affected the binary layout. Common causes:

- Adding a global → changes BSS layout → linker reorders
- Adding a string literal → changes `.rdata` content
- Reordering function definitions → affects `.text` ordering

Keep new globals + strings in the same source files as the
original (use `analysis/ghidra` to find which file owns each
symbol).

---

## Tips

- **Work bottom-up** — if `A` calls `B`, get `B` matching first
- **Pick small** functions to start (< 200 bytes); MSVC 5.0
  quirks become tractable at that scale
- **Trust the disasm** — if MASM keeps fighting, drop down to
  `__declspec(naked) + __asm` and emit the bytes literally
- **One match = forever** — once a function is byte-identical, it
  doesn't drift. No maintenance burden.
- **If a function seems impossible**, leave a comment in the
  source explaining what you tried, mark `status: drafted`, and
  move on. Come back later.

---

## Reference: status states

```
stub      asm-only, not yet decompiled
drafted   C source written, not yet byte-matching
matched   C source compiles to byte-identical asm
```

Track progress with `python3 tools/decomp/progress.py`.

Pick more functions from `config/symbols.yaml`; extend the symbol
list with `python3 tools/decomp/discover_functions.py --write`
when you've named enough new helpers that more CALL targets
become reachable.

---

## Batch matching: clusters of identical-shape stubs

Many functions in the binary are auto-generated wrappers — empty
debug stubs (`c3` only), state-setters (mov+mov+ret), tail-call
trampolines (`jmp Other`), guarded-sequel chains (`call A; if !pause:
jmp B`), and so on. Each variant has a fixed opcode shape with only
the relocation targets/constants differing. Matching them one at
a time is wasteful — they can be matched **in batches of 10–50**
once you've identified the recurring shape.

### Tools

`tools/decomp/batch_match.py` finds clusters of stubs that share
the same opcode "signature" — bytes-with-reloc-positions-nulled.
It bootstraps from one template stub:

```sh
# Pick a stub VA you've already decoded by hand
python3 tools/decomp/batch_match.py --template 0x00461860
# → "found 13 stubs matching this signature"

# After writing a generator that emits all 13 in one .c file:
python3 tools/decomp/batch_match.py --template 0x00461860 \
    --name-prefix Helper_SetState \
    --mark src/game/state_setters.c
# → marks all 13 as matched in symbols.yaml
```

### Recipe

1. **Identify a template.** Find a small stub you understand.
2. **Find the cluster.** Run `batch_match.py --template VA` to
   count how many other stubs share the shape.
3. **Write a generator.** A short Python script that, for each
   cluster member, extracts the call/data targets and emits a
   `__declspec(naked) __asm` wrapper. Batch-emit them all into one
   `.c` file. Use the per-shape examples below.
4. **Compile & verify.** `cl.sh /O2 /Gy /c <file.c>` (the `/Gy`
   gives each function its own COMDAT `.text$<funcname>` section
   so each can be reloc-aware-diff'd independently).
5. **Mark them.** `batch_match.py --template VA --mark <file>`.
6. **Commit.** `git commit -m "Match N <pattern-name> stubs (X -> Y)"`.

### Recurring patterns we've already harvested

(Keep this list up to date — each entry below was an independent
batch in `git log`. Pattern bytes shown stripped of relocations.)

| Pattern | Bytes (mask) | Count matched | Source file |
|---|---|---:|---|
| Empty-stub (`ret` only) | `c3` | 16 | `src/audio/empty_stubs.c` |
| State-setter (mov+mov+ret) | `b8 ?? ?? ?? ?? a3 ?? ?? ?? ?? a3 ?? ?? ?? ?? c3` | 13 | `src/game/state_setters.c` |
| Global-getter (mov eax,[m]; ret) | `a1 ?? ?? ?? ?? c3` | 3 | `src/engine/getters.c` |
| Jump thunk (`jmp Other`) | `e9 ?? ?? ?? ??` | 33 | `src/engine/thunks.c` |
| Push-call-ret wrapper | `68 ?? ?? ?? ?? e8 ?? ?? ?? ?? 83 c4 04 c3` | 43 | `src/engine/wrappers.c` |
| Guarded sequel (call+test+jmp) | `e8 ?? ?? ?? ?? a1 6c 1e 54 00 85 c0 75 05 e9 ?? ?? ?? ?? c3` | 38 | `src/engine/guarded_sequels.c` |
| Set-and-jmp (mov+jmp) | `c7 05 ?? ?? ?? ?? ?? ?? ?? ?? e9 ?? ?? ?? ??` | 47 | `src/engine/setjmp_wrappers.c` |
| Scaled-base init+jmp | `b8 ?? ?? ?? ?? c1 e8 02 a3 ?? ?? ?? ?? e9 ?? ?? ?? ??` | 12 | `src/engine/scaled_init.c` |
| Guarded scaled-init | (33-byte combo of above) | 7 | `src/engine/guarded_scaled.c` |
| Matrix-stack push+call+pop | (75-byte fixed shape) | 11 | `src/engine/mstack_calls.c` |

Total batch-matched so far: **223** functions across 10 clusters.
Each cluster took ~30 minutes from "I've spotted a shape" to PR.

### Hand-rolling a new cluster

When `batch_match.py` finds a cluster, write a small Python
generator like:

```python
# tools/decomp/.local/gen_NEW_PATTERN.py
import struct, sys
sys.path.insert(0, 'tools/decomp')
from discover_functions import parse_symbols
# (boilerplate to load PE.text, parse symbols.yaml)

# 1. Pattern-detect:
matches = []
for r in rows:
    if r.get('status') != 'stub' or r.get('size', 0) == 0: continue
    body = fetch(...)
    while body and body[-1] == 0x90: body = body[:-1]
    if len(body) != EXPECTED_SIZE: continue
    if body[0:N] != EXPECTED_PREFIX: continue
    # ... extract per-instance fields
    matches.append((r['addr'], extracted_field, ...))

# 2. Emit a single .c with extern decls + naked __asm wrappers
print('#include "engine/scenegraph.h"')
print('extern void func_TARGET(void);')
print()
for src, tgt in matches:
    print(f'__declspec(naked) void Wrapper_{src:08x}(void) {{')
    print(f'    __asm jmp func_TARGET')
    print(f'}}')
```

Then verify (build, reloc-aware diff each instance, mark them
all).
