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

/* @addr 0x00403c90 (196b boot) - five TableWalk calls then five pause-gated calls.
 *   For tag in [2,3,4,5,7]: push tag; call TableWalkBoundedCmp; add esp, 4.
 *   call BootInitGuardedCallChain; if (pause != 0) -> end clears.
 *   g_scaledInit = packed_ptr(0x00506c20); call LoadGeoAsset_Default; if (pause != 0) skip;
 *   ... (same again); call AudioStateClearAndChainStep; pause? skip;
 *   g_walkCallback = 0; call CopyGlobal; pause? skip;
 *   g_scaledInit = [0x52ab10]; g_walkCallback = 0xfff88000;
 *   chain[g_scaledInit*4 + 0x54/0x58/0x5c/0x60/0x64/0x68] = 0 (or 0xfff88000 for +0x5c).
 */
extern unsigned int g_eventQueueSeed;
extern void AudioStateClearAndChainStep(void);
extern void BootInitGuardedCallChain(void);
extern void CopyGlobal(void);
extern void TableWalkBoundedCmp(void);

__declspec(naked) void FiveTableWalkInit(void) {
    __asm {
        push    esi
        push    2
        call    TableWalkBoundedCmp
        add     esp, 4
        push    3
        call    TableWalkBoundedCmp
        add     esp, 4
        push    4
        call    TableWalkBoundedCmp
        add     esp, 4
        push    5
        call    TableWalkBoundedCmp
        add     esp, 4
        push    7
        call    TableWalkBoundedCmp
        add     esp, 4
        call    BootInitGuardedCallChain
        mov     eax, dword ptr [g_framePauseFlag]
        xor     esi, esi
        cmp     eax, esi
        _emit   75h
        _emit   7fh
        mov     eax, 0x00506c20
        shr     eax, 2
        mov     dword ptr [g_currentNodeIdx], eax
        call    LoadGeoAsset_Default
        cmp     dword ptr [g_framePauseFlag], esi
        _emit   75h
        _emit   65h
        mov     ecx, 0x00506c20
        shr     ecx, 2
        mov     dword ptr [g_currentNodeIdx], ecx
        call    LoadGeoAsset_Default
        cmp     dword ptr [g_framePauseFlag], esi
        _emit   75h
        _emit   4ah
        call    AudioStateClearAndChainStep
        cmp     dword ptr [g_framePauseFlag], esi
        _emit   75h
        _emit   3dh
        mov     dword ptr [g_walkCallback], esi
        call    CopyGlobal
        cmp     dword ptr [g_framePauseFlag], esi
        _emit   75h
        _emit   2ah
        mov     eax, dword ptr [g_eventQueueSeed]
        mov     ecx, 0xfff88000
        mov     dword ptr [g_currentNodeIdx], eax
        shl     eax, 2
        mov     [eax + 0x60], esi
        mov     [eax + 0x64], esi
        mov     [eax + 0x68], esi
        mov     [eax + 0x54], esi
        mov     [eax + 0x58], esi
        mov     dword ptr [g_walkCallback], ecx
        mov     [eax + 0x5c], ecx
        pop     esi
        ret
    }
}
