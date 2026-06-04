# Plan: reach 100% portable C (NON_MATCHING)

Goal: every one of the 2914 functions has a behavior-correct portable-C
body, so the engine builds and runs without x86 `__asm` (native first,
then WASM). The matching build stays the byte-identical oracle throughout.

Unlike the matching build (pure-C ceiling ~49%, a hard MSVC-codegen wall),
**portable C has no ceiling** - we only need behavior equivalence. So 100%
is a question of effort, not feasibility.

Status at plan start: ~1844/2914 (~63%) have a portable-C form (1423
pure-C + 421 twins). 18 twins runtime-verified. ~1070 still asm-only.

## Strategy: runtime-first

The single highest-leverage move is a **32-bit fixed-VA runtime**, because
it unblocks everything else:
- it turns the ~400 "compiles" twins into "verifiable" (the diff harness
  can run them and catch wrong ones - we already found 7/20 wrong);
- it is the native-PC port target;
- raw 32-bit pointer derefs (which Ghidra emits and which segfault on a
  64-bit host) just work when the arena sits at the original VAs in a
  32-bit process.

(WASM is a later, separate axis: its linear memory starts at 0, so it
additionally needs ALL pointer access routed through the MK4 seam. Native
32-bit does not, so do it first.)

## Phases

### Phase A - 32-bit fixed-VA verification runtime  [BLOCKED - see note]

**Attempt finding (2026-06-04):** Wine64 (Whisky) runs 32-bit mingw PEs,
but `VirtualAlloc((void*)0x00400000, ...)` fails with err=487
(ERROR_INVALID_ADDRESS) even with the harness image based at 0x20000000 -
Wine reserves the low address range, so the arena cannot sit at the
original VAs under this Wine. => the fixed-VA-under-Wine path is out.
Viable alternative: **Unicorn co-execution** - compile each twin to a
32-bit blob and run it INSIDE Unicorn (same emulator, arena mapped at
0x400000 where we control the address space, no OS reservation). This is
a real sub-build (extract .text, place g_mk4Arena, run) but it is the way
to verify the non-seam-clean twins without an OS 32-bit runtime.

Original intent below:
- Build the verify harness as 32-bit (i686-w64-mingw32) run under Wine
  (the matching bottle already exists), with the arena VirtualAlloc'd at
  its real base 0x400000 and the harness image based elsewhere
  (e.g. /BASE:0x10000000) to free that range.
- Then raw derefs resolve; re-run the diff over all leaf twins, then
  extend to non-leaf via co-execution (twin's callees executed from the
  same arena). Target: verify the bulk of the 421 twins; revert/fix any
  that MISMATCH.

### Phase B - mechanical mass conversion (pipeline-driven)
- Extend the injector beyond void(void): recover signatures from Ghidra
  (`int Foo(int,int)`), inject with the recovered prototype, and update
  the header/extern + callers in lockstep (callers are themselves being
  converted, so reconcile by address as we go).
- Add the VA->C-function dispatch table so `code` fn-ptr calls resolve.
- Express CONCAT/SUBxx as bit ops; route remaining DAT_ via the seam.
- Each batch: compile gate + 32-bit diff verify + `make matching` stays
  MD5-identical.

### Phase C - hard cluster (reimplementation, not transcription)
- FSM continuations (`LAB_`): represent `node->resume = &label` as a
  state-id or function-pointer continuation, not a raw code address.
- CRT / SEH / __chkstk / self-installing code: reimplement intent
  (chkstk -> no-op, SEH -> setjmp/longjmp).
- Platform (Glide / DirectSound / Win32 IAT): implement behind the PAL
  (src/platform/<backend>/), native SDL backend first.

### Phase D - WASM
- Route 100% of pointer access through the seam (no raw 32-bit derefs),
  emscripten target, arena as a preloaded asset, WebGL/WebAudio PAL.

## Invariants (every step)
- `make matching` stays MD5-identical (a3d2bf7f) - verify by exit code +
  fresh exe, never a stale MD5.
- Reconcile Ghidra symbols by ADDRESS, never trust Ghidra names.
- A twin ships only if it (a) compiles and (b) passes the diff harness
  once the runtime exists; mark verified ones.

## Definition of done
2914/2914 functions compile in portable C AND pass differential
verification AND the native build runs the game; then WASM as Phase D.
