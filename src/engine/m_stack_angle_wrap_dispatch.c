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
extern unsigned int g_audioBankSel_00537f94;
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
extern unsigned int g_audioBoundNode_005437f0;
extern unsigned int g_data_00543598;
extern unsigned int g_data_0054358c;
extern unsigned int g_fightAxisNegX_00535e70;
extern unsigned int g_fightAxisNegY_00535e74;
extern unsigned int g_fightAxisPosX_00535e78;
extern unsigned int g_fightAxisPosY_00535e7c;

extern unsigned int g_data_004d57ac;
extern unsigned int g_framePauseFlag;
extern unsigned int g_currentNodeIdx;
extern unsigned int g_xformEntityIdx;
extern unsigned int g_eventQueueWorkType;
extern unsigned int g_acc_00542078;
extern unsigned int g_eventQueueNotMask;
extern unsigned int g_eventQueueChild;
extern unsigned int g_xformScratch2088;
extern void RandSarMod0xFFFSub400_0041f1f0(void);
extern void RandSarMod0xFFF_0041f230(void);

__declspec(naked) void MStackAngleWrapDispatch_0048b800(void)
{
    __asm {
        mov      eax, dword ptr [g_data_004d57ac]
        mov      ecx, dword ptr [g_eventQueueCurrent]
        inc      eax
        push     esi
        mov      dword ptr [g_data_004d57ac], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_data_004d57ac]
        mov      edx, dword ptr [g_eventQueueChild]
        inc      eax
        mov      dword ptr [g_data_004d57ac], eax
        mov      dword ptr [eax*4], edx
        mov      eax, dword ptr [g_data_004d57ac]
        mov      ecx, dword ptr [g_currentNodeFlags]
        inc      eax
        mov      dword ptr [g_data_004d57ac], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_data_004d57ac]
        mov      edx, dword ptr [g_xformScratch2088]
        inc      eax
        mov      dword ptr [g_data_004d57ac], eax
        mov      dword ptr [eax*4], edx
        mov      eax, dword ptr [g_data_004d57ac]
        mov      ecx, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_data_004d57ac], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_data_004d57ac]
        mov      edx, dword ptr [g_xformEntityIdx]
        inc      eax
        mov      dword ptr [g_data_004d57ac], eax
        mov      dword ptr [eax*4], edx
        mov      eax, dword ptr [g_data_004d57ac]
        mov      ecx, dword ptr [g_acc_00542078]
        inc      eax
        mov      dword ptr [g_data_004d57ac], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_data_004d57ac]
        mov      edx, dword ptr [g_eventQueueNotMask]
        inc      eax
        mov      dword ptr [g_data_004d57ac], eax
        mov      dword ptr [eax*4], edx
        mov      ecx, dword ptr [g_eventQueueWorkType]
        test     ecx, ecx
        jge      short L_b8ea
        mov      edx, 0x6487d
        mov      eax, 0xa2f99905
        sub      edx, ecx
        mul      edx
        shr      edx, 0x12
        imul     edx, edx, 0x6487e
        add      ecx, edx
        mov      dword ptr [g_eventQueueWorkType], ecx
    L_b8ea:
        cmp      ecx, 0x6487e
        jl       short L_b90b
        mov      eax, 0xa2f99905
        mul      ecx
        shr      edx, 0x12
    L_b8fc:
        sub      ecx, 0x6487e
        dec      edx
        jne      short L_b8fc
        mov      dword ptr [g_eventQueueWorkType], ecx
    L_b90b:
        mov      eax, dword ptr [g_data_004d57ac]
        inc      eax
        mov      dword ptr [g_data_004d57ac], eax
        mov      dword ptr [eax*4], ecx
        call     RandSarMod0xFFF_0041f230
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_bab2
        mov      eax, dword ptr [g_data_004d57ac]
        mov      edx, dword ptr [g_walkCallback]
        mov      ecx, dword ptr [eax*4]
        mov      dword ptr [g_data_004d57ac], eax
        mov      dword ptr [g_eventQueueWorkType], ecx
        mov      dword ptr [eax*4], edx
        call     RandSarMod0xFFFSub400_0041f1f0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_bab2
        mov      eax, dword ptr [g_data_004d57ac]
        mov      ecx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_eventQueueCurrent], ecx
        mov      dword ptr [g_data_004d57ac], eax
        mov      edx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_eventQueueNotMask], edx
        mov      dword ptr [g_data_004d57ac], eax
        mov      edx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_acc_00542078], edx
        mov      dword ptr [g_data_004d57ac], eax
        mov      esi, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_xformEntityIdx], esi
        mov      dword ptr [g_data_004d57ac], eax
        mov      esi, dword ptr [eax*4]
        dec      eax
        push     ecx
        push     edx
        mov      dword ptr [g_currentNodeIdx], esi
        mov      dword ptr [g_data_004d57ac], eax
        call     Mul10Tail_00404af0
        mov      ecx, dword ptr [g_eventQueueNotMask]
        add      esp, 8
        mov      dword ptr [g_eventQueueChild], eax
        mov      eax, dword ptr [g_walkCallback]
        push     eax
        push     ecx
        call     Mul10Tail_00404af0
        mov      ecx, dword ptr [esp + 0x10]
        add      esp, 8
        test     ecx, ecx
        mov      dword ptr [g_currentNodeFlags], eax
        je       short L_ba09
        mov      edx, dword ptr [g_eventQueueChild]
        add      eax, edx
        mov      dword ptr [g_xformScratch2088], eax
        jmp      short L_ba17
    L_ba09:
        mov      ecx, dword ptr [g_eventQueueChild]
        sub      ecx, eax
        mov      dword ptr [g_xformScratch2088], ecx
    L_ba17:
        mov      edx, dword ptr [g_eventQueueCurrent]
        mov      eax, dword ptr [g_eventQueueNotMask]
        push     edx
        push     eax
        call     Mul10Tail_00404af0
        mov      ecx, dword ptr [g_walkCallback]
        mov      edx, dword ptr [g_acc_00542078]
        add      esp, 8
        mov      dword ptr [g_eventQueueChild], eax
        push     ecx
        push     edx
        call     Mul10Tail_00404af0
        mov      ecx, dword ptr [g_eventQueueChild]
        mov      edx, dword ptr [g_xformScratch2088]
        sub      ecx, eax
        mov      eax, dword ptr [g_data_004d57ac]
        mov      dword ptr [g_eventQueueNotMask], ecx
        mov      dword ptr [g_acc_00542078], edx
        mov      ecx, dword ptr [eax*4]
        add      esp, 8
        dec      eax
        mov      dword ptr [g_xformScratch2088], ecx
        mov      dword ptr [g_data_004d57ac], eax
        mov      edx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_currentNodeFlags], edx
        mov      dword ptr [g_data_004d57ac], eax
        mov      ecx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_eventQueueChild], ecx
        mov      dword ptr [g_data_004d57ac], eax
        mov      edx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_eventQueueCurrent], edx
        mov      dword ptr [g_data_004d57ac], eax
    L_bab2:
        pop      esi
        ret
    }
}
