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

/* @addr 0x004236a0 (125b) - if any of {g_dlNalt1, g_dlNalt2,
 *   g_dlNalt3, g_dlNalt4} == 0xf: clear g_counter_0053a51c & g_walkCallback,
 *   call F1. Then v3 = (data_4dfd48 >> 2) + g_counter_0053a51c;
 *   g_currentNodeIdx = v3; arg = arr[v3];
 *   push arg twice; g_rangeBase = arg; call Mul10Tail; g_rangeSqLimit = res; jmp F3.
 */
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_dispatchSave623;
#endif
extern unsigned int g_matrixStack_arr;
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern s32 g_dlNalt1;
extern s32 g_dlNalt2;
extern s32 g_dlNalt3;
extern s32 g_dlNalt4;
extern unsigned int g_rangeBase;
extern unsigned int g_counter_0053a51c;
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
#define g_baseSel (*(unsigned int *)MK4_VA(unsigned int, 0x542060u))
#define g_chainAccumCur (*(unsigned int *)MK4_VA(unsigned int, 0x542078u))
#define g_cj_00542054 (*(unsigned int *)MK4_VA(unsigned int, 0x542054u))
#define g_cj_00542058 (*(unsigned int *)MK4_VA(unsigned int, 0x542058u))
#define g_cj_0054205c (*(unsigned int *)MK4_VA(unsigned int, 0x54205cu))
#define g_counter_0053a51c (*(unsigned int *)MK4_VA(unsigned int, 0x53a51cu))
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_dispatchSave623 (*(unsigned int *)MK4_VA(unsigned int, 0x4dfd48u))
#define g_dlNalt1 (*(int *)MK4_VA(int, 0x537f48u))
#define g_dlNalt2 (*(int *)MK4_VA(int, 0x5380e0u))
#define g_dlNalt3 (*(int *)MK4_VA(int, 0x53a178u))
#define g_dlNalt4 (*(int *)MK4_VA(int, 0x53a250u))
#define g_dualBitGate (*(unsigned int *)MK4_VA(unsigned int, 0x53a7b0u))
#define g_eventArmReload (*(unsigned int *)MK4_VA(unsigned int, 0x53a770u))
#define g_eventQueueCurrent (*(unsigned int *)MK4_VA(unsigned int, 0x542070u))
#define g_fightAxisNegX (*(unsigned int *)MK4_VA(unsigned int, 0x535e70u))
#define g_fightAxisNegY (*(unsigned int *)MK4_VA(unsigned int, 0x535e74u))
#define g_fightAxisPosX (*(unsigned int *)MK4_VA(unsigned int, 0x535e78u))
#define g_fightAxisPosY (*(unsigned int *)MK4_VA(unsigned int, 0x535e7cu))
#define g_fightStateProgress (*(unsigned int *)MK4_VA(unsigned int, 0x535ddcu))
#define g_gameCountdown (*(unsigned int *)MK4_VA(unsigned int, 0x53a718u))
#define g_installOwnerNode (*(unsigned int *)MK4_VA(unsigned int, 0x535cf8u))
#define g_lastGatedTick (*(unsigned int *)MK4_VA(unsigned int, 0x54358cu))
#define g_lastGatedValue (*(unsigned int *)MK4_VA(unsigned int, 0x543598u))
#define g_rangeBase (*(unsigned int *)MK4_VA(unsigned int, 0x53a46cu))
#define g_rangeSqLimit (*(unsigned int *)MK4_VA(unsigned int, 0x53a180u))
#define g_stateCountdown (*(unsigned int *)MK4_VA(unsigned int, 0x53a3c0u))
#define g_walkCallback (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_xformScratch94 (*(unsigned int *)MK4_VA(unsigned int, 0x542094u))
#endif

extern void ScenePostInitSequencer(void);
extern void TablePushAccumTailJmp(void);

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void FourGlobalsEqualFInitTail(void)

{
  if ((((g_dlNalt1 == 0xf) || (g_dlNalt2 == 0xf)) || (g_dlNalt3 == 0xf)) ||
     (g_dlNalt4 == 0xf)) {
    g_counter_0053a51c = 0;
    g_walkCallback = 0;
    TablePushAccumTailJmp();
  }
  g_currentNodeIdx = g_counter_0053a51c + (0x4dfd48u >> 2);
  g_rangeBase = *MK4_NODE(undefined4, (g_currentNodeIdx));
  g_eventQueueCurrent = g_rangeBase;
  g_rangeSqLimit = ((int (*)(int, int))Mul10Tail)(
      (int)g_rangeBase, (int)g_rangeBase);
  g_eventQueueCurrent = g_rangeSqLimit;
  ScenePostInitSequencer();
  return;
}
#else
__declspec(naked) void FourGlobalsEqualFInitTail(void) {
    __asm {
        mov     ecx, dword ptr [g_dlNalt1]
        mov     eax, 0xf
        cmp     ecx, eax
        _emit   74h
        _emit   18h
        cmp     dword ptr [g_dlNalt2], eax
        _emit   74h
        _emit   10h
        cmp     dword ptr [g_dlNalt3], eax
        _emit   74h
        _emit   08h
        cmp     dword ptr [g_dlNalt4], eax
        _emit   75h
        _emit   11h
        xor     eax, eax
        mov     dword ptr [g_counter_0053a51c], eax
        mov     dword ptr [g_walkCallback], eax
        call    TablePushAccumTailJmp
        mov     ecx, dword ptr [g_counter_0053a51c]
        mov     eax, offset g_dispatchSave623
        shr     eax, 2
        add     eax, ecx
        mov     dword ptr [g_eventQueueCurrent], ecx
        mov     dword ptr [g_currentNodeIdx], eax
        mov     eax, [eax*4 + g_matrixStack_arr]
        push    eax
        push    eax
        mov     dword ptr [g_eventQueueCurrent], eax
        mov     dword ptr [g_rangeBase], eax
        call    Mul10Tail
        add     esp, 8
        mov     dword ptr [g_eventQueueCurrent], eax
        mov     dword ptr [g_rangeSqLimit], eax
        jmp     ScenePostInitSequencer
    }
}
#endif
