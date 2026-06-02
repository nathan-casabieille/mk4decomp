/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;
extern unsigned int g_baseSel;
extern unsigned int g_acc_00542078;
extern unsigned int g_cj_0054205c;
extern unsigned int g_gameCountdown;
extern unsigned int g_xformScratch94;
extern unsigned int g_table_00535ddc;
extern unsigned int g_active_00537e88;
extern unsigned int g_active_0053a408;
extern unsigned int g_audioBankSel;

extern void StoreTwoCall(int, int);
extern void SetJmp_0049cb90(void);
extern void Thunk_0049cbd0(void);
extern void ScaledZeroFour(void);
extern void WalkCbSubMul10_00431d50(void);
extern void Mul10Tail(unsigned int a, unsigned int b);
extern void BootMod6487eClampAndChainMul10(void);
extern void SpawnListBatchLoader_00477710(void);
extern void MStackPush2TableNot(void);
extern void GuardedChainCmpDualBitXor(void);
extern void ScaledLoadDecJmp_00429710(void);
extern void ScaledStoreCurDirtyClear_004296f0(void);
extern void MStackBitmaskIncMod_00492450(void);
extern void MStackBitmaskUpdate_00492510(void);
extern void Push1eCallTestDirtyLoop_004923b0(void);
extern void MStackLoopFieldInit_00492280(void);
extern void TaggedSceneDispatch(void);
extern void CallPauseDirty4StackPushFn_004839d0(void);
extern void CallPauseDirty1JmpDirty4StackPush_00483a80(void);
extern void Cmp2CallDirtyCall(void);
extern void QuadBlockArgInstallChain(void);
extern void InstallSelfChainSet84_80CallW_004363f0(void);
extern void Wrapper_00436490(void);
extern void MoveFsmCluster_004364a0(void);
extern void CallPauseTestByteJmpCalls(void);
extern void InstallSelfFullPath(void);
extern void InstallSelfCountdownChain_0047a950(void);
extern void CopyJmp_0048ef90(void);
extern void DualTestDirtyToggle_004282c0(void);
extern void TripleVecAccCallStore(void);
extern void Thunk_004bd5c0(void);
extern void AllocSlotPushTripleGlobals(void);
extern void MStackPop4Rewrite(void);
extern void Push70CallScaleArith(void);
extern void StreamChainStringInstall(void);
extern void MStackFrameCdeclDouble(void);
extern void ChainTableWalkStore_004917e0(void);
extern void Push16Call(void);
extern void DispatcherComplex260_00407030(void);
extern void ScaledLoadCmpStoreXfm_0048f2a0(void);
extern void StackPopDispatchTagged(void);
extern unsigned int g_cj_00542058;
extern unsigned int g_rangeSqLimit;
extern unsigned int g_zero_00541fa4;
extern unsigned int g_zero_00541fa8;
extern unsigned int g_dualBitGate;
extern unsigned int g_eventArmReload;
extern unsigned int g_rangeBase;

extern void ScaledArrStore_004298c0(void);
extern void DualFieldAddSubStore(void);
extern void IterStepDualStore(int);
extern void ScaledXorStore_004900f0(void);
extern void ChainWalkInstall(void);
extern void FpuSqrtMul(void);
extern void PendingMatch_0042b930(void);
extern void MStackPush2RunCountdown(void);
extern void MStackBracket7_DispatchAndChain(void);
extern void MStackBracketed3StoreCall(void);
extern void ChainDirtyBitWalker(void);
extern void Wrapper_0048a350(void);
extern void Wrapper_0048a3a0(void);
extern void Helper_DownloadSetup(void);
extern void MStackPush3CmpCall(void);
extern void Wrapper_0048ec20(void);
extern void FiveCallScaledChainTailJmp(void);
extern void SetJmp_00438f50(void);
extern void SetJmp_00438f60(void);
extern void GuardedDispatch_0042b6c0(void);
extern void MStackPushZeroCallPop_00407d00(void);
extern void DirtyToggleByGate(void);
extern void GameDispatchValidateState(void);
extern void CrouchAttackFsmCluster(void);
extern void MStackPushVec3Mul10(void);
extern void LiteralPushCallEntZero(void);
extern void LeaPlus22StoreSelf(void);
extern void IterLoad_00491050(void);
extern void GuardedDualConst2AndToggle(void);
extern void CallPauseScaledStorePushCall(void);
extern void LoadGeoAsset_Default(void);
extern void DispatcherComplex260_00407400(void);
extern void PushSetCallPop(void);
extern unsigned int g_stateCountdown;
extern unsigned int g_installOwnerNode;
extern unsigned int g_cj_00542054;
extern unsigned int g_audioBoundNode;
extern unsigned int g_lastGatedValue;
extern unsigned int g_lastGatedTick;
extern unsigned int g_fightAxisNegX;
extern unsigned int g_fightAxisNegY;
extern unsigned int g_fightAxisPosX;
extern unsigned int g_fightAxisPosY;

/* ------------------------------------------------------------------ */
/* Skeleton-anim updater V2 cluster (673b game, 2 packed helpers)      */
/* Cousin of SkelAnimUpdaterCluster_0049d940 - uses [g_eventQueueChild] instead of         */
/* [g_eventQueueTotal+8] for the segment-count.                          */
/* ------------------------------------------------------------------ */
extern unsigned int g_particleEmitterNode;
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
        mov      eax, dword ptr [g_particleEmitterNode]
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
        mov      eax, dword ptr [g_matrixStackTop]
        mov      ecx, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], ecx
        mov      edx, dword ptr [g_eventQueueTotal]
        add      edx, 3
        mov      dword ptr [g_xformEntityIdx], edx
        call     LinkedListFieldAdd_0049d380
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_ddcb
        mov      eax, dword ptr [g_matrixStackTop]
        mov      edx, dword ptr [g_eventQueueTotal]
        mov      ecx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      dword ptr [g_matrixStackTop], eax
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
        mov      eax, dword ptr [g_baseSel]
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
