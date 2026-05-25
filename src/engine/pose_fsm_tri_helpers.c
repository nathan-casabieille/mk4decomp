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

extern unsigned int g_data_0052ab10;
extern unsigned int g_framePauseFlag;
extern unsigned int g_currentNodeIdx;
extern unsigned int g_pendingNodeType;
extern unsigned int g_eventQueueEnd;
extern unsigned int g_fightGroupHead;
extern unsigned int g_baseSel_00542060;
extern unsigned int g_eventQueueNotMask;
extern unsigned int g_eventQueueChild;
extern unsigned int g_xformScratch2088;
extern unsigned int g_data_00542094;
extern unsigned int g_data_00542188;
extern void AiAngleDistComputation_00431920(void);
extern void CameraAimSplineDriver_00430e60(void);
extern void DispatchOrInitFightGroup_0042f850(void);
extern void DualEntryInitDispatch_00431360(void);
extern void PendingMatch_00432110(void);
extern void PendingMatch_004326a0(void);
extern void ScaledInitWithCounterAndType_004314f0(void);

__declspec(naked) void PoseFsmTriHelpers_00431650(void)
{
    __asm {
        /* === h1 (0x431650): table-index wrapper, tail-jmp 31920 === */
        mov      ecx, dword ptr [g_eventQueueChild]
        mov      eax, OFFSET g_data_00542188
        shr      eax, 2
        add      eax, ecx
        mov      dword ptr [g_currentNodeIdx], eax
        mov      eax, dword ptr [eax*4]
        mov      dword ptr [g_currentNodeIdx], eax
        jmp      AiAngleDistComputation_00431920
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
        /* === h2 (0x431680): pause-guarded chain → 4314f0 tail-jmp === */
        call     DualEntryInitDispatch_00431360
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_1700
        mov      eax, dword ptr [g_eventQueueEnd]
        mov      dword ptr [g_xformScratch2088], 0x10000
        mov      eax, dword ptr [eax*4 + 0x34]
        mov      dword ptr [g_walkCallback], eax
        and      eax, 1
        mov      dword ptr [g_data_00542094], eax
        je       short L_16bd
        mov      dword ptr [g_xformScratch2088], 0xffff0000
    L_16bd:
        mov      ecx, dword ptr [g_eventQueueChild]
        mov      eax, OFFSET g_data_00542188
        shr      eax, 2
        add      eax, ecx
        mov      dword ptr [g_currentNodeIdx], eax
        mov      ecx, dword ptr [eax*4]
        mov      dword ptr [g_currentNodeIdx], ecx
        call     AiAngleDistComputation_00431920
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_1700
        call     PendingMatch_004326a0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_1700
        jmp      ScaledInitWithCounterAndType_004314f0
    L_1700:
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
        /* === h3 (0x431710): 3-case pose-fn dispatcher === */
    L_1710:
        mov      eax, dword ptr [g_baseSel_00542060]
        push     esi
        push     edi
        xor      edi, edi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], edi
        sub      eax, edi
        je       L_1853
        dec      eax
        je       L_1823
        dec      eax
        je       short L_1747
        call     DispatchOrInitFightGroup_0042f850
        pop      edi
        pop      esi
        ret
    L_1747:
        mov      edx, dword ptr [g_baseSel_00542060]
        mov      ecx, dword ptr [g_data_0052ab10]
        mov      dword ptr [g_fightGroupHead], ecx
        mov      dword ptr [g_walkCallback], edi
        lea      eax, [edx*4]
        mov      dword ptr [eax + 0x40], edi
        mov      ecx, dword ptr [g_walkCallback]
        mov      dword ptr [eax + 0x48], ecx
        call     CameraAimSplineDriver_00430e60
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_191d
        mov      edx, dword ptr [g_baseSel_00542060]
        mov      ecx, dword ptr [g_walkCallback]
        mov      dword ptr [edx*4 + 0x44], ecx
        lea      eax, [edx*4]
        mov      edx, dword ptr [g_eventQueueNotMask]
        mov      dword ptr [eax + 0x34], edx
        mov      ecx, dword ptr [g_eventQueueChild]
        mov      dword ptr [eax + 0x3c], ecx
        mov      ecx, 0x28
        mov      dword ptr [eax + 0x38], 0xfffe8000
        mov      dword ptr [g_walkCallback], ecx
        mov      dword ptr [eax + 0x30], ecx
        mov      dword ptr [esi + 8], OFFSET L_1710
        mov      edx, dword ptr [g_baseSel_00542060]
        mov      ecx, OFFSET L_1710
        add      ecx, 0x3000000
        mov      dword ptr [edx*4 + 0x84], 3
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      edx, dword ptr [g_baseSel_00542060]
        mov      dword ptr [edx*4 + 0x84], edi
        call     PendingMatch_00432110
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        ret
    L_1823:
        mov      eax, dword ptr [g_baseSel_00542060]
        mov      ecx, dword ptr [eax*4 + 0x78]
        mov      dword ptr [g_pendingNodeType], ecx
        mov      dword ptr [esi + 8], OFFSET L_1710
        mov      dword ptr [esi + 0x84], 2
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        ret
    L_1853:
        call     DualEntryInitDispatch_00431360
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_191d
        mov      edx, dword ptr [g_eventQueueEnd]
        mov      dword ptr [g_xformScratch2088], 0x10000
        mov      eax, dword ptr [edx*4 + 0x34]
        mov      dword ptr [g_walkCallback], eax
        and      eax, 1
        mov      dword ptr [g_data_00542094], eax
        je       short L_1894
        mov      dword ptr [g_xformScratch2088], 0xffff0000
    L_1894:
        mov      ecx, dword ptr [g_eventQueueChild]
        mov      eax, OFFSET g_data_00542188
        shr      eax, 2
        add      eax, ecx
        mov      dword ptr [g_currentNodeIdx], eax
        mov      eax, dword ptr [eax*4]
        mov      dword ptr [g_currentNodeIdx], eax
        call     AiAngleDistComputation_00431920
        cmp      dword ptr [g_framePauseFlag], edi
        jne      short L_191d
        mov      dword ptr [esi + 8], OFFSET L_1710
        mov      ecx, dword ptr [g_baseSel_00542060]
        mov      edx, OFFSET L_1710
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
        mov      dword ptr [eax*4 + 0x84], edi
        call     PendingMatch_00432110
        mov      dword ptr [g_framePauseFlag], 1
    L_191d:
        pop      edi
        pop      esi
        ret
    }
}
