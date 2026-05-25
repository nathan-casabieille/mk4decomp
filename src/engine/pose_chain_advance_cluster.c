/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;
extern unsigned int g_baseSel_00542060;
extern unsigned int g_acc_00542078;
extern unsigned int g_cj_0054205c;
extern unsigned int g_state_0053a718;
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
extern unsigned int g_stateCountdown_0053a3c0;
extern unsigned int g_installOwnerNode_00535cf8;
extern unsigned int g_cj_00542054;
extern unsigned int g_audioBoundNode_005437f0;
extern unsigned int g_data_00543598;
extern unsigned int g_data_0054358c;
extern unsigned int g_fightAxisNegX_00535e70;
extern unsigned int g_fightAxisNegY_00535e74;
extern unsigned int g_fightAxisPosX_00535e78;
extern unsigned int g_fightAxisPosY_00535e7c;

/* ------------------------------------------------------------------ */
/* Intro/menu init cluster (767b game, 5 packed helpers):             */
/*  h1 (0x44d280): mstack-bracketed flag handler w/ bit-4 dispatch.   */
/*  h2 (0x44d3a0): pose-fn 2-state intro w/ 44dd00 + 489f90 + 43d830  */
/*    + 4752b0 install. Has push 0x44d5c0 (intro params), push 0x44f1e0 */
/*    (another intro fn entry).                                       */
/*  h3 (0x44d500): event 004e6590 forwarder w/ status init.           */
/*  h4 (0x44d540): event 004e65a0 forwarder w/ 0xfffffbc7 wait.       */
/*  h5 (0x44d570): set state 9 → tail-jmp IntroFsmCluster_0044d580.   */
/* ------------------------------------------------------------------ */
extern void MStackBracket5_FieldClear_StateAdvance_00405630(void);
extern void DoubleCallChainInit_0043d780(void);
extern void PendingMatch_0043d830(void);
extern void IntroFsmCluster_0044d580(void);
extern void GuardedDualScaledChainCopy_0044dd00(void);
extern void PendingMatch_0044dd80(void);
extern void GuardedScaled_00475060(void);
extern void InstallSelfChainAccumPath_004752b0(void);
extern void GameInstall2BodyMul10ScaledInit_00475590(void);
extern void GatedWordPushCall_00489f90(void);
extern void PoseChainAdvanceCluster_0044ef50(void);
extern unsigned int g_data_004e6580;
extern unsigned int g_data_004e6590;
extern unsigned int g_data_004e65a0;
extern unsigned int g_data_00501070;
extern unsigned int g_data_005117c4;

extern void ArgSarStoreJmp_004594f0(void);
extern void FramePauseScaledStore_00406c10(void);
extern void StoreLoadJmp_00404ef0(void);

__declspec(naked) void IntroInitCluster_0044d280(void)
{
    __asm {
        /* === h1 (0x44d280): mstack-bracketed flag handler === */
        mov      eax, dword ptr [g_matrixStackTop]
        mov      ecx, dword ptr [g_xformEntityIdx]
        inc      eax
        push     ebx
        push     esi
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], ecx
        call     GuardedScaled_00475060
        mov      eax, dword ptr [g_framePauseFlag]
        xor      esi, esi
        cmp      eax, esi
        jne      L_d395
        mov      al, byte ptr [g_xformDirtyFlags]
        mov      ebx, 4
        test     al, bl
        je       short L_d2d7
        call     MStackBracket5_FieldClear_StateAdvance_00405630
        cmp      dword ptr [g_framePauseFlag], esi
        jne      L_d395
        test     byte ptr [g_xformDirtyFlags], bl
        je       short L_d327
        jmp      short L_d2fe
    L_d2d7:
        mov      edx, OFFSET g_data_005117c4
        shr      edx, 2
        mov      dword ptr [g_xformEntityIdx], edx
        call     FramePauseScaledStore_00406c10
        cmp      dword ptr [g_framePauseFlag], esi
        jne      L_d395
        test     byte ptr [g_xformDirtyFlags], bl
        je       short L_d327
    L_d2fe:
        mov      edx, dword ptr [g_xformDirtyFlags]
        mov      eax, dword ptr [g_matrixStackTop]
        or       edx, ebx
        dec      eax
        mov      dword ptr [g_xformDirtyFlags], edx
        mov      ecx, dword ptr [eax*4 + 4]
        mov      dword ptr [g_xformEntityIdx], ecx
        mov      dword ptr [g_matrixStackTop], eax
        pop      esi
        pop      ebx
        ret
    L_d327:
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [g_walkCallback], esi
        mov      dword ptr [edx*4 + 0x30], esi
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      eax, dword ptr [g_walkCallback]
        mov      dword ptr [ecx*4 + 0x34], eax
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      edx, dword ptr [g_walkCallback]
        mov      dword ptr [eax*4 + 0x38], edx
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [g_walkCallback], esi
        mov      dword ptr [ecx*4 + 0x1c], esi
        mov      eax, dword ptr [g_matrixStackTop]
        mov      edx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      eax, dword ptr [g_xformDirtyFlags]
        and      al, 0xfb
        mov      dword ptr [g_xformEntityIdx], edx
        mov      dword ptr [g_xformDirtyFlags], eax
    L_d395:
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
        /* === h2 (0x44d3a0): pose-fn 2-state intro === */
    L_d3a0:
        mov      eax, dword ptr [g_baseSel_00542060]
        push     esi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        sub      eax, 0
        je       L_d48e
        dec      eax
        je       short L_d3de
        push     OFFSET g_data_004e6580
        call     ArgSarStoreJmp_004594f0
        mov      eax, dword ptr [g_framePauseFlag]
        add      esp, 4
        pop      esi
        ret
    L_d3de:
        call     GuardedDualScaledChainCopy_0044dd00
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_d4f9
        mov      dword ptr [g_walkCallback], 0x30
        call     GatedWordPushCall_00489f90
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_d4f9
        call     PendingMatch_0043d830
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_d4f9
        mov      ecx, OFFSET g_data_00501070
        shr      ecx, 2
        mov      dword ptr [g_eventQueueEnd], ecx
        mov      dword ptr [esi + 8], OFFSET L_d3a0
        mov      edx, dword ptr [g_baseSel_00542060]
        mov      ecx, OFFSET L_d3a0
        add      ecx, 0x2000000
        mov      dword ptr [edx*4 + 0x84], 2
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      edx, dword ptr [g_baseSel_00542060]
        mov      dword ptr [edx*4 + 0x84], 0
        call     InstallSelfChainAccumPath_004752b0
        mov      dword ptr [g_framePauseFlag], 1
        pop      esi
        ret
    L_d48e:
        push     OFFSET IntroFsmCluster_0044d580 + 0x40
        call     StoreLoadJmp_00404ef0
        add      esp, 4
        push     OFFSET PoseChainAdvanceCluster_0044ef50 + 0x290
        call     StoreLoadJmp_00404ef0
        add      esp, 4
        call     DoubleCallChainInit_0043d780
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_d4f9
        mov      eax, dword ptr [g_eventQueueIdx]
        mov      dword ptr [g_currentNodeFlags], 0x12666
        mov      dword ptr [g_fightGroupHead], eax
        call     GameInstall2BodyMul10ScaledInit_00475590
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_d4f9
        mov      eax, 1
        mov      dword ptr [esi + 8], OFFSET L_d3a0
        mov      dword ptr [esi + 0x84], eax
        mov      dword ptr [g_pendingNodeType], 0x10
        mov      dword ptr [g_framePauseFlag], eax
    L_d4f9:
        pop      esi
        ret
        nop
        nop
        nop
        nop
        nop
        /* === h3 (0x44d500): event 004e6590 forwarder === */
        mov      eax, dword ptr [g_fightGroupHead]
        mov      dword ptr [eax*4 + 0x28], 0x35
        mov      dword ptr [g_walkCallback], 0x27
        call     GatedWordPushCall_00489f90
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_d535
        push     OFFSET g_data_004e6590
        call     ArgSarStoreJmp_004594f0
        add      esp, 4
    L_d535:
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
        /* === h4 (0x44d540): event 004e65a0 forwarder === */
        mov      dword ptr [g_walkCallback], 0xfffffbc7
        call     PendingMatch_0044dd80
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_d565
        push     OFFSET g_data_004e65a0
        call     ArgSarStoreJmp_004594f0
        add      esp, 4
    L_d565:
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
        /* === h5 (0x44d570): set state 9 → tail-jmp 44d580 === */
        mov      dword ptr [g_eventQueueEnd], 9
        jmp      IntroFsmCluster_0044d580
    }
}
