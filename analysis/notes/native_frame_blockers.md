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

## Suggested order

1. `Mul10Tail` (convert + verify_coexec) - removes one blocker cleanly.
2. PAL input + video routing (`Input_Poll*`, `FlushDrawQueue`,
   `Renderer5_BeginFrame_*`) -> the SDL backend.
3. host CRT/file (`Helper_Sprintf`, `ESF_*`) + memory (`AllocateNode`,
   `Mem_Free`, `CountdownClampWalk`).
4. wire `MK4_GameFrame = MainLoopStep`, FSM blockers stubbed -> first frame.
5. FSM cluster (`GameStateMachine`, `Helper_TickAlt`, `TickAllEntities`) for
   a faithful tick.
