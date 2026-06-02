/**
 * Auto-split from misc_matchesLL.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00445fb0 (70b)
 *   load g_eventQueueIdx; set walk=0xa, store eax → g_fightGroupHead;
 *   call F; pause → ret;
 *   copy g_scaledInit → g_xformEntityIdx; baseSel*4 + 0x5c → g_scaledInit; jmp T.
 */
extern void DirtyDoubleDeref(void);
extern void PushPopScaled1cDoubleCall(void);
void SetWalk0xaCrossStore(void) {
    g_fightGroupHead = g_eventQueueIdx;
    g_walkCallback = (void (*)(void))0xa;
    DirtyDoubleDeref();
    if (g_framePauseFlag != 0) return;
    g_xformEntityIdx = g_scaledInit_00542044;
    g_scaledInit_00542044 = *(unsigned int *)(g_baseSel * 4 + 0x5c);
    PushPopScaled1cDoubleCall();
}
