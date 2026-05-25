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

extern unsigned int g_data_004eb1e0;
extern unsigned int g_data_004eb240;
extern unsigned int g_data_004eb258;
extern void ArgSarStoreJmp_004594f0(void);
extern void ComboScriptDispatchCluster_00470530(void);
extern void FiveCallGuardSetTail_0046f6b0(void);
extern void GuardedSeq_004297b0(void);
extern void InstallSelfChainedDispatch_0046cb70(void);
extern void InstallSelfIndirectJmp_0048f3f0(void);
extern void InstallSelfMStackPush_0046cc80(void);
extern void PushPopWalkSet1006_00470ee0(void);
extern void ScaledAndAlfe_00490390(void);
extern void ScaledInit_0048d450(void);
extern void ScaledLoadIncJmp_00429840(void);
extern void ScaledMove74to70_0046eaa0(void);
extern void SlotEvent3EntryChain_0046fdf0(void);

__declspec(naked) void HitStateCluster_0046c7c0(void)
{
    __asm {
        mov      eax, dword ptr [g_fightGroupHead]
        mov      eax, dword ptr [eax*4 + 0x40]
        mov      dword ptr [g_eventQueueWorkType], eax
        and      eax, 0x200
        mov      dword ptr [g_xformScratch94], eax
        mov      eax, dword ptr [g_xformDirtyFlags]
        je       L_c7ea
        or       al, 1
        mov      dword ptr [g_xformDirtyFlags], eax
        ret      
    L_c7ea:
        and      al, 0xfe
        mov      dword ptr [g_xformDirtyFlags], eax
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
        call     ScaledMove74to70_0046eaa0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_c840
        mov      ecx, dword ptr [g_baseSel_00542060]
        mov      eax, 0x600
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x74], eax
        call     ScaledAndAlfe_00490390
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_c840
        push     OFFSET g_data_004eb1e0
        call     ArgSarStoreJmp_004594f0
        add      esp, 4
    L_c840:
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
        nop      
        mov      eax, OFFSET g_data_004eb240
        sar      eax, 2
        mov      dword ptr [g_eventQueueEnd], eax
        jmp      ComboScriptDispatchCluster_00470530
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
        push     OFFSET g_data_004eb258
        call     ArgSarStoreJmp_004594f0
        add      esp, 4
        ret      
        nop      
        nop      
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      dword ptr [g_eventQueueCurrent], 0x51e
        mov      eax, dword ptr [ecx*4 + 0x4c]
        test     eax, eax
        mov      dword ptr [g_walkCallback], eax
        jne      L_c8aa
        mov      eax, 0x51e
        mov      dword ptr [g_walkCallback], eax
    L_c8aa:
        mov      dword ptr [ecx*4 + 0x4c], eax
        mov      eax, dword ptr [g_matrixStackTop]
        inc      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], OFFSET L_c8d0
        jmp      InstallSelfIndirectJmp_0048f3f0
        nop
        nop
        nop
        nop
    L_c8d0:
        mov      eax, dword ptr [g_baseSel_00542060]
        xor      edx, edx
        shl      eax, 2
        mov      ecx, dword ptr [eax + 0x84]
        mov      dword ptr [eax + 0x84], edx
        cmp      ecx, edx
        je       L_c8ef
        jmp      FiveCallGuardSetTail_0046f6b0
    L_c8ef:
        mov      dword ptr [eax + 8], OFFSET L_c8d0
        mov      ecx, dword ptr [g_baseSel_00542060]
        push     edi
        mov      edi, OFFSET L_c8d0
        mov      dword ptr [ecx*4 + 0x84], 1
        mov      ecx, dword ptr [eax + 4]
        add      edi, 0x1000000
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      dword ptr [ecx*4], edi
        mov      ecx, dword ptr [g_currentNodeIdx]
        inc      ecx
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      dword ptr [eax + 4], ecx
        mov      eax, dword ptr [g_baseSel_00542060]
        mov      dword ptr [eax*4 + 0x84], edx
        call     SlotEvent3EntryChain_0046fdf0
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        ret
    L_c950:
        mov      eax, dword ptr [g_baseSel_00542060]
        xor      edx, edx
        shl      eax, 2
        mov      ecx, dword ptr [eax + 0x84]
        mov      dword ptr [eax + 0x84], edx
        cmp      ecx, edx
        je       L_c96f
        jmp      FiveCallGuardSetTail_0046f6b0
    L_c96f:
        mov      dword ptr [eax + 8], OFFSET L_c950
        mov      ecx, dword ptr [g_baseSel_00542060]
        push     edi
        mov      edi, OFFSET L_c950
        mov      dword ptr [ecx*4 + 0x84], 1
        mov      ecx, dword ptr [eax + 4]
        add      edi, 0x1000000
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      dword ptr [ecx*4], edi
        mov      ecx, dword ptr [g_currentNodeIdx]
        inc      ecx
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      dword ptr [eax + 4], ecx
        mov      eax, dword ptr [g_baseSel_00542060]
        mov      dword ptr [eax*4 + 0x84], edx
        call     SlotEvent3EntryChain_0046fdf0
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        ret
    L_c9d0:
        mov      eax, dword ptr [g_baseSel_00542060]
        push     ebx
        push     esi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        sub      eax, 0
        je       L_cab8
        dec      eax
        mov      ebx, 1
        je       L_ca67
        call     CopyJmp_0048ef90
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_cb69
        test     byte ptr [g_xformDirtyFlags], bl
        jne      L_ca22
        call     InstallSelfMStackPush_0046cc80
        pop      esi
        pop      ebx
        ret      
    L_ca22:
        call     GuardedSeq_004297b0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_cb69
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      dword ptr [g_eventQueueCurrent], 0x51e
        mov      eax, dword ptr [ecx*4 + 0x4c]
        test     eax, eax
        mov      dword ptr [g_walkCallback], eax
        jne      L_ca5e
        mov      eax, 0x51e
        mov      dword ptr [g_walkCallback], eax
    L_ca5e:
        mov      dword ptr [ecx*4 + 0x4c], eax
        jmp      L_ca74
    L_ca67:
        mov      eax, dword ptr [g_eventQueueChild]
        dec      eax
        mov      dword ptr [g_eventQueueChild], eax
        jne      L_cac2
    L_ca74:
        call     ScaledAndAlfe_00490390
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_cb69
        call     PushPopWalkSet1006_00470ee0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_cb69
        mov      dword ptr [esi + 8], OFFSET L_c9d0
        mov      dword ptr [esi + 0x84], 2
        mov      dword ptr [g_pendingNodeType], ebx
        mov      dword ptr [g_framePauseFlag], ebx
        pop      esi
        pop      ebx
        ret      
    L_cab8:
        mov      dword ptr [g_eventQueueChild], 3
    L_cac2:
        call     ScaledLoadIncJmp_00429840
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_cb69
        mov      eax, dword ptr [g_matrixStackTop]
        mov      ecx, dword ptr [g_eventQueueChild]
        inc      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], ecx
        mov      dword ptr [g_walkCallback], 0x27
        call     ScaledInit_0048d450
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_cb69
        mov      eax, dword ptr [g_matrixStackTop]
        mov      ebx, 1
        mov      edx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      al, byte ptr [g_xformDirtyFlags]
        test     al, bl
        mov      dword ptr [g_eventQueueChild], edx
        je       L_cb32
        call     InstallSelfChainedDispatch_0046cb70
        pop      esi
        pop      ebx
        ret      
    L_cb32:
        call     CopyJmp_0048ef90
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_cb69
        test     byte ptr [g_xformDirtyFlags], bl
        jne      L_cb50
        call     InstallSelfMStackPush_0046cc80
        pop      esi
        pop      ebx
        ret      
    L_cb50:
        mov      dword ptr [esi + 8], OFFSET L_c9d0
        mov      dword ptr [esi + 0x84], ebx
        mov      dword ptr [g_pendingNodeType], ebx
        mov      dword ptr [g_framePauseFlag], ebx
    L_cb69:
        pop      esi
        pop      ebx
        ret      
    }
}
