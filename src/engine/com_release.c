/**
 * 5 "COM-style Release-and-null" helpers (26b).
 * Pattern:
 *   mov eax, [g_ptr]; test eax,eax; je skip;
 *   mov ecx,[eax]; push eax; call [ecx+VTBL_OFS];
 *   skip: mov [g_ptr], 0; ret
 */
#include "engine/com.h"

extern Mk4ComObj *g_comptr_0058c7b8;   /* 0x0058c7b8 */
extern Mk4ComObj *g_comptr_0058c7bc;   /* 0x0058c7bc */
extern Mk4ComObj *g_comptr_0058c7c0;   /* 0x0058c7c0 */
extern Mk4ComObj *g_comptr_0058c870;   /* 0x0058c870 */
extern Mk4ComObj *g_comptr_0058c8f0;   /* 0x0058c8f0 */

/* @addr 0x004aedc0 */
void ComRelease_004aedc0(void) {
    Mk4ComObj *p = g_comptr_0058c7b8;
    if (p) {
        p->vtbl->Release(p);
    }
    g_comptr_0058c7b8 = 0;
}

/* @addr 0x004aef30 */
void ComRelease_004aef30(void) {
    Mk4ComObj *p = g_comptr_0058c7bc;
    if (p) {
        p->vtbl->Release(p);
    }
    g_comptr_0058c7bc = 0;
}

/* @addr 0x004af000 */
void ComRelease_004af000(void) {
    Mk4ComObj *p = g_comptr_0058c7c0;
    if (p) {
        p->vtbl->Release(p);
    }
    g_comptr_0058c7c0 = 0;
}

/* @addr 0x004afb10 */
void ComRelease_004afb10(void) {
    Mk4ComObj *p = g_comptr_0058c870;
    if (p) {
        p->vtbl->Release(p);
    }
    g_comptr_0058c870 = 0;
}

/* @addr 0x004b0340 */
void ComRelease_004b0340(void) {
    Mk4ComObj *p = g_comptr_0058c8f0;
    if (p) {
        p->vtbl->Release(p);
    }
    g_comptr_0058c8f0 = 0;
}
