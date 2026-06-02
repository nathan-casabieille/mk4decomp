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
extern void DispatcherComplex260_MStackBracket1_TreeWalkRecursive2(void);
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

/* @addr 0x0049fa50 (186b game) - mstack-push g_scaledInit; 2 dirty cmp + 3 push-arg calls; bit-0 set/clear.
 *   Push g_scaledInit; call Cmp2DirtySetOrClear_0049fb10; pause? -> end.
 *   if (208c & 1): goto end-bit-set. else: call Cmp2DirtySetOrClear_0049fb40; pause? -> end.
 *   if (208c & 1): goto end-bit-set.
 *   push 0x15; call DualPushSetCallDualPop; add esp,4; if (208c & 1) goto end-bit-set.
 *   push 0x16; call DualPushSetCallDualPop; add esp,4; if (208c & 1) goto end-bit-set.
 *   push 0x250; call DualPushSetCallDualPop; add esp,4; if !(208c & 1) goto end-bit-clear.
 *   end-bit-set: g_xformDirtyFlags &= ~1; jmp store.
 *   end-bit-clear: g_xformDirtyFlags |= 1.
 *   store: g_xformDirtyFlags = result.
 *   mstack-pop into g_scaledInit.
 */
extern void Cmp2DirtySetOrClear_0049fb10(void);
extern void Cmp2DirtySetOrClear_0049fb40(void);
extern void DualPushSetCallDualPop(void);

extern unsigned int g_matrixStack_arr;

__declspec(naked) void MStackDirtyArgsBit0(void) {
    __asm {
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_scaledInit_00542044]
        inc     eax
        push    ebx
        mov     dword ptr [g_matrixStackTop], eax
        mov     [eax*4 + g_matrixStack_arr], ecx
        call    Cmp2DirtySetOrClear_0049fb10
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   8dh
        _emit   00h
        _emit   00h
        _emit   00h
        mov     al, byte ptr [g_xformDirtyFlags]
        mov     ebx, 1
        _emit   84h
        _emit   0c3h
        _emit   75h
        _emit   52h
        call    Cmp2DirtySetOrClear_0049fb40
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   71h
        test    byte ptr [g_xformDirtyFlags], bl
        _emit   75h
        _emit   3ch
        push    0x15
        call    DualPushSetCallDualPop
        mov     al, byte ptr [g_xformDirtyFlags]
        add     esp, 4
        _emit   84h
        _emit   0c3h
        _emit   75h
        _emit   29h
        push    0x16
        call    DualPushSetCallDualPop
        mov     al, byte ptr [g_xformDirtyFlags]
        add     esp, 4
        _emit   84h
        _emit   0c3h
        _emit   75h
        _emit   16h
        push    0x250
        call    DualPushSetCallDualPop
        mov     al, byte ptr [g_xformDirtyFlags]
        add     esp, 4
        _emit   84h
        _emit   0c3h
        _emit   74h
        _emit   09h
        mov     eax, dword ptr [g_xformDirtyFlags]
        and     al, 0xfe
        _emit   0ebh
        _emit   07h
        mov     eax, dword ptr [g_xformDirtyFlags]
        or      eax, ebx
        mov     dword ptr [g_xformDirtyFlags], eax
        mov     eax, dword ptr [g_matrixStackTop]
        mov     edx, [eax*4 + g_matrixStack_arr]
        dec     eax
        mov     dword ptr [g_scaledInit_00542044], edx
        mov     dword ptr [g_matrixStackTop], eax
        pop     ebx
        ret
    }
}
