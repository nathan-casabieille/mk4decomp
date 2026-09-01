/**
 * The VS screen, which is what the character select's download step hands
 * the frame to, and the thing that eventually releases it.
 *
 * PendingMatch_DownloadPlayerChar parks in its state 3 waiting for either
 * 0x537f28 or 0x53a350 to go non-zero. Only this cluster writes them, so
 * with it hollow the select's own machine waits forever - which is exactly
 * where the confirm stopped after 3ef392067.
 *
 *   0x00462ac0 - the VS controller proper, four states off the table at
 *     0x00462ddc plus a default for anything above 3:
 *       0  gate on "the game phase is 9" (Cmp9DirtyToggle). First time
 *          through it raises the 0x537f74 busy flag, rolls back tag 0x254,
 *          fires scene tags 0x4e2874 and 0x26f, runs the char selector and
 *          installs 0x00462e60, then chains state 1 into
 *          PoseFnInstallDualCluster. On a re-entry with the flag already up
 *          it publishes 0x53a734 into 0x53a350 - the OTHER way the select's
 *          state 3 gets released - and lets go.
 *       1  scene tag 0x4e286c, two chain walks, then bias the node's
 *          position triple (x by -0x3d70, z by -0x51e) and seed a 9-step
 *          countdown before falling into the shared unlink-and-rearm.
 *       2  one chain prepend, then state 3.
 *       3  the countdown body: nine passes through ScaledLoadGuardedJmp,
 *          then install 0x00462df0 and chain state FOUR - which is past the
 *          table, so the next visit lands in
 *       default  set 0x537f28 and release. That store is what lets the
 *          select's download FSM leave state 3.
 *
 *   0x00462a90 - the 32-byte gate in front of it: with 0x537f74 clear,
 *     probe tag 0x23b for 0x00462ec0 first; either way, release.
 *
 *   0x004628e0 / 0x00462930 - the P1 / P2 pair packed inside
 *     TripleEntryWordChainInc5, same body against different globals: unless
 *     the phase is 9 they release; otherwise they publish the player's group
 *     and tail into InstallSelfBootInit (player idle) or the VS gate above.
 *
 *   0x00462e60 - the small companion state 0 installs: it re-arms itself
 *     once on a 10-tick beat and, on that second visit, raises 0x53a734.
 *     That is the value the VS controller's re-entry publishes into
 *     0x53a350 - the OTHER release for the select's state 3.
 *
 *   0x00462ec0 - what the gate probes for under tag 0x23b, and the reason
 *     the gate could not land on its own: with this still a no-op, resolving
 *     0x00462a90 released a node the fight path still pointed at, and
 *     MK4_BOOT_MATCH faulted with an ASLR-varying host address showing up as
 *     a code VA. It stamps 0x6b3 (or clears it) down a +0x40 sibling chain
 *     through +0x7c - the portrait fade - and counts the entry at
 *     0x541fb4[ladder] down, wrapping at 3, on a 0x3c-tick beat.
 *
 *   Cmp9DirtyToggle (0x00464320, 36b) - dirty bit 0 = "g_tickFlagF is 9".
 *
 * NATIVE-ONLY twins: the matching build synthesizes the original bytes.
 */
#ifdef NON_MATCHING

#include "portable/mem_model.h"

extern void CallSetPause(void);
extern void StoreTwoCall(int fn, int tag);
extern void TripleStageRollback(int tag);
extern void TaggedSceneDispatch(unsigned int tag);
extern void SaveCallRestore(int tag);
extern void SetWalkCurCallPauseDirty(unsigned int fn, unsigned int tag);
extern void ScaledLoadGuardedJmp(void);
extern void MStackCall_MStackPush2ChainPrepend_004062f0(void);
/* still weak no-ops - the work-list under this screen */
extern void DirtyBitToggleDispatch(void);
extern void MStackPushSearchLoop(void);
extern void MStackChainCountdownLoop(void);
extern void MStackChainOrBitLoop(void);
extern void PlayerCharSelector(void);
extern void PoseFnInstallDualCluster(void);
extern void Push0_Push463220_Jmp(void);
extern void InstallSelfBootInit(void);
extern void MStackPush2LLWalkCompare(void);

#define g_currentNodeIdx  (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_pendingNodeType (*(unsigned int *)MK4_VA(unsigned int, 0x54204cu))
#define g_slot54          (*(unsigned int *)MK4_VA(unsigned int, 0x542054u))
#define g_slot58          (*(unsigned int *)MK4_VA(unsigned int, 0x542058u))
#define g_fightGroupHead  (*(unsigned int *)MK4_VA(unsigned int, 0x54205cu))
#define g_baseSel         (*(unsigned int *)MK4_VA(unsigned int, 0x542060u))
#define g_walkSlot6c      (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_slot70          (*(unsigned int *)MK4_VA(unsigned int, 0x542070u))
#define g_slot74          (*(unsigned int *)MK4_VA(unsigned int, 0x542074u))
#define g_slot78          (*(unsigned int *)MK4_VA(unsigned int, 0x542078u))
#define g_stateBits8c     (*(unsigned int *)MK4_VA(unsigned int, 0x54208cu))
#define g_framePauseFlag  (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_tickFlagF       (*(unsigned int *)MK4_VA(unsigned int, 0x52aac4u))
#define g_activeP1        (*(unsigned int *)MK4_VA(unsigned int, 0x53a408u))
#define g_activeP2        (*(unsigned int *)MK4_VA(unsigned int, 0x537e88u))
#define g_vsBusy537f74    (*(unsigned int *)MK4_VA(unsigned int, 0x537f74u))
#define g_wait537f28      (*(unsigned int *)MK4_VA(unsigned int, 0x537f28u))
#define g_wait53a350      (*(unsigned int *)MK4_VA(unsigned int, 0x53a350u))
#define g_vsResult53a734  (*(unsigned int *)MK4_VA(unsigned int, 0x53a734u))
#define g_ladderIdx       (*(unsigned int *)MK4_VA(unsigned int, 0x541fb0u))
#define g_chainBase541fb4 (*(unsigned int *)MK4_VA(unsigned int, 0x541fb4u))
#define g_chainBase541fb8 (*(unsigned int *)MK4_VA(unsigned int, 0x541fb8u))

#define VS_VA 0x00462ac0u

/* 0x00464320 (36b) */
void Cmp9DirtyToggle(void)
{
    g_walkSlot6c = g_tickFlagF;
    if (g_tickFlagF == 9)
        g_stateBits8c |= 1u;
    else
        g_stateBits8c &= ~1u;
}

/* 0x00462a90 (32b) */
void PendingMatch_SetWalkCurCallPauseDirty(void)
{
    g_walkSlot6c = g_vsBusy537f74;
    if (g_vsBusy537f74 == 0)
        SetWalkCurCallPauseDirty(0x00462ec0u, 0x23b);
    CallSetPause();                              /* tail-jmp in the original */
}

void VsScreenController_00462ac0(void)
{
    unsigned int cmd = MK4_NODE_AT(unsigned int, g_baseSel, 0x84);
    unsigned int v;

    MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 0;

#ifdef TARGET_SDL
    /* MK4_TRACE_VS: the VS controller's state per visit. Its state FOUR is
     * past the table on purpose - the default is where 0x537f28 gets set. */
    { extern void SDL_Log(const char *, ...); extern char *getenv(const char *);
      static unsigned n;
      if (getenv("MK4_TRACE_VS") && n < 24) { n++;
          SDL_Log("VS cmd=%u phase=%u busy=%u", cmd, g_tickFlagF,
                  g_vsBusy537f74); } }
#endif

    switch (cmd) {

    case 0:                                      /* 0x462bd2 */
        Cmp9DirtyToggle();
        if (g_framePauseFlag != 0) return;
        if ((g_stateBits8c & 1u) == 0) {
            CallSetPause();
            return;
        }
        if (g_vsBusy537f74 != 0) {               /* 0x462ce5 */
            g_walkSlot6c = g_vsResult53a734;
            if (g_vsResult53a734 == 0) {
                CallSetPause();
                return;
            }
            g_wait53a350 = g_vsResult53a734;
            CallSetPause();
            return;
        }
        g_walkSlot6c = 1;
        g_vsBusy537f74 = 1;
        TripleStageRollback(0x254);
        MStackChainOrBitLoop();
        if (g_framePauseFlag != 0) return;
        TaggedSceneDispatch(*MK4_VA(unsigned short, 0x4e2874u));
        SaveCallRestore(0x26f);
        PlayerCharSelector();
        if (g_framePauseFlag != 0) return;
        StoreTwoCall(0x00462e60, 0);
        MStackPushSearchLoop();
        if (g_framePauseFlag != 0) return;
        g_slot58 = 0x8c;
        g_slot54 = g_walkSlot6c;
        MK4_NODE_AT(unsigned int, g_baseSel, 8) = VS_VA;
        MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 1;
        v = MK4_NODE_AT(unsigned int, g_baseSel, 4);
        g_currentNodeIdx = v;
        *MK4_NODE(unsigned int, v) = VS_VA + (1u << 24);
        g_currentNodeIdx = v + 1;
        MK4_NODE_AT(unsigned int, g_baseSel, 4) = v + 1;
        MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 0;
        PoseFnInstallDualCluster();
        g_framePauseFlag = 1;
        return;

    case 1:                                      /* 0x462aed */
        DirtyBitToggleDispatch();
        if (g_framePauseFlag != 0) return;
        if ((g_stateBits8c & 4u) != 0)
            goto done;                           /* 0x462d01 */
        TaggedSceneDispatch(*MK4_VA(unsigned short, 0x4e286cu));
        MStackPushSearchLoop();
        if (g_framePauseFlag != 0) return;
        MStackChainCountdownLoop();
        if (g_framePauseFlag != 0) return;
        g_slot70 = g_slot70 - 0x3d70u;
        MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x54) = g_slot70;
        MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x58) = g_slot74;
        g_slot78 = g_slot78 - 0x51eu;
        MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x5c) = g_slot78;
        g_slot54 = 9;
        g_fightGroupHead = g_currentNodeIdx;
        goto unlink_step;                        /* 0x462b9b */

    case 2:                                      /* 0x462d1b */
        MStackCall_MStackPush2ChainPrepend_004062f0();
        if (g_framePauseFlag != 0) return;
        MK4_NODE_AT(unsigned int, g_baseSel, 8) = VS_VA;
        MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 3;
        g_pendingNodeType = 1;
        g_framePauseFlag = 1;
        return;

    case 3:                                      /* 0x462d3e */
        g_currentNodeIdx = g_fightGroupHead;
        g_slot54 = g_slot54 - 1u;
        if (g_slot54 != 0)
            goto unlink_step;
        StoreTwoCall(0x00462df0, 0);
        g_slot54 = 0;
        g_slot58 = 0xb4;
        MK4_NODE_AT(unsigned int, g_baseSel, 8) = VS_VA;
        MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 4;
        v = MK4_NODE_AT(unsigned int, g_baseSel, 4);
        g_currentNodeIdx = v;
        *MK4_NODE(unsigned int, v) = VS_VA + (4u << 24);
        g_currentNodeIdx = v + 1;
        MK4_NODE_AT(unsigned int, g_baseSel, 4) = v + 1;
        MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 0;
        Push0_Push463220_Jmp();
        g_framePauseFlag = 1;
        return;

    default:                                     /* 0x462d01 - state 4 lands here */
    done:
        g_walkSlot6c = 1;
        g_wait537f28 = 1;                        /* releases the select's state 3 */
        CallSetPause();
        return;
    }

unlink_step:                                     /* 0x462b9b */
    ScaledLoadGuardedJmp();
    if (g_framePauseFlag != 0) return;
    MK4_NODE_AT(unsigned int, g_baseSel, 8) = VS_VA;
    MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 2;
    g_pendingNodeType = 1;
    g_framePauseFlag = 1;
}

/* 0x00462ec0 - packed in PendingMatch_SetWalkCurCallPauseDirty */
void VsPortraitFade_00462ec0(void)
{
    unsigned int cmd = MK4_NODE_AT(unsigned int, g_baseSel, 0x84);
    unsigned int cur, v;

    MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 0;

    if (cmd != 0) {                              /* 0x462ee1 - clear the fade */
        cur = g_slot58;
        g_walkSlot6c = 0;
        g_fightGroupHead = cur;
        MK4_NODE_AT(unsigned int, cur, 0x7c) = 0;
        cur = MK4_NODE_AT(unsigned int, g_fightGroupHead, 0x40);
        g_fightGroupHead = cur;
        while (cur != 0) {
            g_walkSlot6c = 0;
            MK4_NODE_AT(unsigned int, cur, 0x7c) = 0;
            cur = MK4_NODE_AT(unsigned int, g_fightGroupHead, 0x40);
            g_fightGroupHead = cur;
        }
        CallSetPause();
        return;
    }

    Cmp9DirtyToggle();                           /* 0x462f3d */
    if (g_framePauseFlag != 0) return;
    if ((g_stateBits8c & 1u) == 0) {
        CallSetPause();
        return;
    }
    TaggedSceneDispatch(*MK4_VA(unsigned short, 0x4e2884u));
    g_walkSlot6c = g_ladderIdx << 2;
    g_currentNodeIdx = (g_ladderIdx << 2) + g_chainBase541fb8;
    g_walkSlot6c = *MK4_NODE(unsigned int, g_currentNodeIdx);
    MStackPush2LLWalkCompare();
    if (g_framePauseFlag != 0) return;
    if ((g_stateBits8c & 4u) != 0) {
        CallSetPause();
        return;
    }

    cur = g_currentNodeIdx;                      /* 0x462fb3 - stamp the fade */
    g_fightGroupHead = cur;
    g_slot58 = cur;
    g_walkSlot6c = 0x6b3;
    MK4_NODE_AT(unsigned int, cur, 0x7c) = 0x6b3;
    cur = MK4_NODE_AT(unsigned int, g_fightGroupHead, 0x40);
    g_fightGroupHead = cur;
    while (cur != 0) {
        g_walkSlot6c = 0x6b3;
        MK4_NODE_AT(unsigned int, cur, 0x7c) = 0x6b3;
        cur = MK4_NODE_AT(unsigned int, g_fightGroupHead, 0x40);
        g_fightGroupHead = cur;
    }

    g_currentNodeIdx = g_ladderIdx + g_chainBase541fb4;
    v = *MK4_NODE(unsigned int, g_currentNodeIdx) - 1u;
    g_walkSlot6c = v;
    if ((int)v < 0) {
        v = 3;
        g_walkSlot6c = 3;
    }
    *MK4_NODE(unsigned int, g_currentNodeIdx) = v;
    MK4_NODE_AT(unsigned int, g_baseSel, 8) = 0x00462ec0u;
    MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 1;
    g_pendingNodeType = 0x3c;
    g_framePauseFlag = 1;
}

/* 0x00462e60 - packed in PendingMatch_SetWalkCurCallPauseDirty */
void VsResultLatch_00462e60(void)
{
    unsigned int cmd = MK4_NODE_AT(unsigned int, g_baseSel, 0x84);

    MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 0;

    if (cmd != 0) {
        g_walkSlot6c = 1;
        g_vsResult53a734 = 1;
        CallSetPause();                          /* tail-jmp in the original */
        return;
    }
    MK4_NODE_AT(unsigned int, g_baseSel, 8) = 0x00462e60u;
    MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 1;
    g_pendingNodeType = 0xa;
    g_framePauseFlag = 1;
}

/* the P1 / P2 pair packed in TripleEntryWordChainInc5 */
static void vs_player_gate(unsigned int active, unsigned int groupIdx)
{
    Cmp9DirtyToggle();
    if (g_framePauseFlag != 0) return;
    if ((g_stateBits8c & 1u) == 0) {
        CallSetPause();                          /* tail-jmp in the original */
        return;
    }
    g_walkSlot6c = active;
    g_currentNodeIdx = groupIdx;
    if (active == 0)
        InstallSelfBootInit();                   /* tail-jmp */
    else
        PendingMatch_SetWalkCurCallPauseDirty(); /* tail-jmp */
}

/* 0x004628e0 */
void VsPlayerGateP1_004628e0(void)
{
    vs_player_gate(g_activeP1, 0x53a3e0u >> 2);
}

/* 0x00462930 */
void VsPlayerGateP2_00462930(void)
{
    vs_player_gate(g_activeP2, 0x53a700u >> 2);
}

#endif /* NON_MATCHING */
