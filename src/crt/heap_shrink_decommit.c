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

/* @addr 0x004c72a0 (205b crt) - heap shrink/decommit scan.
 *   Walks the heap-region list head [g_heapShrinkPtr]; for each region with
 *   handle != -1, scans its 2KB page-state array (1024 entries × 8 bytes)
 *   at +0x2010, looking for entries marked 0xf0 (free). Decommit each via
 *   IAT[0x4d2168] (VirtualFree); on success, mark slot 0xffffffff, decrement
 *   counter [g_dispatchSave1432], update head ptr at [region+0xc]. Decrement
 *   target count [esp+0x14]; if region fully empty (all -1), call
 *   HeapRegionTeardown(region).
 */
extern unsigned int g_heapShrinkPtr;
extern unsigned int g_dispatchSave1432;
extern unsigned int g_iat_VirtualFree;
extern void HeapRegionTeardown(void);

__declspec(naked) void HeapShrinkDecommit(void) {
    __asm {
        push    ebx
        push    ebp
        push    esi
        push    edi
        mov     edi, dword ptr [g_heapShrinkPtr]
    L_hs_check:
        cmp     dword ptr [edi + 0x10], -1
        jz      L_hs_outer_check
        xor     ebp, ebp
        lea     esi, [edi + 0x2010]
        mov     ebx, 0x003ff000
    L_hs_loop:
        cmp     dword ptr [esi], 0xf0
        jne     short L_hs_nextpage
        mov     eax, [edi + 0x10]
        push    0x4000
        add     eax, ebx
        push    0x1000
        push    eax
        call    dword ptr [g_iat_VirtualFree]
        test    eax, eax
        jz      short L_hs_nextpage
        mov     dword ptr [esi], 0xffffffff
        mov     edx, dword ptr [g_dispatchSave1432]
        dec     edx
        mov     dword ptr [g_dispatchSave1432], edx
        mov     eax, [edi + 0xc]
        test    eax, eax
        jz      short L_hs_setHead
        cmp     eax, esi
        jbe     short L_hs_after
    L_hs_setHead:
        mov     [edi + 0xc], esi
    L_hs_after:
        mov     eax, [esp + 0x14]
        inc     ebp
        dec     eax
        mov     [esp + 0x14], eax
        jz      short L_hs_done
    L_hs_nextpage:
        sub     ebx, 0x1000
        sub     esi, 8
        test    ebx, ebx
        jge     short L_hs_loop
    L_hs_done:
        mov     edx, edi
        mov     edi, [edi + 4]
        test    ebp, ebp
        jz      short L_hs_outer_check
        cmp     dword ptr [edx + 0x18], -1
        jne     short L_hs_outer_check
        mov     eax, 1
        lea     ecx, [edx + 0x20]
    L_hs_scanempty:
        cmp     dword ptr [ecx], -1
        jne     short L_hs_emptyCk
        inc     eax
        add     ecx, 8
        cmp     eax, 0x400
        jl      short L_hs_scanempty
    L_hs_emptyCk:
        cmp     eax, 0x400
        jne     short L_hs_outer_check
        push    edx
        call    HeapRegionTeardown
        add     esp, 4
    L_hs_outer_check:
        cmp     edi, dword ptr [g_heapShrinkPtr]
        jz      short L_hs_ret
        mov     eax, [esp + 0x14]
        test    eax, eax
        jg      L_hs_check
    L_hs_ret:
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        ret
    }
}
