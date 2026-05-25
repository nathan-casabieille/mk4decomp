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

extern void TripleVecAccCallStore_00476880(void);
extern void GatedWordPushCall_00489f90(void);
extern void Thunk_0049cbc0(void);
extern void StoreLoadJmp_00404ef0(void);
extern void PushSetXfmMaskCallPop_00407140(void);
extern void CmpDivJmp_0049d080(void);
extern void MStackCall_00406600(void);
extern void IK_ChainPoseUpdate_00444860(void);
extern unsigned int g_dispatchVar43_004e6070;
extern unsigned int g_data_004e5cc0;
extern unsigned int g_dispatchVar2_0053a24c;
extern unsigned int g_dispatchVar8_0053a35c;

extern void AudioVolumeRescale_004ab690(void);

__declspec(naked) void EndingScreenFsmCluster_00444390(void)
{
    __asm {
        mov      dword ptr [g_walkCallback], 0x200
        call     AudioVolumeRescale_004ab690
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_44bf
        test     byte ptr [g_xformDirtyFlags], 1
        jne      L_43d0
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      eax, dword ptr [ecx*4 + 0x34]
        or       al, 1
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x34], eax
    L_43d0:
        mov      eax, dword ptr [g_eventQueueEnd]
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      eax, dword ptr [eax*4 + 0x54]
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x54], eax
        mov      edx, dword ptr [g_eventQueueEnd]
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      eax, dword ptr [edx*4 + 0x5c]
        mov      dword ptr [ecx*4 + 0x5c], eax
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      eax, 0xffff999a
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [edx*4 + 0x58], eax
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [g_eventQueueWorkType], 0x3333
        add      ecx, 0x15
        mov      dword ptr [g_currentNodeIdx], ecx
        call     TripleVecAccCallStore_00476880
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_44bf
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      dword ptr [g_walkCallback], 0
        sub      eax, 0x15
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4 + 0x6c], 0
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      eax, dword ptr [g_walkCallback]
        mov      dword ptr [ecx*4 + 0x74], eax
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      eax, 0xfffff0a4
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [edx*4 + 0x70], eax
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [g_eventQueueWorkType], 0x20c
        add      ecx, 0x1b
        mov      dword ptr [g_currentNodeIdx], ecx
        call     TripleVecAccCallStore_00476880
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_44bf
        sub      dword ptr [g_currentNodeIdx], 0x1b
    L_44bf:
        ret
        mov      eax, dword ptr [g_xformEntityIdx]
        mov      dword ptr [eax*4 + 0x10], 0
        mov      ecx, dword ptr [g_xformEntityIdx]
        mov      eax, OFFSET g_dispatchVar43_004e6070
        shr      eax, 2
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x14], eax
        ret
        nop
        nop
        nop
        nop
        nop
    L_44f0:
        mov      eax, dword ptr [g_baseSel_00542060]
        push     esi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        sub      eax, 0
        je       L_4553
        dec      eax
        mov      dword ptr [g_walkCallback], 0x11
        call     GatedWordPushCall_00489f90
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_4574
        mov      dword ptr [esi + 8], OFFSET L_44f0
        mov      dword ptr [esi + 0x84], 2
        mov      dword ptr [g_pendingNodeType], 0x146
        mov      dword ptr [g_framePauseFlag], 1
        pop      esi
        ret
    L_4553:
        mov      eax, 1
        mov      dword ptr [esi + 8], OFFSET L_44f0
        mov      dword ptr [esi + 0x84], eax
        mov      dword ptr [g_pendingNodeType], 0x43
        mov      dword ptr [g_framePauseFlag], eax
    L_4574:
        pop      esi
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
    L_4580:
        mov      eax, dword ptr [g_baseSel_00542060]
        push     esi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        test     eax, eax
        je       L_45cd
        mov      ecx, dword ptr [g_baseSel_00542060]
        mov      eax, dword ptr [g_eventQueueEnd]
        dec      eax
        mov      edx, dword ptr [ecx*4 + 0x68]
        mov      dword ptr [g_eventQueueEnd], eax
        mov      dword ptr [g_fightGroupHead], edx
        jns      L_46fc
        call     Thunk_0049cbc0
        pop      esi
        ret
    L_45cd:
        mov      eax, dword ptr [g_baseSel_00542060]
        mov      ecx, dword ptr [g_eventQueueEnd]
        push     OFFSET L_4770
        mov      dword ptr [eax*4 + 0x64], ecx
        mov      edx, dword ptr [g_baseSel_00542060]
        mov      eax, dword ptr [g_eventQueueIdx]
        mov      dword ptr [edx*4 + 0x68], eax
        mov      eax, 0x451e
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [g_dispatchVar2_0053a24c], eax
        call     StoreLoadJmp_00404ef0
        mov      ecx, OFFSET g_data_004e5cc0
        add      esp, 4
        shr      ecx, 2
        mov      dword ptr [g_dispatchVar8_0053a35c], 0
        mov      dword ptr [g_walkCallback], ecx
        call     PushSetXfmMaskCallPop_00407140
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_475f
        test     byte ptr [g_xformDirtyFlags], 4
        jne      L_46e6
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      edx, dword ptr [g_eventQueueIdx]
        mov      dword ptr [g_dispatchVar8_0053a35c], ecx
        mov      eax, dword ptr [edx*4 + 0x34]
        and      eax, 1
        mov      dword ptr [g_walkCallback], eax
        mov      edx, dword ptr [ecx*4 + 0x34]
        or       eax, edx
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x34], eax
        mov      eax, dword ptr [g_matrixStackTop]
        mov      ecx, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], ecx
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      eax, dword ptr [edx*4 + 0x18]
        mov      dword ptr [g_walkCallback], 2
        mov      dword ptr [g_currentNodeIdx], eax
        call     CmpDivJmp_0049d080
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_475f
        mov      eax, dword ptr [g_matrixStackTop]
        mov      ecx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      dword ptr [g_matrixStackTop], eax
        call     MStackCall_00406600
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_475f
    L_46e6:
        mov      edx, dword ptr [g_eventQueueIdx]
        mov      dword ptr [g_eventQueueEnd], 0x2c
        mov      dword ptr [g_fightGroupHead], edx
    L_46fc:
        mov      eax, dword ptr [g_matrixStackTop]
        mov      ecx, dword ptr [g_eventQueueEnd]
        inc      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], ecx
        call     IK_ChainPoseUpdate_00444860
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_475f
        mov      eax, dword ptr [g_matrixStackTop]
        mov      edx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_eventQueueEnd], edx
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [esi + 8], OFFSET L_4580
        mov      dword ptr [esi + 0x84], 1
        mov      dword ptr [g_pendingNodeType], 1
        mov      dword ptr [g_framePauseFlag], 1
    L_475f:
        pop      esi
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
    L_4770:
        mov      eax, dword ptr [g_baseSel_00542060]
        shl      eax, 2
        mov      ecx, dword ptr [eax + 0x84]
        mov      dword ptr [eax + 0x84], 0
        sub      ecx, 0
        je       L_4803
        dec      ecx
        mov      ecx, dword ptr [g_eventQueueEnd]
        je       L_47b3
        dec      ecx
        mov      dword ptr [g_eventQueueEnd], ecx
        jns      L_47c6
        mov      ecx, dword ptr [g_eventQueueIdx]
        dec      ecx
        mov      dword ptr [g_eventQueueIdx], ecx
        jns      L_4817
        jmp      Thunk_0049cbc0
    L_47b3:
        dec      ecx
        mov      dword ptr [g_eventQueueEnd], ecx
        jns      L_4821
        mov      dword ptr [g_eventQueueEnd], 0xa
    L_47c6:
        mov      ecx, dword ptr [g_xformScratch2088]
        mov      edx, dword ptr [g_dispatchVar2_0053a24c]
        add      ecx, edx
        mov      dword ptr [g_walkCallback], ecx
        mov      dword ptr [g_dispatchVar2_0053a24c], ecx
        mov      ecx, 1
        mov      dword ptr [eax + 8], OFFSET L_4770
        mov      dword ptr [eax + 0x84], 2
        mov      dword ptr [g_pendingNodeType], ecx
        mov      dword ptr [g_framePauseFlag], ecx
        ret
    L_4803:
        mov      dword ptr [g_xformScratch2088], 0xa3d
        mov      dword ptr [g_eventQueueIdx], 8
    L_4817:
        mov      dword ptr [g_eventQueueEnd], 0xa
    L_4821:
        mov      ecx, dword ptr [g_dispatchVar2_0053a24c]
        mov      edx, dword ptr [g_xformScratch2088]
        sub      ecx, edx
        mov      dword ptr [g_walkCallback], ecx
        mov      dword ptr [g_dispatchVar2_0053a24c], ecx
        mov      ecx, 1
        mov      dword ptr [eax + 8], OFFSET L_4770
        mov      dword ptr [eax + 0x84], ecx
        mov      dword ptr [g_pendingNodeType], ecx
        mov      dword ptr [g_framePauseFlag], ecx
        ret
    }
}
