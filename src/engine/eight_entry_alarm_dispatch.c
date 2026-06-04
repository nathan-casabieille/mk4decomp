/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
#include "portable/ghidra_types.h"
#include "game/tick.h"

extern unsigned int g_currentNodeIdx;
extern unsigned int g_baseSel;
extern unsigned int g_chainAccumCur;
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
extern unsigned int g_armedReloadA;
extern unsigned int g_armedReloadB;
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

/* @addr 0x00482500 (382b game) - 8-entry packed mini-alarm dispatcher.
 *   Entry 1 (offset 0, 80b): set 0x54206c=0x6666 → CmpP1DualInitStore_00482ab0
 *     → CjTableThresholdDispatch → GateDispatch6c →
 *     SaveSwapCallRestore → push 0x4ede38 → ArgSarStoreJmp.
 *   Entry 2 (offset 0x50, 70b): 0x54206c=0xfffff852 → read slot+0x7c;
 *     if > 1 set 0x54206c=0xfffff0a4. MStackFrameCdeclDouble
 *     → push 0x4ede68 → ArgSarStoreJmp.
 *   10b NOP align pad.
 *   Entry 3 (offset 0xa0, 20b): DualScaledInitClear → tail-jmp
 *     LiteralPushCallEntZero.
 *   12b NOP align pad.
 *   Entry 4 (offset 0xc0, 28b): GateDispatch6c → push 0x4ede90
 *     → ArgSarStoreJmp.
 *   4b NOP align pad.
 *   Entry 5 (offset 0xe0, 50b): GateDispatch6c → push 0x4edec4
 *     → IterStepDualStore → push 0x4edec8 → ArgSarStoreJmp.
 *   14b NOP align pad.
 *   Entry 6 (offset 0x120, 28b): GateDispatch6c → push 0x4edef8
 *     → ArgSarStoreJmp.
 *   4b NOP align pad.
 *   Entry 7 (offset 0x140, 30b): 0x54206c=6 → TableLookupCall_g_eventTbl_19
 *     → tail-jmp TripleGuardSetTailJmp.
 *   2b NOP align pad.
 *   Entry 8 (offset 0x160, 30b): 0x54206c=8 → TableLookupCall_g_eventTbl_112
 *     → tail-jmp TripleGuardSetTailJmp.
 */
extern unsigned int g_dispatchSave760;
extern unsigned int g_dispatchSave761;
extern unsigned int g_dispatchSave762;
extern unsigned int g_dispatchSave763;
extern unsigned int g_dispatchSave764;
extern unsigned int g_dispatchSave765;
extern void ArgSarStoreJmp(void);
extern void CjTableThresholdDispatch(void);
extern void CmpP1DualInitStore_00482ab0(void);
extern void DualScaledInitClear(void);
extern void GateDispatch6c(void);
extern void SaveSwapCallRestore(void);
extern void TableLookupCall_g_eventTbl_112(void);
extern void TableLookupCall_g_eventTbl_19(void);
extern void TripleGuardSetTailJmp(void);

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void EightEntryAlarmDispatch(void)

{
  g_walkCallback = 0x6666;
  CmpP1DualInitStore_00482ab0();
  if (g_framePauseFlag == 0) {
    CjTableThresholdDispatch();
    if (g_framePauseFlag == 0) {
      GateDispatch6c();
      if (g_framePauseFlag == 0) {
        SaveSwapCallRestore();
        if (g_framePauseFlag == 0) {
          ArgSarStoreJmp(&g_dispatchSave760);
        }
      }
    }
  }
  return;
}
#else
__declspec(naked) void EightEntryAlarmDispatch(void) {
    __asm {
        mov     dword ptr [g_walkCallback], 0x6666
        call    CmpP1DualInitStore_00482ab0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_eae_e1End
        call    CjTableThresholdDispatch
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_eae_e1End
        call    GateDispatch6c
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_eae_e1End
        call    SaveSwapCallRestore
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_eae_e1End
        push    offset g_dispatchSave760
        call    ArgSarStoreJmp
        add     esp, 4
    L_eae_e1End:
        ret
    L_eae_entry2:
        mov     eax, dword ptr [g_baseSel]
        mov     dword ptr [g_walkCallback], 0xfffff852
        mov     eax, dword ptr [eax*4 + 0x7c]
        cmp     eax, 1
        mov     dword ptr [g_eventQueueCurrent], eax
        jle     short L_eae_e2NoOver
        mov     dword ptr [g_walkCallback], 0xfffff0a4
    L_eae_e2NoOver:
        call    MStackFrameCdeclDouble
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_eae_e2End
        push    offset g_dispatchSave761
        call    ArgSarStoreJmp
        add     esp, 4
    L_eae_e2End:
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
        /* entry 3 (offset 0xa0) */
    L_eae_entry3:
        call    DualScaledInitClear
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_eae_e3End
        jmp     LiteralPushCallEntZero
    L_eae_e3End:
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
        nop
        /* entry 4 (offset 0xc0) */
    L_eae_entry4:
        call    GateDispatch6c
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_eae_e4End
        push    offset g_dispatchSave762
        call    ArgSarStoreJmp
        add     esp, 4
    L_eae_e4End:
        ret
        nop
        nop
        nop
        nop
        /* entry 5 (offset 0xe0) */
    L_eae_entry5:
        call    GateDispatch6c
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_eae_e5End
        push    offset g_dispatchSave763
        call    IterStepDualStore
        mov     eax, dword ptr [g_framePauseFlag]
        add     esp, 4
        test    eax, eax
        jne     short L_eae_e5End
        push    offset g_dispatchSave764
        call    ArgSarStoreJmp
        add     esp, 4
    L_eae_e5End:
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
        nop
        nop
        nop
        /* entry 6 (offset 0x120) */
    L_eae_entry6:
        call    GateDispatch6c
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_eae_e6End
        push    offset g_dispatchSave765
        call    ArgSarStoreJmp
        add     esp, 4
    L_eae_e6End:
        ret
        nop
        nop
        nop
        nop
        /* entry 7 (offset 0x140) */
    L_eae_entry7:
        mov     dword ptr [g_walkCallback], 6
        call    TableLookupCall_g_eventTbl_19
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_eae_e7End
        jmp     TripleGuardSetTailJmp
    L_eae_e7End:
        ret
        nop
        nop
        /* entry 8 (offset 0x160) */
    L_eae_entry8:
        mov     dword ptr [g_walkCallback], 8
        call    TableLookupCall_g_eventTbl_112
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_eae_e8End
        jmp     TripleGuardSetTailJmp
    L_eae_e8End:
        ret
    }
}
#endif
