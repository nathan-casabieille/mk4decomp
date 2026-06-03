/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_currentNodeIdx;
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
extern void SetJmp_Thunk_LinkedListBitMaskSearch(void);
extern void Thunk_ChainNodeInit(void);
extern void ScaledZeroFour(void);
extern void WalkCbSubMul10(void);
extern void Mul10Tail(unsigned int a, unsigned int b);
extern void BootMod6487eClampAndChainMul10(void);
extern void SpawnListBatchLoader(void);
extern void MStackPush2TableNot(void);
extern void GuardedChainCmpDualBitXor(void);
extern void ScaledLoadDecJmp(void);
extern void ScaledStoreCurDirtyClear(void);
extern void MStackBitmaskIncMod(void);
extern void MStackBitmaskUpdate(void);
extern void Push1eCallTestDirtyLoop(void);
extern void MStackLoopFieldInit(void);
extern void TaggedSceneDispatch(void);
extern void CallPauseDirty4StackPushFn(void);
extern void CallPauseDirty1JmpDirty4StackPush_GuardedDoubleIncCmpJmp(void);
extern void Cmp2CallDirtyCall(void);
extern void QuadBlockArgInstallChain(void);
extern void InstallSelfChainSet84_80CallW(void);
extern void Wrapper_PackedAdvanceCallTailJmp_004e46d0(void);
extern void MoveFsmCluster(void);
extern void CallPauseTestByteJmpCalls(void);
extern void InstallSelfFullPath(void);
extern void InstallSelfCountdownChain(void);
extern void CopyJmp_SlotCmp3way_g_currentNodeIdx(void);
extern void DualTestDirtyToggle_004282c0(void);
extern void TripleVecAccCallStore(void);
extern void Thunk_LoadGeoAsset_Default(void);
extern void AllocSlotPushTripleGlobals(void);
extern void MStackPop4Rewrite(void);
extern void Push70CallScaleArith(void);
extern void StreamChainStringInstall(void);
extern void MStackFrameCdeclDouble(void);
extern void ChainTableWalkStore(void);
extern void Push16Call(void);
extern void DispatcherComplex260_MStackBracket1_TreeWalkRecursive2(void);
extern void ScaledLoadCmpStoreXfm(void);
extern void StackPopDispatchTagged(void);
extern unsigned int g_cj_00542058;
extern unsigned int g_rangeSqLimit;
extern unsigned int g_zero_00541fa4;
extern unsigned int g_zero_00541fa8;
extern unsigned int g_dualBitGate;
extern unsigned int g_eventArmReload;
extern unsigned int g_rangeBase;

extern void ScaledArrStore_ScaledChainJmp_004298c0(void);
extern void DualFieldAddSubStore(void);
extern void IterStepDualStore(int);
extern void ScaledXorStore_004900f0(void);
extern void ChainWalkInstall(void);
extern void FpuSqrtMul(void);
extern void PendingMatch_StoreTwoCall_0042b930(void);
extern void MStackPush2RunCountdown(void);
extern void MStackBracket7_DispatchAndChain(void);
extern void MStackBracketed3StoreCall(void);
extern void ChainDirtyBitWalker(void);
extern void Wrapper_ScaledChainPushCall_004ef858(void);
extern void Wrapper_ScaledChainPushCall_004ef8b0(void);
extern void Helper_DownloadSetup(void);
extern void MStackPush3CmpCall(void);
extern void Wrapper_IterLoad_0048fd30_004f12a0(void);
extern void FiveCallScaledChainTailJmp(void);
extern void SetJmp_StateDispatchYield_00438f50(void);
extern void SetJmp_StateDispatchYield_00438f60(void);
extern void GuardedDispatch_InstallSelfDualEsi(void);
extern void MStackPushZeroCallPop_PendingMatch(void);
extern void DirtyToggleByGate(void);
extern void GameDispatchValidateState(void);
extern void CrouchAttackFsmCluster(void);
extern void MStackPushVec3Mul10(void);
extern void LiteralPushCallEntZero(void);
extern void LeaPlus22StoreSelf(void);
extern void IterLoad_g_scaledInit_00542048_then_DualScaledStoreZero(void);
extern void GuardedDualConst2AndToggle(void);
extern void CallPauseScaledStorePushCall(void);
extern void LoadGeoAsset_Default(void);
extern void DispatcherComplex260_FramePauseScaledStore(void);
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
/* Cousin of SkelAnimUpdaterCluster - uses [g_eventQueueChild] instead of         */
/* [g_eventQueueTotal+8] for the segment-count.                          */
/* ------------------------------------------------------------------ */
extern unsigned int g_particleEmitterNode;
extern void CmpDivJmp(void);
extern void LinkedListFieldAdd_StoreDoubleNegPauseSubStore(void);
extern void MStackCall_MStackPush2ChainPrepend_00406340(void);
extern void MStackCall_MStackPush2ChainLLInsert(void);
extern void MStackPop8(void);
extern void MStackPush8(void);
extern void PoseTreeBlendWalker(void);
extern void PushSetXfmMaskCallPop(void);
extern void SetJmp_ZeroAndDirty4(void);
extern void SixCrossStores(void);
extern void Thunk_Thunk_0049cbc0_0049cbb0(void);

__declspec(naked) void SkelAnimUpdaterClusterV2(void)
{
    __asm {
        /* === Helper 1 (0x49dbf0): per-bone update (alt counter) === */
    L_dbf0:
        call     MStackPush8
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_ddcb
        mov      eax, dword ptr [g_xformEntityIdx]
        mov      dword ptr [g_eventQueueTotal], eax
        mov      eax, dword ptr [eax*4]
        mov      dword ptr [g_walkCallback], eax
        call     PushSetXfmMaskCallPop
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_ddcb
        test     byte ptr [g_xformDirtyFlags], 4
        jne      L_ddda
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      edx, dword ptr [g_eventQueueNotMask]
        mov      dword ptr [ecx*4 + 0x30], edx
        call     SixCrossStores
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
        call     MStackCall_MStackPush2ChainPrepend_00406340
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
        call     SetJmp_ZeroAndDirty4
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
        call     CmpDivJmp
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
        call     LinkedListFieldAdd_StoreDoubleNegPauseSubStore
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
        call     PoseTreeBlendWalker
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        je       short L_ddda
    L_ddcb:
        ret
    L_ddcc:
        call     MStackCall_MStackPush2ChainLLInsert
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_ddcb
    L_ddda:
        mov      eax, dword ptr [g_eventQueueTotal]
        mov      dword ptr [g_xformEntityIdx], eax
        jmp      MStackPop8
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
        call     Thunk_Thunk_0049cbc0_0049cbb0
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
