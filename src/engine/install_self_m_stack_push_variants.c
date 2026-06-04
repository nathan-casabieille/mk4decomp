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

/* @addr 0x0046cc80 (162b game) - install-self with mstack-push:
 *   chain[sel].slot84 -> eax; clear. If !=0: jmp CjInstallSelfRouter.
 *   Else: Wrapper_ScaledChainPushCall_004ef898; pause? ret.
 *   g_eventQueueCurrent = 0x17; install self at +8.
 *   chain[base].slot84 = 1; mstack-push (self + 0x01000000); ++chain[sel].slot4;
 *   chain[base].slot84 = 0; ScaledArrStore_EsiInstallBitCallChain_00428e70; g_framePauseFlag = 1; ret.
 */
extern void CjInstallSelfRouter(void);
extern void FiveCallGuardSetTail(void);
extern void PushPopWalkSet1006(void);
extern void ScaledArrStore_EsiInstallBitCallChain_00428e70(void);
extern void ScaledLoadJmp_00428d20(void);
extern void Wrapper_ScaledChainPushCall_004ef898(void);

extern unsigned int g_arr_41aaf0_mstack;

__declspec(naked) void InstallSelfMStackPush_CjInstallSelfRouter(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel]
        push    esi
        lea     esi, [eax*4]
        mov     eax, [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], 0
        test    eax, eax
        _emit   74h
        _emit   07h
        call    CjInstallSelfRouter
        pop     esi
        ret
        call    Wrapper_ScaledChainPushCall_004ef898
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   69h
        mov     dword ptr [g_eventQueueCurrent], 0x17
        mov     dword ptr [esi + 8], offset InstallSelfMStackPush_CjInstallSelfRouter
        mov     ecx, dword ptr [g_baseSel]
        mov     edx, offset InstallSelfMStackPush_CjInstallSelfRouter
        add     edx, 0x01000000
        mov     dword ptr [ecx*4 + 0x84], 1
        mov     eax, dword ptr [esi + 4]
        mov     dword ptr [g_currentNodeIdx], eax
        mov     [eax*4 + g_arr_41aaf0_mstack], edx
        mov     eax, dword ptr [g_currentNodeIdx]
        inc     eax
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [esi + 4], eax
        mov     eax, dword ptr [g_baseSel]
        mov     dword ptr [eax*4 + 0x84], 0
        call    ScaledArrStore_EsiInstallBitCallChain_00428e70
        mov     dword ptr [g_framePauseFlag], 1
        pop     esi
        ret
    }
}

/* @addr 0x00496630 (152b game) - install-self twin of 0x41aaf0 with
 *   different early-out / second call targets.
 */
__declspec(naked) void InstallSelfMStackPush_FiveCallGuardSetTail_00496630(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel]
        push    esi
        lea     esi, [eax*4]
        mov     eax, [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], 0
        test    eax, eax
        _emit   74h
        _emit   07h
        call    FiveCallGuardSetTail
        pop     esi
        ret
        call    PushPopWalkSet1006
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   5fh
        mov     dword ptr [esi + 8], offset InstallSelfMStackPush_FiveCallGuardSetTail_00496630
        mov     ecx, dword ptr [g_baseSel]
        mov     edx, offset InstallSelfMStackPush_FiveCallGuardSetTail_00496630
        mov     dword ptr [ecx*4 + 0x84], 1
        mov     eax, dword ptr [esi + 4]
        add     edx, 0x01000000
        mov     dword ptr [g_currentNodeIdx], eax
        mov     [eax*4 + g_arr_41aaf0_mstack], edx
        mov     eax, dword ptr [g_currentNodeIdx]
        inc     eax
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [esi + 4], eax
        mov     eax, dword ptr [g_baseSel]
        mov     dword ptr [eax*4 + 0x84], 0
        call    ScaledLoadJmp_00428d20
        mov     dword ptr [g_framePauseFlag], 1
        pop     esi
        ret
    }
}

/* @addr 0x004968a0 (152b game) - install-self twin of 0x496630. */
__declspec(naked) void InstallSelfMStackPush_FiveCallGuardSetTail_004968a0(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel]
        push    esi
        lea     esi, [eax*4]
        mov     eax, [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], 0
        test    eax, eax
        _emit   74h
        _emit   07h
        call    FiveCallGuardSetTail
        pop     esi
        ret
        call    PushPopWalkSet1006
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   5fh
        mov     dword ptr [esi + 8], offset InstallSelfMStackPush_FiveCallGuardSetTail_004968a0
        mov     ecx, dword ptr [g_baseSel]
        mov     edx, offset InstallSelfMStackPush_FiveCallGuardSetTail_004968a0
        mov     dword ptr [ecx*4 + 0x84], 1
        mov     eax, dword ptr [esi + 4]
        add     edx, 0x01000000
        mov     dword ptr [g_currentNodeIdx], eax
        mov     [eax*4 + g_arr_41aaf0_mstack], edx
        mov     eax, dword ptr [g_currentNodeIdx]
        inc     eax
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [esi + 4], eax
        mov     eax, dword ptr [g_baseSel]
        mov     dword ptr [eax*4 + 0x84], 0
        call    ScaledLoadJmp_00428d20
        mov     dword ptr [g_framePauseFlag], 1
        pop     esi
        ret
    }
}
