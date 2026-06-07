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

extern unsigned int g_dispatchSave105;
extern void NodeUnlink(void);

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void BootScheduledNodeTimerWalk(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = g_extra_0052ab3c;
  do {
    while( true ) {
      if (iVar2 == 0) {
        g_framePauseFlag = 0;
        return;
      }
      if (((g_gameMode == 0) || (g_gameMode == *(int *)(iVar2 + 0xd8))) ||
         (*(int *)(iVar2 + 0xe0) == 0x11)) break;
LAB_0041f6ef:
      iVar2 = *(int *)(iVar2 + 0xe4);
    }
    *(short *)(iVar2 + 0xdc) = *(short *)(iVar2 + 0xdc) + -1;
    if (*(short *)(iVar2 + 0xdc) < 1) {
      g_baseSel = iVar2 >> 2;
      g_eventQueueNotMask = MK4_NODE_AT(undefined4, g_baseSel, 0x14);
      g_eventQueueChild = MK4_NODE_AT(undefined4, g_baseSel, 0x18);
      g_cj_00542054 = MK4_NODE_AT(undefined4, g_baseSel, 0x24);
      g_cj_00542058 = MK4_NODE_AT(undefined4, g_baseSel, 0x28);
      g_walkCallback = MK4_NODE_AT(undefined4, g_baseSel, 8);
      g_cj_0054205c = MK4_NODE_AT(undefined4, g_baseSel, 0x2c);
      g_currentNodeFlags = MK4_NODE_AT(undefined4, g_baseSel, 0x1c);
      g_xformScratch2088 = MK4_NODE_AT(undefined4, g_baseSel, 0x20);
      *(undefined4 *)(iVar2 + 0xd8) = MK4_NODE_AT(undefined4, g_baseSel, 8);
      g_framePauseFlag = 0;
      g_dispatchSave105 = *(undefined4 *)(iVar2 + 0xd8);
      (*(MK4ComMethod *)(iVar2 + 0xd8))();
      if ((*(int *)(iVar2 + 0xd8) != -1) && (*(int *)(iVar2 + 0xd8) != 0)) {
        *(undefined4 *)(iVar2 + 0xd8) = MK4_NODE_AT(undefined4, g_baseSel, 8);
        iVar1 = g_baseSel * 4;
        *(undefined4 *)(iVar1 + 0x14) = g_eventQueueNotMask;
        *(undefined4 *)(iVar1 + 0x18) = g_eventQueueChild;
        *(undefined4 *)(iVar1 + 0x1c) = g_currentNodeFlags;
        *(undefined4 *)(iVar1 + 0x20) = g_xformScratch2088;
        *(undefined4 *)(iVar1 + 0x10) = g_dualC;
        *(undefined4 *)(iVar1 + 0x24) = g_cj_00542054;
        *(undefined4 *)(iVar1 + 0x28) = g_cj_00542058;
        *(undefined4 *)(iVar1 + 0x2c) = g_cj_0054205c;
        *(undefined2 *)(iVar2 + 0xdc) = (undefined2)g_dualC;
      }
    }
    if (*(int *)(iVar2 + 0xd8) != -1) goto LAB_0041f6ef;
    iVar1 = *(int *)(iVar2 + 0xe4);
    NodeUnlink(iVar2);
    iVar2 = iVar1;
  } while( true );
}
#else
__declspec(naked) void BootScheduledNodeTimerWalk(void)
{
    __asm
    {
        push    ebx
        push    esi
        mov     esi, dword ptr [g_nodeListTail]
        xor     ebx, ebx
        cmp     esi, ebx
        je      L_bsntw_done
        push    edi
        push    ebp
        or      ebp, 0xffffffff
    L_bsntw_loop:
        mov     eax, dword ptr [g_gameMode]
        cmp     eax, ebx
        je      short L_bsntw_proc
        cmp     eax, dword ptr [esi + 0xd8]
        je      short L_bsntw_proc
        cmp     dword ptr [esi + 0xe0], 0x11
        jne     L_bsntw_nextNode
    L_bsntw_proc:
        dec     word ptr [esi + 0xdc]
        cmp     word ptr [esi + 0xdc], bx
        jg      L_bsntw_checkDead
        mov     eax, esi
        sar     eax, 2
        mov     dword ptr [g_baseSel], eax
        mov     ecx, dword ptr [eax*4 + 0x14]
        mov     dword ptr [g_eventQueueNotMask], ecx
        mov     edx, dword ptr [eax*4 + 0x18]
        mov     dword ptr [g_eventQueueChild], edx
        mov     ecx, dword ptr [eax*4 + 0x24]
        mov     dword ptr [g_eventQueueEnd], ecx
        mov     edx, dword ptr [eax*4 + 0x28]
        mov     dword ptr [g_eventQueueIdx], edx
        mov     ecx, dword ptr [eax*4 + 8]
        mov     dword ptr [g_walkCallback], ecx
        mov     edx, dword ptr [eax*4 + 0x2c]
        mov     dword ptr [g_fightGroupHead], edx
        mov     ecx, dword ptr [eax*4 + 0x1c]
        mov     dword ptr [g_currentNodeFlags], ecx
        mov     edx, dword ptr [eax*4 + 0x20]
        mov     dword ptr [g_xformScratch2088], edx
        mov     eax, dword ptr [eax*4 + 8]
        mov     dword ptr [esi + 0xd8], eax
        mov     dword ptr [g_framePauseFlag], ebx
        mov     ecx, dword ptr [esi + 0xd8]
        mov     dword ptr [g_dispatchSave105], ecx
        call    dword ptr [esi + 0xd8]
        mov     eax, dword ptr [esi + 0xd8]
        cmp     eax, ebp
        je      short L_bsntw_checkDead
        cmp     eax, ebx
        jbe     short L_bsntw_checkDead
        mov     edx, dword ptr [g_baseSel]
        mov     eax, dword ptr [edx*4 + 8]
        mov     dword ptr [esi + 0xd8], eax
        mov     ecx, dword ptr [g_baseSel]
        mov     edx, dword ptr [g_eventQueueNotMask]
        lea     eax, [ecx*4]
        mov     dword ptr [eax + 0x14], edx
        mov     ecx, dword ptr [g_eventQueueChild]
        mov     dword ptr [eax + 0x18], ecx
        mov     edx, dword ptr [g_currentNodeFlags]
        mov     dword ptr [eax + 0x1c], edx
        mov     ecx, dword ptr [g_xformScratch2088]
        mov     dword ptr [eax + 0x20], ecx
        mov     edx, dword ptr [g_pendingNodeType]
        mov     dword ptr [eax + 0x10], edx
        mov     ecx, dword ptr [g_eventQueueEnd]
        mov     dword ptr [eax + 0x24], ecx
        mov     edx, dword ptr [g_eventQueueIdx]
        mov     dword ptr [eax + 0x28], edx
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     dword ptr [eax + 0x2c], ecx
        mov     dx, word ptr [g_pendingNodeType]
        mov     word ptr [esi + 0xdc], dx
    L_bsntw_checkDead:
        cmp     dword ptr [esi + 0xd8], ebp
        jne     short L_bsntw_nextNode
        mov     edi, dword ptr [esi + 0xe4]
        push    esi
        call    NodeUnlink
        add     esp, 4
        mov     esi, edi
        jmp     short L_bsntw_loopEnd
    L_bsntw_nextNode:
        mov     esi, dword ptr [esi + 0xe4]
    L_bsntw_loopEnd:
        cmp     esi, ebx
        jne     L_bsntw_loop
        pop     ebp
        pop     edi
    L_bsntw_done:
        mov     dword ptr [g_framePauseFlag], ebx
        pop     esi
        pop     ebx
        ret
    }
}
#endif
