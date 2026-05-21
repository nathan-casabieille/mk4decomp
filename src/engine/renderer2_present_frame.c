/**
 * Auto-extracted during misc_matches reorganization.
 */
#include "engine/scenegraph.h"

/* @addr 0x004ae950 (57b)
 *   if g_state_0058c7e0 != 0 && g_state_0058c7ec == 0:
 *     call F; if g_state_0058c7b4 != 0 && g_state_0058c7b0 != 0:
 *       call [edx + 0x2c](eax, ecx, 1); store result.
 */
extern unsigned int g_state_0058c7e0;
extern unsigned int g_state_0058c7ec;
extern unsigned int g_state_0058c7b4;
extern unsigned int g_state_0058c7b0;
extern unsigned int g_state_0058c7dc;
extern void Renderer2_EndScene_D3D(void);
void Renderer2_PresentFrame(void) {
    unsigned int cb;
    void *p;
    if (!g_state_0058c7e0) return;
    if (g_state_0058c7ec) return;
    Renderer2_EndScene_D3D();
    cb = g_state_0058c7b4;
    if (!cb) return;
    p = (void *)g_state_0058c7b0;
    if (!p) return;
    g_state_0058c7dc = ((unsigned int (__stdcall **)(void*, unsigned int, int))(*(void**)p))[11](p, cb, 1);
}

