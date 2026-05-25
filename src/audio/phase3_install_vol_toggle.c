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

/* @addr 0x004a8310 (377b audio) - phase-state install w/ vol-up/down on input.
 *   Phase 0: sets [0x52aac4]=2, [0x53a50c]=0xe, installs Self with
 *     slot[+0x84]=1, g_data_0054204c=1, arms 0x541e6c=1.
 *   Phase 1+: AudioSwap2ChainBank3State_004a8490; reads slot[+0x30]:
 *     if 4 → reads vol byte at [g_data_005435a0 + 0x542070*0x18],
 *     if 3 → similar with g_data_0054359c stride. Then
 *     DualListInit_004a8290 + [g_data_00543590]==1 ? DebugStub_NoOp_A :
 *     DebugStub_NoOp_B. Tests [g_data_004d50b4] al/ah bit 2 / 3 for
 *     vol-down / vol-up (via dec/inc cl on the 0x18-stride byte table),
 *     wrapping at 0/0xe. Final call TripleCallByteCheck_004a1bf0; on
 *     zero, calls AudioMicroEntries_004a7600 with the current vol byte
 *     and tail-jmps StackPopDispatchTagged_0041f780. Else: stores
 *     g_data_00542054 into 0x542044, vol byte into 0x54206c, calls
 *     ScaledChainStore24_004a7d40 and falls through to install tail.
 */
extern unsigned int g_data_004d50b4;
extern unsigned int g_data_0052aac4;
extern unsigned int g_data_0053a50c;
extern unsigned int g_framePauseFlag;
extern unsigned int g_data_00542044;
extern unsigned int g_data_0054204c;
extern unsigned int g_data_00542054;
extern unsigned int g_data_00542060;
extern unsigned int g_data_0054206c;
extern unsigned int g_data_005433c8;
extern unsigned int g_data_00543590;
extern unsigned int g_data_0054359c;
extern unsigned int g_data_005435a0;
extern void AudioMicroEntries_004a7600(void);
extern void AudioSwap2ChainBank3State_004a8490(void);
extern void DebugStub_NoOp_A(void);
extern void DebugStub_NoOp_B(void);
extern void DualListInit_004a8290(void);
extern void ScaledChainStore24_004a7d40(void);
extern void SetJmp_004a1ad0(void);
extern void TripleCallByteCheck_004a1bf0(void);

__declspec(naked) void Phase3InstallVolToggle_004a8310(void) {
    __asm {
        mov     eax, dword ptr [g_data_00542060]
        push    esi
        lea     esi, [eax*4]
        mov     eax, dword ptr [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], 0
        test    eax, eax
        je      L_p3v_phase0
        call    AudioSwap2ChainBank3State_004a8490
        mov     ecx, dword ptr [g_data_00542060]
        mov     eax, dword ptr [ecx*4 + 0x30]
        sub     eax, 3
        je      short L_p3v_phase3
        dec     eax
        jne     short L_p3v_afterSnap
        mov     eax, dword ptr [g_data_005433c8]
        add     ecx, eax
        add     eax, 5
        mov     edx, dword ptr [ecx*4 + 0x48]
        mov     dword ptr [g_data_00542054], edx
        jmp     short L_p3v_storeVol
    L_p3v_phase3:
        mov     eax, dword ptr [g_data_0054359c]
        add     ecx, eax
        mov     edx, dword ptr [ecx*4 + 0x34]
        mov     dword ptr [g_data_00542054], edx
    L_p3v_storeVol:
        mov     dword ptr [g_data_00542070], eax
    L_p3v_afterSnap:
        call    DualListInit_004a8290
        cmp     byte ptr [g_data_00543590], 1
        jne     short L_p3v_useStubB
        call    DebugStub_NoOp_A
        jmp     short L_p3v_postStub
    L_p3v_useStubB:
        call    DebugStub_NoOp_B
    L_p3v_postStub:
        mov     eax, dword ptr [g_data_004d50b4]
        test    al, 4
        jne     short L_p3v_doDown
        test    ah, 4
        je      short L_p3v_checkUp
    L_p3v_doDown:
        call    SetJmp_004a1ad0
        mov     eax, dword ptr [g_data_00542070]
        lea     eax, [eax + eax*2]
        mov     cl, byte ptr [eax*8 + g_data_005435a0]
        dec     cl
        mov     byte ptr [eax*8 + g_data_005435a0], cl
        jns     short L_p3v_okDown
        mov     byte ptr [eax*8 + g_data_005435a0], 0xe
    L_p3v_okDown:
        mov     eax, dword ptr [g_data_004d50b4]
    L_p3v_checkUp:
        test    al, 8
        jne     short L_p3v_doUp
        test    ah, 8
        je      short L_p3v_postUp
    L_p3v_doUp:
        call    SetJmp_004a1ad0
        mov     eax, dword ptr [g_data_00542070]
        lea     eax, [eax + eax*2]
        mov     dl, byte ptr [eax*8 + g_data_005435a0]
        inc     dl
        mov     cl, dl
        mov     byte ptr [eax*8 + g_data_005435a0], dl
        cmp     cl, 0xf
        jne     short L_p3v_postUp
        mov     byte ptr [eax*8 + g_data_005435a0], 0
    L_p3v_postUp:
        call    TripleCallByteCheck_004a1bf0
        test    eax, eax
        mov     eax, dword ptr [g_data_00542070]
        je      short L_p3v_storeAndCall
        lea     eax, [eax + eax*2]
        movsx   ecx, byte ptr [eax*8 + g_data_005435a0]
        push    ecx
        call    AudioMicroEntries_004a7600
        add     esp, 4
        call    StackPopDispatchTagged_0041f780
        pop     esi
        ret
    L_p3v_storeAndCall:
        mov     ecx, dword ptr [g_data_00542054]
        lea     edx, [eax + eax*2]
        mov     dword ptr [g_data_00542044], ecx
        movsx   eax, byte ptr [edx*8 + g_data_005435a0]
        mov     dword ptr [g_data_0054206c], eax
        call    ScaledChainStore24_004a7d40
        jmp     short L_p3v_installTail
    L_p3v_phase0:
        mov     dword ptr [g_data_0052aac4], 2
        mov     dword ptr [g_data_0053a50c], 0xe
    L_p3v_installTail:
        mov     eax, 1
        mov     dword ptr [esi + 8], offset Phase3InstallVolToggle_004a8310
        mov     dword ptr [esi + 0x84], eax
        mov     dword ptr [g_data_0054204c], eax
        mov     dword ptr [g_framePauseFlag], eax
        pop     esi
        ret
    }
}
