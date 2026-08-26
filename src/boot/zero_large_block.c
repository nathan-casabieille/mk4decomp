/**
 * Auto-split from misc_matches5.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_currentNodeIdx;
extern unsigned int g_baseSel;
extern unsigned int g_extra_0052ab3c;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_baseSel (*(unsigned int *)MK4_VA(unsigned int, 0x542060u))
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_extra_0052ab3c (*(unsigned int *)MK4_VA(unsigned int, 0x52ab3cu))
#define g_nodeSlotsArea (*(unsigned int *)MK4_VA(unsigned int, 0x53e368u))
#endif


void ZeroLargeBlock(void) {
    g_extra_0052ab3c = 0;
    memset(g_nodeSlotsArea, 0, 0x0e80 * 4);
}
