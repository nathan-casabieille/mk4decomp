/**
 * Auto-split from misc_matchesPP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;

/* @addr 0x00448fc0 (72b)
 *   ecx = [baseSel*4+0x4c]; mov fightGroupHead = ecx;
 *   call F1; pause → ret; call F2; pause → ret;
 *   walk = 2; g_acc_00542078 = 4; jmp T.
 */
extern unsigned int g_baseSel;
extern unsigned int g_acc_00542078;
extern void MStackPush2RunCountdown(void);
extern void MStackBracket7_DispatchAndChain(void);
extern void GuardedSeq_DualSetShiftCall_then_DualPushSet7dCallPop(void);
void LoadStoreDoubleCallSet(void) {
    g_fightGroupHead = *(unsigned int *)(g_baseSel * 4 + 0x4c);
    MStackPush2RunCountdown();
    if (g_framePauseFlag) return;
    MStackBracket7_DispatchAndChain();
    if (g_framePauseFlag) return;
    g_walkCallback = (void(*)(void))2;
    g_acc_00542078 = 4;
    GuardedSeq_DualSetShiftCall_then_DualPushSet7dCallPop();
}
