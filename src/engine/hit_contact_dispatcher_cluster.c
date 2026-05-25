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

extern unsigned int g_data_004d57ac;
extern unsigned int g_data_004ed818;
extern unsigned int g_data_00535ddc;
extern unsigned int g_data_00538158;
extern unsigned int g_framePauseFlag;
extern unsigned int g_data_00542044;
extern unsigned int g_data_0054204c;
extern unsigned int g_data_0054205c;
extern unsigned int g_data_00542060;
extern unsigned int g_data_0054206c;
extern unsigned int g_data_00542074;
extern unsigned int g_data_00542078;
extern unsigned int g_data_0054207c;
extern unsigned int g_data_00542080;
extern unsigned int g_data_00542088;
extern unsigned int g_data_00542094;
extern void ArgSarStoreJmp_004594f0(void);
extern void EsiEdiAliasDualMul10_004906b0(void);
extern void FiveCallGuardSetTail_0046f6b0(void);
extern void Install3StateLongSeq_00480570(void);
extern void MStackPushSet0008_004901a0(void);
extern void NotMaskStorePair_0045f440(void);
extern void PunchAnimCluster_00496d80(void);
extern void PushCallScaledStore_004143c0(void);
extern void ScaledChainJmp_004298e0(void);
extern void ScaledIndexConditionalAdd_0048e400(void);
extern void ScaledZero44_00491500(void);
extern void TripleEntryChainGate_00480790(void);

__declspec(naked) void HitContactDispatcherCluster_00480240(void)
{
    __asm {
        /* === h1 (0x480240): velocity/angle update === */
        mov      eax, dword ptr [g_data_0054207c]
        mov      ecx, dword ptr [g_data_00542070]
        push     esi
        push     eax
        push     ecx
        call     Mul10Tail_00404af0
        mov      edx, dword ptr [g_data_00542080]
        add      esp, 8
        mov      dword ptr [g_data_0054207c], eax
        mov      eax, dword ptr [g_data_00542070]
        push     edx
        push     eax
        call     Mul10Tail_00404af0
        mov      ecx, dword ptr [g_data_00542060]
        mov      dword ptr [g_data_00542080], eax
        mov      esi, dword ptr [g_data_0054207c]
        add      esp, 8
        mov      edx, dword ptr [ecx*4 + 0x38]
        mov      dword ptr [g_data_00542044], edx
        mov      ecx, dword ptr [edx*4 + 0x54]
        mov      dword ptr [g_data_0054206c], ecx
        mov      edx, dword ptr [edx*4 + 0x5c]
        add      edx, eax
        add      ecx, esi
        mov      dword ptr [g_data_00542070], edx
        mov      edx, dword ptr [g_data_0054205c]
        mov      dword ptr [g_data_0054206c], ecx
        mov      dword ptr [edx*4 + 0x54], ecx
        mov      ecx, dword ptr [g_data_0054205c]
        mov      eax, dword ptr [g_data_00542070]
        mov      dword ptr [ecx*4 + 0x5c], eax
        mov      eax, dword ptr [g_data_0054206c]
        mov      edx, dword ptr [g_data_00542070]
        push     eax
        push     eax
        mov      dword ptr [g_data_00542074], eax
        mov      dword ptr [g_data_00542078], edx
        call     Mul10Tail_00404af0
        add      esp, 8
        mov      dword ptr [g_data_00542074], eax
        mov      eax, dword ptr [g_data_00542078]
        push     eax
        push     eax
        call     Mul10Tail_00404af0
        mov      ecx, dword ptr [g_data_00542074]
        add      esp, 8
        add      eax, ecx
        mov      ecx, dword ptr [g_data_0053a180]
        cmp      eax, ecx
        mov      dword ptr [g_data_00542078], eax
        mov      dword ptr [g_data_00542074], ecx
        jle      short L_036c
        mov      eax, dword ptr [g_data_00542060]
        mov      eax, dword ptr [eax*4 + 0x38]
        mov      dword ptr [g_data_00542044], eax
        mov      ecx, dword ptr [eax*4 + 0x54]
        mov      dword ptr [g_data_0054206c], ecx
        mov      edx, dword ptr [eax*4 + 0x5c]
        mov      eax, dword ptr [g_data_0054205c]
        mov      dword ptr [g_data_00542070], edx
        mov      dword ptr [eax*4 + 0x54], ecx
        mov      edx, dword ptr [g_data_0054205c]
        mov      ecx, dword ptr [g_data_00542070]
        mov      dword ptr [edx*4 + 0x5c], ecx
    L_036c:
        call     ScaledChainJmp_004298e0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_03af
        mov      dword ptr [g_data_0054206c], 0xffffd99a
        call     MStackFrameCdeclDouble_004903f0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_03af
        mov      eax, dword ptr [g_data_004d57ac]
        mov      ecx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_data_00542060], ecx
        mov      dword ptr [g_data_004d57ac], eax
        call     ScaledZero44_00491500
    L_03af:
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
        nop
        nop
        /* === h2 (0x4803c0): event 004ed818 forwarder w/ 0x20a === */
        mov      ecx, dword ptr [g_data_00542060]
        mov      eax, 0x20a
        mov      dword ptr [g_data_0054206c], eax
        mov      dword ptr [ecx*4 + 0x74], eax
        call     PushCallScaledStore_004143c0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_03f2
        push     OFFSET g_data_004ed818
        call     ArgSarStoreJmp_004594f0
        add      esp, 4
    L_03f2:
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
        /* === h3 (0x480400): pose-fn 2-state hit-contact === */
    L_0400:
        mov      eax, dword ptr [g_data_00542060]
        push     esi
        push     edi
        mov      edi, 1
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        sub      eax, 0
        je       L_0537
        dec      eax
        je       short L_0454
        mov      dword ptr [g_data_0054206c], 8
        call     ScaledIndexConditionalAdd_0048e400
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_0567
        call     FiveCallGuardSetTail_0046f6b0
        pop      edi
        pop      esi
        ret
    L_0454:
        mov      eax, dword ptr [g_data_00535ddc]
        cmp      eax, 0x10000
        mov      dword ptr [g_data_0054206c], eax
        jge      short L_046d
        call     Install3StateLongSeq_00480570
        pop      edi
        pop      esi
        ret
    L_046d:
        call     TripleEntryChainGate_00480790
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_0567
        mov      dword ptr [g_data_0054206c], 0x9999
        call     EsiEdiAliasDualMul10_004906b0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_0567
        mov      dword ptr [g_data_00542088], 0x10000
        call     PunchAnimCluster_00496d80
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_0567
        call     NotMaskStorePair_0045f440
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_0567
        mov      ecx, dword ptr [g_data_0054205c]
        mov      edx, dword ptr [g_data_00538158]
        mov      eax, edi
        cmp      ecx, edx
        mov      dword ptr [g_data_00542074], eax
        je       short L_04ea
        mov      eax, 0x10
        mov      dword ptr [g_data_00542074], eax
    L_04ea:
        and      eax, dword ptr [g_data_00542070]
        mov      dword ptr [g_data_00542094], eax
        jne      short L_054e
        call     ScaledZeroFour_00490740
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_0567
        call     MStackPushSet0008_004901a0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_0567
        mov      dword ptr [esi + 8], OFFSET L_0400
        mov      dword ptr [esi + 0x84], 2
        mov      dword ptr [g_data_0054204c], 0xc
        mov      dword ptr [g_framePauseFlag], edi
        pop      edi
        pop      esi
        ret
    L_0537:
        mov      edx, dword ptr [g_data_00542060]
        mov      eax, 0x28
        mov      dword ptr [g_data_0054206c], eax
        mov      dword ptr [edx*4 + 0x68], eax
    L_054e:
        mov      dword ptr [esi + 8], OFFSET L_0400
        mov      dword ptr [esi + 0x84], edi
        mov      dword ptr [g_data_0054204c], edi
        mov      dword ptr [g_framePauseFlag], edi
    L_0567:
        pop      edi
        pop      esi
        ret
    }
}
