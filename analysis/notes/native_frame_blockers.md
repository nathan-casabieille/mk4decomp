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

## Render/FSM conversion is blocked on VERIFIABILITY, not transcription (2026-06-10)

Tried to hand-convert `Helper_TickInner` (a scene-graph sibling-walk: walks
`g_siblingTable` from `g_currentNodeIdx`, calling `g_walkCallback` per node).
Transcription from the @addr asm is straightforward (the named globals are
ground truth; Ghidra's `0x542044` IS `g_currentNodeIdx`, they agree). BUT it
is NOT co-exec-verifiable: in the verifier's garbage initial state the walk
indexes `g_siblingTable[<garbage idx>]` and calls through a garbage
`g_walkCallback`, driving EIP into non-code -> `UC_ERR_INSN_INVALID` in the
ORIGINAL run, before any diff. Seeding `g_walkCallback` to a `ret` stub did
not help (the walk itself goes wild on garbage node indices).

So an unverified hand-transcription is all we could ship - and a hand-written
loop with array indexing + FSM control flow is exactly where a subtle bug
hides. Held the line: reverted it (matching stayed byte-identical; also caught
+ fixed a missing `#endif` that briefly broke matching).

THE REAL ENABLER for the render/FSM cluster: a verifier that runs on **seeded
realistic state** - a valid node pool / sibling chain + a benign callback - so
these functions execute deterministically and orig-vs-twin can be diffed.
Without it, this cluster is transcribe-but-cannot-verify, and the "no false"
rule means it does not ship. This is the highest-leverage next investment for
both the native frame and finishing the decomp.

## Seeded verifier works - and immediately caught a wrong-VA data bug (2026-06-10)

Built seeded co-exec verification (seed globals + a `ret` callback stub so a
node-walk runs deterministically). Two `build_twin_blob` fixes were needed and
made it work: (1) an array-base global (`g[i]`) is single-indirect
`((uint*)VA)` not double `(*(uint**)VA)` - the double form on a base-0 table
(`g_siblingTable`, VA 0) is a null deref gcc -O2 turns into `ud2`; (2) compile
twins with `-fno-delete-null-pointer-checks` so fixed-VA / base-0 accesses are
not treated as UB.

With that, `Helper_TickInner`'s empty-walk path VERIFIED - but the loop path
MISMATCHed, and the trace showed why: **the original writes `g_currentNodeIdx`
at 0x542044, but extras_map maps `g_currentNodeIdx -> 0x54205c`** (a 3-way
collision with `g_fightGroupHead` / `g_cj_0054205c`; 0x542044 is unnamed). The
function's first instruction is literally `mov ecx,[0x00542044]`. So the seam
(extras_map / gl_by_va) routes `g_currentNodeIdx` to the WRONG address, and any
portable twin referencing it via the named symbol is wrong - the Ghidra C's raw
`0x542044` was actually correct. (The matching build is unaffected: it resolves
the asm symbol to the real VA independently.)

IMPLICATION: a class of portable twins that reference `g_currentNodeIdx` (and
possibly other mis-mapped/colliding globals) are silently wrong under the seam.
The verifier now CATCHES these (this is exactly what it is for). Next: audit
extras_map for VA collisions / wrong VAs against the matching symbol
resolution, fix `g_currentNodeIdx` -> 0x542044 (carefully, given the 0x54205c
collision), then the render/FSM twins can be transcribed AND verified.

## extras_map VA audit + g_currentNodeIdx fix (2026-06-10, DONE)

Fixed `g_currentNodeIdx`: 0x54205c -> **0x542044** in config/extras_map.yaml.

Safety proof (matching unaffected): forced a full `synthesize.py` re-link after
the edit -> **BYTE-IDENTICAL, Mismatches: 0** (MD5 a3d2bf7f...). The matching
build carries every g_currentNodeIdx site via per-site `reloc_sites.yaml`
overrides (19 sites -> 0x542044, 3 -> 0x54205c), so the extras_map name->VA is
only a fallback there and was free to correct. The portable pure-C functions
that reference `g_currentNodeIdx` use the C *variable* (data.c/stubs.c), not the
seam VA, so they're unaffected too. The fix's real effect is on (1) the co-exec
verifier's global routing and (2) future ghidra_postprocess VA->name naming.

Corroboration the new VA is right: `g_xformEntityIdx` is at **0x542048** (per
extras_map and feedback_alias_address_check), i.e. exactly 0x542044 + 4. The two
node-walk globals are contiguous, and Helper_TickInner's first instruction is
`mov ecx,[0x542044]`. Every portable-C reference uses `g_currentNodeIdx * 4`
(packed node ptr); `g_fightGroupHead` (the real owner of 0x54205c) is used
separately in the same statements (e.g. boot/func.c:26). So 0x542044 =
node-index, 0x54205c = fight-group-head, and they were merged in error.

Broader audit result: 164 high-VA (>=0x401000) addresses carry >1 name; 114 have
>=2 non-self-encoding names. These are OVERWHELMINGLY benign aliases (one VA,
several analysis-pass names: WndProc/WndProc@16, _imp__Sleep@4/g_iat_Sleep, the
renderer/audio COM-struct-field families). Benign because name->VA stays
unambiguous per name. The dangerous class is the inverse - ONE name -> WRONG VA
(what g_currentNodeIdx was) - and the corpus-wide catch mechanism for THAT is the
behavioral co-exec verifier (a wrong VA shows up as a MISMATCH), not static
alias-listing. So the audit's standing conclusion: no further blind VA edits;
treat verify_coexec MISMATCHes as the wrong-VA tripwire.

## Suggested order

1. `Mul10Tail` (convert + verify_coexec) - removes one blocker cleanly.
2. PAL input + video routing (`Input_Poll*`, `FlushDrawQueue`,
   `Renderer5_BeginFrame_*`) -> the SDL backend.
3. host CRT/file (`Helper_Sprintf`, `ESF_*`) + memory (`AllocateNode`,
   `Mem_Free`, `CountdownClampWalk`).
4. wire `MK4_GameFrame = MainLoopStep`, FSM blockers stubbed -> first frame.
5. FSM cluster (`GameStateMachine`, `Helper_TickAlt`, `TickAllEntities`) for
   a faithful tick.
