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

/* @addr 0x00489030 (74b)
 *   Save fightGroupHead → g_pendingNodeType (used as scratch);
 *   load [baseSel*4+0x38] → fightGroupHead; walk = 0x10000;
 *   eventQueueCurrent = 0x3c; call F; if !pause: restore
 *   fightGroupHead from g_pendingNodeType; ret.
 */
extern unsigned int g_baseSel_00542060;
extern void GatedScaledSubSat_0048fb40(void);
void SaveSwapCallRestore_00489030(void) {
    g_pendingNodeType = g_fightGroupHead;
    g_fightGroupHead = *(unsigned int *)(g_baseSel_00542060 * 4 + 0x38);
    g_walkCallback = (void (*)(void))0x10000;
    g_eventQueueCurrent = 0x3c;
    GatedScaledSubSat_0048fb40();
    if (g_framePauseFlag != 0) return;
    g_fightGroupHead = g_pendingNodeType;
}
