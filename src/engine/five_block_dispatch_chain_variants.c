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
extern unsigned int g_data_00542050;
extern unsigned int g_data_00542070;
extern unsigned int g_data_00542084;
extern unsigned int g_state_0054208c;
extern unsigned int g_state_00542088;
extern unsigned int g_state_00542094;
extern unsigned int g_state_00535ddc;
extern unsigned int g_state_00537e88;
extern unsigned int g_state_0053a408;
extern unsigned int g_state_00537f94;
extern unsigned int g_x_00537f94;
extern unsigned int g_data_0054204c;
extern unsigned int g_state_00542080;
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
extern unsigned int g_state_0054207c;
extern unsigned int g_cj_00542058;
extern unsigned int g_data_0053a180;
extern unsigned int g_state_00541fa4;
extern unsigned int g_state_00541fa8;
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
extern unsigned int g_state_00538158;
extern unsigned int g_data_00535cf8;
extern unsigned int g_cj_00542054;
extern unsigned int g_data_005437f0;
extern unsigned int g_data_00543598;
extern unsigned int g_data_0054358c;
extern unsigned int g_data_00535e70;
extern unsigned int g_data_00535e74;
extern unsigned int g_data_00535e78;
extern unsigned int g_data_00535e7c;

extern void CallPauseDirtyMStackPush484b40_00484b00(void);
extern void GuardedDualConst1AndToggle_0048eb20(void);
extern void FiveBlockDispatchChain_00484b70(void);

/*
 * @addr 0x00484a90 (111b game) - install-self with 3 tail jmps:
 *   captures/zeros base[+0x84]; if set and walk_target non-null
 *   tail-jmps to _00484b00; else call dual-toggle helper; on pause
 *   clear, if state bit 0 set tail-jmp FiveBlockDispatchChain_00484b70 else tail-jmp
 *   _00484b00; else install self with tag.
 */
extern void InstallSelfTri_00484a90(void);
void InstallSelfTri_00484a90(void) {
    unsigned char *base = (unsigned char *)(g_baseSel_00542060 * 4);
    unsigned int v = *(unsigned int *)(base + 0x84);
    *(unsigned int *)(base + 0x84) = 0;
    if (v != 0) {
        unsigned int wt = g_x_00537f94;
        g_walkCallback = (void (*)(void))wt;
        if (wt != 0) {
            CallPauseDirtyMStackPush484b40_00484b00();
            return;
        }
        GuardedDualConst1AndToggle_0048eb20();
        if (g_framePauseFlag != 0) return;
        if ((g_state_0054208c & 1) != 0) {
            FiveBlockDispatchChain_00484b70();
            return;
        }
        CallPauseDirtyMStackPush484b40_00484b00();
        return;
    }
    *(unsigned int *)(base + 8) = (unsigned int)&InstallSelfTri_00484a90;
    *(unsigned int *)(base + 0x84) = 1;
    g_data_0054204c = 1;
    g_framePauseFlag = 1;
}

/* @addr 0x0046ec20 (275b game) - 5 adjacent blocks.
 *   B1 (0..0x4f, 64+15 NOPs): call ScaledAndAlfe_00490390; if !pause: cj[+0x74]=0x604;
 *     call TripleCallPauseJmp_00470500; if !pause: push 0x004eb6d8, tail-call ArgSarStoreJmp.
 *   B2 (0x50..0x7f): call Wrapper_0048a3c0; if !pause: g_x_00542054 = 0x004eb6e8>>2;
 *     tail-jmp PhaseDispatchListAdvance_004709e0.
 *   B3 (0x80..0xbf): if bit0 of state set: tail-jmp CallPauseDirtyMStackPushFn_0046e2a0.
 *     Else: g_state_00542080=8, g_x_0054207c=8, mstack-push 0x0046ece0 (B4 addr);
 *     tail-jmp InstallSelfMStackOverwrite_0046e9a0.
 *   B4 (0xc0..0xff): if bit0 of state set: tail-jmp MatchOverCluster_0046ef70.
 *     Else: g_state_00542080=9, g_x_0054207c=8, mstack-push 0x0046ed20 (B5 addr);
 *     tail-jmp InstallSelfMStackOverwrite_0046e9a0.
 *   B5 (0x100..0x112): if bit0 of state set: tail-jmp MatchOverCluster_0046ef70.
 *     Else: tail-jmp MStackJmpInstallSelf_0046ed40.
 */
extern unsigned int g_pause_00541e6c;
extern unsigned int g_x_00542054;
extern unsigned int g_x_0054206c;
extern unsigned int g_x_0054207c;
extern void ArgSarStoreJmp_004594f0(void);
extern void CallPauseDirtyMStackPushFn_0046e2a0(void);
extern void InstallSelfMStackOverwrite_0046e9a0(void);
extern void MStackJmpInstallSelf_0046ed40(void);
extern void MatchOverCluster_0046ef70(void);
extern void PhaseDispatchListAdvance_004709e0(void);
extern void ScaledAndAlfe_00490390(void);
extern void TripleCallPauseJmp_00470500(void);
extern void Wrapper_0048a3c0(void);

__declspec(naked) void FiveBlockDispatchChain_0046ec20(void) {
    __asm {
        call    ScaledAndAlfe_00490390
        mov     eax, dword ptr [g_pause_00541e6c]
        test    eax, eax
        _emit   75h
        _emit   32h
        mov     ecx, dword ptr [g_baseSel_00542060]
        mov     eax, 0x604
        mov     dword ptr [g_x_0054206c], eax
        mov     dword ptr [ecx*4 + 0x74], eax
        call    TripleCallPauseJmp_00470500
        mov     eax, dword ptr [g_pause_00541e6c]
        test    eax, eax
        _emit   75h
        _emit   0dh
        push    0x004eb6d8
        call    ArgSarStoreJmp_004594f0
        add     esp, 4
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
        nop
        call    Wrapper_0048a3c0
        mov     eax, dword ptr [g_pause_00541e6c]
        test    eax, eax
        _emit   75h
        _emit   12h
        mov     eax, 0x004eb6e8
        sar     eax, 2
        mov     dword ptr [g_x_00542054], eax
        jmp     PhaseDispatchListAdvance_004709e0
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
        nop
        test    byte ptr [g_state_0054208c], 1
        _emit   74h
        _emit   05h
        jmp     CallPauseDirtyMStackPushFn_0046e2a0
        mov     eax, 8
        mov     dword ptr [g_state_00542080], eax
        mov     dword ptr [g_x_0054207c], eax
        mov     eax, dword ptr [g_state_004d57ac]
        inc     eax
        mov     dword ptr [g_state_004d57ac], eax
        _emit   0c7h
        _emit   04h
        _emit   85h
        _emit   00h
        _emit   00h
        _emit   00h
        _emit   00h
        _emit   0e0h
        _emit   0ech
        _emit   46h
        _emit   00h
        jmp     InstallSelfMStackOverwrite_0046e9a0
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        test    byte ptr [g_state_0054208c], 1
        _emit   74h
        _emit   05h
        jmp     MatchOverCluster_0046ef70
        mov     eax, dword ptr [g_state_004d57ac]
        mov     dword ptr [g_state_00542080], 9
        inc     eax
        mov     dword ptr [g_x_0054207c], 8
        mov     dword ptr [g_state_004d57ac], eax
        _emit   0c7h
        _emit   04h
        _emit   85h
        _emit   00h
        _emit   00h
        _emit   00h
        _emit   00h
        _emit   20h
        _emit   0edh
        _emit   46h
        _emit   00h
        jmp     InstallSelfMStackOverwrite_0046e9a0
        nop
        nop
        nop
        test    byte ptr [g_state_0054208c], 1
        _emit   74h
        _emit   05h
        jmp     MatchOverCluster_0046ef70
        jmp     MStackJmpInstallSelf_0046ed40
    }
}
