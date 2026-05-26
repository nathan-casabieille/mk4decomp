/**
 * Auto-split from misc_matchesW.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00484b00 (56b)
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     +0x29
 *   test    byte [g_xformDirtyFlags], 4
 *   je      +0x1b
 *   mov     eax, [g_matrixStackTop]
 *   inc     eax
 *   mov     [g_matrixStackTop], eax
 *   mov     [eax*4 + 0], 0x00484b40
 *   jmp     T
 *   jmp     +9
 *   ret
 */
extern void DirtyToggleByGate_0048f350(void);
extern void GuardedDispatch4_00484b40(void);
extern void GameDispatchValidateState_004339c0(void);
extern void GuardedDispatch4_00484b40(void);
void CallPauseDirtyMStackPush484b40_00484b00(void) {
    unsigned int v;
    DirtyToggleByGate_0048f350();
    if (g_framePauseFlag != 0) return;
    if ((g_xformDirtyFlags & 4) != 0) {
        v = g_matrixStackTop + 1;
        g_matrixStackTop = v;
        *(unsigned int *)(v * 4) = (unsigned int)&GuardedDispatch4_00484b40;
        GameDispatchValidateState_004339c0();
        return;
    }
    GuardedDispatch4_00484b40();
}
