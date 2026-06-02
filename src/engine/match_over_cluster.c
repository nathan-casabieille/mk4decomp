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
extern void SetJmp_0049cb90(void);
extern void Thunk_0049cbd0(void);
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
extern void Wrapper_00436490(void);
extern void MoveFsmCluster(void);
extern void CallPauseTestByteJmpCalls(void);
extern void InstallSelfFullPath(void);
extern void InstallSelfCountdownChain(void);
extern void CopyJmp_0048ef90(void);
extern void DualTestDirtyToggle_004282c0(void);
extern void TripleVecAccCallStore(void);
extern void Thunk_004bd5c0(void);
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

extern void ScaledArrStore_004298c0(void);
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
extern void Wrapper_0048a350(void);
extern void Wrapper_0048a3a0(void);
extern void Helper_DownloadSetup(void);
extern void MStackPush3CmpCall(void);
extern void Wrapper_0048ec20(void);
extern void FiveCallScaledChainTailJmp(void);
extern void SetJmp_00438f50(void);
extern void SetJmp_00438f60(void);
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

extern void TripleCallPauseJmp(void);
extern void Wrapper_0048a3c0(void);
extern void PhaseDispatchListAdvance(void);
extern void CallPauseDirtyMStackPushFn(void);
extern void InstallSelfMStackOverwrite(void);
extern void MatchOverCluster_0046ef70(void);
extern void MStackJmpInstallSelf_0046ed40(void);

/* @addr 0x0046ec20 (275b game) - 5 adjacent blocks.
 *   B1 (0..0x4f, 64+15 NOPs): call ScaledAndAlfe; if !pause: cj[+0x74]=0x604;
 *     call TripleCallPauseJmp; if !pause: push 0x004eb6d8, tail-call ArgSarStoreJmp.
 *   B2 (0x50..0x7f): call Wrapper_0048a3c0; if !pause: g_eventQueueEnd = 0x004eb6e8>>2;
 *     tail-jmp PhaseDispatchListAdvance.
 *   B3 (0x80..0xbf): if bit0 of state set: tail-jmp CallPauseDirtyMStackPushFn.
 *     Else: g_eventQueueChild=8, g_eventQueueNotMask=8, mstack-push 0x0046ece0 (B4 addr);
 *     tail-jmp InstallSelfMStackOverwrite.
 *   B4 (0xc0..0xff): if bit0 of state set: tail-jmp MatchOverCluster_0046ef70.
 *     Else: g_eventQueueChild=9, g_eventQueueNotMask=8, mstack-push 0x0046ed20 (B5 addr);
 *     tail-jmp InstallSelfMStackOverwrite.
 *   B5 (0x100..0x112): if bit0 of state set: tail-jmp MatchOverCluster_0046ef70.
 *     Else: tail-jmp MStackJmpInstallSelf_0046ed40.
 */
extern void ArgSarStoreJmp(void);
extern void ScaledAndAlfe(void);

__declspec(naked) void FiveBlockDispatchChain_0046ec20(void) {
    __asm {
        call    ScaledAndAlfe
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   32h
        mov     ecx, dword ptr [g_baseSel]
        mov     eax, 0x604
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x74], eax
        call    TripleCallPauseJmp
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   0dh
        push    0x004eb6d8
        call    ArgSarStoreJmp
        add     esp, 4
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        call    Wrapper_0048a3c0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   12h
        mov     eax, 0x004eb6e8
        sar     eax, 2
        mov     dword ptr [g_eventQueueEnd], eax
        jmp     PhaseDispatchListAdvance
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        test    byte ptr [g_xformDirtyFlags], 1
        _emit   74h
        _emit   05h
        jmp     CallPauseDirtyMStackPushFn
        mov     eax, 8
        mov     dword ptr [g_eventQueueChild], eax
        mov     dword ptr [g_eventQueueNotMask], eax
        mov     eax, dword ptr [g_matrixStackTop]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        _emit   0c7h
        _emit   04h
        _emit   85h
        _emit   00h
        _emit   00h
        _emit   00h
        _emit   00h
        _emit   0e0h
        _emit   0ech
        _emit   46h
        _emit   00h
        jmp     InstallSelfMStackOverwrite
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        test    byte ptr [g_xformDirtyFlags], 1
        _emit   74h
        _emit   05h
        jmp     MatchOverCluster_0046ef70
        mov     eax, dword ptr [g_matrixStackTop]
        mov     dword ptr [g_eventQueueChild], 9
        inc     eax
        mov     dword ptr [g_eventQueueNotMask], 8
        mov     dword ptr [g_matrixStackTop], eax
        _emit   0c7h
        _emit   04h
        _emit   85h
        _emit   00h
        _emit   00h
        _emit   00h
        _emit   00h
        _emit   20h
        _emit   0edh
        _emit   46h
        _emit   00h
        jmp     InstallSelfMStackOverwrite
        nop
        nop
        nop
        test    byte ptr [g_xformDirtyFlags], 1
        _emit   74h
        _emit   05h
        jmp     MatchOverCluster_0046ef70
        jmp     MStackJmpInstallSelf_0046ed40
    }
}
