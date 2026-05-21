/**
 * Auto-split from misc_matchesI.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00453750 (38b)
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   mov     eax, [g_scaledInit_00542044]
 *   mov     ecx, [eax*4 + 0x24]
 *   mov     [g_xformEntityIdx], ecx
 *   jmp     T
 *   ret
 */
extern void DirtyDoubleDeref_00408cb0(void);
extern void func_00407310(void);
void CallPauseScaledStoreXJmp_00453750(void) {
    DirtyDoubleDeref_00408cb0();
    if (g_framePauseFlag != 0) return;
    g_xformEntityIdx = *(unsigned int *)(g_scaledInit_00542044 * 4 + 0x24);
    func_00407310();
}
