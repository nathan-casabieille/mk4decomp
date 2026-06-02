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
extern void CallPauseDirty1JmpDirty4StackPush_00483a80(void);
extern void Cmp2CallDirtyCall(void);
extern void QuadBlockArgInstallChain(void);
extern void InstallSelfChainSet84_80CallW(void);
extern void Wrapper_00436490(void);
extern void MoveFsmCluster(void);
extern void CallPauseTestByteJmpCalls(void);
extern void InstallSelfFullPath(void);
extern void InstallSelfCountdownChain(void);
extern void CopyJmp_0048ef90(void);
extern void DualTestDirtyToggle_004282c0(void);
extern void TripleVecAccCallStore(void);
extern void Thunk_004bd5c0(void);
extern void AllocSlotPushTripleGlobals(void);
extern void MStackPop4Rewrite(void);
extern void Push70CallScaleArith(void);
extern void StreamChainStringInstall(void);
extern void MStackFrameCdeclDouble(void);
extern void ChainTableWalkStore(void);
extern void Push16Call(void);
extern void DispatcherComplex260_00407030(void);
extern void ScaledLoadCmpStoreXfm(void);
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

extern s32 g_dlNalt1;
extern s32 g_dlNalt2;
extern s32 g_dlNalt3;
extern s32 g_dlNalt4;
extern unsigned int g_counter_0053a51c;
extern unsigned int g_rangeBase;
extern unsigned char g_dispatchSave623_004dfd48;
extern void TablePushAccumTailJmp_00429e30(void);
extern unsigned int g_dispatchSave658_004d5308;
extern unsigned int g_dispatchSave659_004d530c;
extern unsigned int g_dispatchSave656_004d5300;
extern unsigned int g_dispatchSave657_004d5304;
extern unsigned int g_particleEmitterNode;
extern unsigned int g_pendingMatchAudio2_0053a7a8;
extern void MStackPush8(void);
extern void TwinLoopSlotFinder_00429a40(void);
extern void *AllocNode(void);
extern void CopyGlobal(void);
extern void PendingMatch_00429ef0(void);
extern void MStackPushDispatchBitGate(void);
extern void MStackPush4LLWalkPop4(void);
extern void InstallSelfDispatch_00407620(void);
extern void MStackCall_00406390(void);
extern void MStackPop8(void);

/* @addr 0x00429b70 (691b game) */
void ScenePostInitSequencer_00429b70(void) {
    __asm {
        call     MStackPush8
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_9e22
        call     TwinLoopSlotFinder_00429a40
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_9e22
        mov      eax, dword ptr [g_cj_00542058]
        mov      eax, dword ptr [eax*4 + 0x3c]
        test     eax, eax
        mov      dword ptr [g_pendingNodeType], eax
        je       short L_9bf5
        mov      dword ptr [g_eventQueueNotMask], 1
        mov      dword ptr [g_eventQueueWorkType], 0x10
        call     AllocNode
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_9e22
        mov      dword ptr [g_eventQueueNotMask], 2
        mov      dword ptr [g_eventQueueWorkType], 0x10
        call     AllocNode
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_9e22
    L_9bf5:
        mov      ecx, dword ptr [g_cj_00542058]
        mov      edx, dword ptr [ecx*4 + 0x18]
        mov      dword ptr [g_walkCallback], edx
        call     CopyGlobal
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_9e22
        mov      eax, dword ptr [g_cj_00542058]
        mov      ecx, dword ptr [eax*4 + 0x1c]
        mov      dword ptr [g_walkCallback], ecx
        mov      dword ptr [g_dispatchSave658_004d5308], ecx
        mov      ecx, dword ptr [eax*4 + 0x20]
        mov      dword ptr [g_walkCallback], ecx
        mov      dword ptr [g_dispatchSave659_004d530c], ecx
        mov      ecx, dword ptr [eax*4 + 0x24]
        mov      dword ptr [g_walkCallback], ecx
        mov      dword ptr [g_dispatchSave656_004d5300], ecx
        mov      eax, dword ptr [eax*4 + 0x28]
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [g_dispatchSave657_004d5304], eax
        call     PendingMatch_00429ef0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_9e22
        mov      eax, dword ptr [g_particleEmitterNode]
        mov      ecx, dword ptr [g_cj_00542058]
        mov      dword ptr [g_scaledInit_00542044], eax
        mov      ecx, dword ptr [ecx*4 + 0x2c]
        mov      dword ptr [g_walkCallback], ecx
        mov      dword ptr [eax*4 + 0x54], ecx
        mov      edx, dword ptr [g_cj_00542058]
        mov      ecx, dword ptr [g_scaledInit_00542044]
        mov      eax, dword ptr [edx*4 + 0x30]
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x58], eax
        mov      edx, dword ptr [g_cj_00542058]
        mov      ecx, dword ptr [g_scaledInit_00542044]
        mov      eax, dword ptr [edx*4 + 0x34]
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x5c], eax
        mov      edx, dword ptr [g_cj_00542058]
        mov      ecx, dword ptr [g_scaledInit_00542044]
        mov      eax, dword ptr [edx*4 + 0x38]
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x3c], eax
        mov      edx, dword ptr [g_cj_00542058]
        mov      eax, dword ptr [edx*4 + 0xc]
        mov      dword ptr [g_xformEntityIdx], eax
        call     MStackPushDispatchBitGate
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_9e22
        mov      eax, dword ptr [g_cj_0054205c]
        mov      dword ptr [g_pendingMatchAudio2_0053a7a8], eax
        mov      dword ptr [eax*4 + 0x30], 0xb
        mov      eax, dword ptr [g_particleEmitterNode]
        mov      ecx, dword ptr [g_cj_0054205c]
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x3c], eax
        mov      edx, dword ptr [g_cj_00542058]
        mov      eax, dword ptr [edx*4 + 0x14]
        test     eax, eax
        mov      dword ptr [g_walkCallback], eax
        je       short L_9d79
        mov      dword ptr [g_xformEntityIdx], eax
        call     MStackPush4LLWalkPop4
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_9e22
    L_9d79:
        mov      eax, dword ptr [g_cj_00542058]
        mov      eax, dword ptr [eax*4 + 0x10]
        test     eax, eax
        mov      dword ptr [g_walkCallback], eax
        je       short L_9dc3
        mov      edx, dword ptr [g_cj_0054205c]
        mov      dword ptr [g_xformEntityIdx], eax
        mov      ecx, dword ptr [eax*4]
        sar      ecx, 2
        mov      dword ptr [g_xformEntityIdx], ecx
        mov      eax, dword ptr [edx*4 + 0x18]
        mov      dword ptr [g_scaledInit_00542044], eax
        call     InstallSelfDispatch_00407620
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_9e22
    L_9dc3:
        mov      ecx, dword ptr [g_cj_0054205c]
        mov      dword ptr [g_scaledInit_00542044], ecx
        call     MStackCall_00406390
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_9e22
        mov      edx, dword ptr [g_cj_00542058]
        mov      eax, dword ptr [edx*4 + 8]
        test     eax, eax
        mov      dword ptr [g_walkCallback], eax
        je       short L_9df5
        call     eax
    L_9df5:
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_9e22
        mov      eax, dword ptr [g_cj_0054205c]
        mov      dword ptr [g_walkCallback], eax
        call     MStackPop8
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_9e22
        mov      ecx, dword ptr [g_walkCallback]
        mov      dword ptr [g_cj_0054205c], ecx
    L_9e22:
        }
}
