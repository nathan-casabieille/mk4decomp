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

extern unsigned int g_data_004f3930;
extern unsigned int g_data_004f393c;
extern unsigned int g_data_004f394c;
extern unsigned int g_data_004f39dc;
extern unsigned int g_data_004f3a48;
extern unsigned int g_data_004f6338;
extern unsigned int g_data_0050b118;
extern unsigned int g_data_0050f130;
extern unsigned int g_data_0050f14c;
extern unsigned int g_data_0051599c;
extern unsigned int g_data_00535de4;
extern unsigned int g_framePauseFlag;
extern unsigned int g_currentNodeIdx;
extern unsigned int g_xformEntityIdx;
extern unsigned int g_pendingNodeType;
extern unsigned int g_eventQueueIdx;
extern unsigned int g_baseSel_00542060;
extern unsigned int g_eventQueueWorkType;
extern unsigned int g_xformDirtyFlags;
extern unsigned int g_data_005433b8;
extern unsigned int g_data_005437f4;
extern void AudioBindEntry_004a1e40(void);
extern void AudioByteTable7LoopChainPick_004a5160(void);
extern void AudioInitArgs3_004a1f20(void);
extern void AudioState50b4BitDispatcher_004a32c0(void);
extern void FiveTableWalkInit_00403c90(void);
extern void InstallSelfPackedF80_00426000(void);
extern void MStackPush2ChainLLInsert_00406790(void);
extern void MStackPushComplexCallPop_00406430(void);
extern void PendingMatch_004a2a80(void);
extern void RetZero_004a1c40(void);
extern void ScaledByteIdxDualCopy_004a3260(void);
extern void SetJmp_004a1ac0(void);
extern void TableWalkBoundedCmp_004bd890(void);
extern void TripleCallByteCheck_004a1bf0(void);
extern void TripleCallSetCopy_004a4880(void);

__declspec(naked) void KonquestPortalCluster_004a5290(void)
{
    __asm {
    L_5290:
        mov      eax, dword ptr [g_baseSel_00542060]
        push     ebx
        push     ebp
        push     esi
        push     edi
        lea      edi, [eax*4]
        xor      ebp, ebp
        mov      eax, dword ptr [edi + 0x84]
        mov      dword ptr [edi + 0x84], ebp
        sub      eax, ebp
        je       L_5453
        dec      eax
        je       short L_52cd
        mov      dword ptr [g_data_005437f4], 1
        call     PendingMatch_004a2a80
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        ret
    L_52cd:
        mov      eax, dword ptr [g_eventQueueIdx]
        cmp      eax, ebp
        je       short L_52e0
        mov      dword ptr [g_currentNodeIdx], eax
        call     MStackPush2ChainLLInsert_00406790
    L_52e0:
        mov      eax, dword ptr [g_data_005433b8]
        cmp      eax, 4
        je       short L_52ff
        cmp      eax, 8
        jne      short L_530d
        mov      ecx, OFFSET g_data_0050f130
        shr      ecx, 2
        mov      dword ptr [g_xformEntityIdx], ecx
        jmp      short L_530d
    L_52ff:
        mov      edx, OFFSET g_data_0050f14c
        shr      edx, 2
        mov      dword ptr [g_xformEntityIdx], edx
    L_530d:
        call     DispatcherComplex260_00407400
        cmp      dword ptr [g_framePauseFlag], ebp
        jne      L_552f
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      dword ptr [g_eventQueueIdx], eax
        call     MStackPushComplexCallPop_00406430
        cmp      dword ptr [g_framePauseFlag], ebp
        jne      L_552f
        test     byte ptr [g_xformDirtyFlags], 4
        jne      short L_5360
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [ecx*4 + 0x54], ebp
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [edx*4 + 0x58], 0xfff60000
    L_5360:
        call     AudioByteTable7LoopChainPick_004a5160
        push     OFFSET g_data_004f3930
        call     ScaledByteIdxDualCopy_004a3260
        add      esp, 4
        push     OFFSET g_data_004f3930
        call     AudioState50b4BitDispatcher_004a32c0
        add      esp, 4
        call     TripleCallByteCheck_004a1bf0
        test     eax, eax
        mov      ebx, 1
        je       short L_53cb
        mov      eax, dword ptr [g_baseSel_00542060]
        mov      eax, dword ptr [eax*4 + 0x30]
        lea      ecx, [eax + eax*8]
        mov      eax, dword ptr [ecx*4 + g_data_004f393c]
        cmp      eax, ebp
        mov      dword ptr [g_currentNodeIdx], eax
        je       short L_53c3
        call     SetJmp_004a1ac0
        call     dword ptr [g_currentNodeIdx]
        cmp      dword ptr [g_framePauseFlag], ebp
        jne      L_552f
    L_53c3:
        test     byte ptr [g_xformDirtyFlags], bl
        jne      short L_53d8
    L_53cb:
        call     RetZero_004a1c40
        test     eax, eax
        je       L_5516
    L_53d8:
        mov      dword ptr [g_eventQueueWorkType], 0x32f
        call     Push16Call_00489f50
        call     AudioByteTable7LoopChainPick_004a5160
        mov      dword ptr [g_eventQueueCurrent], 0x20
        mov      dword ptr [edi + 8], OFFSET L_5290
        mov      edx, dword ptr [g_baseSel_00542060]
        mov      ecx, OFFSET L_5290
        add      ecx, 0x2000000
        mov      dword ptr [edx*4 + 0x84], 2
        mov      eax, dword ptr [edi + 4]
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [edi + 4], eax
        mov      edx, dword ptr [g_baseSel_00542060]
        mov      dword ptr [edx*4 + 0x84], ebp
        call     InstallSelfPackedF80_00426000
        mov      dword ptr [g_framePauseFlag], ebx
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        ret
    L_5453:
        mov      ebx, 1
        push     8
        mov      dword ptr [g_data_00535de4], ebx
        call     TableWalkBoundedCmp_004bd890
        add      esp, 4
        call     FiveTableWalkInit_00403c90
        cmp      dword ptr [g_framePauseFlag], ebp
        jne      L_552f
        mov      esi, OFFSET g_data_004f394c
    L_547e:
        cmp      esi, OFFSET g_data_004f39dc
        jge      short L_54a1
        mov      ecx, dword ptr [esi]
        mov      eax, dword ptr [esi + 4]
        sub      ecx, 0x50000
        push     eax
        push     ecx
        push     ebp
        push     OFFSET g_data_0051599c
        call     AudioInitArgs3_004a1f20
        add      esp, 0x10
    L_54a1:
        movsx    edx, byte ptr [esi - 0xc]
        mov      eax, dword ptr [g_baseSel_00542060]
        add      esi, 0x24
        add      edx, eax
        cmp      esi, OFFSET g_data_004f3a48
        mov      dword ptr [edx*4], ebp
        jb       short L_547e
        push     OFFSET g_data_004f6338
        call     AudioBindEntry_004a1e40
        mov      eax, dword ptr [g_baseSel_00542060]
        mov      ecx, OFFSET g_data_0050b118
        shr      ecx, 2
        add      esp, 4
        mov      dword ptr [eax*4 + 0x30], ebx
        mov      dword ptr [g_data_005433b8], 4
        mov      dword ptr [g_currentNodeIdx], ecx
        call     LoadGeoAsset_Default
        cmp      dword ptr [g_framePauseFlag], ebp
        jne      short L_552f
        call     TripleCallSetCopy_004a4880
        mov      dword ptr [g_eventQueueIdx], ebp
        mov      dword ptr [g_eventQueueWorkType], 9
        call     Push16Call_00489f50
    L_5516:
        mov      dword ptr [edi + 8], OFFSET L_5290
        mov      dword ptr [edi + 0x84], ebx
        mov      dword ptr [g_pendingNodeType], ebx
        mov      dword ptr [g_framePauseFlag], ebx
    L_552f:
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        ret
    }
}
