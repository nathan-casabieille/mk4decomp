/**
 * The loading screen: LoadGeoAssetsStateMachine (0x4a38d0) and the tick it
 * hands the screen to, Screen_Loading_Tick_004a42e0.
 *
 * WHY THE NATIVE BOOT CHAIN STALLS HERE, measured 2026-08-31 with the two
 * trace knobs below. An earlier note had it that the loader never completes.
 * It does: MK4_TRACE_LOAD shows it walk 0 -> 1 -> 2 -> 3 -> 4 -> 5 and set
 * g_gameMode to 0x4a42e0. The stall is one level further on.
 *
 * The tick then spins in its state 1 forever. Its states 0 and 1 only ever
 * re-arm to state 1; the three ways out are the g_gsmOut1/2/3 work flags,
 * which MK4_BOOT_MATCH raises once and which are consumed. Only STATE 2
 * reads 0x54389c, the "assets ready" byte that gates the actual load
 * (QuadCallPhase2), and the only thing in the image that sets it is
 * State6Latch (0x48e240), reached from TripleEntryCountdownInstall
 * (0x46a230) or SlotPhaseResetInstallChain (0x48e0e0) - the round/intro FSM
 * that the port does not drive yet. So the loading screen is waiting on the
 * SEQUENCER, exactly like character select.
 *
 * Two gates ruled out on the way, both of which look like the answer and
 * are not:
 *
 *   g_logicStepFlag (0x54381c) short-circuits the tick to its signal path,
 *   and only WndProc sets it - so it reads like a Win32 gap of the kind the
 *   port keeps finding. It is not: it is menu command 0x73, and the signal
 *   path calls GameStateMachine(3), which opens the PAUSE dialog. Forcing it
 *   every frame does light the screen up (0 -> 20736 px) but what it draws
 *   is PAUSED / CONTINUE MATCH, not progress.
 *
 *   g_audioStateMask50c0 (0x4d50c0) is the other route into that same signal
 *   path, and it is zero natively where the image ships 0xffffffff. That is
 *   not a seam bug either: GameTick(0) clears the whole 64-byte block at
 *   0x4d50b4 on the first logic step, which nothing in .text writes back -
 *   it is audio channel state, armed by the audio layer the port stubs.
 *   The gate wants "armed but no longer active", i.e. a finished cue.
 *
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_currentNodeIdx;
extern unsigned int g_baseSel;
extern unsigned int g_chainAccumCur;
extern unsigned int g_cj_0054205c;
extern unsigned int g_gameCountdown;
extern unsigned int g_xformScratch94;
extern unsigned int g_fightStateProgress;
extern unsigned int g_active_00537e88;
extern unsigned int g_active_0053a408;
extern unsigned int g_audioBankSel;
#endif

extern void StoreTwoCall(int, int);
extern void SetJmp_Thunk_LinkedListBitMaskSearch(void);
extern void Thunk_ChainNodeInit(void);
extern void ScaledZeroFour(void);
extern void WalkCbSubMul10(void);
extern void Mul10Tail(unsigned int a, unsigned int b);
extern void BootMod6487eClampAndChainMul10(void);
extern void SpawnListBatchLoader(void);
extern void MStackPush2TableNot(void);
extern void GuardedChainCmpDualBitXor(void);
extern void ScaledLoadDecJmp(void);
extern void ScaledStoreCurDirtyClear(void);
extern void MStackBitmaskIncMod(void);
extern void MStackBitmaskUpdate(void);
extern void Push1eCallTestDirtyLoop(void);
extern void MStackLoopFieldInit(void);
extern void TaggedSceneDispatch(void);
extern void CallPauseDirty4StackPushFn(void);
extern void CallPauseDirty1JmpDirty4StackPush_GuardedDoubleIncCmpJmp(void);
extern void Cmp2CallDirtyCall(void);
extern void QuadBlockArgInstallChain(void);
extern void InstallSelfChainSet84_80CallW(void);
extern void Wrapper_PackedAdvanceCallTailJmp_004e46d0(void);
extern void MoveFsmCluster(void);
extern void CallPauseTestByteJmpCalls(void);
extern void InstallSelfFullPath(void);
extern void InstallSelfCountdownChain(void);
extern void CopyJmp_SlotCmp3way_g_currentNodeIdx(void);
extern void DualTestDirtyToggle_004282c0(void);
extern void TripleVecAccCallStore(void);
extern void Thunk_LoadGeoAsset_Default(void);
extern void AllocSlotPushTripleGlobals(void);
extern void MStackPop4Rewrite(void);
extern void Push70CallScaleArith(void);
extern void StreamChainStringInstall(void);
extern void MStackFrameCdeclDouble(void);
extern void ChainTableWalkStore(void);
extern void Push16Call(void);
extern void DispatcherComplex260_MStackBracket1_TreeWalkRecursive2(void);
extern void ScaledLoadCmpStoreXfm(void);
extern void StackPopDispatchTagged(void);
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_cj_00542058;
extern unsigned int g_rangeSqLimit;
extern unsigned int g_armedReloadA;
extern unsigned int g_armedReloadB;
extern unsigned int g_dualBitGate;
extern unsigned int g_eventArmReload;
extern unsigned int g_rangeBase;
#endif

extern void ScaledArrStore_ScaledChainJmp_004298c0(void);
extern void DualFieldAddSubStore(void);
extern void IterStepDualStore(int);
extern void ScaledXorStore_004900f0(void);
extern void ChainWalkInstall(void);
extern void FpuSqrtMul(void);
extern void PendingMatch_StoreTwoCall_0042b930(void);
extern void MStackPush2RunCountdown(void);
extern void MStackBracket7_DispatchAndChain(void);
extern void MStackBracketed3StoreCall(void);
extern void ChainDirtyBitWalker(void);
extern void Wrapper_ScaledChainPushCall_004ef858(void);
extern void Wrapper_ScaledChainPushCall_004ef8b0(void);
extern void Helper_DownloadSetup(void);
extern void MStackPush3CmpCall(void);
extern void Wrapper_IterLoad_0048fd30_004f12a0(void);
extern void FiveCallScaledChainTailJmp(void);
extern void SetJmp_StateDispatchYield_00438f50(void);
extern void SetJmp_StateDispatchYield_00438f60(void);
extern void GuardedDispatch_InstallSelfDualEsi(void);
extern void MStackPushZeroCallPop_PendingMatch(void);
extern void DirtyToggleByGate(void);
extern void GameDispatchValidateState(void);
extern void CrouchAttackFsmCluster(void);
extern void MStackPushVec3Mul10(void);
extern void LiteralPushCallEntZero(void);
extern void LeaPlus22StoreSelf(void);
extern void IterLoad_g_scaledInit_00542048_then_DualScaledStoreZero(void);
extern void GuardedDualConst2AndToggle(void);
extern void CallPauseScaledStorePushCall(void);
extern void LoadGeoAsset_Default(void);
extern void DispatcherComplex260_FramePauseScaledStore(void);
extern void PushSetCallPop(void);
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_stateCountdown;
extern unsigned int g_installOwnerNode;
extern unsigned int g_cj_00542054;
extern unsigned int g_audioBoundNode;
extern unsigned int g_lastGatedValue;
extern unsigned int g_lastGatedTick;
extern unsigned int g_fightAxisNegX;
extern unsigned int g_fightAxisNegY;
extern unsigned int g_fightAxisPosX;
extern unsigned int g_fightAxisPosY;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_active_00537e88 (*(unsigned int *)MK4_VA(unsigned int, 0x537e88u))
#define g_active_0053a408 (*(unsigned int *)MK4_VA(unsigned int, 0x53a408u))
#define g_armedReloadA (*(unsigned int *)MK4_VA(unsigned int, 0x541fa4u))
#define g_armedReloadB (*(unsigned int *)MK4_VA(unsigned int, 0x541fa8u))
#define g_audioBankSel (*(unsigned int *)MK4_VA(unsigned int, 0x537f94u))
#define g_audioBoundNode (*(unsigned int *)MK4_VA(unsigned int, 0x5437f0u))
#define g_audioInitScaled (*(unsigned int *)MK4_VA(unsigned int, 0x54343cu))
#define g_audioStateDisp50b4 (*(unsigned int *)MK4_VA(unsigned int, 0x4d50b4u))
#define g_audioStateMask50c0 (*(unsigned int *)MK4_VA(unsigned int, 0x4d50c0u))
#define g_audioStreamState (*(unsigned int *)MK4_VA(unsigned int, 0x53a430u))
#define g_baseSel (*(unsigned int *)MK4_VA(unsigned int, 0x542060u))
#define g_chainAccumCur (*(unsigned int *)MK4_VA(unsigned int, 0x542078u))
#define g_cj_00542054 (*(unsigned int *)MK4_VA(unsigned int, 0x542054u))
#define g_cj_00542058 (*(unsigned int *)MK4_VA(unsigned int, 0x542058u))
#define g_cj_0054205c (*(unsigned int *)MK4_VA(unsigned int, 0x54205cu))
#define g_counter_0053a51c (*(unsigned int *)MK4_VA(unsigned int, 0x53a51cu))
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_dlNalt1 (*(unsigned int *)MK4_VA(unsigned int, 0x537f48u))
#define g_dlNalt2 (*(unsigned int *)MK4_VA(unsigned int, 0x5380e0u))
#define g_dualB_00538038 (*(unsigned int *)MK4_VA(unsigned int, 0x538038u))
#define g_dualB_0053803c (*(unsigned int *)MK4_VA(unsigned int, 0x53803cu))
#define g_dualBitGate (*(unsigned int *)MK4_VA(unsigned int, 0x53a7b0u))
#define g_eventArmReload (*(unsigned int *)MK4_VA(unsigned int, 0x53a770u))
#define g_eventQueueCurrent (*(unsigned int *)MK4_VA(unsigned int, 0x542070u))
#define g_fightAxisNegX (*(unsigned int *)MK4_VA(unsigned int, 0x535e70u))
#define g_fightAxisNegY (*(unsigned int *)MK4_VA(unsigned int, 0x535e74u))
#define g_fightAxisPosX (*(unsigned int *)MK4_VA(unsigned int, 0x535e78u))
#define g_fightAxisPosY (*(unsigned int *)MK4_VA(unsigned int, 0x535e7cu))
#define g_fightStateProgress (*(unsigned int *)MK4_VA(unsigned int, 0x535ddcu))
#define g_framePauseFlag (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_gameCountdown (*(unsigned int *)MK4_VA(unsigned int, 0x53a718u))
#define g_gsmActiveFlag (*(unsigned int *)MK4_VA(unsigned int, 0xab4334u))
#define g_gsmOut1 (*(unsigned int *)MK4_VA(unsigned int, 0x543818u))
#define g_gsmOut2 (*(unsigned int *)MK4_VA(unsigned int, 0x543814u))
#define g_gsmOut3 (*(unsigned int *)MK4_VA(unsigned int, 0x543810u))
#define g_gsmOut4 (*(unsigned int *)MK4_VA(unsigned int, 0x543820u))
#define g_installOwnerNode (*(unsigned int *)MK4_VA(unsigned int, 0x535cf8u))
#define g_lastGatedTick (*(unsigned int *)MK4_VA(unsigned int, 0x54358cu))
#define g_lastGatedValue (*(unsigned int *)MK4_VA(unsigned int, 0x543598u))
#define g_logicStepFlag (*(unsigned int *)MK4_VA(unsigned int, 0x54381cu))
#define g_pendingNodeType (*(unsigned int *)MK4_VA(unsigned int, 0x54204cu))
#define g_rangeBase (*(unsigned int *)MK4_VA(unsigned int, 0x53a46cu))
#define g_rangeSqLimit (*(unsigned int *)MK4_VA(unsigned int, 0x53a180u))
#define g_stateCountdown (*(unsigned int *)MK4_VA(unsigned int, 0x53a3c0u))
#define g_tickFlagF (*(unsigned int *)MK4_VA(unsigned int, 0x52aac4u))
#define g_tickInitFlag (*(unsigned int *)MK4_VA(unsigned int, 0xab4e70u))
#define g_tickW1 (*(unsigned int *)MK4_VA(unsigned int, 0x543550u))
#define g_walkCallback (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_xformDirtyFlags (*(unsigned int *)MK4_VA(unsigned int, 0x54208cu))
#define g_xformEntityIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542048u))
#define g_xformScratch94 (*(unsigned int *)MK4_VA(unsigned int, 0x542094u))
#endif


#ifdef NON_MATCHING
#include "portable/mem_model.h"
#include "portable/code_va.h"
#define g_gameMode (*(unsigned int *)MK4_VA(unsigned int, 0x543800u))

extern void TableWalkBoundedCmp(int);
extern void LoadGeoAsset_Default(void);
extern int  TripleCallByteCheck(void);
extern void SetJmp_Push16Call_004a1ad0(void);
extern void DualScaledLitInitJmp(void);
extern void MStackPush2ChainLLInsert(void);
extern void DispatcherComplex260_FramePauseScaledStore(void);
extern void MStackPushComplexCallPop_MStackPush2ChainPrepend_004064b0(void);
extern void StackPopDispatchTagged(void);
extern void QuadCallPhase2(unsigned int, unsigned int, unsigned int, unsigned int);
extern void PushPopScaledInit343c(void);
extern void TableLookupCall_g_eventTbl_65(void);
extern void TestZeroJmp(void);
extern int  GameStateMachine(int);
extern void SetJmp_Push16Call_004a1ac0(void);
extern void CopyGlobal(void);
extern void BootInitGuardedCallChain(void);
extern void GuardedSetupCallTailJmp(unsigned int, unsigned int);
extern void InitDispatchersJmp(void);
extern void CallSetPause(void);
extern void AudioInitSequence(void);
extern void AudioInstallSelfStatePush(void);
extern void CallZero2(void);

/* @addr 0x004a38d0 (892b) - NATIVE twin; the matching build compiles the
 * naked body below.
 *
 * The match loader, a six-state machine on the scheduled node's +0x84:
 *   0 fade counter armed (0xc0), re-arm as 1
 *   1 fade out by 0x14 per tick; at zero, geo group 8 fixups, both player
 *     records' .geo (table 0x4d52b8, packed) plus the shared 0x506c98,
 *     then the scene-group setup for the player selected by the 542054
 *     probe (template 0x508714 + record table 0x4f33b8, both through the
 *     DC260 dispatcher and the complex prepend); re-arm as 2
 *   2 fade in to 0x100; re-arm as 3
 *   3 wait: an input skip arms 4; audio-busy bits (0xc0c of 4d50b4) toggle
 *     the probe to the OTHER player and re-run the group setup
 *   4 fade out; at zero, geo group 0xb fixups, the two fixed .geo of
 *     DualScaledLitInitJmp, link both groups, re-arm as 5
 *   5+ fade in; at 0x100 the screen tag goes back to the loading screen
 *     tick (0x4a42e0) and StackPopDispatchTagged runs - the one exit that
 *     does not pause. */
void LoadGeoAssetsStateMachine(void)
{
    unsigned int st, rec, v;

    st = MK4_NODE_AT(unsigned int, g_baseSel, 0x84);
    MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 0;

#ifdef TARGET_SDL
    /* MK4_TRACE_LOAD: the loader's state histogram. It DOES complete - it
     * walks 0 -> 1 -> 2 -> 3 -> 4 -> 5 and hands the screen to the tick at
     * 0x4a42e0 - so a stalled loading screen is the TICK's gate, not this. */
    { extern void SDL_Log(const char *, ...); extern char *getenv(const char *);
      static unsigned hits[8], n;
      if (getenv("MK4_TRACE_LOAD")) {
          hits[st < 8 ? st : 7]++;
          if (++n % 60 == 0)
              SDL_Log("LOAD states 0=%u 1=%u 2=%u 3=%u 4=%u 5=%u  tickW1=%u "
                      "audio50b4=0x%x tickFlagF=%u",
                      hits[0], hits[1], hits[2], hits[3], hits[4], hits[5],
                      g_tickW1, g_audioStateDisp50b4, g_tickFlagF); } }
#endif
    if (st > 4) goto st5;
    switch (st) {
    case 0:
        g_tickW1 = 0xc0;
        goto rearm1;

    case 1:
        v = g_tickW1 - 0x14;
        g_tickW1 = v;
        if ((int)v > 0) goto rearm1;
        g_tickW1 = 0;
        TableWalkBoundedCmp(8);
        g_currentNodeIdx = *MK4_VA(unsigned int, 0x4d52b8u + g_dlNalt1 * 4u) >> 2;
        if (g_currentNodeIdx != 0) {
            LoadGeoAsset_Default();
            if (g_framePauseFlag != 0) return;
        }
        g_currentNodeIdx = *MK4_VA(unsigned int, 0x4d52b8u + g_dlNalt2 * 4u) >> 2;
        if (g_currentNodeIdx != 0) {
            LoadGeoAsset_Default();
            if (g_framePauseFlag != 0) return;
        }
        g_currentNodeIdx = 0x506c98u >> 2;
        LoadGeoAsset_Default();
        if (g_framePauseFlag != 0) return;
        g_tickFlagF = 1;
        g_tickInitFlag = 1;
        goto group;

    case 2:
        v = g_tickW1 + 0x14;
        g_tickW1 = v;
        if ((int)v < 0x100) goto rearm2;
        g_tickW1 = 0x100;
        goto arm3;

    /* UPDATE after the input fix (7a6a7a600, 2f9b60244). With the publisher
     * staging the SOURCE words the game derives its aggregates from, this
     * loader COMPLETES on a real key press: states 4 and 5 run (13 and 12
     * visits) where they had never run at all, and state 3 stops at ~250
     * instead of spinning past 2000. The note below describes the state
     * before that fix and is kept for the mechanism it records.
     *
     * The chain now stops one step later, and somewhere else. gameMode's last
     * transition is `004a38d0 -> 004a42e0` - the geo loader HANDS THE WORLD
     * BACK to the loading tick, which it never did while it was spinning - but
     * it stops there rather than returning to 0. So the match sequencer's node
     * (+0xd8 = 0x420300, work type 0x1000) is still gated out of the pump, and
     * it still cycles 0-2-3-4 without reaching state 5. Queuing further ticks
     * after the load completes does not move it.
     *
     */

    /* WHERE THE FRONT-END PATH STOPS (measured 2026-09-03). Driven from the
     * front end rather than MK4_BOOT_MATCH, this loader walks 0 once, 1 ten
     * times, 2 thirteen times, and then SPINS IN STATE 3 - 2016 visits in a
     * 4200-frame run - never reaching 4 or 5.
     *
     * State 3 has exactly two exits and neither fires. TripleCallByteCheck,
     * the press-start gate, stays 0; and g_audioStateDisp50b4 (0x4d50b4, the
     * direction word - bits 2/3 are P1 left/right, 10/11 are P2's) reads 0x0
     * at every sample, so the `(v & 0xc) || (v & 0xc00)` player-toggle path is
     * never taken either. Pressing left, right, start or Enter through
     * MK4_KEYS changes nothing.
     *
     * The press gate is worse than merely shut, it is CONTRADICTORY with what
     * got us here. Our own boot-match harness records that g_gsmActiveFlag is
     * "exactly what makes TestQueueGateState refuse the Enter key - the
     * loading screen's only working skip". But g_gsmActiveFlag is also what
     * the loading tick requires before it will re-enter Screen_Loading at all
     * (0x4a442b), which is how this loader gets installed in the first place.
     * Up for one, down for the other. Faking the same Enter the harness fakes,
     * MK4_NativeFakeKeyPress(0x0d, 2), does not move it.
     *
     * The direction word is NOT the way out, correcting that guess. Re-read
     * the state: the `(v & 0xc) || (v & 0xc00)` path toggles the probe to the
     * other player, links the finished group and ends in `goto group` - it
     * re-enters state 3. ONLY TripleCallByteCheck exits to state 4.
     *
     * That gate has three openings: TestQueueGateState (the Enter skip,
     * refused while g_gsmActiveFlag is up), InputPollFlagBits (player one's
     * pad) and InputPollFlagBitsHalf (player two's). InputPollFlagBits
     * returns 1 on `pad & 1`, and an action press DOES set that pad - with U
     * pressed at frame 2400, 0x4d50b8 reads 1 at frames 2400 AND 2401.
     *
     * And yet MK4_TRACE_GATE3 never sees a non-zero pad in 4200 frames. With
     * the frame number exported (g_mk4FrameNo, set in engine_frame.c right
     * after the input publish) the contradiction is exact rather than
     * suspected:
     *
     *   frame 2448, sampled in engine_frame.c   0x4d50b8 = 1
     *   frame 2448, read here inside MainLoopStep  0x4d50b8 = 0
     *
     * Same byte, same frame, both through MK4_VA. The loader is running
     * inside the press window - the key script fires at 2400..2458 and this
     * probe reports f=2448 - so it is not a case of missing the window.
     *
     * It is NOT split storage either. src/data.c does define
     * g_audioStateMask50b8 as a host symbol while input_poll_flag_bits.c
     * aliases it to the arena, which looks like the usual trap, but the four
     * files that use the name without aliasing are all OUTSIDE the native
     * build and split-globals-audit passes.
     *
     * Bracketed, the clear is inside GameLogicStep. MK4_TRACE_PAD reports the
     * byte still UP at MainLoopStep's entry on frames 2400-2411, and the same
     * probe in the node pump never sees it non-zero at all - so it dies
     * between those two points. BeginFrame is renderer dispatch only, and
     * Input_TickPlayers, bracketed either side, never changes it (it may not
     * even run - GameLogicStep gates it on GameStateMachine(0) returning 0).
     * That leaves GameStateMachine(0) itself, XformChainAdvance, or the two
     * audio calls.
     *
     * Worth knowing before hunting it: the ORIGINAL never writes 0x4d50b8 in
     * any direct encoding. A sweep of the image for every mov/or/and form,
     * byte and dword, finds ZERO write-form references - the game only reads
     * this aggregate, and the native publisher is its only writer. So the
     * clear is indirect: a computed address, or a block wipe covering it. */
    case 3:
#ifdef TARGET_SDL
    /* MK4_TRACE_GATE3: state 3's exit test, evaluated. The pad byte at
     * 0x4d50b8 reads 1 for two frames after an action press and
     * InputPollFlagBits returns 1 on `a & 1`, so TripleCallByteCheck should
     * open - print what it actually returns alongside the raw inputs. */
    { extern void SDL_Log(const char *, ...); extern char *getenv(const char *);
      static int tr = -1; static unsigned n;
      if (tr < 0) tr = getenv("MK4_TRACE_GATE3") != 0;
      if (tr && n < 12) { unsigned char pad = *MK4_VA(unsigned char, 0x4d50b8u);
          static unsigned visits;
          if (pad != 0 || g_audioStateDisp50b4 != 0 || ++visits % 300 == 0) { n++;
              { extern unsigned int g_mk4FrameNo;
                SDL_Log("GATE3 f=%u pad=%02x dir=%08x -> TripleCallByteCheck=%d",
                        g_mk4FrameNo, pad, g_audioStateDisp50b4,
                        TripleCallByteCheck()); } } } }
#endif
        if (TripleCallByteCheck() != 0) {
            SetJmp_Push16Call_004a1ad0();
            goto rearm4;
        }
        v = g_audioStateDisp50b4;
        if ((v & 0xcu) == 0 && (v & 0xc00u) == 0) goto arm3;
        /* toggle the probe to the other player, link the finished group,
         * and run the setup again for the new one */
        v = g_dualB_00538038;
        if (g_cj_00542054 == v) v = g_dualB_0053803c;
        g_cj_00542054 = v;
        SetJmp_Push16Call_004a1ad0();
        g_currentNodeIdx = g_cj_00542058;
        MStackPush2ChainLLInsert();
        g_currentNodeIdx = g_cj_0054205c;
        MStackPush2ChainLLInsert();
        goto group;

    default:                                    /* case 4 */
        v = g_tickW1 - 0x14;
        g_tickW1 = v;
        if ((int)v > 0) goto rearm4;
        g_tickW1 = 0;
        TableWalkBoundedCmp(0xb);
        DualScaledLitInitJmp();
        g_currentNodeIdx = g_cj_00542058;
        MStackPush2ChainLLInsert();
        g_currentNodeIdx = g_cj_0054205c;
        MStackPush2ChainLLInsert();
        g_tickFlagF = 4;
        g_tickInitFlag = 0;
        goto rearm5;
    }

group:
    if (g_cj_00542054 == g_dualB_00538038) {
        rec = g_dlNalt1;
        g_walkCallback = 0xff740000u;
    } else {
        rec = g_dlNalt2;
        g_walkCallback = 0x8c0000u;
    }
    g_eventQueueCurrent = rec;
    if (*MK4_VA(unsigned int, 0x4f33b8u + rec * 4u) != 0) {
        g_xformEntityIdx = 0x508714u >> 2;
        DispatcherComplex260_FramePauseScaledStore();
        if (g_framePauseFlag != 0) return;
        g_cj_0054205c = g_currentNodeIdx;
        if ((g_xformDirtyFlags & 4u) == 0) {
            MStackPushComplexCallPop_MStackPush2ChainPrepend_004064b0();
            if (g_framePauseFlag != 0) return;
        }
        g_xformEntityIdx =
            *MK4_VA(unsigned int, 0x4f33b8u + g_eventQueueCurrent * 4u) >> 2;
        DispatcherComplex260_FramePauseScaledStore();
        if (g_framePauseFlag != 0) return;
        g_cj_00542058 = g_currentNodeIdx;
        if ((g_xformDirtyFlags & 4u) == 0) {
            MStackPushComplexCallPop_MStackPush2ChainPrepend_004064b0();
            if (g_framePauseFlag != 0) return;
        }
    }

rearm2:
    MK4_NODE_AT(unsigned int, g_baseSel, 8) = MK4_CODE_VA(LoadGeoAssetsStateMachine);
    MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 2;
    goto pauseout;
rearm1:
    MK4_NODE_AT(unsigned int, g_baseSel, 8) = MK4_CODE_VA(LoadGeoAssetsStateMachine);
    MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 1;
    goto pauseout;
arm3:
    MK4_NODE_AT(unsigned int, g_baseSel, 8) = MK4_CODE_VA(LoadGeoAssetsStateMachine);
    MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 3;
    goto pauseout;
rearm4:
    MK4_NODE_AT(unsigned int, g_baseSel, 8) = MK4_CODE_VA(LoadGeoAssetsStateMachine);
    MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 4;
    goto pauseout;
rearm5:
    MK4_NODE_AT(unsigned int, g_baseSel, 8) = MK4_CODE_VA(LoadGeoAssetsStateMachine);
    MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 5;
    goto pauseout;

st5:
    v = g_tickW1 + 0x14;
    g_tickW1 = v;
    if ((int)v < 0x100) goto rearm5;
    g_tickW1 = 0x100;
    g_gameMode = 0x4a42e0u;      /* the loading screen tick takes over */
    StackPopDispatchTagged();
    return;

pauseout:
    g_pendingNodeType = 1;
    g_framePauseFlag = 1;
}

/* @addr 0x004a42d0 - the loading screen's install entry (canonical home
 * src/audio/pending_match_variants.c; NATIVE twin lives here beside the
 * loader it drives). Arms the 543824 byte and tail-jmps CallZero2. */
void Screen_Loading(void)
{
    *MK4_VA(unsigned int, 0x543824u) = 1;
    CallZero2();                    /* tail-jmp in the original */
}

/* @addr 0x004a42e0 - the loading screen's TICK entry, +0x10 inside the
 * Screen_Loading blob, reached only through code pointers (node +8 slot,
 * the 543800 screen tag, VA|state<<24 queue words). Registered in
 * config/codeptr_extras.yaml.
 *
 * Three bands on the node's +0x84 state:
 *   0/1 wait for the streaming counters, send FSM command 3 when they
 *       drain, then service the gsmOut flags: 543810 world re-init
 *       (static record 0x4d2250), 543814 audio re-init, 543818 hand the
 *       screen to the match loader with a state-2 resume word queued -
 *       falling through to the ready check otherwise
 *   2   ready check: the 54389c byte set means the loader finished - queue
 *       a state-3 resume word and run the audio install; clear means
 *       re-arm as 1
 *   3+  the load itself: both fighters' sound banks via QuadCallPhase2
 *       (record indices when either character id is 6), the 0x2c event,
 *       and re-arm as 1 */
void Screen_Loading_Tick_004a42e0(void)
{
    unsigned int st, v, flags, bit2, bit5, c2, c5;

    st = MK4_NODE_AT(unsigned int, g_baseSel, 0x84);
    MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 0;

#ifdef TARGET_SDL
    /* MK4_TRACE_TICK: the tick's state histogram and every gate it reads.
     * Spinning in state 1 with all of them zero is the native stall: state 2
     * is the only state that checks 0x54389c ("assets ready"), and only
     * State6Latch sets that - see the block comment at the top of this file. */
    { extern void SDL_Log(const char *, ...); extern char *getenv(const char *);
      static unsigned n, hits[8];
      if (getenv("MK4_TRACE_TICK")) {
          hits[st < 8 ? st : 7]++;
          if (++n % 120 == 0)
              SDL_Log("TICK st 0=%u 1=%u 2=%u 3+=%u | step=%u mask50c0=0x%x "
                      "a53a408=%u a537e88=%u  54380c=%u stream=%u "
                      "gsmActive=%u out1=%u out2=%u out3=%u",
                      hits[0], hits[1], hits[2], hits[3]+hits[4]+hits[5]+hits[6]+hits[7],
                      g_logicStepFlag, g_audioStateMask50c0,
                      g_active_0053a408, g_active_00537e88,
                      (unsigned)*MK4_VA(unsigned char, 0x54380cu),
                      g_audioStreamState, g_gsmActiveFlag,
                      g_gsmOut1, g_gsmOut2, g_gsmOut3); } }
#endif
    if (st == 2) goto ready_check;
    if (st >= 3) goto do_load;

    /* states 0 and 1 */
    g_gsmOut4 = 1;
    if (g_logicStepFlag != 0) goto signal;
    flags = g_audioStateMask50c0;
    bit2 = flags & 4u;
    c2 = g_active_0053a408;
    if (bit2 != 0 && c2 != 0) goto after;
    bit5 = flags & 0x20u;
    c5 = g_active_00537e88;
    if (bit5 != 0 && c5 != 0) goto after;
    if (bit2 == 0 && bit5 == 0) goto after;
    if (c2 != 0 || c5 != 0) goto after;
signal:
    v = *MK4_VA(unsigned char, 0x54380cu);
    g_logicStepFlag = 0;
    if ((unsigned char)v == 0 && g_audioStreamState == 0)
        GameStateMachine(3);
after:
    if (g_gsmActiveFlag != 0) {
        Screen_Loading();
        g_gameMode = 0x4a42e0u;
    }
    if (g_gsmOut3 != 0) {               /* world re-init */
        g_gsmOut3 = 0;
        SetJmp_Push16Call_004a1ac0();
        g_walkCallback = 0;
        CopyGlobal();
        BootInitGuardedCallChain();
        PushPopScaledInit343c();
        GuardedSetupCallTailJmp(0x4d2250u, 0x640000u);
        g_audioInitScaled = g_currentNodeIdx;
        InitDispatchersJmp();
        CallSetPause();
        return;
    }
    if (g_gsmOut2 != 0) {               /* audio re-init */
        g_gsmOut2 = 0;
        SetJmp_Push16Call_004a1ac0();
        g_walkCallback = 0;
        CopyGlobal();
        AudioInitSequence();
        CallSetPause();
        return;
    }
    if (g_gsmOut1 != 0) {               /* hand the screen to the loader */
        g_gsmOut1 = 0;
        g_gameMode = 0x4a38d0u;
        MK4_NODE_AT(unsigned int, g_baseSel, 8) = 0x4a42e0u;
        MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 2;    /* transient */
        v = MK4_NODE_AT(unsigned int, g_baseSel, 4);
        g_currentNodeIdx = v;
        *MK4_NODE(unsigned int, v) = 0x4a42e0u + 0x2000000u;
        g_currentNodeIdx = v + 1;
        MK4_NODE_AT(unsigned int, g_baseSel, 4) = v + 1;
        MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 0;
        LoadGeoAssetsStateMachine();
        g_framePauseFlag = 1;
        return;
    }

ready_check:
    if (*MK4_VA(unsigned char, 0x54389cu) == 0) goto rearm1_tail;
    MK4_NODE_AT(unsigned int, g_baseSel, 8) = 0x4a42e0u;
    MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 3;        /* transient */
    v = MK4_NODE_AT(unsigned int, g_baseSel, 4);
    g_currentNodeIdx = v;
    *MK4_NODE(unsigned int, v) = 0x4a42e0u + 0x3000000u;
    g_currentNodeIdx = v + 1;
    MK4_NODE_AT(unsigned int, g_baseSel, 4) = v + 1;
    MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 0;
    AudioInstallSelfStatePush();
    g_framePauseFlag = 1;
    return;

do_load:
    {
        unsigned int p1c = MK4_NODE_AT(unsigned int, g_dualB_00538038, 0x34);
        unsigned int p2c = MK4_NODE_AT(unsigned int, g_dualB_0053803c, 0x34);
        if (p1c == 6 || p2c == 6)
            QuadCallPhase2(g_dlNalt1, g_dlNalt2,
                           g_counter_0053a51c + 0x12, 0x1d);
        else
            QuadCallPhase2(p1c, p2c, g_counter_0053a51c + 0x12, 0x1d);
    }
    PushPopScaledInit343c();
    PushPopScaledInit343c();
    g_walkCallback = 0x2c;
    TableLookupCall_g_eventTbl_65();
    if (g_framePauseFlag != 0) return;
    *MK4_VA(unsigned char, 0x54389cu) = 0;

rearm1_tail:
    if (g_gsmActiveFlag == 0) {
        TestZeroJmp();
        g_gameMode = 0;
    }
    MK4_NODE_AT(unsigned int, g_baseSel, 8) = 0x4a42e0u;
    MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 1;
    g_pendingNodeType = 1;
    g_framePauseFlag = 1;
}
#else
__declspec(naked) void LoadGeoAssetsStateMachine(void)
{
    __asm {
        _emit    0xa1
        _emit    0x60
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x53
        _emit    0x55
        _emit    0x56
        _emit    0x8d
        _emit    0x34
        _emit    0x85
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0xbb
        _emit    0x04
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x33
        _emit    0xed
        _emit    0x57
        _emit    0x8b
        _emit    0x86
        _emit    0x84
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x89
        _emit    0xae
        _emit    0x84
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x3b
        _emit    0xc3
        _emit    0x0f
        _emit    0x87
        _emit    0xe3
        _emit    0x02
        _emit    0x00
        _emit    0x00
        _emit    0xbf
        _emit    0x01
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0xff
        _emit    0x24
        _emit    0x85
        _emit    0x38
        _emit    0x3c
        _emit    0x4a
        _emit    0x00
        _emit    0xa1
        _emit    0x50
        _emit    0x35
        _emit    0x54
        _emit    0x00
        _emit    0x83
        _emit    0xe8
        _emit    0x14
        _emit    0x3b
        _emit    0xc5
        _emit    0xa3
        _emit    0x50
        _emit    0x35
        _emit    0x54
        _emit    0x00
        _emit    0x0f
        _emit    0x8f
        _emit    0x9f
        _emit    0x02
        _emit    0x00
        _emit    0x00
        _emit    0x6a
        _emit    0x08
        _emit    0x89
        _emit    0x2d
        _emit    0x50
        _emit    0x35
        _emit    0x54
        _emit    0x00
        _emit    0xe8
        _emit    0x67
        _emit    0x9f
        _emit    0x01
        _emit    0x00
        _emit    0x8b
        _emit    0x0d
        _emit    0x48
        _emit    0x7f
        _emit    0x53
        _emit    0x00
        _emit    0x83
        _emit    0xc4
        _emit    0x04
        _emit    0x8b
        _emit    0x14
        _emit    0x8d
        _emit    0xb8
        _emit    0x52
        _emit    0x4d
        _emit    0x00
        _emit    0xc1
        _emit    0xea
        _emit    0x02
        _emit    0x89
        _emit    0x15
        _emit    0x44
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x74
        _emit    0x11
        _emit    0xe8
        _emit    0x67
        _emit    0x9c
        _emit    0x01
        _emit    0x00
        _emit    0x39
        _emit    0x2d
        _emit    0x6c
        _emit    0x1e
        _emit    0x54
        _emit    0x00
        _emit    0x0f
        _emit    0x85
        _emit    0xdd
        _emit    0x02
        _emit    0x00
        _emit    0x00
        _emit    0xa1
        _emit    0xe0
        _emit    0x80
        _emit    0x53
        _emit    0x00
        _emit    0x8b
        _emit    0x0c
        _emit    0x85
        _emit    0xb8
        _emit    0x52
        _emit    0x4d
        _emit    0x00
        _emit    0xc1
        _emit    0xe9
        _emit    0x02
        _emit    0x89
        _emit    0x0d
        _emit    0x44
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x74
        _emit    0x11
        _emit    0xe8
        _emit    0x3f
        _emit    0x9c
        _emit    0x01
        _emit    0x00
        _emit    0x39
        _emit    0x2d
        _emit    0x6c
        _emit    0x1e
        _emit    0x54
        _emit    0x00
        _emit    0x0f
        _emit    0x85
        _emit    0xb5
        _emit    0x02
        _emit    0x00
        _emit    0x00
        _emit    0xba
        _emit    0x98
        _emit    0x6c
        _emit    0x50
        _emit    0x00
        _emit    0xc1
        _emit    0xea
        _emit    0x02
        _emit    0x89
        _emit    0x15
        _emit    0x44
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0xe8
        _emit    0x20
        _emit    0x9c
        _emit    0x01
        _emit    0x00
        _emit    0x39
        _emit    0x2d
        _emit    0x6c
        _emit    0x1e
        _emit    0x54
        _emit    0x00
        _emit    0x0f
        _emit    0x85
        _emit    0x96
        _emit    0x02
        _emit    0x00
        _emit    0x00
        _emit    0x89
        _emit    0x3d
        _emit    0xc4
        _emit    0xaa
        _emit    0x52
        _emit    0x00
        _emit    0x89
        _emit    0x3d
        _emit    0x70
        _emit    0x4e
        _emit    0xab
        _emit    0x00
        _emit    0xe9
        _emit    0xa8
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0xa1
        _emit    0x50
        _emit    0x35
        _emit    0x54
        _emit    0x00
        _emit    0x83
        _emit    0xc0
        _emit    0x14
        _emit    0x3d
        _emit    0x00
        _emit    0x01
        _emit    0x00
        _emit    0x00
        _emit    0xa3
        _emit    0x50
        _emit    0x35
        _emit    0x54
        _emit    0x00
        _emit    0x0f
        _emit    0x8c
        _emit    0x64
        _emit    0x01
        _emit    0x00
        _emit    0x00
        _emit    0xc7
        _emit    0x05
        _emit    0x50
        _emit    0x35
        _emit    0x54
        _emit    0x00
        _emit    0x00
        _emit    0x01
        _emit    0x00
        _emit    0x00
        _emit    0xeb
        _emit    0x2e
        _emit    0xe8
        _emit    0x1a
        _emit    0xe2
        _emit    0xff
        _emit    0xff
        _emit    0x85
        _emit    0xc0
        _emit    0x74
        _emit    0x17
        _emit    0xe8
        _emit    0xf1
        _emit    0xe0
        _emit    0xff
        _emit    0xff
        _emit    0xc7
        _emit    0x46
        _emit    0x08
        _emit    0xd0
        _emit    0x38
        _emit    0x4a
        _emit    0x00
        _emit    0x89
        _emit    0x9e
        _emit    0x84
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0xe9
        _emit    0x12
        _emit    0x02
        _emit    0x00
        _emit    0x00
        _emit    0xa1
        _emit    0xb4
        _emit    0x50
        _emit    0x4d
        _emit    0x00
        _emit    0xa8
        _emit    0x0c
        _emit    0x75
        _emit    0x1b
        _emit    0xf6
        _emit    0xc4
        _emit    0x0c
        _emit    0x75
        _emit    0x16
        _emit    0xc7
        _emit    0x46
        _emit    0x08
        _emit    0xd0
        _emit    0x38
        _emit    0x4a
        _emit    0x00
        _emit    0xc7
        _emit    0x86
        _emit    0x84
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x03
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0xe9
        _emit    0xee
        _emit    0x01
        _emit    0x00
        _emit    0x00
        _emit    0xa1
        _emit    0x38
        _emit    0x80
        _emit    0x53
        _emit    0x00
        _emit    0x8b
        _emit    0x0d
        _emit    0x54
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x3b
        _emit    0xc8
        _emit    0x75
        _emit    0x05
        _emit    0xa1
        _emit    0x3c
        _emit    0x80
        _emit    0x53
        _emit    0x00
        _emit    0xa3
        _emit    0x54
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0xe8
        _emit    0x9d
        _emit    0xe0
        _emit    0xff
        _emit    0xff
        _emit    0x8b
        _emit    0x0d
        _emit    0x58
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x89
        _emit    0x0d
        _emit    0x44
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0xe8
        _emit    0x4c
        _emit    0x2d
        _emit    0xf6
        _emit    0xff
        _emit    0x8b
        _emit    0x15
        _emit    0x5c
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x89
        _emit    0x15
        _emit    0x44
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0xe8
        _emit    0x3b
        _emit    0x2d
        _emit    0xf6
        _emit    0xff
        _emit    0xa1
        _emit    0x54
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x8b
        _emit    0x0d
        _emit    0x38
        _emit    0x80
        _emit    0x53
        _emit    0x00
        _emit    0x3b
        _emit    0xc1
        _emit    0x75
        _emit    0x11
        _emit    0xa1
        _emit    0x48
        _emit    0x7f
        _emit    0x53
        _emit    0x00
        _emit    0xc7
        _emit    0x05
        _emit    0x6c
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x74
        _emit    0xff
        _emit    0xeb
        _emit    0x0f
        _emit    0xa1
        _emit    0xe0
        _emit    0x80
        _emit    0x53
        _emit    0x00
        _emit    0xc7
        _emit    0x05
        _emit    0x6c
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x8c
        _emit    0x00
        _emit    0x8b
        _emit    0x0c
        _emit    0x85
        _emit    0xb8
        _emit    0x33
        _emit    0x4f
        _emit    0x00
        _emit    0xa3
        _emit    0x70
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x3b
        _emit    0xcd
        _emit    0x0f
        _emit    0x84
        _emit    0x91
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0xb9
        _emit    0x14
        _emit    0x87
        _emit    0x50
        _emit    0x00
        _emit    0xc1
        _emit    0xe9
        _emit    0x02
        _emit    0x89
        _emit    0x0d
        _emit    0x48
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0xe8
        _emit    0x55
        _emit    0x39
        _emit    0xf6
        _emit    0xff
        _emit    0x39
        _emit    0x2d
        _emit    0x6c
        _emit    0x1e
        _emit    0x54
        _emit    0x00
        _emit    0x0f
        _emit    0x85
        _emit    0x7b
        _emit    0x01
        _emit    0x00
        _emit    0x00
        _emit    0xa0
        _emit    0x8c
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x8b
        _emit    0x15
        _emit    0x44
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x84
        _emit    0xc3
        _emit    0x89
        _emit    0x15
        _emit    0x5c
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x75
        _emit    0x11
        _emit    0xe8
        _emit    0xdf
        _emit    0x29
        _emit    0xf6
        _emit    0xff
        _emit    0x39
        _emit    0x2d
        _emit    0x6c
        _emit    0x1e
        _emit    0x54
        _emit    0x00
        _emit    0x0f
        _emit    0x85
        _emit    0x55
        _emit    0x01
        _emit    0x00
        _emit    0x00
        _emit    0xa1
        _emit    0x70
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x8b
        _emit    0x0c
        _emit    0x85
        _emit    0xb8
        _emit    0x33
        _emit    0x4f
        _emit    0x00
        _emit    0xc1
        _emit    0xe9
        _emit    0x02
        _emit    0x89
        _emit    0x0d
        _emit    0x48
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0xe8
        _emit    0x09
        _emit    0x39
        _emit    0xf6
        _emit    0xff
        _emit    0x39
        _emit    0x2d
        _emit    0x6c
        _emit    0x1e
        _emit    0x54
        _emit    0x00
        _emit    0x0f
        _emit    0x85
        _emit    0x2f
        _emit    0x01
        _emit    0x00
        _emit    0x00
        _emit    0xa0
        _emit    0x8c
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x8b
        _emit    0x15
        _emit    0x44
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x84
        _emit    0xc3
        _emit    0x89
        _emit    0x15
        _emit    0x58
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x75
        _emit    0x11
        _emit    0xe8
        _emit    0x93
        _emit    0x29
        _emit    0xf6
        _emit    0xff
        _emit    0x39
        _emit    0x2d
        _emit    0x6c
        _emit    0x1e
        _emit    0x54
        _emit    0x00
        _emit    0x0f
        _emit    0x85
        _emit    0x09
        _emit    0x01
        _emit    0x00
        _emit    0x00
        _emit    0xc7
        _emit    0x46
        _emit    0x08
        _emit    0xd0
        _emit    0x38
        _emit    0x4a
        _emit    0x00
        _emit    0xc7
        _emit    0x86
        _emit    0x84
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x02
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x89
        _emit    0x3d
        _emit    0x4c
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x89
        _emit    0x3d
        _emit    0x6c
        _emit    0x1e
        _emit    0x54
        _emit    0x00
        _emit    0x5f
        _emit    0x5e
        _emit    0x5d
        _emit    0x5b
        _emit    0xc3
        _emit    0xa1
        _emit    0x50
        _emit    0x35
        _emit    0x54
        _emit    0x00
        _emit    0x83
        _emit    0xe8
        _emit    0x14
        _emit    0x3b
        _emit    0xc5
        _emit    0xa3
        _emit    0x50
        _emit    0x35
        _emit    0x54
        _emit    0x00
        _emit    0x7e
        _emit    0x12
        _emit    0xc7
        _emit    0x46
        _emit    0x08
        _emit    0xd0
        _emit    0x38
        _emit    0x4a
        _emit    0x00
        _emit    0x89
        _emit    0x9e
        _emit    0x84
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0xe9
        _emit    0x95
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x6a
        _emit    0x0b
        _emit    0x89
        _emit    0x2d
        _emit    0x50
        _emit    0x35
        _emit    0x54
        _emit    0x00
        _emit    0xe8
        _emit    0x15
        _emit    0x9d
        _emit    0x01
        _emit    0x00
        _emit    0x83
        _emit    0xc4
        _emit    0x04
        _emit    0xe8
        _emit    0x7d
        _emit    0x0c
        _emit    0xfc
        _emit    0xff
        _emit    0xa1
        _emit    0x58
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0xa3
        _emit    0x44
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0xe8
        _emit    0xfe
        _emit    0x2b
        _emit    0xf6
        _emit    0xff
        _emit    0x8b
        _emit    0x0d
        _emit    0x5c
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x89
        _emit    0x0d
        _emit    0x44
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0xe8
        _emit    0xed
        _emit    0x2b
        _emit    0xf6
        _emit    0xff
        _emit    0x89
        _emit    0x1d
        _emit    0xc4
        _emit    0xaa
        _emit    0x52
        _emit    0x00
        _emit    0x89
        _emit    0x2d
        _emit    0x70
        _emit    0x4e
        _emit    0xab
        _emit    0x00
        _emit    0xeb
        _emit    0x41
        _emit    0xc7
        _emit    0x05
        _emit    0x50
        _emit    0x35
        _emit    0x54
        _emit    0x00
        _emit    0xc0
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0xbf
        _emit    0x01
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0xc7
        _emit    0x46
        _emit    0x08
        _emit    0xd0
        _emit    0x38
        _emit    0x4a
        _emit    0x00
        _emit    0x89
        _emit    0xbe
        _emit    0x84
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x89
        _emit    0x3d
        _emit    0x4c
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x89
        _emit    0x3d
        _emit    0x6c
        _emit    0x1e
        _emit    0x54
        _emit    0x00
        _emit    0x5f
        _emit    0x5e
        _emit    0x5d
        _emit    0x5b
        _emit    0xc3
        _emit    0xa1
        _emit    0x50
        _emit    0x35
        _emit    0x54
        _emit    0x00
        _emit    0x83
        _emit    0xc0
        _emit    0x14
        _emit    0x3d
        _emit    0x00
        _emit    0x01
        _emit    0x00
        _emit    0x00
        _emit    0xa3
        _emit    0x50
        _emit    0x35
        _emit    0x54
        _emit    0x00
        _emit    0x7d
        _emit    0x27
        _emit    0xc7
        _emit    0x46
        _emit    0x08
        _emit    0xd0
        _emit    0x38
        _emit    0x4a
        _emit    0x00
        _emit    0xc7
        _emit    0x86
        _emit    0x84
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x05
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0xbf
        _emit    0x01
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x89
        _emit    0x3d
        _emit    0x4c
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x89
        _emit    0x3d
        _emit    0x6c
        _emit    0x1e
        _emit    0x54
        _emit    0x00
        _emit    0x5f
        _emit    0x5e
        _emit    0x5d
        _emit    0x5b
        _emit    0xc3
        _emit    0xc7
        _emit    0x05
        _emit    0x50
        _emit    0x35
        _emit    0x54
        _emit    0x00
        _emit    0x00
        _emit    0x01
        _emit    0x00
        _emit    0x00
        _emit    0xc7
        _emit    0x05
        _emit    0x00
        _emit    0x38
        _emit    0x54
        _emit    0x00
        _emit    0xe0
        _emit    0x42
        _emit    0x4a
        _emit    0x00
        _emit    0xe8
        _emit    0x4e
        _emit    0xbb
        _emit    0xf7
        _emit    0xff
        _emit    0x5f
        _emit    0x5e
        _emit    0x5d
        _emit    0x5b
        _emit    0xc3
        _emit    0x90
        _emit    0xb1
        _emit    0x3b
        _emit    0x4a
        _emit    0x00
        _emit    0x07
        _emit    0x39
        _emit    0x4a
        _emit    0x00
        _emit    0xad
        _emit    0x39
        _emit    0x4a
        _emit    0x00
        _emit    0xd1
        _emit    0x39
        _emit    0x4a
        _emit    0x00
        _emit    0x4b
        _emit    0x3b
        _emit    0x4a
        _emit    0x00
    }
}
#endif
