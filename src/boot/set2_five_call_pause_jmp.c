/**
 * Auto-split from misc_matchesMM.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x0041fd10 (91b)
 *   call F0; set g_audioRestoreSlot3_0053a1f0=2; call F1; pause → ret;
 *   call F2; pause → ret; call F3; pause → ret; call F4; pause → ret;
 *   call F5; pause → ret; jmp T.
 */
extern unsigned int g_audioRestoreSlot3_0053a1f0;
extern void Wrapper_0041fd00(void);
extern void ZeroLargeBlock_0041f270(void);
extern void GuardedSeq_004335d0(void);
extern void func_00481fc0(void);
extern void GlobalsResetInit_004222a0(void);
extern void Helper_TickFrameTail(void);
extern void OnceCall_00401340(void);
void Set2FiveCallPauseJmp_0041fd10(void) {
    Wrapper_0041fd00();
    g_audioRestoreSlot3_0053a1f0 = 2;
    ZeroLargeBlock_0041f270();
    if (g_framePauseFlag) return;
    GuardedSeq_004335d0();
    if (g_framePauseFlag) return;
    func_00481fc0();
    if (g_framePauseFlag) return;
    GlobalsResetInit_004222a0();
    if (g_framePauseFlag) return;
    Helper_TickFrameTail();
    if (g_framePauseFlag) return;
    OnceCall_00401340();
}
