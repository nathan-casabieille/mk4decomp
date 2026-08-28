/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
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

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_tickFlagF;
extern u32 g_dlSomeFlag2;
extern unsigned int g_quadEntryGate;
extern unsigned int g_phaseTimer;
extern unsigned int g_dst_00537ea4;
#endif
extern unsigned int g_dispatchSave_00537ef4;
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_dispatchVar11;
extern unsigned int g_hitPhase;
extern unsigned int g_audioBank2State;
extern unsigned int g_fightTickSavedSlot;
extern unsigned int g_roundResetSlot;
extern unsigned int g_phaseInstallSlot;
extern unsigned int g_audioStreamState;
extern unsigned int g_phaseThunkArr;
extern u32 g_dlSomeFlag1;
extern unsigned int g_dst_0053a6e0;
extern unsigned int g_phaseThunkSlot4;
extern unsigned int g_phaseThunkState;
extern unsigned int g_dispatchSave39;
extern unsigned int g_dispatchClr1;
extern unsigned int g_installCountdownSlot2;
extern unsigned int g_smState4Way;
extern unsigned int g_titleDemoState;
extern unsigned int g_titleDemoState2;
extern u32 g_dlState;
extern u32 g_dlAux;
extern unsigned int g_dispatchSave37;
#endif
extern unsigned int g_clusterArr541f60_n6;
extern unsigned int g_clusterArr541f60_n5;
extern unsigned int g_clusterArr541f60_n4;
extern unsigned int g_clusterArr541f60_n3;
extern unsigned int g_clusterArr541f60_n2;
extern unsigned int g_clusterArr541f60_n1;
extern unsigned int g_clusterArr541f60_10;
extern unsigned int g_clusterArr541f60_11;
extern unsigned int g_clusterArr541f60_12;
extern unsigned int g_clusterArr541f60_13;
extern unsigned int g_clusterArr541f60_14;
extern unsigned int g_clusterArr541f60_15;
extern unsigned int g_clusterArr541f60_16;
extern unsigned int g_clusterArr541f60_17;
extern unsigned int g_clusterArr541f60_18;
extern unsigned int g_clusterArr541f60_19;
extern unsigned int g_clusterArr541f60_20;
extern unsigned int g_clusterArr541f60_21;
extern unsigned int g_clusterArr541f60_22;
extern unsigned int g_clusterArr541f60_23;
extern unsigned int g_clusterArr541f60_24;
extern unsigned int g_clusterArr541f60_25;
extern unsigned int g_clusterArr541f60_26;
extern unsigned int g_clusterArr541f60_27;
extern unsigned int g_clusterArr541f60_28;
extern unsigned int g_clusterArr541f60_29;
extern unsigned int g_clusterArr541f60_30;
extern unsigned int g_clusterArr541f60_31;
extern unsigned int g_clusterArr541f60_32;
extern unsigned int g_clusterArr541f60_0;
extern unsigned int g_clusterArr541f60_1;
extern unsigned int g_clusterArr541f60_2;
extern unsigned int g_clusterArr541f60_3;
extern unsigned int g_clusterArr541f60_4;
extern unsigned int g_clusterArr541f60_5;
extern unsigned int g_clusterArr541f60_6;
extern unsigned int g_clusterArr541f60_7;
extern unsigned int g_clusterArr541f60_8;
extern unsigned int g_clusterArr541f60_9;
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_tripleEntryFlag;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_active_00537e88 (*(unsigned int *)MK4_VA(unsigned int, 0x537e88u))
#define g_active_0053a408 (*(unsigned int *)MK4_VA(unsigned int, 0x53a408u))
#define g_armedReloadA (*(unsigned int *)MK4_VA(unsigned int, 0x541fa4u))
#define g_armedReloadB (*(unsigned int *)MK4_VA(unsigned int, 0x541fa8u))
#define g_audioBank2State (*(unsigned int *)MK4_VA(unsigned int, 0x537f98u))
#define g_audioBankSel (*(unsigned int *)MK4_VA(unsigned int, 0x537f94u))
#define g_audioBoundNode (*(unsigned int *)MK4_VA(unsigned int, 0x5437f0u))
#define g_audioStreamState (*(unsigned int *)MK4_VA(unsigned int, 0x53a430u))
#define g_baseSel (*(unsigned int *)MK4_VA(unsigned int, 0x542060u))
#define g_chainAccumCur (*(unsigned int *)MK4_VA(unsigned int, 0x542078u))
#define g_cj_00542054 (*(unsigned int *)MK4_VA(unsigned int, 0x542054u))
#define g_cj_00542058 (*(unsigned int *)MK4_VA(unsigned int, 0x542058u))
#define g_cj_0054205c (*(unsigned int *)MK4_VA(unsigned int, 0x54205cu))
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_dispatchClr1 (*(unsigned int *)MK4_VA(unsigned int, 0x53e34cu))
#define g_dispatchSave37 (*(unsigned int *)MK4_VA(unsigned int, 0x541ee8u))
#define g_dispatchSave39 (*(unsigned int *)MK4_VA(unsigned int, 0x53a788u))
#define g_dispatchVar11 (*(unsigned int *)MK4_VA(unsigned int, 0x537f04u))
#define g_dlAux (*(unsigned int *)MK4_VA(unsigned int, 0x541e38u))
#define g_dlSomeFlag1 (*(unsigned int *)MK4_VA(unsigned int, 0x53a510u))
#define g_dlSomeFlag2 (*(unsigned int *)MK4_VA(unsigned int, 0x52aafcu))
#define g_dlState (*(unsigned int *)MK4_VA(unsigned int, 0x541e34u))
#define g_dst_00537ea4 (*(unsigned int *)MK4_VA(unsigned int, 0x537ea4u))
#define g_dst_0053a6e0 (*(unsigned int *)MK4_VA(unsigned int, 0x53a6e0u))
#define g_dualBitGate (*(unsigned int *)MK4_VA(unsigned int, 0x53a7b0u))
#define g_eventArmReload (*(unsigned int *)MK4_VA(unsigned int, 0x53a770u))
#define g_fightAxisNegX (*(unsigned int *)MK4_VA(unsigned int, 0x535e70u))
#define g_fightAxisNegY (*(unsigned int *)MK4_VA(unsigned int, 0x535e74u))
#define g_fightAxisPosX (*(unsigned int *)MK4_VA(unsigned int, 0x535e78u))
#define g_fightAxisPosY (*(unsigned int *)MK4_VA(unsigned int, 0x535e7cu))
#define g_fightStateProgress (*(unsigned int *)MK4_VA(unsigned int, 0x535ddcu))
#define g_fightTickSavedSlot (*(unsigned int *)MK4_VA(unsigned int, 0x5380d8u))
#define g_framePauseFlag (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_gameCountdown (*(unsigned int *)MK4_VA(unsigned int, 0x53a718u))
#define g_hitPhase (*(unsigned int *)MK4_VA(unsigned int, 0x537f30u))
#define g_installCountdownSlot2 (*(unsigned int *)MK4_VA(unsigned int, 0x541d84u))
#define g_installOwnerNode (*(unsigned int *)MK4_VA(unsigned int, 0x535cf8u))
#define g_lastGatedTick (*(unsigned int *)MK4_VA(unsigned int, 0x54358cu))
#define g_lastGatedValue (*(unsigned int *)MK4_VA(unsigned int, 0x543598u))
#define g_phaseInstallSlot (*(unsigned int *)MK4_VA(unsigned int, 0x53a42cu))
#define g_phaseThunkArr (*(unsigned int *)MK4_VA(unsigned int, 0x53a474u))
#define g_phaseThunkSlot4 (*(unsigned int *)MK4_VA(unsigned int, 0x53a6f8u))
#define g_phaseThunkState (*(unsigned int *)MK4_VA(unsigned int, 0x53a730u))
#define g_phaseTimer (*(unsigned int *)MK4_VA(unsigned int, 0x537e94u))
#define g_quadEntryGate (*(unsigned int *)MK4_VA(unsigned int, 0x52d724u))
#define g_rangeBase (*(unsigned int *)MK4_VA(unsigned int, 0x53a46cu))
#define g_rangeSqLimit (*(unsigned int *)MK4_VA(unsigned int, 0x53a180u))
#define g_roundResetSlot (*(unsigned int *)MK4_VA(unsigned int, 0x53a3e4u))
#define g_smState4Way (*(unsigned int *)MK4_VA(unsigned int, 0x541dc8u))
#define g_stateCountdown (*(unsigned int *)MK4_VA(unsigned int, 0x53a3c0u))
#define g_tickFlagF (*(unsigned int *)MK4_VA(unsigned int, 0x52aac4u))
#define g_titleDemoState (*(unsigned int *)MK4_VA(unsigned int, 0x541df0u))
#define g_titleDemoState2 (*(unsigned int *)MK4_VA(unsigned int, 0x541df4u))
#define g_tripleEntryFlag (*(unsigned int *)MK4_VA(unsigned int, 0x54380cu))
#define g_walkCallback (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_xformDirtyFlags (*(unsigned int *)MK4_VA(unsigned int, 0x54208cu))
#define g_xformScratch94 (*(unsigned int *)MK4_VA(unsigned int, 0x542094u))
#endif

extern void Cmp2DirtyToggle(void);
extern void TestCmpZeroFour(void);
extern void TriBranchFlagWrite(void);
extern void TwoStateCopyDup(void);

#ifdef NON_MATCHING
#include "portable/mem_model.h"
extern void Cmp2DirtyToggle(void);
extern void TwoStateCopyDup(void);
extern void TestCmpZeroFour(void);
extern void TriBranchFlagWrite(void);

/* @addr 0x004223e0 (523b) - NATIVE twin; the matching build keeps the
 * __asm body below.
 *
 * The round reset. Three guarded calls at the head (the dirty toggle, the
 * state copy when bit 0 came back set, and the zero-four check when the
 * tick flag is 2), then two 0x10000 stamps, the hit-phase clear, and a
 * long run of zeroed state - most of it the 0x541eec..0x541f84 pair table,
 * cleared high word before low word exactly as the original walks it.
 * The tail runs the tri-branch flag write and, on a clean return, saves
 * the fight tick counter. */
void RoundReset(void)
{
    Cmp2DirtyToggle();
    if (g_framePauseFlag != 0) return;
    if (g_xformDirtyFlags & 1) {
        TwoStateCopyDup();
        if (g_framePauseFlag != 0) return;
    }
    g_walkCallback = *MK4_VA(unsigned int, 0x52aac4u);
    if (*MK4_VA(unsigned int, 0x52aac4u) == 2) {
        TestCmpZeroFour();
        if (g_framePauseFlag != 0) return;
    }
    *MK4_VA(unsigned int, 0x53a3e4u) = 0x10000;
    *MK4_VA(unsigned int, 0x53a474u) = 0x10000;
    g_walkCallback = *MK4_VA(unsigned int, 0x537f30u);
    if (*MK4_VA(unsigned int, 0x537f30u) == 1) {
        *MK4_VA(unsigned int, 0x53a6e0u) = 0;
        *MK4_VA(unsigned int, 0x537ea4u) = 0;
    }
    *MK4_VA(unsigned int, 0x53a6e0u) = 0;
    *MK4_VA(unsigned int, 0x537ea4u) = 0;
    *MK4_VA(unsigned int, 0x541df0u) = 0;
    *MK4_VA(unsigned int, 0x541df4u) = 0;
    *MK4_VA(unsigned char, 0x54380cu) = 0;
    *MK4_VA(unsigned int, 0x53a6f8u) = 0;
    *MK4_VA(unsigned int, 0x53a788u) = 0;
    *MK4_VA(unsigned int, 0x53e34cu) = 0;
    *MK4_VA(unsigned int, 0x541dc8u) = 0;
    *MK4_VA(unsigned int, 0x537e94u) = 0;
    *MK4_VA(unsigned int, 0x53a42cu) = 0;
    *MK4_VA(unsigned int, 0x537ef4u) = 0;
    *MK4_VA(unsigned int, 0x537f94u) = 0;
    *MK4_VA(unsigned int, 0x52d724u) = 0;
    *MK4_VA(unsigned int, 0x537f98u) = 0;
    *MK4_VA(unsigned int, 0x53a730u) = 0;
    *MK4_VA(unsigned int, 0x541d84u) = 0;
    *MK4_VA(unsigned int, 0x53a430u) = 0;
    *MK4_VA(unsigned int, 0x537f04u) = 0;
    *MK4_VA(unsigned int, 0x53a510u) = 0;
    *MK4_VA(unsigned int, 0x52aafcu) = 0;
    *MK4_VA(unsigned int, 0x541e34u) = 0;
    *MK4_VA(unsigned int, 0x541e38u) = 0;
    *MK4_VA(unsigned int, 0x5380d8u) = 0;
    *MK4_VA(unsigned int, 0x541eecu) = 0;
    *MK4_VA(unsigned int, 0x541ee8u) = 0;
    *MK4_VA(unsigned int, 0x541ef4u) = 0;
    *MK4_VA(unsigned int, 0x541ef0u) = 0;
    *MK4_VA(unsigned int, 0x541efcu) = 0;
    *MK4_VA(unsigned int, 0x541ef8u) = 0;
    *MK4_VA(unsigned int, 0x541f04u) = 0;
    *MK4_VA(unsigned int, 0x541f00u) = 0;
    *MK4_VA(unsigned int, 0x541f0cu) = 0;
    *MK4_VA(unsigned int, 0x541f08u) = 0;
    *MK4_VA(unsigned int, 0x541f14u) = 0;
    *MK4_VA(unsigned int, 0x541f10u) = 0;
    *MK4_VA(unsigned int, 0x541f1cu) = 0;
    *MK4_VA(unsigned int, 0x541f18u) = 0;
    *MK4_VA(unsigned int, 0x541f24u) = 0;
    *MK4_VA(unsigned int, 0x541f20u) = 0;
    *MK4_VA(unsigned int, 0x541f2cu) = 0;
    *MK4_VA(unsigned int, 0x541f28u) = 0;
    *MK4_VA(unsigned int, 0x541f34u) = 0;
    *MK4_VA(unsigned int, 0x541f30u) = 0;
    *MK4_VA(unsigned int, 0x541f3cu) = 0;
    *MK4_VA(unsigned int, 0x541f38u) = 0;
    *MK4_VA(unsigned int, 0x541f44u) = 0;
    *MK4_VA(unsigned int, 0x541f40u) = 0;
    *MK4_VA(unsigned int, 0x541f4cu) = 0;
    *MK4_VA(unsigned int, 0x541f48u) = 0;
    *MK4_VA(unsigned int, 0x541f54u) = 0;
    *MK4_VA(unsigned int, 0x541f50u) = 0;
    *MK4_VA(unsigned int, 0x541f5cu) = 0;
    *MK4_VA(unsigned int, 0x541f58u) = 0;
    *MK4_VA(unsigned int, 0x541f64u) = 0;
    *MK4_VA(unsigned int, 0x541f60u) = 0;
    *MK4_VA(unsigned int, 0x541f6cu) = 0;
    *MK4_VA(unsigned int, 0x541f68u) = 0;
    *MK4_VA(unsigned int, 0x541f74u) = 0;
    *MK4_VA(unsigned int, 0x541f70u) = 0;
    *MK4_VA(unsigned int, 0x541f7cu) = 0;
    *MK4_VA(unsigned int, 0x541f78u) = 0;
    *MK4_VA(unsigned int, 0x541f84u) = 0;
    *MK4_VA(unsigned int, 0x541f80u) = 0;
    TriBranchFlagWrite();
    if (g_framePauseFlag != 0) return;
    g_walkCallback = *MK4_VA(unsigned int, 0x53a498u);
    *MK4_VA(unsigned int, 0x5380d8u) = *MK4_VA(unsigned int, 0x53a498u);
}
#else
__declspec(naked) void RoundReset(void)
{
    __asm {
        push     ebx
        call     Cmp2DirtyToggle
        mov      eax, dword ptr [g_framePauseFlag]
        xor      ebx, ebx
        cmp      eax, ebx
        jne      L_25e9
        test     byte ptr [g_xformDirtyFlags], 1
        je       short L_240f
        call     TwoStateCopyDup
        cmp      dword ptr [g_framePauseFlag], ebx
        jne      L_25e9
    L_240f:
        mov      eax, dword ptr [g_tickFlagF]
        cmp      eax, 2
        mov      dword ptr [g_walkCallback], eax
        jne      short L_242f
        call     TestCmpZeroFour
        cmp      dword ptr [g_framePauseFlag], ebx
        jne      L_25e9
    L_242f:
        mov      eax, 0x10000
        mov      dword ptr [g_roundResetSlot], eax
        mov      dword ptr [g_phaseThunkArr], eax
        mov      eax, dword ptr [g_hitPhase]
        cmp      eax, 1
        mov      dword ptr [g_walkCallback], eax
        jne      short L_2459
        mov      dword ptr [g_dst_0053a6e0], ebx
        mov      dword ptr [g_dst_00537ea4], ebx
    L_2459:
        mov      dword ptr [g_titleDemoState], ebx
        mov      dword ptr [g_titleDemoState2], ebx
        mov      byte ptr [g_tripleEntryFlag], bl
        mov      dword ptr [g_phaseThunkSlot4], ebx
        mov      dword ptr [g_dispatchSave39], ebx
        mov      dword ptr [g_dispatchClr1], ebx
        mov      dword ptr [g_smState4Way], ebx
        mov      dword ptr [g_phaseTimer], ebx
        mov      dword ptr [g_phaseInstallSlot], ebx
        mov      dword ptr [g_dispatchSave_00537ef4], ebx
        mov      dword ptr [g_audioBankSel], ebx
        mov      dword ptr [g_quadEntryGate], ebx
        mov      dword ptr [g_audioBank2State], ebx
        mov      dword ptr [g_phaseThunkState], ebx
        mov      dword ptr [g_installCountdownSlot2], ebx
        mov      dword ptr [g_audioStreamState], ebx
        mov      dword ptr [g_dispatchVar11], ebx
        mov      dword ptr [g_dlSomeFlag1], ebx
        mov      dword ptr [g_dlSomeFlag2], ebx
        mov      dword ptr [g_dlState], ebx
        mov      dword ptr [g_dlAux], ebx
        mov      dword ptr [g_fightTickSavedSlot], ebx
        mov      dword ptr [g_clusterArr541f60_n6], ebx
        mov      dword ptr [g_dispatchSave37], ebx
        mov      dword ptr [g_clusterArr541f60_n4], ebx
        mov      dword ptr [g_clusterArr541f60_n5], ebx
        mov      dword ptr [g_clusterArr541f60_n2], ebx
        mov      dword ptr [g_clusterArr541f60_n3], ebx
        mov      dword ptr [g_clusterArr541f60_10], ebx
        mov      dword ptr [g_clusterArr541f60_n1], ebx
        mov      dword ptr [g_clusterArr541f60_12], ebx
        mov      dword ptr [g_clusterArr541f60_11], ebx
        mov      dword ptr [g_clusterArr541f60_14], ebx
        mov      dword ptr [g_clusterArr541f60_13], ebx
        mov      dword ptr [g_clusterArr541f60_16], ebx
        mov      dword ptr [g_clusterArr541f60_15], ebx
        mov      dword ptr [g_clusterArr541f60_18], ebx
        mov      dword ptr [g_clusterArr541f60_17], ebx
        mov      dword ptr [g_clusterArr541f60_20], ebx
        mov      dword ptr [g_clusterArr541f60_19], ebx
        mov      dword ptr [g_clusterArr541f60_22], ebx
        mov      dword ptr [g_clusterArr541f60_21], ebx
        mov      dword ptr [g_clusterArr541f60_24], ebx
        mov      dword ptr [g_clusterArr541f60_23], ebx
        mov      dword ptr [g_clusterArr541f60_26], ebx
        mov      dword ptr [g_clusterArr541f60_25], ebx
        mov      dword ptr [g_clusterArr541f60_28], ebx
        mov      dword ptr [g_clusterArr541f60_27], ebx
        mov      dword ptr [g_clusterArr541f60_30], ebx
        mov      dword ptr [g_clusterArr541f60_29], ebx
        mov      dword ptr [g_clusterArr541f60_32], ebx
        mov      dword ptr [g_clusterArr541f60_31], ebx
        mov      dword ptr [g_clusterArr541f60_1], ebx
        mov      dword ptr [g_clusterArr541f60_0], ebx
        mov      dword ptr [g_clusterArr541f60_3], ebx
        mov      dword ptr [g_clusterArr541f60_2], ebx
        mov      dword ptr [g_clusterArr541f60_5], ebx
        mov      dword ptr [g_clusterArr541f60_4], ebx
        mov      dword ptr [g_clusterArr541f60_7], ebx
        mov      dword ptr [g_clusterArr541f60_6], ebx
        mov      dword ptr [g_clusterArr541f60_9], ebx
        mov      dword ptr [g_clusterArr541f60_8], ebx
        call     TriBranchFlagWrite
        cmp      dword ptr [g_framePauseFlag], ebx
        jne      short L_25e9
        mov      eax, dword ptr [g_gtFightTickCounter]
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [g_fightTickSavedSlot], eax
    L_25e9:
        pop      ebx
        ret
    }
}
#endif
