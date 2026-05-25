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
extern unsigned int g_xformScratch94;
extern unsigned int g_table_00535ddc;
extern unsigned int g_active_00537e88;
extern unsigned int g_active_0053a408;
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
extern unsigned int g_zero_00541fa4;
extern unsigned int g_zero_00541fa8;
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
extern unsigned int g_player1NodeIdx;
extern unsigned int g_data_00535cf8;
extern unsigned int g_cj_00542054;
extern unsigned int g_data_005437f0;
extern unsigned int g_data_00543598;
extern unsigned int g_data_0054358c;
extern unsigned int g_fightAxisNegX_00535e70;
extern unsigned int g_fightAxisNegY_00535e74;
extern unsigned int g_fightAxisPosX_00535e78;
extern unsigned int g_fightAxisPosY_00535e7c;

extern unsigned int g_data_004e4c20;
extern unsigned int g_data_004e4c38;
extern unsigned int g_data_00501a24;
extern unsigned int g_framePauseFlag;
extern unsigned int g_currentNodeIdx;
extern unsigned int g_eventQueueEnd;
extern unsigned int g_baseSel_00542060;
extern unsigned int g_eventQueueWorkType;
extern unsigned int g_eventQueueNotMask;
extern unsigned int g_eventQueueChild;
extern unsigned int g_xformDirtyFlags;
extern unsigned int g_data_005422fc;
extern void ArgSarStoreJmp_004594f0(void);
extern void CopyJmp_0043a620(void);
extern void EsiInstallClampAddCall_0048fe40(void);
extern void EsiInstallDecCallChain_004294a0(void);
extern void GuardedPackedSlotInit_00428760(void);
extern void GuardedPushCall_0043b980(void);
extern void InstallSelfDoubleMStack_0043b9a0(void);
extern void ScaledLitLoadCall_00480fe0(void);
extern void ScaledLoadIncJmp_00428d00(void);
extern void SfxAttenuateAndApply_0048dee0(void);
extern void StateMachine4ArmCascade_0043aab0(void);

__declspec(naked) void VersusScreenEventPoseCluster_0043b680(void)
{
    __asm {
        /* === h1 (0x43b680): event 004e4c20 forwarder === */
        call     CopyJmp_0043a620
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_b69b
        push     OFFSET g_data_004e4c20
        call     ArgSarStoreJmp_004594f0
        add      esp, 4
    L_b69b:
        ret
        nop
        nop
        nop
        nop
        /* === h2 (0x43b6a0): pose-fn 3-state FSM === */
    L_b6a0:
        mov      eax, dword ptr [g_baseSel_00542060]
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
        call     StateMachine4ArmCascade_0043aab0
        pop      edi
        pop      esi
        ret
    L_b6d3:
        /* state 2: install state 3 via 428d00 */
        mov      dword ptr [esi + 8], OFFSET L_b6a0
        mov      ecx, dword ptr [g_baseSel_00542060]
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
        mov      eax, dword ptr [g_baseSel_00542060]
        mov      dword ptr [eax*4 + 0x84], edi
        call     ScaledLoadIncJmp_00428d00
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        ret
    L_b731:
        /* state 1: install state 2 via 43b9a0 */
        mov      dword ptr [g_eventQueueNotMask], 5
        mov      dword ptr [g_eventQueueChild], 0x23
        mov      dword ptr [esi + 8], OFFSET L_b6a0
        mov      ecx, dword ptr [g_baseSel_00542060]
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
        mov      eax, dword ptr [g_baseSel_00542060]
        mov      dword ptr [eax*4 + 0x84], edi
        call     InstallSelfDoubleMStack_0043b9a0
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        ret
    L_b7a3:
        /* state 0: 0x5fa init + 48f50/45f8d0/428760 → install state 1 */
        mov      dword ptr [g_eventQueueWorkType], 0x5fa
        call     Push16Call_00489f50
        call     FiveCallScaledChainTailJmp_0045f8d0
        cmp      dword ptr [g_framePauseFlag], edi
        jne      short L_b83a
        push     OFFSET g_data_005422fc
        call     GuardedPackedSlotInit_00428760
        mov      eax, dword ptr [g_framePauseFlag]
        add      esp, 4
        cmp      eax, edi
        jne      short L_b83a
        mov      dword ptr [g_eventQueueChild], 9
        mov      dword ptr [esi + 8], OFFSET L_b6a0
        mov      ecx, dword ptr [g_baseSel_00542060]
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
        mov      eax, dword ptr [g_baseSel_00542060]
        mov      dword ptr [eax*4 + 0x84], edi
        call     EsiInstallDecCallChain_004294a0
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
        mov      eax, dword ptr [g_baseSel_00542060]
        push     esi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        test     eax, eax
        je       short L_b876
        push     OFFSET g_data_004e4c38
        call     ArgSarStoreJmp_004594f0
        mov      eax, dword ptr [g_framePauseFlag]
        add      esp, 4
        pop      esi
        ret
    L_b876:
        mov      dword ptr [g_eventQueueWorkType], 0x604
        call     Push16Call_00489f50
        call     FiveCallScaledChainTailJmp_0045f8d0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_b919
        mov      ecx, OFFSET g_data_00501a24
        mov      dword ptr [g_currentNodeFlags], 0x3333
        shr      ecx, 2
        mov      dword ptr [g_eventQueueNotMask], 0
        mov      dword ptr [g_eventQueueEnd], ecx
        mov      dword ptr [esi + 8], OFFSET L_b840
        mov      edx, dword ptr [g_baseSel_00542060]
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
        mov      edx, dword ptr [g_baseSel_00542060]
        mov      dword ptr [edx*4 + 0x84], 0
        call     EsiInstallClampAddCall_0048fe40
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
        call     MStackPush3CmpCall_0048eec0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_b971
        test     byte ptr [g_xformDirtyFlags], 1
        je       short L_b93c
        jmp      GuardedPushCall_0043b980
    L_b93c:
        mov      dword ptr [g_walkCallback], 0x3d70
        call     SfxAttenuateAndApply_0048dee0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_b971
        mov      dword ptr [g_walkCallback], 0x88
        call     ScaledLitLoadCall_00480fe0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_b971
        jmp      GuardedPushCall_0043b980
    L_b971:
        ret
    }
}
