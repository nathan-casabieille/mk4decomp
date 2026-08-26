/**
 * Auto-split from misc_matchesY.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;
extern unsigned int g_phaseTimer;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_baseSel (*(unsigned int *)MK4_VA(unsigned int, 0x542060u))
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_fightGroupHead (*(unsigned int *)MK4_VA(unsigned int, 0x54205cu))
#define g_matrixStackTop (*(unsigned int *)MK4_VA(unsigned int, 0x4d57acu))
#define g_phaseTimer (*(unsigned int *)MK4_VA(unsigned int, 0x537e94u))
#endif


/* @addr 0x00474010 (63b)
 *   inc g_matrixStackTop twice, push g_currentNodeIdx and g_fightGroupHead
 *   onto stack[idx*4]; mov g_currentNodeIdx = 0x7c; jmp T.
 */
extern void HalveChainTriplePop2(void);
void DoubleStackPushAndJmp(void) {
    g_matrixStackTop++;
    *(unsigned int *)(g_matrixStackTop * 4) = g_currentNodeIdx;
    g_matrixStackTop++;
    *(unsigned int *)(g_matrixStackTop * 4) = g_fightGroupHead;
    g_currentNodeIdx = 0x7c;
    HalveChainTriplePop2();
}
