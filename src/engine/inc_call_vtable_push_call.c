/**
 * Auto-split from misc_matchesM.c
 */
#include "engine/ecm.h"

/* @addr 0x004b0d80 (39b)
 *   mov     edx, [0x007ab064]
 *   mov     eax, [0x007ab05c]
 *   inc     edx
 *   test    eax, eax
 *   mov     [0x007ab064], edx
 *   je      +6
 *   mov     ecx, [eax]
 *   push    eax
 *   call    [ecx + 0x48]              ; vtable[18] = DSBuf::Stop
 *   push    0
 *   call    F
 *   add     esp, 4
 *   ret
 */
extern u32 g_ecmReserved;

void IncCallVtablePushCall_004b0d80(void) {
    g_ecmReserved++;
    if (g_ecmDSBuffer != 0) {
        g_ecmDSBuffer->vtbl->Stop(g_ecmDSBuffer);
    }
    Helper_ECM_PostCleanup(0);
}
