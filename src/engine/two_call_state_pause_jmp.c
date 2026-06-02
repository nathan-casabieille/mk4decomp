/**
 * Auto-split from misc_matchesK.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00491990 (44b)
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   mov     eax, [g_counter_0053a51c]
 *   mov     [g_walkCallback], eax
 *   call    F2
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     +5
 *   jmp     T
 *   ret
 */
extern unsigned int g_counter_0053a51c;
extern void IncOrZero9(void);
extern void TablePushAccumTailJmp(void);
extern void RoundStartCluster_RemapWalkAndJmp(void);
void TwoCallStatePauseJmp(void) {
    IncOrZero9();
    if (g_framePauseFlag != 0) return;
    g_walkCallback = (void (*)(void))g_counter_0053a51c;
    TablePushAccumTailJmp();
    if (g_framePauseFlag != 0) return;
    RoundStartCluster_RemapWalkAndJmp();
}
