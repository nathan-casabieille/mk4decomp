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

extern unsigned int g_byte_004f3238;
extern unsigned int g_byte_004f360c;
extern unsigned int g_byte_004f3610;
extern unsigned int g_byte_00543724;
extern unsigned int g_byte_0054372c;
extern unsigned int g_byte_00543730;
extern unsigned int g_byte_00543a24;
extern unsigned int g_byte_00543a3c;
extern unsigned int g_byte_00543a3d;
extern unsigned int g_byte_00543a3e;
extern unsigned int g_byte_00543ab4;
extern unsigned int g_audioStateMachineVar6_004f31cc;
extern unsigned int g_audioStateMachineVar5_004f31d0;
extern unsigned int g_audioStateMachineVar3_004f3404;
extern unsigned int g_loaded_004f3608;
extern unsigned int g_dispatchSave813_004f361c;
extern unsigned int g_dispatchSave577_004f3814;
extern unsigned int g_dispatchSave576_004f3818;
extern unsigned int g_dispatchSave575_004f381c;
extern unsigned int g_dispatchSave574_004f3820;
extern unsigned int g_or_0052ab40;
extern unsigned int g_audioRestoreSlot3_0053a1f0;
extern unsigned int g_audioSavedGlobal0_00543734;
extern unsigned int g_audioSavedGlobal1_00543738;
extern unsigned int g_audioSavedGlobal2_0054373c;
extern unsigned int g_audioSavedGlobal3_00543740;
extern unsigned int g_audioSavedGlobal4_005437f8;
extern unsigned int g_audioSavedGlobal5_005437fc;
extern u32 g_gsmFlag;
extern unsigned int g_audioSavedReg_00543a28;
extern unsigned int g_audioSavedReg_00543a2c;
extern unsigned int g_audioSavedReg_00543a30;
extern unsigned int g_audioSavedReg_00543a34;
extern unsigned int g_audioSavedReg_00543a38;
extern unsigned int g_audioSavedReg_00543a40;
extern unsigned int g_audioSavedReg_00543a44;
extern unsigned int g_audioSavedReg_00543a48;
extern unsigned int g_audioSavedReg_00543a4c;
extern unsigned int g_audioSavedReg_00543a50;
extern unsigned int g_audioSavedReg_00543a54;
extern unsigned int g_audioSavedReg_00543a58;
extern unsigned int g_audioSavedReg_00543a5c;
extern unsigned int g_audioSavedReg_00543a60;
extern unsigned int g_audioSavedReg_00543a64;
extern unsigned int g_audioRestoreSlot2_00543a68;
extern unsigned int g_menuRestoreD_00543a9c;
extern unsigned int g_menuRestoreA_00543aa0;
extern unsigned int g_menuRestoreB_00543aac;
extern unsigned int g_menuRestoreC_00543ab0;
extern unsigned int g_audioRestoreSlot_00543f7c;
extern unsigned int g_table_004f3f28;
extern unsigned int g_table_0053a53c;
extern unsigned int g_table_00543934;
extern unsigned int g_table_00543a6c;
extern unsigned int g_audioStateMachine0_004f3ae4;
extern unsigned int g_audioStateMachine1_004f3ae8;
extern void Config_SnapshotGlobals(void);

__declspec(naked) void Config_RestoreGlobals(void)
{
    __asm {
        mov     eax, dword ptr [g_gsmFlag]
        push    esi
        test    eax, eax
        push    edi
        je      L_arg_setboth
        mov     ecx, dword ptr [g_audioRestoreSlot_00543f7c]
        test    ecx, ecx
        jne     L_arg_tail
    L_arg_setboth:
        mov     ecx, 1
        test    eax, eax
        mov     dword ptr [g_gsmFlag], ecx
        mov     dword ptr [g_audioRestoreSlot_00543f7c], ecx
        jne     L_arg_main
        call    Config_SnapshotGlobals
    L_arg_main:
        mov     ecx, 0x3C
        mov     esi, offset g_table_00543934
        mov     edi, offset g_table_0053a53c
        mov     al, byte ptr [g_byte_00543a24]
        rep     movsd
        mov     edx, dword ptr [g_audioSavedReg_00543a2c]
        mov     ecx, 5
        mov     esi, offset g_table_00543a6c
        mov     edi, offset g_table_004f3f28
        rep     movsd
        mov     ecx, dword ptr [g_audioSavedReg_00543a28]
        mov     byte ptr [g_byte_004f3238], al
        mov     eax, dword ptr [g_audioSavedReg_00543a30]
        mov     dword ptr [g_audioStateMachineVar6_004f31cc], ecx
        mov     ecx, dword ptr [g_audioSavedReg_00543a34]
        mov     dword ptr [g_audioStateMachineVar5_004f31d0], edx
        mov     edx, dword ptr [g_audioSavedReg_00543a38]
        mov     dword ptr [g_audioSavedGlobal4_005437f8], eax
        mov     al, byte ptr [g_byte_00543a3c]
        mov     dword ptr [g_audioSavedGlobal5_005437fc], ecx
        mov     cl, byte ptr [g_byte_00543a3d]
        mov     dword ptr [g_gtConfig4f], edx
        mov     dl, byte ptr [g_byte_00543a3e]
        mov     byte ptr [g_byte_00543724], al
        mov     eax, dword ptr [g_audioSavedReg_00543a40]
        mov     byte ptr [g_byte_0054372c], cl
        mov     ecx, dword ptr [g_audioSavedReg_00543a44]
        mov     byte ptr [g_byte_00543730], dl
        mov     edx, dword ptr [g_audioSavedReg_00543a48]
        mov     dword ptr [g_audioSavedGlobal0_00543734], eax
        mov     eax, dword ptr [g_audioSavedReg_00543a4c]
        mov     dword ptr [g_audioSavedGlobal1_00543738], ecx
        mov     ecx, dword ptr [g_audioSavedReg_00543a50]
        mov     dword ptr [g_audioSavedGlobal2_0054373c], edx
        mov     edx, dword ptr [g_audioSavedReg_00543a54]
        mov     dword ptr [g_audioSavedGlobal3_00543740], eax
        mov     eax, dword ptr [g_audioSavedReg_00543a58]
        mov     dword ptr [g_dispatchSave577_004f3814], ecx
        mov     ecx, dword ptr [g_audioSavedReg_00543a5c]
        mov     dword ptr [g_dispatchSave576_004f3818], edx
        mov     edx, dword ptr [g_audioSavedReg_00543a60]
        mov     dword ptr [g_dispatchSave575_004f381c], eax
        mov     eax, dword ptr [g_audioSavedReg_00543a64]
        mov     dword ptr [g_dispatchSave574_004f3820], ecx
        mov     ecx, dword ptr [g_audioRestoreSlot2_00543a68]
        mov     dword ptr [g_audioStateMachine0_004f3ae4], edx
        movsb
        mov     dword ptr [g_audioStateMachine1_004f3ae8], eax
        mov     dword ptr [g_or_0052ab40], ecx
    L_arg_tail:
        mov     al, byte ptr [g_byte_00543ab4]
        mov     edx, dword ptr [g_menuRestoreC_00543ab0]
        mov     ecx, dword ptr [g_menuRestoreD_00543a9c]
        mov     byte ptr [g_byte_004f360c], al
        mov     byte ptr [g_byte_004f3610], al
        mov     eax, dword ptr [g_menuRestoreB_00543aac]
        mov     dword ptr [g_loaded_004f3608], edx
        mov     edx, dword ptr [g_menuRestoreA_00543aa0]
        pop     edi
        mov     dword ptr [g_audioStateMachineVar3_004f3404], eax
        mov     dword ptr [g_audioRestoreSlot3_0053a1f0], ecx
        mov     dword ptr [g_dispatchSave813_004f361c], edx
        pop     esi
        ret
    }
}
