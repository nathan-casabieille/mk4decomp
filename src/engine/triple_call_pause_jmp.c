/**
 * Auto-split from misc_matchesO.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00470500 (48b)
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   call    F2
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret2
 *   call    F3
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     +5
 *   jmp     T
 *   ret
 */
extern void ZeroThreeSlots_00490780(void);
extern void InitThreeFields_00490e90(void);
extern void DualCallPauseDirtyJmp_00490c30(void);
extern void ScaledChainNegStore_00470310(void);
void TripleCallPauseJmp_00470500(void) {
    ZeroThreeSlots_00490780();
    if (g_framePauseFlag != 0) return;
    InitThreeFields_00490e90();
    if (g_framePauseFlag != 0) return;
    DualCallPauseDirtyJmp_00490c30();
    if (g_framePauseFlag != 0) return;
    ScaledChainNegStore_00470310();
}
