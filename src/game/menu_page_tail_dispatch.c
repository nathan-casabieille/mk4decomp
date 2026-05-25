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

extern unsigned int g_data_004f42d8;
extern unsigned int g_data_004f42dc;
extern unsigned int g_menuPageVar_004f5328;
extern unsigned int g_data_004f6164;
extern unsigned int g_data_004f6190;
extern unsigned int g_data_004f61a0;
extern unsigned int g_data_004f61b0;
extern unsigned int g_data_004f61bc;
extern unsigned int g_data_004f61c8;
extern unsigned int g_data_004f61d0;
extern unsigned int g_data_004f61d8;
extern unsigned int g_dispatchSave721_004f61e0;
extern unsigned int g_menuPageDispatch_00543a98;
extern unsigned int g_menuRestoreD_00543a9c;
extern unsigned int g_menuRestoreA_00543aa0;
extern unsigned int g_menuRestoreB_00543aac;
extern unsigned int g_menuRestoreC_00543ab0;
extern unsigned int g_byte_00543ab4;
extern unsigned int g_data_00ab41c8;
extern unsigned int g_data_00ab4328;
extern unsigned int g_data_00ab4358;
extern void DrawMenu(void);
extern void Helper_Sprintf(void);
extern void StringSubstituteAfterColon_004b7160(void);

__declspec(naked) void MenuPageTailDispatch_004b8080(void)
{
    __asm {
        mov      eax, dword ptr [g_menuPageVar_004f5328]
        mov      dword ptr [esp + 8], OFFSET g_dispatchSave721_004f61e0
        test     eax, eax
        mov      dword ptr [esp + 0xc], OFFSET g_data_004f61d8
        mov      dword ptr [esp + 0x10], OFFSET g_data_004f61d0
        mov      dword ptr [esp + 0x14], OFFSET g_data_004f61c8
        mov      dword ptr [esp + 0x18], OFFSET g_data_004f61bc
        mov      dword ptr [esp + 0x1c], OFFSET g_data_004f61b0
        je       L_8152
        mov      esi, OFFSET g_menuPageVar_004f5328
    L_80c2:
        movsx    eax, word ptr [esi + 4]
        add      eax, -0x3c
        cmp      eax, 5
        ja       short L_8144
        jmp      dword ptr [eax*4 + L_080_jmptbl]
    L_80d5:
        mov      edx, dword ptr [g_menuRestoreC_00543ab0]
        push     edx
        jmp      short L_8117
    L_80de:
        mov      eax, dword ptr [g_menuRestoreB_00543aac]
        jmp      short L_80ea
    L_80e5:
        mov      eax, dword ptr [g_byte_00543ab4]
    L_80ea:
        test     eax, eax
        mov      eax, OFFSET g_data_004f42d8
        jne      short L_810e
        mov      eax, OFFSET g_data_004f42dc
        push     eax
        jmp      short L_813b
    L_80fb:
        mov      eax, dword ptr [g_menuPageDispatch_00543a98]
        test     eax, eax
        mov      eax, OFFSET g_data_004f61a0
        jne      short L_810e
        mov      eax, OFFSET g_data_004f6190
    L_810e:
        push     eax
        jmp      short L_813b
    L_8111:
        mov      eax, dword ptr [g_menuRestoreA_00543aa0]
        push     eax
    L_8117:
        push     OFFSET g_data_004f6164
        push     OFFSET g_data_00ab41c8
        call     Helper_Sprintf
        add      esp, 0xc
        push     OFFSET g_data_00ab41c8
        jmp      short L_813b
    L_8130:
        mov      ecx, dword ptr [g_menuRestoreD_00543a9c]
        mov      edx, dword ptr [esp + ecx*4 + 8]
        push     edx
    L_813b:
        push     esi
        call     StringSubstituteAfterColon_004b7160
        add      esp, 8
    L_8144:
        mov      eax, dword ptr [esi + 8]
        add      esi, 8
        test     eax, eax
        jne      L_80c2
    L_8152:
        mov      eax, dword ptr [g_data_00ab4328]
        push     eax
        push     OFFSET g_menuPageVar_004f5328
        call     DrawMenu
        mov      eax, dword ptr [g_data_00ab4358]
        add      esp, 8
        pop      esi
        pop      ebx
        add      esp, 0x18
        ret
    L_080_tail:
        /* 8-entry jump table at 0x4b8170 (belongs to Helper_GSM_Options's outer switch). */
        _emit 0x65
        _emit 0x80
        _emit 0x4b
        _emit 0x00
        _emit 0xd8
        _emit 0x7e
        _emit 0x4b
        _emit 0x00
        _emit 0x3b
        _emit 0x7f
        _emit 0x4b
        _emit 0x00
        _emit 0xa1
        _emit 0x7f
        _emit 0x4b
        _emit 0x00
        _emit 0x0e
        _emit 0x80
        _emit 0x4b
        _emit 0x00
        _emit 0x2b
        _emit 0x80
        _emit 0x4b
        _emit 0x00
        _emit 0x48
        _emit 0x80
        _emit 0x4b
        _emit 0x00
        _emit 0x80
        _emit 0x80
        _emit 0x4b
        _emit 0x00
        /* 64-byte index array at 0x4b8190 (also Helper_GSM_Options). */
        _emit 0x00
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x01
        _emit 0x02
        _emit 0x03
        _emit 0x04
        _emit 0x05
        _emit 0x06
        _emit 0x90
    L_080_jmptbl:
        /* Our 6-entry jump table (case0..case5). */
        _emit 0x11
        _emit 0x81
        _emit 0x4b
        _emit 0x00
        _emit 0x30
        _emit 0x81
        _emit 0x4b
        _emit 0x00
        _emit 0xd5
        _emit 0x80
        _emit 0x4b
        _emit 0x00
        _emit 0xde
        _emit 0x80
        _emit 0x4b
        _emit 0x00
        _emit 0xe5
        _emit 0x80
        _emit 0x4b
        _emit 0x00
        _emit 0xfb
        _emit 0x80
        _emit 0x4b
        _emit 0x00
    }
}
