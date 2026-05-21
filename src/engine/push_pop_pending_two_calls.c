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

/* @addr 0x0042f4f0 (75b)
 *   PushPop save/restore of g_pendingNodeType across two
 *   push-arg calls (0x249, 0x24a) to SaveCallRestore_004049d0.
 */
extern void SaveCallRestore_004049d0(int);
void PushPopPendingTwoCalls_0042f4f0(void) {
    unsigned int top;
    top = g_state_004d57ac + 1;
    g_state_004d57ac = top;
    *(unsigned int *)(top * 4) = g_pendingNodeType;
    SaveCallRestore_004049d0(0x249);
    SaveCallRestore_004049d0(0x24a);
    top = g_state_004d57ac;
    g_pendingNodeType = *(unsigned int *)(top * 4);
    g_state_004d57ac = top - 1;
}
