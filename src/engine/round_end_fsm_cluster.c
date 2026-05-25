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

extern unsigned int g_data_004e9068;
extern unsigned int g_state_0052aac4_aa;
extern unsigned int g_state_0054355c_hh;
extern unsigned int g_data_00543568;
extern unsigned int g_data_00543714;
extern void ArgSarAddDerefJmp_0048e710(void);
extern void AudioInstallSelfStatePush_004aa8a0(void);
extern void BootInitGuardedCallChain_004265d0(void);
extern void CallSetPause_0041f830(void);
extern void DispatcherComplex115_0049f900(void);
extern void DispatcherComplex115_0049f980(void);
extern void InstallSelfPackedF80_00426000(void);
extern void InstallSelfTableWalk_004200d0(void);
extern void ScenegraphWalk_0041f7d0(void);
extern void SixCallSeqPushImm_004a1d80(void);
extern void TripleStageRollback_00404a50(void);

__declspec(naked) void RoundEndFsmCluster_0045d680(void)
{
    __asm {
        /* === Helper 1 (0x45d680): round-end FSM === */
    L_d680:
        mov      eax, dword ptr [g_baseSel_00542060]
        push     ebx
        push     esi
        push     edi
        lea      esi, [eax*4]
        xor      edi, edi
        mov      eax, dword ptr [esi + 0x84]
        mov      dword ptr [esi + 0x84], edi
        sub      eax, edi
        je       L_d77d
        dec      eax
        je       short L_d6f9
        dec      eax
        je       short L_d6d4
        mov      dword ptr [esi + 8], OFFSET L_d680
        mov      dword ptr [esi + 0x84], 3
        mov      dword ptr [g_pendingNodeType], 8
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        pop      ebx
        ret
    L_d6d4:
        call     SixCallSeqPushImm_004a1d80
        mov      ecx, dword ptr [g_baseSel_00542060]
        mov      eax, 0x1000
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0xc], eax
        call     InstallSelfTableWalk_004200d0
        pop      edi
        pop      esi
        pop      ebx
        ret
    L_d6f9:
        mov      ebx, 2
        mov      dword ptr [g_walkCallback], ebx
        mov      dword ptr [g_active_0053a408], ebx
        mov      dword ptr [g_active_00537e88], ebx
        call     BootInitGuardedCallChain_004265d0
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_d82c
        mov      dword ptr [esi + 8], OFFSET L_d680
        mov      edx, dword ptr [g_baseSel_00542060]
        mov      ecx, OFFSET L_d680
        mov      dword ptr [edx*4 + 0x84], ebx
        mov      eax, dword ptr [esi + 4]
        add      ecx, 0x2000000
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      edx, dword ptr [g_baseSel_00542060]
        mov      dword ptr [edx*4 + 0x84], edi
        call     AudioInstallSelfStatePush_004aa8a0
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        pop      ebx
        ret
    L_d77d:
        push     0x4000
        call     TripleStageRollback_00404a50
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      dword ptr [g_state_0052aac4_aa], edi
        add      esp, 4
        mov      dword ptr [eax*4], edi
        mov      dword ptr [g_walkCallback], edi
        mov      dword ptr [g_active_0053a408], edi
        mov      dword ptr [g_active_00537e88], edi
        call     ScenegraphWalk_0041f7d0
        mov      dword ptr [g_eventQueueWorkType], 4
        call     Push16Call_00489f50
        cmp      dword ptr [g_framePauseFlag], edi
        jne      short L_d82c
        mov      dword ptr [g_eventQueueCurrent], 0xa
        mov      dword ptr [esi + 8], OFFSET L_d680
        mov      ecx, dword ptr [g_baseSel_00542060]
        mov      ebx, 1
        mov      edx, OFFSET L_d680
        mov      dword ptr [ecx*4 + 0x84], ebx
        mov      eax, dword ptr [esi + 4]
        add      edx, 0x1000000
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], edx
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      eax, dword ptr [g_baseSel_00542060]
        mov      dword ptr [eax*4 + 0x84], edi
        call     InstallSelfPackedF80_00426000
        mov      dword ptr [g_framePauseFlag], ebx
    L_d82c:
        pop      edi
        pop      esi
        pop      ebx
        ret
        /* === Helper 2: jmp 0041f830 === */
        jmp      CallSetPause_0041f830
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
        /* === Helper 3: call 0049f900 + jmp 0041f830 === */
        call     DispatcherComplex115_0049f900
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_d853
        jmp      CallSetPause_0041f830
    L_d853:
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
        /* === Helper 4: jmp 0041f830 === */
        jmp      CallSetPause_0041f830
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
        /* === Helper 5: flag-gated dispatch w/ 4e9068 fallback === */
        mov      eax, dword ptr [g_data_00543714]
        test     eax, eax
        je       short L_d890
        mov      eax, dword ptr [g_data_00543568]
        test     eax, eax
        jne      short L_d890
        cmp      byte ptr [g_gtModeFlag], 1
        jne      short L_d890
        jmp      CallSetPause_0041f830
    L_d890:
        mov      eax, dword ptr [g_state_0054355c_hh]
        test     eax, eax
        je       short L_d89e
        jmp      CallSetPause_0041f830
    L_d89e:
        push     OFFSET g_data_004e9068
        call     ArgSarAddDerefJmp_0048e710
        add      esp, 4
        ret
        nop
        nop
        nop
        nop
        /* === Helper 6: jmp 0041f830 === */
        jmp      CallSetPause_0041f830
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
        /* === Helper 7: call 0049f980 + jmp 0041f830 === */
        call     DispatcherComplex115_0049f980
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_d8d3
        jmp      CallSetPause_0041f830
    L_d8d3:
        ret
    }
}
