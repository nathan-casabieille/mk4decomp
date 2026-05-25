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

extern void CrtFpieeeFlt_004cf060(void);
extern void CrtFpuExceptionFilter_004cf3a0(void);
extern void SwitchErrorCode_004cf6d0(void);
/* extern void RetZero_004cf700(void); -- defined elsewhere with diff sig */
extern void FpuMaskMerge_004cf740(void);
extern unsigned int g_data_00522e50;

extern void RetZero_004cf700(void);

__declspec(naked) void Crt_fpieee_flt_004cdd20(void)
{
    __asm {
        sub      esp, 0x58
        mov      ecx, dword ptr [esp + 0x64]
        push     ebx
        push     esi
        mov      esi, dword ptr [esp + 0x68]
        xor      eax, eax
        push     edi
        mov      ax, word ptr [ecx]
        mov      ecx, dword ptr [esi]
        dec      ecx
        mov      dword ptr [esp + 0x70], eax
        cmp      ecx, 7
        ja       short L_ddb0
        jmp      dword ptr [ecx*4 + L_d20_jmptbl]
    L_dd46:
        mov      edi, 8
    L_dd4b:
        lea      ebx, [esi + 0x18]
        push     eax
        push     ebx
        push     edi
        call     CrtFpuExceptionFilter_004cf3a0
        add      esp, 0xc
        test     eax, eax
        jne      short L_ddac
        mov      eax, dword ptr [esp + 0x68]
        cmp      eax, 0x10
        je       short L_dd77
        cmp      eax, 0x16
        je       short L_dd77
        cmp      eax, 0x1d
        je       short L_dd77
        and      dword ptr [esp + 0x44], 0xfffffffe
        jmp      short L_dd93
    L_dd77:
        mov      edx, dword ptr [esp + 0x44]
        mov      ecx, dword ptr [esi + 0x10]
        and      edx, 0xffffffe3
        mov      dword ptr [esp + 0x34], ecx
        or       edx, 3
        mov      dword ptr [esp + 0x44], edx
        mov      edx, dword ptr [esi + 0x14]
        mov      dword ptr [esp + 0x38], edx
    L_dd93:
        lea      ecx, [esi + 8]
        push     ebx
        push     ecx
        push     eax
        lea      edx, [esp + 0x7c]
        push     edi
        lea      eax, [esp + 0x1c]
        push     edx
        push     eax
        call     CrtFpieeeFlt_004cf060
        add      esp, 0x18
    L_ddac:
        mov      eax, dword ptr [esp + 0x70]
    L_ddb0:
        push     0xffff
        push     eax
        call     FpuMaskMerge_004cf740
        mov      ecx, dword ptr [esi]
        add      esp, 8
        xor      eax, eax
        cmp      ecx, 8
        je       short L_ddda
        mov      ecx, dword ptr [g_data_00522e50]
        test     ecx, ecx
        jne      short L_ddda
        push     esi
        call     RetZero_004cf700
        add      esp, 4
    L_ddda:
        test     eax, eax
        jne      short L_dde9
        mov      ecx, dword ptr [esi]
        push     ecx
        call     SwitchErrorCode_004cf6d0
        add      esp, 4
    L_dde9:
        pop      edi
        pop      esi
        pop      ebx
        add      esp, 0x58
        ret
    L_ddf0:
        mov      edi, 0x11
        jmp      L_dd4b
    L_ddfa:
        mov      edi, 0x12
        jmp      L_dd4b
    L_de04:
        mov      edi, 4
        jmp      L_dd4b
    L_de0e:
        mov      edi, 0x10
        jmp      L_dd4b
    L_de18:
        mov      dword ptr [esi], 1
        jmp      short L_ddb0
    L_d20_jmptbl:
        _emit 0x46
        _emit 0xdd
        _emit 0x4c
        _emit 0x00
        _emit 0x04
        _emit 0xde
        _emit 0x4c
        _emit 0x00
        _emit 0xf0
        _emit 0xdd
        _emit 0x4c
        _emit 0x00
        _emit 0xfa
        _emit 0xdd
        _emit 0x4c
        _emit 0x00
        _emit 0x46
        _emit 0xdd
        _emit 0x4c
        _emit 0x00
        _emit 0xb0
        _emit 0xdd
        _emit 0x4c
        _emit 0x00
        _emit 0x18
        _emit 0xde
        _emit 0x4c
        _emit 0x00
        _emit 0x0e
        _emit 0xde
        _emit 0x4c
        _emit 0x00
    }
}
