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

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_dsqc_730_state874;
extern unsigned int g_dsqc_f60_state874;
extern unsigned int g_comret_0058c878;
extern unsigned int g_comret_0058c8f8;
#endif

extern void Renderer3_EndScene_SW_FS(void);
extern void Renderer5_EndScene_SW_FS_Hi(void);

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern DDSurfaceFlippable *g_comptr_0058c864;
extern DDSurfaceFlippable *g_comptr_0058c8e4;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_comptr_0058c864 (*(unsigned int *)MK4_VA(unsigned int, 0x58c864u))
#define g_comptr_0058c8e4 (*(unsigned int *)MK4_VA(unsigned int, 0x58c8e4u))
#define g_comret_0058c878 (*(unsigned int *)MK4_VA(unsigned int, 0x58c878u))
#define g_comret_0058c8f8 (*(unsigned int *)MK4_VA(unsigned int, 0x58c8f8u))
#define g_dsqc_730_state874 (*(unsigned int *)MK4_VA(unsigned int, 0x58c874u))
#define g_dsqc_f60_state874 (*(unsigned int *)MK4_VA(unsigned int, 0x58c8f4u))
#endif


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
