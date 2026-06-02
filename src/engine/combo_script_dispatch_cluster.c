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

extern unsigned int g_dispatchSave971;
extern unsigned int g_dispatchSave560;
extern unsigned int g_dispatchSave559;
extern unsigned int g_dispatchSave972;
extern unsigned int g_dispatchSave973;
extern void CallPauseDirtyMStackPushFn(void);
extern void InstallSelfIndirectJmp(void);
extern void ScaledMove74to70(void);
extern void FiveBlockDispatchChain_0046ec20(void);
extern void TripleCallPauseJmp(void);
extern void ComboScriptDispatchCluster(void);
extern void PhaseDispatchListAdvance(void);
extern void IterStepScaledStore(void);

/* @addr 0x0046ee00 (356b game) - 5-entry packed install-self + alarm chain.
 *   Entry 1 (offset 0, 135b): phase from [scaled g_baseSel+0x84].
 *     phase != 0: writes 0x28f into [g_fightGroupHead*4+0x4c], pushes
 *       0x0046e2a0 (callback addr) onto mstack via g_matrixStackTop, then
 *       tail-call InstallSelfIndirectJmp.
 *     phase 0: calls ScaledZeroFour; on no-error installs Self at
 *       [esi+8], slot[+0x84]=1, g_pendingNodeType=0xc, arms 0x541e6c=1.
 *   9b NOP align pad.
 *   Entry 2 (offset 0x90, 106b): ScaledMove74to70; on no-error
 *     sets [g_baseSel*4+0x74]=0x604; if [scaled+0x30] != 0 tail-jmp
 *     FiveBlockDispatchChain_0046ec20; else chain ScaledAndAlfe →
 *     TripleCallPauseJmp → push 0x4eb6f8 →
 *     ArgSarStoreJmp.
 *   6b NOP align pad.
 *   Entry 3 (offset 0x100, 18b): sets g_eventQueueEnd = &g_dispatchSave560>>2
 *     and tail-jmp PhaseDispatchListAdvance.
 *   14b NOP align pad.
 *   Entry 4 (offset 0x120, 32b): if bit 0 of g_xformDirtyFlags set tail-jmp
 *     CallPauseDirtyMStackPushFn; else set g_eventQueueEnd =
 *     &g_dispatchSave559>>2 and tail-jmp ComboScriptDispatchCluster.
 *   Entry 5 (offset 0x140, 36b): push 0x4eb738, call IterStepScaledStore;
 *     on no-error push 0x4eb740, call ArgSarStoreJmp.
 */
extern unsigned int g_table_004d57b0;
extern void ArgSarStoreJmp(void);
extern void ScaledAndAlfe(void);

__declspec(naked) void FiveEntryAlarmInstallChain(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel]
        push    esi
        lea     esi, [eax*4]
        mov     eax, dword ptr [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], 0
        test    eax, eax
        je      short L_fea_phase0
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     eax, 0x28f
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x4c], eax
        mov     eax, dword ptr [g_matrixStackTop]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4 + g_table_004d57b0], offset CallPauseDirtyMStackPushFn
        call    InstallSelfIndirectJmp
        pop     esi
        ret
    L_fea_phase0:
        call    ScaledZeroFour
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_fea_e1End
        mov     eax, 1
        mov     dword ptr [esi + 8], offset FiveEntryAlarmInstallChain
        mov     dword ptr [esi + 0x84], eax
        mov     dword ptr [g_pendingNodeType], 0xc
        mov     dword ptr [g_framePauseFlag], eax
    L_fea_e1End:
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
        /* entry 2 (offset 0x90) */
    L_fea_entry2:
        call    ScaledMove74to70
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_fea_e2End
        mov     ecx, dword ptr [g_baseSel]
        mov     eax, 0x604
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x74], eax
        mov     edx, dword ptr [g_baseSel]
        mov     eax, dword ptr [edx*4 + 0x30]
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        je      short L_fea_skipJmp
        jmp     FiveBlockDispatchChain_0046ec20
    L_fea_skipJmp:
        call    ScaledAndAlfe
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_fea_e2End
        call    TripleCallPauseJmp
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_fea_e2End
        push    offset g_dispatchSave971
        call    ArgSarStoreJmp
        add     esp, 4
    L_fea_e2End:
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        /* entry 3 (offset 0x100) */
    L_fea_entry3:
        mov     eax, offset g_dispatchSave560
        sar     eax, 2
        mov     dword ptr [g_eventQueueEnd], eax
        jmp     PhaseDispatchListAdvance
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
        /* entry 4 (offset 0x120) */
    L_fea_entry4:
        test    byte ptr [g_xformDirtyFlags], 1
        je      short L_fea_e4second
        jmp     CallPauseDirtyMStackPushFn
    L_fea_e4second:
        mov     eax, offset g_dispatchSave559
        sar     eax, 2
        mov     dword ptr [g_eventQueueEnd], eax
        jmp     ComboScriptDispatchCluster
        /* entry 5 (offset 0x140) */
    L_fea_entry5:
        push    offset g_dispatchSave972
        call    IterStepScaledStore
        mov     eax, dword ptr [g_framePauseFlag]
        add     esp, 4
        test    eax, eax
        jne     short L_fea_e5End
        push    offset g_dispatchSave973
        call    ArgSarStoreJmp
        add     esp, 4
    L_fea_e5End:
        ret
    }
}
