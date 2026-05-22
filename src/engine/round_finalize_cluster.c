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

extern unsigned int g_data_004f24a8;
extern unsigned int g_data_004f2540;
extern unsigned int g_data_004f2550;
extern unsigned int g_data_004f2560;
extern unsigned int g_data_00541e6c;
extern unsigned int g_data_00542044;
extern unsigned int g_data_00542048;
extern unsigned int g_data_0054204c;
extern unsigned int g_data_0054205c;
extern unsigned int g_data_00542060;
extern unsigned int g_data_0054206c;
extern unsigned int g_data_00542088;
extern unsigned int g_data_0054208c;
extern unsigned int g_data_00542098;
extern void ArgSarStoreJmp_004594f0(void);
extern void ArgSar_Set0_Jmp_0049c6f0(void);
extern void CallSetPause_0041f830(void);
extern void CondPickDualStore_0049c670(void);
extern void CopyThreeFields_00404df0(void);
extern void DualCmpSwapStore_0049c5a0(void);
extern void MStackBracket2_TreeWalkRecursive_00405e70(void);
extern void MStackBracket5_LinkedListUnlink_00409aa0(void);
extern void MStackPush2ChainPrepend_00409970(void);
extern void Phase1ContextSetup3Helpers_0040d990(void);
extern void QuadBlockSoundInit_0049bb90(void);
extern void ScaledStackCallPause_0049c360(void);
extern void TableLookupCall_00489ff0(void);
extern void ThreeChanPackClamp_00404cc0(void);

__declspec(naked) void RoundFinalizeCluster_0049b8b0(void)
{
    __asm {
        /* === h1 (0x49b8b0): scan chain + 49b7c0 install === */
        mov      ecx, dword ptr [g_data_00542060]
        mov      eax, dword ptr [ecx*4 + 0x68]
        test     eax, eax
        mov      dword ptr [g_data_0054206c], eax
        jne      short L_b8d3
        mov      eax, dword ptr [g_data_0054208c]
        or       al, 4
        mov      dword ptr [g_data_0054208c], eax
        ret
    L_b8d3:
        mov      dword ptr [g_data_00542044], eax
        mov      eax, dword ptr [eax*4]
        test     eax, eax
        mov      dword ptr [g_data_00542048], eax
        jne      short L_b8f5
        mov      eax, dword ptr [g_data_0054208c]
        or       al, 4
        mov      dword ptr [g_data_0054208c], eax
        ret
    L_b8f5:
        mov      edx, dword ptr [eax*4 + 0x1c]
        cmp      edx, 3
        mov      dword ptr [g_data_0054206c], edx
        je       short L_b909
        xor      eax, eax
    L_b909:
        mov      dword ptr [ecx*4 + 0x68], eax
        mov      eax, dword ptr [g_data_00542044]
        mov      edx, dword ptr [g_data_0054208c]
        mov      ecx, 4
        mov      dword ptr [g_data_0054204c], eax
        mov      dword ptr [g_data_00542048], ecx
        mov      eax, dword ptr [eax*4]
        or       edx, ecx
        test     eax, eax
        mov      dword ptr [g_data_00542044], eax
        mov      dword ptr [g_data_0054208c], edx
        je       short L_b966
        xor      edx, ecx
        test     eax, eax
        mov      dword ptr [g_data_0054208c], edx
        je       short L_b966
        call     MStackBracket5_LinkedListUnlink_00409aa0
        mov      eax, dword ptr [g_data_00541e6c]
        test     eax, eax
        jne      L_b9f9
        mov      eax, dword ptr [g_data_00542044]
    L_b966:
        mov      dword ptr [g_data_00542050], eax
        mov      eax, dword ptr [g_data_0054204c]
        mov      dword ptr [g_data_00542044], eax
        call     MStackBracket2_TreeWalkRecursive_00405e70
        mov      eax, dword ptr [g_data_00541e6c]
        test     eax, eax
        jne      short L_b9f9
        mov      eax, dword ptr [g_data_00542050]
        xor      ecx, ecx
        test     eax, eax
        sete     cl
        mov      dword ptr [g_data_00542098], ecx
        mov      ecx, 0xffff6b59
        mov      dword ptr [g_data_00542044], eax
        mov      dword ptr [g_data_0054206c], ecx
        mov      dword ptr [eax*4 + 0x38], ecx
        mov      edx, dword ptr [g_data_00542060]
        mov      eax, dword ptr [edx*4 + 0x64]
        mov      dword ptr [g_data_00542048], eax
        mov      eax, dword ptr [g_data_00542098]
        test     eax, eax
        jne      short L_b9d5
        call     MStackPush2ChainPrepend_00409970
        mov      eax, dword ptr [g_data_00541e6c]
        test     eax, eax
        jne      short L_b9f9
    L_b9d5:
        call     ChainWalkInstall_0049b7c0
        mov      eax, dword ptr [g_data_00541e6c]
        test     eax, eax
        jne      short L_b9f9
        mov      eax, dword ptr [g_data_0054208c]
        mov      dword ptr [g_data_0054206c], 1
        and      al, 0xfb
        mov      dword ptr [g_data_0054208c], eax
    L_b9f9:
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        /* === h2 (0x49ba00): event 004f24a8 forwarder w/ 0x313 store === */
        mov      ecx, dword ptr [g_data_00542060]
        mov      eax, 0x313
        mov      dword ptr [g_data_0054206c], eax
        mov      dword ptr [ecx*4 + 0x74], eax
        call     CondPickDualStore_0049c670
        mov      eax, dword ptr [g_data_00541e6c]
        test     eax, eax
        jne      short L_ba32
        push     OFFSET g_data_004f24a8
        call     ArgSarStoreJmp_004594f0
        add      esp, 4
    L_ba32:
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
        /* === h3 (0x49ba40): event 004f2540 forwarder + 0x11fff2 sub === */
        call     DualCmpSwapStore_0049c5a0
        mov      eax, dword ptr [g_data_00541e6c]
        test     eax, eax
        jne      short L_baaa
        push     OFFSET g_data_004f2540
        call     ScaledStackCallPause_0049c360
        mov      eax, dword ptr [g_data_00541e6c]
        add      esp, 4
        test     eax, eax
        jne      short L_baaa
        test     byte ptr [g_data_0054208c], 4
        jne      short L_baa5
        mov      eax, dword ptr [g_data_00542044]
        push     0x11fff2
        mov      dword ptr [g_data_0054205c], eax
        call     ThreeChanPackClamp_00404cc0
        mov      ecx, dword ptr [g_data_0054205c]
        add      esp, 4
        push     ecx
        call     CopyThreeFields_00404df0
        mov      edx, dword ptr [g_data_0054205c]
        add      esp, 4
        mov      eax, dword ptr [edx*4 + 0x18]
        mov      dword ptr [g_data_00542044], eax
    L_baa5:
        jmp      CallSetPause_0041f830
    L_baaa:
        ret
        nop
        nop
        nop
        nop
        nop
        /* === h4 (0x49bab0): event 004f2550 forwarder + 2x 0x3333 alloc === */
        push     esi
        call     DualCmpSwapStore_0049c5a0
        mov      eax, dword ptr [g_data_00541e6c]
        test     eax, eax
        jne      L_bb51
        push     OFFSET g_data_004f2550
        call     ScaledStackCallPause_0049c360
        mov      eax, dword ptr [g_data_00541e6c]
        add      esp, 4
        test     eax, eax
        jne      short L_bb51
        test     byte ptr [g_data_0054208c], 4
        je       short L_bae9
        call     CallSetPause_0041f830
        pop      esi
        ret
    L_bae9:
        mov      ecx, dword ptr [g_data_00542084]
        mov      eax, dword ptr [g_data_00542044]
        push     ecx
        push     0x3333
        lea      esi, [eax*4]
        call     Mul10Tail_00404af0
        mov      edx, dword ptr [g_data_00542088]
        add      esp, 8
        mov      dword ptr [g_data_00542084], eax
        push     edx
        push     0x3333
        call     Mul10Tail_00404af0
        mov      dword ptr [g_data_00542088], eax
        mov      eax, dword ptr [g_data_00542084]
        mov      dword ptr [esi + 0x6c], eax
        mov      ecx, dword ptr [g_data_00542088]
        add      esp, 8
        mov      dword ptr [esi + 0x74], ecx
        mov      edx, dword ptr [g_data_00542044]
        push     OFFSET g_data_004f2560
        mov      dword ptr [g_data_0054205c], edx
        call     ArgSar_Set0_Jmp_0049c6f0
        add      esp, 4
    L_bb51:
        pop      esi
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
        /* === h5 (0x49bb70): 489ff0+40d990 chain → tail-jmp 49bb90 === */
        mov      dword ptr [g_data_0054206c], 0x5e
        call     TableLookupCall_00489ff0
        mov      eax, dword ptr [g_data_00541e6c]
        test     eax, eax
        jne      short L_bb8b
        call     Phase1ContextSetup3Helpers_0040d990
        mov      eax, dword ptr [g_data_00541e6c]
        test     eax, eax
        jne      short L_bb8b
        jmp      QuadBlockSoundInit_0049bb90
    L_bb8b:
        ret
    }
}
