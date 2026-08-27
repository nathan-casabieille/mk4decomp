/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
#include "portable/ghidra_types.h"
#include "game/tick.h"

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
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
#endif

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
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_cj_00542058;
extern unsigned int g_rangeSqLimit;
extern unsigned int g_armedReloadA;
extern unsigned int g_armedReloadB;
extern unsigned int g_dualBitGate;
extern unsigned int g_eventArmReload;
extern unsigned int g_rangeBase;
#endif

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
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
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
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_active_00537e88 (*(unsigned int *)MK4_VA(unsigned int, 0x537e88u))
#define g_active_0053a408 (*(unsigned int *)MK4_VA(unsigned int, 0x53a408u))
#define g_armedReloadA (*(unsigned int *)MK4_VA(unsigned int, 0x541fa4u))
#define g_armedReloadB (*(unsigned int *)MK4_VA(unsigned int, 0x541fa8u))
#define g_audioBankSel (*(unsigned int *)MK4_VA(unsigned int, 0x537f94u))
#define g_audioBoundNode (*(unsigned int *)MK4_VA(unsigned int, 0x5437f0u))
#define g_baseSel (*(unsigned int *)MK4_VA(unsigned int, 0x542060u))
#define g_chainAccumCur (*(unsigned int *)MK4_VA(unsigned int, 0x542078u))
#define g_cj_00542054 (*(unsigned int *)MK4_VA(unsigned int, 0x542054u))
#define g_cj_00542058 (*(unsigned int *)MK4_VA(unsigned int, 0x542058u))
#define g_cj_0054205c (*(unsigned int *)MK4_VA(unsigned int, 0x54205cu))
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_dualBitGate (*(unsigned int *)MK4_VA(unsigned int, 0x53a7b0u))
#define g_dualC (*(unsigned int *)MK4_VA(unsigned int, 0x54204cu))
#define g_dualD (*(unsigned int *)MK4_VA(unsigned int, 0x542050u))
#define g_eventArmReload (*(unsigned int *)MK4_VA(unsigned int, 0x53a770u))
#define g_eventQueuePending (*(unsigned int *)MK4_VA(unsigned int, 0x542048u))
#define g_fightAxisNegX (*(unsigned int *)MK4_VA(unsigned int, 0x535e70u))
#define g_fightAxisNegY (*(unsigned int *)MK4_VA(unsigned int, 0x535e74u))
#define g_fightAxisPosX (*(unsigned int *)MK4_VA(unsigned int, 0x535e78u))
#define g_fightAxisPosY (*(unsigned int *)MK4_VA(unsigned int, 0x535e7cu))
#define g_fightStateProgress (*(unsigned int *)MK4_VA(unsigned int, 0x535ddcu))
#define g_gameCountdown (*(unsigned int *)MK4_VA(unsigned int, 0x53a718u))
#define g_installOwnerNode (*(unsigned int *)MK4_VA(unsigned int, 0x535cf8u))
#define g_lastGatedTick (*(unsigned int *)MK4_VA(unsigned int, 0x54358cu))
#define g_lastGatedValue (*(unsigned int *)MK4_VA(unsigned int, 0x543598u))
#define g_rangeBase (*(unsigned int *)MK4_VA(unsigned int, 0x53a46cu))
#define g_rangeSqLimit (*(unsigned int *)MK4_VA(unsigned int, 0x53a180u))
#define g_stateCountdown (*(unsigned int *)MK4_VA(unsigned int, 0x53a3c0u))
#define g_xformLoopCounter (*(unsigned int *)MK4_VA(unsigned int, 0x53a1acu))
#define g_xformScratch94 (*(unsigned int *)MK4_VA(unsigned int, 0x542094u))
#endif


/* @addr 0x004ab380 (191b audio) - linked-list builder for ESI=g_eventQueueTotal array.
 *   ebx = g_xformEntityIdx; esi = g_eventQueueTotal; edi = g_pendingNodeType.
 *   [esi+0] = 0; [esi+4] = ebx; [esi+8] = g_eventQueueEnd.
 *   if (g_eventQueueEnd == 0): return.
 *   [esi+0] = g_scaledInit; eax = ebx + g_scaledInit + 1; [eax*4] = esi.
 *   [0x53a1ac] = [esi+8]; if (<= 1) skip loop;
 *   [0x53a1ac] -= 2; eax = g_scaledInit + edi;
 *   loop: push ebp; ecx = g_scaledInit*4; [ecx + ebx*4 + 4] = esi; [ecx + ebx*4] = eax;
 *     ebp = [0x53a1ac]; edx = eax; ecx = eax*4; eax += edi; ebp--;
 *     [0x53a1ac] = ebp; if (ebp >= 0) loop;
 *   pop ebp.
 *   [ebx + edx] *= 0; [(ebx + edx + 1)*4] = esi.
 *   pop edi/esi/ebx.
 */
extern unsigned int g_matrixStack_arr;

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void LinkedListBuilder(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar3 = g_dualD;
  iVar2 = g_dualC;
  iVar1 = g_eventQueuePending;
  MK4_NODE_AT(undefined4, g_dualD, 0) = 0;
  MK4_NODE_AT(int, iVar3, 4) = g_eventQueuePending;
  MK4_NODE_AT(int, iVar3, 8) = g_cj_00542054;
  iVar4 = (g_currentNodeIdx);
  if (g_cj_00542054 != 0) {
    MK4_NODE_AT(int, iVar3, 0) = (g_currentNodeIdx);
    *MK4_NODE(int, (iVar1 + 1 + iVar4)) = iVar3;
    g_xformLoopCounter = MK4_NODE_AT(int, iVar3, 8);
    if (1 < g_xformLoopCounter) {
      for (g_xformLoopCounter = g_xformLoopCounter + -2; -1 < (int)g_xformLoopCounter; g_xformLoopCounter = g_xformLoopCounter + -1) {
        iVar5 = iVar4 * 4;
        iVar4 = iVar4 + iVar2;
        *MK4_NODE(int, iVar5 + 4 + iVar1) = iVar3;
        *MK4_NODE(int, iVar5 + iVar1) = iVar4;
      }
    }
    *MK4_NODE(undefined4, (iVar1 + iVar4)) = 0;
    *MK4_NODE(int, (iVar1 + 1 + iVar4)) = iVar3;
  }
  return;
}
#else
__declspec(naked) void LinkedListBuilder(void) {
    __asm {
        push    ebx
        mov     ebx, dword ptr [g_xformEntityIdx]
        push    esi
        mov     esi, dword ptr [g_eventQueueTotal]
        push    edi
        mov     edi, dword ptr [g_pendingNodeType]
        mov     dword ptr [esi*4 + g_matrixStack_arr], 0
        mov     eax, dword ptr [g_xformEntityIdx]
        mov     [esi*4 + 4], eax
        mov     ecx, dword ptr [g_eventQueueEnd]
        mov     [esi*4 + 8], ecx
        mov     eax, dword ptr [g_eventQueueEnd]
        test    eax, eax
        _emit   74h
        _emit   79h
        mov     edx, dword ptr [g_currentNodeIdx]
        mov     [esi*4 + g_matrixStack_arr], edx
        lea     eax, [ebx + edx + 1]
        mov     [eax*4 + g_matrixStack_arr], esi
        mov     eax, [esi*4 + 8]
        cmp     eax, 1
        mov     dword ptr [g_xformLoopCounter], eax
        _emit   7eh
        _emit   37h
        sub     eax, 2
        mov     dword ptr [g_xformLoopCounter], eax
        lea     eax, [edx + edi]
        _emit   78h
        _emit   2ah
        push    ebp
        lea     ecx, [edx*4 + g_matrixStack_arr]
        mov     [ecx + ebx*4 + 4], esi
        mov     [ecx + ebx*4], eax
        mov     ebp, dword ptr [g_xformLoopCounter]
        mov     edx, eax
        lea     ecx, [eax*4 + g_matrixStack_arr]
        add     eax, edi
        dec     ebp
        mov     dword ptr [g_xformLoopCounter], ebp
        _emit   79h
        _emit   0dfh
        pop     ebp
        lea     ecx, [ebx + edx]
        lea     edx, [ebx + edx + 1]
        mov     dword ptr [ecx*4 + g_matrixStack_arr], 0
        mov     [edx*4 + g_matrixStack_arr], esi
        pop     edi
        pop     esi
        pop     ebx
        ret
    }
}
#endif
