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

extern unsigned int g_phaseThunkVar2;
extern unsigned int g_tickFlagF;
extern unsigned int g_eventMusicSlot2;
extern unsigned int g_eventMusicVar;
extern unsigned int g_dispatchVar3;
extern unsigned int g_eventMusicSlot;
extern unsigned int g_dispatchTab61;
extern unsigned int g_dispatchSave1705;
extern void CallSetPause(void);
extern void Cmp7DirtyToggle(void);
extern void DispatcherComplex181_StreamChainStringInstall(void);
extern void GuardedDualMaskFlagToggle(void);
extern void RoundCleanupCluster_Ten404c40_404bd0(void);
extern void SaveCallRestore(void);
extern void SetWalkCurCallPauseDirty(void);
extern void StoreIncrMStackPush6(void);

__declspec(naked) void Event23bMusicCluster(void)
{
    __asm {
        /* === Main: event 0x23b dispatch === */
        push     ebx
        push     0x23b
        call     SaveCallRestore
        mov      eax, dword ptr [g_active_0053a408]
        mov      edx, dword ptr [g_eventMusicSlot2]
        mov      ecx, dword ptr [g_active_00537e88]
        add      esp, 4
        cmp      eax, 1
        jne      short L_f57b
        test     ecx, ecx
        jne      short L_f57b
        cmp      edx, 2
        jne      short L_f57b
        mov      ebx, dword ptr [g_eventMusicSlot]
        test     ebx, ebx
        jl       L_f691
    L_f57b:
        test     eax, eax
        jne      short L_f599
        cmp      ecx, 1
        jne      short L_f599
        cmp      edx, ecx
        jne      short L_f612
        mov      eax, dword ptr [g_dispatchVar3]
        test     eax, eax
        jl       L_f691
    L_f599:
        cmp      edx, 1
        jne      short L_f612
        mov      eax, dword ptr [g_phaseThunkVar2]
        mov      dword ptr [g_walkCallback], eax
        call     StoreIncrMStackPush6
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_f691
        mov      dword ptr [g_eventQueueCurrent], 4
        mov      dword ptr [g_eventQueueWorkType], 0x23b
        mov      dword ptr [g_acc_00542078], OFFSET g_dispatchTab61
        mov      dword ptr [g_eventQueueNotMask], OFFSET g_dispatchSave1705
        mov      dword ptr [g_currentNodeFlags], 1
        call     DispatcherComplex181_StreamChainStringInstall
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_f691
        call     RoundCleanupCluster_Ten404c40_404bd0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_f691
        jmp      short L_f67a
    L_f612:
        mov      edx, dword ptr [g_phaseThunkVar2]
        mov      dword ptr [g_walkCallback], edx
        call     StoreIncrMStackPush6
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_f691
        mov      dword ptr [g_eventQueueCurrent], 4
        mov      dword ptr [g_eventQueueWorkType], 0x23b
        mov      dword ptr [g_acc_00542078], 0xff920000
        mov      dword ptr [g_eventQueueNotMask], OFFSET g_dispatchSave1705
        mov      dword ptr [g_currentNodeFlags], 1
        call     DispatcherComplex181_StreamChainStringInstall
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_f691
        call     RoundCleanupCluster_Ten404c40_404bd0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_f691
    L_f67a:
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      eax, 0x14000
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x5c], eax
    L_f691:
        pop      ebx
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
        /* === Helper 2 (0x42f6a0): event 0x225 tail === */
        call     Cmp7DirtyToggle
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_f6ce
        test     byte ptr [g_xformDirtyFlags], 1
        je       short L_f6c9
        push     0x225
        push     OFFSET L_f6d0
        call     SetWalkCurCallPauseDirty
        add      esp, 8
    L_f6c9:
        jmp      CallSetPause
    L_f6ce:
        ret
        nop
        /* === Helper 3 (0x42f6d0): callback handler === */
    L_f6d0:
        mov      eax, dword ptr [g_baseSel]
        push     ebx
        push     esi
        mov      ebx, 1
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        test     eax, eax
        je       short L_f733
        mov      eax, dword ptr [g_tickFlagF]
        cmp      eax, 7
        mov      dword ptr [g_walkCallback], eax
        jne      short L_f72b
        mov      eax, dword ptr [g_phaseThunkVar2]
        test     eax, eax
        mov      dword ptr [g_walkCallback], eax
        je       short L_f72b
        call     GuardedDualMaskFlagToggle
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_f75c
        test     byte ptr [g_xformDirtyFlags], bl
        jne      short L_f733
    L_f72b:
        call     CallSetPause
        pop      esi
        pop      ebx
        ret
    L_f733:
        mov      dword ptr [g_walkCallback], ebx
        mov      dword ptr [g_eventMusicVar], ebx
        mov      dword ptr [esi + 8], OFFSET L_f6d0
        mov      dword ptr [esi + 0x84], ebx
        mov      dword ptr [g_pendingNodeType], 0xa
        mov      dword ptr [g_framePauseFlag], ebx
    L_f75c:
        pop      esi
        pop      ebx
        ret
    }
}
