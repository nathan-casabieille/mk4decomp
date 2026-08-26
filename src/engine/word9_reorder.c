/**
 * Auto-split from misc_matchesPP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_currentNodeIdx;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#endif


/* @addr 0x004b3b30 (79b)
 *   Reorder-copy 9 16-bit words from arg0 to arg1 with a fixed
 *   permutation: src offsets 0,6,12,2,8,14,4,10,16 →
 *   dst offsets 0,2,4,6,8,10,12,14,16. Looks like a quat or
 *   matrix-row swizzle.
 */
void Word9Reorder(unsigned short *src, unsigned short *dst) {
    dst[0] = src[0];
    dst[1] = src[3];
    dst[2] = src[6];
    dst[3] = src[1];
    dst[4] = src[4];
    dst[5] = src[7];
    dst[6] = src[2];
    dst[7] = src[5];
    dst[8] = src[8];
}
