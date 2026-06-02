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
extern void SetJmp_0049cb90(void);
extern void Thunk_0049cbd0(void);
extern void ScaledZeroFour(void);
extern void WalkCbSubMul10_00431d50(void);
extern void Mul10Tail(unsigned int a, unsigned int b);
extern void BootMod6487eClampAndChainMul10(void);
extern void SpawnListBatchLoader_00477710(void);
extern void MStackPush2TableNot(void);
extern void GuardedChainCmpDualBitXor(void);
extern void ScaledLoadDecJmp_00429710(void);
extern void ScaledStoreCurDirtyClear_004296f0(void);
extern void MStackBitmaskIncMod_00492450(void);
extern void MStackBitmaskUpdate_00492510(void);
extern void Push1eCallTestDirtyLoop_004923b0(void);
extern void MStackLoopFieldInit_00492280(void);
extern void TaggedSceneDispatch(void);
extern void CallPauseDirty4StackPushFn_004839d0(void);
extern void CallPauseDirty1JmpDirty4StackPush_00483a80(void);
extern void Cmp2CallDirtyCall(void);
extern void QuadBlockArgInstallChain(void);
extern void InstallSelfChainSet84_80CallW_004363f0(void);
extern void Wrapper_00436490(void);
extern void MoveFsmCluster_004364a0(void);
extern void CallPauseTestByteJmpCalls(void);
extern void InstallSelfFullPath(void);
extern void InstallSelfCountdownChain_0047a950(void);
extern void CopyJmp_0048ef90(void);
extern void DualTestDirtyToggle_004282c0(void);
extern void TripleVecAccCallStore(void);
extern void Thunk_004bd5c0(void);
extern void AllocSlotPushTripleGlobals(void);
extern void MStackPop4Rewrite(void);
extern void Push70CallScaleArith(void);
extern void StreamChainStringInstall(void);
extern void MStackFrameCdeclDouble(void);
extern void ChainTableWalkStore_004917e0(void);
extern void Push16Call(void);
extern void DispatcherComplex260_00407030(void);
extern void ScaledLoadCmpStoreXfm_0048f2a0(void);
extern void StackPopDispatchTagged(void);
extern unsigned int g_cj_00542058;
extern unsigned int g_rangeSqLimit;
extern unsigned int g_zero_00541fa4;
extern unsigned int g_zero_00541fa8;
extern unsigned int g_dualBitGate;
extern unsigned int g_eventArmReload;
extern unsigned int g_rangeBase;

extern void ScaledArrStore_004298c0(void);
extern void DualFieldAddSubStore(void);
extern void IterStepDualStore(int);
extern void ScaledXorStore_004900f0(void);
extern void ChainWalkInstall(void);
extern void FpuSqrtMul(void);
extern void PendingMatch_0042b930(void);
extern void MStackPush2RunCountdown(void);
extern void MStackBracket7_DispatchAndChain(void);
extern void MStackBracketed3StoreCall(void);
extern void ChainDirtyBitWalker(void);
extern void Wrapper_0048a350(void);
extern void Wrapper_0048a3a0(void);
extern void Helper_DownloadSetup(void);
extern void MStackPush3CmpCall(void);
extern void Wrapper_0048ec20(void);
extern void FiveCallScaledChainTailJmp(void);
extern void SetJmp_00438f50(void);
extern void SetJmp_00438f60(void);
extern void GuardedDispatch_0042b6c0(void);
extern void MStackPushZeroCallPop_00407d00(void);
extern void DirtyToggleByGate(void);
extern void GameDispatchValidateState(void);
extern void CrouchAttackFsmCluster(void);
extern void MStackPushVec3Mul10(void);
extern void LiteralPushCallEntZero(void);
extern void LeaPlus22StoreSelf(void);
extern void IterLoad_00491050(void);
extern void GuardedDualConst2AndToggle(void);
extern void CallPauseScaledStorePushCall(void);
extern void LoadGeoAsset_Default(void);
extern void DispatcherComplex260_00407400(void);
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

extern unsigned int g_dispatchSave643_004f2178;
extern unsigned int g_dispatchSave642_004f2190;
extern unsigned int g_dispatchSave641_004f21a0;
extern void ArgSarStoreJmp(void);
extern void ArgSar_Set0_Jmp_0049c6f0(void);
extern void CondPickDualStore_0049c670(void);
extern void DualCmpSwapStore_0049c5a0(void);
extern void FiveCallGuardSetTail_0046f6b0(void);
extern void PushChainAddCallPop_00493c80(void);
extern void ScaledIndirectJmp_0049c850(void);
extern void ScaledLoadIncJmp_00428d00(void);
extern void StageEventCluster_00497e80(void);
extern void SweepCluster_004984e0(void);
extern void TripleBlockChainDiffMStackThunks_0049ca10(void);
extern void Vec2SumMul10ChainCompute_0049bc60(void);

__declspec(naked) void PunchDispatcherCluster_00497b50(void)
{
    __asm {
        /* === h1 (0x497b50): event 004f2178 forwarder === */
        mov      ecx, dword ptr [g_baseSel]
        mov      eax, 0x316
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x74], eax
        mov      edx, dword ptr [g_baseSel]
        mov      ecx, dword ptr [edx*4 + 4]
        lea      eax, [edx*4 + 4]
        mov      edx, dword ptr [g_eventQueueChild]
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      dword ptr [ecx*4], edx
        mov      ecx, dword ptr [g_currentNodeIdx]
        inc      ecx
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      dword ptr [eax], ecx
        call     CondPickDualStore_0049c670
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_7bb8
        push     OFFSET g_dispatchSave643_004f2178
        call     ArgSarStoreJmp
        add      esp, 4
    L_7bb8:
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        /* === h2 (0x497bc0): pose-fn install state 1 w/ timer + 428d00 === */
    L_7bc0:
        mov      eax, dword ptr [g_baseSel]
        push     esi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        test     eax, eax
        je       short L_7be9
        call     FiveCallGuardSetTail_0046f6b0
        pop      esi
        ret
    L_7be9:
        call     SweepCluster_004984e0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_7ca3
        mov      ecx, dword ptr [g_baseSel]
        push     0x51
        push     OFFSET L_7cb0
        mov      eax, dword ptr [ecx*4 + 4]
        dec      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      edx, dword ptr [eax*4]
        mov      dword ptr [g_eventQueueChild], edx
        mov      dword ptr [ecx*4 + 4], eax
        call     StoreTwoCall
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      ecx, dword ptr [g_fightGroupHead]
        add      esp, 8
        mov      dword ptr [eax*4 + 0x28], ecx
        mov      dword ptr [esi + 8], OFFSET L_7bc0
        mov      edx, dword ptr [g_baseSel]
        mov      ecx, OFFSET L_7bc0
        add      ecx, 0x1000000
        mov      dword ptr [edx*4 + 0x84], 1
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      edx, dword ptr [g_baseSel]
        mov      dword ptr [edx*4 + 0x84], 0
        call     ScaledLoadIncJmp_00428d00
        mov      dword ptr [g_framePauseFlag], 1
    L_7ca3:
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
        /* === h3 (0x497cb0): resume entry - 0x9999 + 0x3d70 ratio === */
    L_7cb0:
        mov      eax, dword ptr [g_matrixStackTop]
        mov      ecx, dword ptr [g_eventQueueEnd]
        inc      eax
        push     esi
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], ecx
        call     DualCmpSwapStore_0049c5a0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_7e3c
        mov      eax, dword ptr [g_matrixStackTop]
        mov      ecx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      eax, dword ptr [g_eventQueueIdx]
        mov      dword ptr [g_fightGroupHead], ecx
        lea      esi, [ecx*4]
        mov      edx, dword ptr [eax*4 + 0x54]
        mov      ecx, dword ptr [g_xformScratch2088]
        mov      dword ptr [g_walkCallback], edx
        mov      eax, dword ptr [eax*4 + 0x5c]
        mov      dword ptr [g_eventQueueCurrent], eax
        mov      eax, dword ptr [g_currentNodeFlags]
        push     eax
        push     0x9999
        mov      dword ptr [g_eventQueueWorkType], eax
        mov      dword ptr [g_acc_00542078], ecx
        call     Mul10Tail
        mov      edx, dword ptr [g_acc_00542078]
        add      esp, 8
        mov      dword ptr [g_eventQueueWorkType], eax
        push     edx
        push     0x9999
        call     Mul10Tail
        mov      ecx, dword ptr [g_walkCallback]
        mov      edx, dword ptr [g_eventQueueWorkType]
        add      ecx, edx
        mov      edx, dword ptr [g_eventQueueCurrent]
        add      edx, eax
        mov      dword ptr [g_acc_00542078], eax
        mov      dword ptr [g_walkCallback], ecx
        mov      dword ptr [g_eventQueueCurrent], edx
        mov      dword ptr [esi + 0x54], ecx
        mov      eax, dword ptr [g_eventQueueCurrent]
        add      esp, 8
        mov      dword ptr [esi + 0x5c], eax
        call     TripleBlockChainDiffMStackThunks_0049ca10
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_7e3c
        mov      ecx, dword ptr [g_currentNodeFlags]
        push     ecx
        push     0x3d70
        call     Mul10Tail
        mov      edx, dword ptr [g_xformScratch2088]
        add      esp, 8
        mov      dword ptr [g_currentNodeFlags], eax
        push     edx
        push     0x3d70
        call     Mul10Tail
        mov      ecx, dword ptr [g_currentNodeFlags]
        mov      dword ptr [g_xformScratch2088], eax
        mov      eax, dword ptr [g_fightGroupHead]
        add      esp, 8
        mov      dword ptr [eax*4 + 0x6c], ecx
        mov      edx, dword ptr [g_fightGroupHead]
        mov      eax, dword ptr [g_xformScratch2088]
        push     OFFSET g_dispatchSave642_004f2190
        mov      dword ptr [edx*4 + 0x74], eax
        mov      edx, dword ptr [g_eventQueueChild]
        mov      eax, OFFSET g_dispatchSave641_004f21a0
        shr      eax, 2
        add      eax, edx
        mov      edx, dword ptr [g_fightGroupHead]
        mov      dword ptr [g_currentNodeIdx], eax
        mov      ecx, dword ptr [eax*4]
        mov      eax, 1
        mov      dword ptr [edx*4 + 0x70], ecx
        mov      ecx, dword ptr [g_baseSel]
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x68], eax
        call     ArgSar_Set0_Jmp_0049c6f0
        add      esp, 4
    L_7e3c:
        pop      esi
        ret
        nop
        nop
        /* === h4 (0x497e40): chained dispatcher → tail-jmp 49c850 === */
        call     StageEventCluster_00497e80
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_7e7e
        call     PushChainAddCallPop_00493c80
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_7e7e
        call     Vec2SumMul10ChainCompute_0049bc60
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_7e7e
        mov      eax, dword ptr [g_eventQueueCurrent]
        mov      ecx, dword ptr [g_eventQueueWorkType]
        cmp      eax, ecx
        jle      short L_7e7e
        jmp      ScaledIndirectJmp_0049c850
    L_7e7e:
        ret
    }
}
