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

/* @addr 0x004c6760 (144b boot) - CRT _close bundle + 2 thunks + fmod/fprem helper.
 *   sub-1 (76b @ 0x4c6760): _close(fd). Calls CloseHandle via IAT[0x4d2150];
 *     on success, checks state bits; on permission error, sets errno=0xd and
 *     doserrno=5; returns -1 on error, 0 on success.
 *   sub-2 (10b @ 0x4c67b0): mov edx, 0x00520000; jmp far (longjmp-like helper).
 *   sub-3 (10b @ 0x4c67bb): another similar mov+jmp pair.
 *   sub-4 (~30b @ 0x4c67c5): floating-point modulus via fprem (or compat helper).
 */
extern unsigned int g_dispatchSave1423;
extern unsigned int g_iat_GetFileAttributesA;
extern unsigned int g_iat_GetLastError;
extern void Crt_doserrno(void);
extern void Crt_errno(void);
extern void DosMapErr(void);
extern void FmodHelper_004ccb7d(void);
extern void Thunk_004ca701_helper(void);
extern void Thunk_004ca77b_helper(void);

__declspec(naked) void CloseAndThunksBundle(void) {
    __asm {
        /* sub-1: _close */
        mov     eax, [esp + 4]
        push    eax
        call    dword ptr [g_iat_GetFileAttributesA]
        cmp     eax, -1
        jne     short L_cl_check
        call    dword ptr [g_iat_GetLastError]
        push    eax
        call    DosMapErr
        add     esp, 4
        or      eax, -1
        ret
    L_cl_check:
        test    al, 1
        jz      short L_cl_zero
        test    byte ptr [esp + 8], 2
        jz      short L_cl_zero
        call    Crt_errno
        mov     dword ptr [eax], 0x0d
        call    Crt_doserrno
        mov     dword ptr [eax], 5
        or      eax, -1
        ret
    L_cl_zero:
        xor     eax, eax
        ret
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        /* sub-2: mov edx + jmp far helper */
        mov     edx, 0x00520000
        jmp     Thunk_004ca77b_helper
        /* sub-3: mov edx + jmp far helper */
        mov     edx, 0x00520000
        jmp     Thunk_004ca701_helper
        /* sub-4: fmod via fprem */
        fxch    st(1)
    L_fmod_loop:
        cmp     dword ptr [g_dispatchSave1423], 1
        jz      short L_fmod_use_helper
        fprem
        jmp     short L_fmod_check
    L_fmod_use_helper:
        call    FmodHelper_004ccb7d
    L_fmod_check:
        fwait
        fnstsw  ax
        fwait
        sahf
        jp      short L_fmod_loop
        fstp    st(1)
        ret
        _emit   0cch
        _emit   0cch
        _emit   0cch
        _emit   0cch
        _emit   0cch
        _emit   0cch
        _emit   0cch
        _emit   0cch
        _emit   0cch
        _emit   0cch
        _emit   0cch
        _emit   0cch
        _emit   0cch
        _emit   0cch
    }
}
