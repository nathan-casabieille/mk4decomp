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
extern void CallPauseDirty1JmpDirty4StackPush_00483a80(void);
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
extern void DispatcherComplex260_00407030(void);
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
extern void PendingMatch_0042b930(void);
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

extern unsigned int g_dispatchSave596;
extern unsigned int g_secondary_00535d04;
extern unsigned int g_primary_0053a774;
extern void ArgSarStoreJmp(void);
extern void DualCallPauseDirtyJmp_00490c30(void);
extern void DualSetCallPair(void);
extern void FiveCallGuardSetTail(void);
extern void GuardedSeq_GuardedChainCmpDualBitXor_then_ScaledIncCmpJmp(void);
extern void InstallSelfCmpJmpIndirect(void);
extern void InstallSelfIndirectJmpNeg(void);
extern void MStackSignedMod(void);
extern void PushPlayerSwapCallClamp(void);
extern void SlotEvent3EntryChain(void);
extern void ZeroSixStores6080(void);
extern void ZeroThreeSlots_00490780(void);

__declspec(naked) void StageEventStartCluster(void)
{
    __asm {
        /* H1 */
        call     DualSetCallPair
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_ffa9
        mov      eax, dword ptr [g_matrixStackTop]
        inc      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], OFFSET L_ffb0
        jmp      InstallSelfIndirectJmpNeg
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
        mov      eax, dword ptr [g_matrixStackTop]
        mov      dword ptr [g_currentNodeFlags], 0xfffd8000
        inc      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], OFFSET L_ffe0
        jmp      InstallSelfCmpJmpIndirect
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
        call     ZeroSixStores6080
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_0017
        call     DualCallPauseDirtyJmp_00490c30
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_0017
        push     OFFSET g_dispatchSave596
        call     ArgSarStoreJmp
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
        mov      eax, dword ptr [g_baseSel]
        xor      edx, edx
        shl      eax, 2
        mov      ecx, dword ptr [eax + 0x84]
        mov      dword ptr [eax + 0x84], edx
        cmp      ecx, edx
        je       short L_003f
        jmp      FiveCallGuardSetTail
    L_003f:
        mov      dword ptr [eax + 8], OFFSET L_480020
        mov      ecx, dword ptr [g_baseSel]
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
        mov      eax, dword ptr [g_baseSel]
        mov      dword ptr [eax*4 + 0x84], edx
        call     SlotEvent3EntryChain
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        ret
        /* H5 */
        mov      eax, dword ptr [g_fightGroupHead]
        push     esi
        mov      dword ptr [g_currentNodeIdx], eax
        call     MStackSignedMod
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_019a
        cmp      dword ptr [g_walkCallback], 0x5999
        jle      short L_00d0
        call     PushPlayerSwapCallClamp
        pop      esi
        ret
    L_00d0:
        mov      edx, dword ptr [g_fightGroupHead]
        mov      esi, dword ptr [g_player1NodeIdx]
        mov      eax, OFFSET g_primary_0053a774
        mov      ecx, OFFSET g_secondary_00535d04
        shr      eax, 2
        shr      ecx, 2
        cmp      edx, esi
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [g_xformEntityIdx], ecx
        je       short L_0102
        mov      eax, ecx
        mov      dword ptr [g_currentNodeIdx], eax
    L_0102:
        mov      ecx, dword ptr [g_rangeSqLimit]
        mov      eax, dword ptr [eax*4]
        add      ecx, 0xfffb0000
        mov      dword ptr [g_walkCallback], eax
        cmp      eax, ecx
        mov      dword ptr [g_eventQueueCurrent], ecx
        jle      short L_012b
        call     PushPlayerSwapCallClamp
        pop      esi
        ret
    L_012b:
        mov      eax, dword ptr [g_table_00535ddc]
        mov      dword ptr [g_eventQueueCurrent], 0x5e667
        cmp      eax, 0x5e667
        mov      dword ptr [g_walkCallback], eax
        jl       short L_014d
        call     PushPlayerSwapCallClamp
        pop      esi
        ret
    L_014d:
        mov      eax, dword ptr [edx*4 + 0x6c]
        mov      dword ptr [g_walkCallback], eax
        mov      ecx, dword ptr [edx*4 + 0x74]
        add      ecx, eax
        mov      dword ptr [g_eventQueueCurrent], ecx
        jne      short L_0171
        call     PushPlayerSwapCallClamp
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
        call     GuardedSeq_GuardedChainCmpDualBitXor_then_ScaledIncCmpJmp
    L_019a:
        pop      esi
        ret
    }
}
