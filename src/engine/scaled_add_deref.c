/**
 * Auto-split from misc_matchesK.c
 */
#include "engine/scenegraph.h"
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#endif
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
#define g_walkCallback (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#endif


/* @addr 0x00494800 (39b)
 *   mov     eax, [g_baseSel]
 *   mov     ecx, [g_walkCallback]
 *   mov     eax, [eax*4 + 0x30]
 *   add     eax, ecx
 *   mov     [g_currentNodeIdx], eax
 *   mov     ecx, [eax*4 + 0]
 *   mov     [g_currentNodeIdx], ecx
 *   ret
 */
void ScaledAddDeref(void) {
    unsigned int idx;
#ifdef MK4_ARENA
    idx = MK4_NODE_AT(unsigned int, g_baseSel, 0x30) + (unsigned int)g_walkCallback;
    g_currentNodeIdx = idx;
    g_currentNodeIdx = *MK4_NODE(unsigned int, idx);
#else
    idx = *(unsigned int *)(g_baseSel * 4 + 0x30) + (unsigned int)g_walkCallback;
    g_currentNodeIdx = idx;
    g_currentNodeIdx = *(unsigned int *)(idx * 4);
#endif
}
