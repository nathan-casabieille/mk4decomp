/**
 * Auto-split from misc_matches2.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_currentNodeIdx;
extern unsigned int g_baseSel;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_baseSel (*(unsigned int *)MK4_VA(unsigned int, 0x542060u))
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_walkCallback (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_xformDirtyFlags (*(unsigned int *)MK4_VA(unsigned int, 0x54208cu))
#endif


/* @addr 0x00405430 (23b)
 *   mov     eax, [g_xformDirtyFlags]
 *   mov     [g_walkCallback], 0
 *   or      al, 4
 *   mov     [g_xformDirtyFlags], eax
 *   ret
 */
void ZeroAndDirty4(void) {
    unsigned int v = g_xformDirtyFlags;
    g_walkCallback = 0;
    g_xformDirtyFlags = v | 4;
}
