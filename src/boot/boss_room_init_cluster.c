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

extern void func_0047f830(void);
extern void MStackCall_00406340(void);
extern void BossRoomInitCluster_00410340(void);

/* @addr 0x004101f0 (329b boot) - bundled boot installer pair.
 *   sub-1 (~20b @ 0x4101f0): pushes 0x88 and callback ptr (sub-2 @ 0x00410210),
 *     calls StoreTwoCall_0049cb40 to register the callback.
 *   sub-2 (~309b @ 0x00410210): boot countdown state machine.
 *     If [esi+0x84] non-zero (already installed): decrement g_data_00542054
 *     countdown, jns to chain-walk, else call GuardedSeq_00471670.
 *     Else: setup pipeline with DispatcherComplex260_00407400, MStackCall_00406340,
 *     install self at [esi+8] = 0x00410210, set state flags.
 */
__declspec(naked) void BootInstallerPair_004101f0(void) {
    __asm {
        /* sub-1: trampoline */
        push    0x88
        push    offset L_bip_callback
        call    StoreTwoCall_0049cb40
        add     esp, 8
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
        /* sub-2: callback */
    L_bip_callback:
        mov     eax, dword ptr [g_data_00542060]
        push    esi
        lea     esi, [eax*4]
        mov     eax, [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], 0
        test    eax, eax
        jz      short L_bip_init
        mov     eax, dword ptr [g_data_00542054]
        dec     eax
        mov     dword ptr [g_data_00542054], eax
        jns     L_bip_resume
        call    GuardedSeq_00471670
        pop     esi
        ret
    L_bip_init:
        mov     ecx, 0x004d57f8
        shr     ecx, 2
        mov     dword ptr [g_data_00542048], ecx
        call    DispatcherComplex260_00407400
        mov     eax, dword ptr [g_data_00541e6c]
        test    eax, eax
        jne     L_bip_done
        test    byte ptr [g_state_0054208c], 4
        jz      short L_bip_doMain
        call    func_0047f830
        pop     esi
        ret
    L_bip_doMain:
        mov     eax, dword ptr [g_data_00542044]
        mov     dword ptr [g_data_0054205c], eax
        mov     ecx, dword ptr [eax*4 + 0x34]
        or      ecx, 2
        mov     dword ptr [eax*4 + 0x34], ecx
        mov     edx, dword ptr [g_data_00542044]
        mov     eax, 0x00100000
        mov     dword ptr [g_data_0054206c], eax
        mov     dword ptr [edx*4 + 0x5c], eax
        call    MStackCall_00406340
        mov     eax, dword ptr [g_data_00541e6c]
        test    eax, eax
        jne     L_bip_done
        mov     eax, 0x004d57c8
        mov     dword ptr [g_data_0054206c], 0x00ffffff
        shr     eax, 2
        mov     dword ptr [g_data_00542044], eax
        mov     dword ptr [eax*4], 0x00ffffff
        mov     eax, 0x004d6e20
        shr     eax, 2
        mov     dword ptr [g_data_00542054], 6
        mov     dword ptr [g_data_00542058], eax
        jmp     short L_bip_loadIdx
    L_bip_resume:
        mov     eax, dword ptr [g_data_00542058]
    L_bip_loadIdx:
        mov     ecx, [eax*4]
        inc     eax
        mov     dword ptr [g_data_0054206c], ecx
        mov     dword ptr [g_data_00542058], eax
        call    BossRoomInitCluster_00410340
        mov     eax, dword ptr [g_data_00541e6c]
        test    eax, eax
        jne     short L_bip_done
        mov     eax, 1
        mov     dword ptr [esi + 8], offset L_bip_callback
        mov     dword ptr [esi + 0x84], eax
        mov     dword ptr [g_data_0054204c], eax
        mov     dword ptr [g_data_00541e6c], eax
    L_bip_done:
        pop     esi
        ret
    }
}
