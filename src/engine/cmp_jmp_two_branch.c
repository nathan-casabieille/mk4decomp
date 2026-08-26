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
#define g_eventQueueChild (*(unsigned int *)MK4_VA(unsigned int, 0x542080u))
#endif


/* @addr 0x004871d0 (19b)
 *   cmp     [g_eventQueueChild], 5
 *   jge     +5
 *   jmp     T1
 *   jmp     T2
 */
extern void Wrapper_ScaledChainPushCall_004ef900(void);
extern void Wrapper_ScaledChainPushCall_004ef910(void);
void CmpJmpTwoBranch(void) {
    if ((int)g_eventQueueChild < 5) {
        Wrapper_ScaledChainPushCall_004ef900();
        return;
    }
    Wrapper_ScaledChainPushCall_004ef910();
}
