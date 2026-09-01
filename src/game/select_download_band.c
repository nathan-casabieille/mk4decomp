/**
 * PendingMatch_DownloadPlayerChar (0x00461ca0, 1996b) - the character
 * select's own DOWNLOAD step, and the last weak no-op between a confirmed
 * fighter and a staged match.
 *
 * SceneEvalFsm state 3 chains state 4 into it at 0x0049e0ea. Hollow, the
 * chain's continuation is never popped and, worse, the two chosen fighters
 * are never registered - so when the confirm eventually reaches
 * Screen_ArcadeEnding, MatchInitMonsterChain hunts the record registry for
 * fighters nobody put there. MK4_BOOT_MATCH papers over exactly this by
 * calling DownloadPlayerChar itself at frame 8, which is why that harness
 * gets a fight and the real path did not.
 *
 * Seven states off the jump table at 0x00462450, and a shared exit at
 * 0x00462433 for anything above 6 - which state 6 deliberately parks on by
 * arming state SEVEN.
 *
 *   0  the entry. Two table walks, then a fork: with 0x54356c set it hands
 *      straight to the demo pair in state 1; otherwise it parks the game
 *      phase at 9, runs the init trio, walks the chain at 0x541fb8 through
 *      CombatChainWalkExpand until it hits a zero, and then splits on
 *      0x53a3c0 - clear (which is what the select leaves, SceneEvalFsm
 *      zeroes it at 0x0049e07b) goes to the plain download at 0x00462355,
 *      set goes into the tower/ladder body.
 *   1  the DEMO pair: bump one side's character id with a wrap at 15 - P2's
 *      when the mode byte at 0x543590 is 1, P1's otherwise - then download
 *      both, bracketed by the 0x54371c busy byte.
 *   2  scene tag 0x4e2888, two chain walks, and the three installs that put
 *      the VS screen up: 0x4626f0 tag 0x254, the input repeater 0x427780
 *      tag 0x262 over the table at 0x4ea518, and 0x462660 tag 0x257.
 *   3  wait for 0x537f28 and 0x53a350 to clear, then re-arm as 3.
 *   4  publish each player's group into the work slot and ask
 *      SetTagsCallCmpToggleDirty; on a hit, chain 5 into
 *      RoundEndHandlerCluster.
 *   5  clear both actives and hand back to the attract root.
 *   6  roll back tag 0x262, work type 0x4a, and park on state 7.
 *
 * DualPathDownloadChar (0x00463810, 94b) is the payload and is folded in
 * here: ONE player per call - P1's id from 0x537f48 into the record at
 * 0x535cfc when g_activeP1 is set, otherwise P2's id from 0x5380e0 into
 * 0x53a1d0.
 *
 * InstallSelfFullChainInit (0x00462470, 230b) is what state 0 chains into
 * on that path, and it was hollow too - so the download ran and the flow
 * parked again one step later. It seeds the VS node's own transform block
 * (kind 0x8c, z at -0x20000, the -0xa3333 scale) from the title logo node's
 * +0x60 / +0x68 and chains its state 1 into PendingMatch_ThreeMul10Stores.
 *
 * And the two controllers state 2 installs for the VS screen, both packed
 * inside MkTowerScreenFsmCluster and both reached only as tagged callbacks:
 *
 *   0x004626f0 (tag 0x254) - alternates two chain walks on a 4-tick beat,
 *     MStackChainOrBitLoop on the odd visit and MStackPush2ScaledChainLoop
 *     on the even one.
 *   0x00462660 (tag 0x257) - a two-level countdown, six ticks by fifteen,
 *     that ends by installing 0x00462ac0 under tag 0 and releasing itself.
 *
 * NATIVE-ONLY twins: the matching build synthesizes the original bytes.
 */
#ifdef NON_MATCHING

#include "portable/mem_model.h"

extern void TableWalkBoundedCmp(int kind);
extern void QuadCallPhase2(int a, int b, int c, int d);
extern void Push16Call(void);
extern void StoreTwoCall(int fn, int tag);
extern void TaggedSceneDispatch(unsigned int tag);
extern void TripleStageRollback(int tag);
extern void StackPopDispatchTagged(void);
extern void BootInitGuardedCallChain(void);
extern void GuardedSeq_ZeroTriple_then_PendingMatch(void);
extern void DownloadPlayerChar(void);
extern void ScenegraphWalk(void);
/* still on the work-list - weak no-ops in engine_frontier_stubs.c */
extern void SequencedInit3Call(void);
extern void MStackChainPackedDispatch(void);
extern void CombatChainWalkExpand(void);
extern void MkTowerScreenFsmCluster(void);
extern void StoreCallPauseCmpDirty(void);
extern void DirtyBitToggleDispatch(void);
extern void InstallSelfStateMachine_SwapOrPassSet(void);
extern void SetTagsCallCmpToggleDirty(void);
extern void RoundEndHandlerCluster(void);
extern void PackedTableWalkChainStore(void);
extern void MStackPush2ScaledChainLoop(void);
extern void AudioInstallSelfStatePush(void);
extern void MStackChainCountdownLoop(void);
extern void FixedDiv16(void);
extern void PlayerCharSelector(void);
extern void Push0_Push463220_Jmp(void);
extern void PendingMatch_ThreeMul10Stores(void);
extern void MStackChainOrBitLoop(void);
extern void CallSetPause(void);

#define g_currentNodeIdx   (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_pendingNodeType  (*(unsigned int *)MK4_VA(unsigned int, 0x54204cu))
#define g_slot54           (*(unsigned int *)MK4_VA(unsigned int, 0x542054u))
#define g_slot58           (*(unsigned int *)MK4_VA(unsigned int, 0x542058u))
#define g_fightGroupHead   (*(unsigned int *)MK4_VA(unsigned int, 0x54205cu))
#define g_baseSel          (*(unsigned int *)MK4_VA(unsigned int, 0x542060u))
#define g_walkSlot6c       (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_slot70           (*(unsigned int *)MK4_VA(unsigned int, 0x542070u))
#define g_slot74           (*(unsigned int *)MK4_VA(unsigned int, 0x542074u))
#define g_slot78           (*(unsigned int *)MK4_VA(unsigned int, 0x542078u))
#define g_stateBits8c      (*(unsigned int *)MK4_VA(unsigned int, 0x54208cu))
#define g_framePauseFlag   (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_tickFlagF        (*(unsigned int *)MK4_VA(unsigned int, 0x52aac4u))
#define g_titleLogoNode    (*(unsigned int *)MK4_VA(unsigned int, 0x52ab10u))
#define g_activeP1         (*(unsigned int *)MK4_VA(unsigned int, 0x53a408u))
#define g_activeP2         (*(unsigned int *)MK4_VA(unsigned int, 0x537e88u))
#define g_charIdP1         (*(unsigned int *)MK4_VA(unsigned int, 0x537f48u))
#define g_charIdP2         (*(unsigned int *)MK4_VA(unsigned int, 0x5380e0u))
#define g_modeByte543590   (*(unsigned char *)MK4_VA(unsigned char, 0x543590u))
#define g_dlBusyByte       (*(unsigned char *)MK4_VA(unsigned char, 0x54371cu))
#define g_dlGate54356c     (*(unsigned int *)MK4_VA(unsigned int, 0x54356cu))
#define g_chainBase541fb8  (*(unsigned int *)MK4_VA(unsigned int, 0x541fb8u))
#define g_chainBase541fb4  (*(unsigned int *)MK4_VA(unsigned int, 0x541fb4u))
#define g_ladderIdx        (*(unsigned int *)MK4_VA(unsigned int, 0x541fb0u))
#define g_ladderState      (*(unsigned int *)MK4_VA(unsigned int, 0x53a3c0u))
#define g_xformLoopCounter (*(unsigned int *)MK4_VA(unsigned int, 0x53a1acu))
#define g_vsBusy537f74     (*(unsigned int *)MK4_VA(unsigned int, 0x537f74u))
#define g_wait537f28       (*(unsigned int *)MK4_VA(unsigned int, 0x537f28u))
#define g_wait53a350       (*(unsigned int *)MK4_VA(unsigned int, 0x53a350u))
#define g_groupP1          (*(unsigned int *)MK4_VA(unsigned int, 0x53a3e0u))
#define g_groupP2          (*(unsigned int *)MK4_VA(unsigned int, 0x53a700u))

#define DL_VA 0x00461ca0u

/* park the resume word, queue the tagged continuation on the spare chain at
 * +4, run the sub, pause - the standard hand-off */
static void dl_chain(unsigned int st, void (*sub)(void))
{
    unsigned int v;

    MK4_NODE_AT(unsigned int, g_baseSel, 8) = DL_VA;
    MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = st;
    v = MK4_NODE_AT(unsigned int, g_baseSel, 4);
    g_currentNodeIdx = v;
    *MK4_NODE(unsigned int, v) = DL_VA + (st << 24);
    g_currentNodeIdx = v + 1;
    MK4_NODE_AT(unsigned int, g_baseSel, 4) = v + 1;
    MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 0;
    sub();
    g_framePauseFlag = 1;
}

/* 0x00463810 (94b) - ONE player per call */
void DualPathDownloadChar(void)
{
    if (g_activeP1 != 0) {
        g_walkSlot6c = g_charIdP1;
        g_slot54 = 0x535cfcu >> 2;
        g_slot70 = 0;
        DownloadPlayerChar();
        return;
    }
    g_walkSlot6c = g_charIdP2;
    g_slot54 = 0x53a1d0u >> 2;
    g_slot70 = 1;
    DownloadPlayerChar();                        /* tail-jmp in the original */
}

/* 0x004626f0 - tag 0x254, packed in MkTowerScreenFsmCluster */
void VsChainAlternate_004626f0(void)
{
    unsigned int cmd = MK4_NODE_AT(unsigned int, g_baseSel, 0x84);

    MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 0;

    if (cmd == 1) {
        MStackChainOrBitLoop();
        if (g_framePauseFlag != 0) return;
        MK4_NODE_AT(unsigned int, g_baseSel, 8) = 0x004626f0u;
        MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 2;
        g_pendingNodeType = 4;
        g_framePauseFlag = 1;
        return;
    }
    MStackPush2ScaledChainLoop();
    if (g_framePauseFlag != 0) return;
    MK4_NODE_AT(unsigned int, g_baseSel, 8) = 0x004626f0u;
    MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 1;
    g_pendingNodeType = 4;
    g_framePauseFlag = 1;
}

/* 0x00462660 - tag 0x257, packed in MkTowerScreenFsmCluster */
void VsCountdown_00462660(void)
{
    unsigned int cmd = MK4_NODE_AT(unsigned int, g_baseSel, 0x84);

    MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 0;

    if (cmd != 0) {
        g_slot58 = g_slot58 - 1u;
        if (g_slot58 != 0)
            goto rearm;
        g_slot54 = g_slot54 - 1u;
        if (g_slot54 == 0) {
            StoreTwoCall(0x00462ac0, 0);
            CallSetPause();                      /* tail-jmp in the original */
            return;
        }
    } else {
        g_slot54 = 0xf;
    }
    g_slot58 = 6;
rearm:
    MK4_NODE_AT(unsigned int, g_baseSel, 8) = 0x00462660u;
    MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 1;
    g_pendingNodeType = 0xa;
    g_framePauseFlag = 1;
}

/* 0x00462470 (230b) */
void InstallSelfFullChainInit(void)
{
    unsigned int cmd = MK4_NODE_AT(unsigned int, g_baseSel, 0x84);
    unsigned int logo;

    MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 0;

    if (cmd != 0) {
        StackPopDispatchTagged();
        return;
    }

    MK4_NODE_AT(unsigned int, g_baseSel, 0x30) = 0x8c;
    MK4_NODE_AT(unsigned int, g_baseSel, 0x34) = 0;
    MK4_NODE_AT(unsigned int, g_baseSel, 0x38) = 0xfffe0000u;
    g_walkSlot6c = 0xfff5cccdu;
    MK4_NODE_AT(unsigned int, g_baseSel, 0x3c) = 0xfff5cccdu;
    logo = g_titleLogoNode;
    g_fightGroupHead = logo;
    MK4_NODE_AT(unsigned int, g_baseSel, 0x40) =
        MK4_NODE_AT(unsigned int, logo, 0x60);
    g_walkSlot6c = 0;
    MK4_NODE_AT(unsigned int, g_baseSel, 0x44) = 0;
    g_walkSlot6c = MK4_NODE_AT(unsigned int, logo, 0x68);
    MK4_NODE_AT(unsigned int, g_baseSel, 0x48) = g_walkSlot6c;

    {   /* chain(1, PendingMatch_ThreeMul10Stores) against ITS own VA */
        unsigned int v;
        MK4_NODE_AT(unsigned int, g_baseSel, 8) = 0x00462470u;
        MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 1;
        v = MK4_NODE_AT(unsigned int, g_baseSel, 4);
        g_currentNodeIdx = v;
        *MK4_NODE(unsigned int, v) = 0x00462470u + (1u << 24);
        g_currentNodeIdx = v + 1;
        MK4_NODE_AT(unsigned int, g_baseSel, 4) = v + 1;
        MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 0;
        PendingMatch_ThreeMul10Stores();
        g_framePauseFlag = 1;
    }
}

void PendingMatch_DownloadPlayerChar(void)
{
    unsigned int cmd = MK4_NODE_AT(unsigned int, g_baseSel, 0x84);
    unsigned int v, node;

    MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 0;

#ifdef TARGET_SDL
    /* MK4_TRACE_DL: the select's download state machine, one line a visit. */
    { extern void SDL_Log(const char *, ...); extern char *getenv(const char *);
      static unsigned n;
      if (getenv("MK4_TRACE_DL") && n < 24) { n++;
          SDL_Log("DL cmd=%u gate=%x ladder=%x p1=%u p2=%u", cmd,
                  g_dlGate54356c, g_ladderState, g_activeP1, g_activeP2); } }
#endif

    switch (cmd) {

    case 1:                                      /* 0x461ccd - the demo pair */
        if (g_modeByte543590 == 1) {
            v = g_charIdP2 + 1u;
            g_charIdP2 = v;
            if ((int)v >= 0xf) g_charIdP2 = 0;
        } else {
            v = g_charIdP1 + 1u;
            g_charIdP1 = v;
            if ((int)v >= 0xf) g_charIdP1 = 0;
        }
        g_slot54 = 0x535cfcu >> 2;
        g_dlBusyByte = 1;
        g_walkSlot6c = g_charIdP1;
        g_slot70 = 0;
        DownloadPlayerChar();
        if (g_framePauseFlag != 0) return;
        g_slot70 = 1;
        g_walkSlot6c = g_charIdP2;
        DownloadPlayerChar();
        if (g_framePauseFlag != 0) return;
        g_dlBusyByte = 0;
        StackPopDispatchTagged();
        return;

    case 2:                                      /* 0x461d70 - the VS screen */
        TaggedSceneDispatch(*MK4_VA(unsigned short, 0x4e2888u));
        PackedTableWalkChainStore();
        if (g_framePauseFlag != 0) return;
        MStackPush2ScaledChainLoop();
        if (g_framePauseFlag != 0) return;
        StoreTwoCall(0x004626f0, 0x254);
        g_walkSlot6c = 0;
        g_vsBusy537f74 = 0;
        g_fightGroupHead = 0x4ea518u >> 2;
        StoreTwoCall(0x00427780, 0x262);
        StoreTwoCall(0x00462660, 0x257);
        goto arm3;

    case 3:                                      /* 0x461df4 */
        g_walkSlot6c = g_wait537f28;
        if (g_wait537f28 != 0) goto state6;
        g_walkSlot6c = g_wait53a350;
        if (g_wait53a350 != 0) goto state6;
    arm3:
        MK4_NODE_AT(unsigned int, g_baseSel, 8) = DL_VA;
        MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 3;
        g_pendingNodeType = 1;
        g_framePauseFlag = 1;
        return;

    case 4:                                      /* 0x461e3c */
        if (g_activeP1 != 0) {
            g_walkSlot6c = g_groupP1;
            g_slot74 = 0;
        }
        g_slot70 = g_activeP2;
        if (g_activeP2 != 0) {
            g_walkSlot6c = g_groupP2;
            g_slot74 = 1;
        }
        SetTagsCallCmpToggleDirty();
        if (g_framePauseFlag != 0) return;
        if ((g_stateBits8c & 1u) == 0) goto state5;
        g_walkSlot6c = g_slot74;
        dl_chain(5, RoundEndHandlerCluster);
        return;

    case 5:                                      /* 0x461f06 - back to attract */
    state5:
        g_walkSlot6c = 0;
        g_activeP1 = 0;
        g_activeP2 = 0;
        BootInitGuardedCallChain();
        if (g_framePauseFlag != 0) return;
        GuardedSeq_ZeroTriple_then_PendingMatch();
        return;

    case 6:                                      /* 0x4620ae */
    state6:
        TripleStageRollback(0x262);
        g_slot74 = 0x4a;
        Push16Call();
        if (g_framePauseFlag != 0) return;
        /* state SEVEN is past the table - the next visit takes the shared
         * exit at 0x00462433 on purpose */
        dl_chain(7, AudioInstallSelfStatePush);
        return;

    case 0:                                      /* 0x461f32 - the entry */
        TableWalkBoundedCmp(2);
        TableWalkBoundedCmp(5);
        if (g_dlGate54356c != 0) {
            dl_chain(1, AudioInstallSelfStatePush);
            return;
        }
        QuadCallPhase2(0x1e, -1, -1, -1);
        g_walkSlot6c = 9;
        g_tickFlagF = 9;
        SequencedInit3Call();
        if (g_framePauseFlag != 0) return;
        MStackChainPackedDispatch();
        if (g_framePauseFlag != 0) return;
        g_slot74 = 0x49;
        Push16Call();
        if (g_framePauseFlag != 0) return;

        g_pendingNodeType = g_chainBase541fb8;
        v = *MK4_NODE(unsigned int, g_pendingNodeType);
        g_walkSlot6c = v;
        while (v != 0) {
            CombatChainWalkExpand();
            if (g_framePauseFlag != 0) return;
            g_pendingNodeType = g_pendingNodeType + 4u;
            v = *MK4_NODE(unsigned int, g_pendingNodeType);
            g_walkSlot6c = v;
        }

        g_walkSlot6c = g_ladderState;
        if (g_ladderState == 0) {                /* 0x462355 - the select's own */
            DualPathDownloadChar();
            if (g_framePauseFlag != 0) return;
            node = g_chainBase541fb4;
            g_vsBusy537f74 = 1;
            g_walkSlot6c = 0;
            g_currentNodeIdx = node;
            g_xformLoopCounter = 4;
            do {
                *MK4_NODE(unsigned int, g_currentNodeIdx) = g_walkSlot6c;
                g_currentNodeIdx = g_currentNodeIdx + 1u;
                g_xformLoopCounter = g_xformLoopCounter - 1u;
            } while ((int)g_xformLoopCounter >= 0);
            g_ladderState = 1;
            g_wait537f28 = g_walkSlot6c;
            g_walkSlot6c = 0;
            g_ladderIdx = 0;
            dl_chain(2, InstallSelfFullChainInit);
            return;
        }

        MkTowerScreenFsmCluster();
        if (g_framePauseFlag != 0) return;
        StoreCallPauseCmpDirty();
        if (g_framePauseFlag != 0) return;
        if ((g_stateBits8c & 1u) != 0) {         /* 0x4622e9 */
            g_walkSlot6c = 1;
            g_vsBusy537f74 = 1;
            dl_chain(4, InstallSelfStateMachine_SwapOrPassSet);
            return;
        }
        DirtyBitToggleDispatch();
        if (g_framePauseFlag != 0) return;
        if ((g_stateBits8c & 4u) != 0)
            goto state6;

        /* 0x462135 - the tower/ladder body */
        DualPathDownloadChar();
        if (g_framePauseFlag != 0) return;
        g_fightGroupHead = g_titleLogoNode;
        g_walkSlot6c = g_ladderState - 1u;
        MStackChainCountdownLoop();
        if (g_framePauseFlag != 0) return;
        MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x54) = g_slot70 + 0xffffc290u;
        MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x58) = g_slot74;
        g_slot78 = g_slot78 - 0x51eu;
        MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x5c) = g_slot78;
        g_walkSlot6c = 0x6978;
        g_slot70 = 0x20000;
        FixedDiv16();
        if (g_framePauseFlag != 0) return;
        g_slot74 = g_slot74 - g_walkSlot6c;
        MK4_NODE_AT(unsigned int, g_fightGroupHead, 0x58) = g_slot74;
        g_walkSlot6c = g_ladderIdx << 2;
        g_pendingNodeType = (g_ladderIdx << 2) + g_chainBase541fb8;
        g_walkSlot6c = MK4_NODE_AT(unsigned int, g_pendingNodeType, 4);
        MK4_NODE_AT(unsigned int, g_fightGroupHead, 0x54) = g_walkSlot6c;
        MK4_NODE_AT(unsigned int, g_fightGroupHead, 0x5c) =
            MK4_NODE_AT(unsigned int, g_pendingNodeType, 8) - 0x20000u;
        g_walkSlot6c = 0;
        MK4_NODE_AT(unsigned int, g_fightGroupHead, 0x60) = 0;
        MK4_NODE_AT(unsigned int, g_fightGroupHead, 0x64) = 0;
        MK4_NODE_AT(unsigned int, g_fightGroupHead, 0x68) = 0;
        PlayerCharSelector();
        if (g_framePauseFlag != 0) return;
        g_slot58 = 0x50;
        g_slot54 = g_ladderState;
        dl_chain(6, Push0_Push463220_Jmp);
        return;

    default:                                     /* 0x462433 - anything > 6 */
        break;
    }

    ScenegraphWalk();
    BootInitGuardedCallChain();
    if (g_framePauseFlag != 0) return;
    StackPopDispatchTagged();
}

#endif /* NON_MATCHING */
