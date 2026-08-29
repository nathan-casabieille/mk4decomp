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
