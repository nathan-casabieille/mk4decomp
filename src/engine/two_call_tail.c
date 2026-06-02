/**
 * 2 "two-call + pause guard + tail-jmp" helpers (34 bytes each).
 *
 * Pattern:
 *   call    FuncA
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     ret_label
 *   call    FuncB
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     ret_label
 *   jmp     Tail
 * ret_label:
 *   ret
 */
#include "game/tick.h"

extern void ScaledStore501Set8Jmp_0042c390(void);
extern void Cascade3ChainInit(void);
extern void StoreLitRetSet2_0042c3b0(void);
extern void GateDispatch6c(void);
extern void CjTableThresholdDispatch(void);
extern void AggressorRunInitCluster_004813b0(void);

/* @addr 0x0042b690 */
void TwoCallTail_0042b690(void) {
    ScaledStore501Set8Jmp_0042c390();
    if (g_framePauseFlag) return;
    Cascade3ChainInit();
    if (g_framePauseFlag) return;
    StoreLitRetSet2_0042c3b0();
}

/* @addr 0x00481380 */
void TwoCallTail_00481380(void) {
    GateDispatch6c();
    if (g_framePauseFlag) return;
    CjTableThresholdDispatch();
    if (g_framePauseFlag) return;
    AggressorRunInitCluster_004813b0();
}
