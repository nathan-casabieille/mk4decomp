/**
 * Auto-split from misc_matchesO.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00480ef0 (47b)
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   test    byte [g_xformDirtyFlags], 4
 *   je      +0x17
 *   mov     ecx, [g_fightGroupHead]
 *   mov     eax, 7
 *   mov     [g_walkCallback], eax
 *   mov     [ecx*4 + 0x28], eax
 *   ret
 */
extern void func_004b85e0(void);
void CallPauseDirtyScaledSet7_00480ef0(void) {
    func_004b85e0();
    if (g_framePauseFlag != 0) return;
    if ((g_xformDirtyFlags & 4) == 0) return;
    g_walkCallback = (void (*)(void))7;
    *(unsigned int *)(g_fightGroupHead * 4 + 0x28) = 7;
}
