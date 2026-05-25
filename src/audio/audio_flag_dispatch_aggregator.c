/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_state_004d57ac;
extern unsigned int g_scaledInit_00542044;
extern packed_ptr g_xformEntityIdx;
extern u32 g_eventQueueEnd;
extern unsigned int g_baseSel_00542060;
extern u32 g_eventQueueWorkType;
extern unsigned int g_acc_00542078;
extern unsigned int g_cj_0054205c;
extern u32 g_framePauseFlag;
extern unsigned int g_state_0053a718;
extern unsigned int g_eventQueueTotal;
extern unsigned int g_eventQueueCurrent;
extern unsigned int g_currentNodeFlags;
extern unsigned int g_xformDirtyFlags;
extern unsigned int g_xformScratch2088;
extern unsigned int g_state_00542094;
extern unsigned int g_table_00535ddc;
extern unsigned int g_active_00537e88;
extern unsigned int g_active_0053a408;
extern unsigned int g_state_00537f94;
extern unsigned int g_eventQueueChild;
extern u32 g_pendingNodeType;

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
extern unsigned int g_eventQueueNotMask;
extern unsigned int g_cj_00542058;
extern unsigned int g_data_0053a180;
extern unsigned int g_zero_00541fa4;
extern unsigned int g_zero_00541fa8;
extern unsigned int g_state_0053a7b0;
extern unsigned int g_data_0053a770;
extern unsigned int g_data_0053a46c;

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
extern unsigned int g_state_0053a3c0;
extern unsigned int g_state_00538158;
extern unsigned int g_data_00535cf8;
extern unsigned int g_cj_00542054;
extern unsigned int g_data_005437f0;
extern unsigned int g_data_00543598;
extern unsigned int g_data_0054358c;
extern unsigned int g_data_00535e70;
extern unsigned int g_data_00535e74;
extern unsigned int g_data_00535e78;
extern unsigned int g_data_00535e7c;

/*
 * AudioFlagDispatchAggregator_004aa430 - 226b audio multi-bit-flag dispatcher.
 *   Six independent bit tests on g_byte_004d50d4/d8; for each set bit, push (channel<<16, &table)
 *   and call ShiftDownThreeAndAppend.
 *   Final aggregator: combine low nibble of g_byte_004d50d4 into a 4-bit value, shl 16; if nonzero,
 *   push (combined, &table) and call again. Ret.
 */
extern unsigned int g_byte_004d50d4;
extern unsigned int g_byte_004d50d8;
extern unsigned int g_data_00543398;
extern void ShiftDownThreeAndAppend_004aa3f0(void);

void AudioFlagDispatchAggregator_004aa430(void) {
    __asm {
        test    byte ptr [g_byte_004d50d4], 0x10
        je      short L_skip0
        push    0x000b0000
        push    offset g_data_00543398
        call    ShiftDownThreeAndAppend_004aa3f0
        add     esp, 8
    L_skip0:
        test    byte ptr [g_byte_004d50d4], 0x40
        je      short L_skip1
        push    0x000c0000
        push    offset g_data_00543398
        call    ShiftDownThreeAndAppend_004aa3f0
        add     esp, 8
    L_skip1:
        test    byte ptr [g_byte_004d50d8], 0x01
        je      short L_skip2
        push    0x000d0000
        push    offset g_data_00543398
        call    ShiftDownThreeAndAppend_004aa3f0
        add     esp, 8
    L_skip2:
        test    byte ptr [g_byte_004d50d8], 0x02
        je      short L_skip3
        push    0x000e0000
        push    offset g_data_00543398
        call    ShiftDownThreeAndAppend_004aa3f0
        add     esp, 8
    L_skip3:
        test    byte ptr [g_byte_004d50d8], 0x04
        je      short L_skip4
        push    0x000f0000
        push    offset g_data_00543398
        call    ShiftDownThreeAndAppend_004aa3f0
        add     esp, 8
    L_skip4:
        test    byte ptr [g_byte_004d50d4], 0x20
        je      short L_skip5
        push    0x00100000
        push    offset g_data_00543398
        call    ShiftDownThreeAndAppend_004aa3f0
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
        push    offset g_data_00543398
        call    ShiftDownThreeAndAppend_004aa3f0
        add     esp, 8
    L_done:
        }
}

