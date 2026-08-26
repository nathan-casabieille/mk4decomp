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
extern unsigned int g_eq;
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
#define g_eq (*(unsigned int *)MK4_VA(unsigned int, 0x542098u))
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
#define g_matrixStackTop (*(unsigned int *)MK4_VA(unsigned int, 0x4d57acu))
#define g_rangeBase (*(unsigned int *)MK4_VA(unsigned int, 0x53a46cu))
#define g_rangeSqLimit (*(unsigned int *)MK4_VA(unsigned int, 0x53a180u))
#define g_stateCountdown (*(unsigned int *)MK4_VA(unsigned int, 0x53a3c0u))
#define g_walkCallback (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_xformDirtyFlags (*(unsigned int *)MK4_VA(unsigned int, 0x54208cu))
#endif


/*
 * BootChainPushAddSignFlag - 297b boot mstack-push1 + sign-add + bit-flag toggle.
 *   g_eq = (g_walkCallback < 0); push g_xformEntityIdx to mstack.
 *   ecx = g_fightGroupHead[+0x24]; g_xformEntityIdx = ecx. If sign flag was set:
 *     edx = g_currentNodeIdx[+0x28] + g_walkCallback; g_walkCallback = edx. If sign cleared (jns):
 *       pop mstack → g_xformEntityIdx; g_xformDirtyFlags &= 0xfe; pop+ret.
 *     Else: ecx = ecx[+4]; pop mstack into edx; ecx--; g_xformDirtyFlags |= 1;
 *       g_xformEntityIdx = edx; g_walkCallback = ecx; pop+ret.
 *   Otherwise (positive branch): eax = g_walkCallback + g_currentNodeIdx[+0x28]; g_walkCallback = eax.
 *     esi = ecx[+4]; ecx = g_matrixStackTop--; g_eq = (eax < esi);
 *     edx = mstack at top; g_xformEntityIdx = edx; g_xformDirtyFlags &= 0xfffffffe;
 *     commit g_matrixStackTop. If sign result = 0: g_walkCallback = 0; g_xformDirtyFlags |= 1.
 *     pop+ret.
 */

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void BootChainPushAddSignFlag(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  g_eq = (uint)(g_walkCallback < 0);
  g_matrixStackTop = g_matrixStackTop + 1;
  *MK4_NODE(undefined4, (int)g_matrixStackTop) = g_eventQueuePending;
  iVar2 = MK4_NODE_AT(int, g_cj_0054205c, 0x24);
  if (g_eq == 0) {
    g_walkCallback = g_walkCallback + MK4_NODE_AT(int, g_cj_0054205c, 0x28);
    g_eq = (uint)(g_walkCallback < MK4_NODE_AT(int, iVar2, 4));
    g_eventQueuePending = MK4_NODE_AT(undefined4, (int)(g_matrixStackTop + -1), 4);
    g_xformDirtyFlags = g_xformDirtyFlags & 0xfffffffe;
    g_matrixStackTop = g_matrixStackTop + -1;
    if (g_eq == 0) {
      g_xformDirtyFlags = g_xformDirtyFlags | 1;
      g_walkCallback = 0;
    }
    return;
  }
  g_walkCallback = g_walkCallback + MK4_NODE_AT(int, (g_currentNodeIdx), 0x28);
  if (g_walkCallback < 0) {
    puVar1 = (undefined4 *)((int)g_matrixStackTop * 4);
    g_matrixStackTop = g_matrixStackTop + -1;
    g_eventQueuePending = *puVar1;
    g_walkCallback = MK4_NODE_AT(int, iVar2, 4) + -1;
    g_xformDirtyFlags = g_xformDirtyFlags | 1;
    return;
  }
  puVar1 = (undefined4 *)((int)g_matrixStackTop * 4);
  g_matrixStackTop = g_matrixStackTop + -1;
  g_eventQueuePending = *puVar1;
  g_xformDirtyFlags = g_xformDirtyFlags & 0xfffffffe;
  return;
}
#else
__declspec(naked) void BootChainPushAddSignFlag(void)
{
    __asm
    {
        mov     edx, dword ptr [g_walkCallback]
        xor     eax, eax
        test    edx, edx
        mov     ecx, dword ptr [g_xformEntityIdx]
        push    esi
        setl    al
        mov     dword ptr [g_eq], eax
        mov     eax, dword ptr [g_matrixStackTop]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4], ecx
        mov     edx, dword ptr [g_fightGroupHead]
        mov     eax, dword ptr [g_eq]
        mov     ecx, dword ptr [edx*4 + 0x24]
        test    eax, eax
        mov     dword ptr [g_xformEntityIdx], ecx
        je      short L_77_pos
        mov     edx, dword ptr [g_currentNodeIdx]
        mov     eax, dword ptr [edx*4 + 0x28]
        mov     edx, dword ptr [g_walkCallback]
        add     edx, eax
        mov     dword ptr [g_walkCallback], edx
        jns     short L_77_signClear
        mov     ecx, dword ptr [ecx*4 + 4]
        mov     eax, dword ptr [g_matrixStackTop]
        mov     dword ptr [g_walkCallback], ecx
        mov     edx, dword ptr [eax*4]
        dec     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     eax, dword ptr [g_xformDirtyFlags]
        dec     ecx
        or      al, 1
        mov     dword ptr [g_xformEntityIdx], edx
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [g_xformDirtyFlags], eax
        pop     esi
        ret
    L_77_signClear:
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [eax*4]
        dec     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     eax, dword ptr [g_xformDirtyFlags]
        and     al, 0xfe
        mov     dword ptr [g_xformEntityIdx], ecx
        mov     dword ptr [g_xformDirtyFlags], eax
        pop     esi
        ret
    L_77_pos:
        mov     eax, dword ptr [g_walkCallback]
        mov     esi, dword ptr [edx*4 + 0x28]
        add     eax, esi
        xor     edx, edx
        mov     dword ptr [g_walkCallback], eax
        mov     esi, dword ptr [ecx*4 + 4]
        mov     ecx, dword ptr [g_matrixStackTop]
        cmp     eax, esi
        setl    dl
        mov     eax, edx
        dec     ecx
        mov     dword ptr [g_eq], eax
        mov     edx, dword ptr [ecx*4 + 4]
        mov     dword ptr [g_xformEntityIdx], edx
        mov     edx, dword ptr [g_xformDirtyFlags]
        and     edx, 0xfffffffe
        mov     dword ptr [g_matrixStackTop], ecx
        test    eax, eax
        mov     dword ptr [g_xformDirtyFlags], edx
        jne     short L_77_done
        mov     dword ptr [g_walkCallback], eax
        mov     eax, edx
        or      al, 1
        mov     dword ptr [g_xformDirtyFlags], eax
    L_77_done:
        pop     esi
        ret
    }
}
#endif
