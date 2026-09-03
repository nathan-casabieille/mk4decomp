/**
 * Screen_ArcadeEnding (0x420300, 4216b) - the MATCH SEQUENCER.
 *
 * The name is the auto-namer's guess; the function is the 19-state FSM that
 * runs one whole match: stage the two characters and hand the loading screen
 * their asset requests (entry), wait out the load (2..4), set up the round
 * and the fighters' game records (5), run the round loop (6), tear the round
 * down and stage the winner (6's match-end tail, 7..9), then route the
 * post-match flow - victory pose, continue screen, endurance, round text -
 * through its sub-controllers (10..18).
 *
 * It is the single blocker the loading-screen investigation (f82338c95)
 * ended at: ScaledClearTripleCallJmp tail-jmps into it every frame - a
 * direct C call, which is exactly the MK4_TRACE_STUBS blind spot - and as a
 * weak stub it consumed its command and advanced nothing, so the whole boot
 * chain idled at its entry state forever.
 *
 * WHERE IT STALLS TODAY (measured 2026-09-03). MK4_TRACE_SAE over a full
 * front-end run - menu, character select, tower, timeout - shows this
 * sequencer running states 0, 2, 3 and 4 exactly once each and then nothing.
 * It never reaches state 5.
 *
 * It runs between frames 1600 and 2000, AFTER the tower times out - not
 * between 800 and 1200 as an earlier note here said. A run capped at 1200 or
 * 1400 frames shows no SAE activity at all, which is how that first bisect
 * went wrong and how a later MK4_TRACE_INSTALL run at 1400 frames appeared to
 * show state 4 never executing its install. Cap any measurement of this
 * sequencer at 2000 frames or more.
 *
 * That matters more than it looks, because state 4 is where the match is
 * actually requested: it ends with StoreTwoCall(0x4a42e0, 0x4000), the
 * loading tick - the identical call MK4_BOOT_MATCH makes by hand to put a
 * fight on screen. So the front end DOES get as far as asking for the match.
 * The request is then dropped: neither this sequencer nor the loading tick
 * appears in the node list at frames 1150 or 1300, where only the four tower
 * controllers are live, and MK4_TRACE_GAMEMODE never sees Screen_Loading
 * claim the world (which it would, at 0x4a4438, the moment it ran).
 *
 * The stall is the state-4 to state-5 hand-off. sae_arm_round() ends with
 * sae_chain(5) followed by Install3WayCountdownGame() and a pause, so state 5
 * only arrives when that sub-controller's chain unwinds. Install3WayCountdown-
 * Game is NOT the hollow one - it is converted in game/round_intro_band.c,
 * that file is in the native build, and MK4_TRACE_STUBS records no stub hit
 * for it - so the break is somewhere under it, in what it installs or what
 * that in turn waits on.
 *
 * THE LOADING TICK IS NOT STARVED OF A NODE - correcting the note that stood
 * here. With MK4_TRACE_INSTALL reporting the allocator's own result,
 * StoreTwoCall(0x4a42e0, 0x4000) is seen to give the loading tick its OWN
 * fresh node, packed 0x14fa70 = VA 0x53e9c0, installed by the download FSM's
 * node 0x14f8da that this sequencer was guesting on. The earlier claim that
 * the download FSM reclaims it came from printing g_baseSel, which is the
 * node the pump is dispatching - the INSTALLER - and not AllocateNode's
 * result, which it reports in g_currentNodeIdx.
 *
 * That node is reached, too, and the loading screen does run once. But the
 * gameMode -1 seen in that dispatch is NOT AudioInitSequence's, correcting
 * the note this replaces: a probe on AudioInitSequence's install site never
 * fires at all. The -1 comes from a SECOND site, 0x4a4287, that an earlier
 * scan missed because it only checked three instruction encodings. A full
 * sweep of every write form gives nine references to 0x543800, two more than
 * the seven previously listed.
 *
 * 0x4a4287 sits in a small function at 0x4a4260 that is the real "start the
 * game flow" install:
 *
 *     g_pendingNodeType    = 0x4200b0        the handler
 *     g_eventQueueWorkType = 0x1000
 *     call AllocNode                         NOT StoreTwoCall - which is why
 *     ...                                    MK4_TRACE_INSTALL never saw it
 *     gameMode = -1 ; 0x54206c = 2 ; 0x52aac4 = 2 ; jmp Push16Call
 *
 * and 0x4200b0 is GuardedSeq_ZeroTriple_then_PendingMatch, which tail-jmps
 * into the ROOT FLOW FSM. So this is what gives the root its node, and
 * MK4_MAIN_MENU's gameMode poke is a hand-made stand-in for it.
 *
 * Screen_Loading drives both halves, in order: +0x1b6 calls 0x4a4260 (the
 * root install, observed happening) and +0x1e3 calls AudioInitSequence (the
 * sequencer's trampoline install, never reached). So the loading screen stops
 * between those two calls, and THAT is the remaining gap - a dozen
 * instructions wide, in one function, rather than anywhere in the front end.
 *
 * OLDER NOTE, kept for the node-sharing detail it establishes:
 * With the round countdown's own probe fixed to report its first visits (it
 * only printed every 40th, so a controller that runs once and stops was
 * invisible), Install3WayCountdownGame is seen to run EXACTLY ONCE - visit 1,
 * cmd 0 - and it re-arms node 0x14f8da, whose +0xd8 reads 0x420300, this
 * sequencer. Packed 0x14f8da is VA 0x53e368, and that is the very node the
 * node list shows at frames 1150 and 1300 carrying cb=0x461ca0: the tower's
 * download FSM. So the countdown parks its continuation on a node the
 * download FSM then takes back, and the state-5 resume goes with it.
 *
 * WHY IT IS ON THE WRONG NODE: there are TWO ways into this sequencer and the
 * flow takes the wrong one. Nothing in the image installs 0x420300 itself -
 * zero references outside its own body - so it is always entered through the
 * trampoline ScaledClearTripleCallJmp (0x4202c0), and that has two callers:
 *
 *   AudioInitSequence, at 0x4a422a, does `push 0x1000; push 0x4202c0; call
 *     StoreTwoCall` - it INSTALLS the trampoline as a controller with its own
 *     node - and then sets gameMode to -1 and clears 0x54206c and 0x52aac4.
 *     This is the path that gives the sequencer a node to own. It is
 *     converted, correctly, in src/audio/audio_init_sequence.c.
 *
 *   TwoStageAudioInit (0x4a6180) ends with a plain tail-jmp to the same
 *     trampoline - a direct call on whatever node is current. Also converted
 *     correctly, in src/audio/two_stage_audio_init.c.
 *
 * Measured: neither 0x4202c0 nor InstallSelfDualBranchInit (0x4201a0, the
 * other direct caller) is EVER dispatched in a full front-end run, so
 * AudioInitSequence's install never happens. The sequencer only ever arrives
 * through TwoStageAudioInit's tail-jmp, on the download FSM's node, which is
 * why its state-5 continuation is discarded when that FSM takes the node
 * back.
 *
 * So neither twin is at fault - both match the original. The question is why
 * the flow reaches TwoStageAudioInit and never AudioInitSequence, and that is
 * the next thing to chase.
 *
 * (0x45c290, installed by state 3 as a tag-0x1d side controller, IS hollow -
 * it shows up as an unresolved code VA - but it is not in this chain and does
 * not explain the stall.)
 *
 * Control-flow conventions, shared with the other sequencer twins
 * (round_setup_states.c, load_geo_assets_state_machine.c):
 *
 *  - the controller node is g_baseSel; +0x84 is the command, read and
 *    cleared on entry; +8 is the callback slot the node pump re-invokes.
 *  - "rearm(N, type)" parks the FSM: callback = self, command = N for the
 *    next visit, g_pendingNodeType = type, pause.
 *  - "chain(N, Sub)" hands one FRAME SLICE to a sub-controller: it queues
 *    the tagged continuation 0x420300 + (N << 24) into the node queue at
 *    +4, calls Sub - which installs ITSELF as the active callback - and
 *    pauses. When Sub's chain unwinds, the queued word resumes this FSM at
 *    state N. State 17/18 chains to state 0x13, which is PAST the jump
 *    table's bound - the next visit lands in the default arm, the idle
 *    pump, which is how a finished match parks.
 *  - every sub-call is followed by a pause check; a set pause is a yield,
 *    resumed by the node pump on a later frame.
 *
 * States 5 and 6 share their round-loop body: state 5's not-yet-flagged
 * path falls into state 6's body in the original (je 0x420767), factored
 * here as sae_round_body().
 *
 * NATIVE-ONLY twin: the matching build synthesizes the original bytes
 * (the naked transcription lives in pending_match_variants.c, which is not
 * a native TU).
 */
#ifdef NON_MATCHING

#include "portable/mem_model.h"
#include "portable/code_va.h"

/* real (converted) callees */
extern void TableWalkBoundedCmp(int kind);
extern void DualScaledLitInitJmp(void);
extern void BootInitGuardedCallChain(void);
extern void QuadCallPhase2(int a, int b, int c, int d);
extern void MatchInitMonsterChain(void);
extern void StoreTwoCall(int fn, int arg);
extern void Cmp2DirtyToggle(void);
extern void SwapOrPassSet(void);
extern void Thunk_ChainNodeInit(void);
extern void AndShlStore(void);
extern void Push71_Push48caa0(void);
extern void ZeroTriple(void);
extern void Push16Call(void);
extern void CopyGlobal(void);
extern void AppInit_Misc7(void);
extern void GuardedSeq_ZeroTriple_then_PendingMatch(void);

/* the still-hollow frontier - weak no-ops in engine_frontier_stubs.c until
 * each is converted; MK4_TRACE_STUBS counts them, which is the work-list */
extern void TableWalkPause(void);
extern int  CmpDualStateMatch(void);
extern void GuardedScaledLookupCallJmp(void);
extern void DirtyKeyedStateCopy(void);
extern void TriDispatchSetupChain(void);
extern void Init28fDecLoad(void);
extern void Install3WayCountdownGame(void);
extern void MkIntroFsm(void);
extern void CallPauseEvtPushJmp(void);
extern void AiWalkCounterDualCluster(void);
extern void DualTestDirtyToggle_004282c0(void);
extern void MStackPushSearchLoop(void);
extern void GuardedChainDispatch(void);
extern void DualCounterPhaseGateInstall(void);
extern void Phase3InstallSelfChain(void);
extern void BootMultiAssetLoadStateInit(void);
extern void Push70CallScaleArith(void);
extern void StateCmpAndStoreByte(void);
extern void InstallSelfPackedF80(void);
extern void MarkSlot(int slot);
extern void Install3StateAudioChain(void);
extern void SetTagsCallCmpToggleDirty(void);
extern void RoundEndHandlerCluster(void);
extern void ContinueScreenFsm(void);
extern void ChainInit3CallTailJmp(void);
extern void EnduranceFsmCluster(void);

#define g_currentNodeIdx  (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_xformEntityIdx  (*(unsigned int *)MK4_VA(unsigned int, 0x542048u))
#define g_pendingNodeType (*(unsigned int *)MK4_VA(unsigned int, 0x54204cu))
#define g_slot50          (*(unsigned int *)MK4_VA(unsigned int, 0x542050u))
#define g_slot54          (*(unsigned int *)MK4_VA(unsigned int, 0x542054u))
#define g_groupHead       (*(unsigned int *)MK4_VA(unsigned int, 0x54205cu))
#define g_baseSel         (*(unsigned int *)MK4_VA(unsigned int, 0x542060u))
#define g_walkSlot6c      (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_slot70          (*(unsigned int *)MK4_VA(unsigned int, 0x542070u))
#define g_slot74          (*(unsigned int *)MK4_VA(unsigned int, 0x542074u))
#define g_slot78          (*(unsigned int *)MK4_VA(unsigned int, 0x542078u))
#define g_slot7c          (*(unsigned int *)MK4_VA(unsigned int, 0x54207cu))
#define g_slot80          (*(unsigned int *)MK4_VA(unsigned int, 0x542080u))
#define g_slot84          (*(unsigned int *)MK4_VA(unsigned int, 0x542084u))
#define g_slot88          (*(unsigned int *)MK4_VA(unsigned int, 0x542088u))
#define g_stateBits8c     (*(unsigned int *)MK4_VA(unsigned int, 0x54208cu))
#define g_scratch94       (*(unsigned int *)MK4_VA(unsigned int, 0x542094u))
#define g_slot2000        (*(unsigned int *)MK4_VA(unsigned int, 0x542000u))
#define g_slot2004        (*(unsigned int *)MK4_VA(unsigned int, 0x542004u))
#define g_framePauseFlag  (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_matrixStackTop  (*(unsigned int *)MK4_VA(unsigned int, 0x4d57acu))

#define g_flags52ab40     (*(unsigned int *)MK4_VA(unsigned int, 0x52ab40u))
#define g_phase52aac4     (*(unsigned int *)MK4_VA(unsigned int, 0x52aac4u))
#define g_ovrValue        (*(unsigned int *)MK4_VA(unsigned int, 0x4f3608u))
#define g_roundPhase      (*(unsigned int *)MK4_VA(unsigned int, 0x537f94u))
#define g_p1NodeIdxG      (*(unsigned int *)MK4_VA(unsigned int, 0x538158u))
#define g_p1Group         (*(unsigned int *)MK4_VA(unsigned int, 0x538038u))
#define g_p2Group         (*(unsigned int *)MK4_VA(unsigned int, 0x53803cu))
#define g_charP1          (*(unsigned int *)MK4_VA(unsigned int, 0x537f48u))
#define g_charP2          (*(unsigned int *)MK4_VA(unsigned int, 0x5380e0u))
#define g_charP1Alt       (*(unsigned int *)MK4_VA(unsigned int, 0x53a178u))
#define g_charP2Alt       (*(unsigned int *)MK4_VA(unsigned int, 0x53a250u))
#define g_stageP1         (*(unsigned int *)MK4_VA(unsigned int, 0x537f30u))
#define g_mode538094      (*(unsigned int *)MK4_VA(unsigned int, 0x538094u))
#define g_stageIdx        (*(unsigned int *)MK4_VA(unsigned int, 0x53a51cu))
#define g_srcCharP1       (*(unsigned int *)MK4_VA(unsigned int, 0x53a790u))
#define g_srcCharP2       (*(unsigned int *)MK4_VA(unsigned int, 0x537ea0u))
#define g_srcAltP1        (*(unsigned int *)MK4_VA(unsigned int, 0x537edcu))
#define g_srcAltP2        (*(unsigned int *)MK4_VA(unsigned int, 0x53a1ccu))
#define g_activeP1        (*(unsigned int *)MK4_VA(unsigned int, 0x53a408u))
#define g_activeP2        (*(unsigned int *)MK4_VA(unsigned int, 0x537e88u))
#define g_winsP1          (*(unsigned int *)MK4_VA(unsigned int, 0x53a3e0u))
#define g_winsP2          (*(unsigned int *)MK4_VA(unsigned int, 0x53a700u))
#define g_pauseHold543438 (*(unsigned int *)MK4_VA(unsigned int, 0x543438u))
#define g_dbg4f3238       (*(unsigned char *)MK4_VA(unsigned char, 0x4f3238u))
#define g_dbg4f3234       (*(unsigned int *)MK4_VA(unsigned int, 0x4f3234u))
#define g_dbgByte543590   (*(unsigned char *)MK4_VA(unsigned char, 0x543590u))
#define g_byte54380c      (*(unsigned char *)MK4_VA(unsigned char, 0x54380cu))
#define g_flag541dc8      (*(unsigned int *)MK4_VA(unsigned int, 0x541dc8u))
#define g_group53a464     (*(unsigned int *)MK4_VA(unsigned int, 0x53a464u))
#define g_flag543734      (*(unsigned int *)MK4_VA(unsigned int, 0x543734u))
#define g_flag543714      (*(unsigned int *)MK4_VA(unsigned int, 0x543714u))
#define g_flag54356c      (*(unsigned int *)MK4_VA(unsigned int, 0x54356cu))
#define g_seed53a6dc      (*(unsigned int *)MK4_VA(unsigned int, 0x53a6dcu))
#define g_demoTimer53a3c0 (*(unsigned int *)MK4_VA(unsigned int, 0x53a3c0u))
#define g_flag543744      (*(unsigned int *)MK4_VA(unsigned int, 0x543744u))
#define g_byte4d5714      (*(unsigned char *)MK4_VA(unsigned char, 0x4d5714u))
#define g_contFlag53a50c  (*(unsigned int *)MK4_VA(unsigned int, 0x53a50cu))
#define g_flag541ec0      (*(unsigned int *)MK4_VA(unsigned int, 0x541ec0u))

#define SAE_VA 0x420300u

/* park: run state N on the node pump's next visit */
static void sae_rearm(unsigned int state, unsigned int type)
{
    MK4_NODE_AT(unsigned int, g_baseSel, 8) = SAE_VA;
    MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = state;
    g_pendingNodeType = type;
    g_framePauseFlag = 1;
}

/* queue the tagged continuation for state N, then the caller hands the
 * frame to a sub-controller and pauses */
static void sae_chain(unsigned int state)
{
    unsigned int q;

    MK4_NODE_AT(unsigned int, g_baseSel, 8) = SAE_VA;
    MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = state;
    q = MK4_NODE_AT(unsigned int, g_baseSel, 4);
    g_currentNodeIdx = q;
    *(unsigned int *)MK4_PTR(q * 4) = SAE_VA + (state << 24);
    g_currentNodeIdx = q + 1;
    MK4_NODE_AT(unsigned int, g_baseSel, 4) = q + 1;
    MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 0;
}

/* 0x4211e7 - states 0/1: stage the characters, request their assets */
static void sae_entry(void)
{
    TableWalkBoundedCmp(4);
    DualScaledLitInitJmp();
    TableWalkPause();
    BootInitGuardedCallChain();

    g_walkSlot6c = 0;
    g_phase52aac4 = 0;
    if (g_slot2004 == 1) {
        unsigned int mode = g_stageP1;
        unsigned int p1 = g_srcCharP1, p2 = g_srcCharP2;
        unsigned int a1 = g_srcAltP1, a2 = g_srcAltP2;

        g_walkSlot6c = mode;
        g_charP1 = p1;
        g_charP2 = p2;
        g_charP1Alt = a1;
        g_charP2Alt = a2;
        g_scratch94 = mode & 1;
        if ((mode & 1) == 0) {
            /* the ALT ids load, published as the mains for the call */
            g_charP1 = a1;
            g_charP2 = a2;
            QuadCallPhase2((int)a1, (int)a2, (int)(g_stageIdx + 0x12), 0x1d);
            g_charP1 = p1;
            g_charP2 = p2;
        } else {
            QuadCallPhase2((int)p1, (int)p2, (int)(g_stageIdx + 0x12), 0x1d);
        }
    } else {
        QuadCallPhase2((int)g_charP1, (int)g_charP2,
                       (int)(g_stageIdx + 0x12), 0x1d);
    }

    sae_chain(2);
    MatchInitMonsterChain();
    g_framePauseFlag = 1;
}

/* 0x42060d - the round-arm tail states 4 and 5 share */
static void sae_arm_round(void)
{
    unsigned int flags, c;

    g_walkSlot6c = 6;
    AndShlStore();
    if (g_framePauseFlag != 0) return;

    flags = g_flags52ab40;
    g_flag541dc8 = 1;
    g_walkSlot6c = flags;
    g_scratch94 = flags & 0x100;
    if ((flags & 0x100) != 0) {
        Push71_Push48caa0();
        if (g_framePauseFlag != 0) return;
        flags = g_flags52ab40;
    }
    c = 0;
    g_slot70 = 0;
    if ((flags & 0x1000) != 0) {
        c = 1;
        g_slot70 = 1;
    }
    g_walkSlot6c = flags;
    g_slot2000 = c;
    g_scratch94 = flags & 0x40;
    if ((flags & 0x40) != 0) {
        Init28fDecLoad();
        if (g_framePauseFlag != 0) return;
    }
    sae_chain(5);
    Install3WayCountdownGame();
    g_framePauseFlag = 1;
}

/* 0x420767 - the per-frame ROUND LOOP, state 6's body and state 5's
 * not-yet-flagged fall-through */
static void sae_round_body(void)
{
    unsigned int who, val;

    CallPauseEvtPushJmp();
    if (g_framePauseFlag != 0) return;
    AiWalkCounterDualCluster();
    if (g_framePauseFlag != 0) return;
    DualTestDirtyToggle_004282c0();
    if (g_framePauseFlag != 0) return;

    if ((g_stateBits8c & 1) != 0) {
        SwapOrPassSet();
        if (g_framePauseFlag != 0) return;
        if (g_walkSlot6c == g_ovrValue) {
            /* the round timer elapsed: floor the losing side's meter */
            unsigned int meter, health;

            who = g_pendingNodeType;
            if (who == g_p1NodeIdxG) {
                meter  = 0x541de8u >> 2;
                health = 0x53a714u >> 2;
            } else {
                meter  = 0x541decu >> 2;
                health = 0x5380a8u >> 2;
            }
            g_currentNodeIdx = meter;
            g_xformEntityIdx = 0x541decu >> 2;
            g_slot50 = health;
            g_slot54 = 0x5380a8u >> 2;
            val = *(unsigned int *)MK4_PTR(health * 4);
            g_walkSlot6c = val;
            if (val == 0xf) {
                g_walkSlot6c = 1;
                *(unsigned int *)MK4_PTR(meter * 4) = 1;
            }
        }
    }

    g_group53a464 = (g_roundPhase == 1) ? g_p1Group : g_p2Group;

    DualTestDirtyToggle_004282c0();
    if (g_framePauseFlag != 0) return;
    if ((g_stateBits8c & 1) == 0) {
        g_slot70 = g_demoTimer53a3c0;
        MStackPushSearchLoop();
        if (g_framePauseFlag != 0) return;
        if (g_flag543734 != 0 || (int)g_slot70 >= (int)g_walkSlot6c) {
            SwapOrPassSet();
            if (g_framePauseFlag != 0) return;
            if (g_walkSlot6c == g_ovrValue) {
                val = (g_pendingNodeType == g_p1NodeIdxG) ? g_activeP1
                                                          : g_activeP2;
                g_walkSlot6c = val;
                if (val == 1)
                    goto match_end;
            }
        }
    }

    Cmp2DirtyToggle();
    if (g_framePauseFlag != 0) return;
    if ((g_stateBits8c & 1) == 0) {
        unsigned int flags = g_flags52ab40;

        g_walkSlot6c = flags;
        g_scratch94 = flags & 0x10;
        if ((flags & 0x10) != 0) {
            TriDispatchSetupChain();
            if (g_framePauseFlag != 0) return;
        }
    }
    if (g_flag543714 != 0 && g_flag54356c == 0) {
        Phase3InstallSelfChain();
        return;
    }
    GuardedChainDispatch();
    if (g_framePauseFlag != 0) return;
    if ((g_stateBits8c & 1) != 0) {
        unsigned int top = g_matrixStackTop + 1;

        g_matrixStackTop = top;
        *(unsigned int *)MK4_PTR(top * 4) = 0x421380u;  /* Phase3InstallSelfChain */
        DualCounterPhaseGateInstall();
        return;
    }
    Phase3InstallSelfChain();
    return;

match_end:                                       /* 0x42099c */
    ZeroTriple();
    if (g_framePauseFlag != 0) return;
    g_walkSlot6c = 0xa;
    g_phase52aac4 = 0xa;
    SwapOrPassSet();
    if (g_framePauseFlag != 0) return;

    who = g_slot50;
    g_slot80 = (who == g_p1Group) ? g_charP1 : g_charP2;
    if (who == g_p1Group) {
        g_currentNodeIdx = g_p2Group;
        g_slot54 = g_p1Group;
    } else {
        g_currentNodeIdx = g_p1Group;
        g_slot54 = g_p2Group;
    }

    g_byte54380c = 1;
    g_slot74 = 0xfffffffeu;
    Push16Call();
    g_xformEntityIdx = 0x421790u;
    Thunk_ChainNodeInit();
    if (g_framePauseFlag != 0) return;
    g_currentNodeIdx = g_slot54;
    g_xformEntityIdx = 0x421740u;
    Thunk_ChainNodeInit();
    if (g_framePauseFlag != 0) return;
    TableWalkBoundedCmp(1);
    sae_rearm(7, 0x21c);
}

void Screen_ArcadeEnding(void)
{
    unsigned int cmd, q;

    cmd = MK4_NODE_AT(unsigned int, g_baseSel, 0x84);
    MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 0;

#ifdef TARGET_SDL
    /* MK4_TRACE_SAE: every visit, with the command - the sequencer runs a
     * handful of states per frame through the queue, so this stays small */
    { extern void SDL_Log(const char *, ...); extern char *getenv(const char *);
      if (getenv("MK4_TRACE_SAE"))
          SDL_Log("SAE cmd=%u q=%u pause=%u", cmd,
                  MK4_NODE_AT(unsigned int, g_baseSel, 4), g_framePauseFlag); }
#endif

    switch (cmd) {
    case 0:
    case 1:
        sae_entry();
        return;

    case 2:                                      /* 0x42032e */
        sae_rearm(3, 1);
        return;

    case 3: {                                    /* 0x420353 */
        unsigned int flags;

        g_slot70 = g_mode538094;
        g_phase52aac4 = (g_mode538094 == 0) ? 4u : 6u;
        flags = g_flags52ab40;
        g_walkSlot6c = flags;
        g_scratch94 = flags & 8;
        if ((flags & 8) == 0) {
            GuardedScaledLookupCallJmp();
            if (g_framePauseFlag != 0) return;
        }
        if (g_pauseHold543438 == 0)
            StoreTwoCall(0x45c290, 0x1d);
        sae_rearm(4, 0x96);
        return;
    }

    case 4:                                      /* 0x4203d7 */
        if (g_pauseHold543438 != 0 && g_dbg4f3238 != 0) {
            if (g_dbg4f3234 == 2) {
                g_slot54 = g_p1Group;
                StoreTwoCall(0x4aa750, 0);
                g_slot54 = g_p2Group;
                StoreTwoCall(0x4aa750, 0);
            } else {
                if (g_dbgByte543590 == 1) {
                    g_slot54 = g_p1Group;
                    StoreTwoCall(0x4aa750, 0);
                }
                if (g_dbgByte543590 == 2) {
                    g_slot54 = g_p2Group;
                    StoreTwoCall(0x4aa750, 0);
                }
            }
        }
        StoreTwoCall(0x4a42e0, 0x4000);          /* the loading tick */
        sae_arm_round();
        return;

    case 5:                                      /* 0x420473 */
        if (g_slot70 == 0) {
            sae_chain(6);
            MkIntroFsm();
            g_framePauseFlag = 1;
            return;
        }
        if (CmpDualStateMatch() != 0)
            return;
        Cmp2DirtyToggle();
        if (g_framePauseFlag != 0) return;
        if ((g_stateBits8c & 1) == 0) {
            sae_round_body();
            return;
        }
        SwapOrPassSet();
        if (g_framePauseFlag != 0) return;
        {
            unsigned int val =
                *(unsigned int *)MK4_PTR(g_xformEntityIdx * 4);

            g_walkSlot6c = val;
            if ((int)val >= (int)(g_ovrValue - 1)) {
                DirtyKeyedStateCopy();
                if (g_framePauseFlag != 0) return;
                if ((g_stateBits8c & 4) != 0) {
                    sae_round_body();
                    return;
                }
            }
        }
        g_slot7c = 0;
        g_slot80 = 0;
        TriDispatchSetupChain();
        if (g_framePauseFlag != 0) return;
        DirtyKeyedStateCopy();
        if (g_framePauseFlag != 0) return;
        if ((g_stateBits8c & 4) != 0) {
            sae_round_body();
            return;
        }
        DirtyKeyedStateCopy();
        if (g_framePauseFlag != 0) return;
        {
            unsigned int rec = g_xformEntityIdx;

            g_slot84 = MK4_NODE_AT(unsigned int, rec, 0x54);
            g_slot88 = MK4_NODE_AT(unsigned int, rec, 0x5c);
        }
        g_xformEntityIdx = 0x4694c0u;
        Thunk_ChainNodeInit();
        if (g_framePauseFlag != 0) return;
        {
            unsigned int cur = g_currentNodeIdx;

            MK4_NODE_AT(unsigned int, cur, 0x28) = g_groupHead;
            MK4_NODE_AT(unsigned int, cur, 0x74) = 0x2012;
            MK4_NODE_AT(unsigned int, cur, 0x5c) = g_slot84;
            MK4_NODE_AT(unsigned int, cur, 0x60) = g_slot88;
        }
        {
            unsigned int slot = (g_seed53a6dc != 0) ? (0x537f2cu >> 2)
                                                    : (0x53a6dcu >> 2);

            g_slot70 = 0x10000;
            g_currentNodeIdx = slot;
            g_xformEntityIdx = 0x537f2cu >> 2;
            *(unsigned int *)MK4_PTR(slot * 4) = 0x10000;
        }
        g_roundPhase = 0;
        g_flag541dc8 = 0;
        sae_arm_round();
        return;

    case 6:                                      /* 0x42075a */
        if (CmpDualStateMatch() != 0)
            return;
        sae_round_body();
        return;

    case 7:                                      /* 0x420a9f */
        sae_rearm(8, 0x3c);
        return;

    case 8:                                      /* 0x420ac9: winner pose */
        q = MK4_NODE_AT(unsigned int, g_baseSel, 4);
        g_currentNodeIdx = q;
        *(unsigned int *)MK4_PTR(q * 4) = g_slot80;
        g_currentNodeIdx = q + 1;
        MK4_NODE_AT(unsigned int, g_baseSel, 4) = q + 1;
        BootInitGuardedCallChain();
        if (g_framePauseFlag != 0) return;
        g_walkSlot6c = 0;
        CopyGlobal();
        if (g_framePauseFlag != 0) return;
        AppInit_Misc7();
        sae_rearm(9, 2);
        return;

    case 9: {                                    /* 0x420b56: victory scene */
        static const struct { unsigned int rec, ofs; } quad[4] = {
            { 0x4deda0u, 0xffba0000u },
            { 0x4dedc0u, 0xffec0000u },
            { 0x4dedd8u, 0x000a0000u },
            { 0x4dede8u, 0x00280000u },
        };
        int i;

        g_slot74 = 0x3e;
        Push16Call();
        if (g_framePauseFlag != 0) return;
        g_walkSlot6c = 0;
        g_activeP1 = 0;
        g_activeP2 = 0;
        BootMultiAssetLoadStateInit();
        if (g_framePauseFlag != 0) return;
        for (i = 0; i < 4; i++) {
            g_xformEntityIdx = quad[i].rec >> 2;
            g_walkSlot6c = 0xa;
            g_slot70 = 4;
            g_slot78 = 0;
            g_slot7c = quad[i].ofs;
            Push70CallScaleArith();
            if (g_framePauseFlag != 0) return;
            MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x5c) = 0x10000;
        }
        g_walkSlot6c = 0x10000;
        StateCmpAndStoreByte();
        sae_rearm(0xa, 0x2d0);
        return;
    }

    case 0xa:                                    /* 0x420cfc */
        g_slot70 = 4;
        sae_chain(0xb);
        InstallSelfPackedF80();
        g_framePauseFlag = 1;
        return;

    case 0xb: {                                  /* 0x420d67: teardown */
        int k;

        TableWalkBoundedCmp(9);
        ZeroTriple();
        if (g_framePauseFlag != 0) return;
        for (k = 2; k <= 7; k++)
            TableWalkBoundedCmp(k);
        BootInitGuardedCallChain();
        if (g_framePauseFlag != 0) return;
        q = MK4_NODE_AT(unsigned int, g_baseSel, 4) - 1;
        g_currentNodeIdx = q;
        g_slot7c = *(unsigned int *)MK4_PTR(q * 4);
        MK4_NODE_AT(unsigned int, g_baseSel, 4) = q;
        g_byte4d5714 = 1;
        g_flag543744 = 1;
        MarkSlot((int)g_slot7c);
        sae_chain(0xc);
        Install3StateAudioChain();
        g_framePauseFlag = 1;
        return;
    }

    case 0xc:                                    /* 0x420e72: score the round */
        g_flag543744 = 0;
        TableWalkBoundedCmp(8);
        if (g_roundPhase == 1) {
            g_walkSlot6c = g_winsP1;
            SetTagsCallCmpToggleDirty();
            if (g_framePauseFlag != 0) return;
            if ((g_stateBits8c & 1) == 0 || g_flag543714 != 0)
                goto continue_screen;
            g_activeP1 = 1;
            g_slot74 = 0;
            g_winsP1 += 1;
            sae_chain(0xd);
            RoundEndHandlerCluster();
            g_framePauseFlag = 1;
        } else {
            g_walkSlot6c = g_winsP2;
            SetTagsCallCmpToggleDirty();
            if (g_framePauseFlag != 0) return;
            if ((g_stateBits8c & 1) == 0 || g_flag543714 != 0)
                goto continue_screen;
            g_slot74 = 1;
            g_activeP2 = 1;
            g_winsP2 += 1;
            sae_chain(0xe);
            RoundEndHandlerCluster();
            g_framePauseFlag = 1;
        }
        return;

    case 0xd:                                    /* 0x420fb6 */
        g_activeP1 = 0;
        goto continue_screen;
    case 0xe:                                    /* 0x420fbe */
        g_activeP2 = 0;
        goto continue_screen;

    continue_screen:                             /* 0x420fc9 */
        g_phase52aac4 = 2;
        g_contFlag53a50c = 1;
        g_flag541ec0 = 1;
        sae_chain(0xf);
        ContinueScreenFsm();
        g_framePauseFlag = 1;
        return;

    case 0xf:                                    /* 0x42103b */
        sae_chain(0x10);
        ChainInit3CallTailJmp();
        g_framePauseFlag = 1;
        return;

    case 0x10:                                   /* 0x42109b */
        g_flag541ec0 = 0;
        sae_chain(0x11);
        EnduranceFsmCluster();
        g_framePauseFlag = 1;
        return;

    case 0x11:
    case 0x12: {                                 /* 0x421101: match verdict */
        unsigned int a1 = g_activeP1, a2 = g_activeP2;

        g_walkSlot6c = a1;
        if (a1 == 0) {
            g_walkSlot6c = a2;
            if (a2 == 0)
                break;                           /* idle pump */
        }
        if (a1 != 0) {
            g_walkSlot6c = g_winsP1;
            g_slot74 = 0;
        }
        g_slot70 = a2;
        if (a2 != 0) {
            g_walkSlot6c = g_winsP2;
            g_slot74 = 1;
        }
        SetTagsCallCmpToggleDirty();
        if (g_framePauseFlag != 0) return;
        if ((g_stateBits8c & 1) == 0)
            break;                               /* idle pump */
        g_walkSlot6c = g_slot74;
        sae_chain(0x13);                         /* past the table: parks */
        RoundEndHandlerCluster();
        g_framePauseFlag = 1;
        return;
    }

    default:
        break;
    }

    /* 0x42131f - the idle pump, and every out-of-range state */
    GuardedSeq_ZeroTriple_then_PendingMatch();
}

#endif /* NON_MATCHING */
