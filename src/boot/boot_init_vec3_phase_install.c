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

extern unsigned int g_dispatchSave144;
extern unsigned int g_particleEmitterNode;
extern unsigned int g_phaseIdx;
extern void BootMultiAssetLoadStateInit(void);
extern void FiveTableWalkInit(void);
extern void InstallSelfPackedF80(void);
extern void MStackCall_MStackPush2ChainPrepend_00406340(void);
extern void TableWalkBoundedCmp(void);

__declspec(naked) void BootInitVec3PhaseInstall(void)
{
    __asm
    {
        mov     eax, dword ptr [g_baseSel]
        push    esi
        push    edi
        xor     edi, edi
        lea     esi, [eax*4]
        mov     eax, dword ptr [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], edi
        sub     eax, edi
        je      short L_bivpi_phase0
        dec     eax
        je      short L_bivpi_phase1
        push    9
        call    TableWalkBoundedCmp
        add     esp, 4
        call    StackPopDispatchTagged
        pop     edi
        pop     esi
        ret
    L_bivpi_phase0:
        call    FiveTableWalkInit
        cmp     dword ptr [g_framePauseFlag], edi
        jne     L_bivpi_pop
        mov     dword ptr [g_phaseIdx], 0xa
        call    BootMultiAssetLoadStateInit
        cmp     dword ptr [g_framePauseFlag], edi
        jne     L_bivpi_pop
        push    edi
        push    0x4a2180
        call    StoreTwoCall
        mov     ecx, offset g_dispatchSave144
        add     esp, 8
        shr     ecx, 2
        mov     dword ptr [g_xformEntityIdx], ecx
        call    DispatcherComplex260_MStackBracket1_TreeWalkRecursive2
        cmp     dword ptr [g_framePauseFlag], edi
        jne     L_bivpi_pop
        test    byte ptr [g_xformDirtyFlags], 4
        je      short L_bivpi_doVec3Init
    L_bivpi_phase1:
        mov     dword ptr [g_eventQueueCurrent], 3
        mov     dword ptr [esi + 8], offset BootInitVec3PhaseInstall
        mov     edx, dword ptr [g_baseSel]
        mov     ecx, offset BootInitVec3PhaseInstall
        add     ecx, 0x2000000
        mov     dword ptr [edx*4 + 0x84], 2
        mov     eax, dword ptr [esi + 4]
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [eax*4], ecx
        mov     eax, dword ptr [g_currentNodeIdx]
        inc     eax
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [esi + 4], eax
        mov     edx, dword ptr [g_baseSel]
        mov     dword ptr [edx*4 + 0x84], edi
        call    InstallSelfPackedF80
        mov     dword ptr [g_framePauseFlag], 1
        pop     edi
        pop     esi
        ret
    L_bivpi_doVec3Init:
        mov     eax, dword ptr [g_currentNodeIdx]
        shl     eax, 2
        mov     dword ptr [eax + 0x54], edi
        mov     dword ptr [eax + 0x58], edi
        mov     dword ptr [eax + 0x5c], edi
        mov     ecx, dword ptr [g_currentNodeIdx]
        mov     eax, 9
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x30], eax
        call    MStackCall_MStackPush2ChainPrepend_00406340
        cmp     dword ptr [g_framePauseFlag], edi
        jne     L_bivpi_pop
        mov     eax, dword ptr [g_particleEmitterNode]
        mov     edx, dword ptr [g_currentNodeIdx]
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [g_fightGroupHead], edx
        shl     eax, 2
        mov     ecx, 0xfffde667
        mov     dword ptr [eax + 0x54], edi
        mov     dword ptr [eax + 0x58], edi
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [eax + 0x5c], ecx
        mov     eax, dword ptr [g_fightGroupHead]
        mov     ecx, dword ptr [g_currentNodeIdx]
        mov     dword ptr [eax*4 + 0x3c], ecx
        mov     eax, dword ptr [g_fightGroupHead]
        mov     ecx, dword ptr [eax*4 + 0x34]
        or      ecx, 0x80000
        mov     dword ptr [eax*4 + 0x34], ecx
        mov     edx, dword ptr [g_fightGroupHead]
        mov     eax, 0xc91
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [edx*4 + 0x7c], eax
        mov     eax, 1
        mov     dword ptr [esi + 8], offset BootInitVec3PhaseInstall
        mov     dword ptr [esi + 0x84], eax
        mov     dword ptr [g_pendingNodeType], 0x180
        mov     dword ptr [g_framePauseFlag], eax
    L_bivpi_pop:
        pop     edi
        pop     esi
        ret
    }
}
