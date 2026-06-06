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

/* @addr 0x0043a830 (286b game) - scaled-step + threshold cmp + install-self.
 *   Load idx=g_baseSel; entry=ecx=*idx*4; state=[idx*4+0x84]; clear state.
 *   state==0: clear-and-init path; copy [idx*4+0x58], [g_chainAccumCur]; fall to install.
 *   state!=0: bump [g_eventQueueEnd*4 + 0x70] by 0x3d7; compare with [g_baseSel*4 + 0x5c].
 *     if eax<edx: jump to install (state stays 1).
 *     else: clear scaledInit fields; tail-call StackPopDispatchTagged.
 *   install: state=1; [ecx+8]=self; g_pendingNodeType=1; g_pause=1; ret.
 */

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void InstallSelfScaledAdv3d7Cmp(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = g_baseSel * 4;
  iVar2 = MK4_NODE_AT(int, g_baseSel, 0x84);
  *(undefined4 *)(iVar1 + 0x84) = 0;
  if (iVar2 == 0) {
    g_walkCallback = MK4_NODE_AT(int, g_cj_00542054, 0x58);
    MK4_NODE_AT(int, g_baseSel, 0x5c) = g_walkCallback;
    MK4_NODE_AT(undefined4, g_cj_00542054, 0x70) = g_chainAccumCur;
  }
  else {
    MK4_NODE_AT(int, g_cj_00542054, 0x70) = MK4_NODE_AT(int, g_cj_00542054, 0x70) + 0x3d7;
    g_walkCallback = MK4_NODE_AT(int, g_cj_00542054, 0x58);
    g_eventQueueCurrent = MK4_NODE_AT(int, g_baseSel, 0x5c);
    if (g_eventQueueCurrent <= g_walkCallback) {
      g_walkCallback = 0;
      MK4_NODE_AT(undefined4, g_cj_00542054, 0x6c) = 0;
      MK4_NODE_AT(int, g_cj_00542054, 0x70) = g_walkCallback;
      MK4_NODE_AT(int, g_cj_00542054, 0x74) = g_walkCallback;
      g_walkCallback = MK4_NODE_AT(undefined4, g_baseSel, 0x5c);
      MK4_NODE_AT(int, g_cj_00542054, 0x58) = g_walkCallback;
      StackPopDispatchTagged();
      return;
    }
  }
  *(code **)(iVar1 + 8) = InstallSelfScaledAdv3d7Cmp;
  *(undefined4 *)(iVar1 + 0x84) = 1;
  g_dualC = 1;
  g_framePauseFlag = 1;
  return;
}
#else
__declspec(naked) void InstallSelfScaledAdv3d7Cmp(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel]
        push    esi
        lea     ecx, [eax*4 + 0]
        mov     eax, dword ptr [eax*4 + 0x84]
        mov     dword ptr [ecx + 0x84], 0
        test    eax, eax
        je      case0
        mov     edx, dword ptr [g_eventQueueEnd]
        mov     eax, dword ptr [edx*4 + 0x70]
        add     eax, 0x3d7
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [edx*4 + 0x70], eax
        mov     esi, dword ptr [g_eventQueueEnd]
        mov     edx, dword ptr [g_baseSel]
        mov     eax, dword ptr [esi*4 + 0x58]
        mov     dword ptr [g_walkCallback], eax
        mov     edx, dword ptr [edx*4 + 0x5c]
        cmp     eax, edx
        mov     dword ptr [g_eventQueueCurrent], edx
        jl      install
        mov     dword ptr [g_walkCallback], 0
        mov     dword ptr [esi*4 + 0x6c], 0
        mov     ecx, dword ptr [g_eventQueueEnd]
        mov     eax, dword ptr [g_walkCallback]
        mov     dword ptr [ecx*4 + 0x70], eax
        mov     eax, dword ptr [g_eventQueueEnd]
        mov     edx, dword ptr [g_walkCallback]
        mov     dword ptr [eax*4 + 0x74], edx
        mov     ecx, dword ptr [g_baseSel]
        mov     edx, dword ptr [g_eventQueueEnd]
        mov     eax, dword ptr [ecx*4 + 0x5c]
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [edx*4 + 0x58], eax
        call    StackPopDispatchTagged
        pop     esi
        ret
    case0:
        mov     eax, dword ptr [g_eventQueueEnd]
        mov     edx, dword ptr [g_baseSel]
        mov     eax, dword ptr [eax*4 + 0x58]
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [edx*4 + 0x5c], eax
        mov     eax, dword ptr [g_eventQueueEnd]
        mov     edx, dword ptr [g_chainAccumCur]
        mov     dword ptr [eax*4 + 0x70], edx
    install:
        mov     eax, 1
        mov     dword ptr [ecx + 8], offset InstallSelfScaledAdv3d7Cmp
        mov     dword ptr [ecx + 0x84], eax
        mov     dword ptr [g_pendingNodeType], eax
        mov     dword ptr [g_framePauseFlag], eax
        pop     esi
        ret
    }
}
#endif
