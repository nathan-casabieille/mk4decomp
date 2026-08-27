/**
 * Auto-split from misc_matchesZ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_baseSel (*(unsigned int *)MK4_VA(unsigned int, 0x542060u))
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_eventQueueCurrent (*(unsigned int *)MK4_VA(unsigned int, 0x542070u))
#define g_eventQueueNotMask (*(unsigned int *)MK4_VA(unsigned int, 0x54207cu))
#define g_fightGroupHead (*(unsigned int *)MK4_VA(unsigned int, 0x54205cu))
#define g_matrixStackTop (*(unsigned int *)MK4_VA(unsigned int, 0x4d57acu))
#endif


/* @addr 0x00490290 (55b)
 *   load g_fightGroupHead, g_eventQueueNotMask; or eax with [ecx*4+0x40];
 *   store both eventQueueCurrent and back to [ecx*4+0x40];
 *   load g_matrixStackTop; pop top into eventQueueNotMask; dec ; store.
 */
void OrStoreDecStackPop(void) {
    FightGroupNode *n = (FightGroupNode *)MK4_PTR((g_fightGroupHead * 4));
    unsigned int v = g_eventQueueNotMask | n->bits;
    g_eventQueueCurrent = v;
    n->bits = v;
    g_eventQueueNotMask = *(unsigned int *)MK4_PTR((g_matrixStackTop * 4));
    g_matrixStackTop--;
}
