/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_state_004d57ac;
extern unsigned int g_scaledInit_00542044;
extern packed_ptr g_xformEntityIdx;
extern u32 g_eventQueueEnd;
extern unsigned int g_baseSel_00542060;
extern u32 g_eventQueueWorkType;
extern unsigned int g_acc_00542078;
extern unsigned int g_cj_0054205c;
extern u32 g_framePauseFlag;
extern unsigned int g_state_0053a718;
extern unsigned int g_eventQueueTotal;
extern unsigned int g_eventQueueCurrent;
extern unsigned int g_currentNodeFlags;
extern unsigned int g_xformDirtyFlags;
extern unsigned int g_xformScratch2088;
extern unsigned int g_xformScratch94;
extern unsigned int g_table_00535ddc;
extern unsigned int g_active_00537e88;
extern unsigned int g_active_0053a408;
extern unsigned int g_state_00537f94;
extern unsigned int g_eventQueueChild;
extern u32 g_pendingNodeType;

extern void StoreTwoCall_0049cb40(int, int);
extern void SetJmp_0049cb90(void);
extern void Thunk_0049cbd0(void);
extern void ScaledZeroFour_00490740(void);
extern void WalkCbSubMul10_00431d50(void);
extern void Mul10Tail_00404af0(unsigned int a, unsigned int b);
extern void BootMod6487eClampAndChainMul10_00407510(void);
extern void SpawnListBatchLoader_00477710(void);
extern void MStackPush2TableNot_00426230(void);
extern void GuardedChainCmpDualBitXor_004299a0(void);
extern void ScaledLoadDecJmp_00429710(void);
extern void ScaledStoreCurDirtyClear_004296f0(void);
extern void MStackBitmaskIncMod_00492450(void);
extern void MStackBitmaskUpdate_00492510(void);
extern void Push1eCallTestDirtyLoop_004923b0(void);
extern void MStackLoopFieldInit_00492280(void);
extern void TaggedSceneDispatch_004be690(void);
extern void CallPauseDirty4StackPushFn_004839d0(void);
extern void CallPauseDirty1JmpDirty4StackPush_00483a80(void);
extern void Cmp2CallDirtyCall_004398b0(void);
extern void QuadBlockArgInstallChain_0043a950(void);
extern void InstallSelfChainSet84_80CallW_004363f0(void);
extern void Wrapper_00436490(void);
extern void MoveFsmCluster_004364a0(void);
extern void CallPauseTestByteJmpCalls_004390f0(void);
extern void InstallSelfFullPath_0047a840(void);
extern void InstallSelfCountdownChain_0047a950(void);
extern void CopyJmp_0048ef90(void);
extern void DualTestDirtyToggle_004282c0(void);
extern void TripleVecAccCallStore_00476880(void);
extern void Thunk_004bd5c0(void);
extern void AllocSlotPushTripleGlobals_00427470(void);
extern void MStackPop4Rewrite_004274f0(void);
extern void Push70CallScaleArith_00457ad0(void);
extern void StreamChainStringInstall_00457900(void);
extern void MStackFrameCdeclDouble_004903f0(void);
extern void ChainTableWalkStore_004917e0(void);
extern void Push16Call_00489f50(void);
extern void DispatcherComplex260_00407030(void);
extern void ScaledLoadCmpStoreXfm_0048f2a0(void);
extern void StackPopDispatchTagged_0041f780(void);
extern unsigned int g_eventQueueNotMask;
extern unsigned int g_cj_00542058;
extern unsigned int g_data_0053a180;
extern unsigned int g_zero_00541fa4;
extern unsigned int g_zero_00541fa8;
extern unsigned int g_state_0053a7b0;
extern unsigned int g_data_0053a770;
extern unsigned int g_data_0053a46c;

extern void ScaledArrStore_004298c0(void);
extern void DualFieldAddSubStore_00470340(void);
extern void IterStepDualStore_00490b40(int);
extern void ScaledXorStore_004900f0(void);
extern void ChainWalkInstall_0049b7c0(void);
extern void FpuSqrtMul_004ab350(void);
extern void PendingMatch_0042b930(void);
extern void MStackPush2RunCountdown_004089e0(void);
extern void MStackBracket7_DispatchAndChain_004b8fa0(void);
extern void MStackBracketed3StoreCall_00475990(void);
extern void ChainDirtyBitWalker_00408c10(void);
extern void Wrapper_0048a350(void);
extern void Wrapper_0048a3a0(void);
extern void Helper_DownloadSetup(void);
extern void MStackPush3CmpCall_0048eec0(void);
extern void Wrapper_0048ec20(void);
extern void FiveCallScaledChainTailJmp_0045f8d0(void);
extern void SetJmp_00438f50(void);
extern void SetJmp_00438f60(void);
extern void GuardedDispatch_0042b6c0(void);
extern void MStackPushZeroCallPop_00407d00(void);
extern void DirtyToggleByGate_0048f350(void);
extern void GameDispatchValidateState_004339c0(void);
extern void CrouchAttackFsmCluster_0046f7a0(void);
extern void MStackPushVec3Mul10_004767e0(void);
extern void LiteralPushCallEntZero_00488c00(void);
extern void LeaPlus22StoreSelf_0048e4d0(void);
extern void IterLoad_00491050(void);
extern void GuardedDualConst2AndToggle_0048eba0(void);
extern void CallPauseScaledStorePushCall_0045fca0(void);
extern void LoadGeoAsset_Default(void);
extern void DispatcherComplex260_00407400(void);
extern void PushSetCallPop_00406530(void);
extern unsigned int g_state_0053a3c0;
extern unsigned int g_player1NodeIdx;
extern unsigned int g_installOwnerNode_00535cf8;
extern unsigned int g_cj_00542054;
extern unsigned int g_data_005437f0;
extern unsigned int g_data_00543598;
extern unsigned int g_data_0054358c;
extern unsigned int g_fightAxisNegX_00535e70;
extern unsigned int g_fightAxisNegY_00535e74;
extern unsigned int g_fightAxisPosX_00535e78;
extern unsigned int g_fightAxisPosY_00535e7c;

/* @addr 0x004609e0 (383b game) - 2-entry packed: 3-call chain + countdown
 *   install. Entry 1 (offset 0, 104b): writes g_walkCallback into
 *     [scaled+0x6c], sets 0x54206c=0x2147, chains
 *     MStackFrameCdeclDouble_004903f0 → NineEntryFlagDispatch_00461260 →
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
 *     phase 0: sets g_xformEntityIdx = &g_data_00500c50>>2, calls
 *       DualScaledStoreZero_00491080. On no-error writes 0xb into
 *       [g_fightGroupHead*4 + 0x28], g_eventQueueChild=1, installs Self
 *       at body, arms 0x541e6c=1.
 */
extern unsigned int g_data_004e9f78;
extern unsigned int g_data_004e9f80;
extern unsigned int g_data_00500c50;
extern unsigned int g_framePauseFlag;
extern unsigned int g_xformEntityIdx;
extern unsigned int g_pendingNodeType;
extern unsigned int g_fightGroupHead;
extern unsigned int g_baseSel_00542060;
extern unsigned int g_eventQueueChild;
extern unsigned int g_xformDirtyFlags;
extern void DispatchThroughBaseSel6c_00460f20(void);
extern void DualScaledStoreZero_00491080(void);
extern void GatedScaledSubSat_0048fb40(void);
extern void GuardedScaledChainJmpIndirect_00460e40(void);
extern void NineEntryFlagDispatch_00461260(void);
extern void StateSnapshotDispatch_00460b60(void);
extern void ZeroScaledZeroCallPauseJmp_0045fa90(void);

__declspec(naked) void AlarmCountdownInstall_004609e0(void) {
    __asm {
        mov     ecx, dword ptr [g_baseSel_00542060]
        mov     eax, dword ptr [g_walkCallback]
        mov     dword ptr [ecx*4 + 0x6c], eax
        mov     dword ptr [g_walkCallback], 0x2147
        call    MStackFrameCdeclDouble_004903f0
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
        push    offset g_data_004e9f78
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
        mov     eax, dword ptr [g_baseSel_00542060]
        push    ebx
        push    esi
        lea     esi, [eax*4]
        mov     eax, dword ptr [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], 0
        test    eax, eax
        je      L_aci_phase0
        push    offset g_data_004e9f80
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
        mov     ecx, offset g_data_00500c50
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
