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

/* @addr 0x004ce150 (147b crt) - lazy-load + invoke 4-arg function via 3 GetProcAddress lookups.
 *   Cache: [0xf9fc34] (main FP), [0xf9fc38] (init FP), [0xf9fc3c] (cleanup FP).
 *   If cache populated, skip setup; else:
 *     GetModuleHandleA("...") -> esi; if 0 -> fail.
 *     GetProcAddress(esi, name1) -> store [0xf9fc34]; if 0 -> fail.
 *     GetProcAddress(esi, name2) -> store [0xf9fc38].
 *     GetProcAddress(esi, name3) -> store [0xf9fc3c].
 *   If [0xf9fc38]: ebx = [0xf9fc38]().
 *   If ebx && [0xf9fc3c]: ebx = [0xf9fc3c](ebx).
 *   Call main FP with (ebx, arg1, arg2, arg3).
 *   Tail block 3 (+0x8f-+0x92): NOP + xor eax, eax + ret (unreachable dead code).
 */
extern unsigned int g_GetModuleHandleA;
extern unsigned int g_GetProcAddress;
extern unsigned int g_dispatchSave1452_00f9fc34;
extern unsigned int g_dispatchSave1453_00f9fc38;
extern unsigned int g_dispatchSave1454_00f9fc3c;

__declspec(naked) void LazyLoadInvoke_004ce150(void) {
    __asm {
        mov     eax, dword ptr [g_dispatchSave1452_00f9fc34]
        push    ebx
        xor     ebx, ebx
        push    esi
        test    eax, eax
        push    edi
        _emit   75h
        _emit   42h
        push    0x004d2f70
        call    dword ptr [g_GetModuleHandleA]
        mov     esi, eax
        test    esi, esi
        _emit   74h
        _emit   6ah
        mov     edi, dword ptr [g_GetProcAddress]
        push    0x004d2f64
        push    esi
        call    edi
        test    eax, eax
        mov     dword ptr [g_dispatchSave1452_00f9fc34], eax
        _emit   74h
        _emit   53h
        push    0x004d2f54
        push    esi
        call    edi
        push    0x004d2f40
        push    esi
        mov     dword ptr [g_dispatchSave1453_00f9fc38], eax
        call    edi
        mov     dword ptr [g_dispatchSave1454_00f9fc3c], eax
        mov     eax, dword ptr [g_dispatchSave1453_00f9fc38]
        test    eax, eax
        _emit   74h
        _emit   04h
        call    eax
        mov     ebx, eax
        test    ebx, ebx
        _emit   74h
        _emit   0eh
        mov     eax, dword ptr [g_dispatchSave1454_00f9fc3c]
        test    eax, eax
        _emit   74h
        _emit   05h
        push    ebx
        call    eax
        mov     ebx, eax
        mov     eax, [esp + 0x18]
        mov     ecx, [esp + 0x14]
        mov     edx, [esp + 0x10]
        push    eax
        push    ecx
        push    edx
        push    ebx
        call    dword ptr [g_dispatchSave1452_00f9fc34]
        pop     edi
        pop     esi
        pop     ebx
        ret
        pop     edi
        pop     esi
        xor     eax, eax
        pop     ebx
        ret
        nop
        xor     eax, eax
        ret
    }
}
