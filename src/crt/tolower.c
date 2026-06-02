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

extern unsigned char g_dispatchSave1444_00f9fc10;
extern void Tolower(int);

/*
 * @addr 0x004cc6f0 (130b crt) - locale-aware tolower w/ critsec
 *   gate: if locale init flag is unset and char is ASCII 'A'-'Z',
 *   shortcut by adding 0x20; otherwise enter critsec (with lazy
 *   init taking a global _lock(0x13)), call Tolower, exit.
 */
extern unsigned int g_iat_InterlockedIncrement;
extern unsigned int g_iat_InterlockedDecrement;
extern unsigned int g_dispatchSave1463_00f9fdac;
extern unsigned int g_dispatchSave1464_00f9fdb0;
extern void Lock(void);
extern void TableLookupIatCall(void);

__declspec(naked) void TolowerLocale(void) {
    __asm {
        mov     eax, dword ptr [g_dispatchSave1444_00f9fc10]
        test    eax, eax
        jne     localePath
        mov     eax, dword ptr [esp + 4]
        cmp     eax, 0x41
        jl      bareRet
        cmp     eax, 0x5a
        jg      bareRet
        add     eax, 0x20
        ret
localePath:
        push    edi
        push    esi
        push    ebx
        push    offset g_dispatchSave1464_00f9fdb0
        call    dword ptr [g_iat_InterlockedIncrement]
        mov     eax, dword ptr [g_dispatchSave1463_00f9fdac]
        mov     edi, dword ptr [g_iat_InterlockedDecrement]
        test    eax, eax
        je      noLock
        push    offset g_dispatchSave1464_00f9fdb0
        call    edi
        push    0x13
        call    Lock
        add     esp, 4
        mov     esi, 1
        jmp     callInner
noLock:
        xor     esi, esi
callInner:
        mov     eax, dword ptr [esp + 0x10]
        push    eax
        call    Tolower
        add     esp, 4
        mov     ebx, eax
        test    esi, esi
        je      directLeave
        push    0x13
        call    TableLookupIatCall
        add     esp, 4
        mov     eax, ebx
        pop     ebx
        pop     esi
        pop     edi
        ret
directLeave:
        push    offset g_dispatchSave1464_00f9fdb0
        call    edi
        mov     eax, ebx
        pop     ebx
        pop     esi
        pop     edi
bareRet:
        ret
    }
}
