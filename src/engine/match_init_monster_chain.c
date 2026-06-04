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

extern unsigned int g_counter_0053a51c;
extern unsigned int g_dispatchSave881;
extern unsigned int g_dispatchSave509;
extern int GuardedScaledLookupCallJmp(void);
extern void AndShlStore(void);
extern void StackPopDispatchTagged(void);
extern void TableWalkBoundedCmp(int);
extern void BootInitGuardedCallChain(void);
extern void DualScaledLitInitJmp(void);
extern void TableWalkPause(void);
extern void QuadCallPhase2(void);
extern void StoreTwoCall(void);
extern void MatchInitMonsterChain(void);

/* @addr 0x00403170 (348b boot) - 3-state install-self phase dispatcher.
 *   Reads phase from [g_baseSel*4 + 0x84], zeroes it, then dispatches
 *   on phase = 0, 1, 2, 3.
 *     - phase 0 / 1: jump to the heavy "first-time init" path that pushes 4
 *       on TableWalkBoundedCmp, calls BootInitGuardedCallChain,
 *       DualScaledLitInitJmp, TableWalkPause, then runs
 *       QuadCallPhase2 with args (g_dlNalt1, g_dlNalt2,
 *       g_counter_0053a51c + 0x12, 0x1d). Pushes two StoreTwoCall calls
 *       with table pointers 0x004a2090 / 0x004a2180. Installs self at
 *       [esi+8]=0x403170 and sets [eax*4+0x84]=2 (with packed_ptr +
 *       0x02000000 tag), then calls MatchInitMonsterChain and asserts the error
 *       flag g_framePauseFlag = 1.
 *     - phase 2: install self at [esi+8]=0x403170, zero [esi+0x84]=3,
 *       set g_pendingNodeType=4, set g_framePauseFlag=1, return.
 *     - phase 3: call GuardedScaledLookupCallJmp, on no-error set
 *       g_walkCallback=3, call AndShlStore, call
 *       StackPopDispatchTagged, return.
 */
extern s32 g_dlNalt1;
extern s32 g_dlNalt2;
extern unsigned int g_smState4Way;

__declspec(naked) void Phase3InstallSelf(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel]
        push    esi
        push    edi
        xor     edi, edi
        lea     esi, [eax*4]
        mov     eax, dword ptr [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], edi
        sub     eax, edi
        je      L_p3i_initPath
        dec     eax
        je      L_p3i_initPath
        dec     eax
        je      short L_p3i_phase2
        call    GuardedScaledLookupCallJmp
        cmp     dword ptr [g_framePauseFlag], edi
        jne     L_p3i_done
        mov     dword ptr [g_walkCallback], 3
        call    AndShlStore
        cmp     dword ptr [g_framePauseFlag], edi
        jne     L_p3i_done
        call    StackPopDispatchTagged
        pop     edi
        pop     esi
        ret
    L_p3i_phase2:
        mov     dword ptr [g_walkCallback], edi
        mov     dword ptr [g_smState4Way], edi
        mov     dword ptr [esi + 8], offset Phase3InstallSelf
        mov     dword ptr [esi + 0x84], 3
        mov     dword ptr [g_pendingNodeType], 4
        mov     dword ptr [g_framePauseFlag], 1
        pop     edi
        pop     esi
        ret
    L_p3i_initPath:
        push    4
        call    TableWalkBoundedCmp
        add     esp, 4
        call    BootInitGuardedCallChain
        cmp     dword ptr [g_framePauseFlag], edi
        jne     L_p3i_done
        call    DualScaledLitInitJmp
        call    TableWalkPause
        mov     ecx, dword ptr [g_counter_0053a51c]
        mov     edx, dword ptr [g_dlNalt2]
        mov     eax, dword ptr [g_dlNalt1]
        add     ecx, 0x12
        push    0x1d
        push    ecx
        push    edx
        push    eax
        call    QuadCallPhase2
        add     esp, 0x10
        call    BootInitGuardedCallChain
        cmp     dword ptr [g_framePauseFlag], edi
        jne     short L_p3i_done
        push    edi
        push    offset g_dispatchSave881
        call    StoreTwoCall
        add     esp, 8
        push    edi
        push    offset g_dispatchSave509
        call    StoreTwoCall
        mov     dword ptr [esi + 8], offset Phase3InstallSelf
        mov     ecx, dword ptr [g_baseSel]
        mov     edx, offset Phase3InstallSelf
        add     esp, 8
        mov     dword ptr [ecx*4 + 0x84], 2
        mov     eax, dword ptr [esi + 4]
        add     edx, 0x02000000
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [eax*4], edx
        mov     eax, dword ptr [g_currentNodeIdx]
        inc     eax
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [esi + 4], eax
        mov     eax, dword ptr [g_baseSel]
        mov     dword ptr [eax*4 + 0x84], edi
        call    MatchInitMonsterChain
        mov     dword ptr [g_framePauseFlag], 1
    L_p3i_done:
        pop     edi
        pop     esi
        ret
    }
}
