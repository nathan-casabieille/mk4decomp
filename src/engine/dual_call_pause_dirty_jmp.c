/**
 * Auto-split from misc_matchesH.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00435f20 (43b)
 *   call    F
 *   test    eax, eax
 *   jne     .skip2
 *   call    F2
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   test    byte [g_xformDirtyFlags], 1
 *   je      .ret
 *   jmp     T1
 * .skip2:
 *   jmp     +6
 *   ret
 */
extern int func_004395b0(void);
extern void func_00439600(void);
extern void func_0043625b(void);
extern void func_00435f4d(void);
void DualCallPauseDirtyJmp_00435f20(void) {
    if (func_004395b0() != 0) {
        return;
    }
    func_00439600();
    if (g_framePauseFlag != 0) {
        return;
    }
    if ((g_xformDirtyFlags & 1) != 0) {
        func_0043625b();
    } else {
        func_00435f4d();
    }
}
