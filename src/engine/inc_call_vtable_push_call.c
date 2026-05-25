/**
 * Auto-split from misc_matchesM.c
 */
#include "engine/scenegraph.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004b0d80 (39b)
 *   mov     edx, [0x007ab064]
 *   mov     eax, [0x007ab05c]
 *   inc     edx
 *   test    eax, eax
 *   mov     [0x007ab064], edx
 *   je      +6
 *   mov     ecx, [eax]
 *   push    eax
 *   call    [ecx + 0x48]
 *   push    0
 *   call    F
 *   add     esp, 4
 *   ret
 */
extern u32 g_ecmReserved;
extern void *g_iface_007ab05c;
extern int func_004b0982(int);
void IncCallVtablePushCall_004b0d80(void) {
    g_ecmReserved++;
    if (g_iface_007ab05c != 0) {
        ((void (__stdcall *)(void *))((void **)*(void **)g_iface_007ab05c)[0x12])(g_iface_007ab05c);
    }
    func_004b0982(0);
}
