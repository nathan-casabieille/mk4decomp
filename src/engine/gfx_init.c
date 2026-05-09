/**
 * Top-level renderer / scene-graph init driver.
 */
#include "engine/render.h"
#include "platform/win32.h"

/*
 * @addr 0x004b4370
 *
 * The fail-tail comes BEFORE the success-tail in the original, so
 * the natural form `if (init() == 0) { fail; return 0; } success;
 * return 1;` doesn't reproduce the layout. Using the if-success-
 * inverted form: `if (init() != 0) goto success; fail; goto end;
 * success: ...; end: ...`. (Equivalent to MSVC SP3's preferred
 * out-of-line ordering for the "small fail / large success" case.)
 */
s32 Gfx_Init(HWND hwnd)
{
    if (g_gfxInited != 0) return 1;
    if (hwnd == NULL)     return 0;

    g_gfxHwnd = hwnd;
    BuildSortKeyLUT();
    if (Helper_GfxInit2(g_gfxHwnd) == 0) {
        Helper_GfxCleanup();
        ShowErrorMessage("Gfx_Init()");
        g_gfxInited = 0;
        return 0;
    }
    g_clampedRendererMode = 4;
    g_gfxFlagA = 1;
    g_gfxFlagB = 1;
    g_gfxFlagC = 1;
    BeginFrame(1);
    DrawScene();
    PresentFrame();
    g_gfxInited = 1;
    return 1;
}
