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
extern unsigned int g_baseSel_00542060;
extern unsigned int g_acc_00542078;
extern void MStackPush2RunCountdown_004089e0(void);
extern void MStackBracket7_DispatchAndChain_004b8fa0(void);
extern void GuardedSeq_00473f50(void);
void LoadStoreDoubleCallSet_00448fc0(void) {
    g_fightGroupHead = *(unsigned int *)(g_baseSel_00542060 * 4 + 0x4c);
    MStackPush2RunCountdown_004089e0();
    if (g_framePauseFlag) return;
    MStackBracket7_DispatchAndChain_004b8fa0();
    if (g_framePauseFlag) return;
    g_walkCallback = (void(*)(void))2;
    g_acc_00542078 = 4;
    GuardedSeq_00473f50();
}
