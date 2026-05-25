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
extern unsigned int g_state_00542094;
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
extern unsigned int g_state_00538158;
extern unsigned int g_data_00535cf8;
extern unsigned int g_cj_00542054;
extern unsigned int g_data_005437f0;
extern unsigned int g_data_00543598;
extern unsigned int g_data_0054358c;
extern unsigned int g_data_00535e70;
extern unsigned int g_data_00535e74;
extern unsigned int g_data_00535e78;
extern unsigned int g_data_00535e7c;

extern unsigned int g_data_004d57ac;
extern unsigned int g_data_004eee3c;
extern unsigned int g_framePauseFlag;
extern unsigned int g_currentNodeIdx;
extern unsigned int g_xformEntityIdx;
extern unsigned int g_fightGroupHead;
extern unsigned int g_baseSel_00542060;
extern unsigned int g_eventQueueWorkType;
extern unsigned int g_eventQueueNotMask;
extern unsigned int g_eventQueueChild;
extern void GatedChainClamp_00486e80(void);
extern void MStackPush3CallCascade_00486d90(void);
extern void Phase2InitDispatchInstallSelf_0040ba70(void);
extern void ScaledChainDouble_004911f0(void);

__declspec(naked) void RoundResultSlotInitTable_00486860(void)
{
    __asm {
        mov      eax, dword ptr [g_data_004d57ac]
        mov      ecx, dword ptr [g_walkCallback]
        inc      eax
        push     esi
        mov      dword ptr [g_data_004d57ac], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_data_004d57ac]
        mov      edx, dword ptr [g_eventQueueCurrent]
        inc      eax
        mov      dword ptr [g_data_004d57ac], eax
        mov      dword ptr [eax*4], edx
        mov      eax, dword ptr [g_data_004d57ac]
        mov      ecx, dword ptr [g_eventQueueNotMask]
        inc      eax
        mov      dword ptr [g_data_004d57ac], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_data_004d57ac]
        mov      edx, dword ptr [g_eventQueueChild]
        inc      eax
        mov      dword ptr [g_data_004d57ac], eax
        mov      dword ptr [eax*4], edx
        call     ScaledChainDouble_004911f0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_69c8
        mov      ecx, dword ptr [g_eventQueueNotMask]
        mov      edx, dword ptr [g_eventQueueChild]
        mov      esi, dword ptr [g_fightGroupHead]
        sar      ecx, 1
        sar      edx, 1
        mov      dword ptr [g_eventQueueNotMask], ecx
        mov      dword ptr [g_eventQueueChild], edx
        mov      eax, dword ptr [esi*4 + 0x54]
        mov      dword ptr [g_walkCallback], eax
        mov      esi, dword ptr [esi*4 + 0x5c]
        add      eax, ecx
        mov      ecx, dword ptr [g_baseSel_00542060]
        add      esi, edx
        add      ecx, 0x19
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [g_eventQueueCurrent], esi
        mov      dword ptr [g_eventQueueWorkType], 0xfffe6667
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      dword ptr [ecx*4], eax
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      eax, dword ptr [g_eventQueueWorkType]
        mov      dword ptr [edx*4 + 4], eax
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      ecx, dword ptr [g_eventQueueCurrent]
        mov      eax, OFFSET g_data_004eee3c
        shr      eax, 2
        mov      dword ptr [edx*4 + 8], ecx
        mov      dword ptr [g_xformEntityIdx], eax
        call     Phase2InitDispatchInstallSelf_0040ba70
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_69c8
        mov      eax, dword ptr [g_data_004d57ac]
        mov      ecx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_eventQueueChild], ecx
        mov      dword ptr [g_data_004d57ac], eax
        mov      edx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_eventQueueNotMask], edx
        mov      dword ptr [g_data_004d57ac], eax
        mov      ecx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_eventQueueCurrent], ecx
        mov      dword ptr [g_data_004d57ac], eax
        mov      edx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_walkCallback], edx
        mov      dword ptr [g_data_004d57ac], eax
    L_69c8:
        pop      esi
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        mov      eax, dword ptr [g_baseSel_00542060]
        mov      dword ptr [eax*4 + 0x74], 0x4004
        mov      dword ptr [g_eventQueueCurrent], 1
        mov      dword ptr [g_eventQueueWorkType], 0
        mov      dword ptr [g_eventQueueNotMask], 2
        mov      dword ptr [g_walkCallback], 0xf5c
        mov      dword ptr [g_eventQueueChild], 3
        jmp      MStackPush3CallCascade_00486d90
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        xor      ecx, ecx
        mov      eax, 1
        mov      dword ptr [g_eventQueueCurrent], ecx
        mov      dword ptr [g_eventQueueWorkType], eax
        mov      dword ptr [g_eventQueueNotMask], eax
        mov      dword ptr [g_walkCallback], ecx
        mov      dword ptr [g_eventQueueChild], 0x10
        jmp      MStackPush3CallCascade_00486d90
        nop
        nop
        nop
        nop
        mov      dword ptr [g_eventQueueCurrent], 0
        mov      dword ptr [g_eventQueueWorkType], 1
        mov      dword ptr [g_eventQueueNotMask], 2
        mov      dword ptr [g_walkCallback], 0x2e14
        mov      dword ptr [g_eventQueueChild], 0x15
        jmp      MStackPush3CallCascade_00486d90
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        mov      eax, 1
        mov      dword ptr [g_eventQueueNotMask], 2
        mov      dword ptr [g_eventQueueCurrent], eax
        mov      dword ptr [g_eventQueueWorkType], eax
        mov      dword ptr [g_walkCallback], 0x3333
        mov      dword ptr [g_eventQueueChild], 0x16
        jmp      MStackPush3CallCascade_00486d90
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
        mov      eax, 1
        mov      dword ptr [g_eventQueueChild], 0x17
        mov      dword ptr [g_eventQueueWorkType], eax
        mov      dword ptr [g_eventQueueCurrent], eax
        mov      dword ptr [g_eventQueueNotMask], 3
        mov      dword ptr [g_walkCallback], 0x4000
        jmp      MStackPush3CallCascade_00486d90
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
        mov      eax, 1
        mov      dword ptr [g_eventQueueChild], 7
        mov      dword ptr [g_eventQueueWorkType], eax
        mov      dword ptr [g_eventQueueCurrent], eax
        mov      dword ptr [g_eventQueueNotMask], 3
        mov      dword ptr [g_walkCallback], 0x4000
        jmp      MStackPush3CallCascade_00486d90
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
        mov      eax, 1
        mov      dword ptr [g_eventQueueNotMask], 2
        mov      dword ptr [g_eventQueueCurrent], eax
        mov      dword ptr [g_eventQueueWorkType], eax
        mov      dword ptr [g_walkCallback], 0x3333
        mov      dword ptr [g_eventQueueChild], 6
        jmp      MStackPush3CallCascade_00486d90
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
        mov      dword ptr [g_eventQueueCurrent], 1
        mov      dword ptr [g_eventQueueWorkType], 0
        mov      dword ptr [g_eventQueueNotMask], 2
        mov      dword ptr [g_walkCallback], 0x3333
        mov      dword ptr [g_eventQueueChild], 6
        jmp      MStackPush3CallCascade_00486d90
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        mov      dword ptr [g_eventQueueCurrent], 0
        mov      dword ptr [g_eventQueueWorkType], 1
        mov      dword ptr [g_eventQueueNotMask], 2
        mov      dword ptr [g_walkCallback], 0x2e14
        mov      dword ptr [g_eventQueueChild], 5
        jmp      MStackPush3CallCascade_00486d90
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        mov      dword ptr [g_eventQueueCurrent], 0
        mov      dword ptr [g_eventQueueWorkType], 1
        mov      dword ptr [g_eventQueueNotMask], 2
        mov      dword ptr [g_walkCallback], 0x2666
        mov      dword ptr [g_eventQueueChild], 4
        jmp      MStackPush3CallCascade_00486d90
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        mov      eax, dword ptr [g_baseSel_00542060]
        mov      dword ptr [eax*4 + 0x74], 0x4004
        mov      eax, 1
        mov      dword ptr [g_eventQueueCurrent], eax
        mov      dword ptr [g_eventQueueWorkType], eax
        mov      dword ptr [g_eventQueueNotMask], 2
        mov      dword ptr [g_walkCallback], 0xf5c
        mov      dword ptr [g_eventQueueChild], 3
        jmp      MStackPush3CallCascade_00486d90
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
        mov      eax, 1
        mov      dword ptr [g_eventQueueCurrent], 0
        mov      dword ptr [g_eventQueueWorkType], eax
        mov      dword ptr [g_eventQueueNotMask], eax
        mov      dword ptr [g_walkCallback], 0x3d70
        mov      dword ptr [g_eventQueueChild], eax
        jmp      MStackPush3CallCascade_00486d90
        nop
        nop
        nop
        xor      eax, eax
        mov      dword ptr [g_eventQueueNotMask], 1
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [g_eventQueueCurrent], eax
        mov      dword ptr [g_eventQueueWorkType], eax
        mov      dword ptr [g_eventQueueChild], eax
        jmp      MStackPush3CallCascade_00486d90
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
        xor      eax, eax
        mov      dword ptr [g_walkCallback], 0x2147
        mov      dword ptr [g_eventQueueCurrent], eax
        mov      dword ptr [g_eventQueueWorkType], eax
        mov      dword ptr [g_eventQueueNotMask], 2
        mov      dword ptr [g_eventQueueChild], 5
        jmp      MStackPush3CallCascade_00486d90
        nop
        xor      eax, eax
        mov      ecx, 1
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [g_eventQueueCurrent], eax
        mov      dword ptr [g_eventQueueWorkType], ecx
        mov      dword ptr [g_eventQueueNotMask], ecx
        mov      dword ptr [g_eventQueueChild], eax
        jmp      MStackPush3CallCascade_00486d90
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        xor      eax, eax
        mov      dword ptr [g_eventQueueCurrent], 1
        mov      dword ptr [g_eventQueueNotMask], 2
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [g_eventQueueChild], eax
        jmp      GatedChainClamp_00486e80
    }
}
