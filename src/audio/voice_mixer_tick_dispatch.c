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

extern unsigned int g_dispatchSave804;
extern unsigned int g_dispatchSave578;
extern unsigned int g_dispatchSave806;
extern unsigned int g_dispatchSave808;
extern unsigned int g_dispatchSave809;
extern unsigned int g_dispatchSave723;
extern unsigned int g_dispatchSave120;
extern unsigned int g_dispatchSave1332;
extern void AudioBindEntry(void);
extern void AudioInitArgs3(void);
extern void GuardedSetupCallTailJmp(void);

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void VoiceMixerTickDispatch(void)

{
  undefined *puVar1;
  int iVar2;
  undefined **ppuVar3;
  undefined **ppuVar4;
  int iVar5;
  
  ppuVar3 = (undefined **)&g_dispatchSave578;
  do {
    if (ppuVar3 < &g_dispatchSave806) {
      AudioInitArgs3(&g_dispatchSave120,0,*ppuVar3 + -0x50000,0x10000);
    }
    ppuVar3 = ppuVar3 + 7;
  } while (ppuVar3 < &g_dispatchSave809);
  AudioBindEntry(&g_dispatchSave723);
  iVar5 = 0;
  ppuVar3 = &g_dispatchSave804;
  do {
    g_walkCallback = ppuVar3[2];
    (*(unsigned int *)MK4_VA(unsigned int, 0x542044)) = *ppuVar3;
    GuardedSetupCallTailJmp((*(unsigned int *)MK4_VA(unsigned int, 0x542044)),g_walkCallback);
    switch(iVar5) {
    case 6:
    case 7:
      iVar2 = *(int *)((int)(*(unsigned int *)MK4_VA(unsigned int, 0x542044)) * 4 + 0x54) + -0xf00000;
      break;
    case 8:
    case 9:
      iVar2 = *(int *)((int)(*(unsigned int *)MK4_VA(unsigned int, 0x542044)) * 4 + 0x54) + 0xf00000;
      break;
    default:
      goto switchD_004a2838_default;
    }
    *(int *)((int)(*(unsigned int *)MK4_VA(unsigned int, 0x542044)) * 4 + 0x54) = iVar2;
switchD_004a2838_default:
    ppuVar4 = ppuVar3 + 7;
    *(undefined **)((int)(*(unsigned int *)MK4_VA(unsigned int, 0x542044)) * 4 + 0x5c) = ppuVar3[3];
    iVar2 = g_baseSel;
    puVar1 = (*(unsigned int *)MK4_VA(unsigned int, 0x542044));
    ppuVar3[1] = *(undefined **)((int)(*(unsigned int *)MK4_VA(unsigned int, 0x542044)) * 4 + 0x54);
    g_eventQueueCurrent = (int)*(char *)(ppuVar3 + -1);
    iVar5 = iVar5 + 1;
    *(undefined **)((g_eventQueueCurrent + iVar2) * 4) = puVar1;
    ppuVar3 = ppuVar4;
    if (&g_dispatchSave808 <= ppuVar4) {
      return;
    }
  } while( true );
}
#else
__declspec(naked) void VoiceMixerTickDispatch(void)
{
    __asm {
        push     ebx
        push     ebp
        push     esi
        push     edi
        mov      esi, OFFSET g_dispatchSave578
    L_27c9:
        cmp      esi, OFFSET g_dispatchSave806
        jae      L_27ed
        mov      eax, dword ptr [esi]
        push     0x10000
        sub      eax, 0x50000
        push     eax
        push     0
        push     OFFSET g_dispatchSave120
        call     AudioInitArgs3
        add      esp, 0x10
    L_27ed:
        add      esi, 0x1c
        cmp      esi, OFFSET g_dispatchSave809
        jb       L_27c9
        push     OFFSET g_dispatchSave723
        call     AudioBindEntry
        add      esp, 4
        xor      edi, edi
        mov      esi, OFFSET g_dispatchSave804
        mov      ebp, 0xff100000
        mov      ebx, OFFSET g_dispatchSave1332
    L_2816:
        mov      eax, dword ptr [esi + 8]
        mov      ecx, dword ptr [esi]
        push     eax
        push     ecx
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [g_currentNodeIdx], ecx
        call     GuardedSetupCallTailJmp
        lea      eax, [edi - 6]
        add      esp, 8
        cmp      eax, 3
        ja       L_2864
        jmp      dword ptr [eax*4 + L_jmptbl]
    L_283f:
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      ecx, dword ptr [eax*4 + 0x54]
        add      ecx, ebp
        jmp      L_285d
    L_284f:
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      ecx, dword ptr [eax*4 + 0x54]
        add      ecx, ebx
    L_285d:
        mov      dword ptr [eax*4 + 0x54], ecx
    L_2864:
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      ecx, dword ptr [esi + 0xc]
        add      esi, 0x1c
        mov      dword ptr [edx*4 + 0x5c], ecx
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      edx, dword ptr [g_baseSel]
        mov      ecx, dword ptr [eax*4 + 0x54]
        mov      dword ptr [esi - 0x18], ecx
        movsx    ecx, byte ptr [esi - 0x20]
        mov      dword ptr [g_eventQueueCurrent], ecx
        add      ecx, edx
        inc      edi
        cmp      esi, OFFSET g_dispatchSave808
        mov      dword ptr [ecx*4], eax
        jb       L_2816
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        ret
        /* 3-byte lea ecx, [ecx+0] alignment nop (MASM picks 2-byte form; force 3-byte via _emit) */
        _emit 0x8d
        _emit 0x49
        _emit 0x00
    L_jmptbl:
        /* 4 dwords (2 unique targets, each twice) */
        _emit 0x3f
        _emit 0x28
        _emit 0x4a
        _emit 0x00
        _emit 0x3f
        _emit 0x28
        _emit 0x4a
        _emit 0x00
        _emit 0x4f
        _emit 0x28
        _emit 0x4a
        _emit 0x00
        _emit 0x4f
        _emit 0x28
        _emit 0x4a
        _emit 0x00
    }
}
#endif
