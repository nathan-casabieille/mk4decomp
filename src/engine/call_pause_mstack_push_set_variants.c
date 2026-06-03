/**
 * Auto-split from misc_matchesV.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;
extern unsigned int g_acc_00542078;
extern void SelfInstallPhaseDispatch_DualGatedStateYield_0045fd30(void);
extern void LeaPlus22StoreSelf(void);

/* @addr 0x0045fcf0 (52b)
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   mov     eax, [g_matrixStackTop]
 *   mov     [g_walkCallback], 0
 *   inc     eax
 *   mov     [g_matrixStackTop], eax
 *   mov     [eax*4 + 0], OFFSET T
 *   jmp     T2
 *   ret
 */
void CallPauseMStackPushSet0Jmp(void) {
    unsigned int top;
    LeaPlus22StoreSelf();
    if (g_framePauseFlag != 0) return;
    top = g_matrixStackTop;
    g_walkCallback = (void (*)(void))0;
    top++;
    g_matrixStackTop = top;
    *(unsigned int *)(top * 4) = (unsigned int)&SelfInstallPhaseDispatch_DualGatedStateYield_0045fd30;
    MstackPopScaledChainPlusThunks();
}

/* @addr 0x0045ffc0 (52b): same shape, value=9 */
extern void ScaledInit_GuardedDirtyXformFromTable_g_scaledInit(void);
extern void SelfInstallPhaseDispatch_DualGatedStateYield_00460000(void);
void CallPauseMStackPushSet9Jmp(void) {
    unsigned int top;
    ScaledInit_GuardedDirtyXformFromTable_g_scaledInit();
    if (g_framePauseFlag != 0) return;
    top = g_matrixStackTop;
    g_walkCallback = (void (*)(void))9;
    top++;
    g_matrixStackTop = top;
    *(unsigned int *)(top * 4) = (unsigned int)&SelfInstallPhaseDispatch_DualGatedStateYield_00460000;
    MstackPopScaledChainPlusThunks();
}

/* @addr 0x00460d00 (52b): same shape, value=3, OFFSET 0x00470480 */
extern void LeaPlus22StoreSelf(void);
extern void CjInstallSelfRouter(void);
void CallPauseMStackPushSet3Jmp(void) {
    unsigned int top;
    LeaPlus22StoreSelf();
    if (g_framePauseFlag != 0) return;
    top = g_matrixStackTop;
    g_walkCallback = (void (*)(void))3;
    top++;
    g_matrixStackTop = top;
    *(unsigned int *)(top * 4) = (unsigned int)&CjInstallSelfRouter;
    MstackPopScaledChainPlusThunks();
}

/* @addr 0x00460d40 (52b): same shape, value=4 */
extern void LeaPlus22StoreSelf(void);
void CallPauseMStackPushSet4Jmp(void) {
    unsigned int top;
    LeaPlus22StoreSelf();
    if (g_framePauseFlag != 0) return;
    top = g_matrixStackTop;
    g_walkCallback = (void (*)(void))4;
    top++;
    g_matrixStackTop = top;
    *(unsigned int *)(top * 4) = (unsigned int)&CjInstallSelfRouter;
    MstackPopScaledChainPlusThunks();
}
