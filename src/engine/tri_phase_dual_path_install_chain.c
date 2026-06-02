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
extern void SetJmp_0049cb90(void);
extern void Thunk_0049cbd0(void);
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
extern void Wrapper_00436490(void);
extern void MoveFsmCluster(void);
extern void CallPauseTestByteJmpCalls(void);
extern void InstallSelfFullPath(void);
extern void InstallSelfCountdownChain(void);
extern void CopyJmp_0048ef90(void);
extern void DualTestDirtyToggle_004282c0(void);
extern void TripleVecAccCallStore(void);
extern void Thunk_004bd5c0(void);
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

extern void ScaledArrStore_004298c0(void);
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
extern void Wrapper_0048a350(void);
extern void Wrapper_0048a3a0(void);
extern void Helper_DownloadSetup(void);
extern void MStackPush3CmpCall(void);
extern void Wrapper_0048ec20(void);
extern void FiveCallScaledChainTailJmp(void);
extern void SetJmp_00438f50(void);
extern void SetJmp_00438f60(void);
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

extern unsigned int g_dispatchSave717_004ed590;
extern unsigned int g_dispatchSave718_004ed5a8;
extern void MStackPushSet0008(void);
extern void MStackPushSet0020(void);
extern void CmpEqInitCallElseJmp(void);
extern void TriPhaseDualPathInstallChain(void);
extern void TailJmpInstallSelfPair(void);
extern void ScaledAndAldf(void);
extern void EsiEdiAliasDualMul10(void);
extern void InstallSelfThresholdDispatch(void);

/* @addr 0x0047e1a0 (355b game) - 3-entry packed phase chain w/ alarms.
 *   Entry 1 (offset 0, 51b): writes 0x1012 into [g_baseSel*4+0x74]
 *     (mirrored 0x54206c), calls MStackPushSet0008, on no-error
 *     pushes 0x4ed590 (alarm string) and calls ArgSarStoreJmp.
 *   13b NOP align pad.
 *   Entry 2 (offset 0x40, 67b): same shape but writes [scaled+0x68]=0x402,
 *     [scaled+0x74]=0x201 first, calls MStackPushSet0020, then
 *     conditionally pushes 0x4ed5a8.
 *   13b NOP align pad.
 *   Entry 3 / body (offset 0x90, 211b): phase-state install. Phase 0 →
 *     install Self body at [esi+8], slot[+0x84]=1, arms 0x541e6c. Phase 1 →
 *     CmpEqInitCallElseJmp, on no-error: if bit 0 of 0x54208c set
 *     tail-call TriPhaseDualPathInstallChain; else call TailJmpInstallSelfPair.
 *     If g_walkCallback < 0x26666 (threshold) tail-installs Self.
 *     Else chains ScaledAndAldf → EsiEdiAliasDualMul10,
 *     writes 0x28f into [g_fightGroupHead*4+0x4c], calls
 *     InstallSelfThresholdDispatch.
 */
extern void ArgSarStoreJmp(void);

__declspec(naked) void Alarm3EntryPhaseChain(void) {
    __asm {
        mov     ecx, dword ptr [g_baseSel]
        mov     eax, 0x1012
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x74], eax
        call    MStackPushSet0008
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_a3e_e1End
        push    offset g_dispatchSave717_004ed590
        call    ArgSarStoreJmp
        add     esp, 4
    L_a3e_e1End:
        ret
        /* 13b NOP pad */
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
        /* entry 2 (offset 0x40) */
    L_a3e_entry2:
        mov     eax, dword ptr [g_baseSel]
        mov     dword ptr [eax*4 + 0x68], 0x402
        mov     ecx, dword ptr [g_baseSel]
        mov     eax, 0x201
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x74], eax
        call    MStackPushSet0020
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_a3e_e2End
        push    offset g_dispatchSave718_004ed5a8
        call    ArgSarStoreJmp
        add     esp, 4
    L_a3e_e2End:
        ret
        /* 13b NOP pad */
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
        /* entry 3 / body (offset 0x90) */
    L_a3e_body:
        mov     eax, dword ptr [g_baseSel]
        push    ebx
        push    esi
        mov     ebx, 1
        lea     esi, [eax*4]
        mov     eax, dword ptr [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], 0
        test    eax, eax
        je      L_a3e_installPhase0
        mov     dword ptr [g_walkCallback], 2
        call    CmpEqInitCallElseJmp
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_a3e_doneNoPop
        test    byte ptr [g_xformDirtyFlags], bl
        je      short L_a3e_e3InitChain
        call    TriPhaseDualPathInstallChain
        pop     esi
        pop     ebx
        ret
    L_a3e_e3InitChain:
        call    TailJmpInstallSelfPair
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_a3e_doneNoPop
        cmp     dword ptr [g_walkCallback], 0x26666
        jl      short L_a3e_installPhase0
        call    ScaledAndAldf
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_a3e_doneNoPop
        mov     dword ptr [g_walkCallback], 0x4ccc
        call    EsiEdiAliasDualMul10
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_a3e_doneNoPop
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     eax, 0x28f
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x4c], eax
        call    InstallSelfThresholdDispatch
        pop     esi
        pop     ebx
        ret
    L_a3e_installPhase0:
        mov     dword ptr [esi + 8], offset L_a3e_body
        mov     dword ptr [esi + 0x84], ebx
        mov     dword ptr [g_pendingNodeType], ebx
        mov     dword ptr [g_framePauseFlag], ebx
    L_a3e_doneNoPop:
        pop     esi
        pop     ebx
        ret
    }
}
