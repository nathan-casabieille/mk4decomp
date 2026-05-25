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

extern unsigned int g_data_004d5320;
extern unsigned int g_data_004d59e8;
extern unsigned int g_data_00512538;
extern unsigned int g_data_0053815c;
extern unsigned int g_data_0053e35c;
extern unsigned int g_framePauseFlag;
extern unsigned int g_data_00542044;
extern unsigned int g_data_00542048;
extern unsigned int g_data_00542054;
extern unsigned int g_data_0054205c;
extern unsigned int g_data_00542074;
extern void FramePauseScaledStore_00406c10(void);
extern void MStackCall_00406250(void);
extern void MStackPush2ChainLLInsert_00406790(void);
extern void PushSetXfmMaskCallPop_00407140(void);
extern void ScaledChainOr8_00404e50(void);
extern void ScaledTestPauseStore_00408860(void);
extern void ScaledTripleCopy54_004ac040(void);
extern void Thunk_00405ac0(void);

__declspec(naked) void Phase1InitModelAdjustChain_00410fb0(void)
{
    __asm {
        mov     eax, offset g_data_004d59e8
        shr     eax, 2
        mov     dword ptr [g_walkCallback], eax
        call    PushSetXfmMaskCallPop_00407140
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p1im_ret
        test    byte ptr [g_state_0054208c], 4
        jne     L_p1im_ret
        mov     ecx, dword ptr [g_data_00542044]
        mov     edx, offset g_data_00512538
        shr     edx, 2
        mov     dword ptr [g_data_0054205c], ecx
        mov     dword ptr [g_data_00542048], edx
        call    FramePauseScaledStore_00406c10
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p1im_ret
        test    byte ptr [g_state_0054208c], 4
        jne     L_p1im_after_4e50
        mov     ecx, dword ptr [g_data_00542044]
        mov     eax, dword ptr [ecx*4 + 0x20]
        or      ah, 6
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x20], eax
        call    ScaledTestPauseStore_00408860
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p1im_ret
        test    byte ptr [g_state_0054208c], 4
        je      L_p1im_continue
        jmp     MStackPush2ChainLLInsert_00406790
    L_p1im_continue:
        mov     eax, dword ptr [g_data_00542048]
        mov     ecx, dword ptr [eax*4]
        or      ecx, 8
        mov     dword ptr [eax*4], ecx
        mov     eax, dword ptr [g_data_00542048]
        mov     dword ptr [g_walkCallback], 0xB333
        mov     dword ptr [eax*4 + 0x48], 0xB333
        mov     ecx, dword ptr [g_data_0054205c]
        mov     edx, dword ptr [ecx*4 + 0x18]
        mov     dword ptr [g_data_00542048], edx
        call    Thunk_00405ac0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p1im_ret
        mov     eax, dword ptr [g_data_004d5320]
        mov     ecx, dword ptr [g_data_00542044]
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x44], eax
    L_p1im_after_4e50:
        call    ScaledChainOr8_00404e50
        mov     edx, dword ptr [g_data_00542048]
        mov     dword ptr [edx*4 + 0x48], 0xB333
        mov     eax, dword ptr [g_data_0054205c]
        mov     dword ptr [eax*4 + 0x30], 0x72
        mov     eax, dword ptr [g_data_0053e35c]
        mov     ecx, dword ptr [g_data_0054205c]
        shr     eax, 0x10
        and     eax, 1
        mov     dword ptr [g_walkCallback], eax
        mov     edx, dword ptr [ecx*4 + 0x34]
        or      eax, edx
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x34], eax
        call    ScaledTripleCopy54_004ac040
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p1im_ret
        mov     ecx, dword ptr [g_data_00542054]
        mov     edx, dword ptr [g_data_0054205c]
        mov     eax, dword ptr [ecx*4 + 0x58]
        sub     eax, 0x9999
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [edx*4 + 0x58], eax
        mov     ecx, dword ptr [g_data_00535e7c]
        mov     edx, dword ptr [g_data_0053815c]
        mov     eax, dword ptr [g_data_00535e78]
        mov     dword ptr [g_data_00542074], ecx
        mov     ecx, dword ptr [g_data_00542054]
        mov     dword ptr [g_data_00542070], eax
        cmp     ecx, edx
        jne     L_p1im_after_special
        mov     eax, dword ptr [g_data_00535e70]
        cmp     ecx, edx
        mov     dword ptr [g_data_00542070], eax
        jne     L_p1im_after_special
        mov     edx, dword ptr [g_data_00535e74]
        mov     dword ptr [g_data_00542074], edx
    L_p1im_after_special:
        push    eax
        push    0xFFFFF334
        call    Mul10Tail_00404af0
        mov     ecx, dword ptr [g_data_0054205c]
        mov     dword ptr [g_data_00542070], eax
        add     esp, 8
        mov     dword ptr [ecx*4 + 0x6C], eax
        mov     edx, dword ptr [g_data_00542074]
        push    edx
        push    0xFFFFF334
        call    Mul10Tail_00404af0
        mov     ecx, dword ptr [g_data_0054205c]
        mov     dword ptr [g_data_00542074], eax
        add     esp, 8
        mov     dword ptr [ecx*4 + 0x74], eax
        jmp     MStackCall_00406250
    L_p1im_ret:
        ret
    }
}
