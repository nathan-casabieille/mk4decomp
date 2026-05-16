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

extern unsigned int g_scaledInit_00542044;

extern void TierBranchChain_0048b6c0(void);
extern void MStackPush3TripleMul10WithAbs_0048b500(void);
extern void MStackPush2ChainLLInsert_00406790(void);
extern void StackPopDispatchTagged_0041f780(void);

/* @addr 0x0048b4e0 */
void CopyCallPauseJmp_0048b4e0(void) {
    g_eventQueueWorkType = g_eventQueueChild;
    TierBranchChain_0048b6c0();
    if (g_framePauseFlag) return;
    MStackPush3TripleMul10WithAbs_0048b500();
}

/* @addr 0x004a19a0 */
void CopyCallPauseJmp_004a19a0(void) {
    g_scaledInit_00542044 = g_fightGroupHead;
    MStackPush2ChainLLInsert_00406790();
    if (g_framePauseFlag) return;
    StackPopDispatchTagged_0041f780();
}
