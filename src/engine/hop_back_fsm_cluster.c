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

extern void ScaledLitLoadCall_ScaledChainCallPauseSetJmp_then_Wrapper_IterLoad_0048fd30_00480fe0(void);
extern void MoveSelectorCluster(void);
extern void HopBackFsmCluster(void);

/* @addr 0x0047a090 (300b game) - 3-state install-self with field-set + sibling-tail.
 *   state==0: call ScaledAndAldf; if pause ret.
 *     If g_xformScratch2088==1: tail-call MoveSelectorCluster; ret.
 *     Else: install-self at entry+0x01000000; call HopBackFsmCluster; pause=1; ret.
 *   state==1: g_walkCallback=0x5e; call ScaledLitLoadCall; if pause ret.
 *     Install-self at entry+0x02000000; jmp common chain-push tail.
 *   state>=2: g_walkCallback=0x51e; call ScaledLitLoadCall; if pause ret.
 *     [cj*4+0x4c]=0x51e; tail-call InstallSelf3StateDualChain; pop+ret.
 */
extern void InstallSelf3StateDualChain(void);
extern void ScaledAndAldf(void);

__declspec(naked) void InstallSelf3StateFieldSet(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel]
        push    esi
        lea     esi, [eax*4 + 0]
        mov     eax, dword ptr [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], 0
        _emit   83h
        _emit   0e8h
        _emit   00h
        _emit   0fh
        _emit   84h
        _emit   86h
        _emit   00h
        _emit   00h
        _emit   00h
        dec     eax
        _emit   74h
        _emit   3ah
        mov     dword ptr [g_walkCallback], 0x5f
        call    ScaledLitLoadCall_ScaledChainCallPauseSetJmp_then_Wrapper_IterLoad_0048fd30_00480fe0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   0e4h
        _emit   00h
        _emit   00h
        _emit   00h
        mov     ecx, dword ptr [g_cj_0054205c]
        mov     eax, 0x51e
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x4c], eax
        call    InstallSelf3StateDualChain
        pop     esi
        ret
        mov     dword ptr [g_walkCallback], 0x5e
        call    ScaledLitLoadCall_ScaledChainCallPauseSetJmp_then_Wrapper_IterLoad_0048fd30_00480fe0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   0aah
        _emit   00h
        _emit   00h
        _emit   00h
        mov     dword ptr [esi + 8], offset InstallSelf3StateFieldSet
        mov     edx, dword ptr [g_baseSel]
        mov     ecx, offset InstallSelf3StateFieldSet
        mov     dword ptr [edx*4 + 0x84], 2
        mov     eax, dword ptr [esi + 4]
        mov     dword ptr [g_currentNodeIdx], eax
        add     ecx, 0x02000000
        _emit   0ebh
        _emit   48h
        call    ScaledAndAldf
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   6fh
        cmp     dword ptr [g_xformScratch2088], 1
        _emit   75h
        _emit   07h
        call    MoveSelectorCluster
        pop     esi
        ret
        mov     dword ptr [esi + 8], offset InstallSelf3StateFieldSet
        mov     eax, dword ptr [g_baseSel]
        mov     ecx, offset InstallSelf3StateFieldSet
        mov     dword ptr [eax*4 + 0x84], 1
        mov     eax, dword ptr [esi + 4]
        mov     dword ptr [g_currentNodeIdx], eax
        add     ecx, 0x01000000
        mov     dword ptr [eax*4 + 0], ecx
        mov     eax, dword ptr [g_currentNodeIdx]
        inc     eax
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [esi + 4], eax
        mov     edx, dword ptr [g_baseSel]
        mov     dword ptr [edx*4 + 0x84], 0
        call    HopBackFsmCluster
        mov     dword ptr [g_framePauseFlag], 1
        pop     esi
        ret
    }
}
