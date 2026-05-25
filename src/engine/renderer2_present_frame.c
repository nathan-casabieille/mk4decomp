/**
 * Auto-extracted during misc_matches reorganization.
 */
#include "engine/scenegraph.h"

/* @addr 0x004ae950 (57b)
 *   if g_renderer2_active != 0 && g_renderer2_paused == 0:
 *     call F; if g_comptr_0058c7b4 != 0 && g_comptr_0058c7b0 != 0:
 *       call [edx + 0x2c](eax, ecx, 1); store result.
 */
extern int g_renderer2_active;
extern int g_renderer2_paused;
extern unsigned int g_comptr_0058c7b4;
extern unsigned int g_comptr_0058c7b0;
extern int g_renderer2_present_rc;
extern void Renderer2_EndScene_D3D(void);
void Renderer2_PresentFrame(void) {
    unsigned int cb;
    void *p;
    if (!g_renderer2_active) return;
    if (g_renderer2_paused) return;
    Renderer2_EndScene_D3D();
    cb = g_comptr_0058c7b4;
    if (!cb) return;
    p = (void *)g_comptr_0058c7b0;
    if (!p) return;
    g_renderer2_present_rc = ((unsigned int (__stdcall **)(void*, unsigned int, int))(*(void**)p))[11](p, cb, 1);
}

