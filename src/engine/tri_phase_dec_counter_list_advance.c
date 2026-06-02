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

extern void EntryThunkBodyStateMachine(void);
extern void EsiEdiAliasDualMul10(void);
extern void EsiInstallSetCallChain(void);
extern void InstallSelfPauseTwoCall(void);
extern void ScaledLitLoadCall_00480fe0(void);
extern void TripleFieldCopyHi(void);
extern void TripleFieldCopyJmpHi(void);

__declspec(naked) void TriPhaseDecCounterListAdvance(void)
{
    __asm
    {
        mov     eax, dword ptr [g_baseSel]
        push    ebx
        push    esi
        mov     ebx, 1
        lea     esi, [eax*4]
        mov     eax, dword ptr [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], 0
        sub     eax, 0
        je      L_tpdcla_phase0
        dec     eax
        je      short L_tpdcla_phase1
        mov     dword ptr [g_walkCallback], 0x9d
        call    ScaledLitLoadCall_00480fe0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_tpdcla_abort
        mov     ecx, dword ptr [g_baseSel]
        mov     eax, dword ptr [ecx*4 + 4]
        dec     eax
        mov     dword ptr [g_currentNodeIdx], eax
        mov     edx, dword ptr [eax*4]
        mov     dword ptr [g_eventQueueChild], edx
        mov     dword ptr [ecx*4 + 4], eax
        mov     eax, dword ptr [g_eventQueueChild]
        dec     eax
        mov     dword ptr [g_eventQueueChild], eax
        jne     L_tpdcla_chain
        call    EsiInstallSetCallChain
        pop     esi
        pop     ebx
        ret
    L_tpdcla_phase1:
        call    TripleFieldCopyHi
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_tpdcla_abort
        mov     dword ptr [g_walkCallback], 0xe666
        call    EsiEdiAliasDualMul10
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_tpdcla_abort
        mov     dword ptr [esi + 8], offset TriPhaseDecCounterListAdvance
        mov     dword ptr [esi + 0x84], 2
        mov     dword ptr [g_pendingNodeType], 5
        mov     dword ptr [g_framePauseFlag], 1
        pop     esi
        pop     ebx
        ret
    L_tpdcla_phase0:
        cmp     dword ptr [g_xformScratch2088], ebx
        jne     short L_tpdcla_phase0_dispatch
        call    InstallSelfPauseTwoCall
        pop     esi
        pop     ebx
        ret
    L_tpdcla_phase0_dispatch:
        call    MStackPush3CmpCall
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_tpdcla_abort
        test    byte ptr [g_xformDirtyFlags], bl
        je      short L_tpdcla_p0_skip
        call    EsiInstallSetCallChain
        pop     esi
        pop     ebx
        ret
    L_tpdcla_p0_skip:
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     eax, dword ptr [ecx*4 + 0x28]
        cmp     eax, 0x18
        mov     dword ptr [g_walkCallback], eax
        jg      short L_tpdcla_storeBack
        mov     eax, 0x18
        mov     dword ptr [g_walkCallback], eax
    L_tpdcla_storeBack:
        mov     dword ptr [ecx*4 + 0x28], eax
        mov     dword ptr [g_eventQueueChild], 2
    L_tpdcla_chain:
        mov     eax, dword ptr [g_baseSel]
        mov     edx, dword ptr [g_eventQueueChild]
        mov     ecx, dword ptr [eax*4 + 4]
        lea     eax, [eax*4 + 4]
        mov     dword ptr [g_currentNodeIdx], ecx
        mov     dword ptr [ecx*4], edx
        mov     ecx, dword ptr [g_currentNodeIdx]
        inc     ecx
        mov     dword ptr [g_currentNodeIdx], ecx
        mov     dword ptr [eax], ecx
        mov     dword ptr [g_eventQueueNotMask], 6
        call    EntryThunkBodyStateMachine
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_tpdcla_abort
        call    TripleFieldCopyJmpHi
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_tpdcla_abort
        mov     dword ptr [esi + 8], offset TriPhaseDecCounterListAdvance
        mov     dword ptr [esi + 0x84], ebx
        mov     dword ptr [g_pendingNodeType], 5
        mov     dword ptr [g_framePauseFlag], ebx
    L_tpdcla_abort:
        pop     esi
        pop     ebx
        ret
    }
}
