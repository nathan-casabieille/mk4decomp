/* Hand-written weak stub frontier, COMPLEMENTING the generated
 * engine_autostubs.c (grow_native.py). New conversions reference callees the
 * generated frontier does not know yet; each gets the same shape of weak
 * no-op here - counted by MK4_StubHit, so MK4_TRACE_STUBS keeps reporting
 * the live work-list - until it is converted, whose strong definition then
 * wins the link. Duplicates with the generated file are harmless: both are
 * weak.
 *
 * Current crop: the callees of Screen_ArcadeEnding, the match sequencer
 * (src/game/screen_arcade_ending.c). */

#ifdef MK4_NATIVE_FULL

extern void MK4_StubHit(const char *);

#define FRONTIER_STUB(name) \
    __attribute__((weak)) void name(void) { MK4_StubHit(#name); }
#define FRONTIER_STUB0(name) \
    __attribute__((weak)) int name(void) { MK4_StubHit(#name); return 0; }
#define FRONTIER_STUB1(name) \
    __attribute__((weak)) void name(int a) { (void)a; MK4_StubHit(#name); }

FRONTIER_STUB(TableWalkPause)
FRONTIER_STUB0(CmpDualStateMatch)
FRONTIER_STUB(GuardedScaledLookupCallJmp)
FRONTIER_STUB(DirtyKeyedStateCopy)
FRONTIER_STUB(TriDispatchSetupChain)
FRONTIER_STUB(Init28fDecLoad)
FRONTIER_STUB(Install3WayCountdownGame)
FRONTIER_STUB(MkIntroFsm)
FRONTIER_STUB(CallPauseEvtPushJmp)
FRONTIER_STUB(AiWalkCounterDualCluster)
FRONTIER_STUB(DualTestDirtyToggle_004282c0)
FRONTIER_STUB(MStackPushSearchLoop)
FRONTIER_STUB(GuardedChainDispatch)
FRONTIER_STUB(DualCounterPhaseGateInstall)
FRONTIER_STUB(Phase3InstallSelfChain)
FRONTIER_STUB(BootMultiAssetLoadStateInit)
FRONTIER_STUB(Push70CallScaleArith)
FRONTIER_STUB(StateCmpAndStoreByte)
FRONTIER_STUB(InstallSelfPackedF80)
FRONTIER_STUB1(MarkSlot)
FRONTIER_STUB(Install3StateAudioChain)
FRONTIER_STUB(SetTagsCallCmpToggleDirty)
FRONTIER_STUB(RoundEndHandlerCluster)
FRONTIER_STUB(ContinueScreenFsm)
FRONTIER_STUB(ChainInit3CallTailJmp)
FRONTIER_STUB(EnduranceFsmCluster)

/* the phase-3 band's two big deferred callees (939a2edcb ff.) */
FRONTIER_STUB(RoundEndFsm)
FRONTIER_STUB(PendingMatch_0042d240)

/* the main-menu screen's still-hollow leaves */
FRONTIER_STUB(Config_RestoreGlobals)
FRONTIER_STUB(GameMode_EnterScene)
FRONTIER_STUB(InstallSelfStateMachine6)
FRONTIER_STUB(FiveTableWalkInit)


#endif /* MK4_NATIVE_FULL */
