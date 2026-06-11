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

extern unsigned int g_dispatchSave60;
extern unsigned int g_installOwner2;
extern void ArgSarStoreJmp(void);
extern void DoubleCallChainInit(void);
extern void EsiInstallSetCbChainExtend_0048a970(void);
extern void InstallSelfChainAccumPath(void);
extern void PendingMatch_MStackPush2LLWalkCompare(void);
extern void StoreLoadJmp(void);
extern void Thunk_ScaledNeg1SetPause(void);
extern void VersusScreenFsmCluster(void);

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void DualSubInstallChain(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = g_baseSel * 4;
  iVar1 = *(int *)(iVar2 + 0x84);
  *(undefined4 *)(iVar2 + 0x84) = 0;
  if (iVar1 != 0) {
    thunk_ScaledNeg1SetPause();
    return;
  }
  g_eventQueueNotMask = 0;
  g_cj_00542054 = g_installOwner2;
  *(code **)(iVar2 + 8) = DualSubInstallChain;
  MK4_NODE_AT(undefined4, g_baseSel, 0x84) = 1;
  (g_currentNodeIdx) = *(int *)(iVar2 + 4);
  *MK4_NODE(undefined4, (g_currentNodeIdx)) = 0x144f4b0;
  (g_currentNodeIdx) = (g_currentNodeIdx) + 1;
  *(int *)(iVar2 + 4) = (g_currentNodeIdx);
  MK4_NODE_AT(undefined4, g_baseSel, 0x84) = 0;
  EsiInstallSetCbChainExtend_0048a970();
  g_framePauseFlag = 1;
  return;
}
#else
__declspec(naked) void DualSubInstallChain(void)
{
    __asm
    {
        mov     eax, dword ptr [g_baseSel]
        xor     edx, edx
        shl     eax, 2
        mov     ecx, dword ptr [eax + 0x84]
        mov     dword ptr [eax + 0x84], edx
        cmp     ecx, edx
        je      short L_dsic_install1
        jmp     Thunk_ScaledNeg1SetPause
    L_dsic_install1:
        mov     ecx, dword ptr [g_installOwner2]
        mov     dword ptr [g_eventQueueNotMask], edx
        mov     dword ptr [g_eventQueueEnd], ecx
        mov     dword ptr [eax + 8], offset DualSubInstallChain
        mov     ecx, dword ptr [g_baseSel]
        push    edi
        mov     edi, offset DualSubInstallChain
        mov     dword ptr [ecx*4 + 0x84], 1
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
        call    EsiInstallSetCbChainExtend_0048a970
        mov     dword ptr [g_framePauseFlag], 1
        pop     edi
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
        nop
    L_dsic_sub2:
        mov     eax, dword ptr [g_baseSel]
        push    esi
        lea     esi, [eax*4]
        mov     eax, dword ptr [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], 0
        test    eax, eax
        je      short L_dsic_sub2_phase0
        call    PendingMatch_MStackPush2LLWalkCompare
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_dsic_sub2_ret
        push    0x4e6f40
        call    ArgSarStoreJmp
        mov     eax, dword ptr [g_framePauseFlag]
        add     esp, 4
        pop     esi
        ret
    L_dsic_sub2_phase0:
        push    0x44fef0
        call    StoreLoadJmp
        add     esp, 4
        push    0x91
        push    0x450360
        call    StoreTwoCall
        mov     ecx, dword ptr [g_eventQueueIdx]
        add     esp, 8
        mov     dword ptr [g_fightGroupHead], ecx
        call    DoubleCallChainInit
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_dsic_sub2_ret
        mov     edx, offset g_dispatchSave60
        mov     ecx, offset L_dsic_sub2
        shr     edx, 2
        mov     dword ptr [g_eventQueueEnd], edx
        mov     dword ptr [esi + 8], offset L_dsic_sub2
        mov     eax, dword ptr [g_baseSel]
        add     ecx, 0x1000000
        mov     dword ptr [eax*4 + 0x84], 1
        mov     eax, dword ptr [esi + 4]
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [eax*4], ecx
        mov     eax, dword ptr [g_currentNodeIdx]
        inc     eax
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [esi + 4], eax
        mov     edx, dword ptr [g_baseSel]
        mov     dword ptr [edx*4 + 0x84], 0
        call    InstallSelfChainAccumPath
        mov     dword ptr [g_framePauseFlag], 1
    L_dsic_sub2_ret:
        pop     esi
        ret
    L_dsic_sub3:
        push    0x91
        push    0x44fe40
        call    StoreTwoCall
        add     esp, 8
        mov     dword ptr [g_eventQueueEnd], 0xd
        jmp     VersusScreenFsmCluster
    }
}
#endif
