/**
 * Auto-split from misc_matchesH.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00438ca0 (44b)
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   test    byte [g_xformDirtyFlags], 1
 *   je      +5
 *   jmp     +0x2a4
 *   mov     [g_walkCallback], 0x0c
 *   jmp     +0x384c5
 *   ret
 */
extern void func_00482ec0(void);
extern void func_0049f4ad(void);
extern void func_0046f170(void);
void CallPauseDirtyConstJmp_00438ca0(void) {
    func_00482ec0();
    if (g_framePauseFlag) return;
    if (g_xformDirtyFlags & 1) {
        func_0049f4ad();
        return;
    }
    g_walkCallback = (void(*)(void))0x0c;
    func_0046f170();
}
