/**
 * Auto-split from misc_matches3.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_currentNodeIdx;
#endif

/* @addr 0x00409280 (22b)
 *   mov     eax, [g_walkCallback]
 *   and     eax, 0xf
 *   shl     eax, 0x14
 *   mov     [g_walkCallback], eax
 *   mov     [g_X], eax
 *   ret
 */
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_dest_0053a6e4;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_dest_0053a6e4 (*(unsigned int *)MK4_VA(unsigned int, 0x53a6e4u))
#define g_walkCallback (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#endif

void AndShlStore(void) {
    unsigned int v = ((unsigned int)g_walkCallback & 0xf) << 0x14;
    g_walkCallback  = v;
    g_dest_0053a6e4 = v;
}
