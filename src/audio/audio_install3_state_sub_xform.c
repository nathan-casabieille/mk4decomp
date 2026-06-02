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

/*
 * AudioInstall3StateSubXform - 245b audio 3-state install-self.
 *   chain = g_baseSel<<2; saved=chain->state; chain->state=0.
 *   state 2+: ecx=g_fightGroupHead; eax=chain[+0x6c]-0x4000; g_walkCallback=eax; chain[+0x6c]=eax;
 *     if eax>0 jump installSelf; else call ScaledInitOrSelfPtrSetType14; pop+ret.
 *   state 1: eax=g_eventQueueEnd; g_walkCallback=eax; if 0 jump installSelf; else call
 *     InstallSelfChainAddSigned; pop+ret.
 *   state 0: chain[+0x54]=g_eventQueueWorkType; chain[+0x58]=g_walkCallback=0; g_currentNodeIdx=ecx;
 *     MStackPushComplexCallPop; if !paused: install-self at entry; chain->state=1;
 *     g_pendingNodeType=0x1c; pause=1. pop+ret.
 *   installSelf: install-self at entry; chain->state=2; g_pendingNodeType=1; pause=1; pop+ret.
 */
extern void InstallSelfChainAddSigned(void);
extern void MStackPushComplexCallPop_00406430(void);
extern void ScaledInitOrSelfPtrSetType14(void);

__declspec(naked) void AudioInstall3StateSubXform(void)
{
    __asm
    {
        mov     eax, dword ptr [g_baseSel]
        push    esi
        lea     esi, [eax*4]
        mov     eax, dword ptr [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], 0
        sub     eax, 0
        je      short L_a17_state0
        dec     eax
        je      short L_a17_state1
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     eax, dword ptr [ecx*4 + 0x6c]
        sub     eax, 0x4000
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x6c], eax
        mov     eax, dword ptr [g_walkCallback]
        test    eax, eax
        jg      short L_a17_installSelf
        call    ScaledInitOrSelfPtrSetType14
        pop     esi
        ret
    L_a17_state1:
        mov     eax, dword ptr [g_eventQueueEnd]
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        je      short L_a17_installSelf
        call    InstallSelfChainAddSigned
        pop     esi
        ret
    L_a17_installSelf:
        mov     eax, 1
        mov     dword ptr [esi + 8], offset AudioInstall3StateSubXform
        mov     dword ptr [esi + 0x84], 2
        mov     dword ptr [g_pendingNodeType], eax
        mov     dword ptr [g_framePauseFlag], eax
        pop     esi
        ret
    L_a17_state0:
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     edx, dword ptr [g_eventQueueWorkType]
        mov     dword ptr [ecx*4 + 0x54], edx
        mov     eax, dword ptr [g_fightGroupHead]
        mov     dword ptr [g_walkCallback], 0
        mov     dword ptr [eax*4 + 0x58], 0
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     dword ptr [g_currentNodeIdx], ecx
        call    MStackPushComplexCallPop_00406430
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_a17_s0_ret
        mov     eax, 1
        mov     dword ptr [esi + 8], offset AudioInstall3StateSubXform
        mov     dword ptr [esi + 0x84], eax
        mov     dword ptr [g_pendingNodeType], 0x1c
        mov     dword ptr [g_framePauseFlag], eax
    L_a17_s0_ret:
        pop     esi
        ret
    }
}
