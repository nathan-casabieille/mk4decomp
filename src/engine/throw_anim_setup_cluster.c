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

extern void InstallSelfTwoTailJmp(void);
extern void TradePlaceChain(void);
extern void ThrowAnimSetupCluster(void);

/* @addr 0x00484000 (336b game) - install-self with multi-call cascade + chain field-copy thunk.
 *   state!=0: tail-call FiveCallGuardSetTail; pop+ret.
 *   state==0: dec g_eventQueueNotMask; if non-zero tail-call InstallSelfTwoTailJmp.
 *     Call SlotPhaseResetInstallChain; if pause ret.
 *     g_eventQueueCurrent=[cj*4+0x28]. Install-self at entry+0x01000000; state=1; call CallPauseScaledStoreJmp; pause=1; ret.
 *   Tail (+0xc0): g_walkCallback=3; call ByteWordTableTaggedDispatch; if pause ret.
 *     Call TradePlaceChain; if pause ret. g_eventQueueEnd=g_scaledInit. If zero: tail-jmp CjInstallSelfRouter.
 *     Push 0x70, push (ThrowAnimSetupCluster + 0x10); call StoreTwoCall; pop. Copy chain[baseSel*4+0x3c] to [scaledInit*4+0x3c].
 *     Call CopyJmp; if pause ret. If bit0(0054208c): jmp ThrowAnimSetupCluster.
 *     Else: push 0x004ee800; call ArgSarStoreJmp; pop; ret.
 */
extern void ArgSarStoreJmp(void);
extern void ByteWordTableTaggedDispatch(void);
extern void CallPauseScaledStoreJmp_00428820(void);
extern void CjInstallSelfRouter(void);
extern void FiveCallGuardSetTail(void);
extern void SlotPhaseResetInstallChain(void);

__declspec(naked) void InstallSelfMultiCascadeChainCopy(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel]
        push    esi
        lea     esi, [eax*4 + 0]
        mov     eax, dword ptr [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], 0
        test    eax, eax
        _emit   74h
        _emit   07h
        call    FiveCallGuardSetTail
        pop     esi
        ret
        mov     eax, dword ptr [g_eventQueueNotMask]
        dec     eax
        mov     dword ptr [g_eventQueueNotMask], eax
        _emit   74h
        _emit   07h
        call    InstallSelfTwoTailJmp
        pop     esi
        ret
        call    SlotPhaseResetInstallChain
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   72h
        mov     ecx, dword ptr [g_cj_0054205c]
        mov     edx, dword ptr [ecx*4 + 0x28]
        mov     ecx, offset InstallSelfMultiCascadeChainCopy
        mov     dword ptr [g_eventQueueCurrent], edx
        mov     dword ptr [esi + 8], offset InstallSelfMultiCascadeChainCopy
        mov     eax, dword ptr [g_baseSel]
        add     ecx, 0x01000000
        mov     dword ptr [eax*4 + 0x84], 1
        mov     eax, dword ptr [esi + 4]
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     dword ptr [eax*4 + 0], ecx
        mov     eax, dword ptr [g_scaledInit_00542044]
        inc     eax
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     dword ptr [esi + 4], eax
        mov     edx, dword ptr [g_baseSel]
        mov     dword ptr [edx*4 + 0x84], 0
        call    CallPauseScaledStoreJmp_00428820
        mov     dword ptr [g_framePauseFlag], 1
        pop     esi
        ret
        _emit   90h
        mov     dword ptr [g_walkCallback], 3
        call    ByteWordTableTaggedDispatch
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   77h
        call    TradePlaceChain
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   69h
        mov     eax, dword ptr [g_scaledInit_00542044]
        test    eax, eax
        mov     dword ptr [g_eventQueueEnd], eax
        _emit   75h
        _emit   05h
        jmp     CjInstallSelfRouter
        push    0x70
        push    offset ThrowAnimSetupCluster + 0x10
        call    StoreTwoCall
        mov     eax, dword ptr [g_baseSel]
        mov     ecx, dword ptr [g_scaledInit_00542044]
        add     esp, 8
        mov     eax, dword ptr [eax*4 + 0x3c]
        mov     dword ptr [g_xformEntityIdx], eax
        mov     dword ptr [ecx*4 + 0x3c], eax
        call    CopyJmp_SlotCmp3way_g_currentNodeIdx
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   1bh
        test    byte ptr [g_xformDirtyFlags], 1
        _emit   74h
        _emit   05h
        jmp     ThrowAnimSetupCluster
        push    0x004ee800
        call    ArgSarStoreJmp
        add     esp, 4
        ret
    }
}
