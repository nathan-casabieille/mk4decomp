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

/* @addr 0x0042d090 (304b game) - 3D-distance mul10 + scaled chain advance.
 *   Load eax/ecx/edx from globals 0053a1a8/0053a1a4/g_cj. esi = [cj*4+0x54].
 *   Compute diffs: eax -= esi; ecx -= edx[cj*4+0x5c].
 *   Mul10Tail(eax,eax)->g_eventQueueWorkType. Mul10Tail(ecx,ecx)->g_acc_00542078; add for g_eventQueueWorkType.
 *   Call FpuSqrtMul; if pause ret.
 *   Mul10Tail(g_currentNodeFlags, g_walkCallback)->g_eventQueueChild.
 *   Mul10Tail(eax, g_eventQueueScratch)->g_eventQueueWorkType. Mul10Tail(ecx, g_eventQueueChildSrc)->g_acc.
 *   Sum: g_walkCallback = g_dual_0053a1a8 + g_eventQueueWorkType; g_eventQueueCurrent = g_dual_0053a1a4 + g_acc.
 *   Store both into [g_cj*4+0x54] and [+0x5c]. Tail-call DualCallPauseDirtyJmp; pop esi; ret.
 */
extern unsigned int g_dual_0053a1a4;
extern unsigned int g_dual_0053a1a8;
extern unsigned int g_eventQueueChildSrc;
extern unsigned int g_eventQueueScratch;
extern void DualCallPauseDirtyJmp_00490c30(void);

__declspec(naked) void Distance3DMul10Chain(void) {
    __asm {
        mov     eax, dword ptr [g_dual_0053a1a8]
        mov     ecx, dword ptr [g_dual_0053a1a4]
        mov     edx, dword ptr [g_cj_0054205c]
        push    esi
        mov     dword ptr [g_eventQueueWorkType], eax
        mov     dword ptr [g_acc_00542078], ecx
        mov     esi, dword ptr [edx*4 + 0x54]
        mov     dword ptr [g_walkCallback], esi
        mov     edx, dword ptr [edx*4 + 0x5c]
        sub     eax, esi
        sub     ecx, edx
        push    eax
        push    eax
        mov     dword ptr [g_eventQueueCurrent], edx
        mov     dword ptr [g_eventQueueWorkType], eax
        mov     dword ptr [g_acc_00542078], ecx
        call    Mul10Tail
        add     esp, 8
        mov     dword ptr [g_eventQueueWorkType], eax
        mov     eax, dword ptr [g_acc_00542078]
        push    eax
        push    eax
        call    Mul10Tail
        mov     ecx, dword ptr [g_eventQueueWorkType]
        add     esp, 8
        add     ecx, eax
        mov     dword ptr [g_acc_00542078], eax
        mov     dword ptr [g_eventQueueWorkType], ecx
        call    FpuSqrtMul
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   0a5h
        _emit   00h
        _emit   00h
        _emit   00h
        mov     eax, dword ptr [g_walkCallback]
        mov     dword ptr [g_eventQueueChild], eax
        push    eax
        mov     eax, dword ptr [g_currentNodeFlags]
        push    eax
        call    Mul10Tail
        mov     ecx, dword ptr [g_eventQueueScratch]
        mov     edx, dword ptr [g_eventQueueChildSrc]
        add     esp, 8
        mov     dword ptr [g_eventQueueChild], eax
        mov     dword ptr [g_eventQueueWorkType], ecx
        mov     dword ptr [g_acc_00542078], edx
        push    ecx
        push    eax
        call    Mul10Tail
        mov     ecx, dword ptr [g_eventQueueChild]
        add     esp, 8
        mov     dword ptr [g_eventQueueWorkType], eax
        mov     eax, dword ptr [g_acc_00542078]
        push    eax
        push    ecx
        call    Mul10Tail
        mov     edx, dword ptr [g_eventQueueWorkType]
        mov     ecx, dword ptr [g_dual_0053a1a8]
        add     ecx, edx
        mov     edx, dword ptr [g_dual_0053a1a4]
        mov     dword ptr [g_acc_00542078], eax
        add     edx, eax
        mov     eax, dword ptr [g_cj_0054205c]
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [g_eventQueueCurrent], edx
        add     esp, 8
        mov     dword ptr [eax*4 + 0x54], ecx
        mov     ecx, dword ptr [g_cj_0054205c]
        mov     edx, dword ptr [g_eventQueueCurrent]
        mov     dword ptr [ecx*4 + 0x5c], edx
        call    DualCallPauseDirtyJmp_00490c30
        pop     esi
        ret
    }
}
