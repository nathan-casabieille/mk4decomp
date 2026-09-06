/**
 * MatchStartFsmCluster (0x468eb0, 1157b) - THE KEYSTONE. Every measured
 * gap of the pose work converges here: it spawns the Phase4 build and
 * walk-in, drives the per-frame anim advance for the round intro, STOPS
 * the walk-in, and schedules the idle FSMs. Installed in the original as
 * a state transition of the 0x4685d0 AppInit FSM; the native bridge
 * spawns it per fighter with StoreTwoCall(0x468eb0, 0x8a), the mechanism
 * MK4_BOOT_FIGHT already proves.
 *
 * Entry FSM (0x468eb0): cmd 0 arms itself with pendingNodeType 0x14;
 * cmd 1 queues a tagged re-arm and runs ScaledLoadJmp_00429390 (anim
 * install through the 00429610 chain variant); cmd 2+ tails into
 * FiveCallGuardSetTail - which drives the SIX-STATE machine below.
 *
 * Main FSM (0x468f60), states via the jump table at 0x46928c:
 *   0 (0x4691ef): cam+0x74 = 0x101, set the anim stored at 0x542a54 on
 *     the group (GuardedPackedSlotInit), target frame 0xf, arm state 1
 *     through InstallSelfPair3Branch - the anim-until-frame runner.
 *   1 (0x468f8d): spawn the idle FSMs (Phase4FivePackedHelpers, traced
 *     stub for now), target 0x23, arm state 2 via InstallSelf3WayChainCmp.
 *   2 (0x469007): SPAWN THE BUILD/WALK-IN (Phase4DualHelperTrampoline),
 *     eventTbl_112(0x50), notMask 3 -> EntryThunkBodyStateMachine,
 *     MStackPush3CmpCall, and unless dirty-1: the round SFX (0x23d7) and
 *     the 0x88 lit-load; then target 0x26, arm state 3.
 *   3 (0x469108): notMask = 0xa (the walk-in step BUDGET), then run
 *     code-table state 0x25 (ScaledArrStore...) and arm state 4.
 *   4 (0x469114): run state 0x26, arm state 5.
 *   5 (0x469142): decrement the budget; while it lasts, loop 0x25 -> 4;
 *     at zero run ScaledLoadJmp_00428d20 (the 00429530 chain variant -
 *     THE WALK-IN STOP) and arm cmd 6 -> the default -> FiveCallGuardSetTail.
 *
 * The anim runners, all their callees already REAL:
 *   InstallSelf3WayChainCmp (0x428d80): cmd 0 or an unfinished cmd 1 runs
 *     GuardedSeq_GCDBX_then_ScaledIncCmpJmp per frame (dirty-1 stops via
 *     ScaledInitOrSelfPtr); a cmd-1 frame at/past the 0x542080 target
 *     runs the bare advance and arms cmd 2; cmd 2+ pops out.
 *   InstallSelfPair3Branch (0x429240): same shape over
 *     GuardedDoubleIncCmpJmp / ScaledArrStore.
 *   GuardedPackedSlotInit(slotVA): CopyJmp_GuardedChain... then group
 *     +0x24 = *(slotVA), +0x28 = 0.
 *   ScaledLoadJmp_00428d20 / _00429390 (23b): wcb = group+0x28, tail
 *     into the 00429530 / 00429610 install variants (the ones whose
 *     (code **) bug the VM exposed).
 *
 * NATIVE-ONLY twins: the matching build synthesizes the original bytes.
 */
#ifdef NON_MATCHING

#include "portable/mem_model.h"

extern void SDL_Log(const char *, ...);
extern char *getenv(const char *);
extern void StoreTwoCall(int cb, int type);
extern void StackPopDispatchTagged(void);
extern void FiveCallGuardSetTail(void);
extern void Phase4FivePackedHelpers(void);
extern void Phase4DualHelperTrampoline(void);
extern void TableLookupCall_g_eventTbl_112(void);
extern void EntryThunkBodyStateMachine(void);
extern void MStackPush3CmpCall(void);
extern void SfxAttenuateAndApply(void);
extern void ScaledLitLoadCall_ScaledChainCallPauseSetJmp_then_Wrapper_IterLoad_0048fd30_00480fe0(void);
extern void ScaledArrStore_GuardedChainCmpDualBitXor_00429980(void);
extern void GuardedChainCmpDualBitXor(void);
extern void GuardedSeq_GuardedChainCmpDualBitXor_then_ScaledIncCmpJmp(void);
extern void ScaledInitOrSelfPtr_StackPopDispatchTagged(void);
extern void GuardedDoubleIncCmpJmp(void);
extern void CopyJmp_GuardedChainPushSetCallPop_g_currentNodeIdx(void);
extern void EsiInstallBitCallChain_CopyJmp_GuardedChainPushSetCallPop_g_currentNodeIdx_00429530(void);
extern void EsiInstallBitCallChain_CopyJmp_GuardedChainPushSetCallPop_g_currentNodeIdx_00429610(void);

void MatchStartFsm_00468f60(void);

#define g_currentNodeIdx   (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_eventQueueTotal  (*(unsigned int *)MK4_VA(unsigned int, 0x542050u))
#define g_pendingNodeType  (*(unsigned int *)MK4_VA(unsigned int, 0x54204cu))
#define g_fightGroupHead   (*(unsigned int *)MK4_VA(unsigned int, 0x54205cu))
#define g_baseSel          (*(unsigned int *)MK4_VA(unsigned int, 0x542060u))
#define g_walkCallback     (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_eventQueueCur    (*(unsigned int *)MK4_VA(unsigned int, 0x542070u))
#define g_eventQueueNotMask (*(unsigned int *)MK4_VA(unsigned int, 0x54207cu))
#define g_targetFrame      (*(unsigned int *)MK4_VA(unsigned int, 0x542080u))
#define g_xformDirtyFlags  (*(unsigned int *)MK4_VA(unsigned int, 0x54208cu))
#define g_framePauseFlag   (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))

#define W(i)               (*(unsigned int *)MK4_PTR((unsigned int)(i) * 4u))
#define NODE_W(n,off)      MK4_NODE_AT(unsigned int, (n), (off))

/* queue a tagged re-arm of `selfVA` with `tag` and set cmd - the idiom
 * every state of this band ends with */
static void ms_arm(unsigned int selfVA, unsigned int tag)
{
    unsigned int cam = g_baseSel;
    unsigned int q;

    NODE_W(cam, 8) = selfVA;
    NODE_W(g_baseSel, 0x84) = tag;
    q = NODE_W(cam, 4);
    g_currentNodeIdx = q;
    W(q) = selfVA + (tag << 24);
    g_currentNodeIdx = q + 1;
    NODE_W(cam, 4) = q + 1;
    NODE_W(g_baseSel, 0x84) = 0;
}

void ScaledLoadJmp_00428d20(void)
{
    g_walkCallback = NODE_W(g_fightGroupHead, 0x28);
    EsiInstallBitCallChain_CopyJmp_GuardedChainPushSetCallPop_g_currentNodeIdx_00429530();
}

void ScaledLoadJmp_00429390(void)
{
    g_walkCallback = NODE_W(g_fightGroupHead, 0x28);
    EsiInstallBitCallChain_CopyJmp_GuardedChainPushSetCallPop_g_currentNodeIdx_00429610();
}

void GuardedPackedSlotInit(int slotVA)
{
    unsigned int anim;

    CopyJmp_GuardedChainPushSetCallPop_g_currentNodeIdx();
    if (g_framePauseFlag != 0)
        return;
    g_eventQueueTotal = (unsigned int)slotVA >> 2;
    anim = W((unsigned int)slotVA >> 2);
    g_eventQueueTotal = ((unsigned int)slotVA >> 2) + 1u;
    g_currentNodeIdx = anim;
    NODE_W(g_fightGroupHead, 0x24) = anim;
    g_walkCallback = 0;
    NODE_W(g_fightGroupHead, 0x28) = 0;
#ifdef TARGET_SDL
    /* MK4_TRACE_POSE: this is the one place that hands a fighter group a NEW
     * animation and RESTARTS its frame counter. Posing stops on both paths
     * because the current clip plays out and clamps (see anim_frame_advance);
     * if this never runs, nothing ever restarts one. */
    { extern void SDL_Log(const char *, ...); extern char *getenv(const char *);
      extern unsigned int g_mk4FrameNo;
      static int tr = -1; static unsigned n;
      if (tr < 0) tr = getenv("MK4_TRACE_POSE") != 0;
      if (tr && n < 12) { n++;
          SDL_Log("ANIMSET f=%u group=%x anim=%08x (frame counter reset)",
                  g_mk4FrameNo, g_fightGroupHead, anim); } }
#endif
}

void InstallSelf3WayChainCmp(void)
{
    unsigned int cam = g_baseSel;
    unsigned int cmd = NODE_W(cam, 0x84);

    NODE_W(cam, 0x84) = 0;
    if (cmd >= 2) {
        StackPopDispatchTagged();
        return;
    }
    if (cmd == 1) {
        unsigned int frame = NODE_W(g_fightGroupHead, 0x28);

        g_eventQueueCur = frame;
        if ((int)frame >= (int)g_targetFrame) {
            GuardedChainCmpDualBitXor();
            if (g_framePauseFlag != 0) return;
            NODE_W(cam, 8) = 0x428d80u;
            NODE_W(cam, 0x84) = 2;
            g_pendingNodeType = 1;
            g_framePauseFlag = 1;
            return;
        }
    }
    GuardedSeq_GuardedChainCmpDualBitXor_then_ScaledIncCmpJmp();
    if (g_framePauseFlag != 0) return;
    if ((g_xformDirtyFlags & 1u) != 0) {
        ScaledInitOrSelfPtr_StackPopDispatchTagged();
        return;
    }
    NODE_W(cam, 8) = 0x428d80u;
    NODE_W(cam, 0x84) = 1;
    g_pendingNodeType = 1;
    g_framePauseFlag = 1;
}

void InstallSelfPair3Branch(void)
{
    unsigned int cam = g_baseSel;
    unsigned int cmd = NODE_W(cam, 0x84);
    unsigned int frame;

    NODE_W(cam, 0x84) = 0;
    if (cmd >= 2) {
        StackPopDispatchTagged();
        return;
    }
    GuardedDoubleIncCmpJmp();
    if (g_framePauseFlag != 0) return;
    if ((g_xformDirtyFlags & 1u) != 0) {
        ScaledInitOrSelfPtr_StackPopDispatchTagged();
        return;
    }
    frame = NODE_W(g_fightGroupHead, 0x28);
    g_walkCallback = frame;
    if ((int)frame >= (int)g_targetFrame) {
        ScaledArrStore_GuardedChainCmpDualBitXor_00429980();
        if (g_framePauseFlag != 0) return;
        NODE_W(cam, 8) = 0x429240u;
        NODE_W(cam, 0x84) = 2;
    } else {
        NODE_W(cam, 8) = 0x429240u;
        NODE_W(cam, 0x84) = 1;
    }
    g_pendingNodeType = 1;
    g_framePauseFlag = 1;
}

void MatchStartEntry_00468eb0(void)
{
    unsigned int cam = g_baseSel;
    unsigned int cmd = NODE_W(cam, 0x84);

    NODE_W(cam, 0x84) = 0;
#ifdef TARGET_SDL
    { static int n;
      if (getenv("MK4_TRACE_MS") && n < 30) { n++;
        SDL_Log("MSENT cmd=%u cam=%06x group=%06x", cmd, cam, g_fightGroupHead); } }
#endif
    if (cmd == 0) {
        NODE_W(cam, 8) = 0x468eb0u;
        NODE_W(cam, 0x84) = 1;
        g_pendingNodeType = 0x14u;
        g_framePauseFlag = 1;
        return;
    }
    if (cmd == 1) {
        ms_arm(0x468eb0u, 2);
        ScaledLoadJmp_00429390();
        g_framePauseFlag = 1;
        return;
    }
    FiveCallGuardSetTail();              /* jmp in the original */
}

void MatchStartFsm_00468f60(void)
{
    unsigned int cam = g_baseSel;
    unsigned int cmd = NODE_W(cam, 0x84);

    NODE_W(cam, 0x84) = 0;
#ifdef TARGET_SDL
    { static int n;
      if (getenv("MK4_TRACE_MS") && n < 60) { n++;
        SDL_Log("MSFSM st=%u cam=%06x group=%06x budget=%u",
                cmd, cam, g_fightGroupHead, g_eventQueueNotMask); } }
#endif
    if (cmd > 5) {
        FiveCallGuardSetTail();
        return;
    }
    switch (cmd) {
    case 0:                              /* 0x4691ef */
        g_walkCallback = 0x101u;
        NODE_W(g_baseSel, 0x74) = 0x101u;
        GuardedPackedSlotInit(0x542a54);
        if (g_framePauseFlag != 0) return;
        g_targetFrame = 0xfu;
        ms_arm(0x468f60u, 1);
        InstallSelfPair3Branch();
        g_framePauseFlag = 1;
        return;

    case 1:                              /* 0x468f8d */
        Phase4FivePackedHelpers();
        if (g_framePauseFlag != 0) return;
        g_targetFrame = 0x23u;
        ms_arm(0x468f60u, 2);
        InstallSelf3WayChainCmp();
        g_framePauseFlag = 1;
        return;

    case 2:                              /* 0x469007: spawn the build */
        Phase4DualHelperTrampoline();
        if (g_framePauseFlag != 0) return;
        g_walkCallback = 0x50u;
        TableLookupCall_g_eventTbl_112();
        if (g_framePauseFlag != 0) return;
        g_eventQueueNotMask = 3;
        EntryThunkBodyStateMachine();
        if (g_framePauseFlag != 0) return;
        MStackPush3CmpCall();
        if (g_framePauseFlag != 0) return;
        if ((g_xformDirtyFlags & 1u) == 0) {
            g_walkCallback = 0x23d7u;
            SfxAttenuateAndApply();
            if (g_framePauseFlag != 0) return;
            g_walkCallback = 0x88u;
            ScaledLitLoadCall_ScaledChainCallPauseSetJmp_then_Wrapper_IterLoad_0048fd30_00480fe0();
            if (g_framePauseFlag != 0) return;
        }
        g_targetFrame = 0x26u;
        ms_arm(0x468f60u, 3);
        InstallSelf3WayChainCmp();
        g_framePauseFlag = 1;
        return;

    case 3:                              /* 0x469108 */
        g_eventQueueNotMask = 0xau;      /* the walk-in step budget */
        goto run_25;

    case 4:                              /* 0x469114 */
        g_targetFrame = 0x26u;
        ScaledArrStore_GuardedChainCmpDualBitXor_00429980();
        if (g_framePauseFlag != 0) return;
        NODE_W(cam, 8) = 0x468f60u;
        NODE_W(cam, 0x84) = 5;
        g_pendingNodeType = 1;
        g_framePauseFlag = 1;
        return;

    case 5:                              /* 0x469142 */
        g_eventQueueNotMask -= 1u;
        if (g_eventQueueNotMask == 0) {
            ms_arm(0x468f60u, 6);        /* -> default -> the tail */
            ScaledLoadJmp_00428d20();    /* THE WALK-IN STOP */
            g_framePauseFlag = 1;
            return;
        }
run_25:
        g_targetFrame = 0x25u;
        ScaledArrStore_GuardedChainCmpDualBitXor_00429980();
        if (g_framePauseFlag != 0) return;
        NODE_W(cam, 8) = 0x468f60u;
        NODE_W(cam, 0x84) = 4;
        g_pendingNodeType = 1;
        g_framePauseFlag = 1;
        return;
    }
}

#endif /* NON_MATCHING */
