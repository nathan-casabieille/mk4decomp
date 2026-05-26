/**
 * Auto-split from misc_matchesZ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00475750 (62b)
 *   load g_eventQueueIdx, g_eventQueueEnd; cross-copy [+0x54] then [+0x5c].
 */
void DoubleScaledCrossStore_00475750(void) {
    unsigned int v;
    v = ((ScenegraphNode *)(g_eventQueueIdx * 4))->position_x;
    g_walkCallback = (void(*)(void))v;
    ((ScenegraphNode *)(g_eventQueueEnd * 4))->position_x = v;
    v = ((ScenegraphNode *)(g_eventQueueIdx * 4))->position_z;
    g_walkCallback = (void(*)(void))v;
    ((ScenegraphNode *)(g_eventQueueEnd * 4))->position_z = v;
}
