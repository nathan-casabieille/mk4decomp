# Native memory model - the decision (was mem_model.h's "open decision")

Settled 2026-06-11, grounded by two findings.

## Finding 1: identity-mapping is impossible (host constraint)
`mmap(MAP_FIXED, 0x400000, ...)` FAILS on macOS arm64 ("Cannot allocate memory" -
the low address space is reserved). So we CANNOT place the arena at the original
image base to make raw VAs work by identity. **=> Address translation is
mandatory.** Every fixed-VA / packed-ptr / global access must route through the
seam (MK4_VA / MK4_NODE). (A raw `*(uint*)0x542044` deref is wrong natively: that
address is unmapped; the data lives at `g_mk4Arena + (0x542044 - 0x400000)`.)

## Finding 2: the node pool is a fixed-VA array already in the arena
AllocateNode hands out slots from `g_nodeSlotsArea[]` (64 x 0xE8) - a STATIC array
at **VA 0x53e368** (pool 0x53e368..0x542000). The packed-ptr convention is
`packed_idx * 4 == node_VA`, and that VA is inside the loaded image range
(0x400000 + 12MB arena covers it). Therefore:

    MK4_NODE(idx) = g_mk4Arena + (idx*4 - 0x400000)

is **correct as-is** for the node pool (no special heap model needed) - the pool
is just part of the arena. The mem_model.h relocated branch is RIGHT; it was never
exercised because raw-`idx*4` twins bypass it.

## The forced model (consistent + correct)
1. **Arena at an arbitrary base** (current: malloc'd g_mk4Arena), loaded with the
   image's data/rdata/bss at (VA - 0x400000). Already done; covers the node pool.
2. **All packed-ptr access via MK4_NODE** - re-route the ~11 twins that still do
   raw `*(uint*)(idx*4)` (they read a raw low/unmapped addr under the arena).
3. **Globals via MK4_VA, NOT C variables.** The current C-variable mirror
   (native_globals.c) is INCONSISTENT: a datum read by name (`g_x`, a C var) and by
   VA (`*(uint*)MK4_VA(0x..)`) becomes two different locations. Fix: generate
   `#define g_x (*(T*)MK4_VA(T, VA))` for every fixed-VA global, and conditionalize
   the scattered local `extern <T> g_x;` decls under `#ifndef MK4_ARENA` (they are
   needed for matching, broken by the macro under the arena). Mechanical,
   corpus-wide, matching-safe (MK4_ARENA undefined in matching).
4. **VA->native trampoline for stored CODE pointers.** `(*g_x)()` and node fields
   used as fn-ptrs hold ORIGINAL code VAs (0x4xxxxx); natively those aren't code.
   Need a table mapping original-fn-VA -> native fn, and an indirect-call shim that
   looks up the target. (Data pointers are fine once #3 routes them through the
   arena.)

## Implementation progress (2026-06-11)
- **Step 1 DONE + validated** (commit 71a9b918): seam_route_nodes.py re-routed
  raw `*(T*)(idx*4[+off])` -> MK4_NODE / MK4_NODE_AT in 263 twins (1856 sites).
  Identity-preserving (verify_coexec sample VERIFIED), matching byte-identical.
- **Step 3 DONE + validated** (commit c43f5792): name_va_globals.py rewrote
  `*(T*)MK4_VA(T,0xVA)` -> the named C global in 290 twins (2551 sites), for
  uniquely-named + C-defined VAs. Kills the named-vs-VA dual-copy bug. Identity-
  preserving, matching byte-identical, native-full builds+runs.
- **Step 4 (code-ptr trampoline): pending, and END-TO-END GATED.** Unlike 1/3 it
  is NOT validatable in isolation: a VA->native-fn table + indirect-call shim only
  matters once the FSM's stored-fn-ptr dispatch actually runs, which needs the
  render backend + un-stubbed FSM (lots more conversion). Building it now would be
  untested scaffolding. Also: many fn-ptr stores in converted code are already
  `g_x = NativeFn` (native, works) - only raw-VA stores (data dispatch tables /
  asm) need the trampoline, so its scope is narrower than steps 1/3. Defer until a
  consumer path is live to validate against.

## Status / sequencing
- node-pool DATA model: SOLVED (fixed-VA array in arena; MK4_NODE correct).
- #2 (re-route raw idx*4) + #3 (globals via MK4_VA + conditional externs):
  mechanical corpus transforms; the real remaining memory-model work.
- #4 (code-ptr trampoline): needed before the FSM's indirect dispatch runs.
- Only after #2-#4 is native-full CORRECT (today it merely compiles+links+loops;
  deep node/indirect paths are unexercised because the FSM is stubbed).

This replaces the "*** the relocated branch is the next open decision ***" note in
include/portable/mem_model.h - the decision is: translation-mandatory, arena at
arbitrary base, everything through the seam, globals macro'd to MK4_VA.
