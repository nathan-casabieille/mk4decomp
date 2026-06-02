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

/* @addr 0x00461260 (222b game) - 9-entry-point flag dispatcher.
 *   A: call Wrapper_0048a300; if !pause: g_eventQueueChild=0xd; ret.
 *   B (+0x20): g_walkCallback=0x4000; jmp OrDualStore.
 *   C (+0x30): g_walkCallback=0x2000; jmp OrDualStore.
 *   D (+0x40): g_walkCallback=0x1000, g_eventQueueCurrent=5, g_save_0053a7d8=5; jmp OrDualStore.
 *   E (+0x60): byte[g_byte_00543730]=1; g_walkCallback=0x800; jmp OrDualStore.
 *   F (+0x80): call FiveSetWalkJmp; if !pause: g_walkCallback=0x400; jmp OrDualStore.
 *   G (+0xa0): g_walkCallback=0x200; jmp OrDualStore.
 *   H (+0xb0): g_walkCallback=0x40; jmp OrDualStore.
 *   I (+0xc0): g_walkCallback=0x2000; call OrDualStore; if !pause jmp Set1JmpSet2Jmp; ret.
 */
extern unsigned int g_save_0053a7d8;
extern unsigned int g_byte_00543730;
extern void FiveSetWalkJmp(void);
extern void OrDualStore_0048e4b0(void);
extern void Set1JmpSet2Jmp(void);
extern void Wrapper_0048a300(void);

__declspec(naked) void NineEntryFlagDispatch(void) {
    __asm {
        call    Wrapper_0048a300
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   0ah
        mov     dword ptr [g_eventQueueChild], 0x0d
        ret
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        mov     dword ptr [g_walkCallback], 0x00004000
        jmp     OrDualStore_0048e4b0
        _emit   90h
        mov     dword ptr [g_walkCallback], 0x00002000
        jmp     OrDualStore_0048e4b0
        _emit   90h
        mov     eax, 5
        mov     dword ptr [g_walkCallback], 0x00001000
        mov     dword ptr [g_eventQueueCurrent], eax
        mov     dword ptr [g_save_0053a7d8], eax
        jmp     OrDualStore_0048e4b0
        _emit   90h
        _emit   90h
        mov     byte ptr [g_byte_00543730], 1
        mov     dword ptr [g_walkCallback], 0x00000800
        jmp     OrDualStore_0048e4b0
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
        call    FiveSetWalkJmp
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   0fh
        mov     dword ptr [g_walkCallback], 0x00000400
        jmp     OrDualStore_0048e4b0
        ret
        _emit   90h
        _emit   90h
        mov     dword ptr [g_walkCallback], 0x00000200
        jmp     OrDualStore_0048e4b0
        _emit   90h
        mov     dword ptr [g_walkCallback], 0x00000040
        jmp     OrDualStore_0048e4b0
        _emit   90h
        mov     dword ptr [g_walkCallback], 0x00002000
        call    OrDualStore_0048e4b0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   05h
        jmp     Set1JmpSet2Jmp
        ret
    }
}
