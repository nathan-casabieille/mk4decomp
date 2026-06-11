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

extern unsigned int g_audioBank2State;
extern unsigned int g_audioStreamState;
extern void InstallSelfStackReset(void);
extern void ScaledInitOrSelfPtr_InstallSelfStackReset(void);

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void DualCounterPhaseGateInstall(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = g_baseSel * 4;
  iVar1 = *(int *)(iVar2 + 0x84);
  *(undefined4 *)(iVar2 + 0x84) = 0;
  if (iVar1 == 0) {
    g_eventQueuePending = *MK4_NODE(undefined4, (int)g_matrixStackTop);
    g_matrixStackTop = g_matrixStackTop + -1;
    (g_currentNodeIdx) = MK4_NODE_AT(int, g_baseSel, 4);
    iVar1 = g_baseSel * 4;
    *MK4_NODE(undefined4, (g_currentNodeIdx)) = g_eventQueuePending;
    *(int *)(iVar1 + 4) = (g_currentNodeIdx) + 1;
    g_walkCallback = 0;
    g_audioBank2State = 0;
    g_eventQueueChild = 0x3c;
    iVar1 = g_eventQueueChild;
LAB_00421e9e:
    g_eventQueueChild = iVar1;
    *(code **)(iVar2 + 8) = DualCounterPhaseGateInstall;
    MK4_NODE_AT(undefined4, g_baseSel, 0x84) = 1;
    (g_currentNodeIdx) = *(int *)(iVar2 + 4);
    *MK4_NODE(undefined4, (g_currentNodeIdx)) = 0x1421d50;
    (g_currentNodeIdx) = (g_currentNodeIdx) + 1;
    *(int *)(iVar2 + 4) = (g_currentNodeIdx);
    MK4_NODE_AT(undefined4, g_baseSel, 0x84) = 0;
    ScaledInitOrSelfPtr_InstallSelfStackReset();
    g_framePauseFlag = 1;
    return;
  }
  if (iVar1 == 1) {
    iVar1 = g_eventQueueChild + -1;
    if (g_eventQueueChild + -1 != 0) goto LAB_00421e9e;
    g_walkCallback = g_audioStreamState;
    if (g_audioStreamState != 0) goto LAB_00421dbf;
    g_walkCallback = 0;
    g_eventQueueChild = 0xf0;
    iVar1 = g_eventQueueChild;
  }
  else {
    g_walkCallback = g_audioBank2State;
    if (g_audioBank2State != 0) {
      InstallSelfStackReset();
      return;
    }
    iVar1 = g_eventQueueChild + -1;
    if (g_eventQueueChild + -1 == 0) {
LAB_00421dbf:
      g_eventQueueChild = g_eventQueueChild + -1;
      StackPopDispatchTagged();
      return;
    }
  }
  g_eventQueueChild = iVar1;
  g_audioBank2State = g_walkCallback;
  *(code **)(iVar2 + 8) = DualCounterPhaseGateInstall;
  MK4_NODE_AT(undefined4, g_baseSel, 0x84) = 2;
  (g_currentNodeIdx) = *(int *)(iVar2 + 4);
  *MK4_NODE(undefined4, (g_currentNodeIdx)) = 0x2421d50;
  (g_currentNodeIdx) = (g_currentNodeIdx) + 1;
  *(int *)(iVar2 + 4) = (g_currentNodeIdx);
  MK4_NODE_AT(undefined4, g_baseSel, 0x84) = 0;
  ScaledInitOrSelfPtr_InstallSelfStackReset();
  g_framePauseFlag = 1;
  return;
}
#else
__declspec(naked) void DualCounterPhaseGateInstall(void)
{
    __asm
    {
        mov     eax, dword ptr [g_baseSel]
        xor     edx, edx
        shl     eax, 2
        push    esi
        push    edi
        mov     ecx, dword ptr [eax + 0x84]
        mov     dword ptr [eax + 0x84], edx
        sub     ecx, edx
        je      L_dcpgi_phase0
        dec     ecx
        je      short L_dcpgi_phase1
        mov     ecx, dword ptr [g_audioBank2State]
        cmp     ecx, edx
        mov     dword ptr [g_walkCallback], ecx
        je      short L_dcpgi_call40
        call    InstallSelfStackReset
        pop     edi
        pop     esi
        ret
    L_dcpgi_call40:
        mov     ecx, dword ptr [g_eventQueueChild]
        dec     ecx
        mov     dword ptr [g_eventQueueChild], ecx
        je      short L_dcpgi_install
        jmp     short L_dcpgi_setup
    L_dcpgi_phase1:
        mov     ecx, dword ptr [g_eventQueueChild]
        dec     ecx
        mov     dword ptr [g_eventQueueChild], ecx
        jne     L_dcpgi_install2
        mov     ecx, dword ptr [g_audioStreamState]
        cmp     ecx, edx
        mov     dword ptr [g_walkCallback], ecx
        je      short L_dcpgi_resetSetup
    L_dcpgi_install:
        call    StackPopDispatchTagged
        pop     edi
        pop     esi
        ret
    L_dcpgi_resetSetup:
        mov     dword ptr [g_walkCallback], edx
        mov     dword ptr [g_audioBank2State], edx
        mov     dword ptr [g_eventQueueChild], 0xf0
    L_dcpgi_setup:
        mov     dword ptr [eax + 8], offset DualCounterPhaseGateInstall
        mov     ecx, dword ptr [g_baseSel]
        mov     esi, offset DualCounterPhaseGateInstall
        mov     dword ptr [ecx*4 + 0x84], 2
        mov     ecx, dword ptr [eax + 4]
        add     esi, 0x2000000
        mov     dword ptr [g_currentNodeIdx], ecx
        mov     dword ptr [ecx*4], esi
        mov     ecx, dword ptr [g_currentNodeIdx]
        inc     ecx
        mov     dword ptr [g_currentNodeIdx], ecx
        mov     dword ptr [eax + 4], ecx
        mov     eax, dword ptr [g_baseSel]
        mov     dword ptr [eax*4 + 0x84], edx
        call    ScaledInitOrSelfPtr_InstallSelfStackReset
        mov     dword ptr [g_framePauseFlag], 1
        pop     edi
        pop     esi
        ret
    L_dcpgi_phase0:
        mov     ecx, dword ptr [g_matrixStackTop]
        mov     esi, dword ptr [ecx*4]
        dec     ecx
        mov     dword ptr [g_matrixStackTop], ecx
        mov     ecx, dword ptr [g_baseSel]
        mov     dword ptr [g_xformEntityIdx], esi
        mov     edi, dword ptr [ecx*4 + 4]
        lea     ecx, [ecx*4 + 4]
        mov     dword ptr [g_currentNodeIdx], edi
        mov     dword ptr [edi*4], esi
        mov     esi, dword ptr [g_currentNodeIdx]
        inc     esi
        mov     dword ptr [g_currentNodeIdx], esi
        mov     dword ptr [ecx], esi
        mov     dword ptr [g_walkCallback], edx
        mov     dword ptr [g_audioBank2State], edx
        mov     dword ptr [g_eventQueueChild], 0x3c
    L_dcpgi_install2:
        mov     dword ptr [eax + 8], offset DualCounterPhaseGateInstall
        mov     ecx, dword ptr [g_baseSel]
        mov     esi, 1
        mov     edi, offset DualCounterPhaseGateInstall
        mov     dword ptr [ecx*4 + 0x84], esi
        mov     ecx, dword ptr [eax + 4]
        add     edi, 0x1000000
        mov     dword ptr [g_currentNodeIdx], ecx
        mov     dword ptr [ecx*4], edi
        mov     ecx, dword ptr [g_currentNodeIdx]
        inc     ecx
        mov     dword ptr [g_currentNodeIdx], ecx
        mov     dword ptr [eax + 4], ecx
        mov     eax, dword ptr [g_baseSel]
        mov     dword ptr [eax*4 + 0x84], edx
        call    ScaledInitOrSelfPtr_InstallSelfStackReset
        mov     dword ptr [g_framePauseFlag], esi
        pop     edi
        pop     esi
        ret
    }
}
#endif
