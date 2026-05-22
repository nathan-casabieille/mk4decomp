/**
 * Set-walk=2 + double-call pause-chain dispatcher.
 */
#include "engine/scenegraph.h"

/* @addr 0x004535e0 (53b)
 *   mov     [g_walkCallback], 2
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   test    byte [g_xformDirtyFlags], 4
 *   jne     +0x13
 *   call    F2
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     +5
 *   jmp     T
 *   ret
 */
extern unsigned int g_framePauseFlag;
extern void func_00455746(void);
extern void func_00455760(void);
extern void func_0042038f(void);
void Set2CallDirtyCallPauseJmp_004535e0(void) {
    g_walkCallback = (void (*)(void))2;
    func_00455746();
    if (g_framePauseFlag != 0) return;
    if ((g_xformDirtyFlags & 4) != 0) return;
    func_00455760();
    if (g_framePauseFlag != 0) return;
    func_0042038f();
}
