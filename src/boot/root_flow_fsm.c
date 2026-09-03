/**
 * The ROOT game-flow controller, 0x00401b70
 * (PendingMatch_LeaPlus22StoreSelf in symbols.yaml).
 *
 * This is the node the engine installs as g_pendingNodeType 0x004200b0's
 * body: GuardedSeq_ZeroTriple_then_PendingMatch calls ZeroTriple and, if the
 * frame is not paused, tail-jumps here. It is the ONE controller that is
 * created with work type 0x11, so the pump at 0x0041f570 runs it on every
 * frame no matter which screen owns g_gameMode - it is the attract/title/
 * game-flow master, and every screen that hands off to another screen does
 * it by parking a state here.
 *
 * Why it landed now: the pump only reached this node once the node unlink in
 * BootScheduledNodeTimerWalk was fixed to pass a host pointer. Before that,
 * a controller that released itself with CallSetPause stayed in the list
 * forever, and the leaked screen node kept driving the frame - which hid the
 * fact that the root's body was still a weak autostub. MK4_TRACE_STUBS on
 * the boot-match path named it: 240 calls, 240 frames, one per frame.
 *
 * Shape: 21 states off a jump table at 0x004022fc, plus a shared default for
 * anything above 0x14. Nearly every state is the standard "chain(N, Sub)"
 * hand-off - park N as the resume word, queue the tagged continuation
 * 0x401b70 + (N << 24) on the node's spare chain at +4, call the sub-screen,
 * pause - so root_chain() below carries the whole idiom once.
 *
 * Two states loop instead of returning. State 3 and state 13 both re-enter
 * the dispatch at 0x00401bf5 when SceneFrameStepWithInputs reports a live
 * frame, re-running LeaPlus22StoreSelf and re-reading the resume word; that
 * is the for(;;) here, and the two `break`s are the only way into it.
 *
 * The default body (0x00401c1e, also state 20's table entry) counts
 * g_pendingMatchSlot up and clears g_pendingMatchSlot2 past 3, then FALLS
 * INTO state 2 - the fallthrough is deliberate and matches the binary.
 *
 * NATIVE-ONLY twin: the matching build keeps the naked body in
 * src/boot/pending_match_variants.c and synthesizes the original bytes.
 */
#ifdef NON_MATCHING

#include "portable/mem_model.h"

extern void LeaPlus22StoreSelf(void);
extern void CopyGlobal(void);
extern void Push16Call(void);
extern void ZeroMultiGlobalsCmp(void);
extern void AudioVolumeRescale(void);
extern void TableWalkBoundedCmp(int kind);
extern void QuadCallPhase2(int a, int b, int c, int d);
extern void SceneFrameStepWithInputs(void);
extern void StoreTwoCall(int fn, int arg);
extern void PendingMatch_004a2a80(void);
extern void PhaseInstallSelf3Step(void);
extern void PendingMatch_Push16Call_00402540(void);
extern void BootStateInitWithRecurseInstall(void);
extern void TitleDemoStateMachine(void);
extern void BootStateMachine4Way(void);
extern void Screen_GreatestWarrior(void);
extern void Screen_BestKombatants(void);
extern void BootInitVec3PhaseInstall(void);
extern void InstallSelfCounter(void);

#define g_currentNodeIdx     (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_dualC              (*(unsigned int *)MK4_VA(unsigned int, 0x54204cu))
#define g_baseSel            (*(unsigned int *)MK4_VA(unsigned int, 0x542060u))
#define g_walkCallback       (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_eventQueueWorkType (*(unsigned int *)MK4_VA(unsigned int, 0x542074u))
#define g_xformDirtyFlags    (*(unsigned int *)MK4_VA(unsigned int, 0x54208cu))
#define g_framePauseFlag     (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_pendingMatchSlot2  (*(unsigned int *)MK4_VA(unsigned int, 0x541dc0u))
#define g_zeroTripleA        (*(unsigned int *)MK4_VA(unsigned int, 0x541de8u))
#define g_zeroTripleB        (*(unsigned int *)MK4_VA(unsigned int, 0x541decu))
#define g_titleDemoState     (*(unsigned int *)MK4_VA(unsigned int, 0x541df0u))
#define g_titleDemoState2    (*(unsigned int *)MK4_VA(unsigned int, 0x541df4u))
#define g_pendingMatchSlot   (*(unsigned int *)MK4_VA(unsigned int, 0x53a19cu))
#define g_pendingMatchAcc    (*(unsigned int *)MK4_VA(unsigned int, 0x53a3e8u))
#define g_phaseIdx           (*(unsigned int *)MK4_VA(unsigned int, 0x53a50cu))
#define g_activeP1           (*(unsigned int *)MK4_VA(unsigned int, 0x53a408u))
#define g_activeP2           (*(unsigned int *)MK4_VA(unsigned int, 0x537e88u))
#define g_tickFlagF          (*(unsigned int *)MK4_VA(unsigned int, 0x52aac4u))

#define ROOT_FSM_VA 0x00401b70u

/* The hand-off every state but 0, 1 and 3 ends in: park the resume word,
 * queue the tagged continuation on the spare chain at +4, run the sub-screen,
 * pause. The resume word is written twice on purpose - the original stores N
 * before the chain push and clears it after, so a sub-screen that reads +0x84
 * during its own build sees zero, not N. */
static void root_chain(unsigned int st, void (*sub)(void))
{
    unsigned int v;

    MK4_NODE_AT(unsigned int, g_baseSel, 8) = ROOT_FSM_VA;
    MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = st;
    v = MK4_NODE_AT(unsigned int, g_baseSel, 4);
    g_currentNodeIdx = v;
    *MK4_NODE(unsigned int, v) = ROOT_FSM_VA + (st << 24);
    g_currentNodeIdx = v + 1;
    MK4_NODE_AT(unsigned int, g_baseSel, 4) = v + 1;
    MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 0;
    sub();
    g_framePauseFlag = 1;
}

/* rearm(N): keep the node, come back in state N next frame. */
static void root_rearm(unsigned int st)
{
    MK4_NODE_AT(unsigned int, g_baseSel, 8) = ROOT_FSM_VA;
    MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = st;
    g_dualC = 1;
    g_framePauseFlag = 1;
}

/* State 4's body has two entries: the table, and state 3's "frame is done"
 * exit at 0x00401bc6. */
static void root_state4(void)
{
    g_eventQueueWorkType = 0;
    Push16Call();
    if (g_framePauseFlag != 0)
        return;
    QuadCallPhase2(0x1e, -1, -1, -1);
    root_chain(5, PhaseInstallSelf3Step);
}

/* WHERE THIS FSM ACTUALLY GETS TO, measured 2026-09-02.
 *
 * Across a full front-end run - mode select, character select, the tower, and
 * the tower's timeout - MK4_TRACE_ROOT shows this machine running states 0, 1
 * and 2 exactly once each and then never again. That is not a stall. State 2
 * chains to state 3 THROUGH the menu controller PendingMatch_004a2a80, so the
 * root parks until the menu releases, and the menu never does: the harness
 * force-drives past it. Everything the front-end has been doing since - the
 * select, the download FSM, the tower - runs on a branch installed UNDERNEATH
 * a root still waiting on the menu.
 *
 * That is why the tower's state-7 release lands back on the mode-select menu
 * rather than in a match. The release pops the tagged continuation and the
 * menu, still parked as state 2's chain target, simply resumes. Nothing is
 * broken there; the flow is returning to exactly where the root left it.
 *
 * Root state 3 is the live frame - QuadCallPhase2(0x16, ...) then
 * SceneFrameStepWithInputs(0, 1) - so the route to an actual match runs
 * through the menu RELEASING, not through anything on the tower screen.
 *
 * Second measurement, worth knowing before trusting any front-end trace: this
 * FSM is not dispatched at all without MK4_MAIN_MENU. That flag sets gameMode
 * (0x543800) to -1, and it is the gameMode filter that lets the root node
 * through the pump. On a plain boot MK4_TRACE_ROOT prints nothing whatsoever.
 * So the front-end work so far has been running with the harness holding
 * gameMode open, which is a scaffold, not the game's own condition - see the
 * lesson in feedback_port_scaffold_env_gates.
 */
void PendingMatch_LeaPlus22StoreSelf(void)
{
    unsigned int st;

    for (;;) {
        LeaPlus22StoreSelf();

        st = MK4_NODE_AT(unsigned int, g_baseSel, 0x84);
        MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 0;
        if (st > 0x14u)
            st = 20;                       /* the default IS state 20's entry */

#ifdef TARGET_SDL
        /* MK4_TRACE_ROOT: the state the game-flow master runs each frame. */
        { extern void SDL_Log(const char *, ...); extern char *getenv(const char *);
          static unsigned n;
          if (getenv("MK4_TRACE_ROOT") && n < 400) { n++;
              SDL_Log("ROOT st=%u pause=%u", st, g_framePauseFlag); } }
#endif

        switch (st) {

        case 0:                            /* 0x004022d6 - first tick */
            g_walkCallback = 0;
            CopyGlobal();
            root_rearm(1);
            return;

        case 1:                            /* 0x00401cb8 - global reset */
            TableWalkBoundedCmp(9);
            g_eventQueueWorkType = 0;
            Push16Call();
            if (g_framePauseFlag != 0)
                return;
            g_phaseIdx = 0;
            g_walkCallback = 2;
            g_tickFlagF = 2;
            g_eventQueueWorkType = 0;
            Push16Call();
            if (g_framePauseFlag != 0)
                return;
            ZeroMultiGlobalsCmp();
            if (g_framePauseFlag != 0)
                return;
            g_walkCallback = 0;
            g_pendingMatchSlot2 = 0;
            g_pendingMatchSlot = 0;
            g_activeP1 = 0;
            g_activeP2 = 0;
            root_rearm(2);
            return;

        case 3:                            /* 0x00401baa - the live frame */
            QuadCallPhase2(0x16, -1, -1, -1);
            if (((int (*)(int, int))SceneFrameStepWithInputs)(0, 1) == 0) {
                root_state4();
                return;
            }
            break;                         /* re-dispatch, 0x00401bf5 */

        case 4:                            /* 0x00401d46 */
            root_state4();
            return;

        case 5:                            /* 0x00401dc0 */
            root_chain(6, PendingMatch_Push16Call_00402540);
            return;

        case 6:                            /* 0x00401e14 - volume, then fork */
            g_walkCallback = 0x64;
            AudioVolumeRescale();
            MK4_NODE_AT(unsigned int, g_baseSel, 8) = ROOT_FSM_VA;
            if ((g_xformDirtyFlags & 1u) != 0)
                root_chain(7, BootStateInitWithRecurseInstall);
            else
                root_chain(9, BootStateInitWithRecurseInstall);
            return;

        case 7:                            /* 0x00401e76 */
            root_chain(8, TitleDemoStateMachine);
            return;

        case 8:                            /* 0x00401f1d - shared with 10 */
        case 10:
            TableWalkBoundedCmp(8);
            QuadCallPhase2(0x1c, -1, -1, -1);
            root_chain(0xb, Screen_GreatestWarrior);
            return;

        case 9:                            /* 0x00401eca */
            root_chain(0xa, BootStateMachine4Way);
            return;

        case 11:                           /* 0x00401f8a */
            QuadCallPhase2(0x1e, -1, -1, -1);
            root_chain(0xc, Screen_BestKombatants);
            return;

        case 12:                           /* 0x00401fee */
            root_chain(0xd, BootInitVec3PhaseInstall);
            return;

        case 13:                           /* 0x00401bce - the demo counter */
            g_pendingMatchAcc = g_pendingMatchAcc + 1;
            if (g_pendingMatchAcc != 4) {
                root_chain(0xe, BootStateInitWithRecurseInstall);
                return;
            }
            if (((int (*)(int, int))SceneFrameStepWithInputs)(0x23, 1) == 0) {
                g_pendingMatchAcc = 0;
                root_chain(0xe, BootStateInitWithRecurseInstall);
                return;
            }
            break;                         /* re-dispatch, 0x00401bf5 */

        case 14:                           /* 0x0040209a */
            root_chain(0xf, BootStateMachine4Way);
            return;

        case 15:                           /* 0x004020ee */
            TableWalkBoundedCmp(8);
            QuadCallPhase2(0x1e, -1, -1, -1);
            StoreTwoCall(0x004a2180, 0);
            QuadCallPhase2(0x1c, -1, -1, -1);
            root_chain(0x10, Screen_GreatestWarrior);
            return;

        case 16:                           /* 0x00402179 */
            QuadCallPhase2(0x1e, -1, -1, -1);
            root_chain(0x11, Screen_BestKombatants);
            return;

        case 17:                           /* 0x004021dc */
            root_chain(0x12, InstallSelfCounter);
            return;

        case 18:                           /* 0x00402230 */
            root_chain(0x13, BootStateInitWithRecurseInstall);
            return;

        case 19:                           /* 0x00402283 */
            root_chain(0x14, TitleDemoStateMachine);
            return;

        case 20:                           /* 0x00401c1e, and every st > 0x14 */
            g_pendingMatchSlot = g_pendingMatchSlot + 1;
            if (g_pendingMatchSlot > 3u)
                g_pendingMatchSlot2 = 0;
            /* FALLTHROUGH into state 2 - the binary does the same */

        case 2:                            /* 0x00401c37 */
            g_walkCallback = 0;
            g_zeroTripleA = 0;
            g_zeroTripleB = 0;
            g_titleDemoState = 0;
            g_titleDemoState2 = 0;
            QuadCallPhase2(0x1e, -1, -1, -1);
            root_chain(3, PendingMatch_004a2a80);
            return;
        }
    }
}

#endif /* NON_MATCHING */
