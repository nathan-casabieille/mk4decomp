/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;
extern unsigned int g_baseSel_00542060;
extern unsigned int g_acc_00542078;
extern unsigned int g_cj_0054205c;
extern unsigned int g_gameCountdown_0053a718;
extern unsigned int g_xformScratch94;
extern unsigned int g_table_00535ddc;
extern unsigned int g_active_00537e88;
extern unsigned int g_active_0053a408;
extern unsigned int g_audioBankSel_00537f94;

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
extern unsigned int g_cj_00542058;
extern unsigned int g_rangeSqLimit_0053a180;
extern unsigned int g_zero_00541fa4;
extern unsigned int g_zero_00541fa8;
extern unsigned int g_dualBitGate_0053a7b0;
extern unsigned int g_eventArmReload_0053a770;
extern unsigned int g_rangeBase_0053a46c;

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
extern unsigned int g_stateCountdown_0053a3c0;
extern unsigned int g_installOwnerNode_00535cf8;
extern unsigned int g_cj_00542054;
extern unsigned int g_audioBoundNode_005437f0;
extern unsigned int g_lastGatedValue_00543598;
extern unsigned int g_lastGatedTick_0054358c;
extern unsigned int g_fightAxisNegX_00535e70;
extern unsigned int g_fightAxisNegY_00535e74;
extern unsigned int g_fightAxisPosX_00535e78;
extern unsigned int g_fightAxisPosY_00535e7c;

/*
 * @addr 0x00439920 (129b game) - weighted-sum + cap + helper:
 *   computes walk = clamp(0x53a3c0 * 0x4f381c + 0x4f3814 + 0x54355c_dispatch
 *   + 0x541fb0*0x4f3818 + 0x53a1f0*0x4f3820, max 0x3cf); cj-dependent
 *   pick of multiplier (0x5433f0 if baseSel==0x538038, else 0x543444);
 *   call func_004ab620.
 */
extern unsigned int g_x_004f3814;
extern unsigned int g_x_004f3818;
extern unsigned int g_x_004f381c;
extern unsigned int g_x_004f3820;
extern unsigned int g_audioRestoreSlot3_0053a1f0;
extern unsigned int g_phaseCounter_00541fb0;
extern unsigned int g_audioInstallSlot2_005433f0;
extern unsigned int g_phaseThunkSave2_00543444;
extern unsigned int g_audioPathFlag_0054355c;
extern void AudioVolumeRescale_004ab690(void);

/*
 * NON-COAXABLE: orig keeps d (g_x_004f3818) in ecx (volatile) across the entire
 * dispatch branch, and reuses esi as scratch for two different short-lived values
 * (ref in dispatch branch, then f intermediate after noScale). MSVC /O2 instead
 * promotes d to edi (extra callee-saved push), giving two-register prologue
 * (push esi/edi) vs orig's single push esi. The volatile-register-survives-
 * branch + register-reuse pattern is not coaxable from pure C.
 */
__declspec(naked) void WeightedSumClampHelper_00439920(void) {
    __asm {
        mov     eax, dword ptr [g_stateCountdown_0053a3c0]
        mov     edx, dword ptr [g_x_004f3814]
        imul    eax, dword ptr [g_x_004f381c]
        mov     ecx, dword ptr [g_audioPathFlag_0054355c]
        add     eax, edx
        test    ecx, ecx
        mov     ecx, dword ptr [g_x_004f3818]
        push    esi
        je      noScale
        mov     edx, dword ptr [g_baseSel_00542060]
        mov     esi, dword ptr [g_gtPlayerProbe2]
        cmp     edx, esi
        mov     edx, ecx
        jne     useB
        imul    edx, dword ptr [g_audioInstallSlot2_005433f0]
        jmp     after
useB:
        imul    edx, dword ptr [g_phaseThunkSave2_00543444]
after:
        add     eax, edx
noScale:
        mov     esi, dword ptr [g_phaseCounter_00541fb0]
        mov     edx, dword ptr [g_audioRestoreSlot3_0053a1f0]
        imul    edx, dword ptr [g_x_004f3820]
        imul    esi, ecx
        add     esi, eax
        lea     eax, [esi + edx]
        cmp     eax, 0x3cf
        mov     dword ptr [g_walkCallback], eax
        jle     callTail
        mov     dword ptr [g_walkCallback], 0x3cf
callTail:
        call    AudioVolumeRescale_004ab690
        pop     esi
        ret
    }
}
