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

/* ------------------------------------------------------------------ */
/* Special-move chain cluster (812b game, 4 packed helpers):          */
/*  h1 (0x43f9c0): 7-stage 76670 + 73070 chain w/ status sequence     */
/*    (0x76, 0x7b, 0x77, 0xc1×2, 0xc0, 0x93, 0x74, 0x75) + event 4e51c8.*/
/*  h2 (0x43fb90): mstack pop helper.                                 */
/*  h3 (0x43fbb0): pose-fn install state 1 w/ 0043fcf0 (476de0 chain).*/
/*  h4 (0x43fc50): pose-fn install state 1 w/ 0043fcf0 (476f10 chain).*/
/* ------------------------------------------------------------------ */
extern void TwoCallScaledOr1600_0043f8f0(void);
extern void EntitySetupCountdownFsm_0043fcf0(void);
extern void ComboLoopCluster_00440070(void);
extern void PushPopCurrentSetFFFFFFFF_00473070(void);
extern void MStackPush2BitLoop_00476670(void);
extern void GuardedSeq_00476de0(void);
extern void GuardedSeq_00476f10(void);
extern void GuardedSeq_00476fc0(void);
extern unsigned int g_data_004e51c8;

extern unsigned int g_data_004d57ac;
extern unsigned int g_framePauseFlag;
extern unsigned int g_currentNodeIdx;
extern unsigned int g_eventQueueEnd;
extern unsigned int g_fightGroupHead;
extern unsigned int g_baseSel_00542060;
extern void ArgSarStoreJmp_004594f0(void);

__declspec(naked) void SpecialMoveChainCluster_0043f9c0(void)
{
    __asm {
        /* === h1 (0x43f9c0): 7-stage status sequence + event 4e51c8 === */
        mov      dword ptr [g_walkCallback], 0x76
        call     MStackPush2BitLoop_00476670
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_fb81
        mov      dword ptr [g_walkCallback], 0x7b
        call     MStackPush2BitLoop_00476670
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_fb81
        mov      dword ptr [g_walkCallback], 0x77
        call     MStackPush2BitLoop_00476670
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_fb81
        mov      dword ptr [g_walkCallback], 0xc1
        call     MStackPush2BitLoop_00476670
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_fb81
        mov      dword ptr [g_walkCallback], 0xc1
        call     PushPopCurrentSetFFFFFFFF_00473070
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_fb81
        mov      dword ptr [g_walkCallback], 0xc0
        call     PushPopCurrentSetFFFFFFFF_00473070
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_fb81
        call     TwoCallScaledOr1600_0043f8f0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_fb81
        mov      eax, dword ptr [g_data_004d57ac]
        mov      ecx, dword ptr [g_fightGroupHead]
        inc      eax
        mov      dword ptr [g_data_004d57ac], eax
        mov      dword ptr [eax*4], ecx
        mov      ecx, dword ptr [g_baseSel_00542060]
        mov      edx, dword ptr [g_fightGroupHead]
        shl      ecx, 2
        lea      eax, [edx*4]
        mov      edx, dword ptr [ecx + 0x3c]
        mov      dword ptr [g_walkCallback], edx
        mov      dword ptr [eax + 0x54], edx
        mov      edx, dword ptr [ecx + 0x40]
        mov      dword ptr [g_walkCallback], edx
        mov      dword ptr [eax + 0x58], edx
        mov      edx, dword ptr [ecx + 0x44]
        mov      dword ptr [eax + 0x5c], edx
        mov      dword ptr [g_walkCallback], 0x93
        call     PushPopCurrentSetFFFFFFFF_00473070
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_fb81
        mov      eax, dword ptr [g_baseSel_00542060]
        shl      eax, 2
        mov      ecx, dword ptr [eax + 0x64]
        mov      dword ptr [g_eventQueueEnd], ecx
        mov      edx, dword ptr [eax + 0x30]
        shl      ecx, 2
        mov      dword ptr [g_walkCallback], edx
        mov      dword ptr [ecx + 0x54], edx
        mov      edx, dword ptr [eax + 0x34]
        mov      dword ptr [g_walkCallback], edx
        mov      dword ptr [ecx + 0x58], edx
        mov      edx, dword ptr [eax + 0x38]
        mov      dword ptr [ecx + 0x5c], edx
        mov      eax, dword ptr [g_eventQueueEnd]
        mov      dword ptr [g_fightGroupHead], eax
        mov      dword ptr [g_walkCallback], 3
        call     GuardedSeq_00476fc0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_fb81
        mov      dword ptr [g_walkCallback], 0x74
        call     MStackPush2BitLoop_00476670
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_fb81
        mov      dword ptr [g_walkCallback], 0x75
        call     MStackPush2BitLoop_00476670
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_fb81
        call     ScaledZeroFour_00490740
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_fb81
        push     OFFSET g_data_004e51c8
        call     ArgSarStoreJmp_004594f0
        add      esp, 4
    L_fb81:
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
        /* === h2 (0x43fb90): mstack pop helper === */
        mov      eax, dword ptr [g_data_004d57ac]
        mov      ecx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_fightGroupHead], ecx
        mov      dword ptr [g_data_004d57ac], eax
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        /* === h3 (0x43fbb0): pose-fn install state 1 w/ 476de0 === */
    L_fbb0:
        mov      eax, dword ptr [g_baseSel_00542060]
        shl      eax, 2
        mov      ecx, dword ptr [eax + 0x84]
        mov      dword ptr [eax + 0x84], 0
        test     ecx, ecx
        je       short L_fbe9
        mov      dword ptr [g_walkCallback], 3
        call     GuardedSeq_00476de0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_fc4b
        jmp      ComboLoopCluster_00440070
    L_fbe9:
        mov      dword ptr [eax + 8], OFFSET L_fbb0
        mov      ecx, dword ptr [g_baseSel_00542060]
        mov      edx, OFFSET L_fbb0
        mov      dword ptr [ecx*4 + 0x84], 1
        mov      ecx, dword ptr [eax + 4]
        add      edx, 0x1000000
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      dword ptr [ecx*4], edx
        mov      ecx, dword ptr [g_currentNodeIdx]
        inc      ecx
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      dword ptr [eax + 4], ecx
        mov      eax, dword ptr [g_baseSel_00542060]
        mov      dword ptr [eax*4 + 0x84], 0
        call     EntitySetupCountdownFsm_0043fcf0
        mov      dword ptr [g_framePauseFlag], 1
    L_fc4b:
        ret
        nop
        nop
        nop
        nop
        /* === h4 (0x43fc50): pose-fn install state 1 w/ 476f10 === */
    L_fc50:
        mov      eax, dword ptr [g_baseSel_00542060]
        shl      eax, 2
        mov      ecx, dword ptr [eax + 0x84]
        mov      dword ptr [eax + 0x84], 0
        test     ecx, ecx
        je       short L_fc89
        mov      dword ptr [g_walkCallback], 3
        call     GuardedSeq_00476f10
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_fceb
        jmp      ComboLoopCluster_00440070
    L_fc89:
        mov      dword ptr [eax + 8], OFFSET L_fc50
        mov      ecx, dword ptr [g_baseSel_00542060]
        mov      edx, OFFSET L_fc50
        mov      dword ptr [ecx*4 + 0x84], 1
        mov      ecx, dword ptr [eax + 4]
        add      edx, 0x1000000
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      dword ptr [ecx*4], edx
        mov      ecx, dword ptr [g_currentNodeIdx]
        inc      ecx
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      dword ptr [eax + 4], ecx
        mov      eax, dword ptr [g_baseSel_00542060]
        mov      dword ptr [eax*4 + 0x84], 0
        call     EntitySetupCountdownFsm_0043fcf0
        mov      dword ptr [g_framePauseFlag], 1
    L_fceb:
        ret
    }
}
