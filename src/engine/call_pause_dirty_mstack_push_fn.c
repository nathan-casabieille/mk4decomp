/**
 * Auto-split from misc_matchesV.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;
extern unsigned int g_acc_00542078;

/* @addr 0x0046e2a0 (56b)
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     +0x29
 *   test    byte [g_xformDirtyFlags], 4
 *   je      +0x1b
 *   mov     eax, [g_matrixStackTop]
 *   inc     eax
 *   mov     [g_matrixStackTop], eax
 *   mov     [eax*4 + 0], 0x0046e2e0
 *   jmp     T
 *   jmp     +9
 *   ret
 */
extern void func_00470450(void);
extern void PendingMatch_0046e2e0(void);
extern void GameDispatchValidateState_004339c0(void);
extern void func_0046e2b3(void);
void CallPauseDirtyMStackPushFn_0046e2a0(void) {
    unsigned int top;
    func_00470450();
    if (g_framePauseFlag != 0) return;
    if ((g_xformDirtyFlags & 4) != 0) {
        top = g_matrixStackTop + 1;
        g_matrixStackTop = top;
        *(unsigned int *)(top * 4) = (unsigned int)&PendingMatch_0046e2e0;
        GameDispatchValidateState_004339c0();
        return;
    }
    func_0046e2b3();
}
