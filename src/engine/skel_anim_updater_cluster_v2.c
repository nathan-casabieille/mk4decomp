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
extern unsigned int g_audioBankSel_00537f94;
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
extern unsigned int g_rangeSqLimit_0053a180;
extern unsigned int g_zero_00541fa4;
extern unsigned int g_zero_00541fa8;
extern unsigned int g_dualBitGate_0053a7b0;
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
extern unsigned int g_stateCountdown_0053a3c0;
extern unsigned int g_player1NodeIdx;
extern unsigned int g_installOwnerNode_00535cf8;
extern unsigned int g_cj_00542054;
extern unsigned int g_audioBoundNode_005437f0;
extern unsigned int g_data_00543598;
extern unsigned int g_data_0054358c;
extern unsigned int g_fightAxisNegX_00535e70;
extern unsigned int g_fightAxisNegY_00535e74;
extern unsigned int g_fightAxisPosX_00535e78;
extern unsigned int g_fightAxisPosY_00535e7c;

/* ------------------------------------------------------------------ */
/* Skeleton-anim updater V2 cluster (673b game, 2 packed helpers)      */
/* Cousin of SkelAnimUpdaterCluster_0049d940 - uses [g_eventQueueChild] instead of         */
/* [g_eventQueueTotal+8] for the segment-count.                          */
/* ------------------------------------------------------------------ */
extern unsigned int g_data_004d57ac;
extern unsigned int g_data_00535e6c;
extern unsigned int g_framePauseFlag;
extern unsigned int g_currentNodeIdx;
extern unsigned int g_xformEntityIdx;
extern unsigned int g_pendingNodeType;
extern unsigned int g_eventQueueIdx;
extern unsigned int g_fightGroupHead;
extern unsigned int g_baseSel_00542060;
extern unsigned int g_eventQueueWorkType;
extern unsigned int g_eventQueueNotMask;
extern unsigned int g_eventQueueChild;
extern unsigned int g_xformDirtyFlags;
extern void CmpDivJmp_0049d080(void);
extern void LinkedListFieldAdd_0049d380(void);
extern void MStackCall_00406340(void);
extern void MStackCall_00406740(void);
extern void MStackPop8_004ab860(void);
extern void MStackPush8_004ab790(void);
extern void PoseTreeBlendWalker_0049d680(void);
extern void PushSetXfmMaskCallPop_00407140(void);
extern void SetJmp_00405420(void);
extern void SixCrossStores_0049d8e0(void);
extern void Thunk_0049cbb0(void);

__declspec(naked) void SkelAnimUpdaterClusterV2_0049dbf0(void)
{
    __asm {
        /* === Helper 1 (0x49dbf0): per-bone update (alt counter) === */
    L_dbf0:
        call     MStackPush8_004ab790
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_ddcb
        mov      eax, dword ptr [g_xformEntityIdx]
        mov      dword ptr [g_eventQueueTotal], eax
        mov      eax, dword ptr [eax*4]
        mov      dword ptr [g_walkCallback], eax
        call     PushSetXfmMaskCallPop_00407140
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_ddcb
        test     byte ptr [g_xformDirtyFlags], 4
        jne      L_ddda
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      edx, dword ptr [g_eventQueueNotMask]
        mov      dword ptr [ecx*4 + 0x30], edx
        call     SixCrossStores_0049d8e0
        mov      eax, dword ptr [g_data_00535e6c]
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x3c], eax
        mov      edx, dword ptr [g_eventQueueTotal]
        mov      ecx, dword ptr [g_eventQueueNotMask]
        mov      eax, dword ptr [edx*4 + 4]
        mov      dword ptr [g_eventQueueWorkType], ecx
        mov      dword ptr [g_pendingNodeType], eax
        call     AllocNode
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_ddcb
        test     byte ptr [g_xformDirtyFlags], 1
        jne      L_ddcc
        mov      edx, dword ptr [g_fightGroupHead]
        mov      dword ptr [g_currentNodeIdx], edx
        call     MStackCall_00406340
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_ddcb
        mov      eax, dword ptr [g_fightGroupHead]
        mov      ecx, dword ptr [eax*4 + 0x18]
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      eax, dword ptr [ecx*4 + 0x20]
        or       ah, 0x40
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x20], eax
        mov      ecx, dword ptr [g_eventQueueChild]
        cmp      ecx, 3
        mov      dword ptr [g_eventQueueCurrent], ecx
        jl       short L_dd0e
        mov      eax, 0x55555556
        imul     ecx
        mov      ecx, edx
        shr      ecx, 0x1f
        add      edx, ecx
        mov      dword ptr [g_eventQueueCurrent], edx
    L_dd0e:
        call     SetJmp_00405420
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_ddcb
        test     byte ptr [g_xformDirtyFlags], 4
        jne      short L_dd3b
        mov      edx, dword ptr [g_eventQueueCurrent]
        lea      eax, [edx + 1]
        shr      eax, 1
        mov      dword ptr [g_eventQueueCurrent], eax
        jmp      short L_dd40
    L_dd3b:
        mov      eax, dword ptr [g_eventQueueCurrent]
    L_dd40:
        test     eax, eax
        mov      dword ptr [g_walkCallback], eax
        je       short L_ddda
        call     CmpDivJmp_0049d080
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_ddcb
        test     byte ptr [g_xformDirtyFlags], 4
        jne      short L_ddda
        mov      eax, dword ptr [g_data_004d57ac]
        mov      ecx, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_data_004d57ac], eax
        mov      dword ptr [eax*4], ecx
        mov      edx, dword ptr [g_eventQueueTotal]
        add      edx, 3
        mov      dword ptr [g_xformEntityIdx], edx
        call     LinkedListFieldAdd_0049d380
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_ddcb
        mov      eax, dword ptr [g_data_004d57ac]
        mov      edx, dword ptr [g_eventQueueTotal]
        mov      ecx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      dword ptr [g_data_004d57ac], eax
        mov      dword ptr [g_xformEntityIdx], edx
        call     PoseTreeBlendWalker_0049d680
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        je       short L_ddda
    L_ddcb:
        ret
    L_ddcc:
        call     MStackCall_00406740
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_ddcb
    L_ddda:
        mov      eax, dword ptr [g_eventQueueTotal]
        mov      dword ptr [g_xformEntityIdx], eax
        jmp      MStackPop8_004ab860
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        /* === Helper 2 (0x49ddf0): bone-list walker === */
    L_ddf0:
        push     ecx
        mov      eax, dword ptr [g_baseSel_00542060]
        push     esi
        push     edi
        mov      edi, OFFSET L_ddf0
        mov      ecx, dword ptr [eax*4 + 0x84]
        lea      esi, [eax*4]
        mov      dword ptr [esp + 8], ecx
        mov      dword ptr [esi + 0x84], 0
    L_de19:
        mov      ecx, dword ptr [g_eventQueueIdx]
        mov      eax, dword ptr [ecx*4]
        inc      ecx
        test     eax, eax
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [g_eventQueueIdx], ecx
        je       short L_de71
        mov      ecx, eax
        sar      ecx, 0x18
        and      eax, 0xffffff
        mov      dword ptr [g_eventQueueCurrent], ecx
        mov      dword ptr [g_xformEntityIdx], eax
        mov      dword ptr [g_pendingNodeType], ecx
        mov      dword ptr [g_walkCallback], eax
        je       short L_de66
        call     L_dbf0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_de8d
    L_de66:
        mov      eax, dword ptr [g_pendingNodeType]
        test     eax, eax
        jne      short L_de7a
        jmp      short L_de19
    L_de71:
        call     Thunk_0049cbb0
        pop      edi
        pop      esi
        pop      ecx
        ret
    L_de7a:
        mov      eax, 1
        mov      dword ptr [esi + 8], edi
        mov      dword ptr [esi + 0x84], eax
        mov      dword ptr [g_framePauseFlag], eax
    L_de8d:
        pop      edi
        pop      esi
        pop      ecx
        ret
    }
}
