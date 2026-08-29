/**
 * The round-intro FSM cluster - the reaction-table handlers at
 * 0x4ebee0[0x3e]/[0x3f] that StateDispatchYield jumps into once the
 * round phase (0x537f94) is up, plus their self-install states and
 * leaves. This is what stands between "camera pump yields every frame"
 * and the fighters actually walking + fighting.
 *
 * Packed layout (symbols.yaml's TripleEntryCountdownInstall @ 0x46a230
 * and MStackInstallBodyChain @ 0x46a3a0 each cover several entries):
 *   0x46a230  thunk: reaction word 0x20012 -> HitReactionDispatcher
 *   0x46a240  RoundCountdownEnter (table[0x3e])
 *   0x46a2e0  RoundCountdownTick (self-installed, 3 states)
 *   0x46a3a0  MStackInstallBodyChain
 *   0x46a3e0  BodyChainState (self-installed, 4 states; state 1 appends
 *             its own VA + 0x2000000 into the camera node's event queue -
 *             StackPopDispatchTagged strips the tag on consumption)
 *   0x46a4d0  RoundIntroSwap (table[0x3f])
 *   0x46a520  CallPauseCmpStateJmp
 *   0x46a580  PushArgClearSetCallJmp
 *
 * Leaves: State6Latch (0x48e240), InstallSelfIndirectJmpNeg (0x48f4f0,
 * ends in an indirect jump through 0x542054 - the continuation
 * MStackInstallBodyChain parked there), InstallSelfOrCmpJmp (0x48f570,
 * tails into StackPopDispatchTagged when the +0x70 timer runs out).
 *
 * NATIVE-ONLY twins: the matching build synthesizes the original bytes.
 */
#ifdef NON_MATCHING

#include "portable/mem_model.h"

extern void HitReactionDispatcher(void);
extern void State6Latch(void);
extern void ClearBit2x34(void);
extern void ScaledZeroFour(void);
extern void Wrapper_ArgSarStoreJmp_004eba28(void);
extern void CallPauseScaledStoreCopyJmp(void);
extern void DualCallPauseDirtyJmp_00490c30(void);
extern void MStackPushSet0008(void);
extern void SwapOrPassSet(void);
extern void StackPopDispatchTagged(void);
extern void CmpCondIdxArrLookup(void);
extern void TableLookupCall_g_eventTbl_65(void);
extern void IterLoad_g_scaledInit_00542048_then_DualScaledStoreZero(int);
extern void ScaledInitOrSelfPtrSetType_0046a5e0(void);
extern void GuardedPushCall_CopyJmp_then_ArgSarStoreJmp_0046a560(void);
extern void ArgSarStoreJmp(int);

#define g_currentNodeIdx  (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_pendingNodeType (*(unsigned int *)MK4_VA(unsigned int, 0x54204cu))
#define g_contSlot54      (*(unsigned int *)MK4_VA(unsigned int, 0x542054u))
#define g_baseSel         (*(unsigned int *)MK4_VA(unsigned int, 0x542060u))
#define g_walkSlot6c      (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_slot70          (*(unsigned int *)MK4_VA(unsigned int, 0x542070u))
#define g_slot80          (*(unsigned int *)MK4_VA(unsigned int, 0x542080u))
#define g_reactionWord    (*(unsigned int *)MK4_VA(unsigned int, 0x54207cu))
#define g_scratch94       (*(unsigned int *)MK4_VA(unsigned int, 0x542094u))
#define g_groupHead       (*(unsigned int *)MK4_VA(unsigned int, 0x54205cu))
#define g_framePauseFlag  (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_matrixStackTop  (*(unsigned int *)MK4_VA(unsigned int, 0x4d57acu))
#define g_flags52ab40     (*(unsigned int *)MK4_VA(unsigned int, 0x52ab40u))
#define g_byte54380c      (*(unsigned char *)MK4_VA(unsigned char, 0x54380cu))
#define g_byte54389c      (*(unsigned char *)MK4_VA(unsigned char, 0x54389cu))
#define g_p1NodeIdxG      (*(unsigned int *)MK4_VA(unsigned int, 0x538158u))
#define g_charP1          (*(unsigned int *)MK4_VA(unsigned int, 0x537f48u))
#define g_charP2          (*(unsigned int *)MK4_VA(unsigned int, 0x5380e0u))
#define g_roundPhase      (*(unsigned int *)MK4_VA(unsigned int, 0x537f94u))
#define g_ovrValue        (*(unsigned int *)MK4_VA(unsigned int, 0x4f3608u))
#define g_progress535ddc  (*(unsigned int *)MK4_VA(unsigned int, 0x535ddcu))

void State6Latch(void)
{
    unsigned int chr;

    chr = (g_groupHead == g_p1NodeIdxG) ? g_charP1 : g_charP2;
    g_walkSlot6c = chr;
    if (chr != 6)
        return;                     /* only character 6 latches */
    g_slot70 = MK4_NODE_AT(unsigned int, g_baseSel, 0x34);
    if (g_slot70 == 6)
        return;
    if (g_roundPhase == 0) {
        g_walkSlot6c = 5;
        CmpCondIdxArrLookup();
        if (g_framePauseFlag != 0)
            return;
        if ((int)g_walkSlot6c < 0x258)
            return;
    }
    g_byte54389c = 1;
    MK4_NODE_AT(unsigned int, g_baseSel, 0x34) = 6;
    g_walkSlot6c = 0x2c;
    TableLookupCall_g_eventTbl_65();
    if (g_framePauseFlag != 0)
        return;
    ClearBit2x34();                 /* jmp in the original */
}

void InstallSelfIndirectJmpNeg(void)
{
    unsigned int cam = g_baseSel;
    unsigned int cmd, top;

    cmd = MK4_NODE_AT(unsigned int, cam, 0x84);
    MK4_NODE_AT(unsigned int, cam, 0x84) = 0;
    if (cmd != 0) {
        g_walkSlot6c = MK4_NODE_AT(unsigned int, g_groupHead, 0x70);
        if ((int)g_walkSlot6c >= 0) {
            ((void (*)(void))MK4_ResolveCode(g_contSlot54))();
            return;                 /* jmp [0x542054] in the original */
        }
    } else {
        top = g_matrixStackTop;
        g_contSlot54 = *(unsigned int *)MK4_PTR(top * 4);
        g_matrixStackTop = top - 1;
    }
    MK4_NODE_AT(unsigned int, cam, 8) = 0x48f4f0u;
    MK4_NODE_AT(unsigned int, cam, 0x84) = 1;
    g_pendingNodeType = 1;
    g_framePauseFlag = 1;
}

void InstallSelfOrCmpJmp(void)
{
    unsigned int cam = g_baseSel;
    unsigned int cmd;

    cmd = MK4_NODE_AT(unsigned int, cam, 0x84);
    MK4_NODE_AT(unsigned int, cam, 0x84) = 0;
    if (cmd != 0) {
        g_walkSlot6c = MK4_NODE_AT(unsigned int, g_groupHead, 0x70);
        if ((int)g_walkSlot6c < 0) {
            StackPopDispatchTagged();   /* jmp in the original */
            return;
        }
    }
    MK4_NODE_AT(unsigned int, cam, 8) = 0x48f570u;
    MK4_NODE_AT(unsigned int, cam, 0x84) = 1;
    g_pendingNodeType = 1;
    g_framePauseFlag = 1;
}

void RoundReaction20012_0046a230(void)
{
    g_reactionWord = 0x20012u;
    HitReactionDispatcher();        /* jmp in the original */
}

void MStackInstallBodyChain(void)
{
    unsigned int top;

    g_walkSlot6c = 0x83;
    MK4_NODE_AT(unsigned int, g_groupHead, 0x4c) = 0x83;
    top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    *(unsigned int *)MK4_PTR(top * 4) = 0x46a3e0u;   /* the continuation */
    InstallSelfIndirectJmpNeg();    /* jmp in the original */
}

void BodyChainState_0046a3e0(void)
{
    unsigned int cam = g_baseSel;
    unsigned int cmd, q;

    cmd = MK4_NODE_AT(unsigned int, cam, 0x84);
    MK4_NODE_AT(unsigned int, cam, 0x84) = 0;

    if (cmd == 0) {
        MK4_NODE_AT(unsigned int, cam, 8) = 0x46a3e0u;
        MK4_NODE_AT(unsigned int, cam, 0x84) = 1;
        g_pendingNodeType = 0xa;
        g_framePauseFlag = 1;
        return;
    }
    if (cmd == 1) {
        g_walkSlot6c = 0xffffff7du;
        MK4_NODE_AT(unsigned int, g_groupHead, 0x4c) = 0xffffff7du;
        MK4_NODE_AT(unsigned int, cam, 8) = 0x46a3e0u;
        MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 2;
        /* append the tagged continuation into the camera event queue */
        q = MK4_NODE_AT(unsigned int, cam, 4);
        g_currentNodeIdx = q;
        *(unsigned int *)MK4_PTR(q * 4) = 0x46a3e0u + 0x2000000u;
        g_currentNodeIdx = q + 1;
        MK4_NODE_AT(unsigned int, cam, 4) = q + 1;
        MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 0;
        InstallSelfOrCmpJmp();
        g_framePauseFlag = 1;
        return;
    }
    if (cmd == 2) {
        MK4_NODE_AT(unsigned int, cam, 8) = 0x46a3e0u;
        MK4_NODE_AT(unsigned int, cam, 0x84) = 3;
        g_pendingNodeType = 0xa;
        g_framePauseFlag = 1;
        return;
    }
    MStackInstallBodyChain();       /* cmd 3+: restart the chain */
}

void RoundCountdownTick_0046a2e0(void)
{
    unsigned int cam = g_baseSel;
    unsigned int cmd, v;

    cmd = MK4_NODE_AT(unsigned int, cam, 0x84);
    MK4_NODE_AT(unsigned int, cam, 0x84) = 0;

    if (cmd == 0) {                 /* prime the energy ramp */
        g_walkSlot6c = 0xfffffd71u;
        MK4_NODE_AT(unsigned int, g_groupHead, 0x4c) = 0xfffffd71u;
        MK4_NODE_AT(unsigned int, cam, 8) = 0x46a2e0u;
        MK4_NODE_AT(unsigned int, cam, 0x84) = 1;
        g_pendingNodeType = 1;
        g_framePauseFlag = 1;
        return;
    }
    if (cmd == 1) {                 /* arm 10 ramp steps */
        g_slot80 = 0xa;
    } else {                        /* ramp: +0x41 per tick, 10 times */
        g_slot70 = 0x41;
        v = MK4_NODE_AT(unsigned int, g_groupHead, 0x4c) + 0x41;
        g_walkSlot6c = v;
        MK4_NODE_AT(unsigned int, g_groupHead, 0x4c) = v;
        g_slot80 -= 1;
        if (g_slot80 == 0) {
            MStackInstallBodyChain();
            return;
        }
    }
    MK4_NODE_AT(unsigned int, cam, 8) = 0x46a2e0u;
    MK4_NODE_AT(unsigned int, cam, 0x84) = 2;
    g_pendingNodeType = 1;
    g_framePauseFlag = 1;
}

void RoundCountdownEnter_0046a240(void)
{
    unsigned int cam = g_baseSel;
    unsigned int cmd;

    cmd = MK4_NODE_AT(unsigned int, cam, 0x84);
    MK4_NODE_AT(unsigned int, cam, 0x84) = 0;
    if (cmd == 0) {
        State6Latch();
        if (g_framePauseFlag != 0)
            return;
        g_walkSlot6c = g_flags52ab40;
        g_scratch94 = g_flags52ab40 & 0x10;
        if (g_scratch94 != 0) {
            CallPauseScaledStoreCopyJmp();
            if (g_framePauseFlag != 0)
                return;
            MK4_NODE_AT(unsigned int, cam, 8) = 0x46a240u;
            MK4_NODE_AT(unsigned int, cam, 0x84) = 1;
            g_pendingNodeType = 0x78;
            g_framePauseFlag = 1;
            return;
        }
    }
    ClearBit2x34();
    if (g_framePauseFlag != 0)
        return;
    ScaledZeroFour();
    if (g_framePauseFlag != 0)
        return;
    g_byte54380c = 1;
    Wrapper_ArgSarStoreJmp_004eba28();
}

void CallPauseCmpStateJmp(void)
{
    ScaledZeroFour();
    if (g_framePauseFlag != 0)
        return;
    g_walkSlot6c = g_progress535ddc;
    if ((int)g_progress535ddc > 0x30000) {
        GuardedPushCall_CopyJmp_then_ArgSarStoreJmp_0046a560();
        return;                     /* jmp in the original */
    }
    ArgSarStoreJmp(0x4eabb0);
}

void PushArgClearSetCallJmp(void)
{
    g_walkSlot6c = 0;
    MK4_NODE_AT(unsigned int, g_baseSel, 0x80) = 0;
    MK4_NODE_AT(unsigned int, g_baseSel, 0x7c) = 0;
    g_walkSlot6c = 0x1009u;
    MK4_NODE_AT(unsigned int, g_baseSel, 0x74) = 0x1009u;
    IterLoad_g_scaledInit_00542048_then_DualScaledStoreZero(0x542a64);
    if (g_framePauseFlag != 0)
        return;
    ScaledInitOrSelfPtrSetType_0046a5e0();   /* jmp in the original */
}

void RoundIntroSwap_0046a4d0(void)
{
    DualCallPauseDirtyJmp_00490c30();
    if (g_framePauseFlag != 0)
        return;
    MStackPushSet0008();
    if (g_framePauseFlag != 0)
        return;
    SwapOrPassSet();
    if (g_framePauseFlag != 0)
        return;
    if (g_walkSlot6c == g_ovrValue) {
        PushArgClearSetCallJmp();   /* jmp in the original */
        return;
    }
    CallPauseCmpStateJmp();         /* jmp in the original */
}

#endif /* NON_MATCHING */
