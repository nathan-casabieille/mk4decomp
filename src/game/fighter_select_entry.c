/**
 * ARCADE, part two: the hand-off from the join screen to the FIGHTER SELECT.
 *
 * The join screen's state 1 picks one of four exits by "are both players in"
 * and the 1-on-1 / 2-on-2 toggle. All four were weak no-ops, and a no-op is
 * worse than nothing here: the exit is expected to install the next
 * controller and PAUSE, so returning without pausing left the node pump
 * re-entering the join controller inside the same frame, which chained the
 * fade again, which spawned another overlay - an unbounded loop. Pressing
 * the action key a second time on the join screen hung the process.
 *
 * The three small exits share one shape: point currentNodeIdx/xformEntityIdx
 * at the confirming player's pair (0x53a408 + 0x53a3e0 for P1, 0x537e88 +
 * 0x53a700 for P2, chosen by the same g_dbgByte543590 the menu set),
 * DualScaledStoreConst to stamp 0 and 2 through them, ClearTwoCallSetStore
 * to re-enter the scene, set g_dlMode (0 for one player, 1 for two),
 * SixCallSeqPushImm to sweep the six asset kinds, and tail into
 * InstallSelfTableWalk unless something paused on the way.
 * AudioModeInitVariant is the two-player one: it runs the stamp twice, once
 * per player, and clears dirty bit 0 first.
 *
 *   ZeroMultiGlobalsCmp (0x404680) - the round/player state wipe, with
 *     0x535de4 cleared only when BOTH audio path flags are clear.
 *   IncOrZero9 (0x422080) - the stage counter 0x53a51c, wrapping past 9.
 *   DualScaledStoreConst (0x4a22c0) - *xformEntityIdx = 0, *currentNodeIdx = 2.
 *   ClearTwoCallSetStore (0x4a2270) - BootInitGuardedCallChain then
 *     ZeroMultiGlobalsCmp, and on success baseSel[+0xc] = 0x1000.
 *   SixCallSeqPushImm (0x4a1d80) - TableWalkBoundedCmp for kinds 9,2,3,4,5,7.
 *   InstallSelfTableWalk (0x4200d0) - the fighter-select controller's entry.
 *     State 0 bumps the stage counter, runs DispatchPair on it, chains state
 *     1 and hands the frame to SceneEvalFsm. Any other state goes to
 *     InstallSelfDualBranchInit.
 *   InstallSelfDualBranchInit (0x4201a0) - state 0 branches on
 *     0x4f3404 (the options block's restored value) into state 1 through
 *     Set5CallPauseTestByteJmpCall or state 2 through
 *     AudioInstallSelfStatePush; states 1 and 2 share one body -
 *     TableWalkBoundedCmp(5), the scene enter, ScaledClearTripleCallJmp.
 *
 * SceneEvalFsm (0x49dea0), Set5CallPauseTestByteJmpCall (0x491950) and
 * AudioInstallSelfStatePush (0x4aa8a0) are still hollow - that is the
 * fighter grid itself. None of them can hang the pump: every path that
 * reaches them pauses on the way back.
 *
 * NATIVE-ONLY twins: the matching build synthesizes the original bytes.
 */
#ifdef NON_MATCHING

#include "portable/mem_model.h"

extern void TableWalkBoundedCmp(int kind);
extern void BootInitGuardedCallChain(void);
extern void Push16Call(void);
extern void DispatchPair(void);
extern void SceneEvalFsm(void);
extern void TestCmpZeroFour(void);
extern void ScaledClearTripleCallJmp(void);
extern void Set5CallPauseTestByteJmpCall(void);
extern void AudioInstallSelfStatePush(void);
void InstallSelfTableWalk(void);
void InstallSelfDualBranchInit(void);

#define g_currentNodeIdx  (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_xformEntityIdx  (*(unsigned int *)MK4_VA(unsigned int, 0x542048u))
#define g_baseSel         (*(unsigned int *)MK4_VA(unsigned int, 0x542060u))
#define g_walkSlot6c      (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_slot74          (*(unsigned int *)MK4_VA(unsigned int, 0x542074u))
#define g_framePauseFlag  (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_dlMode          (*(unsigned int *)MK4_VA(unsigned int, 0x542004u))
#define g_confirmPlayer   (*(unsigned char *)MK4_VA(unsigned char, 0x543590u))
#define g_stageCounter    (*(unsigned int *)MK4_VA(unsigned int, 0x53a51cu))
#define g_pendingMatchSlot2 (*(unsigned int *)MK4_VA(unsigned int, 0x541dc0u))
#define g_optionsVar3     (*(unsigned int *)MK4_VA(unsigned int, 0x4f3404u))

#define TABLEWALK_VA 0x4200d0u
#define DUALBRANCH_VA 0x4201a0u

/* 0x404680 */
void ZeroMultiGlobalsCmp(void)
{
    g_walkSlot6c = 0;
    *MK4_VA(unsigned int, 0x53a3c0u) = 0;
    *MK4_VA(unsigned int, 0x537f10u) = 0;
    if (*MK4_VA(unsigned int, 0x54355cu) == 0
        && *MK4_VA(unsigned int, 0x543710u) == 0)
        *MK4_VA(unsigned int, 0x535de4u) = 0;
    *MK4_VA(unsigned int, 0x52ab00u) = 0;
    *MK4_VA(unsigned int, 0x537f8cu) = 0;
    *MK4_VA(unsigned int, 0x541d90u) = 0;
    *MK4_VA(unsigned int, 0x53a3e0u) = 0;
    *MK4_VA(unsigned int, 0x53a700u) = 0;
    *MK4_VA(unsigned int, 0x535e44u) = 0;
}

/* 0x422080 */
void IncOrZero9(void)
{
    unsigned int v = g_stageCounter + 1;

    g_walkSlot6c = v;
    if ((int)v > 9) {
        v = 0;
        g_walkSlot6c = 0;
    }
    g_stageCounter = v;
}

/* 0x4a22c0 */
void DualScaledStoreConst(void)
{
    *(unsigned int *)MK4_PTR(g_xformEntityIdx * 4) = 0;
    g_walkSlot6c = 2;
    *(unsigned int *)MK4_PTR(g_currentNodeIdx * 4) = 2;
}

/* 0x4a2270 */
void ClearTwoCallSetStore(void)
{
    g_walkSlot6c = 0;
    g_pendingMatchSlot2 = 0;
    BootInitGuardedCallChain();
    if (g_framePauseFlag != 0) return;
    ZeroMultiGlobalsCmp();
    if (g_framePauseFlag != 0) return;
    g_walkSlot6c = 0x1000;
    MK4_NODE_AT(unsigned int, g_baseSel, 0xc) = 0x1000;
}

/* 0x4a1d80 */
void SixCallSeqPushImm(void)
{
    TableWalkBoundedCmp(9);
    TableWalkBoundedCmp(2);
    TableWalkBoundedCmp(3);
    TableWalkBoundedCmp(4);
    TableWalkBoundedCmp(5);
    TableWalkBoundedCmp(7);
}

/* the shared body of the three single-stamp exits */
static void fs_stamp_confirming_player(void)
{
    if (g_confirmPlayer == 1) {
        g_currentNodeIdx = 0x53a408u >> 2;
        g_xformEntityIdx = 0x53a3e0u >> 2;
    } else {
        g_currentNodeIdx = 0x537e88u >> 2;
        g_xformEntityIdx = 0x53a700u >> 2;
    }
    DualScaledStoreConst();
}

static void fs_enter(unsigned int dlMode)
{
    ClearTwoCallSetStore();
    g_dlMode = dlMode;
    SixCallSeqPushImm();
    g_slot74 = 0;
    Push16Call();
    if (g_framePauseFlag != 0)
        return;
    InstallSelfTableWalk();                      /* jmp in the original */
}

/* 0x4a22f0 - one player, 1 on 1 */
void AudioTriEntryFlagPairInit(void)
{
    fs_stamp_confirming_player();
    fs_enter(0);
}

/* 0x4a2610 - one player, 2 on 2 */
void AudioModeInit(void)
{
    fs_stamp_confirming_player();
    fs_enter(1);
}

/* 0x4a2690 - both players */
void AudioModeInitVariant(void)
{
    *MK4_VA(unsigned int, 0x54208cu) &= 0xfffffffeu;
    g_currentNodeIdx = 0x53a408u >> 2;
    g_xformEntityIdx = 0x53a3e0u >> 2;
    DualScaledStoreConst();
    g_currentNodeIdx = 0x537e88u >> 2;
    g_xformEntityIdx = 0x53a700u >> 2;
    DualScaledStoreConst();
    fs_enter(1);
}

/* 0x4201a0 */
void InstallSelfDualBranchInit(void)
{
    unsigned int cmd = MK4_NODE_AT(unsigned int, g_baseSel, 0x84);
    unsigned int q;

    MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 0;

#ifdef TARGET_SDL
    /* MK4_TRACE_DUALBRANCH: every visit to the fighter-select entry and the
     * fork it takes. This is where the flow parks once the character select
     * has torn itself down. */
    { extern void SDL_Log(const char *, ...); extern char *getenv(const char *);
      static unsigned n;
      if (getenv("MK4_TRACE_DUALBRANCH") && n < 20) { n++;
          SDL_Log("DUALBR cmd=%u optVar3=%u", cmd, g_optionsVar3); } }
#endif
    if (cmd != 0) {                              /* states 1 and 2 share one body */
        TableWalkBoundedCmp(5);
        BootInitGuardedCallChain();
        if (g_framePauseFlag != 0) return;
        ScaledClearTripleCallJmp();
        return;
    }

    TestCmpZeroFour();
    if (g_framePauseFlag != 0) return;

    MK4_NODE_AT(unsigned int, g_baseSel, 8) = DUALBRANCH_VA;
    if (g_optionsVar3 != 0) {
        MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 1;
        q = MK4_NODE_AT(unsigned int, g_baseSel, 4);
        g_currentNodeIdx = q;
        *(unsigned int *)MK4_PTR(q * 4) = DUALBRANCH_VA + (1u << 24);
        g_currentNodeIdx = q + 1;
        MK4_NODE_AT(unsigned int, g_baseSel, 4) = q + 1;
        MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 0;
        Set5CallPauseTestByteJmpCall();
    } else {
        MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 2;
        q = MK4_NODE_AT(unsigned int, g_baseSel, 4);
        g_currentNodeIdx = q;
        *(unsigned int *)MK4_PTR(q * 4) = DUALBRANCH_VA + (2u << 24);
        g_currentNodeIdx = q + 1;
        MK4_NODE_AT(unsigned int, g_baseSel, 4) = q + 1;
        MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 0;
        AudioInstallSelfStatePush();
    }
    g_framePauseFlag = 1;
}

/* 0x4200d0 */
void InstallSelfTableWalk(void)
{
    unsigned int cmd = MK4_NODE_AT(unsigned int, g_baseSel, 0x84);
    unsigned int q;

    MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 0;

    if (cmd != 0) {
        InstallSelfDualBranchInit();
        return;
    }

    TableWalkBoundedCmp(8);
    IncOrZero9();
    if (g_framePauseFlag != 0) return;
    g_walkSlot6c = g_stageCounter;
    DispatchPair();
    if (g_framePauseFlag != 0) return;

    g_walkSlot6c = 0;
    g_pendingMatchSlot2 = 0;
    MK4_NODE_AT(unsigned int, g_baseSel, 8) = TABLEWALK_VA;
    MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 1;
    q = MK4_NODE_AT(unsigned int, g_baseSel, 4);
    g_currentNodeIdx = q;
    *(unsigned int *)MK4_PTR(q * 4) = TABLEWALK_VA + (1u << 24);
    g_currentNodeIdx = q + 1;
    MK4_NODE_AT(unsigned int, g_baseSel, 4) = q + 1;
    MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 0;
    SceneEvalFsm();
    g_framePauseFlag = 1;
}

#endif /* NON_MATCHING */
