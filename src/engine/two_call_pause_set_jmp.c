/**
 * Auto-split from misc_matchesT.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

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
 *   mov     [g_acc_00542078], 2
 *   jmp     T
 *   ret
 */
extern unsigned int g_acc_00542078;
extern void MStackPush2RunCountdown_004089e0(void);
extern void MStackBracket7_DispatchAndChain_004b8fa0(void);
extern void GuardedSeq_00473f50(void);
void TwoCallPauseSetJmp_00445e80(void) {
    MStackPush2RunCountdown_004089e0();
    if (g_framePauseFlag != 0) return;
    MStackBracket7_DispatchAndChain_004b8fa0();
    if (g_framePauseFlag != 0) return;
    g_walkCallback = (void (*)(void))3;
    g_acc_00542078 = 2;
    GuardedSeq_00473f50();
}
