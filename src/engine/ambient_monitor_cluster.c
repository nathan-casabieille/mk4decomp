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
extern unsigned int g_rangeSqLimit_0053a180;
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
extern unsigned int g_installOwnerNode_00535cf8;
extern unsigned int g_cj_00542054;
extern unsigned int g_data_005437f0;
extern unsigned int g_data_00543598;
extern unsigned int g_data_0054358c;
extern unsigned int g_fightAxisNegX_00535e70;
extern unsigned int g_fightAxisNegY_00535e74;
extern unsigned int g_fightAxisPosX_00535e78;
extern unsigned int g_fightAxisPosY_00535e7c;

extern void SetWalkCurCallPauseDirty_00404c70(void);
extern void StackPopDispatchTagged_0041f780(void);
extern void BootInitGuardedCallChain_004265d0(void);
extern void DualTestDirtyToggle_00427ea0(void);
extern void DualTestDirtyToggle_004282c0(void);
extern void PendingMatch_00461ca0(void);
extern void Push16Call_00489f50(void);
extern void StoreTwoCall_0049cb40(void);
extern void PhaseClampInstallSlot_0049e1c0(void);
extern void GuardedCmpDualToggle_0049e360(void);
extern void AmbientMonitorCluster_0049e3c0(void);
extern void ThrowAnimTriggerCluster_0049efa0(void);
extern void MStackDirtyArgsBit0_0049fa50(void);
extern void TableWalkBoundedCmp_004bd890(int);
extern void TaggedSceneDispatch_004be690(void);
extern void QuadCallPhase2_004be800(void);
extern void RoundCleanupCluster_00427690(void);
extern unsigned int g_data_004e2868;
extern unsigned int g_data_004f29c0;
extern unsigned int g_data_0052aac4;
extern unsigned int g_data_00535e44;
extern unsigned int g_active_00537e88;
extern unsigned int g_data_00537eec;
extern unsigned int g_data_00537f48;
extern unsigned int g_data_005380e0;
extern unsigned int g_data_0053a3c0;
extern unsigned int g_active_0053a408;
extern unsigned int g_data_0053a468;
extern unsigned int g_framePauseFlag;
extern unsigned int g_data_00541fb0;
extern unsigned int g_currentNodeIdx;
extern unsigned int g_pendingNodeType;
extern unsigned int g_fightGroupHead;
extern unsigned int g_baseSel_00542060;
extern unsigned int g_eventQueueWorkType;
extern unsigned int g_xformDirtyFlags;
extern unsigned int g_data_005433ec;
extern unsigned int g_data_0054356c;
extern unsigned int g_data_00543590;
extern unsigned int g_data_00543714;
extern unsigned int g_data_00543728;

__declspec(naked) void SceneEvalFsm_0049dea0(void)
{
    __asm {
        mov      eax, dword ptr [g_baseSel_00542060]
        push     ebx
        push     esi
        xor      ebx, ebx
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], ebx
        cmp      eax, 3
        ja       L_e198
        jmp      dword ptr [eax*4 + L_jmptbl]
        push     0x251
        push     OFFSET AmbientMonitorCluster_0049e3c0 + 0xd0
        call     StoreTwoCall_0049cb40
        add      esp, 8
        mov      ecx, OFFSET g_data_004f29c0
        shr      ecx, 2
        push     0x262
        push     OFFSET RoundCleanupCluster_00427690 + 0xf0
        mov      dword ptr [g_fightGroupHead], ecx
        call     StoreTwoCall_0049cb40
        mov      eax, 1
        mov      dword ptr [esi + 8], OFFSET SceneEvalFsm_0049dea0
        mov      dword ptr [esi + 0x84], 2
        add      esp, 8
        mov      dword ptr [g_pendingNodeType], eax
        mov      dword ptr [g_framePauseFlag], eax
        pop      esi
        pop      ebx
        ret      
        mov      dword ptr [g_eventQueueWorkType], 0x47
        call     Push16Call_00489f50
        cmp      dword ptr [g_framePauseFlag], ebx
        je       L_df68
        pop      esi
        pop      ebx
        ret      
        push     0x251
        push     OFFSET AmbientMonitorCluster_0049e3c0 + 0xd0
        call     SetWalkCurCallPauseDirty_00404c70
        add      esp, 8
        call     MStackDirtyArgsBit0_0049fa50
        cmp      dword ptr [g_framePauseFlag], ebx
        jne      L_e1aa
        test     byte ptr [g_xformDirtyFlags], 1
        jne      L_df8b
    L_df68:
        mov      eax, 1
        mov      dword ptr [esi + 8], OFFSET SceneEvalFsm_0049dea0
        mov      dword ptr [esi + 0x84], 3
        mov      dword ptr [g_pendingNodeType], eax
        mov      dword ptr [g_framePauseFlag], eax
        pop      esi
        pop      ebx
        ret      
    L_df8b:
        call     DualTestDirtyToggle_004282c0
        cmp      dword ptr [g_framePauseFlag], ebx
        jne      L_e1aa
        test     byte ptr [g_xformDirtyFlags], 1
        je       L_e05e
        jmp      L_e198
        push     6
        mov      byte ptr [g_data_00543728], bl
        call     TableWalkBoundedCmp_004bd890
        add      esp, 4
        push     2
        call     TableWalkBoundedCmp_004bd890
        add      esp, 4
        push     4
        call     TableWalkBoundedCmp_004bd890
        add      esp, 4
        push     -1
        push     -1
        push     -1
        push     0x1e
        call     QuadCallPhase2_004be800
        add      esp, 0x10
        call     DualTestDirtyToggle_00427ea0
        cmp      dword ptr [g_framePauseFlag], ebx
        jne      L_e1aa
        test     byte ptr [g_xformDirtyFlags], 1
        jne      L_e010
        mov      dword ptr [g_walkCallback], 1
        mov      dword ptr [g_active_0053a408], 1
    L_e010:
        call     AmbientMonitorCluster_0049e3c0
        cmp      dword ptr [g_framePauseFlag], ebx
        jne      L_e1aa
        call     GuardedCmpDualToggle_0049e360
        cmp      dword ptr [g_framePauseFlag], ebx
        jne      L_e1aa
        cmp      dword ptr [g_data_0053a3c0], ebx
        je       L_e0fc
        cmp      dword ptr [g_active_0053a408], 2
        je       L_e0fc
        mov      eax, dword ptr [g_active_00537e88]
        cmp      eax, 2
        mov      dword ptr [g_walkCallback], eax
        je       L_e0fc
    L_e05e:
        cmp      dword ptr [g_data_00543714], ebx
        je       L_e09d
        cmp      dword ptr [g_data_0054356c], ebx
        je       L_e09d
        cmp      dword ptr [g_data_005433ec], ebx
        je       L_e09d
        mov      al, byte ptr [g_data_00543590]
        mov      dword ptr [g_data_0053a3c0], ebx
        cmp      al, 1
        mov      dword ptr [g_data_00541fb0], 4
        jne      L_e097
        mov      dword ptr [g_data_005380e0], ebx
        jmp      L_e09d
    L_e097:
        mov      dword ptr [g_data_00537f48], ebx
    L_e09d:
        mov      dword ptr [esi + 8], OFFSET SceneEvalFsm_0049dea0
        mov      edx, dword ptr [g_baseSel_00542060]
        mov      ecx, OFFSET SceneEvalFsm_0049dea0
        mov      dword ptr [edx*4 + 0x84], 4
        mov      eax, dword ptr [esi + 4]
        add      ecx, 0x4000000
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      edx, dword ptr [g_baseSel_00542060]
        mov      dword ptr [edx*4 + 0x84], ebx
        call     PendingMatch_00461ca0
        mov      dword ptr [g_framePauseFlag], 1
        pop      esi
        pop      ebx
        ret      
    L_e0fc:
        mov      ax, word ptr [g_data_004e2868]
        mov      dword ptr [g_data_0052aac4], 3
        push     eax
        mov      dword ptr [g_data_00537eec], ebx
        mov      dword ptr [g_data_0053a468], ebx
        mov      dword ptr [g_walkCallback], ebx
        mov      dword ptr [g_data_00535e44], ebx
        call     TaggedSceneDispatch_004be690
        add      esp, 4
        call     ThrowAnimTriggerCluster_0049efa0
        cmp      dword ptr [g_framePauseFlag], ebx
        jne      L_e1aa
        mov      dword ptr [esi + 8], OFFSET SceneEvalFsm_0049dea0
        mov      ecx, dword ptr [g_baseSel_00542060]
        mov      edx, OFFSET SceneEvalFsm_0049dea0
        mov      dword ptr [ecx*4 + 0x84], 1
        mov      eax, dword ptr [esi + 4]
        add      edx, 0x1000000
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], edx
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      eax, dword ptr [g_baseSel_00542060]
        mov      dword ptr [eax*4 + 0x84], ebx
        call     PhaseClampInstallSlot_0049e1c0
        mov      dword ptr [g_framePauseFlag], 1
        pop      esi
        pop      ebx
        ret      
    L_e198:
        call     BootInitGuardedCallChain_004265d0
        cmp      dword ptr [g_framePauseFlag], ebx
        jne      L_e1aa
        call     StackPopDispatchTagged_0041f780
    L_e1aa:
        pop      esi
        pop      ebx
        ret
        _emit 0x8d
        _emit 0x49
        _emit 0x00
    L_jmptbl:
        _emit 0xae
        _emit 0xdf
        _emit 0x49
        _emit 0x00
        _emit 0xcd
        _emit 0xde
        _emit 0x49
        _emit 0x00
        _emit 0x22
        _emit 0xdf
        _emit 0x49
        _emit 0x00
        _emit 0x3c
        _emit 0xdf
        _emit 0x49
        _emit 0x00
    }
}
