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

extern unsigned int g_dispatchSave648;
extern void ArgSarStoreJmp(void);
extern void GuardedDirtyXformFromTable(void);
extern void AerialHitDispatcher(void);
extern void Vec2ChainComputeStores(void);
extern void DualCallPauseDirtyJmp_00490c30(void);
extern void ScaledChainTwoStores(void);
extern void InstallSelfCmpJgJmp(void);

__declspec(naked) void PairedSubInstallSelfBigChain(void)
{
    __asm
    {
        mov     ecx, dword ptr [g_baseSel]
        mov     eax, 0x20e
        mov     dword ptr [g_walkCallback], eax
        push    0x4ed2a0
        mov     dword ptr [ecx*4 + 0x74], eax
        call    ArgSarStoreJmp
        add     esp, 4
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
    L_psisbc_entry2:
        mov     eax, dword ptr [g_baseSel]
        push    esi
        lea     esi, [eax*4]
        mov     eax, dword ptr [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], 0
        sub     eax, 0
        je      L_psisbc_phase0
        dec     eax
        mov     eax, dword ptr [g_fightGroupHead]
        je      short L_psisbc_phase1
        mov     ecx, dword ptr [eax*4 + 0x58]
        mov     dword ptr [g_walkCallback], ecx
        mov     eax, dword ptr [eax*4 + 0x48]
        cmp     ecx, eax
        mov     dword ptr [g_eventQueueCurrent], eax
        jg      L_psisbc_install2
        mov     ecx, offset g_dispatchSave648
        shr     ecx, 2
        mov     dword ptr [g_currentNodeIdx], ecx
        call    GuardedDirtyXformFromTable
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_psisbc_ret
        mov     edx, dword ptr [g_fightGroupHead]
        mov     eax, 0x51e
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [edx*4 + 0x4c], eax
        call    AerialHitDispatcher
        pop     esi
        ret
    L_psisbc_phase1:
        mov     dword ptr [eax*4 + 0x58], 0
        mov     ecx, dword ptr [g_currentNodeFlags]
        mov     edx, dword ptr [g_xformScratch2088]
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [g_eventQueueCurrent], edx
        call    Vec2ChainComputeStores
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_psisbc_ret
        call    DualCallPauseDirtyJmp_00490c30
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_psisbc_ret
    L_psisbc_install2:
        mov     dword ptr [esi + 8], offset L_psisbc_entry2
        mov     dword ptr [esi + 0x84], 2
        mov     dword ptr [g_pendingNodeType], 1
        mov     dword ptr [g_framePauseFlag], 1
        pop     esi
        ret
    L_psisbc_phase0:
        call    ScaledChainTwoStores
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_psisbc_ret
        mov     eax, dword ptr [g_walkCallback]
        mov     ecx, dword ptr [g_eventQueueCurrent]
        mov     dword ptr [g_currentNodeFlags], eax
        mov     dword ptr [g_xformScratch2088], ecx
        mov     dword ptr [g_eventQueueNotMask], 0xfffc0000
        mov     dword ptr [esi + 8], offset L_psisbc_entry2
        mov     edx, dword ptr [g_baseSel]
        mov     ecx, offset L_psisbc_entry2
        add     ecx, 0x1000000
        mov     dword ptr [edx*4 + 0x84], 1
        mov     eax, dword ptr [esi + 4]
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [eax*4], ecx
        mov     eax, dword ptr [g_currentNodeIdx]
        inc     eax
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [esi + 4], eax
        mov     edx, dword ptr [g_baseSel]
        mov     dword ptr [edx*4 + 0x84], 0
        call    InstallSelfCmpJgJmp
        mov     dword ptr [g_framePauseFlag], 1
    L_psisbc_ret:
        pop     esi
        ret
    }
}
