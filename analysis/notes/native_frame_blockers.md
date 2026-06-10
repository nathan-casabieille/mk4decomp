# Native frame: the path from `MainLoopStep` to a runnable `MK4_GameFrame`

`MainLoopStep` (src/boot/main_loop.c) IS the per-frame entry and is clean
portable C:

```
BeginFrame(1); GameLogicStep(); DrawScene(); PresentFrame();
... QueryMicroTimer() pacing loop, Sleep(...) ...
```

So `MK4_GameFrame` (the SDL main-loop hook) should call `MainLoopStep`.

## Closure status (source-based call graph)

`MainLoopStep`'s transitive closure = **80 functions: 66 portable**
(47 pure-C + 19 twins) and **14 blockers** that must be resolved before the
native build links a real frame. The 14, bucketed by what each needs:

| Bucket | Functions | How to resolve |
|---|---|---|
| **INPUT -> PAL** | `Input_PollJoystick`, `Input_PollPlayerKeyboard` | route to `MK4_PalKeyDown` / `MK4_PalMouse` |
| **VIDEO -> PAL** | `FlushDrawQueue`, `Renderer5_BeginFrame_SW_FS_Hi` | route the SW framebuffer to `MK4_PalBlit555`; begin/present via PAL |
| **CRT / FILE -> host** | `ESF_Open`, `ESF_ReadData`, `Helper_Sprintf` | host stdio / `vsnprintf` (asset I/O over the real filesystem) |
| **MEMORY / node pool** | `AllocateNode`, `Mem_Free`, `CountdownClampWalk` | real allocators backed by the arena / host heap; node-pool init |
| **MATH (just convert)** | `Mul10Tail` | convert the 16.16 fixmul to portable C + verify (easy) |
| **GAME-FSM (hard cluster)** | `GameStateMachine`, `Helper_TickAlt`, `TickAllEntities` | the FSM cluster - per-function reimplementation; `TickAllEntities` is already a verifier-confirmed MISMATCH (blocklisted) |

## Read of it

~11 of 14 are tractable now: the PAL ones are exactly what the SDL backend
exists for; the CRT/file/memory ones are host-backed; `Mul10Tail` is a quick
verifiable conversion. The remaining 3 are the hard FSM cluster (and one is
already known-wrong), so a *fully* faithful frame is gated on that cluster.

A **partial** runnable frame is reachable sooner: implement the PAL/CRT/
memory blockers, stub the 3 FSM blockers as no-ops, and `MainLoopStep` links
+ runs - showing real `DrawScene`/`PresentFrame` output (the converted
renderer path) even before the game FSM ticks. That is the recommended first
"real frame" milestone for the native port.

## Empirical native-compile findings (2026-06-10)

Compiled `MainLoopStep`'s portable closure (54 source files) under the
**64-bit host clang** with `-DNON_MATCHING -DMK4_ARENA -DTARGET_SDL`:

- **The converted code is seam-clean / 64-bit-native-feasible.** `main_loop.c`
  itself compiles with zero raw-VA derefs (just a `Sleep` shim). This is the
  big de-risking result: 64-bit native (and therefore WASM) is viable for the
  converted corpus, not blocked on a pervasive raw-pointer rewrite.
- Two central enablers landed (matching byte-identical throughout):
  1. `ghidra_types.h` now includes `mem_model.h` (the injector added the
     former but not the seam header -> `MK4_NODE_AT`/`MK4_VA` looked like
     undeclared functions standalone).
  2. `types.h` neutralizes `__stdcall`/`__declspec`/`__cdecl`/`__fastcall`
     under `!_WIN32`.
- Closure compile status: **26 / 54** files compile under permissive native
  flags (`-Wno-int-conversion -Wno-implicit-function-declaration
  -Wno-incompatible-pointer-types -Wno-int-to-pointer-cast` - the int<->ptr
  ones are just the seam's pointer-as-int model). The remaining ~28 fail on a
  finite per-file grind: missing externs (globals/functions not yet in any
  header), Ghidra syntax artifacts, FPU inline (`fpu_sqrt_mul.c`), and Win32
  headers in platform-glue files (`<mmsystem.h>` in `timer.c` -> PAL).
- Real host/PAL shims the closure needs (small list): `Sleep`, `timeGetTime`,
  `mciSendCommandA`, `__alldiv`, `__allshl`.

## Named-global memory model (the project's "open decision") - explored

The deeper native blocker behind many "undeclared identifier" failures:
named fixed-VA globals (`g_dualC`, `g_cj_*`, ...) are NOT C variables - they
are offsets into the `.data`/`.rdata` blobs, pinned at their VAs by the linker
for matching, referenced by symbol. ~2500 of them have NO C `extern` decl, so
the portable/native build cannot resolve them.

Right architecture (matches how verify_coexec already models globals, and what
WASM needs): under `MK4_ARENA`, `#define` each such global as its arena
accessor (`MK4_VA`), since the arena already holds the `.data`/`.rdata` bytes
at their VAs - reads/writes land at the original VA with the original value, no
separate storage, no init step.

Prototype: `tools/decomp/gen_arena_globals.py` generates such a header (2508
globals). Wired it under `MK4_ARENA` (gated off for the verifier via
`MK4_COEXEC_GATE`). Result: matching byte-identical and the verifier still
passes, BUT it was a NET REGRESSION on the frame closure (26 -> 24): globals
with MIXED usage (`g = v` AND `g[i]`/`*g`) cannot take one macro form, so the
pointer form broke `g = v` ("expression is not assignable"); and the closure
files that need these globals have OTHER blockers, so 0 net-fixed there.
REVERTED the wiring (kept the generator). Lesson: this needs real per-global
type precision (scalar lvalue is the safe default; pointer/array only when the
global is NEVER a direct scalar lvalue), and it pays off corpus-wide, not on
this particular closure. A deliberate next sub-project, not a broad auto-gen.

## Suggested order

1. `Mul10Tail` (convert + verify_coexec) - removes one blocker cleanly.
2. PAL input + video routing (`Input_Poll*`, `FlushDrawQueue`,
   `Renderer5_BeginFrame_*`) -> the SDL backend.
3. host CRT/file (`Helper_Sprintf`, `ESF_*`) + memory (`AllocateNode`,
   `Mem_Free`, `CountdownClampWalk`).
4. wire `MK4_GameFrame = MainLoopStep`, FSM blockers stubbed -> first frame.
5. FSM cluster (`GameStateMachine`, `Helper_TickAlt`, `TickAllEntities`) for
   a faithful tick.
