/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_currentNodeIdx;
extern unsigned int g_baseSel;
extern unsigned int g_acc_00542078;
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
extern unsigned int g_zero_00541fa4;
extern unsigned int g_zero_00541fa8;
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

extern unsigned int g_dispatchSave591;
extern unsigned int g_dispatchSave590;
extern unsigned int g_dispatchSave588;
extern unsigned int g_dispatchSave587;
extern unsigned int g_dispatchSave586;
extern unsigned int g_dispatchSave585;
extern unsigned int g_dispatchSave584;
extern void ArgSarStoreJmp(void);
extern void CallPauseScaledStoreJmp_CopyJmp_GuardedChainPushSetCallPop_g_currentNodeIdx_then_CallPauseDirty1JmpDirty4StackPush(void);
extern void CjTableThresholdDispatch(void);
extern void GateDispatch6c(void);
extern void GuardedPushCall_Wrapper_ScaledChainPushCall_then_ArgSarStoreJmp(void);
extern void ScaledMove48to58(void);
extern void SixBlockCjCascade(void);
extern void TableLookupCall_g_eventTbl_19(void);
extern void Wrapper_ScaledChainPushCall_004ef920(void);

__declspec(naked) void StageGameProgressCluster(void)
{
    __asm {
        /* H1 */
        mov      dword ptr [g_walkCallback], 2
        jmp      TableLookupCall_g_eventTbl_19
        nop
        /* H2 */
        call     ScaledMove48to58
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_27ab
        push     OFFSET g_dispatchSave591
        call     ArgSarStoreJmp
        add      esp, 4
    L_27ab:
        ret
        nop
        nop
        nop
        nop
        /* H3 */
        call     GateDispatch6c
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_27cb
        push     OFFSET g_dispatchSave590
        call     ArgSarStoreJmp
        add      esp, 4
    L_27cb:
        ret
        nop
        nop
        nop
        nop
        /* H4 */
        call     GateDispatch6c
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_27eb
        push     OFFSET g_dispatchSave588
        call     ArgSarStoreJmp
        add      esp, 4
    L_27eb:
        ret
        nop
        nop
        nop
        nop
        /* H5 (L_27f0): per-entity FSM init */
    L_27f0:
        mov      eax, dword ptr [g_baseSel]
        xor      edx, edx
        shl      eax, 2
        mov      ecx, dword ptr [eax + 0x84]
        mov      dword ptr [eax + 0x84], edx
        cmp      ecx, edx
        je       short L_280f
        jmp      LiteralPushCallEntZero
    L_280f:
        mov      ecx, dword ptr [g_fightGroupHead]
        push     edi
        mov      edi, OFFSET L_27f0
        mov      ecx, dword ptr [ecx*4 + 0x28]
        add      edi, 0x1000000
        mov      dword ptr [g_eventQueueCurrent], ecx
        mov      dword ptr [eax + 8], OFFSET L_27f0
        mov      ecx, dword ptr [g_baseSel]
        mov      dword ptr [ecx*4 + 0x84], 1
        mov      ecx, dword ptr [eax + 4]
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      dword ptr [ecx*4], edi
        mov      ecx, dword ptr [g_currentNodeIdx]
        inc      ecx
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      dword ptr [eax + 4], ecx
        mov      eax, dword ptr [g_baseSel]
        mov      dword ptr [eax*4 + 0x84], edx
        call     CallPauseScaledStoreJmp_CopyJmp_GuardedChainPushSetCallPop_g_currentNodeIdx_then_CallPauseDirty1JmpDirty4StackPush
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
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
        /* H6 */
        call     CjTableThresholdDispatch
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_28ab
        push     OFFSET g_dispatchSave587
        call     ArgSarStoreJmp
        add      esp, 4
    L_28ab:
        ret
        nop
        nop
        nop
        nop
        /* H7 */
        call     CjTableThresholdDispatch
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_28cb
        push     OFFSET g_dispatchSave586
        call     ArgSarStoreJmp
        add      esp, 4
    L_28cb:
        ret
        nop
        nop
        nop
        nop
        /* H8 */
        call     CjTableThresholdDispatch
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_2923
        call     GateDispatch6c
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_2923
        call     SixBlockCjCascade
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_2923
        test     byte ptr [g_xformDirtyFlags], 1
        je       short L_2908
        jmp      GuardedPushCall_Wrapper_ScaledChainPushCall_then_ArgSarStoreJmp
    L_2908:
        call     Wrapper_ScaledChainPushCall_004ef920
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_2923
        push     OFFSET g_dispatchSave585
        call     ArgSarStoreJmp
        add      esp, 4
    L_2923:
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
        /* H9 */
        call     CjTableThresholdDispatch
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_2983
        call     GateDispatch6c
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_2983
        call     SixBlockCjCascade
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_2983
        test     byte ptr [g_xformDirtyFlags], 1
        je       short L_2968
        jmp      GuardedPushCall_Wrapper_ScaledChainPushCall_then_ArgSarStoreJmp
    L_2968:
        call     Wrapper_ScaledChainPushCall_004ef920
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_2983
        push     OFFSET g_dispatchSave584
        call     ArgSarStoreJmp
        add      esp, 4
    L_2983:
        ret
    }
}
