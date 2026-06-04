/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
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

extern unsigned int g_dispatchSave790;
extern unsigned int g_dispatchSave791;
extern unsigned int g_savedNode;
extern void AiComboDispatcherCluster(void);
extern void ArgSarStoreJmp(void);
extern void ArgSar_Set0_Jmp(void);
extern void BootInstallPeriodicAudio(void);
extern void CmpDivJmp(void);
extern void CondPickDualStore(void);
extern void CopyThreeFields(void);
extern void DualCmpSwapStore(void);
extern void GuardedSeq_MStackCall_then_CallSetPause_00497450(void);
extern void MStackPush8CallbackInit(void);
extern void PushCallScaledClearJmp(void);
extern void ScaledIndirectJmp_0049c850(void);
extern void ScaledTripleCopy4(void);
extern void SoundSetupLoop(void);
extern void TableLookupCall_g_eventTbl_112(void);
extern void ThreeChanPackClamp(void);
extern void Vec2SumMul10ChainCompute(void);

__declspec(naked) void SweepKickDispatcher(void)
{
    __asm {
        /* === h1 (0x4970f0): event 004f20c0 forwarder === */
        mov      eax, dword ptr [g_baseSel]
        mov      ecx, dword ptr [g_walkCallback]
        mov      dword ptr [eax*4 + 0x74], ecx
        call     CondPickDualStore
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_712b
        call     BootInstallPeriodicAudio
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_712b
        push     OFFSET g_dispatchSave790
        call     ArgSarStoreJmp
        add      esp, 4
    L_712b:
        ret
        nop
        nop
        nop
        nop
        /* === h2 (0x497130): main sweep-kick + 0049d2d0 + 004f20f0 === */
        push     esi
        push     edi
        call     DualCmpSwapStore
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_739c
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      edx, dword ptr [g_player1NodeIdx]
        mov      eax, dword ptr [g_gtPlayerProbe2]
        cmp      ecx, edx
        mov      dword ptr [g_currentNodeIdx], eax
        je       short L_7168
        mov      eax, dword ptr [g_gtPlayerProbe1]
        mov      dword ptr [g_currentNodeIdx], eax
    L_7168:
        mov      edx, dword ptr [eax*4 + 0x74]
        mov      dword ptr [g_eventQueueChild], edx
        call     AiComboDispatcherCluster
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_739c
        mov      ecx, dword ptr [g_eventQueueChild]
        mov      edx, 0x28f
        mov      eax, 0xffffe667
        cmp      ecx, 0x311
        mov      dword ptr [g_eventQueueCurrent], 0x189
        mov      dword ptr [g_eventQueueWorkType], edx
        mov      dword ptr [g_walkCallback], eax
        je       short L_71cc
        cmp      ecx, 0x311
        mov      dword ptr [g_eventQueueCurrent], edx
        je       short L_71cc
        mov      eax, 0xffffcccd
        mov      dword ptr [g_walkCallback], eax
    L_71cc:
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [ecx*4 + 0x70], eax
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      eax, dword ptr [g_eventQueueCurrent]
        mov      dword ptr [edx*4 + 0x4c], eax
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      dword ptr [g_pendingNodeType], eax
        mov      ecx, dword ptr [eax*4 + 0x18]
        mov      dword ptr [g_walkCallback], 1
        mov      dword ptr [g_currentNodeIdx], ecx
        call     CmpDivJmp
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_739c
        test     byte ptr [g_xformDirtyFlags], 4
        jne      short L_729f
        mov      edx, dword ptr [g_pendingNodeType]
        mov      eax, dword ptr [g_savedNode]
        mov      dword ptr [g_xformEntityIdx], eax
        lea      edi, [edx*4]
        lea      esi, [eax*4]
        mov      eax, dword ptr [edi + 0x6c]
        push     eax
        push     0xffff3334
        mov      dword ptr [g_walkCallback], eax
        call     Mul10Tail
        mov      dword ptr [esi], eax
        mov      dword ptr [g_walkCallback], 0
        add      esp, 8
        mov      dword ptr [esi + 4], 0
        mov      edi, dword ptr [edi + 0x74]
        push     edi
        push     0xffff3334
        mov      dword ptr [g_walkCallback], edi
        call     Mul10Tail
        add      esp, 8
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [esi + 8], eax
        call     ScaledTripleCopy4
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_739c
    L_729f:
        mov      eax, dword ptr [g_pendingNodeType]
        mov      eax, dword ptr [eax*4 + 0x18]
        mov      dword ptr [g_currentNodeIdx], eax
        mov      eax, dword ptr [eax*4 + 0x28]
        mov      dword ptr [g_currentNodeIdx], eax
        mov      ecx, dword ptr [eax*4]
        or       ecx, 8
        mov      dword ptr [eax*4], ecx
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      eax, 0xc000
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x48], eax
        mov      eax, dword ptr [g_pendingNodeType]
        mov      ecx, dword ptr [g_baseSel]
        mov      dword ptr [g_currentNodeIdx], eax
        lea      esi, [eax*4]
        mov      eax, dword ptr [ecx*4 + 0x5c]
        mov      dword ptr [g_currentNodeFlags], eax
        mov      edx, dword ptr [ecx*4 + 0x60]
        push     eax
        push     0x3333
        mov      dword ptr [g_xformScratch2088], edx
        call     Mul10Tail
        add      esp, 8
        mov      dword ptr [g_currentNodeFlags], eax
        mov      eax, dword ptr [g_xformScratch2088]
        push     eax
        push     0x3333
        call     Mul10Tail
        mov      ecx, dword ptr [g_currentNodeFlags]
        add      esp, 8
        mov      dword ptr [g_xformScratch2088], eax
        mov      dword ptr [esi + 0x6c], ecx
        mov      edx, dword ptr [g_xformScratch2088]
        push     0x8000
        mov      dword ptr [esi + 0x74], edx
        call     ThreeChanPackClamp
        mov      eax, dword ptr [g_fightGroupHead]
        add      esp, 4
        push     eax
        call     CopyThreeFields
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      edx, dword ptr [g_baseSel]
        add      esp, 4
        mov      eax, 0x30
        mov      dword ptr [g_fightGroupHead], ecx
        mov      dword ptr [g_walkCallback], eax
        push     OFFSET g_dispatchSave791
        mov      dword ptr [edx*4 + 0x5c], eax
        call     ArgSar_Set0_Jmp
        add      esp, 4
    L_739c:
        pop      edi
        pop      esi
        ret
        nop
        /* === h3 (0x4973a0): 413b70 + add + 49bc60 → tail 49c850 === */
        call     MStackPush8CallbackInit
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_73f7
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      eax, dword ptr [ecx*4 + 0x4c]
        mov      dword ptr [g_eventQueueCurrent], eax
        mov      edx, dword ptr [ecx*4 + 0x70]
        add      eax, edx
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x70], eax
        call     Vec2SumMul10ChainCompute
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_73f7
        mov      eax, dword ptr [g_eventQueueCurrent]
        mov      ecx, dword ptr [g_eventQueueWorkType]
        cmp      eax, ecx
        jle      short L_73f7
        jmp      ScaledIndirectJmp_0049c850
    L_73f7:
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        /* === h4 (0x497400): 0x60/0x61 status + 0040bf20 → 497450 === */
        mov      eax, dword ptr [g_xformScratch2088]
        mov      dword ptr [g_walkCallback], 0x60
        cmp      eax, 1
        jne      short L_741e
        mov      dword ptr [g_walkCallback], 0x61
    L_741e:
        call     TableLookupCall_g_eventTbl_112
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_744d
        call     PushCallScaledClearJmp
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_744d
        call     SoundSetupLoop
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_744d
        jmp      GuardedSeq_MStackCall_then_CallSetPause_00497450
    L_744d:
        ret
    }
}
