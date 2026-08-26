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
#define g_framePauseFlag (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_matrixStackTop (*(unsigned int *)MK4_VA(unsigned int, 0x4d57acu))
#define g_walkCallback (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#endif


/* @addr 0x00460260 (66b)
 *   call F1; pause → ret; call F2; pause → ret;
 *   set walk = 0xc; inc g_matrixStackTop;
 *   push 0x004602b0 onto stack[idx*4]; jmp T.
 */
extern void ScaledZeroFour(void);
extern void ScaledInit_GuardedDirtyXformFromTable_g_scaledInit(void);
extern void func_004602b0_pp(void);
extern void MstackPopScaledChainPlusThunks(void);
void GuardedDoubleCallSetJmp(void) {
    unsigned int top;
    ScaledZeroFour();
    if (g_framePauseFlag != 0) {
        return;
    }
    ScaledInit_GuardedDirtyXformFromTable_g_scaledInit();
    if (g_framePauseFlag != 0) {
        return;
    }
    top = g_matrixStackTop;
    g_walkCallback = (void (*)(void))0x0c;
    top++;
    g_matrixStackTop = top;
    *(unsigned int *)(top * 4) = (unsigned int)&func_004602b0_pp;
    MstackPopScaledChainPlusThunks();
}
