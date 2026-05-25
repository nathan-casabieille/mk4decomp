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
extern unsigned int g_data_004f3608;
extern unsigned int g_data_0052ab48;
extern unsigned int g_data_00537e88;
extern unsigned int g_data_00538158;
extern unsigned int g_data_0053a3e0;
extern unsigned int g_data_0053a408;
extern unsigned int g_data_0053a700;
extern unsigned int g_framePauseFlag;
extern unsigned int g_data_00542044;
extern unsigned int g_data_0054204c;
extern unsigned int g_data_00542054;
extern unsigned int g_data_00542058;
extern unsigned int g_data_00542060;
extern unsigned int g_data_0054208c;
extern void CallSetPause_0041f830(void);
extern void DualPushSetCallDualPop_00404b10(void);
extern void MStackPush2ChainLLInsert_00406790(void);
extern void MStackPushComplexCallPop_00406430(void);
extern void MultiGateDispatchCallJmp_004779d0(void);
extern void SaveCallRestoreOrXor_00404a00(void);
extern void ScaledLoadGuardedJmp_004066d0(void);
extern void SwapOrPassSet_0048fbf0(void);

__declspec(naked) void AiWalkCounterDualCluster_00477e20(void)
{
    __asm {
        /* === h1 (0x477e20): mstack lookup + counter inc === */
        mov      eax, dword ptr [g_data_004d57ac]
        mov      ecx, dword ptr [g_data_00542044]
        inc      eax
        mov      dword ptr [g_data_004d57ac], eax
        mov      dword ptr [eax*4], ecx
        call     SwapOrPassSet_0048fbf0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_7eda
        mov      edx, dword ptr [g_walkCallback]
        mov      eax, dword ptr [g_data_004f3608]
        cmp      edx, eax
        jne      short L_7ec2
        mov      eax, dword ptr [g_data_0054204c]
        mov      ecx, dword ptr [g_data_00538158]
        cmp      eax, ecx
        jne      short L_7e7d
        mov      eax, dword ptr [g_data_0053a408]
        test     eax, eax
        mov      dword ptr [g_walkCallback], eax
        je       short L_7ec2
        mov      ecx, OFFSET g_data_0053a3e0
        jmp      short L_7e90
    L_7e7d:
        mov      eax, dword ptr [g_data_00537e88]
        test     eax, eax
        mov      dword ptr [g_walkCallback], eax
        je       short L_7ec2
        mov      ecx, OFFSET g_data_0053a700
    L_7e90:
        shr      ecx, 2
        mov      dword ptr [g_data_00542044], ecx
        mov      eax, dword ptr [ecx*4]
        inc      eax
        cmp      eax, 0x3e7
        mov      dword ptr [g_walkCallback], eax
        jae      short L_7ec2
        mov      dword ptr [ecx*4], eax
        call     MultiGateDispatchCallJmp_004779d0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_7eda
    L_7ec2:
        mov      eax, dword ptr [g_data_004d57ac]
        mov      ecx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_data_00542044], ecx
        mov      dword ptr [g_data_004d57ac], eax
    L_7eda:
        ret
        nop
        nop
        nop
        nop
        nop
        /* === h2 (0x477ee0): pose-fn 2-state dispatch === */
    L_7ee0:
        mov      eax, dword ptr [g_data_00542060]
        push     ebp
        push     esi
        push     edi
        lea      esi, [eax*4]
        xor      edi, edi
        mov      eax, dword ptr [esi + 0x84]
        mov      dword ptr [esi + 0x84], edi
        sub      eax, edi
        je       L_80c4
        dec      eax
        mov      eax, dword ptr [g_data_0052ab48]
        mov      dword ptr [g_walkCallback], eax
        je       L_8005
        cmp      eax, edi
        jne      L_7fee
        mov      edx, dword ptr [g_data_0054208c]
        mov      eax, dword ptr [g_data_00542054]
        mov      ebp, 4
        mov      dword ptr [g_data_00542044], eax
        or       edx, ebp
        cmp      eax, edi
        mov      dword ptr [g_data_0054208c], edx
        je       short L_7f5e
        mov      ecx, edx
        xor      ecx, ebp
        cmp      eax, edi
        mov      dword ptr [g_data_0054208c], ecx
        je       short L_7f5e
        call     MStackPushComplexCallPop_00406430
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_8119
    L_7f5e:
        mov      edx, dword ptr [g_data_0054208c]
        mov      eax, dword ptr [g_data_00542058]
        or       edx, ebp
        cmp      eax, edi
        mov      dword ptr [g_data_00542044], eax
        mov      dword ptr [g_data_0054208c], edx
        je       L_80c4
        mov      ecx, edx
        xor      ecx, ebp
        cmp      eax, edi
        mov      dword ptr [g_data_0054208c], ecx
        je       L_80c4
        call     MStackPushComplexCallPop_00406430
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_8119
        push     0x90
        call     DualPushSetCallDualPop_00404b10
        mov      al, byte ptr [g_data_0054208c]
        add      esp, 4
        test     al, 1
        je       L_80c4
        mov      ecx, dword ptr [g_data_00542054]
        mov      dword ptr [g_data_00542044], ecx
        call     MStackPush2ChainLLInsert_00406790
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_8119
        mov      edx, dword ptr [g_data_00542058]
        mov      dword ptr [g_data_00542044], edx
        call     MStackPush2ChainLLInsert_00406790
        jmp      L_80b3
    L_7fee:
        mov      eax, dword ptr [g_data_00542060]
        mov      dword ptr [g_walkCallback], edi
        mov      dword ptr [eax*4 + 0xc], edi
        jmp      L_80ae
    L_8005:
        cmp      eax, edi
        jne      L_809b
        mov      edx, dword ptr [g_data_0054208c]
        mov      eax, dword ptr [g_data_00542054]
        mov      ebp, 4
        mov      dword ptr [g_data_00542044], eax
        or       edx, ebp
        cmp      eax, edi
        mov      dword ptr [g_data_0054208c], edx
        je       short L_804d
        mov      ecx, edx
        xor      ecx, ebp
        cmp      eax, edi
        mov      dword ptr [g_data_0054208c], ecx
        je       short L_804d
        call     ScaledLoadGuardedJmp_004066d0
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_8119
    L_804d:
        mov      edx, dword ptr [g_data_0054208c]
        mov      eax, dword ptr [g_data_00542058]
        or       edx, ebp
        cmp      eax, edi
        mov      dword ptr [g_data_00542044], eax
        mov      dword ptr [g_data_0054208c], edx
        je       short L_8088
        mov      ecx, edx
        xor      ecx, ebp
        cmp      eax, edi
        mov      dword ptr [g_data_0054208c], ecx
        je       short L_8088
        call     ScaledLoadGuardedJmp_004066d0
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_8119
    L_8088:
        mov      dword ptr [esi + 8], OFFSET L_7ee0
        mov      dword ptr [esi + 0x84], 2
        jmp      short L_8105
    L_809b:
        mov      ecx, dword ptr [g_data_00542060]
        mov      dword ptr [g_walkCallback], edi
        mov      dword ptr [ecx*4 + 0xc], edi
    L_80ae:
        call     MultiGateDispatchCallJmp_004779d0
    L_80b3:
        cmp      dword ptr [g_framePauseFlag], edi
        jne      short L_8119
        call     CallSetPause_0041f830
        pop      edi
        pop      esi
        pop      ebp
        ret
    L_80c4:
        push     0x232
        call     SaveCallRestoreOrXor_00404a00
        mov      edx, dword ptr [g_data_00542044]
        add      esp, 4
        mov      dword ptr [g_data_00542054], edx
        push     0x233
        call     SaveCallRestoreOrXor_00404a00
        mov      eax, dword ptr [g_data_00542044]
        add      esp, 4
        mov      dword ptr [g_data_00542058], eax
        mov      dword ptr [esi + 8], OFFSET L_7ee0
        mov      dword ptr [esi + 0x84], 1
    L_8105:
        mov      dword ptr [g_data_0054204c], 0xa
        mov      dword ptr [g_framePauseFlag], 1
    L_8119:
        pop      edi
        pop      esi
        pop      ebp
        ret
    }
}
