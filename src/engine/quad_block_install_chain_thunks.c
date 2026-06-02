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
extern void CopyJmp_0048ef90(void);
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
extern void GuardedDispatch_0042b6c0(void);
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

extern void Wrapper_ScaledChainPushCall_004ef8e0(void);
extern void ScaledDecOrZero(void);
extern void ScaledAndAlf7(void);
extern void DirtyToggleByGate(void);
extern void QuadBlockInstallChainThunks(void);
extern void DualPushCallPause(void);

/* @addr 0x00483b80 (264b game) - dual block: counter inc thunk + cj cascade dispatch.
 *   B1 (0..0x1a, +5 NOPs): ++baseSel[+0x7c]; g_walkCallback = new value; ret.
 *   B2 (0x20..0x107): cascade of guarded calls ending in 3-way dispatch:
 *     baseSel[+0x80] vs g_eventQueueChild (set per state bits): if less, jmp QuadBlockInstallChainThunks.
 *     Else if baseSel[+0x34] != 0xf: jmp QuadBlockInstallChainThunks. Else: push 0x004ee780, tail-call ArgSarStoreJmp.
 */
extern void ArgSarStoreJmp(void);
extern void FlagCascadeStateSet(void);
extern void SixBlockCjCascade(void);

__declspec(naked) void IncThunkPlusCjDispatch(void) {
    __asm {
        mov     ecx, dword ptr [g_baseSel]
        mov     eax, dword ptr [ecx*4 + 0x7c]
        inc     eax
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x7c], eax
        ret
        nop
        nop
        nop
        nop
        nop
        call    Wrapper_ScaledChainPushCall_004ef8e0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   0d5h
        _emit   00h
        _emit   00h
        _emit   00h
        call    SixBlockCjCascade
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   0c3h
        _emit   00h
        _emit   00h
        _emit   00h
        test    byte ptr [g_xformDirtyFlags], 1
        _emit   74h
        _emit   05h
        jmp     DualPushCallPause
        call    ScaledDecOrZero
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   0a3h
        _emit   00h
        _emit   00h
        _emit   00h
        call    ScaledAndAlf7
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   91h
        _emit   00h
        _emit   00h
        _emit   00h
        mov     dword ptr [g_eventQueueChild], 0x3333
        call    FlagCascadeStateSet
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   79h
        test    byte ptr [g_xformDirtyFlags], 1
        _emit   74h
        _emit   0ah
        mov     dword ptr [g_eventQueueChild], 0x2666
        call    DirtyToggleByGate
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   58h
        test    byte ptr [g_xformDirtyFlags], 4
        _emit   74h
        _emit   0ah
        mov     dword ptr [g_eventQueueChild], 0x2666
        mov     ecx, dword ptr [g_baseSel]
        mov     edx, dword ptr [g_eventQueueChild]
        mov     eax, dword ptr [ecx*4 + 0x80]
        cmp     eax, edx
        mov     dword ptr [g_walkCallback], eax
        _emit   7ch
        _emit   05h
        jmp     QuadBlockInstallChainThunks
        mov     ecx, dword ptr [ecx*4 + 0x34]
        cmp     ecx, 0x0f
        mov     dword ptr [g_walkCallback], ecx
        _emit   75h
        _emit   05h
        jmp     QuadBlockInstallChainThunks
        push    0x004ee780
        call    ArgSarStoreJmp
        add     esp, 4
        ret
    }
}
