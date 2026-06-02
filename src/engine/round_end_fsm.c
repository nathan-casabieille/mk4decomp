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

extern unsigned int g_hitPhase;
extern unsigned int g_quadEntryGate;
extern void PendingMatch_0042d240(void);
extern void ScenegraphWalk(void);
extern void Screen_ArcadeEnding(void);
extern void TwinMStackPushScaledChain(void);
extern void RoundEndFsm(void);
extern void CallPauseClear3CallTriple(void);
extern void ScaledInit_GuardedDirtyXformFromTable_g_scaledInit(void);
extern void CopyJmp_GuardedChainPushSetCallPop_g_currentNodeIdx(void);
extern void ScaledZero44(void);
extern void MStackPushSet0001(void);
extern void MStackPushSet0004(void);
extern void ScaledInitWithCounterAndType_004314f0(void);

/* @addr 0x00421380 (378b game) - 2-entry packed phase install + 6-call chain.
 *   Entry 1 (offset 0, 277b): phase-state install.
 *     Phase 1+: SwapOrPassSet; on no-error compares
 *       g_walkCallback with g_loaded. If equal, tail-call
 *       PendingMatch_0042d240. Else bumps g_hitPhase by 1, calls
 *       CallPauseClear3CallTriple, then chains
 *       ScenegraphWalk + Screen_ArcadeEnding.
 *     Phase 0: g_quadEntryGate=1, reads g_or and tests
 *       bit 3; if clear calls TwinMStackPushScaledChain. Either way installs Self
 *       at body with slot[+0x84]=1, packs (Self + 0x01000000) at the
 *       bumped scaled slot, calls RoundEndFsm, arms 0x541e6c=1.
 *   11b NOP align pad.
 *   Entry 2 (offset 0x120, 90b): 6-call chain (ScaledInit_GuardedDirtyXformFromTable_g_scaledInit,
 *     CopyJmp_GuardedChainPushSetCallPop_g_currentNodeIdx, ScaledZero44, ScaledZeroFour,
 *     MStackPushSet0001, MStackPushSet0004), each
 *     gated by 0x541e6c. On full success, tail-jmps
 *     ScaledInitWithCounterAndType_004314f0.
 */
extern unsigned int g_loaded;
extern unsigned int g_or;
extern void SwapOrPassSet(void);

__declspec(naked) void Phase3InstallSelfChain(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel]
        push    esi
        lea     esi, [eax*4]
        mov     eax, dword ptr [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], 0
        test    eax, eax
        je      short L_pis2_phase0
        call    SwapOrPassSet
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_pis2_done
        mov     ecx, dword ptr [g_walkCallback]
        mov     eax, dword ptr [g_loaded]
        cmp     ecx, eax
        jne     short L_pis2_advance
        call    PendingMatch_0042d240
        pop     esi
        ret
    L_pis2_advance:
        mov     edx, dword ptr [g_hitPhase]
        lea     eax, [edx + 1]
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [g_hitPhase], eax
        call    CallPauseClear3CallTriple
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_pis2_done
        call    ScenegraphWalk
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_pis2_done
        call    Screen_ArcadeEnding
        pop     esi
        ret
    L_pis2_phase0:
        mov     eax, dword ptr [g_or]
        mov     dword ptr [g_quadEntryGate], 1
        mov     dword ptr [g_walkCallback], eax
        and     eax, 8
        mov     dword ptr [g_xformScratch94], eax
        jne     short L_pis2_skipCall
        call    TwinMStackPushScaledChain
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_pis2_done
    L_pis2_skipCall:
        mov     dword ptr [esi + 8], offset Phase3InstallSelfChain
        mov     eax, dword ptr [g_baseSel]
        mov     ecx, offset Phase3InstallSelfChain
        mov     dword ptr [eax*4 + 0x84], 1
        mov     eax, dword ptr [esi + 4]
        add     ecx, 0x01000000
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [eax*4], ecx
        mov     eax, dword ptr [g_currentNodeIdx]
        inc     eax
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [esi + 4], eax
        mov     edx, dword ptr [g_baseSel]
        mov     dword ptr [edx*4 + 0x84], 0
        call    RoundEndFsm
        mov     dword ptr [g_framePauseFlag], 1
    L_pis2_done:
        pop     esi
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
        nop
        /* entry 2 (offset 0x120) */
    L_pis2_entry2:
        call    ScaledInit_GuardedDirtyXformFromTable_g_scaledInit
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_pis2_e2End
        call    CopyJmp_GuardedChainPushSetCallPop_g_currentNodeIdx
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_pis2_e2End
        call    ScaledZero44
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_pis2_e2End
        call    ScaledZeroFour
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_pis2_e2End
        call    MStackPushSet0001
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_pis2_e2End
        call    MStackPushSet0004
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_pis2_e2End
        jmp     ScaledInitWithCounterAndType_004314f0
    L_pis2_e2End:
        ret
    }
}
