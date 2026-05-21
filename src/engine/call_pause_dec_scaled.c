/**
 * Auto-split from misc_matchesD.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00428650 (41b)
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   mov     ecx, [g_fightGroupHead]
 *   mov     eax, [ecx*4 + 0x28]
 *   dec     eax
 *   mov     [g_walkCallback], eax
 *   mov     [ecx*4 + 0x28], eax
 *   ret
 */
extern void func_0040592c(void);
void CallPauseDecScaled_00428650(void) {
    unsigned int idx;
    unsigned int v;
    func_0040592c();
    if (g_framePauseFlag) return;
    idx = g_fightGroupHead;
    v = *(unsigned int *)(idx * 4 + 0x28) - 1;
    g_walkCallback = (void (*)(void))v;
    *(unsigned int *)(idx * 4 + 0x28) = v;
}
