/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_currentNodeIdx;
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

/* @addr 0x0048b500 (271b game) - mstack-push 3 globals + 3 Mul10Tail + abs/half.
 *   mstack-push g_eventQueueChild, g_currentNodeFlags, g_xformScratch2088.
 *   Compute: ecx = g_eventQueueChild << 0x10; eax = g_xformScratch2088 - ecx; abs(eax).
 *   ecx = g_currentNodeFlags >> 1; push twice; Mul10Tail; result -> g_walkCallback.
 *   Push edx=g_xformScratch2088 and eax (last result); Mul10Tail.
 *   eax >>= 2; ecx >>= 2; add; sub edx; add 0x10000; Mul10Tail; -> g_walkCallback.
 *   mstack-pop 3.
 */

void MStackPush3TripleMul10WithAbs(void) {
    __asm {
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_eventQueueChild]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4 + 0], ecx
        mov     eax, dword ptr [g_matrixStackTop]
        mov     edx, dword ptr [g_currentNodeFlags]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4 + 0], edx
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_xformScratch2088]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4 + 0], ecx
        mov     ecx, dword ptr [g_eventQueueChild]
        mov     eax, dword ptr [g_xformScratch2088]
        shl     ecx, 0x10
        sub     eax, ecx
        mov     dword ptr [g_eventQueueChild], ecx
        mov     dword ptr [g_xformScratch2088], eax
        _emit   79h
        _emit   07h
        neg     eax
        mov     dword ptr [g_xformScratch2088], eax
        mov     ecx, dword ptr [g_currentNodeFlags]
        push    eax
        sar     ecx, 1
        push    eax
        mov     dword ptr [g_currentNodeFlags], ecx
        call    Mul10Tail
        mov     edx, dword ptr [g_xformScratch2088]
        add     esp, 8
        mov     dword ptr [g_walkCallback], eax
        push    edx
        push    eax
        call    Mul10Tail
        mov     edx, dword ptr [g_walkCallback]
        add     esp, 8
        mov     ecx, edx
        sar     eax, 2
        sar     ecx, 2
        add     ecx, eax
        mov     dword ptr [g_xformScratch2088], eax
        mov     eax, dword ptr [g_currentNodeFlags]
        sub     ecx, edx
        add     ecx, 0x00010000
        push    ecx
        push    eax
        mov     dword ptr [g_walkCallback], ecx
        call    Mul10Tail
        mov     dword ptr [g_walkCallback], eax
        mov     eax, dword ptr [g_matrixStackTop]
        add     esp, 8
        mov     ecx, dword ptr [eax*4 + 0]
        dec     eax
        mov     dword ptr [g_xformScratch2088], ecx
        mov     dword ptr [g_matrixStackTop], eax
        mov     edx, dword ptr [eax*4 + 0]
        dec     eax
        mov     dword ptr [g_currentNodeFlags], edx
        mov     dword ptr [g_matrixStackTop], eax
        mov     ecx, dword ptr [eax*4 + 0]
        dec     eax
        mov     dword ptr [g_eventQueueChild], ecx
        mov     dword ptr [g_matrixStackTop], eax
        }
}

