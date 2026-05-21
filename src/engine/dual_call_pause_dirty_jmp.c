/**
 * Auto-split from misc_matchesK.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00490c30 (43b)
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   test    byte [g_xformDirtyFlags], 1
 *   jne     +0x0e
 *   call    F2
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     +5
 *   jmp     T
 *   ret
 */
extern void GuardedDualAndFlagToggle_0048f020(void);
extern void func_00490371(void);
extern void func_0049126c(void);
void DualCallPauseDirtyJmp_00490c30(void) {
    GuardedDualAndFlagToggle_0048f020();
    if (g_framePauseFlag != 0) return;
    if ((g_xformDirtyFlags & 1) == 0) {
        func_00490371();
        if (g_framePauseFlag != 0) return;
    }
    func_0049126c();
}
