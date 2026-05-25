/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_state_004d57ac;
extern unsigned int g_scaledInit_00542044;
extern packed_ptr g_xformEntityIdx;
extern u32 g_eventQueueEnd;
extern unsigned int g_baseSel_00542060;
extern u32 g_eventQueueWorkType;
extern unsigned int g_acc_00542078;
extern unsigned int g_cj_0054205c;
extern u32 g_framePauseFlag;
extern unsigned int g_state_0053a718;
extern unsigned int g_eventQueueTotal;
extern unsigned int g_eventQueueCurrent;
extern unsigned int g_currentNodeFlags;
extern unsigned int g_xformDirtyFlags;
extern unsigned int g_xformScratch2088;
extern unsigned int g_state_00542094;
extern unsigned int g_state_00535ddc;
extern unsigned int g_state_00537e88;
extern unsigned int g_state_0053a408;
extern unsigned int g_state_00537f94;
extern unsigned int g_eventQueueChild;
extern u32 g_pendingNodeType;

extern void StoreTwoCall_0049cb40(int, int);
extern void SetJmp_0049cb90(void);
extern void Thunk_0049cbd0(void);
extern void ScaledZeroFour_00490740(void);
extern void WalkCbSubMul10_00431d50(void);
extern void Mul10Tail_00404af0(unsigned int a, unsigned int b);
extern void BootMod6487eClampAndChainMul10_00407510(void);
extern void SpawnListBatchLoader_00477710(void);
extern void MStackPush2TableNot_00426230(void);
extern void GuardedChainCmpDualBitXor_004299a0(void);
extern void ScaledLoadDecJmp_00429710(void);
extern void ScaledStoreCurDirtyClear_004296f0(void);
extern void MStackBitmaskIncMod_00492450(void);
extern void MStackBitmaskUpdate_00492510(void);
extern void Push1eCallTestDirtyLoop_004923b0(void);
extern void MStackLoopFieldInit_00492280(void);
extern void TaggedSceneDispatch_004be690(void);
extern void CallPauseDirty4StackPushFn_004839d0(void);
extern void CallPauseDirty1JmpDirty4StackPush_00483a80(void);
extern void Cmp2CallDirtyCall_004398b0(void);
extern void QuadBlockArgInstallChain_0043a950(void);
extern void InstallSelfChainSet84_80CallW_004363f0(void);
extern void Wrapper_00436490(void);
extern void MoveFsmCluster_004364a0(void);
extern void CallPauseTestByteJmpCalls_004390f0(void);
extern void InstallSelfFullPath_0047a840(void);
extern void InstallSelfCountdownChain_0047a950(void);
extern void CopyJmp_0048ef90(void);
extern void DualTestDirtyToggle_004282c0(void);
extern void TripleVecAccCallStore_00476880(void);
extern void Thunk_004bd5c0(void);
extern void AllocSlotPushTripleGlobals_00427470(void);
extern void MStackPop4Rewrite_004274f0(void);
extern void Push70CallScaleArith_00457ad0(void);
extern void StreamChainStringInstall_00457900(void);
extern void MStackFrameCdeclDouble_004903f0(void);
extern void ChainTableWalkStore_004917e0(void);
extern void Push16Call_00489f50(void);
extern void DispatcherComplex260_00407030(void);
extern void ScaledLoadCmpStoreXfm_0048f2a0(void);
extern void StackPopDispatchTagged_0041f780(void);
extern unsigned int g_eventQueueNotMask;
extern unsigned int g_cj_00542058;
extern unsigned int g_data_0053a180;
extern unsigned int g_state_00541fa4;
extern unsigned int g_state_00541fa8;
extern unsigned int g_state_0053a7b0;
extern unsigned int g_data_0053a770;
extern unsigned int g_data_0053a46c;

extern void ScaledArrStore_004298c0(void);
extern void DualFieldAddSubStore_00470340(void);
extern void IterStepDualStore_00490b40(int);
extern void ScaledXorStore_004900f0(void);
extern void ChainWalkInstall_0049b7c0(void);
extern void FpuSqrtMul_004ab350(void);
extern void PendingMatch_0042b930(void);
extern void MStackPush2RunCountdown_004089e0(void);
extern void MStackBracket7_DispatchAndChain_004b8fa0(void);
extern void MStackBracketed3StoreCall_00475990(void);
extern void ChainDirtyBitWalker_00408c10(void);
extern void Wrapper_0048a350(void);
extern void Wrapper_0048a3a0(void);
extern void Helper_DownloadSetup(void);
extern void MStackPush3CmpCall_0048eec0(void);
extern void Wrapper_0048ec20(void);
extern void FiveCallScaledChainTailJmp_0045f8d0(void);
extern void SetJmp_00438f50(void);
extern void SetJmp_00438f60(void);
extern void GuardedDispatch_0042b6c0(void);
extern void MStackPushZeroCallPop_00407d00(void);
extern void DirtyToggleByGate_0048f350(void);
extern void GameDispatchValidateState_004339c0(void);
extern void CrouchAttackFsmCluster_0046f7a0(void);
extern void MStackPushVec3Mul10_004767e0(void);
extern void LiteralPushCallEntZero_00488c00(void);
extern void LeaPlus22StoreSelf_0048e4d0(void);
extern void IterLoad_00491050(void);
extern void GuardedDualConst2AndToggle_0048eba0(void);
extern void CallPauseScaledStorePushCall_0045fca0(void);
extern void LoadGeoAsset_Default(void);
extern void DispatcherComplex260_00407400(void);
extern void PushSetCallPop_00406530(void);
extern unsigned int g_state_0053a3c0;
extern unsigned int g_state_00538158;
extern unsigned int g_data_00535cf8;
extern unsigned int g_cj_00542054;
extern unsigned int g_data_005437f0;
extern unsigned int g_data_00543598;
extern unsigned int g_data_0054358c;
extern unsigned int g_data_00535e70;
extern unsigned int g_data_00535e74;
extern unsigned int g_data_00535e78;
extern unsigned int g_data_00535e7c;

extern unsigned int g_data_004d57ac;
extern unsigned int g_data_004f2178;
extern unsigned int g_data_004f2190;
extern unsigned int g_data_004f21a0;
extern unsigned int g_framePauseFlag;
extern unsigned int g_currentNodeIdx;
extern unsigned int g_eventQueueEnd;
extern unsigned int g_eventQueueIdx;
extern unsigned int g_fightGroupHead;
extern unsigned int g_data_00542060;
extern unsigned int g_eventQueueWorkType;
extern unsigned int g_data_00542078;
extern unsigned int g_eventQueueChild;
extern unsigned int g_xformScratch2088;
extern void ArgSarStoreJmp_004594f0(void);
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
        mov      ecx, dword ptr [g_data_00542060]
        mov      eax, 0x316
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x74], eax
        mov      edx, dword ptr [g_data_00542060]
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
        push     OFFSET g_data_004f2178
        call     ArgSarStoreJmp_004594f0
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
        mov      eax, dword ptr [g_data_00542060]
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
        mov      ecx, dword ptr [g_data_00542060]
        push     0x51
        push     OFFSET L_7cb0
        mov      eax, dword ptr [ecx*4 + 4]
        dec      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      edx, dword ptr [eax*4]
        mov      dword ptr [g_eventQueueChild], edx
        mov      dword ptr [ecx*4 + 4], eax
        call     StoreTwoCall_0049cb40
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      ecx, dword ptr [g_fightGroupHead]
        add      esp, 8
        mov      dword ptr [eax*4 + 0x28], ecx
        mov      dword ptr [esi + 8], OFFSET L_7bc0
        mov      edx, dword ptr [g_data_00542060]
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
        mov      edx, dword ptr [g_data_00542060]
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
        mov      eax, dword ptr [g_data_004d57ac]
        mov      ecx, dword ptr [g_eventQueueEnd]
        inc      eax
        push     esi
        mov      dword ptr [g_data_004d57ac], eax
        mov      dword ptr [eax*4], ecx
        call     DualCmpSwapStore_0049c5a0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_7e3c
        mov      eax, dword ptr [g_data_004d57ac]
        mov      ecx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_data_004d57ac], eax
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
        mov      dword ptr [g_data_00542078], ecx
        call     Mul10Tail_00404af0
        mov      edx, dword ptr [g_data_00542078]
        add      esp, 8
        mov      dword ptr [g_eventQueueWorkType], eax
        push     edx
        push     0x9999
        call     Mul10Tail_00404af0
        mov      ecx, dword ptr [g_walkCallback]
        mov      edx, dword ptr [g_eventQueueWorkType]
        add      ecx, edx
        mov      edx, dword ptr [g_eventQueueCurrent]
        add      edx, eax
        mov      dword ptr [g_data_00542078], eax
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
        call     Mul10Tail_00404af0
        mov      edx, dword ptr [g_xformScratch2088]
        add      esp, 8
        mov      dword ptr [g_currentNodeFlags], eax
        push     edx
        push     0x3d70
        call     Mul10Tail_00404af0
        mov      ecx, dword ptr [g_currentNodeFlags]
        mov      dword ptr [g_xformScratch2088], eax
        mov      eax, dword ptr [g_fightGroupHead]
        add      esp, 8
        mov      dword ptr [eax*4 + 0x6c], ecx
        mov      edx, dword ptr [g_fightGroupHead]
        mov      eax, dword ptr [g_xformScratch2088]
        push     OFFSET g_data_004f2190
        mov      dword ptr [edx*4 + 0x74], eax
        mov      edx, dword ptr [g_eventQueueChild]
        mov      eax, OFFSET g_data_004f21a0
        shr      eax, 2
        add      eax, edx
        mov      edx, dword ptr [g_fightGroupHead]
        mov      dword ptr [g_currentNodeIdx], eax
        mov      ecx, dword ptr [eax*4]
        mov      eax, 1
        mov      dword ptr [edx*4 + 0x70], ecx
        mov      ecx, dword ptr [g_data_00542060]
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
