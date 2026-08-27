/**
 * Auto-split from misc_matchesMM.c
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
#define g_currentNodeFlags (*(unsigned int *)MK4_VA(unsigned int, 0x542084u))
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_framePauseFlag (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_matrixStackTop (*(unsigned int *)MK4_VA(unsigned int, 0x4d57acu))
#endif


/* @addr 0x00438b90 (91b)
 *   push g_currentNodeFlags onto stack[idx*4]; 3-call pause chain;
 *   pop stack value back into g_currentNodeFlags.
 */
extern void ScaledZeroFour(void);
extern void DualCallPauseDirtyJmp_00490c30(void);
extern void CallPauseScaledStoreCopyJmp(void);
void PushPop84TripleCall(void) {
    g_matrixStackTop++;
    *(unsigned int *)MK4_PTR((g_matrixStackTop * 4)) = g_currentNodeFlags;
    ScaledZeroFour();
    if (g_framePauseFlag != 0) {
        return;
    }
    DualCallPauseDirtyJmp_00490c30();
    if (g_framePauseFlag != 0) {
        return;
    }
    CallPauseScaledStoreCopyJmp();
    if (g_framePauseFlag != 0) {
        return;
    }
    g_currentNodeFlags = *(unsigned int *)MK4_PTR((g_matrixStackTop * 4));
    g_matrixStackTop--;
}
