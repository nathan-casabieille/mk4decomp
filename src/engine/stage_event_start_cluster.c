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
extern unsigned int g_installOwnerNode_00535cf8;
extern unsigned int g_cj_00542054;
extern unsigned int g_data_005437f0;
extern unsigned int g_data_00543598;
extern unsigned int g_data_0054358c;
extern unsigned int g_fightAxisNegX_00535e70;
extern unsigned int g_fightAxisNegY_00535e74;
extern unsigned int g_fightAxisPosX_00535e78;
extern unsigned int g_fightAxisPosY_00535e7c;

extern unsigned int g_data_004d57ac;
extern unsigned int g_data_004ed800;
extern unsigned int g_data_00535d04;
extern unsigned int g_table_00535ddc;
extern unsigned int g_player1NodeIdx;
extern unsigned int g_data_0053a774;
extern unsigned int g_framePauseFlag;
extern unsigned int g_currentNodeIdx;
extern unsigned int g_xformEntityIdx;
extern unsigned int g_fightGroupHead;
extern unsigned int g_baseSel_00542060;
extern void ArgSarStoreJmp_004594f0(void);
extern void DualCallPauseDirtyJmp_00490c30(void);
extern void DualSetCallPair_0047dbc0(void);
extern void FiveCallGuardSetTail_0046f6b0(void);
extern void GuardedSeq_004297b0(void);
extern void InstallSelfCmpJmpIndirect_0048f470(void);
extern void InstallSelfIndirectJmpNeg_0048f4f0(void);
extern void MStackSignedMod_0042fee0(void);
extern void PushPlayerSwapCallClamp_004801a0(void);
extern void SlotEvent3EntryChain_0046fdf0(void);
extern void ZeroSixStores6080_00490e40(void);
extern void ZeroThreeSlots_00490780(void);

__declspec(naked) void StageEventStartCluster_0047ff80(void)
{
    __asm {
        /* H1 */
        call     DualSetCallPair_0047dbc0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_ffa9
        mov      eax, dword ptr [g_data_004d57ac]
        inc      eax
        mov      dword ptr [g_data_004d57ac], eax
        mov      dword ptr [eax*4], OFFSET L_ffb0
        jmp      InstallSelfIndirectJmpNeg_0048f4f0
    L_ffa9:
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        /* H2 (L_ffb0) */
    L_ffb0:
        mov      eax, dword ptr [g_data_004d57ac]
        mov      dword ptr [g_currentNodeFlags], 0xfffd8000
        inc      eax
        mov      dword ptr [g_data_004d57ac], eax
        mov      dword ptr [eax*4], OFFSET L_ffe0
        jmp      InstallSelfCmpJmpIndirect_0048f470
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
        /* H3 (L_ffe0) */
    L_ffe0:
        call     ZeroThreeSlots_00490780
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_0017
        call     ZeroSixStores6080_00490e40
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_0017
        call     DualCallPauseDirtyJmp_00490c30
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_0017
        push     OFFSET g_data_004ed800
        call     ArgSarStoreJmp_004594f0
        add      esp, 4
    L_0017:
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        /* H4 (L_480020) */
    L_480020:
        mov      eax, dword ptr [g_baseSel_00542060]
        xor      edx, edx
        shl      eax, 2
        mov      ecx, dword ptr [eax + 0x84]
        mov      dword ptr [eax + 0x84], edx
        cmp      ecx, edx
        je       short L_003f
        jmp      FiveCallGuardSetTail_0046f6b0
    L_003f:
        mov      dword ptr [eax + 8], OFFSET L_480020
        mov      ecx, dword ptr [g_baseSel_00542060]
        push     edi
        mov      edi, OFFSET L_480020
        mov      dword ptr [ecx*4 + 0x84], 1
        mov      ecx, dword ptr [eax + 4]
        add      edi, 0x1000000
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      dword ptr [ecx*4], edi
        mov      ecx, dword ptr [g_currentNodeIdx]
        inc      ecx
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      dword ptr [eax + 4], ecx
        mov      eax, dword ptr [g_baseSel_00542060]
        mov      dword ptr [eax*4 + 0x84], edx
        call     SlotEvent3EntryChain_0046fdf0
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        ret
        /* H5 */
        mov      eax, dword ptr [g_fightGroupHead]
        push     esi
        mov      dword ptr [g_currentNodeIdx], eax
        call     MStackSignedMod_0042fee0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_019a
        cmp      dword ptr [g_walkCallback], 0x5999
        jle      short L_00d0
        call     PushPlayerSwapCallClamp_004801a0
        pop      esi
        ret
    L_00d0:
        mov      edx, dword ptr [g_fightGroupHead]
        mov      esi, dword ptr [g_player1NodeIdx]
        mov      eax, OFFSET g_data_0053a774
        mov      ecx, OFFSET g_data_00535d04
        shr      eax, 2
        shr      ecx, 2
        cmp      edx, esi
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [g_xformEntityIdx], ecx
        je       short L_0102
        mov      eax, ecx
        mov      dword ptr [g_currentNodeIdx], eax
    L_0102:
        mov      ecx, dword ptr [g_data_0053a180]
        mov      eax, dword ptr [eax*4]
        add      ecx, 0xfffb0000
        mov      dword ptr [g_walkCallback], eax
        cmp      eax, ecx
        mov      dword ptr [g_eventQueueCurrent], ecx
        jle      short L_012b
        call     PushPlayerSwapCallClamp_004801a0
        pop      esi
        ret
    L_012b:
        mov      eax, dword ptr [g_table_00535ddc]
        mov      dword ptr [g_eventQueueCurrent], 0x5e667
        cmp      eax, 0x5e667
        mov      dword ptr [g_walkCallback], eax
        jl       short L_014d
        call     PushPlayerSwapCallClamp_004801a0
        pop      esi
        ret
    L_014d:
        mov      eax, dword ptr [edx*4 + 0x6c]
        mov      dword ptr [g_walkCallback], eax
        mov      ecx, dword ptr [edx*4 + 0x74]
        add      ecx, eax
        mov      dword ptr [g_eventQueueCurrent], ecx
        jne      short L_0171
        call     PushPlayerSwapCallClamp_004801a0
        pop      esi
        ret
    L_0171:
        mov      eax, dword ptr [edx*4 + 0x24]
        mov      dword ptr [g_currentNodeIdx], eax
        mov      edx, dword ptr [edx*4 + 0x28]
        mov      dword ptr [g_walkCallback], edx
        mov      ecx, dword ptr [eax*4 + 4]
        cmp      edx, ecx
        jg       short L_019a
        call     GuardedSeq_004297b0
    L_019a:
        pop      esi
        ret
    }
}
