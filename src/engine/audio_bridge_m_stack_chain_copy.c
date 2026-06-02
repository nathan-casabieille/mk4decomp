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

/* @addr 0x00440730 (324b game) - audio bridge: rescale + bit0 gate + mstack-push 3 + scaledInit copy. */
extern unsigned int g_audioBridgeSlot_0052d718;
extern unsigned int g_audioBridgeSlot3_0052d71c;
extern unsigned int g_audioBridgeSlot2_0052d720;
extern unsigned int g_audioBridgeBase_0052d740;
extern unsigned int g_dispatchSave107_0052d744;
extern unsigned int g_dispatchSave106_0052d748;
extern void AudioVolumeRescale(void);
extern void DoubleStackPushAndJmp7d(void);

extern unsigned int g_matrixStack_arr;

void AudioBridgeMStackChainCopy(void) {
    __asm {
        call    AudioVolumeRescale
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   31h
        _emit   01h
        _emit   00h
        _emit   00h
        test    byte ptr [g_xformDirtyFlags], 1
        _emit   0fh
        _emit   84h
        _emit   24h
        _emit   01h
        _emit   00h
        _emit   00h
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_scaledInit_00542044]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     [eax*4 + g_matrixStack_arr], ecx
        mov     eax, dword ptr [g_matrixStackTop]
        mov     edx, dword ptr [g_pendingNodeType]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     [eax*4 + g_matrixStack_arr], edx
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_eventQueueIdx]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     edx, offset g_audioBridgeSlot_0052d718
        mov     [eax*4 + g_matrixStack_arr], ecx
        mov     eax, dword ptr [g_scaledInit_00542044]
        shr     edx, 2
        mov     ecx, dword ptr [eax*4 + 0x6c]
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [g_audioBridgeSlot_0052d718], ecx
        mov     ecx, dword ptr [eax*4 + 0x70]
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [g_audioBridgeSlot3_0052d71c], ecx
        mov     ecx, dword ptr [eax*4 + 0x74]
        mov     dword ptr [g_pendingNodeType], edx
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [g_audioBridgeSlot2_0052d720], ecx
        mov     ecx, dword ptr [eax*4 + 0x54]
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [g_audioBridgeBase_0052d740], ecx
        mov     ecx, dword ptr [eax*4 + 0x58]
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [g_dispatchSave107_0052d744], ecx
        mov     eax, dword ptr [eax*4 + 0x5c]
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [g_dispatchSave106_0052d748], eax
        mov     eax, offset g_audioBridgeBase_0052d740
        shr     eax, 2
        mov     dword ptr [g_eventQueueIdx], eax
        call    DoubleStackPushAndJmp7d
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   3eh
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, [eax*4 + g_matrixStack_arr]
        dec     eax
        mov     dword ptr [g_eventQueueIdx], ecx
        mov     dword ptr [g_matrixStackTop], eax
        mov     edx, [eax*4 + g_matrixStack_arr]
        dec     eax
        mov     dword ptr [g_pendingNodeType], edx
        mov     dword ptr [g_matrixStackTop], eax
        mov     ecx, [eax*4 + g_matrixStack_arr]
        dec     eax
        mov     dword ptr [g_scaledInit_00542044], ecx
        mov     dword ptr [g_matrixStackTop], eax
        }
}

