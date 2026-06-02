/**
 * Auto-split from misc_matchesMM.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x0041fd10 (91b)
 *   call F0; set g_audioRestoreSlot3_0053a1f0=2; call F1; pause → ret;
 *   call F2; pause → ret; call F3; pause → ret; call F4; pause → ret;
 *   call F5; pause → ret; jmp T.
 */
extern unsigned int g_audioRestoreSlot3_0053a1f0;
extern void Wrapper_OrListLoop_004d8e80(void);
extern void ZeroLargeBlock(void);
extern void GuardedSeq_004335d0(void);
extern void SentinelInitTripleCall(void);
extern void GlobalsResetInit(void);
extern void Helper_TickFrameTail(void);
extern void OnceCall(void);
void Set2FiveCallPauseJmp(void) {
    Wrapper_OrListLoop_004d8e80();
    g_audioRestoreSlot3_0053a1f0 = 2;
    ZeroLargeBlock();
    if (g_framePauseFlag) return;
    GuardedSeq_004335d0();
    if (g_framePauseFlag) return;
    SentinelInitTripleCall();
    if (g_framePauseFlag) return;
    GlobalsResetInit();
    if (g_framePauseFlag) return;
    Helper_TickFrameTail();
    if (g_framePauseFlag) return;
    OnceCall();
}
