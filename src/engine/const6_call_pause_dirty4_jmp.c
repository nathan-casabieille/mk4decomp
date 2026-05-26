/**
 * Auto-split from misc_matchesH.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00453510 (39b): same shape, value=6 */
extern void CallPauseScaledStoreXJmp_00453750(void);
extern void GuardedSeq_00453780(void);
void Const6Call_PauseDirty4_Jmp_00453510(void) {
    g_walkCallback = (void(*)(void))6;
    CallPauseScaledStoreXJmp_00453750();
    if (g_framePauseFlag) return;
    if (g_xformDirtyFlags & 4) return;
    GuardedSeq_00453780();
}
