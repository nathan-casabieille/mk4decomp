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
 * BootChainStreamWalkExtract - 287b boot mstack-push1 + chain stream walker.
 *   Push g_eventQueueTotal to mstack. g_pendingNodeType--; esi = chain[g_currentNodeIdx*4] + g_currentNodeIdx+1;
 *   g_currentNodeIdx++. If esi <= ecx: pop+ret.
 *   Loop: eax = chain[ecx*4]; g_walkCallback=eax. If eax < 0: skip pos branch.
 *     Else: g_eq = (eax == 0); if != 0: skip to loop test.
 *       eax = chain[eax*4 + 0x20]; g_walkCallback=eax; g_pendingNodeType += 0xf; eax &= 0x100;
 *       g_xformScratch94 = eax; if 0: skip to loop test.
 *       g_walkCallback = g_xformEntityIdx[0]; call ExtractBitsToVec3; if paused: ret-noPop.
 *     edx = g_xformEntityIdx+1; eax = (esi > ecx); g_xformScratch94 = eax; if 0: pop+ret;
 *       g_eventQueueTotal--; if sign: pop+ret; else loop back.
 *   Loop test: if esi > ecx: loop.
 *   Pop1 mstack into g_eventQueueTotal; pop esi; ret.
 */
extern unsigned int g_eq;
extern void ExtractBitsToVec3(void);

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void BootChainStreamWalkExtract(void)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  
  g_matrixStackTop = g_matrixStackTop + 1;
  *MK4_NODE(int, (int)g_matrixStackTop) = g_dualD;
  g_dualD = g_dualC - 1;
  piVar1 = (int *)((g_currentNodeIdx) * 4);
  (g_currentNodeIdx) = (g_currentNodeIdx) + 1;
  iVar3 = *piVar1 + (g_currentNodeIdx);
  g_eventQueueWorkType = iVar3;
  if ((g_currentNodeIdx) < iVar3) {
    do {
      while( true ) {
        g_walkCallback = *MK4_NODE(uint, (g_currentNodeIdx));
        (g_currentNodeIdx) = (g_currentNodeIdx) + 1;
        if (-1 < (int)g_walkCallback) break;
LAB_00407bae:
        g_eq = (uint)((g_currentNodeIdx) < iVar3);
        g_eventQueuePending = g_eventQueuePending + 1;
        if ((g_eq == 0) || (g_dualD = g_dualD + -1, g_dualD < 0))
        goto LAB_00407be5;
      }
      g_eq = (uint)(g_walkCallback == 0);
      g_dualC = g_walkCallback;
      if (g_eq == 0) {
        uVar2 = MK4_NODE_AT(uint, g_walkCallback, 0x20);
        g_dualC = g_walkCallback + 0xf;
        g_xformScratch94 = uVar2 & 0x100;
        g_walkCallback = uVar2;
        if (g_xformScratch94 != 0) {
          g_walkCallback = MK4_NODE_AT(uint, g_eventQueuePending, 0);
          ExtractBitsToVec3();
          iVar3 = g_eventQueueWorkType;
          if (g_framePauseFlag != 0) {
            return;
          }
          goto LAB_00407bae;
        }
      }
    } while ((g_currentNodeIdx) < iVar3);
  }
LAB_00407be5:
  g_dualD = *MK4_NODE(undefined4, (int)g_matrixStackTop);
  g_matrixStackTop = g_matrixStackTop + -1;
  return;
}
#else
__declspec(naked) void BootChainStreamWalkExtract(void)
{
    __asm
    {
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_eventQueueTotal]
        inc     eax
        push    esi
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4], ecx
        mov     edx, dword ptr [g_pendingNodeType]
        mov     ecx, dword ptr [g_currentNodeIdx]
        dec     edx
        mov     dword ptr [g_eventQueueTotal], edx
        mov     esi, dword ptr [ecx*4]
        inc     ecx
        add     esi, ecx
        mov     dword ptr [g_currentNodeIdx], ecx
        cmp     esi, ecx
        mov     dword ptr [g_eventQueueWorkType], esi
        jle     L_7ae_pop1
    L_7ae_loop:
        mov     eax, dword ptr [ecx*4]
        inc     ecx
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [g_currentNodeIdx], ecx
        jl      short L_7ae_neg
        xor     edx, edx
        mov     dword ptr [g_pendingNodeType], eax
        test    eax, eax
        sete    dl
        test    edx, edx
        mov     dword ptr [g_eq], edx
        jne     L_7ae_loopTest
        mov     eax, dword ptr [eax*4 + 0x20]
        mov     edx, dword ptr [g_pendingNodeType]
        mov     dword ptr [g_walkCallback], eax
        add     edx, 0xf
        and     eax, 0x100
        mov     dword ptr [g_pendingNodeType], edx
        mov     dword ptr [g_xformScratch94], eax
        je      short L_7ae_loopTest
        mov     eax, dword ptr [g_xformEntityIdx]
        mov     ecx, dword ptr [eax*4]
        mov     dword ptr [g_walkCallback], ecx
        call    ExtractBitsToVec3
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_7ae_justRet
        mov     esi, dword ptr [g_eventQueueWorkType]
        mov     ecx, dword ptr [g_currentNodeIdx]
    L_7ae_neg:
        mov     edx, dword ptr [g_xformEntityIdx]
        xor     eax, eax
        cmp     esi, ecx
        setg    al
        inc     edx
        mov     dword ptr [g_eq], eax
        test    eax, eax
        mov     dword ptr [g_xformEntityIdx], edx
        je      short L_7ae_pop1
        mov     eax, dword ptr [g_eventQueueTotal]
        dec     eax
        mov     dword ptr [g_eventQueueTotal], eax
        js      short L_7ae_pop1
        jmp     L_7ae_loop
    L_7ae_loopTest:
        cmp     esi, ecx
        jg      L_7ae_loop
    L_7ae_pop1:
        mov     eax, dword ptr [g_matrixStackTop]
        mov     edx, dword ptr [eax*4]
        dec     eax
        mov     dword ptr [g_eventQueueTotal], edx
        mov     dword ptr [g_matrixStackTop], eax
    L_7ae_justRet:
        pop     esi
        ret
    }
}
#endif
