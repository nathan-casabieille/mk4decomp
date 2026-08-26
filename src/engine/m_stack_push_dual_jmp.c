/**
 * Auto-split from misc_matchesT.c
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
#define g_matrixStackTop (*(unsigned int *)MK4_VA(unsigned int, 0x4d57acu))
#endif

extern void Dirty4Branch_MStackPushDual_StackPop_00428390(void);
extern void EsiInstallChainCallIndirect(void);

void MStackPushDualJmp(void) {
    int top = g_matrixStackTop;
    top++;
    g_matrixStackTop = top;
    *(void(**)(void))((unsigned int)top * 4) = Dirty4Branch_MStackPushDual_StackPop_00428390;
    EsiInstallChainCallIndirect();
}
