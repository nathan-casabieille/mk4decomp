/**
 * Per-renderer EndScene + mode-switch helpers.
 */
#include "engine/render.h"

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
