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

extern void TripleMStackPushChainStores(void);
extern void StoreFightFieldCallTailJmp(void);
extern void FourPackedSubInitCmpDispatch(void);

/* @addr 0x00466490 (285b game) - dual block: thunk + 4-field copy + cj setup.
 *   B1 (0..0xf, +2 NOPs): push 0x004eaa08; tail-call ArgSarStoreJmp.
 *   B2 (0x10..0x11c): call TripleMStackPushChainStores; if pause? ret.
 *     If bit2 of g_xformDirtyFlags set: tail-jmp StoreFightFieldCallTailJmp.
 *     Else: copy cj[+0x58/+0x3c/+0x64] to scaledInit fields with intermediate via
 *     g_eventQueueIdx (for +0x38). cj[+0x30]=0x7e. Call MStackCall_00406340; if pause? ret.
 *     baseSel[+0x30]=2, baseSel[+0x34]=g_scaledInit, baseSel[+0x38]=g_eventQueueIdx,
 *     baseSel[+0x3c]=g_cj_0054205c. Tail-jmp FourPackedSubInitCmpDispatch; ret.
 */
extern void ArgSarStoreJmp(void);
extern void MStackCall_00406340(void);

__declspec(naked) void ThunkPlus4FieldCjCopy(void) {
    __asm {
        push    0x004eaa08
        call    ArgSarStoreJmp
        add     esp, 4
        ret
        nop
        nop
        call    TripleMStackPushChainStores
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   0fah
        _emit   00h
        _emit   00h
        _emit   00h
        test    byte ptr [g_xformDirtyFlags], 4
        _emit   74h
        _emit   05h
        jmp     StoreFightFieldCallTailJmp
        mov     eax, dword ptr [g_eventQueueEnd]
        mov     edx, dword ptr [g_cj_0054205c]
        mov     ecx, dword ptr [eax*4 + 0x38]
        mov     dword ptr [g_eventQueueIdx], ecx
        mov     eax, dword ptr [edx*4 + 0x58]
        mov     ecx, dword ptr [g_scaledInit_00542044]
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x58], eax
        mov     edx, dword ptr [g_cj_0054205c]
        mov     ecx, dword ptr [g_scaledInit_00542044]
        mov     eax, dword ptr [edx*4 + 0x3c]
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x3c], eax
        mov     edx, dword ptr [g_cj_0054205c]
        mov     ecx, dword ptr [g_scaledInit_00542044]
        mov     eax, dword ptr [edx*4 + 0x64]
        mov     dword ptr [ecx*4 + 0x64], eax
        mov     edx, dword ptr [g_scaledInit_00542044]
        mov     eax, 0x7e
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [edx*4 + 0x30], eax
        call    MStackCall_00406340
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   5dh
        mov     eax, dword ptr [g_scaledInit_00542044]
        mov     ecx, dword ptr [g_baseSel]
        mov     dword ptr [g_eventQueueEnd], eax
        mov     eax, 2
        mov     dword ptr [g_pendingNodeType], eax
        mov     dword ptr [ecx*4 + 0x30], eax
        mov     edx, dword ptr [g_baseSel]
        mov     eax, dword ptr [g_eventQueueEnd]
        mov     dword ptr [edx*4 + 0x34], eax
        mov     ecx, dword ptr [g_baseSel]
        mov     edx, dword ptr [g_eventQueueIdx]
        mov     dword ptr [ecx*4 + 0x38], edx
        mov     ecx, dword ptr [g_baseSel]
        mov     eax, dword ptr [g_cj_0054205c]
        mov     dword ptr [ecx*4 + 0x3c], eax
        jmp     FourPackedSubInitCmpDispatch
        ret
    }
}
