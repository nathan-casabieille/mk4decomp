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

/* @addr 0x00462470 (230b game) - install-self with full chain init.
 *   chain[+0x84]!=0 path: call StackPopDispatchTagged; pop+ret.
 *   chain[+0x84]==0 path: chain[*4+0x30]=0x8c, chain[*4+0x34]=0; chain at [esi+0x38..0x48] populated from
 *   g_eventQueueSeed fields (+0x60, 0, +0x68); install-self at +0x08=0x00462470 with scaledInit-chain push;
 *   call PendingMatch_ThreeMul10Stores; g_pause=1; pop+ret.
 */
extern unsigned int g_eventQueueSeed;
extern void PendingMatch_ThreeMul10Stores(void);

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void InstallSelfFullChainInit(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = g_baseSel * 4;
  iVar3 = MK4_NODE_AT(int, g_baseSel, 0x84);
  *(undefined4 *)(iVar1 + 0x84) = 0;
  iVar2 = g_baseSel;
  if (iVar3 != 0) {
    StackPopDispatchTagged();
    return;
  }
  MK4_NODE_AT(undefined4, g_baseSel, 0x30) = 0x8c;
  iVar2 = iVar2 * 4;
  MK4_NODE_AT(undefined4, g_baseSel, 0x34) = 0;
  *(undefined4 *)(iVar2 + 0x38) = 0xfffe0000;
  *(undefined4 *)(iVar2 + 0x3c) = 0xfff5cccd;
  g_cj_0054205c = g_eventQueueSeed;
  iVar3 = g_eventQueueSeed * 4;
  *(undefined4 *)(iVar2 + 0x40) = *(undefined4 *)(iVar3 + 0x60);
  *(undefined4 *)(iVar2 + 0x44) = 0;
  g_walkCallback = *(undefined4 *)(iVar3 + 0x68);
  *(undefined4 *)(iVar2 + 0x48) = g_walkCallback;
  *(code **)(iVar1 + 8) = InstallSelfFullChainInit;
  MK4_NODE_AT(undefined4, g_baseSel, 0x84) = 1;
  (g_currentNodeIdx) = *(int *)(iVar1 + 4);
  *MK4_NODE(undefined4, (g_currentNodeIdx)) = 0x1462470;
  (g_currentNodeIdx) = (g_currentNodeIdx) + 1;
  *(int *)(iVar1 + 4) = (g_currentNodeIdx);
  MK4_NODE_AT(undefined4, g_baseSel, 0x84) = 0;
  PendingMatch_ThreeMul10Stores();
  g_framePauseFlag = 1;
  return;
}
#else
__declspec(naked) void InstallSelfFullChainInit(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel]
        push    esi
        xor     esi, esi
        lea     ecx, [eax*4 + 0]
        mov     eax, dword ptr [eax*4 + 0x84]
        mov     dword ptr [ecx + 0x84], esi
        cmp     eax, esi
        _emit   74h
        _emit   07h
        call    StackPopDispatchTagged
        pop     esi
        ret
        mov     edx, dword ptr [g_baseSel]
        mov     dword ptr [edx*4 + 0x30], 0x0000008c
        push    edi
        lea     eax, [edx*4 + 0]
        mov     edx, dword ptr [g_baseSel]
        mov     dword ptr [edx*4 + 0x34], esi
        mov     edx, 0xfff5cccd
        mov     dword ptr [eax + 0x38], 0xfffe0000
        mov     dword ptr [g_walkCallback], edx
        mov     dword ptr [eax + 0x3c], edx
        mov     edx, dword ptr [g_eventQueueSeed]
        mov     dword ptr [g_fightGroupHead], edx
        shl     edx, 2
        mov     edi, dword ptr [edx + 0x60]
        mov     dword ptr [eax + 0x40], edi
        mov     dword ptr [g_walkCallback], esi
        mov     dword ptr [eax + 0x44], esi
        mov     edx, dword ptr [edx + 0x68]
        mov     dword ptr [g_walkCallback], edx
        mov     dword ptr [eax + 0x48], edx
        mov     dword ptr [ecx + 0x08], 0x00462470
        mov     eax, dword ptr [g_baseSel]
        mov     edi, 1
        mov     edx, 0x00462470
        mov     dword ptr [eax*4 + 0x84], edi
        mov     eax, dword ptr [ecx + 4]
        add     edx, 0x01000000
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [eax*4 + 0], edx
        mov     eax, dword ptr [g_currentNodeIdx]
        inc     eax
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [ecx + 4], eax
        mov     eax, dword ptr [g_baseSel]
        mov     dword ptr [eax*4 + 0x84], esi
        call    PendingMatch_ThreeMul10Stores
        mov     dword ptr [g_framePauseFlag], edi
        pop     edi
        pop     esi
        ret
    }
}
#endif
