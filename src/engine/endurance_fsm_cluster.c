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

extern unsigned int g_data_004df6f0;
extern unsigned int g_active_00537e88;
extern unsigned int g_active_0053a408;
extern unsigned int g_framePauseFlag;
extern unsigned int g_currentNodeIdx;
extern unsigned int g_xformEntityIdx;
extern unsigned int g_pendingNodeType;
extern unsigned int g_eventQueueIdx;
extern unsigned int g_fightGroupHead;
extern unsigned int g_baseSel_00542060;
extern unsigned int g_acc_00542078;
extern unsigned int g_eventQueueNotMask;
extern void BootInitGuardedCallChain_004265d0(void);
extern void BootMultiAssetLoadStateInit_00403b10(void);
extern void CallSetPause_0041f830(void);
extern void InstallSelfPackedF80_00426000(void);
extern void MStackCall_00406740(void);
extern void TableWalkBoundedCmp_004bd890(void);

__declspec(naked) void EnduranceFsmCluster_004238e0(void)
{
    __asm {
        /* === Helper 1 (0x4238e0): 4-state FSM w/ jump table === */
    L_38e0:
        mov      eax, dword ptr [g_baseSel_00542060]
        push     esi
        push     edi
        xor      edi, edi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], edi
        cmp      eax, 3
        ja       L_3a64
        jmp      dword ptr [eax*4 + L_jmptbl_3a78]
    L_390d:
        /* case 2: bump counter */
        mov      eax, dword ptr [g_eventQueueIdx]
        inc      eax
        mov      dword ptr [g_eventQueueIdx], eax
        jmp      short L_39c9
    L_391d:
        /* case 3: state-4 install-self */
        mov      eax, 4
        mov      edx, OFFSET L_38e0
        mov      dword ptr [g_eventQueueCurrent], eax
        mov      dword ptr [esi + 8], OFFSET L_38e0
        mov      ecx, dword ptr [g_baseSel_00542060]
        add      edx, 0x4000000
        mov      dword ptr [ecx*4 + 0x84], eax
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], edx
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      eax, dword ptr [g_baseSel_00542060]
        mov      dword ptr [eax*4 + 0x84], edi
        call     InstallSelfPackedF80_00426000
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        ret
    L_3981:
        /* case 0: initial → walk table */
        call     BootInitGuardedCallChain_004265d0
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_3a73
        mov      dword ptr [g_walkCallback], edi
        mov      dword ptr [g_active_0053a408], edi
        mov      dword ptr [g_active_00537e88], edi
        call     BootMultiAssetLoadStateInit_00403b10
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_3a73
        mov      eax, OFFSET g_data_004df6f0
        shr      eax, 2
        mov      dword ptr [g_eventQueueIdx], eax
        jmp      short L_39c9
    L_39c4:
        /* case 1: load from saved table-index, then walk */
        mov      eax, dword ptr [g_eventQueueIdx]
    L_39c9:
        mov      ecx, dword ptr [eax*4]
        cmp      ecx, edi
        mov      dword ptr [g_walkCallback], ecx
        jge      short L_3a02
        mov      dword ptr [esi + 8], OFFSET L_38e0
        mov      dword ptr [esi + 0x84], 3
        mov      dword ptr [g_pendingNodeType], 0x168
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        ret
    L_3a02:
        mov      edi, 1
        cmp      ecx, edi
        je       short L_3a3e
        push     0x17
        push     OFFSET L_3a90
        call     StoreTwoCall_0049cb40
        mov      dword ptr [esi + 8], OFFSET L_38e0
        mov      dword ptr [esi + 0x84], 2
        add      esp, 8
        mov      dword ptr [g_pendingNodeType], 0x12
        mov      dword ptr [g_framePauseFlag], edi
        pop      edi
        pop      esi
        ret
    L_3a3e:
        inc      eax
        mov      dword ptr [g_eventQueueIdx], eax
        mov      dword ptr [esi + 8], OFFSET L_38e0
        mov      dword ptr [esi + 0x84], edi
        mov      dword ptr [g_pendingNodeType], 0x32
        mov      dword ptr [g_framePauseFlag], edi
        pop      edi
        pop      esi
        ret
    L_3a64:
        push     9
        call     TableWalkBoundedCmp_004bd890
        add      esp, 4
        call     StackPopDispatchTagged_0041f780
    L_3a73:
        pop      edi
        pop      esi
        ret
        mov      edi, edi
    L_jmptbl_3a78:
        /* 4 absolute-address entries */
        _emit 0x81
        _emit 0x39
        _emit 0x42
        _emit 0x00
        _emit 0xc4
        _emit 0x39
        _emit 0x42
        _emit 0x00
        _emit 0x0d
        _emit 0x39
        _emit 0x42
        _emit 0x00
        _emit 0x1d
        _emit 0x39
        _emit 0x42
        _emit 0x00
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        /* === Helper 2 (0x423a90): wait-then-end-of-round FSM === */
    L_3a90:
        mov      eax, dword ptr [g_baseSel_00542060]
        push     esi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        test     eax, eax
        je       short L_3ae8
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      eax, dword ptr [ecx*4 + 0x58]
        cmp      eax, 0xff060000
        mov      dword ptr [g_walkCallback], eax
        jg       L_3b5d
        call     MStackCall_00406740
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_3b79
        call     CallSetPause_0041f830
        pop      esi
        ret
    L_3ae8:
        mov      edx, dword ptr [g_eventQueueIdx]
        mov      eax, dword ptr [edx*4]
        mov      dword ptr [g_walkCallback], 0xa
        mov      dword ptr [g_xformEntityIdx], eax
        mov      dword ptr [g_eventQueueCurrent], 4
        mov      dword ptr [g_acc_00542078], 0
        mov      dword ptr [g_eventQueueNotMask], 0xfa0000
        call     Push70CallScaleArith_00457ad0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_3b79
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [ecx*4 + 0x5c], 0x10000
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      ecx, 0xfffe1000
        mov      dword ptr [g_fightGroupHead], eax
        mov      dword ptr [g_walkCallback], ecx
        mov      dword ptr [eax*4 + 0x70], ecx
    L_3b5d:
        mov      eax, 1
        mov      dword ptr [esi + 8], OFFSET L_3a90
        mov      dword ptr [esi + 0x84], eax
        mov      dword ptr [g_pendingNodeType], eax
        mov      dword ptr [g_framePauseFlag], eax
    L_3b79:
        pop      esi
        ret
    }
}
