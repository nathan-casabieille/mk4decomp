/**
 * Auto-split from misc_matchesY.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_scaledInit_00542044;
extern unsigned int g_phaseTimer;

/* @addr 0x00451a60 (62b)
 *   call F1; pause → ret
 *   testb 4,[dirty]; je → ret
 *   call F2; pause → ret
 *   call F3; pause → ret
 *   mov [g_walkCallback], 0
 *   ret
 */
extern void SetJmp_ZeroAndDirty4(void);
extern void MStackPush2RunCountdown(void);
extern void MStackBracket7_DispatchAndChain(void);
void CallPauseTestByte4ZeroCB(void) {
    SetJmp_ZeroAndDirty4();
    if (g_framePauseFlag) return;
    if (!(g_xformDirtyFlags & 4)) return;
    MStackPush2RunCountdown();
    if (g_framePauseFlag) return;
    MStackBracket7_DispatchAndChain();
    if (g_framePauseFlag) return;
    g_walkCallback = 0;
}
