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
extern unsigned int g_data_0050d23c;
extern unsigned int g_data_0050d258;
extern unsigned int g_data_0052ab4c;
extern unsigned int g_data_00535e6c;
extern unsigned int g_data_00537f78;
extern unsigned int g_data_00541de0;
extern unsigned int g_framePauseFlag;
extern unsigned int g_currentNodeIdx;
extern unsigned int g_xformEntityIdx;
extern unsigned int g_pendingNodeType;
extern unsigned int g_eventQueueEnd;
extern unsigned int g_baseSel_00542060;
extern unsigned int g_xformDirtyFlags;
extern void SaveCallRestoreOrXor_00404a00(void);
extern void ScaledChainInit2Phase_0042e800(void);

void RoundEndAudioCluster_0042e8d0(void) {
    __asm {
        /* H1 */
        mov      eax, dword ptr [g_data_004d57ac]
        mov      ecx, dword ptr [g_currentNodeIdx]
        inc      eax
        push     0x23c
        mov      dword ptr [g_data_004d57ac], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_data_004d57ac]
        mov      edx, dword ptr [g_eventQueueEnd]
        inc      eax
        mov      dword ptr [g_data_004d57ac], eax
        mov      dword ptr [eax*4], edx
        call     SaveCallRestoreOrXor_00404a00
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      ecx, OFFSET g_data_0050d23c
        shr      ecx, 2
        add      esp, 4
        mov      dword ptr [g_eventQueueEnd], eax
        mov      dword ptr [g_xformEntityIdx], ecx
        call     DispatcherComplex260_00407030
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_e9a6
        test     byte ptr [g_xformDirtyFlags], 4
        jne      short L_e949
        push     0x23a
        call     ScaledChainInit2Phase_0042e800
        add      esp, 4
    L_e949:
        mov      edx, OFFSET g_data_0050d258
        shr      edx, 2
        mov      dword ptr [g_xformEntityIdx], edx
        call     DispatcherComplex260_00407030
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_e9a6
        test     byte ptr [g_xformDirtyFlags], 4
        jne      short L_e97b
        push     0x268
        call     ScaledChainInit2Phase_0042e800
        add      esp, 4
    L_e97b:
        mov      eax, dword ptr [g_data_004d57ac]
        mov      ecx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_eventQueueEnd], ecx
        mov      dword ptr [g_data_004d57ac], eax
        mov      edx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_currentNodeIdx], edx
        mov      dword ptr [g_data_004d57ac], eax
    L_e9a6:
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
        /* H2 (L_e9b0): health fade */
    L_e9b0:
        mov      eax, dword ptr [g_baseSel_00542060]
        shl      eax, 2
        mov      ecx, dword ptr [eax + 0x84]
        mov      dword ptr [eax + 0x84], 0
        test     ecx, ecx
        jne      short L_e9d6
        mov      dword ptr [g_currentNodeFlags], 0xe666
    L_e9d6:
        mov      ecx, dword ptr [g_data_00537f78]
        mov      edx, dword ptr [g_currentNodeFlags]
        mov      dword ptr [ecx*4 + 0x3c], edx
        mov      edx, dword ptr [g_data_00541de0]
        mov      ecx, dword ptr [g_currentNodeFlags]
        mov      dword ptr [edx*4 + 0x3c], ecx
        mov      ecx, dword ptr [g_data_00535e6c]
        mov      edx, dword ptr [g_currentNodeFlags]
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      dword ptr [ecx*4 + 0x3c], edx
        mov      ecx, dword ptr [g_currentNodeFlags]
        sub      ecx, 0x83
        mov      dword ptr [g_walkCallback], 0x83
        cmp      ecx, 0x1999
        mov      dword ptr [g_currentNodeFlags], ecx
        jge      short L_ea43
        mov      dword ptr [g_currentNodeFlags], 0x1999
    L_ea43:
        mov      ecx, 1
        mov      dword ptr [eax + 8], OFFSET L_e9b0
        mov      dword ptr [eax + 0x84], ecx
        mov      dword ptr [g_pendingNodeType], ecx
        mov      dword ptr [g_framePauseFlag], ecx
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
        /* H3 (L_ea70): gray fade */
    L_ea70:
        mov      eax, dword ptr [g_baseSel_00542060]
        mov      ecx, 0xa0
        lea      edx, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [edx + 0x84], 0
        test     eax, eax
        je       short L_ea9c
        mov      ecx, dword ptr [g_eventQueueEnd]
    L_ea9c:
        mov      eax, ecx
        shl      eax, 8
        or       eax, ecx
        shl      eax, 8
        or       eax, ecx
        dec      ecx
        cmp      ecx, 0x19
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [g_data_0052ab4c], eax
        mov      dword ptr [g_eventQueueEnd], ecx
        jge      short L_eac8
        mov      dword ptr [g_eventQueueEnd], 0x19
    L_eac8:
        mov      eax, 1
        mov      dword ptr [edx + 8], OFFSET L_ea70
        mov      dword ptr [edx + 0x84], eax
        mov      dword ptr [g_pendingNodeType], 7
        mov      dword ptr [g_framePauseFlag], eax
        }
}

