/**
 * Auto-split from misc_matchesP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00486fc0 (48b)
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   call    F2
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   test    byte [g_xformDirtyFlags], 4
 *   je      +5
 *   jmp     T1
 *   jmp     T2
 *   ret
 */
extern void func_00487640(void);
extern void func_00487358(void);
extern void CjInstallSelfRouter_00470480(void);
extern void Install3StateDualArmQuad_004602b0(void);
void DualCallPauseDirtyDoubleJmp_00486fc0(void) {
    func_00487640();
    if (g_framePauseFlag != 0) return;
    func_00487358();
    if (g_framePauseFlag != 0) return;
    if ((g_xformDirtyFlags & 4) != 0) {
        CjInstallSelfRouter_00470480();
        return;
    }
    Install3StateDualArmQuad_004602b0();
}
