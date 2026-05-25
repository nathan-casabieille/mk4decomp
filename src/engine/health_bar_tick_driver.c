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
extern unsigned int g_audioBankSel_00537f94;
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
extern unsigned int g_player1NodeIdx;
extern unsigned int g_installOwnerNode_00535cf8;
extern unsigned int g_cj_00542054;
extern unsigned int g_audioBoundNode_005437f0;
extern unsigned int g_data_00543598;
extern unsigned int g_data_0054358c;
extern unsigned int g_fightAxisNegX_00535e70;
extern unsigned int g_fightAxisNegY_00535e74;
extern unsigned int g_fightAxisPosX_00535e78;
extern unsigned int g_fightAxisPosY_00535e7c;

extern void QuadCallPauseJmp_00457ff0(void);
extern void SequencedInit3CallB_00458ae0(void);
extern void HealthBarTickDriver_00458cc0(void);
extern unsigned int g_data_004e8698;
extern unsigned int g_data_0052aac4;
extern unsigned int g_data_00537e98;
extern unsigned int g_data_00537f48;
extern unsigned int g_data_0053a51c;
extern unsigned int g_data_00541d6c;
extern unsigned int g_const_00427780;
extern void func_00427780(void);

extern unsigned int g_data_005380e0;
extern unsigned int g_framePauseFlag;
extern unsigned int g_pendingNodeType;
extern unsigned int g_fightGroupHead;
extern unsigned int g_baseSel_00542060;
extern unsigned int g_eventQueueWorkType;
extern unsigned int g_xformDirtyFlags;
extern void BootInitGuardedCallChain_004265d0(void);
extern void CallSetPause_0041f830(void);
extern void DualPushSetCallDualPop_00404b10(void);
extern void QuadCallPhase2_004be800(void);
extern void SpawnTrioInitCluster_00458440(void);
extern void TableWalkBoundedCmp_004bd890(void);
extern void TripleStageRollback_00404a50(void);

__declspec(naked) void RoundEndHandlerCluster_00457de0(void)
{
    __asm {
        /* H1 (L_7de0): 3-state FSM */
    L_7de0:
        mov      eax, dword ptr [g_baseSel_00542060]
        push     ebx
        push     esi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        sub      eax, 0
        je       L_7ed2
        dec      eax
        jne      short L_7e38
        mov      eax, dword ptr [g_data_00541d6c]
        test     eax, eax
        mov      dword ptr [g_walkCallback], eax
        je       L_7f6d
        push     0x25e
        call     DualPushSetCallDualPop_00404b10
        mov      al, byte ptr [g_xformDirtyFlags]
        mov      ebx, 1
        add      esp, 4
        test     al, bl
        jne      short L_7e7d
    L_7e38:
        call     BootInitGuardedCallChain_004265d0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_7f8b
        push     3
        call     TableWalkBoundedCmp_004bd890
        mov      ecx, dword ptr [g_data_0053a51c]
        mov      edx, dword ptr [g_data_005380e0]
        mov      eax, dword ptr [g_data_00537f48]
        add      esp, 4
        add      ecx, 0x12
        push     0x1d
        push     ecx
        push     edx
        push     eax
        call     QuadCallPhase2_004be800
        add      esp, 0x10
        call     StackPopDispatchTagged_0041f780
        pop      esi
        pop      ebx
        ret
    L_7e7d:
        call     HealthBarTickDriver_00458cc0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_7f8b
        call     SpawnTrioInitCluster_00458440
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_7f8b
        push     0x25e
        call     TripleStageRollback_00404a50
        mov      dword ptr [esi + 8], OFFSET L_7de0
        mov      dword ptr [esi + 0x84], 2
        add      esp, 4
        mov      dword ptr [g_pendingNodeType], 0x3c
        mov      dword ptr [g_framePauseFlag], ebx
        pop      esi
        pop      ebx
        ret
    L_7ed2:
        push     7
        call     TableWalkBoundedCmp_004bd890
        add      esp, 4
        push     -1
        push     -1
        push     -1
        push     0x1c
        call     QuadCallPhase2_004be800
        mov      ecx, dword ptr [g_eventQueueWorkType]
        mov      eax, 0xc
        add      esp, 0x10
        mov      dword ptr [g_data_00537e98], ecx
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [g_data_0052aac4], eax
        call     SequencedInit3CallB_00458ae0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_7f8b
        call     QuadCallPauseJmp_00457ff0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_7f8b
        push     0x25e
        push     OFFSET L_7f90
        call     StoreTwoCall_0049cb40
        add      esp, 8
        mov      dword ptr [g_eventQueueWorkType], 9
        call     Push16Call_00489f50
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_7f8b
        mov      edx, OFFSET g_data_004e8698
        push     0x262
        shr      edx, 2
        push     OFFSET func_00427780
        mov      dword ptr [g_fightGroupHead], edx
        call     StoreTwoCall_0049cb40
        add      esp, 8
    L_7f6d:
        mov      ebx, 1
        mov      dword ptr [esi + 8], OFFSET L_7de0
        mov      dword ptr [esi + 0x84], ebx
        mov      dword ptr [g_pendingNodeType], ebx
        mov      dword ptr [g_framePauseFlag], ebx
    L_7f8b:
        pop      esi
        pop      ebx
        ret
        nop
        nop
        /* H2 (L_7f90): per-entity state-clear */
    L_7f90:
        mov      eax, dword ptr [g_baseSel_00542060]
        shl      eax, 2
        mov      ecx, dword ptr [eax + 0x84]
        mov      dword ptr [eax + 0x84], 0
        test     ecx, ecx
        je       short L_7fc2
        mov      ecx, 1
        mov      dword ptr [g_walkCallback], ecx
        mov      dword ptr [g_data_00541d6c], ecx
        jmp      CallSetPause_0041f830
    L_7fc2:
        mov      ecx, 1
        mov      dword ptr [eax + 8], OFFSET L_7f90
        mov      dword ptr [eax + 0x84], ecx
        mov      dword ptr [g_pendingNodeType], 0x708
        mov      dword ptr [g_framePauseFlag], ecx
        ret
    }
}
