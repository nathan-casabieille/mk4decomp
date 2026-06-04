/**
 * Auto-split from misc_matchesT.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x00445e80 (54b)
 *   call    F1
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   call    F2
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     +0x19
 *   mov     [g_walkCallback], 3
 *   mov     [g_chainAccumCur], 2
 *   jmp     T
 *   ret
 */
extern unsigned int g_chainAccumCur;
extern void MStackPush2RunCountdown(void);
extern void MStackBracket7_DispatchAndChain(void);
extern void GuardedSeq_DualSetShiftCall_then_DualPushSet7dCallPop(void);
void TwoCallPauseSetJmp(void) {
    MStackPush2RunCountdown();
    if (g_framePauseFlag != 0) return;
    MStackBracket7_DispatchAndChain();
    if (g_framePauseFlag != 0) return;
    g_walkCallback = (void (*)(void))3;
    g_chainAccumCur = 2;
    GuardedSeq_DualSetShiftCall_then_DualPushSet7dCallPop();
}
