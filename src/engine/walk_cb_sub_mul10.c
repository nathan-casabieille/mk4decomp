/**
 * Auto-split from misc_matchesPP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_state_004d57ac;
extern unsigned int g_scaledInit_00542044;
extern u32 g_eventQueueWorkType;
extern packed_ptr g_xformEntityIdx;
extern u32 g_eventQueueEnd;
extern u32 g_tickW1;
extern packed_ptr g_fightGroupHead;

/* @addr 0x00431d50 (74b)
 *   walk = 0x1921f - walk; mov g_eventQueueWorkType = walk; call F1;
 *   pause → ret; g_acc_00542078 = walk; call F2; pause → ret;
 *   g_eventQueueWorkType = walk; ret.
 */
extern unsigned int g_acc_00542078;
extern void MStackMagicModMul10_00424410(void);
extern void ModMagicMul10Index_00424350(void);
void WalkCbSubMul10_00431d50(void) {
    unsigned int v = 0x1921f - (unsigned int)g_walkCallback;
    g_walkCallback = (void(*)(void))v;
    g_eventQueueWorkType = v;
    MStackMagicModMul10_00424410();
    if (g_framePauseFlag) return;
    g_acc_00542078 = (unsigned int)g_walkCallback;
    ModMagicMul10Index_00424350();
    if (g_framePauseFlag) return;
    g_eventQueueWorkType = (unsigned int)g_walkCallback;
}
