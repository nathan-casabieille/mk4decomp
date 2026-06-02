/**
 * Auto-split from misc_matchesK.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x0048fa20 (44b)
 *   mov     eax, [g_fightGroupHead]
 *   mov     [g_scaledInit_00542044], eax
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   call    F2
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     +5
 *   jmp     T
 *   ret
 */
extern void GuardedChainPushSetCallPop(void);
extern void ScaledZeroFour(void);
extern void MStackPushSet0004(void);
void StoreCallPauseCallPauseJmp(void) {
    g_scaledInit_00542044 = g_fightGroupHead;
    GuardedChainPushSetCallPop();
    if (g_framePauseFlag != 0) return;
    ScaledZeroFour();
    if (g_framePauseFlag != 0) return;
    MStackPushSet0004();
}
