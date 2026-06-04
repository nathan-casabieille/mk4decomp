/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_currentNodeIdx;
extern unsigned int g_baseSel;
extern unsigned int g_chainAccumCur;
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
extern unsigned int g_armedReloadA;
extern unsigned int g_armedReloadB;
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

extern void CmpRangeJmpStateInit(void);
extern void DualCallPauseDirtyJmp_00435f20(void);
extern void InstallSelfThreeStateDispatch(void);

/* @addr 0x00435f50 (209b game) - 4-block dual-Mul10Tail + thresholded state dispatcher.
 *   A: Mul10Tail pair on cj[+0x6c]/[+0x74]; if sum zero call CmpRangeJmpStateInit.
 *     Else threshold checks on g_fightStateProgress: <0x13333 jmp PrefixThunkInstallSelf3State, >0x28000 jmp GuardedSeq_PackedSelectLoad6_then_GuardedSeq,
 *     else jmp PrefixThunkInstallSelf3State.
 *   B/C (+0x80/+0x90): jmp DualCallPauseDirtyJmp_00435f20.
 *   D (+0xa0): call Cmp2CallDirtyCall; if nz ret; threshold dispatch state_00535ddc: <0x2b333 jmp Wrapper_CmpDualPatchScaledRangeJmp_004e4990,
 *     >0x14ccc jmp PoseFsm4StateInstall, else jmp InstallSelfThreeStateDispatch. ret.
 */
extern void GuardedSeq_PackedSelectLoad6_then_GuardedSeq(void);
extern void PoseFsm4StateInstall(void);
extern void PrefixThunkInstallSelf3State(void);
extern void Wrapper_CmpDualPatchScaledRangeJmp_004e4990(void);

__declspec(naked) void Mul10ThresholdQuad(void) {
    __asm {
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     eax, dword ptr [ecx*4 + 0x6c]
        mov     dword ptr [g_walkCallback], eax
        mov     ecx, dword ptr [ecx*4 + 0x74]
        push    eax
        push    eax
        mov     dword ptr [g_eventQueueCurrent], ecx
        call    Mul10Tail
        add     esp, 8
        mov     dword ptr [g_walkCallback], eax
        mov     eax, dword ptr [g_eventQueueCurrent]
        push    eax
        push    eax
        call    Mul10Tail
        mov     ecx, dword ptr [g_walkCallback]
        add     esp, 8
        add     eax, ecx
        mov     dword ptr [g_eventQueueCurrent], eax
        _emit   74h
        _emit   05h
        jmp     CmpRangeJmpStateInit
        mov     eax, dword ptr [g_fightStateProgress]
        cmp     eax, 0x00013333
        mov     dword ptr [g_walkCallback], eax
        _emit   7dh
        _emit   05h
        jmp     PrefixThunkInstallSelf3State
        cmp     eax, 0x00028000
        _emit   7eh
        _emit   05h
        jmp     GuardedSeq_PackedSelectLoad6_then_GuardedSeq
        jmp     PrefixThunkInstallSelf3State
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        jmp     DualCallPauseDirtyJmp_00435f20
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        jmp     DualCallPauseDirtyJmp_00435f20
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        call    Cmp2CallDirtyCall
        test    eax, eax
        _emit   75h
        _emit   27h
        mov     eax, dword ptr [g_fightStateProgress]
        cmp     eax, 0x0002b333
        mov     dword ptr [g_walkCallback], eax
        _emit   7eh
        _emit   05h
        jmp     Wrapper_CmpDualPatchScaledRangeJmp_004e4990
        cmp     eax, 0x00014ccc
        _emit   7dh
        _emit   05h
        jmp     PoseFsm4StateInstall
        jmp     InstallSelfThreeStateDispatch
        ret
    }
}
