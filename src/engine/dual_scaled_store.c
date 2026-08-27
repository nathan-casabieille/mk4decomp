/**
 * Auto-split from misc_matchesH.c
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
#define g_eventQueueEnd (*(unsigned int *)MK4_VA(unsigned int, 0x542054u))
#define g_eventQueueIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542058u))
#endif


/* @addr 0x00452740 (37b)
 *   mov     eax, [g_baseSel]
 *   mov     ecx, [g_eventQueueEnd]
 *   mov     [eax*4 + 0x64], ecx
 *   mov     edx, [g_baseSel]
 *   mov     eax, [g_eventQueueIdx]
 *   mov     [edx*4 + 0x68], eax
 *   ret
 */
void DualScaledStore(void) {
    *(unsigned int *)MK4_PTR((g_baseSel * 4 + 0x64)) = g_eventQueueEnd;
    *(unsigned int *)MK4_PTR((g_baseSel * 4 + 0x68)) = g_eventQueueIdx;
}
