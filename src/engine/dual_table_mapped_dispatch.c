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
extern unsigned int g_state_00537f94;
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
extern unsigned int g_data_005437f0;
extern unsigned int g_data_00543598;
extern unsigned int g_data_0054358c;
extern unsigned int g_fightAxisNegX_00535e70;
extern unsigned int g_fightAxisNegY_00535e74;
extern unsigned int g_fightAxisPosX_00535e78;
extern unsigned int g_fightAxisPosY_00535e7c;

extern unsigned int g_data_0050b13c;
extern unsigned int g_data_0052ab10;
extern unsigned int g_data_00537f48;
extern unsigned int g_data_005380e0;
extern unsigned int g_framePauseFlag;
extern unsigned int g_currentNodeIdx;
extern unsigned int g_xformEntityIdx;
extern unsigned int g_pendingNodeType;
extern unsigned int g_data_00543088;
extern void BootInitGuardedCallChain_004265d0(void);
extern void TableWalkBoundedCmp_004bd890(void);
extern void ZeroThreeFields_00404ed0(void);

__declspec(naked) void DualTableMappedDispatch_00492e60(void)
{
    __asm
    {
        push    esi
        push    5
        call    TableWalkBoundedCmp_004bd890
        add     esp, 4
        call    BootInitGuardedCallChain_004265d0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_dtmd_ret
        mov     eax, offset g_data_0050b13c
        shr     eax, 2
        mov     dword ptr [g_currentNodeIdx], eax
        call    LoadGeoAsset_Default
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_dtmd_ret
        mov     eax, dword ptr [g_data_00537f48]
        mov     esi, offset g_data_00543088
        shr     esi, 2
        cmp     eax, 0xf
        mov     ecx, esi
        jne     short L_dtmd_skip1
        mov     eax, 6
    L_dtmd_skip1:
        cmp     eax, 0x10
        jne     short L_dtmd_skip2
        mov     eax, 2
    L_dtmd_skip2:
        cmp     eax, 0x11
        jne     short L_dtmd_skip3
        mov     eax, 7
    L_dtmd_skip3:
        add     eax, eax
        add     ecx, eax
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [g_pendingNodeType], ecx
        mov     edx, dword ptr [ecx*4]
        inc     ecx
        mov     dword ptr [g_currentNodeIdx], edx
        mov     dword ptr [g_pendingNodeType], ecx
        mov     dword ptr [g_xformEntityIdx], 0x7e20000
        call    Thunk_004bd5c0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_dtmd_ret
        mov     eax, dword ptr [g_pendingNodeType]
        mov     ecx, dword ptr [eax*4]
        inc     eax
        mov     dword ptr [g_currentNodeIdx], ecx
        mov     dword ptr [g_pendingNodeType], eax
        mov     dword ptr [g_xformEntityIdx], 0x7e00000
        call    Thunk_004bd5c0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_dtmd_ret
        mov     eax, dword ptr [g_data_005380e0]
        cmp     eax, 0xf
        jne     short L_dtmd_skip4
        mov     eax, 6
    L_dtmd_skip4:
        cmp     eax, 0x10
        jne     short L_dtmd_skip5
        mov     eax, 2
    L_dtmd_skip5:
        cmp     eax, 0x11
        jne     short L_dtmd_skip6
        mov     eax, 7
    L_dtmd_skip6:
        add     eax, eax
        add     esi, eax
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [g_pendingNodeType], esi
        mov     edx, dword ptr [esi*4]
        inc     esi
        mov     dword ptr [g_currentNodeIdx], edx
        mov     dword ptr [g_pendingNodeType], esi
        mov     dword ptr [g_xformEntityIdx], 0x7f10000
        call    Thunk_004bd5c0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_dtmd_ret
        mov     eax, dword ptr [g_pendingNodeType]
        mov     ecx, dword ptr [eax*4]
        inc     eax
        mov     dword ptr [g_currentNodeIdx], ecx
        mov     dword ptr [g_pendingNodeType], eax
        mov     dword ptr [g_xformEntityIdx], 0x7e10000
        call    Thunk_004bd5c0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_dtmd_ret
        mov     eax, dword ptr [g_data_0052ab10]
        mov     dword ptr [g_currentNodeIdx], eax
        lea     esi, [eax*4]
        call    ZeroThreeFields_00404ed0
        mov     eax, 0xfff88000
        mov     dword ptr [esi + 0x54], 0
        mov     dword ptr [esi + 0x58], 0x1999
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [esi + 0x5c], eax
    L_dtmd_ret:
        pop     esi
        ret
    }
}
