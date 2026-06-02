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
extern void CopyJmp_0048ef90(void);
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
extern void Wrapper_ScaledChainPushCall_004ef858(void);
extern void Wrapper_ScaledChainPushCall_004ef8b0(void);
extern void Helper_DownloadSetup(void);
extern void MStackPush3CmpCall(void);
extern void Wrapper_IterLoad_0048fd30_004f12a0(void);
extern void FiveCallScaledChainTailJmp(void);
extern void SetJmp_StateDispatchYield_00438f50(void);
extern void SetJmp_StateDispatchYield_00438f60(void);
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

extern s32 g_installValidated;
extern u8 g_configBuffer[];
extern unsigned char g_dispatchSave632;
extern unsigned char g_dispatchSave631;
/* g_iat_RegCreateKeyExA/2010/2004 declared as unsigned int below */
extern void Config_SnapshotGlobals(void);
extern s32 ComputeConfigHash(void);
extern void DeobfuscateConfig(void);

/* @addr 0x004ad410 (138b) - if g_installValidated: setup install regs via 3 calls;
 *   open key (IAT@4d2000); if success: query (IAT@4d2010), close (IAT@4d2004);
 *   clear g_installValidated; ret.
 */
extern unsigned int g_iat_RegCreateKeyExA;
extern unsigned int g_iat_RegCloseKey;
extern unsigned int g_iat_RegSetValueExA;

void Config_SaveToRegistry(void) {
    __asm {
        sub     esp, 8
        mov     eax, dword ptr [g_installValidated]
        _emit   0c7h
        _emit   044h
        _emit   024h
        _emit   000h
        _emit   000h
        _emit   000h
        _emit   000h
        _emit   000h
        test    eax, eax
        _emit   74h
        _emit   72h
        call    Config_SnapshotGlobals
        call    ComputeConfigHash
        mov     dword ptr [g_configBuffer], eax
        call    DeobfuscateConfig
        lea     eax, [esp + 4]
        _emit   8dh
        _emit   4ch
        _emit   24h
        _emit   00h
        push    eax
        push    ecx
        push    0
        push    0x20006
        push    0
        push    0
        push    0
        push    offset g_dispatchSave632
        push    0x80000002
        call    dword ptr [g_iat_RegCreateKeyExA]
        _emit   8bh
        _emit   44h
        _emit   24h
        _emit   00h
        test    eax, eax
        _emit   74h
        _emit   2fh
        push    0x24c
        push    offset g_configBuffer
        push    3
        push    0
        push    offset g_dispatchSave631
        push    eax
        call    dword ptr [g_iat_RegSetValueExA]
        _emit   8bh
        _emit   54h
        _emit   24h
        _emit   00h
        push    edx
        call    dword ptr [g_iat_RegCloseKey]
        mov     dword ptr [g_installValidated], 0
        add     esp, 8
        }
}

