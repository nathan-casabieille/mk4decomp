/**
 * 3 "COM-style Release-and-null with captured retval" helpers (31b).
 *
 * Pattern:
 *   mov eax, [g_iface]
 *   test eax, eax
 *   je skip
 *   mov ecx, [eax]
 *   push eax
 *   call [ecx + 8]                 ; vtable[2] = Release
 *   mov [g_retSlot], eax           ; capture refcount
 * skip:
 *   mov [g_iface], 0
 *   ret
 *
 * Variant of com_release.c that stores the Release return value
 * into a separate global before clearing the interface slot. The
 * je skips both the Release call and the store, but still falls
 * through to the unconditional clear.
 */
#include "engine/com.h"

extern Mk4ComObj   *g_comptr_0058c7ac;   /* 0x0058c7ac */
extern unsigned int g_comret_0058c7dc;   /* 0x0058c7dc */
extern Mk4ComObj   *g_comptr_0058c860;   /* 0x0058c860 */
extern unsigned int g_comret_0058c878;   /* 0x0058c878 */
extern Mk4ComObj   *g_comptr_0058c8e0;   /* 0x0058c8e0 */
extern unsigned int g_comret_0058c8f8;   /* 0x0058c8f8 */

/* @addr 0x004aeee0 */
void ComReleaseCapture_004aeee0(void) {
    Mk4ComObj *p = g_comptr_0058c7ac;
    if (p) {
        g_comret_0058c7dc = p->vtbl->Release(p);
    }
    g_comptr_0058c7ac = 0;
}

/* @addr 0x004afb50 */
void ComReleaseCapture_004afb50(void) {
    Mk4ComObj *p = g_comptr_0058c860;
    if (p) {
        g_comret_0058c878 = p->vtbl->Release(p);
    }
    g_comptr_0058c860 = 0;
}

/* @addr 0x004b0380 */
void ComReleaseCapture_004b0380(void) {
    Mk4ComObj *p = g_comptr_0058c8e0;
    if (p) {
        g_comret_0058c8f8 = p->vtbl->Release(p);
    }
    g_comptr_0058c8e0 = 0;
}
