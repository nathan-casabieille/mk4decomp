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

/* @addr 0x00490290 (55b)
 *   load g_fightGroupHead, g_eventQueueNotMask; or eax with [ecx*4+0x40];
 *   store both eventQueueCurrent and back to [ecx*4+0x40];
 *   load g_state_004d57ac; pop top into eventQueueNotMask; dec ; store.
 */
void OrStoreDecStackPop_00490290(void) {
    unsigned int v = g_eventQueueNotMask | *(unsigned int *)(g_fightGroupHead * 4 + 0x40);
    g_eventQueueCurrent = v;
    *(unsigned int *)(g_fightGroupHead * 4 + 0x40) = v;
    g_eventQueueNotMask = *(unsigned int *)(g_state_004d57ac * 4);
    g_state_004d57ac--;
}
