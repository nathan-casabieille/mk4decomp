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

/* @addr 0x00405450 (348b boot) - mstack-push-2 + 6/13-dword burst init.
 *   Pushes g_currentNodeIdx and g_xformLoopCounter onto the mstack, snapshots
 *   g_bootChainState4 to g_currentNodeIdx, calls MStackPushChainStepIndex.
 *   On no-error AND bit 2 of g_xformDirtyFlags clear: bursts 6 dwords of 0 at
 *   the scaled g_currentNodeIdx base via unrolled 4-store loop with rep stosd
 *   tail; advances 0x542044 by 6, sets g_xformLoopCounter=0xd, bursts 13 dwords
 *   of 0 at the new scaled base (using a 12+remainder pattern); then restores
 *   from g_currentNodeIdx-6 storing g_baseSel at offset +0x14.
 *   Always: pops the 2 mstack entries back, sets bit 2 of 0x54208c then
 *   clears it again (with a do-while-0 style fork on the eq flag) and exits.
 */
extern unsigned int g_bootChainState4;
extern unsigned int g_phaseChainTbl;
extern void MStackPushChainStepIndex(void);

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void MStackPush2Burst6Init(void)

{
  int iVar1;
  undefined *puVar2;
  int iVar3;
  undefined4 *puVar4;
  bool bVar5;
  
  g_matrixStackTop = g_matrixStackTop + 1;
  *MK4_NODE(int, (int)g_matrixStackTop) = (g_currentNodeIdx);
  g_matrixStackTop = g_matrixStackTop + 1;
  *MK4_NODE(undefined4, (int)g_matrixStackTop) = g_xformLoopCounter;
  (g_currentNodeIdx) = g_bootChainState4;
  MStackPushChainStepIndex();
  if (g_framePauseFlag == 0) {
    if ((g_xformDirtyFlags & 4) == 0) {
      iVar3 = 6;
      puVar4 = (undefined4 *)((g_currentNodeIdx) * 4);
      iVar1 = 1;
      do {
        *puVar4 = 0;
        iVar3 = iVar3 + -4;
        puVar4[1] = 0;
        puVar4[2] = 0;
        puVar4[3] = 0;
        puVar4 = puVar4 + 4;
        iVar1 = iVar1 + -1;
      } while (iVar1 != 0);
      if (0 < iVar3) {
        for (; iVar3 != 0; iVar3 = iVar3 + -1) {
          *puVar4 = 0;
          puVar4 = puVar4 + 1;
        }
      }
      iVar3 = 0xd;
      (g_currentNodeIdx) = (g_currentNodeIdx) + 6;
      g_walkCallback = 0;
      puVar4 = (undefined4 *)((g_currentNodeIdx) * 4);
      iVar1 = 3;
      do {
        *puVar4 = 0;
        iVar3 = iVar3 + -4;
        puVar4[1] = 0;
        puVar4[2] = 0;
        puVar4[3] = 0;
        puVar4 = puVar4 + 4;
        iVar1 = iVar1 + -1;
      } while (iVar1 != 0);
      if (0 < iVar3) {
        for (; iVar3 != 0; iVar3 = iVar3 + -1) {
          *puVar4 = 0;
          puVar4 = puVar4 + 1;
        }
      }
      (g_currentNodeIdx) = (g_currentNodeIdx) + -6;
      MK4_NODE_AT(undefined4, (g_currentNodeIdx), 0x14) = g_baseSel;
    }
    g_eventQueuePending = (g_currentNodeIdx);
    g_xformLoopCounter = *MK4_NODE(undefined4, (int)g_matrixStackTop);
    puVar2 = g_matrixStackTop + -1;
    g_matrixStackTop = g_matrixStackTop + -2;
    g_xformDirtyFlags = g_xformDirtyFlags | 4;
    if (((g_currentNodeIdx) == 0) ||
       (g_xformDirtyFlags = g_xformDirtyFlags ^ 4, bVar5 = (g_currentNodeIdx) == 0,
       (g_currentNodeIdx) = *MK4_NODE(int, (int)puVar2), bVar5)) {
      g_eventQueuePending = 0;
      (g_currentNodeIdx) = *MK4_NODE(int, (int)puVar2);
    }
  }
  return;
}
#else
__declspec(naked) void MStackPush2Burst6Init(void) {
    __asm {
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_currentNodeIdx]
        inc     eax
        push    esi
        mov     dword ptr [g_matrixStackTop], eax
        push    edi
        mov     dword ptr [eax*4 + g_phaseChainTbl], ecx
        mov     eax, dword ptr [g_matrixStackTop]
        mov     edx, dword ptr [g_xformLoopCounter]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4 + g_phaseChainTbl], edx
        mov     eax, dword ptr [g_bootChainState4]
        mov     dword ptr [g_currentNodeIdx], eax
        call    MStackPushChainStepIndex
        mov     eax, dword ptr [g_framePauseFlag]
        xor     edx, edx
        cmp     eax, edx
        jne     L_mpb_pop2
        test    byte ptr [g_xformDirtyFlags], 4
        jne     L_mpb_skipBursts
        mov     eax, dword ptr [g_currentNodeIdx]
        mov     ecx, 6
        lea     edi, [eax*4]
        mov     eax, 1
    L_mpb_burst1:
        mov     dword ptr [edi], edx
        add     edi, 4
        sub     ecx, 4
        mov     dword ptr [edi], edx
        add     edi, 4
        mov     dword ptr [edi], edx
        add     edi, 4
        mov     dword ptr [edi], edx
        add     edi, 4
        dec     eax
        jne     short L_mpb_burst1
        cmp     ecx, edx
        jle     short L_mpb_after1
        xor     eax, eax
        rep stosd
    L_mpb_after1:
        mov     eax, dword ptr [g_currentNodeIdx]
        mov     ecx, 0xd
        add     eax, 6
        mov     dword ptr [g_xformLoopCounter], ecx
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [g_walkCallback], edx
        lea     edi, [eax*4]
        mov     eax, 3
    L_mpb_burst2:
        mov     dword ptr [edi], edx
        add     edi, 4
        sub     ecx, 4
        mov     dword ptr [edi], edx
        add     edi, 4
        mov     dword ptr [edi], edx
        add     edi, 4
        mov     dword ptr [edi], edx
        add     edi, 4
        dec     eax
        jne     short L_mpb_burst2
        cmp     ecx, edx
        jle     short L_mpb_after2
        xor     eax, eax
        rep stosd
    L_mpb_after2:
        mov     eax, dword ptr [g_currentNodeIdx]
        mov     ecx, dword ptr [g_baseSel]
        sub     eax, 6
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [eax*4 + 0x14], ecx
    L_mpb_skipBursts:
        mov     ecx, dword ptr [g_currentNodeIdx]
        mov     eax, dword ptr [g_matrixStackTop]
        mov     dword ptr [g_xformEntityIdx], ecx
        mov     esi, dword ptr [eax*4 + g_phaseChainTbl]
        dec     eax
        mov     dword ptr [g_xformLoopCounter], esi
        mov     dword ptr [g_matrixStackTop], eax
        mov     esi, dword ptr [eax*4 + g_phaseChainTbl]
        dec     eax
        mov     dword ptr [g_currentNodeIdx], esi
        mov     esi, dword ptr [g_xformDirtyFlags]
        or      esi, 4
        cmp     ecx, edx
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [g_xformDirtyFlags], esi
        je      short L_mpb_zeroOut
        mov     eax, esi
        xor     eax, 4
        cmp     ecx, edx
        mov     dword ptr [g_xformDirtyFlags], eax
        jne     short L_mpb_pop2
    L_mpb_zeroOut:
        mov     dword ptr [g_xformEntityIdx], edx
    L_mpb_pop2:
        pop     edi
        pop     esi
        ret
    }
}
#endif
