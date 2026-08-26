/**
 * Auto-split from misc_matches4.c
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
#define g_framePauseFlag (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#endif


/* @addr 0x0041f830 (16b)
 *   call    F
 *   mov     [g_framePauseFlag], 1
 *   ret
 */
extern void ScaledNeg1SetPause(void);
void CallSetPause(void) {
    ScaledNeg1SetPause();
    g_framePauseFlag = 1;
}
