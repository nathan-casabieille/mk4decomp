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

/* @addr 0x00496fc0 (303b game) - multi-thunk dispatcher with 5 small blocks.
 *   Block A (0..0x13): call MStackCall; if !pause tail-jmp CallSetPause; ret.
 *   Block B (+0x20): call CondPickDualStore; if pause ret. Set chain[+0x74]=0x314,
 *     g_walkCallback=0x314; push 0x004f2078; call ArgSarStoreJmp; pop; ret.
 *   Block C (+0x50): call DualCmpSwapStore; if pause ret. Push 0x004f20a0;
 *     call ScaledStackCallPause; pop; if pause ret. If bit2(0054208c) jmp CallSetPause.
 *     mul10[3333,x84]; chain[+0x6c]=result. mul10[3333,x88]; chain[+0x74]=result;
 *     g_cj=scaledInit; push 0x004f20b0; call ArgSar_Set0_Jmp; pop; ret.
 *   Block D (+0xd0): g_walkCallback=0x312; jmp +0x11. (1-NOP)
 *   Block E (+0xe5): g_walkCallback=0x311; jmp +1 (to next fn at 0x004970f0).
 */
extern unsigned int g_dispatchSave697;
extern void ArgSarStoreJmp(void);
extern void ArgSar_Set0_Jmp(void);
extern void ArgScaledTestStore(void);
extern void CallPauseCallTestStackPushJmp(void);
extern void CallPauseMStackPushSet0Jmp(void);
extern void CallSetPause(void);
extern void CondPickDualStore(void);
extern void DualCmpSwapStore(void);
extern void DualScaledStoreZero(void);
extern void GuardedDispatch_CallPauseMStackPushSet3Jmp(void);
extern void GuardedDispatch_CallPauseMStackPushSet4Jmp(void);
extern void MStackCall_00406740(void);
extern void NotShrCmp1Store(void);
extern void PerSlotPhaseRouter_DualGatedStateYield_004605d0(void);
extern void PerSlotPhaseRouter_DualGatedStateYield_00460770(void);
extern void ScaledStackCallPause(void);

__declspec(naked) void MultiThunkDispatcher_MStackCall(void) {
    __asm {
        call    MStackCall_00406740
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   05h
        jmp     CallSetPause
        ret
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        call    CondPickDualStore
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   24h
        mov     ecx, dword ptr [g_baseSel]
        mov     eax, 0x314
        mov     dword ptr [g_walkCallback], eax
        push    0x004f2078
        mov     dword ptr [ecx*4 + 0x74], eax
        call    ArgSarStoreJmp
        add     esp, 4
        ret
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        call    DualCmpSwapStore
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   91h
        _emit   00h
        _emit   00h
        _emit   00h
        push    0x004f20a0
        call    ScaledStackCallPause
        mov     eax, dword ptr [g_framePauseFlag]
        add     esp, 4
        test    eax, eax
        _emit   75h
        _emit   7bh
        test    byte ptr [g_xformDirtyFlags], 4
        _emit   74h
        _emit   05h
        jmp     CallSetPause
        mov     eax, dword ptr [g_currentNodeFlags]
        push    eax
        push    0x3333
        call    Mul10Tail
        mov     ecx, dword ptr [g_xformScratch2088]
        add     esp, 8
        mov     dword ptr [g_currentNodeFlags], eax
        push    ecx
        push    0x3333
        call    Mul10Tail
        mov     edx, dword ptr [g_scaledInit_00542044]
        mov     dword ptr [g_xformScratch2088], eax
        mov     eax, dword ptr [g_currentNodeFlags]
        add     esp, 8
        mov     dword ptr [edx*4 + 0x6c], eax
        mov     ecx, dword ptr [g_scaledInit_00542044]
        mov     edx, dword ptr [g_xformScratch2088]
        push    0x004f20b0
        mov     dword ptr [ecx*4 + 0x74], edx
        mov     eax, dword ptr [g_scaledInit_00542044]
        mov     dword ptr [g_cj_0054205c], eax
        call    ArgSar_Set0_Jmp
        add     esp, 4
        ret
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        mov     dword ptr [g_walkCallback], 0x312
        _emit   0e9h
        _emit   11h
        _emit   00h
        _emit   00h
        _emit   00h
        _emit   90h
        mov     dword ptr [g_walkCallback], 0x311
        _emit   0e9h
        _emit   01h
        _emit   00h
        _emit   00h
        _emit   00h
    }
}

/* @addr 0x00460470 (308b game) - multi-thunk: push-call entry + state dispatcher + 6 LeaPlus22 thunks.
 *   Block A (0..0x1c): push 0x00542980; call ArgScaledTestStore; pop; if !pause tail-jmp DualScaledStoreZero; ret.
 *   Block B (0x20..0xbc): call DirtyToggleByGate; if pause ret. If bit2(0054208c) ret.
 *     g_eventQueueTotal = (0x004ea000>>2); call NotShrCmp1Store; if pause ret.
 *     ecx = g_eventQueueTotal + (g_walkCallback & 0xf); jmp [ecx*4].
 *   Block C-H (0xc0..end): 6 thunks, each "call LeaPlus22StoreSelf; if !pause tail-jmp <target>; ret".
 */
__declspec(naked) void MultiThunkDispatcher_ArgScaledTestStore(void) {
    __asm {
        push    0x00542980
        call    ArgScaledTestStore
        mov     eax, dword ptr [g_framePauseFlag]
        add     esp, 4
        test    eax, eax
        _emit   75h
        _emit   05h
        jmp     DualScaledStoreZero
        ret
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        call    DirtyToggleByGate
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   4eh
        test    byte ptr [g_xformDirtyFlags], 4
        _emit   75h
        _emit   45h
        mov     eax, offset g_dispatchSave697
        shr     eax, 2
        mov     dword ptr [g_eventQueueTotal], eax
        call    NotShrCmp1Store
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   2ah
        mov     eax, dword ptr [g_walkCallback]
        mov     ecx, dword ptr [g_eventQueueTotal]
        and     eax, 0xf
        add     ecx, eax
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [g_eventQueueTotal], ecx
        mov     ecx, dword ptr [ecx*4 + 0]
        mov     dword ptr [g_eventQueueTotal], ecx
        jmp     ecx
        ret
        _emit   90h
        _emit   90h
        _emit   90h
        call    LeaPlus22StoreSelf
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   05h
        jmp     CallPauseCallTestStackPushJmp
        ret
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        call    LeaPlus22StoreSelf
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   05h
        jmp     CallPauseMStackPushSet0Jmp
        ret
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        call    LeaPlus22StoreSelf
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   05h
        jmp     PerSlotPhaseRouter_DualGatedStateYield_00460770
        ret
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        call    LeaPlus22StoreSelf
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   05h
        jmp     GuardedDispatch_CallPauseMStackPushSet4Jmp
        ret
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        call    LeaPlus22StoreSelf
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   05h
        jmp     PerSlotPhaseRouter_DualGatedStateYield_004605d0
        ret
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        call    LeaPlus22StoreSelf
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   05h
        jmp     GuardedDispatch_CallPauseMStackPushSet3Jmp
        ret
    }
}
