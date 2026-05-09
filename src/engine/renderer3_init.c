/**
 * Renderer 3 (Software Fullscreen) init.
 *
 * Brings up DirectDraw in fullscreen with a single primary surface +
 * back buffer. Returns 1 on success / "already initialised", 0 on
 * any DDraw failure (with state rolled back via DDraw3_Cleanup).
 */
#include "engine/render.h"
#include "platform/win32.h"

/*
 * @addr 0x004af8c0
 *
 * Layout: cleanup tail comes BEFORE the success tail in memory, so
 * the do-while-0 + break pattern is what reproduces it (success
 * path returns from inside the loop, cleanup runs as the post-loop
 * body, MSVC SP3 lays the cleanup first / success second).
 */
int Renderer3_Init_SW_FS(HWND hwnd, char *param)
{
    if (g_renderer3_active != 0) return 1;
    if (hwnd == NULL) return 0;

    g_renderer3_surface = 0;
    g_renderer3_present_rc = 0;
    g_renderer3_hwnd_obj = (u32)hwnd;

    do {
        if (DDraw3_Create() == 0) break;
        DDraw3_PostCreate();
        if (DDraw3_CreateSurface(1) == 0) break;
        g_renderer3_surface_active = 1;
        if (DDraw3_SetCooperativeLevel() == 0) break;
        DDraw3_GetSurface();
        if (param != NULL) {
            *param = (char)g_renderer3_initByte;
        }
        g_renderer3_active = 1;
        return 1;
    } while (0);
    DDraw3_Cleanup();
    g_renderer3_active = 0;
    return 0;
}
