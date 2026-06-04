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

extern void CallPauseConstStoreJmp_Push80SetWalkNegDualCallPop_then_InstallSelfWaitCmp(void);
extern void CallPauseTestByteJmpCalls(void);
extern void EntryThenDispatcherPair(void);
extern void ProneFsmCluster(void);
extern void InstallSelfPacked0x2005(void);
extern void JumpTableDispatch(void);

/* @addr 0x00435df0 (302b game) - 3-block install-self + threshold cascade + masked dispatch.
 *   Block A (0..0x83): load state at [base*4+0x84]; clear state. If state!=0 jmp Wrapper_CmpDualPatchScaledRangeJmp_004e4990.
 *     Else: g_currentNodeFlags=0x5cccc; g_eventQueueChild=0x3c; install-self at entry+0x01000000.
 *     state=1; call CallPauseConstStoreJmp; pause=1; pop edi; ret.
 *   Block B (+0xa0): call Cmp2CallDirtyCall; if !=0 ret. Cascade on g_fightStateProgress:
 *     <0x10000 jmp CallPauseTestByteJmpCalls; <0x20000 jmp EntryThenDispatcherPair;
 *     <0x40000 jmp ProneFsmCluster; else jmp InstallSelfPacked0x2005.
 *   Block C (+0xe0): g_scaledInit=[baseSel*4+0x38]; g_eventQueueCurrent=[chain+0x40];
 *     and 0x200 -> g_xformScratch94. If nonzero jmp PrefixThunkInstallSelf3State.
 *     Else: g_walkCallback &= 0xff; push 0x004e4668; call JumpTableDispatch; pop; ret.
 */
extern void PrefixThunkInstallSelf3State(void);
extern void Wrapper_CmpDualPatchScaledRangeJmp_004e4990(void);

__declspec(naked) void TripleBlockInstallThresholdMasked(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel]
        xor     edx, edx
        shl     eax, 2
        mov     ecx, dword ptr [eax + 0x84]
        mov     dword ptr [eax + 0x84], edx
        cmp     ecx, edx
        _emit   74h
        _emit   05h
        jmp     Wrapper_CmpDualPatchScaledRangeJmp_004e4990
        mov     dword ptr [g_currentNodeFlags], 0x5cccc
        mov     dword ptr [g_eventQueueChild], 0x3c
        mov     dword ptr [eax + 8], offset TripleBlockInstallThresholdMasked
        mov     ecx, dword ptr [g_baseSel]
        push    edi
        mov     edi, offset TripleBlockInstallThresholdMasked
        mov     dword ptr [ecx*4 + 0x84], 1
        mov     ecx, dword ptr [eax + 4]
        add     edi, 0x01000000
        mov     dword ptr [g_currentNodeIdx], ecx
        mov     dword ptr [ecx*4 + 0], edi
        mov     ecx, dword ptr [g_currentNodeIdx]
        inc     ecx
        mov     dword ptr [g_currentNodeIdx], ecx
        mov     dword ptr [eax + 4], ecx
        mov     eax, dword ptr [g_baseSel]
        mov     dword ptr [eax*4 + 0x84], edx
        call    CallPauseConstStoreJmp_Push80SetWalkNegDualCallPop_then_InstallSelfWaitCmp
        mov     dword ptr [g_framePauseFlag], 1
        pop     edi
        ret
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
        _emit   90h
        call    Cmp2CallDirtyCall
        test    eax, eax
        _emit   75h
        _emit   33h
        mov     eax, dword ptr [g_fightStateProgress]
        cmp     eax, 0x10000
        mov     dword ptr [g_walkCallback], eax
        _emit   7dh
        _emit   05h
        jmp     CallPauseTestByteJmpCalls
        cmp     eax, 0x20000
        _emit   7dh
        _emit   05h
        jmp     EntryThenDispatcherPair
        cmp     eax, 0x40000
        _emit   7dh
        _emit   05h
        jmp     ProneFsmCluster
        jmp     InstallSelfPacked0x2005
        ret
        _emit   90h
        _emit   90h
        _emit   90h
        mov     eax, dword ptr [g_baseSel]
        mov     eax, dword ptr [eax*4 + 0x38]
        mov     dword ptr [g_currentNodeIdx], eax
        mov     eax, dword ptr [eax*4 + 0x40]
        mov     dword ptr [g_eventQueueCurrent], eax
        and     eax, 0x200
        mov     dword ptr [g_xformScratch94], eax
        _emit   74h
        _emit   05h
        jmp     PrefixThunkInstallSelf3State
        mov     edx, dword ptr [g_walkCallback]
        push    0x004e4668
        and     edx, 0xff
        mov     dword ptr [g_walkCallback], edx
        call    JumpTableDispatch
        add     esp, 4
        ret
    }
}
