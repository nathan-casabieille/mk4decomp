/**
 * Mode-2 vs default vtable call on a renderer 2 DDSurface slot pair.
 */
#include "engine/render.h"

extern DDSurface *g_comptr_0058c7b0;
extern DDSurface *g_comptr_0058c7b4;

/*
 * @addr 0x004ad590 (95b engine.install) - mode-2 vs default vtable
 *   release: gated by two heads; if state == 2 picks the b4 slot;
 *   else picks the b0 slot; calls vt[0x80] (= slot 32) with (slot, 0)
 *   and stashes the return into g_renderer2_present_rc before clearing
 *   the mode flag.
 */
void VtRelease_Modal_004ad590(void) {
    DDSurface *p;
    if (g_renderer2_active == 0) return;
    if (g_renderer2_paused == 0) return;
    if (g_renderer2_paused == 2) {
        p = g_comptr_0058c7b4;
        if (p != 0) {
            g_renderer2_present_rc = (int)p->vtbl->method32(p, 0);
            g_renderer2_paused = 0;
            return;
        }
    } else {
        p = g_comptr_0058c7b0;
        if (p != 0) {
            g_renderer2_present_rc = (int)p->vtbl->method32(p, 0);
        }
    }
    g_renderer2_paused = 0;
}
