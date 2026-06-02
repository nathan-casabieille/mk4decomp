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
extern void SetJmp_0049cb90(void);
extern void Thunk_0049cbd0(void);
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
extern void Wrapper_00436490(void);
extern void MoveFsmCluster(void);
extern void CallPauseTestByteJmpCalls(void);
extern void InstallSelfFullPath(void);
extern void InstallSelfCountdownChain(void);
extern void CopyJmp_0048ef90(void);
extern void DualTestDirtyToggle_004282c0(void);
extern void TripleVecAccCallStore(void);
extern void Thunk_004bd5c0(void);
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

extern void ScaledArrStore_004298c0(void);
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
extern void Wrapper_0048a350(void);
extern void Wrapper_0048a3a0(void);
extern void Helper_DownloadSetup(void);
extern void MStackPush3CmpCall(void);
extern void Wrapper_0048ec20(void);
extern void FiveCallScaledChainTailJmp(void);
extern void SetJmp_00438f50(void);
extern void SetJmp_00438f60(void);
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

extern unsigned int g_dispatchSave648_004ed8d8;
extern void AerialHitDispatcher_0047c290(void);
extern void ArgSarStoreJmp(void);
extern void DualCallPauseDirtyJmp_00490c30(void);
extern void GuardedDirtyXformFromTable(void);
extern void InstallSelfCmpJgJmp_00480ac0(void);
extern void ScaledChainTwoStores_00480d20(void);
extern void Vec2ChainComputeStores_00480b80(void);

__declspec(naked) void PairedSubInstallSelfBigChain_0047c0d0(void)
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
        mov     ecx, offset g_dispatchSave648_004ed8d8
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
        call    AerialHitDispatcher_0047c290
        pop     esi
        ret
    L_psisbc_phase1:
        mov     dword ptr [eax*4 + 0x58], 0
        mov     ecx, dword ptr [g_currentNodeFlags]
        mov     edx, dword ptr [g_xformScratch2088]
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [g_eventQueueCurrent], edx
        call    Vec2ChainComputeStores_00480b80
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
        call    ScaledChainTwoStores_00480d20
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
        call    InstallSelfCmpJgJmp_00480ac0
        mov     dword ptr [g_framePauseFlag], 1
    L_psisbc_ret:
        pop     esi
        ret
    }
}
