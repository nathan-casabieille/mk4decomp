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

extern unsigned int g_data_004d57ac;
extern unsigned int g_data_004ffe4c;
extern unsigned int g_data_00501970;
extern unsigned int g_data_0052aafc;
extern unsigned int g_active_00537e88;
extern unsigned int g_data_00537f48;
extern unsigned int g_data_00537f78;
extern unsigned int g_data_00537f94;
extern unsigned int g_data_005380e0;
extern unsigned int g_data_0053a318;
extern unsigned int g_active_0053a408;
extern unsigned int g_data_0053a510;
extern unsigned int g_data_00541de8;
extern unsigned int g_data_00541dec;
extern unsigned int g_framePauseFlag;
extern unsigned int g_currentNodeIdx;
extern unsigned int g_xformEntityIdx;
extern unsigned int g_fightGroupHead;
extern unsigned int g_eventQueueWorkType;
extern unsigned int g_data_00543564;
extern unsigned int g_data_00543594;
extern void CallSetPause_0041f830(void);
extern void Cmp7CondStateUpdate_0042ed90(void);
extern void GameMusicState4Way_00426d90(void);
extern void GuardedDualPushTailJmp_004231f0(void);
extern void ScaledLoadOrSetJmp_00406b20(void);

__declspec(naked) void DeathAnimCluster_0042eaf0(void)
{
    __asm {
        /* === Helper 1 (0x42eaf0): death-pose install + post-rotation === */
        mov      eax, dword ptr [g_data_004d57ac]
        mov      ecx, dword ptr [g_xformEntityIdx]
        inc      eax
        push     esi
        mov      dword ptr [g_data_004d57ac], eax
        xor      esi, esi
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_data_004d57ac]
        mov      edx, dword ptr [g_data_00541dec]
        mov      ecx, dword ptr [g_data_00541de8]
        inc      eax
        mov      dword ptr [g_eventQueueCurrent], edx
        mov      dword ptr [g_data_004d57ac], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_data_004d57ac]
        mov      edx, dword ptr [g_eventQueueCurrent]
        inc      eax
        mov      dword ptr [g_data_004d57ac], eax
        mov      dword ptr [eax*4], edx
        mov      eax, dword ptr [g_data_0053a318]
        cmp      eax, 1
        mov      dword ptr [g_data_00541de8], esi
        mov      dword ptr [g_data_00541dec], esi
        je       short L_eb75
        mov      eax, dword ptr [g_data_00537f48]
        mov      ecx, dword ptr [g_data_0053a510]
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [g_eventQueueWorkType], ecx
        jmp      short L_eb8b
    L_eb75:
        mov      edx, dword ptr [g_data_005380e0]
        mov      eax, dword ptr [g_data_0052aafc]
        mov      dword ptr [g_walkCallback], edx
        mov      dword ptr [g_eventQueueWorkType], eax
    L_eb8b:
        mov      dword ptr [g_eventQueueCurrent], esi
        call     GuardedDualPushTailJmp_004231f0
        cmp      dword ptr [g_framePauseFlag], esi
        jne      L_ed0b
        mov      eax, dword ptr [g_data_004d57ac]
        mov      ecx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_eventQueueCurrent], ecx
        mov      dword ptr [g_data_004d57ac], eax
        mov      edx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_walkCallback], edx
        mov      dword ptr [g_data_004d57ac], eax
        mov      dword ptr [g_data_00541de8], edx
        mov      dword ptr [g_data_00541dec], ecx
        call     GameMusicState4Way_00426d90
        cmp      dword ptr [g_framePauseFlag], esi
        jne      L_ed0b
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      dword ptr [ecx*4 + 0x30], 0x23c
        mov      dword ptr [ecx*4 + 0x54], esi
        mov      dword ptr [ecx*4 + 0x58], esi
        mov      edx, dword ptr [ecx*4 + 0x34]
        lea      eax, [ecx*4]
        or       edx, 0x180000
        mov      dword ptr [eax + 0x34], edx
        mov      dword ptr [eax + 0x64], esi
        mov      dword ptr [eax + 0x68], esi
        mov      dword ptr [eax + 0x5c], 0xfffd0000
        mov      dword ptr [eax + 0x60], 0x4b333
        mov      ecx, dword ptr [g_data_00537f94]
        mov      eax, OFFSET g_data_004ffe4c
        mov      edx, 0xf
        shr      eax, 2
        cmp      ecx, 2
        mov      dword ptr [g_walkCallback], eax
        jne      short L_ec66
        cmp      dword ptr [g_data_00537f48], edx
        jne      short L_ec66
        mov      eax, OFFSET g_data_00501970
        shr      eax, 2
        mov      dword ptr [g_walkCallback], eax
    L_ec66:
        cmp      ecx, 1
        jne      short L_ec80
        cmp      dword ptr [g_data_005380e0], edx
        jne      short L_ec80
        mov      eax, OFFSET g_data_00501970
        shr      eax, 2
        mov      dword ptr [g_walkCallback], eax
    L_ec80:
        mov      edx, dword ptr [g_fightGroupHead]
        mov      dword ptr [edx*4 + 0x24], eax
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      eax, dword ptr [g_walkCallback]
        mov      dword ptr [ecx*4 + 0x28], eax
        call     ScaledLoadOrSetJmp_00406b20
        cmp      dword ptr [g_framePauseFlag], esi
        jne      short L_ed0b
        mov      eax, dword ptr [g_data_00537f78]
        mov      dword ptr [g_xformEntityIdx], eax
        mov      dword ptr [eax*4 + 0x54], esi
        mov      edx, dword ptr [g_xformEntityIdx]
        mov      eax, 0xfff98000
        mov      dword ptr [edx*4 + 0x58], esi
        mov      ecx, dword ptr [g_xformEntityIdx]
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x5c], eax
        mov      eax, dword ptr [g_fightGroupHead]
        mov      edx, dword ptr [g_xformEntityIdx]
        mov      dword ptr [eax*4 + 0x3c], edx
        mov      eax, dword ptr [g_data_004d57ac]
        mov      ecx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_xformEntityIdx], ecx
        mov      dword ptr [g_data_004d57ac], eax
    L_ed0b:
        pop      esi
        ret
        nop
        nop
        nop
        /* === Helper 2: p1 death gate → 0042ed90 === */
        mov      ecx, dword ptr [g_active_0053a408]
        mov      eax, 1
        cmp      ecx, eax
        jne      short L_ed38
        mov      ecx, dword ptr [g_active_00537e88]
        test     ecx, ecx
        jne      short L_ed38
        mov      ecx, dword ptr [g_data_00543594]
        test     ecx, ecx
        jge      short L_ed38
        jmp      CallSetPause_0041f830
    L_ed38:
        mov      ecx, OFFSET g_active_0053a408
        mov      dword ptr [g_eventQueueCurrent], eax
        shr      ecx, 2
        mov      dword ptr [g_currentNodeIdx], ecx
        jmp      Cmp7CondStateUpdate_0042ed90
        /* === Helper 3: p2 death gate → 0042ed90 === */
        mov      eax, dword ptr [g_active_0053a408]
        test     eax, eax
        jne      short L_ed70
        cmp      dword ptr [g_active_00537e88], 1
        jne      short L_ed70
        mov      eax, dword ptr [g_data_00543564]
        test     eax, eax
        jge      short L_ed70
        jmp      CallSetPause_0041f830
    L_ed70:
        mov      eax, OFFSET g_active_00537e88
        mov      dword ptr [g_eventQueueCurrent], 2
        shr      eax, 2
        mov      dword ptr [g_currentNodeIdx], eax
        jmp      Cmp7CondStateUpdate_0042ed90
    }
}
