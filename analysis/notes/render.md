# Render subsystem

Per-subsystem deep dive for MK4's render pipeline. Covers the
5-renderer dispatch ladder, the per-frame queue + sort, mesh
submission, and where the byte-match constraints sit.

For the scenegraph traversal that feeds this pipeline see
[scenegraph.md](scenegraph.md). For the asm-verified `DrawMeshBlock`
and `SubmitDrawEntry` work see [architecture.md](architecture.md)
sections "Draw queue layout" and "Per-block data layout".


## Pipeline at a glance

MK4 has a **queue-then-flush** renderer with a counting-sort z-buckets:

```
GameLogicStep
  └── (scenegraph walk -> DrawMeshBlock per leaf node)
      └── SubmitDrawEntry(28-byte entry) -> g_drawQueue

MainLoopStep
  ├── BeginFrame(1)           -> Renderer<mode>_BeginFrame_*
  ├── DrawScene
  │     ├── FlushDrawQueue    -> histogram + dispatch per-entry
  │     │                       to Renderer1 (Glide) / Renderer2 (D3D)
  │     │                       or SW rasterizer
  │     └── Renderer<mode>_EndScene_*
  └── PresentFrame            -> Renderer<mode>_PresentFrame
```

There are **five renderer modes** that can drive the output:

| Mode | Constant                       | Backend                              | Init function                       |
|------|--------------------------------|--------------------------------------|-------------------------------------|
| 1    | `RENDERER_MODE_GLIDE`          | 3dfx Glide (dynamic LoadLibrary)     | `Renderer1_Init_Glide`  `0x004b49a0`|
| 2    | `RENDERER_MODE_D3D`            | Direct3D (DDraw + Direct3D2)         | `Renderer2_Init_D3D`    `0x004ad6a0`|
| 3    | `RENDERER_MODE_SW_FS`          | DirectDraw fullscreen 320x240        | `Renderer3_Init_SW_FS`  `0x004af8c0`|
| 4    | `RENDERER_MODE_SW_WINDOWED`    | DirectDraw windowed 640x480 (default)| (no init - always available)        |
| 5    | `RENDERER_MODE_SW_FS_HI`       | DirectDraw fullscreen hi-res         | `Renderer5_Init_SW_FS_Hi` `0x004b00f0`|

Each mode has its own `BeginFrame`, `EndScene`, and `PresentFrame`
entry point. The dispatchers in `BeginFrame` / `DrawScene` /
`PresentFrame` ([src/engine/render.c](../../src/engine/render.c),
[src/engine/draw_scene.c](../../src/engine/draw_scene.c)) are pure C
switch-on-mode functions.

DLL surface (from `config/imports.yaml`):

- **`DDRAW.dll`** : `DirectDrawCreate`, `DirectDrawEnumerateA`
- **`KERNEL32.dll`** : `LoadLibraryA` + `GetProcAddress`
  (used to bind `glide2x.dll` entry points into `g_glideFnTable`
  at runtime - Glide is NOT in the IAT)
- **No `D3DIM.DLL`, no `D3D9.dll`** : the Direct3D mode is
  Direct3D 2 (DDraw-era), obtained via `QueryInterface(IID_IDirect3D)`
  on the DDraw object. The `D3DObj` vtable layout in
  [include/engine/render.h](../../include/engine/render.h) confirms
  slots 11 (= `IDirect3DDevice2::EndScene`) and 29 (`DrawPrimitive`)
  are the only ones called.

USER32 / GDI32 are only used for window plumbing (CreateWindowExA,
GetDC, SetWindowTextA, etc.) - none of the actual rasterizing.


## Init ladder - TryInitRenderer (0x004b3ed0)

`AppInit` ([src/boot/app_init.c:47](../../src/boot/app_init.c#L47))
walks through the modes in order **1 -> 2 -> 3 -> 5**, calling
`TryInitRenderer()` between each step. If a mode fails to init, the
ladder downgrades to the next one. Mode 4 (`SW_WINDOWED`) is the
fallback - it always succeeds on a Win32 host.

```c
g_pumpFlagE4 = 1; g_pumpFlagE0 = 1; g_pumpFlagDC = 1; g_pumpFlagD8 = 1;
Helper_GSM_PlayMusic(1);   // try Glide
if (TryInitRenderer() < 0) {
    g_pumpFlagD8 = 0;
    Helper_GSM_PlayMusic(2);   // try D3D
    if (TryInitRenderer() < 0) {
        g_pumpFlagDC = 0;
        Helper_GSM_PlayMusic(3);   // try SW_FS
        if (TryInitRenderer() < 0) {
            g_pumpFlagE0 = 0;
            Helper_GSM_PlayMusic(5);   // try SW_FS_Hi
            if (TryInitRenderer() < 0) {
                g_pumpFlagE4 = 0;       // give up - mode 4 only
            }
        }
    }
}
```

Mode 4 is implicit: `g_clampedRendererMode` is set to 4 in `Gfx_Init`
and the windowed-software path is wired up by `Helper_GfxInit2`
before this ladder runs. The four `g_pumpFlag*` globals are
"capability bits" the rest of the engine uses to decide whether to
attempt mode-specific features (e.g. texture filtering, FSAA).

`Helper_GSM_PlayMusic` is misleadingly named - it's actually
`SetRendererMode` at `0x004b40a0`, validating and storing the
requested mode into `g_clampedRendererMode`. Out-of-range modes
clamp to 4. The name comes from the function being reused as a
state-machine helper for the music selector elsewhere.


## Per-mode init details

### Renderer 1 (Glide) - LoadLibrary-based

`Renderer1_Init_Glide` ([src/engine/renderer1_init_glide.c](../../src/engine/renderer1_init_glide.c)):

1. Fill `g_glideTable1[256]` with floats 0.0..255.0 (linear ramp).
2. Fill `g_glideTable3[32]` with a bit-pattern float table via the
   `and dl, 1; neg dl; sbb edx, edx; and edx, 7; or esi, edx` idiom.
3. Open Glide context via `g_glideFnTable[N]` indirect calls -
   `grSstQueryHardware` to enumerate adapters, then `grSstSelect`,
   `grSstWinOpen`, `grRenderBuffer`, `grColorMask`, `grAlphaCombine`.
4. On any failure, calls `Helper_GlideError` (which probably shows a
   message box) and returns 0.

`g_glideFnTable` (`0x007b0000`) is a runtime-populated function-
pointer table - `glide2x.dll` is dynamically loaded via
`LoadLibraryA` + `GetProcAddress` (NOT in the IAT). This is how MK4
ships a Glide build that also runs on machines without 3dfx hardware:
if `glide2x.dll` fails to load, mode 1 silently fails and the ladder
falls through to mode 2.

Still naked (`Renderer1_Init_Glide`): pure-C conversion got to 592 vs
618 bytes but MSVC SP3 caches the zero constant in `EBX`, emitting
27x `push ebx` (1 byte) instead of the orig's `push 0` (2 bytes).
The pattern is non-coaxable from C source.

### Renderer 2 (D3D) - DDraw + Direct3D2

`Renderer2_Init_D3D` ([src/engine/renderer2_init.c](../../src/engine/renderer2_init.c))
chains 11 sub-init helpers (`R2_Init1` through `R2_Init11`). The path is:

```
DDraw create -> IDirectDraw::QueryInterface(IID_IDirect3D2)
-> create rendering surface -> create back buffer
-> create Z-buffer -> EnumDevices -> create IDirect3DDevice2
-> set viewport -> set render state -> create vertex batch
```

The 256-entry float LUT (`g_renderer2_lutTable`) at `0x00544308` is
filled before any DDraw call - it's a precomputed perspective table
the D3D batch submitter uses to avoid per-vertex divides.

The D3D vtable methods MK4 calls (from
[include/engine/render.h](../../include/engine/render.h)):

- **Slot 11** (`offset 0x2c`): `IDirect3DDevice2::EndScene` - called
  by `Renderer2_EndScene_D3D` once per frame.
- **Slot 29** (`offset 0x74`): `IDirect3DDevice2::DrawPrimitive` -
  called by `Renderer2_FlushBatch_D3D` to submit each batched primitive.

`g_renderer2_batchCount` (`0x0058c7f0`) tracks how many tris are queued;
`g_renderer2_vertexBatch` (`0x00544718`) holds the actual vertex data.

### Renderers 3 / 5 (Software fullscreen) - pure DDraw

Both are pure-C now ([src/engine/renderer3_init.c](../../src/engine/renderer3_init.c),
renderer5_init.c). Pattern:

```c
do {
    if (DDraw3_Create() == 0) break;
    DDraw3_PostCreate();
    if (DDraw3_CreateSurface(1) == 0) break;
    g_renderer3_surface_active = 1;
    if (DDraw3_SetCooperativeLevel() == 0) break;
    DDraw3_GetSurface();
    /* ok */
    return 1;
} while (0);
DDraw3_Cleanup();
return 0;
```

The `do { ... } while (0)` + `break` form is the only C shape that
matches the original's "fail-tail before success-tail" block
ordering on MSVC SP3.

The DDraw surface vtable used by both 3 and 5 has its **slot 32**
(offset `0x80`) called per `EndScene` - that's `IDirectDrawSurface::Flip`
in DDraw1. Modes 3 and 5 both target 320x240 (the "hi" in mode 5
refers to color depth, not resolution).

### Renderer 4 (Software windowed) - GDI/DDraw blit

`Renderer4_PresentFrame` is pure C
([src/engine/renderer4_present_frame.c](../../src/engine/renderer4_present_frame.c)).
The 12-arg IAT call after `EndScene` is `IDirectDrawSurface::Blt(...)`
with source rect (0,0,320,240) and dest at the cached window-client
origin in `g_dispatchSave1621/1624`. Mode 4 uses a 640x480 viewport.


## Per-frame loop

`MainLoopStep` ([src/engine/main_loop_step.c](../../src/engine/main_loop_step.c))
calls `BeginFrame(1)` -> `GameLogicStep()` -> `DrawScene()` ->
`PresentFrame()` once per tick (with a 60 Hz throttle and catch-up
loop).

### BeginFrame (0x004b4200)

Mode-switch dispatcher with a uniform viewport-set tail:

| Mode | Begin handler                       | Viewport set            |
|------|-------------------------------------|-------------------------|
| 1    | `Renderer1_BeginFrame_Glide(flag)`  | (zero w,h - no-op)      |
| 2    | `Renderer2_BeginFrame_D3D(flag)`    | (zero w,h - no-op)      |
| 3    | `Renderer3_BeginFrame_SW_FS(...)`   | `SetViewport(..,320,240)` |
| 4    | `Renderer4_BeginFrame_SW_Win(...)`  | `SetViewport(..,640,480)` |
| 5    | `Renderer5_BeginFrame_SW_FS_Hi(...)`| `SetViewport(..,320,240)` |

Modes 3/4/5 receive output args for the computed top-left rect coords
(modes 1/2 don't - they own their own viewport state via Glide/D3D).
`SetViewport` then stuffs `g_viewportX/Y/W/H` for the rest of the frame.

### DrawScene (0x004b42e0)

Pure C:

```c
void DrawScene(void) {
    g_drawSceneTimeMs -= timeGetTime();
    FlushDrawQueue();
    switch (g_clampedRendererMode) {
        case 1: Renderer1_EndScene_Glide();      break;
        case 2: Renderer2_EndScene_D3D();        break;
        case 3: Renderer3_EndScene_SW_FS();      break;
        case 5: Renderer5_EndScene_SW_FS_Hi();   break;
        case 4: Renderer4_EndScene_SW_Win();     break;
    }
    g_drawSceneTimeMs += timeGetTime();
}
```

`g_drawSceneTimeMs` (`0x007afa00`) is the cumulative ms-spent counter
used by the throttle in `MainLoopStep`. The case order (1/2/3/5/4)
is deliberate: MSVC SP3 generates the jump table in source order,
and case 4 needs to be last so its tail codegen matches.

### PresentFrame (0x004b3e90)

Same shape - pure C switch tail-calling each renderer's present.
Mode order is again 1/2/3/5/4 to match the orig.


## Draw queue + counting sort

The per-frame work isn't done immediately. `DrawMeshBlock`
([src/engine/draw_mesh_block.c](../../src/engine/draw_mesh_block.c))
processes each scenegraph leaf node into a stream of 28-byte
draw-entries and calls `SubmitDrawEntry` per triangle:

```
g_drawQueue       at 0x00f71310    DRAW_QUEUE_MAX (3000) * 28 bytes
g_drawQueueSize   at 0x00f85b40    current entry count
g_drawQueueBuckets at 0x00f6d050   1024 dwords (counting-sort histogram)
```

### SubmitDrawEntry (0x004c3360)

Receives a 28-byte entry, frustum-culls it via X/Y bounds against
`g_viewportW/H` (with a -100/+740 X envelope and -100/+580 Y envelope
for the 640x480 case), then copies it into `g_drawQueue[g_drawQueueSize]`
and rewrites the sort-key word at +0x12 via `g_zSortKeyLUT[z]`.

The two bounds loops mutate `g_clipMinScratch` / `g_clipMaxScratch`
in place - these scratch globals at `0x00f70f70/78` are reused per
entry for X then Y. Still naked.

### Draw entry layout (28 bytes)

```
+0x00  int16 x0      vertex 0 screen X
+0x02  int16 y0      vertex 0 screen Y
+0x04  int16 x1      vertex 1 screen X (skipped if flag&0x20)
+0x06  int16 y1      vertex 1 screen Y
+0x08  int16 x2      vertex 2 screen X
+0x0A  int16 y2      vertex 2 screen Y
+0x0C..+0x11  6 bytes coords / UVs / colors
+0x12  uint16 sort_key       pre-LUT z key (rewritten to bucket id)
+0x14..+0x19  6 bytes more (UVs / shaded colors)
+0x1A  uint8  flags           bit 0x20 = "skip vertex 1" (tri vs quad)
+0x1B  uint8  ...
```

### FlushDrawQueue (0x004bf460)

The big one (~3.8 KB, still naked). Two passes:

1. **Histogram**: zero `g_drawQueueBuckets[1024]`, then for each
   entry in `g_drawQueue[0..g_drawQueueSize]`, increment
   `g_drawQueueBuckets[entry.sort_key]`.
2. **Cumulative-sum** the buckets in place (turns the histogram into
   per-bucket start offsets - a classic counting-sort post-pass).
3. **Dispatch**: walk the queue a second time. For each entry, look
   up `g_drawQueueBuckets[entry.sort_key]++` to get the sorted output
   index. Dispatch each triangle to the per-mode submitter:
   - Glide: `GlideTriBatchEmit_004adca0` / `GlideTriColorFlush_004b46f0`
   - D3D: queued into `g_renderer2_vertexBatch`, flushed via
     `Renderer2_FlushBatch_D3D` at EndScene
   - SW: one of the
     [Textured/Scanline]Tri[Rasterize|Blit]\* functions in the
     `0x004c0360..0x004c2cb0` range

After all dispatches, `g_drawQueueSize = 0`.

### Sort-key LUT (0x004bf290)

`BuildSortKeyLUT` ([src/engine/sort_lut.c](../../src/engine/sort_lut.c))
fills `g_zSortKeyLUT[65536]` with `(s32)(i / (i * 31 / 65536 + 1))`,
which is a hyperbolic remap giving more sort precision to near
geometry. The result is a 16-bit bucket index in [0..1023] (the
counting sort's histogram size).

The constants are loaded as `double` and clamped via .rdata reads.
The C source uses a deliberate reverse declaration order
(`k_inv_65536` before `k_31`) so MSVC SP3 emits the `fmul m64`
operands in the right .rdata order - the .rdata pool layout is
reversed from the C declaration order.


## Vertex pipeline - ProjectVertex / TransformVertex

The triangle stream coming out of the scenegraph is in **model space**.
Before it reaches the draw queue, two transforms happen per vertex:

### ProjectVertex (0x004b2e80)

Reads local-space `g_vtxIn_{x,y,z}` (s16), multiplies by the 3x3
matrix `g_vtxMat[9]` (column-major s16), adds `g_vtxTrans{X,Y,Z}` (s32),
writes world coords to `g_vtxOut_{x,y,z}` (s32), perspective-divides
by Z, and writes screen coords to `g_vtxScreen{X,Y}` (s16).

`ProjectTwoVertices` (`0x004b2af0`) is the two-vertex variant used
when entering a strip - reads `g_vtxIn1_*` and `g_vtxIn2_*`, writes
to the paired `g_vtxOut1/2`, then tail-calls `Helper_EmitLine(2)`.

### TransformVertex (0x004b3310)

Applies per-vertex lighting on the working RGB555 color `g_vtxColor`.
Uses two directional lights (`g_vtxLight0/1`, s32 x/y/z each) and
6 per-channel intensity scales (`g_vtxRGBScale0/1_{r,g,b}`, u8 each).
Result is clamped to 5 bits per channel and stored back to
`g_vtxColor`. The previous color is saved to `g_vtxColorSaved` for
restore.

The full color block at `0x007af9f0..0x007af9fc` is:

```
+0   g_vtxColorPrev      u32
+2   g_vtxRGBScale0_b    u8
+3   g_vtxRGBScale1_b    u8
+4   g_vtxRGBScale0_g    u8
+5   g_vtxRGBScale1_g    u8
+6   g_vtxRGBScale0_r    u8
+7   g_vtxRGBScale1_r    u8
+8   g_vtxColorCopy      u16
+a   g_vtxColorSaved     u16
+c   g_vtxColor          u16
```

Layout is critical - the per-channel scales are read as a single
DWORD via byte addressing, and the working color reads as a packed
u16 immediately after.

### Triangle-strip ring (AdvanceTriStripRing 0x004b2fa0)

Per-strip vertex carryover uses two parallel 3-slot rings plus three
16-bit X-coord scratch slots:

```c
g_triStripRingA[3]  at 0x007af9b4..0x007af9bc
g_triStripRingB[3]  at 0x007af984..0x007af98c
g_triStripX0/1/2    at 0x007af95c/962/968
```

`AdvanceTriStripRing(v0, v1, v2)` shifts both rings forward by one
(slot[0] = slot[1], slot[1] = slot[2]), then writes the three
caller-supplied 16-bit values into the X-coord slots.


## DrawMeshBlock - the leaf-node submitter (0x004bb250)

For each leaf node in the scenegraph, `RenderSceneNode` calls
`DrawMeshBlock` ([src/engine/draw_mesh_block.c](../../src/engine/draw_mesh_block.c)),
which:

1. Reads the block-header table at `block + 8 + block->ofs_b`.
2. For each strip (header has `flag` + `count`, terminated by `count < 0`):
   - Load 2 base vertices, `ProjectTwoVertices()`.
   - For each subsequent vertex (1 per triangle):
     - `AdvanceTriStripRing` shifts the ring forward.
     - `TransformVertex` shades.
     - `ProjectVertex` does the 3D->2D projection.
     - 2D cross-product winding test for back-face cull.
     - If facing-camera matches `flag.winding_bit` and Z is positive:
       fill 28-byte draw entry, `SubmitDrawEntry()`.

The per-vertex layout in the .geo block is 12 bytes (3x s16 pos +
3x s16 normal). The per-strip header is 4 bytes (`flag` u16 +
`count` int16). See [architecture.md](architecture.md) for the
full mesh stream walkthrough.

Still naked - ~1.5 KB of register-allocator-sensitive code that
shuttles state across the per-vertex helpers' globals.


## Globals reference

### Pipeline state

| Symbol                | Address     | Role                                     |
|-----------------------|-------------|------------------------------------------|
| `g_currentRendererMode`| `0x004f4b3c`| Last requested mode (set by `SetRendererMode`) |
| `g_clampedRendererMode`| `0x004f4b38`| Clamped to [1..5], what dispatchers read |
| `g_gfxInited`         | `0x007afa08`| 1 = `Gfx_Init` succeeded                 |
| `g_gfxHwnd`           | `0x007afa04`| HWND captured at `Gfx_Init`              |
| `g_gfxFlagA/B/C/D`    | `0x007afa0c..18` | Per-frame state flags             |
| `g_gfxSavedMode`      | `0x00543aa4`| Mode in effect before transition         |
| `g_gfxPostInitArg`    | `0x00543a94`| Last `Helper_GfxFlush` arg               |
| `g_viewportX/Y/W/H`   | `0x00f85b50/54` + `0x004ffd44/48` | Active viewport rect |
| `g_drawSceneTimeMs`   | `0x007afa00`| Cumulative ms in DrawScene (profiling)   |

### Draw queue + sort

| Symbol                | Address     | Role                                     |
|-----------------------|-------------|------------------------------------------|
| `g_drawQueue[]`       | `0x00f71310`| 3000 x 28-byte entries (max 84000 bytes) |
| `g_drawQueueSize`     | `0x00f85b40`| Current entry count                      |
| `g_drawQueueBuckets[1024]`| `0x00f6d050`| Counting-sort histogram               |
| `g_zSortKeyLUT[65536]`| `0x00b0d008`| z -> bucket remap (built once at boot)   |
| `g_clipMinScratch`    | `0x00f70f70`| Per-entry X/Y bounds scratch             |
| `g_clipMaxScratch`    | `0x00f70f78`| Per-entry X/Y bounds scratch             |

### Vertex pipeline

| Symbol                | Address     | Role                                     |
|-----------------------|-------------|------------------------------------------|
| `g_vtxIn_{x,y,z}`     | `0x007af95c/962/968`| Local-space input (s16)            |
| `g_vtxMat[9]`         | `0x007af990`| 3x3 transform (s16)                      |
| `g_vtxTrans{X,Y,Z}`   | `0x007af9a4/a8/ac`| Translation (s32)                   |
| `g_vtxOut_{x,y,z}`    | `0x007af974/980/98c`| World-space output (s32)           |
| `g_vtxValid`          | `0x007af9b0`| 1 = vertex made it through Z-clip        |
| `g_vtxScreen{X,Y}`    | `0x007af9bc/be`| Screen coords (s16, post-perspective) |
| `g_vtxColor`          | `0x007af9fc`| Working RGB555 color                     |
| `g_vtxLight0/1_*`     | `0x007af9d8..ec`| Two directional lights (s32)        |
| `g_vtxRGBScale0/1_*`  | `0x007af9f2..f7`| Per-channel light intensities (u8) |

### Triangle-strip ring

| Symbol                | Address     | Role                                     |
|-----------------------|-------------|------------------------------------------|
| `g_triStripRingA[3]`  | `0x007af9b4`| 32-bit ring (Y coords + state)           |
| `g_triStripRingB[3]`  | `0x007af984`| 32-bit ring (Z coords + state)           |
| `g_triStripX0/1/2`    | `0x007af95c/962/968`| 16-bit X coords                    |

### Per-renderer state

| Renderer | obj         | active      | surface     | present_rc  |
|----------|-------------|-------------|-------------|-------------|
| 1 Glide  | (see g_glide*)| `0x007affe4`| `0x007afff4`| (n/a)     |
| 2 D3D    | `0x0058c7c0`| `0x0058c7e0`| `0x0058c7e4`| `0x0058c7dc`|
| 3 SW_FS  | `0x0058c868`| `0x0058c874`| `0x0058c880`| `0x0058c878`|
| 4 SW_Win | (none)      | `0x007af940`| `0x007af948`| (n/a)       |
| 5 SW_FS_Hi| `0x0058c8e8`| `0x0058c8f4`| `0x0058c900`| `0x0058c8f8`|


## What's safe to change vs not

**Safe**:
- Renaming any of the globals above (apply consistently + `make matching`).
- Changing the SW rasterizer's color math (in the
  `0x004c0360..0x004c2cb0` range) **only if you stay in pure-C bodies
  already converted**; the byte match is sensitive to register choices.
- Editing `BeginFrame` / `DrawScene` / `PresentFrame` switch
  ordering - but careful: the case order is calibrated to match orig
  jump-table layout. If you reorder, `make matching` will fail.
- Adding a 6th renderer by extending the dispatchers - they'll
  silently no-op on unknown modes.

**Unsafe**:
- Changing the draw-entry stride (28 bytes). Hardcoded in
  `SubmitDrawEntry`'s `rep movsd`, in `FlushDrawQueue`'s
  per-entry walk, and in every rasterizer that reads from `g_drawQueue`.
- Changing `DRAW_QUEUE_MAX` (3000) or `DRAW_QUEUE_BUCKETS` (1024).
  Both are baked into `SubmitDrawEntry`'s overflow check (`cmp edi, 3000`)
  and `FlushDrawQueue`'s bucket-clear loop.
- Reordering the color block at `0x007af9f0..0x007af9fc`. The 6
  RGB-scale bytes and the 3 u16 colors are read as overlapping
  byte/word/dword accesses; any reorder breaks
  TransformVertex byte-for-byte.
- Touching `g_vtxMat` stride (3x3 s16 = 18 bytes). Read with hand-
  computed offsets by every projection path.
- Changing `g_zSortKeyLUT` size (65536) or formula. Indexed
  directly from `SubmitDrawEntry`.
- Reordering globals at `0x007af9*`. The vertex pipeline's
  `mov [g_vtx*], reg` chains use absolute addressing; offset
  changes propagate to every `mov reg, [g_X]` site.


## What's still naked vs pure C

In `src/engine/` render code:

- **Pure C** (already converted):
  `Gfx_Init`, `Helper_GfxInit2`, `BeginFrame`, `DrawScene`,
  `PresentFrame`, `SetRendererMode`, `TryInitRenderer`,
  `Renderer3_Init_SW_FS`, `Renderer5_Init_SW_FS_Hi`,
  `DDraw3_*` and `DDraw5_*` helpers (Create / PostCreate /
  CreateSurface / SetCooperativeLevel / GetSurface / Cleanup),
  `Renderer4_PresentFrame`, `AdvanceTriStripRing`, `BuildSortKeyLUT`,
  most R2_Init helpers, `Helper_GlideError`, `Helper_GlidePostInit`.

- **Hybrid C+__asm**:
  Various per-mode `BeginFrame` / `PresentFrame` cleanup wrappers.

- **Still naked** (NON-COAXABLE):
  `Renderer1_Init_Glide` - MSVC zero-caching in EBX (27x push ebx vs push 0).
  `Renderer2_Init_D3D` - 11-helper chain register threading.
  `FlushDrawQueue` - histogram + counting sort + per-mode dispatch.
  `SubmitDrawEntry` - dual X/Y bounds loops sharing scratch globals.
  `DrawMeshBlock` - ~1.5 KB of vertex-pipeline state shuttling.
  `RenderSceneNode` - 1899 bytes recursive (see [scenegraph.md](scenegraph.md)).
  `ProjectVertex` / `ProjectTwoVertices` / `TransformVertex` -
  fixed-point FPU sequences with strict register threading.

The per-function `NON-COAXABLE:` comment in each naked file explains
the specific MSVC SP3 codegen quirk. The survey is complete; do not
re-attempt conversion.


## Where to start when modifying

1. **Force a specific renderer**: edit `g_clampedRendererMode = N`
   in `Gfx_Init` (currently `= 4`). Useful when debugging mode
   transitions. Breaks byte match - flag this as a build-time
   constant.
2. **Add a frame-counter overlay**: after `PresentFrame`, blit text
   via `Helper_DrawCursor` or a fresh `SubmitDrawEntry` with a
   sort-key of 0 (always foreground). No matching-code change needed
   if added in a NEW source file.
3. **Replace Glide with modern OpenGL**: stub out `g_glideFnTable`
   entries with your own `LoadLibraryA` of a wrapper DLL.
   `Renderer1_Init_Glide` won't notice as long as the function-pointer
   signatures match.
4. **Replace SW rasterizers with hardware-accelerated**: hook
   `FlushDrawQueue`'s per-mode dispatch. Pass the sorted entries to
   your own backend; `SubmitDrawEntry` stays the same so the rest
   of the engine doesn't notice.
5. **Profile draw queue saturation**: tap `g_drawQueueSize` before
   `FlushDrawQueue` returns. Pure observation, no risk.
6. **Tune sort precision**: change the `31` in `BuildSortKeyLUT`'s
   hyperbolic formula. Lower = more far precision, higher = more
   near precision. Breaks byte match - constants are loaded from
   .rdata.


## The 12 draw-queue submitters

The 28-byte entries in `g_drawQueue` come from exactly **12 functions**
that call `SubmitDrawEntry` (`Helper_DrawCursor` `0x004c3360`). Each
specializes in a particular kind of geometry / overlay:

| Function                       | VA           | Submits                                                |
|--------------------------------|--------------|--------------------------------------------------------|
| `DrawMeshBlock`                | `0x004bb250` | One textured triangle per .geo strip vertex (main path) |
| `Helper_DrawMenuText`          | `0x004b21d0` | 3D menu text glyphs (perspective-projected font3d_g)   |
| `DrawMenu`                     | `0x004b65c0` | 2D menu items + background sprites                     |
| `Helper_DrawMenu_PostRender`   | `0x004b6880` | Menu cursor + post-pass overlay                        |
| `BillboardChainRender_004bb030`| `0x004bb030` | Single-billboard chain (camera-facing quads)           |
| `BillboardSheetDualEmit_004bbda0`| `0x004bbda0`| Multi-sprite sheet emitter (dual-pass)                |
| `MovesPanelEmit_004bcf60`      | `0x004bcf60` | Move-list overlay panel (character select screen)      |
| `SunbeamSpriteEmit_004bd270`   | `0x004bd270` | Sunbeam / lens flare sprite effect                     |
| `TristripBatchEmit_004bbb80`   | `0x004bbb80` | Triangle-strip batch (generic stripped geometry)       |
| `TristripBatchEmit2_004bb930`  | `0x004bb930` | Triangle-strip batch variant 2                         |
| `TristripBatchEmit3Cap_004bb680`| `0x004bb680`| Triangle-strip batch variant 3 with end-cap            |
| `Helper_TickReinit`            | (varies)     | Re-init path that flushes residual entries             |

All 12 are still naked. Each has a specific 28-byte entry layout
they produce; the dispatch then routes entries to either Glide / D3D
/ SW rasterizers based on `g_clampedRendererMode`.

The split into 3 `TristripBatchEmit*` variants reflects MK4's late-90s
fighting-game-engine optimization: pre-batched strips with different
winding/cap handling for different node-types in the scenegraph. The
distinction is opaque from outside (the queue entries look the same);
the variants differ in their internal walk pattern.


## Software rasterizers - the SW-mode pixel-pushing

The `0x004c0360..0x004c2cb0` range (~9 KB) holds the **10 software
rasterizers** that `FlushDrawQueue` dispatches to when running in
modes 3 / 4 / 5 (no Glide, no D3D). They are split into two
families:

| Family             | Style              | Input                  |
|--------------------|--------------------|------------------------|
| `ScanlineTexBlit*` | 2D sprite blit     | Sprite (axis-aligned)  |
| `TexturedTriRasterize*` | 3D textured tri | Triangle (3 verts)    |

### The 10 rasterizers

| Function                            | VA           | Family    | Role                                   |
|-------------------------------------|--------------|-----------|----------------------------------------|
| `ScanlineTexBlitPaletted_004c0360`  | `0x004c0360` | sprite    | Default sprite blit (palette LUT)      |
| `ScanlineTexBlit_004c0920`          | `0x004c0920` | sprite    | Plain opaque copy (no blend)           |
| `ScanlineTexBlitAlpha_004c0b70`     | `0x004c0b70` | sprite    | Alpha-blend src over dst               |
| `ScanlineTexBlitAdditive_004c0e10`  | `0x004c0e10` | sprite    | Additive blend (saturated add)         |
| `ScanlineTexBlitInterlaced_004c1130`| `0x004c1130` | sprite    | Skip every other scanline (low-res)    |
| `TexturedTriRasterize_004c13f0`     | `0x004c13f0` | triangle  | Plain textured triangle                |
| `TexturedTriRasterizeAlpha_004c19c0`| `0x004c19c0` | triangle  | Triangle with alpha-blend              |
| `TexturedTriRasterizeAlphaPal_004c1fe0`| `0x004c1fe0`| triangle | Triangle with alpha + palette          |
| `TexturedTriRasterizeDithered_004c2650`| `0x004c2650`| triangle | Triangle with dithered output (4:4:4)  |
| `TexturedTriRasterizeShaded_004c2cb0`| `0x004c2cb0`| triangle  | Triangle with Gouraud shading          |

Plus one auxiliary blitter outside the rasterizer block:

| Function                  | VA           | Role                             |
|---------------------------|--------------|----------------------------------|
| `BlitBlend16bpp_004c05e0` | `0x004c05e0` | 16bpp two-source blend (sprites) |
| `GlideTriBatchEmit_004adca0`| `0x004adca0`| D3D path (batched)               |
| `GlideTriColorFlush_004b46f0`| `0x004b46f0`| Glide path (per-triangle)        |

All 10 rasterizers are still naked - they each have 300-650 lines of
inner-loop asm with FPU-driven edge interpolation, sub-pixel offsets,
and per-pixel blending. Pure-C conversion would lose the FPU
scheduling and produce 30-50% larger code; not worth the matching
effort.

### Dispatch in FlushDrawQueue

`FlushDrawQueue` (`0x004bf460`) walks the sorted draw queue and
picks a rasterizer per entry based on TWO words in the 28-byte entry:

- **Entry +0x14**: if `< 0x7fff`, the entry is a **sprite** (low-z,
  no triangle geometry); if `>= 0x7fff`, it's a **textured triangle**.
- **Entry +0x1a**: a flags word. Bits `0x180` select the blend mode;
  bit `0x40` selects the 16bpp two-source blend variant.

The dispatch is **renderer-mode-sensitive**: the same draw entry
maps to different rasterizers in low-res (mode 3/4) vs hi-res (mode 5):

#### Sprite path (`entry[+0x14] < 0x7fff`)

| `entry[+0x1a] & 0x180` | Mode 3/4 (low-res)            | Mode 5 (hi-res)                |
|------------------------|-------------------------------|--------------------------------|
| 0x80                   | `ScanlineTexBlitInterlaced`   | `ScanlineTexBlitAdditive`      |
| 0x100                  | `ScanlineTexBlitInterlaced`   | `ScanlineTexBlitInterlaced`    |
| 0x180                  | `ScanlineTexBlitInterlaced`   | `ScanlineTexBlitAlpha`         |
| other, bit 0x40 set    | `BlitBlend16bpp`              | `BlitBlend16bpp`               |
| other                  | `ScanlineTexBlit`             | `ScanlineTexBlit`              |

So in low-res mode, the `Additive` and `Alpha` blend modes degrade
to `Interlaced` (i.e. mode 3/4 doesn't have enough fillrate to do
true alpha; it just halves the scanline count to compensate).
`ScanlineTexBlitPaletted` is the **fallback** when none of the other
flags match.

#### Triangle path (`entry[+0x14] >= 0x7fff`)

If `entry.flags & 0x10` (shading bit) is set, always
`TexturedTriRasterizeShaded`. Otherwise:

| `entry[+0x1a] & 0x180` | Mode 3/4 (low-res)              | Mode 5 (hi-res)                  |
|------------------------|---------------------------------|----------------------------------|
| 0x80                   | `TexturedTriRasterizeDithered`  | `TexturedTriRasterizeAlphaPal`   |
| 0x100                  | `TexturedTriRasterizeDithered`  | `TexturedTriRasterizeDithered`   |
| 0x180                  | `TexturedTriRasterizeDithered`  | `TexturedTriRasterizeAlpha`      |
| other                  | `TexturedTriRasterize`          | `TexturedTriRasterize`           |

Low-res mode again collapses the variants to `Dithered` (which
emits 16bpp from 24bpp via Bayer dithering - the cheapest
fillrate-friendly path). Hi-res uses the full set.

### Per-rasterizer pixel inner loop

Each rasterizer has a similar structure (~300 lines asm):

1. **Viewport clip**: bail if `g_viewportX == 0` or computed
   coords fall outside `g_viewportW x g_viewportH`. Read from
   `g_dispatchSave1378_00f70fa8` (x), `g_dispatchSave1381_00f70fb8`
   (y), `g_dispatchSave1380_00f70fb0` (width).
2. **Source/dest setup**: source texture pointer (from `+0x14` of
   entry), dest framebuffer offset.
3. **Inner loop**: per-pixel read from source, optional palette
   indirection, blend with dest, store. Loop counter is width;
   outer counter is height (sprite) or scanline count (triangle).
4. **Triangle variants**: also interpolate U/V coords along edges
   (fixed-point step counters) and the color (for Shaded variant).

Sizes:

| Family member        | LOC (incl. boilerplate) | Estimated inner-loop bytes |
|----------------------|-------------------------|----------------------------|
| ScanlineTexBlit family (5) | 294-362 lines      | ~200 bytes each            |
| TexturedTriRasterize family (5)| 568-645 lines  | ~600 bytes each            |

The TexturedTri variants are bigger because they include the
edge-walking + UV-interpolation setup (the FPU-driven 1/z and 1/w
divides) on top of the per-pixel inner loop.

### Framebuffer layout

All rasterizers write into the SW framebuffer. The destination
format depends on the mode:

- **Mode 4** (SW Win): 16bpp DIBSection, RGB-555 or RGB-565
  depending on display caps.
- **Mode 3** (SW FS 320x240): DDraw primary, 16bpp.
- **Mode 5** (SW FS Hi): DDraw primary, 16bpp at higher resolution.

The `Dithered` variant outputs 16bpp from a 24bpp intermediate;
the other variants are direct 16bpp.

### What to do when porting away

The 10-function dispatch in `FlushDrawQueue` can be replaced with a
modern OpenGL/Vulkan path that:

1. Walks the sorted queue same way.
2. For each entry, decides sprite vs triangle from `+0x14`.
3. Emits a textured quad (sprite) or triangle into a vertex buffer
   instead of calling the SW rasterizers.
4. Flushes the vertex buffer at the end of the frame.

The flag bits in `+0x1a` map cleanly to GLSL discard/alpha-test
states. Once that's done, **all 10 rasterizers become dead code**
and can be left in but never invoked. The `BlitBlend16bpp` auxiliary
follows the same fate.


## Caveat: avoid converting rasterizers to pure C

For PORTING purposes, the rasterizers can be replaced wholesale
with a modern blitter without touching `FlushDrawQueue` - the
queue-then-dispatch architecture cleanly isolates them. The
`Renderer4_PresentFrame` path's `IDirectDrawSurface::Blt` makes
this especially easy on Windows: replace it with `StretchBlt` to
hit any output device.
