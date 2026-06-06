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

extern unsigned int g_stateFlag;
extern unsigned int g_stateChangePair2;
extern unsigned int g_stateChangeBase;
extern unsigned int g_stateChangePair3;
extern unsigned int g_stateChangePair;
extern void CallSetPause(void);
extern void MStackPush2ClampLookup(void);
extern void SpawnTrioInitCluster(void);
extern void TripleEntryDispatch(void);

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void GuardedStateChangePair(void)

{
  int *piVar1;
  
  g_walkCallback = g_stateChangePair;
  if (g_stateChangePair != 0) {
    CallSetPause();
    return;
  }
  g_walkCallback = g_stateChangePair3;
  if (g_stateChangePair3 == 0x27) {
    g_eventQueueCurrent = g_stateChangePair2 + -1;
    if (g_eventQueueCurrent < 0) {
      CallSetPause();
      return;
    }
    (*(unsigned int *)MK4_VA(unsigned int, 0x542044)) = g_stateChangePair2 + 0x14e02b;
    g_walkCallback = 0x27;
    g_stateChangePair2 = g_eventQueueCurrent;
    *(undefined4 *)((*(unsigned int *)MK4_VA(unsigned int, 0x542044)) * 4) = 0x27;
    SpawnTrioInitCluster();
    if (g_framePauseFlag == 0) {
      CallSetPause();
      return;
    }
  }
  else {
    (*(unsigned int *)MK4_VA(unsigned int, 0x542044)) = 0x14e02c;
    g_eventQueueCurrent = g_stateChangePair2;
    if (2 < g_stateChangePair2) {
LAB_004586cd:
      g_walkCallback = 1;
      g_stateChangePair = 1;
      StoreTwoCall(0x458770,0);
      CallSetPause();
      return;
    }
    (*(unsigned int *)MK4_VA(unsigned int, 0x542044)) = g_stateChangePair2 + 0x14e02c;
    *(int *)((*(unsigned int *)MK4_VA(unsigned int, 0x542044)) * 4) = g_stateChangePair3;
    g_matrixStackTop = g_matrixStackTop + 1;
    *(int *)((int)g_matrixStackTop * 4) = g_eventQueueCurrent;
    MStackPush2ClampLookup();
    if (g_framePauseFlag == 0) {
      piVar1 = (int *)((int)g_matrixStackTop * 4);
      g_matrixStackTop = g_matrixStackTop + -1;
      g_eventQueueCurrent = *piVar1 + 1;
      if (2 < g_eventQueueCurrent) goto LAB_004586cd;
      g_stateChangePair2 = g_eventQueueCurrent;
      SpawnTrioInitCluster();
      if (g_framePauseFlag == 0) {
        StoreTwoCall(0x458770,0);
        CallSetPause();
        return;
      }
    }
  }
  return;
}
#else
__declspec(naked) void GuardedStateChangePair(void)
{
    __asm
    {
        mov     eax, dword ptr [g_stateChangePair]
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        je      short L_gscp_check27
        jmp     CallSetPause
    L_gscp_check27:
        mov     edx, dword ptr [g_stateChangePair3]
        cmp     edx, 0x27
        mov     dword ptr [g_walkCallback], edx
        je      L_gscp_dec
        mov     ecx, dword ptr [g_stateChangePair2]
        mov     eax, offset g_stateChangeBase
        shr     eax, 2
        cmp     ecx, 2
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [g_eventQueueCurrent], ecx
        jg      short L_gscp_inst
        add     eax, ecx
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [eax*4], edx
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_eventQueueCurrent]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4], ecx
        call    MStackPush2ClampLookup
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_gscp_ret
        mov     ecx, dword ptr [g_matrixStackTop]
        mov     eax, dword ptr [ecx*4]
        dec     ecx
        inc     eax
        mov     dword ptr [g_matrixStackTop], ecx
        cmp     eax, 2
        mov     dword ptr [g_eventQueueCurrent], eax
        jle     short L_gscp_setSlot
    L_gscp_inst:
        mov     eax, 1
        push    0
        push    offset L_gscp_sub2
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [g_stateChangePair], eax
        call    StoreTwoCall
        add     esp, 8
        jmp     CallSetPause
    L_gscp_setSlot:
        mov     dword ptr [g_stateChangePair2], eax
        call    SpawnTrioInitCluster
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_gscp_ret
        push    0
        push    offset L_gscp_sub2
        call    StoreTwoCall
        add     esp, 8
        jmp     CallSetPause
    L_gscp_dec:
        mov     edx, dword ptr [g_stateChangePair2]
        lea     ecx, [edx - 1]
        test    ecx, ecx
        mov     dword ptr [g_eventQueueCurrent], ecx
        jge     short L_gscp_decOk
        jmp     CallSetPause
    L_gscp_decOk:
        mov     eax, offset g_stateChangeBase
        mov     dword ptr [g_stateChangePair2], ecx
        shr     eax, 2
        add     eax, ecx
        mov     dword ptr [g_walkCallback], 0x27
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [eax*4], 0x27
        call    SpawnTrioInitCluster
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_gscp_ret
        jmp     CallSetPause
    L_gscp_ret:
        ret
        nop
        nop
        nop
    L_gscp_sub2:
        mov     eax, dword ptr [g_baseSel]
        shl     eax, 2
        mov     ecx, dword ptr [eax + 0x84]
        mov     dword ptr [eax + 0x84], 0
        test    ecx, ecx
        je      short L_gscp_sub2_inst
        mov     dword ptr [g_eventQueueWorkType], 0x264
        call    Push16Call
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_gscp_sub2_ret
        jmp     CallSetPause
    L_gscp_sub2_inst:
        mov     ecx, 1
        mov     dword ptr [eax + 8], offset L_gscp_sub2
        mov     dword ptr [eax + 0x84], ecx
        mov     dword ptr [g_pendingNodeType], ecx
        mov     dword ptr [g_framePauseFlag], ecx
    L_gscp_sub2_ret:
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
    L_gscp_sub3:
        mov     eax, dword ptr [g_stateFlag]
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        je      short L_gscp_sub3_jmp
        jmp     CallSetPause
    L_gscp_sub3_jmp:
        jmp     TripleEntryDispatch
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
    L_gscp_sub4:
        mov     eax, dword ptr [g_stateFlag]
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        jne     short L_gscp_sub4_jmp
        jmp     CallSetPause
    L_gscp_sub4_jmp:
        jmp     TripleEntryDispatch
    }
}
#endif
