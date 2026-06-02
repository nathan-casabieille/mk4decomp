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

__declspec(naked) void FormatMenuItemsAndDraw(void)
{
    __asm {
        _emit    0xa1
        _emit    0xd8
        _emit    0x52
        _emit    0x4f
        _emit    0x00
        _emit    0x85
        _emit    0xc0
        _emit    0x0f
        _emit    0x84
        _emit    0x81
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0xbe
        _emit    0xd8
        _emit    0x52
        _emit    0x4f
        _emit    0x00
        _emit    0x0f
        _emit    0xbf
        _emit    0x46
        _emit    0x04
        _emit    0x83
        _emit    0xc0
        _emit    0xc8
        _emit    0x83
        _emit    0xf8
        _emit    0x03
        _emit    0x77
        _emit    0x66
        _emit    0xff
        _emit    0x24
        _emit    0x85
        _emit    0xe0
        _emit    0x7d
        _emit    0x4b
        _emit    0x00
        _emit    0xa1
        _emit    0x90
        _emit    0x3a
        _emit    0x54
        _emit    0x00
        _emit    0x50
        _emit    0x68
        _emit    0x88
        _emit    0x61
        _emit    0x4f
        _emit    0x00
        _emit    0xeb
        _emit    0x37
        _emit    0xa1
        _emit    0x8c
        _emit    0x3a
        _emit    0x54
        _emit    0x00
        _emit    0x85
        _emit    0xc0
        _emit    0xb8
        _emit    0xd8
        _emit    0x42
        _emit    0x4f
        _emit    0x00
        _emit    0x75
        _emit    0x23
        _emit    0xeb
        _emit    0x1c
        _emit    0x8b
        _emit    0x0d
        _emit    0x88
        _emit    0x3a
        _emit    0x54
        _emit    0x00
        _emit    0x51
        _emit    0x68
        _emit    0x88
        _emit    0x61
        _emit    0x4f
        _emit    0x00
        _emit    0xeb
        _emit    0x19
        _emit    0xa1
        _emit    0x84
        _emit    0x3a
        _emit    0x54
        _emit    0x00
        _emit    0x85
        _emit    0xc0
        _emit    0xb8
        _emit    0xd8
        _emit    0x42
        _emit    0x4f
        _emit    0x00
        _emit    0x75
        _emit    0x05
        _emit    0xb8
        _emit    0xdc
        _emit    0x42
        _emit    0x4f
        _emit    0x00
        _emit    0x50
        _emit    0x68
        _emit    0x38
        _emit    0x43
        _emit    0x4f
        _emit    0x00
        _emit    0x68
        _emit    0xc8
        _emit    0x41
        _emit    0xab
        _emit    0x00
        _emit    0xe8
        _emit    0x2d
        _emit    0xd8
        _emit    0x00
        _emit    0x00
        _emit    0x83
        _emit    0xc4
        _emit    0x0c
        _emit    0x68
        _emit    0xc8
        _emit    0x41
        _emit    0xab
        _emit    0x00
        _emit    0x56
        _emit    0xe8
        _emit    0xff
        _emit    0xf3
        _emit    0xff
        _emit    0xff
        _emit    0x83
        _emit    0xc4
        _emit    0x08
        _emit    0x8b
        _emit    0x46
        _emit    0x08
        _emit    0x83
        _emit    0xc6
        _emit    0x08
        _emit    0x85
        _emit    0xc0
        _emit    0x75
        _emit    0x84
        _emit    0x8b
        _emit    0x15
        _emit    0xe4
        _emit    0x42
        _emit    0xab
        _emit    0x00
        _emit    0x52
        _emit    0x68
        _emit    0xd8
        _emit    0x52
        _emit    0x4f
        _emit    0x00
        _emit    0xe8
        _emit    0x41
        _emit    0xe8
        _emit    0xff
        _emit    0xff
        _emit    0xa1
        _emit    0x54
        _emit    0x43
        _emit    0xab
        _emit    0x00
        _emit    0x83
        _emit    0xc4
        _emit    0x08
        _emit    0x5e
        _emit    0x5b
        _emit    0xc3
        _emit    0x8b
        _emit    0xff
        _emit    0xcd
        _emit    0x7c
        _emit    0x4b
        _emit    0x00
        _emit    0xfa
        _emit    0x7b
        _emit    0x4b
        _emit    0x00
        _emit    0x93
        _emit    0x7c
        _emit    0x4b
        _emit    0x00
        _emit    0x4a
        _emit    0x7c
        _emit    0x4b
        _emit    0x00
        _emit    0xb0
        _emit    0x7c
        _emit    0x4b
        _emit    0x00
        _emit    0xe0
        _emit    0x7c
        _emit    0x4b
        _emit    0x00
        _emit    0x00
        _emit    0x05
        _emit    0x05
        _emit    0x05
        _emit    0x05
        _emit    0x05
        _emit    0x05
        _emit    0x05
        _emit    0x05
        _emit    0x05
        _emit    0x05
        _emit    0x05
        _emit    0x05
        _emit    0x05
        _emit    0x05
        _emit    0x05
        _emit    0x05
        _emit    0x05
        _emit    0x05
        _emit    0x05
        _emit    0x05
        _emit    0x05
        _emit    0x05
        _emit    0x05
        _emit    0x05
        _emit    0x05
        _emit    0x05
        _emit    0x05
        _emit    0x05
        _emit    0x05
        _emit    0x05
        _emit    0x05
        _emit    0x05
        _emit    0x05
        _emit    0x05
        _emit    0x05
        _emit    0x05
        _emit    0x05
        _emit    0x05
        _emit    0x05
        _emit    0x05
        _emit    0x05
        _emit    0x05
        _emit    0x05
        _emit    0x05
        _emit    0x05
        _emit    0x05
        _emit    0x05
        _emit    0x05
        _emit    0x05
        _emit    0x05
        _emit    0x05
        _emit    0x05
        _emit    0x01
        _emit    0x02
        _emit    0x03
        _emit    0x04
        _emit    0x8d
        _emit    0x49
        _emit    0x00
        _emit    0x05
        _emit    0x7d
        _emit    0x4b
        _emit    0x00
        _emit    0x12
        _emit    0x7d
        _emit    0x4b
        _emit    0x00
        _emit    0x22
        _emit    0x7d
        _emit    0x4b
        _emit    0x00
        _emit    0x30
        _emit    0x7d
        _emit    0x4b
        _emit    0x00
    }
}
