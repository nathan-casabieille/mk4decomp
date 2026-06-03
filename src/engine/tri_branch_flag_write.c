/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_currentNodeIdx;
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

/* @addr 0x00422720 (142b game) - 3-branch flag set:
 *   If g_audioMatchStartFlag == 1 && g_audioTriEntryFlag == 0:
 *     if g_active_0053a408: call ClampTwoToMax_004226a0; goto setB.
 *     else: write 0x10000 to walkCallback/0x53a6dc/0x53a328.
 *     setB: if g_active_00537e88: call ClampTwoToMax_004226e0; ret.
 *     else: write 0x10000 to walkCallback/0x537f2c/0x53e348; ret.
 *   Else: clear g_audioTriEntryFlag; write 0x10000 to all 5 globals; ret.
 */
extern unsigned int g_active_00537e88;
extern unsigned int g_clamp_00537f2c;
extern unsigned int g_clamp_0053a328;
extern unsigned int g_active_0053a408;
extern unsigned int g_clamp_0053a6dc;
extern unsigned int g_clamp_0053e348;
extern unsigned int g_audioTriEntryFlag;
extern unsigned int g_audioMatchStartFlag;
extern void ClampTwoToMax_004226a0(void);
extern void ClampTwoToMax_004226e0(void);

__declspec(naked) void TriBranchFlagWrite(void) {
    __asm {
        mov     eax, dword ptr [g_audioMatchStartFlag]
        push    esi
        cmp     eax, 1
        _emit   75h
        _emit   54h
        mov     eax, dword ptr [g_audioTriEntryFlag]
        test    eax, eax
        _emit   75h
        _emit   4bh
        mov     eax, dword ptr [g_active_0053a408]
        mov     esi, 0x10000
        test    eax, eax
        _emit   74h
        _emit   07h
        call    ClampTwoToMax_004226a0
        _emit   0ebh
        _emit   12h
        mov     dword ptr [g_walkCallback], esi
        mov     dword ptr [g_clamp_0053a6dc], esi
        mov     dword ptr [g_clamp_0053a328], esi
        mov     eax, dword ptr [g_active_00537e88]
        test    eax, eax
        _emit   74h
        _emit   07h
        call    ClampTwoToMax_004226e0
        pop     esi
        ret
        mov     dword ptr [g_walkCallback], esi
        mov     dword ptr [g_clamp_00537f2c], esi
        mov     dword ptr [g_clamp_0053e348], esi
        pop     esi
        ret
        mov     esi, 0x10000
        mov     dword ptr [g_audioTriEntryFlag], 0
        mov     dword ptr [g_walkCallback], esi
        mov     dword ptr [g_clamp_0053a6dc], esi
        mov     dword ptr [g_clamp_0053a328], esi
        mov     dword ptr [g_clamp_00537f2c], esi
        mov     dword ptr [g_clamp_0053e348], esi
        pop     esi
        ret
    }
}
