/**
 * Auto-split from misc_matchesH.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004534e0 (39b)
 *   mov     [g_walkCallback], 5
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   test    byte [g_xformDirtyFlags], 4
 *   jne     .ret
 *   jmp     T
 *   ret
 */
extern void CallPauseScaledStoreXJmp_00453750(void);
extern void GuardedSeq_00453780(void);
void Const5Call_PauseDirty4_Jmp_004534e0(void) {
    g_walkCallback = (void(*)(void))5;
    CallPauseScaledStoreXJmp_00453750();
    if (g_framePauseFlag) return;
    if (g_xformDirtyFlags & 4) return;
    GuardedSeq_00453780();
}
