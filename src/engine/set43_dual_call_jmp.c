/**
 * Auto-split from misc_matchesL.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x0049a620 (44b)
 *   mov     [g_walkCallback], 0x43
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
extern void func_00489fe6_l(void);
extern void BootOneShotSetup_0040bde0(void);
extern void GuardedSeq_0049a650(void);
void Set43DualCallJmp_0049a620(void) {
    g_walkCallback = (void (*)(void))0x43;
    func_00489fe6_l();
    if (g_framePauseFlag != 0) return;
    BootOneShotSetup_0040bde0();
    if (g_framePauseFlag != 0) return;
    GuardedSeq_0049a650();
}
