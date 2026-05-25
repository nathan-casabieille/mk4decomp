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

/* ------------------------------------------------------------------ */
/* Throw-init link cluster (815b game, 3 packed helpers):             */
/*  h1 (0x4555f0): main link/init chain - 4089e0+4b8fa0+407140 mstack */
/*    + 406600+408c10 + copy 3 angles + 4ab700 + d5324 timer.         */
/*  h2 (0x455730): pose-fn 2-state - state 0 init via 407330+4058c0+  */
/*    406340 + push 0x456510 helper-call + 48b740 + status 0x91/bit-flags */
/*    + event 004e7f28; state 1 install state 1 w/ 0x41 wait.         */
/*  h3 (0x4558f0): set wait=0x16 → tail-jmp RoundCleanupCluster_00455920.*/
/* ------------------------------------------------------------------ */
extern void MStackPushTwoEntryChainCall_004058c0(void);
extern void MStackCall_00406600(void);
extern void PushSetXfmMaskCallPop_00407140(void);
extern void MStackPushDispatchBitGate_00407330(void);
extern void RoundCleanupCluster_00455920(void);
extern void CharSelectFsmCluster_004561f0(void);
extern void ChainGatedNegAccum_0048b740(void);
extern unsigned int g_data_004e7f28;
extern unsigned int g_data_004e8158;
extern unsigned int g_data_0050d434;

extern unsigned int g_data_004d5324;
extern unsigned int g_particleEmitterNode_00535e6c;
extern void ArgSarStoreJmp_004594f0(void);
extern void AudioMixerStep_004ab700(void);
extern void DualScaledStore_00452740(void);
extern void MStackCall_00406340(void);
extern void StoreLoadJmp_00404ef0(void);
extern void Thunk_0049cbc0(void);

__declspec(naked) void ThrowInitLinkCluster_004555f0(void)
{
    __asm {
        /* === h1 (0x4555f0): main link/init chain === */
        call     MStackPush2RunCountdown_004089e0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_5721
        call     MStackBracket7_DispatchAndChain_004b8fa0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_5721
        mov      eax, OFFSET g_data_004e8158
        mov      ecx, dword ptr [g_fightGroupHead]
        shr      eax, 2
        mov      dword ptr [g_walkCallback], eax
        mov      eax, dword ptr [g_matrixStackTop]
        inc      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], ecx
        call     PushSetXfmMaskCallPop_00407140
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_5721
        mov      eax, dword ptr [g_matrixStackTop]
        mov      edx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      al, byte ptr [g_xformDirtyFlags]
        test     al, 4
        mov      dword ptr [g_fightGroupHead], edx
        jne      L_5721
        call     MStackCall_00406600
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_5721
        mov      dword ptr [g_walkCallback], 0xa
        call     ChainDirtyBitWalker_00408c10
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_5721
        mov      eax, dword ptr [g_xformEntityIdx]
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      eax, dword ptr [eax*4 + 0x3c]
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x54], eax
        mov      edx, dword ptr [g_xformEntityIdx]
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      eax, dword ptr [edx*4 + 0x40]
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x58], eax
        mov      edx, dword ptr [g_xformEntityIdx]
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      eax, dword ptr [edx*4 + 0x44]
        mov      dword ptr [ecx*4 + 0x5c], eax
        mov      edx, dword ptr [g_data_004d5324]
        mov      dword ptr [g_walkCallback], edx
        call     AudioMixerStep_004ab700
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_5721
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      eax, dword ptr [g_walkCallback]
        mov      dword ptr [ecx*4 + 0x68], eax
    L_5721:
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
        /* === h2 (0x455730): pose-fn 2-state w/ throw setup === */
    L_5730:
        mov      eax, dword ptr [g_baseSel_00542060]
        push     esi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        test     eax, eax
        je       L_58d0
        mov      ecx, OFFSET g_data_0050d434
        shr      ecx, 2
        mov      dword ptr [g_xformEntityIdx], ecx
        call     MStackPushDispatchBitGate_00407330
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_58ff
        test     byte ptr [g_xformDirtyFlags], 4
        je       short L_5786
        call     Thunk_0049cbc0
        pop      esi
        ret
    L_5786:
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [g_fightGroupHead], edx
        call     MStackPushTwoEntryChainCall_004058c0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_58ff
        call     MStackCall_00406340
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_58ff
        push     OFFSET CharSelectFsmCluster_004561f0 + 0x320
        call     StoreLoadJmp_00404ef0
        mov      eax, dword ptr [g_eventQueueIdx]
        add      esp, 4
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [g_acc_00542078], 0x16666
        mov      dword ptr [g_eventQueueNotMask], 0
        call     ChainGatedNegAccum_0048b740
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_58ff
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      edx, dword ptr [g_acc_00542078]
        push     OFFSET g_data_004e7f28
        mov      dword ptr [ecx*4 + 0x54], edx
        mov      eax, dword ptr [g_fightGroupHead]
        mov      ecx, dword ptr [g_eventQueueNotMask]
        mov      dword ptr [eax*4 + 0x5c], ecx
        mov      edx, dword ptr [g_fightGroupHead]
        mov      eax, 0x91
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [edx*4 + 0x30], eax
        mov      eax, dword ptr [g_eventQueueIdx]
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      eax, dword ptr [eax*4 + 0x48]
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x58], eax
        mov      edx, dword ptr [g_eventQueueIdx]
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      eax, dword ptr [edx*4 + 0x64]
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x64], eax
        mov      edx, dword ptr [g_eventQueueIdx]
        mov      ecx, dword ptr [edx*4 + 0x34]
        mov      edx, dword ptr [g_fightGroupHead]
        mov      dword ptr [g_eventQueueCurrent], ecx
        and      ecx, 1
        mov      eax, dword ptr [edx*4 + 0x34]
        mov      dword ptr [g_eventQueueCurrent], ecx
        and      al, 0xfe
        or       eax, ecx
        or       eax, 0x81000
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [edx*4 + 0x34], eax
        mov      eax, dword ptr [g_fightGroupHead]
        mov      ecx, dword ptr [g_particleEmitterNode_00535e6c]
        mov      dword ptr [eax*4 + 0x3c], ecx
        call     ArgSarStoreJmp_004594f0
        mov      eax, dword ptr [g_framePauseFlag]
        add      esp, 4
        pop      esi
        ret
    L_58d0:
        call     DualScaledStore_00452740
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_58ff
        mov      eax, 1
        mov      dword ptr [esi + 8], OFFSET L_5730
        mov      dword ptr [esi + 0x84], eax
        mov      dword ptr [g_pendingNodeType], 0x41
        mov      dword ptr [g_framePauseFlag], eax
    L_58ff:
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
        /* === h3 (0x4558f0): set wait=0x16 → tail-jmp 00455920 === */
        mov      dword ptr [g_eventQueueIdx], 0x16
        jmp      RoundCleanupCluster_00455920
    }
}
