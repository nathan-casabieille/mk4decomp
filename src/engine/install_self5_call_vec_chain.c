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

/* @addr 0x00464660 (386b game) - install-self with 5-call vec/slot chain.
 *   Always installs Self at end (no phase check). Sets:
 *     - g_data_00542048 = g_data_00541f8c (vec0 base)
 *     - g_data_0054204c = g_data_00542060 + 0xc (slot pointer+0xc)
 *     - g_data_00542050 = [g_data_00542054*4] (deref scope)
 *   If 0x542050 is non-zero AND [g_data_00542058*4] is non-zero, runs a
 *   5-step chain through scaled-buffer indices: QuadInterpolatorV2_004255b0 (+0x15) →
 *   TripleSubVec3_004250f0 (+0x15) → ThreeMul10Stores_004252c0
 *   (with 0xcccc weight) → TripleSubVec3_004250f0 (+0x1b) →
 *   ThreeClampLoop_00425a80 (with 0x4ccc cap) → TripleAddVec3_00425130
 *   (with +0x1b advance). Failure path skips remaining calls.
 *
 *   Tail unconditionally installs Self with slot[+0x84]=1,
 *   g_data_0054204c=2, arms 0x541e6c=1.
 */
extern unsigned int g_framePauseFlag;
extern unsigned int g_data_00541f8c;
extern unsigned int g_data_00541f98;
extern unsigned int g_data_00542044;
extern unsigned int g_data_00542048;
extern unsigned int g_data_0054204c;
extern unsigned int g_data_00542054;
extern unsigned int g_data_00542058;
extern unsigned int g_data_00542060;
extern void QuadInterpolatorV2_004255b0(void);
extern void ThreeClampLoop_00425a80(void);
extern void ThreeMul10Stores_004252c0(void);
extern void TripleAddVec3_00425130(void);
extern void TripleSubVec3_004250f0(void);

__declspec(naked) void InstallSelf5CallVecChain_00464660(void) {
    __asm {
        mov     eax, dword ptr [g_data_00542060]
        push    esi
        mov     dword ptr [eax*4 + 0x84], 0
        mov     edx, dword ptr [g_data_00542060]
        mov     ecx, dword ptr [g_data_00541f8c]
        lea     esi, [eax*4]
        mov     eax, dword ptr [g_data_00542054]
        add     edx, 0xc
        mov     dword ptr [g_data_00542048], ecx
        mov     dword ptr [g_data_0054204c], edx
        mov     eax, dword ptr [eax*4]
        test    eax, eax
        mov     dword ptr [g_data_00542050], eax
        je      L_isvc_install
        mov     ecx, dword ptr [g_data_00541f98]
        add     eax, 0x15
        mov     dword ptr [g_data_00542050], eax
        mov     dword ptr [g_data_00542044], ecx
        call    QuadInterpolatorV2_004255b0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_isvc_done
        mov     edx, dword ptr [g_data_00542044]
        mov     eax, dword ptr [g_data_00542058]
        mov     ecx, dword ptr [g_data_00542050]
        mov     dword ptr [g_data_00542048], edx
        mov     eax, dword ptr [eax*4]
        test    ecx, ecx
        je      L_isvc_install
        add     eax, 0x15
        mov     dword ptr [g_data_0054204c], eax
        call    TripleSubVec3_004250f0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_isvc_done
        mov     ecx, dword ptr [g_data_00542044]
        mov     dword ptr [g_walkCallback], 0xcccc
        mov     dword ptr [g_data_00542048], ecx
        call    ThreeMul10Stores_004252c0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_isvc_done
        mov     edx, dword ptr [g_data_00542044]
        mov     eax, dword ptr [g_data_00542058]
        mov     dword ptr [g_data_00542048], edx
        mov     ecx, dword ptr [eax*4]
        add     ecx, 0x1b
        mov     dword ptr [g_data_0054204c], ecx
        call    TripleSubVec3_004250f0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_isvc_done
        mov     edx, dword ptr [g_data_00542044]
        mov     dword ptr [g_walkCallback], 0x4ccc
        mov     dword ptr [g_data_00542048], edx
        call    ThreeClampLoop_00425a80
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_isvc_done
        mov     eax, dword ptr [g_data_00542044]
        mov     ecx, dword ptr [g_data_00542058]
        mov     dword ptr [g_data_00542048], eax
        mov     eax, dword ptr [ecx*4]
        add     eax, 0x1b
        mov     dword ptr [g_data_0054204c], eax
        mov     dword ptr [g_data_00542044], eax
        call    TripleAddVec3_00425130
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_isvc_done
    L_isvc_install:
        mov     eax, 1
        mov     dword ptr [esi + 8], offset InstallSelf5CallVecChain_00464660
        mov     dword ptr [esi + 0x84], eax
        mov     dword ptr [g_data_0054204c], 2
        mov     dword ptr [g_framePauseFlag], eax
    L_isvc_done:
        pop     esi
        ret
    }
}
