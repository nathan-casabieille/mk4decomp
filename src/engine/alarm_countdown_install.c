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

/* @addr 0x004609e0 (383b game) - 2-entry packed: 3-call chain + countdown
 *   install. Entry 1 (offset 0, 104b): writes g_walkCallback into
 *     [scaled+0x6c], sets 0x54206c=0x2147, chains
 *     MStackFrameCdeclDouble → NineEntryFlagDispatch_00461260 →
 *     0x54206c=0x51e / 0x542070=0x28 / GatedScaledSubSat_0048fb40 → push
 *     0x4e9f78 → StateSnapshotDispatch_00460b60.
 *   8b NOP align pad.
 *   Entry 2 / body (offset 0x70, 271b): phase-state install.
 *     phase != 0: push 0x4e9f80 → GuardedScaledChainJmpIndirect_00460e40
 *       → DispatchThroughBaseSel6c_00460f20. If bit 0 of 0x54208c set,
 *       0x54206c=0x51e + 0x542070=0x28 + GatedScaledSubSat. If
 *       g_eventQueueCurrent > 0: decrement g_eventQueueChild; if zero call
 *       NineEntryFlagDispatch_00461260; else fall through to install
 *       success tail. Else tail-call ZeroScaledZeroCallPauseJmp_0045fa90.
 *     phase 0: sets g_xformEntityIdx = &g_dispatchTableArr10_00500c50>>2, calls
 *       DualScaledStoreZero_00491080. On no-error writes 0xb into
 *       [g_fightGroupHead*4 + 0x28], g_eventQueueChild=1, installs Self
 *       at body, arms 0x541e6c=1.
 */
extern unsigned int g_dispatchSave959_004e9f78;
extern unsigned int g_dispatchSave960_004e9f80;
extern unsigned int g_dispatchTableArr10_00500c50;
extern void DispatchThroughBaseSel6c_00460f20(void);
extern void DualScaledStoreZero_00491080(void);
extern void GatedScaledSubSat_0048fb40(void);
extern void GuardedScaledChainJmpIndirect_00460e40(void);
extern void NineEntryFlagDispatch_00461260(void);
extern void StateSnapshotDispatch_00460b60(void);
extern void ZeroScaledZeroCallPauseJmp_0045fa90(void);

__declspec(naked) void AlarmCountdownInstall_004609e0(void) {
    __asm {
        mov     ecx, dword ptr [g_baseSel]
        mov     eax, dword ptr [g_walkCallback]
        mov     dword ptr [ecx*4 + 0x6c], eax
        mov     dword ptr [g_walkCallback], 0x2147
        call    MStackFrameCdeclDouble
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_aci_e1End
        call    NineEntryFlagDispatch_00461260
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_aci_e1End
        mov     dword ptr [g_walkCallback], 0x51e
        mov     dword ptr [g_eventQueueCurrent], 0x28
        call    GatedScaledSubSat_0048fb40
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_aci_e1End
        push    offset g_dispatchSave959_004e9f78
        call    StateSnapshotDispatch_00460b60
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
        push    offset g_dispatchSave960_004e9f80
        call    GuardedScaledChainJmpIndirect_00460e40
        mov     eax, dword ptr [g_framePauseFlag]
        add     esp, 4
        test    eax, eax
        jne     L_aci_doneNoPop
        call    DispatchThroughBaseSel6c_00460f20
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_aci_doneNoPop
        mov     al, byte ptr [g_xformDirtyFlags]
        mov     ebx, 1
        test    al, bl
        je      short L_aci_checkVel
        mov     dword ptr [g_walkCallback], 0x51e
        mov     dword ptr [g_eventQueueCurrent], 0x28
        call    GatedScaledSubSat_0048fb40
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_aci_doneNoPop
        mov     eax, dword ptr [g_eventQueueCurrent]
        test    eax, eax
        jg      short L_aci_doCountdown
    L_aci_checkVel:
        call    ZeroScaledZeroCallPauseJmp_0045fa90
        pop     esi
        pop     ebx
        ret
    L_aci_doCountdown:
        mov     eax, dword ptr [g_eventQueueChild]
        dec     eax
        mov     dword ptr [g_eventQueueChild], eax
        jne     short L_aci_installTail
        call    NineEntryFlagDispatch_00461260
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_aci_doneNoPop
        jmp     short L_aci_installTail
    L_aci_phase0:
        mov     ecx, offset g_dispatchTableArr10_00500c50
        shr     ecx, 2
        mov     dword ptr [g_xformEntityIdx], ecx
        call    DualScaledStoreZero_00491080
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
