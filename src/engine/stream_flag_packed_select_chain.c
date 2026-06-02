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

/* @addr 0x00469340 (364b game) - cdecl chain with stream-flag swap +
 *   packed_ptr select. Sets g_walkCallback=0x52, calls
 *   TableLookupCall_g_table_004efa00; on no-error sets 0x54206c=0xa, calls
 *   ScaledIndexConditionalAdd. Then dispatches on
 *   g_baseSel:
 *     - matches g_gtPlayerProbe2: if g_mul10SumState is set, picks
 *       &g_mul10TableBase>>2 (state 1) or &g_dispatchTab>>2 (other)
 *       into g_eventQueueTotal, clears g_mul10SumState, jumps to next.
 *     - matches g_gtPlayerProbe1: mirror with g_mul10SumState2.
 *     - default: both g_eventQueueTotal and 0x54204c set to the two
 *       packed_ptrs, zeroes g_eventQueueChild, calls
 *       GuardedDualConst2AndToggle. If bit 0 of 0x54208c set,
 *       sets g_eventQueueChild=1 and copies 0x54204c into 0x542050; else
 *       keeps 0x542050.
 *   Tail: copies chosen base into 0x542044, calls Mul10SumStoreNegCommit, pushes
 *   0x542a58 and calls GuardedPackedSlotInit, then
 *   MStackPush3CmpCall. If bit 0 of 0x54208c set, calls
 *   PendingMatch_QuadCallPhase2. Then tail-jmp ScaledChainJmp_00429470 or
 *   ScaledClearJmp_EsiInstallBitCallChain depending on g_eventQueueChild.
 */
extern unsigned int g_dispatchTab;
extern unsigned int g_mul10TableBase;
extern unsigned int g_dispatchVar37;
extern unsigned int g_mul10SumState;
extern unsigned int g_mul10SumState2;
extern void GuardedPackedSlotInit(void);
extern void Mul10SumStoreNegCommit(void);
extern void PendingMatch_QuadCallPhase2(void);
extern void ScaledChainJmp_00429470(void);
extern void ScaledClearJmp_EsiInstallBitCallChain(void);
extern void ScaledIndexConditionalAdd(void);
extern void TableLookupCall_g_table_004efa00(void);

__declspec(naked) void StreamFlagPackedSelectChain(void) {
    __asm {
        mov     dword ptr [g_walkCallback], 0x52
        call    TableLookupCall_g_table_004efa00
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_sfp_done
        mov     dword ptr [g_walkCallback], 0xa
        call    ScaledIndexConditionalAdd
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_sfp_done
        mov     ecx, dword ptr [g_baseSel]
        mov     eax, dword ptr [g_gtPlayerProbe2]
        cmp     ecx, eax
        jne     short L_sfp_check2
        mov     eax, dword ptr [g_mul10SumState]
        test    eax, eax
        je      short L_sfp_check2
        cmp     eax, 1
        mov     eax, offset g_mul10TableBase
        je      short L_sfp_useEax1
        mov     eax, offset g_dispatchTab
    L_sfp_useEax1:
        shr     eax, 2
        mov     dword ptr [g_eventQueueTotal], eax
        mov     dword ptr [g_mul10SumState], 0
        jmp     L_sfp_callBlock
    L_sfp_check2:
        cmp     ecx, dword ptr [g_gtPlayerProbe1]
        jne     short L_sfp_defaultPath
        mov     eax, dword ptr [g_mul10SumState2]
        test    eax, eax
        je      short L_sfp_defaultPath
        cmp     eax, 1
        mov     eax, offset g_mul10TableBase
        je      short L_sfp_useEax2
        mov     eax, offset g_dispatchTab
    L_sfp_useEax2:
        shr     eax, 2
        mov     dword ptr [g_eventQueueTotal], eax
        mov     dword ptr [g_mul10SumState2], 0
        jmp     short L_sfp_callBlock
    L_sfp_defaultPath:
        mov     eax, offset g_dispatchTab
        mov     ecx, offset g_mul10TableBase
        shr     eax, 2
        shr     ecx, 2
        mov     dword ptr [g_pendingNodeType], eax
        mov     dword ptr [g_eventQueueTotal], ecx
        mov     dword ptr [g_eventQueueChild], 0
        call    GuardedDualConst2AndToggle
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_sfp_done
        mov     eax, dword ptr [g_xformDirtyFlags]
        and     eax, 1
        je      short L_sfp_useSecond
        mov     dword ptr [g_eventQueueChild], 1
    L_sfp_useSecond:
        test    eax, eax
        je      short L_sfp_useStored
        mov     eax, dword ptr [g_pendingNodeType]
        mov     dword ptr [g_eventQueueTotal], eax
        jmp     short L_sfp_callBlock
    L_sfp_useStored:
        mov     eax, dword ptr [g_eventQueueTotal]
    L_sfp_callBlock:
        mov     dword ptr [g_currentNodeIdx], eax
        call    Mul10SumStoreNegCommit
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_sfp_done
        push    offset g_dispatchVar37
        call    GuardedPackedSlotInit
        mov     eax, dword ptr [g_framePauseFlag]
        add     esp, 4
        test    eax, eax
        jne     short L_sfp_done
        call    MStackPush3CmpCall
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_sfp_done
        test    byte ptr [g_xformDirtyFlags], 1
        je      short L_sfp_skipCallb0
        call    PendingMatch_QuadCallPhase2
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_sfp_done
    L_sfp_skipCallb0:
        mov     eax, dword ptr [g_eventQueueChild]
        test    eax, eax
        jne     short L_sfp_tailClear
        jmp     ScaledChainJmp_00429470
    L_sfp_tailClear:
        jmp     ScaledClearJmp_EsiInstallBitCallChain
    L_sfp_done:
        ret
    }
}
