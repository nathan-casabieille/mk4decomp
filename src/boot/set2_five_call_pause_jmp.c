/**
 * Auto-split from misc_matchesMM.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;
#endif

/* @addr 0x0041fd10 (91b)
 *   call F0; set g_audioRestoreSlot3=2; call F1; pause → ret;
 *   call F2; pause → ret; call F3; pause → ret; call F4; pause → ret;
 *   call F5; pause → ret; jmp T.
 */
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_audioRestoreSlot3;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_audioRestoreSlot3 (*(unsigned int *)MK4_VA(unsigned int, 0x53a1f0u))
#define g_baseSel (*(unsigned int *)MK4_VA(unsigned int, 0x542060u))
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_framePauseFlag (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#endif

extern void Wrapper_OrListLoop_004d8e80(void);
extern void ZeroLargeBlock(void);
extern void GuardedSeq_BitmapBlitRunLength_then_FiveTableInitChainBracketed(void);
extern void SentinelInitTripleCall(void);
extern void GlobalsResetInit(void);
extern void Helper_TickFrameTail(void);
extern void OnceCall(void);
void Set2FiveCallPauseJmp(void) {
    Wrapper_OrListLoop_004d8e80();
    g_audioRestoreSlot3 = 2;
    ZeroLargeBlock();
    if (g_framePauseFlag) return;
    GuardedSeq_BitmapBlitRunLength_then_FiveTableInitChainBracketed();
    if (g_framePauseFlag) return;
    SentinelInitTripleCall();
    if (g_framePauseFlag) return;
    GlobalsResetInit();
    if (g_framePauseFlag) return;
    Helper_TickFrameTail();
    if (g_framePauseFlag) return;
    OnceCall();
}
