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
extern unsigned int g_fightStateProgress;
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

/* @addr 0x0049c5a0 (199b game) - dual-cmp swap-and-store with 3 saved regs.
 *   edx = g_fightGroupHead; ebx = [0x538158]; esi = [0x53803c]; edi = [0x538038];
 *   g_xformEntityIdx = edi; if (edx != ebx) g_xformEntityIdx = esi;
 *   g_currentNodeFlags = chain[g_xformEntityIdx + 0x68];
 *   g_xformScratch2088 = chain[g_xformEntityIdx + 0x6c];
 *   ecx = [0x53815c]; g_eventQueueTotal = g_dispatchVar30;
 *   g_xformEntityIdx = ecx; g_pendingNodeType = esi; g_eventQueueEnd = g_dispatchVar29;
 *   if (ecx == edx): swap with ebx-side; g_pendingNodeType = edi;
 *      g_xformEntityIdx = ebx; g_eventQueueTotal = g_dispatchVar28; g_eventQueueEnd = g_dispatchVar27;
 *   eax = g_baseSel*4; chain[eax + 0x38] = ecx;
 *   chain[eax + 0x3c] = g_pendingNodeType (=ecx-or-edi);
 *   chain[eax + 0x40] = g_eventQueueTotal; chain[eax + 0x44] = g_eventQueueEnd.
 */
extern unsigned int g_dispatchVar30;
extern unsigned int g_dispatchVar29;
extern unsigned int g_dispatchVar28;
extern unsigned int g_dispatchVar27;

extern unsigned int g_matrixStack_arr;

__declspec(naked) void DualCmpSwapStore(void) {
    __asm {
        mov     edx, dword ptr [g_fightGroupHead]
        push    ebx
        mov     ebx, dword ptr [g_player1NodeIdx]
        push    esi
        mov     esi, dword ptr [g_gtPlayerProbe1]
        push    edi
        mov     edi, dword ptr [g_gtPlayerProbe2]
        cmp     edx, ebx
        mov     eax, edi
        mov     dword ptr [g_xformEntityIdx], eax
        _emit   74h
        _emit   07h
        mov     eax, esi
        mov     dword ptr [g_xformEntityIdx], eax
        mov     ecx, [eax*4 + 0x68]
        mov     dword ptr [g_currentNodeFlags], ecx
        mov     eax, [eax*4 + 0x6c]
        mov     ecx, dword ptr [g_player2NodeIdx]
        mov     dword ptr [g_xformScratch2088], eax
        mov     eax, dword ptr [g_dispatchVar30]
        cmp     ecx, edx
        mov     dword ptr [g_eventQueueTotal], eax
        mov     eax, dword ptr [g_dispatchVar29]
        mov     dword ptr [g_xformEntityIdx], ecx
        mov     dword ptr [g_pendingNodeType], esi
        mov     dword ptr [g_eventQueueEnd], eax
        _emit   75h
        _emit   24h
        mov     edx, dword ptr [g_dispatchVar28]
        mov     eax, dword ptr [g_dispatchVar27]
        mov     ecx, ebx
        mov     dword ptr [g_pendingNodeType], edi
        mov     dword ptr [g_xformEntityIdx], ecx
        mov     dword ptr [g_eventQueueTotal], edx
        mov     dword ptr [g_eventQueueEnd], eax
        mov     edx, dword ptr [g_baseSel]
        mov     [edx*4 + 0x38], ecx
        mov     ecx, dword ptr [g_pendingNodeType]
        pop     edi
        lea     eax, [edx*4 + g_matrixStack_arr]
        pop     esi
        pop     ebx
        mov     [eax + 0x3c], ecx
        mov     edx, dword ptr [g_eventQueueTotal]
        mov     [eax + 0x40], edx
        mov     ecx, dword ptr [g_eventQueueEnd]
        mov     [eax + 0x44], ecx
        ret
    }
}
