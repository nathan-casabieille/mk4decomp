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
extern unsigned int g_fightStateProgress;
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

/*
 * AudioFlagDispatchAggregator - 226b audio multi-bit-flag dispatcher.
 *   Six independent bit tests on g_byte_004d50d4/d8; for each set bit, push (channel<<16, &table)
 *   and call ShiftDownThreeAndAppend.
 *   Final aggregator: combine low nibble of g_byte_004d50d4 into a 4-bit value, shl 16; if nonzero,
 *   push (combined, &table) and call again. Ret.
 */
extern unsigned int g_byte_004d50d4;
extern unsigned int g_byte_004d50d8;
extern unsigned int g_audioFlagAggBase2;
extern void ShiftDownThreeAndAppend(void);

void AudioFlagDispatchAggregator(void) {
    __asm {
        test    byte ptr [g_byte_004d50d4], 0x10
        je      short L_skip0
        push    0x000b0000
        push    offset g_audioFlagAggBase2
        call    ShiftDownThreeAndAppend
        add     esp, 8
    L_skip0:
        test    byte ptr [g_byte_004d50d4], 0x40
        je      short L_skip1
        push    0x000c0000
        push    offset g_audioFlagAggBase2
        call    ShiftDownThreeAndAppend
        add     esp, 8
    L_skip1:
        test    byte ptr [g_byte_004d50d8], 0x01
        je      short L_skip2
        push    0x000d0000
        push    offset g_audioFlagAggBase2
        call    ShiftDownThreeAndAppend
        add     esp, 8
    L_skip2:
        test    byte ptr [g_byte_004d50d8], 0x02
        je      short L_skip3
        push    0x000e0000
        push    offset g_audioFlagAggBase2
        call    ShiftDownThreeAndAppend
        add     esp, 8
    L_skip3:
        test    byte ptr [g_byte_004d50d8], 0x04
        je      short L_skip4
        push    0x000f0000
        push    offset g_audioFlagAggBase2
        call    ShiftDownThreeAndAppend
        add     esp, 8
    L_skip4:
        test    byte ptr [g_byte_004d50d4], 0x20
        je      short L_skip5
        push    0x00100000
        push    offset g_audioFlagAggBase2
        call    ShiftDownThreeAndAppend
        add     esp, 8
    L_skip5:
        mov     cl, byte ptr [g_byte_004d50d4]
        xor     eax, eax
        test    cl, 1
        je      short L_bit1
        mov     eax, 1
    L_bit1:
        test    cl, 2
        je      short L_bit2
        add     eax, 2
    L_bit2:
        test    cl, 4
        je      short L_bit3
        add     eax, 4
    L_bit3:
        test    cl, 8
        je      short L_bit4
        add     eax, 8
    L_bit4:
        test    eax, eax
        je      short L_done
        shl     eax, 0x10
        push    eax
        push    offset g_audioFlagAggBase2
        call    ShiftDownThreeAndAppend
        add     esp, 8
    L_done:
        }
}

