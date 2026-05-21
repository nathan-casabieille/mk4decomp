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

/* @addr 0x00470340 (76b)
 *   ecx = [fightGroupHead*4+0x18]; eax = walk + [ecx*4+0x34];
 *   stores eax both to g_eventQueueCurrent and back to [ecx*4+0x34];
 *   then eax = [fightGroupHead*4+0x58] - walk; same dual store.
 */
void DualFieldAddSubStore_00470340(void) {
    unsigned int s = *(unsigned int *)(g_fightGroupHead * 4 + 0x18);
    unsigned int v;
    g_scaledInit_00542044 = s;
    v = (unsigned int)g_walkCallback + *(unsigned int *)(s * 4 + 0x34);
    g_eventQueueCurrent = v;
    *(unsigned int *)(s * 4 + 0x34) = v;
    v = *(unsigned int *)(g_fightGroupHead * 4 + 0x58) - (unsigned int)g_walkCallback;
    g_eventQueueCurrent = v;
    *(unsigned int *)(g_fightGroupHead * 4 + 0x58) = v;
}
