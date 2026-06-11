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

extern unsigned int g_dispatchSave706;
extern unsigned int g_dispatchSave710;
extern void AudioMixerStep(void);
extern void PendingMatch_AudioMixerStep_00473640(void);
extern void ScaledStoreThree_00409260(void);
extern void StoreDoubleNegPauseSubStore(void);

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void SizeGateInstallSelfThenSubMul10(void)

{
  undefined4 uVar1;
  int iVar2;
  
  if (g_chainAccumCur <= MK4_NODE_AT(int, (g_currentNodeIdx), 0x1c)) {
    g_eventQueuePending = MK4_NODE_AT(int, (g_currentNodeIdx), 0x28);
    MK4_NODE_AT(undefined4, g_eventQueuePending, 0x20) = MK4_NODE_AT(undefined4, (g_currentNodeIdx), 0x3c);
    g_walkCallback = *(code **)((g_currentNodeIdx) * 4 + 0x40);
    if (g_walkCallback != (code *)0x0) {
      uVar1 = Mul10Tail(0x1999,g_walkCallback);
      MK4_NODE_AT(undefined4, g_eventQueuePending, 0x48) = uVar1;
      MK4_NODE_AT(uint, g_eventQueuePending, 0) = MK4_NODE_AT(uint, g_eventQueuePending, 0) | 8;
    }
    g_walkCallback = (code *)0x10000;
    StoreDoubleNegPauseSubStore();
    if (g_framePauseFlag != 0) {
      return;
    }
    *(code **)(g_eventQueuePending * 4 + 0x18) = g_walkCallback;
    g_walkCallback = (code *)0xccc;
    AudioMixerStep();
    if (g_framePauseFlag != 0) {
      return;
    }
    MK4_NODE_AT(int, g_eventQueuePending, 0x1c) = (int)g_walkCallback + 0xccc;
    iVar2 = (g_currentNodeIdx) * 4;
    *(undefined4 *)(iVar2 + 0x3c) = 0;
    *(undefined4 *)(iVar2 + 0x40) = 0;
    *(undefined4 *)(iVar2 + 0x44) = 0;
    g_walkCallback = (code *)0x13b30e;
    ScaledStoreThree_00409260();
    if (g_framePauseFlag != 0) {
      return;
    }
    MK4_NODE_AT(undefined4, g_eventQueuePending, 0x10) = 0;
    MK4_NODE_AT(undefined4, g_eventQueuePending, 0x14) = 0x13b254;
  }
  g_walkCallback = *(code **)((g_currentNodeIdx) * 4 + 0xc);
  if (g_walkCallback != (code *)0x0) {
    g_walkCallback = SizeGateInstallSelfThenSubMul10;
    Helper_TickAlt();
    if (g_framePauseFlag != 0) {
      return;
    }
  }
  g_xformDirtyFlags = g_xformDirtyFlags & 0xfffffffe;
  return;
}
#else
__declspec(naked) void SizeGateInstallSelfThenSubMul10(void)
{
    __asm
    {
        mov     eax, dword ptr [g_currentNodeIdx]
        mov     edx, dword ptr [g_chainAccumCur]
        push    esi
        xor     esi, esi
        mov     ecx, dword ptr [eax*4 + 0x1c]
        cmp     ecx, edx
        mov     dword ptr [g_walkCallback], ecx
        jl      L_sgis_lateTail
        mov     ecx, dword ptr [eax*4 + 0x28]
        mov     dword ptr [g_xformEntityIdx], ecx
        mov     eax, dword ptr [eax*4 + 0x3c]
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x20], eax
        mov     eax, dword ptr [g_currentNodeIdx]
        mov     eax, dword ptr [eax*4 + 0x40]
        cmp     eax, esi
        mov     dword ptr [g_walkCallback], eax
        je      short L_sgis_after40
        push    eax
        push    0x1999
        call    Mul10Tail
        mov     ecx, dword ptr [g_xformEntityIdx]
        mov     dword ptr [g_walkCallback], eax
        add     esp, 8
        mov     dword ptr [ecx*4 + 0x48], eax
        mov     eax, dword ptr [g_xformEntityIdx]
        or      dword ptr [eax*4], 8
    L_sgis_after40:
        mov     dword ptr [g_walkCallback], 0x10000
        call    StoreDoubleNegPauseSubStore
        cmp     dword ptr [g_framePauseFlag], esi
        jne     L_sgis_ret
        mov     eax, dword ptr [g_xformEntityIdx]
        mov     edx, dword ptr [g_walkCallback]
        mov     dword ptr [eax*4 + 0x18], edx
        mov     dword ptr [g_walkCallback], 0xccc
        call    AudioMixerStep
        cmp     dword ptr [g_framePauseFlag], esi
        jne     L_sgis_ret
        mov     ecx, dword ptr [g_walkCallback]
        mov     edx, dword ptr [g_xformEntityIdx]
        add     ecx, 0xccc
        mov     dword ptr [edx*4 + 0x1c], ecx
        mov     eax, dword ptr [g_currentNodeIdx]
        shl     eax, 2
        mov     ecx, offset g_dispatchSave710
        shr     ecx, 2
        mov     dword ptr [eax + 0x3c], esi
        mov     dword ptr [eax + 0x40], esi
        mov     dword ptr [eax + 0x44], esi
        mov     dword ptr [g_walkCallback], ecx
        call    ScaledStoreThree_00409260
        cmp     dword ptr [g_framePauseFlag], esi
        jne     short L_sgis_ret
        mov     edx, dword ptr [g_xformEntityIdx]
        mov     eax, offset g_dispatchSave706
        shr     eax, 2
        mov     dword ptr [edx*4 + 0x10], esi
        mov     ecx, dword ptr [g_xformEntityIdx]
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x14], eax
        mov     eax, dword ptr [g_currentNodeIdx]
    L_sgis_lateTail:
        mov     eax, dword ptr [eax*4 + 0xc]
        cmp     eax, esi
        mov     dword ptr [g_walkCallback], eax
        je      short L_sgis_clear
        mov     dword ptr [g_walkCallback], offset SizeGateInstallSelfThenSubMul10
        call    Helper_TickAlt
        cmp     dword ptr [g_framePauseFlag], esi
        jne     short L_sgis_ret
    L_sgis_clear:
        mov     eax, dword ptr [g_xformDirtyFlags]
        and     al, 0xfe
        mov     dword ptr [g_xformDirtyFlags], eax
    L_sgis_ret:
        pop     esi
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
    L_sgis_sub2:
        mov     eax, dword ptr [g_xformEntityIdx]
        mov     eax, dword ptr [eax*4 + 0x48]
        push    eax
        push    0x13f35
        mov     dword ptr [g_walkCallback], eax
        call    Mul10Tail
        mov     ecx, dword ptr [g_xformEntityIdx]
        mov     dword ptr [g_walkCallback], eax
        add     esp, 8
        mov     dword ptr [ecx*4 + 0x48], eax
        jmp     PendingMatch_AudioMixerStep_00473640
    }
}
#endif
