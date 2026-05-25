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
extern unsigned int g_audioBankSel_00537f94;
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
extern unsigned int g_rangeSqLimit_0053a180;
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
extern unsigned int g_audioBoundNode_005437f0;
extern unsigned int g_data_00543598;
extern unsigned int g_data_0054358c;
extern unsigned int g_fightAxisNegX_00535e70;
extern unsigned int g_fightAxisNegY_00535e74;
extern unsigned int g_fightAxisPosX_00535e78;
extern unsigned int g_fightAxisPosY_00535e7c;

extern void ScaledAndAlfe_00490390(void);
extern void TripleCallPauseJmp_00470500(void);
extern void Wrapper_0048a3c0(void);
extern void PhaseDispatchListAdvance_004709e0(void);
extern void CallPauseDirtyMStackPushFn_0046e2a0(void);
extern void InstallSelfMStackOverwrite_0046e9a0(void);
extern void FiveEntryAlarmInstallChain_0046ee00(void);
extern void MStackJmpInstallSelf_0046ed40(void);
extern unsigned int g_data_004eb6c8;

/* @addr 0x0046eac0 (339b game) - 5-thunk dispatcher with mstack-push chain (state-machine via mstack callback ptrs).
 *   Thunk A (0..0x3f): call ScaledAndAlfe; if pause ret. chain[baseSel*4+0x74]=0x603, g_walkCallback=0x603.
 *     Call TripleCallPauseJmp; if pause ret. Push 0x004eb6b8; call ArgSarStoreJmp; pop; ret. 15-NOP pad.
 *   Thunk B (+0x50): call Wrapper_0048a3c0; if pause ret.
 *     g_eventQueueEnd = (0x004eb6c8 >> 2); tail-jmp PhaseDispatchListAdvance_004709e0. ret. 15-NOP pad.
 *   Thunk C (+0x80): if bit0(0054208c): jmp CallPauseDirtyMStackPushFn.
 *     g_eventQueueChild=g_eventQueueNotMask=7. Mstack-push body_eb80; tail-jmp InstallSelfMStackOverwrite. 8-NOP pad.
 *   Thunk D body_eb80 (+0xc0): if bit0: jmp FiveEntryAlarmInstallChain_0046ee00.
 *     g_eventQueueChild=8; g_eventQueueNotMask=7. Mstack-push body_ebc0; tail-jmp InstallSelfMStackOverwrite. 3-NOP pad.
 *   Thunk E body_ebc0 (+0x100): same as D but state_00542080=9; mstack-push body_ec00. 3-NOP pad.
 *   Thunk F body_ec00 (+0x140): if bit0 jmp FiveEntryAlarmInstallChain_0046ee00; else jmp MStackJmpInstallSelf.
 */
extern unsigned int g_framePauseFlag;
extern unsigned int g_eventQueueEnd;
extern void ArgSarStoreJmp_004594f0(void);

extern unsigned int g_data_004d57ac_arr;

__declspec(naked) void FiveThunkMStackDispatcher_0046eac0(void) {
    __asm {
        call    ScaledAndAlfe_00490390
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   32h
        mov     ecx, dword ptr [g_baseSel_00542060]
        mov     eax, 0x603
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x74], eax
        call    TripleCallPauseJmp_00470500
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   0dh
        push    0x004eb6b8
        call    ArgSarStoreJmp_004594f0
        add     esp, 4
        ret
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        call    Wrapper_0048a3c0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   12h
        mov     eax, offset g_data_004eb6c8
        sar     eax, 2
        mov     dword ptr [g_eventQueueEnd], eax
        jmp     PhaseDispatchListAdvance_004709e0
        ret
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        test    byte ptr [g_xformDirtyFlags], 1
        _emit   74h
        _emit   05h
        jmp     CallPauseDirtyMStackPushFn_0046e2a0
        mov     eax, 7
        mov     dword ptr [g_eventQueueChild], eax
        mov     dword ptr [g_eventQueueNotMask], eax
        mov     eax, dword ptr [g_state_004d57ac]
        inc     eax
        mov     dword ptr [g_state_004d57ac], eax
        mov     [eax*4 + g_data_004d57ac_arr], offset FiveThunkMStackDispatcher_0046eac0 + 0xc0
        jmp     InstallSelfMStackOverwrite_0046e9a0
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
    body_eb80:
        test    byte ptr [g_xformDirtyFlags], 1
        _emit   74h
        _emit   05h
        jmp     FiveEntryAlarmInstallChain_0046ee00
        mov     eax, dword ptr [g_state_004d57ac]
        mov     dword ptr [g_eventQueueChild], 8
        inc     eax
        mov     dword ptr [g_eventQueueNotMask], 7
        mov     dword ptr [g_state_004d57ac], eax
        mov     [eax*4 + g_data_004d57ac_arr], offset FiveThunkMStackDispatcher_0046eac0 + 0x100
        jmp     InstallSelfMStackOverwrite_0046e9a0
        _emit   90h
        _emit   90h
        _emit   90h
    body_ebc0:
        test    byte ptr [g_xformDirtyFlags], 1
        _emit   74h
        _emit   05h
        jmp     FiveEntryAlarmInstallChain_0046ee00
        mov     eax, dword ptr [g_state_004d57ac]
        mov     dword ptr [g_eventQueueChild], 9
        inc     eax
        mov     dword ptr [g_eventQueueNotMask], 7
        mov     dword ptr [g_state_004d57ac], eax
        mov     [eax*4 + g_data_004d57ac_arr], offset FiveThunkMStackDispatcher_0046eac0 + 0x140
        jmp     InstallSelfMStackOverwrite_0046e9a0
        _emit   90h
        _emit   90h
        _emit   90h
    body_ec00:
        test    byte ptr [g_xformDirtyFlags], 1
        _emit   74h
        _emit   05h
        jmp     FiveEntryAlarmInstallChain_0046ee00
        jmp     MStackJmpInstallSelf_0046ed40
    }
}
