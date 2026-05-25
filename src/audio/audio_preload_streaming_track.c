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

extern void PendingMatch_004a62b0(void);
extern void AudioPreloadStreamingTrack_004a6e70(void);
extern void FiveTableWalkInit_00403c90(void);
extern void CallSetPause_0041f830(void);
extern void BootInitGuardedCallChain_004265d0(void);
extern void IncCapped3e7_00491920(void);
/* extern void AllocNode(void); -- defined elsewhere with diff sig */
extern void TripleCallSetCopy_004a4880(void);
extern void MemcpyByteN_004a5680(void);
extern void AudioInstallSelfStatePush_004aa8a0(void);
extern void LoadGeoAsset_Default(void);
extern void TableWalkBoundedCmp_004bd890(int);
extern void QuadCallPhase2_004be800(void);
extern unsigned int g_audioPreloadVar2_004f3a58;
extern unsigned int g_audioPreloadVar_004f3a70;
extern unsigned int g_dispatchSave519_004f3a98;
extern unsigned int g_data_004f3aa8;
extern unsigned int g_audioPreloadBase_0050b118;
extern unsigned int g_count_005433b8;
extern unsigned int g_byte_005435a0;
extern unsigned int g_byte_005435b8;
extern unsigned int g_audioPreloadState_00543830;


__declspec(naked) void AudioPreloadStreamingTrack_004a6e70(void)
{
    __asm {
        mov      eax, dword ptr [g_baseSel_00542060]
        shl      eax, 2
        mov      ecx, dword ptr [eax + 0x84]
        mov      dword ptr [eax + 0x84], 0
        test     ecx, ecx
        je       L_6fc9
        push     8
        call     TableWalkBoundedCmp_004bd890
        add      esp, 4
        push     7
        call     TableWalkBoundedCmp_004bd890
        add      esp, 4
        call     BootInitGuardedCallChain_004265d0
        call     IncCapped3e7_00491920
        push     -1
        push     -1
        push     -1
        push     0x1e
        call     QuadCallPhase2_004be800
        add      esp, 0x10
        call     FiveTableWalkInit_00403c90
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_702b
        mov      ecx, OFFSET g_audioPreloadBase_0050b118
        shr      ecx, 2
        mov      dword ptr [g_currentNodeIdx], ecx
        call     LoadGeoAsset_Default
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_702b
        call     TripleCallSetCopy_004a4880
        mov      eax, dword ptr [g_count_005433b8]
        cmp      eax, 4
        mov      eax, dword ptr [g_audioBankSel_00537f94]
        jne      short L_6f3d
        mov      edx, dword ptr [g_audioPreloadState_00543830]
        cmp      eax, 1
        lea      eax, [edx*4]
        mov      ecx, dword ptr [eax + g_audioPreloadVar2_004f3a58]
        lea      ecx, [ecx + ecx*2]
        jne      short L_6f2e
        mov      eax, dword ptr [eax + g_dispatchSave519_004f3a98]
        lea      ecx, [ecx*8 + g_byte_005435a0]
        jmp      short L_6f7f
    L_6f2e:
        mov      eax, dword ptr [eax + g_dispatchSave519_004f3a98]
        lea      ecx, [ecx*8 + g_byte_005435b8]
        jmp      short L_6f7f
    L_6f3d:
        cmp      eax, 1
        jne      short L_6f5c
        mov      eax, dword ptr [g_audioPreloadState_00543830]
        shl      eax, 2
        mov      ecx, dword ptr [eax + g_audioPreloadVar_004f3a70]
        lea      ecx, [ecx + ecx*2]
        lea      ecx, [ecx*8 + g_byte_005435a0]
        jmp      short L_6f79
    L_6f5c:
        mov      edx, dword ptr [g_audioPreloadState_00543830]
        lea      eax, [edx*4]
        mov      ecx, dword ptr [eax + g_audioPreloadVar_004f3a70]
        lea      ecx, [ecx + ecx*2]
        lea      ecx, [ecx*8 + g_byte_005435b8]
    L_6f79:
        mov      eax, dword ptr [eax + g_data_004f3aa8]
    L_6f7f:
        lea      edx, [eax + eax*2]
        push     0x18
        push     ecx
        lea      eax, [edx*8 + g_byte_005435a0]
        push     eax
        call     MemcpyByteN_004a5680
        mov      ecx, dword ptr [g_audioPreloadState_00543830]
        add      esp, 0xc
        inc      ecx
        mov      dword ptr [g_pendingNodeType], OFFSET PendingMatch_004a62b0
        mov      dword ptr [g_audioPreloadState_00543830], ecx
        mov      dword ptr [g_eventQueueWorkType], 0x1000
        call     AllocNode
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_702b
        jmp      CallSetPause_0041f830
    L_6fc9:
        mov      dword ptr [eax + 8], OFFSET AudioPreloadStreamingTrack_004a6e70
        mov      ecx, dword ptr [g_baseSel_00542060]
        mov      edx, OFFSET AudioPreloadStreamingTrack_004a6e70
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
        call     AudioInstallSelfStatePush_004aa8a0
        mov      dword ptr [g_framePauseFlag], 1
    L_702b:
        ret
    }
}
