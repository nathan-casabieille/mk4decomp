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

extern unsigned int g_bootChainPair0;
extern void MStackPushChainStepIndex(void);

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void BootPhaseGateBracketedInit(void)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
  g_matrixStackTop = g_matrixStackTop + 1;
  *MK4_NODE(undefined4, (int)g_matrixStackTop) = g_xformLoopCounter;
  (g_currentNodeIdx) = g_bootChainPair0;
  MStackPushChainStepIndex();
  if (g_framePauseFlag == 0) {
    if ((g_xformDirtyFlags & 4) == 0) {
      iVar2 = 0x15;
      puVar1 = (undefined4 *)((g_currentNodeIdx) << 2);
      g_walkCallback = 0;
      iVar3 = 5;
      do {
        iVar2 = iVar2 + -4;
        *puVar1 = g_walkCallback;
        puVar1[1] = g_walkCallback;
        puVar1[2] = g_walkCallback;
        puVar1[3] = g_walkCallback;
        puVar1 = puVar1 + 4;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
      if (0 < iVar2) {
        do {
          *puVar1 = g_walkCallback;
          puVar1 = puVar1 + 1;
          iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
      }
      iVar3 = 0xc;
      (g_currentNodeIdx) = (g_currentNodeIdx) + 0x15;
      g_walkCallback = 0;
      puVar1 = (undefined4 *)((g_currentNodeIdx) * 4);
      iVar2 = 3;
      do {
        *puVar1 = 0;
        iVar3 = iVar3 + -4;
        puVar1[1] = 0;
        puVar1[2] = 0;
        puVar1[3] = 0;
        puVar1 = puVar1 + 4;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
      iVar2 = iVar3;
      if (0 < iVar3) {
        for (; iVar2 != 0; iVar2 = iVar2 + -1) {
          *puVar1 = 0;
          puVar1 = puVar1 + 1;
        }
        do {
          iVar3 = iVar3 + -1;
        } while (iVar3 != 0);
      }
      (g_currentNodeIdx) = (g_currentNodeIdx) + -0x15;
      MK4_NODE_AT(undefined4, (g_currentNodeIdx), 0x48) = 0x10000;
      MK4_NODE_AT(undefined4, (g_currentNodeIdx), 0x4c) = 0x10000;
      MK4_NODE_AT(undefined4, (g_currentNodeIdx), 0x50) = 0x10000;
      MK4_NODE_AT(undefined4, (g_currentNodeIdx), 0x20) = g_baseSel;
    }
    g_xformDirtyFlags = g_xformDirtyFlags | 4;
    g_xformLoopCounter = *MK4_NODE(undefined4, (int)g_matrixStackTop);
    g_matrixStackTop = g_matrixStackTop + -1;
    if ((g_currentNodeIdx) != 0) {
      g_xformDirtyFlags = g_xformDirtyFlags ^ 4;
    }
  }
  return;
}
#else
__declspec(naked) void BootPhaseGateBracketedInit(void)
{
    __asm
    {
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_xformLoopCounter]
        inc     eax
        push    esi
        mov     dword ptr [g_matrixStackTop], eax
        push    edi
        mov     dword ptr [eax*4], ecx
        mov     edx, dword ptr [g_bootChainPair0]
        mov     dword ptr [g_currentNodeIdx], edx
        call    MStackPushChainStepIndex
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_bpgbi_pop
        test    byte ptr [g_xformDirtyFlags], 4
        jne     L_bpgbi_postInit
        mov     eax, dword ptr [g_currentNodeIdx]
        mov     ecx, 0x15
        shl     eax, 2
        mov     dword ptr [g_walkCallback], 0
        mov     edx, 5
    L_bpgbi_loop1:
        mov     esi, dword ptr [g_walkCallback]
        sub     ecx, 4
        mov     dword ptr [eax], esi
        mov     esi, dword ptr [g_walkCallback]
        add     eax, 4
        mov     dword ptr [eax], esi
        mov     esi, dword ptr [g_walkCallback]
        add     eax, 4
        mov     dword ptr [eax], esi
        mov     esi, dword ptr [g_walkCallback]
        add     eax, 4
        mov     dword ptr [eax], esi
        add     eax, 4
        dec     edx
        jne     short L_bpgbi_loop1
        test    ecx, ecx
        jle     short L_bpgbi_block2
    L_bpgbi_rem1:
        mov     edx, dword ptr [g_walkCallback]
        mov     dword ptr [eax], edx
        add     eax, 4
        dec     ecx
        jne     short L_bpgbi_rem1
    L_bpgbi_block2:
        mov     eax, dword ptr [g_currentNodeIdx]
        mov     edx, 0xc
        add     eax, 0x15
        mov     dword ptr [g_walkCallback], 0
        mov     dword ptr [g_currentNodeIdx], eax
        lea     edi, [eax*4]
        mov     eax, 3
    L_bpgbi_loop2:
        mov     dword ptr [edi], 0
        add     edi, 4
        sub     edx, 4
        mov     dword ptr [edi], 0
        add     edi, 4
        mov     dword ptr [edi], 0
        add     edi, 4
        mov     dword ptr [edi], 0
        add     edi, 4
        dec     eax
        jne     short L_bpgbi_loop2
        test    edx, edx
        jle     short L_bpgbi_after2
        mov     ecx, edx
        xor     eax, eax
        mov     esi, edx
        rep stosd
    L_bpgbi_rem2:
        dec     edx
        dec     esi
        jne     short L_bpgbi_rem2
    L_bpgbi_after2:
        mov     eax, dword ptr [g_currentNodeIdx]
        mov     ecx, 0x10000
        sub     eax, 0x15
        mov     dword ptr [g_xformLoopCounter], edx
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [eax*4 + 0x48], ecx
        mov     eax, dword ptr [g_currentNodeIdx]
        mov     dword ptr [eax*4 + 0x4c], ecx
        mov     edx, dword ptr [g_currentNodeIdx]
        mov     dword ptr [edx*4 + 0x50], ecx
        mov     eax, dword ptr [g_currentNodeIdx]
        mov     ecx, dword ptr [g_baseSel]
        mov     dword ptr [eax*4 + 0x20], ecx
    L_bpgbi_postInit:
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_xformDirtyFlags]
        or      ecx, 4
        mov     edx, dword ptr [eax*4]
        dec     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     eax, dword ptr [g_currentNodeIdx]
        test    eax, eax
        mov     dword ptr [g_xformLoopCounter], edx
        mov     dword ptr [g_xformDirtyFlags], ecx
        je      short L_bpgbi_pop
        mov     eax, ecx
        xor     eax, 4
        mov     dword ptr [g_xformDirtyFlags], eax
    L_bpgbi_pop:
        pop     edi
        pop     esi
        ret
    }
}
#endif
