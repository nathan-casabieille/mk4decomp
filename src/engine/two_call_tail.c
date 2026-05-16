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
extern void Cascade3ChainInit_0048fa50(void);
extern void StoreLitRetSet2_0042c3b0(void);
extern void GateDispatch6c_00494580(void);
extern void CjTableThresholdDispatch_00488f00(void);
extern void AggressorRunInitCluster_004813b0(void);

/* @addr 0x0042b690 */
void TwoCallTail_0042b690(void) {
    ScaledStore501Set8Jmp_0042c390();
    if (g_framePauseFlag) return;
    Cascade3ChainInit_0048fa50();
    if (g_framePauseFlag) return;
    StoreLitRetSet2_0042c3b0();
}

/* @addr 0x00481380 */
void TwoCallTail_00481380(void) {
    GateDispatch6c_00494580();
    if (g_framePauseFlag) return;
    CjTableThresholdDispatch_00488f00();
    if (g_framePauseFlag) return;
    AggressorRunInitCluster_004813b0();
}
