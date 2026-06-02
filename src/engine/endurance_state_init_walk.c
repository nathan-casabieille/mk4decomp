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

extern void MStackPushDispatchBitGate(void);
extern void PollThenInit(void);
extern void MultiGateDispatchCallJmp(void);
extern void SpawnLeftRightProps(void);
extern void BulletVolleySpawner(void);
extern void EnduranceStateInitWalk(void);
extern void ScaledOrStore_004903d0(void);

extern void MStackPushComplexCallPop_00406430(void);

__declspec(naked) void SpawnListBatchLoader(void)
{
    __asm {
        mov      eax, dword ptr [g_currentNodeIdx]
        push     ebx
        mov      ecx, dword ptr [eax*4]
        inc      eax
        test     ecx, ecx
        mov      dword ptr [g_eventQueueChild], ecx
        mov      dword ptr [g_currentNodeIdx], eax
        je       L_7882
        mov      bl, 4
    L_7733:
        mov      ecx, dword ptr [eax*4]
        inc      eax
        mov      dword ptr [g_eventQueueNotMask], ecx
        mov      ecx, dword ptr [g_matrixStackTop]
        inc      ecx
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [g_matrixStackTop], ecx
        mov      dword ptr [ecx*4], eax
        mov      edx, dword ptr [g_eventQueueChild]
        mov      dword ptr [g_xformEntityIdx], edx
        call     MStackPushDispatchBitGate
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_790f
        test     byte ptr [g_xformDirtyFlags], bl
        jne      L_78ca
        call     MStackPushComplexCallPop_00406430
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_790f
        mov      eax, dword ptr [g_matrixStackTop]
        mov      ecx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      eax, dword ptr [g_eventQueueNotMask]
        test     eax, eax
        mov      dword ptr [g_currentNodeIdx], ecx
        je       short L_77c9
        call     ScaledOrStore_004903d0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_790f
    L_77c9:
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      edx, dword ptr [g_fightGroupHead]
        mov      eax, dword ptr [ecx*4]
        inc      ecx
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      dword ptr [edx*4 + 0x30], eax
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      ecx, dword ptr [eax*4]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      eax, dword ptr [g_fightGroupHead]
        mov      dword ptr [g_walkCallback], ecx
        mov      dword ptr [eax*4 + 0x54], ecx
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      edx, dword ptr [g_fightGroupHead]
        mov      ecx, dword ptr [eax*4]
        inc      eax
        mov      dword ptr [g_walkCallback], ecx
        add      ecx, 0x40000
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [edx*4 + 0x58], ecx
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      ecx, dword ptr [eax*4]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      eax, dword ptr [g_fightGroupHead]
        mov      dword ptr [g_walkCallback], ecx
        mov      dword ptr [eax*4 + 0x5c], ecx
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      ecx, dword ptr [eax*4]
        inc      eax
        test     ecx, ecx
        mov      dword ptr [g_eventQueueChild], ecx
        mov      dword ptr [g_currentNodeIdx], eax
        jne      L_7733
    L_7882:
        call     PollThenInit
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_790f
        call     MultiGateDispatchCallJmp
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_790f
        call     EnduranceStateInitWalk
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_790f
        call     SpawnLeftRightProps
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_790f
        call     BulletVolleySpawner
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        je       short L_78e4
        pop      ebx
        ret
    L_78ca:
        mov      eax, dword ptr [g_matrixStackTop]
        mov      ecx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      dword ptr [g_matrixStackTop], eax
        jmp      short L_78e9
    L_78e4:
        mov      eax, dword ptr [g_matrixStackTop]
    L_78e9:
        mov      edx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_currentNodeIdx], edx
        mov      dword ptr [g_matrixStackTop], eax
        mov      ecx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_fightGroupHead], ecx
        mov      dword ptr [g_matrixStackTop], eax
    L_790f:
        pop      ebx
        ret
    }
}
