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

extern unsigned int g_data_004f20c0;
extern unsigned int g_data_004f20f0;
extern unsigned int g_savedNode_00541f98;
extern void AiComboDispatcherCluster_00497470(void);
extern void ArgSarStoreJmp_004594f0(void);
extern void ArgSar_Set0_Jmp_0049c6f0(void);
extern void BootInstallPeriodicAudio_00413aa0(void);
extern void CmpDivJmp_0049d080(void);
extern void CondPickDualStore_0049c670(void);
extern void CopyThreeFields_00404df0(void);
extern void DualCmpSwapStore_0049c5a0(void);
extern void GuardedSeq_00497450(void);
extern void MStackPush8CallbackInit_00413b70(void);
extern void PushCallScaledClearJmp_0040bf20(void);
extern void ScaledIndirectJmp_0049c850(void);
extern void ScaledTripleCopy4_0049d2d0(void);
extern void SoundSetupLoop_00413ea0(void);
extern void TableLookupCall_00489ff0(void);
extern void ThreeChanPackClamp_00404cc0(void);
extern void Vec2SumMul10ChainCompute_0049bc60(void);

__declspec(naked) void SweepKickDispatcher_004970f0(void)
{
    __asm {
        /* === h1 (0x4970f0): event 004f20c0 forwarder === */
        mov      eax, dword ptr [g_baseSel_00542060]
        mov      ecx, dword ptr [g_walkCallback]
        mov      dword ptr [eax*4 + 0x74], ecx
        call     CondPickDualStore_0049c670
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_712b
        call     BootInstallPeriodicAudio_00413aa0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_712b
        push     OFFSET g_data_004f20c0
        call     ArgSarStoreJmp_004594f0
        add      esp, 4
    L_712b:
        ret
        nop
        nop
        nop
        nop
        /* === h2 (0x497130): main sweep-kick + 0049d2d0 + 004f20f0 === */
        push     esi
        push     edi
        call     DualCmpSwapStore_0049c5a0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_739c
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      edx, dword ptr [g_player1NodeIdx]
        mov      eax, dword ptr [g_gtPlayerProbe2]
        cmp      ecx, edx
        mov      dword ptr [g_currentNodeIdx], eax
        je       short L_7168
        mov      eax, dword ptr [g_gtPlayerProbe1]
        mov      dword ptr [g_currentNodeIdx], eax
    L_7168:
        mov      edx, dword ptr [eax*4 + 0x74]
        mov      dword ptr [g_eventQueueChild], edx
        call     AiComboDispatcherCluster_00497470
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_739c
        mov      ecx, dword ptr [g_eventQueueChild]
        mov      edx, 0x28f
        mov      eax, 0xffffe667
        cmp      ecx, 0x311
        mov      dword ptr [g_eventQueueCurrent], 0x189
        mov      dword ptr [g_eventQueueWorkType], edx
        mov      dword ptr [g_walkCallback], eax
        je       short L_71cc
        cmp      ecx, 0x311
        mov      dword ptr [g_eventQueueCurrent], edx
        je       short L_71cc
        mov      eax, 0xffffcccd
        mov      dword ptr [g_walkCallback], eax
    L_71cc:
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [ecx*4 + 0x70], eax
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      eax, dword ptr [g_eventQueueCurrent]
        mov      dword ptr [edx*4 + 0x4c], eax
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      dword ptr [g_pendingNodeType], eax
        mov      ecx, dword ptr [eax*4 + 0x18]
        mov      dword ptr [g_walkCallback], 1
        mov      dword ptr [g_currentNodeIdx], ecx
        call     CmpDivJmp_0049d080
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_739c
        test     byte ptr [g_xformDirtyFlags], 4
        jne      short L_729f
        mov      edx, dword ptr [g_pendingNodeType]
        mov      eax, dword ptr [g_savedNode_00541f98]
        mov      dword ptr [g_xformEntityIdx], eax
        lea      edi, [edx*4]
        lea      esi, [eax*4]
        mov      eax, dword ptr [edi + 0x6c]
        push     eax
        push     0xffff3334
        mov      dword ptr [g_walkCallback], eax
        call     Mul10Tail_00404af0
        mov      dword ptr [esi], eax
        mov      dword ptr [g_walkCallback], 0
        add      esp, 8
        mov      dword ptr [esi + 4], 0
        mov      edi, dword ptr [edi + 0x74]
        push     edi
        push     0xffff3334
        mov      dword ptr [g_walkCallback], edi
        call     Mul10Tail_00404af0
        add      esp, 8
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [esi + 8], eax
        call     ScaledTripleCopy4_0049d2d0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_739c
    L_729f:
        mov      eax, dword ptr [g_pendingNodeType]
        mov      eax, dword ptr [eax*4 + 0x18]
        mov      dword ptr [g_currentNodeIdx], eax
        mov      eax, dword ptr [eax*4 + 0x28]
        mov      dword ptr [g_currentNodeIdx], eax
        mov      ecx, dword ptr [eax*4]
        or       ecx, 8
        mov      dword ptr [eax*4], ecx
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      eax, 0xc000
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x48], eax
        mov      eax, dword ptr [g_pendingNodeType]
        mov      ecx, dword ptr [g_baseSel_00542060]
        mov      dword ptr [g_currentNodeIdx], eax
        lea      esi, [eax*4]
        mov      eax, dword ptr [ecx*4 + 0x5c]
        mov      dword ptr [g_currentNodeFlags], eax
        mov      edx, dword ptr [ecx*4 + 0x60]
        push     eax
        push     0x3333
        mov      dword ptr [g_xformScratch2088], edx
        call     Mul10Tail_00404af0
        add      esp, 8
        mov      dword ptr [g_currentNodeFlags], eax
        mov      eax, dword ptr [g_xformScratch2088]
        push     eax
        push     0x3333
        call     Mul10Tail_00404af0
        mov      ecx, dword ptr [g_currentNodeFlags]
        add      esp, 8
        mov      dword ptr [g_xformScratch2088], eax
        mov      dword ptr [esi + 0x6c], ecx
        mov      edx, dword ptr [g_xformScratch2088]
        push     0x8000
        mov      dword ptr [esi + 0x74], edx
        call     ThreeChanPackClamp_00404cc0
        mov      eax, dword ptr [g_fightGroupHead]
        add      esp, 4
        push     eax
        call     CopyThreeFields_00404df0
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      edx, dword ptr [g_baseSel_00542060]
        add      esp, 4
        mov      eax, 0x30
        mov      dword ptr [g_fightGroupHead], ecx
        mov      dword ptr [g_walkCallback], eax
        push     OFFSET g_data_004f20f0
        mov      dword ptr [edx*4 + 0x5c], eax
        call     ArgSar_Set0_Jmp_0049c6f0
        add      esp, 4
    L_739c:
        pop      edi
        pop      esi
        ret
        nop
        /* === h3 (0x4973a0): 413b70 + add + 49bc60 → tail 49c850 === */
        call     MStackPush8CallbackInit_00413b70
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_73f7
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      eax, dword ptr [ecx*4 + 0x4c]
        mov      dword ptr [g_eventQueueCurrent], eax
        mov      edx, dword ptr [ecx*4 + 0x70]
        add      eax, edx
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x70], eax
        call     Vec2SumMul10ChainCompute_0049bc60
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_73f7
        mov      eax, dword ptr [g_eventQueueCurrent]
        mov      ecx, dword ptr [g_eventQueueWorkType]
        cmp      eax, ecx
        jle      short L_73f7
        jmp      ScaledIndirectJmp_0049c850
    L_73f7:
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        /* === h4 (0x497400): 0x60/0x61 status + 0040bf20 → 497450 === */
        mov      eax, dword ptr [g_xformScratch2088]
        mov      dword ptr [g_walkCallback], 0x60
        cmp      eax, 1
        jne      short L_741e
        mov      dword ptr [g_walkCallback], 0x61
    L_741e:
        call     TableLookupCall_00489ff0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_744d
        call     PushCallScaledClearJmp_0040bf20
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_744d
        call     SoundSetupLoop_00413ea0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_744d
        jmp      GuardedSeq_00497450
    L_744d:
        ret
    }
}
