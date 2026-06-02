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
extern void GuardedDispatch_InstallSelfDualEsi(void);
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

/* @addr 0x00484c90 (248b game) - dual-block install-self pair.
 *   B1 (0..49, +10 NOPs): if chain[+0x84]==0: install-self at [eax+8]=0x00484c90;
 *     chain[+0x84]=1; g_pendingNodeType=1; pause=1; ret.
 *     Else: mstack-push 0x00484cf0 (sibling); tail-jmp GameDispatchValidateState.
 *   B2 (96..247): snapshot+clear chain[+0x84]. If was zero -> tail-call
 *     FiveCallGuardSetTail. Else: dec g_eventQueueChild; if zero ->
 *     tail-call 0x00484c90 (self), else: install-self at [eax+8]=0x00484cf0;
 *     chain[+0x84]=1; scaledInit-chain push 0x00484cf0+0x01000000;
 *     call ScaledLoadIncJmp_set_g_eventQueueCurrent_then_ScaledArrStore_EsiInstallBitCallChain; pause=1; ret.
 */
extern void FiveCallGuardSetTail(void);
extern void ScaledLoadIncJmp_set_g_eventQueueCurrent_then_ScaledArrStore_EsiInstallBitCallChain(void);

__declspec(naked) void DualBlockInstallSelfWithSibling(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel]
        shl     eax, 2
        mov     ecx, dword ptr [eax + 0x84]
        mov     dword ptr [eax + 0x84], 0
        test    ecx, ecx
        _emit   74h
        _emit   1bh
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
        _emit   0f0h
        _emit   4ch
        _emit   48h
        _emit   00h
        jmp     GameDispatchValidateState
        mov     ecx, 1
        mov     dword ptr [eax + 8], 0x00484c90
        mov     dword ptr [eax + 0x84], ecx
        mov     dword ptr [g_pendingNodeType], ecx
        mov     dword ptr [g_framePauseFlag], ecx
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
        mov     eax, dword ptr [g_baseSel]
        xor     edx, edx
        shl     eax, 2
        push    edi
        mov     ecx, dword ptr [eax + 0x84]
        mov     dword ptr [eax + 0x84], edx
        cmp     ecx, edx
        _emit   74h
        _emit   07h
        call    FiveCallGuardSetTail
        pop     edi
        ret
        mov     ecx, dword ptr [g_eventQueueChild]
        dec     ecx
        mov     dword ptr [g_eventQueueChild], ecx
        _emit   74h
        _emit   07h
        call    DualBlockInstallSelfWithSibling
        pop     edi
        ret
        mov     dword ptr [eax + 8], 0x00484cf0
        mov     ecx, dword ptr [g_baseSel]
        mov     edi, 0x00484cf0
        mov     dword ptr [ecx*4 + 0x84], 1
        mov     ecx, dword ptr [eax + 4]
        add     edi, 0x01000000
        mov     dword ptr [g_scaledInit_00542044], ecx
        mov     dword ptr [ecx*4 + 0], edi
        mov     ecx, dword ptr [g_scaledInit_00542044]
        inc     ecx
        mov     dword ptr [g_scaledInit_00542044], ecx
        mov     dword ptr [eax + 4], ecx
        mov     eax, dword ptr [g_baseSel]
        mov     dword ptr [eax*4 + 0x84], edx
        call    ScaledLoadIncJmp_set_g_eventQueueCurrent_then_ScaledArrStore_EsiInstallBitCallChain
        mov     dword ptr [g_framePauseFlag], 1
        pop     edi
        ret
    }
}
