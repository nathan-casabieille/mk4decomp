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

extern unsigned int g_data_004d5324;
extern unsigned int g_data_004d57ac;
extern unsigned int g_data_004e5798;
extern unsigned int g_data_004e57d0;
extern unsigned int g_framePauseFlag;
extern unsigned int g_currentNodeIdx;
extern unsigned int g_xformEntityIdx;
extern unsigned int g_pendingNodeType;
extern unsigned int g_eventQueueEnd;
extern unsigned int g_eventQueueIdx;
extern unsigned int g_fightGroupHead;
extern unsigned int g_baseSel_00542060;
extern unsigned int g_xformDirtyFlags;
extern void AudioMixerStep_004ab700(void);
extern void ChainInitMul10BulkStore_00442740(void);
extern void CopyThreeFields_00404df0(void);
extern void DispatcherComplex138_004760f0(void);
extern void FourSegmentPoseWalk_00442880(void);
extern void MStackCall_00406600(void);
extern void PendingMatch_004411d0(void);
extern void PushSetXfmMaskCallPop_00407140(void);
extern void ScaledOr4Jmp_00476e00(void);
extern void SpawnFreezeProjectileChain_00442530(void);
extern void StoreLoadJmp_00404ef0(void);
extern void ThreeChanPackClamp_00404cc0(void);
extern void Thunk_0049cbc0(void);

__declspec(naked) void SpawnEffectCluster_004420a0(void)
{
    __asm {
    L_20a0:
        mov      eax, dword ptr [g_data_004d57ac]
        mov      ecx, dword ptr [g_currentNodeIdx]
        push     ebx
        inc      eax
        push     esi
        mov      dword ptr [g_data_004d57ac], eax
        mov      esi, 0x91
        mov      dword ptr [eax*4], ecx
        mov      dword ptr [g_currentNodeIdx], 0
        mov      dword ptr [g_walkCallback], esi
        call     DispatcherComplex138_004760f0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_2165
        mov      bl, 4
    L_20e3:
        test     byte ptr [g_xformDirtyFlags], bl
        mov      eax, dword ptr [g_data_004d57ac]
        jne      L_2152
        mov      edx, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_data_004d57ac], eax
        mov      dword ptr [eax*4], edx
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      ecx, dword ptr [eax*4 + 0x18]
        mov      dword ptr [g_currentNodeIdx], ecx
        call     ScaledOr4Jmp_00476e00
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_2165
        mov      eax, dword ptr [g_data_004d57ac]
        mov      edx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_currentNodeIdx], edx
        mov      dword ptr [g_data_004d57ac], eax
        mov      dword ptr [g_walkCallback], esi
        call     DispatcherComplex138_004760f0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        je       L_20e3
        pop      esi
        pop      ebx
        ret      
    L_2152:
        mov      ecx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      dword ptr [g_data_004d57ac], eax
    L_2165:
        pop      esi
        pop      ebx
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
    L_2170:
        mov      eax, dword ptr [g_baseSel_00542060]
        push     esi
        push     edi
        mov      edi, OFFSET L_2170
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        test     eax, eax
        je       L_21b0
        mov      eax, dword ptr [g_eventQueueIdx]
        mov      ecx, dword ptr [eax*4]
        inc      eax
        mov      dword ptr [g_walkCallback], ecx
        jmp      L_224b
    L_21b0:
        mov      edx, dword ptr [g_baseSel_00542060]
        mov      eax, dword ptr [g_eventQueueEnd]
        push     OFFSET L_23c0
        mov      dword ptr [edx*4 + 0x64], eax
        mov      ecx, dword ptr [g_baseSel_00542060]
        mov      edx, dword ptr [g_eventQueueIdx]
        mov      dword ptr [ecx*4 + 0x68], edx
        call     StoreLoadJmp_00404ef0
        add      esp, 4
        push     OFFSET PendingMatch_004411d0 + 0xb60
        call     StoreLoadJmp_00404ef0
        mov      eax, dword ptr [g_eventQueueEnd]
        add      esp, 4
        mov      dword ptr [g_fightGroupHead], eax
        push     0x806000
        call     ThreeChanPackClamp_00404cc0
        mov      ecx, dword ptr [g_fightGroupHead]
        add      esp, 4
        push     ecx
        call     CopyThreeFields_00404df0
        add      esp, 4
        call     MStackPush2RunCountdown_004089e0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_23af
        call     MStackBracket7_DispatchAndChain_004b8fa0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_23af
        mov      dword ptr [g_eventQueueEnd], 3
    L_2243:
        mov      eax, OFFSET g_data_004e5798
        shr      eax, 2
    L_224b:
        mov      dword ptr [g_eventQueueIdx], eax
        mov      eax, dword ptr [eax*4]
        test     eax, eax
        mov      dword ptr [g_walkCallback], eax
        jne      L_227e
        mov      eax, dword ptr [g_eventQueueEnd]
        dec      eax
        mov      dword ptr [g_eventQueueEnd], eax
        jns      L_2243
        call     L_20a0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        je       L_22d6
        pop      edi
        pop      esi
        ret      
    L_227e:
        mov      eax, dword ptr [g_data_004d57ac]
        mov      edx, dword ptr [g_fightGroupHead]
        inc      eax
        mov      dword ptr [g_data_004d57ac], eax
        mov      dword ptr [eax*4], edx
        mov      eax, OFFSET g_data_004e57d0
        shr      eax, 2
        mov      dword ptr [g_walkCallback], eax
        call     PushSetXfmMaskCallPop_00407140
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_23af
        mov      eax, dword ptr [g_data_004d57ac]
        mov      ecx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_data_004d57ac], eax
        mov      al, byte ptr [g_xformDirtyFlags]
        test     al, 4
        mov      dword ptr [g_fightGroupHead], ecx
        je       L_22de
    L_22d6:
        call     Thunk_0049cbc0
        pop      edi
        pop      esi
        ret      
    L_22de:
        call     MStackCall_00406600
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_23af
        mov      edx, dword ptr [g_eventQueueIdx]
        mov      eax, dword ptr [edx*4]
        mov      dword ptr [g_walkCallback], eax
        call     ChainDirtyBitWalker_00408c10
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_23af
        mov      ecx, dword ptr [g_xformEntityIdx]
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      eax, dword ptr [ecx*4 + 0x3c]
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [edx*4 + 0x54], eax
        mov      eax, dword ptr [g_xformEntityIdx]
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      eax, dword ptr [eax*4 + 0x40]
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x58], eax
        mov      edx, dword ptr [g_xformEntityIdx]
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      eax, dword ptr [edx*4 + 0x44]
        mov      dword ptr [ecx*4 + 0x5c], eax
        mov      edx, dword ptr [g_data_004d5324]
        mov      dword ptr [g_walkCallback], edx
        call     AudioMixerStep_004ab700
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_23af
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      eax, dword ptr [g_walkCallback]
        mov      dword ptr [ecx*4 + 0x68], eax
        mov      eax, 1
        mov      dword ptr [esi + 8], edi
        mov      dword ptr [esi + 0x84], eax
        mov      dword ptr [g_pendingNodeType], eax
        mov      dword ptr [g_framePauseFlag], eax
    L_23af:
        pop      edi
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
    L_23c0:
        mov      eax, dword ptr [g_baseSel_00542060]
        push     esi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        cmp      eax, 3
        ja       L_24f7
        jmp      dword ptr [eax*4 + L_jmptbl]
    L_23ee:
        call     SpawnFreezeProjectileChain_00442530
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_2518
        mov      dword ptr [esi + 8], OFFSET L_23c0
        mov      dword ptr [esi + 0x84], 2
        mov      dword ptr [g_pendingNodeType], 3
        mov      dword ptr [g_framePauseFlag], 1
        pop      esi
        ret
    L_2427:
        mov      ecx, dword ptr [g_baseSel_00542060]
        mov      ecx, dword ptr [ecx*4 + 0x64]
        mov      dword ptr [g_fightGroupHead], ecx
        mov      eax, dword ptr [ecx*4 + 0x34]
        or       al, 4
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x34], eax
        mov      dword ptr [esi + 8], OFFSET L_23c0
        mov      dword ptr [esi + 0x84], 3
        mov      dword ptr [g_pendingNodeType], 5
        mov      dword ptr [g_framePauseFlag], 1
        pop      esi
        ret
    L_2476:
        call     FourSegmentPoseWalk_00442880
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_2518
        mov      dword ptr [esi + 8], OFFSET L_23c0
        mov      dword ptr [esi + 0x84], 4
        mov      dword ptr [g_pendingNodeType], 8
        mov      dword ptr [g_framePauseFlag], 1
        pop      esi
        ret
    L_24af:
        mov      edx, dword ptr [g_baseSel_00542060]
        mov      eax, dword ptr [g_eventQueueEnd]
        mov      dword ptr [edx*4 + 0x64], eax
        mov      ecx, dword ptr [g_baseSel_00542060]
        mov      edx, dword ptr [g_eventQueueIdx]
        mov      eax, 1
        mov      dword ptr [ecx*4 + 0x68], edx
        mov      dword ptr [esi + 8], OFFSET L_23c0
        mov      dword ptr [esi + 0x84], eax
        mov      dword ptr [g_pendingNodeType], 5
        mov      dword ptr [g_framePauseFlag], eax
        pop      esi
        ret      
    L_24f7:
        call     FourSegmentPoseWalk_00442880
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_2518
        call     ChainInitMul10BulkStore_00442740
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_2518
        call     Thunk_0049cbc0
    L_2518:
        pop      esi
        ret
        _emit 0x8b
        _emit 0xff
    L_jmptbl:
        _emit 0xaf
        _emit 0x24
        _emit 0x44
        _emit 0x00
        _emit 0xee
        _emit 0x23
        _emit 0x44
        _emit 0x00
        _emit 0x27
        _emit 0x24
        _emit 0x44
        _emit 0x00
        _emit 0x76
        _emit 0x24
        _emit 0x44
        _emit 0x00
    }
}
