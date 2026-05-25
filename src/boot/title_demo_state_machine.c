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
extern unsigned int g_state_00542094;
extern unsigned int g_state_00535ddc;
extern unsigned int g_state_00537e88;
extern unsigned int g_state_0053a408;
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

extern void ZeroMultiGlobalsCmp_00404680(void);
extern void TitleDemoStateMachine_004032d0(void);
extern void PendingMatch_00403d60(void);
extern unsigned int g_data_0053a19c;
extern unsigned int g_data_00541dc0;

extern unsigned int g_data_0052aac4;
extern unsigned int g_data_00537e88;
extern unsigned int g_data_0053a3e8;
extern unsigned int g_data_0053a408;
extern unsigned int g_data_0053a50c;
extern unsigned int g_data_00541de8;
extern unsigned int g_data_00541dec;
extern unsigned int g_data_00541df0;
extern unsigned int g_data_00541df4;
extern unsigned int g_framePauseFlag;
extern unsigned int g_currentNodeIdx;
extern unsigned int g_pendingNodeType;
extern unsigned int g_data_00542060;
extern unsigned int g_eventQueueWorkType;
extern unsigned int g_xformDirtyFlags;
extern void AudioVolumeRescale_004ab690(void);
extern void BootInitVec3PhaseInstall_00402c10(void);
extern void BootStateInitWithRecurseInstall_00402de0(void);
extern void BootStateMachine4Way_00402f60(void);
extern void CopyGlobal_004ac1f0(void);
extern void InstallSelfCounter_00404920(void);
extern void PendingMatch_00402540(void);
extern void PendingMatch_00403670(void);
extern void PendingMatch_004a2a80(void);
extern void PhaseInstallSelf3Step_00402350(void);
extern void QuadCallPhase2_004be800(void);
extern void SceneFrameStepWithInputs_004be250(void);
extern void TableWalkBoundedCmp_004bd890(void);

__declspec(naked) void PendingMatch_00401b70(void)
{
    __asm {
        push     ebx
        push     ebp
        push     esi
        push     edi
        call     LeaPlus22StoreSelf_0048e4d0
        mov      eax, dword ptr [g_data_00542060]
        xor      ebp, ebp
        mov      edi, 0x401b70
        mov      ebx, 1
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], ebp
        cmp      eax, 0x14
        ja       L_1c1e
    L_1ba3:
        jmp      dword ptr [eax*4 + L_22fc_jmptbl]
        push     -1
        push     -1
        push     -1
        push     0x16
        call     QuadCallPhase2_004be800
        add      esp, 0x10
        push     ebx
        push     ebp
        call     SceneFrameStepWithInputs_004be250
        add      esp, 8
        test     eax, eax
        je       L_1d46
        jmp      L_1bf5
        mov      eax, dword ptr [g_data_0053a3e8]
        inc      eax
        cmp      eax, 4
        mov      dword ptr [g_data_0053a3e8], eax
        jne      L_2047
        push     ebx
        push     0x23
        call     SceneFrameStepWithInputs_004be250
        add      esp, 8
        test     eax, eax
        je       L_2041
    L_1bf5:
        call     LeaPlus22StoreSelf_0048e4d0
        mov      ecx, dword ptr [g_data_00542060]
        mov      edi, 0x401b70
        mov      eax, dword ptr [ecx*4 + 0x84]
        lea      esi, [ecx*4]
        cmp      eax, 0x14
        mov      dword ptr [esi + 0x84], ebp
        jbe      L_1ba3
    L_1c1e:
        mov      ecx, dword ptr [g_data_0053a19c]
        lea      eax, [ecx + 1]
        cmp      eax, 3
        mov      dword ptr [g_data_0053a19c], eax
        jbe      L_1c37
        mov      dword ptr [g_data_00541dc0], ebx
    L_1c37:
        push     -1
        push     -1
        push     -1
        push     0x1e
        mov      dword ptr [g_walkCallback], ebp
        mov      dword ptr [g_data_00541de8], ebp
        mov      dword ptr [g_data_00541dec], ebp
        mov      dword ptr [g_data_00541df0], ebp
        mov      dword ptr [g_data_00541df4], ebp
        call     QuadCallPhase2_004be800
        mov      dword ptr [esi + 8], edi
        mov      edx, dword ptr [g_data_00542060]
        add      edi, 0x3000000
        add      esp, 0x10
        mov      dword ptr [edx*4 + 0x84], 3
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], edi
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      eax, dword ptr [g_data_00542060]
        mov      dword ptr [eax*4 + 0x84], ebp
        call     PendingMatch_004a2a80
        mov      dword ptr [g_framePauseFlag], ebx
    L_1cb3:
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        ret      
        push     9
        call     TableWalkBoundedCmp_004bd890
        add      esp, 4
        mov      dword ptr [g_eventQueueWorkType], ebp
        call     Push16Call_00489f50
        cmp      dword ptr [g_framePauseFlag], ebp
        jne      L_1cb3
        mov      eax, 2
        mov      dword ptr [g_data_0053a50c], ebp
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [g_data_0052aac4], eax
        mov      dword ptr [g_eventQueueWorkType], ebp
        call     Push16Call_00489f50
        cmp      dword ptr [g_framePauseFlag], ebp
        jne      L_1cb3
        call     ZeroMultiGlobalsCmp_00404680
        cmp      dword ptr [g_framePauseFlag], ebp
        jne      L_1cb3
        mov      dword ptr [g_walkCallback], ebp
        mov      dword ptr [g_data_00541dc0], ebp
        mov      dword ptr [g_data_0053a19c], ebp
        mov      dword ptr [g_data_0053a408], ebp
        mov      dword ptr [g_data_00537e88], ebp
        mov      dword ptr [esi + 8], edi
        mov      dword ptr [esi + 0x84], 2
        mov      dword ptr [g_pendingNodeType], ebx
        mov      dword ptr [g_framePauseFlag], ebx
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        ret      
    L_1d46:
        mov      dword ptr [g_eventQueueWorkType], ebp
        call     Push16Call_00489f50
        cmp      dword ptr [g_framePauseFlag], ebp
        jne      L_1cb3
        push     -1
        push     -1
        push     -1
        push     0x1e
        call     QuadCallPhase2_004be800
        mov      dword ptr [esi + 8], edi
        mov      edx, dword ptr [g_data_00542060]
        add      edi, 0x5000000
        add      esp, 0x10
        mov      dword ptr [edx*4 + 0x84], 5
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], edi
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      eax, dword ptr [g_data_00542060]
        mov      dword ptr [eax*4 + 0x84], ebp
        call     PhaseInstallSelf3Step_00402350
        mov      dword ptr [g_framePauseFlag], ebx
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        ret      
        mov      dword ptr [esi + 8], edi
        mov      ecx, dword ptr [g_data_00542060]
        add      edi, 0x6000000
        mov      dword ptr [ecx*4 + 0x84], 6
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], edi
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      edx, dword ptr [g_data_00542060]
        mov      dword ptr [edx*4 + 0x84], ebp
        call     PendingMatch_00402540
        mov      dword ptr [g_framePauseFlag], ebx
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        ret      
        mov      dword ptr [g_walkCallback], 0x64
        call     AudioVolumeRescale_004ab690
        mov      al, byte ptr [g_xformDirtyFlags]
        mov      dword ptr [esi + 8], edi
        test     al, bl
        je       L_1e52
        mov      eax, dword ptr [g_data_00542060]
        add      edi, 0x7000000
        mov      dword ptr [eax*4 + 0x84], 7
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_currentNodeIdx], eax
        jmp      L_2251
    L_1e52:
        mov      edx, dword ptr [g_data_00542060]
        add      edi, 0x9000000
        mov      dword ptr [edx*4 + 0x84], 9
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_currentNodeIdx], eax
        jmp      L_2069
        mov      dword ptr [esi + 8], edi
        mov      ecx, dword ptr [g_data_00542060]
        add      edi, 0x8000000
        mov      dword ptr [ecx*4 + 0x84], 8
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], edi
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      edx, dword ptr [g_data_00542060]
        mov      dword ptr [edx*4 + 0x84], ebp
        call     TitleDemoStateMachine_004032d0
        mov      dword ptr [g_framePauseFlag], ebx
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        ret      
        mov      dword ptr [esi + 8], edi
        mov      eax, dword ptr [g_data_00542060]
        add      edi, 0xa000000
        mov      dword ptr [eax*4 + 0x84], 0xa
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], edi
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      ecx, dword ptr [g_data_00542060]
        mov      dword ptr [ecx*4 + 0x84], ebp
        call     BootStateMachine4Way_00402f60
        mov      dword ptr [g_framePauseFlag], ebx
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        ret      
        push     8
        call     TableWalkBoundedCmp_004bd890
        add      esp, 4
        push     -1
        push     -1
        push     -1
        push     0x1c
        call     QuadCallPhase2_004be800
        mov      dword ptr [esi + 8], edi
        mov      edx, dword ptr [g_data_00542060]
        add      edi, 0xb000000
        add      esp, 0x10
        mov      dword ptr [edx*4 + 0x84], 0xb
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], edi
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      eax, dword ptr [g_data_00542060]
        mov      dword ptr [eax*4 + 0x84], ebp
        call     PendingMatch_00403d60
        mov      dword ptr [g_framePauseFlag], ebx
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        ret      
        push     -1
        push     -1
        push     -1
        push     0x1e
        call     QuadCallPhase2_004be800
        mov      dword ptr [esi + 8], edi
        mov      ecx, dword ptr [g_data_00542060]
        add      edi, 0xc000000
        add      esp, 0x10
        mov      dword ptr [ecx*4 + 0x84], 0xc
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], edi
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      edx, dword ptr [g_data_00542060]
        mov      dword ptr [edx*4 + 0x84], ebp
        call     PendingMatch_00403670
        mov      dword ptr [g_framePauseFlag], ebx
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        ret      
        mov      dword ptr [esi + 8], edi
        mov      eax, dword ptr [g_data_00542060]
        add      edi, 0xd000000
        mov      dword ptr [eax*4 + 0x84], 0xd
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], edi
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      ecx, dword ptr [g_data_00542060]
        mov      dword ptr [ecx*4 + 0x84], ebp
        call     BootInitVec3PhaseInstall_00402c10
        mov      dword ptr [g_framePauseFlag], ebx
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        ret      
    L_2041:
        mov      dword ptr [g_data_0053a3e8], ebp
    L_2047:
        mov      dword ptr [esi + 8], edi
        mov      edx, dword ptr [g_data_00542060]
        add      edi, 0xe000000
        mov      dword ptr [edx*4 + 0x84], 0xe
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_currentNodeIdx], eax
    L_2069:
        mov      dword ptr [eax*4], edi
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      eax, dword ptr [g_data_00542060]
        mov      dword ptr [eax*4 + 0x84], ebp
        call     BootStateInitWithRecurseInstall_00402de0
        mov      dword ptr [g_framePauseFlag], ebx
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        ret      
        mov      dword ptr [esi + 8], edi
        mov      ecx, dword ptr [g_data_00542060]
        add      edi, 0xf000000
        mov      dword ptr [ecx*4 + 0x84], 0xf
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], edi
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      edx, dword ptr [g_data_00542060]
        mov      dword ptr [edx*4 + 0x84], ebp
        call     BootStateMachine4Way_00402f60
        mov      dword ptr [g_framePauseFlag], ebx
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        ret      
        push     8
        call     TableWalkBoundedCmp_004bd890
        add      esp, 4
        push     -1
        push     -1
        push     -1
        push     0x1e
        call     QuadCallPhase2_004be800
        add      esp, 0x10
        push     ebp
        push     0x4a2180
        call     StoreTwoCall_0049cb40
        add      esp, 8
        push     -1
        push     -1
        push     -1
        push     0x1c
        call     QuadCallPhase2_004be800
        mov      dword ptr [esi + 8], edi
        mov      eax, dword ptr [g_data_00542060]
        add      edi, 0x10000000
        add      esp, 0x10
        mov      dword ptr [eax*4 + 0x84], 0x10
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], edi
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      ecx, dword ptr [g_data_00542060]
        mov      dword ptr [ecx*4 + 0x84], ebp
        call     PendingMatch_00403d60
        mov      dword ptr [g_framePauseFlag], ebx
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        ret      
        push     -1
        push     -1
        push     -1
        push     0x1e
        call     QuadCallPhase2_004be800
        mov      dword ptr [esi + 8], edi
        mov      edx, dword ptr [g_data_00542060]
        add      edi, 0x11000000
        add      esp, 0x10
        mov      dword ptr [edx*4 + 0x84], 0x11
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], edi
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      eax, dword ptr [g_data_00542060]
        mov      dword ptr [eax*4 + 0x84], ebp
        call     PendingMatch_00403670
        mov      dword ptr [g_framePauseFlag], ebx
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        ret      
        mov      dword ptr [esi + 8], edi
        mov      ecx, dword ptr [g_data_00542060]
        add      edi, 0x12000000
        mov      dword ptr [ecx*4 + 0x84], 0x12
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], edi
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      edx, dword ptr [g_data_00542060]
        mov      dword ptr [edx*4 + 0x84], ebp
        call     InstallSelfCounter_00404920
        mov      dword ptr [g_framePauseFlag], ebx
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        ret      
        mov      dword ptr [esi + 8], edi
        mov      eax, dword ptr [g_data_00542060]
        add      edi, 0x13000000
        mov      dword ptr [eax*4 + 0x84], 0x13
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_currentNodeIdx], eax
    L_2251:
        mov      dword ptr [eax*4], edi
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      ecx, dword ptr [g_data_00542060]
        mov      dword ptr [ecx*4 + 0x84], ebp
        call     BootStateInitWithRecurseInstall_00402de0
        mov      dword ptr [g_framePauseFlag], ebx
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        ret      
        mov      dword ptr [esi + 8], edi
        mov      edx, dword ptr [g_data_00542060]
        add      edi, 0x14000000
        mov      dword ptr [edx*4 + 0x84], 0x14
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], edi
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      eax, dword ptr [g_data_00542060]
        mov      dword ptr [eax*4 + 0x84], ebp
        call     TitleDemoStateMachine_004032d0
        mov      dword ptr [g_framePauseFlag], ebx
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        ret      
        mov      dword ptr [g_walkCallback], ebp
        call     CopyGlobal_004ac1f0
        mov      dword ptr [esi + 8], edi
        mov      dword ptr [esi + 0x84], ebx
        pop      edi
        pop      esi
        mov      dword ptr [g_pendingNodeType], ebx
        mov      dword ptr [g_framePauseFlag], ebx
        pop      ebp
        pop      ebx
        ret      
        nop      
    L_22fc_jmptbl:
        /* 21-entry jump table */
        _emit    0xd6
        _emit    0x22
        _emit    0x40
        _emit    0x00
        _emit    0xb8
        _emit    0x1c
        _emit    0x40
        _emit    0x00
        _emit    0x37
        _emit    0x1c
        _emit    0x40
        _emit    0x00
        _emit    0xaa
        _emit    0x1b
        _emit    0x40
        _emit    0x00
        _emit    0x46
        _emit    0x1d
        _emit    0x40
        _emit    0x00
        _emit    0xc0
        _emit    0x1d
        _emit    0x40
        _emit    0x00
        _emit    0x14
        _emit    0x1e
        _emit    0x40
        _emit    0x00
        _emit    0x76
        _emit    0x1e
        _emit    0x40
        _emit    0x00
        _emit    0x1d
        _emit    0x1f
        _emit    0x40
        _emit    0x00
        _emit    0xca
        _emit    0x1e
        _emit    0x40
        _emit    0x00
        _emit    0x1d
        _emit    0x1f
        _emit    0x40
        _emit    0x00
        _emit    0x8a
        _emit    0x1f
        _emit    0x40
        _emit    0x00
        _emit    0xee
        _emit    0x1f
        _emit    0x40
        _emit    0x00
        _emit    0xce
        _emit    0x1b
        _emit    0x40
        _emit    0x00
        _emit    0x9a
        _emit    0x20
        _emit    0x40
        _emit    0x00
        _emit    0xee
        _emit    0x20
        _emit    0x40
        _emit    0x00
        _emit    0x79
        _emit    0x21
        _emit    0x40
        _emit    0x00
        _emit    0xdc
        _emit    0x21
        _emit    0x40
        _emit    0x00
        _emit    0x30
        _emit    0x22
        _emit    0x40
        _emit    0x00
        _emit    0x83
        _emit    0x22
        _emit    0x40
        _emit    0x00
        _emit    0x1e
        _emit    0x1c
        _emit    0x40
        _emit    0x00
    }
}
