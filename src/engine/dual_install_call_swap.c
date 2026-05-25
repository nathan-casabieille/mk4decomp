/**
 * 2 "dual install + call + pause-guarded swap + tail-jmp" helpers (64b).
 *
 * Pattern:
 *   mov     eax, [g_A]
 *   mov     ecx, [g_B]
 *   mov     [g_C], eax
 *   mov     [g_D], ecx
 *   call    Func
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   mov     edx, [g_E]
 *   mov     eax, [g_F]
 *   mov     [g_C], edx                       ; replace with E/F
 *   mov     [g_D], eax
 *   jmp     Tail
 * .ret:
 *   ret
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern packed_ptr g_xformEntityIdx;     /* 0x00542048 */
extern unsigned int g_scaledInit_00542044;
extern unsigned int g_baseSel_00542060;

extern unsigned int g_dualA_00542044;     /* alias of g_scaledInit_00542044 */
extern unsigned int g_dualB_00542020;
extern unsigned int g_dualC_0054204c;     /* alias of g_pendingNodeType */
extern unsigned int g_dualD_00542050;     /* alias of g_eventQueueTotal */
extern unsigned int g_dualF_00542024;

extern unsigned int g_dualB_00538038;     /* g_gtPlayerProbe2 */
extern unsigned int g_dualB_0053803c;     /* g_gtPlayerProbe1 */
extern unsigned int g_dualA_00538158;     /* g_player1NodeIdx */
extern unsigned int g_player2NodeIdx;     /* g_player2NodeIdx */

extern void SqDistThresholdRevertAdvance_00489d10(void);
extern void CjChainResetThreshold_00490cc0(void);

/* @addr 0x00489cd0 */
void DualInstallCallSwap_00489cd0(void) {
    g_pendingNodeType = g_scaledInit_00542044;
    g_eventQueueTotal = g_dualB_00542020;
    SqDistThresholdRevertAdvance_00489d10();
    if (g_framePauseFlag) return;
    g_pendingNodeType = g_xformEntityIdx;
    g_eventQueueTotal = g_dualF_00542024;
    SqDistThresholdRevertAdvance_00489d10();
}

/* @addr 0x00490c80 */
void DualInstallCallSwap_00490c80(void) {
    g_fightGroupHead = g_player1NodeIdx;
    g_baseSel_00542060 = g_gtPlayerProbe2;
    CjChainResetThreshold_00490cc0();
    if (g_framePauseFlag) return;
    g_fightGroupHead = g_player2NodeIdx;
    g_baseSel_00542060 = g_gtPlayerProbe1;
    CjChainResetThreshold_00490cc0();
}
