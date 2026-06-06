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

extern void Set14CallAddJmp(void);
extern void GameStateDispatch4Way(void);
extern void Push80SetWalkDualCallPop(void);
extern void Push80SetWalkNegDualCallPop(void);
extern void CjInstallSelfRouter(void);
extern void AudioVolumeRescale(void);


#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void GameStateDispatch4Way(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = g_baseSel * 4;
  uVar2 = MK4_NODE_AT(undefined4, g_baseSel, 0x84);
  *(undefined4 *)(iVar1 + 0x84) = 0;
  switch(uVar2) {
  case 0:
    Push80SetWalkDualCallPop();
    if (g_framePauseFlag != 0) {
      return;
    }
    *(code **)(iVar1 + 8) = GameStateDispatch4Way;
    MK4_NODE_AT(undefined4, g_baseSel, 0x84) = 1;
    (*(unsigned int *)MK4_VA(unsigned int, 0x542044)) = *(int *)(iVar1 + 4);
    uVar2 = 0x1436e50;
    break;
  case 1:
    Push80SetWalkNegDualCallPop();
    if (g_framePauseFlag != 0) {
      return;
    }
    *(code **)(iVar1 + 8) = GameStateDispatch4Way;
    MK4_NODE_AT(undefined4, g_baseSel, 0x84) = 2;
    (*(unsigned int *)MK4_VA(unsigned int, 0x542044)) = *(int *)(iVar1 + 4);
    uVar2 = 0x2436e50;
    break;
  case 2:
    g_walkCallback = 500;
    AudioVolumeRescale();
    if (g_framePauseFlag != 0) {
      return;
    }
    if (((byte)g_xformDirtyFlags & 1) != 0) goto switchD_00436e76_default;
    Push80SetWalkDualCallPop();
    if (g_framePauseFlag != 0) {
      return;
    }
    *(code **)(iVar1 + 8) = GameStateDispatch4Way;
    MK4_NODE_AT(undefined4, g_baseSel, 0x84) = 3;
    (*(unsigned int *)MK4_VA(unsigned int, 0x542044)) = *(int *)(iVar1 + 4);
    uVar2 = 0x3436e50;
    break;
  case 3:
    Push80SetWalkNegDualCallPop();
    if (g_framePauseFlag != 0) {
      return;
    }
    *(code **)(iVar1 + 8) = GameStateDispatch4Way;
    MK4_NODE_AT(undefined4, g_baseSel, 0x84) = 4;
    (*(unsigned int *)MK4_VA(unsigned int, 0x542044)) = *(int *)(iVar1 + 4);
    uVar2 = 0x4436e50;
    break;
  default:
switchD_00436e76_default:
    CjInstallSelfRouter();
    return;
  }
  *(undefined4 *)((*(unsigned int *)MK4_VA(unsigned int, 0x542044)) * 4) = uVar2;
  (*(unsigned int *)MK4_VA(unsigned int, 0x542044)) = (*(unsigned int *)MK4_VA(unsigned int, 0x542044)) + 1;
  *(int *)(iVar1 + 4) = (*(unsigned int *)MK4_VA(unsigned int, 0x542044));
  MK4_NODE_AT(undefined4, g_baseSel, 0x84) = 0;
  Set14CallAddJmp();
  g_framePauseFlag = 1;
  return;
}
#else
__declspec(naked) void GameStateDispatch4Way(void)
{
    __asm {
        mov      eax, dword ptr [g_baseSel]
        push     esi
        push     edi
        xor      edi, edi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], edi
        cmp      eax, 3
        ja       L_6fcd
        jmp      dword ptr [eax*4 + L_e50_jmptbl]
    L_6e7d:
        call     Push80SetWalkNegDualCallPop
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_6fd2
        mov      dword ptr [esi + 8], OFFSET GameStateDispatch4Way
        mov      ecx, dword ptr [g_baseSel]
        mov      edx, OFFSET GameStateDispatch4Way
        mov      dword ptr [ecx*4 + 0x84], 2
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_currentNodeIdx], eax
        add      edx, 0x2000000
        jmp      L_6f9a
    L_6ebe:
        mov      dword ptr [g_walkCallback], 0x1f4
        call     AudioVolumeRescale
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_6fd2
        test     byte ptr [g_xformDirtyFlags], 1
        jne      L_6fcd
        call     Push80SetWalkDualCallPop
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_6fd2
        mov      dword ptr [esi + 8], OFFSET GameStateDispatch4Way
        mov      ecx, dword ptr [g_baseSel]
        mov      edx, OFFSET GameStateDispatch4Way
        mov      dword ptr [ecx*4 + 0x84], 3
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_currentNodeIdx], eax
        add      edx, 0x3000000
        jmp      short L_6f9a
    L_6f24:
        call     Push80SetWalkNegDualCallPop
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_6fd2
        mov      dword ptr [esi + 8], OFFSET GameStateDispatch4Way
        mov      ecx, dword ptr [g_baseSel]
        mov      edx, OFFSET GameStateDispatch4Way
        mov      dword ptr [ecx*4 + 0x84], 4
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_currentNodeIdx], eax
        add      edx, 0x4000000
        jmp      short L_6f9a
    L_6f62:
        call     Push80SetWalkDualCallPop
        cmp      dword ptr [g_framePauseFlag], edi
        jne      short L_6fd2
        mov      dword ptr [esi + 8], OFFSET GameStateDispatch4Way
        mov      ecx, dword ptr [g_baseSel]
        mov      edx, OFFSET GameStateDispatch4Way
        mov      dword ptr [ecx*4 + 0x84], 1
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_currentNodeIdx], eax
        add      edx, 0x1000000
    L_6f9a:
        mov      dword ptr [eax*4], edx
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      eax, dword ptr [g_baseSel]
        mov      dword ptr [eax*4 + 0x84], edi
        call     Set14CallAddJmp
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        ret
    L_6fcd:
        call     CjInstallSelfRouter
    L_6fd2:
        pop      edi
        pop      esi
        ret
        /* 3-byte align nop `lea ecx, [ecx]` = 8d 49 00 */
        _emit    0x8d
        _emit    0x49
        _emit    0x00
    L_e50_jmptbl:
        _emit    0x62
        _emit    0x6f
        _emit    0x43
        _emit    0x00
        _emit    0x7d
        _emit    0x6e
        _emit    0x43
        _emit    0x00
        _emit    0xbe
        _emit    0x6e
        _emit    0x43
        _emit    0x00
        _emit    0x24
        _emit    0x6f
        _emit    0x43
        _emit    0x00
    }
}
#endif
