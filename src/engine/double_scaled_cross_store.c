/**
 * Auto-split from misc_matchesZ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;
extern unsigned int g_state_004d57ac;
extern packed_ptr g_fightGroupHead;
extern u32 g_eventQueueNotMask;

/* @addr 0x00475750 (62b)
 *   load g_eventQueueIdx, g_eventQueueEnd; cross-copy [+0x54] then [+0x5c].
 */
void DoubleScaledCrossStore_00475750(void) {
    unsigned int v;
    v = *(unsigned int *)(g_eventQueueIdx * 4 + 0x54);
    g_walkCallback = (void(*)(void))v;
    *(unsigned int *)(g_eventQueueEnd * 4 + 0x54) = v;
    v = *(unsigned int *)(g_eventQueueIdx * 4 + 0x5c);
    g_walkCallback = (void(*)(void))v;
    *(unsigned int *)(g_eventQueueEnd * 4 + 0x5c) = v;
}
