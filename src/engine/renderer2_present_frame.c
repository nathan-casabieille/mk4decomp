/**
 * Auto-extracted during misc_matches reorganization.
 */
#include "engine/render.h"

/* @addr 0x004ae950 (57b)
 *   if g_renderer2_active != 0 && g_renderer2_paused == 0:
 *     call F; if g_comptr_0058c7b4 != 0 && g_comptr_0058c7b0 != 0:
 *       call [edx + 0x2c](eax, ecx, 1); store result.
 *
 * vtable[11] (offset 0x2c) with 2 args is IDirectDrawSurface::Flip.
 */
extern DDSurfaceFlippable *g_comptr_0058c7b4;
extern DDSurfaceFlippable *g_comptr_0058c7b0;
extern void Renderer2_EndScene_D3D(void);

void Renderer2_PresentFrame(void) {
    DDSurfaceFlippable *cb;
    DDSurfaceFlippable *p;
    if (!g_renderer2_active) return;
    if (g_renderer2_paused) return;
    Renderer2_EndScene_D3D();
    cb = g_comptr_0058c7b4;
    if (!cb) return;
    p = g_comptr_0058c7b0;
    if (!p) return;
    g_renderer2_present_rc = (int)p->vtbl->Flip(p, cb, 1);
}
