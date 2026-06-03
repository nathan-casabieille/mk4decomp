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
 * DualBitFlagAudioChain - 175b audio dispatcher with two parallel bit-flag branches.
 *   Reads g_byte_004d50b4 as byte pair (al,ah).
 *   Branch 0 (al bit 0 OR ah bit 0): movsx slot from g_byteTab_004f3080[edx*4];
 *     if slot != -1 set chain->field_30 = slot and SetJmp; push 0x00160000;
 *     g_eventQueueChild = 0x708; call Helper_AudioStub_2960.
 *   Branch 1 (al bit 1 OR ah bit 1): same with g_byteTab_004f3080+1 and push 0xffea0000.
 */
extern unsigned int g_byteTab_004f3080;
extern unsigned int g_byte_004d50b4;
extern void Helper_AudioStub_2960(void);
extern void SetJmp_Push16Call_004a1ad0(void);

void DualBitFlagAudioChain(void) {
    __asm {
        mov     eax, dword ptr [g_byte_004d50b4]
        test    al, 1
        jne     short L_b0_enter
        test    ah, 1
        je      short L_b1_check
    L_b0_enter:
        mov     ecx, dword ptr [g_baseSel]
        mov     eax, dword ptr [ecx*4 + 0x30]
        mov     edx, eax
        shl     edx, 3
        sub     edx, eax
        movsx   eax, byte ptr [edx*4 + g_byteTab_004f3080]
        cmp     eax, -1
        mov     dword ptr [g_walkCallback], eax
        je      short L_b0_skip
        mov     dword ptr [ecx*4 + 0x30], eax
        call    SetJmp_Push16Call_004a1ad0
    L_b0_skip:
        push    0x00160000
        mov     dword ptr [g_eventQueueChild], 0x00000708
        call    Helper_AudioStub_2960
        mov     eax, dword ptr [g_byte_004d50b4]
        add     esp, 4
    L_b1_check:
        test    al, 2
        jne     short L_b1_enter
        test    ah, 2
        je      short L_ret
    L_b1_enter:
        mov     ecx, dword ptr [g_baseSel]
        mov     eax, dword ptr [ecx*4 + 0x30]
        mov     edx, eax
        shl     edx, 3
        sub     edx, eax
        movsx   eax, byte ptr [edx*4 + g_byteTab_004f3080 + 1]
        cmp     eax, -1
        mov     dword ptr [g_walkCallback], eax
        je      short L_b1_skip
        mov     dword ptr [ecx*4 + 0x30], eax
        call    SetJmp_Push16Call_004a1ad0
    L_b1_skip:
        push    0xffea0000
        mov     dword ptr [g_eventQueueChild], 0x00000708
        call    Helper_AudioStub_2960
        add     esp, 4
    L_ret:
        }
}

