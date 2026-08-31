/**
 * The FIGHT-FRAME DRIVERS: the small per-frame gate functions the
 * sequencer's round body leans on every pass. All were weak stubs, and the
 * measured consequence (29cfd1a5b) was branch-steering by STALE dirty bits:
 * with the round gate forced, the round body wandered into Phase3's queue
 * push while g_baseSel still pointed at a fighter, and the tagged
 * continuation corrupted a node link. These maintain the bits.
 *
 *   DualTestDirtyToggle_004282c0: dirty bit 0 = "both fighters have an
 *       active word" (0x53a408 && 0x537e88).
 *   CmpDualStateMatch: returns 1 - and runs the idle pump after clearing
 *       both active words - when BOTH energy ramps sit exactly at 0x10000;
 *       the round body bails out for that frame.
 *   DirtyKeyedStateCopy: stage the current side's records (node slot,
 *       group, ready word) by the ramp key 0x53a6dc: zero picks P1's
 *       trio, non-zero P2's; dirty bit 2 = "ready word is zero".
 *   GuardedChainDispatch: while the round countdown lives, SwapOrPassSet;
 *       if the walk hits the ovr limit, read the LOSER's meter (+0x34 of
 *       the other side's group); 0xf means the round is decided -
 *       TwoPushCallSetDirty schedules the round-end pair (0x4573e0 type
 *       0x29, StageEventRearm type 0x2c) and sets dirty bit 0; anything
 *       else clears it.
 *   CallPauseEvtPushJmp: SwapOrPassSet, bump the walk counter through the
 *       current entity slot, tail into BulletVolleySpawner.
 *   MStackPushSearchLoop: count the live entries of the record list at
 *       [0x541fb8 + 0x541fb0*4]+0xc under an mstack save of slot70/current.
 *   AiWalkCounterDualCluster (the 0x477e20 body only - the symbol also
 *       packs an unrelated controller at 0x477ee0, left for later): at the
 *       ovr limit, bump the current side's WIN counter (0x53a3e0 / 0x53a700,
 *       capped 0x3e7) and run MultiGateDispatchCallJmp, all under an mstack
 *       save of the current node.
 *
 * NATIVE-ONLY twins: the matching build synthesizes the original bytes.
 */
#ifdef NON_MATCHING

#include "portable/mem_model.h"

extern void SwapOrPassSet(void);
extern void GuardedSeq_ZeroTriple_then_PendingMatch(void);
extern void StoreTwoCall(int fn, int arg);
extern void BulletVolleySpawner(void);
extern void MultiGateDispatchCallJmp(void);

#define g_currentNodeIdx  (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_xformEntityIdx  (*(unsigned int *)MK4_VA(unsigned int, 0x542048u))
#define g_pendingNodeType (*(unsigned int *)MK4_VA(unsigned int, 0x54204cu))
#define g_slot50          (*(unsigned int *)MK4_VA(unsigned int, 0x542050u))
#define g_groupHead       (*(unsigned int *)MK4_VA(unsigned int, 0x54205cu))
#define g_walkSlot6c      (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_slot70          (*(unsigned int *)MK4_VA(unsigned int, 0x542070u))
#define g_stateBits8c     (*(unsigned int *)MK4_VA(unsigned int, 0x54208cu))
#define g_framePauseFlag  (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_matrixStackTop  (*(unsigned int *)MK4_VA(unsigned int, 0x4d57acu))
#define g_activeP1        (*(unsigned int *)MK4_VA(unsigned int, 0x53a408u))
#define g_activeP2        (*(unsigned int *)MK4_VA(unsigned int, 0x537e88u))
#define g_rampA           (*(unsigned int *)MK4_VA(unsigned int, 0x53a6dcu))
#define g_rampB           (*(unsigned int *)MK4_VA(unsigned int, 0x537f2cu))
#define g_ovrValue        (*(unsigned int *)MK4_VA(unsigned int, 0x4f3608u))
#define g_roundCountdown  (*(unsigned int *)MK4_VA(unsigned int, 0x53a718u))
#define g_p1NodeSlot      (*(unsigned int *)MK4_VA(unsigned int, 0x538158u))
#define g_p2NodeSlot      (*(unsigned int *)MK4_VA(unsigned int, 0x53815cu))
#define g_p1Group         (*(unsigned int *)MK4_VA(unsigned int, 0x538038u))
#define g_p2Group         (*(unsigned int *)MK4_VA(unsigned int, 0x53803cu))
#define g_readyP1         (*(unsigned int *)MK4_VA(unsigned int, 0x538160u))
#define g_readyP2         (*(unsigned int *)MK4_VA(unsigned int, 0x538164u))
#define g_winsP1          (*(unsigned int *)MK4_VA(unsigned int, 0x53a3e0u))
#define g_winsP2          (*(unsigned int *)MK4_VA(unsigned int, 0x53a700u))
#define g_recListBase     (*(unsigned int *)MK4_VA(unsigned int, 0x541fb8u))
#define g_recListIdx      (*(unsigned int *)MK4_VA(unsigned int, 0x541fb0u))

void DualTestDirtyToggle_004282c0(void)
{
    g_walkSlot6c = g_activeP1;
    if (g_activeP1 != 0) {
        g_walkSlot6c = g_activeP2;
        if (g_activeP2 != 0) {
            g_stateBits8c |= 1;
            return;
        }
    }
    g_stateBits8c &= ~1u;
}

int CmpDualStateMatch(void)
{
    g_walkSlot6c = g_rampA;
    if (g_rampA != 0x10000)
        return 0;
    g_walkSlot6c = g_rampB;
    if (g_rampB != 0x10000)
        return 0;
    g_walkSlot6c = 0;
    g_activeP1 = 0;
    g_activeP2 = 0;
    GuardedSeq_ZeroTriple_then_PendingMatch();
    return 1;
}

void DirtyKeyedStateCopy(void)
{
    unsigned int ready;

    g_xformEntityIdx = g_p1NodeSlot;
    g_currentNodeIdx = g_p1Group;
    ready = g_readyP1;
    g_walkSlot6c = g_rampA;
    g_groupHead = ready;
    if (g_rampA != 0) {
        g_xformEntityIdx = g_p2NodeSlot;
        g_currentNodeIdx = g_p2Group;
        ready = g_readyP2;
        g_groupHead = ready;
    }
    g_stateBits8c |= 4;
    if (ready != 0)
        g_stateBits8c &= ~4u;
}

void TwoPushCallSetDirty(void)
{
    StoreTwoCall(0x4573e0, 0x29);
    StoreTwoCall(0x422200, 0x2c);
    g_stateBits8c |= 1;
}

void GuardedChainDispatch(void)
{
    g_walkSlot6c = g_roundCountdown;
    if (g_roundCountdown != 0) {
        SwapOrPassSet();
        if (g_framePauseFlag != 0)
            return;
        if (g_walkSlot6c == g_ovrValue) {
            unsigned int grp = (g_slot50 == g_p1Group) ? g_p2Group : g_p1Group;
            unsigned int meter;

            g_currentNodeIdx = grp;
            meter = MK4_NODE_AT(unsigned int, grp, 0x34);
            g_walkSlot6c = meter;
            if (meter == 0xf) {
                TwoPushCallSetDirty();           /* jmp in the original */
                return;
            }
        }
    }
    g_stateBits8c &= ~1u;
}

void CallPauseEvtPushJmp(void)
{
    unsigned int v;

    SwapOrPassSet();
    if (g_framePauseFlag != 0)
        return;
    v = g_walkSlot6c + 1;
    g_walkSlot6c = v;
    *(unsigned int *)MK4_PTR(g_xformEntityIdx * 4) = v;
    BulletVolleySpawner();                       /* jmp in the original */
}

void MStackPushSearchLoop(void)
{
    unsigned int top, rec, count, v;

    top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    *(unsigned int *)MK4_PTR(top * 4) = g_slot70;
    top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    *(unsigned int *)MK4_PTR(top * 4) = g_currentNodeIdx;

    g_slot70 = 4;
    g_walkSlot6c = g_recListIdx << 2;
    g_currentNodeIdx = (g_recListIdx << 2) + g_recListBase;
    rec = *(unsigned int *)MK4_PTR(g_currentNodeIdx * 4 + 0xc);
    g_walkSlot6c = 0;
    g_currentNodeIdx = rec;
    count = 0;
    v = *(unsigned int *)MK4_PTR(rec * 4);
    g_slot70 = v;
    g_currentNodeIdx = rec + 1;
    while (v != 0) {
        count++;
        g_walkSlot6c = count;
        rec++;
        v = *(unsigned int *)MK4_PTR(rec * 4);
        g_slot70 = v;
        g_currentNodeIdx = rec + 1;
    }

    top = g_matrixStackTop;
    g_currentNodeIdx = *(unsigned int *)MK4_PTR(top * 4);
    top -= 1;
    g_matrixStackTop = top;
    g_slot70 = *(unsigned int *)MK4_PTR(top * 4);
    g_matrixStackTop = top - 1;
}

void AiWalkCounterDualCluster(void)
{
    unsigned int top;

    top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    *(unsigned int *)MK4_PTR(top * 4) = g_currentNodeIdx;

    SwapOrPassSet();
    if (g_framePauseFlag != 0)
        return;                                  /* mstack leak, as original */

    if (g_walkSlot6c == g_ovrValue) {
        unsigned int slot = 0, take = 0;

        if (g_pendingNodeType == g_p1NodeSlot) {
            g_walkSlot6c = g_activeP1;
            if (g_activeP1 != 0) {
                slot = 0x53a3e0u >> 2;
                take = 1;
            }
        } else {
            g_walkSlot6c = g_activeP2;
            if (g_activeP2 != 0) {
                slot = 0x53a700u >> 2;
                take = 1;
            }
        }
        if (take) {
            unsigned int wins;

            g_currentNodeIdx = slot;
            wins = *(unsigned int *)MK4_PTR(slot * 4) + 1;
            g_walkSlot6c = wins;
            if (wins < 0x3e7) {
                *(unsigned int *)MK4_PTR(slot * 4) = wins;
                MultiGateDispatchCallJmp();
                if (g_framePauseFlag != 0)
                    return;                      /* mstack leak, as original */
            }
        }
    }

    top = g_matrixStackTop;
    g_currentNodeIdx = *(unsigned int *)MK4_PTR(top * 4);
    g_matrixStackTop = top - 1;
}

#endif /* NON_MATCHING */
