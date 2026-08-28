/**
 * Auto-split from misc_matchesB.c
 */
#include "engine/scenegraph.h"

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_currentNodeIdx;
#endif

/* @addr 0x004ac1f0 (11b)
 *   mov     eax, [g_walkCallback]
 *   mov     [g_target_0053a6fc], eax
 *   ret
 */
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_target_0053a6fc;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_target_0053a6fc (*(unsigned int *)MK4_VA(unsigned int, 0x53a6fcu))
#define g_walkCallback (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#endif

void CopyGlobal(void) {
    g_target_0053a6fc = (unsigned int)g_walkCallback;
}
