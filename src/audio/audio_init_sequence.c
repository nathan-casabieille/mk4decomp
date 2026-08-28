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

/* @addr 0x004a41a0 (182b audio) - audio init sequence.
 *   g_audioInitSeqByte = 1; g_walkCallback = 0; call CopyGlobal; call BootInitGuardedCallChain.
 *   Copy chain: [0x541ec4] = [0x541ecc]; [0x541ec8] = [0x541ed0]; [0x537f48] = [0x53a790];
 *               [0x5380e0] = [0x537ea0]; [0x53a178] = [0x537edc]; [0x53a250] = [0x53a1cc];
 *               g_walkCallback = [0x53a51c].
 *   call TablePushAccumTailJmp; pause? -> end.
 *   call TestCmpZeroFour; pause? -> end.
 *   push 0x1000, 0x004202c0; call StoreTwoCall; add esp, 8.
 *   [0x543800] = -1; g_walkCallback = 0; [0x52aac4] = 0.
 */
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_tickFlagF;
extern unsigned int g_audioInitState6;
extern unsigned int g_audioInitState5;
extern s32 g_dlNalt1;
extern s32 g_dlNalt2;
extern s32 g_dlNalt3;
extern unsigned int g_audioInitState4;
extern s32 g_dlNalt4;
extern unsigned int g_counter_0053a51c;
extern unsigned int g_audioInitState3;
extern s32 g_dlChar13;
extern s32 g_dlChar24;
extern unsigned int g_audioInitState2;
extern unsigned int g_audioInitState1;
extern unsigned int g_audioInitSeqByte;
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
#define g_audioInitSeqByte (*(unsigned int *)MK4_VA(unsigned int, 0x542040u))
#define g_audioInitState1 (*(unsigned int *)MK4_VA(unsigned int, 0x541ed0u))
#define g_audioInitState2 (*(unsigned int *)MK4_VA(unsigned int, 0x541eccu))
#define g_audioInitState3 (*(unsigned int *)MK4_VA(unsigned int, 0x53a790u))
#define g_audioInitState4 (*(unsigned int *)MK4_VA(unsigned int, 0x53a1ccu))
#define g_audioInitState5 (*(unsigned int *)MK4_VA(unsigned int, 0x537edcu))
#define g_audioInitState6 (*(unsigned int *)MK4_VA(unsigned int, 0x537ea0u))
#define g_baseSel (*(unsigned int *)MK4_VA(unsigned int, 0x542060u))
#define g_chainAccumCur (*(unsigned int *)MK4_VA(unsigned int, 0x542078u))
#define g_cj_00542054 (*(unsigned int *)MK4_VA(unsigned int, 0x542054u))
#define g_cj_00542058 (*(unsigned int *)MK4_VA(unsigned int, 0x542058u))
#define g_cj_0054205c (*(unsigned int *)MK4_VA(unsigned int, 0x54205cu))
#define g_counter_0053a51c (*(unsigned int *)MK4_VA(unsigned int, 0x53a51cu))
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_dlChar13 (*(int *)MK4_VA(int, 0x541ec4u))
#define g_dlChar24 (*(int *)MK4_VA(int, 0x541ec8u))
#define g_dlNalt1 (*(int *)MK4_VA(int, 0x537f48u))
#define g_dlNalt2 (*(int *)MK4_VA(int, 0x5380e0u))
#define g_dlNalt3 (*(int *)MK4_VA(int, 0x53a178u))
#define g_dlNalt4 (*(int *)MK4_VA(int, 0x53a250u))
#define g_dualBitGate (*(unsigned int *)MK4_VA(unsigned int, 0x53a7b0u))
#define g_eventArmReload (*(unsigned int *)MK4_VA(unsigned int, 0x53a770u))
#define g_fightAxisNegX (*(unsigned int *)MK4_VA(unsigned int, 0x535e70u))
#define g_fightAxisNegY (*(unsigned int *)MK4_VA(unsigned int, 0x535e74u))
#define g_fightAxisPosX (*(unsigned int *)MK4_VA(unsigned int, 0x535e78u))
#define g_fightAxisPosY (*(unsigned int *)MK4_VA(unsigned int, 0x535e7cu))
#define g_fightStateProgress (*(unsigned int *)MK4_VA(unsigned int, 0x535ddcu))
#define g_framePauseFlag (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_gameCountdown (*(unsigned int *)MK4_VA(unsigned int, 0x53a718u))
#define g_installOwnerNode (*(unsigned int *)MK4_VA(unsigned int, 0x535cf8u))
#define g_lastGatedTick (*(unsigned int *)MK4_VA(unsigned int, 0x54358cu))
#define g_lastGatedValue (*(unsigned int *)MK4_VA(unsigned int, 0x543598u))
#define g_rangeBase (*(unsigned int *)MK4_VA(unsigned int, 0x53a46cu))
#define g_rangeSqLimit (*(unsigned int *)MK4_VA(unsigned int, 0x53a180u))
#define g_stateCountdown (*(unsigned int *)MK4_VA(unsigned int, 0x53a3c0u))
#define g_tickFlagF (*(unsigned int *)MK4_VA(unsigned int, 0x52aac4u))
#define g_walkCallback (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_xformScratch94 (*(unsigned int *)MK4_VA(unsigned int, 0x542094u))
#endif

extern void BootInitGuardedCallChain(void);
extern void CopyGlobal(void);
extern void TablePushAccumTailJmp(void);
extern void TestCmpZeroFour(void);

#ifdef NON_MATCHING
#include "portable/mem_model.h"
extern void CopyGlobal(void);
extern void BootInitGuardedCallChain(void);
extern void TablePushAccumTailJmp(void);
extern void TestCmpZeroFour(void);

/* @addr 0x004a41a0 (182b) - NATIVE twin; the matching build keeps the
 * __asm body below.
 *
 * The character-select handoff. Publishes the six staged selections into
 * the live slots the match loader reads (both fighters' ids and alt ids,
 * plus the two destination records), points the walk at the staged arena
 * index, runs the accumulate and compare passes, schedules the match
 * dispatcher, and finally puts the game-mode tag back to -1 - the "run
 * every scheduled node" value that un-parks the node CallSetPause parked. */
void AudioInitSequence(void)
{
    *MK4_VA(unsigned char, 0x542040u) = 1;
    g_walkCallback = 0;
    CopyGlobal();
    BootInitGuardedCallChain();

    *MK4_VA(unsigned int, 0x541ec4u) = *MK4_VA(unsigned int, 0x541eccu);
    *MK4_VA(unsigned int, 0x541ec8u) = *MK4_VA(unsigned int, 0x541ed0u);
    *MK4_VA(unsigned int, 0x537f48u) = *MK4_VA(unsigned int, 0x53a790u);
    *MK4_VA(unsigned int, 0x5380e0u) = *MK4_VA(unsigned int, 0x537ea0u);
    *MK4_VA(unsigned int, 0x53a178u) = *MK4_VA(unsigned int, 0x537edcu);
    *MK4_VA(unsigned int, 0x53a250u) = *MK4_VA(unsigned int, 0x53a1ccu);
    g_walkCallback = *MK4_VA(unsigned int, 0x53a51cu);

    TablePushAccumTailJmp();
    if (g_framePauseFlag != 0) return;
    TestCmpZeroFour();
    if (g_framePauseFlag != 0) return;

    StoreTwoCall(0x4202c0u, 0x1000u);
    *MK4_VA(unsigned int, 0x543800u) = 0xffffffffu;
    g_walkCallback = 0;
    *MK4_VA(unsigned int, 0x52aac4u) = 0;
}
#else
void AudioInitSequence(void) {
    __asm {
        mov     byte ptr [g_audioInitSeqByte], 1
        mov     dword ptr [g_walkCallback], 0
        call    CopyGlobal
        call    BootInitGuardedCallChain
        mov     eax, dword ptr [g_audioInitState2]
        mov     ecx, dword ptr [g_audioInitState1]
        mov     edx, dword ptr [g_audioInitState3]
        mov     dword ptr [g_dlChar13], eax
        mov     eax, dword ptr [g_audioInitState6]
        mov     dword ptr [g_dlChar24], ecx
        mov     ecx, dword ptr [g_audioInitState5]
        mov     dword ptr [g_dlNalt1], edx
        mov     edx, dword ptr [g_audioInitState4]
        mov     dword ptr [g_dlNalt2], eax
        mov     eax, dword ptr [g_counter_0053a51c]
        mov     dword ptr [g_dlNalt3], ecx
        mov     dword ptr [g_dlNalt4], edx
        mov     dword ptr [g_walkCallback], eax
        call    TablePushAccumTailJmp
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   3eh
        call    TestCmpZeroFour
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   30h
        push    0x1000
        push    0x004202c0
        call    StoreTwoCall
        add     esp, 8
        mov     dword ptr [g_gameMode], 0xffffffff
        mov     dword ptr [g_walkCallback], 0
        mov     dword ptr [g_tickFlagF], 0
        }
}
#endif

