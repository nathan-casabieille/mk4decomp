/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
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

/* @addr 0x00464190 (173b game) - sequenced init: call BootInitGuardedCallChain; pause-check;
 *   call Init4Globals; pause-check; setup scaledInit/0053a734/0053a350 from g_eventQueueSeed;
 *   init 5 fields of struct[*4+0x54..0x68]; call CopyGlobal; pause-check;
 *   scaledInit = 0x0050b124>>2; call LoadGeoAsset_Default; pause-check; repeat; ret.
 */
extern unsigned int g_eventQueueSeed;
extern unsigned int g_dispatchSave42;
extern unsigned int g_dispatchSave40;
extern void BootInitGuardedCallChain(void);
extern void CopyGlobal(void);
extern void Init4Globals(void);

__declspec(naked) void SequencedInit3Call(void) {
    __asm {
        push    esi
        call    BootInitGuardedCallChain
        mov     eax, dword ptr [g_framePauseFlag]
        xor     esi, esi
        cmp     eax, esi
        _emit   0fh
        _emit   85h
        _emit   96h
        _emit   00h
        _emit   00h
        _emit   00h
        call    Init4Globals
        cmp     dword ptr [g_framePauseFlag], esi
        _emit   0fh
        _emit   85h
        _emit   85h
        _emit   00h
        _emit   00h
        _emit   00h
        mov     eax, dword ptr [g_eventQueueSeed]
        mov     dword ptr [g_dispatchSave40], esi
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [g_dispatchSave42], esi
        shl     eax, 2
        mov     dword ptr [eax + 0x54], esi
        mov     dword ptr [eax + 0x58], 0xfffe199a
        mov     dword ptr [eax + 0x5c], 0xfffc0000
        mov     dword ptr [g_walkCallback], esi
        mov     dword ptr [eax + 0x60], esi
        mov     ecx, dword ptr [g_walkCallback]
        mov     dword ptr [eax + 0x64], ecx
        mov     edx, dword ptr [g_walkCallback]
        mov     dword ptr [eax + 0x68], edx
        mov     dword ptr [g_walkCallback], esi
        call    CopyGlobal
        cmp     dword ptr [g_framePauseFlag], esi
        _emit   75h
        _emit   2dh
        mov     eax, 0x0050b124
        shr     eax, 2
        mov     dword ptr [g_currentNodeIdx], eax
        call    LoadGeoAsset_Default
        cmp     dword ptr [g_framePauseFlag], esi
        _emit   75h
        _emit   13h
        mov     ecx, 0x0050b124
        shr     ecx, 2
        mov     dword ptr [g_currentNodeIdx], ecx
        call    LoadGeoAsset_Default
        pop     esi
        ret
    }
}
