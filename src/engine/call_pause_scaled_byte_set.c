/**
 * Auto-split from misc_matchesFF.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;
extern packed_ptr g_xformEntityIdx;

/* @addr 0x0043c350 (62b)
 *   call F; pause-test → ret;
 *   load baseSel, scaled +0x38 → g_eventQueueEnd;
 *   testb 1,[g_xformDirtyFlags]; set g_eventQueueChild based on dirty bit.
 */
extern void MStackPush2ChainSwap_0048f090(void);
void CallPauseScaledByteSet_0043c350(void) {
    MStackPush2ChainSwap_0048f090();
    if (g_framePauseFlag != 0) {
        return;
    }
    g_eventQueueEnd = *(unsigned int *)(g_baseSel_00542060 * 4 + 0x38);
    g_eventQueueChild = 0xffff0000;
    if ((g_xformDirtyFlags & 1) != 0) {
        g_eventQueueChild = 0x10000;
    }
}
