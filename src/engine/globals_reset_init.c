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

/* @addr 0x004222a0 (224b game) - reset/init: clears ~17 globals, sets g_pendingNodeType=0x004200b0,
 *   g_eventQueueWorkType=0x1000, call AllocNode; if !pause: clears more globals and stores eax=0xc
 *   to g_walkCallback/0x0053a3e8; call ResetSceneCallbacks_00420090; if !pause: clears 6 more globals; ret.
 */
extern unsigned int g_dispatchSave109_0052aab4;
extern unsigned int g_dispatchSave108_0052ab44;
extern unsigned int g_extra_00535e68;
extern unsigned int g_dispatchSave102_00535e80;
extern unsigned int g_dispatchSave_00537ef4;
extern unsigned int g_dispatchVar38_00538128;
extern unsigned int g_extra_0053a280;
extern unsigned int g_dispatchSave94_0053a2d8;
extern unsigned int g_dispatchSave93_0053a2dc;
extern unsigned int g_dispatchSave91_0053a358;
extern unsigned int g_player1State;
extern unsigned int g_pendingMatchAcc_0053a3e8;
extern unsigned int g_dispatchSave84_0053a6d8;
extern unsigned int g_dst_0053a6e0;
extern unsigned int g_player2State;
extern unsigned int g_load_0052ab04;
extern unsigned int g_load_0052ab08;
extern unsigned int g_phaseTimer_00537e94;
extern unsigned int g_dst_00537ea4;
extern unsigned int g_counter_0053a51c;
extern unsigned int g_dispatchVar9_00541dc0;
extern unsigned int g_nodeUnlinkSlot_00541e4c;
extern void ResetSceneCallbacks_00420090(void);

__declspec(naked) void GlobalsResetInit_004222a0(void) {
    __asm {
        push    esi
        xor     esi, esi
        mov     dword ptr [g_walkCallback], esi
        mov     dword ptr [g_dispatchVar9_00541dc0], esi
        mov     dword ptr [g_pendingNodeType], 0x004200b0
        mov     dword ptr [g_eventQueueWorkType], 0x00001000
        call    AllocNode
        cmp     dword ptr [g_framePauseFlag], esi
        _emit   0fh
        _emit   85h
        _emit   0aah
        _emit   00h
        _emit   00h
        _emit   00h
        mov     eax, 0x0c
        mov     dword ptr [g_counter_0053a51c], esi
        mov     dword ptr [g_dispatchSave108_0052ab44], esi
        mov     dword ptr [g_dispatchSave84_0053a6d8], esi
        mov     dword ptr [g_player1NodeIdx], esi
        mov     dword ptr [g_player2NodeIdx], esi
        mov     dword ptr [g_phaseTimer_00537e94], esi
        mov     dword ptr [g_dispatchSave_00537ef4], esi
        mov     dword ptr [g_extra_00535e68], esi
        mov     dword ptr [g_extra_0053a280], esi
        mov     dword ptr [g_dispatchSave102_00535e80], esi
        mov     dword ptr [g_dispatchVar38_00538128], esi
        mov     dword ptr [g_player1State], esi
        mov     dword ptr [g_player2State], esi
        mov     dword ptr [g_dst_0053a6e0], esi
        mov     dword ptr [g_dst_00537ea4], esi
        mov     dword ptr [g_dispatchSave91_0053a358], esi
        mov     dword ptr [g_dispatchSave109_0052aab4], 8
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [g_pendingMatchAcc_0053a3e8], eax
        call    ResetSceneCallbacks_00420090
        cmp     dword ptr [g_framePauseFlag], esi
        _emit   75h
        _emit   24h
        mov     dword ptr [g_walkCallback], esi
        mov     dword ptr [g_nodeUnlinkSlot_00541e4c], esi
        mov     dword ptr [g_dispatchSave94_0053a2d8], esi
        mov     dword ptr [g_dispatchSave93_0053a2dc], esi
        mov     dword ptr [g_load_0052ab04], esi
        mov     dword ptr [g_load_0052ab08], esi
        pop     esi
        ret
    }
}
