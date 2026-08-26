/**
 * Auto-split from misc_matchesD.c
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
#define g_fightGroupHead (*(unsigned int *)MK4_VA(unsigned int, 0x54205cu))
#define g_xformDirtyFlags (*(unsigned int *)MK4_VA(unsigned int, 0x54208cu))
#endif


/* @addr 0x00429730 (31b): same shape, or al,1 instead of and al,0xfe */
void ScaledStoreCurDirtyOr1(void) {
    unsigned int idx = g_fightGroupHead;
    ((ScenegraphNode *)(idx * 4))->queue_idx = g_eventQueueCurrent;
    g_xformDirtyFlags = g_xformDirtyFlags | 1;
}
