/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
#include "portable/ghidra_types.h"
#include "game/tick.h"

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
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
#endif

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
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_cj_00542058;
extern unsigned int g_rangeSqLimit;
extern unsigned int g_armedReloadA;
extern unsigned int g_armedReloadB;
extern unsigned int g_dualBitGate;
extern unsigned int g_eventArmReload;
extern unsigned int g_rangeBase;
#endif

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
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
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
#endif

/*
 * @addr 0x00439920 (129b game) - weighted-sum + cap + helper:
 *   computes walk = clamp(0x53a3c0 * 0x4f381c + 0x4f3814 + 0x54355c_dispatch
 *   + 0x541fb0*0x4f3818 + 0x53a1f0*0x4f3820, max 0x3cf); cj-dependent
 *   pick of multiplier (0x5433f0 if baseSel==0x538038, else 0x543444);
 *   call StorePauseImulShr16.
 */
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_dispatchSave1319;
extern unsigned int g_dispatchSave1320;
extern unsigned int g_dispatchSave1321;
extern unsigned int g_dispatchSave1322;
extern unsigned int g_audioRestoreSlot3;
extern unsigned int g_phaseCounter;
extern unsigned int g_audioInstallSlot2;
extern unsigned int g_phaseThunkSave2;
extern unsigned int g_audioPathFlag;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_active_00537e88 (*(unsigned int *)MK4_VA(unsigned int, 0x537e88u))
#define g_active_0053a408 (*(unsigned int *)MK4_VA(unsigned int, 0x53a408u))
#define g_armedReloadA (*(unsigned int *)MK4_VA(unsigned int, 0x541fa4u))
#define g_armedReloadB (*(unsigned int *)MK4_VA(unsigned int, 0x541fa8u))
#define g_audioBankSel (*(unsigned int *)MK4_VA(unsigned int, 0x537f94u))
#define g_audioBoundNode (*(unsigned int *)MK4_VA(unsigned int, 0x5437f0u))
#define g_audioInstallSlot2 (*(unsigned int *)MK4_VA(unsigned int, 0x5433f0u))
#define g_audioPathFlag (*(unsigned int *)MK4_VA(unsigned int, 0x54355cu))
#define g_audioRestoreSlot3 (*(unsigned int *)MK4_VA(unsigned int, 0x53a1f0u))
#define g_baseSel (*(unsigned int *)MK4_VA(unsigned int, 0x542060u))
#define g_chainAccumCur (*(unsigned int *)MK4_VA(unsigned int, 0x542078u))
#define g_cj_00542054 (*(unsigned int *)MK4_VA(unsigned int, 0x542054u))
#define g_cj_00542058 (*(unsigned int *)MK4_VA(unsigned int, 0x542058u))
#define g_cj_0054205c (*(unsigned int *)MK4_VA(unsigned int, 0x54205cu))
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_dispatchSave1319 (*(unsigned int *)MK4_VA(unsigned int, 0x4f3814u))
#define g_dispatchSave1320 (*(unsigned int *)MK4_VA(unsigned int, 0x4f3818u))
#define g_dispatchSave1321 (*(unsigned int *)MK4_VA(unsigned int, 0x4f381cu))
#define g_dispatchSave1322 (*(unsigned int *)MK4_VA(unsigned int, 0x4f3820u))
#define g_dualB_00538038 (*(unsigned int *)MK4_VA(unsigned int, 0x538038u))
#define g_dualBitGate (*(unsigned int *)MK4_VA(unsigned int, 0x53a7b0u))
#define g_eventArmReload (*(unsigned int *)MK4_VA(unsigned int, 0x53a770u))
#define g_fightAxisNegX (*(unsigned int *)MK4_VA(unsigned int, 0x535e70u))
#define g_fightAxisNegY (*(unsigned int *)MK4_VA(unsigned int, 0x535e74u))
#define g_fightAxisPosX (*(unsigned int *)MK4_VA(unsigned int, 0x535e78u))
#define g_fightAxisPosY (*(unsigned int *)MK4_VA(unsigned int, 0x535e7cu))
#define g_fightStateProgress (*(unsigned int *)MK4_VA(unsigned int, 0x535ddcu))
#define g_gameCountdown (*(unsigned int *)MK4_VA(unsigned int, 0x53a718u))
#define g_installOwnerNode (*(unsigned int *)MK4_VA(unsigned int, 0x535cf8u))
#define g_lastGatedTick (*(unsigned int *)MK4_VA(unsigned int, 0x54358cu))
#define g_lastGatedValue (*(unsigned int *)MK4_VA(unsigned int, 0x543598u))
#define g_phaseCounter (*(unsigned int *)MK4_VA(unsigned int, 0x541fb0u))
#define g_phaseThunkSave2 (*(unsigned int *)MK4_VA(unsigned int, 0x543444u))
#define g_rangeBase (*(unsigned int *)MK4_VA(unsigned int, 0x53a46cu))
#define g_rangeSqLimit (*(unsigned int *)MK4_VA(unsigned int, 0x53a180u))
#define g_stateCountdown (*(unsigned int *)MK4_VA(unsigned int, 0x53a3c0u))
#define g_walkCallback (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_xformScratch94 (*(unsigned int *)MK4_VA(unsigned int, 0x542094u))
#endif

extern void AudioVolumeRescale(void);

/*
 * NON-COAXABLE: orig keeps d (g_dispatchSave1320) in ecx (volatile) across the entire
 * dispatch branch, and reuses esi as scratch for two different short-lived values
 * (ref in dispatch branch, then f intermediate after noScale). MSVC /O2 instead
 * promotes d to edi (extra callee-saved push), giving two-register prologue
 * (push esi/edi) vs orig's single push esi. The volatile-register-survives-
 * branch + register-reuse pattern is not coaxable from pure C.
 */
#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void WeightedSumClampHelper(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = g_stateCountdown * g_dispatchSave1321 + g_dispatchSave1319;
  if (g_audioPathFlag != 0) {
    iVar1 = g_phaseThunkSave2;
    if (g_baseSel == g_dualB_00538038) {
      iVar1 = g_audioInstallSlot2;
    }
    iVar2 = iVar2 + g_dispatchSave1320 * iVar1;
  }
  g_walkCallback = g_phaseCounter * g_dispatchSave1320 + iVar2 + g_audioRestoreSlot3 * g_dispatchSave1322;
  if (0x3cf < g_walkCallback) {
    g_walkCallback = 0x3cf;
  }
  AudioVolumeRescale();
  return;
}
#else
__declspec(naked) void WeightedSumClampHelper(void) {
    __asm {
        mov     eax, dword ptr [g_stateCountdown]
        mov     edx, dword ptr [g_dispatchSave1319]
        imul    eax, dword ptr [g_dispatchSave1321]
        mov     ecx, dword ptr [g_audioPathFlag]
        add     eax, edx
        test    ecx, ecx
        mov     ecx, dword ptr [g_dispatchSave1320]
        push    esi
        je      noScale
        mov     edx, dword ptr [g_baseSel]
        mov     esi, dword ptr [g_gtPlayerProbe2]
        cmp     edx, esi
        mov     edx, ecx
        jne     useB
        imul    edx, dword ptr [g_audioInstallSlot2]
        jmp     after
useB:
        imul    edx, dword ptr [g_phaseThunkSave2]
after:
        add     eax, edx
noScale:
        mov     esi, dword ptr [g_phaseCounter]
        mov     edx, dword ptr [g_audioRestoreSlot3]
        imul    edx, dword ptr [g_dispatchSave1322]
        imul    esi, ecx
        add     esi, eax
        lea     eax, [esi + edx]
        cmp     eax, 0x3cf
        mov     dword ptr [g_walkCallback], eax
        jle     callTail
        mov     dword ptr [g_walkCallback], 0x3cf
callTail:
        call    AudioVolumeRescale
        pop     esi
        ret
    }
}
#endif
