# Native render backend - the path to on-screen pixels

Status (2026-06-11): the engine **loop + game logic** run natively (MK4.native.full,
146 TUs, on real arena data). **Rendering is the remaining gap** - nothing reaches
the screen yet. This doc specifies the work.

## Original render chain
```
GameLogicStep      -> enqueues primitives into g_drawQueueBuckets (g_drawQueueSize)
FlushDrawQueue     -> dequeues, dispatches each primitive to a SW rasterizer   [NAKED]
  TexturedTriRasterize* / ScanlineTexBlit* (8+ fns, 600-1700 bytes each)       [NAKED]
                   -> write pixels into a DirectDraw surface's locked memory
RendererN_EndScene_SW_* -> finalises the surface                               [NAKED]
RendererN_PresentFrame  -> surface->vtbl->Flip()  (DirectDraw COM)
```
Renderers: 1=Glide, 2=D3D (hardware, skip natively); 3=SW-FS, 4=SW-Win, 5=SW-FS-Hi
(software - the native targets). g_clampedRendererMode selects. The Hi path is
16-bit 555 (matches MK4_PalBlit555 + the verified Vec3ColorShiftClamp pack).

## What already works
- **Output half is DONE**: `make native` blits a framebuffer to SDL via
  MK4_PalBlit555 (the smoke pattern proves PAL output end-to-end).
- The loop drives BeginFrame/DrawScene/PresentFrame each frame.

## What's missing (critical path, in order)
1. **DirectDraw COM surface shim** (the video PAL backend; com.h calls it Phase 2).
   The converted code dispatches `(*(MK4ComMethod*)(*iface + off))(iface, ...)`.
   Build host objects = {vtbl ptr, ...} with C method impls for the slots the
   renderer uses (CreateSurface / Lock / Unlock / Flip / Blt). Lock returns a real
   linear buffer; Flip calls MK4_PalBlit555(buffer). Populate g_renderer5_surface /
   the DDraw object globals with these shims. Offset-mapping is a finite RE task
   (grep `(*iface + 0x..)` in the renderer/ddraw path - DSound/DDraw/D3D offsets
   are intermixed; isolate the IDirectDrawSurface slots).
2. **Convert FlushDrawQueue** (naked, draw-queue dispatcher over g_drawQueueBuckets)
   to a verified twin.
3. **Convert >= 1 SW rasterizer** (TexturedTriRasterize / ScanlineTexBlit, big naked)
   so something actually writes pixels to the locked buffer. THIS is the dominant
   cost - large hand ASM->C conversions, each verify_coexec'd (seed a small draw
   queue + a surface buffer).
4. Reroute RendererN_EndScene/Flip -> the shim -> MK4_PalBlit. Force
   g_clampedRendererMode to the SW mode at init.
5. GameLogicStep must enqueue primitives (boot/menu does; otherwise inject a test
   primitive to validate the chain before the FSM is fully lit).

## Shortest demo milestone
Shim (1) + convert FlushDrawQueue (2) + ONE rasterizer (3) + Flip->PAL (4), then
feed a single test primitive (5). That displays the first engine-rendered pixels.
Full game visuals follow as more rasterizers + the GameLogicStep/FSM cluster convert.

## Honest estimate
~70% of "playable frame" is done (loop, logic, arena, memory model, seams, the
convert+verify+native toolchain, PAL output). The remaining ~30% is this render
backend: a bounded COM-surface shim + the big-naked-rasterizer conversion grind.
The rasterizers are the long pole.
