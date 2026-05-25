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

extern unsigned int g_framePauseFlag;
extern unsigned int g_pendingNodeType;
extern unsigned int g_baseSel_00542060;
extern unsigned int g_acc_00542078;
extern unsigned int g_eventQueueNotMask;
extern void DualScaledStore_00452740(void);
extern void EntryThunkBodyStateMachine_00457bb0(void);
extern void GatedWordPushCall_00489f90(void);
extern void GuardedSeq_00472840(void);
extern void GuardedSeq_00473f10(void);
extern void MStackPush4ChainCopyPop4_00472e10(void);
extern void ScaledLoadTwoCallLit_00451f70(void);
extern void Set2CallIncJmp_00472860(void);
extern void Thunk_0049cbc0(void);

__declspec(naked) void JuggleFsmCluster_00451b90(void)
{
    __asm {
        mov      dword ptr [g_acc_00542078], 0xb
        jmp      GuardedSeq_00473f10
        nop
    L_1ba0:
        mov      eax, dword ptr [g_baseSel_00542060]
        push     esi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        cmp      eax, 8
        ja       L_1ed3
        jmp      dword ptr [eax*4 + L_jmptbl]
    L_1bce:
        mov      dword ptr [g_walkCallback], 0x35
        call     GatedWordPushCall_00489f90
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1ef0
        mov      dword ptr [g_walkCallback], 0x2b
        call     GatedWordPushCall_00489f90
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1ef0
        mov      dword ptr [esi + 8], OFFSET L_1ba0
        mov      dword ptr [esi + 0x84], 2
        mov      dword ptr [g_pendingNodeType], 0x12
        mov      dword ptr [g_framePauseFlag], 1
        pop      esi
        ret
    L_1c2d:
        mov      dword ptr [g_walkCallback], 0x36
        call     GatedWordPushCall_00489f90
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1ef0
        mov      dword ptr [esi + 8], OFFSET L_1ba0
        mov      dword ptr [esi + 0x84], 3
        mov      dword ptr [g_pendingNodeType], 0x12
        mov      dword ptr [g_framePauseFlag], 1
        pop      esi
        ret
    L_1c70:
        mov      dword ptr [g_walkCallback], 0x37
        call     GatedWordPushCall_00489f90
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1ef0
        mov      dword ptr [g_walkCallback], 0x2a
        call     GatedWordPushCall_00489f90
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1ef0
        mov      dword ptr [esi + 8], OFFSET L_1ba0
        mov      dword ptr [esi + 0x84], 4
        mov      dword ptr [g_pendingNodeType], 0x11
        mov      dword ptr [g_framePauseFlag], 1
        pop      esi
        ret
    L_1ccf:
        mov      dword ptr [g_walkCallback], 0x36
        call     GatedWordPushCall_00489f90
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1ef0
        mov      dword ptr [esi + 8], OFFSET L_1ba0
        mov      dword ptr [esi + 0x84], 5
        mov      dword ptr [g_pendingNodeType], 0x5f
        mov      dword ptr [g_framePauseFlag], 1
        pop      esi
        ret
    L_1d12:
        mov      dword ptr [g_walkCallback], 8
        call     GuardedSeq_00472840
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1ef0
        mov      dword ptr [esi + 8], OFFSET L_1ba0
        mov      dword ptr [esi + 0x84], 6
        mov      dword ptr [g_pendingNodeType], 0xf
        mov      dword ptr [g_framePauseFlag], 1
        pop      esi
        ret
    L_1d55:
        mov      dword ptr [g_walkCallback], 0x37
        call     GatedWordPushCall_00489f90
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1ef0
        mov      dword ptr [esi + 8], OFFSET L_1ba0
        mov      dword ptr [esi + 0x84], 7
        mov      dword ptr [g_pendingNodeType], 4
        mov      dword ptr [g_framePauseFlag], 1
        pop      esi
        ret
    L_1d98:
        call     MStackPush4ChainCopyPop4_00472e10
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1ef0
        call     Set2CallIncJmp_00472860
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1ef0
        call     ScaledLoadTwoCallLit_00451f70
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1ef0
        mov      dword ptr [g_eventQueueNotMask], 5
        call     EntryThunkBodyStateMachine_00457bb0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1ef0
        mov      dword ptr [esi + 8], OFFSET L_1ba0
        mov      dword ptr [esi + 0x84], 8
        mov      dword ptr [g_pendingNodeType], 0x1b
        mov      dword ptr [g_framePauseFlag], 1
        pop      esi
        ret
    L_1e11:
        call     MStackPush4ChainCopyPop4_00472e10
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1ef0
        call     Set2CallIncJmp_00472860
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1ef0
        call     ScaledLoadTwoCallLit_00451f70
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1ef0
        mov      dword ptr [g_eventQueueNotMask], 7
        call     EntryThunkBodyStateMachine_00457bb0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1ef0
        mov      dword ptr [esi + 8], OFFSET L_1ba0
        mov      dword ptr [esi + 0x84], 9
        mov      dword ptr [g_pendingNodeType], 7
        mov      dword ptr [g_framePauseFlag], 1
        pop      esi
        ret
    L_1e8a:
        call     DualScaledStore_00452740
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1ef0
        mov      dword ptr [g_eventQueueNotMask], 6
        call     EntryThunkBodyStateMachine_00457bb0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1ef0
        mov      eax, 1
        mov      dword ptr [esi + 8], OFFSET L_1ba0
        mov      dword ptr [esi + 0x84], eax
        mov      dword ptr [g_pendingNodeType], 0x55
        mov      dword ptr [g_framePauseFlag], eax
        pop      esi
        ret      
    L_1ed3:
        mov      dword ptr [g_walkCallback], 0x12
        call     GatedWordPushCall_00489f90
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1ef0
        call     Thunk_0049cbc0
    L_1ef0:
        pop      esi
        ret
        _emit 0x8b
        _emit 0xff
    L_jmptbl:
        _emit 0x8a
        _emit 0x1e
        _emit 0x45
        _emit 0x00
        _emit 0xce
        _emit 0x1b
        _emit 0x45
        _emit 0x00
        _emit 0x2d
        _emit 0x1c
        _emit 0x45
        _emit 0x00
        _emit 0x70
        _emit 0x1c
        _emit 0x45
        _emit 0x00
        _emit 0xcf
        _emit 0x1c
        _emit 0x45
        _emit 0x00
        _emit 0x12
        _emit 0x1d
        _emit 0x45
        _emit 0x00
        _emit 0x55
        _emit 0x1d
        _emit 0x45
        _emit 0x00
        _emit 0x98
        _emit 0x1d
        _emit 0x45
        _emit 0x00
        _emit 0x11
        _emit 0x1e
        _emit 0x45
        _emit 0x00
    }
}
