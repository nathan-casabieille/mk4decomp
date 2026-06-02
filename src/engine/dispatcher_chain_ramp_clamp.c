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

extern void DispatcherChainRampClamp(void);
extern void StackPopDispatchTagged(void);
extern void DivBy(void);
extern unsigned int g_phaseThunkScratch;

/* @addr 0x00426000 (199b game) - install-self gate with three-way exit:
 *   esi = base*4; snapshot [esi+0x84]; clear.
 *   if (snapshot != 0) goto install-self-zero;
 *   save g_eventQueueCurrent in 0x53a384; call DispatcherChainRampClamp; pause? ret;
 *   if (208c & 4 != 0) goto install-self-zero;
 *   else: chain[g_xformEntityIdx + 0x10] = 0x426190 (handler);
 *         chain[+0x14] = 0x80; restore g_eventQueueCurrent;
 *         g_walkCallback = 0x80; call DivBy; pause? ret;
 *         g_walkCallback += 6; g_pendingNodeType = g_walkCallback;
 *         [esi+8] = 0x00426000; [esi+0x84] = 1; pause = 1.
 *   install-self-zero: g_tickW1 = 0; call StackPopDispatchTagged; ret.
 */

extern unsigned int g_matrixStack_arr;

__declspec(naked) void InstallSelfPackedF80(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel]
        push    esi
        lea     esi, [eax*4 + g_matrixStack_arr]
        mov     eax, [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], 0
        test    eax, eax
        _emit   75h
        _emit   27h
        mov     ecx, dword ptr [g_eventQueueCurrent]
        mov     dword ptr [g_phaseThunkScratch], ecx
        call    DispatcherChainRampClamp
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   85h
        _emit   00h
        _emit   00h
        _emit   00h
        test    byte ptr [g_xformDirtyFlags], 4
        _emit   74h
        _emit   11h
        mov     dword ptr [g_tickW1], 0
        call    StackPopDispatchTagged
        pop     esi
        ret
        mov     edx, dword ptr [g_xformEntityIdx]
        mov     eax, 0x80
        mov     dword ptr [edx*4 + 0x10], 0x00426190
        mov     ecx, dword ptr [g_xformEntityIdx]
        mov     [ecx*4 + 0x14], eax
        mov     edx, dword ptr [g_phaseThunkScratch]
        mov     dword ptr [g_eventQueueCurrent], edx
        mov     dword ptr [g_walkCallback], eax
        call    DivBy
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   29h
        mov     eax, dword ptr [g_walkCallback]
        add     eax, 6
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [g_pendingNodeType], eax
        mov     eax, 1
        mov     dword ptr [esi + 8], 0x00426000
        mov     dword ptr [esi + 0x84], eax
        mov     dword ptr [g_framePauseFlag], eax
        pop     esi
        ret
    }
}
