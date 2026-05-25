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
extern unsigned int g_data_00535e70;
extern unsigned int g_data_00535e74;
extern unsigned int g_data_00535e78;
extern unsigned int g_data_00535e7c;

extern unsigned int g_data_0052aabc;
extern unsigned int g_data_0052aac4;
extern unsigned int g_active_00537e88;
extern unsigned int g_data_0053a318;
extern unsigned int g_active_0053a408;
extern unsigned int g_data_00541dd8;
extern unsigned int g_framePauseFlag;
extern unsigned int g_currentNodeIdx;
extern unsigned int g_pendingNodeType;
extern unsigned int g_baseSel_00542060;
extern unsigned int g_eventQueueWorkType;
extern unsigned int g_acc_00542078;
extern unsigned int g_eventQueueNotMask;
extern unsigned int g_xformDirtyFlags;
extern unsigned int g_data_00543564;
extern unsigned int g_data_00543594;
extern unsigned int g_data_00550000;
extern unsigned int g_data_008c0000;
extern void CallSetPause_0041f830(void);
extern void Cmp7DirtyToggle_0042ee10(void);
extern void DispatcherComplex181_00426310(void);
extern void GuardedDualMaskFlagToggle_004261d0(void);
extern void RoundCleanupCluster_00427690(void);
extern void SaveCallRestore_004049d0(void);
extern void SetWalkCurCallPauseDirty_00404c70(void);
extern void StoreIncrMStackPush6_004275c0(void);

__declspec(naked) void Event23bMusicCluster_0042f540(void)
{
    __asm {
        /* === Main: event 0x23b dispatch === */
        push     ebx
        push     0x23b
        call     SaveCallRestore_004049d0
        mov      eax, dword ptr [g_active_0053a408]
        mov      edx, dword ptr [g_data_0053a318]
        mov      ecx, dword ptr [g_active_00537e88]
        add      esp, 4
        cmp      eax, 1
        jne      short L_f57b
        test     ecx, ecx
        jne      short L_f57b
        cmp      edx, 2
        jne      short L_f57b
        mov      ebx, dword ptr [g_data_00543594]
        test     ebx, ebx
        jl       L_f691
    L_f57b:
        test     eax, eax
        jne      short L_f599
        cmp      ecx, 1
        jne      short L_f599
        cmp      edx, ecx
        jne      short L_f612
        mov      eax, dword ptr [g_data_00543564]
        test     eax, eax
        jl       L_f691
    L_f599:
        cmp      edx, 1
        jne      short L_f612
        mov      eax, dword ptr [g_data_0052aabc]
        mov      dword ptr [g_walkCallback], eax
        call     StoreIncrMStackPush6_004275c0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_f691
        mov      dword ptr [g_eventQueueCurrent], 4
        mov      dword ptr [g_eventQueueWorkType], 0x23b
        mov      dword ptr [g_acc_00542078], OFFSET g_data_00550000
        mov      dword ptr [g_eventQueueNotMask], OFFSET g_data_008c0000
        mov      dword ptr [g_currentNodeFlags], 1
        call     DispatcherComplex181_00426310
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_f691
        call     RoundCleanupCluster_00427690
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_f691
        jmp      short L_f67a
    L_f612:
        mov      edx, dword ptr [g_data_0052aabc]
        mov      dword ptr [g_walkCallback], edx
        call     StoreIncrMStackPush6_004275c0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_f691
        mov      dword ptr [g_eventQueueCurrent], 4
        mov      dword ptr [g_eventQueueWorkType], 0x23b
        mov      dword ptr [g_acc_00542078], 0xff920000
        mov      dword ptr [g_eventQueueNotMask], OFFSET g_data_008c0000
        mov      dword ptr [g_currentNodeFlags], 1
        call     DispatcherComplex181_00426310
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_f691
        call     RoundCleanupCluster_00427690
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_f691
    L_f67a:
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      eax, 0x14000
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x5c], eax
    L_f691:
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
        nop
        nop
        nop
        nop
        nop
        /* === Helper 2 (0x42f6a0): event 0x225 tail === */
        call     Cmp7DirtyToggle_0042ee10
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_f6ce
        test     byte ptr [g_xformDirtyFlags], 1
        je       short L_f6c9
        push     0x225
        push     OFFSET L_f6d0
        call     SetWalkCurCallPauseDirty_00404c70
        add      esp, 8
    L_f6c9:
        jmp      CallSetPause_0041f830
    L_f6ce:
        ret
        nop
        /* === Helper 3 (0x42f6d0): callback handler === */
    L_f6d0:
        mov      eax, dword ptr [g_baseSel_00542060]
        push     ebx
        push     esi
        mov      ebx, 1
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        test     eax, eax
        je       short L_f733
        mov      eax, dword ptr [g_data_0052aac4]
        cmp      eax, 7
        mov      dword ptr [g_walkCallback], eax
        jne      short L_f72b
        mov      eax, dword ptr [g_data_0052aabc]
        test     eax, eax
        mov      dword ptr [g_walkCallback], eax
        je       short L_f72b
        call     GuardedDualMaskFlagToggle_004261d0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_f75c
        test     byte ptr [g_xformDirtyFlags], bl
        jne      short L_f733
    L_f72b:
        call     CallSetPause_0041f830
        pop      esi
        pop      ebx
        ret
    L_f733:
        mov      dword ptr [g_walkCallback], ebx
        mov      dword ptr [g_data_00541dd8], ebx
        mov      dword ptr [esi + 8], OFFSET L_f6d0
        mov      dword ptr [esi + 0x84], ebx
        mov      dword ptr [g_pendingNodeType], 0xa
        mov      dword ptr [g_framePauseFlag], ebx
    L_f75c:
        pop      esi
        pop      ebx
        ret
    }
}
