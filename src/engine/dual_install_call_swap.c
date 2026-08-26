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

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern packed_ptr g_xformEntityIdx;     /* 0x00542048 */
extern unsigned int g_currentNodeIdx;
extern unsigned int g_baseSel;
#endif

extern unsigned int g_dualA_00542044;     /* alias of g_currentNodeIdx */
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_dualB_00542020;
extern unsigned int g_dualC;     /* alias of g_pendingNodeType */
extern unsigned int g_dualD;     /* alias of g_eventQueueTotal */
extern unsigned int g_dualF;
#endif

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_dualB_00538038;     /* g_gtPlayerProbe2 */
extern unsigned int g_dualB_0053803c;     /* g_gtPlayerProbe1 */
#endif
extern unsigned int g_dualA_00538158;     /* g_player1NodeIdx */
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_player2NodeIdx;     /* g_player2NodeIdx */
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_baseSel (*(unsigned int *)MK4_VA(unsigned int, 0x542060u))
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_dualB_00538038 (*(unsigned int *)MK4_VA(unsigned int, 0x538038u))
#define g_dualB_0053803c (*(unsigned int *)MK4_VA(unsigned int, 0x53803cu))
#define g_dualB_00542020 (*(unsigned int *)MK4_VA(unsigned int, 0x542020u))
#define g_dualC (*(unsigned int *)MK4_VA(unsigned int, 0x54204cu))
#define g_dualD (*(unsigned int *)MK4_VA(unsigned int, 0x542050u))
#define g_dualF (*(unsigned int *)MK4_VA(unsigned int, 0x542024u))
#define g_eventQueueTotal (*(unsigned int *)MK4_VA(unsigned int, 0x542050u))
#define g_fightGroupHead (*(unsigned int *)MK4_VA(unsigned int, 0x54205cu))
#define g_framePauseFlag (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_gtPlayerProbe1 (*(unsigned int *)MK4_VA(unsigned int, 0x53803cu))
#define g_gtPlayerProbe2 (*(unsigned int *)MK4_VA(unsigned int, 0x538038u))
#define g_pendingNodeType (*(unsigned int *)MK4_VA(unsigned int, 0x54204cu))
#define g_player1NodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x538158u))
#define g_player2NodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x53815cu))
#define g_xformEntityIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542048u))
#endif


extern void SqDistThresholdRevertAdvance(void);
extern void CjChainResetThreshold(void);

/* @addr 0x00489cd0 */
void DualInstallCallSwap_SqDistThresholdRevertAdvance_then_SqDistThresholdRevertAdvance(void) {
    g_pendingNodeType = g_currentNodeIdx;
    g_eventQueueTotal = g_dualB_00542020;
    SqDistThresholdRevertAdvance();
    if (g_framePauseFlag) return;
    g_pendingNodeType = g_xformEntityIdx;
    g_eventQueueTotal = g_dualF;
    SqDistThresholdRevertAdvance();
}

/* @addr 0x00490c80 */
void DualInstallCallSwap_CjChainResetThreshold_then_CjChainResetThreshold(void) {
    g_fightGroupHead = g_player1NodeIdx;
    g_baseSel = g_gtPlayerProbe2;
    CjChainResetThreshold();
    if (g_framePauseFlag) return;
    g_fightGroupHead = g_player2NodeIdx;
    g_baseSel = g_gtPlayerProbe1;
    CjChainResetThreshold();
}
