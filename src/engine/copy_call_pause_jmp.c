/**
 * 2 "copy-call-pause-jmp" helpers (30 bytes each).
 *
 * Pattern:
 *   mov     eax, [g_A]
 *   mov     [g_B], eax
 *   call    Func
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     skip
 *   jmp     Tail
 * skip:
 *   ret
 *
 * MSVC SP3 /O2 produces this exact layout from:
 *   g_B = g_A; Func(); if (g_framePauseFlag) return; Tail();
 * (tail-call optimization turns the final void(void) call into jmp.)
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_currentNodeIdx;

extern void TierBranchChain(void);
extern void MStackPush3TripleMul10WithAbs(void);
extern void MStackPush2ChainLLInsert(void);
extern void StackPopDispatchTagged(void);

/* @addr 0x0048b4e0 */
void CopyCallPauseJmp_TierBranchChain_then_MStackPush3TripleMul10WithAbs(void) {
    g_eventQueueWorkType = g_eventQueueChild;
    TierBranchChain();
    if (g_framePauseFlag) return;
    MStackPush3TripleMul10WithAbs();
}

/* @addr 0x004a19a0 */
void CopyCallPauseJmp_MStackPush2ChainLLInsert_then_StackPopDispatchTagged(void) {
    g_currentNodeIdx = g_fightGroupHead;
    MStackPush2ChainLLInsert();
    if (g_framePauseFlag) return;
    StackPopDispatchTagged();
}
