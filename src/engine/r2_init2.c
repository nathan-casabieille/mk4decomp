/**
 * Auto-extracted during misc_matches reorganization.
 */
#include "engine/scenegraph.h"

/* @addr 0x004aef00 (43b): COM-style call with capture
 *   mov     eax, [g_iface_0058c7ac]
 *   test    eax, eax
 *   je      +0x14
 *   mov     ecx, [eax]
 *   push    0x004d287c
 *   push    0x004d2870
 *   push    eax
 *   call    [ecx]
 *   mov     [g_state_0058c7dc], eax
 *   mov     ecx, [g_iface_0058c7bc]
 *   xor     eax, eax
 *   test    ecx, ecx
 *   setne   al
 *   ret
 */
extern void *g_iface_0058c7ac;
extern unsigned int g_state_0058c7dc;
extern void *g_iface_0058c7bc;
extern void *g_data_004d2870;
extern void *g_data_004d287c;
int R2_Init2(void) {
    void *p = g_iface_0058c7ac;
    if (p != 0) {
        g_state_0058c7dc = ((unsigned int (__stdcall **)(void *, void *, void *))(*(void **)p))[0](p, &g_data_004d2870, &g_data_004d287c);
    }
    return g_iface_0058c7bc != 0;
}

