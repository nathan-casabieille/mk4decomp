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

extern unsigned int g_dispatchSave908;
extern unsigned int g_dispatchSave538;
extern unsigned int g_savedNode;
extern void CallSetPause(void);
extern void CmpDivJmp(void);
extern void PushSetXfmMaskCallPop(void);
extern void ScaledTripleCopy4(void);
extern void TripleEntry3Block(void);
extern void Vec3AccMul10ChainBlend(void);

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void MstackPushPackChainInit(void)

{
  undefined4 uVar1;
  uint *puVar2;
  
  g_matrixStackTop = g_matrixStackTop + 1;
  *MK4_NODE(int, (int)g_matrixStackTop) = g_cj_0054205c;
  g_walkCallback = 0x1359c6;
  PushSetXfmMaskCallPop();
  if (g_framePauseFlag == 0) {
    (*(unsigned int *)MK4_VA(unsigned int, 0x542044)) = g_cj_0054205c;
    g_cj_0054205c = *MK4_NODE(int, (int)g_matrixStackTop);
    g_matrixStackTop = g_matrixStackTop + -1;
    if (((byte)g_xformDirtyFlags & 4) != 0) {
      CallSetPause();
      return;
    }
    g_dualD = 0x13c9fc;
    func_0x0049c3d0();
    if (g_framePauseFlag == 0) {
      TripleEntry3Block();
      MK4_NODE_AT(undefined4, (*(unsigned int *)MK4_VA(unsigned int, 0x542044)), 100) = 0;
      g_dualC = (*(unsigned int *)MK4_VA(unsigned int, 0x542044));
      (*(unsigned int *)MK4_VA(unsigned int, 0x542044)) = MK4_NODE_AT(int, (*(unsigned int *)MK4_VA(unsigned int, 0x542044)), 0x18);
      g_walkCallback = 1;
      CmpDivJmp();
      if (g_framePauseFlag == 0) {
        if (((byte)g_xformDirtyFlags & 4) == 0) {
          g_eventQueuePending = g_savedNode;
          g_walkCallback = MK4_NODE_AT(undefined4, g_dualC, 0x6c);
          uVar1 = Mul10Tail(0xffff3334,g_walkCallback);
          MK4_NODE_AT(undefined4, g_eventQueuePending, 0) = uVar1;
          MK4_NODE_AT(undefined4, g_eventQueuePending, 4) = 0;
          g_walkCallback = MK4_NODE_AT(undefined4, g_dualC, 0x74);
          g_walkCallback = Mul10Tail(0xffff3334,g_walkCallback);
          MK4_NODE_AT(undefined4, g_eventQueuePending, 8) = g_walkCallback;
          ScaledTripleCopy4();
          if (g_framePauseFlag != 0) {
            return;
          }
        }
        puVar2 = (uint *)(MK4_NODE_AT(int, MK4_NODE_AT(int, g_dualC, 0x18), 0x28) * 4);
        *puVar2 = *puVar2 | 8;
        g_walkCallback = 0xc000;
        puVar2[0x12] = 0xc000;
        (*(unsigned int *)MK4_VA(unsigned int, 0x542044)) = g_dualC;
      }
    }
  }
  return;
}
#else
__declspec(naked) void MstackPushPackChainInit(void)
{
    __asm
    {
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_fightGroupHead]
        inc     eax
        mov     edx, offset g_dispatchSave908
        mov     dword ptr [g_matrixStackTop], eax
        push    esi
        shr     edx, 2
        mov     dword ptr [eax*4], ecx
        mov     dword ptr [g_walkCallback], edx
        call    PushSetXfmMaskCallPop
        mov     eax, dword ptr [g_framePauseFlag]
        xor     esi, esi
        cmp     eax, esi
        jne     L_mppci_ret
        mov     eax, dword ptr [g_fightGroupHead]
        mov     dword ptr [g_currentNodeIdx], eax
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [eax*4]
        dec     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     al, byte ptr [g_xformDirtyFlags]
        test    al, 4
        mov     dword ptr [g_fightGroupHead], ecx
        je      short L_mppci_branchA
        call    CallSetPause
        pop     esi
        ret
    L_mppci_branchA:
        mov     edx, offset g_dispatchSave538
        shr     edx, 2
        mov     dword ptr [g_eventQueueTotal], edx
        call    Vec3AccMul10ChainBlend
        cmp     dword ptr [g_framePauseFlag], esi
        jne     L_mppci_ret
        call    TripleEntry3Block
        mov     eax, dword ptr [g_currentNodeIdx]
        mov     dword ptr [g_walkCallback], esi
        mov     dword ptr [eax*4 + 0x64], esi
        mov     eax, dword ptr [g_currentNodeIdx]
        mov     dword ptr [g_pendingNodeType], eax
        mov     ecx, dword ptr [eax*4 + 0x18]
        mov     dword ptr [g_walkCallback], 1
        mov     dword ptr [g_currentNodeIdx], ecx
        call    CmpDivJmp
        cmp     dword ptr [g_framePauseFlag], esi
        jne     L_mppci_ret
        test    byte ptr [g_xformDirtyFlags], 4
        jne     L_mppci_join
        mov     edx, dword ptr [g_savedNode]
        mov     eax, dword ptr [g_pendingNodeType]
        mov     dword ptr [g_xformEntityIdx], edx
        mov     eax, dword ptr [eax*4 + 0x6c]
        push    eax
        push    0xffff3334
        mov     dword ptr [g_walkCallback], eax
        call    Mul10Tail
        mov     ecx, dword ptr [g_xformEntityIdx]
        add     esp, 8
        mov     dword ptr [ecx*4], eax
        mov     edx, dword ptr [g_xformEntityIdx]
        mov     dword ptr [g_walkCallback], esi
        mov     dword ptr [edx*4 + 4], esi
        mov     eax, dword ptr [g_pendingNodeType]
        mov     eax, dword ptr [eax*4 + 0x74]
        push    eax
        push    0xffff3334
        mov     dword ptr [g_walkCallback], eax
        call    Mul10Tail
        mov     ecx, dword ptr [g_xformEntityIdx]
        add     esp, 8
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 8], eax
        call    ScaledTripleCopy4
        cmp     dword ptr [g_framePauseFlag], esi
        jne     short L_mppci_ret
    L_mppci_join:
        mov     edx, dword ptr [g_pendingNodeType]
        mov     eax, dword ptr [edx*4 + 0x18]
        mov     dword ptr [g_currentNodeIdx], eax
        mov     eax, dword ptr [eax*4 + 0x28]
        mov     dword ptr [g_currentNodeIdx], eax
        shl     eax, 2
        mov     ecx, dword ptr [eax]
        or      ecx, 8
        mov     dword ptr [eax], ecx
        mov     ecx, 0xc000
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [eax + 0x48], ecx
        mov     eax, dword ptr [g_pendingNodeType]
        mov     dword ptr [g_currentNodeIdx], eax
    L_mppci_ret:
        pop     esi
        ret
    }
}
#endif
