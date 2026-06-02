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

extern void MStackBracket1_TreeWalkRecursive2(void);
extern void DirtyDoubleDeref(void);
extern void PushPopScaled1cDoubleCall(void);
extern unsigned int g_installChainTailSlot;

/* @addr 0x004a7030 (189b audio) - packed-ptr install + chain init + tail-jmp.
 *   g_xformEntityIdx = packed_ptr(0x50d418); call MStackBracket1_TreeWalkRecursive2; pause? -> end;
 *   (208c&4)? -> end;
 *   mstack-push g_scaledInit; [0x53a3a8] = g_scaledInit;
 *   chain[+0x40] = 0x6487; chain[+0x3c] = 0; chain[+0x44] = 0; chain[+0x30] = 0;
 *   g_walkCallback = 9; call DirtyDoubleDeref; pause? -> end;
 *   g_xformEntityIdx = g_scaledInit; mstack-pop into g_scaledInit; jmp PushPopScaled1cDoubleCall.
 */

extern unsigned int g_matrixStack_arr;

__declspec(naked) void InstallChainInitTailJmp(void) {
    __asm {
        mov     eax, 0x0050d418
        shr     eax, 2
        mov     dword ptr [g_xformEntityIdx], eax
        call    MStackBracket1_TreeWalkRecursive2
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   9dh
        _emit   00h
        _emit   00h
        _emit   00h
        test    byte ptr [g_xformDirtyFlags], 4
        _emit   0fh
        _emit   85h
        _emit   90h
        _emit   00h
        _emit   00h
        _emit   00h
        mov     ecx, dword ptr [g_matrixStackTop]
        mov     eax, dword ptr [g_scaledInit_00542044]
        inc     ecx
        mov     dword ptr [g_installChainTailSlot], eax
        mov     dword ptr [g_matrixStackTop], ecx
        mov     [ecx*4 + g_matrixStack_arr], eax
        mov     ecx, dword ptr [g_scaledInit_00542044]
        mov     dword ptr [ecx*4 + 0x40], 0x00006487
        mov     dword ptr [ecx*4 + 0x3c], 0
        lea     eax, [ecx*4 + g_matrixStack_arr]
        mov     dword ptr [eax + 0x44], 0
        mov     dword ptr [eax + 0x30], 0
        mov     dword ptr [g_walkCallback], 9
        call    DirtyDoubleDeref
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   29h
        mov     edx, dword ptr [g_scaledInit_00542044]
        mov     eax, dword ptr [g_matrixStackTop]
        mov     dword ptr [g_xformEntityIdx], edx
        mov     ecx, [eax*4 + g_matrixStack_arr]
        dec     eax
        mov     dword ptr [g_scaledInit_00542044], ecx
        mov     dword ptr [g_matrixStackTop], eax
        jmp     PushPopScaled1cDoubleCall
        ret
    }
}
