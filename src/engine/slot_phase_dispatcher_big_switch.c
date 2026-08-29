/**
 * SlotPhaseDispatcherBigSwitch - 0x0045fac0 (473b game.fight) and its gate.
 *
 * The per-frame camera/pose phase pump. Drains the command word at
 * camera-node[+0x84] in a loop: each pass runs DirtyToggleByGate,
 * CjMaskedFlagProbe and NotShrCmp1Store (state bits at 0x54208c divert to
 * CjInstallSelfRouter / GuardedDoubleCallSetJmp), then the mode mask from
 * 0x54206c picks one of six phase routers - (m&9)==9, (m&5)==5, m&1, m&8,
 * m&4, m&2 in that priority - each of which ends the frame. With no mode
 * bits it clears group-head[+0x6c/0x70/0x74], runs CallPauseTriCmpJmp and
 * loops if a new command arrived. The idle tail runs DualGatedStateYield;
 * a zero yield with 0x538094 clear re-installs THIS function's VA in the
 * camera node's +8 callback slot, re-arms +0x84 = 1, and raises the pause
 * flag - the yield that hands the frame back.
 *
 * DirtyToggleByGate - 0x0048f350 (97b): set state-bit 2; when the group
 * head is P1's node keep it set and run DirtyFlagsManipB; otherwise clear
 * it, re-set it, and clear it again only when 0x537e88 is armed.
 *
 * NATIVE-ONLY twins: the matching build synthesizes the original bytes.
 */
#ifdef NON_MATCHING

#include "portable/mem_model.h"

extern void CjMaskedFlagProbe(void);
extern void ScaledZeroFour(void);
extern void FiveCallScaledChainTailJmp(void);

extern void NotShrCmp1Store(void);
extern void CjInstallSelfRouter(void);
extern void GuardedDoubleCallSetJmp(void);
extern void GuardedDispatch_CallPauseMStackPushSet3Jmp(void);
extern void GuardedDispatch_CallPauseMStackPushSet4Jmp(void);
extern void CallPauseCallTestStackPushJmp(void);
extern void PerSlotPhaseRouter_DualGatedStateYield_004605d0(void);
extern void PerSlotPhaseRouter_DualGatedStateYield_00460770(void);
extern void CallPauseMStackPushSet0Jmp(void);
extern void CallPauseTriCmpJmp(void);
extern int  DualGatedStateYield(void);
extern void UnlinkChainInstall_00460dd0(void);
extern void DirtyFlagsManipB(void);

#define g_currentNodeIdx  (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_pendingNodeType (*(unsigned int *)MK4_VA(unsigned int, 0x54204cu))
#define g_walkSlot6c      (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_slot70          (*(unsigned int *)MK4_VA(unsigned int, 0x542070u))
#define g_scratch94       (*(unsigned int *)MK4_VA(unsigned int, 0x542094u))
#define g_baseSel         (*(unsigned int *)MK4_VA(unsigned int, 0x542060u))
#define g_groupHead       (*(unsigned int *)MK4_VA(unsigned int, 0x54205cu))
#define g_framePauseFlag  (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_stateBits8c     (*(unsigned int *)MK4_VA(unsigned int, 0x54208cu))
#define g_p1NodeIdx       (*(unsigned int *)MK4_VA(unsigned int, 0x538158u))
#define g_armed537e88     (*(unsigned int *)MK4_VA(unsigned int, 0x537e88u))
#define g_gate538094      (*(unsigned int *)MK4_VA(unsigned int, 0x538094u))

#define g_p1SetEnt        (0x53a6e0u >> 2)
#define g_p1SetNode       (0x537ea4u >> 2)
#define g_roundPhase      (*(unsigned int *)MK4_VA(unsigned int, 0x537f94u))
#define g_roundAux        (*(unsigned int *)MK4_VA(unsigned int, 0x52d724u))
#define g_ovrGate         (*(unsigned int *)MK4_VA(unsigned int, 0x543714u))
#define g_ovrValue        (*(unsigned int *)MK4_VA(unsigned int, 0x4f3608u))
#define g_p2NodeIdxG      (*(unsigned int *)MK4_VA(unsigned int, 0x53815cu))
#define g_p1NodeIdxG      (*(unsigned int *)MK4_VA(unsigned int, 0x538158u))
#define g_p1Other         (*(unsigned int *)MK4_VA(unsigned int, 0x538038u))
#define g_p2Other         (*(unsigned int *)MK4_VA(unsigned int, 0x53803cu))
#define g_matrixStackTop  (*(unsigned int *)MK4_VA(unsigned int, 0x4d57acu))
#define g_targetSlot54    (*(unsigned int *)MK4_VA(unsigned int, 0x542054u))
#define g_xformEntityIdx  (*(unsigned int *)MK4_VA(unsigned int, 0x542048u))

/* SwapOrPassSet - 0x0048fbf0 (142b): stage the per-round player pair.
 * Phase 1 keeps P1's (node, other, set-cells); any other phase swaps in
 * P2's. Leaves the picked set-cell's value in 0x54206c, overridden by
 * 0x4f3608 when the 0x543714 gate is up. */
void SwapOrPassSet(void)
{
    unsigned int phase = g_roundPhase;
    unsigned int ent = g_p1SetEnt, node = g_p1SetNode;

    g_pendingNodeType = g_p1NodeIdxG;
    g_slot70 = g_p1Other;   /* 0x542050 */
    g_walkSlot6c = phase;
    g_xformEntityIdx = ent;
    g_currentNodeIdx = node;
    if (phase != 1) {
        g_pendingNodeType = g_p2NodeIdxG;
        g_slot70 = g_p2Other;
        g_xformEntityIdx = node;   /* eax = ecx: entity takes the node cell */
        ent = node;
    }
    g_walkSlot6c = *(unsigned int *)MK4_PTR(g_xformEntityIdx * 4);
    if (g_ovrGate != 0)
        g_walkSlot6c = g_ovrValue;
}

/* BitSavePushCallMergePop - 0x0045dc60 (108b): save bit 0 of the group
 * head's kind across FiveCallScaledChainTailJmp and merge it back. */
void BitSavePushCallMergePop(void)
{
    unsigned int top, bit;

    bit = MK4_NODE_AT(unsigned int, g_groupHead, 0x34) & 1u;
    g_walkSlot6c = bit;
    top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    *(unsigned int *)MK4_PTR(top * 4) = bit;
    FiveCallScaledChainTailJmp();
    if (g_framePauseFlag != 0)
        return;                     /* abort: the push leaks */
    top = g_matrixStackTop;
    bit = *(unsigned int *)MK4_PTR(top * 4);
    g_matrixStackTop = top - 1;
    g_walkSlot6c = bit;
    MK4_NODE_AT(unsigned int, g_groupHead, 0x34) =
        (MK4_NODE_AT(unsigned int, g_groupHead, 0x34) & ~1u) | bit;
}

/* StateDispatchYield - 0x00471190 (187b): pick the round-intro handler
 * from the reaction table 0x4ebee0 by the index in 0x54206c, park it on
 * the matrix stack across the chain calls, then jump to it (via the
 * trampoline). Indexes 4/5/8/0xb take the merge-pop variant. */
void StateDispatchYield(void)
{
    unsigned int idx = g_walkSlot6c;
    unsigned int slot = (0x4ebee0u >> 2) + idx;
    unsigned int fn, top;

    g_currentNodeIdx = slot;
    fn = *(unsigned int *)MK4_PTR(slot * 4);
    top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    g_currentNodeIdx = fn;
    *(unsigned int *)MK4_PTR(top * 4) = fn;

    if (idx == 4 || idx == 5 || idx == 8 || idx == 0xb) {
        ScaledZeroFour();
        if (g_framePauseFlag != 0) return;
        BitSavePushCallMergePop();
        if (g_framePauseFlag != 0) return;
    } else {
        ScaledZeroFour();
        if (g_framePauseFlag != 0) return;
        FiveCallScaledChainTailJmp();
        if (g_framePauseFlag != 0) return;
    }
    top = g_matrixStackTop;
    fn = *(unsigned int *)MK4_PTR(top * 4);
    g_matrixStackTop = top - 1;
    g_currentNodeIdx = fn;
    if (fn != 0)
        ((void (*)(void))MK4_ResolveCode(fn))();   /* jmp in the original */
}

/* DualGatedStateYield - 0x0048fc80 (169b): the round-phase gate the
 * camera pump asks before yielding. Phase down -> set state-bit 2 and
 * report 0 (the caller re-installs itself and pauses the frame). Phase
 * up -> stage the round pair, pick intro index 0x3f (0x3e for the
 * group head's own set when 0x52d724 is armed), clear bit 2, run
 * StateDispatchYield, report 1. */
int DualGatedStateYield(void)
{
    unsigned int top, picked;

    g_walkSlot6c = g_roundPhase;
    if (g_roundPhase == 0) {
        g_stateBits8c |= 4u;
        return 0;
    }
    top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    *(unsigned int *)MK4_PTR(top * 4) = g_currentNodeIdx;
    SwapOrPassSet();
    top = g_matrixStackTop;
    picked = g_pendingNodeType;
    g_currentNodeIdx = *(unsigned int *)MK4_PTR(top * 4);
    g_matrixStackTop = top - 1;
    g_walkSlot6c = 0x3f;
    if (g_groupHead == picked) {
        g_walkSlot6c = g_roundAux;
        if (g_roundAux == 0) {
            g_stateBits8c |= 4u;
            return 0;
        }
        g_walkSlot6c = 0x3e;
    }
    g_stateBits8c &= ~4u;
    StateDispatchYield();
    return 1;
}

void DirtyToggleByGate(void)
{
    g_stateBits8c |= 4u;
    if (g_groupHead == g_p1NodeIdx) {
        DirtyFlagsManipB();
        return;
    }
    g_stateBits8c ^= 4u;
    if (g_groupHead == g_p1NodeIdx) {   /* unreachable second look, kept */
        DirtyFlagsManipB();
        return;
    }
    g_stateBits8c |= 4u;
    g_walkSlot6c = g_armed537e88;
    if (g_armed537e88 != 0)
        g_stateBits8c ^= 4u;
}

void SlotPhaseDispatcherBigSwitch(void)
{
    unsigned int node, cmd, m;

    node = g_baseSel;
    cmd = MK4_NODE_AT(unsigned int, node, 0x84);
    MK4_NODE_AT(unsigned int, node, 0x84) = 0;

    while (cmd != 0) {
        DirtyToggleByGate();
        if (g_framePauseFlag != 0) return;
        if ((g_stateBits8c & 4) != 0) { CjInstallSelfRouter(); return; }
        CjMaskedFlagProbe();
        if (g_framePauseFlag != 0) return;
        if ((g_stateBits8c & 1) != 0) { GuardedDoubleCallSetJmp(); return; }
        NotShrCmp1Store();
        if (g_framePauseFlag != 0) return;

        m = g_walkSlot6c;
        if ((m & 9) == 9) { g_slot70 = m & 9; GuardedDispatch_CallPauseMStackPushSet3Jmp(); return; }
        if ((m & 5) == 5) { g_slot70 = m & 5; GuardedDispatch_CallPauseMStackPushSet4Jmp(); return; }
        if ((m & 1) != 0) { g_slot70 = m & 1; CallPauseCallTestStackPushJmp(); return; }
        if ((m & 8) != 0) { g_slot70 = m & 8; PerSlotPhaseRouter_DualGatedStateYield_004605d0(); return; }
        if ((m & 4) != 0) { g_slot70 = m & 4; PerSlotPhaseRouter_DualGatedStateYield_00460770(); return; }
        if ((m & 2) != 0) { g_scratch94 = m & 2; CallPauseMStackPushSet0Jmp(); return; }
        g_scratch94 = 0;

        g_walkSlot6c = 0;
        MK4_NODE_AT(unsigned int, g_groupHead, 0x6c) = 0;
        MK4_NODE_AT(unsigned int, g_groupHead, 0x70) = 0;
        MK4_NODE_AT(unsigned int, g_groupHead, 0x74) = 0;
        CallPauseTriCmpJmp();
        if (g_framePauseFlag != 0) return;

        node = g_baseSel;
        cmd = MK4_NODE_AT(unsigned int, node, 0x84);
        MK4_NODE_AT(unsigned int, node, 0x84) = 0;
    }

    if (DualGatedStateYield() != 0)
        return;
    g_slot70 = g_gate538094;
    if (g_gate538094 != 0) {
        UnlinkChainInstall_00460dd0();
        return;
    }
    /* re-install self as the camera node's callback and yield the frame */
    MK4_NODE_AT(unsigned int, node, 8) = 0x45fac0u;
    MK4_NODE_AT(unsigned int, node, 0x84) = 1;
    g_pendingNodeType = 1;
    g_framePauseFlag = 1;
}

#endif /* NON_MATCHING */
