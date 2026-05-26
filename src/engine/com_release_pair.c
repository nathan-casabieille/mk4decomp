/**
 * 3 "double Release-and-null with refcount capture" helpers (56 bytes).
 *
 * Pattern (two-stage release):
 *   mov     eax, [g_ifaceA]
 *   test    eax, eax
 *   je      .skipA
 *   mov     ecx, [eax]
 *   push    eax
 *   call    [ecx+8]              ; A->Release()
 * .skipA:
 *   mov     eax, [g_ifaceB]
 *   mov     [g_ifaceA], 0
 *   test    eax, eax
 *   je      .skipB
 *   mov     edx, [eax]
 *   push    eax
 *   call    [edx+8]              ; B->Release()
 *   mov     [g_refSlot], eax     ; capture B refcount
 * .skipB:
 *   mov     [g_ifaceB], 0
 *   ret
 *
 * Releases two related COM interfaces in sequence, captures only the
 * second Release's return value into a refcount slot, then clears
 * both pointers.
 */
#include "engine/com.h"

extern Mk4ComObj   *g_comptr_0058c7b4;   /* iface A */
extern Mk4ComObj   *g_comptr_0058c7b0;   /* iface B */
extern unsigned int g_comret_0058c7dc;
extern Mk4ComObj   *g_comptr_0058c868;
extern Mk4ComObj   *g_comptr_0058c864;
extern unsigned int g_comret_0058c878;
extern Mk4ComObj   *g_comptr_0058c8e8;
extern Mk4ComObj   *g_comptr_0058c8e4;
extern unsigned int g_comret_0058c8f8;

/* @addr 0x004af440 */
void ComReleasePair_004af440(void) {
    Mk4ComObj *a = g_comptr_0058c7b4;
    Mk4ComObj *b;
    if (a) {
        a->vtbl->Release(a);
    }
    b = g_comptr_0058c7b0;
    g_comptr_0058c7b4 = 0;
    if (b) {
        g_comret_0058c7dc = b->vtbl->Release(b);
    }
    g_comptr_0058c7b0 = 0;
}

/* @addr 0x004afcd0 */
void ComReleasePair_004afcd0(void) {
    Mk4ComObj *a = g_comptr_0058c868;
    Mk4ComObj *b;
    if (a) {
        a->vtbl->Release(a);
    }
    b = g_comptr_0058c864;
    g_comptr_0058c868 = 0;
    if (b) {
        g_comret_0058c878 = b->vtbl->Release(b);
    }
    g_comptr_0058c864 = 0;
}

/* @addr 0x004b0500 */
void ComReleasePair_004b0500(void) {
    Mk4ComObj *a = g_comptr_0058c8e8;
    Mk4ComObj *b;
    if (a) {
        a->vtbl->Release(a);
    }
    b = g_comptr_0058c8e4;
    g_comptr_0058c8e8 = 0;
    if (b) {
        g_comret_0058c8f8 = b->vtbl->Release(b);
    }
    g_comptr_0058c8e4 = 0;
}
