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
extern void WalkCbSubMul10_00431d50(void);
extern void Mul10Tail(unsigned int a, unsigned int b);
extern void BootMod6487eClampAndChainMul10(void);
extern void SpawnListBatchLoader_00477710(void);
extern void MStackPush2TableNot(void);
extern void GuardedChainCmpDualBitXor(void);
extern void ScaledLoadDecJmp_00429710(void);
extern void ScaledStoreCurDirtyClear_004296f0(void);
extern void MStackBitmaskIncMod_00492450(void);
extern void MStackBitmaskUpdate_00492510(void);
extern void Push1eCallTestDirtyLoop_004923b0(void);
extern void MStackLoopFieldInit_00492280(void);
extern void TaggedSceneDispatch(void);
extern void CallPauseDirty4StackPushFn_004839d0(void);
extern void CallPauseDirty1JmpDirty4StackPush_00483a80(void);
extern void Cmp2CallDirtyCall(void);
extern void QuadBlockArgInstallChain(void);
extern void InstallSelfChainSet84_80CallW_004363f0(void);
extern void Wrapper_00436490(void);
extern void MoveFsmCluster_004364a0(void);
extern void CallPauseTestByteJmpCalls(void);
extern void InstallSelfFullPath(void);
extern void InstallSelfCountdownChain_0047a950(void);
extern void CopyJmp_0048ef90(void);
extern void DualTestDirtyToggle_004282c0(void);
extern void TripleVecAccCallStore(void);
extern void Thunk_004bd5c0(void);
extern void AllocSlotPushTripleGlobals(void);
extern void MStackPop4Rewrite(void);
extern void Push70CallScaleArith(void);
extern void StreamChainStringInstall(void);
extern void MStackFrameCdeclDouble(void);
extern void ChainTableWalkStore_004917e0(void);
extern void Push16Call(void);
extern void DispatcherComplex260_00407030(void);
extern void ScaledLoadCmpStoreXfm_0048f2a0(void);
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

/* @addr 0x0046eac0 (339b game) - 5-thunk dispatcher with mstack-push chain (state-machine via mstack callback ptrs).
 *   Thunk A (0..0x3f): call ScaledAndAlfe; if pause ret. chain[baseSel*4+0x74]=0x603, g_walkCallback=0x603.
 *     Call TripleCallPauseJmp; if pause ret. Push 0x004eb6b8; call ArgSarStoreJmp; pop; ret. 15-NOP pad.
 *   Thunk B (+0x50): call Wrapper_0048a3c0; if pause ret.
 *     g_eventQueueEnd = (0x004eb6c8 >> 2); tail-jmp PhaseDispatchListAdvance_004709e0. ret. 15-NOP pad.
 *   Thunk C (+0x80): if bit0(0054208c): jmp CallPauseDirtyMStackPushFn.
 *     g_eventQueueChild=g_eventQueueNotMask=7. Mstack-push body_eb80; tail-jmp InstallSelfMStackOverwrite. 8-NOP pad.
 *   Thunk D body_eb80 (+0xc0): if bit0: jmp FiveEntryAlarmInstallChain_0046ee00.
 *     g_eventQueueChild=8; g_eventQueueNotMask=7. Mstack-push body_ebc0; tail-jmp InstallSelfMStackOverwrite. 3-NOP pad.
 *   Thunk E body_ebc0 (+0x100): same as D but state_00542080=9; mstack-push body_ec00. 3-NOP pad.
 *   Thunk F body_ec00 (+0x140): if bit0 jmp FiveEntryAlarmInstallChain_0046ee00; else jmp MStackJmpInstallSelf.
 */
extern unsigned int g_dispatchSave701_004eb6c8;
extern void ArgSarStoreJmp(void);
extern void CallPauseDirtyMStackPushFn_0046e2a0(void);
extern void FiveEntryAlarmInstallChain_0046ee00(void);
extern void InstallSelfMStackOverwrite_0046e9a0(void);
extern void MStackJmpInstallSelf_0046ed40(void);
extern void PhaseDispatchListAdvance_004709e0(void);
extern void ScaledAndAlfe_00490390(void);
extern void TripleCallPauseJmp_00470500(void);
extern void Wrapper_0048a3c0(void);

extern unsigned int g_matrixStack_arr;

__declspec(naked) void FiveThunkMStackDispatcher_0046eac0(void) {
    __asm {
        call    ScaledAndAlfe_00490390
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   32h
        mov     ecx, dword ptr [g_baseSel]
        mov     eax, 0x603
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x74], eax
        call    TripleCallPauseJmp_00470500
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   0dh
        push    0x004eb6b8
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
        _emit   90h
        _emit   90h
        call    Wrapper_0048a3c0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   12h
        mov     eax, offset g_dispatchSave701_004eb6c8
        sar     eax, 2
        mov     dword ptr [g_eventQueueEnd], eax
        jmp     PhaseDispatchListAdvance_004709e0
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
        _emit   90h
        _emit   90h
        test    byte ptr [g_xformDirtyFlags], 1
        _emit   74h
        _emit   05h
        jmp     CallPauseDirtyMStackPushFn_0046e2a0
        mov     eax, 7
        mov     dword ptr [g_eventQueueChild], eax
        mov     dword ptr [g_eventQueueNotMask], eax
        mov     eax, dword ptr [g_matrixStackTop]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     [eax*4 + g_matrixStack_arr], offset FiveThunkMStackDispatcher_0046eac0 + 0xc0
        jmp     InstallSelfMStackOverwrite_0046e9a0
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
    body_eb80:
        test    byte ptr [g_xformDirtyFlags], 1
        _emit   74h
        _emit   05h
        jmp     FiveEntryAlarmInstallChain_0046ee00
        mov     eax, dword ptr [g_matrixStackTop]
        mov     dword ptr [g_eventQueueChild], 8
        inc     eax
        mov     dword ptr [g_eventQueueNotMask], 7
        mov     dword ptr [g_matrixStackTop], eax
        mov     [eax*4 + g_matrixStack_arr], offset FiveThunkMStackDispatcher_0046eac0 + 0x100
        jmp     InstallSelfMStackOverwrite_0046e9a0
        _emit   90h
        _emit   90h
        _emit   90h
    body_ebc0:
        test    byte ptr [g_xformDirtyFlags], 1
        _emit   74h
        _emit   05h
        jmp     FiveEntryAlarmInstallChain_0046ee00
        mov     eax, dword ptr [g_matrixStackTop]
        mov     dword ptr [g_eventQueueChild], 9
        inc     eax
        mov     dword ptr [g_eventQueueNotMask], 7
        mov     dword ptr [g_matrixStackTop], eax
        mov     [eax*4 + g_matrixStack_arr], offset FiveThunkMStackDispatcher_0046eac0 + 0x140
        jmp     InstallSelfMStackOverwrite_0046e9a0
        _emit   90h
        _emit   90h
        _emit   90h
    body_ec00:
        test    byte ptr [g_xformDirtyFlags], 1
        _emit   74h
        _emit   05h
        jmp     FiveEntryAlarmInstallChain_0046ee00
        jmp     MStackJmpInstallSelf_0046ed40
    }
}
