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

extern unsigned int g_data_004d2320;
extern unsigned int g_data_004d2330;
extern unsigned int g_data_004d2340;
extern unsigned int g_data_00537f94;
extern unsigned int g_data_0053a430;
extern unsigned int g_framePauseFlag;
extern unsigned int g_currentNodeIdx;
extern unsigned int g_pendingNodeType;
extern unsigned int g_data_00542060;
extern void AudioInitInstallerPair_004a2140(void);
extern void BootInitGuardedCallChain_004265d0(void);
extern void GuardedSetupCallTailJmp_004a1fa0(void);
extern void TwoCallsTwoBranchTail_004a3c50(void);

__declspec(naked) void BossFight6StateSequencer_004a3ce0(void)
{
    __asm {
    L_3ce0:
        mov      eax, dword ptr [g_data_00542060]
        push     esi
        push     edi
        xor      edi, edi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], edi
        cmp      eax, 5
        ja       L_3f23
        jmp      dword ptr [eax*4 + L_jmptbl_3f30]
    L_3d0d:
        /* case 1: kick off if state == 0 then check 0053a430 flag */
        mov      ecx, dword ptr [g_data_00542060]
        mov      edx, dword ptr [ecx*4 + 0x30]
        mov      dword ptr [edx*4 + 0x74], edi
        mov      eax, dword ptr [g_data_0053a430]
        cmp      eax, edi
        jne      short L_3d63
        call     TwoCallsTwoBranchTail_004a3c50
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_3f2d
        mov      dword ptr [esi + 8], OFFSET L_3ce0
        mov      dword ptr [esi + 0x84], 2
        mov      dword ptr [g_pendingNodeType], 0x1e
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        ret
    L_3d63:
        /* case 2: arm slot-0x34 velocity */
        mov      eax, dword ptr [g_data_00542060]
        mov      ecx, dword ptr [eax*4 + 0x34]
        mov      dword ptr [ecx*4 + 0x58], 0x140000
        mov      edx, dword ptr [g_data_00542060]
        mov      eax, dword ptr [edx*4 + 0x34]
        mov      dword ptr [eax*4 + 0x74], 0xffffc000
        mov      dword ptr [esi + 8], OFFSET L_3ce0
        mov      dword ptr [esi + 0x84], 3
        mov      dword ptr [g_pendingNodeType], 0x24
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        ret
    L_3dba:
        /* case 3: reset slot-0x34 velocity to 0 */
        mov      ecx, dword ptr [g_data_00542060]
        mov      edx, dword ptr [ecx*4 + 0x34]
        mov      dword ptr [edx*4 + 0x74], edi
        mov      dword ptr [esi + 8], OFFSET L_3ce0
        mov      dword ptr [esi + 0x84], 4
        mov      dword ptr [g_pendingNodeType], 0x3c
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        ret
    L_3df6:
        /* case 4: state-bump only */
        mov      dword ptr [esi + 8], OFFSET L_3ce0
        mov      dword ptr [esi + 0x84], 5
        mov      dword ptr [g_pendingNodeType], 0x3c
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        ret
    L_3e1e:
        /* case 5: long-timer state-bump */
        mov      dword ptr [esi + 8], OFFSET L_3ce0
        mov      dword ptr [esi + 0x84], 6
        mov      dword ptr [g_pendingNodeType], 0xf0
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        ret
    L_3e46:
        /* case 0: initial spawn - pick mesh by flag, install slots */
        push     0xffec0000
        push     OFFSET g_data_004d2320
        call     GuardedSetupCallTailJmp_004a1fa0
        mov      eax, dword ptr [g_data_00542060]
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      edi, 1
        add      esp, 8
        mov      dword ptr [eax*4 + 0x30], ecx
        mov      eax, dword ptr [g_data_00537f94]
        cmp      eax, edi
        mov      eax, OFFSET g_data_004d2330
        je       short L_3e82
        mov      eax, OFFSET g_data_004d2340
    L_3e82:
        push     0x140000
        push     eax
        mov      dword ptr [g_currentNodeIdx], eax
        call     GuardedSetupCallTailJmp_004a1fa0
        mov      edx, dword ptr [g_data_00542060]
        mov      eax, dword ptr [g_currentNodeIdx]
        add      esp, 8
        mov      dword ptr [edx*4 + 0x34], eax
        mov      ecx, dword ptr [g_data_00542060]
        mov      eax, 0xa0000
        mov      edx, dword ptr [ecx*4 + 0x30]
        mov      dword ptr [edx*4 + 0x5c], eax
        mov      ecx, dword ptr [g_data_00542060]
        mov      edx, dword ptr [ecx*4 + 0x34]
        mov      dword ptr [edx*4 + 0x5c], eax
        mov      eax, dword ptr [g_data_00542060]
        mov      ecx, dword ptr [eax*4 + 0x34]
        mov      dword ptr [ecx*4 + 0x58], 0xf0600000
        mov      edx, dword ptr [g_data_00542060]
        mov      eax, dword ptr [edx*4 + 0x30]
        mov      dword ptr [eax*4 + 0x74], 0xffffc000
        mov      dword ptr [esi + 8], OFFSET L_3ce0
        mov      dword ptr [esi + 0x84], edi
        mov      dword ptr [g_pendingNodeType], 0x24
        mov      dword ptr [g_framePauseFlag], edi
        pop      edi
        pop      esi
        ret
    L_3f23:
        call     BootInitGuardedCallChain_004265d0
        call     AudioInitInstallerPair_004a2140
    L_3f2d:
        pop      edi
        pop      esi
        ret
    L_jmptbl_3f30:
        /* 6 absolute-address entries (no reloc - orig has DIR32 reloc;
           literal bytes match link-time addresses) */
        _emit 0x46
        _emit 0x3e
        _emit 0x4a
        _emit 0x00
        _emit 0x0d
        _emit 0x3d
        _emit 0x4a
        _emit 0x00
        _emit 0x63
        _emit 0x3d
        _emit 0x4a
        _emit 0x00
        _emit 0xba
        _emit 0x3d
        _emit 0x4a
        _emit 0x00
        _emit 0xf6
        _emit 0x3d
        _emit 0x4a
        _emit 0x00
        _emit 0x1e
        _emit 0x3e
        _emit 0x4a
        _emit 0x00
    }
}
