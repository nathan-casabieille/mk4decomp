/**
 * Auto-split from misc_matchesLL.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00445fb0 (70b)
 *   load g_eventQueueIdx; set walk=0xa, store eax → g_fightGroupHead;
 *   call F; pause → ret;
 *   copy g_scaledInit → g_xformEntityIdx; baseSel*4 + 0x5c → g_scaledInit; jmp T.
 */
extern void func_00408c98(void);
extern void func_004084d0(void);
void SetWalk0xaCrossStore_00445fb0(void) {
    g_fightGroupHead = g_eventQueueIdx;
    g_walkCallback = (void (*)(void))0xa;
    func_00408c98();
    if (g_framePauseFlag != 0) return;
    g_xformEntityIdx = g_scaledInit_00542044;
    g_scaledInit_00542044 = *(unsigned int *)(g_baseSel_00542060 * 4 + 0x5c);
    func_004084d0();
}
