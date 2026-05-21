/**
 * Auto-split from misc_matchesK.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00491990 (44b)
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   mov     eax, [g_state_0053a51c]
 *   mov     [g_walkCallback], eax
 *   call    F2
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     +5
 *   jmp     T
 *   ret
 */
extern unsigned int g_state_0053a51c;
extern int GuardedScaledLookupCallJmp_004220a0(void);
extern void func_0042a330(void);
extern void func_0049199a(void);
void TwoCallStatePauseJmp_00491990(void) {
    GuardedScaledLookupCallJmp_004220a0();
    if (g_framePauseFlag != 0) return;
    g_walkCallback = (void (*)(void))g_state_0053a51c;
    func_0042a330();
    if (g_framePauseFlag != 0) return;
    func_0049199a();
}
