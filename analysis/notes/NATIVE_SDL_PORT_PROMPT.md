# MEGA PROMPT - MK4 native SDL port (path A: pure-C reimplementation)

> Paste everything below the line into a fresh Claude Code session opened at the
> repo root (`/Users/nathan_casab/Documents/MK4`). It is self-contained: it states
> the mission, the hard constraints, the architecture, the verification doctrine,
> the exact commands, and the concrete first task. Do not paraphrase it down - the
> precision is what keeps a fresh agent from breaking the byte-match build or
> shipping a behaviorally-wrong twin.

---

You are continuing a long-running reverse-engineering / decompilation project:
**MK4 = Mortal Kombat 4 (PC, 1998)**. Working dir: `/Users/nathan_casab/Documents/MK4`,
git repo, branch `main`, host = macOS Apple Silicon. Identity for all commits and
artifacts is **Nathan Casabieille** only.

## 0. Your mission this track

Build a **native, portable, no-Wine build that DISPLAYS the game**, by
**reimplementing the render path as real portable C** (this is "path A"), compiled
for SDL and validated by **running it**. This is the `NON_MATCHING` / `TARGET_SDL`
world - it is COMPLETELY SEPARATE from the byte-matching build and must never
perturb it.

This is NOT the x86-emulation path (that was prototyped in `tools/decomp/boot_emu.py`
and rejected in favor of real C). You write C that reproduces the engine's behavior,
not an emulator.

## 1. TWO HARD CONSTRAINTS - violating either is a failure

1. **Never break the byte-matching build.** The matching build rebuilds the original
   `MK4.EXE` byte-identical (MD5 `a3d2bf7f1222e5fcf8df93c7d8d8b5cf`). After ANY change
   that touches a file compiled into the matching build, you MUST run:
   ```
   make matching
   md5 -q build/MK4.EXE      # must print a3d2bf7f1222e5fcf8df93c7d8d8b5cf
   ```
   Per-OBJ diff tools can show `diffs=0` while the whole-EXE synth regresses
   (reloc-shuffle false negative) - so `make matching` + MD5 is the ONLY trustworthy
   gate. If the MD5 changes, you broke it: revert until it is green again.

2. **Never ship a behaviorally-wrong ("false") twin.** Verify-or-revert. A twin that
   "compiles and looks right" but diverges from the original is worse than no twin.
   Every reimplemented function is validated (co-exec and/or run-test, see section 5)
   before it is committed. If you cannot verify it, you keep the original naked code
   behind `#else` and move on.

## 2. How matching and non-matching coexist in ONE source tree

Each engine function that has been ported exists in TWO forms in the same `.c` file,
selected by the `NON_MATCHING` macro:

```c
#ifdef NON_MATCHING
    /* portable C twin - compiled into the SDL/native build, validated by behavior */
    void Foo(void) { ... real C ... }
#else
    /* original form - compiled by MSVC 5.0 into the byte-identical matching build */
    __declspec(naked) void Foo(void) { __asm { ... } }
#endif
```

- The **matching** build (`make matching`, MSVC 5.0 under Whisky/Wine) compiles the
  `#else` branch -> must stay byte-identical.
- The **native/SDL** build compiles the `NON_MATCHING` branch -> this is what you grow.
- So: you ADD C twins under `#ifdef NON_MATCHING`, you NEVER delete or edit the
  `#else` naked body. The naked body is the ground truth the matching build needs.

Build flags in play (see Makefile): `-DNON_MATCHING` (use the twin),
`-DMK4_ARENA` (relocated memory model), `-DTARGET_SDL`, `-DMK4_NATIVE_FULL`
(the broad-closure native-full link only).

## 3. Build targets and exact commands

```
make matching        # byte-match build (MSVC via Whisky). MUST stay a3d2bf7f...
md5 -q build/MK4.EXE  # the matching gate

make native          # clean SDL smoke build: src/platform/sdl/*.c + arena + host
                     # shims + weak engine stubs. Runs a frame. -DNON_MATCHING
                     # -DMK4_ARENA -DTARGET_SDL
make native-run      # build native + run it

make native-full     # broad-closure link: every natively-compilable engine TU in
                     # the MainLoopStep/GameLogicStep/DrawScene closure + the weak
                     # stub frontier (-DMK4_NATIVE_FULL). Measures port surface;
                     # may not run cleanly yet. Regenerate file list:
                     #   build/venv/bin/python tools/decomp/grow_native.py

make arena-test      # host-native test of the MK4_VA / MK4_NODE memory seam
make progress        # progress svg
```

Python venv with unicorn etc.: `build/venv/bin/python`.

## 4. Architecture you are building on

### 4a. Memory model (settled - do not relitigate)
`include/portable/mem_model.h` is the seam. MAP_FIXED at 0x400000 FAILS on macOS
arm64, so the native build uses a **translated** model: a 12 MB arena, node pool at
fixed VA `g_nodeSlotsArea @ 0x53e368`.
- `MK4_NODE(T, idx)` -> `(T*)(idx*4)` identity under the verifier / arena-translated
  in the native build.
- `MK4_VA(T, va)`, `MK4_NODE_AT(T, idx, off)`, `MK4_ResolveCode(va)` (identity macro
  by default; real VA->native-fn trampoline only under `-DMK4_NATIVE_FULL`).
- Native globals are consolidated in `src/platform/sdl/native_globals.c` (~2248
  globals + arena-seed); the VA->native-fn table is `native_codeptr_table.c`.

### 4b. The SDL backend
`src/platform/sdl/`:
- `main_sdl.c` - entry, calls `MK4_NativeGlobalsInit`, `MK4_CodePtrSelfTest`, drives
  `MK4_GameFrame` -> `MainLoopStep`, honors `MK4_MAX_FRAMES`.
- `engine_frame.c`, `engine_stubs.c` (weak blocker stubs), `engine_autostubs.c`
  (weak frontier stubs), `native_globals.c`, `native_codeptr_table.c`.
- Platform abstraction header: `include/platform/pal.h`.

### 4c. The render path you are reimplementing (mapped - this is the work)
`DrawScene`'s transitive call subtree is **bounded: 29 functions**. The convertible
core that produces pixels:

**8 SW rasterizer/blitter LEAVES** (0 callees -> NO register-arg-callee trap ->
directly C-convertible AND cleanly co-exec-verifiable):
| function | approx size | role |
|---|---|---|
| `ScanlineTexBlit` | 583 B | affine color-keyed 16bpp texture scanline blit |
| `ScanlineTexBlitPaletted` | 633 B | paletted variant |
| `ScanlineTexBlitAlpha` | 662 B | alpha-blended variant |
| `ScanlineTexBlitInterlaced` | 691 B | interlaced variant |
| `ScanlineTexBlitAdditive` | 798 B | additive-blend variant |
| `BlitBlend16bpp` | 752 B | 16bpp blend blit |
| `TexturedTriRasterize` | 1474 B | textured triangle rasterizer |
| `TexturedTriRasterizeShaded` | 1702 B | shaded textured triangle rasterizer |

Then up the tree:
- `FlushDrawQueue` (~16 callees) - the depth-sort + per-mode dispatch (do this AFTER
  its rasterizer leaves are converted, then co-exec at this root).
- `Renderer*_EndScene` (SW variant) - presents the framebuffer.
- **Stub** the 3dfx Glide leaves (`GlidePolyClip`, `GlideTriColorFlush`,
  `GlideTriBatchEmit`) and `R2_Init11` - force SW mode, no hardware path.
- `Helper_ChkStk` (= MSVC `__alloca_probe`) and `DoubleToInt64` (= `__ftol`) are CRT
  - use the C equivalent / compiler builtin in the twin; do not transcribe.

Re-derive the subtree any time with this one-liner pattern (BFS over `call NAME` +
C-call edges from `DrawScene`); the project has `tools/decomp/symindex.py` (writes
`/tmp/symidx.json`, name->files) to seed it.

## 5. The verification doctrine - THIS is what makes path A safe

The earlier fear that "the render path can't be converted" was WRONG. That trap
(`feedback_tail_jmp_register_args_non_coaxable`) is about converting a SINGLE
function whose callee is still original x86: the engine passes implicit register
args (eax/ecx/edx) the C twin drops. The render leaves have NO callees, so the trap
does not apply to them. For higher nodes (`FlushDrawQueue`), the trap dissolves when
you convert the WHOLE subtree: once caller AND callees are all C, the calls are
C-ABI-consistent, and you verify at the subtree ROOT.

So the rule is: **convert bottom-up, verify at subtree roots.**

### 5a. Seeded co-exec (rigorous, per leaf and per subtree root)
`tools/decomp/verify_coexec.py` runs a twin as 32-bit code in unicorn and compares
its memory writes against the original bytes running the same way. Invoke with twin
names:
```
build/venv/bin/python tools/decomp/verify_coexec.py ScanlineTexBlit
```
Knobs (env): `MK4_COEXEC_CAP` (instruction cap, default 2000000),
`MK4_COEXEC_WALL_US` (wall-clock timeout us, default 3000000). The verifier models
globals as 32-bit unsigned; `MK4_NODE`/`MK4_ResolveCode` are identity under it.

CRITICAL - an at-rest "VERIFIED / 0 writes / [capped]" is often a FALSE POSITIVE:
the meaningful path (the actual pixel loop) was never entered because the inputs
were zero. You MUST **seed** the relevant globals (renderer state, a small texture
buffer, a dest buffer, non-degenerate width/height/coords) so the inner loop runs,
THEN compare the blitted pixels. A rasterizer that "verifies" writing nothing has
proven nothing. (See `feedback_seeded_coexec_node_walk_template`.) Signed loop
counters need an `(int)` cast because the verifier models globals as unsigned.

### 5b. Run-validation (end-to-end, the path A acceptance test)
Once a subtree is C, `make native-full` (or `native`) and run it; the acceptance
criterion for the milestone is a correct rendered frame in the SDL window (visually
and/or by dumping the framebuffer and comparing to a Wine-rendered reference frame).

### 5c. Verify-or-revert
If a twin fails seeded co-exec and you cannot fix it, `git checkout` the file (the
`#else` naked body must remain intact) and add the function name to
`config/twin_mismatch_blocklist.txt` with a one-line reason. Never commit a twin you
could not verify.

## 6. The work loop (do this, repeat)

For each rasterizer leaf, bottom-up:
1. Read the naked `__asm` body (find it: `grep -rn "naked.*<Name>" src/engine/*.c`;
   prefer the dedicated file, e.g. `src/engine/scanline_tex_blit.c`).
2. Understand it: viewport clipping -> 16.16 fixed-point texcoord gradients (`idiv`)
   -> per-row + per-pixel stepping. Watch the subtle bits: `rol ecx,0x10` /
   `adc dl,cl` is carry-based fixed-point texcoord stepping; `mov ax,[edx*2]` +
   `test ax,ax; je` is color-key-0 transparency; writes are 16bpp `word`.
3. Write the C twin under `#ifdef NON_MATCHING`, leaving the `#else` naked body
   UNCHANGED. Model the fixed-point exactly (use `unsigned` for the fractional
   accumulators so the carry math matches; the pixel write is `(unsigned short)`).
4. Seed + co-exec verify (section 5a). Iterate until the blitted dest buffer matches
   byte-for-byte. If unfixable -> revert + blocklist.
5. `make matching` + MD5 gate (the `#else` body is what it compiles, so this should
   stay green - confirm it does).
6. Commit (see section 7). One rasterizer per commit.

Then `FlushDrawQueue` (co-exec at its root once its leaves are C), then the SW
`EndScene`, then wire its framebuffer to SDL (`MK4_PalBlit` / the pal.h present
path), then `make native-full` and chase the first real frame.

## 7. Project hygiene (hard rules - from accumulated memory)

- **Git**: commit only when a unit is verified. NO "Co-Authored-By: Claude" and NO
  "Generated with Claude Code" blocks. Commits are signed by the user's SSH key.
  Author = Nathan Casabieille. Do NOT push unless asked.
- **Identity**: never write "Ava Cohen" / any harness email into any file, commit,
  or artifact. Nathan Casabieille only.
- **ASCII only** in files/commits/comments: hyphen `-`, never em/en-dash. No
  `#else`/`#endif`/`#ifdef` tokens inside twin COMMENTS (the verifier's twin
  extractor does a naive `s.find('#else')` and grabs the comment -> false "SKIP
  no-twin"; say "naked branch" instead).
- **No untracked background process fleets.** Never launch `( cmd ) &` fans - they
  orphan to launchd (PPID=1) and become unkillable, pegging cores. Use a single
  `run_in_background` Bash call or bounded foreground subsets. `verify_coexec` has a
  wall-clock timeout for exactly this reason - keep it.
- Header edits are dangerous to the matching build: adding a struct/typedef to a
  header included by a pure-C switch TU shifts MSVC `$L` labels and the Makefile has
  no header deps (force-rebuild the `.c` to actually re-test). Prefer keeping new
  structs in native-only headers. Always `make matching` + MD5 after header touches.

## 8. Definition of done (milestones, in order)

1. All 8 SW rasterizer leaves converted to C and seeded-co-exec-verified; matching
   still `a3d2bf7f...`.
2. `FlushDrawQueue` + SW `EndScene` converted; co-exec-verified at the root.
3. Framebuffer wired to SDL; `make native-full` runs and presents a frame.
4. **First milestone visible**: a real DrawScene frame rendered in an SDL window,
   native, no Wine - pixel-compared to a Wine-rendered reference.
5. Then input (`Input_GetAsyncKey`/`Input_PollJoystick` -> SDL), timer, file I/O
   (`FILESYS.DAT`), audio - to reach an interactive frame.

## 9. First concrete task

Convert **`ScanlineTexBlit`** (`src/engine/scanline_tex_blit.c`, the dedicated copy
near line 134; 583 B; the smallest leaf). Read its full `__asm`, write the C twin
under `#ifdef NON_MATCHING` leaving the `#else` naked body intact, seed a small
texture + dest buffer + the renderer-state globals it reads (`g_viewportX/Y/W/H`,
the `g_dispatchSave*` edge/gradient/texcoord state), co-exec until the blit matches
byte-for-byte, confirm `make matching` is still `a3d2bf7f...`, and commit. Then move
to `ScanlineTexBlitPaletted`. Do not stop after one - chain through the 8 leaves,
verifying each, then `FlushDrawQueue`.

Start now. Re-derive any fact you are unsure of from the repo rather than assuming.
