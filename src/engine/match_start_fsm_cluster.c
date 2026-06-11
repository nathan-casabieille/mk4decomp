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

extern unsigned int g_dispatchSave63;
extern void CjInstallSelfRouter(void);
extern void EntryThunkBodyStateMachine(void);
extern void FiveCallGuardSetTail(void);
extern void GuardedPackedSlotInit(void);
extern void InstallSelf3WayChainCmp(void);
extern void InstallSelfPair3Branch(void);
extern void Phase4DualHelperTrampoline(void);
extern void Phase4FivePackedHelpers(void);
extern void ScaledArrStore_GuardedChainCmpDualBitXor_00429980(void);
extern void ScaledLitLoadCall_ScaledChainCallPauseSetJmp_then_Wrapper_IterLoad_0048fd30_00480fe0(void);
extern void ScaledLoadJmp_00428d20(void);
extern void ScaledLoadJmp_00429390(void);
extern void SfxAttenuateAndApply(void);
extern void StreamFlagPackedSelectChain(void);
extern void TableLookupCall_g_eventTbl_112(void);

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void MatchStartFsmCluster(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = g_baseSel * 4;
  iVar1 = *(int *)(iVar2 + 0x84);
  *(undefined4 *)(iVar2 + 0x84) = 0;
  if (iVar1 == 0) {
    *(code **)(iVar2 + 8) = MatchStartFsmCluster;
    *(undefined4 *)(iVar2 + 0x84) = 1;
    g_dualC = 0x14;
    g_framePauseFlag = 1;
    return;
  }
  if (iVar1 != 1) {
    FiveCallGuardSetTail();
    return;
  }
  *(code **)(iVar2 + 8) = MatchStartFsmCluster;
  MK4_NODE_AT(undefined4, g_baseSel, 0x84) = 2;
  (*(unsigned int *)MK4_VA(unsigned int, 0x542044)) = *(int *)(iVar2 + 4);
  *MK4_NODE(undefined4, (*(unsigned int *)MK4_VA(unsigned int, 0x542044))) = 0x2468eb0;
  (*(unsigned int *)MK4_VA(unsigned int, 0x542044)) = (*(unsigned int *)MK4_VA(unsigned int, 0x542044)) + 1;
  *(int *)(iVar2 + 4) = (*(unsigned int *)MK4_VA(unsigned int, 0x542044));
  MK4_NODE_AT(undefined4, g_baseSel, 0x84) = 0;
  ScaledLoadJmp_00429390();
  g_framePauseFlag = 1;
  return;
}
#else
__declspec(naked) void MatchStartFsmCluster(void)
{
    __asm {
        mov      eax, dword ptr [g_baseSel]
        xor      edx, edx
        shl      eax, 2
        push     esi
        mov      ecx, dword ptr [eax + 0x84]
        mov      dword ptr [eax + 0x84], edx
        sub      ecx, edx
        je       L_8f35
        dec      ecx
        je       L_8ed5
        call     FiveCallGuardSetTail
        pop      esi
        ret      
    L_8ed5:
        mov      dword ptr [eax + 8], OFFSET MatchStartFsmCluster
        mov      ecx, dword ptr [g_baseSel]
        mov      esi, OFFSET MatchStartFsmCluster
        mov      dword ptr [ecx*4 + 0x84], 2
        mov      ecx, dword ptr [eax + 4]
        add      esi, 0x2000000
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      dword ptr [ecx*4], esi
        mov      ecx, dword ptr [g_currentNodeIdx]
        inc      ecx
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      dword ptr [eax + 4], ecx
        mov      eax, dword ptr [g_baseSel]
        mov      dword ptr [eax*4 + 0x84], edx
        call     ScaledLoadJmp_00429390
        mov      dword ptr [g_framePauseFlag], 1
        pop      esi
        ret      
    L_8f35:
        mov      ecx, 1
        mov      dword ptr [eax + 8], OFFSET MatchStartFsmCluster
        mov      dword ptr [eax + 0x84], ecx
        mov      dword ptr [g_pendingNodeType], 0x14
        mov      dword ptr [g_framePauseFlag], ecx
        pop      esi
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        nop
    L_8f60:
        mov      eax, dword ptr [g_baseSel]
        push     ebx
        push     esi
        push     edi
        lea      esi, [eax*4]
        xor      edi, edi
        mov      eax, dword ptr [esi + 0x84]
        mov      dword ptr [esi + 0x84], edi
        cmp      eax, 5
        ja       L_9283
        jmp      dword ptr [eax*4 + L_jmptbl]
    L_8f8d:
        call     Phase4FivePackedHelpers
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_9288
        mov      dword ptr [g_eventQueueChild], 0x23
        mov      dword ptr [esi + 8], OFFSET L_8f60
        mov      ecx, dword ptr [g_baseSel]
        mov      edx, OFFSET L_8f60
        add      edx, 0x2000000
        mov      dword ptr [ecx*4 + 0x84], 2
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], edx
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      eax, dword ptr [g_baseSel]
        mov      dword ptr [eax*4 + 0x84], edi
        call     InstallSelf3WayChainCmp
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        pop      ebx
        ret      
    L_9007:
        call     Phase4DualHelperTrampoline
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_9288
        mov      dword ptr [g_walkCallback], 0x50
        call     TableLookupCall_g_eventTbl_112
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_9288
        mov      dword ptr [g_eventQueueNotMask], 3
        call     EntryThunkBodyStateMachine
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_9288
        call     MStackPush3CmpCall
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_9288
        mov      al, byte ptr [g_xformDirtyFlags]
        mov      ebx, 1
        test     al, bl
        jne      L_90a3
        mov      dword ptr [g_walkCallback], 0x23d7
        call     SfxAttenuateAndApply
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_9288
        mov      dword ptr [g_walkCallback], 0x88
        call     ScaledLitLoadCall_ScaledChainCallPauseSetJmp_then_Wrapper_IterLoad_0048fd30_00480fe0
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_9288
    L_90a3:
        mov      dword ptr [g_eventQueueChild], 0x26
        mov      dword ptr [esi + 8], OFFSET L_8f60
        mov      ecx, dword ptr [g_baseSel]
        mov      edx, OFFSET L_8f60
        add      edx, 0x3000000
        mov      dword ptr [ecx*4 + 0x84], 3
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], edx
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      eax, dword ptr [g_baseSel]
        mov      dword ptr [eax*4 + 0x84], edi
        call     InstallSelf3WayChainCmp
        mov      dword ptr [g_framePauseFlag], ebx
        pop      edi
        pop      esi
        pop      ebx
        ret
    L_9108:
        mov      dword ptr [g_eventQueueNotMask], 0xa
        jmp      L_914f
    L_9114:
        mov      dword ptr [g_eventQueueChild], 0x26
        call     ScaledArrStore_GuardedChainCmpDualBitXor_00429980
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_9288
        mov      dword ptr [esi + 8], OFFSET L_8f60
        mov      dword ptr [esi + 0x84], 5
        jmp      L_917b
    L_9142:
        mov      eax, dword ptr [g_eventQueueNotMask]
        dec      eax
        mov      dword ptr [g_eventQueueNotMask], eax
        je       L_9190
    L_914f:
        mov      dword ptr [g_eventQueueChild], 0x25
        call     ScaledArrStore_GuardedChainCmpDualBitXor_00429980
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_9288
        mov      dword ptr [esi + 8], OFFSET L_8f60
        mov      dword ptr [esi + 0x84], 4
    L_917b:
        mov      ebx, 1
        mov      dword ptr [g_pendingNodeType], ebx
        mov      dword ptr [g_framePauseFlag], ebx
        pop      edi
        pop      esi
        pop      ebx
        ret      
    L_9190:
        mov      dword ptr [esi + 8], OFFSET L_8f60
        mov      ecx, dword ptr [g_baseSel]
        mov      edx, OFFSET L_8f60
        mov      dword ptr [ecx*4 + 0x84], 6
        mov      eax, dword ptr [esi + 4]
        add      edx, 0x6000000
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], edx
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      eax, dword ptr [g_baseSel]
        mov      dword ptr [eax*4 + 0x84], edi
        call     ScaledLoadJmp_00428d20
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        pop      ebx
        ret
    L_91ef:
        mov      ecx, dword ptr [g_baseSel]
        mov      eax, 0x101
        mov      dword ptr [g_walkCallback], eax
        push     OFFSET g_dispatchSave63
        mov      dword ptr [ecx*4 + 0x74], eax
        call     GuardedPackedSlotInit
        mov      eax, dword ptr [g_framePauseFlag]
        add      esp, 4
        cmp      eax, edi
        jne      L_9288
        mov      dword ptr [g_eventQueueChild], 0xf
        mov      dword ptr [esi + 8], OFFSET L_8f60
        mov      edx, dword ptr [g_baseSel]
        mov      ebx, 1
        mov      ecx, OFFSET L_8f60
        mov      dword ptr [edx*4 + 0x84], ebx
        mov      eax, dword ptr [esi + 4]
        add      ecx, 0x1000000
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      edx, dword ptr [g_baseSel]
        mov      dword ptr [edx*4 + 0x84], edi
        call     InstallSelfPair3Branch
        mov      dword ptr [g_framePauseFlag], ebx
        pop      edi
        pop      esi
        pop      ebx
        ret      
    L_9283:
        call     FiveCallGuardSetTail
    L_9288:
        pop      edi
        pop      esi
        pop      ebx
        ret
    L_jmptbl:
        _emit 0xef
        _emit 0x91
        _emit 0x46
        _emit 0x00
        _emit 0x8d
        _emit 0x8f
        _emit 0x46
        _emit 0x00
        _emit 0x07
        _emit 0x90
        _emit 0x46
        _emit 0x00
        _emit 0x08
        _emit 0x91
        _emit 0x46
        _emit 0x00
        _emit 0x14
        _emit 0x91
        _emit 0x46
        _emit 0x00
        _emit 0x42
        _emit 0x91
        _emit 0x46
        _emit 0x00
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
    L_92b0:
        mov      eax, dword ptr [g_baseSel]
        xor      edx, edx
        shl      eax, 2
        mov      ecx, dword ptr [eax + 0x84]
        mov      dword ptr [eax + 0x84], edx
        cmp      ecx, edx
        je       L_92cf
        jmp      CjInstallSelfRouter
    L_92cf:
        mov      dword ptr [eax + 8], OFFSET L_92b0
        mov      ecx, dword ptr [g_baseSel]
        push     edi
        mov      edi, OFFSET L_92b0
        mov      dword ptr [ecx*4 + 0x84], 1
        mov      ecx, dword ptr [eax + 4]
        add      edi, 0x1000000
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      dword ptr [ecx*4], edi
        mov      ecx, dword ptr [g_currentNodeIdx]
        inc      ecx
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      dword ptr [eax + 4], ecx
        mov      eax, dword ptr [g_baseSel]
        mov      dword ptr [eax*4 + 0x84], edx
        call     StreamFlagPackedSelectChain
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        ret      
        jmp      StreamFlagPackedSelectChain
    }
}
#endif
