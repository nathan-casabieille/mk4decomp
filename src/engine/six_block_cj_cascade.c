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

/* @addr 0x004829b0 (256b game) - 6 small blocks (80/64/16/16/16/64 byte alignment).
 *   B1 (0..79): cmp baseSel[+0x60] vs 0x2001/0x2002, set/clear bit0 of state, ret.
 *   B2 (80..143): call DualCallPauseDirtyJmp; if !pause: add 0x32492 to cj[+0x64],
 *     push 0x004ee188, tail-call ArgSarStoreJmp; ret.
 *   B3 (144..159): push 0x004ee1a8; tail-call ArgSarStoreJmp.
 *   B4 (160..175): push 0x004ee1b8; tail-call ArgSarStoreJmp.
 *   B5 (176..191): push 0x004ee1d0; tail-call ArgSarStoreJmp.
 *   B6 (192..255): call CjTableThresholdDispatch; if !pause: call GateDispatch6c; if !pause:
 *     push 0x004ee1e8; call CrouchFsmCluster_00482c30+0x1c0 (0x00482df0); pop;
 *     if !pause: push 0x004ee1f0, tail-call ArgSarStoreJmp; ret.
 */
extern void ArgSarStoreJmp(void);
extern void CjTableThresholdDispatch(void);
extern void DualCallPauseDirtyJmp_00490c30(void);
extern void GateDispatch6c(void);

void SixBlockCjCascade_004829b0(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel]
        mov     eax, dword ptr [eax*4 + 0x60]
        cmp     eax, 0x2001
        mov     dword ptr [g_walkCallback], eax
        _emit   75h
        _emit   0dh
        mov     eax, dword ptr [g_xformDirtyFlags]
        or      al, 1
        mov     dword ptr [g_xformDirtyFlags], eax
        ret
        cmp     eax, 0x2002
        mov     eax, dword ptr [g_xformDirtyFlags]
        _emit   75h
        _emit   08h
        or      al, 1
        mov     dword ptr [g_xformDirtyFlags], eax
        ret
        and     al, 0xfe
        mov     dword ptr [g_xformDirtyFlags], eax
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
        call    DualCallPauseDirtyJmp_00490c30
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   2bh
        mov     ecx, dword ptr [g_cj_0054205c]
        push    0x004ee188
        mov     eax, dword ptr [ecx*4 + 0x64]
        add     eax, 0x00032492
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x64], eax
        call    ArgSarStoreJmp
        add     esp, 4
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        push    0x004ee1a8
        call    ArgSarStoreJmp
        add     esp, 4
        ret
        nop
        nop
        push    0x004ee1b8
        call    ArgSarStoreJmp
        add     esp, 4
        ret
        nop
        nop
        push    0x004ee1d0
        call    ArgSarStoreJmp
        add     esp, 4
        ret
        nop
        nop
        call    CjTableThresholdDispatch
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   31h
        call    GateDispatch6c
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   23h
        push    0x004ee1e8
        _emit   0e8h
        _emit   5ah
        _emit   03h
        _emit   00h
        _emit   00h
        mov     eax, dword ptr [g_framePauseFlag]
        add     esp, 4
        test    eax, eax
        _emit   75h
        _emit   0dh
        push    0x004ee1f0
        call    ArgSarStoreJmp
        add     esp, 4
        }
}

