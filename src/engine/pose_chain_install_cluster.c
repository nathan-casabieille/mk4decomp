/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;
extern unsigned int g_baseSel;
extern unsigned int g_acc_00542078;
extern unsigned int g_cj_0054205c;
extern unsigned int g_gameCountdown;
extern unsigned int g_xformScratch94;
extern unsigned int g_table_00535ddc;
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
extern void CallPauseDirty1JmpDirty4StackPush_00483a80(void);
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
extern void DispatcherComplex260_00407030(void);
extern void ScaledLoadCmpStoreXfm(void);
extern void StackPopDispatchTagged(void);
extern unsigned int g_cj_00542058;
extern unsigned int g_rangeSqLimit;
extern unsigned int g_zero_00541fa4;
extern unsigned int g_zero_00541fa8;
extern unsigned int g_dualBitGate;
extern unsigned int g_eventArmReload;
extern unsigned int g_rangeBase;

extern void ScaledArrStore_ScaledChainJmp_004298c0(void);
extern void DualFieldAddSubStore(void);
extern void IterStepDualStore(int);
extern void ScaledXorStore_004900f0(void);
extern void ChainWalkInstall(void);
extern void FpuSqrtMul(void);
extern void PendingMatch_0042b930(void);
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
extern void MStackPushZeroCallPop_00407d00(void);
extern void DirtyToggleByGate(void);
extern void GameDispatchValidateState(void);
extern void CrouchAttackFsmCluster(void);
extern void MStackPushVec3Mul10(void);
extern void LiteralPushCallEntZero(void);
extern void LeaPlus22StoreSelf(void);
extern void IterLoad_00491050(void);
extern void GuardedDualConst2AndToggle(void);
extern void CallPauseScaledStorePushCall(void);
extern void LoadGeoAsset_Default(void);
extern void DispatcherComplex260_00407400(void);
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

/* ------------------------------------------------------------------ */
/* Per-tick main chain (750b game, 2 packed helpers):                 */
/*  h1 (0x481070): 14-stage pause-guarded chain (490130 → 494580 →    */
/*                 48f720 → 4903xx series → 486530 → 481360 → 470310 →*/
/*                 0040eb80 → 00427b60 → 0048e2f0 → 49cb40 timer install). */
/*  h2 (0x481340): wait + tail-jmp CallSetPause.                     */
/* ------------------------------------------------------------------ */
extern void PendingMatch_0040eb80(void);
extern void PoseChainInstallCluster(void);
extern void ScaledChainNegStore(void);
extern void CallPauseConstStoreJmp_BootChainMaskAndDispatch_then_MStackBitLoopTripleCall(void);
extern void ScaledLoadCmp1003JmpDispatch(void);
extern void PushCallPauseScaledJmpInd(void);
extern void ScaledInit_GuardedDirtyXformFromTable_g_scaledInit(void);
extern void ClearBit2x34(void);
extern void MStackPushSet0004(void);
extern void ScaledAndAl7f(void);
extern void ScaledAndAldf(void);
extern void ScaledAndAlbf(void);
extern void ScaledAndAlfe(void);
extern unsigned int g_or;
extern unsigned int g_pendingMatchCmp;

extern s32 g_dlNalt1;
extern s32 g_dlNalt2;
extern void CallSetPause(void);
extern void DualCallPauseDirtyJmp_00490c30(void);
extern void GateDispatch6c(void);
extern void ScaledAndAlf7(void);
extern void ScaledLitLoadCall_ScaledChainCallPauseSetJmp_then_Wrapper_IterLoad_0048fd30_00480fe0(void);

__declspec(naked) void MainTickChain(void)
{
    __asm {
        push     esi
        call     ClearBit2x34
        mov      eax, dword ptr [g_framePauseFlag]
        xor      esi, esi
        cmp      eax, esi
        jne      L_1336
        mov      eax, dword ptr [g_baseSel]
        mov      eax, dword ptr [eax*4 + 0x30]
        cmp      eax, esi
        mov      dword ptr [g_currentNodeIdx], eax
        je       short L_10bc
        mov      eax, dword ptr [eax*4]
        cmp      eax, 0x6c
        mov      dword ptr [g_walkCallback], eax
        jne      short L_10bc
        call     GateDispatch6c
        cmp      dword ptr [g_framePauseFlag], esi
        jne      L_1336
    L_10bc:
        call     ScaledInit_GuardedDirtyXformFromTable_g_scaledInit
        cmp      dword ptr [g_framePauseFlag], esi
        jne      L_1336
        call     ScaledAndAldf
        cmp      dword ptr [g_framePauseFlag], esi
        jne      L_1336
        call     ScaledAndAlbf
        cmp      dword ptr [g_framePauseFlag], esi
        jne      L_1336
        call     ScaledAndAl7f
        cmp      dword ptr [g_framePauseFlag], esi
        jne      L_1336
        call     ScaledAndAlfe
        cmp      dword ptr [g_framePauseFlag], esi
        jne      L_1336
        call     ScaledAndAlf7
        cmp      dword ptr [g_framePauseFlag], esi
        jne      L_1336
        call     MStackPushSet0004
        cmp      dword ptr [g_framePauseFlag], esi
        jne      L_1336
        cmp      dword ptr [g_pendingMatchCmp], esi
        jne      short L_114c
        call     DualCallPauseDirtyJmp_00490c30
        cmp      dword ptr [g_framePauseFlag], esi
        jne      L_1336
    L_114c:
        mov      dword ptr [g_pendingMatchCmp], esi
        call     ScaledLoadCmp1003JmpDispatch
        cmp      dword ptr [g_framePauseFlag], esi
        jne      L_1336
        mov      ecx, dword ptr [g_baseSel]
        mov      eax, dword ptr [ecx*4 + 0x34]
        cmp      eax, 0x10
        mov      dword ptr [g_walkCallback], eax
        jne      short L_1184
        mov      eax, 2
        mov      dword ptr [g_walkCallback], eax
    L_1184:
        cmp      eax, 0x11
        jne      short L_1193
        mov      eax, 7
        mov      dword ptr [g_walkCallback], eax
    L_1193:
        cmp      eax, esi
        jne      short L_11a8
        call     CallPauseConstStoreJmp_BootChainMaskAndDispatch_then_MStackBitLoopTripleCall
        cmp      dword ptr [g_framePauseFlag], esi
        jne      L_1336
    L_11a8:
        mov      edx, dword ptr [g_baseSel]
        mov      ecx, dword ptr [edx*4 + 0x74]
        lea      eax, [edx*4]
        mov      dword ptr [eax + 0x60], ecx
        mov      dword ptr [g_walkCallback], esi
        mov      dword ptr [eax + 0x5c], esi
        mov      edx, dword ptr [g_walkCallback]
        mov      dword ptr [eax + 0x74], edx
        mov      ecx, dword ptr [g_walkCallback]
        mov      dword ptr [eax + 0x4c], ecx
        mov      edx, dword ptr [g_fightGroupHead]
        mov      dword ptr [edx*4 + 0x44], esi
        mov      dword ptr [g_walkCallback], esi
        lea      eax, [edx*4]
        mov      dword ptr [eax + 0x78], esi
        mov      ecx, dword ptr [g_walkCallback]
        mov      dword ptr [eax + 0x80], ecx
        mov      edx, dword ptr [g_walkCallback]
        mov      dword ptr [eax + 0x60], edx
        mov      ecx, dword ptr [g_walkCallback]
        mov      dword ptr [eax + 0x68], ecx
        call     ScaledChainNegStore
        cmp      dword ptr [g_framePauseFlag], esi
        jne      L_1336
        mov      edx, dword ptr [g_fightGroupHead]
        mov      ecx, dword ptr [g_player1NodeIdx]
        mov      eax, dword ptr [g_dlNalt1]
        cmp      edx, ecx
        mov      dword ptr [g_walkCallback], eax
        je       short L_124a
        mov      eax, dword ptr [g_dlNalt2]
        mov      dword ptr [g_walkCallback], eax
    L_124a:
        cmp      eax, 0xa
        jne      short L_1260
        call     PendingMatch_0040eb80
        cmp      dword ptr [g_framePauseFlag], esi
        jne      L_1336
    L_1260:
        mov      eax, dword ptr [g_or]
        mov      dword ptr [g_walkCallback], eax
        and      eax, 0x2000
        mov      dword ptr [g_xformScratch94], eax
        jne      L_1336
        mov      eax, dword ptr [g_baseSel]
        mov      eax, dword ptr [eax*4 + 0x80]
        cmp      eax, 0x6666
        mov      dword ptr [g_walkCallback], eax
        jle      L_1336
        call     PoseChainInstallCluster
        cmp      dword ptr [g_framePauseFlag], esi
        jne      L_1336
        mov      ecx, dword ptr [g_baseSel]
        mov      eax, dword ptr [ecx*4 + 0x7c]
        cmp      eax, 3
        mov      dword ptr [g_walkCallback], eax
        jl       short L_12cb
        call     PushCallPauseScaledJmpInd
        cmp      dword ptr [g_framePauseFlag], esi
        jne      short L_1336
    L_12cb:
        mov      edx, dword ptr [g_baseSel]
        push     0x31
        push     OFFSET L_1340
        mov      dword ptr [edx*4 + 0x80], esi
        mov      eax, dword ptr [g_baseSel]
        mov      dword ptr [g_walkCallback], esi
        mov      dword ptr [eax*4 + 0x7c], esi
        call     StoreTwoCall
        mov      ecx, dword ptr [g_baseSel]
        mov      edx, dword ptr [g_currentNodeIdx]
        add      esp, 8
        mov      eax, dword ptr [ecx*4 + 0x3c]
        mov      dword ptr [g_xformEntityIdx], eax
        mov      dword ptr [edx*4 + 0x3c], eax
        mov      eax, dword ptr [g_baseSel]
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      eax, dword ptr [eax*4 + 0x38]
        mov      dword ptr [g_xformEntityIdx], eax
        mov      dword ptr [ecx*4 + 0x38], eax
    L_1336:
        pop      esi
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        /* === h2 (0x481340): wait+tail-jmp 0041f830 === */
    L_1340:
        mov      dword ptr [g_walkCallback], 0x2e
        call     ScaledLitLoadCall_ScaledChainCallPauseSetJmp_then_Wrapper_IterLoad_0048fd30_00480fe0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_135d
        jmp      CallSetPause
    L_135d:
        ret
    }
}
