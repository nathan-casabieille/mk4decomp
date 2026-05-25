/**
 * Auto-split from misc_matchesLL.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x0041aa80 (70b)
 *   set workType = 2; pendingNodeType = 0x4d7b28>>2; call F;
 *   pause → ret; testb 4,[dirty] → ret;
 *   load g_xformEntityIdx; set walk = 0x14ccc and store at [ecx*4 + 0x48]; ret.
 */
extern unsigned int g_data_004d7b28;
extern void func_00419190(void);
void SetWorkTypeScaledCallStoreCcc_0041aa80(void) {
    g_eventQueueWorkType = 2;
    g_pendingNodeType = (unsigned int)&g_data_004d7b28 >> 2;
    func_00419190();
    if (g_framePauseFlag != 0) return;
    if ((g_xformDirtyFlags & 4) != 0) return;
    g_walkCallback = (void (*)(void))0x14ccc;
    *(unsigned int *)(g_xformEntityIdx * 4 + 0x48) = 0x14ccc;
}
