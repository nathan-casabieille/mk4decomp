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

extern unsigned int g_phaseThunkState2;
extern void CallPauseCallTestStackPushJmp(void);
extern void CallPauseMStackPushSet0Jmp(void);
extern void CallPauseTriCmpJmp(void);
extern void CjInstallSelfRouter(void);
extern void CjMaskedFlagProbe(void);
extern void DualGatedStateYield(void);
extern void GuardedDispatch_00460ca0(void);
extern void GuardedDispatch_00460cd0(void);
extern void GuardedDoubleCallSetJmp(void);
extern void NotShrCmp1Store(void);
extern void PerSlotPhaseRouter_004605d0(void);
extern void PerSlotPhaseRouter_00460770(void);
extern void UnlinkChainInstall_00460dd0(void);

__declspec(naked) void SlotPhaseDispatcherBigSwitch(void)
{
    __asm
    {
        mov     eax, dword ptr [g_baseSel]
        push    ebx
        push    esi
        push    edi
        lea     esi, [eax*4]
        xor     edi, edi
        mov     eax, dword ptr [esi + 0x84]
        mov     dword ptr [esi + 0x84], edi
        cmp     eax, edi
        je      L_spdbs_phase0
        mov     ebx, 4
    L_spdbs_loop:
        call    DirtyToggleByGate
        cmp     dword ptr [g_framePauseFlag], edi
        jne     L_spdbs_ret
        test    byte ptr [g_xformDirtyFlags], bl
        jne     L_spdbs_b4
        call    CjMaskedFlagProbe
        cmp     dword ptr [g_framePauseFlag], edi
        jne     L_spdbs_ret
        test    byte ptr [g_xformDirtyFlags], 1
        jne     L_spdbs_b1
        call    NotShrCmp1Store
        cmp     dword ptr [g_framePauseFlag], edi
        jne     L_spdbs_ret
        mov     eax, dword ptr [g_walkCallback]
        mov     ecx, eax
        and     ecx, 9
        cmp     ecx, 9
        mov     dword ptr [g_eventQueueCurrent], ecx
        je      L_spdbs_b9
        mov     ecx, eax
        and     ecx, 5
        cmp     ecx, 5
        mov     dword ptr [g_eventQueueCurrent], ecx
        je      L_spdbs_b5
        mov     ecx, eax
        and     ecx, 1
        cmp     ecx, 1
        mov     dword ptr [g_eventQueueCurrent], ecx
        je      L_spdbs_b1a
        mov     ecx, eax
        and     ecx, 8
        cmp     ecx, 8
        mov     dword ptr [g_eventQueueCurrent], ecx
        je      L_spdbs_b8
        mov     ecx, eax
        and     ecx, ebx
        cmp     ecx, ebx
        mov     dword ptr [g_eventQueueCurrent], ecx
        je      L_spdbs_b4a
        and     eax, 2
        mov     dword ptr [g_xformScratch94], eax
        jne     L_spdbs_b2
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     dword ptr [g_walkCallback], edi
        mov     dword ptr [ecx*4 + 0x6c], edi
        mov     eax, dword ptr [g_fightGroupHead]
        mov     edx, dword ptr [g_walkCallback]
        mov     dword ptr [eax*4 + 0x70], edx
        mov     edx, dword ptr [g_fightGroupHead]
        mov     ecx, dword ptr [g_walkCallback]
        mov     dword ptr [edx*4 + 0x74], ecx
        call    CallPauseTriCmpJmp
        cmp     dword ptr [g_framePauseFlag], edi
        jne     short L_spdbs_ret
        mov     eax, dword ptr [g_baseSel]
        lea     esi, [eax*4]
        mov     eax, dword ptr [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], edi
        cmp     eax, edi
        jne     L_spdbs_loop
    L_spdbs_phase0:
        call    DualGatedStateYield
        test    eax, eax
        jne     short L_spdbs_ret
        mov     eax, dword ptr [g_phaseThunkState2]
        cmp     eax, edi
        mov     dword ptr [g_eventQueueCurrent], eax
        je      short L_spdbs_install
        call    UnlinkChainInstall_00460dd0
        pop     edi
        pop     esi
        pop     ebx
        ret
    L_spdbs_install:
        mov     eax, 1
        mov     dword ptr [esi + 8], offset SlotPhaseDispatcherBigSwitch
        mov     dword ptr [esi + 0x84], eax
        mov     dword ptr [g_pendingNodeType], eax
        mov     dword ptr [g_framePauseFlag], eax
    L_spdbs_ret:
        pop     edi
        pop     esi
        pop     ebx
        ret
    L_spdbs_b4:
        call    CjInstallSelfRouter
        pop     edi
        pop     esi
        pop     ebx
        ret
    L_spdbs_b1:
        call    GuardedDoubleCallSetJmp
        pop     edi
        pop     esi
        pop     ebx
        ret
    L_spdbs_b9:
        call    GuardedDispatch_00460ca0
        pop     edi
        pop     esi
        pop     ebx
        ret
    L_spdbs_b5:
        call    GuardedDispatch_00460cd0
        pop     edi
        pop     esi
        pop     ebx
        ret
    L_spdbs_b1a:
        call    CallPauseCallTestStackPushJmp
        pop     edi
        pop     esi
        pop     ebx
        ret
    L_spdbs_b8:
        call    PerSlotPhaseRouter_004605d0
        pop     edi
        pop     esi
        pop     ebx
        ret
    L_spdbs_b4a:
        call    PerSlotPhaseRouter_00460770
        pop     edi
        pop     esi
        pop     ebx
        ret
    L_spdbs_b2:
        call    CallPauseMStackPushSet0Jmp
        pop     edi
        pop     esi
        pop     ebx
        ret
    }
}
