/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
#include "portable/ghidra_types.h"
#include "game/tick.h"

extern unsigned int g_currentNodeIdx;
extern unsigned int g_baseSel;
extern unsigned int g_chainAccumCur;
extern unsigned int g_cj_0054205c;
extern unsigned int g_gameCountdown;
extern unsigned int g_xformScratch94;
extern unsigned int g_fightStateProgress;
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
extern unsigned int g_armedReloadA;
extern unsigned int g_armedReloadB;
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

/* @addr 0x004a07a0 (196b audio) - mstack-push 2; sample bit-update by index.
 *   Push g_chainAccumCur, g_xformEntityIdx.
 *   ecx = [0x541fc0]; eax = g_walkCallback; g_xformEntityIdx = ecx;
 *   [0x535e48] = eax (= g_walkCallback snapshot); ecx += eax;
 *   eax = chain[ecx]; g_xformEntityIdx = eax;
 *   edx = chain[eax + 0x10]; g_xformEntityIdx = edx; esi = chain[edx];
 *   g_chainAccumCur--; g_walkCallback = esi;
 *   if (g_chainAccumCur > 0 before decrement, i.e., decremented value >= 0):
 *     g_eventQueueCurrent = (1 << g_chainAccumCur) | esi; chain[edx] = same.
 *   mstack-pop into g_xformEntityIdx, g_chainAccumCur.
 */
extern unsigned int g_dispatchArg;
extern unsigned int g_audioBitField;

extern unsigned int g_matrixStack_arr;

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void BitSetByIndex(void)

{
  int iVar1;
  
  g_matrixStackTop = g_matrixStackTop + 1;
  *MK4_NODE(int, (int)g_matrixStackTop) = g_chainAccumCur;
  g_matrixStackTop = g_matrixStackTop + 1;
  *MK4_NODE(undefined4, (int)g_matrixStackTop) = g_eventQueuePending;
  g_dispatchArg = g_walkCallback;
  iVar1 = MK4_NODE_AT(int, *(int *)((g_audioBitField + g_walkCallback) * 4), 0x10);
  g_walkCallback = MK4_NODE_AT(uint, iVar1, 0);
  if (-1 < g_chainAccumCur + -1) {
    g_eventQueueCurrent = 1 << ((byte)(g_chainAccumCur + -1) & 0x1f) | g_walkCallback;
    MK4_NODE_AT(uint, iVar1, 0) = g_eventQueueCurrent;
  }
  g_eventQueuePending = *MK4_NODE(undefined4, (int)g_matrixStackTop);
  g_chainAccumCur = *MK4_NODE(undefined4, (int)(g_matrixStackTop + -1));
  g_matrixStackTop = g_matrixStackTop + -2;
  return;
}
#else
__declspec(naked) void BitSetByIndex(void) {
    __asm {
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_chainAccumCur]
        inc     eax
        push    esi
        mov     dword ptr [g_matrixStackTop], eax
        mov     [eax*4 + g_matrixStack_arr], ecx
        mov     eax, dword ptr [g_matrixStackTop]
        mov     edx, dword ptr [g_xformEntityIdx]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     [eax*4 + g_matrixStack_arr], edx
        mov     ecx, dword ptr [g_audioBitField]
        mov     eax, dword ptr [g_walkCallback]
        mov     dword ptr [g_xformEntityIdx], ecx
        add     ecx, eax
        mov     dword ptr [g_dispatchArg], eax
        mov     eax, [ecx*4 + g_matrixStack_arr]
        mov     dword ptr [g_xformEntityIdx], eax
        mov     edx, [eax*4 + 0x10]
        mov     eax, dword ptr [g_chainAccumCur]
        mov     dword ptr [g_xformEntityIdx], edx
        dec     eax
        mov     esi, [edx*4 + g_matrixStack_arr]
        mov     dword ptr [g_chainAccumCur], eax
        mov     dword ptr [g_walkCallback], esi
        _emit   78h
        _emit   1bh
        mov     ecx, dword ptr [g_chainAccumCur]
        mov     eax, 1
        shl     eax, cl
        or      eax, esi
        mov     dword ptr [g_eventQueueCurrent], eax
        mov     [edx*4 + g_matrixStack_arr], eax
        mov     eax, dword ptr [g_matrixStackTop]
        pop     esi
        mov     ecx, [eax*4 + g_matrixStack_arr]
        dec     eax
        mov     dword ptr [g_xformEntityIdx], ecx
        mov     dword ptr [g_matrixStackTop], eax
        mov     edx, [eax*4 + g_matrixStack_arr]
        dec     eax
        mov     dword ptr [g_chainAccumCur], edx
        mov     dword ptr [g_matrixStackTop], eax
        ret
    }
}
#endif
