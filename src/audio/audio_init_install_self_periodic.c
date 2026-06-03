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
 * AudioInitInstallSelfPeriodic - 216b audio 2-body install/periodic.
 *   Entry 0x004a0610: g_walkCallback=g_dlMode. If eax==0 OR g_state2_0053a354 != 0:
 *     tail-call CallSetPause; pop+ret. Else: chain=g_baseSel;
 *     g_state2_0053a354=1, g_state2_00537ea8=0, g_audioPeriodicSlot=0, g_audioInitPeriodic=4,
 *     g_walkCallback=0, chain[+0xc]=0; call RoundWinTransition; if !paused: pop+ret;
 *     else CallSetPause; pop+ret.
 *   Entry 0x004a0680 (body): chain = g_baseSel*4; saved=chain->state; chain->state=0.
 *     If was 0: countdown g_eventQueueEnd; if not yet 0: skip; else tail-jmp CallSetPause.
 *     Else: ecx=g_installSelfStride5; g_walkCallback=ecx; if 0: tail-jmp InstallSelfStride5.
 *     Else: install-self at body; chain->state=1; g_pendingNodeType=2; g_framePauseFlag=1; ret.
 */
extern unsigned int g_state2_0053a354;
extern u32 g_dlMode;
extern unsigned int g_audioInitPeriodic;
extern unsigned int g_state2_00537ea8;
extern unsigned int g_installSelfStride5;
extern unsigned int g_audioPeriodicSlot;
extern void CallSetPause(void);
extern void InstallSelfStride5(void);
extern void RoundWinTransition(void);

__declspec(naked) void AudioInitInstallSelfPeriodic(void)
{
    __asm
    {
        mov     eax, dword ptr [g_dlMode]
        push    esi
        xor     esi, esi
        mov     dword ptr [g_walkCallback], eax
        cmp     eax, esi
        je      short L_pause
        mov     eax, dword ptr [g_state2_0053a354]
        cmp     eax, esi
        mov     dword ptr [g_walkCallback], eax
        jne     short L_pause
        mov     eax, dword ptr [g_baseSel]
        mov     dword ptr [g_state2_0053a354], 1
        mov     dword ptr [g_state2_00537ea8], esi
        mov     dword ptr [g_audioPeriodicSlot], esi
        mov     dword ptr [g_audioInitPeriodic], 4
        mov     dword ptr [g_walkCallback], esi
        mov     dword ptr [eax*4 + 0xc], esi
        call    RoundWinTransition
        cmp     dword ptr [g_framePauseFlag], esi
        jne     short L_pop_ret
    L_pause:
        call    CallSetPause
    L_pop_ret:
        pop     esi
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
    L_body:
        mov     eax, dword ptr [g_baseSel]
        shl     eax, 2
        mov     ecx, dword ptr [eax + 0x84]
        mov     dword ptr [eax + 0x84], 0
        test    ecx, ecx
        jne     short L_checkRollover
        mov     ecx, dword ptr [g_eventQueueEnd]
        dec     ecx
        mov     dword ptr [g_eventQueueEnd], ecx
        jns     short L_checkRollover
        jmp     CallSetPause
    L_checkRollover:
        mov     ecx, dword ptr [g_installSelfStride5]
        test    ecx, ecx
        mov     dword ptr [g_walkCallback], ecx
        jne     short L_install
        jmp     InstallSelfStride5
    L_install:
        mov     ecx, 1
        mov     dword ptr [eax + 8], offset L_body
        mov     dword ptr [eax + 0x84], ecx
        mov     dword ptr [g_pendingNodeType], 2
        mov     dword ptr [g_framePauseFlag], ecx
        ret
    }
}
