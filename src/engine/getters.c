/**
 * Three single-instruction getters that just return a global.
 *
 * Each compiles to `mov eax, [m32]; ret` (6 bytes total) under
 * /O2. They exist because the original C source likely defined a
 * trivial accessor inline in a header file - MSVC SP3 emitted
 * each as its own out-of-line function rather than inlining.
 */
#include "audio/sound.h"        /* g_dsoundContext */
#include "platform/win32.h"     /* g_hInstance */
#include "engine/render.h"      /* g_currentRendererMode */

/*
 * @addr 0x004b3db0
 * Returns the currently-selected renderer mode (0=SW, 1=Glide,
 * 2=D3D, 3=SW-fullscreen, 4=SW-windowed, ...).
 */
int Renderer_GetMode(void)
{
    return g_currentRendererMode;
}

/*
 * @addr 0x004c37e0
 * Returns the active IDirectSound interface (or NULL if init failed).
 */
void *DSound_GetContext(void)
{
    return g_dsoundContext;
}

/*
 * @addr 0x004c49a0
 * Returns the process HINSTANCE the WinMain prologue stashed.
 */
HINSTANCE Win32_GetHInstance(void)
{
    return g_hInstance;
}
