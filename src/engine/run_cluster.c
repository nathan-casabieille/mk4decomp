/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;
extern unsigned int g_baseSel_00542060;
extern unsigned int g_acc_00542078;
extern unsigned int g_cj_0054205c;
extern unsigned int g_gameCountdown_0053a718;
extern unsigned int g_xformScratch94;
extern unsigned int g_table_00535ddc;
extern unsigned int g_active_00537e88;
extern unsigned int g_active_0053a408;
extern unsigned int g_audioBankSel_00537f94;

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
extern unsigned int g_cj_00542058;
extern unsigned int g_rangeSqLimit_0053a180;
extern unsigned int g_zero_00541fa4;
extern unsigned int g_zero_00541fa8;
extern unsigned int g_dualBitGate_0053a7b0;
extern unsigned int g_eventArmReload_0053a770;
extern unsigned int g_rangeBase_0053a46c;

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
extern unsigned int g_stateCountdown_0053a3c0;
extern unsigned int g_installOwnerNode_00535cf8;
extern unsigned int g_cj_00542054;
extern unsigned int g_audioBoundNode_005437f0;
extern unsigned int g_lastGatedValue_00543598;
extern unsigned int g_lastGatedTick_0054358c;
extern unsigned int g_fightAxisNegX_00535e70;
extern unsigned int g_fightAxisNegY_00535e74;
extern unsigned int g_fightAxisPosX_00535e78;
extern unsigned int g_fightAxisPosY_00535e7c;

extern unsigned int g_phaseTimer_00537e94;
extern void CallDualStoreXorBit_004285e0(void);
extern void DualHelperCallStoreCjFields_0048ff40(void);
extern void DualMul10AccCj_00491230(void);
extern void EsiEdiAliasDualMul10_004906b0(void);
extern void FiveCallGuardSetTail_0046f6b0(void);
extern void GuardedSeq_0047d980(void);
extern void MoveSelectorCluster_0047d9a0(void);
extern void ScaledLitLoadCall_00480fe0(void);
extern void ScaledZero44_00491500(void);
extern void TableLookupCall_00489ff0(void);
extern void TwoPhaseInstallScaledPackedPtr_00480d50(void);

__declspec(naked) void RunCluster_0047d6e0(void)
{
    __asm {
        /* === Helper 1 (0x47d6e0): ramp+blend driver === */
    L_d6e0:
        mov      dword ptr [g_walkCallback], 0x4000
        call     EsiEdiAliasDualMul10_004906b0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_d73b
        call     ScaledZero44_00491500
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_d73b
        call     CopyJmp_0048ef90
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_d73b
        mov      al, byte ptr [g_xformDirtyFlags]
        mov      dword ptr [g_walkCallback], 0x28f
        test     al, 1
        mov      dword ptr [g_eventQueueCurrent], 0
        je       short L_d736
        jmp      TwoPhaseInstallScaledPackedPtr_00480d50
    L_d736:
        jmp      FiveCallGuardSetTail_0046f6b0
    L_d73b:
        ret
        nop
        nop
        nop
        nop
        /* === Helper 2 (0x47d740): ev0x14 trigger === */
        mov      eax, 2
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [g_phaseTimer_00537e94], eax
        call     CallDualStoreXorBit_004285e0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_d77d
        test     byte ptr [g_xformDirtyFlags], 4
        je       short L_d77d
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      eax, 0x14
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x28], eax
    L_d77d:
        ret
        nop
        nop
        /* === Helper 3 (0x47d780): distance-test caller === */
        mov      eax, dword ptr [g_fightGroupHead]
        push     esi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x54]
        mov      dword ptr [g_walkCallback], eax
        mov      ecx, dword ptr [esi + 0x5c]
        push     eax
        push     eax
        mov      dword ptr [g_eventQueueCurrent], ecx
        call     Mul10Tail_00404af0
        add      esp, 8
        mov      dword ptr [g_walkCallback], eax
        mov      eax, dword ptr [g_eventQueueCurrent]
        push     eax
        push     eax
        call     Mul10Tail_00404af0
        mov      ecx, dword ptr [g_walkCallback]
        add      esp, 8
        add      ecx, eax
        mov      dword ptr [g_eventQueueCurrent], eax
        cmp      ecx, 0x640000
        mov      dword ptr [g_walkCallback], ecx
        jl       short L_d841
        mov      ecx, dword ptr [esi + 0x6c]
        mov      dword ptr [g_eventQueueCurrent], ecx
        mov      edx, dword ptr [esi + 0x74]
        mov      dword ptr [g_eventQueueWorkType], edx
        mov      eax, dword ptr [esi + 0x54]
        mov      dword ptr [g_acc_00542078], eax
        mov      esi, dword ptr [esi + 0x5c]
        add      eax, ecx
        add      esi, edx
        push     eax
        push     eax
        mov      dword ptr [g_acc_00542078], eax
        mov      dword ptr [g_eventQueueNotMask], esi
        call     Mul10Tail_00404af0
        add      esp, 8
        mov      dword ptr [g_acc_00542078], eax
        mov      eax, dword ptr [g_eventQueueNotMask]
        push     eax
        push     eax
        call     Mul10Tail_00404af0
        mov      edx, dword ptr [g_acc_00542078]
        mov      ecx, dword ptr [g_walkCallback]
        add      eax, edx
        add      esp, 8
        cmp      eax, ecx
        mov      dword ptr [g_eventQueueNotMask], eax
        jl       short L_d841
        call     L_d6e0
    L_d841:
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
        /* === Helper 4 (0x47d850): stride-FSM === */
    L_d850:
        mov      eax, dword ptr [g_baseSel_00542060]
        push     esi
        push     edi
        mov      edi, 1
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        test     eax, eax
        je       short L_d88b
        mov      eax, dword ptr [g_eventQueueChild]
        dec      eax
        mov      dword ptr [g_eventQueueChild], eax
        je       L_d91c
        jmp      short L_d8c1
    L_d88b:
        cmp      dword ptr [g_xformScratch2088], edi
        jne      short L_d89b
        call     MoveSelectorCluster_0047d9a0
        pop      edi
        pop      esi
        ret
    L_d89b:
        mov      dword ptr [g_walkCallback], 0xd
        call     TableLookupCall_00489ff0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_d97c
        mov      dword ptr [g_eventQueueChild], 0x32
    L_d8c1:
        mov      dword ptr [g_walkCallback], 0x18000
        mov      dword ptr [g_eventQueueCurrent], 0xffffe667
        call     DualHelperCallStoreCjFields_0048ff40
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_d97c
        mov      ecx, dword ptr [g_baseSel_00542060]
        mov      edx, dword ptr [ecx*4 + 0x38]
        mov      dword ptr [g_currentNodeIdx], edx
        call     DualMul10AccCj_00491230
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_d97c
        mov      eax, dword ptr [g_rangeSqLimit_0053a180]
        mov      ecx, dword ptr [g_walkCallback]
        cmp      ecx, eax
        mov      dword ptr [g_eventQueueCurrent], eax
        jle      short L_d954
    L_d91c:
        mov      dword ptr [g_walkCallback], 0x53
        call     ScaledLitLoadCall_00480fe0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_d97c
        mov      dword ptr [g_walkCallback], 0xc
        call     TableLookupCall_00489ff0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_d97c
        call     GuardedSeq_0047d980
        pop      edi
        pop      esi
        ret
    L_d954:
        mov      eax, 3
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [g_phaseTimer_00537e94], eax
        mov      dword ptr [esi + 8], OFFSET L_d850
        mov      dword ptr [esi + 0x84], edi
        mov      dword ptr [g_pendingNodeType], edi
        mov      dword ptr [g_framePauseFlag], edi
    L_d97c:
        pop      edi
        pop      esi
        ret
    }
}
