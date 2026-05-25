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

extern void StageEventComplexFsm_0047c680(void);
extern void GuardedDispatch_00460ca0(void);
extern void GuardedDispatch_00460cd0(void);
extern void NotShrCmp1Store_00460d80(void);
extern void OneSetCmpJmpLoadCall_0047c620(void);
extern void TripleEntryTblPushJmp_0047c880(void);
extern void StageEventExitCluster_0047cd50(void);
extern void DeltaAbsCompareBitToggle_0048ea90(void);
extern void DirtyToggleByGate_0048f350(void);
extern void EsiEdiAliasDualMul10_004906b0(void);
extern void PunchAnimCluster_00496d80(void);
extern unsigned int g_data_004ffe28;

extern unsigned int g_data_0052d74c;
extern unsigned int g_data_00537f94;
extern unsigned int g_data_00538068;
extern unsigned int g_player1NodeIdx;
extern unsigned int g_framePauseFlag;
extern unsigned int g_currentNodeIdx;
extern unsigned int g_xformEntityIdx;
extern unsigned int g_pendingNodeType;
extern unsigned int g_fightGroupHead;
extern unsigned int g_baseSel_00542060;
extern unsigned int g_xformScratch2088;
extern unsigned int g_xformDirtyFlags;

__declspec(naked) void StageEventComplexFsm_0047c680(void)
{
    __asm {
        mov      eax, dword ptr [g_baseSel_00542060]
        push     ebx
        push     ebp
        push     esi
        lea      esi, [eax*4]
        push     edi
        xor      edi, edi
        mov      eax, dword ptr [esi + 0x84]
        mov      dword ptr [esi + 0x84], edi
        cmp      eax, edi
        je       L_c819
        mov      ebx, 0x18000
        mov      ebp, 0x10000
    L_c6b0:
        mov      eax, dword ptr [g_data_00537f94]
        cmp      eax, edi
        mov      dword ptr [g_walkCallback], eax
        jne      L_c82f
        call     NotShrCmp1Store_00460d80
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_c855
        mov      eax, dword ptr [g_walkCallback]
        mov      ecx, eax
        and      ecx, 9
        cmp      ecx, 9
        mov      dword ptr [g_eventQueueCurrent], ecx
        je       L_c85a
        and      eax, 5
        cmp      eax, 5
        mov      dword ptr [g_eventQueueCurrent], eax
        je       L_c864
        mov      dword ptr [g_walkCallback], 0xb333
        call     EsiEdiAliasDualMul10_004906b0
        cmp      dword ptr [g_framePauseFlag], edi
        jne      short L_c855
        mov      dword ptr [g_xformScratch2088], ebx
        call     PunchAnimCluster_00496d80
        cmp      dword ptr [g_framePauseFlag], edi
        jne      short L_c855
        call     DeltaAbsCompareBitToggle_0048ea90
        cmp      dword ptr [g_framePauseFlag], edi
        jne      short L_c855
        mov      al, byte ptr [g_xformDirtyFlags]
        mov      dword ptr [g_walkCallback], ebp
        test     al, 1
        jne      short L_c759
        mov      dword ptr [g_walkCallback], 0x8000
    L_c759:
        call     EsiEdiAliasDualMul10_004906b0
        cmp      dword ptr [g_framePauseFlag], edi
        jne      short L_c855
        mov      edx, dword ptr [g_fightGroupHead]
        mov      esi, dword ptr [g_player1NodeIdx]
        mov      eax, OFFSET g_data_0052d74c
        mov      ecx, OFFSET g_data_00538068
        shr      eax, 2
        shr      ecx, 2
        cmp      edx, esi
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [g_xformEntityIdx], ecx
        je       short L_c79c
        mov      eax, ecx
        mov      dword ptr [g_currentNodeIdx], eax
    L_c79c:
        mov      eax, dword ptr [eax*4]
        cmp      eax, edi
        mov      dword ptr [g_walkCallback], eax
        je       short L_c86e
        mov      eax, OFFSET g_data_004ffe28
        shr      eax, 2
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [edx*4 + 0x24], eax
        mov      ecx, dword ptr [g_baseSel_00542060]
        mov      eax, dword ptr [ecx*4 + 0x68]
        dec      eax
        mov      dword ptr [g_walkCallback], eax
        jne      short L_c7eb
        call     TripleEntryTblPushJmp_0047c880
        cmp      dword ptr [g_framePauseFlag], edi
        jne      short L_c855
        mov      eax, dword ptr [g_walkCallback]
    L_c7eb:
        mov      edx, dword ptr [g_baseSel_00542060]
        mov      dword ptr [edx*4 + 0x68], eax
        mov      eax, dword ptr [g_baseSel_00542060]
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], edi
        cmp      eax, edi
        jne      L_c6b0
    L_c819:
        call     DirtyToggleByGate_0048f350
        cmp      dword ptr [g_framePauseFlag], edi
        jne      short L_c855
        test     byte ptr [g_xformDirtyFlags], 4
        je       short L_c839
    L_c82f:
        call     StageEventExitCluster_0047cd50
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        ret
    L_c839:
        mov      eax, 1
        mov      dword ptr [esi + 8], OFFSET StageEventComplexFsm_0047c680
        mov      dword ptr [esi + 0x84], eax
        mov      dword ptr [g_pendingNodeType], eax
        mov      dword ptr [g_framePauseFlag], eax
    L_c855:
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        ret
    L_c85a:
        call     GuardedDispatch_00460ca0
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        ret
    L_c864:
        call     GuardedDispatch_00460cd0
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        ret
    L_c86e:
        call     OneSetCmpJmpLoadCall_0047c620
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        ret
    }
}
