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
/* Move-dispatch 4-state FSM (766b game):                             */
/*  state 0: parse move-cmd packed bytes, decode flags, install state 1.*/
/*  state 1: angle-store + counter-inc, install state 2.              */
/*  state 2/3: counter-loop, call 0048d490 then 494e20/return.        */
/* ------------------------------------------------------------------ */
extern void InstallSelf3WayChainCmp(void);
extern void ScaledInit_MStackChainInstallDispatch_g_scaledInit_0048d490(void);
extern void InstallSelfChain494d60(void);
extern void DispatchDoubleScaledCluster(void);

extern void ScaledLoadIncJmp_set_g_walkCallback_then_ScaledArrStore_GuardedChainCmpDualBitXor(void);
extern void TableLookupCall_g_table_004efa00(void);

__declspec(naked) void MoveDispatch4StateFsm(void)
{
    __asm {
    L_4a60:
        mov      eax, dword ptr [g_baseSel]
        push     esi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        sub      eax, 0
        je       L_4c20
        dec      eax
        je       L_4b69
        dec      eax
        je       short L_4aa5
        mov      eax, dword ptr [g_eventQueueChild]
        dec      eax
        mov      dword ptr [g_eventQueueChild], eax
        jne      short L_4aba
        call     InstallSelfChain494d60
        pop      esi
        ret
    L_4aa5:
        mov      edx, dword ptr [g_eventQueueEnd]
        xor      ecx, ecx
        mov      cl, byte ptr [edx*4 + 5]
        mov      dword ptr [g_eventQueueChild], ecx
    L_4aba:
        call     ScaledLoadIncJmp_set_g_walkCallback_then_ScaledArrStore_GuardedChainCmpDualBitXor
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_4d5c
        mov      eax, dword ptr [g_eventQueueEnd]
        mov      edx, dword ptr [g_eventQueueChild]
        mov      ecx, dword ptr [eax*4 + 8]
        mov      eax, dword ptr [g_matrixStackTop]
        and      ecx, 0xff
        inc      eax
        mov      dword ptr [g_walkCallback], ecx
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], edx
        call     ScaledInit_MStackChainInstallDispatch_g_scaledInit_0048d490
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_4d5c
        mov      eax, dword ptr [g_matrixStackTop]
        mov      ecx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      eax, dword ptr [g_xformScratch2088]
        cmp      eax, 1
        mov      dword ptr [g_eventQueueChild], ecx
        jne      short L_4b37
        call     DispatchDoubleScaledCluster
        pop      esi
        ret
    L_4b37:
        test     eax, eax
        je       short L_4b42
        call     DispatchDoubleScaledCluster
        pop      esi
        ret
    L_4b42:
        mov      dword ptr [esi + 8], OFFSET L_4a60
        mov      dword ptr [esi + 0x84], 3
        mov      dword ptr [g_pendingNodeType], 1
        mov      dword ptr [g_framePauseFlag], 1
        pop      esi
        ret
    L_4b69:
        mov      edx, dword ptr [g_eventQueueEnd]
        mov      eax, dword ptr [edx*4 + 8]
        shr      eax, 0x10
        mov      dword ptr [g_walkCallback], eax
        call     TableLookupCall_g_table_004efa00
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_4d5c
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      eax, dword ptr [ecx*4 + 0x28]
        inc      eax
        mov      dword ptr [g_eventQueueChild], eax
        mov      dword ptr [ecx*4 + 0x28], eax
        mov      edx, dword ptr [g_eventQueueEnd]
        xor      ecx, ecx
        mov      cl, byte ptr [edx*4 + 6]
        mov      dword ptr [g_eventQueueChild], ecx
        mov      dword ptr [esi + 8], OFFSET L_4a60
        mov      eax, dword ptr [g_baseSel]
        mov      ecx, OFFSET L_4a60
        add      ecx, 0x2000000
        mov      dword ptr [eax*4 + 0x84], 2
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      edx, dword ptr [g_baseSel]
        mov      dword ptr [edx*4 + 0x84], 0
        call     InstallSelf3WayChainCmp
        mov      dword ptr [g_framePauseFlag], 1
        pop      esi
        ret
    L_4c20:
        mov      eax, dword ptr [g_eventQueueEnd]
        mov      ecx, dword ptr [g_baseSel]
        mov      eax, dword ptr [eax*4 + 8]
        and      eax, 0xff
        add      eax, 0x300
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x68], eax
        mov      edx, dword ptr [g_baseSel]
        mov      eax, 0x10e
        mov      dword ptr [g_eventQueueCurrent], eax
        mov      ecx, dword ptr [edx*4 + 0x74]
        cmp      ecx, 0x113
        mov      dword ptr [g_walkCallback], ecx
        jne      short L_4c74
        mov      eax, ecx
        mov      dword ptr [g_eventQueueCurrent], eax
    L_4c74:
        cmp      ecx, 0x111
        jne      short L_4c83
        mov      eax, ecx
        mov      dword ptr [g_eventQueueCurrent], eax
    L_4c83:
        cmp      ecx, 0x112
        jne      short L_4c92
        mov      eax, ecx
        mov      dword ptr [g_eventQueueCurrent], eax
    L_4c92:
        cmp      ecx, 0x212
        jne      short L_4ca1
        mov      eax, ecx
        mov      dword ptr [g_eventQueueCurrent], eax
    L_4ca1:
        mov      dword ptr [edx*4 + 0x74], eax
        mov      edx, dword ptr [g_eventQueueEnd]
        mov      ecx, dword ptr [g_fightGroupHead]
        xor      eax, eax
        mov      al, byte ptr [edx*4 + 9]
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x28], eax
        mov      edx, dword ptr [g_eventQueueEnd]
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      eax, dword ptr [edx*4]
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [ecx*4 + 0x24], eax
        mov      edx, dword ptr [g_eventQueueEnd]
        mov      eax, dword ptr [edx*4 + 4]
        mov      edx, OFFSET L_4a60
        shr      eax, 0x18
        mov      dword ptr [g_eventQueueChild], eax
        mov      dword ptr [esi + 8], OFFSET L_4a60
        mov      ecx, dword ptr [g_baseSel]
        add      edx, 0x1000000
        mov      dword ptr [ecx*4 + 0x84], 1
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], edx
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      eax, dword ptr [g_baseSel]
        mov      dword ptr [eax*4 + 0x84], 0
        call     InstallSelf3WayChainCmp
        mov      dword ptr [g_framePauseFlag], 1
    L_4d5c:
        pop      esi
        ret
    }
}
