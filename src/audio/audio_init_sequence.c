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
extern void CallPauseDirty1JmpDirty4StackPush_00483a80(void);
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

extern void ScaledArrStore_ScaledChainJmp_004298c0(void);
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
extern void Wrapper_ScaledChainPushCall_004ef858(void);
extern void Wrapper_ScaledChainPushCall_004ef8b0(void);
extern void Helper_DownloadSetup(void);
extern void MStackPush3CmpCall(void);
extern void Wrapper_IterLoad_0048fd30_004f12a0(void);
extern void FiveCallScaledChainTailJmp(void);
extern void SetJmp_StateDispatchYield_00438f50(void);
extern void SetJmp_StateDispatchYield_00438f60(void);
extern void GuardedDispatch_InstallSelfDualEsi(void);
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

/* @addr 0x004a41a0 (182b audio) - audio init sequence.
 *   g_byte_00542040 = 1; g_walkCallback = 0; call CopyGlobal; call BootInitGuardedCallChain.
 *   Copy chain: [0x541ec4] = [0x541ecc]; [0x541ec8] = [0x541ed0]; [0x537f48] = [0x53a790];
 *               [0x5380e0] = [0x537ea0]; [0x53a178] = [0x537edc]; [0x53a250] = [0x53a1cc];
 *               g_walkCallback = [0x53a51c].
 *   call TablePushAccumTailJmp; pause? -> end.
 *   call TestCmpZeroFour; pause? -> end.
 *   push 0x1000, 0x004202c0; call StoreTwoCall; add esp, 8.
 *   [0x543800] = -1; g_walkCallback = 0; [0x52aac4] = 0.
 */
extern unsigned int g_tickFlagF;
extern unsigned int g_audioInitState6;
extern unsigned int g_audioInitState5;
extern s32 g_dlNalt1;
extern s32 g_dlNalt2;
extern s32 g_dlNalt3;
extern unsigned int g_audioInitState4;
extern s32 g_dlNalt4;
extern unsigned int g_counter_0053a51c;
extern unsigned int g_audioInitState3;
extern s32 g_dlChar13;
extern s32 g_dlChar24;
extern unsigned int g_audioInitState2;
extern unsigned int g_audioInitState1;
extern unsigned int g_byte_00542040;
extern void BootInitGuardedCallChain(void);
extern void CopyGlobal(void);
extern void TablePushAccumTailJmp(void);
extern void TestCmpZeroFour(void);

void AudioInitSequence(void) {
    __asm {
        mov     byte ptr [g_byte_00542040], 1
        mov     dword ptr [g_walkCallback], 0
        call    CopyGlobal
        call    BootInitGuardedCallChain
        mov     eax, dword ptr [g_audioInitState2]
        mov     ecx, dword ptr [g_audioInitState1]
        mov     edx, dword ptr [g_audioInitState3]
        mov     dword ptr [g_dlChar13], eax
        mov     eax, dword ptr [g_audioInitState6]
        mov     dword ptr [g_dlChar24], ecx
        mov     ecx, dword ptr [g_audioInitState5]
        mov     dword ptr [g_dlNalt1], edx
        mov     edx, dword ptr [g_audioInitState4]
        mov     dword ptr [g_dlNalt2], eax
        mov     eax, dword ptr [g_counter_0053a51c]
        mov     dword ptr [g_dlNalt3], ecx
        mov     dword ptr [g_dlNalt4], edx
        mov     dword ptr [g_walkCallback], eax
        call    TablePushAccumTailJmp
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   3eh
        call    TestCmpZeroFour
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   30h
        push    0x1000
        push    0x004202c0
        call    StoreTwoCall
        add     esp, 8
        mov     dword ptr [g_gameMode], 0xffffffff
        mov     dword ptr [g_walkCallback], 0
        mov     dword ptr [g_tickFlagF], 0
        }
}

