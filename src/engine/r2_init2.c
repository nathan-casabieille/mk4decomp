/**
 * Auto-extracted during misc_matches reorganization.
 */
#include "engine/com.h"

/* @addr 0x004aef00 (43b): COM-style call with capture
 *   mov     eax, [g_renderer2SrcIface]
 *   test    eax, eax
 *   je      +0x14
 *   mov     ecx, [eax]
 *   push    0x004d287c
 *   push    0x004d2870
 *   push    eax
 *   call    [ecx]                   ; vtable[0] = QueryInterface
 *   mov     [g_renderer2_present_rc], eax
 *   mov     ecx, [g_renderer2CapsIface]
 *   xor     eax, eax
 *   test    ecx, ecx
 *   setne   al
 *   ret
 */
extern Mk4ComObj *g_renderer2SrcIface;
extern int g_renderer2_present_rc;
extern void *g_renderer2CapsIface;
extern void *g_dispatchSave1158;
extern void *g_comptr_0058c7bc;

int R2_Init2(void) {
    Mk4ComObj *p = g_renderer2SrcIface;
    if (p != 0) {
        g_renderer2_present_rc = (int)p->vtbl->QueryInterface(p,
            &g_dispatchSave1158, &g_comptr_0058c7bc);
    }
    return g_renderer2CapsIface != 0;
}
