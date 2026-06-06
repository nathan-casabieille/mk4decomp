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

/* @addr 0x004609e0 (383b game) - 2-entry packed: 3-call chain + countdown
 *   install. Entry 1 (offset 0, 104b): writes g_walkCallback into
 *     [scaled+0x6c], sets 0x54206c=0x2147, chains
 *     MStackFrameCdeclDouble → NineEntryFlagDispatch →
 *     0x54206c=0x51e / 0x542070=0x28 / GatedScaledSubSat → push
 *     0x4e9f78 → StateSnapshotDispatch.
 *   8b NOP align pad.
 *   Entry 2 / body (offset 0x70, 271b): phase-state install.
 *     phase != 0: push 0x4e9f80 → GuardedScaledChainJmpIndirect
 *       → DispatchThroughBaseSel6c. If bit 0 of 0x54208c set,
 *       0x54206c=0x51e + 0x542070=0x28 + GatedScaledSubSat. If
 *       g_eventQueueCurrent > 0: decrement g_eventQueueChild; if zero call
 *       NineEntryFlagDispatch; else fall through to install
 *       success tail. Else tail-call ZeroScaledZeroCallPauseJmp.
 *     phase 0: sets g_xformEntityIdx = &g_dispatchTableArr10>>2, calls
 *       DualScaledStoreZero. On no-error writes 0xb into
 *       [g_fightGroupHead*4 + 0x28], g_eventQueueChild=1, installs Self
 *       at body, arms 0x541e6c=1.
 */
extern unsigned int g_dispatchSave959;
extern unsigned int g_dispatchSave960;
extern unsigned int g_dispatchTableArr10;
extern void DispatchThroughBaseSel6c(void);
extern void DualScaledStoreZero(void);
extern void GatedScaledSubSat(void);
extern void GuardedScaledChainJmpIndirect(void);
extern void NineEntryFlagDispatch(void);
extern void StateSnapshotDispatch(void);
extern void ZeroScaledZeroCallPauseJmp(void);

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void AlarmCountdownInstall(void)

{
  MK4_NODE_AT(undefined4, g_baseSel, 0x6c) = g_walkCallback;
  g_walkCallback = 0x2147;
  MStackFrameCdeclDouble();
  if (g_framePauseFlag == 0) {
    NineEntryFlagDispatch();
    if (g_framePauseFlag == 0) {
      g_walkCallback = 0x51e;
      g_eventQueueCurrent = 0x28;
      GatedScaledSubSat();
      if (g_framePauseFlag == 0) {
        StateSnapshotDispatch(&g_dispatchSave959);
      }
    }
  }
  return;
}
#else
__declspec(naked) void AlarmCountdownInstall(void) {
    __asm {
        mov     ecx, dword ptr [g_baseSel]
        mov     eax, dword ptr [g_walkCallback]
        mov     dword ptr [ecx*4 + 0x6c], eax
        mov     dword ptr [g_walkCallback], 0x2147
        call    MStackFrameCdeclDouble
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_aci_e1End
        call    NineEntryFlagDispatch
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_aci_e1End
        mov     dword ptr [g_walkCallback], 0x51e
        mov     dword ptr [g_eventQueueCurrent], 0x28
        call    GatedScaledSubSat
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_aci_e1End
        push    offset g_dispatchSave959
        call    StateSnapshotDispatch
        add     esp, 4
    L_aci_e1End:
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        /* entry 2 / body (offset 0x70) */
    L_aci_body:
        mov     eax, dword ptr [g_baseSel]
        push    ebx
        push    esi
        lea     esi, [eax*4]
        mov     eax, dword ptr [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], 0
        test    eax, eax
        je      L_aci_phase0
        push    offset g_dispatchSave960
        call    GuardedScaledChainJmpIndirect
        mov     eax, dword ptr [g_framePauseFlag]
        add     esp, 4
        test    eax, eax
        jne     L_aci_doneNoPop
        call    DispatchThroughBaseSel6c
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_aci_doneNoPop
        mov     al, byte ptr [g_xformDirtyFlags]
        mov     ebx, 1
        test    al, bl
        je      short L_aci_checkVel
        mov     dword ptr [g_walkCallback], 0x51e
        mov     dword ptr [g_eventQueueCurrent], 0x28
        call    GatedScaledSubSat
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_aci_doneNoPop
        mov     eax, dword ptr [g_eventQueueCurrent]
        test    eax, eax
        jg      short L_aci_doCountdown
    L_aci_checkVel:
        call    ZeroScaledZeroCallPauseJmp
        pop     esi
        pop     ebx
        ret
    L_aci_doCountdown:
        mov     eax, dword ptr [g_eventQueueChild]
        dec     eax
        mov     dword ptr [g_eventQueueChild], eax
        jne     short L_aci_installTail
        call    NineEntryFlagDispatch
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_aci_doneNoPop
        jmp     short L_aci_installTail
    L_aci_phase0:
        mov     ecx, offset g_dispatchTableArr10
        shr     ecx, 2
        mov     dword ptr [g_xformEntityIdx], ecx
        call    DualScaledStoreZero
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_aci_doneNoPop
        mov     edx, dword ptr [g_fightGroupHead]
        mov     eax, 0xb
        mov     dword ptr [g_walkCallback], eax
        mov     ebx, 1
        mov     dword ptr [edx*4 + 0x28], eax
        mov     dword ptr [g_eventQueueChild], ebx
    L_aci_installTail:
        mov     dword ptr [esi + 8], offset L_aci_body
        mov     dword ptr [esi + 0x84], ebx
        mov     dword ptr [g_pendingNodeType], ebx
        mov     dword ptr [g_framePauseFlag], ebx
    L_aci_doneNoPop:
        pop     esi
        pop     ebx
        ret
    }
}
#endif
