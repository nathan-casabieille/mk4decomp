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

__declspec(naked) void CrtWoutputFormatInteger(void)
{
    __asm {
        _emit    0x8b
        _emit    0x44
        _emit    0x24
        _emit    0x34
        _emit    0x85
        _emit    0xc0
        _emit    0x0f
        _emit    0x85
        _emit    0x0e
        _emit    0x01
        _emit    0x00
        _emit    0x00
        _emit    0x8b
        _emit    0x5c
        _emit    0x24
        _emit    0x10
        _emit    0xf6
        _emit    0xc3
        _emit    0x40
        _emit    0x74
        _emit    0x2a
        _emit    0xf6
        _emit    0xc7
        _emit    0x01
        _emit    0x74
        _emit    0x07
        _emit    0xc6
        _emit    0x44
        _emit    0x24
        _emit    0x22
        _emit    0x2d
        _emit    0xeb
        _emit    0x16
        _emit    0xf6
        _emit    0xc3
        _emit    0x01
        _emit    0x74
        _emit    0x07
        _emit    0xc6
        _emit    0x44
        _emit    0x24
        _emit    0x22
        _emit    0x2b
        _emit    0xeb
        _emit    0x0a
        _emit    0xf6
        _emit    0xc3
        _emit    0x02
        _emit    0x74
        _emit    0x0d
        _emit    0xc6
        _emit    0x44
        _emit    0x24
        _emit    0x22
        _emit    0x20
        _emit    0xc7
        _emit    0x44
        _emit    0x24
        _emit    0x24
        _emit    0x01
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x8b
        _emit    0x7c
        _emit    0x24
        _emit    0x28
        _emit    0x8b
        _emit    0x4c
        _emit    0x24
        _emit    0x24
        _emit    0x2b
        _emit    0xfd
        _emit    0x2b
        _emit    0xf9
        _emit    0xf6
        _emit    0xc3
        _emit    0x0c
        _emit    0x75
        _emit    0x1a
        _emit    0x8b
        _emit    0xb4
        _emit    0x24
        _emit    0x60
        _emit    0x02
        _emit    0x00
        _emit    0x00
        _emit    0x8d
        _emit    0x44
        _emit    0x24
        _emit    0x1c
        _emit    0x50
        _emit    0x56
        _emit    0x57
        _emit    0x6a
        _emit    0x20
        _emit    0xe8
        _emit    0x5b
        _emit    0x02
        _emit    0x00
        _emit    0x00
        _emit    0x83
        _emit    0xc4
        _emit    0x10
        _emit    0xeb
        _emit    0x07
        _emit    0x8b
        _emit    0xb4
        _emit    0x24
        _emit    0x60
        _emit    0x02
        _emit    0x00
        _emit    0x00
        _emit    0x8b
        _emit    0x54
        _emit    0x24
        _emit    0x24
        _emit    0x8d
        _emit    0x4c
        _emit    0x24
        _emit    0x1c
        _emit    0x51
        _emit    0x56
        _emit    0x8d
        _emit    0x44
        _emit    0x24
        _emit    0x2a
        _emit    0x52
        _emit    0x50
        _emit    0xe8
        _emit    0x7a
        _emit    0x02
        _emit    0x00
        _emit    0x00
        _emit    0x83
        _emit    0xc4
        _emit    0x10
        _emit    0xf6
        _emit    0xc3
        _emit    0x08
        _emit    0x74
        _emit    0x16
        _emit    0xf6
        _emit    0xc3
        _emit    0x04
        _emit    0x75
        _emit    0x11
        _emit    0x8d
        _emit    0x4c
        _emit    0x24
        _emit    0x1c
        _emit    0x51
        _emit    0x56
        _emit    0x57
        _emit    0x6a
        _emit    0x30
        _emit    0xe8
        _emit    0x1f
        _emit    0x02
        _emit    0x00
        _emit    0x00
        _emit    0x83
        _emit    0xc4
        _emit    0x10
        _emit    0x8b
        _emit    0x44
        _emit    0x24
        _emit    0x2c
        _emit    0x85
        _emit    0xc0
        _emit    0x0f
        _emit    0x84
        _emit    0x96
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x85
        _emit    0xed
        _emit    0x0f
        _emit    0x8e
        _emit    0x8e
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x8b
        _emit    0x74
        _emit    0x24
        _emit    0x14
        _emit    0x8d
        _emit    0x5d
        _emit    0xff
        _emit    0x66
        _emit    0x8b
        _emit    0x06
        _emit    0x8d
        _emit    0x54
        _emit    0x24
        _emit    0x48
        _emit    0x50
        _emit    0x52
        _emit    0x83
        _emit    0xc6
        _emit    0x02
        _emit    0xe8
        _emit    0xd0
        _emit    0x41
        _emit    0x00
        _emit    0x00
        _emit    0x83
        _emit    0xc4
        _emit    0x08
        _emit    0x85
        _emit    0xc0
        _emit    0x7e
        _emit    0x22
        _emit    0x8b
        _emit    0x94
        _emit    0x24
        _emit    0x60
        _emit    0x02
        _emit    0x00
        _emit    0x00
        _emit    0x8d
        _emit    0x4c
        _emit    0x24
        _emit    0x1c
        _emit    0x51
        _emit    0x52
        _emit    0x50
        _emit    0x8d
        _emit    0x44
        _emit    0x24
        _emit    0x54
        _emit    0x50
        _emit    0xe8
        _emit    0x11
        _emit    0x02
        _emit    0x00
        _emit    0x00
        _emit    0x83
        _emit    0xc4
        _emit    0x10
        _emit    0x8b
        _emit    0xcb
        _emit    0x4b
        _emit    0x85
        _emit    0xc9
        _emit    0x75
        _emit    0xc6
        _emit    0x8b
        _emit    0x5c
        _emit    0x24
        _emit    0x10
        _emit    0xf6
        _emit    0xc3
        _emit    0x04
        _emit    0x74
        _emit    0x18
        _emit    0x8b
        _emit    0x94
        _emit    0x24
        _emit    0x60
        _emit    0x02
        _emit    0x00
        _emit    0x00
        _emit    0x8d
        _emit    0x4c
        _emit    0x24
        _emit    0x1c
        _emit    0x51
        _emit    0x52
        _emit    0x57
        _emit    0x6a
        _emit    0x20
        _emit    0xe8
        _emit    0xa9
        _emit    0x01
        _emit    0x00
        _emit    0x00
        _emit    0x83
        _emit    0xc4
        _emit    0x10
        _emit    0x8b
        _emit    0xbc
        _emit    0x24
        _emit    0x64
        _emit    0x02
        _emit    0x00
        _emit    0x00
        _emit    0x8a
        _emit    0x1f
        _emit    0x47
        _emit    0x84
        _emit    0xdb
        _emit    0x88
        _emit    0x5c
        _emit    0x24
        _emit    0x40
        _emit    0x89
        _emit    0xbc
        _emit    0x24
        _emit    0x64
        _emit    0x02
        _emit    0x00
        _emit    0x00
        _emit    0x0f
        _emit    0x85
        _emit    0xde
        _emit    0xf7
        _emit    0xff
        _emit    0xff
        _emit    0x8b
        _emit    0x44
        _emit    0x24
        _emit    0x1c
        _emit    0x5f
        _emit    0x5e
        _emit    0x5d
        _emit    0x5b
        _emit    0x81
        _emit    0xc4
        _emit    0x4c
        _emit    0x02
        _emit    0x00
        _emit    0x00
        _emit    0xc3
        _emit    0x8b
        _emit    0x44
        _emit    0x24
        _emit    0x14
        _emit    0x8d
        _emit    0x54
        _emit    0x24
        _emit    0x1c
        _emit    0x52
        _emit    0x56
        _emit    0x55
        _emit    0x50
        _emit    0xe8
        _emit    0xa9
        _emit    0x01
        _emit    0x00
        _emit    0x00
        _emit    0x83
        _emit    0xc4
        _emit    0x10
        _emit    0xeb
        _emit    0xa1
        _emit    0x20
        _emit    0x7b
        _emit    0x4c
        _emit    0x00
        _emit    0xa4
        _emit    0x79
        _emit    0x4c
        _emit    0x00
        _emit    0xc9
        _emit    0x79
        _emit    0x4c
        _emit    0x00
        _emit    0x32
        _emit    0x7a
        _emit    0x4c
        _emit    0x00
        _emit    0x7c
        _emit    0x7a
        _emit    0x4c
        _emit    0x00
        _emit    0x85
        _emit    0x7a
        _emit    0x4c
        _emit    0x00
        _emit    0xca
        _emit    0x7a
        _emit    0x4c
        _emit    0x00
        _emit    0x9a
        _emit    0x7b
        _emit    0x4c
        _emit    0x00
        _emit    0x05
        _emit    0x7a
        _emit    0x4c
        _emit    0x00
        _emit    0x14
        _emit    0x7a
        _emit    0x4c
        _emit    0x00
        _emit    0xf6
        _emit    0x79
        _emit    0x4c
        _emit    0x00
        _emit    0xe7
        _emit    0x79
        _emit    0x4c
        _emit    0x00
        _emit    0x23
        _emit    0x7a
        _emit    0x4c
        _emit    0x00
        _emit    0x5a
        _emit    0x81
        _emit    0x4c
        _emit    0x00
        _emit    0x00
        _emit    0x05
        _emit    0x05
        _emit    0x01
        _emit    0x05
        _emit    0x05
        _emit    0x05
        _emit    0x05
        _emit    0x05
        _emit    0x05
        _emit    0x05
        _emit    0x02
        _emit    0x05
        _emit    0x03
        _emit    0x05
        _emit    0x05
        _emit    0x04
        _emit    0x8d
        _emit    0x49
        _emit    0x00
        _emit    0xf7
        _emit    0x7a
        _emit    0x4c
        _emit    0x00
        _emit    0x7b
        _emit    0x7b
        _emit    0x4c
        _emit    0x00
        _emit    0xe8
        _emit    0x7a
        _emit    0x4c
        _emit    0x00
        _emit    0x8a
        _emit    0x7b
        _emit    0x4c
        _emit    0x00
        _emit    0x5a
        _emit    0x81
        _emit    0x4c
        _emit    0x00
        _emit    0x00
        _emit    0x04
        _emit    0x04
        _emit    0x04
        _emit    0x04
        _emit    0x04
        _emit    0x04
        _emit    0x04
        _emit    0x04
        _emit    0x04
        _emit    0x04
        _emit    0x04
        _emit    0x04
        _emit    0x04
        _emit    0x04
        _emit    0x04
        _emit    0x04
        _emit    0x04
        _emit    0x04
        _emit    0x04
        _emit    0x04
        _emit    0x04
        _emit    0x04
        _emit    0x04
        _emit    0x04
        _emit    0x04
        _emit    0x04
        _emit    0x04
        _emit    0x04
        _emit    0x04
        _emit    0x04
        _emit    0x01
        _emit    0x04
        _emit    0x04
        _emit    0x04
        _emit    0x02
        _emit    0x04
        _emit    0x04
        _emit    0x04
        _emit    0x04
        _emit    0x04
        _emit    0x04
        _emit    0x04
        _emit    0x04
        _emit    0x04
        _emit    0x04
        _emit    0x03
        _emit    0x90
        _emit    0xb8
        _emit    0x7b
        _emit    0x4c
        _emit    0x00
        _emit    0x87
        _emit    0x7d
        _emit    0x4c
        _emit    0x00
        _emit    0x87
        _emit    0x7d
        _emit    0x4c
        _emit    0x00
        _emit    0x9c
        _emit    0x7c
        _emit    0x4c
        _emit    0x00
        _emit    0x90
        _emit    0x7e
        _emit    0x4c
        _emit    0x00
        _emit    0x33
        _emit    0x7c
        _emit    0x4c
        _emit    0x00
        _emit    0xca
        _emit    0x7b
        _emit    0x4c
        _emit    0x00
        _emit    0x6a
        _emit    0x7e
        _emit    0x4c
        _emit    0x00
        _emit    0x92
        _emit    0x7d
        _emit    0x4c
        _emit    0x00
        _emit    0x6a
        _emit    0x7e
        _emit    0x4c
        _emit    0x00
        _emit    0x46
        _emit    0x7d
        _emit    0x4c
        _emit    0x00
        _emit    0xcc
        _emit    0x7e
        _emit    0x4c
        _emit    0x00
        _emit    0x88
        _emit    0x7e
        _emit    0x4c
        _emit    0x00
        _emit    0xae
        _emit    0x7c
        _emit    0x4c
        _emit    0x00
        _emit    0x7e
        _emit    0x7e
        _emit    0x4c
        _emit    0x00
        _emit    0x9a
        _emit    0x7e
        _emit    0x4c
        _emit    0x00
        _emit    0x40
        _emit    0x80
        _emit    0x4c
        _emit    0x00
        _emit    0x00
        _emit    0x10
        _emit    0x01
        _emit    0x10
        _emit    0x02
        _emit    0x10
        _emit    0x10
        _emit    0x10
        _emit    0x10
        _emit    0x10
        _emit    0x10
        _emit    0x10
        _emit    0x10
        _emit    0x10
        _emit    0x10
        _emit    0x10
        _emit    0x03
        _emit    0x10
        _emit    0x10
        _emit    0x10
        _emit    0x10
        _emit    0x04
        _emit    0x10
        _emit    0x05
        _emit    0x10
        _emit    0x10
        _emit    0x10
        _emit    0x10
        _emit    0x10
        _emit    0x10
        _emit    0x10
        _emit    0x10
        _emit    0x06
        _emit    0x07
        _emit    0x08
        _emit    0x08
        _emit    0x08
        _emit    0x10
        _emit    0x09
        _emit    0x10
        _emit    0x10
        _emit    0x10
        _emit    0x10
        _emit    0x0a
        _emit    0x0b
        _emit    0x0c
        _emit    0x10
        _emit    0x10
        _emit    0x0d
        _emit    0x10
        _emit    0x0e
        _emit    0x10
        _emit    0x10
        _emit    0x0f
    }
}
