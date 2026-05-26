/**
 * Auto-split from misc_matchesH.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00470f30 (34b)
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   test    byte [g_xformDirtyFlags], 4
 *   je      .doit
 *   jmp     +0x44
 * .doit:
 *   jmp     +0x0f
 *   ret
 */
extern void DirtyToggleByGate_0048f350(void);
extern void GuardedBitChainCmpJmp_00470f90(void);
extern void ScaledAndCheckJmp_00470f60(void);
void CallDirty4DualJmp_00470f30(void) {
    DirtyToggleByGate_0048f350();
    if (g_framePauseFlag) return;
    if (g_xformDirtyFlags & 4) {
        GuardedBitChainCmpJmp_00470f90();
        return;
    }
    ScaledAndCheckJmp_00470f60();
}
