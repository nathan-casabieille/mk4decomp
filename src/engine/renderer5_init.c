/**
 * Renderer 5 (Software Fullscreen Hi-res) init.
 *
 * Same shape as Renderer3_Init_SW_FS but pointed at the renderer-5
 * DDraw helpers and the renderer-5 state globals.
 */
#include "engine/render.h"
#include "platform/win32.h"

/*
 * @addr 0x004b00f0
 */
int Renderer5_Init_SW_FS_Hi(HWND hwnd, char *param)
{
    if (g_renderer5_active != 0) return 1;
    if (hwnd == NULL) return 0;

    g_renderer5_surface = 0;
    g_renderer5_present_rc = 0;
    g_renderer5_hwnd_obj = (u32)hwnd;

    do {
        if (DDraw5_Create() == 0) break;
        DDraw5_PostCreate();
        if (DDraw5_CreateSurface(1) == 0) break;
        g_renderer5_surface_active = 1;
        if (DDraw5_SetCooperativeLevel() == 0) break;
        DDraw5_GetSurface();
        if (param != NULL) {
            *param = (char)g_renderer5_initByte;
        }
        g_renderer5_active = 1;
        return 1;
    } while (0);
    DDraw5_Cleanup();
    g_renderer5_active = 0;
    return 0;
}
