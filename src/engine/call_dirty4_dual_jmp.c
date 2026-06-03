/**
 * Auto-split from misc_matchesH.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

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
extern void DirtyToggleByGate(void);
extern void GuardedBitChainCmpJmp(void);
extern void ScaledAndCheckJmp(void);
void CallDirty4DualJmp(void) {
    DirtyToggleByGate();
    if (g_framePauseFlag) return;
    if (g_xformDirtyFlags & 4) {
        GuardedBitChainCmpJmp();
        return;
    }
    ScaledAndCheckJmp();
}
