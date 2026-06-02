/**
 * Auto-split from misc_matchesP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
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
extern void ScaledZeroFour(void);
extern void DirtyToggleByGate(void);
extern void CjInstallSelfRouter(void);
extern void Install3StateDualArmQuad(void);
void DualCallPauseDirtyDoubleJmp(void) {
    ScaledZeroFour();
    if (g_framePauseFlag != 0) return;
    DirtyToggleByGate();
    if (g_framePauseFlag != 0) return;
    if ((g_xformDirtyFlags & 4) != 0) {
        CjInstallSelfRouter();
        return;
    }
    Install3StateDualArmQuad();
}
