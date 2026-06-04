/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
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

/* @addr 0x00486130 (352b game) - 3-entry packed phase-state install w/ tails.
 *   Entry 1 (offset 0, 247b): phase from [scaled g_baseSel + 0x84].
 *     phase 0: tail-calls StackPopDispatchTagged.
 *     phase 1: add g_currentNodeFlags into [g_fightGroupHead*4 + 0x58] AND into
 *              [g_eventQueueEnd*4 + 0x58] (both mirrored through 0x54206c),
 *              installs Self at [eax+8], slot[+0x84]=2, g_pendingNodeType=3,
 *              arms g_framePauseFlag=1.
 *     phase 2: sub g_currentNodeFlags from the same +0x58 fields, installs
 *              Self, slot[+0x84]=1, g_pendingNodeType=3, arms 0x541e6c=1.
 *   (9-byte NOP align pad.)
 *   Entry 2 (offset 0x100, 56b): chains ScaledTestCallPauseJmpFar
 *     then CopyJmp_SlotCmp3way_g_currentNodeIdx, both gated by 0x541e6c. If bit 0 of
 *     g_xformDirtyFlags set, tail-jmp TwoCallTail_GateDispatch6c_then_CjTableThresholdDispatch_then_AggressorRunInitCluster; else push 0x4eed08
 *     and call ArgSarStoreJmp.
 *   (8-byte NOP align pad.)
 *   Entry 3 (offset 0x140, 36b): if [scaled g_baseSel + 0x7c] > 3
 *     tail-jmp BattleEndCluster; else fall through to the next adjacent
 *     function ChainDispatcher4Call via jmp.
 */
extern unsigned int g_dispatchSave646;
extern void ArgSarStoreJmp(void);
extern void BattleEndCluster(void);
extern void ChainDispatcher4Call(void);
extern void ScaledTestCallPauseJmpFar(void);
extern void TwoCallTail_GateDispatch6c_then_CjTableThresholdDispatch_then_AggressorRunInitCluster(void);

__declspec(naked) void Phase3Packed3EntryDispatch(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel]
        push    esi
        shl     eax, 2
        mov     ecx, dword ptr [eax + 0x84]
        mov     dword ptr [eax + 0x84], 0
        sub     ecx, 0
        je      short L_p3p_phase2
        dec     ecx
        je      short L_p3p_phase1
        call    StackPopDispatchTagged
        pop     esi
        ret
    L_p3p_phase1:
        mov     edx, dword ptr [g_fightGroupHead]
        mov     ecx, dword ptr [g_currentNodeFlags]
        add     ecx, dword ptr [edx*4 + 0x58]
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [edx*4 + 0x58], ecx
        mov     edx, dword ptr [g_eventQueueEnd]
        mov     ecx, dword ptr [g_currentNodeFlags]
        add     ecx, dword ptr [edx*4 + 0x58]
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [edx*4 + 0x58], ecx
        mov     dword ptr [eax + 8], offset Phase3Packed3EntryDispatch
        mov     dword ptr [eax + 0x84], 2
        mov     dword ptr [g_pendingNodeType], 3
        mov     dword ptr [g_framePauseFlag], 1
        pop     esi
        ret
    L_p3p_phase2:
        mov     edx, dword ptr [g_fightGroupHead]
        mov     esi, dword ptr [g_currentNodeFlags]
        mov     ecx, dword ptr [edx*4 + 0x58]
        sub     ecx, esi
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [edx*4 + 0x58], ecx
        mov     edx, dword ptr [g_eventQueueEnd]
        mov     esi, dword ptr [g_currentNodeFlags]
        mov     ecx, dword ptr [edx*4 + 0x58]
        sub     ecx, esi
        pop     esi
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [edx*4 + 0x58], ecx
        mov     ecx, 1
        mov     dword ptr [eax + 8], offset Phase3Packed3EntryDispatch
        mov     dword ptr [eax + 0x84], ecx
        mov     dword ptr [g_pendingNodeType], 3
        mov     dword ptr [g_framePauseFlag], ecx
        ret
        /* 9-byte NOP pad */
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        /* entry 2 (offset 0x100) */
    L_p3p_entry2:
        call    ScaledTestCallPauseJmpFar
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_p3p_e2End
        call    CopyJmp_SlotCmp3way_g_currentNodeIdx
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_p3p_e2End
        test    byte ptr [g_xformDirtyFlags], 1
        je      short L_p3p_pushPath
        jmp     TwoCallTail_GateDispatch6c_then_CjTableThresholdDispatch_then_AggressorRunInitCluster
    L_p3p_pushPath:
        push    offset g_dispatchSave646
        call    ArgSarStoreJmp
        add     esp, 4
    L_p3p_e2End:
        ret
        /* 8-byte NOP pad */
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        /* entry 3 (offset 0x140) */
    L_p3p_entry3:
        mov     eax, dword ptr [g_baseSel]
        mov     eax, dword ptr [eax*4 + 0x7c]
        cmp     eax, 3
        mov     dword ptr [g_walkCallback], eax
        jle     short L_p3p_jumpNext
        jmp     BattleEndCluster
    L_p3p_jumpNext:
        jmp     ChainDispatcher4Call
    }
}
