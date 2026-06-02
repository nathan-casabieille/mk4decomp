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

extern void ScaledStore501Set8Jmp(void);
extern void Cascade3ChainInit(void);
extern void StoreLitRetSet2(void);
extern void GateDispatch6c(void);
extern void CjTableThresholdDispatch(void);
extern void AggressorRunInitCluster(void);

/* @addr 0x0042b690 */
void TwoCallTail_ScaledStore501Set8Jmp_then_Cascade3ChainInit_then_StoreLitRetSet2(void) {
    ScaledStore501Set8Jmp();
    if (g_framePauseFlag) return;
    Cascade3ChainInit();
    if (g_framePauseFlag) return;
    StoreLitRetSet2();
}

/* @addr 0x00481380 */
void TwoCallTail_GateDispatch6c_then_CjTableThresholdDispatch_then_AggressorRunInitCluster(void) {
    GateDispatch6c();
    if (g_framePauseFlag) return;
    CjTableThresholdDispatch();
    if (g_framePauseFlag) return;
    AggressorRunInitCluster();
}
