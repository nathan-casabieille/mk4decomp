/**
 * Auto-split from misc_matchesN.c
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
#endif


/* @addr 0x00405880 (49b)
 *   mov     ecx, [g_currentNodeIdx]
 *   mov     edx, [g_walkCallback]
 *   mov     [g_eventQueueCurrent], 0xfffffff0
 *   mov     eax, [ecx*4 + 0x20]
 *   and     eax, 0xfffffff0
 *   or      eax, edx
 *   mov     [g_eventQueueCurrent], eax
 *   mov     [ecx*4 + 0x20], eax
 *   ret
 */
#ifdef NON_MATCHING
#include "portable/mem_model.h"
/* NATIVE twin: same body through the node seam. Replaces the node's
 * entry-type nibble (bits 24-27 of +0x20) with the walk value, leaving
 * the rest of the word alone; the counter global carries the mask first
 * and the result after, which is what the original's two stores do. */
void ScaledMaskOrStore(void)
{
    unsigned int v;

    g_eventQueueCurrent = 0xf0ffffffu;
    v = (MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x20) & 0xf0ffffffu)
        | g_walkCallback;
    g_eventQueueCurrent = v;
    MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x20) = v;
}
#else
void ScaledMaskOrStore(void) {
    unsigned int idx = g_currentNodeIdx;
    unsigned int walk = (unsigned int)g_walkCallback;
    unsigned int v;
    g_eventQueueCurrent = 0xf0ffffff;
    v = (((ScenegraphNode *)(idx * 4))->flags & 0xf0ffffff) | walk;
    g_eventQueueCurrent = v;
    ((ScenegraphNode *)(idx * 4))->flags = v;
}
#endif
