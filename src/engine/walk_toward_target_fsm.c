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

extern void Distance2DSaturationClamp(void);
extern void ChainFieldTest2Branch(void);
extern void LoadSetCallPauseStoreJmp(void);
extern void MStackPush4DualCallAbsPop4(void);
extern void WalkTowardTargetFsm(void);
extern void DualMul10ChainAcc7C(void);
extern void EsiInstallChainCallCmpThreshold(void);
extern void GuardedSeq_DualMulScaleStore_then_PhaseInstall2DInterpDispatch_0042fba0(void);
extern void Mul10Triple0xd999Interp(void);
extern void SubCmpCallPauseJmp(void);
extern void GuardedSeq_DualMulScaleStore_then_PhaseInstall2DInterpDispatch_0042fb80(void);

/* @addr 0x0042f8a0 (355b game) - install-self phase dispatcher with 2D
 *   interpolation tails. Phase 0: installs Self at [eax+8] with slot[+0x84]=1
 *   and arms g_framePauseFlag.
 *   Phase 1+ path: chains Distance2DSaturationClamp → load
 *   g_player1NodeIdx → ChainFieldTest2Branch → load g_player2NodeIdx
 *   → ChainFieldTest2Branch → LoadSetCallPauseStoreJmp →
 *   MStackPush4DualCallAbsPop4. After the chain:
 *     - if g_acc_00542078 > 0xa3d, tail-call WalkTowardTargetFsm.
 *     - else call DualMul10ChainAcc7C, then if g_eventQueueNotMask <
 *       0x300000 tail-call EsiInstallChainCallCmpThreshold.
 *     - else (>= 0x370000): compute eax = g_eventQueueWorkType - 0x1999,
 *       store into g_acc_00542078, compare 0x54206c/0x542070 against it
 *       and select one of three tails:
 *         - if 0x54206c <  threshold: GuardedSeq_DualMulScaleStore_then_PhaseInstall2DInterpDispatch_0042fba0
 *         - else if 0x542070 < threshold: GuardedSeq_DualMulScaleStore_then_PhaseInstall2DInterpDispatch_0042fba0
 *         - else if 0x54206c < 0x542074: pick Mul10Triple0xd999Interp
 *           or SubCmpCallPauseJmp (after stashing 0x5381cc into
 *           g_currentNodeIdx)
 *         - else (>= 0x542074): GuardedSeq_DualMulScaleStore_then_PhaseInstall2DInterpDispatch_0042fb80 or SubCmpCallPauseJmp.
 */

__declspec(naked) void PhaseInstall2DInterpDispatch(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel]
        push    esi
        shl     eax, 2
        mov     ecx, dword ptr [eax + 0x84]
        mov     dword ptr [eax + 0x84], 0
        test    ecx, ecx
        je      L_pii_phase0
        call    Distance2DSaturationClamp
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_pii_done
        mov     ecx, dword ptr [g_player1NodeIdx]
        mov     dword ptr [g_currentNodeIdx], ecx
        call    ChainFieldTest2Branch
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_pii_done
        mov     edx, dword ptr [g_player2NodeIdx]
        mov     dword ptr [g_currentNodeIdx], edx
        call    ChainFieldTest2Branch
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_pii_done
        call    LoadSetCallPauseStoreJmp
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_pii_done
        call    MStackPush4DualCallAbsPop4
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_pii_done
        cmp     dword ptr [g_acc_00542078], 0xa3d
        jle     short L_pii_check2
        call    WalkTowardTargetFsm
        pop     esi
        ret
    L_pii_check2:
        call    DualMul10ChainAcc7C
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_pii_done
        mov     eax, dword ptr [g_eventQueueNotMask]
        cmp     eax, 0x300000
        jge     short L_pii_check3
        call    EsiInstallChainCallCmpThreshold
        pop     esi
        ret
    L_pii_check3:
        mov     ecx, dword ptr [g_eventQueueWorkType]
        mov     esi, dword ptr [g_walkCallback]
        mov     edx, dword ptr [g_eventQueueCurrent]
        cmp     eax, 0x370000
        jl      short L_pii_sample
        lea     eax, [ecx - 0x1999]
        cmp     esi, eax
        mov     dword ptr [g_acc_00542078], eax
        jge     short L_pii_eaxOk
        call    GuardedSeq_DualMulScaleStore_then_PhaseInstall2DInterpDispatch_0042fba0
        pop     esi
        ret
    L_pii_eaxOk:
        cmp     edx, eax
        jge     short L_pii_sample
        call    GuardedSeq_DualMulScaleStore_then_PhaseInstall2DInterpDispatch_0042fba0
        pop     esi
        ret
    L_pii_sample:
        cmp     esi, ecx
        jge     short L_pii_storeEdx
        cmp     edx, ecx
        jge     short L_pii_storeEsi
        call    Mul10Triple0xd999Interp
        pop     esi
        ret
    L_pii_storeEsi:
        mov     eax, dword ptr [g_player2NodeIdx]
        mov     dword ptr [g_acc_00542078], esi
        mov     dword ptr [g_currentNodeIdx], eax
        call    SubCmpCallPauseJmp
        pop     esi
        ret
    L_pii_storeEdx:
        cmp     edx, ecx
        jle     short L_pii_writeEdx
        call    GuardedSeq_DualMulScaleStore_then_PhaseInstall2DInterpDispatch_0042fb80
        pop     esi
        ret
    L_pii_writeEdx:
        mov     dword ptr [g_acc_00542078], edx
        call    SubCmpCallPauseJmp
        pop     esi
        ret
    L_pii_phase0:
        mov     ecx, 1
        mov     dword ptr [eax + 8], offset PhaseInstall2DInterpDispatch
        mov     dword ptr [eax + 0x84], ecx
        mov     dword ptr [g_pendingNodeType], ecx
        mov     dword ptr [g_framePauseFlag], ecx
    L_pii_done:
        pop     esi
        ret
    }
}
