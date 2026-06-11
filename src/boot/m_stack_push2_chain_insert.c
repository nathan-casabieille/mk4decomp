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

/*
 * MStackPush2ChainInsert - 243b boot linked-list insert with mstack push2.
 *   Push g_chainInsertSlot, g_pendingNodeType to mstack. base=g_xformEntityIdx (packed_ptr).
 *   esi = base[+8]; ecx = g_currentNodeIdx + esi; chain[ecx*4 + 4] = base; g_walkCallback = 0;
 *   chain[ecx*4 + 8] = 0; esi = base[0]; g_walkCallback = esi; chain[ecx*4] = esi.
 *   If base[0] == 0: base[+4] = g_currentNodeIdx; else walk: g_pendingNodeType = base->key + esi;
 *     chain[g_pendingNodeType*4 + 8] = g_currentNodeIdx. base[0] = g_currentNodeIdx. base[+0xc]++.
 *   Pop2 mstack into g_pendingNodeType and g_chainInsertSlot; ret.
 */
extern unsigned int g_chainInsertSlot;

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void MStackPush2ChainInsert(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = g_eventQueuePending;
  iVar1 = (*(unsigned int *)MK4_VA(unsigned int, 0x542044));
  g_matrixStackTop = g_matrixStackTop + 1;
  *MK4_NODE(undefined4, (int)g_matrixStackTop) = g_chainInsertSlot;
  g_matrixStackTop = g_matrixStackTop + 1;
  *MK4_NODE(undefined4, (int)g_matrixStackTop) = g_dualC;
  iVar3 = iVar1 + MK4_NODE_AT(int, iVar2, 8);
  MK4_NODE_AT(int, iVar3, 4) = iVar2;
  MK4_NODE_AT(undefined4, iVar3, 8) = 0;
  g_walkCallback = MK4_NODE_AT(int, iVar2, 0);
  MK4_NODE_AT(int, iVar3, 0) = g_walkCallback;
  if (MK4_NODE_AT(int, iVar2, 0) == 0) {
    MK4_NODE_AT(int, iVar2, 4) = iVar1;
  }
  else {
    MK4_NODE_AT(int, (g_walkCallback + MK4_NODE_AT(int, iVar2, 8)), 8) = iVar1;
  }
  MK4_NODE_AT(int, iVar2, 0) = iVar1;
  MK4_NODE_AT(int, iVar2, 0xc) = MK4_NODE_AT(int, iVar2, 0xc) + 1;
  g_dualC = *MK4_NODE(undefined4, (int)g_matrixStackTop);
  g_chainInsertSlot = *MK4_NODE(undefined4, (int)(g_matrixStackTop + -1));
  g_matrixStackTop = g_matrixStackTop + -2;
  return;
}
#else
__declspec(naked) void MStackPush2ChainInsert(void)
{
    __asm
    {
        mov     ecx, dword ptr [g_matrixStackTop]
        mov     edx, dword ptr [g_currentNodeIdx]
        mov     eax, dword ptr [g_xformEntityIdx]
        push    esi
        mov     esi, dword ptr [g_chainInsertSlot]
        inc     ecx
        mov     dword ptr [g_matrixStackTop], ecx
        mov     dword ptr [ecx*4], esi
        mov     ecx, dword ptr [g_matrixStackTop]
        mov     esi, dword ptr [g_pendingNodeType]
        inc     ecx
        mov     dword ptr [g_matrixStackTop], ecx
        mov     dword ptr [ecx*4], esi
        mov     esi, dword ptr [eax*4 + 8]
        mov     ecx, edx
        add     ecx, esi
        mov     dword ptr [ecx*4 + 4], eax
        mov     dword ptr [g_walkCallback], 0
        mov     dword ptr [ecx*4 + 8], 0
        mov     esi, dword ptr [eax*4]
        mov     dword ptr [g_walkCallback], esi
        mov     dword ptr [ecx*4], esi
        cmp     dword ptr [eax*4], 0
        jne     short L_walk
        mov     dword ptr [eax*4 + 4], edx
        jmp     short L_after
    L_walk:
        mov     ecx, dword ptr [g_walkCallback]
        mov     dword ptr [g_pendingNodeType], ecx
        mov     esi, dword ptr [eax*4 + 8]
        add     ecx, esi
        mov     dword ptr [g_pendingNodeType], ecx
        mov     dword ptr [ecx*4 + 8], edx
    L_after:
        mov     dword ptr [eax*4], edx
        mov     esi, dword ptr [eax*4 + 0xc]
        inc     esi
        mov     dword ptr [eax*4 + 0xc], esi
        mov     eax, dword ptr [g_matrixStackTop]
        pop     esi
        mov     ecx, dword ptr [eax*4]
        dec     eax
        mov     dword ptr [g_pendingNodeType], ecx
        mov     dword ptr [g_matrixStackTop], eax
        mov     edx, dword ptr [eax*4]
        dec     eax
        mov     dword ptr [g_chainInsertSlot], edx
        mov     dword ptr [g_matrixStackTop], eax
        ret
    }
}
#endif
