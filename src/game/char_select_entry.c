/**
 * How the game ARRIVES at the character select: SceneEvalFsm (0x49dea0) and
 * the leaves it drives. InstallSelfTableWalk's state 0 chains here, and it
 * was the last hollow link on the path out of the arcade join screen - the
 * screen faded and landed on black.
 *
 * SceneEvalFsm is a four-state machine on the controller command word,
 * dispatched through the jump table at 0x49e1b0, with anything above 3
 * falling into the shared pop-out tail (BootInitGuardedCallChain then
 * StackPopDispatchTagged):
 *
 *   0  ENTRY. Sweep asset kinds 6, 2 and 4, QuadCallPhase2(0x1e), then
 *      DualTestDirtyToggle_00427ea0 - "is either player active" - and if
 *      NEITHER is, force P1 active. AmbientMonitorCluster builds the screen,
 *      GuardedCmpDualToggle promotes a player from 1 (picking) to 2 (picked).
 *      Then the fork: with the idle countdown at zero, or either player
 *      already at 2, take the READY path; otherwise fall into the DOWNLOAD
 *      path, which clears the other player's char id when all three of
 *      0x543714 / 0x54356c / 0x5433ec are set, chains state 4 - past the
 *      table, so the pop-out tail runs next - and hands the frame to
 *      PendingMatch_DownloadPlayerChar.
 *      READY path: TaggedSceneDispatch on the word at 0x4e2868,
 *      ThrowAnimTriggerCluster, chain state 1, PhaseClampInstallSlot.
 *   1  Install the select screen's two per-frame controllers:
 *      0x49e490 (tag 0x251, packed inside AmbientMonitorCluster) and
 *      0x427780 (tag 0x262, packed inside RoundCleanupCluster), with
 *      g_fightGroupHead pointed at 0x4f29c0. Park as state 2.
 *   2  The select jingle (sound 0x47), then state 3.
 *   3  PER FRAME. Re-arm the 0x251 controller if it is gone
 *      (SetWalkCurCallPauseDirty), run MStackDirtyArgsBit0 - the
 *      "both sides settled" test - and while dirty bit 0 is clear stay in
 *      state 3. When it comes up, DualTestDirtyToggle_004282c0 decides:
 *      still active means back to the state-0 fork, otherwise pop out.
 *
 * Leaves converted with it:
 *   DualTestDirtyToggle_00427ea0 (0x427ea0) - dirty bit 0 = either of the
 *     two player-active words is non-zero.
 *   GuardedCmpDualToggle (0x49e360) - when the pair is settled, promote each
 *     player sitting at 1 to 2.
 *   SetWalkCurCallPauseDirty (0x404c70) - allocate a node with this callback
 *     and tag ONLY if the tag is not already in the chain. Note the argument
 *     order: (callback, tag), the tag arriving in the second slot.
 *   MStackDirtyArgsBit0 (0x49fa50) - under an mstack save of the current
 *     node, test both players against 2, then sweep tags 0x15, 0x16 and
 *     0x250; dirty bit 0 ends set only if every step left it clear.
 *   Cmp2DirtySetOrClear x2 (0x49fb10 / 0x49fb40), DualPushSetCallDualPop
 *     (0x404b10) - the tag probe under a save of slot6c and slot70.
 *   PhaseClampInstallSlot (0x49e1c0) - the title node's ZOOM-OUT: state 0
 *     takes g_titleLogoNode as the head and sets +0x74 to 0x53333, state 1
 *     to 0x29999, state 2 waits for z to pass 0xffee0000 then drops to
 *     0x10000, state 3 waits for 0xfff50000 then parks z at 0xfff60000,
 *     spawns 0x50f184 and pops out.
 *
 * Still hollow above this: AmbientMonitorCluster (0x49e3c0, 1047b),
 * ThrowAnimTriggerCluster (0x49efa0, 578b) and
 * PendingMatch_DownloadPlayerChar (0x461ca0, 1996b) - the select screen's
 * own content. None can hang the pump: every call site here either checks
 * the pause flag or sets it itself.
 *
 * NATIVE-ONLY twins: the matching build synthesizes the original bytes.
 */
#ifdef NON_MATCHING

#include "portable/mem_model.h"

extern void TableWalkBoundedCmp(int kind);
extern void QuadCallPhase2(int a, int b, int c, int d);
extern void StoreTwoCall(int fn, int arg);
extern void Push16Call(void);
extern void BootInitGuardedCallChain(void);
extern void StackPopDispatchTagged(void);
extern void AllocNode(void);
extern void Thunk_NodeChainMaskMatch(void);
extern void DualTestDirtyToggle_004282c0(void);
extern void TaggedSceneDispatch(int tag);
extern void DispatcherComplex260_FramePauseScaledStore(void);
extern void MStackPushComplexCallPop_MStackPush2ChainPrepend_00406430(void);
/* still hollow - the select screen's own content */
extern void AmbientMonitorCluster(void);
extern void ThrowAnimTriggerCluster(void);
extern void PendingMatch_DownloadPlayerChar(void);

#define g_currentNodeIdx  (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_xformEntityIdx  (*(unsigned int *)MK4_VA(unsigned int, 0x542048u))
#define g_pendingNodeType (*(unsigned int *)MK4_VA(unsigned int, 0x54204cu))
#define g_fightGroupHead  (*(unsigned int *)MK4_VA(unsigned int, 0x54205cu))
#define g_baseSel         (*(unsigned int *)MK4_VA(unsigned int, 0x542060u))
#define g_walkSlot6c      (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_slot70          (*(unsigned int *)MK4_VA(unsigned int, 0x542070u))
#define g_slot74          (*(unsigned int *)MK4_VA(unsigned int, 0x542074u))
#define g_stateBits8c     (*(unsigned int *)MK4_VA(unsigned int, 0x54208cu))
#define g_framePauseFlag  (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_matrixStackTop  (*(unsigned int *)MK4_VA(unsigned int, 0x4d57acu))
#define g_activeP1        (*(unsigned int *)MK4_VA(unsigned int, 0x53a408u))
#define g_activeP2        (*(unsigned int *)MK4_VA(unsigned int, 0x537e88u))
#define g_idleCountdown   (*(unsigned int *)MK4_VA(unsigned int, 0x53a3c0u))
#define g_titleLogoNode   (*(unsigned int *)MK4_VA(unsigned int, 0x52ab10u))
#define g_confirmPlayer   (*(unsigned char *)MK4_VA(unsigned char, 0x543590u))
#define g_tickFlagF       (*(unsigned int *)MK4_VA(unsigned int, 0x52aac4u))

#define SEF_VA   0x49dea0u
#define PCIS_VA  0x49e1c0u

/* 0x427ea0 */
void DualTestDirtyToggle_00427ea0(void)
{
    g_walkSlot6c = g_activeP1;
    if (g_activeP1 == 0) {
        g_walkSlot6c = g_activeP2;
        if (g_activeP2 == 0) {
            g_stateBits8c &= ~1u;
            return;
        }
    }
    g_stateBits8c |= 1;
}

/* 0x49e360 */
void GuardedCmpDualToggle(void)
{
    DualTestDirtyToggle_004282c0();
    if (g_framePauseFlag != 0) return;
    if ((g_stateBits8c & 1u) == 0) return;

    g_walkSlot6c = g_activeP1;
    if (g_activeP1 == 1) {
        g_walkSlot6c = 2;
        g_activeP1 = 2;
    }
    g_slot70 = g_activeP2;
    if (g_activeP2 == 1) {
        g_walkSlot6c = 2;
        g_activeP2 = 2;
    }
}

/* 0x404c70 - allocate (callback, tag) only when the tag is not in the chain */
void SetWalkCurCallPauseDirty(unsigned int callback, unsigned int tag)
{
    g_walkSlot6c = tag;
    g_slot70 = 0xffff;
    Thunk_NodeChainMaskMatch();
    if (g_framePauseFlag != 0) return;
    if ((g_stateBits8c & 1u) != 0) return;
    g_slot74 = tag;
    g_pendingNodeType = callback;
    AllocNode();
}

/* 0x49fb10 / 0x49fb40 */
void Cmp2DirtySetOrClear_0049fb10(void)
{
    g_walkSlot6c = g_activeP1;
    if (g_activeP1 == 2) g_stateBits8c |= 1; else g_stateBits8c &= ~1u;
}

void Cmp2DirtySetOrClear_0049fb40(void)
{
    g_walkSlot6c = g_activeP2;
    if (g_activeP2 == 2) g_stateBits8c |= 1; else g_stateBits8c &= ~1u;
}

/* 0x404b10 - probe one tag under a save of slot6c and slot70 */
void DualPushSetCallDualPop(unsigned int tag)
{
    unsigned int top;

    top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    *(unsigned int *)MK4_PTR(top * 4) = g_walkSlot6c;
    top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    *(unsigned int *)MK4_PTR(top * 4) = g_slot70;

    g_walkSlot6c = tag;
    g_slot70 = 0xffff;
    Thunk_NodeChainMaskMatch();
    if (g_framePauseFlag != 0)
        return;                                  /* mstack leak, as original */

    top = g_matrixStackTop;
    g_slot70 = *(unsigned int *)MK4_PTR(top * 4);
    top -= 1;
    g_matrixStackTop = top;
    g_walkSlot6c = *(unsigned int *)MK4_PTR(top * 4);
    g_matrixStackTop = top - 1;
}

/* 0x49fa50 - "have both sides settled and is every stage tag gone" */
void MStackDirtyArgsBit0(void)
{
    unsigned int top;
    int hit;

    top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    *(unsigned int *)MK4_PTR(top * 4) = g_currentNodeIdx;

    Cmp2DirtySetOrClear_0049fb10();
    if (g_framePauseFlag != 0)
        return;                                  /* mstack leak, as original */
    hit = (g_stateBits8c & 1u) != 0;
    if (!hit) {
        Cmp2DirtySetOrClear_0049fb40();
        if (g_framePauseFlag != 0)
            return;
        hit = (g_stateBits8c & 1u) != 0;
    }
    if (!hit) {
        DualPushSetCallDualPop(0x15);
        hit = (g_stateBits8c & 1u) != 0;
    }
    if (!hit) {
        DualPushSetCallDualPop(0x16);
        hit = (g_stateBits8c & 1u) != 0;
    }
    if (!hit) {
        DualPushSetCallDualPop(0x250);
        hit = (g_stateBits8c & 1u) != 0;
    }
    if (hit)
        g_stateBits8c &= ~1u;
    else
        g_stateBits8c |= 1;

    top = g_matrixStackTop;
    g_currentNodeIdx = *(unsigned int *)MK4_PTR(top * 4);
    g_matrixStackTop = top - 1;
}

/* 0x49e1c0 - the title node's zoom-out */
void PhaseClampInstallSlot(void)
{
    unsigned int cmd = MK4_NODE_AT(unsigned int, g_baseSel, 0x84);
    unsigned int head;
    int z;

    MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 0;

    if (cmd == 0) {                              /* 0x49e319 */
        head = g_titleLogoNode;
        g_fightGroupHead = head;
        g_walkSlot6c = 0x53333;
        MK4_NODE_AT(unsigned int, head, 0x74) = 0x53333;
        MK4_NODE_AT(unsigned int, g_baseSel, 8) = PCIS_VA;
        MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 1;
        g_pendingNodeType = 0xc;
        g_framePauseFlag = 1;
        return;
    }

    if (cmd == 1) {                              /* 0x49e2dd */
        g_walkSlot6c = 0x29999;
        MK4_NODE_AT(unsigned int, g_fightGroupHead, 0x74) = 0x29999;
        goto arm2;
    }

    head = g_fightGroupHead;
    z = (int)MK4_NODE_AT(unsigned int, head, 0x5c);
    g_walkSlot6c = (unsigned int)z;

    if (cmd == 2) {                              /* 0x49e29f */
        if (z < (int)0xffee0000)
            goto arm2;
        g_walkSlot6c = 0x10000;
        MK4_NODE_AT(unsigned int, head, 0x74) = 0x10000;
        goto arm3;
    }

    /* cmd >= 3 */
    if (z < (int)0xfff50000)
        goto arm3;

    MK4_NODE_AT(unsigned int, head, 0x74) = 0;
    g_walkSlot6c = 0xfff60000u;
    MK4_NODE_AT(unsigned int, g_fightGroupHead, 0x5c) = 0xfff60000u;
    g_xformEntityIdx = 0x50f184u >> 2;
    DispatcherComplex260_FramePauseScaledStore();
    if (g_framePauseFlag != 0) return;
    if ((g_stateBits8c & 4u) == 0) {
        MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x54) = 0;
        g_walkSlot6c = 0xff8a0000u;
        MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x58) = 0xff8a0000u;
        MStackPushComplexCallPop_MStackPush2ChainPrepend_00406430();
        if (g_framePauseFlag != 0) return;
        g_walkSlot6c = 0;
        *MK4_VA(unsigned int, 0x541d88u) = 0;
        *MK4_VA(unsigned int, 0x537ea8u) = 0;
    }
    StackPopDispatchTagged();
    return;

arm2:
    MK4_NODE_AT(unsigned int, g_baseSel, 8) = PCIS_VA;
    MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 2;
    g_pendingNodeType = 1;
    g_framePauseFlag = 1;
    return;

arm3:
    MK4_NODE_AT(unsigned int, g_baseSel, 8) = PCIS_VA;
    MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 3;
    g_pendingNodeType = 1;
    g_framePauseFlag = 1;
}

/* queue the tagged continuation for state N */
static void sef_chain(unsigned int state)
{
    unsigned int q;

    MK4_NODE_AT(unsigned int, g_baseSel, 8) = SEF_VA;
    MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = state;
    q = MK4_NODE_AT(unsigned int, g_baseSel, 4);
    g_currentNodeIdx = q;
    *(unsigned int *)MK4_PTR(q * 4) = SEF_VA + (state << 24);
    g_currentNodeIdx = q + 1;
    MK4_NODE_AT(unsigned int, g_baseSel, 4) = q + 1;
    MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 0;
}

static void sef_rearm(unsigned int state)
{
    MK4_NODE_AT(unsigned int, g_baseSel, 8) = SEF_VA;
    MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = state;
    g_pendingNodeType = 1;
    g_framePauseFlag = 1;
}

void SceneEvalFsm(void)
{
    unsigned int cmd = MK4_NODE_AT(unsigned int, g_baseSel, 0x84);

    MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 0;
#ifdef TARGET_SDL
    { extern void SDL_Log(const char *, ...); extern char *getenv(const char *);
      static unsigned int seen;
      if (getenv("MK4_TRACE_CS") && !(seen & (1u << (cmd & 31)))) {
          seen |= 1u << (cmd & 31);
          SDL_Log("SEF first visit to cmd=%u", cmd); } }
#endif

    switch (cmd) {
    case 1:                                      /* 0x49decd */
        StoreTwoCall(0x49e490, 0x251);
        g_fightGroupHead = 0x4f29c0u >> 2;
        StoreTwoCall(0x427780, 0x262);
        sef_rearm(2);
        return;

    case 2:                                      /* 0x49df22 */
        g_slot74 = 0x47;
        Push16Call();
        if (g_framePauseFlag != 0) return;
        sef_rearm(3);
        return;

    case 3:                                      /* 0x49df3c */
        SetWalkCurCallPauseDirty(0x49e490, 0x251);
        MStackDirtyArgsBit0();
        if (g_framePauseFlag != 0) return;
        if ((g_stateBits8c & 1u) == 0) {
            sef_rearm(3);
            return;
        }
        DualTestDirtyToggle_004282c0();
        if (g_framePauseFlag != 0) return;
        if ((g_stateBits8c & 1u) != 0)
            goto popout;
        goto download_gate;                      /* 0x49e05e */

    case 0:                                      /* 0x49dfae: ENTRY */
        break;

    default:
        goto popout;
    }

    *MK4_VA(unsigned char, 0x543728u) = 0;
    TableWalkBoundedCmp(6);
    TableWalkBoundedCmp(2);
    TableWalkBoundedCmp(4);
    QuadCallPhase2(0x1e, -1, -1, -1);
    DualTestDirtyToggle_00427ea0();
    if (g_framePauseFlag != 0) return;
    if ((g_stateBits8c & 1u) == 0) {
        g_walkSlot6c = 1;
        g_activeP1 = 1;
    }
    AmbientMonitorCluster();
    if (g_framePauseFlag != 0) return;
    GuardedCmpDualToggle();
    if (g_framePauseFlag != 0) return;
#ifdef TARGET_SDL
    { extern void SDL_Log(const char *, ...); extern char *getenv(const char *);
      static int n;
      if (getenv("MK4_TRACE_CS") && n < 4) { n++;
          SDL_Log("CS p1=%u p2=%u idle=%u phase1=%u phase2=%u dl=%u tbl=%x",
                  g_activeP1, g_activeP2, g_idleCountdown,
                  *MK4_VA(unsigned int, 0x537f88u),
                  *MK4_VA(unsigned int, 0x537e90u),
                  *MK4_VA(unsigned int, 0x542004u),
                  *MK4_VA(unsigned int, 0x541fc0u)); } }
#endif

    if (g_idleCountdown == 0 || g_activeP1 == 2) goto ready;
    g_walkSlot6c = g_activeP2;
    if (g_activeP2 == 2) goto ready;

download_gate:                                   /* 0x49e05e */
    if (*MK4_VA(unsigned int, 0x543714u) != 0
        && *MK4_VA(unsigned int, 0x54356cu) != 0
        && *MK4_VA(unsigned int, 0x5433ecu) != 0) {
        unsigned char who = g_confirmPlayer;

        g_idleCountdown = 0;
        *MK4_VA(unsigned int, 0x541fb0u) = 4;
        if (who == 1)
            *MK4_VA(unsigned int, 0x5380e0u) = 0;
        else
            *MK4_VA(unsigned int, 0x537f48u) = 0;
    }
    sef_chain(4);                                /* past the table: pops out */
    PendingMatch_DownloadPlayerChar();
    g_framePauseFlag = 1;
    return;

ready:                                           /* 0x49e0fc */
    {
        unsigned int tag = *MK4_VA(unsigned short, 0x4e2868u);

        g_tickFlagF = 3;
        *MK4_VA(unsigned int, 0x537eecu) = 0;
        *MK4_VA(unsigned int, 0x53a468u) = 0;
        g_walkSlot6c = 0;
        *MK4_VA(unsigned int, 0x535e44u) = 0;
        TaggedSceneDispatch((int)tag);
    }
    ThrowAnimTriggerCluster();
    if (g_framePauseFlag != 0) return;
    sef_chain(1);
    PhaseClampInstallSlot();
    g_framePauseFlag = 1;
    return;

popout:                                          /* 0x49e198 */
    BootInitGuardedCallChain();
    if (g_framePauseFlag != 0) return;
    StackPopDispatchTagged();
}

#endif /* NON_MATCHING */
