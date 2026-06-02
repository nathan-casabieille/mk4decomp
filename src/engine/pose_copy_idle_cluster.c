/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;
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
extern void SetJmp_0049cb90(void);
extern void Thunk_0049cbd0(void);
extern void ScaledZeroFour(void);
extern void WalkCbSubMul10_00431d50(void);
extern void Mul10Tail(unsigned int a, unsigned int b);
extern void BootMod6487eClampAndChainMul10(void);
extern void SpawnListBatchLoader_00477710(void);
extern void MStackPush2TableNot(void);
extern void GuardedChainCmpDualBitXor(void);
extern void ScaledLoadDecJmp_00429710(void);
extern void ScaledStoreCurDirtyClear_004296f0(void);
extern void MStackBitmaskIncMod_00492450(void);
extern void MStackBitmaskUpdate_00492510(void);
extern void Push1eCallTestDirtyLoop_004923b0(void);
extern void MStackLoopFieldInit_00492280(void);
extern void TaggedSceneDispatch(void);
extern void CallPauseDirty4StackPushFn_004839d0(void);
extern void CallPauseDirty1JmpDirty4StackPush_00483a80(void);
extern void Cmp2CallDirtyCall(void);
extern void QuadBlockArgInstallChain(void);
extern void InstallSelfChainSet84_80CallW_004363f0(void);
extern void Wrapper_00436490(void);
extern void MoveFsmCluster_004364a0(void);
extern void CallPauseTestByteJmpCalls(void);
extern void InstallSelfFullPath(void);
extern void InstallSelfCountdownChain_0047a950(void);
extern void CopyJmp_0048ef90(void);
extern void DualTestDirtyToggle_004282c0(void);
extern void TripleVecAccCallStore(void);
extern void Thunk_004bd5c0(void);
extern void AllocSlotPushTripleGlobals(void);
extern void MStackPop4Rewrite(void);
extern void Push70CallScaleArith(void);
extern void StreamChainStringInstall(void);
extern void MStackFrameCdeclDouble(void);
extern void ChainTableWalkStore_004917e0(void);
extern void Push16Call(void);
extern void DispatcherComplex260_00407030(void);
extern void ScaledLoadCmpStoreXfm_0048f2a0(void);
extern void StackPopDispatchTagged(void);
extern unsigned int g_cj_00542058;
extern unsigned int g_rangeSqLimit;
extern unsigned int g_zero_00541fa4;
extern unsigned int g_zero_00541fa8;
extern unsigned int g_dualBitGate;
extern unsigned int g_eventArmReload;
extern unsigned int g_rangeBase;

extern void ScaledArrStore_004298c0(void);
extern void DualFieldAddSubStore(void);
extern void IterStepDualStore(int);
extern void ScaledXorStore_004900f0(void);
extern void ChainWalkInstall(void);
extern void FpuSqrtMul(void);
extern void PendingMatch_0042b930(void);
extern void MStackPush2RunCountdown(void);
extern void MStackBracket7_DispatchAndChain(void);
extern void MStackBracketed3StoreCall(void);
extern void ChainDirtyBitWalker(void);
extern void Wrapper_0048a350(void);
extern void Wrapper_0048a3a0(void);
extern void Helper_DownloadSetup(void);
extern void MStackPush3CmpCall(void);
extern void Wrapper_0048ec20(void);
extern void FiveCallScaledChainTailJmp(void);
extern void SetJmp_00438f50(void);
extern void SetJmp_00438f60(void);
extern void GuardedDispatch_0042b6c0(void);
extern void MStackPushZeroCallPop_00407d00(void);
extern void DirtyToggleByGate(void);
extern void GameDispatchValidateState(void);
extern void CrouchAttackFsmCluster(void);
extern void MStackPushVec3Mul10(void);
extern void LiteralPushCallEntZero(void);
extern void LeaPlus22StoreSelf(void);
extern void IterLoad_00491050(void);
extern void GuardedDualConst2AndToggle(void);
extern void CallPauseScaledStorePushCall(void);
extern void LoadGeoAsset_Default(void);
extern void DispatcherComplex260_00407400(void);
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

extern void DirtyDoubleDeref_00408cb0(void);
extern void PoseCopyIdleCluster_004537a0(void);
extern void Bit2GatedChainInit_00453620(void);
extern void GDispatch4_004089c0(void);

extern unsigned char g_dispatchSave622_004ebee0;
extern unsigned int g_arr_491350;
extern unsigned int g_gtPlayerProbe2;
extern unsigned int g_gtPlayerProbe1;
#define g_gtPlayerProbe2 g_gtPlayerProbe2
#define g_gtPlayerProbe1 g_gtPlayerProbe1
extern void Thunk_0049cbd0(void);
extern void FiveCallScaledChainTailJmp(void);

extern void TwinLoopSlotFinder_00429a40(void);
extern void LoadGeoAsset_Default(void);

extern void CjInstallSelfRouter_00470480(void);
extern void Wrapper_0048a300(void);
extern void ScaledArrStore_00428e70(void);

extern void PushSetXfmMaskCallPop_00407140(void);

extern unsigned int g_gameCountdown;
extern void SaveCallRestore_004049d0(int);
extern void SaveCallRestoreOrXor_00404a00(int);

extern void func_004244d0_fwd(void);
#define MStackPush1MagicMod2_004244d0 func_004244d0_fwd
extern unsigned int g_chain_disp_64_40a690_fwd;
#define g_chain_disp_64_40a690 g_chain_disp_64_40a690_fwd

extern void GuardedClampStoreJmp_00428bd0(void);
extern void MStackPushZeroCallPop_00407d00(void);

extern unsigned int g_counter_0053a51c;
#define g_counter_0053a51c g_counter_0053a51c
extern void SixCallSeqPushImm_004a1d80(void);
extern unsigned int g_phaseTimer;
#define g_phaseTimer g_phaseTimer
extern void BossSpinCluster_00487e80(void);

extern unsigned int g_bootLongChainState_00537f24;
extern unsigned int g_arr_chain_4348f0_2c;
extern unsigned int g_arr_chain_4348f0_main;

/* @addr 0x0049d0a0 (166b game) - linked-list walk + swap head:
 *   eax = chain[scaledInit].slot2c; if 0: ret.
 *   mstack-push g_xformEntityIdx; ecx = eax; g_xformEntityIdx = ecx;
 *   while ((eax = arr[ecx]) != 0): ecx = eax; g_xformEntityIdx = ecx;
 *   At tail: arr[ecx] = g_bootLongChainState_00537f24; g_bootLongChainState_00537f24 = chain[scaledInit].slot2c;
 *   mstack-pop g_xformEntityIdx.
 */

extern unsigned int g_matrixStack_arr;

void LinkedListSwapHead_0049d0a0(void) {
    __asm {
        mov     eax, dword ptr [g_scaledInit_00542044]
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
        mov     eax, dword ptr [g_bootLongChainState_00537f24]
        mov     dword ptr [g_walkCallback], eax
        mov     [ecx*4 + g_arr_chain_4348f0_main], eax
        mov     edx, dword ptr [g_scaledInit_00542044]
        mov     eax, [edx*4 + g_arr_chain_4348f0_2c]
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [g_bootLongChainState_00537f24], eax
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, [eax*4 + g_matrixStack_arr]
        dec     eax
        mov     dword ptr [g_xformEntityIdx], ecx
        mov     dword ptr [g_matrixStackTop], eax
        }
}

