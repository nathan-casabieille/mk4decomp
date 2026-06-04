/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
#include "portable/ghidra_types.h"
#include "game/tick.h"

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
extern unsigned int g_cj_00542058;
extern unsigned int g_rangeSqLimit;
extern unsigned int g_armedReloadA;
extern unsigned int g_armedReloadB;
extern unsigned int g_dualBitGate;
extern unsigned int g_eventArmReload;
extern unsigned int g_rangeBase;

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

extern void PendingMatch_MStackBracket3_ChainSwapAdvance(void);

/*
 * @addr 0x004818e0 (104b game) - cj snapshot + dispatch + commit:
 *   stash cj into _58, call ScaledZeroFour; gate pause; call
 *   PendingMatch_MStackBracket3_ChainSwapAdvance; gate again. Compute walk index either 0x538158>>2
 *   or 0x53815c>>2 depending on whether _58 still matches [0x538158];
 *   store [cj*4 + reloc] = walk.
 */
extern unsigned int g_bootGatedByte360c;
extern unsigned int g_tickFlagF;
extern unsigned int g_particleEmitterNode;
extern s32 g_dlNalt1;
extern s32 g_dlNalt2;
extern unsigned int g_pendingMatchAcc;
extern unsigned int g_phaseIdx;
extern unsigned int g_zerotriple_00541de8;
extern unsigned int g_zerotriple_00541dec;
extern unsigned int g_titleDemoState;
extern unsigned int g_titleDemoState2;
extern unsigned int g_dispatchSave6;
extern unsigned int g_mul10TransformVar;
extern unsigned int g_iat_timeGetTime;
extern unsigned int g_iat_mciSendCommandA;
extern unsigned int g_phaseChainTbl;
extern unsigned int g_bootInitSaveSlot;
extern u32 g_audioPreState;
extern void AudioVolumeRescale(void);
extern void BootChainBidirRecurseWalk(void);
extern void BootInitTripleAddChain(void);
extern void BootInitVec3PhaseInstall(void);
extern void BootInstallerPair(void);
extern void BootMStackBracketedScaledStores(void);
extern void BootMultiAssetLoadStateInit(void);
extern void BootOneShotMStackPush3(void);
extern void BootPhaseGateBracketedInit(void);
extern void BootStateInitWithRecurseInstall(void);
extern void BootStateMachine4Way(void);
extern void BootStateTriple(void);
extern void CjInstallSelfRouter(void);
extern void ClampMulShiftStore(void);
extern void CmpDivJmp(void);
extern void CmpP1ScaledInitB(void);
extern void CopyByteUntilNull(void);
extern void DirtyDoubleDeref(void);
extern void DispatchSetDirtyToggle(void);
extern void DispatcherComplex181_Push70CallScaleArith2(void);
extern void DualBlockChainCallInstall(void);
extern void DualCallPauseDirtyJmp_00490c30(void);
extern void FramePauseScaledStore(void);
extern void GateDispatch6c(void);
extern void Helper_AuxAudio_PostInit(void);
extern void InstallSelfCounter(void);
extern void InstallSelfSearchAccum(void);
extern void LoopUnrolledTripleMul10(void);
extern void MStackBracket1_TreeWalkRecursive2(void);
extern void MStackBracket2_TreeWalkRecursive(void);
extern void MStackCall_MStackPush2ChainInsert_00406250(void);
extern void MStackCall_MStackPush2ChainInsert_004062a0(void);
extern void MStackCall_MStackPush2ChainPrepend_00406600(void);
extern void MStackInitCallToggle(void);
extern void MStackPush2ChainLLInsert(void);
extern void MStackPush2DualModMul10Pop2(void);
extern void MStackPush2TripleCallChain(void);
extern void MStackPush3InitCallChain(void);
extern void MStackPushComplexCallPop_MStackPush2ChainPrepend_00406430(void);
extern void MStackPushNegMul10(void);
extern void MStackPushPairTriCall(void);
extern void MStackPushZeroCallPop(void);
extern void MStackScopedSlotSetupPair(void);
extern void Mul10HeavyTransform(void);
extern void NegateThree(void);
extern void NestedLoopDispatch(void);
extern void PendingMatch_004a2a80(void);
extern void Phase1InitModelAdjustChain(void);
extern void Phase1SlotLinkAndInit(void);
extern void PhaseInstallSelf3Step(void);
extern void QuadCallPhase2(void);
extern void QuadInterpolator(void);
extern void RegistryPushBindPop(void);
extern void SaveCallRestore(void);
extern void ScaledAndAlf7(void);
extern void ScaledChainCallPauseSetJmp(void);
extern void ScaledIndexConditionalAdd(void);
extern void ScaledLitLoadCall_ScaledChainCallPauseSetJmp_then_Wrapper_IterLoad_0048fd30_00480fe0(void);
extern void ScaledMaskByte(void);
extern void ScaledOrAh8CallPauseJmp(void);
extern void ScaledStoreIdx24(void);
extern void ScaledTestPauseStore(void);
extern void ScaledThreeChanPack(void);
extern void ScaledTripleCopy10(void);
extern void ScaledTripleCopy4(void);
extern void SceneFrameStepWithInputs(void);
extern void SetJmp_BootStateTriple(void);
extern void ThreeMul10Stores(void);
extern void Thunk_MStackPush2ChainPrepend(void);
extern void Triple3VecMul10Tail(void);
extern void TripleChainTailJmp(void);
extern void TripleMul10TailIndexed(void);
extern void TripleSubVec3(void);

extern unsigned int g_dispatchSave1130;
extern unsigned int g_pendingMatchVar2;
extern unsigned int g_pendingMatchVar;
extern unsigned int g_dispatchSave564;
extern unsigned int g_dispatchSave563;
extern unsigned int g_dispatchSave896;
extern unsigned int g_dispatchSave619;
extern unsigned int g_dispatchSave522;
extern unsigned int g_phaseChainArr2;
extern unsigned int g_dispatchSave918;
extern unsigned int g_dispatchSave919;
extern unsigned int g_dispatchSave606;
extern unsigned int g_dispatchSave505;
extern unsigned int g_dispatchSave788;
extern unsigned int g_dispatchSave789;
extern unsigned int g_dispatchSave510;
extern unsigned int g_crtHeapMaxPtr;
extern unsigned int g_dispatchSave12;
extern unsigned int g_dispatchSave19;
extern unsigned int g_dispatchSave54;
extern unsigned int g_dispatchSave11;
extern unsigned int g_dispatchSave5;
extern unsigned int g_phaseThunkSave;
extern unsigned int g_eventQueueSeed;
extern unsigned int g_or;
extern unsigned int g_bootInitState;
extern unsigned int g_dispatchSave100;
extern unsigned int g_alarmTriState;
extern unsigned int g_pendingMatchSlot;
extern unsigned int g_pendingMatchSlot2;
extern unsigned int g_savedNode;
extern unsigned int g_phaseCounter;
extern unsigned int g_dispatchTableArr2;
extern unsigned int g_walkTreeArrBase;
extern unsigned int g_audioBankPick;
extern unsigned int g_counter_005433c8;
extern unsigned int g_counter_0054359c;
extern unsigned int g_audioBank2Base;
extern unsigned int g_dispatchTab62;
extern unsigned int g_voicePoolTickFlag_005437f4;
extern unsigned int g_audioStateByte834;
extern unsigned int g_pendingMatchCmp;
extern u32 g_timerActive;
extern u32 g_timerStartSec;
extern u32 g_timerEndSec;
extern u32 g_timerHandle;
extern u32 g_timerLastNow;
extern u32 g_timerFlag;
extern u32 g_audioState0C;
extern unsigned int g_joySelP0;
extern unsigned int g_joySelP1;
extern unsigned int g_dispatchSave1704;
extern unsigned int g_dispatchSave1491;
extern unsigned int g_dispatchSave1423;
extern unsigned int g_dispatchSave1430;
extern unsigned int g_dispatchSave1460;
extern unsigned int g_dispatchSave1470;
extern void Alarm5EntryScopedChain(void);
extern void ArgSarStoreJmp(void);
extern void ArgSar_Set0_Jmp(void);
extern void Atan2QuadrantLookup(void);
extern void AudioInitArgs3(void);
extern void AudioInstallSelfStatePush(void);
extern void AudioMixerStep(void);
extern void AudioMode2BankSetup(void);
extern void Audio_TimerTeardown(void);
extern void BootInitGuardedCallChain(void);
extern void BootMod6487eClampAndChainMul10(void);
extern void BootOneShotSetup(void);
extern void ByteWordTableTaggedDispatch(void);
extern void CallPauseConstStoreJmp_BootChainMaskAndDispatch_then_MStackBitLoopTripleCall(void);
extern void CallSetPause(void);
extern void ChainListVecAdd(void);
extern void ChainNodeAdvanceCallback(void);
extern void ChainWalkPushPop(void);
extern void CjTableThresholdDispatch(void);
extern void ClearBit2x34(void);
extern void CondPickDualStore(void);
extern void CopyGlobal(void);
extern void CopyThreeFields(void);
extern void CrtGetLocaleInfo(void);
extern void DispatcherComplex260_FramePauseScaledStore(void);
extern void DosMapErr(void);
extern void DualAddSar(void);
extern void DualCallPauseAddrSetRecurse_func_004196c0_jj(void);
extern void DualCallPauseAddrSetRecurse_func_00419780_jj(void);
extern void DualCallPauseAddrSetRecurse_func_00419840_jj(void);
extern void DualCallPauseAddrSetRecurse_func_00419980_jj(void);
extern void DualCallPauseAddrSetRecurse_func_00419a40_jj(void);
extern void DualCallPauseAddrSetRecurse_func_00419b00_jj(void);
extern void DualCmpSwapStore(void);
extern void DualConstMaskFlagToggle4(void);
extern void DualConstMaskFlagToggle8(void);
extern void DualListInit(void);
extern void Filbuf(void);
extern void FiveTableWalkInit(void);
extern void FlagThunk4EntryDispatcher(void);
extern void FmodHelper_004ccb7d(void);
extern void GameModeAdvanceCluster(void);
extern void GuardedSeq_MStackCall_then_CallSetPause_00471670(void);
extern void GuardedSeq_MStackCall_then_CallSetPause_0049c340(void);
extern void GuardedSetupCallTailJmp(void);
extern void Audio_PlaySoundId(void);
extern void Helper_MemMalloc_Post(void);
extern void HitReactionDispatcher(void);
extern void IndirectCall(void);
extern void InstallSelf3WayState(void);
extern void InstallSelfChainExtendCall_GameModeAdvanceCluster(void);
extern void InstallSelfPackedF80(void);
extern void IterLoad_g_scaledInit_00542044_then_MStackPush4IndirectCall(void);
extern void MStackBracket3_ChainSwapAdvance(void);
extern void MStackCall_MStackPush2ChainPrepend_004062f0(void);
extern void MStackCall_MStackPush2ChainPrepend_00406340(void);
extern void MStackCall_MStackPush2ChainLLInsert(void);
extern void MStackInstallBodyEqCheck(void);
extern void MStackNegAwareMul10Pair(void);
extern void MStackPop7(void);
extern void MStackPop8(void);
extern void MStackPush7(void);
extern void MStackPush8(void);
extern void MStackPushSet0001(void);
extern void MStackPushSet0004(void);
extern void MainTickChain(void);
extern void Mul10Tail(void);
extern void MultiThunkDispatcher_MStackCall(void);
extern void PendingMatch_004013a0(void);
extern void PendingMatch_LeaPlus22StoreSelf(void);
extern void Screen_GreatestWarrior(void);
extern void PendingMatch_StoreTailJmpSigned(void);
extern void PendingMatch_MStackPush8_0040a8d0(void);
extern void PendingMatch_AudioMixerStep_0040b020(void);
extern void PendingMatch_ZeroAndDirty4_0040d1d0(void);
extern void PendingMatch_ChainWalkPushPop_0040dbb0(void);
extern void PendingMatch_StoreDoubleNegPauseSubStore(void);
extern void PendingMatch_PushSarCallBitToggle(void);
extern void PendingMatch_ChainWalkPushPop_00411890(void);
extern void PendingMatch_PushSetXfmMaskCallPop_00413f40(void);
extern void PendingMatch_StoreTwoCall_004155c0(void);
extern void PendingMatch_00416e20(void);
extern void PendingMatch_TripleSubVec3(void);
extern void PendingMatch_MStackPush2ChainLLInsert_00418170(void);
extern void PendingMatch_Mul10Tail_00419c90(void);
extern void PendingMatch_DirtyDoubleDeref_0041afd0(void);
extern void PendingMatch_MStackPush8_0041bca0(void);
extern void PendingMatch_0041dc00(void);
extern void Phase1ChainExtendedInitLoop(void);
extern void PoseChainInstallCluster(void);
extern void Push16Call(void);
extern void PushCallPauseScaledJmpInd(void);
extern void PushPopScaled14(void);
extern void PushSetXfmMaskCallPop(void);
extern void QuadMul10TailFpuChain(void);
extern void ScaledAndAl7f(void);
extern void ScaledAndAlbf(void);
extern void ScaledAndAldf(void);
extern void ScaledAndAlfe(void);
extern void ScaledChainNegStore(void);
extern void ScaledChainOr8(void);
extern void ScaledIndirectJmp_0049c850(void);
extern void ScaledInitWithCounterAndType_004314f0(void);
extern void ScaledInit_Phase4SevenPackedDispatch_g_eventQueueTotal(void);
extern void ScaledInit_GuardedDirtyXformFromTable_g_scaledInit(void);
extern void ScaledLoadCmp1003JmpDispatch(void);
extern void ScaledStackCallPause(void);
extern void ScaledStoreThree_00409260(void);
extern void ScaledTripleCopy54(void);
extern void ScaledZero44(void);
extern void ScaledZeroIfNonzero(void);
extern void ScenegraphWalk(void);
extern void SetJmp_ZeroAndDirty4(void);
extern void SpawnLeftRightAudioCrew(void);
extern void StackPushAdd15CallPop(void);
extern void StoreCallPauseCallPauseJmp(void);
extern void StoreDoubleNegPauseSubStore(void);
extern void StoreTwoCall(void);
extern void StringDigitConvert(void);
extern void TableLookupCall_g_eventTbl_112(void);
extern void TableWalkBoundedCmp(void);
extern void Test4StatesAny(void);
extern void TestByteSelectInit(void);
extern void ThreeChanPackClamp(void);
extern void Thunk_NodeChainMaskMatch(void);
extern void Thunk_LoadShlDerefCallSkip(void);
extern void Thunk_ChainNodeInit(void);
extern void Thunk_StructArrayWalkCondCall(void);
extern void Thunk_004ca701_helper(void);
extern void Thunk_004ca77b_helper(void);
extern void TitleDemoStateMachine(void);
extern void Transform9Words(void);
extern void TripleCallByteCheck(void);
extern void TripleCallSetCopy(void);
extern void TwoStageAudioInit(void);
extern void Vec2SumMul10ChainCompute(void);
extern void VoicePicker(void);
extern void ZeroAndDirty4(void);
extern void ZeroMultiGlobalsCmp(void);
extern void ZeroThreeFields6c(void);
extern void ZeroThreeFields_0040a8b0(void);

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void CjDispatchCommit(void)

{
  int iVar1;
  
  g_cj_00542058 = g_cj_0054205c;
  ScaledZeroFour();
  if (g_framePauseFlag == 0) {
    func_0x0041d770();
    if (g_framePauseFlag == 0) {
      g_currentNodeIdx = 0x14e056;
      g_eventQueuePending = 0x14e057;
      iVar1 = 0x14e056;
      if (g_cj_00542058 != g_player1NodeIdx) {
        g_currentNodeIdx = 0x14e057;
        iVar1 = 0x14e057;
      }
      MK4_NODE_AT(int, iVar1, 0) = g_cj_0054205c;
    }
  }
  return;
}
#else
__declspec(naked) void CjDispatchCommit(void) {
    __asm {
        mov     eax, dword ptr [g_cj_0054205c]
        mov     dword ptr [g_cj_00542058], eax
        call    ScaledZeroFour
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     done
        call    PendingMatch_MStackBracket3_ChainSwapAdvance
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     done
        mov     edx, dword ptr [g_cj_00542058]
        push    esi
        mov     esi, dword ptr [g_player1NodeIdx]
        mov     eax, 0x00538158
        mov     ecx, 0x0053815c
        shr     eax, 2
        shr     ecx, 2
        cmp     edx, esi
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [g_xformEntityIdx], ecx
        je      same
        mov     eax, ecx
        mov     dword ptr [g_currentNodeIdx], eax
same:
        mov     ecx, dword ptr [g_cj_0054205c]
        pop     esi
        mov     dword ptr [eax*4 + 0], ecx
done:
        ret
    }
}
#endif


/* @addr 0x00413ea0 (157b boot) - 4-stage sound setup loop:
 *   ThreeChanPackClamp(0x408000); CopyThreeFields(cj); MStackPush8;
 *   pause? jmp tail. g_eventQueueTotal=0x23, g_eventQueueEnd=cj; SetJmp; pause? jmp tail.
 *   if !(g_xformDirtyFlags & 4): g_eventQueueTotal = 0x14.
 *   loop: call PendingMatch_PushSetXfmMaskCallPop_00413f40; pause? jmp tail. if dirty bit2: jmp 0x96 path.
 *   if (--g_eventQueueTotal >= 0): loop again.
 *   tail: call MStackPop8; ret.
 */
__declspec(naked) void SoundSetupLoop(void) {
    __asm {
        push    ebx
        push    offset g_dispatchSave1130
        call    ThreeChanPackClamp
        mov     eax, dword ptr [g_cj_0054205c]
        add     esp, 4
        push    eax
        call    CopyThreeFields
        add     esp, 4
        call    MStackPush8
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   71h
        mov     ecx, dword ptr [g_cj_0054205c]
        mov     dword ptr [g_eventQueueTotal], 0x23
        mov     dword ptr [g_eventQueueEnd], ecx
        call    SetJmp_ZeroAndDirty4
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   4dh
        mov     al, byte ptr [g_xformDirtyFlags]
        mov     bl, 4
        _emit   84h
        _emit   0c3h
        _emit   75h
        _emit   0ah
        mov     dword ptr [g_eventQueueTotal], 0x14
loop413ea0:
        call    PendingMatch_PushSetXfmMaskCallPop_00413f40
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   2ah
        test    byte ptr [g_xformDirtyFlags], bl
        _emit   75h
        _emit   1dh
        mov     eax, dword ptr [g_eventQueueTotal]
        dec     eax
        mov     dword ptr [g_eventQueueTotal], eax
        _emit   78h
        _emit   10h
        call    PendingMatch_PushSetXfmMaskCallPop_00413f40
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   74h
        _emit   0ddh
        pop     ebx
        ret
        call    MStackPop8
        pop     ebx
        ret
    }
}


/* @addr 0x0049c220 (274b game) - three adjacent blocks.
 *   B1 (0..0x7f): 2x Mul10Tail with 0x3333 mod for g_currentNodeFlags/g_xformScratch2088;
 *     store results to scaledInit[+0x6c/+0x74]; g_cj_0054205c = scaledInit;
 *     baseSel[+0x5c]=0x30; baseSel[+0x74]=1; ret.
 *   B2 (0x80..0xe3, +12 NOPs): dec baseSel[+0x74] (clamp to 3 if was 0); if
 *     orig was 0: call Phase1ChainExtendedInitLoop. If !pause: dec baseSel[+0x5c]; if was 0:
 *     tail-jmp ScaledIndirectJmp_0049c850. ret.
 *   B3 (0xf0..0x111): call BootOneShotSetup; if !pause: call PendingMatch_MStackPush8_0040a8d0;
 *     if !pause: tail-jmp GuardedSeq_MStackCall_then_CallSetPause_0049c340; ret.
 */
__declspec(naked) void DualMul10AndDispatchChain(void) {
    __asm {
        mov     edx, dword ptr [g_currentNodeFlags]
        mov     eax, dword ptr [g_currentNodeIdx]
        mov     ecx, dword ptr [g_baseSel]
        push    esi
        push    edi
        push    edx
        push    0x3333
        lea     esi, [eax*4 + 0]
        lea     edi, [ecx*4 + 0]
        call    Mul10Tail
        add     esp, 8
        mov     dword ptr [g_currentNodeFlags], eax
        mov     eax, dword ptr [g_xformScratch2088]
        push    eax
        push    0x3333
        call    Mul10Tail
        mov     ecx, dword ptr [g_currentNodeFlags]
        mov     dword ptr [g_xformScratch2088], eax
        mov     dword ptr [esi + 0x6c], ecx
        mov     edx, dword ptr [g_xformScratch2088]
        mov     dword ptr [esi + 0x74], edx
        mov     eax, dword ptr [g_currentNodeIdx]
        mov     dword ptr [g_cj_0054205c], eax
        mov     eax, 1
        add     esp, 8
        mov     dword ptr [edi + 0x5c], 0x30
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [edi + 0x74], eax
        pop     edi
        pop     esi
        ret
        nop
        mov     ecx, dword ptr [g_baseSel]
        mov     eax, dword ptr [ecx*4 + 0x74]
        dec     eax
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [g_bootInitSaveSlot], eax
        _emit   75h
        _emit   0ah
        mov     eax, 3
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x74], eax
        mov     eax, dword ptr [g_bootInitSaveSlot]
        test    eax, eax
        _emit   75h
        _emit   0eh
        call    Phase1ChainExtendedInitLoop
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   21h
        mov     ecx, dword ptr [g_baseSel]
        mov     eax, dword ptr [ecx*4 + 0x5c]
        dec     eax
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x5c], eax
        _emit   75h
        _emit   05h
        jmp     ScaledIndirectJmp_0049c850
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        call    BootOneShotSetup
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   13h
        call    PendingMatch_MStackPush8_0040a8d0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   05h
        jmp     GuardedSeq_MStackCall_then_CallSetPause_0049c340
        ret
    }
}


/* @addr 0x00483c90 (334b game) - 4-block: thunk + install-self body + 2 small thunks. */
__declspec(naked) void QuadBlockInstallChainThunks(void) {
    __asm {
        call    CjTableThresholdDispatch
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   0dh
        push    0x004ee7b8
        call    ArgSarStoreJmp
        add     esp, 4
        ret
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
    body_cb0:
        mov     eax, dword ptr [g_baseSel]
        push    ebx
        push    esi
        lea     esi, [eax*4 + 0]
        mov     eax, dword ptr [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], 0
        test    eax, eax
        _emit   74h
        _emit   08h
        call    CjInstallSelfRouter
        pop     esi
        pop     ebx
        ret
        call    MainTickChain
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   0afh
        _emit   00h
        _emit   00h
        _emit   00h
        call    PendingMatch_00416e20
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   9dh
        _emit   00h
        _emit   00h
        _emit   00h
        call    CopyJmp_SlotCmp3way_g_currentNodeIdx
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   8bh
        _emit   00h
        _emit   00h
        _emit   00h
        mov     al, byte ptr [g_xformDirtyFlags]
        mov     ebx, 1
        _emit   84h
        _emit   0c3h
        mov     dword ptr [g_walkCallback], 0
        _emit   75h
        _emit   08h
        call    DualBlockChainCallInstall
        pop     esi
        pop     ebx
        ret
        mov     dword ptr [g_walkCallback], ebx
        call    ByteWordTableTaggedDispatch
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   57h
        mov     dword ptr [esi + 8], offset body_cb0
        mov     ecx, dword ptr [g_baseSel]
        mov     edx, offset body_cb0
        mov     dword ptr [ecx*4 + 0x84], ebx
        mov     eax, dword ptr [esi + 4]
        add     edx, 0x01000000
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [eax*4 + 0], edx
        mov     eax, dword ptr [g_currentNodeIdx]
        inc     eax
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [esi + 4], eax
        mov     eax, dword ptr [g_baseSel]
        mov     dword ptr [eax*4 + 0x84], 0
        call    GameModeAdvanceCluster
        mov     dword ptr [g_framePauseFlag], ebx
        pop     esi
        pop     ebx
        ret
        _emit   90h
        call    MainTickChain
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   0fh
        mov     dword ptr [g_walkCallback], 0x2013
        jmp     DualBlockChainCallInstall
        ret
        _emit   90h
        _emit   90h
        call    MainTickChain
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   0fh
        mov     dword ptr [g_walkCallback], 0x1013
        jmp     DualBlockChainCallInstall
        ret
    }
}

/* extern void Input_PollJoystick(void); -- defined elsewhere with diff sig */
extern void *g_iat_GetFileAttributesA;


/* @addr 0x004ac650 (290b audio) - MIDI MCI playback position setter.
 *   Calls Audio_TimerTeardown. Saves 4 args into globals (5438f8/ec/f0/f4).
 *   If 0x54390c non-zero or PostInit fails or already-init flag 0x543904 set:
 *     skip to timeGetTime tail. Else build MCI packet with mciSendCommandA
 *     (cmd 0x80d MCI_SET, 0x806 MCI_PLAY); convert esi/edi via /60 divmod
 *     using 0x88888889 reciprocal-mul to TMSF (mins:secs:frames) format.
 *     Set flag 0x543904 on success. Tail-call timeGetTime via IAT[0x4d2240];
 *     save in 0x5438fc.
 */
__declspec(naked) void Audio_TimerSet(void) {
    __asm {
        sub     esp, 0x18
        push    ebx
        push    esi
        push    edi
        call    Audio_TimerTeardown
        mov     eax, [esp + 0x34]
        mov     ebx, [esp + 0x28]
        mov     esi, [esp + 0x2c]
        mov     edi, [esp + 0x30]
        mov     dword ptr [g_timerHandle], eax
        mov     eax, dword ptr [g_audioState0C]
        test    eax, eax
        mov     dword ptr [g_timerActive], ebx
        mov     dword ptr [g_timerStartSec], esi
        mov     dword ptr [g_timerEndSec], edi
        jne     L_mp_tailCall
        call    Helper_AuxAudio_PostInit
        test    eax, eax
        jz      L_mp_tailCall
        mov     eax, dword ptr [g_timerFlag]
        test    eax, eax
        jne     L_mp_tailCall
        mov     edx, dword ptr [g_audioPreState]
        lea     ecx, [esp + 0x18]
        push    ebp
        mov     ebp, dword ptr [g_iat_mciSendCommandA]
        push    ecx
        push    0x400
        push    0x80d
        push    edx
        mov     dword ptr [esp + 0x30], 0x0a
        call    ebp
        mov     eax, 0x88888889
        mov     ecx, ebx
        imul    esi
        add     edx, esi
        and     ecx, 0xff
        sar     edx, 5
        mov     eax, edx
        shr     eax, 31
        add     edx, eax
        mov     eax, esi
        mov     ebx, edx
        mov     esi, 60
        cdq
        idiv    esi
        xor     eax, eax
        and     ebx, 0xffff
        mov     ah, dl
        or      ebx, eax
        mov     eax, 0x88888889
        imul    edi
        add     edx, edi
        sar     edx, 5
        mov     eax, edx
        shr     eax, 31
        add     edx, eax
        mov     eax, edi
        mov     esi, edx
        mov     edi, 60
        cdq
        idiv    edi
        xor     eax, eax
        and     esi, 0xffff
        shl     ebx, 8
        or      ebx, ecx
        mov     [esp + 0x14], ebx
        mov     ah, dl
        mov     edx, dword ptr [g_audioPreState]
        or      esi, eax
        shl     esi, 8
        or      esi, ecx
        lea     ecx, [esp + 0x10]
        push    ecx
        push    0xc
        push    0x806
        push    edx
        mov     [esp + 0x28], esi
        call    ebp
        neg     eax
        sbb     eax, eax
        pop     ebp
        inc     eax
        mov     dword ptr [g_timerFlag], eax
    L_mp_tailCall:
        call    dword ptr [g_iat_timeGetTime]
        pop     edi
        pop     esi
        mov     dword ptr [g_timerLastNow], eax
        pop     ebx
        add     esp, 0x18
        ret
    }
}


/* @addr 0x0040e190 (369b boot) - 3-entry packed mstack-scoped init + alarms.
 *   Entry 1 (offset 0, 180b): MStackPush8, then on no-error
 *     mstack-pushes g_eventQueueNotMask, caches g_fightGroupHead into 0x542054,
 *     sets g_walkCallback = &g_phaseChainArr2>>2 (stored also in 0x5381 3c),
 *     g_eventQueueIdx = &g_dispatchSave522>>2, g_eventQueueNotMask = 0xc1.
 *     Pushes 0x49db40, 0xc0 onto StoreTwoCall. If bit 0 of
 *     0x54208c clear, calls StackPushAdd15CallPop +
 *     ZeroThreeFields_0040a8b0. Pops the snapshot back and tail-jmps
 *     MStackPop8.
 *   12b NOP align pad.
 *   Entry 2 (offset 0xc0, 83b): sets 0x54207c=0x2666, 0x54206c=0x170a;
 *     calls StoreDoubleNegPauseSubStore; on no-error computes
 *     g_walkCallback += 0x10000, multiplies via Mul10Tail
 *     (push twice with the cur cj), negates, and tail-jmps PendingMatch_StoreDoubleNegPauseSubStore.
 *   13b NOP align pad.
 *   Entry 3 (offset 0x120, 81b): mirror of entry 2 with 0x3333 / 0x7ae
 *     constants; no negation before final store; tail-jmps PendingMatch_StoreDoubleNegPauseSubStore.
 */
__declspec(naked) void MStackInitTriAlarm(void) {
    __asm {
        call    MStackPush8
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_msi_e1Ret
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_eventQueueNotMask]
        inc     eax
        push    0xc0
        mov     dword ptr [g_matrixStackTop], eax
        push    0x49db40
        mov     dword ptr [eax*4 + g_phaseChainTbl], ecx
        mov     edx, dword ptr [g_fightGroupHead]
        mov     eax, offset g_phaseChainArr2
        mov     dword ptr [g_eventQueueEnd], edx
        shr     eax, 2
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [g_alarmTriState], eax
        mov     eax, offset g_dispatchSave522
        mov     dword ptr [g_eventQueueNotMask], 0xc1
        shr     eax, 2
        mov     dword ptr [g_eventQueueIdx], eax
        call    StoreTwoCall
        mov     al, byte ptr [g_xformDirtyFlags]
        add     esp, 8
        test    al, 1
        jne     short L_msi_skipAlarm
        call    StackPushAdd15CallPop
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_msi_e1Ret
        call    ZeroThreeFields_0040a8b0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_msi_e1Ret
    L_msi_skipAlarm:
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [eax*4 + g_phaseChainTbl]
        dec     eax
        mov     dword ptr [g_eventQueueNotMask], ecx
        mov     dword ptr [g_matrixStackTop], eax
        jmp     MStackPop8
    L_msi_e1Ret:
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        /* entry 2 (offset 0xc0) */
    L_msi_entry2:
        mov     dword ptr [g_eventQueueNotMask], 0x2666
        mov     dword ptr [g_walkCallback], 0x170a
        call    StoreDoubleNegPauseSubStore
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_msi_e2End
        mov     eax, dword ptr [g_walkCallback]
        mov     ecx, dword ptr [g_eventQueueNotMask]
        add     eax, 0x10000
        push    ecx
        push    eax
        mov     dword ptr [g_walkCallback], eax
        call    Mul10Tail
        add     esp, 8
        mov     dword ptr [g_eventQueueNotMask], eax
        neg     eax
        mov     dword ptr [g_walkCallback], eax
        jmp     PendingMatch_StoreDoubleNegPauseSubStore
    L_msi_e2End:
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        /* entry 3 (offset 0x120) */
    L_msi_entry3:
        mov     dword ptr [g_eventQueueNotMask], 0x3333
        mov     dword ptr [g_walkCallback], 0x7ae
        call    StoreDoubleNegPauseSubStore
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_msi_e3End
        mov     eax, dword ptr [g_walkCallback]
        mov     ecx, dword ptr [g_eventQueueNotMask]
        add     eax, 0x10000
        push    ecx
        push    eax
        mov     dword ptr [g_walkCallback], eax
        call    Mul10Tail
        add     esp, 8
        mov     dword ptr [g_eventQueueNotMask], eax
        mov     dword ptr [g_walkCallback], eax
        jmp     PendingMatch_StoreDoubleNegPauseSubStore
    L_msi_e3End:
        ret
    }
}


#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void Vec2SumMul10ChainCompute(void)

{
  int iVar1;
  
  g_walkCallback = MK4_NODE_AT(undefined4, g_cj_0054205c, 0x54);
  g_eventQueueCurrent = MK4_NODE_AT(undefined4, g_cj_0054205c, 0x5c);
  g_walkCallback = Mul10Tail(g_walkCallback,g_walkCallback);
  iVar1 = Mul10Tail(g_eventQueueCurrent,g_eventQueueCurrent);
  g_eventQueueCurrent = iVar1 + g_walkCallback;
  g_eventQueueWorkType = g_rangeSqLimit + 0xc0000;
  return;
}
#else
__declspec(naked) void Vec2SumMul10ChainCompute(void)
{
    __asm
    {
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     eax, dword ptr [ecx*4 + 0x54]
        mov     dword ptr [g_walkCallback], eax
        mov     ecx, dword ptr [ecx*4 + 0x5c]
        push    eax
        push    eax
        mov     dword ptr [g_eventQueueCurrent], ecx
        call    Mul10Tail
        add     esp, 8
        mov     dword ptr [g_walkCallback], eax
        mov     eax, dword ptr [g_eventQueueCurrent]
        push    eax
        push    eax
        call    Mul10Tail
        mov     ecx, dword ptr [g_walkCallback]
        mov     edx, dword ptr [g_rangeSqLimit]
        add     eax, ecx
        add     edx, 0xc0000
        add     esp, 8
        mov     dword ptr [g_eventQueueCurrent], eax
        mov     dword ptr [g_eventQueueWorkType], edx
        ret
        nop
        nop
        nop
    L_v2sm10_sub2:
        call    CondPickDualStore
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_v2sm10_sub2_ret
        mov     ecx, dword ptr [g_baseSel]
        mov     eax, 0x304
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x74], eax
        call    PendingMatch_ZeroAndDirty4_0040d1d0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_v2sm10_sub2_ret
        push    0x4f2570
        call    ArgSarStoreJmp
        add     esp, 4
    L_v2sm10_sub2_ret:
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
    L_v2sm10_sub3:
        push    esi
        call    DualCmpSwapStore
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_v2sm10_sub3_ret
        push    0x4f25b8
        call    ScaledStackCallPause
        mov     eax, dword ptr [g_framePauseFlag]
        add     esp, 4
        test    eax, eax
        jne     L_v2sm10_sub3_ret
        test    byte ptr [g_xformDirtyFlags], 4
        je      short L_v2sm10_sub3_main
        call    CallSetPause
        pop     esi
        ret
    L_v2sm10_sub3_main:
        mov     eax, dword ptr [g_currentNodeIdx]
        mov     eax, dword ptr [eax*4 + 0x18]
        mov     dword ptr [g_xformEntityIdx], eax
        mov     ecx, dword ptr [eax*4 + 0x28]
        mov     eax, offset g_dispatchSave510
        shr     eax, 2
        mov     dword ptr [g_xformEntityIdx], ecx
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 4], eax
        mov     edx, dword ptr [g_currentNodeFlags]
        mov     ecx, dword ptr [g_currentNodeIdx]
        push    edx
        push    0x3333
        lea     esi, [ecx*4]
        call    Mul10Tail
        add     esp, 8
        mov     dword ptr [g_currentNodeFlags], eax
        mov     eax, dword ptr [g_xformScratch2088]
        push    eax
        push    0x3333
        call    Mul10Tail
        mov     ecx, dword ptr [g_currentNodeFlags]
        mov     dword ptr [g_xformScratch2088], eax
        mov     dword ptr [esi + 0x6c], ecx
        mov     edx, dword ptr [g_xformScratch2088]
        add     esp, 8
        mov     dword ptr [esi + 0x74], edx
        mov     eax, dword ptr [g_currentNodeIdx]
        push    0x4f25c8
        mov     dword ptr [g_fightGroupHead], eax
        call    ArgSar_Set0_Jmp
        add     esp, 4
    L_v2sm10_sub3_ret:
        pop     esi
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
    L_v2sm10_sub4:
        mov     dword ptr [g_walkCallback], 0xe
        call    TableLookupCall_g_eventTbl_112
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_v2sm10_sub4_ret
        jmp     Alarm5EntryScopedChain
    L_v2sm10_sub4_ret:
        ret
    }
}
#endif


__declspec(naked) void Phase2InitSlotTreeWalk(void)
{
    __asm {
        mov     dword ptr [g_walkCallback], 0
        call    FlagThunk4EntryDispatcher
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p2is_ret
        mov     dword ptr [g_walkCallback], 8
        call    FlagThunk4EntryDispatcher
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p2is_ret
        mov     dword ptr [g_walkCallback], 2
        call    DirtyDoubleDeref
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p2is_ret
        mov     eax, dword ptr [g_currentNodeIdx]
        mov     ecx, dword ptr [eax*4 + 0x24]
        mov     dword ptr [g_xformEntityIdx], ecx
        call    DispatcherComplex260_FramePauseScaledStore
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p2is_ret
        test    byte ptr [g_xformDirtyFlags], 4
        je      L_p2is_continue
        jmp     PendingMatch_DirtyDoubleDeref_0041afd0
    L_p2is_continue:
        mov     edx, dword ptr [g_currentNodeIdx]
        mov     dword ptr [edx*4 + 0x30], 0x80
        mov     eax, dword ptr [g_particleEmitterNode]
        mov     ecx, dword ptr [g_currentNodeIdx]
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x3C], eax
        mov     edx, dword ptr [g_fightGroupHead]
        mov     dword ptr [g_eventQueueNotMask], 0x10000
        mov     eax, dword ptr [edx*4 + 0x34]
        and     eax, 1
        mov     dword ptr [g_walkCallback], eax
        je      L_p2is_after_select
        mov     dword ptr [g_eventQueueNotMask], 0xFFFF0000
    L_p2is_after_select:
        mov     ecx, dword ptr [g_currentNodeIdx]
        mov     edx, dword ptr [ecx*4 + 0x34]
        or      edx, eax
        mov     eax, 0x147A
        mov     dword ptr [ecx*4 + 0x34], edx
        mov     ecx, dword ptr [g_currentNodeIdx]
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x80], eax
        mov     edx, dword ptr [g_currentNodeIdx]
        mov     dword ptr [g_eventQueueEnd], edx
        call    MStackPush2RunCountdown
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p2is_ret
        call    MStackBracket7_DispatchAndChain
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p2is_ret
        mov     dword ptr [g_walkCallback], 2
        call    BootStateTriple
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p2is_ret
        mov     eax, dword ptr [g_xformEntityIdx]
        mov     ecx, dword ptr [g_eventQueueEnd]
        mov     eax, dword ptr [eax*4 + 0x3C]
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x54], eax
        mov     edx, dword ptr [g_xformEntityIdx]
        mov     ecx, dword ptr [g_eventQueueEnd]
        mov     eax, dword ptr [edx*4 + 0x40]
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x58], eax
        mov     edx, dword ptr [g_xformEntityIdx]
        mov     ecx, dword ptr [g_eventQueueEnd]
        mov     eax, dword ptr [edx*4 + 0x44]
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x5C], eax
        mov     edx, dword ptr [g_eventQueueEnd]
        mov     eax, dword ptr [edx*4 + 0x18]
        mov     dword ptr [g_walkCallback], 0
        mov     dword ptr [g_eventQueueTotal], eax
        mov     dword ptr [eax*4 + 0x30], 0
        mov     ecx, dword ptr [g_eventQueueTotal]
        mov     eax, dword ptr [g_walkCallback]
        mov     dword ptr [ecx*4 + 0x34], eax
        mov     eax, dword ptr [g_eventQueueTotal]
        mov     edx, dword ptr [g_walkCallback]
        mov     dword ptr [eax*4 + 0x38], edx
        mov     ecx, dword ptr [g_baseSel]
        mov     eax, offset g_walkTreeArrBase
        sar     eax, 2
        mov     dword ptr [g_xformEntityIdx], eax
        mov     edx, dword ptr [ecx*4 + 0x34]
        add     eax, edx
        mov     dword ptr [g_xformEntityIdx], eax
        mov     edx, dword ptr [eax*4]
        mov     dword ptr [g_xformEntityIdx], edx
        call    MStackBracket1_TreeWalkRecursive2
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p2is_ret
        test    byte ptr [g_xformDirtyFlags], 4
        je      L_p2is_after_walk
        jmp     PendingMatch_DirtyDoubleDeref_0041afd0
    L_p2is_after_walk:
        mov     eax, dword ptr [g_eventQueueTotal]
        mov     dword ptr [g_xformEntityIdx], eax
        call    Thunk_MStackPush2ChainPrepend
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p2is_ret
        jmp     PendingMatch_DirtyDoubleDeref_0041afd0
    L_p2is_ret:
        ret
    }
}


__declspec(naked) void MStackBracket3_FieldSequentialCopy(void)
{
    __asm {
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_xformEntityIdx]
        inc     eax
        push    ebx
        mov     dword ptr [g_matrixStackTop], eax
        mov     ebx, 4
        mov     dword ptr [eax*4], ecx
        mov     eax, dword ptr [g_matrixStackTop]
        mov     edx, dword ptr [g_pendingNodeType]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4], edx
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_fightGroupHead]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4], ecx
        mov     al, byte ptr [g_bootGatedByte360c]
        mov     edx, dword ptr [g_currentNodeIdx]
        mov     dword ptr [g_currentNodeIdx], 0
        test    al, al
        mov     dword ptr [g_pendingNodeType], edx
        je      L_mb3fsc_pop3
        mov     dword ptr [g_walkCallback], 0x3333
        call    AudioMixerStep
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_mb3fsc_abort
        add     dword ptr [g_walkCallback], 0xCCCC
        call    ZeroAndDirty4
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_mb3fsc_abort
        test    byte ptr [g_xformDirtyFlags], bl
        je      L_mb3fsc_pop3
        mov     eax, offset g_dispatchSave619
        shr     eax, 2
        mov     dword ptr [g_walkCallback], eax
        call    PushSetXfmMaskCallPop
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_mb3fsc_abort
        test    byte ptr [g_xformDirtyFlags], bl
        jne     L_mb3fsc_pop3
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     dword ptr [ecx*4 + 0x30], 0xC2
        lea     eax, [ecx*4]
        mov     ecx, dword ptr [g_eventQueueSeed]
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [eax + 0x3C], ecx
        mov     ecx, dword ptr [eax + 0x34]
        or      ch, 0x40
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [eax + 0x34], ecx
        mov     edx, dword ptr [g_xformEntityIdx]
        mov     ecx, dword ptr [edx*4]
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [eax + 0x54], ecx
        mov     ecx, dword ptr [g_xformEntityIdx]
        inc     ecx
        mov     dword ptr [g_xformEntityIdx], ecx
        mov     ecx, dword ptr [ecx*4]
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [eax + 0x58], ecx
        mov     ecx, dword ptr [g_xformEntityIdx]
        inc     ecx
        mov     dword ptr [g_xformEntityIdx], ecx
        mov     ecx, dword ptr [ecx*4]
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [eax + 0x5C], ecx
        mov     ecx, dword ptr [g_xformEntityIdx]
        inc     ecx
        mov     dword ptr [g_xformEntityIdx], ecx
        mov     ecx, dword ptr [g_pendingNodeType]
        mov     ecx, dword ptr [ecx*4]
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [eax + 0x6C], ecx
        mov     ecx, dword ptr [g_pendingNodeType]
        inc     ecx
        mov     dword ptr [g_pendingNodeType], ecx
        mov     ecx, dword ptr [ecx*4]
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [eax + 0x70], ecx
        mov     ecx, dword ptr [g_pendingNodeType]
        inc     ecx
        mov     dword ptr [g_pendingNodeType], ecx
        mov     ecx, dword ptr [ecx*4]
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [eax + 0x74], ecx
        mov     ecx, dword ptr [g_pendingNodeType]
        inc     ecx
        mov     dword ptr [g_pendingNodeType], ecx
        mov     edx, dword ptr [eax + 0x6C]
        mov     dword ptr [g_eventQueueWorkType], edx
        mov     eax, dword ptr [eax + 0x74]
        mov     dword ptr [g_chainAccumCur], eax
        call    Atan2QuadrantLookup
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_mb3fsc_abort
        mov     ecx, dword ptr [g_pendingMatchVar2]
        mov     edx, dword ptr [g_walkCallback]
        sub     edx, ecx
        mov     dword ptr [g_walkCallback], edx
        call    BootMod6487eClampAndChainMul10
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_mb3fsc_abort
        mov     edx, dword ptr [g_fightGroupHead]
        mov     eax, dword ptr [g_walkCallback]
        mov     dword ptr [edx*4 + 0x64], eax
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     eax, dword ptr [ecx*4 + 0x18]
        mov     dword ptr [g_currentNodeIdx], eax
        mov     ecx, dword ptr [eax*4 + 0x20]
        and     ch, 0xF9
        mov     dword ptr [eax*4 + 0x20], ecx
        mov     edx, dword ptr [g_currentNodeIdx]
        mov     ecx, 0x00411890
        mov     eax, dword ptr [edx*4 + 0x28]
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [g_xformEntityIdx], eax
        mov     dword ptr [eax*4 + 0x10], ecx
        call    PendingMatch_ChainWalkPushPop_00411890
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_mb3fsc_abort
        call    MStackCall_MStackPush2ChainPrepend_004062f0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_mb3fsc_abort
        mov     eax, dword ptr [g_fightGroupHead]
        mov     dword ptr [g_currentNodeIdx], eax
    L_mb3fsc_pop3:
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [eax*4]
        dec     eax
        mov     dword ptr [g_fightGroupHead], ecx
        mov     dword ptr [g_matrixStackTop], eax
        mov     edx, dword ptr [eax*4]
        dec     eax
        mov     dword ptr [g_pendingNodeType], edx
        mov     dword ptr [g_matrixStackTop], eax
        mov     ecx, dword ptr [eax*4]
        dec     eax
        mov     dword ptr [g_xformEntityIdx], ecx
        mov     ecx, dword ptr [g_xformDirtyFlags]
        mov     dword ptr [g_matrixStackTop], eax
        mov     eax, dword ptr [g_currentNodeIdx]
        or      ecx, ebx
        test    eax, eax
        mov     dword ptr [g_xformDirtyFlags], ecx
        je      L_mb3fsc_abort
        mov     eax, ecx
        xor     eax, ebx
        mov     dword ptr [g_xformDirtyFlags], eax
    L_mb3fsc_abort:
        pop     ebx
        ret
    }
}


#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void Phase4FourPackedDispatch(void)

{
  ArgSarStoreJmp(0x4d7ce8);
  return;
}
#else
__declspec(naked) void Phase4FourPackedDispatch(void)
{
    __asm {
        push    offset g_dispatchSave918
        call    ArgSarStoreJmp
        add     esp, 4
        ret
        nop
        nop
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
    L_p4fpd2_M:
        mov     eax, dword ptr [g_baseSel]
        push    esi
        lea     esi, [eax*4]
        mov     eax, dword ptr [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], 0
        sub     eax, 0
        je      L_p4fpd2_M_phase0
        dec     eax
        je      L_p4fpd2_M_phase1
        mov     ecx, dword ptr [g_baseSel]
        mov     edx, dword ptr [ecx*4 + 0x38]
        mov     dword ptr [g_fightGroupHead], edx
        call    MStackPush2TripleCallChain
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        je      L_p4fpd2_M_call_0041f830
        pop     esi
        ret
    L_p4fpd2_M_phase1:
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_fightGroupHead]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4], ecx
        mov     edx, dword ptr [g_baseSel]
        mov     eax, dword ptr [edx*4 + 0x38]
        mov     dword ptr [g_fightGroupHead], eax
        call    MStackPushPairTriCall
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4fpd2_M_ret
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [eax*4]
        dec     eax
        mov     dword ptr [g_fightGroupHead], ecx
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [g_xformEntityIdx], 0x0041F1B0
        call    ScaledChainCallPauseSetJmp
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4fpd2_M_ret
        mov     dword ptr [g_walkCallback], 0x0E
        call    TableLookupCall_g_eventTbl_112
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4fpd2_M_ret
        call    MStackCall_MStackPush2ChainLLInsert
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4fpd2_M_ret
        mov     eax, dword ptr [g_xformDirtyFlags]
        mov     ecx, 4
        or      eax, ecx
        mov     dword ptr [g_xformDirtyFlags], eax
        mov     eax, dword ptr [g_eventQueueIdx]
        test    eax, eax
        je      L_p4fpd2_M_install2
        mov     edx, dword ptr [g_xformDirtyFlags]
        xor     edx, ecx
        test    eax, eax
        mov     dword ptr [g_xformDirtyFlags], edx
        jne     L_p4fpd2_M_call_0041f830
    L_p4fpd2_M_install2:
        mov     eax, 1
        mov     dword ptr [esi + 8], 0x0041B920
        mov     dword ptr [esi + 0x84], 2
        mov     dword ptr [g_pendingNodeType], eax
        mov     dword ptr [g_framePauseFlag], eax
        pop     esi
        ret
    L_p4fpd2_M_phase0:
        mov     edx, dword ptr [g_eventQueueNotMask]
        mov     dword ptr [g_eventQueueIdx], edx
        call    CondPickDualStore
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4fpd2_M_ret
        call    DualCmpSwapStore
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4fpd2_M_ret
        push    offset g_dispatchSave919
        call    ScaledStackCallPause
        mov     eax, dword ptr [g_framePauseFlag]
        add     esp, 4
        test    eax, eax
        jne     L_p4fpd2_M_ret
        test    byte ptr [g_xformDirtyFlags], 4
        je      L_p4fpd2_M_continue
    L_p4fpd2_M_call_0041f830:
        call    CallSetPause
        pop     esi
        ret
    L_p4fpd2_M_continue:
        mov     eax, dword ptr [g_currentNodeIdx]
        mov     eax, dword ptr [eax*4 + 0x18]
        mov     dword ptr [g_xformEntityIdx], eax
        mov     ecx, dword ptr [eax*4 + 0x28]
        mov     eax, offset g_dispatchSave510
        sar     eax, 2
        mov     dword ptr [g_xformEntityIdx], ecx
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 4], eax
        mov     eax, dword ptr [g_baseSel]
        mov     ecx, dword ptr [eax*4 + 0x40]
        mov     dword ptr [g_xformEntityIdx], ecx
        mov     ecx, dword ptr [ecx*4]
        mov     dword ptr [g_currentNodeFlags], ecx
        mov     eax, dword ptr [eax*4 + 0x44]
        mov     dword ptr [g_xformEntityIdx], eax
        push    ecx
        mov     edx, dword ptr [eax*4]
        push    0x3333
        mov     dword ptr [g_xformScratch2088], edx
        call    Mul10Tail
        add     esp, 8
        mov     dword ptr [g_currentNodeFlags], eax
        mov     eax, dword ptr [g_xformScratch2088]
        push    eax
        push    0x3333
        call    Mul10Tail
        mov     ecx, dword ptr [g_currentNodeIdx]
        mov     edx, dword ptr [g_currentNodeFlags]
        mov     dword ptr [g_xformScratch2088], eax
        add     esp, 8
        mov     dword ptr [ecx*4 + 0x6C], edx
        mov     eax, dword ptr [g_currentNodeIdx]
        mov     ecx, dword ptr [g_xformScratch2088]
        mov     dword ptr [eax*4 + 0x74], ecx
        mov     eax, dword ptr [g_fightStateProgress]
        mov     edx, dword ptr [g_currentNodeIdx]
        lea     eax, [eax + eax*4]
        mov     dword ptr [g_fightGroupHead], edx
        mov     dword ptr [g_walkCallback], eax
        sar     eax, 0x10
        mov     dword ptr [g_pendingNodeType], eax
        mov     eax, 1
        mov     dword ptr [esi + 8], 0x0041B920
        mov     dword ptr [esi + 0x84], eax
        mov     dword ptr [g_framePauseFlag], eax
    L_p4fpd2_M_ret:
        pop     esi
        ret
        nop
        nop
        nop
        nop
        nop
    L_p4fpd2_H:
        mov     eax, dword ptr [g_baseSel]
        push    esi
        lea     esi, [eax*4]
        mov     eax, dword ptr [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], 0
        sub     eax, 0
        je      L_p4fpd2_H_phase0
        dec     eax
        je      L_p4fpd2_H_phase1
        mov     ecx, dword ptr [g_currentNodeFlags]
        mov     eax, 0x83
        mov     dword ptr [g_walkCallback], eax
        add     ecx, eax
        mov     eax, dword ptr [g_eventQueueEnd]
        mov     dword ptr [g_currentNodeFlags], ecx
        dec     eax
        mov     dword ptr [g_eventQueueEnd], eax
        jns     L_p4fpd2_H_call_p2
        call    CallSetPause
        pop     esi
        ret
    L_p4fpd2_H_phase1:
        mov     dword ptr [g_eventQueueIdx], 0x0A
        mov     dword ptr [g_xformScratch2088], 0x312
        call    PendingMatch_MStackPush8_0041bca0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4fpd2_H_exit
        mov     eax, 1
        mov     dword ptr [esi + 8], 0x0041BBB0
        mov     dword ptr [esi + 0x84], 2
        mov     dword ptr [g_pendingNodeType], eax
        mov     dword ptr [g_framePauseFlag], eax
        pop     esi
        ret
    L_p4fpd2_H_phase0:
        mov     dword ptr [g_eventQueueEnd], 0x2D
        mov     dword ptr [g_currentNodeFlags], 0x51E
    L_p4fpd2_H_call_p2:
        mov     dword ptr [g_eventQueueIdx], 9
        mov     dword ptr [g_xformScratch2088], 0xFFFFFCEE
        call    PendingMatch_MStackPush8_0041bca0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4fpd2_H_exit
        mov     eax, 1
        mov     dword ptr [esi + 8], 0x0041BBB0
        mov     dword ptr [esi + 0x84], eax
        mov     dword ptr [g_pendingNodeType], eax
        mov     dword ptr [g_framePauseFlag], eax
    L_p4fpd2_H_exit:
        pop     esi
        ret
    }
}
#endif


#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void StageEntityInitCluster(void)

{
  ThreeChanPackClamp(&g_dispatchSave1704);
  CopyThreeFields(g_cj_0054205c);
  MK4_NODE_AT(undefined4, g_baseSel, 0x38) = g_currentNodeIdx;
  MK4_NODE_AT(undefined4, g_baseSel, 0x3c) = g_eventQueuePending;
  MK4_NODE_AT(undefined4, g_baseSel, 0x80) = 0;
  g_walkCallback = 0;
  MK4_NODE_AT(undefined4, g_baseSel, 0x7c) = 0;
  MK4_NODE_AT(undefined4, g_baseSel, 0x30) = g_walkCallback;
  MainTickChain();
  if (g_framePauseFlag == 0) {
    g_eventQueueNotMask = 0x1002e;
    HitReactionDispatcher();
    return;
  }
  return;
}
#else
__declspec(naked) void StageEntityInitCluster(void)
{
    __asm {
        /* H1 */
        push     OFFSET g_dispatchSave1704
        call     ThreeChanPackClamp
        mov      eax, dword ptr [g_fightGroupHead]
        add      esp, 4
        push     eax
        call     CopyThreeFields
        mov      ecx, dword ptr [g_baseSel]
        mov      edx, dword ptr [g_currentNodeIdx]
        add      esp, 4
        mov      dword ptr [ecx*4 + 0x38], edx
        mov      eax, dword ptr [g_baseSel]
        mov      ecx, dword ptr [g_xformEntityIdx]
        mov      dword ptr [eax*4 + 0x3c], ecx
        mov      edx, dword ptr [g_baseSel]
        mov      dword ptr [edx*4 + 0x80], 0
        mov      eax, dword ptr [g_baseSel]
        mov      dword ptr [g_walkCallback], 0
        mov      dword ptr [eax*4 + 0x7c], 0
        mov      ecx, dword ptr [g_baseSel]
        mov      edx, dword ptr [g_walkCallback]
        mov      dword ptr [ecx*4 + 0x30], edx
        call     MainTickChain
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_173b
        mov      dword ptr [g_eventQueueNotMask], 0x1002e
        jmp      HitReactionDispatcher
    L_173b:
        ret
        nop
        nop
        nop
        nop
        /* H2 */
        mov      dword ptr [g_walkCallback], 0
        mov      dword ptr [g_active_0053a408], 0
        mov      dword ptr [g_active_00537e88], 0
        call     StoreCallPauseCallPauseJmp
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_178d
        call     MStackPushSet0001
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_178d
        call     ScaledInit_GuardedDirtyXformFromTable_g_scaledInit
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_178d
        jmp      ScaledInitWithCounterAndType_004314f0
    L_178d:
        ret
        nop
        nop
        /* H3 */
        mov      eax, dword ptr [g_baseSel]
        mov      ecx, dword ptr [eax*4 + 0x3c]
        mov      dword ptr [g_xformEntityIdx], OFFSET L_1870
        mov      dword ptr [g_currentNodeIdx], ecx
        call     Thunk_ChainNodeInit
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_182b
        mov      dword ptr [g_walkCallback], 0x43
        mov      dword ptr [g_eventQueueCurrent], 0xffffffff
        call     Thunk_StructArrayWalkCondCall
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_182b
        mov      dword ptr [g_walkCallback], 0x71
        call     MStackInstallBodyEqCheck
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_182b
        call     ScaledZeroFour
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_182b
        call     ScaledZero44
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_182b
        push     OFFSET g_dispatchSave606
        call     IterLoad_g_scaledInit_00542044_then_MStackPush4IndirectCall
        mov      eax, dword ptr [g_framePauseFlag]
        add      esp, 4
        test     eax, eax
        jne      short L_182b
        jmp      PendingMatch_MStackPush2ChainLLInsert_00418170
    L_182b:
        ret
        nop
        nop
        nop
        nop
        /* H4 (L_1830) */
    L_1830:
        mov      dword ptr [g_walkCallback], 0x14
        mov      dword ptr [g_eventQueueCurrent], 0xffffffff
        call     Thunk_StructArrayWalkCondCall
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_1865
        call     MainTickChain
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_1865
        jmp      InstallSelf3WayState
    L_1865:
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        /* H5 (L_1870) */
    L_1870:
        mov      dword ptr [g_walkCallback], 0x14
        mov      dword ptr [g_eventQueueCurrent], 0xffffffff
        call     Thunk_StructArrayWalkCondCall
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_18a5
        call     MainTickChain
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_18a5
        jmp      InstallSelfChainExtendCall_GameModeAdvanceCluster
    L_18a5:
        ret
    }
}
#endif

/* ------------------------------------------------------------------ */
/* Punch-anim event cluster (574b game, 6 packed helpers)              */
/* ------------------------------------------------------------------ */

__declspec(naked) void PunchAnimCluster(void)
{
    __asm {
        /* === Helper 1 (0x496d80): jab impulse via flag-driven mul10 === */
        mov      dword ptr [g_currentNodeFlags], 0
        call     DualConstMaskFlagToggle4
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_6df0
        test     byte ptr [g_xformDirtyFlags], 1
        je       short L_6dab
        mov      dword ptr [g_currentNodeFlags], 0xffffe667
    L_6dab:
        call     DualConstMaskFlagToggle8
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_6df0
        test     byte ptr [g_xformDirtyFlags], 1
        je       short L_6dcc
        mov      dword ptr [g_currentNodeFlags], 0x1999
    L_6dcc:
        mov      eax, dword ptr [g_currentNodeFlags]
        mov      ecx, dword ptr [g_xformScratch2088]
        push     eax
        push     ecx
        call     Mul10Tail
        add      esp, 8
        mov      dword ptr [g_currentNodeFlags], eax
        mov      dword ptr [g_walkCallback], eax
        jmp      MStackNegAwareMul10Pair
    L_6df0:
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        /* === Helper 2: blocked-state tail jmp === */
        mov      dword ptr [g_eventQueueNotMask], 0x2000d
        jmp      HitReactionDispatcher
        nop
        /* === Helper 3: event 0x315 dispatch === */
        mov      dword ptr [g_walkCallback], 0x12
        call     ScaledIndexConditionalAdd
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_6e5a
        call     CondPickDualStore
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_6e5a
        mov      ecx, dword ptr [g_baseSel]
        mov      eax, 0x315
        mov      dword ptr [g_walkCallback], eax
        push     OFFSET g_dispatchSave788
        mov      dword ptr [ecx*4 + 0x74], eax
        call     ArgSarStoreJmp
        add      esp, 4
    L_6e5a:
        ret
        nop
        nop
        nop
        nop
        nop
        /* === Helper 4: install slot 0x30=0x43 + 0x30a3 blend + 004f2068 === */
        call     PendingMatch_StoreTwoCall_004155c0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_6f69
        call     DualCmpSwapStore
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_6f69
        mov      eax, OFFSET g_dispatchSave505
        shr      eax, 2
        mov      dword ptr [g_xformEntityIdx], eax
        call     DispatcherComplex260_MStackBracket1_TreeWalkRecursive2
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_6f69
        call     MStackCall_MStackPush2ChainPrepend_00406340
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_6f69
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      edx, dword ptr [g_currentNodeIdx]
        push     esi
        lea      eax, [ecx*4]
        lea      esi, [edx*4]
        mov      ecx, 0x43
        mov      dword ptr [g_walkCallback], ecx
        mov      dword ptr [esi + 0x30], ecx
        mov      ecx, dword ptr [eax + 0x54]
        mov      dword ptr [g_walkCallback], ecx
        mov      edx, dword ptr [eax + 0x58]
        mov      dword ptr [g_eventQueueCurrent], edx
        mov      eax, dword ptr [eax + 0x5c]
        mov      dword ptr [g_eventQueueWorkType], eax
        mov      dword ptr [esi + 0x54], ecx
        mov      ecx, dword ptr [g_eventQueueCurrent]
        mov      dword ptr [esi + 0x58], ecx
        mov      edx, dword ptr [g_eventQueueWorkType]
        mov      dword ptr [esi + 0x5c], edx
        mov      eax, dword ptr [g_currentNodeFlags]
        push     eax
        push     0x30a3
        call     Mul10Tail
        mov      ecx, dword ptr [g_xformScratch2088]
        add      esp, 8
        mov      dword ptr [g_currentNodeFlags], eax
        push     ecx
        push     0x30a3
        call     Mul10Tail
        mov      edx, dword ptr [g_currentNodeFlags]
        mov      dword ptr [g_xformScratch2088], eax
        mov      dword ptr [esi + 0x6c], edx
        mov      eax, dword ptr [g_xformScratch2088]
        add      esp, 8
        mov      dword ptr [esi + 0x74], eax
        mov      ecx, dword ptr [g_currentNodeIdx]
        push     OFFSET g_dispatchSave789
        mov      dword ptr [g_fightGroupHead], ecx
        call     ArgSar_Set0_Jmp
        add      esp, 4
        pop      esi
    L_6f69:
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        /* === Helper 5: position-gate jmp === */
        call     Vec2SumMul10ChainCompute
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_6f92
        mov      eax, dword ptr [g_eventQueueCurrent]
        mov      ecx, dword ptr [g_eventQueueWorkType]
        cmp      eax, ecx
        jle      short L_6f92
        jmp      ScaledIndirectJmp_0049c850
    L_6f92:
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        /* === Helper 6: event 0x65 + jmp 0x496fc0 === */
        mov      dword ptr [g_walkCallback], 0x65
        call     TableLookupCall_g_eventTbl_112
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_6fbd
        jmp      MultiThunkDispatcher_MStackCall
    L_6fbd:
        ret
    }
}

/* ------------------------------------------------------------------ */
/* Per-tick main chain (750b game, 2 packed helpers):                 */
/*  h1 (0x481070): 14-stage pause-guarded chain (490130 → 494580 →    */
/*                 48f720 → 4903xx series → 486530 → 481360 → 470310 →*/
/*                 0040eb80 → 00427b60 → 0048e2f0 → 49cb40 timer install). */
/*  h2 (0x481340): wait + tail-jmp CallSetPause.                     */
/* ------------------------------------------------------------------ */

__declspec(naked) void MainTickChain(void)
{
    __asm {
        push     esi
        call     ClearBit2x34
        mov      eax, dword ptr [g_framePauseFlag]
        xor      esi, esi
        cmp      eax, esi
        jne      L_1336
        mov      eax, dword ptr [g_baseSel]
        mov      eax, dword ptr [eax*4 + 0x30]
        cmp      eax, esi
        mov      dword ptr [g_currentNodeIdx], eax
        je       short L_10bc
        mov      eax, dword ptr [eax*4]
        cmp      eax, 0x6c
        mov      dword ptr [g_walkCallback], eax
        jne      short L_10bc
        call     GateDispatch6c
        cmp      dword ptr [g_framePauseFlag], esi
        jne      L_1336
    L_10bc:
        call     ScaledInit_GuardedDirtyXformFromTable_g_scaledInit
        cmp      dword ptr [g_framePauseFlag], esi
        jne      L_1336
        call     ScaledAndAldf
        cmp      dword ptr [g_framePauseFlag], esi
        jne      L_1336
        call     ScaledAndAlbf
        cmp      dword ptr [g_framePauseFlag], esi
        jne      L_1336
        call     ScaledAndAl7f
        cmp      dword ptr [g_framePauseFlag], esi
        jne      L_1336
        call     ScaledAndAlfe
        cmp      dword ptr [g_framePauseFlag], esi
        jne      L_1336
        call     ScaledAndAlf7
        cmp      dword ptr [g_framePauseFlag], esi
        jne      L_1336
        call     MStackPushSet0004
        cmp      dword ptr [g_framePauseFlag], esi
        jne      L_1336
        cmp      dword ptr [g_pendingMatchCmp], esi
        jne      short L_114c
        call     DualCallPauseDirtyJmp_00490c30
        cmp      dword ptr [g_framePauseFlag], esi
        jne      L_1336
    L_114c:
        mov      dword ptr [g_pendingMatchCmp], esi
        call     ScaledLoadCmp1003JmpDispatch
        cmp      dword ptr [g_framePauseFlag], esi
        jne      L_1336
        mov      ecx, dword ptr [g_baseSel]
        mov      eax, dword ptr [ecx*4 + 0x34]
        cmp      eax, 0x10
        mov      dword ptr [g_walkCallback], eax
        jne      short L_1184
        mov      eax, 2
        mov      dword ptr [g_walkCallback], eax
    L_1184:
        cmp      eax, 0x11
        jne      short L_1193
        mov      eax, 7
        mov      dword ptr [g_walkCallback], eax
    L_1193:
        cmp      eax, esi
        jne      short L_11a8
        call     CallPauseConstStoreJmp_BootChainMaskAndDispatch_then_MStackBitLoopTripleCall
        cmp      dword ptr [g_framePauseFlag], esi
        jne      L_1336
    L_11a8:
        mov      edx, dword ptr [g_baseSel]
        mov      ecx, dword ptr [edx*4 + 0x74]
        lea      eax, [edx*4]
        mov      dword ptr [eax + 0x60], ecx
        mov      dword ptr [g_walkCallback], esi
        mov      dword ptr [eax + 0x5c], esi
        mov      edx, dword ptr [g_walkCallback]
        mov      dword ptr [eax + 0x74], edx
        mov      ecx, dword ptr [g_walkCallback]
        mov      dword ptr [eax + 0x4c], ecx
        mov      edx, dword ptr [g_fightGroupHead]
        mov      dword ptr [edx*4 + 0x44], esi
        mov      dword ptr [g_walkCallback], esi
        lea      eax, [edx*4]
        mov      dword ptr [eax + 0x78], esi
        mov      ecx, dword ptr [g_walkCallback]
        mov      dword ptr [eax + 0x80], ecx
        mov      edx, dword ptr [g_walkCallback]
        mov      dword ptr [eax + 0x60], edx
        mov      ecx, dword ptr [g_walkCallback]
        mov      dword ptr [eax + 0x68], ecx
        call     ScaledChainNegStore
        cmp      dword ptr [g_framePauseFlag], esi
        jne      L_1336
        mov      edx, dword ptr [g_fightGroupHead]
        mov      ecx, dword ptr [g_player1NodeIdx]
        mov      eax, dword ptr [g_dlNalt1]
        cmp      edx, ecx
        mov      dword ptr [g_walkCallback], eax
        je       short L_124a
        mov      eax, dword ptr [g_dlNalt2]
        mov      dword ptr [g_walkCallback], eax
    L_124a:
        cmp      eax, 0xa
        jne      short L_1260
        call     PendingMatch_PushSarCallBitToggle
        cmp      dword ptr [g_framePauseFlag], esi
        jne      L_1336
    L_1260:
        mov      eax, dword ptr [g_or]
        mov      dword ptr [g_walkCallback], eax
        and      eax, 0x2000
        mov      dword ptr [g_xformScratch94], eax
        jne      L_1336
        mov      eax, dword ptr [g_baseSel]
        mov      eax, dword ptr [eax*4 + 0x80]
        cmp      eax, 0x6666
        mov      dword ptr [g_walkCallback], eax
        jle      L_1336
        call     PoseChainInstallCluster
        cmp      dword ptr [g_framePauseFlag], esi
        jne      L_1336
        mov      ecx, dword ptr [g_baseSel]
        mov      eax, dword ptr [ecx*4 + 0x7c]
        cmp      eax, 3
        mov      dword ptr [g_walkCallback], eax
        jl       short L_12cb
        call     PushCallPauseScaledJmpInd
        cmp      dword ptr [g_framePauseFlag], esi
        jne      short L_1336
    L_12cb:
        mov      edx, dword ptr [g_baseSel]
        push     0x31
        push     OFFSET L_1340
        mov      dword ptr [edx*4 + 0x80], esi
        mov      eax, dword ptr [g_baseSel]
        mov      dword ptr [g_walkCallback], esi
        mov      dword ptr [eax*4 + 0x7c], esi
        call     StoreTwoCall
        mov      ecx, dword ptr [g_baseSel]
        mov      edx, dword ptr [g_currentNodeIdx]
        add      esp, 8
        mov      eax, dword ptr [ecx*4 + 0x3c]
        mov      dword ptr [g_xformEntityIdx], eax
        mov      dword ptr [edx*4 + 0x3c], eax
        mov      eax, dword ptr [g_baseSel]
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      eax, dword ptr [eax*4 + 0x38]
        mov      dword ptr [g_xformEntityIdx], eax
        mov      dword ptr [ecx*4 + 0x38], eax
    L_1336:
        pop      esi
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        /* === h2 (0x481340): wait+tail-jmp 0041f830 === */
    L_1340:
        mov      dword ptr [g_walkCallback], 0x2e
        call     ScaledLitLoadCall_ScaledChainCallPauseSetJmp_then_Wrapper_IterLoad_0048fd30_00480fe0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_135d
        jmp      CallSetPause
    L_135d:
        ret
    }
}


__declspec(naked) void Match_TeamOutcomeScreen(void)
{
    __asm {
        mov      eax, dword ptr [g_baseSel]
        push     ebx
        push     esi
        xor      ebx, ebx
        lea      esi, [eax*4]
        push     edi
        mov      eax, dword ptr [esi + 0x84]
        mov      dword ptr [esi + 0x84], ebx
        cmp      eax, 4
        ja       L_97f8
        mov      edi, 1
        jmp      dword ptr [eax*4 + L_9808_jmptbl]
        call     Test4StatesAny
        test     eax, eax
        jne      L_9454
        mov      eax, dword ptr [g_eventQueueChild]
        inc      eax
        cmp      eax, 0x3c
        mov      dword ptr [g_eventQueueChild], eax
        jge      L_942d
        mov      edi, 1
        mov      dword ptr [esi + 8], 0x4a93c0
        mov      dword ptr [esi + 0x84], edi
        mov      dword ptr [g_pendingNodeType], edi
        mov      dword ptr [g_framePauseFlag], edi
        pop      edi
        pop      esi
        pop      ebx
        ret      
    L_942d:
        mov      dword ptr [g_eventQueueChild], ebx
        jmp      L_9505
        call     Test4StatesAny
        test     eax, eax
        je       L_94ef
        mov      dword ptr [g_eventQueueWorkType], 0x32f
        call     Push16Call
    L_9454:
        push     8
        call     TableWalkBoundedCmp
        add      esp, 4
        push     6
        call     TableWalkBoundedCmp
        mov      eax, dword ptr [g_counter_005433c8]
        add      esp, 4
        lea      edx, [eax + eax*2]
        lea      eax, [edx*8 + g_dispatchTab62]
        push     eax
        mov      eax, dword ptr [g_counter_0054359c]
        lea      ecx, [eax + eax*2]
        lea      edx, [ecx*8 + g_audioBank2Base]
        push     edx
        call     AudioMode2BankSetup
        mov      dword ptr [esi + 8], 0x4a93c0
        mov      eax, dword ptr [g_baseSel]
        mov      ecx, 0x4a93c0
        add      esp, 8
        mov      dword ptr [eax*4 + 0x84], 3
        mov      eax, dword ptr [esi + 4]
        add      ecx, 0x3000000
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      edx, dword ptr [g_baseSel]
        mov      dword ptr [edx*4 + 0x84], ebx
        call     AudioInstallSelfStatePush
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        pop      ebx
        ret      
    L_94ef:
        mov      eax, dword ptr [g_eventQueueChild]
        inc      eax
        cmp      eax, 0x12c
        mov      dword ptr [g_eventQueueChild], eax
        jge      L_9454
    L_9505:
        call     DualListInit
        mov      ecx, dword ptr [g_counter_0054359c]
        mov      edx, dword ptr [g_counter_005433c8]
        add      edx, 0x12
        lea      eax, [ecx + 0xd]
        mov      cl, byte ptr [g_gtFightTickCounter]
        test     cl, 8
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [g_eventQueueCurrent], edx
        je       L_957e
        cmp      dword ptr [g_eventQueueChild], 0x11d
        jge      L_957e
        mov      ecx, dword ptr [g_baseSel]
        add      eax, ecx
        mov      ecx, 0x7d00000
        mov      eax, dword ptr [eax*4]
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4 + 0x58], ecx
        mov      edx, dword ptr [g_baseSel]
        mov      eax, dword ptr [g_eventQueueCurrent]
        add      eax, edx
        mov      eax, dword ptr [eax*4]
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4 + 0x58], ecx
    L_957e:
        mov      edi, 1
        mov      dword ptr [esi + 8], 0x4a93c0
        mov      dword ptr [esi + 0x84], 2
        mov      dword ptr [g_pendingNodeType], edi
        mov      dword ptr [g_framePauseFlag], edi
        pop      edi
        pop      esi
        pop      ebx
        ret      
        call     DualAddSar
        mov      eax, dword ptr [g_bootInitState]
        mov      ecx, dword ptr [g_walkCallback]
        cdq      
        and      edx, 3
        and      ecx, 3
        add      eax, edx
        add      ecx, 3
        sar      eax, 2
        cmp      eax, 4
        mov      dword ptr [g_walkCallback], ecx
        mov      dword ptr [g_phaseCounter], eax
        mov      dword ptr [g_stateCountdown], ecx
        jle      L_95e3
        mov      dword ptr [g_phaseCounter], 4
    L_95e3:
        call     TwoStageAudioInit
        pop      edi
        pop      esi
        pop      ebx
        ret      
        call     TripleCallByteCheck
        test     eax, eax
        je       L_97d7
        mov      dword ptr [g_eventQueueWorkType], 0x325
        call     Push16Call
        mov      dword ptr [g_eventQueueCurrent], 0x20
        mov      dword ptr [esi + 8], 0x4a93c0
        mov      ecx, dword ptr [g_baseSel]
        mov      edx, 0x4a93c0
        add      edx, 0x5000000
        mov      dword ptr [ecx*4 + 0x84], 5
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], edx
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      eax, dword ptr [g_baseSel]
        mov      dword ptr [eax*4 + 0x84], ebx
        call     InstallSelfPackedF80
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        pop      ebx
        ret      
        call     BootInitGuardedCallChain
        cmp      dword ptr [g_framePauseFlag], ebx
        jne      L_9803
        cmp      byte ptr [g_audioStateByte834], bl
        je       L_9692
        mov      byte ptr [g_audioStateByte834], bl
        jmp      L_96d1
    L_9692:
        call     FiveTableWalkInit
        cmp      dword ptr [g_framePauseFlag], ebx
        jne      L_9803
        push     8
        call     TableWalkBoundedCmp
        mov      ecx, 0x50b118
        add      esp, 4
        shr      ecx, 2
        mov      dword ptr [g_currentNodeIdx], ecx
        call     LoadGeoAsset_Default
        cmp      dword ptr [g_framePauseFlag], ebx
        jne      L_9803
        call     TripleCallSetCopy
    L_96d1:
        call     SpawnLeftRightAudioCrew
        call     DualListInit
        cmp      dword ptr [g_audioBankPick], ebx
        je       L_9454
        mov      dword ptr [g_eventQueueWorkType], 0x4a
        call     Push16Call
        mov      dword ptr [g_eventQueueWorkType], 0x4f
        call     Push16Call
        cmp      dword ptr [g_framePauseFlag], ebx
        jne      L_9803
        push     0x10000
        push     0xff970000
        push     ebx
        push     0x515980
        call     AudioInitArgs3
        add      esp, 0x10
        push     0x10000
        push     0xffb00000
        push     ebx
        push     0x51599c
        call     AudioInitArgs3
        add      esp, 0x10
        push     0x10000
        push     ebx
        push     ebx
        push     0x51599c
        call     AudioInitArgs3
        add      esp, 0x10
        push     0x10000
        push     0x550000
        push     ebx
        push     0x51599c
        call     AudioInitArgs3
        add      esp, 0x10
        push     0xff9c0000
        push     0x4d2748
        call     GuardedSetupCallTailJmp
        mov      eax, dword ptr [g_audioBankPick]
        add      esp, 8
        cmp      eax, edi
        push     0xffb50000
        jne      L_97a6
        push     0x4d2770
        call     GuardedSetupCallTailJmp
        add      esp, 8
        push     0x50000
        push     0x4d27a0
        jmp      L_97bd
    L_97a6:
        push     0x4d2790
        call     GuardedSetupCallTailJmp
        add      esp, 8
        push     0x50000
        push     0x4d2780
    L_97bd:
        call     GuardedSetupCallTailJmp
        add      esp, 8
        push     0x5a0000
        push     0x4d22e0
        call     GuardedSetupCallTailJmp
        add      esp, 8
    L_97d7:
        mov      dword ptr [esi + 8], 0x4a93c0
        mov      dword ptr [esi + 0x84], 4
        mov      dword ptr [g_pendingNodeType], edi
        mov      dword ptr [g_framePauseFlag], edi
        pop      edi
        pop      esi
        pop      ebx
        ret      
    L_97f8:
        mov      dword ptr [g_voicePoolTickFlag_005437f4], ebx
        call     PendingMatch_LeaPlus22StoreSelf
    L_9803:
        pop      edi
        pop      esi
        pop      ebx
        ret      
        nop      
    L_9808_jmptbl:
        /* 5-entry jump table */
        _emit    0x71
        _emit    0x96
        _emit    0x4a
        _emit    0x00
        _emit    0xf2
        _emit    0x93
        _emit    0x4a
        _emit    0x00
        _emit    0x38
        _emit    0x94
        _emit    0x4a
        _emit    0x00
        _emit    0xa4
        _emit    0x95
        _emit    0x4a
        _emit    0x00
        _emit    0xec
        _emit    0x95
        _emit    0x4a
        _emit    0x00
    }
}

__declspec(naked) void PendingMatch_MStackPush2RunCountdown_0040cd50(void)
{
    __asm {
        push     ebx
        push     ebp
        push     esi
        push     edi
        call     MStackPush2RunCountdown
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_d104
        call     MStackBracket7_DispatchAndChain
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_d104
        mov      eax, dword ptr [g_fightGroupHead]
        mov      esi, dword ptr [g_xformDirtyFlags]
        mov      ebx, 4
        mov      ecx, dword ptr [eax*4 + 0x1c]
        or       esi, ebx
        test     ecx, ecx
        mov      dword ptr [g_pendingNodeType], ecx
        mov      dword ptr [g_xformDirtyFlags], esi
        je       L_d0ff
        mov      edx, esi
        xor      edx, ebx
        test     ecx, ecx
        mov      dword ptr [g_xformDirtyFlags], edx
        je       L_d0ff
        mov      edx, dword ptr [g_eventQueueTotal]
        mov      dword ptr [g_eventQueueIdx], eax
        mov      eax, dword ptr [edx*4]
        inc      edx
        test     eax, eax
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [g_eventQueueTotal], edx
        je       L_d0ff
        mov      esi, 0x59
        mov      edi, 0x40d110
        mov      ebp, 5
    L_cdec:
        add      eax, ecx
        mov      dword ptr [g_eventQueueEnd], eax
        mov      eax, dword ptr [eax*4]
        test     eax, eax
        mov      dword ptr [g_walkCallback], eax
        jle      L_d0de
        mov      dword ptr [g_eventQueueEnd], eax
        mov      eax, 0x4d6600
        shr      eax, 2
        mov      dword ptr [g_walkCallback], eax
        call     PushSetXfmMaskCallPop
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_d104
        test     byte ptr [g_xformDirtyFlags], bl
        jne      L_d0ff
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      dword ptr [ecx*4 + 0x30], esi
        mov      eax, dword ptr [g_particleEmitterNode]
        mov      edx, dword ptr [g_fightGroupHead]
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [edx*4 + 0x3c], eax
        mov      eax, dword ptr [g_matrixStackTop]
        mov      ecx, dword ptr [g_pendingNodeType]
        inc      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], ecx
        mov      edx, dword ptr [g_eventQueueEnd]
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      eax, dword ptr [edx*4 + 0x28]
        mov      dword ptr [g_xformEntityIdx], eax
        mov      eax, dword ptr [eax*4 + 0x3c]
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x54], eax
        mov      edx, dword ptr [g_xformEntityIdx]
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      eax, dword ptr [edx*4 + 0x40]
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x58], eax
        mov      edx, dword ptr [g_xformEntityIdx]
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      eax, dword ptr [edx*4 + 0x44]
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x5c], eax
        mov      ecx, dword ptr [g_xformEntityIdx]
        mov      edx, dword ptr [g_eventQueueIdx]
        mov      eax, dword ptr [g_savedNode]
        add      ecx, 0xf
        add      edx, 0x15
        mov      dword ptr [g_xformEntityIdx], ecx
        mov      dword ptr [g_pendingNodeType], edx
        mov      dword ptr [g_currentNodeIdx], eax
        call     TripleSubVec3
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_d104
        mov      edx, dword ptr [g_fightGroupHead]
        mov      ecx, dword ptr [g_currentNodeIdx]
        add      edx, 0x1b
        mov      dword ptr [g_xformEntityIdx], ecx
        mov      dword ptr [g_walkCallback], 0x6666
        mov      dword ptr [g_currentNodeIdx], edx
        call     ThreeMul10Stores
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_d104
        mov      eax, dword ptr [g_matrixStackTop]
        mov      ecx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_pendingNodeType], ecx
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [g_walkCallback], 0x7ae
        call     StoreDoubleNegPauseSubStore
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_d104
        mov      edx, dword ptr [g_walkCallback]
        mov      eax, dword ptr [g_fightGroupHead]
        add      edx, 0xffffe8f6
        mov      dword ptr [eax*4 + 0x70], edx
        mov      dword ptr [g_walkCallback], 0xcccc
        call     StoreDoubleNegPauseSubStore
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_d104
        mov      edx, dword ptr [g_fightGroupHead]
        mov      ecx, dword ptr [g_walkCallback]
        mov      dword ptr [edx*4 + 0x80], ecx
        mov      dword ptr [g_walkCallback], 0x3333
        call     StoreDoubleNegPauseSubStore
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_d104
        mov      eax, dword ptr [g_fightGroupHead]
        mov      ecx, dword ptr [g_walkCallback]
        mov      dword ptr [eax*4 + 0x7c], ecx
        mov      edx, dword ptr [g_fightGroupHead]
        mov      eax, dword ptr [edx*4 + 0x18]
        mov      dword ptr [g_currentNodeIdx], eax
        mov      eax, dword ptr [eax*4 + 0x28]
        mov      dword ptr [g_walkCallback], edi
        mov      dword ptr [g_xformEntityIdx], eax
        mov      dword ptr [eax*4 + 0x10], edi
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      ecx, dword ptr [eax*4 + 0x20]
        or       ch, 0x40
        mov      dword ptr [eax*4 + 0x20], ecx
        mov      dword ptr [g_walkCallback], ebp
        call     CmpDivJmp
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_d104
        test     byte ptr [g_xformDirtyFlags], bl
        jne      L_d0ca
        mov      eax, 0x4d6a90
        shr      eax, 2
        mov      dword ptr [g_xformEntityIdx], eax
    L_d064:
        call     ScaledTripleCopy10
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_d104
        add      dword ptr [g_xformEntityIdx], 3
        call     ScaledTripleCopy4
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_d104
        mov      eax, dword ptr [g_xformEntityIdx]
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      edx, dword ptr [g_xformDirtyFlags]
        add      eax, 3
        mov      dword ptr [g_xformEntityIdx], eax
        mov      eax, dword ptr [ecx*4]
        or       edx, ebx
        mov      dword ptr [g_currentNodeIdx], eax
        test     eax, eax
        mov      dword ptr [g_xformDirtyFlags], edx
        je       L_d0ca
        mov      ecx, edx
        xor      ecx, ebx
        test     eax, eax
        mov      dword ptr [g_xformDirtyFlags], ecx
        jne      L_d064
    L_d0ca:
        call     MStackCall_MStackPush2ChainPrepend_004062f0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_d104
        mov      ecx, dword ptr [g_pendingNodeType]
    L_d0de:
        mov      edx, dword ptr [g_eventQueueTotal]
        mov      eax, dword ptr [edx*4]
        inc      edx
        test     eax, eax
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [g_eventQueueTotal], edx
        jne      L_cdec
    L_d0ff:
        call     MStackPop8
    L_d104:
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        ret      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        mov      eax, dword ptr [g_matrixStackTop]
        mov      ecx, dword ptr [g_fightGroupHead]
        inc      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], ecx
        call     ChainListVecAdd
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_d1c5
        call     ChainWalkPushPop
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_d1c5
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      dword ptr [g_walkCallback], 0x106
        mov      eax, dword ptr [ecx*4 + 0x70]
        add      eax, 0x106
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x70], eax
        js       L_d1ad
        mov      edx, dword ptr [g_fightGroupHead]
        mov      eax, dword ptr [edx*4 + 0x58]
        test     eax, eax
        mov      dword ptr [g_eventQueueCurrent], eax
        jl       L_d1ad
        mov      eax, dword ptr [g_walkCallback]
        push     eax
        push     0xffff6667
        call     Mul10Tail
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      dword ptr [g_walkCallback], eax
        add      esp, 8
        mov      dword ptr [ecx*4 + 0x70], eax
    L_d1ad:
        mov      eax, dword ptr [g_matrixStackTop]
        mov      edx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_fightGroupHead], edx
        mov      dword ptr [g_matrixStackTop], eax
    L_d1c5:
        ret      
    }
}


#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void PendingMatch_MStackBracket3_ChainSwapAdvance(void)

{
  func_0x0041d560();
  if ((g_framePauseFlag == 0) && ((g_xformDirtyFlags & 4) == 0)) {
    g_walkCallback = MK4_NODE_AT(uint, g_cj_0054205c, 0x34) | 4;
    MK4_NODE_AT(uint, g_cj_0054205c, 0x34) = g_walkCallback;
    g_xformDirtyFlags = g_xformDirtyFlags | 4;
    g_cj_0054205c = g_currentNodeIdx;
    if (g_currentNodeIdx != 0) {
      g_xformDirtyFlags = g_xformDirtyFlags ^ 4;
    }
  }
  return;
}
#else
__declspec(naked) void PendingMatch_MStackBracket3_ChainSwapAdvance(void)
{
    __asm {
        call     MStackBracket3_ChainSwapAdvance
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_d7cc
        mov      al, byte ptr [g_xformDirtyFlags]
        mov      edx, 4
        test     al, dl
        jne      L_d7cc
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      eax, dword ptr [ecx*4 + 0x34]
        or       eax, edx
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x34], eax
        mov      ecx, dword ptr [g_xformDirtyFlags]
        mov      eax, dword ptr [g_currentNodeIdx]
        or       ecx, edx
        mov      dword ptr [g_fightGroupHead], eax
        test     eax, eax
        mov      dword ptr [g_xformDirtyFlags], ecx
        je       L_d7cc
        mov      eax, ecx
        xor      eax, edx
        mov      dword ptr [g_xformDirtyFlags], eax
    L_d7cc:
        ret      
        nop      
        nop      
        nop      
        mov      eax, dword ptr [g_baseSel]
        push     ebx
        push     esi
        push     edi
        lea      esi, [eax*4]
        xor      edi, edi
        mov      eax, dword ptr [esi + 0x84]
        mov      dword ptr [esi + 0x84], edi
        sub      eax, edi
        je       L_d8dc
        dec      eax
        je       L_d850
        dec      eax
        mov      dword ptr [g_walkCallback], edi
        je       L_d816
        call     FlagThunk4EntryDispatcher
        cmp      dword ptr [g_framePauseFlag], edi
        je       L_d894
        pop      edi
        pop      esi
        pop      ebx
        ret      
    L_d816:
        call     FlagThunk4EntryDispatcher
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_d924
        mov      dword ptr [esi + 8], 0x41d7d0
        mov      dword ptr [esi + 0x84], 3
        mov      dword ptr [g_pendingNodeType], 0xa
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        pop      ebx
        ret      
    L_d850:
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      edx, 0x4d89d0
        sar      edx, 2
        push     0xc0
        push     0x49db40
        mov      dword ptr [g_eventQueueEnd], ecx
        mov      dword ptr [g_eventQueueIdx], edx
        mov      dword ptr [g_eventQueueNotMask], 0xc1
        call     StoreTwoCall
        mov      al, byte ptr [g_xformDirtyFlags]
        mov      ebx, 1
        add      esp, 8
        test     al, bl
        je       L_d89d
    L_d894:
        call     CallSetPause
        pop      edi
        pop      esi
        pop      ebx
        ret      
    L_d89d:
        call     StackPushAdd15CallPop
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_d924
        call     ZeroThreeFields_0040a8b0
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_d924
        mov      dword ptr [esi + 8], 0x41d7d0
        mov      dword ptr [esi + 0x84], 2
        mov      dword ptr [g_pendingNodeType], 0xa
        mov      dword ptr [g_framePauseFlag], ebx
        pop      edi
        pop      esi
        pop      ebx
        ret      
    L_d8dc:
        mov      dword ptr [g_walkCallback], edi
        call     FlagThunk4EntryDispatcher
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_d924
        mov      dword ptr [g_walkCallback], 8
        call     FlagThunk4EntryDispatcher
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_d924
        mov      ebx, 1
        mov      dword ptr [esi + 8], 0x41d7d0
        mov      dword ptr [esi + 0x84], ebx
        mov      dword ptr [g_pendingNodeType], ebx
        mov      dword ptr [g_framePauseFlag], ebx
    L_d924:
        pop      edi
        pop      esi
        pop      ebx
        ret      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        mov      eax, dword ptr [g_fightGroupHead]
        mov      ecx, dword ptr [eax*4 + 0x18]
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      eax, dword ptr [ecx*4 + 0x20]
        or       al, 0x40
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x20], eax
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      eax, dword ptr [ecx*4 + 0x28]
        mov      dword ptr [g_xformEntityIdx], eax
        mov      ecx, dword ptr [eax*4]
        or       ecx, 0xa
        mov      dword ptr [eax*4], ecx
        mov      edx, dword ptr [g_pendingMatchVar]
        mov      dword ptr [g_walkCallback], edx
        call     AudioMixerStep
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_da81
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      eax, dword ptr [g_walkCallback]
        mov      dword ptr [ecx*4 + 0x3c], eax
        mov      edx, dword ptr [g_pendingMatchVar]
        mov      dword ptr [g_walkCallback], edx
        call     AudioMixerStep
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_da81
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      eax, dword ptr [g_walkCallback]
        mov      dword ptr [ecx*4 + 0x40], eax
        mov      edx, dword ptr [g_pendingMatchVar]
        mov      dword ptr [g_walkCallback], edx
        call     AudioMixerStep
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_da81
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      eax, dword ptr [g_walkCallback]
        mov      dword ptr [ecx*4 + 0x44], eax
        mov      dword ptr [g_walkCallback], 0x8000
        call     AudioMixerStep
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_da81
        mov      edx, dword ptr [g_walkCallback]
        mov      eax, dword ptr [g_xformEntityIdx]
        add      edx, 0xb333
        mov      dword ptr [eax*4 + 0x48], edx
        mov      dword ptr [g_walkCallback], 0x6666
        call     StoreDoubleNegPauseSubStore
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_da81
        mov      edx, dword ptr [g_xformEntityIdx]
        mov      ecx, dword ptr [g_walkCallback]
        mov      eax, 0x49d200
        mov      dword ptr [edx*4 + 0x2c], ecx
        mov      ecx, dword ptr [g_xformEntityIdx]
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x10], eax
        jmp      CallSetPause
    L_da81:
        ret      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        mov      eax, dword ptr [g_baseSel]
        push     esi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        test     eax, eax
        je       L_dac8
        mov      eax, dword ptr [g_eventQueueNotMask]
        dec      eax
        test     eax, eax
        mov      dword ptr [g_eventQueueNotMask], eax
        jg       L_db34
        call     GuardedSeq_MStackCall_then_CallSetPause_00471670
        pop      esi
        ret      
    L_dac8:
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      ecx, dword ptr [ecx*4 + 0x18]
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      eax, dword ptr [ecx*4 + 0x20]
        or       al, 0x40
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x20], eax
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      eax, dword ptr [edx*4 + 0x28]
        mov      dword ptr [g_xformEntityIdx], eax
        mov      ecx, dword ptr [eax*4]
        or       ecx, 8
        mov      dword ptr [eax*4], ecx
        mov      ecx, dword ptr [g_xformEntityIdx]
        mov      eax, 0x5999
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x48], eax
        mov      dword ptr [g_eventQueueNotMask], 0x1e
    L_db34:
        call     ScaledChainOr8
        call     ChainListVecAdd
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_db63
        mov      eax, 1
        mov      dword ptr [esi + 8], 0x41da90
        mov      dword ptr [esi + 0x84], eax
        mov      dword ptr [g_pendingNodeType], eax
        mov      dword ptr [g_framePauseFlag], eax
    L_db63:
        pop      esi
        ret      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        call     MStackPush8
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_db90
        mov      eax, 0x4d8a18
        sar      eax, 2
        mov      dword ptr [g_eventQueueTotal], eax
        jmp      PendingMatch_0041dc00
    L_db90:
        ret      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        call     MStackPush8
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_dbc0
        mov      eax, 0x4d8c80
        sar      eax, 2
        mov      dword ptr [g_eventQueueTotal], eax
        jmp      PendingMatch_0041dc00
    L_dbc0:
        ret      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        call     MStackPush8
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_dbf0
        mov      eax, 0x4d8d88
        sar      eax, 2
        mov      dword ptr [g_eventQueueTotal], eax
        jmp      PendingMatch_0041dc00
    L_dbf0:
        ret      
    }
}
#endif

__declspec(naked) void Screen_BestKombatants(void)
{
    __asm {
        push     ecx
        mov      eax, dword ptr [g_baseSel]
        push     ebx
        push     ebp
        push     esi
        lea      ecx, [eax*4]
        xor      esi, esi
        push     edi
        mov      dword ptr [esp + 0x10], ecx
        mov      eax, dword ptr [ecx + 0x84]
        mov      dword ptr [ecx + 0x84], esi
        sub      eax, esi
        mov      edi, 1
        mov      ebp, 0xa
        je       L_36bd
        dec      eax
        je       L_3a7b
        push     9
        call     TableWalkBoundedCmp
        add      esp, 4
        call     StackPopDispatchTagged
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        pop      ecx
        ret      
    L_36bd:
        call     BootInitGuardedCallChain
        cmp      dword ptr [g_framePauseFlag], esi
        jne      L_3b07
        push     esi
        push     0x4a2180
        mov      dword ptr [g_phaseIdx], 9
        call     StoreTwoCall
        add      esp, 8
        call     BootMultiAssetLoadStateInit
        cmp      dword ptr [g_framePauseFlag], esi
        jne      L_3b07
        call     NestedLoopDispatch
        cmp      dword ptr [g_framePauseFlag], esi
        jne      L_3b07
        call     AllocSlotPushTripleGlobals
        cmp      dword ptr [g_framePauseFlag], esi
        jne      L_3b07
        mov      ecx, 0x4d5388
        mov      ebx, 4
        shr      ecx, 2
        mov      dword ptr [g_xformEntityIdx], ecx
        mov      dword ptr [g_walkCallback], ebp
        mov      dword ptr [g_eventQueueCurrent], ebx
        mov      dword ptr [g_chainAccumCur], esi
        mov      dword ptr [g_eventQueueNotMask], 0xff9c0000
        call     Push70CallScaleArith
        cmp      dword ptr [g_framePauseFlag], esi
        jne      L_3b07
        call     MStackPop4Rewrite
        cmp      dword ptr [g_framePauseFlag], esi
        jne      L_3b07
        test     byte ptr [g_xformDirtyFlags], bl
        jne      L_3a7b
        mov      edx, dword ptr [g_baseSel]
        mov      dword ptr [g_eventQueueChild], 0x18000
        mov      dword ptr [g_walkCallback], edi
        mov      eax, 0x53a53c
        mov      dword ptr [edx*4 + 0x30], edi
        mov      ecx, dword ptr [g_baseSel]
        shr      eax, 2
        mov      dword ptr [g_eventQueueNotMask], 0xff830000
        mov      dword ptr [g_pendingNodeType], eax
        mov      dword ptr [g_eventQueueCurrent], ebx
        mov      dword ptr [g_eventQueueWorkType], ebp
        mov      dword ptr [g_chainAccumCur], 0xff380000
        mov      dword ptr [g_currentNodeFlags], edi
        mov      edx, dword ptr [ecx*4 + 0x30]
        mov      dword ptr [g_walkCallback], edx
        call     DispatcherComplex181_Push70CallScaleArith2
        cmp      dword ptr [g_framePauseFlag], esi
        jne      L_3b07
    L_37ea:
        test     byte ptr [g_xformDirtyFlags], bl
        jne      L_3a7b
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      eax, dword ptr [g_eventQueueChild]
        mov      esi, 0x535d70
        shr      esi, 2
        mov      dword ptr [ecx*4 + 0x5c], eax
        mov      eax, esi
        mov      dword ptr [g_xformEntityIdx], eax
        mov      dword ptr [eax*4], 0x2e
        mov      eax, dword ptr [g_xformEntityIdx]
        inc      eax
        mov      dword ptr [g_walkCallback], 0x20
        mov      dword ptr [g_xformEntityIdx], eax
        mov      dword ptr [g_xformLoopCounter], edi
    L_383d:
        mov      eax, dword ptr [g_xformEntityIdx]
        mov      edx, dword ptr [g_walkCallback]
        mov      dword ptr [eax*4], edx
        mov      ecx, dword ptr [g_xformEntityIdx]
        mov      eax, dword ptr [g_xformLoopCounter]
        inc      ecx
        dec      eax
        mov      dword ptr [g_xformEntityIdx], ecx
        mov      dword ptr [g_xformLoopCounter], eax
        jns      L_383d
        mov      dword ptr [g_xformLoopCounter], 2
    L_3873:
        call     ScaledMaskByte
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_3b07
        mov      edx, dword ptr [g_pendingNodeType]
        mov      ecx, dword ptr [g_xformEntityIdx]
        inc      edx
        mov      dword ptr [g_pendingNodeType], edx
        mov      edx, dword ptr [g_walkCallback]
        mov      dword ptr [ecx*4], edx
        mov      ecx, dword ptr [g_xformEntityIdx]
        mov      eax, dword ptr [g_xformLoopCounter]
        inc      ecx
        dec      eax
        mov      dword ptr [g_xformEntityIdx], ecx
        mov      dword ptr [g_xformLoopCounter], eax
        jns      L_3873
        mov      eax, ecx
        mov      ecx, 0x538140
        mov      dword ptr [g_walkCallback], 0
        shr      ecx, 2
        mov      dword ptr [eax*4], 0
        mov      dword ptr [g_currentNodeIdx], esi
        mov      dword ptr [g_xformEntityIdx], ecx
        call     CopyByteUntilNull
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_3b07
        mov      esi, 0xff380000
        mov      dword ptr [g_walkCallback], ebp
        mov      dword ptr [g_eventQueueCurrent], ebx
        mov      dword ptr [g_chainAccumCur], esi
        call     StreamChainStringInstall
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_3b07
        test     byte ptr [g_xformDirtyFlags], bl
        jne      L_3a7b
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      edx, dword ptr [g_eventQueueChild]
        mov      dword ptr [eax*4 + 0x5c], edx
        call     ScaledMaskByte
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_3b07
        mov      ecx, dword ptr [g_pendingNodeType]
        mov      dword ptr [g_eventQueueCurrent], ebx
        inc      ecx
        mov      dword ptr [g_eventQueueWorkType], ebp
        mov      dword ptr [g_pendingNodeType], ecx
        mov      dword ptr [g_chainAccumCur], 0xffe20000
        mov      dword ptr [g_currentNodeFlags], edi
        call     DispatcherComplex181_Push70CallScaleArith2
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_3b07
        test     byte ptr [g_xformDirtyFlags], bl
        jne      L_3a7b
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      ecx, dword ptr [g_eventQueueChild]
        mov      eax, 0x4d5398
        shr      eax, 2
        mov      dword ptr [edx*4 + 0x5c], ecx
        mov      dword ptr [g_xformEntityIdx], eax
        mov      dword ptr [g_walkCallback], ebp
        mov      dword ptr [g_eventQueueCurrent], ebx
        mov      dword ptr [g_chainAccumCur], 0
        call     StreamChainStringInstall
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_3b07
        test     byte ptr [g_xformDirtyFlags], bl
        jne      L_3a7b
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      ecx, dword ptr [g_eventQueueChild]
        mov      dword ptr [edx*4 + 0x5c], ecx
        mov      eax, dword ptr [g_eventQueueNotMask]
        mov      ecx, dword ptr [g_baseSel]
        add      eax, 0x150000
        mov      dword ptr [g_eventQueueNotMask], eax
        mov      eax, dword ptr [ecx*4 + 0x30]
        inc      eax
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x30], eax
        cmp      dword ptr [g_walkCallback], 0xf
        ja       L_3ae6
        mov      eax, dword ptr [g_baseSel]
        mov      dword ptr [g_eventQueueCurrent], ebx
        mov      dword ptr [g_eventQueueWorkType], ebp
        mov      dword ptr [g_chainAccumCur], esi
        mov      dword ptr [g_currentNodeFlags], edi
        mov      ecx, dword ptr [eax*4 + 0x30]
        mov      dword ptr [g_walkCallback], ecx
        call     DispatcherComplex181_Push70CallScaleArith2
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        je       L_37ea
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        pop      ecx
        ret      
    L_3a7b:
        mov      ecx, dword ptr [esp + 0x10]
        mov      dword ptr [g_eventQueueCurrent], ebp
        mov      dword ptr [ecx + 8], 0x403670
        mov      edx, dword ptr [g_baseSel]
        mov      dword ptr [edx*4 + 0x84], 2
        mov      eax, dword ptr [ecx + 4]
        mov      edx, 0x403670
        mov      dword ptr [g_currentNodeIdx], eax
        add      edx, 0x2000000
        mov      dword ptr [eax*4], edx
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [ecx + 4], eax
        mov      eax, dword ptr [g_baseSel]
        mov      dword ptr [eax*4 + 0x84], 0
        call     InstallSelfPackedF80
        mov      dword ptr [g_framePauseFlag], edi
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        pop      ecx
        ret      
    L_3ae6:
        mov      eax, dword ptr [esp + 0x10]
        mov      dword ptr [eax + 8], 0x403670
        mov      dword ptr [eax + 0x84], edi
        mov      dword ptr [g_pendingNodeType], 0x104
        mov      dword ptr [g_framePauseFlag], edi
    L_3b07:
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        pop      ecx
        ret      
    }
}


#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void PendingMatch_ChainWalkPushPop_00411890(void)

{
  if (g_gameMode == 0) {
    g_matrixStackTop = g_matrixStackTop + 1;
    *(int *)((int)g_matrixStackTop * 4) = g_cj_0054205c;
    g_matrixStackTop = g_matrixStackTop + 1;
    *(int *)((int)g_matrixStackTop * 4) = g_chainAccumCur;
    ChainWalkPushPop();
    if (g_framePauseFlag == 0) {
      g_walkCallback = MK4_NODE_AT(int, g_cj_0054205c, 0x50);
      if (g_walkCallback < 0xcccd) {
        MStackCall_MStackPush2ChainLLInsert();
        if (g_framePauseFlag != 0) {
          return;
        }
        g_currentNodeIdx = 0;
      }
      else {
        g_chainAccumCur = MK4_NODE_AT(int, g_cj_0054205c, 0x70) + 0xe5;
        MK4_NODE_AT(int, g_cj_0054205c, 0x70) = g_chainAccumCur;
        g_walkCallback = PendingMatch_StoreTailJmpSigned(MK4_NODE_AT(undefined4, g_cj_0054205c, 0x6c),
                                    MK4_NODE_AT(undefined4, g_cj_0054205c, 0x74));
        g_eventQueueWorkType = g_walkCallback;
        Atan2QuadrantLookup();
        if (g_framePauseFlag != 0) {
          return;
        }
        g_walkCallback = g_walkCallback + g_pendingMatchVar2;
        BootMod6487eClampAndChainMul10();
        if (g_framePauseFlag != 0) {
          return;
        }
        MK4_NODE_AT(int, g_cj_0054205c, 0x60) = g_walkCallback;
        g_walkCallback = MK4_NODE_AT(int, g_cj_0054205c, 0x58);
        if (-1 < g_walkCallback) {
          ZeroThreeFields6c();
          if (g_framePauseFlag != 0) {
            return;
          }
          g_walkCallback = 0;
          MK4_NODE_AT(undefined4, g_cj_0054205c, 0x58) = 0;
          MK4_NODE_AT(int, g_cj_0054205c, 0x60) = g_walkCallback;
          g_walkCallback = 0x1356bb;
          ScaledStoreThree_00409260();
          if (g_framePauseFlag != 0) {
            return;
          }
          g_walkCallback = 0;
          MK4_NODE_AT(undefined4, g_eventQueuePending, 0x10) = 0;
        }
      }
      g_chainAccumCur = *(undefined4 *)((int)g_matrixStackTop * 4);
      g_cj_0054205c = *(int *)((int)(g_matrixStackTop + -1) * 4);
      g_matrixStackTop = g_matrixStackTop + -2;
    }
  }
  return;
}
#else
__declspec(naked) void PendingMatch_ChainWalkPushPop_00411890(void)
{
    __asm {
        mov      eax, dword ptr [g_gameMode]
        push     esi
        xor      esi, esi
        cmp      eax, esi
        jne      L_1a48
        mov      eax, dword ptr [g_matrixStackTop]
        mov      ecx, dword ptr [g_fightGroupHead]
        inc      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_matrixStackTop]
        mov      edx, dword ptr [g_chainAccumCur]
        inc      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], edx
        call     ChainWalkPushPop
        cmp      dword ptr [g_framePauseFlag], esi
        jne      L_1a48
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      eax, dword ptr [ecx*4 + 0x50]
        cmp      eax, 0xcccc
        mov      dword ptr [g_walkCallback], eax
        jle      L_1a0a
        mov      dword ptr [g_chainAccumCur], 0xe5
        mov      eax, dword ptr [ecx*4 + 0x70]
        add      eax, 0xe5
        mov      dword ptr [g_chainAccumCur], eax
        mov      dword ptr [ecx*4 + 0x70], eax
        mov      eax, dword ptr [g_fightGroupHead]
        mov      ecx, dword ptr [eax*4 + 0x74]
        mov      edx, dword ptr [eax*4 + 0x6c]
        push     ecx
        push     edx
        call     PendingMatch_StoreTailJmpSigned
        add      esp, 8
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [g_eventQueueWorkType], eax
        call     Atan2QuadrantLookup
        cmp      dword ptr [g_framePauseFlag], esi
        jne      L_1a48
        mov      eax, dword ptr [g_pendingMatchVar2]
        mov      ecx, dword ptr [g_walkCallback]
        add      ecx, eax
        mov      dword ptr [g_walkCallback], ecx
        call     BootMod6487eClampAndChainMul10
        cmp      dword ptr [g_framePauseFlag], esi
        jne      L_1a48
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      edx, dword ptr [g_walkCallback]
        mov      dword ptr [ecx*4 + 0x60], edx
        mov      eax, dword ptr [g_fightGroupHead]
        mov      eax, dword ptr [eax*4 + 0x58]
        cmp      eax, esi
        mov      dword ptr [g_walkCallback], eax
        jl       L_1a1d
        call     ZeroThreeFields6c
        cmp      dword ptr [g_framePauseFlag], esi
        jne      L_1a48
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      dword ptr [g_walkCallback], esi
        mov      dword ptr [ecx*4 + 0x58], esi
        mov      eax, dword ptr [g_fightGroupHead]
        mov      edx, dword ptr [g_walkCallback]
        mov      ecx, 0x4d5aec
        shr      ecx, 2
        mov      dword ptr [eax*4 + 0x60], edx
        mov      dword ptr [g_walkCallback], ecx
        call     ScaledStoreThree_00409260
        cmp      dword ptr [g_framePauseFlag], esi
        jne      L_1a48
        mov      edx, dword ptr [g_xformEntityIdx]
        mov      dword ptr [g_walkCallback], esi
        mov      dword ptr [edx*4 + 0x10], esi
        jmp      L_1a1d
    L_1a0a:
        call     MStackCall_MStackPush2ChainLLInsert
        cmp      dword ptr [g_framePauseFlag], esi
        jne      L_1a48
        mov      dword ptr [g_currentNodeIdx], esi
    L_1a1d:
        mov      eax, dword ptr [g_matrixStackTop]
        mov      ecx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_chainAccumCur], ecx
        mov      dword ptr [g_matrixStackTop], eax
        mov      edx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_fightGroupHead], edx
        mov      dword ptr [g_matrixStackTop], eax
    L_1a48:
        pop      esi
        ret      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        push     ecx
        mov      al, byte ptr [g_bootGatedByte360c]
        push     ebx
        push     ebp
        push     esi
        test     al, al
        push     edi
        je       L_1d74
        call     MStackPush7
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1d74
        mov      dword ptr [g_eventQueueIdx], 4
        mov      dword ptr [g_walkCallback], 0xd999
        call     ZeroAndDirty4
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1d74
        test     byte ptr [g_xformDirtyFlags], 4
        jne      L_1aad
        mov      dword ptr [g_eventQueueIdx], 2
    L_1aad:
        mov      eax, dword ptr [g_eventQueueSeed]
        mov      dword ptr [g_eventQueueTotal], eax
        mov      eax, 0x4d5ad8
        shr      eax, 2
        mov      dword ptr [esp + 0x10], eax
        mov      dword ptr [g_walkCallback], eax
        call     PushSetXfmMaskCallPop
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1d74
        mov      ebx, 0x1999
        mov      ebp, 0x6666
        mov      edi, 0x411890
    L_1ae9:
        test     byte ptr [g_xformDirtyFlags], 4
        jne      L_1d6f
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      dword ptr [ecx*4 + 0x30], 0xc2
        mov      eax, dword ptr [g_eventQueueSeed]
        mov      edx, dword ptr [g_fightGroupHead]
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [edx*4 + 0x3c], eax
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      eax, dword ptr [ecx*4 + 0x34]
        or       ah, 0x40
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x34], eax
        call     ScaledTripleCopy54
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1d74
        mov      ecx, dword ptr [g_eventQueueEnd]
        mov      eax, dword ptr [g_fightGroupHead]
        mov      edx, dword ptr [ecx*4 + 0x58]
        lea      esi, [eax*4]
        sub      edx, ebx
        mov      dword ptr [esi + 0x58], edx
        mov      dword ptr [g_walkCallback], 0x51e
        call     AudioMixerStep
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1d74
        mov      eax, dword ptr [g_walkCallback]
        sub      eax, ebx
        mov      dword ptr [esi + 0x70], eax
        mov      dword ptr [g_walkCallback], ebp
        call     StoreDoubleNegPauseSubStore
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1d74
        mov      eax, dword ptr [g_eventQueueTotal]
        mov      edx, dword ptr [g_walkCallback]
        mov      ecx, dword ptr [eax*4 + 0x54]
        mov      dword ptr [g_walkCallback], ebp
        add      ecx, edx
        mov      dword ptr [g_eventQueueNotMask], ecx
        call     StoreDoubleNegPauseSubStore
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1d74
        mov      edx, dword ptr [g_eventQueueTotal]
        mov      eax, dword ptr [g_walkCallback]
        add      eax, dword ptr [edx*4 + 0x5c]
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [g_eventQueueChild], eax
        call     QuadMul10TailFpuChain
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1d74
        mov      dword ptr [g_walkCallback], ebx
        call     AudioMixerStep
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1d74
        mov      eax, dword ptr [g_walkCallback]
        mov      ecx, dword ptr [g_eventQueueNotMask]
        add      eax, 0x147a
        push     ecx
        push     eax
        mov      dword ptr [g_walkCallback], eax
        call     Mul10Tail
        mov      edx, dword ptr [g_eventQueueChild]
        add      esp, 8
        mov      dword ptr [g_eventQueueNotMask], eax
        mov      eax, dword ptr [g_walkCallback]
        push     edx
        push     eax
        call     Mul10Tail
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      edx, dword ptr [g_eventQueueNotMask]
        mov      dword ptr [g_eventQueueChild], eax
        add      esp, 8
        mov      dword ptr [ecx*4 + 0x6c], edx
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      eax, dword ptr [g_eventQueueChild]
        mov      dword ptr [ecx*4 + 0x74], eax
        mov      edx, dword ptr [g_eventQueueNotMask]
        mov      eax, dword ptr [g_eventQueueChild]
        mov      dword ptr [g_eventQueueWorkType], edx
        mov      dword ptr [g_chainAccumCur], eax
        call     Atan2QuadrantLookup
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1d74
        mov      ecx, dword ptr [g_pendingMatchVar2]
        mov      edx, dword ptr [g_walkCallback]
        sub      edx, ecx
        mov      dword ptr [g_walkCallback], edx
        call     BootMod6487eClampAndChainMul10
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1d74
        mov      edx, dword ptr [g_fightGroupHead]
        mov      eax, dword ptr [g_walkCallback]
        mov      dword ptr [edx*4 + 0x64], eax
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      eax, dword ptr [ecx*4 + 0x18]
        mov      dword ptr [g_currentNodeIdx], eax
        mov      ecx, dword ptr [eax*4 + 0x20]
        and      ch, 0xf9
        mov      dword ptr [eax*4 + 0x20], ecx
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      eax, dword ptr [edx*4 + 0x28]
        mov      dword ptr [g_walkCallback], edi
        mov      dword ptr [g_xformEntityIdx], eax
        mov      dword ptr [eax*4 + 0x10], edi
        call     PendingMatch_ChainWalkPushPop_00411890
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1d74
        call     MStackCall_MStackPush2ChainPrepend_004062f0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1d74
        mov      eax, dword ptr [g_eventQueueIdx]
        dec      eax
        mov      dword ptr [g_eventQueueIdx], eax
        js       L_1d6f
        mov      eax, dword ptr [esp + 0x10]
        mov      dword ptr [g_walkCallback], eax
        call     PushSetXfmMaskCallPop
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        je       L_1ae9
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        pop      ecx
        ret      
    L_1d6f:
        call     MStackPop7
    L_1d74:
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        pop      ecx
        ret      
    }
}
#endif


#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void PendingMatch_ChainWalkPushPop_0040dbb0(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = g_currentNodeIdx * 4;
  iVar1 = g_cj_0054205c * 4;
  *(undefined4 *)(iVar1 + 0x54) = *(undefined4 *)(iVar2 + 0x54);
  *(undefined4 *)(iVar1 + 0x58) = *(undefined4 *)(iVar2 + 0x58);
  g_walkCallback = *(undefined4 *)(iVar2 + 0x5c);
  *(undefined4 *)(iVar1 + 0x5c) = g_walkCallback;
  return;
}
#else
__declspec(naked) void PendingMatch_ChainWalkPushPop_0040dbb0(void)
{
    __asm {
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      eax, dword ptr [g_fightGroupHead]
        shl      ecx, 2
        shl      eax, 2
        mov      edx, dword ptr [ecx + 0x54]
        mov      dword ptr [g_walkCallback], edx
        mov      dword ptr [eax + 0x54], edx
        mov      edx, dword ptr [ecx + 0x58]
        mov      dword ptr [g_walkCallback], edx
        mov      dword ptr [eax + 0x58], edx
        mov      ecx, dword ptr [ecx + 0x5c]
        mov      dword ptr [g_walkCallback], ecx
        mov      dword ptr [eax + 0x5c], ecx
        ret      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        mov      eax, dword ptr [g_gameMode]
        test     eax, eax
        jne      L_dce1
        mov      eax, dword ptr [g_matrixStackTop]
        mov      ecx, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_matrixStackTop]
        mov      edx, dword ptr [g_fightGroupHead]
        inc      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], edx
        call     ChainWalkPushPop
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_dce1
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      dword ptr [g_walkCallback], 0x20c
        mov      eax, dword ptr [ecx*4 + 0x80]
        add      eax, 0x20c
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x80], eax
        mov      ecx, dword ptr [g_xformEntityIdx]
        mov      eax, dword ptr [ecx*4 + 0x14]
        sub      eax, 9
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x14], eax
        call     ChainListVecAdd
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_dce1
        call     ChainWalkPushPop
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_dce1
        mov      eax, dword ptr [g_xformEntityIdx]
        mov      ecx, dword ptr [eax*4 + 0x18]
        mov      dword ptr [g_currentNodeIdx], ecx
        call     PendingMatch_ChainWalkPushPop_0040dbb0
        mov      eax, dword ptr [g_matrixStackTop]
        mov      edx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_fightGroupHead], edx
        mov      dword ptr [g_matrixStackTop], eax
        mov      ecx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      dword ptr [g_matrixStackTop], eax
    L_dce1:
        ret      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        mov      eax, dword ptr [g_gameMode]
        test     eax, eax
        jne      L_dda7
        mov      eax, dword ptr [g_matrixStackTop]
        mov      ecx, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_matrixStackTop]
        mov      edx, dword ptr [g_fightGroupHead]
        inc      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], edx
        mov      ecx, dword ptr [g_xformEntityIdx]
        mov      eax, dword ptr [ecx*4 + 0x14]
        sub      eax, 0x10
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x14], eax
        call     ChainListVecAdd
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_dda7
        call     ChainWalkPushPop
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_dda7
        mov      eax, dword ptr [g_xformEntityIdx]
        mov      ecx, dword ptr [eax*4 + 0x18]
        mov      dword ptr [g_currentNodeIdx], ecx
        call     PendingMatch_ChainWalkPushPop_0040dbb0
        mov      eax, dword ptr [g_matrixStackTop]
        mov      edx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_fightGroupHead], edx
        mov      dword ptr [g_matrixStackTop], eax
        mov      ecx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      dword ptr [g_matrixStackTop], eax
    L_dda7:
        ret      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        mov      dword ptr [g_walkCallback], 0x51e
        call     StoreDoubleNegPauseSubStore
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_de4d
        mov      eax, dword ptr [g_walkCallback]
        mov      ecx, dword ptr [g_fightGroupHead]
        sub      eax, 0x2666
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x70], eax
        mov      edx, dword ptr [g_fightGroupHead]
        mov      eax, dword ptr [edx*4 + 0x18]
        mov      dword ptr [g_walkCallback], 0x6487e
        mov      dword ptr [g_currentNodeIdx], eax
        call     AudioMixerStep
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_de4d
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      edx, dword ptr [g_walkCallback]
        mov      dword ptr [ecx*4 + 0x44], edx
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      ecx, 0x40de50
        mov      eax, dword ptr [eax*4 + 0x28]
        mov      dword ptr [g_walkCallback], ecx
        mov      dword ptr [g_xformEntityIdx], eax
        mov      dword ptr [eax*4 + 0x10], ecx
        jmp      CallSetPause
    L_de4d:
        ret      
        nop      
        nop      
        mov      eax, dword ptr [g_gameMode]
        test     eax, eax
        jne      L_df84
        mov      eax, dword ptr [g_matrixStackTop]
        mov      ecx, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_matrixStackTop]
        mov      edx, dword ptr [g_fightGroupHead]
        inc      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], edx
        call     ChainListVecAdd
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_df84
        call     ChainWalkPushPop
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_df84
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      dword ptr [g_walkCallback], 0x126
        mov      eax, dword ptr [ecx*4 + 0x70]
        add      eax, 0x126
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x70], eax
        js       L_df59
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      eax, dword ptr [ecx*4 + 0x58]
        test     eax, eax
        mov      dword ptr [g_walkCallback], eax
        jl       L_df59
        mov      dword ptr [ecx*4 + 0x58], 0xfffffd71
        mov      eax, dword ptr [g_fightGroupHead]
        mov      edx, 0x4d6c98
        mov      dword ptr [eax*4 + 0x70], 0
        mov      ecx, dword ptr [g_xformEntityIdx]
        shr      edx, 2
        mov      dword ptr [ecx*4 + 0x10], 0
        mov      dword ptr [g_walkCallback], edx
        call     ScaledStoreThree_00409260
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_df84
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      ecx, dword ptr [eax*4 + 0x2c]
        mov      dword ptr [g_currentNodeIdx], ecx
        call     ScaledZeroIfNonzero
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_df84
    L_df59:
        mov      eax, dword ptr [g_matrixStackTop]
        mov      edx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_fightGroupHead], edx
        mov      dword ptr [g_matrixStackTop], eax
        mov      ecx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      dword ptr [g_matrixStackTop], eax
    L_df84:
        ret      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        mov      dword ptr [g_walkCallback], 0x51e
        call     StoreDoubleNegPauseSubStore
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_e02d
        mov      eax, dword ptr [g_walkCallback]
        mov      ecx, dword ptr [g_fightGroupHead]
        add      eax, 0x1999
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x70], eax
        mov      edx, dword ptr [g_fightGroupHead]
        mov      eax, dword ptr [edx*4 + 0x18]
        mov      dword ptr [g_walkCallback], 0x6487e
        mov      dword ptr [g_currentNodeIdx], eax
        call     AudioMixerStep
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_e02d
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      edx, dword ptr [g_walkCallback]
        mov      dword ptr [ecx*4 + 0x44], edx
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      ecx, 0x40de50
        mov      eax, dword ptr [eax*4 + 0x28]
        mov      dword ptr [g_walkCallback], ecx
        mov      dword ptr [g_xformEntityIdx], eax
        mov      dword ptr [eax*4 + 0x10], ecx
        jmp      CallSetPause
    L_e02d:
        ret      
        nop      
        nop      
        mov      eax, dword ptr [g_fightGroupHead]
        mov      dword ptr [g_currentNodeIdx], eax
        call     MStackPushZeroCallPop
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_e137
        call     MStackCall_MStackPush2ChainPrepend_00406600
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_e137
        mov      dword ptr [g_walkCallback], 0xccc
        call     MStackPushNegMul10
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_e137
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      edx, dword ptr [g_walkCallback]
        mov      dword ptr [ecx*4 + 0x6c], edx
        mov      eax, dword ptr [g_fightGroupHead]
        mov      ecx, dword ptr [g_eventQueueCurrent]
        mov      dword ptr [eax*4 + 0x74], ecx
        mov      edx, dword ptr [g_fightGroupHead]
        mov      ecx, dword ptr [edx*4 + 0x18]
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      eax, dword ptr [ecx*4 + 0x20]
        or       al, 0x40
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x20], eax
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      eax, dword ptr [eax*4 + 0x28]
        mov      dword ptr [g_xformEntityIdx], eax
        mov      ecx, dword ptr [eax*4]
        or       ecx, 0xa
        mov      dword ptr [eax*4], ecx
        mov      ecx, dword ptr [g_xformEntityIdx]
        mov      dword ptr [ecx*4 + 0x48], 0x5999
        mov      edx, dword ptr [g_xformEntityIdx]
        mov      dword ptr [edx*4 + 0x2c], 0x26666
        mov      eax, dword ptr [g_xformEntityIdx]
        mov      dword ptr [eax*4 + 0x14], 0xff
        mov      ecx, dword ptr [g_xformEntityIdx]
        mov      eax, 0x40e140
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x10], eax
        jmp      CallSetPause
    L_e137:
        ret      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        mov      eax, dword ptr [g_gameMode]
        test     eax, eax
        jne      L_e17f
        mov      ecx, dword ptr [g_xformEntityIdx]
        mov      dword ptr [g_walkCallback], 0xfffffd71
        mov      eax, dword ptr [ecx*4 + 0x48]
        sub      eax, 0x28f
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x48], eax
        call     ChainListVecAdd
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_e184
    L_e17f:
        jmp      ClampMulShiftStore
    L_e184:
        ret      
    }
}
#endif


#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void PendingMatch_TripleSubVec3(void)

{
  g_xformDirtyFlags = g_xformDirtyFlags | 4;
  if ((g_currentNodeIdx != 0) && (g_xformDirtyFlags = g_xformDirtyFlags ^ 4, g_currentNodeIdx != 0)) {
    g_dualD = g_currentNodeIdx;
    MK4_NODE_AT(int, g_currentNodeIdx, 0x58) = MK4_NODE_AT(int, g_currentNodeIdx, 0x58) + -0xb333;
    g_walkCallback = MK4_NODE_AT(undefined4, g_dualD, 0x58);
    g_dualC = g_dualD + 0x15;
    g_eventQueuePending = g_eventQueueSeed + 0x15;
    g_currentNodeIdx = g_savedNode;
    TripleSubVec3();
    if (g_framePauseFlag == 0) {
      g_eventQueuePending = g_currentNodeIdx;
      g_walkCallback = 0x51e;
      g_currentNodeIdx = g_dualD + 0x1b;
      ThreeMul10Stores();
      return;
    }
  }
  return;
}
#else
__declspec(naked) void PendingMatch_TripleSubVec3(void)
{
    __asm {
        mov      eax, dword ptr [g_xformDirtyFlags]
        mov      ecx, 4
        or       eax, ecx
        mov      dword ptr [g_xformDirtyFlags], eax
        mov      eax, dword ptr [g_currentNodeIdx]
        test     eax, eax
        je       L_78f8
        mov      edx, dword ptr [g_xformDirtyFlags]
        xor      edx, ecx
        test     eax, eax
        mov      dword ptr [g_xformDirtyFlags], edx
        je       L_78f8
        mov      dword ptr [g_eventQueueTotal], eax
        mov      ecx, dword ptr [eax*4 + 0x58]
        add      ecx, 0xffff4ccd
        mov      dword ptr [eax*4 + 0x58], ecx
        mov      eax, dword ptr [g_eventQueueTotal]
        mov      edx, dword ptr [g_savedNode]
        mov      ecx, dword ptr [eax*4 + 0x58]
        add      eax, 0x15
        mov      dword ptr [g_walkCallback], ecx
        mov      ecx, dword ptr [g_eventQueueSeed]
        add      ecx, 0x15
        mov      dword ptr [g_currentNodeIdx], edx
        mov      dword ptr [g_xformEntityIdx], ecx
        mov      dword ptr [g_pendingNodeType], eax
        call     TripleSubVec3
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_78f8
        mov      eax, dword ptr [g_eventQueueTotal]
        mov      edx, dword ptr [g_currentNodeIdx]
        add      eax, 0x1b
        mov      dword ptr [g_xformEntityIdx], edx
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [g_walkCallback], 0x51e
        jmp      ThreeMul10Stores
    L_78f8:
        ret      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        mov      eax, dword ptr [g_baseSel]
        shl      eax, 2
        mov      ecx, dword ptr [eax + 0x84]
        mov      dword ptr [eax + 0x84], 0
        test     ecx, ecx
        je       L_796e
        mov      ecx, dword ptr [g_dispatchSave100]
        test     ecx, ecx
        mov      dword ptr [g_walkCallback], ecx
        je       L_796e
        mov      dword ptr [g_walkCallback], 2
        call     DirtyDoubleDeref
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_798c
        test     byte ptr [g_xformDirtyFlags], 4
        jne      L_7969
        mov      ecx, 0x50d418
        shr      ecx, 2
        mov      dword ptr [g_walkCallback], ecx
        call     ScaledStoreIdx24
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_798c
    L_7969:
        jmp      CallSetPause
    L_796e:
        mov      ecx, 1
        mov      dword ptr [eax + 8], 0x417900
        mov      dword ptr [eax + 0x84], ecx
        mov      dword ptr [g_pendingNodeType], ecx
        mov      dword ptr [g_framePauseFlag], ecx
    L_798c:
        ret      
        nop      
        nop      
        nop      
        mov      eax, dword ptr [g_baseSel]
        push     ebx
        push     esi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        cmp      eax, 0xa
        ja       L_7da4
        jmp      dword ptr [eax*4 + L_7dec_jmptbl]
        mov      ecx, dword ptr [g_eventQueueEnd]
        mov      eax, 0x417fb0
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x10], eax
        mov      dword ptr [esi + 8], 0x417990
        mov      dword ptr [esi + 0x84], 2
        mov      dword ptr [g_pendingNodeType], 0x1a
        mov      dword ptr [g_framePauseFlag], 1
        pop      esi
        pop      ebx
        ret      
        mov      edx, dword ptr [g_eventQueueEnd]
        mov      eax, 0x417ff0
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [edx*4 + 0x10], eax
        mov      dword ptr [esi + 8], 0x417990
        mov      dword ptr [esi + 0x84], 3
        mov      dword ptr [g_pendingNodeType], 0x1a
        mov      dword ptr [g_framePauseFlag], 1
        pop      esi
        pop      ebx
        ret      
        mov      eax, dword ptr [g_eventQueueEnd]
        mov      dword ptr [eax*4 + 0x10], 0x418030
        mov      dword ptr [g_walkCallback], 0x6c
        call     TableLookupCall_g_eventTbl_112
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_7de7
        push     0
        push     0x417900
        call     StoreTwoCall
        add      esp, 8
        call     BootMStackBracketedScaledStores
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_7de7
        call     PendingMatch_TripleSubVec3
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_7de7
        mov      dword ptr [esi + 8], 0x417990
        mov      dword ptr [esi + 0x84], 5
        mov      dword ptr [g_pendingNodeType], 2
        mov      dword ptr [g_framePauseFlag], 1
        pop      esi
        pop      ebx
        ret      
        call     BootOneShotMStackPush3
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_7de7
        mov      dword ptr [esi + 8], 0x417990
        mov      dword ptr [esi + 0x84], 6
        mov      dword ptr [g_pendingNodeType], 2
        mov      dword ptr [g_framePauseFlag], 1
        pop      esi
        pop      ebx
        ret      
        call     BootOneShotMStackPush3
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_7de7
        mov      dword ptr [esi + 8], 0x417990
        mov      dword ptr [esi + 0x84], 7
        mov      dword ptr [g_pendingNodeType], 2
        mov      dword ptr [g_framePauseFlag], 1
        pop      esi
        pop      ebx
        ret      
        call     BootOneShotMStackPush3
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_7de7
        mov      dword ptr [esi + 8], 0x417990
        mov      dword ptr [esi + 0x84], 8
        mov      dword ptr [g_pendingNodeType], 2
        mov      dword ptr [g_framePauseFlag], 1
        pop      esi
        pop      ebx
        ret      
        call     BootMStackBracketedScaledStores
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_7de7
        call     PendingMatch_TripleSubVec3
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_7de7
        mov      dword ptr [esi + 8], 0x417990
        mov      dword ptr [esi + 0x84], 9
        mov      dword ptr [g_pendingNodeType], 2
        mov      dword ptr [g_framePauseFlag], 1
        pop      esi
        pop      ebx
        ret      
        call     ScaledInit_Phase4SevenPackedDispatch_g_eventQueueTotal
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_7de7
        mov      dword ptr [esi + 8], 0x417990
        mov      dword ptr [esi + 0x84], 0xa
        mov      dword ptr [g_pendingNodeType], 2
        mov      dword ptr [g_framePauseFlag], 1
        pop      esi
        pop      ebx
        ret      
        mov      ecx, dword ptr [g_baseSel]
        mov      edx, dword ptr [g_xformDirtyFlags]
        mov      ebx, 4
        mov      eax, dword ptr [ecx*4 + 0x30]
        or       edx, ebx
        test     eax, eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [g_xformDirtyFlags], edx
        je       L_7c41
        mov      ecx, edx
        xor      ecx, ebx
        test     eax, eax
        mov      dword ptr [g_xformDirtyFlags], ecx
        je       L_7c41
        call     MStackBracket2_TreeWalkRecursive
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_7de7
    L_7c41:
        mov      dword ptr [g_eventQueueIdx], 0x19
        jmp      L_7db1
        mov      dword ptr [g_walkCallback], 2
        call     DirtyDoubleDeref
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_7de7
        mov      al, byte ptr [g_xformDirtyFlags]
        mov      ebx, 4
        test     al, bl
        jne      L_7ce2
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      eax, dword ptr [g_baseSel]
        mov      ecx, 0x5074ec
        mov      dword ptr [g_pendingNodeType], edx
        mov      dword ptr [g_walkCallback], 0
        mov      dword ptr [eax*4 + 0x30], 0
        shr      ecx, 2
        mov      dword ptr [g_xformEntityIdx], ecx
        call     MStackBracket1_TreeWalkRecursive2
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_7de7
        test     byte ptr [g_xformDirtyFlags], bl
        jne      L_7ce2
        call     ScaledTestPauseStore
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_7de7
        test     byte ptr [g_xformDirtyFlags], bl
        je       L_7d06
    L_7ce2:
        mov      dword ptr [esi + 8], 0x417990
        mov      dword ptr [esi + 0x84], ebx
        mov      dword ptr [g_pendingNodeType], 0x68
        mov      dword ptr [g_framePauseFlag], 1
        pop      esi
        pop      ebx
        ret      
    L_7d06:
        mov      edx, dword ptr [g_baseSel]
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      dword ptr [edx*4 + 0x30], eax
        mov      eax, dword ptr [g_xformEntityIdx]
        mov      ecx, dword ptr [eax*4]
        or       ecx, 8
        mov      dword ptr [eax*4], ecx
        mov      ecx, dword ptr [g_xformEntityIdx]
        mov      eax, 0x28f
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x48], eax
        mov      edx, dword ptr [g_xformEntityIdx]
        mov      eax, dword ptr [g_pendingNodeType]
        mov      dword ptr [g_eventQueueEnd], edx
        mov      dword ptr [g_xformEntityIdx], eax
        call     Thunk_MStackPush2ChainPrepend
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_7de7
        mov      ecx, dword ptr [g_eventQueueEnd]
        mov      eax, 0x417f70
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x10], eax
        mov      eax, 1
        mov      dword ptr [esi + 8], 0x417990
        mov      dword ptr [esi + 0x84], eax
        mov      dword ptr [g_pendingNodeType], 0x34
        mov      dword ptr [g_framePauseFlag], eax
        pop      esi
        pop      ebx
        ret      
    L_7da4:
        mov      eax, dword ptr [g_eventQueueIdx]
        dec      eax
        mov      dword ptr [g_eventQueueIdx], eax
        js       L_7de2
    L_7db1:
        call     ScaledInit_Phase4SevenPackedDispatch_g_eventQueueTotal
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_7de7
        mov      eax, 1
        mov      dword ptr [esi + 8], 0x417990
        mov      dword ptr [esi + 0x84], 0xb
        mov      dword ptr [g_pendingNodeType], eax
        mov      dword ptr [g_framePauseFlag], eax
        pop      esi
        pop      ebx
        ret      
    L_7de2:
        call     CallSetPause
    L_7de7:
        pop      esi
        pop      ebx
        ret      
        mov      edi, edi
    L_7dec_jmptbl:
        /* 11-entry jump table */
        _emit    0x50
        _emit    0x7c
        _emit    0x41
        _emit    0x00
        _emit    0xbf
        _emit    0x79
        _emit    0x41
        _emit    0x00
        _emit    0xfe
        _emit    0x79
        _emit    0x41
        _emit    0x00
        _emit    0x3d
        _emit    0x7a
        _emit    0x41
        _emit    0x00
        _emit    0x4d
        _emit    0x7a
        _emit    0x41
        _emit    0x00
        _emit    0xc4
        _emit    0x7a
        _emit    0x41
        _emit    0x00
        _emit    0xfe
        _emit    0x7a
        _emit    0x41
        _emit    0x00
        _emit    0x38
        _emit    0x7b
        _emit    0x41
        _emit    0x00
        _emit    0x72
        _emit    0x7b
        _emit    0x41
        _emit    0x00
        _emit    0xbe
        _emit    0x7b
        _emit    0x41
        _emit    0x00
        _emit    0xf8
        _emit    0x7b
        _emit    0x41
        _emit    0x00
    }
}
#endif

__declspec(naked) void PendingMatch_StoreTwoCall_00411210(void)
{
    __asm {
        push     0xc0
        push     0x49db40
        mov      dword ptr [g_eventQueueNotMask], 0xc2
        call     StoreTwoCall
        mov      al, byte ptr [g_xformDirtyFlags]
        add      esp, 8
        test     al, 1
        jne      L_1273
        mov      eax, dword ptr [g_fightGroupHead]
        mov      ecx, dword ptr [g_currentNodeIdx]
        shl      eax, 2
        shl      ecx, 2
        mov      edx, dword ptr [eax + 0x54]
        mov      dword ptr [g_walkCallback], edx
        mov      dword ptr [ecx + 0x38], edx
        mov      edx, dword ptr [eax + 0x5c]
        mov      dword ptr [g_walkCallback], edx
        mov      dword ptr [ecx + 0x40], edx
        mov      eax, dword ptr [eax + 0x58]
        sub      eax, 0x6666
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx + 0x3c], eax
        jmp      ZeroThreeFields_0040a8b0
    L_1273:
        ret      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        mov      eax, dword ptr [g_baseSel]
        push     esi
        push     edi
        xor      esi, esi
        lea      edi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [edi + 0x84], esi
        cmp      eax, esi
        je       L_133a
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      eax, dword ptr [ecx*4 + 0x58]
        cmp      eax, esi
        mov      dword ptr [g_walkCallback], eax
        jl       L_145d
        call     ZeroThreeFields6c
        cmp      dword ptr [g_framePauseFlag], esi
        jne      L_1521
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      dword ptr [g_walkCallback], esi
        mov      dword ptr [ecx*4 + 0x58], esi
        mov      edx, dword ptr [g_fightGroupHead]
        mov      eax, dword ptr [g_walkCallback]
        mov      dword ptr [edx*4 + 0x60], eax
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      eax, dword ptr [ecx*4 + 0x18]
        mov      dword ptr [g_xformEntityIdx], eax
        mov      edx, dword ptr [eax*4 + 0x28]
        mov      eax, 0x4d5aec
        shr      eax, 2
        mov      dword ptr [g_xformEntityIdx], edx
        mov      dword ptr [g_walkCallback], eax
        call     ScaledStoreThree_00409260
        cmp      dword ptr [g_framePauseFlag], esi
        jne      L_1521
        call     CallSetPause
        pop      edi
        pop      esi
        ret      
    L_133a:
        mov      ecx, dword ptr [g_pendingMatchVar]
        mov      dword ptr [g_walkCallback], ecx
        call     AudioMixerStep
        cmp      dword ptr [g_framePauseFlag], esi
        jne      L_1521
        mov      eax, dword ptr [g_fightGroupHead]
        mov      edx, dword ptr [g_walkCallback]
        mov      dword ptr [eax*4 + 0x64], edx
        mov      dword ptr [g_walkCallback], 0x5999
        call     AudioMixerStep
        cmp      dword ptr [g_framePauseFlag], esi
        jne      L_1521
        mov      ecx, dword ptr [g_walkCallback]
        mov      edx, dword ptr [g_fightGroupHead]
        add      ecx, 0x2666
        mov      dword ptr [edx*4 + 0x60], ecx
        mov      eax, dword ptr [g_baseSel]
        add      eax, 0x11
        mov      dword ptr [g_walkCallback], esi
        mov      dword ptr [g_pendingNodeType], eax
        mov      dword ptr [eax*4], esi
        mov      edx, dword ptr [g_pendingNodeType]
        mov      ecx, dword ptr [g_walkCallback]
        mov      dword ptr [edx*4 + 8], ecx
        mov      dword ptr [g_walkCallback], 0x7ae
        call     AudioMixerStep
        cmp      dword ptr [g_framePauseFlag], esi
        jne      L_1521
        mov      eax, dword ptr [g_walkCallback]
        mov      ecx, dword ptr [g_pendingNodeType]
        sub      eax, 0x1999
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 4], eax
        mov      eax, dword ptr [g_fightGroupHead]
        mov      edx, dword ptr [g_dispatchSave6]
        add      eax, 0x18
        mov      dword ptr [g_currentNodeIdx], edx
        mov      dword ptr [g_xformEntityIdx], eax
        call     Mul10HeavyTransform
        cmp      dword ptr [g_framePauseFlag], esi
        jne      L_1521
        mov      edx, dword ptr [g_fightGroupHead]
        mov      ecx, dword ptr [g_currentNodeIdx]
        add      edx, 0x1b
        mov      dword ptr [g_xformEntityIdx], ecx
        mov      dword ptr [g_currentNodeIdx], edx
        call     QuadInterpolator
        cmp      dword ptr [g_framePauseFlag], esi
        jne      L_1521
        mov      ecx, dword ptr [g_fightGroupHead]
    L_145d:
        mov      dword ptr [g_chainAccumCur], 0xe5
        mov      eax, dword ptr [ecx*4 + 0x70]
        add      eax, 0xe5
        mov      dword ptr [g_chainAccumCur], eax
        mov      dword ptr [ecx*4 + 0x70], eax
        mov      eax, dword ptr [g_fightGroupHead]
        mov      ecx, dword ptr [eax*4 + 0x74]
        mov      edx, dword ptr [eax*4 + 0x6c]
        push     ecx
        push     edx
        call     PendingMatch_StoreTailJmpSigned
        add      esp, 8
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [g_eventQueueWorkType], eax
        call     Atan2QuadrantLookup
        cmp      dword ptr [g_framePauseFlag], esi
        jne      L_1521
        mov      eax, dword ptr [g_pendingMatchVar2]
        mov      ecx, dword ptr [g_walkCallback]
        add      ecx, eax
        mov      dword ptr [g_walkCallback], ecx
        call     BootMod6487eClampAndChainMul10
        cmp      dword ptr [g_framePauseFlag], esi
        jne      L_1521
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      edx, dword ptr [g_walkCallback]
        mov      dword ptr [ecx*4 + 0x60], edx
        mov      eax, dword ptr [g_fightGroupHead]
        mov      ecx, dword ptr [eax*4 + 0x18]
        mov      dword ptr [g_currentNodeIdx], ecx
        call     ChainListVecAdd
        cmp      dword ptr [g_framePauseFlag], esi
        jne      L_1521
        mov      eax, 1
        mov      dword ptr [edi + 8], 0x411280
        mov      dword ptr [edi + 0x84], eax
        mov      dword ptr [g_pendingNodeType], eax
        mov      dword ptr [g_framePauseFlag], eax
    L_1521:
        pop      edi
        pop      esi
        ret      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        call     ScaledChainOr8
        mov      eax, dword ptr [g_xformEntityIdx]
        mov      dword ptr [eax*4 + 0x48], 0x8000
        mov      ecx, dword ptr [g_xformEntityIdx]
        mov      eax, 0xfffffeb9
        mov      dword ptr [ecx*4 + 0x10], 0x49d200
        mov      edx, dword ptr [g_fightGroupHead]
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [edx*4 + 0x70], eax
        jmp      CallSetPause
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        push     0x2d
        push     0x411590
        call     StoreTwoCall
        add      esp, 8
        ret      
        mov      eax, dword ptr [g_baseSel]
        push     edi
        lea      edi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [edi + 0x84], 0
        test     eax, eax
        je       L_15c6
        mov      eax, dword ptr [g_eventQueueIdx]
        dec      eax
        mov      dword ptr [g_eventQueueIdx], eax
        jns      L_15d0
        call     CallSetPause
        pop      edi
        ret      
    L_15c6:
        mov      dword ptr [g_eventQueueIdx], 0xf
    L_15d0:
        mov      dword ptr [g_walkCallback], 0x3333
        call     AudioMixerStep
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1884
        add      dword ptr [g_walkCallback], 0xcccc
        call     ZeroAndDirty4
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1884
        test     byte ptr [g_xformDirtyFlags], 4
        je       L_185f
        mov      ecx, 0x4d5ad8
        shr      ecx, 2
        mov      dword ptr [g_walkCallback], ecx
        call     PushSetXfmMaskCallPop
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1884
        test     byte ptr [g_xformDirtyFlags], 4
        jne      L_185f
        mov      edx, dword ptr [g_fightGroupHead]
        mov      dword ptr [edx*4 + 0x30], 0xc2
        mov      ecx, dword ptr [g_particleEmitterNode]
        lea      eax, [edx*4]
        mov      dword ptr [g_walkCallback], ecx
        mov      dword ptr [eax + 0x3c], ecx
        mov      ecx, dword ptr [g_eventQueueEnd]
        mov      ecx, dword ptr [ecx*4 + 0x64]
        mov      dword ptr [g_walkCallback], ecx
        mov      dword ptr [eax + 0x64], ecx
        mov      edx, dword ptr [g_eventQueueEnd]
        mov      ecx, dword ptr [edx*4 + 0x34]
        and      ecx, 1
        mov      dword ptr [g_walkCallback], ecx
        mov      edx, dword ptr [eax + 0x34]
        or       ch, 0x40
        or       edx, ecx
        mov      dword ptr [eax + 0x34], edx
        mov      eax, edx
        mov      dword ptr [g_walkCallback], eax
        call     ScaledTripleCopy54
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1884
        mov      ecx, dword ptr [g_eventQueueEnd]
        mov      eax, dword ptr [g_fightGroupHead]
        mov      edx, dword ptr [ecx*4 + 0x58]
        sub      edx, 0x1999
        mov      dword ptr [eax*4 + 0x58], edx
        mov      dword ptr [g_walkCallback], 0x7ae
        call     StoreDoubleNegPauseSubStore
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1884
        mov      eax, dword ptr [g_walkCallback]
        mov      ecx, dword ptr [g_fightGroupHead]
        sub      eax, 0x170a
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x70], eax
        mov      edx, dword ptr [g_fightAxisPosY]
        mov      ecx, dword ptr [g_eventQueueEnd]
        mov      eax, dword ptr [g_fightAxisPosX]
        mov      dword ptr [g_eventQueueWorkType], edx
        mov      edx, dword ptr [g_player2NodeIdx]
        mov      dword ptr [g_chainAccumCur], 0xf5c
        cmp      ecx, edx
        mov      dword ptr [g_eventQueueCurrent], eax
        jne      L_175a
        mov      eax, dword ptr [g_fightAxisNegX]
        cmp      ecx, edx
        mov      dword ptr [g_eventQueueCurrent], eax
        jne      L_175a
        mov      ecx, dword ptr [g_fightAxisNegY]
        mov      dword ptr [g_eventQueueWorkType], ecx
    L_175a:
        push     eax
        push     0xf5c
        call     Mul10Tail
        add      esp, 8
        mov      dword ptr [g_eventQueueCurrent], eax
        mov      dword ptr [g_walkCallback], 0x28f
        call     StoreDoubleNegPauseSubStore
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1884
        mov      eax, dword ptr [g_eventQueueCurrent]
        mov      edx, dword ptr [g_walkCallback]
        add      eax, edx
        mov      edx, dword ptr [g_fightGroupHead]
        mov      dword ptr [g_eventQueueCurrent], eax
        mov      dword ptr [edx*4 + 0x6c], eax
        mov      eax, dword ptr [g_eventQueueWorkType]
        mov      ecx, dword ptr [g_chainAccumCur]
        push     eax
        push     ecx
        call     Mul10Tail
        add      esp, 8
        mov      dword ptr [g_eventQueueWorkType], eax
        mov      dword ptr [g_walkCallback], 0x28f
        call     StoreDoubleNegPauseSubStore
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1884
        mov      eax, dword ptr [g_eventQueueWorkType]
        mov      edx, dword ptr [g_walkCallback]
        add      eax, edx
        mov      edx, dword ptr [g_fightGroupHead]
        mov      dword ptr [g_eventQueueWorkType], eax
        mov      dword ptr [edx*4 + 0x74], eax
        mov      eax, dword ptr [g_fightGroupHead]
        mov      eax, dword ptr [eax*4 + 0x18]
        mov      dword ptr [g_currentNodeIdx], eax
        mov      ecx, dword ptr [eax*4 + 0x20]
        and      ch, 0xf9
        mov      dword ptr [eax*4 + 0x20], ecx
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      eax, dword ptr [ecx*4 + 0x28]
        mov      ecx, 0x411890
        mov      dword ptr [g_xformEntityIdx], eax
        mov      dword ptr [g_walkCallback], ecx
        mov      dword ptr [eax*4 + 0x10], ecx
        call     PendingMatch_ChainWalkPushPop_00411890
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1884
        call     MStackCall_MStackPush2ChainPrepend_004062f0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1884
    L_185f:
        mov      dword ptr [edi + 8], 0x411590
        mov      dword ptr [edi + 0x84], 1
        mov      dword ptr [g_pendingNodeType], 1
        mov      dword ptr [g_framePauseFlag], 1
    L_1884:
        pop      edi
        ret      
    }
}

__declspec(naked) void PendingMatch_Push16Call_00402540(void)
{
    __asm {
        mov      eax, dword ptr [g_baseSel]
        push     ebx
        push     esi
        push     edi
        lea      esi, [eax*4]
        mov      ecx, 8
        xor      edi, edi
        mov      eax, dword ptr [esi + 0x84]
        mov      dword ptr [esi + 0x84], edi
        cmp      eax, ecx
        ja       L_2b0a
        jmp      dword ptr [eax*4 + L_2b14_jmptbl]
        mov      dword ptr [g_eventQueueWorkType], ecx
        call     Push16Call
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_2b0f
        mov      dword ptr [esi + 8], 0x402540
        mov      dword ptr [esi + 0x84], 2
        mov      dword ptr [g_pendingNodeType], 0xba
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        pop      ebx
        ret      
        mov      ecx, 0x50835c
        shr      ecx, 2
        mov      dword ptr [g_xformEntityIdx], ecx
        call     DispatcherComplex260_FramePauseScaledStore
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_2b0f
        test     byte ptr [g_xformDirtyFlags], 4
        jne      L_2a07
        mov      eax, dword ptr [g_baseSel]
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [eax*4 + 0x64], edx
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      eax, 0x10000
        mov      dword ptr [ecx*4 + 0x54], edi
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [edx*4 + 0x58], eax
        call     MStackPushComplexCallPop_MStackPush2ChainPrepend_00406430
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_2b0f
        push     0x31
        call     SaveCallRestore
        mov      dword ptr [esi + 8], 0x402540
        mov      dword ptr [esi + 0x84], 3
        add      esp, 4
        mov      dword ptr [g_pendingNodeType], 0x3c
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        pop      ebx
        ret      
        mov      eax, 0x5082d0
        shr      eax, 2
        mov      dword ptr [g_xformEntityIdx], eax
        call     DispatcherComplex260_FramePauseScaledStore
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_2b0f
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      ebx, 0x1f
        mov      dword ptr [ecx*4 + 0x54], 0xfed40000
        mov      eax, dword ptr [g_baseSel]
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [eax*4 + 0x5c], edx
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [g_walkCallback], ebx
        mov      dword ptr [ecx*4 + 0x30], ebx
        call     MStackPushComplexCallPop_MStackPush2ChainPrepend_00406430
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_2b0f
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      eax, 0xa0000
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [edx*4 + 0x6c], eax
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      dword ptr [g_eventQueueEnd], eax
        call     RegistryPushBindPop
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_2b0f
        mov      ecx, 0x5082ec
        shr      ecx, 2
        mov      dword ptr [g_xformEntityIdx], ecx
        call     DispatcherComplex260_FramePauseScaledStore
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_2b0f
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [edx*4 + 0x54], 0x12b0000
        mov      ecx, dword ptr [g_baseSel]
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      dword ptr [ecx*4 + 0x60], eax
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [g_walkCallback], ebx
        mov      dword ptr [edx*4 + 0x30], ebx
        call     MStackPushComplexCallPop_MStackPush2ChainPrepend_00406430
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_2b0f
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      ecx, 0xfff60000
        mov      dword ptr [g_eventQueueIdx], eax
        mov      dword ptr [g_walkCallback], ecx
        mov      dword ptr [eax*4 + 0x6c], ecx
        call     RegistryPushBindPop
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_2b0f
        mov      dword ptr [esi + 8], 0x402540
        mov      dword ptr [esi + 0x84], 4
        mov      dword ptr [g_pendingNodeType], 0x14
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        pop      ebx
        ret      
        mov      eax, dword ptr [g_eventQueueEnd]
        push     0x28f
        mov      dword ptr [eax*4 + 0x6c], edi
        mov      ecx, dword ptr [g_eventQueueIdx]
        mov      dword ptr [g_walkCallback], edi
        mov      dword ptr [ecx*4 + 0x6c], edi
        call     SaveCallRestore
        add      esp, 4
        mov      dword ptr [g_eventQueueWorkType], 9
        call     Push16Call
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_2b0f
        mov      eax, 1
        mov      dword ptr [esi + 8], 0x402540
        mov      dword ptr [esi + 0x84], 5
        mov      dword ptr [g_pendingNodeType], eax
        mov      dword ptr [g_framePauseFlag], eax
        pop      edi
        pop      esi
        pop      ebx
        ret      
        mov      dword ptr [esi + 8], 0x402540
        mov      edx, dword ptr [g_baseSel]
        mov      ecx, 0x402540
        mov      dword ptr [edx*4 + 0x84], 6
        mov      eax, dword ptr [esi + 4]
        add      ecx, 0x6000000
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      edx, dword ptr [g_baseSel]
        mov      dword ptr [edx*4 + 0x84], edi
        call     InstallSelfSearchAccum
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        pop      ebx
        ret      
        mov      dword ptr [esi + 8], 0x402540
        mov      dword ptr [esi + 0x84], 7
        mov      dword ptr [g_pendingNodeType], 0x5a
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        pop      ebx
        ret      
        mov      dword ptr [esi + 8], 0x402540
        mov      dword ptr [esi + 0x84], ecx
        mov      dword ptr [g_pendingNodeType], 0x1a4
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        pop      ebx
        ret      
        call     FiveTableWalkInit
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_2b0f
        mov      ebx, 4
        push     edi
        push     0x4a2180
        mov      dword ptr [g_phaseIdx], ebx
        call     StoreTwoCall
        mov      eax, 0x506c38
        add      esp, 8
        shr      eax, 2
        mov      dword ptr [g_currentNodeIdx], eax
        call     LoadGeoAsset_Default
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_2b0f
        mov      ecx, 0x506c38
        shr      ecx, 2
        mov      dword ptr [g_currentNodeIdx], ecx
        call     LoadGeoAsset_Default
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_2b0f
        mov      edx, 0x508340
        shr      edx, 2
        mov      dword ptr [g_xformEntityIdx], edx
        call     DispatcherComplex260_FramePauseScaledStore
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_2b0f
        test     byte ptr [g_xformDirtyFlags], bl
        jne      L_2a07
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      ecx, 0x28f
        shl      eax, 2
        mov      dword ptr [eax + 0x54], edi
        mov      dword ptr [eax + 0x58], 0x640000
        mov      dword ptr [g_walkCallback], ecx
        mov      dword ptr [eax + 0x30], ecx
        call     MStackPushComplexCallPop_MStackPush2ChainPrepend_00406430
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_2b0f
        mov      ecx, 0x506d98
        shr      ecx, 2
        mov      dword ptr [g_xformEntityIdx], ecx
        call     DispatcherComplex260_MStackBracket1_TreeWalkRecursive2
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_2b0f
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [edx*4 + 0x54], edi
        mov      dword ptr [edx*4 + 0x58], edi
        mov      dword ptr [edx*4 + 0x64], 0xa3d
        lea      eax, [edx*4]
        mov      dword ptr [eax + 0x5c], 0xfff9b334
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      eax, 0x31
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x30], eax
        call     MStackCall_MStackPush2ChainPrepend_00406340
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_2b0f
        test     byte ptr [g_xformDirtyFlags], bl
        je       L_2a71
    L_2a07:
        mov      dword ptr [g_eventQueueCurrent], 0xa
        mov      dword ptr [esi + 8], 0x402540
        mov      edx, dword ptr [g_baseSel]
        mov      ecx, 0x402540
        add      ecx, 0x9000000
        mov      dword ptr [edx*4 + 0x84], 9
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      edx, dword ptr [g_baseSel]
        mov      dword ptr [edx*4 + 0x84], edi
        call     InstallSelfPackedF80
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        pop      ebx
        ret      
    L_2a71:
        call     RegistryPushBindPop
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_2b0f
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      ecx, dword ptr [eax*4 + 0x34]
        or       ecx, 0x80000
        mov      dword ptr [eax*4 + 0x34], ecx
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      dword ptr [eax*4 + 0x60], 0x32439
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      eax, 0xccc
        mov      dword ptr [ecx*4 + 0x74], 0x11eb
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [edx*4 + 0x78], eax
        mov      dword ptr [g_eventQueueWorkType], 0x131
        call     Push16Call
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_2b0f
        mov      eax, 1
        mov      dword ptr [esi + 8], 0x402540
        mov      dword ptr [esi + 0x84], eax
        mov      dword ptr [g_pendingNodeType], eax
        mov      dword ptr [g_framePauseFlag], eax
        pop      edi
        pop      esi
        pop      ebx
        ret      
    L_2b0a:
        call     StackPopDispatchTagged
    L_2b0f:
        pop      edi
        pop      esi
        pop      ebx
        ret      
        nop      
    L_2b14_jmptbl:
        /* 9-entry jump table */
        _emit    0xc8
        _emit    0x28
        _emit    0x40
        _emit    0x00
        _emit    0x71
        _emit    0x25
        _emit    0x40
        _emit    0x00
        _emit    0xb1
        _emit    0x25
        _emit    0x40
        _emit    0x00
        _emit    0x57
        _emit    0x26
        _emit    0x40
        _emit    0x00
        _emit    0xaf
        _emit    0x27
        _emit    0x40
        _emit    0x00
        _emit    0x1a
        _emit    0x28
        _emit    0x40
        _emit    0x00
        _emit    0x7a
        _emit    0x28
        _emit    0x40
        _emit    0x00
        _emit    0xa3
        _emit    0x28
        _emit    0x40
        _emit    0x00
        _emit    0x07
        _emit    0x2a
        _emit    0x40
        _emit    0x00
    }
}

__declspec(naked) void PendingMatch_StoreTwoCall_004108a0(void)
{
    __asm {
        mov      eax, dword ptr [g_walkCallback]
        push     0x2f
        push     0x4109b0
        mov      dword ptr [g_eventQueueIdx], eax
        call     StoreTwoCall
        mov      ecx, dword ptr [g_currentNodeIdx]
        add      esp, 8
        mov      dword ptr [g_baseSel], ecx
        call     CmpP1ScaledInitB
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_09a9
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      ecx, dword ptr [edx*4 + 0x64]
        test     ecx, ecx
        mov      dword ptr [g_eventQueueWorkType], ecx
        jge      L_090d
        mov      edx, 0x6487d
        mov      eax, 0xa2f99905
        sub      edx, ecx
        mul      edx
        shr      edx, 0x12
        imul     edx, edx, 0x6487e
        add      ecx, edx
        mov      dword ptr [g_eventQueueWorkType], ecx
    L_090d:
        cmp      ecx, 0x6487e
        jl       L_092e
        mov      eax, 0xa2f99905
        mul      ecx
        shr      edx, 0x12
    L_091f:
        sub      ecx, 0x6487e
        dec      edx
        jne      L_091f
        mov      dword ptr [g_eventQueueWorkType], ecx
    L_092e:
        mov      eax, dword ptr [g_dispatchSave6]
        mov      dword ptr [g_pendingNodeType], eax
        call     MStackPush2DualModMul10Pop2
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_09a9
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      edx, dword ptr [g_pendingNodeType]
        mov      eax, dword ptr [ecx*4 + 0x34]
        mov      dword ptr [g_currentNodeIdx], edx
        mov      dword ptr [g_walkCallback], eax
        and      eax, 1
        mov      dword ptr [g_xformScratch94], eax
        je       L_097c
        call     NegateThree
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_09a9
    L_097c:
        mov      eax, dword ptr [g_baseSel]
        mov      edx, dword ptr [g_eventQueueIdx]
        mov      ecx, dword ptr [g_pendingNodeType]
        add      eax, 0xc
        add      edx, 9
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [g_xformEntityIdx], ecx
        mov      dword ptr [g_pendingNodeType], edx
        jmp      QuadInterpolator
    L_09a9:
        ret      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        mov      eax, dword ptr [g_baseSel]
        push     ebx
        push     ebp
        push     esi
        lea      ebx, [eax*4]
        push     edi
        mov      eax, dword ptr [ebx + 0x84]
        mov      dword ptr [ebx + 0x84], 0
        test     eax, eax
        jne      L_0d64
        mov      ecx, dword ptr [g_eventQueueIdx]
        mov      edx, dword ptr [ecx*4 + 0x10]
        mov      dword ptr [g_eventQueueNotMask], edx
    L_09eb:
        mov      dword ptr [g_walkCallback], 0x2666
        call     AudioMixerStep
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_0d7c
        add      dword ptr [g_walkCallback], 0xe147
        call     ZeroAndDirty4
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_0d7c
        test     byte ptr [g_xformDirtyFlags], 4
        je       L_0d10
        mov      eax, dword ptr [g_eventQueueIdx]
        mov      ecx, dword ptr [eax*4]
        mov      dword ptr [g_walkCallback], ecx
        call     PushSetXfmMaskCallPop
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_0d7c
        test     byte ptr [g_xformDirtyFlags], 4
        jne      L_0d77
        mov      edx, dword ptr [g_fightGroupHead]
        mov      eax, 0xc2
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [edx*4 + 0x30], eax
        call     ScaledTripleCopy54
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_0d7c
        mov      eax, dword ptr [g_fightGroupHead]
        mov      ecx, dword ptr [g_eventQueueIdx]
        mov      edx, dword ptr [g_baseSel]
        lea      esi, [eax*4]
        lea      edi, [ecx*4]
        lea      ebp, [edx*4]
        mov      eax, dword ptr [esi + 0x58]
        mov      dword ptr [g_walkCallback], eax
        mov      ecx, dword ptr [edi + 0x1c]
        add      eax, ecx
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [esi + 0x58], eax
        mov      eax, dword ptr [edi + 0x20]
        mov      dword ptr [g_walkCallback], eax
        call     StoreDoubleNegPauseSubStore
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_0d7c
        mov      eax, dword ptr [g_walkCallback]
        mov      ecx, dword ptr [ebp + 0x30]
        add      eax, ecx
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [esi + 0x6c], eax
        mov      ecx, dword ptr [edi + 0x20]
        mov      dword ptr [g_walkCallback], ecx
        call     StoreDoubleNegPauseSubStore
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_0d7c
        mov      eax, dword ptr [g_walkCallback]
        mov      ecx, dword ptr [ebp + 0x34]
        add      eax, ecx
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [esi + 0x70], eax
        mov      edx, dword ptr [edi + 0x20]
        mov      dword ptr [g_walkCallback], edx
        call     StoreDoubleNegPauseSubStore
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_0d7c
        mov      eax, dword ptr [g_walkCallback]
        mov      edi, dword ptr [ebp + 0x38]
        add      eax, edi
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [esi + 0x74], eax
        mov      esi, dword ptr [esi + 0x18]
        mov      dword ptr [g_currentNodeIdx], esi
        mov      ecx, dword ptr [esi*4 + 0x28]
        mov      dword ptr [g_xformEntityIdx], ecx
        mov      eax, dword ptr [ecx*4]
        or       al, 8
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4], eax
        mov      eax, dword ptr [g_eventQueueIdx]
        mov      ecx, dword ptr [g_xformEntityIdx]
        mov      eax, dword ptr [eax*4 + 8]
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x48], eax
        mov      edx, dword ptr [g_eventQueueIdx]
        mov      ecx, dword ptr [g_xformEntityIdx]
        mov      eax, dword ptr [edx*4 + 4]
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x10], eax
        mov      edx, dword ptr [g_eventQueueIdx]
        mov      eax, dword ptr [edx*4 + 0x14]
        test     eax, eax
        mov      dword ptr [g_walkCallback], eax
        je       L_0d02
        call     CmpDivJmp
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_0d7c
        test     byte ptr [g_xformDirtyFlags], 4
        jne      L_0d02
        mov      eax, dword ptr [g_savedNode]
        mov      ecx, dword ptr [g_eventQueueIdx]
        mov      dword ptr [g_xformEntityIdx], eax
        mov      edx, dword ptr [ecx*4 + 0x18]
        mov      dword ptr [g_walkCallback], edx
        call     StoreDoubleNegPauseSubStore
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_0d7c
    L_0c1b:
        mov      ecx, dword ptr [g_xformEntityIdx]
        mov      eax, dword ptr [g_walkCallback]
        mov      dword ptr [ecx*4], eax
        mov      edx, dword ptr [g_eventQueueIdx]
        mov      eax, dword ptr [edx*4 + 0x18]
        mov      dword ptr [g_walkCallback], eax
        call     StoreDoubleNegPauseSubStore
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_0d7c
        mov      edx, dword ptr [g_xformEntityIdx]
        mov      ecx, dword ptr [g_walkCallback]
        mov      dword ptr [edx*4 + 4], ecx
        mov      eax, dword ptr [g_eventQueueIdx]
        mov      ecx, dword ptr [eax*4 + 0x18]
        mov      dword ptr [g_walkCallback], ecx
        call     StoreDoubleNegPauseSubStore
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_0d7c
        mov      eax, dword ptr [g_xformEntityIdx]
        mov      edx, dword ptr [g_walkCallback]
        mov      dword ptr [eax*4 + 8], edx
        call     ScaledTripleCopy10
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_0d7c
        call     ScaledTripleCopy4
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_0d7c
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      eax, dword ptr [ecx*4]
        test     eax, eax
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [g_currentNodeIdx], eax
        je       L_0d02
        mov      edx, dword ptr [g_eventQueueIdx]
        mov      eax, dword ptr [edx*4 + 0x18]
        mov      dword ptr [g_walkCallback], eax
        call     StoreDoubleNegPauseSubStore
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        je       L_0c1b
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        ret      
    L_0d02:
        call     MStackCall_MStackPush2ChainInsert_00406250
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_0d7c
    L_0d10:
        mov      ecx, dword ptr [g_eventQueueIdx]
        mov      esi, dword ptr [g_xformDirtyFlags]
        mov      eax, dword ptr [ecx*4 + 0xc]
        mov      ecx, 4
        or       esi, ecx
        mov      dword ptr [g_pendingNodeType], eax
        test     eax, eax
        mov      dword ptr [g_xformDirtyFlags], esi
        je       L_0d64
        mov      edx, esi
        xor      edx, ecx
        test     eax, eax
        mov      dword ptr [g_xformDirtyFlags], edx
        je       L_0d64
        mov      eax, 0x4109b0
        mov      dword ptr [ebx + 8], eax
        mov      eax, 1
        mov      dword ptr [ebx + 0x84], eax
        mov      dword ptr [g_framePauseFlag], eax
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        ret      
    L_0d64:
        mov      eax, dword ptr [g_eventQueueNotMask]
        dec      eax
        test     eax, eax
        mov      dword ptr [g_eventQueueNotMask], eax
        jg       L_09eb
    L_0d77:
        call     CallSetPause
    L_0d7c:
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        ret      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        mov      eax, dword ptr [g_gameMode]
        test     eax, eax
        jne      L_0e04
        mov      eax, dword ptr [g_matrixStackTop]
        mov      ecx, dword ptr [g_fightGroupHead]
        inc      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], ecx
        call     ChainWalkPushPop
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_0e04
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      dword ptr [g_walkCallback], 0xe5
        mov      eax, dword ptr [ecx*4 + 0x70]
        add      eax, 0xe5
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x70], eax
        mov      eax, dword ptr [g_matrixStackTop]
        mov      edx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_fightGroupHead], edx
        mov      dword ptr [g_matrixStackTop], eax
        jmp      ChainListVecAdd
    L_0e04:
        ret      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        mov      eax, dword ptr [g_gameMode]
        test     eax, eax
        jne      L_0e78
        mov      eax, dword ptr [g_matrixStackTop]
        mov      ecx, dword ptr [g_fightGroupHead]
        inc      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], ecx
        call     ChainWalkPushPop
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_0e78
        push     0x80
        call     ScaledThreeChanPack
        mov      edx, dword ptr [g_fightGroupHead]
        add      esp, 4
        push     edx
        call     CopyThreeFields
        mov      eax, dword ptr [g_matrixStackTop]
        add      esp, 4
        mov      ecx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_fightGroupHead], ecx
        mov      dword ptr [g_matrixStackTop], eax
        jmp      ChainListVecAdd
    L_0e78:
        ret      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        call     Phase1InitModelAdjustChain
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_0fa3
        test     byte ptr [g_xformDirtyFlags], 4
        jne      L_0fa3
        mov      dword ptr [g_walkCallback], 0xfffff5c3
        call     MStackPushNegMul10
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_0fa3
        mov      eax, dword ptr [g_fightGroupHead]
        mov      ecx, dword ptr [g_walkCallback]
        shl      eax, 2
        add      ecx, dword ptr [eax + 0x6c]
        mov      dword ptr [g_walkCallback], ecx
        mov      edx, dword ptr [eax + 0x74]
        mov      dword ptr [eax + 0x6c], ecx
        mov      ecx, dword ptr [g_eventQueueCurrent]
        add      ecx, edx
        mov      dword ptr [g_eventQueueCurrent], ecx
        mov      dword ptr [eax + 0x74], ecx
        call     Phase1InitModelAdjustChain
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_0fa3
        test     byte ptr [g_xformDirtyFlags], 4
        jne      L_0fa3
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      eax, dword ptr [ecx*4 + 0x18]
        mov      ecx, 0x4000
        mov      dword ptr [g_currentNodeIdx], eax
        mov      eax, dword ptr [eax*4 + 0x28]
        mov      dword ptr [g_walkCallback], ecx
        mov      dword ptr [g_xformEntityIdx], eax
        mov      dword ptr [eax*4 + 0x48], ecx
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      eax, dword ptr [edx*4]
        mov      dword ptr [g_currentNodeIdx], eax
        mov      eax, dword ptr [eax*4 + 0x28]
        mov      dword ptr [g_xformEntityIdx], eax
        mov      dword ptr [eax*4 + 0x48], ecx
        mov      dword ptr [g_walkCallback], 0xa3d
        call     MStackPushNegMul10
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_0fa3
        mov      eax, dword ptr [g_fightGroupHead]
        mov      ecx, dword ptr [g_walkCallback]
        shl      eax, 2
        add      ecx, dword ptr [eax + 0x6c]
        mov      dword ptr [g_walkCallback], ecx
        mov      edx, dword ptr [eax + 0x74]
        mov      dword ptr [eax + 0x6c], ecx
        mov      ecx, dword ptr [g_eventQueueCurrent]
        add      ecx, edx
        mov      dword ptr [g_eventQueueCurrent], ecx
        mov      dword ptr [eax + 0x74], ecx
    L_0fa3:
        ret      
    }
}


__declspec(naked) void PendingMatch_MStackPush8_0040a8d0(void)
{
    __asm {
        push     ecx
        push     ebx
        push     ebp
        push     esi
        push     edi
        call     MStackPush8
        mov      eax, dword ptr [g_framePauseFlag]
        xor      ebp, ebp
        cmp      eax, ebp
        jne      L_acd2
        mov      eax, dword ptr [g_fightGroupHead]
        mov      ecx, 0x4d60b8
        shr      ecx, 2
        push     0xc0
        push     0x49db40
        mov      dword ptr [g_eventQueueEnd], eax
        mov      dword ptr [g_eventQueueIdx], ecx
        mov      dword ptr [g_eventQueueNotMask], 0xc1
        call     StoreTwoCall
        mov      al, byte ptr [g_xformDirtyFlags]
        mov      ebx, 1
        add      esp, 8
        test     al, bl
        jne      L_accd
        call     StackPushAdd15CallPop
        cmp      dword ptr [g_framePauseFlag], ebp
        jne      L_acd2
        mov      edx, dword ptr [g_eventQueueEnd]
        mov      dword ptr [g_eventQueueCurrent], 0xfffff334
        mov      ecx, dword ptr [g_currentNodeIdx]
        push     0x27
        mov      eax, dword ptr [edx*4 + 0x6c]
        push     0x40ae30
        cdq      
        sub      eax, edx
        sar      eax, 1
        neg      eax
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x44], eax
        mov      edx, dword ptr [g_eventQueueEnd]
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      eax, dword ptr [edx*4 + 0x74]
        cdq      
        sub      eax, edx
        sar      eax, 1
        neg      eax
        mov      dword ptr [ecx*4 + 0x4c], eax
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      eax, 0xffffe667
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [edx*4 + 0x48], eax
        call     StoreTwoCall
        mov      al, byte ptr [g_xformDirtyFlags]
        add      esp, 8
        test     al, bl
        jne      L_accd
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      dword ptr [g_eventQueueChild], 5
        mov      dword ptr [g_baseSel], eax
        mov      eax, 0x50b7e0
        shr      eax, 2
        mov      dword ptr [g_eventQueueNotMask], ebp
        mov      dword ptr [esp + 0x10], eax
        mov      dword ptr [g_xformEntityIdx], eax
        call     DispatcherComplex260_MStackBracket1_TreeWalkRecursive2
        cmp      dword ptr [g_framePauseFlag], ebp
        jne      L_acd2
        mov      edi, 0x40
        mov      esi, 2
    L_aa0a:
        test     byte ptr [g_xformDirtyFlags], 4
        jne      L_acbb
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      dword ptr [g_fightGroupHead], eax
        mov      eax, dword ptr [eax*4 + 0x18]
        mov      dword ptr [g_walkCallback], ebx
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4 + 0x1c], ebx
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      edx, dword ptr [eax*4 + 0x20]
        or       dh, 6
        mov      dword ptr [eax*4 + 0x20], edx
        mov      ecx, dword ptr [g_eventQueueNotMask]
        mov      edx, dword ptr [g_baseSel]
        lea      eax, [ecx + edx + 0xc]
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      dword ptr [g_xformEntityIdx], eax
        mov      dword ptr [eax*4], ecx
        mov      edx, dword ptr [g_fightGroupHead]
        mov      dword ptr [g_walkCallback], edi
        mov      dword ptr [edx*4 + 0x30], edi
        mov      eax, dword ptr [g_fightGroupHead]
        mov      ecx, dword ptr [eax*4 + 0x34]
        or       ch, 0x20
        mov      dword ptr [eax*4 + 0x34], ecx
        mov      eax, dword ptr [g_fightGroupHead]
        mov      dword ptr [g_walkCallback], esi
        mov      dword ptr [eax*4 + 0x44], esi
        call     ScaledTripleCopy54
        cmp      dword ptr [g_framePauseFlag], ebp
        jne      L_acd2
        mov      eax, dword ptr [g_mul10TransformVar]
        mov      dword ptr [g_pendingNodeType], eax
        mov      dword ptr [eax*4], ebp
        mov      ecx, dword ptr [g_pendingNodeType]
        mov      dword ptr [ecx*4 + 4], 0xffffe667
        mov      edx, dword ptr [g_pendingNodeType]
        mov      dword ptr [edx*4 + 8], ebp
        mov      eax, dword ptr [g_savedNode]
        mov      dword ptr [g_xformEntityIdx], eax
        mov      dword ptr [g_walkCallback], 0x3243f
        call     StoreDoubleNegPauseSubStore
        cmp      dword ptr [g_framePauseFlag], ebp
        jne      L_acd2
        call     BootMod6487eClampAndChainMul10
        cmp      dword ptr [g_framePauseFlag], ebp
        jne      L_acd2
        mov      edx, dword ptr [g_xformEntityIdx]
        mov      ecx, dword ptr [g_walkCallback]
        mov      dword ptr [edx*4 + 4], ecx
        mov      dword ptr [g_walkCallback], 0x13333
        call     StoreDoubleNegPauseSubStore
        cmp      dword ptr [g_framePauseFlag], ebp
        jne      L_acd2
        call     BootMod6487eClampAndChainMul10
        cmp      dword ptr [g_framePauseFlag], ebp
        jne      L_acd2
        mov      ecx, dword ptr [g_xformEntityIdx]
        mov      eax, dword ptr [g_walkCallback]
        mov      dword ptr [ecx*4], eax
        mov      edx, dword ptr [g_xformEntityIdx]
        mov      dword ptr [g_walkCallback], ebp
        mov      dword ptr [edx*4 + 8], ebp
        mov      eax, dword ptr [g_dispatchSave6]
        mov      dword ptr [g_currentNodeIdx], eax
        call     Mul10HeavyTransform
        cmp      dword ptr [g_framePauseFlag], ebp
        jne      L_acd2
        mov      edx, dword ptr [g_fightGroupHead]
        mov      ecx, dword ptr [g_currentNodeIdx]
        add      edx, 0x1b
        mov      dword ptr [g_xformEntityIdx], ecx
        mov      dword ptr [g_currentNodeIdx], edx
        call     QuadInterpolator
        cmp      dword ptr [g_framePauseFlag], ebp
        jne      L_acd2
        mov      eax, dword ptr [g_eventQueueEnd]
        mov      dword ptr [g_eventQueueCurrent], 0xffffe000
        mov      eax, dword ptr [eax*4 + 0x6c]
        push     eax
        push     0xffffe000
        mov      dword ptr [g_walkCallback], eax
        call     Mul10Tail
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      dword ptr [g_walkCallback], eax
        add      esp, 8
        add      eax, dword ptr [ecx*4 + 0x6c]
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x6c], eax
        mov      ecx, dword ptr [g_eventQueueEnd]
        mov      edx, dword ptr [g_eventQueueCurrent]
        mov      eax, dword ptr [ecx*4 + 0x74]
        push     eax
        push     edx
        mov      dword ptr [g_walkCallback], eax
        call     Mul10Tail
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      dword ptr [g_walkCallback], eax
        add      esp, 8
        add      eax, dword ptr [ecx*4 + 0x74]
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x74], eax
        mov      eax, dword ptr [g_fightGroupHead]
        mov      dword ptr [g_currentNodeIdx], eax
        call     MStackCall_MStackPush2ChainInsert_004062a0
        cmp      dword ptr [g_framePauseFlag], ebp
        jne      L_acd2
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      dword ptr [g_pendingNodeType], ecx
        call     PendingMatch_AudioMixerStep_0040b020
        cmp      dword ptr [g_framePauseFlag], ebp
        jne      L_acd2
        mov      eax, dword ptr [g_eventQueueNotMask]
        mov      ecx, dword ptr [g_eventQueueChild]
        inc      eax
        cmp      eax, ecx
        mov      dword ptr [g_eventQueueNotMask], eax
        jge      L_acbb
        mov      edx, dword ptr [esp + 0x10]
        mov      dword ptr [g_xformEntityIdx], edx
        call     DispatcherComplex260_MStackBracket1_TreeWalkRecursive2
        cmp      dword ptr [g_framePauseFlag], ebp
        je       L_aa0a
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        pop      ecx
        ret      
    L_acbb:
        mov      eax, dword ptr [g_baseSel]
        mov      ecx, dword ptr [g_eventQueueNotMask]
        mov      dword ptr [eax*4 + 0x14], ecx
    L_accd:
        call     MStackPop8
    L_acd2:
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        pop      ecx
        ret      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        mov      eax, dword ptr [g_baseSel]
        push     esi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        sub      eax, 0
        je       L_ada9
        dec      eax
        je       L_ad45
        mov      ecx, dword ptr [g_baseSel]
        mov      eax, dword ptr [ecx*4 + 0x38]
        sub      eax, 0x20
        mov      dword ptr [g_walkCallback], eax
        jns      L_ad28
        xor      eax, eax
        mov      dword ptr [g_walkCallback], eax
    L_ad28:
        mov      dword ptr [ecx*4 + 0x38], eax
        mov      eax, dword ptr [g_eventQueueNotMask]
        dec      eax
        test     eax, eax
        mov      dword ptr [g_eventQueueNotMask], eax
        jg       L_ad62
        call     GuardedSeq_MStackCall_then_CallSetPause_00471670
        pop      esi
        ret      
    L_ad45:
        mov      eax, dword ptr [g_eventQueueNotMask]
        dec      eax
        test     eax, eax
        mov      dword ptr [g_eventQueueNotMask], eax
        jg       L_ade8
        mov      dword ptr [g_eventQueueNotMask], 8
    L_ad62:
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      edx, dword ptr [ecx*4 + 0x18]
        mov      dword ptr [g_currentNodeIdx], edx
        call     ChainListVecAdd
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_ae25
        mov      eax, 1
        mov      dword ptr [esi + 8], 0x40ace0
        mov      dword ptr [esi + 0x84], 2
        mov      dword ptr [g_pendingNodeType], eax
        mov      dword ptr [g_framePauseFlag], eax
        pop      esi
        ret      
    L_ada9:
        call     MStackScopedSlotSetupPair
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_ae25
        mov      eax, dword ptr [g_fightGroupHead]
        mov      ecx, dword ptr [eax*4 + 0x18]
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      eax, dword ptr [ecx*4 + 0x20]
        or       al, 0x40
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x20], eax
        mov      dword ptr [g_eventQueueNotMask], 0x10
    L_ade8:
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      edx, dword ptr [ecx*4 + 0x18]
        mov      dword ptr [g_currentNodeIdx], edx
        call     ChainListVecAdd
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_ae25
        mov      eax, 1
        mov      dword ptr [esi + 8], 0x40ace0
        mov      dword ptr [esi + 0x84], eax
        mov      dword ptr [g_pendingNodeType], eax
        mov      dword ptr [g_framePauseFlag], eax
    L_ae25:
        pop      esi
        ret      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        mov      eax, dword ptr [g_baseSel]
        push     ebx
        push     ebp
        push     edi
        lea      ebp, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [ebp + 0x84], 0
        test     eax, eax
        je       L_aee7
        mov      eax, dword ptr [g_eventQueueChild]
        dec      eax
        test     eax, eax
        mov      dword ptr [g_eventQueueChild], eax
        jg       L_af03
        mov      ecx, dword ptr [g_baseSel]
        mov      dword ptr [g_chainAccumCur], 0
        lea      eax, [ecx + 0xc]
        mov      dword ptr [g_xformEntityIdx], eax
        mov      edx, dword ptr [eax*4]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], edx
        mov      dword ptr [g_xformEntityIdx], eax
        call     MStackPush2ChainLLInsert
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_b014
    L_aea8:
        mov      eax, dword ptr [g_chainAccumCur]
        mov      ecx, dword ptr [g_eventQueueNotMask]
        inc      eax
        cmp      eax, ecx
        mov      dword ptr [g_chainAccumCur], eax
        jge      L_aef0
        mov      eax, dword ptr [g_xformEntityIdx]
        mov      ecx, dword ptr [eax*4]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      dword ptr [g_xformEntityIdx], eax
        call     MStackPush2ChainLLInsert
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        je       L_aea8
        pop      edi
        pop      ebp
        pop      ebx
        ret      
    L_aee7:
        mov      eax, dword ptr [g_eventQueueNotMask]
        test     eax, eax
        jne      L_aef9
    L_aef0:
        call     CallSetPause
        pop      edi
        pop      ebp
        pop      ebx
        ret      
    L_aef9:
        mov      dword ptr [g_eventQueueChild], 0x78
    L_af03:
        mov      edx, dword ptr [g_baseSel]
        mov      dword ptr [g_chainAccumCur], 0
        add      edx, 0xc
        mov      ebx, 0xe5
        mov      dword ptr [g_xformEntityIdx], edx
        mov      edi, 0xffffdfff
    L_af26:
        mov      eax, dword ptr [g_xformEntityIdx]
        mov      ecx, dword ptr [eax*4]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      dword ptr [g_xformEntityIdx], eax
        mov      dword ptr [g_walkCallback], ebx
        mov      eax, dword ptr [ecx*4 + 0x70]
        add      eax, ebx
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x70], eax
        mov      eax, dword ptr [g_currentNodeIdx]
        js       L_afcf
        mov      ecx, dword ptr [eax*4 + 0x58]
        test     ecx, ecx
        mov      dword ptr [g_eventQueueCurrent], ecx
        jl       L_afcf
        mov      eax, dword ptr [g_walkCallback]
        push     eax
        push     0xffff6667
        call     Mul10Tail
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [g_walkCallback], eax
        add      esp, 8
        mov      dword ptr [ecx*4 + 0x70], eax
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      edx, dword ptr [eax*4 + 0x44]
        dec      edx
        mov      dword ptr [eax*4 + 0x44], edx
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      ecx, dword ptr [eax*4 + 0x44]
        test     ecx, ecx
        jge      L_afcf
        mov      ecx, dword ptr [eax*4 + 0x34]
        and      ecx, edi
        mov      dword ptr [eax*4 + 0x34], ecx
        mov      eax, dword ptr [g_currentNodeIdx]
    L_afcf:
        cmp      dword ptr [g_eventQueueChild], 0x14
        jne      L_afdf
        and      dword ptr [eax*4 + 0x34], edi
    L_afdf:
        mov      eax, dword ptr [g_chainAccumCur]
        mov      ecx, dword ptr [g_eventQueueNotMask]
        inc      eax
        cmp      eax, ecx
        mov      dword ptr [g_chainAccumCur], eax
        jl       L_af26
        mov      eax, 1
        mov      dword ptr [ebp + 8], 0x40ae30
        mov      dword ptr [ebp + 0x84], eax
        mov      dword ptr [g_pendingNodeType], eax
        mov      dword ptr [g_framePauseFlag], eax
    L_b014:
        pop      edi
        pop      ebp
        pop      ebx
        ret      
    }
}


__declspec(naked) void PendingMatch_LeaPlus22StoreSelf(void)
{
    __asm {
        push     ebx
        push     ebp
        push     esi
        push     edi
        call     LeaPlus22StoreSelf
        mov      eax, dword ptr [g_baseSel]
        xor      ebp, ebp
        mov      edi, 0x401b70
        mov      ebx, 1
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], ebp
        cmp      eax, 0x14
        ja       L_1c1e
    L_1ba3:
        jmp      dword ptr [eax*4 + L_22fc_jmptbl]
        push     -1
        push     -1
        push     -1
        push     0x16
        call     QuadCallPhase2
        add      esp, 0x10
        push     ebx
        push     ebp
        call     SceneFrameStepWithInputs
        add      esp, 8
        test     eax, eax
        je       L_1d46
        jmp      L_1bf5
        mov      eax, dword ptr [g_pendingMatchAcc]
        inc      eax
        cmp      eax, 4
        mov      dword ptr [g_pendingMatchAcc], eax
        jne      L_2047
        push     ebx
        push     0x23
        call     SceneFrameStepWithInputs
        add      esp, 8
        test     eax, eax
        je       L_2041
    L_1bf5:
        call     LeaPlus22StoreSelf
        mov      ecx, dword ptr [g_baseSel]
        mov      edi, 0x401b70
        mov      eax, dword ptr [ecx*4 + 0x84]
        lea      esi, [ecx*4]
        cmp      eax, 0x14
        mov      dword ptr [esi + 0x84], ebp
        jbe      L_1ba3
    L_1c1e:
        mov      ecx, dword ptr [g_pendingMatchSlot]
        lea      eax, [ecx + 1]
        cmp      eax, 3
        mov      dword ptr [g_pendingMatchSlot], eax
        jbe      L_1c37
        mov      dword ptr [g_pendingMatchSlot2], ebx
    L_1c37:
        push     -1
        push     -1
        push     -1
        push     0x1e
        mov      dword ptr [g_walkCallback], ebp
        mov      dword ptr [g_zerotriple_00541de8], ebp
        mov      dword ptr [g_zerotriple_00541dec], ebp
        mov      dword ptr [g_titleDemoState], ebp
        mov      dword ptr [g_titleDemoState2], ebp
        call     QuadCallPhase2
        mov      dword ptr [esi + 8], edi
        mov      edx, dword ptr [g_baseSel]
        add      edi, 0x3000000
        add      esp, 0x10
        mov      dword ptr [edx*4 + 0x84], 3
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], edi
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      eax, dword ptr [g_baseSel]
        mov      dword ptr [eax*4 + 0x84], ebp
        call     PendingMatch_004a2a80
        mov      dword ptr [g_framePauseFlag], ebx
    L_1cb3:
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        ret      
        push     9
        call     TableWalkBoundedCmp
        add      esp, 4
        mov      dword ptr [g_eventQueueWorkType], ebp
        call     Push16Call
        cmp      dword ptr [g_framePauseFlag], ebp
        jne      L_1cb3
        mov      eax, 2
        mov      dword ptr [g_phaseIdx], ebp
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [g_tickFlagF], eax
        mov      dword ptr [g_eventQueueWorkType], ebp
        call     Push16Call
        cmp      dword ptr [g_framePauseFlag], ebp
        jne      L_1cb3
        call     ZeroMultiGlobalsCmp
        cmp      dword ptr [g_framePauseFlag], ebp
        jne      L_1cb3
        mov      dword ptr [g_walkCallback], ebp
        mov      dword ptr [g_pendingMatchSlot2], ebp
        mov      dword ptr [g_pendingMatchSlot], ebp
        mov      dword ptr [g_active_0053a408], ebp
        mov      dword ptr [g_active_00537e88], ebp
        mov      dword ptr [esi + 8], edi
        mov      dword ptr [esi + 0x84], 2
        mov      dword ptr [g_pendingNodeType], ebx
        mov      dword ptr [g_framePauseFlag], ebx
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        ret      
    L_1d46:
        mov      dword ptr [g_eventQueueWorkType], ebp
        call     Push16Call
        cmp      dword ptr [g_framePauseFlag], ebp
        jne      L_1cb3
        push     -1
        push     -1
        push     -1
        push     0x1e
        call     QuadCallPhase2
        mov      dword ptr [esi + 8], edi
        mov      edx, dword ptr [g_baseSel]
        add      edi, 0x5000000
        add      esp, 0x10
        mov      dword ptr [edx*4 + 0x84], 5
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], edi
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      eax, dword ptr [g_baseSel]
        mov      dword ptr [eax*4 + 0x84], ebp
        call     PhaseInstallSelf3Step
        mov      dword ptr [g_framePauseFlag], ebx
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        ret      
        mov      dword ptr [esi + 8], edi
        mov      ecx, dword ptr [g_baseSel]
        add      edi, 0x6000000
        mov      dword ptr [ecx*4 + 0x84], 6
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], edi
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      edx, dword ptr [g_baseSel]
        mov      dword ptr [edx*4 + 0x84], ebp
        call     PendingMatch_Push16Call_00402540
        mov      dword ptr [g_framePauseFlag], ebx
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        ret      
        mov      dword ptr [g_walkCallback], 0x64
        call     AudioVolumeRescale
        mov      al, byte ptr [g_xformDirtyFlags]
        mov      dword ptr [esi + 8], edi
        test     al, bl
        je       L_1e52
        mov      eax, dword ptr [g_baseSel]
        add      edi, 0x7000000
        mov      dword ptr [eax*4 + 0x84], 7
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_currentNodeIdx], eax
        jmp      L_2251
    L_1e52:
        mov      edx, dword ptr [g_baseSel]
        add      edi, 0x9000000
        mov      dword ptr [edx*4 + 0x84], 9
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_currentNodeIdx], eax
        jmp      L_2069
        mov      dword ptr [esi + 8], edi
        mov      ecx, dword ptr [g_baseSel]
        add      edi, 0x8000000
        mov      dword ptr [ecx*4 + 0x84], 8
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], edi
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      edx, dword ptr [g_baseSel]
        mov      dword ptr [edx*4 + 0x84], ebp
        call     TitleDemoStateMachine
        mov      dword ptr [g_framePauseFlag], ebx
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        ret      
        mov      dword ptr [esi + 8], edi
        mov      eax, dword ptr [g_baseSel]
        add      edi, 0xa000000
        mov      dword ptr [eax*4 + 0x84], 0xa
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], edi
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      ecx, dword ptr [g_baseSel]
        mov      dword ptr [ecx*4 + 0x84], ebp
        call     BootStateMachine4Way
        mov      dword ptr [g_framePauseFlag], ebx
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        ret      
        push     8
        call     TableWalkBoundedCmp
        add      esp, 4
        push     -1
        push     -1
        push     -1
        push     0x1c
        call     QuadCallPhase2
        mov      dword ptr [esi + 8], edi
        mov      edx, dword ptr [g_baseSel]
        add      edi, 0xb000000
        add      esp, 0x10
        mov      dword ptr [edx*4 + 0x84], 0xb
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], edi
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      eax, dword ptr [g_baseSel]
        mov      dword ptr [eax*4 + 0x84], ebp
        call     Screen_GreatestWarrior
        mov      dword ptr [g_framePauseFlag], ebx
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        ret      
        push     -1
        push     -1
        push     -1
        push     0x1e
        call     QuadCallPhase2
        mov      dword ptr [esi + 8], edi
        mov      ecx, dword ptr [g_baseSel]
        add      edi, 0xc000000
        add      esp, 0x10
        mov      dword ptr [ecx*4 + 0x84], 0xc
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], edi
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      edx, dword ptr [g_baseSel]
        mov      dword ptr [edx*4 + 0x84], ebp
        call     Screen_BestKombatants
        mov      dword ptr [g_framePauseFlag], ebx
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        ret      
        mov      dword ptr [esi + 8], edi
        mov      eax, dword ptr [g_baseSel]
        add      edi, 0xd000000
        mov      dword ptr [eax*4 + 0x84], 0xd
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], edi
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      ecx, dword ptr [g_baseSel]
        mov      dword ptr [ecx*4 + 0x84], ebp
        call     BootInitVec3PhaseInstall
        mov      dword ptr [g_framePauseFlag], ebx
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        ret      
    L_2041:
        mov      dword ptr [g_pendingMatchAcc], ebp
    L_2047:
        mov      dword ptr [esi + 8], edi
        mov      edx, dword ptr [g_baseSel]
        add      edi, 0xe000000
        mov      dword ptr [edx*4 + 0x84], 0xe
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_currentNodeIdx], eax
    L_2069:
        mov      dword ptr [eax*4], edi
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      eax, dword ptr [g_baseSel]
        mov      dword ptr [eax*4 + 0x84], ebp
        call     BootStateInitWithRecurseInstall
        mov      dword ptr [g_framePauseFlag], ebx
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        ret      
        mov      dword ptr [esi + 8], edi
        mov      ecx, dword ptr [g_baseSel]
        add      edi, 0xf000000
        mov      dword ptr [ecx*4 + 0x84], 0xf
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], edi
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      edx, dword ptr [g_baseSel]
        mov      dword ptr [edx*4 + 0x84], ebp
        call     BootStateMachine4Way
        mov      dword ptr [g_framePauseFlag], ebx
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        ret      
        push     8
        call     TableWalkBoundedCmp
        add      esp, 4
        push     -1
        push     -1
        push     -1
        push     0x1e
        call     QuadCallPhase2
        add      esp, 0x10
        push     ebp
        push     0x4a2180
        call     StoreTwoCall
        add      esp, 8
        push     -1
        push     -1
        push     -1
        push     0x1c
        call     QuadCallPhase2
        mov      dword ptr [esi + 8], edi
        mov      eax, dword ptr [g_baseSel]
        add      edi, 0x10000000
        add      esp, 0x10
        mov      dword ptr [eax*4 + 0x84], 0x10
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], edi
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      ecx, dword ptr [g_baseSel]
        mov      dword ptr [ecx*4 + 0x84], ebp
        call     Screen_GreatestWarrior
        mov      dword ptr [g_framePauseFlag], ebx
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        ret      
        push     -1
        push     -1
        push     -1
        push     0x1e
        call     QuadCallPhase2
        mov      dword ptr [esi + 8], edi
        mov      edx, dword ptr [g_baseSel]
        add      edi, 0x11000000
        add      esp, 0x10
        mov      dword ptr [edx*4 + 0x84], 0x11
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], edi
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      eax, dword ptr [g_baseSel]
        mov      dword ptr [eax*4 + 0x84], ebp
        call     Screen_BestKombatants
        mov      dword ptr [g_framePauseFlag], ebx
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        ret      
        mov      dword ptr [esi + 8], edi
        mov      ecx, dword ptr [g_baseSel]
        add      edi, 0x12000000
        mov      dword ptr [ecx*4 + 0x84], 0x12
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], edi
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      edx, dword ptr [g_baseSel]
        mov      dword ptr [edx*4 + 0x84], ebp
        call     InstallSelfCounter
        mov      dword ptr [g_framePauseFlag], ebx
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        ret      
        mov      dword ptr [esi + 8], edi
        mov      eax, dword ptr [g_baseSel]
        add      edi, 0x13000000
        mov      dword ptr [eax*4 + 0x84], 0x13
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_currentNodeIdx], eax
    L_2251:
        mov      dword ptr [eax*4], edi
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      ecx, dword ptr [g_baseSel]
        mov      dword ptr [ecx*4 + 0x84], ebp
        call     BootStateInitWithRecurseInstall
        mov      dword ptr [g_framePauseFlag], ebx
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        ret      
        mov      dword ptr [esi + 8], edi
        mov      edx, dword ptr [g_baseSel]
        add      edi, 0x14000000
        mov      dword ptr [edx*4 + 0x84], 0x14
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], edi
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      eax, dword ptr [g_baseSel]
        mov      dword ptr [eax*4 + 0x84], ebp
        call     TitleDemoStateMachine
        mov      dword ptr [g_framePauseFlag], ebx
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        ret      
        mov      dword ptr [g_walkCallback], ebp
        call     CopyGlobal
        mov      dword ptr [esi + 8], edi
        mov      dword ptr [esi + 0x84], ebx
        pop      edi
        pop      esi
        mov      dword ptr [g_pendingNodeType], ebx
        mov      dword ptr [g_framePauseFlag], ebx
        pop      ebp
        pop      ebx
        ret      
        nop      
    L_22fc_jmptbl:
        /* 21-entry jump table */
        _emit    0xd6
        _emit    0x22
        _emit    0x40
        _emit    0x00
        _emit    0xb8
        _emit    0x1c
        _emit    0x40
        _emit    0x00
        _emit    0x37
        _emit    0x1c
        _emit    0x40
        _emit    0x00
        _emit    0xaa
        _emit    0x1b
        _emit    0x40
        _emit    0x00
        _emit    0x46
        _emit    0x1d
        _emit    0x40
        _emit    0x00
        _emit    0xc0
        _emit    0x1d
        _emit    0x40
        _emit    0x00
        _emit    0x14
        _emit    0x1e
        _emit    0x40
        _emit    0x00
        _emit    0x76
        _emit    0x1e
        _emit    0x40
        _emit    0x00
        _emit    0x1d
        _emit    0x1f
        _emit    0x40
        _emit    0x00
        _emit    0xca
        _emit    0x1e
        _emit    0x40
        _emit    0x00
        _emit    0x1d
        _emit    0x1f
        _emit    0x40
        _emit    0x00
        _emit    0x8a
        _emit    0x1f
        _emit    0x40
        _emit    0x00
        _emit    0xee
        _emit    0x1f
        _emit    0x40
        _emit    0x00
        _emit    0xce
        _emit    0x1b
        _emit    0x40
        _emit    0x00
        _emit    0x9a
        _emit    0x20
        _emit    0x40
        _emit    0x00
        _emit    0xee
        _emit    0x20
        _emit    0x40
        _emit    0x00
        _emit    0x79
        _emit    0x21
        _emit    0x40
        _emit    0x00
        _emit    0xdc
        _emit    0x21
        _emit    0x40
        _emit    0x00
        _emit    0x30
        _emit    0x22
        _emit    0x40
        _emit    0x00
        _emit    0x83
        _emit    0x22
        _emit    0x40
        _emit    0x00
        _emit    0x1e
        _emit    0x1c
        _emit    0x40
        _emit    0x00
    }
}

__declspec(naked) void PendingMatch_StoreTwoCall_004163c0(void)
{
    __asm {
        push     0xb5
        push     0x4163f0
        call     StoreTwoCall
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      ecx, dword ptr [g_fightGroupHead]
        add      esp, 8
        mov      dword ptr [eax*4 + 0x2c], ecx
        ret      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        push     ecx
        mov      eax, dword ptr [g_baseSel]
        push     ebx
        push     ebp
        push     esi
        lea      ebx, [eax*4]
        mov      dword ptr [esp + 0xc], ebx
        mov      eax, dword ptr [ebx + 0x84]
        mov      dword ptr [ebx + 0x84], 0
        test     eax, eax
        je       L_642f
        mov      eax, dword ptr [g_eventQueueIdx]
        dec      eax
        mov      dword ptr [g_eventQueueIdx], eax
        jns      L_6469
        call     CallSetPause
        pop      esi
        pop      ebp
        pop      ebx
        pop      ecx
        ret      
    L_642f:
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      dword ptr [g_eventQueueEnd], ecx
        call     CmpP1ScaledInitB
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_68eb
        mov      edx, dword ptr [g_baseSel]
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      dword ptr [edx*4 + 0x30], eax
        mov      dword ptr [g_eventQueueIdx], 0x1e
    L_6469:
        mov      esi, 0x2666
        mov      dword ptr [g_walkCallback], esi
        call     AudioMixerStep
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_68eb
        mov      ecx, dword ptr [g_walkCallback]
        mov      ebp, 0xe666
        add      ecx, ebp
        mov      dword ptr [g_walkCallback], ecx
        call     ZeroAndDirty4
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_68eb
        test     byte ptr [g_xformDirtyFlags], 4
        je       L_68c3
        mov      ecx, 0x4d7640
        shr      ecx, 2
        mov      dword ptr [g_walkCallback], ecx
        call     PushSetXfmMaskCallPop
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_68eb
        test     byte ptr [g_xformDirtyFlags], 4
        jne      L_68c3
        mov      edx, dword ptr [g_fightGroupHead]
        mov      eax, 0xa5
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [edx*4 + 0x30], eax
        mov      eax, dword ptr [g_matrixStackTop]
        mov      ecx, dword ptr [g_fightGroupHead]
        inc      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], ecx
        mov      edx, dword ptr [g_eventQueueEnd]
        mov      dword ptr [g_fightGroupHead], edx
        call     MStackPush2RunCountdown
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_68eb
        mov      dword ptr [g_walkCallback], 2
        call     ChainDirtyBitWalker
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_68eb
        mov      eax, dword ptr [g_xformEntityIdx]
        shl      eax, 2
        mov      ecx, dword ptr [eax]
        mov      dword ptr [eax + 0x30], 0
        or       ecx, 4
        mov      dword ptr [eax + 0x34], 0xfffff334
        mov      dword ptr [eax], ecx
        mov      ecx, 0xffffe667
        mov      dword ptr [g_walkCallback], ecx
        mov      dword ptr [eax + 0x38], ecx
        call     MStackBracket7_DispatchAndChain
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_68eb
        mov      eax, dword ptr [g_matrixStackTop]
        mov      edx, dword ptr [g_xformEntityIdx]
        mov      ecx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_matrixStackTop], eax
        lea      eax, [edx*4]
        mov      dword ptr [g_fightGroupHead], ecx
        mov      edx, dword ptr [eax + 0x3c]
        shl      ecx, 2
        mov      dword ptr [g_walkCallback], edx
        mov      dword ptr [ecx + 0x54], edx
        mov      edx, dword ptr [eax + 0x40]
        mov      dword ptr [g_walkCallback], edx
        mov      dword ptr [ecx + 0x58], edx
        mov      eax, dword ptr [eax + 0x44]
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx + 0x5c], eax
        mov      eax, dword ptr [g_fightGroupHead]
        mov      ecx, dword ptr [g_baseSel]
        add      eax, 0x15
        mov      dword ptr [g_pendingNodeType], eax
        mov      edx, dword ptr [ecx*4 + 0x30]
        mov      eax, dword ptr [g_savedNode]
        add      edx, 0x15
        mov      dword ptr [g_xformEntityIdx], edx
        mov      dword ptr [g_currentNodeIdx], eax
        call     TripleSubVec3
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_68eb
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      eax, 0x4ccc
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 4], eax
        mov      dword ptr [g_eventQueueCurrent], 0xc000
        mov      dword ptr [g_eventQueueWorkType], 0x14000
        call     TripleMul10TailIndexed
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_68eb
        call     Triple3VecMul10Tail
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_68eb
        mov      eax, dword ptr [g_fightGroupHead]
        mov      edx, dword ptr [g_currentNodeIdx]
        add      eax, 0x1b
        mov      dword ptr [g_walkCallback], 0x1c28
        mov      dword ptr [g_xformEntityIdx], edx
        mov      dword ptr [g_currentNodeIdx], eax
        call     ThreeMul10Stores
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_68eb
        call     SetJmp_BootStateTriple
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_68eb
        mov      ecx, dword ptr [g_xformEntityIdx]
        mov      dword ptr [ecx*4 + 0x48], esi
        mov      dword ptr [ecx*4 + 0x14], 0xe0
        mov      dword ptr [ecx*4 + 0x10], 0x4168f0
        lea      eax, [ecx*4]
        mov      ecx, dword ptr [ecx*4]
        or       ecx, 8
        mov      dword ptr [eax], ecx
        mov      dword ptr [g_eventQueueCurrent], 6
        mov      dword ptr [g_walkCallback], ebp
        call     ZeroAndDirty4
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_68eb
        test     byte ptr [g_xformDirtyFlags], 4
        jne      L_6732
        mov      dword ptr [g_eventQueueCurrent], 4
        mov      dword ptr [g_walkCallback], 0xf333
        call     ZeroAndDirty4
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_68eb
    L_6732:
        mov      edx, dword ptr [g_eventQueueCurrent]
        mov      dword ptr [g_walkCallback], edx
        call     CmpDivJmp
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_68eb
        test     byte ptr [g_xformDirtyFlags], 4
        jne      L_68b5
        mov      eax, dword ptr [g_savedNode]
        mov      ebp, 0x45a
        mov      dword ptr [g_xformEntityIdx], eax
        mov      dword ptr [g_walkCallback], ebp
        lea      esi, [eax*4]
        call     StoreDoubleNegPauseSubStore
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_68eb
        mov      ebx, 0x19999
    L_6790:
        mov      eax, dword ptr [g_walkCallback]
        mov      dword ptr [esi], eax
        mov      dword ptr [g_walkCallback], ebp
        call     StoreDoubleNegPauseSubStore
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_68eb
        mov      ecx, dword ptr [g_walkCallback]
        mov      dword ptr [esi + 4], ecx
        mov      dword ptr [g_walkCallback], ebp
        call     StoreDoubleNegPauseSubStore
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_68eb
        mov      edx, dword ptr [g_walkCallback]
        mov      dword ptr [esi + 8], edx
        call     ScaledTripleCopy10
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_68eb
        mov      eax, dword ptr [g_matrixStackTop]
        mov      ecx, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], ecx
        mov      edx, dword ptr [g_xformEntityIdx]
        mov      dword ptr [g_currentNodeIdx], edx
        mov      dword ptr [g_walkCallback], ebx
        call     ThreeMul10Stores
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_68eb
        mov      eax, dword ptr [g_matrixStackTop]
        mov      ecx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      dword ptr [g_matrixStackTop], eax
        call     ScaledTripleCopy4
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_68eb
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      esi, dword ptr [g_xformDirtyFlags]
        mov      ecx, 4
        mov      eax, dword ptr [edx*4]
        or       esi, ecx
        test     eax, eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [g_xformDirtyFlags], esi
        je       L_68b1
        mov      edx, esi
        xor      edx, ecx
        test     eax, eax
        mov      dword ptr [g_xformDirtyFlags], edx
        je       L_68b1
        mov      eax, dword ptr [g_xformEntityIdx]
        mov      dword ptr [g_walkCallback], ebp
        lea      esi, [eax*4]
        call     StoreDoubleNegPauseSubStore
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        je       L_6790
        pop      esi
        pop      ebp
        pop      ebx
        pop      ecx
        ret      
    L_68b1:
        mov      ebx, dword ptr [esp + 0xc]
    L_68b5:
        call     MStackCall_MStackPush2ChainPrepend_004062f0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_68eb
    L_68c3:
        mov      ecx, dword ptr [g_eventQueueEnd]
        mov      eax, 1
        mov      dword ptr [g_fightGroupHead], ecx
        mov      dword ptr [ebx + 8], 0x4163f0
        mov      dword ptr [ebx + 0x84], eax
        mov      dword ptr [g_pendingNodeType], eax
        mov      dword ptr [g_framePauseFlag], eax
    L_68eb:
        pop      esi
        pop      ebp
        pop      ebx
        pop      ecx
        ret      
        mov      eax, dword ptr [g_matrixStackTop]
        mov      ecx, dword ptr [g_fightGroupHead]
        inc      eax
        push     esi
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_gameMode]
        test     eax, eax
        jne      L_6a7a
        mov      eax, dword ptr [g_matrixStackTop]
        mov      edx, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], edx
        mov      eax, dword ptr [g_matrixStackTop]
        mov      ecx, dword ptr [g_xformEntityIdx]
        inc      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], ecx
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      esi, dword ptr [g_xformDirtyFlags]
        mov      ecx, 4
        mov      eax, dword ptr [edx*4 + 0x2c]
        or       esi, ecx
        test     eax, eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [g_xformDirtyFlags], esi
        je       L_699c
        mov      edx, esi
        xor      edx, ecx
        test     eax, eax
        mov      dword ptr [g_xformDirtyFlags], edx
        je       L_699c
        mov      eax, 0x4d78c8
        shr      eax, 2
        mov      dword ptr [g_xformEntityIdx], eax
        call     LoopUnrolledTripleMul10
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_6aa0
    L_699c:
        mov      eax, dword ptr [g_matrixStackTop]
        mov      ecx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_xformEntityIdx], ecx
        mov      dword ptr [g_matrixStackTop], eax
        mov      edx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_currentNodeIdx], edx
        mov      dword ptr [g_matrixStackTop], eax
        call     ChainWalkPushPop
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_6aa0
        push     0x201000
        call     ThreeChanPackClamp
        mov      eax, dword ptr [g_fightGroupHead]
        add      esp, 4
        push     eax
        call     CopyThreeFields
        mov      ecx, dword ptr [g_fightGroupHead]
        add      esp, 4
        mov      edx, dword ptr [ecx*4 + 0x6c]
        lea      esi, [ecx*4]
        push     edx
        push     0xf70a
        call     Mul10Tail
        add      esp, 8
        mov      dword ptr [esi + 0x6c], eax
        mov      eax, dword ptr [esi + 0x70]
        push     eax
        push     0xf70a
        call     Mul10Tail
        mov      ecx, dword ptr [esi + 0x74]
        add      esp, 8
        mov      dword ptr [esi + 0x70], eax
        push     ecx
        push     0xf70a
        call     Mul10Tail
        mov      dword ptr [esi + 0x74], eax
        mov      eax, dword ptr [g_xformEntityIdx]
        add      esp, 8
        mov      ecx, dword ptr [eax*4 + 0x48]
        add      ecx, 0x28f
        mov      dword ptr [eax*4 + 0x48], ecx
        mov      edx, dword ptr [g_xformEntityIdx]
        mov      eax, dword ptr [edx*4 + 0x48]
        mov      dword ptr [g_walkCallback], eax
        call     ChainListVecAdd
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_6aa0
    L_6a7a:
        call     ClampMulShiftStore
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_6aa0
        mov      eax, dword ptr [g_matrixStackTop]
        mov      ecx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_fightGroupHead], ecx
        mov      dword ptr [g_matrixStackTop], eax
    L_6aa0:
        pop      esi
        ret      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        mov      eax, dword ptr [g_xformEntityIdx]
        add      dword ptr [eax*4 + 0x14], -0x2d
        ret      
        nop      
        nop      
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      eax, 0x30000
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x44], eax
        ret      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        push     ebx
        mov      dword ptr [g_walkCallback], 0xffffffec
        call     MStackInitCallToggle
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_6ca4
        mov      al, byte ptr [g_xformDirtyFlags]
        mov      ebx, 4
        test     al, bl
        je       L_6ca4
        mov      dword ptr [g_walkCallback], 2
        call     DirtyDoubleDeref
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_6ca4
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      ecx, 0x51140c
        shr      ecx, 2
        mov      dword ptr [g_pendingNodeType], eax
        mov      dword ptr [g_xformEntityIdx], ecx
        call     MStackBracket1_TreeWalkRecursive2
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_6ca4
        test     byte ptr [g_xformDirtyFlags], bl
        jne      L_6ca4
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [g_walkCallback], 0xffffffec
        mov      dword ptr [edx*4 + 0x1c], 0xffffffec
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      eax, dword ptr [eax*4]
        mov      dword ptr [g_xformEntityIdx], eax
        mov      dword ptr [eax*4 + 0x1c], 0xffffffeb
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      eax, 0x5e666
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x40], eax
        mov      ecx, dword ptr [g_pendingNodeType]
        mov      eax, dword ptr [ecx*4 + 0x20]
        or       eax, ebx
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x20], eax
        mov      edx, dword ptr [g_pendingNodeType]
        mov      dword ptr [g_xformEntityIdx], edx
        call     Thunk_MStackPush2ChainPrepend
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_6ca4
        mov      dword ptr [g_walkCallback], 0xa
        call     DirtyDoubleDeref
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_6ca4
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      ecx, 0x511444
        shr      ecx, 2
        mov      dword ptr [g_pendingNodeType], eax
        mov      dword ptr [g_xformEntityIdx], ecx
        call     DispatchSetDirtyToggle
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_6ca4
        test     byte ptr [g_xformDirtyFlags], bl
        jne      L_6c40
        mov      edx, 0x511460
        shr      edx, 2
        mov      dword ptr [g_xformEntityIdx], edx
    L_6c40:
        call     MStackBracket1_TreeWalkRecursive2
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_6ca4
        test     byte ptr [g_xformDirtyFlags], bl
        jne      L_6ca4
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      ecx, 0xccc
        shl      eax, 2
        mov      dword ptr [eax + 0x34], ecx
        mov      dword ptr [eax + 0x38], ecx
        mov      ecx, 0x4ccc
        mov      dword ptr [eax + 0x1c], 0xffffffea
        mov      dword ptr [eax + 0x30], 0xffffc000
        mov      dword ptr [eax + 0x3c], 0x13333
        mov      dword ptr [eax + 0x40], 0x3e666
        mov      dword ptr [g_walkCallback], ecx
        mov      dword ptr [eax + 0x44], ecx
        mov      ecx, dword ptr [g_pendingNodeType]
        mov      dword ptr [g_xformEntityIdx], ecx
        call     Thunk_MStackPush2ChainPrepend
    L_6ca4:
        pop      ebx
        ret      
    }
}


#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void PendingMatch_Mul10Tail_00419c90(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = g_eventQueuePending * 4;
  iVar1 = g_currentNodeIdx * 4;
  *(undefined4 *)(iVar1 + 0x30) = *(undefined4 *)(iVar2 + 0x30);
  *(undefined4 *)(iVar1 + 0x34) = *(undefined4 *)(iVar2 + 0x34);
  g_walkCallback = *(undefined4 *)(iVar2 + 0x38);
  *(undefined4 *)(iVar1 + 0x38) = g_walkCallback;
  return;
}
#else
__declspec(naked) void PendingMatch_Mul10Tail_00419c90(void)
{
    __asm {
        mov      ecx, dword ptr [g_xformEntityIdx]
        mov      eax, dword ptr [g_currentNodeIdx]
        shl      ecx, 2
        shl      eax, 2
        mov      edx, dword ptr [ecx + 0x30]
        mov      dword ptr [g_walkCallback], edx
        mov      dword ptr [eax + 0x30], edx
        mov      edx, dword ptr [ecx + 0x34]
        mov      dword ptr [g_walkCallback], edx
        mov      dword ptr [eax + 0x34], edx
        mov      ecx, dword ptr [ecx + 0x38]
        mov      dword ptr [g_walkCallback], ecx
        mov      dword ptr [eax + 0x38], ecx
        ret      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        mov      eax, dword ptr [g_baseSel]
        push     ebp
        push     esi
        push     edi
        lea      ebp, [eax*4]
        xor      edi, edi
        mov      esi, 1
        mov      eax, dword ptr [ebp + 0x84]
        mov      dword ptr [ebp + 0x84], edi
        sub      eax, edi
        je       L_9fe6
        mov      ecx, dword ptr [g_fightGroupHead]
        dec      eax
        je       L_9e23
        mov      eax, dword ptr [ecx*4 + 0x80]
        push     eax
        push     0xfd70
        mov      dword ptr [g_walkCallback], eax
        call     Mul10Tail
        mov      edx, dword ptr [g_fightGroupHead]
        mov      dword ptr [g_walkCallback], eax
        add      esp, 8
        mov      dword ptr [edx*4 + 0x80], eax
        mov      eax, dword ptr [g_eventQueueChild]
        inc      eax
        cmp      eax, 3
        mov      dword ptr [g_eventQueueChild], eax
        jne      L_9d5a
        mov      dword ptr [g_eventQueueChild], edi
        call     BootInitTripleAddChain
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_a361
    L_9d5a:
        mov      eax, dword ptr [g_fightGroupHead]
        mov      ecx, dword ptr [eax*4 + 0x70]
        lea      esi, [eax*4]
        mov      eax, dword ptr [g_dispatchSave563]
        add      eax, ecx
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [esi + 0x70], eax
        js       L_9fc0
        mov      eax, dword ptr [esi + 0x58]
        add      eax, 0x2666
        cmp      eax, edi
        mov      dword ptr [g_walkCallback], eax
        jle      L_9fc0
        mov      eax, 0x1999
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [esi + 0x78], eax
        mov      eax, dword ptr [esi + 0x6c]
        push     eax
        push     0xb333
        mov      dword ptr [g_walkCallback], eax
        call     Mul10Tail
        mov      dword ptr [g_walkCallback], eax
        add      esp, 8
        mov      dword ptr [esi + 0x6c], eax
        mov      eax, dword ptr [esi + 0x74]
        push     eax
        push     0xb333
        mov      dword ptr [g_walkCallback], eax
        call     Mul10Tail
        mov      dword ptr [g_walkCallback], eax
        add      esp, 8
        mov      dword ptr [esi + 0x74], eax
        mov      eax, dword ptr [esi + 0x70]
        push     eax
        push     0xffff4ccd
        mov      dword ptr [g_walkCallback], eax
        call     Mul10Tail
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [esi + 0x70], eax
        mov      eax, dword ptr [g_walkCallback]
        add      esp, 8
        cmp      eax, 0xfffff5c3
        jl       L_9fc0
        call     MStackCall_MStackPush2ChainLLInsert
        cmp      dword ptr [g_framePauseFlag], edi
        je       L_a000
        pop      edi
        pop      esi
        pop      ebp
        ret      
    L_9e23:
        mov      eax, dword ptr [g_dispatchSave563]
        mov      edx, dword ptr [ecx*4 + 0x70]
        add      eax, edx
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x70], eax
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      eax, dword ptr [ecx*4 + 0x80]
        push     eax
        push     0xfae1
        mov      dword ptr [g_walkCallback], eax
        call     Mul10Tail
        mov      edx, dword ptr [g_fightGroupHead]
        mov      dword ptr [g_walkCallback], eax
        add      esp, 8
        mov      dword ptr [edx*4 + 0x80], eax
        mov      eax, dword ptr [g_eventQueueChild]
        inc      eax
        cmp      eax, 4
        mov      dword ptr [g_eventQueueChild], eax
        jne      L_9e96
        mov      dword ptr [g_eventQueueChild], edi
        call     BootInitTripleAddChain
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_a361
    L_9e96:
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      eax, dword ptr [ecx*4 + 0x50]
        cmp      eax, 0xcccc
        mov      dword ptr [g_walkCallback], eax
        jg       L_a348
        mov      eax, dword ptr [g_eventQueueSeed]
        mov      dword ptr [g_eventQueueTotal], eax
        mov      eax, dword ptr [eax*4 + 0x58]
        mov      dword ptr [g_walkCallback], eax
        mov      esi, dword ptr [ecx*4 + 0x58]
        add      eax, esi
        sar      eax, 1
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x58], eax
        call     MStackPush3InitCallChain
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_a361
        mov      eax, dword ptr [g_fightGroupHead]
        mov      eax, dword ptr [eax*4 + 0x70]
        push     eax
        push     0xffff8000
        mov      dword ptr [g_walkCallback], eax
        call     Mul10Tail
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      dword ptr [g_walkCallback], eax
        add      esp, 8
        mov      dword ptr [ecx*4 + 0x70], eax
        mov      edx, dword ptr [g_fightGroupHead]
        mov      eax, dword ptr [edx*4 + 0x6c]
        push     eax
        push     eax
        mov      dword ptr [g_walkCallback], eax
        call     Mul10Tail
        mov      dword ptr [g_walkCallback], eax
        mov      eax, dword ptr [g_fightGroupHead]
        add      esp, 8
        mov      eax, dword ptr [eax*4 + 0x74]
        push     eax
        push     eax
        mov      dword ptr [g_eventQueueWorkType], eax
        call     Mul10Tail
        mov      ecx, dword ptr [g_walkCallback]
        add      esp, 8
        add      eax, ecx
        mov      dword ptr [g_eventQueueWorkType], eax
        call     FpuSqrtMul
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_a361
        mov      ecx, dword ptr [g_walkCallback]
        neg      ecx
        mov      dword ptr [g_walkCallback], ecx
        call     MStackPushNegMul10
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_a361
        mov      edx, dword ptr [g_fightGroupHead]
        mov      eax, dword ptr [g_walkCallback]
        mov      dword ptr [edx*4 + 0x6c], eax
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      edx, dword ptr [g_eventQueueCurrent]
        mov      dword ptr [ecx*4 + 0x74], edx
    L_9fc0:
        mov      esi, 1
        mov      dword ptr [ebp + 8], 0x419cd0
        mov      dword ptr [ebp + 0x84], 2
        mov      dword ptr [g_pendingNodeType], esi
        mov      dword ptr [g_framePauseFlag], esi
        pop      edi
        pop      esi
        pop      ebp
        ret      
    L_9fe6:
        call     BootPhaseGateBracketedInit
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_a361
        test     byte ptr [g_xformDirtyFlags], 4
        je       L_a009
    L_a000:
        call     CallSetPause
        pop      edi
        pop      esi
        pop      ebp
        ret      
    L_a009:
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      dword ptr [g_eventQueueEnd], eax
        mov      dword ptr [eax*4 + 0x30], 0x80
        mov      eax, dword ptr [g_particleEmitterNode]
        mov      ecx, dword ptr [g_eventQueueEnd]
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x3c], eax
        mov      edx, dword ptr [g_fightGroupHead]
        mov      dword ptr [g_eventQueueNotMask], 0x10000
        mov      eax, dword ptr [edx*4 + 0x34]
        and      eax, esi
        mov      dword ptr [g_walkCallback], eax
        je       L_a05f
        mov      dword ptr [g_eventQueueNotMask], 0xffff0000
    L_a05f:
        mov      ecx, dword ptr [g_eventQueueEnd]
        mov      edx, dword ptr [ecx*4 + 0x34]
        or       edx, eax
        mov      eax, 0x147a
        mov      dword ptr [ecx*4 + 0x34], edx
        mov      ecx, dword ptr [g_eventQueueEnd]
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x80], eax
        call     MStackPush2RunCountdown
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_a361
        call     MStackBracket7_DispatchAndChain
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_a361
        mov      dword ptr [g_walkCallback], 2
        call     BootStateTriple
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_a361
        mov      edx, dword ptr [g_xformEntityIdx]
        mov      ecx, dword ptr [g_eventQueueEnd]
        mov      eax, dword ptr [edx*4 + 0x3c]
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x54], eax
        mov      edx, dword ptr [g_xformEntityIdx]
        mov      ecx, dword ptr [g_eventQueueEnd]
        mov      eax, dword ptr [edx*4 + 0x40]
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x58], eax
        mov      edx, dword ptr [g_xformEntityIdx]
        mov      ecx, dword ptr [g_eventQueueEnd]
        mov      eax, dword ptr [edx*4 + 0x44]
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x5c], eax
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      eax, 0x5117c4
        shr      eax, 2
        mov      dword ptr [g_pendingNodeType], edx
        mov      dword ptr [g_xformEntityIdx], eax
        call     FramePauseScaledStore
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_a361
        test     byte ptr [g_xformDirtyFlags], 4
        jne      L_a19c
        mov      ecx, dword ptr [g_currentNodeIdx]
        or       eax, 0xffffffff
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x1c], eax
        mov      edx, dword ptr [g_pendingNodeType]
        mov      dword ptr [g_xformEntityIdx], edx
        call     PendingMatch_Mul10Tail_00419c90
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_a361
        call     PushPopScaled14
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_a361
    L_a19c:
        mov      eax, dword ptr [g_pendingNodeType]
        mov      dword ptr [g_currentNodeIdx], eax
        call     BootChainBidirRecurseWalk
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_a361
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [g_walkCallback], edi
        mov      dword ptr [ecx*4 + 0x30], edi
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      edx, dword ptr [g_walkCallback]
        mov      dword ptr [eax*4 + 0x34], edx
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      edx, dword ptr [g_walkCallback]
        mov      dword ptr [ecx*4 + 0x38], edx
        mov      eax, dword ptr [g_eventQueueEnd]
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [eax*4 + 0x18], ecx
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      eax, dword ptr [g_eventQueueEnd]
        mov      dword ptr [edx*4 + 0x18], eax
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [g_walkCallback], esi
        mov      dword ptr [ecx*4 + 0x1c], esi
        mov      edx, dword ptr [g_fightGroupHead]
        mov      eax, dword ptr [edx*4 + 0x50]
        mov      dword ptr [g_chainAccumCur], eax
        push     eax
        mov      eax, dword ptr [g_dispatchSave564]
        push     eax
        call     Mul10Tail
        mov      ecx, dword ptr [g_eventQueueEnd]
        mov      dword ptr [g_chainAccumCur], eax
        mov      eax, dword ptr [g_eventQueueSeed]
        mov      dword ptr [g_fightGroupHead], ecx
        mov      dword ptr [g_eventQueueTotal], eax
        add      esp, 8
        mov      edx, dword ptr [eax*4 + 0x54]
        mov      dword ptr [g_eventQueueNotMask], edx
        mov      eax, dword ptr [eax*4 + 0x5c]
        mov      dword ptr [g_eventQueueChild], eax
        call     QuadMul10TailFpuChain
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_a361
        mov      ecx, dword ptr [g_eventQueueNotMask]
        mov      edx, dword ptr [g_chainAccumCur]
        push     ecx
        push     edx
        call     Mul10Tail
        mov      ecx, dword ptr [g_chainAccumCur]
        add      esp, 8
        mov      dword ptr [g_eventQueueNotMask], eax
        mov      eax, dword ptr [g_eventQueueChild]
        push     eax
        push     ecx
        call     Mul10Tail
        mov      edx, dword ptr [g_fightGroupHead]
        mov      dword ptr [g_eventQueueChild], eax
        mov      eax, dword ptr [g_eventQueueNotMask]
        add      esp, 8
        mov      dword ptr [edx*4 + 0x6c], eax
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      edx, dword ptr [g_eventQueueChild]
        mov      dword ptr [ecx*4 + 0x74], edx
        mov      eax, dword ptr [g_eventQueueTotal]
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      eax, dword ptr [eax*4 + 0x58]
        mov      dword ptr [g_walkCallback], eax
        mov      edx, dword ptr [ecx*4 + 0x58]
        sub      eax, edx
        mov      edx, dword ptr [g_dispatchSave564]
        push     eax
        push     edx
        mov      dword ptr [g_walkCallback], eax
        call     Mul10Tail
        mov      ecx, dword ptr [g_dispatchSave896]
        add      esp, 8
        sub      eax, ecx
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x70], eax
        call     MStackCall_MStackPush2ChainPrepend_004062f0
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_a361
        mov      dword ptr [g_eventQueueChild], edi
    L_a348:
        mov      dword ptr [ebp + 8], 0x419cd0
        mov      dword ptr [ebp + 0x84], esi
        mov      dword ptr [g_pendingNodeType], esi
        mov      dword ptr [g_framePauseFlag], esi
    L_a361:
        pop      edi
        pop      esi
        pop      ebp
        ret      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        mov      eax, dword ptr [g_baseSel]
        push     esi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        cmp      eax, 8
        ja       L_a5b4
        jmp      dword ptr [eax*4 + L_a5e4_jmptbl]
        push     0x87
        push     0x419cd0
        call     StoreTwoCall
        mov      eax, 1
        mov      dword ptr [esi + 8], 0x41a370
        mov      dword ptr [esi + 0x84], 2
        add      esp, 8
        mov      dword ptr [g_pendingNodeType], eax
        mov      dword ptr [g_framePauseFlag], eax
        pop      esi
        ret      
        call     DualCallPauseAddrSetRecurse_func_004196c0_jj
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_a5df
        mov      eax, 1
        mov      dword ptr [esi + 8], 0x41a370
        mov      dword ptr [esi + 0x84], 3
        mov      dword ptr [g_pendingNodeType], eax
        mov      dword ptr [g_framePauseFlag], eax
        pop      esi
        ret      
        call     BootInstallerPair
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_a5df
        call     DualCallPauseAddrSetRecurse_func_00419b00_jj
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_a5df
        mov      eax, 1
        mov      dword ptr [esi + 8], 0x41a370
        mov      dword ptr [esi + 0x84], 4
        mov      dword ptr [g_pendingNodeType], eax
        mov      dword ptr [g_framePauseFlag], eax
        pop      esi
        ret      
        call     DualCallPauseAddrSetRecurse_func_00419a40_jj
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_a5df
        mov      eax, 1
        mov      dword ptr [esi + 8], 0x41a370
        mov      dword ptr [esi + 0x84], 5
        mov      dword ptr [g_pendingNodeType], eax
        mov      dword ptr [g_framePauseFlag], eax
        pop      esi
        ret      
        mov      dword ptr [g_walkCallback], 8
        call     FlagThunk4EntryDispatcher
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_a5df
        call     DualCallPauseAddrSetRecurse_func_00419980_jj
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_a5df
        mov      eax, 1
        mov      dword ptr [esi + 8], 0x41a370
        mov      dword ptr [esi + 0x84], 6
        mov      dword ptr [g_pendingNodeType], eax
        mov      dword ptr [g_framePauseFlag], eax
        pop      esi
        ret      
        call     DualCallPauseAddrSetRecurse_func_00419780_jj
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_a5df
        mov      eax, 1
        mov      dword ptr [esi + 8], 0x41a370
        mov      dword ptr [esi + 0x84], 7
        mov      dword ptr [g_pendingNodeType], eax
        mov      dword ptr [g_framePauseFlag], eax
        pop      esi
        ret      
        call     DualCallPauseAddrSetRecurse_func_00419840_jj
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_a5df
        mov      eax, 1
        mov      dword ptr [esi + 8], 0x41a370
        mov      dword ptr [esi + 0x84], 8
        mov      dword ptr [g_pendingNodeType], eax
        mov      dword ptr [g_framePauseFlag], eax
        pop      esi
        ret      
        call     TripleChainTailJmp
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_a5df
        mov      eax, 1
        mov      dword ptr [esi + 8], 0x41a370
        mov      dword ptr [esi + 0x84], 9
        mov      dword ptr [g_pendingNodeType], eax
        mov      dword ptr [g_framePauseFlag], eax
        pop      esi
        ret      
        call     ScaledOrAh8CallPauseJmp
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_a5df
        call     BootOneShotMStackPush3
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_a5df
        call     TestByteSelectInit
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_a5df
        mov      eax, 1
        mov      dword ptr [esi + 8], 0x41a370
        mov      dword ptr [esi + 0x84], eax
        mov      dword ptr [g_pendingNodeType], eax
        mov      dword ptr [g_framePauseFlag], eax
        pop      esi
        ret      
    L_a5b4:
        mov      dword ptr [g_walkCallback], 8
        call     FlagThunk4EntryDispatcher
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_a5df
        call     Phase1SlotLinkAndInit
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_a5df
        call     CallSetPause
    L_a5df:
        pop      esi
        ret      
        _emit    0x8d
        _emit    0x49
        _emit    0x00
    L_a5e4_jmptbl:
        /* 9-entry jump table */
        _emit    0x6c
        _emit    0xa5
        _emit    0x41
        _emit    0x00
        _emit    0x9e
        _emit    0xa3
        _emit    0x41
        _emit    0x00
        _emit    0xd2
        _emit    0xa3
        _emit    0x41
        _emit    0x00
        _emit    0x06
        _emit    0xa4
        _emit    0x41
        _emit    0x00
        _emit    0x4c
        _emit    0xa4
        _emit    0x41
        _emit    0x00
        _emit    0x80
        _emit    0xa4
        _emit    0x41
        _emit    0x00
        _emit    0xd0
        _emit    0xa4
        _emit    0x41
        _emit    0x00
        _emit    0x04
        _emit    0xa5
        _emit    0x41
        _emit    0x00
        _emit    0x38
        _emit    0xa5
        _emit    0x41
        _emit    0x00
    }
}
#endif
