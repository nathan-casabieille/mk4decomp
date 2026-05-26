/**
 * 2 "two-gate COM call with refcount capture" helpers (39 bytes).
 *
 * Pattern:
 *   mov     eax, [g_X]
 *   test    eax, eax
 *   je      .ret
 *   call    Setup
 *   mov     eax, [g_Y]                ; iface
 *   test    eax, eax
 *   je      .ret
 *   mov     ecx, [eax]
 *   push    1
 *   push    0
 *   push    eax
 *   call    [ecx + 0x2c]              ; vtable[11] = Flip
 *   mov     [g_Z], eax                ; capture refcount
 * .ret:
 *   ret
 *
 * Vtable slot 11 (offset 0x2c) with 2 args (0, 1) is
 * IDirectDrawSurface::Flip(target=NULL, flags=WAIT).
 */
#include "engine/render.h"

extern unsigned int g_dsqc_730_state874;
extern unsigned int g_dsqc_f60_state874;
extern unsigned int g_comret_0058c878;
extern unsigned int g_comret_0058c8f8;

extern void Renderer3_EndScene_SW_FS(void);
extern void Renderer5_EndScene_SW_FS_Hi(void);

extern DDSurfaceFlippable *g_comptr_0058c864;
extern DDSurfaceFlippable *g_comptr_0058c8e4;

/* @addr 0x004af690 */
void Renderer3_PresentFrame(void) {
    DDSurfaceFlippable *p;
    if (!g_dsqc_730_state874) return;
    Renderer3_EndScene_SW_FS();
    p = g_comptr_0058c864;
    if (!p) return;
    g_comret_0058c878 = (unsigned int)p->vtbl->Flip(p, 0, 1);
}

/* @addr 0x004afec0 */
void Renderer5_PresentFrame(void) {
    DDSurfaceFlippable *p;
    if (!g_dsqc_f60_state874) return;
    Renderer5_EndScene_SW_FS_Hi();
    p = g_comptr_0058c8e4;
    if (!p) return;
    g_comret_0058c8f8 = (unsigned int)p->vtbl->Flip(p, 0, 1);
}
