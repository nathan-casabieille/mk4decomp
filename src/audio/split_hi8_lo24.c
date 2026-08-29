/**
 * Auto-split from misc_matches8.c
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
#define g_walkCallback (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_xformEntityIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542048u))
#endif


/* @addr 0x004abfc0 (27b)
 *   mov     eax, [g_eventQueueCurrent]
 *   mov     ecx, eax
 *   and     eax, 0x00ffffff
 *   shr     ecx, 0x18
 *   mov     [g_eventQueueCurrent], ecx
 *   mov     [g_xformEntityIdx], eax
 *   ret
 */
void SplitHi8Lo24(void) {
    unsigned int v = *(unsigned int *)&g_walkCallback;
    g_eventQueueCurrent = v >> 24;
    g_xformEntityIdx = v & 0x00ffffff;
}
