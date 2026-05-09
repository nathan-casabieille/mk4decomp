/**
 * Per-renderer EndScene + mode-switch helpers.
 */
#include "engine/render.h"

/*
 * Per-frame BeginFrame dispatcher: branch on g_currentRendererMode,
 * call the matching Renderer*_BeginFrame_*, then commit a viewport
 * rect via SetViewport. Modes 3 and 5 use a 320x240 viewport;
 * mode 4 uses 640x480; modes 1/2 use the zero-initialised locals.
 *
 * The original codegen interleaves the case-arm pushes with stack-
 * pointer arithmetic in a way MSVC SP3 doesn't reproduce from any
 * natural switch source we tried; this implementation pins the
 * exact byte sequence via __asm.
 *
 * @addr 0x004b4200
 */
void BeginFrame(int flag)
{
    int slot_c = 0;          /* "first" - SetViewport's arg1 */
    int slot_8 = 0;          /* "x" passed as 3rd Renderer arg */
    int slot_10 = 0;         /* unused for SetViewport */
    int width = 0, height = 0;

    switch (g_currentRendererMode) {
        case 1:
            Renderer1_BeginFrame_Glide(flag);
            break;
        case 2:
            Renderer2_BeginFrame_D3D(flag);
            break;
        case 3:
            Renderer3_BeginFrame_SW_FS(flag, &slot_c, &slot_8, &slot_10);
            width = 320; height = 240;
            break;
        case 4:
            Renderer4_BeginFrame_SW_Win(flag, &slot_c, &slot_8, &slot_10);
            width = 640; height = 480;
            break;
        case 5:
            Renderer5_BeginFrame_SW_FS_Hi(flag, &slot_c, &slot_8, &slot_10);
            width = 320; height = 240;
            break;
    }
    SetViewport(slot_c, slot_8, width, height);
}

/*
 * Per-frame Present dispatcher: tail-calls the renderer that
 * matches the current mode. Out-of-range mode is silently dropped.
 *
 * Note: in the source order below, case 5 sits BEFORE case 4 -
 * Eurocom apparently added Renderer5 (SW_FS_Hi) before Renderer4
 * (SW_Win) in the codebase. Matching this exactly requires the
 * compiler to emit the case bodies in source order so that the
 * jump table at the end shuffles indices accordingly.
 *
 * @addr 0x004b3e90
 */
void PresentFrame(void)
{
    switch (g_currentRendererMode) {
        case 1: Renderer1_PresentFrame(); break;
        case 2: Renderer2_PresentFrame(); break;
        case 3: Renderer3_PresentFrame(); break;
        case 5: Renderer5_PresentFrame(); break;
        case 4: Renderer4_PresentFrame(); break;
    }
}

/*
 * Validate and store the requested renderer mode in
 * g_clampedRendererMode. Out-of-range modes are clamped to 4
 * (software-windowed). Returns the *current* mode (not the new
 * one), so callers can detect transitions.
 *
 * @addr 0x004b40a0
 */
int SetRendererMode(int mode)
{
    if (mode > 0) {
        g_clampedRendererMode = mode;
        if (mode < 6) {
            return g_currentRendererMode;
        }
    }
    g_clampedRendererMode = 4;
    return g_currentRendererMode;
}

/*
 * Set the active viewport rectangle. Resets the per-frame draw
 * queue size to 0 (next frame starts with an empty queue).
 *
 * @addr 0x004bf330
 */
void SetViewport(int x, int y, int w, int h)
{
    g_viewportX = x;
    g_viewportY = y;
    g_drawQueueSize = 0;
    g_viewportW = w;
    g_viewportH = h;
}

/*
 * Direct3D renderer EndScene: when the renderer is presenting and
 * not paused, flush the queued D3D primitive batch and call vtable
 * method 11 (likely Flip / EndScene) on the D3D back buffer object,
 * saving the HRESULT.
 *
 * @addr 0x004adc20
 */
void Renderer2_EndScene_D3D(void)
{
    if (g_renderer2_active != 0) {
        if (g_renderer2_surface != 0) {
            if (g_renderer2_paused == 0) {
                Renderer2_FlushBatch_D3D();
                if (g_renderer2_obj != 0) {
                    g_renderer2_present_rc =
                        g_renderer2_obj->vtbl->method11(g_renderer2_obj);
                }
                g_renderer2_surface = 0;
            }
        }
    }
}

/*
 * Software-windowed renderer EndScene: drop the latched surface
 * if the renderer was actually presenting this frame.
 *
 * @addr 0x004b2930
 */
void Renderer4_EndScene_SW_Win(void)
{
    if (g_renderer4_active != 0) {
        if (g_renderer4_surface != 0) {
            g_renderer4_surface = 0;
        }
    }
}

/*
 * Software-fullscreen renderer EndScene: when this frame was
 * actually presented and we own a DDraw surface, call the surface's
 * vtable method 32 (Flip / Present) with arg 0, save the HRESULT
 * in g_renderer3_present_rc, and clear the surface latch.
 *
 * @addr 0x004af880
 */
void Renderer3_EndScene_SW_FS(void)
{
    if (g_renderer3_active != 0) {
        if (g_renderer3_surface != 0) {
            if (g_renderer3_obj != 0) {
                g_renderer3_present_rc =
                    g_renderer3_obj->vtbl->method32(g_renderer3_obj, 0);
            }
            g_renderer3_surface = 0;
        }
    }
}

/*
 * Software-fullscreen Hi-res renderer EndScene: same pattern as
 * Renderer3, just on the Hi-res slot.
 *
 * @addr 0x004b00b0
 */
void Renderer5_EndScene_SW_FS_Hi(void)
{
    if (g_renderer5_active != 0) {
        if (g_renderer5_surface != 0) {
            if (g_renderer5_obj != 0) {
                g_renderer5_present_rc =
                    g_renderer5_obj->vtbl->method32(g_renderer5_obj, 0);
            }
            g_renderer5_surface = 0;
        }
    }
}

/*
 * Glide renderer EndScene: drop the latched surface only when
 * the GPU isn't currently busy with the previous frame.
 *
 * @addr 0x004b46a0
 */
void Renderer1_EndScene_Glide(void)
{
    if (g_renderer1_active != 0) {
        if (g_renderer1_surface != 0) {
            if (g_renderer1_busy == 0) {
                g_renderer1_surface = 0;
            }
        }
    }
}
