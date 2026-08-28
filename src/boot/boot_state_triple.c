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

extern void BootStateTriple(void);
extern void DispatcherComplex260_FramePauseScaledStore(void);
extern void GDispatch4(void);
extern void MStackBracket2_StateAdvance6(void);

/* @addr 0x004096b0 (143b boot) - mstack-push 2 (g_xformEntityIdx, g_pendingNodeType);
 *   call F1; pause? ret; g_pendingNodeType = g_xformEntityIdx; g_xformEntityIdx = chain[g_scaledInit+9];
 *   call F2; pause? ret; if (g_xformDirtyFlags & 4) ret; call F3; pause? ret;
 *   if (g_xformDirtyFlags & 4) ret; jmp F4.
 */

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_chain_disp_24_4096b0;
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
#define g_chain_disp_24_4096b0 (*(unsigned int *)MK4_VA(unsigned int, 0x24u))
#define g_cj_00542054 (*(unsigned int *)MK4_VA(unsigned int, 0x542054u))
#define g_cj_00542058 (*(unsigned int *)MK4_VA(unsigned int, 0x542058u))
#define g_cj_0054205c (*(unsigned int *)MK4_VA(unsigned int, 0x54205cu))
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_dualBitGate (*(unsigned int *)MK4_VA(unsigned int, 0x53a7b0u))
#define g_dualC (*(unsigned int *)MK4_VA(unsigned int, 0x54204cu))
#define g_eventArmReload (*(unsigned int *)MK4_VA(unsigned int, 0x53a770u))
#define g_eventQueueCurrent (*(unsigned int *)MK4_VA(unsigned int, 0x542070u))
#define g_eventQueuePending (*(unsigned int *)MK4_VA(unsigned int, 0x542048u))
#define g_fightAxisNegX (*(unsigned int *)MK4_VA(unsigned int, 0x535e70u))
#define g_fightAxisNegY (*(unsigned int *)MK4_VA(unsigned int, 0x535e74u))
#define g_fightAxisPosX (*(unsigned int *)MK4_VA(unsigned int, 0x535e78u))
#define g_fightAxisPosY (*(unsigned int *)MK4_VA(unsigned int, 0x535e7cu))
#define g_fightGroupHead (*(unsigned int *)MK4_VA(unsigned int, 0x54205cu))
#define g_fightStateProgress (*(unsigned int *)MK4_VA(unsigned int, 0x535ddcu))
#define g_framePauseFlag (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
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
#define g_xformEntityIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542048u))
#define g_xformLoopCounter (*(unsigned int *)MK4_VA(unsigned int, 0x53a1acu))
#define g_xformScratch94 (*(unsigned int *)MK4_VA(unsigned int, 0x542094u))
#endif

extern unsigned int g_matrixStack_arr;

#ifdef NON_MATCHING
#include "portable/mem_model.h"

extern void MStackCall_MStackPush2ChainPrepend_00406340(void);

/* @addr 0x00408d30 (main entry of the 312b triple) - NATIVE ONLY; the
 * matching build synthesizes it, and the symbol packs two more entries at
 * +0x90/+0xb0 that nothing calls directly (they would go through
 * codeptr_extras if a stored VA ever named them).
 *
 * A three-step pointer chase under the bit-2 toggle discipline: node =
 * fgh[+0x1c], advanced by g_walkCallback; then its [0]; then that node's
 * +0x28 into g_xformEntityIdx - each step bracketed by dirty |= 4 and only
 * xor'd back when the loaded value is non-null, so a null anywhere leaves
 * bit 2 SET, which is the walk machinery's not-found signal. The third test
 * is signed (jle): a negative node also aborts. */
void BootStateTriple(void)
{
    unsigned int v;

    g_xformDirtyFlags |= 4;
    v = MK4_NODE_AT(unsigned int, g_fightGroupHead, 0x1c);
    g_currentNodeIdx = v;
    if (v == 0)
        return;
    g_xformDirtyFlags ^= 4;
    if (v == 0)
        return;                       /* dead, as in the original */

    v += g_walkCallback;
    g_currentNodeIdx = v;
    g_xformDirtyFlags |= 4;
    v = *MK4_NODE(unsigned int, v);
    g_currentNodeIdx = v;
    if (v == 0)
        return;
    g_xformDirtyFlags ^= 4;
    if ((int)v <= 0)
        return;

    v = MK4_NODE_AT(unsigned int, v, 0x28);
    g_xformDirtyFlags |= 4;
    g_xformEntityIdx = v;
    if (v != 0)
        g_xformDirtyFlags ^= 4;
}
#else
/* no matching-side C for BootStateTriple - the synthesizer provides
 * 0x00408d30. */
#endif

#ifdef NON_MATCHING#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void MStackPush2DispatchChain(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  g_matrixStackTop = g_matrixStackTop + 1;
  *MK4_NODE(int, (int)g_matrixStackTop) = g_eventQueuePending;
  g_matrixStackTop = g_matrixStackTop + 1;
  *MK4_NODE(int, (int)g_matrixStackTop) = g_dualC;
  BootStateTriple();
  if (g_framePauseFlag == 0) {
    g_dualC = g_eventQueuePending;
    g_eventQueuePending = MK4_NODE_AT(int, (g_currentNodeIdx), 0x24);
    DispatcherComplex260_FramePauseScaledStore();
    if ((g_framePauseFlag == 0) && ((g_xformDirtyFlags & 4) == 0)) {
      GDispatch4();
      if ((g_framePauseFlag == 0) && ((g_xformDirtyFlags & 4) == 0)) {
        g_walkCallback = MK4_NODE_AT(uint, g_dualC, 0) | 0x10;
        MK4_NODE_AT(uint, g_dualC, 0) = g_walkCallback;
        MStackPush2RunCountdown();
        if (g_framePauseFlag == 0) {
          MStackBracket7_DispatchAndChain();
          if (g_framePauseFlag == 0) {
            MK4_NODE_AT(uint, g_dualC, 0) = MK4_NODE_AT(uint, g_dualC, 0) & 0xffffffef;
            MK4_NODE_AT(undefined4, (g_currentNodeIdx), 0x54) = MK4_NODE_AT(undefined4, g_dualC, 0x3c);
            MK4_NODE_AT(undefined4, (g_currentNodeIdx), 0x58) = MK4_NODE_AT(undefined4, g_dualC, 0x40);
            MK4_NODE_AT(undefined4, (g_currentNodeIdx), 0x5c) = MK4_NODE_AT(undefined4, g_dualC, 0x44);
            g_eventQueuePending = MK4_NODE_AT(int, (g_currentNodeIdx), 0x18);
            g_eventQueueCurrent = 0xc000000;
            MK4_NODE_AT(uint, g_eventQueuePending, 0x20) =
                 MK4_NODE_AT(uint, g_eventQueuePending, 0x20) & 0xfcffffff | 0xc000000;
            g_walkCallback = 0x10000;
            MK4_NODE_AT(undefined4, g_eventQueuePending, 0x3c) = 0x10000;
            g_matrixStackTop = g_matrixStackTop + 1;
            *MK4_NODE(int, (int)g_matrixStackTop) = (g_currentNodeIdx);
            g_eventQueuePending = MK4_NODE_AT(int, g_eventQueuePending, 0x28) + 6;
            puVar1 = (undefined4 *)((g_dualC + 6) * 4);
            puVar2 = (undefined4 *)(g_eventQueuePending * 4);
            *puVar2 = *puVar1;
            puVar2[1] = puVar1[1];
            puVar2[2] = puVar1[2];
            puVar2[3] = puVar1[3];
            puVar2[4] = puVar1[4];
            g_xformLoopCounter = 0;
            (g_currentNodeIdx) = *MK4_NODE(int, (int)g_matrixStackTop);
            g_matrixStackTop = g_matrixStackTop + -1;
            MStackCall_MStackPush2ChainPrepend_00406340();
            if (g_framePauseFlag == 0) {
              g_xformDirtyFlags = g_xformDirtyFlags | 4;
              if ((g_currentNodeIdx) != 0) {
                g_xformDirtyFlags = g_xformDirtyFlags ^ 4;
              }
              g_dualC = *MK4_NODE(int, (int)g_matrixStackTop);
              g_eventQueuePending = *MK4_NODE(int, (int)(g_matrixStackTop + -1));
              g_matrixStackTop = g_matrixStackTop + -2;
            }
          }
        }
        return;
      }
    }
  }
  return;
}
#else
__declspec(naked) void MStackPush2DispatchChain(void) {
    __asm {
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_xformEntityIdx]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     [eax*4 + g_matrixStack_arr], ecx
        mov     eax, dword ptr [g_matrixStackTop]
        mov     edx, dword ptr [g_pendingNodeType]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     [eax*4 + g_matrixStack_arr], edx
        call    BootStateTriple
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   50h
        mov     eax, dword ptr [g_xformEntityIdx]
        mov     ecx, dword ptr [g_currentNodeIdx]
        mov     dword ptr [g_pendingNodeType], eax
        mov     edx, [ecx*4 + g_chain_disp_24_4096b0]
        mov     dword ptr [g_xformEntityIdx], edx
        call    DispatcherComplex260_FramePauseScaledStore
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   25h
        test    byte ptr [g_xformDirtyFlags], 4
        _emit   75h
        _emit   1ch
        call    GDispatch4
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   0eh
        test    byte ptr [g_xformDirtyFlags], 4
        _emit   75h
        _emit   05h
        jmp     MStackBracket2_StateAdvance6
        ret
    }
}
#endif
