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
 * BootChainMaskAndDispatch - 250b boot 2-body chain dispatch.
 *   Entry 0x00416cb0: g_walkCallback=2; DirtyDoubleDeref; if paused or g_currentNodeIdx==0: ret.
 *     chain[+0x20] &= 0xfffffffb; g_walkCallback=-0x14; MStackInitCallToggle; if paused: ret.
 *     If !(g_xformDirtyFlags & 4): MStackBracket2_TreeWalkRecursive; if paused: ret.
 *     g_walkCallback=-0x16; MStackInitCallToggle; if paused: ret. If !(g_xformDirtyFlags & 4):
 *       tail-jmp MStackBracket2_TreeWalkRecursive. Ret.
 *   Entry 0x00416d40 (16b-aligned): g_walkCallback=-0x14; MStackInitCallToggle; if paused: ret.
 *     If !(g_xformDirtyFlags & 4): chain[+0x3c] = 0x00800000. g_walkCallback=-0x15;
 *     MStackInitCallToggle; if paused: ret. If !(g_xformDirtyFlags & 4):
 *       chain[+0x3c] = -0x16666 = g_walkCallback; ret.
 */
extern void DirtyDoubleDeref(void);
extern void MStackBracket2_TreeWalkRecursive(void);
extern void MStackInitCallToggle(void);

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void BootChainMaskAndDispatch(void)

{
  g_walkCallback = 2;
  DirtyDoubleDeref();
  if ((g_framePauseFlag == 0) && ((*(unsigned int *)MK4_VA(unsigned int, 0x542044)) != 0)) {
    *(uint *)((*(unsigned int *)MK4_VA(unsigned int, 0x542044)) * 4 + 0x20) = *(uint *)((*(unsigned int *)MK4_VA(unsigned int, 0x542044)) * 4 + 0x20) & 0xfffffffb;
    g_walkCallback = 0xffffffec;
    MStackInitCallToggle();
    if (g_framePauseFlag == 0) {
      if ((((byte)g_xformDirtyFlags & 4) == 0) && (MStackBracket2_TreeWalkRecursive(), g_framePauseFlag != 0)) {
        return;
      }
      g_walkCallback = 0xffffffea;
      MStackInitCallToggle();
      if ((g_framePauseFlag == 0) && (((byte)g_xformDirtyFlags & 4) == 0)) {
        MStackBracket2_TreeWalkRecursive();
        return;
      }
    }
  }
  return;
}
#else
__declspec(naked) void BootChainMaskAndDispatch(void)
{
    __asm
    {
        mov     dword ptr [g_walkCallback], 2
        call    DirtyDoubleDeref
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_b1_ret
        mov     eax, dword ptr [g_currentNodeIdx]
        test    eax, eax
        je      short L_b1_ret
        mov     ecx, dword ptr [eax*4 + 0x20]
        and     ecx, 0xfffffffb
        mov     dword ptr [eax*4 + 0x20], ecx
        mov     dword ptr [g_walkCallback], 0xffffffec
        call    MStackInitCallToggle
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_b1_ret
        test    byte ptr [g_xformDirtyFlags], 4
        jne     short L_b1_callMid
        call    MStackBracket2_TreeWalkRecursive
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_b1_ret
    L_b1_callMid:
        mov     dword ptr [g_walkCallback], 0xffffffea
        call    MStackInitCallToggle
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_b1_ret
        test    byte ptr [g_xformDirtyFlags], 4
        jne     short L_b1_ret
        jmp     MStackBracket2_TreeWalkRecursive
    L_b1_ret:
        ret
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        mov     dword ptr [g_walkCallback], 0xffffffec
        call    MStackInitCallToggle
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_b2_ret
        test    byte ptr [g_xformDirtyFlags], 4
        jne     short L_b2_step2
        mov     eax, dword ptr [g_currentNodeIdx]
        mov     dword ptr [eax*4 + 0x3c], 0x00008000
    L_b2_step2:
        mov     dword ptr [g_walkCallback], 0xffffffeb
        call    MStackInitCallToggle
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_b2_ret
        test    byte ptr [g_xformDirtyFlags], 4
        jne     short L_b2_ret
        mov     ecx, dword ptr [g_currentNodeIdx]
        mov     eax, 0xfffe999a
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x3c], eax
    L_b2_ret:
        ret
    }
}
#endif
