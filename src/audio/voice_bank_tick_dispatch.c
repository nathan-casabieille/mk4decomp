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
extern unsigned int g_data_0053a180;
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
extern unsigned int g_data_00535cf8;
extern unsigned int g_cj_00542054;
extern unsigned int g_data_005437f0;
extern unsigned int g_data_00543598;
extern unsigned int g_data_0054358c;
extern unsigned int g_data_00535e70;
extern unsigned int g_data_00535e74;
extern unsigned int g_data_00535e78;
extern unsigned int g_data_00535e7c;

extern unsigned int g_data_004f2fc0;
extern unsigned int g_data_004f31a0;
extern unsigned int g_data_004f31cc;
extern unsigned int g_data_004f31d0;
extern unsigned int g_data_004f31d8;
extern unsigned int g_data_004f3220;
extern unsigned int g_data_004f3234;
extern unsigned int g_data_004f3238;
extern unsigned int g_data_004f3240;
extern unsigned int g_data_004f3264;
extern unsigned int g_data_004f33cc;
extern unsigned int g_data_004f42e0;
extern unsigned int g_data_004f42f4;
extern unsigned int g_data_004f4304;
extern unsigned int g_data_004f4310;
extern unsigned int g_data_004f4320;
extern unsigned int g_data_004f432c;
extern unsigned int g_currentNodeIdx;
extern unsigned int g_baseSel_00542060;
extern unsigned int g_data_00543450;
extern unsigned int g_data_005437f8;
extern unsigned int g_data_005437fc;
extern void GuardedSetupCallTailJmp_004a1fa0(void);
extern void Helper_Sprintf(void);
extern void MStackPush2ChainLLInsert_00406790(void);

__declspec(naked) void VoiceBankTickDispatch_004a3120(void)
{
    __asm {
        push     esi
        push     edi
        xor      edi, edi
        mov      esi, OFFSET g_data_004f3264
    L_3129:
        movsx    eax, byte ptr [esi - 4]
        mov      ecx, dword ptr [g_baseSel_00542060]
        add      ecx, eax
        mov      edx, dword ptr [ecx*4]
        mov      dword ptr [g_currentNodeIdx], edx
        call     MStackPush2ChainLLInsert_00406790
        lea      eax, [edi - 1]
        cmp      eax, 5
        ja       L_31e2
        jmp      dword ptr [eax*4 + L_120_jmptbl]
    L_315a:
        mov      eax, dword ptr [g_data_004f31cc]
        mov      ecx, dword ptr [eax*4 + g_data_004f31d8]
        push     ecx
        push     OFFSET g_data_004f432c
        jmp      L_31d5
    L_316e:
        mov      edx, dword ptr [g_data_004f31d0]
        mov      eax, dword ptr [edx*4 + g_data_004f31d8]
        push     eax
        push     OFFSET g_data_004f4320
        jmp      L_31d5
    L_3183:
        mov      ecx, dword ptr [g_data_005437fc]
        mov      edx, dword ptr [ecx*4 + g_data_004f3220]
        push     edx
        push     OFFSET g_data_004f4310
        jmp      L_31d5
    L_3198:
        mov      eax, dword ptr [g_data_004f3234]
        mov      ecx, dword ptr [eax*4 + g_data_004f3240]
        push     ecx
        push     OFFSET g_data_004f4304
        jmp      L_31d5
    L_31ac:
        mov      edx, dword ptr [g_data_005437f8]
        mov      eax, dword ptr [edx*4 + g_data_004f31a0]
        push     eax
        push     OFFSET g_data_004f42f4
        jmp      L_31d5
    L_31c1:
        movsx    ecx, byte ptr [g_data_004f3238]
        mov      edx, dword ptr [ecx*4 + g_data_004f2fc0]
        push     edx
        push     OFFSET g_data_004f42e0
    L_31d5:
        push     OFFSET g_data_00543450
        call     Helper_Sprintf
        add      esp, 0xc
    L_31e2:
        mov      eax, dword ptr [esi + 8]
        mov      ecx, dword ptr [esi]
        push     eax
        push     ecx
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [g_currentNodeIdx], ecx
        call     GuardedSetupCallTailJmp_004a1fa0
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      eax, dword ptr [esi + 0xc]
        add      esp, 8
        add      esi, 0x24
        mov      dword ptr [ecx*4 + 0x5c], eax
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      edx, dword ptr [eax*4 + 0x54]
        mov      dword ptr [esi - 0x20], edx
        mov      edx, dword ptr [g_baseSel_00542060]
        movsx    ecx, byte ptr [esi - 0x28]
        mov      dword ptr [g_eventQueueCurrent], ecx
        add      ecx, edx
        inc      edi
        cmp      esi, OFFSET g_data_004f33cc
        mov      dword ptr [ecx*4], eax
        jb       L_3129
        pop      edi
        pop      esi
        ret
        nop
    L_120_jmptbl:
        _emit 0x5a
        _emit 0x31
        _emit 0x4a
        _emit 0x00
        _emit 0x6e
        _emit 0x31
        _emit 0x4a
        _emit 0x00
        _emit 0x83
        _emit 0x31
        _emit 0x4a
        _emit 0x00
        _emit 0x98
        _emit 0x31
        _emit 0x4a
        _emit 0x00
        _emit 0xac
        _emit 0x31
        _emit 0x4a
        _emit 0x00
        _emit 0xc1
        _emit 0x31
        _emit 0x4a
        _emit 0x00
    }
}
