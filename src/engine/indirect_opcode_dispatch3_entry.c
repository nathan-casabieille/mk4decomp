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

extern void IndirectOpcodeDispatch3Entry(void);
extern unsigned int g_state2_00541d88;
extern unsigned int g_state2_00537ea8;

/* @addr 0x0049f260 (306b game) - state cascade switch + dual-arm thunks (no prologue: continuation of 0x0049f1f0).
 *   Multi-cmp on eax: ==ebx → branch_A; ==2/3/4 → +0xe then call LinkedListIndirectDirtyToggle; ==5 → use esi.
 *     <5 → CallSetPause; ==0xa/0xf → -5; ==0x12 → -4; >0x12 → CallSetPause.
 *   After call LinkedListIndirectDirtyToggle: if pause CallSetPause; if !bit0(0054208c) loop to start.
 *   Else: chain[scaledInit*4]=g_walkCallback; copy g_dispatchArg to g_eventQueueCurrent;
 *     call RoundWinTransition; if pause CallSetPause; load chain[g_xformEntityIdx*4+8];
 *     call GuardedScaledCall; if !pause CallSetPause; pop esi/ebx; ret.
 *   Tail thunk_1 (+0xe0): if g_state2_00541d88!=0 jmp CallSetPause else g_dispatchArg=0; jmp IndirectOpcodeDispatch3Entry.
 *   Tail thunk_2 (+0x110): if g_state2_00537ea8!=0 jmp CallSetPause else g_dispatchArg=1; jmp IndirectOpcodeDispatch3Entry.
 */
extern unsigned int g_dispatchArg;
extern void CallSetPause(void);
extern void GuardedScaledCall(void);
extern void LinkedListIndirectDirtyToggle(void);
extern void RoundWinTransition(void);

__declspec(naked) void StateCascadeDualThunkContin(void) {
    __asm {
        cmp     eax, ebx
        _emit   74h
        _emit   3ch
        cmp     eax, 2
        _emit   74h
        _emit   0ah
        cmp     eax, 3
        _emit   74h
        _emit   05h
        cmp     eax, 4
        _emit   75h
        _emit   28h
        add     eax, 0xe
        mov     dword ptr [g_walkCallback], eax
        call    LinkedListIndirectDirtyToggle
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   0aeh
        _emit   00h
        _emit   00h
        _emit   00h
        _emit   84h
        _emit   1dh
        _emit   8ch
        _emit   20h
        _emit   54h
        _emit   00h
        _emit   0fh
        _emit   85h
        _emit   9dh
        _emit   00h
        _emit   00h
        _emit   00h
        _emit   0ebh
        _emit   2fh
        cmp     eax, 5
        _emit   75h
        _emit   08h
        mov     dword ptr [g_walkCallback], esi
        _emit   0ebh
        _emit   22h
        _emit   0fh
        _emit   82h
        _emit   88h
        _emit   00h
        _emit   00h
        _emit   00h
        cmp     eax, 0xa
        _emit   76h
        _emit   0fh
        cmp     eax, 0xf
        _emit   76h
        _emit   0ah
        cmp     eax, 0x12
        _emit   77h
        _emit   79h
        sub     eax, 4
        _emit   0ebh
        _emit   03h
        sub     eax, 5
        mov     dword ptr [g_walkCallback], eax
        call    LinkedListIndirectDirtyToggle
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   63h
        _emit   84h
        _emit   1dh
        _emit   8ch
        _emit   20h
        _emit   54h
        _emit   00h
        _emit   74h
        _emit   0ah
        mov     eax, dword ptr [g_walkCallback]
        _emit   0e9h
        _emit   76h
        _emit   0ffh
        _emit   0ffh
        _emit   0ffh
        mov     eax, dword ptr [g_currentNodeIdx]
        mov     ecx, dword ptr [g_walkCallback]
        mov     dword ptr [eax*4 + 0], ecx
        mov     edx, dword ptr [g_dispatchArg]
        mov     dword ptr [g_eventQueueCurrent], edx
        call    RoundWinTransition
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   25h
        mov     eax, dword ptr [g_xformEntityIdx]
        mov     ecx, dword ptr [eax*4 + 8]
        mov     dword ptr [g_walkCallback], ecx
        call    GuardedScaledCall
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   05h
        call    CallSetPause
        pop     esi
        pop     ebx
        ret
        _emit   90h
        _emit   90h
        mov     eax, dword ptr [g_state2_00541d88]
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        _emit   74h
        _emit   05h
        jmp     CallSetPause
        mov     dword ptr [g_dispatchArg], 0
        jmp     IndirectOpcodeDispatch3Entry
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
        _emit   90h
        mov     eax, dword ptr [g_state2_00537ea8]
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        _emit   74h
        _emit   05h
        jmp     CallSetPause
        mov     dword ptr [g_dispatchArg], 1
        _emit   0e9h
        _emit   0eh
        _emit   00h
        _emit   00h
        _emit   00h
    }
}
