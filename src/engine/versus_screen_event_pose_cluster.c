/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;
extern unsigned int g_baseSel;
extern unsigned int g_acc_00542078;
extern unsigned int g_cj_0054205c;
extern unsigned int g_gameCountdown;
extern unsigned int g_xformScratch94;
extern unsigned int g_table_00535ddc;
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

extern unsigned int g_dispatchSave927;
extern unsigned int g_dispatchSave928;
extern unsigned int g_dispatchSave145;
extern unsigned int g_dispatchSave72;
extern void ArgSarStoreJmp(void);
extern void CopyJmp_QuadFieldEarlyJmpThenInstall_g_currentNodeIdx(void);
extern void EsiInstallClampAddCall(void);
extern void EsiInstallDecCallChain_StackPopDispatchTagged_004294a0(void);
extern void GuardedPackedSlotInit(void);
extern void GuardedPushCall_CopyJmp_then_ArgSarStoreJmp_0043b980(void);
extern void InstallSelfDoubleMStack(void);
extern void ScaledLitLoadCall_ScaledChainCallPauseSetJmp_then_Wrapper_IterLoad_0048fd30_00480fe0(void);
extern void ScaledLoadIncJmp_set_g_eventQueueCurrent_then_ScaledArrStore_EsiInstallBitCallChain(void);
extern void SfxAttenuateAndApply(void);
extern void StateMachine4ArmCascade(void);

__declspec(naked) void VersusScreenEventPoseCluster(void)
{
    __asm {
        /* === h1 (0x43b680): event 004e4c20 forwarder === */
        call     CopyJmp_QuadFieldEarlyJmpThenInstall_g_currentNodeIdx
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_b69b
        push     OFFSET g_dispatchSave927
        call     ArgSarStoreJmp
        add      esp, 4
    L_b69b:
        ret
        nop
        nop
        nop
        nop
        /* === h2 (0x43b6a0): pose-fn 3-state FSM === */
    L_b6a0:
        mov      eax, dword ptr [g_baseSel]
        push     esi
        push     edi
        xor      edi, edi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], edi
        sub      eax, edi
        je       L_b7a3
        dec      eax
        je       short L_b731
        dec      eax
        je       short L_b6d3
        call     StateMachine4ArmCascade
        pop      edi
        pop      esi
        ret
    L_b6d3:
        /* state 2: install state 3 via 428d00 */
        mov      dword ptr [esi + 8], OFFSET L_b6a0
        mov      ecx, dword ptr [g_baseSel]
        mov      edx, OFFSET L_b6a0
        mov      dword ptr [ecx*4 + 0x84], 3
        mov      eax, dword ptr [esi + 4]
        add      edx, 0x3000000
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], edx
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      eax, dword ptr [g_baseSel]
        mov      dword ptr [eax*4 + 0x84], edi
        call     ScaledLoadIncJmp_set_g_eventQueueCurrent_then_ScaledArrStore_EsiInstallBitCallChain
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        ret
    L_b731:
        /* state 1: install state 2 via 43b9a0 */
        mov      dword ptr [g_eventQueueNotMask], 5
        mov      dword ptr [g_eventQueueChild], 0x23
        mov      dword ptr [esi + 8], OFFSET L_b6a0
        mov      ecx, dword ptr [g_baseSel]
        mov      edx, OFFSET L_b6a0
        mov      dword ptr [ecx*4 + 0x84], 2
        mov      eax, dword ptr [esi + 4]
        add      edx, 0x2000000
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], edx
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      eax, dword ptr [g_baseSel]
        mov      dword ptr [eax*4 + 0x84], edi
        call     InstallSelfDoubleMStack
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        ret
    L_b7a3:
        /* state 0: 0x5fa init + 48f50/45f8d0/428760 → install state 1 */
        mov      dword ptr [g_eventQueueWorkType], 0x5fa
        call     Push16Call
        call     FiveCallScaledChainTailJmp
        cmp      dword ptr [g_framePauseFlag], edi
        jne      short L_b83a
        push     OFFSET g_dispatchSave72
        call     GuardedPackedSlotInit
        mov      eax, dword ptr [g_framePauseFlag]
        add      esp, 4
        cmp      eax, edi
        jne      short L_b83a
        mov      dword ptr [g_eventQueueChild], 9
        mov      dword ptr [esi + 8], OFFSET L_b6a0
        mov      ecx, dword ptr [g_baseSel]
        mov      edx, OFFSET L_b6a0
        add      edx, 0x1000000
        mov      dword ptr [ecx*4 + 0x84], 1
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], edx
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      eax, dword ptr [g_baseSel]
        mov      dword ptr [eax*4 + 0x84], edi
        call     EsiInstallDecCallChain_StackPopDispatchTagged_004294a0
        mov      dword ptr [g_framePauseFlag], 1
    L_b83a:
        pop      edi
        pop      esi
        ret
        nop
        nop
        nop
        /* === h3 (0x43b840): event 004e4c38 forwarder + pose install === */
    L_b840:
        mov      eax, dword ptr [g_baseSel]
        push     esi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        test     eax, eax
        je       short L_b876
        push     OFFSET g_dispatchSave928
        call     ArgSarStoreJmp
        mov      eax, dword ptr [g_framePauseFlag]
        add      esp, 4
        pop      esi
        ret
    L_b876:
        mov      dword ptr [g_eventQueueWorkType], 0x604
        call     Push16Call
        call     FiveCallScaledChainTailJmp
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_b919
        mov      ecx, OFFSET g_dispatchSave145
        mov      dword ptr [g_currentNodeFlags], 0x3333
        shr      ecx, 2
        mov      dword ptr [g_eventQueueNotMask], 0
        mov      dword ptr [g_eventQueueEnd], ecx
        mov      dword ptr [esi + 8], OFFSET L_b840
        mov      edx, dword ptr [g_baseSel]
        mov      ecx, OFFSET L_b840
        mov      dword ptr [edx*4 + 0x84], 1
        mov      eax, dword ptr [esi + 4]
        add      ecx, 0x1000000
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      edx, dword ptr [g_baseSel]
        mov      dword ptr [edx*4 + 0x84], 0
        call     EsiInstallClampAddCall
        mov      dword ptr [g_framePauseFlag], 1
    L_b919:
        pop      esi
        ret
        nop
        nop
        nop
        nop
        nop
        /* === h4 (0x43b920): pre-pose chain → tail 43b980 === */
        call     MStackPush3CmpCall
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_b971
        test     byte ptr [g_xformDirtyFlags], 1
        je       short L_b93c
        jmp      GuardedPushCall_CopyJmp_then_ArgSarStoreJmp_0043b980
    L_b93c:
        mov      dword ptr [g_walkCallback], 0x3d70
        call     SfxAttenuateAndApply
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_b971
        mov      dword ptr [g_walkCallback], 0x88
        call     ScaledLitLoadCall_ScaledChainCallPauseSetJmp_then_Wrapper_IterLoad_0048fd30_00480fe0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_b971
        jmp      GuardedPushCall_CopyJmp_then_ArgSarStoreJmp_0043b980
    L_b971:
        ret
    }
}
