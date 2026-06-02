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

extern void StageEventComplexFsm(void);
extern void GuardedDispatch_CallPauseMStackPushSet3Jmp(void);
extern void GuardedDispatch_CallPauseMStackPushSet4Jmp(void);
extern void NotShrCmp1Store(void);
extern void OneSetCmpJmpLoadCall(void);
extern void TripleEntryTblPushJmp(void);
extern void StageEventExitCluster(void);
extern void DeltaAbsCompareBitToggle(void);
extern void DirtyToggleByGate(void);
extern void EsiEdiAliasDualMul10(void);
extern void PunchAnimCluster(void);
extern unsigned int g_dispatchSave568;

extern unsigned int g_primary_0052d74c;
extern unsigned int g_secondary_00538068;

__declspec(naked) void StageEventComplexFsm(void)
{
    __asm {
        mov      eax, dword ptr [g_baseSel]
        push     ebx
        push     ebp
        push     esi
        lea      esi, [eax*4]
        push     edi
        xor      edi, edi
        mov      eax, dword ptr [esi + 0x84]
        mov      dword ptr [esi + 0x84], edi
        cmp      eax, edi
        je       L_c819
        mov      ebx, 0x18000
        mov      ebp, 0x10000
    L_c6b0:
        mov      eax, dword ptr [g_audioBankSel]
        cmp      eax, edi
        mov      dword ptr [g_walkCallback], eax
        jne      L_c82f
        call     NotShrCmp1Store
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_c855
        mov      eax, dword ptr [g_walkCallback]
        mov      ecx, eax
        and      ecx, 9
        cmp      ecx, 9
        mov      dword ptr [g_eventQueueCurrent], ecx
        je       L_c85a
        and      eax, 5
        cmp      eax, 5
        mov      dword ptr [g_eventQueueCurrent], eax
        je       L_c864
        mov      dword ptr [g_walkCallback], 0xb333
        call     EsiEdiAliasDualMul10
        cmp      dword ptr [g_framePauseFlag], edi
        jne      short L_c855
        mov      dword ptr [g_xformScratch2088], ebx
        call     PunchAnimCluster
        cmp      dword ptr [g_framePauseFlag], edi
        jne      short L_c855
        call     DeltaAbsCompareBitToggle
        cmp      dword ptr [g_framePauseFlag], edi
        jne      short L_c855
        mov      al, byte ptr [g_xformDirtyFlags]
        mov      dword ptr [g_walkCallback], ebp
        test     al, 1
        jne      short L_c759
        mov      dword ptr [g_walkCallback], 0x8000
    L_c759:
        call     EsiEdiAliasDualMul10
        cmp      dword ptr [g_framePauseFlag], edi
        jne      short L_c855
        mov      edx, dword ptr [g_fightGroupHead]
        mov      esi, dword ptr [g_player1NodeIdx]
        mov      eax, OFFSET g_primary_0052d74c
        mov      ecx, OFFSET g_secondary_00538068
        shr      eax, 2
        shr      ecx, 2
        cmp      edx, esi
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [g_xformEntityIdx], ecx
        je       short L_c79c
        mov      eax, ecx
        mov      dword ptr [g_currentNodeIdx], eax
    L_c79c:
        mov      eax, dword ptr [eax*4]
        cmp      eax, edi
        mov      dword ptr [g_walkCallback], eax
        je       short L_c86e
        mov      eax, OFFSET g_dispatchSave568
        shr      eax, 2
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [edx*4 + 0x24], eax
        mov      ecx, dword ptr [g_baseSel]
        mov      eax, dword ptr [ecx*4 + 0x68]
        dec      eax
        mov      dword ptr [g_walkCallback], eax
        jne      short L_c7eb
        call     TripleEntryTblPushJmp
        cmp      dword ptr [g_framePauseFlag], edi
        jne      short L_c855
        mov      eax, dword ptr [g_walkCallback]
    L_c7eb:
        mov      edx, dword ptr [g_baseSel]
        mov      dword ptr [edx*4 + 0x68], eax
        mov      eax, dword ptr [g_baseSel]
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], edi
        cmp      eax, edi
        jne      L_c6b0
    L_c819:
        call     DirtyToggleByGate
        cmp      dword ptr [g_framePauseFlag], edi
        jne      short L_c855
        test     byte ptr [g_xformDirtyFlags], 4
        je       short L_c839
    L_c82f:
        call     StageEventExitCluster
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        ret
    L_c839:
        mov      eax, 1
        mov      dword ptr [esi + 8], OFFSET StageEventComplexFsm
        mov      dword ptr [esi + 0x84], eax
        mov      dword ptr [g_pendingNodeType], eax
        mov      dword ptr [g_framePauseFlag], eax
    L_c855:
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        ret
    L_c85a:
        call     GuardedDispatch_CallPauseMStackPushSet3Jmp
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        ret
    L_c864:
        call     GuardedDispatch_CallPauseMStackPushSet4Jmp
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        ret
    L_c86e:
        call     OneSetCmpJmpLoadCall
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        ret
    }
}
