/**
 * Auto-split from misc_matchesPP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;

/* @addr 0x00470340 (76b)
 *   ecx = [fightGroupHead*4+0x18]; eax = walk + [ecx*4+0x34];
 *   stores eax both to g_eventQueueCurrent and back to [ecx*4+0x34];
 *   then eax = [fightGroupHead*4+0x58] - walk; same dual store.
 */
void DualFieldAddSubStore_00470340(void) {
    unsigned int s = ((ScenegraphNode *)(g_fightGroupHead * 4))->child_chain;
    unsigned int v;
    g_scaledInit_00542044 = s;
    v = (unsigned int)g_walkCallback + ((ScenegraphNode *)(s * 4))->state_mask;
    g_eventQueueCurrent = v;
    ((ScenegraphNode *)(s * 4))->state_mask = v;
    v = ((ScenegraphNode *)(g_fightGroupHead * 4))->position_y - (unsigned int)g_walkCallback;
    g_eventQueueCurrent = v;
    ((ScenegraphNode *)(g_fightGroupHead * 4))->position_y = v;
}
