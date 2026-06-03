/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_currentNodeIdx;
extern unsigned int g_baseSel;
extern unsigned int g_acc_00542078;
extern unsigned int g_cj_0054205c;
extern unsigned int g_gameCountdown;
extern unsigned int g_xformScratch94;
extern unsigned int g_table_00535ddc;
extern unsigned int g_active_00537e88;
extern unsigned int g_active_0053a408;
extern unsigned int g_audioBankSel;

extern void StoreTwoCall(int, int);
extern void SetJmp_Thunk_LinkedListBitMaskSearch(void);
extern void Thunk_ChainNodeInit(void);
extern void ScaledZeroFour(void);
extern void WalkCbSubMul10(void);
extern void Mul10Tail(unsigned int a, unsigned int b);
extern void BootMod6487eClampAndChainMul10(void);
extern void SpawnListBatchLoader(void);
extern void MStackPush2TableNot(void);
extern void GuardedChainCmpDualBitXor(void);
extern void ScaledLoadDecJmp(void);
extern void ScaledStoreCurDirtyClear(void);
extern void MStackBitmaskIncMod(void);
extern void MStackBitmaskUpdate(void);
extern void Push1eCallTestDirtyLoop(void);
extern void MStackLoopFieldInit(void);
extern void TaggedSceneDispatch(void);
extern void CallPauseDirty4StackPushFn(void);
extern void CallPauseDirty1JmpDirty4StackPush_GuardedDoubleIncCmpJmp(void);
extern void Cmp2CallDirtyCall(void);
extern void QuadBlockArgInstallChain(void);
extern void InstallSelfChainSet84_80CallW(void);
extern void Wrapper_PackedAdvanceCallTailJmp_004e46d0(void);
extern void MoveFsmCluster(void);
extern void CallPauseTestByteJmpCalls(void);
extern void InstallSelfFullPath(void);
extern void InstallSelfCountdownChain(void);
extern void CopyJmp_SlotCmp3way_g_currentNodeIdx(void);
extern void DualTestDirtyToggle_004282c0(void);
extern void TripleVecAccCallStore(void);
extern void Thunk_LoadGeoAsset_Default(void);
extern void AllocSlotPushTripleGlobals(void);
extern void MStackPop4Rewrite(void);
extern void Push70CallScaleArith(void);
extern void StreamChainStringInstall(void);
extern void MStackFrameCdeclDouble(void);
extern void ChainTableWalkStore(void);
extern void Push16Call(void);
extern void DispatcherComplex260_MStackBracket1_TreeWalkRecursive2(void);
extern void ScaledLoadCmpStoreXfm(void);
extern void StackPopDispatchTagged(void);
extern unsigned int g_cj_00542058;
extern unsigned int g_rangeSqLimit;
extern unsigned int g_zero_00541fa4;
extern unsigned int g_zero_00541fa8;
extern unsigned int g_dualBitGate;
extern unsigned int g_eventArmReload;
extern unsigned int g_rangeBase;

extern void ScaledArrStore_ScaledChainJmp_004298c0(void);
extern void DualFieldAddSubStore(void);
extern void IterStepDualStore(int);
extern void ScaledXorStore_004900f0(void);
extern void ChainWalkInstall(void);
extern void FpuSqrtMul(void);
extern void PendingMatch_StoreTwoCall_0042b930(void);
extern void MStackPush2RunCountdown(void);
extern void MStackBracket7_DispatchAndChain(void);
extern void MStackBracketed3StoreCall(void);
extern void ChainDirtyBitWalker(void);
extern void Wrapper_ScaledChainPushCall_004ef858(void);
extern void Wrapper_ScaledChainPushCall_004ef8b0(void);
extern void Helper_DownloadSetup(void);
extern void MStackPush3CmpCall(void);
extern void Wrapper_IterLoad_0048fd30_004f12a0(void);
extern void FiveCallScaledChainTailJmp(void);
extern void SetJmp_StateDispatchYield_00438f50(void);
extern void SetJmp_StateDispatchYield_00438f60(void);
extern void GuardedDispatch_InstallSelfDualEsi(void);
extern void MStackPushZeroCallPop_PendingMatch(void);
extern void DirtyToggleByGate(void);
extern void GameDispatchValidateState(void);
extern void CrouchAttackFsmCluster(void);
extern void MStackPushVec3Mul10(void);
extern void LiteralPushCallEntZero(void);
extern void LeaPlus22StoreSelf(void);
extern void IterLoad_g_scaledInit_00542048_then_DualScaledStoreZero(void);
extern void GuardedDualConst2AndToggle(void);
extern void CallPauseScaledStorePushCall(void);
extern void LoadGeoAsset_Default(void);
extern void DispatcherComplex260_FramePauseScaledStore(void);
extern void PushSetCallPop(void);
extern unsigned int g_stateCountdown;
extern unsigned int g_installOwnerNode;
extern unsigned int g_cj_00542054;
extern unsigned int g_audioBoundNode;
extern unsigned int g_lastGatedValue;
extern unsigned int g_lastGatedTick;
extern unsigned int g_fightAxisNegX;
extern unsigned int g_fightAxisNegY;
extern unsigned int g_fightAxisPosX;
extern unsigned int g_fightAxisPosY;

extern unsigned int g_arr_41aaf0_mstack;
extern void BootStateInitLongChain(void);
extern void KnockbackPositionReset(void);

extern void PushPopWalkSet1006(void);
extern void ScaledLoadJmp_00428d20(void);

extern unsigned int g_chain_disp_64_440d20;
extern void BackdashSetupCluster(void);

extern void Thunk_NodeChainMaskMatch(void);
extern void Thunk_LoadShlDerefCallSkip(void);

extern unsigned int g_eventQueueIdx;

extern unsigned char g_dispatchSave1198;
extern unsigned char g_dispatchSave1199;
extern unsigned int g_arr_4237d0;
extern void Cmp2DirtyToggle(void);

extern unsigned char g_dispatchSave1277;
extern unsigned int g_arr_461640;
extern unsigned char g_str_00461980;

extern void PreFightInstallCluster(void);

extern unsigned int g_chain_disp_30_439a40;
extern unsigned int g_chain_disp_40_439a40;
extern unsigned int g_fightTickSavedSlot;
extern void TwoStageWalkGate(void);
extern void TwoConditionalJmp(void);
extern void Thunk_SetJmp(void);
extern void AudioVolumeRescale(void);

extern void MStackPush2ChainLLInsert(void);
extern void MStackPush2LLWalkCompare(void);

extern void DirtyDoubleDeref(void);
extern void PoseCopyIdleCluster(void);
extern void Bit2GatedChainInit(void);
extern void GDispatch4(void);

extern unsigned char g_dispatchSave622;
extern unsigned int g_arr_491350;
extern unsigned int g_gtPlayerProbe2;
extern unsigned int g_gtPlayerProbe1;
extern void Thunk_ChainNodeInit(void);
extern void FiveCallScaledChainTailJmp(void);

extern void TwinLoopSlotFinder(void);
extern void LoadGeoAsset_Default(void);

extern void CjInstallSelfRouter(void);
extern void Wrapper_ScaledChainPushCall_004ef898(void);
extern void ScaledArrStore_EsiInstallBitCallChain_00428e70(void);

extern void PushSetXfmMaskCallPop(void);

extern unsigned int g_gameCountdown;
extern void SaveCallRestore(int);
extern void SaveCallRestoreOrXor(int);

extern void func_004244d0_fwd(void);
#define MStackPush1MagicMod2 func_004244d0_fwd
extern unsigned int g_chain_disp_64_40a690_fwd;
#define g_chain_disp_64_40a690 g_chain_disp_64_40a690_fwd

extern void GuardedClampStoreJmp(void);
extern void MStackPushZeroCallPop_PendingMatch(void);

extern unsigned int g_counter_0053a51c;
extern void SixCallSeqPushImm(void);
extern unsigned int g_phaseTimer;
extern void BossSpinCluster(void);

extern unsigned int g_bootLongChainState;
extern unsigned int g_arr_chain_4348f0_2c;
extern unsigned int g_arr_chain_4348f0_main;

/* @addr 0x0049d0a0 (166b game) - linked-list walk + swap head:
 *   eax = chain[scaledInit].slot2c; if 0: ret.
 *   mstack-push g_xformEntityIdx; ecx = eax; g_xformEntityIdx = ecx;
 *   while ((eax = arr[ecx]) != 0): ecx = eax; g_xformEntityIdx = ecx;
 *   At tail: arr[ecx] = g_bootLongChainState; g_bootLongChainState = chain[scaledInit].slot2c;
 *   mstack-pop g_xformEntityIdx.
 */

extern unsigned int g_matrixStack_arr;

void LinkedListSwapHead(void) {
    __asm {
        mov     eax, dword ptr [g_currentNodeIdx]
        mov     eax, [eax*4 + g_arr_chain_4348f0_2c]
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        _emit   0fh
        _emit   84h
        _emit   8ch
        _emit   00h
        _emit   00h
        _emit   00h
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_xformEntityIdx]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     [eax*4 + g_matrixStack_arr], ecx
        mov     ecx, dword ptr [g_walkCallback]
        mov     dword ptr [g_xformEntityIdx], ecx
        mov     eax, [ecx*4 + g_arr_chain_4348f0_main]
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        _emit   74h
        _emit   18h
loopWalk:
        mov     ecx, eax
        mov     dword ptr [g_xformEntityIdx], ecx
        mov     eax, [eax*4 + g_arr_chain_4348f0_main]
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        _emit   75h
        _emit   0e8h
        mov     eax, dword ptr [g_bootLongChainState]
        mov     dword ptr [g_walkCallback], eax
        mov     [ecx*4 + g_arr_chain_4348f0_main], eax
        mov     edx, dword ptr [g_currentNodeIdx]
        mov     eax, [edx*4 + g_arr_chain_4348f0_2c]
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [g_bootLongChainState], eax
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, [eax*4 + g_matrixStack_arr]
        dec     eax
        mov     dword ptr [g_xformEntityIdx], ecx
        mov     dword ptr [g_matrixStackTop], eax
        }
}

