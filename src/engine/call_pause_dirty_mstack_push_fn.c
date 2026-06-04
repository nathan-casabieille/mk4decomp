/**
 * Auto-split from misc_matchesV.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;
extern unsigned int g_chainAccumCur;

/* @addr 0x0046e2a0 (56b)
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     +0x29
 *   test    byte [g_xformDirtyFlags], 4
 *   je      +0x1b
 *   mov     eax, [g_matrixStackTop]
 *   inc     eax
 *   mov     [g_matrixStackTop], eax
 *   mov     [eax*4 + 0], 0x0046e2e0
 *   jmp     T
 *   jmp     +9
 *   ret
 */
extern void DirtyToggleByGate(void);
extern void PendingMatch_SlotEvent3EntryChain(void);
extern void GameDispatchValidateState(void);
extern void PendingMatch_SlotEvent3EntryChain(void);
void CallPauseDirtyMStackPushFn(void) {
    unsigned int top;
    DirtyToggleByGate();
    if (g_framePauseFlag != 0) return;
    if ((g_xformDirtyFlags & 4) != 0) {
        top = g_matrixStackTop + 1;
        g_matrixStackTop = top;
        *(unsigned int *)(top * 4) = (unsigned int)&PendingMatch_SlotEvent3EntryChain;
        GameDispatchValidateState();
        return;
    }
    PendingMatch_SlotEvent3EntryChain();
}
