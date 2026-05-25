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

extern unsigned int g_const_004d2ebc;
extern unsigned int g_const_004d2ee4;
extern unsigned int g_const_004d2ee8;
extern unsigned int g_const_004d2f04;
extern unsigned int g_const_004d2f08;
extern unsigned int g_data_00520064;
extern unsigned int g_data_00522908;
extern unsigned int g_data_0052290c;
extern unsigned int g_crtCType_00522998;
extern unsigned int g_state_00f9f84c_ee;
extern unsigned int g_arr_00fa0de0;
extern unsigned int g_iat_004d20a0;
extern unsigned int g_iat_004d2108;
extern unsigned int g_iat_004d2148;
extern void LazyLoadInvoke_004ce150(void);
extern void Strncpy_004cdc20(void);

__declspec(naked) void RaiseAbortLocalized_004cc070(void)
{
    __asm {
        mov      ecx, dword ptr [esp + 4]
        sub      esp, 0x1a8
        mov      eax, OFFSET g_data_00522908
        push     ebx
        push     ebp
        push     esi
        push     edi
        xor      ebp, ebp
    L_c085:
        cmp      ecx, dword ptr [eax]
        je       short L_c094
        add      eax, 8
        inc      ebp
        cmp      eax, OFFSET g_crtCType_00522998
        jb       short L_c085
    L_c094:
        cmp      ecx, dword ptr [ebp*8 + g_data_00522908]
        jne      L_c23b
        mov      eax, dword ptr [g_state_00f9f84c_ee]
        cmp      eax, 1
        je       L_c1fd
        test     eax, eax
        jne      short L_c0c0
        cmp      dword ptr [g_data_00520064], 1
        je       L_c1fd
    L_c0c0:
        cmp      ecx, 0xfc
        je       L_c23b
        lea      eax, [esp + 0xb4]
        push     0x104
        push     eax
        push     0
        call     dword ptr [g_iat_004d20a0]
        test     eax, eax
        jne      short L_c0fb
        mov      ecx, 5
        mov      esi, OFFSET g_const_004d2f08
        lea      edi, [esp + 0xb4]
        rep movsd
        movsw
        movsb
    L_c0fb:
        lea      edi, [esp + 0xb4]
        or       ecx, 0xffffffff
        xor      eax, eax
        lea      ebx, [esp + 0xb4]
        repne scasb
        not      ecx
        cmp      ecx, 0x3c
        jbe      short L_c144
        lea      edi, [esp + 0xb4]
        or       ecx, 0xffffffff
        repne scasb
        not      ecx
        dec      ecx
        push     3
        mov      ebx, ecx
        lea      ecx, [esp + 0xb8]
        sub      ecx, 0x3b
        push     OFFSET g_const_004d2f04
        add      ebx, ecx
        push     ebx
        call     Strncpy_004cdc20
        add      esp, 0xc
    L_c144:
        mov      ecx, 6
        mov      esi, OFFSET g_const_004d2ee8
        lea      edi, [esp + 0x14]
        xor      eax, eax
        rep movsd
        movsw
        or       ecx, 0xffffffff
        mov      edi, ebx
        repne scasb
        not      ecx
        sub      edi, ecx
        lea      edx, [esp + 0x14]
        mov      ebx, ecx
        mov      esi, edi
        or       ecx, 0xffffffff
        mov      edi, edx
        repne scasb
        mov      ecx, ebx
        dec      edi
        shr      ecx, 2
        rep movsd
        mov      ecx, ebx
        lea      edx, [esp + 0x14]
        and      ecx, 3
        push     0x12010
        rep movsb
        mov      edi, OFFSET g_const_004d2ee4
        or       ecx, 0xffffffff
        repne scasb
        not      ecx
        sub      edi, ecx
        push     OFFSET g_const_004d2ebc
        mov      esi, edi
        mov      ebx, ecx
        mov      edi, edx
        or       ecx, 0xffffffff
        repne scasb
        mov      ecx, ebx
        dec      edi
        shr      ecx, 2
        rep movsd
        mov      ecx, ebx
        lea      edx, [esp + 0x1c]
        and      ecx, 3
        rep movsb
        mov      edi, dword ptr [ebp*8 + g_data_0052290c]
        or       ecx, 0xffffffff
        repne scasb
        not      ecx
        sub      edi, ecx
        mov      esi, edi
        mov      ebx, ecx
        mov      edi, edx
        or       ecx, 0xffffffff
        repne scasb
        mov      ecx, ebx
        dec      edi
        shr      ecx, 2
        rep movsd
        mov      ecx, ebx
        lea      eax, [esp + 0x1c]
        and      ecx, 3
        push     eax
        rep movsb
        call     LazyLoadInvoke_004ce150
        add      esp, 0xc
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        add      esp, 0x1a8
        ret
    L_c1fd:
        mov      eax, dword ptr [g_arr_00fa0de0]
        test     eax, eax
        je       short L_c20e
        mov      esi, dword ptr [eax + 0x48]
        cmp      esi, -1
        jne      short L_c218
    L_c20e:
        push     -0xc
        call     dword ptr [g_iat_004d2148]
        mov      esi, eax
    L_c218:
        mov      edx, dword ptr [ebp*8 + g_data_0052290c]
        lea      ecx, [esp + 0x10]
        push     0
        push     ecx
        mov      edi, edx
        or       ecx, 0xffffffff
        xor      eax, eax
        repne scasb
        not      ecx
        dec      ecx
        push     ecx
        push     edx
        push     esi
        call     dword ptr [g_iat_004d2108]
    L_c23b:
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        add      esp, 0x1a8
        ret
    }
}
