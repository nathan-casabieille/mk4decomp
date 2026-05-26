/**
 * Auto-split from misc_matchesZ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00490290 (55b)
 *   load g_fightGroupHead, g_eventQueueNotMask; or eax with [ecx*4+0x40];
 *   store both eventQueueCurrent and back to [ecx*4+0x40];
 *   load g_matrixStackTop; pop top into eventQueueNotMask; dec ; store.
 */
void OrStoreDecStackPop_00490290(void) {
    FightGroupNode *n = (FightGroupNode *)(g_fightGroupHead * 4);
    unsigned int v = g_eventQueueNotMask | n->bits;
    g_eventQueueCurrent = v;
    n->bits = v;
    g_eventQueueNotMask = *(unsigned int *)(g_matrixStackTop * 4);
    g_matrixStackTop--;
}
