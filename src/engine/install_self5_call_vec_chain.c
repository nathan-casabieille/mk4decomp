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

/* @addr 0x00464660 (386b game) - install-self with 5-call vec/slot chain.
 *   Always installs Self at end (no phase check). Sets:
 *     - g_xformEntityIdx = g_installVecChainVar (vec0 base)
 *     - g_pendingNodeType = g_baseSel + 0xc (slot pointer+0xc)
 *     - g_eventQueueTotal = [g_eventQueueEnd*4] (deref scope)
 *   If 0x542050 is non-zero AND [g_eventQueueIdx*4] is non-zero, runs a
 *   5-step chain through scaled-buffer indices: QuadInterpolatorV2 (+0x15) →
 *   TripleSubVec3 (+0x15) → ThreeMul10Stores
 *   (with 0xcccc weight) → TripleSubVec3 (+0x1b) →
 *   ThreeClampLoop (with 0x4ccc cap) → TripleAddVec3
 *   (with +0x1b advance). Failure path skips remaining calls.
 *
 *   Tail unconditionally installs Self with slot[+0x84]=1,
 *   g_pendingNodeType=2, arms 0x541e6c=1.
 */
extern unsigned int g_installVecChainVar;
extern unsigned int g_savedNode;
extern void QuadInterpolatorV2(void);
extern void ThreeClampLoop(void);
extern void ThreeMul10Stores(void);
extern void TripleAddVec3(void);
extern void TripleSubVec3(void);

__declspec(naked) void InstallSelf5CallVecChain(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel]
        push    esi
        mov     dword ptr [eax*4 + 0x84], 0
        mov     edx, dword ptr [g_baseSel]
        mov     ecx, dword ptr [g_installVecChainVar]
        lea     esi, [eax*4]
        mov     eax, dword ptr [g_eventQueueEnd]
        add     edx, 0xc
        mov     dword ptr [g_xformEntityIdx], ecx
        mov     dword ptr [g_pendingNodeType], edx
        mov     eax, dword ptr [eax*4]
        test    eax, eax
        mov     dword ptr [g_eventQueueTotal], eax
        je      L_isvc_install
        mov     ecx, dword ptr [g_savedNode]
        add     eax, 0x15
        mov     dword ptr [g_eventQueueTotal], eax
        mov     dword ptr [g_currentNodeIdx], ecx
        call    QuadInterpolatorV2
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_isvc_done
        mov     edx, dword ptr [g_currentNodeIdx]
        mov     eax, dword ptr [g_eventQueueIdx]
        mov     ecx, dword ptr [g_eventQueueTotal]
        mov     dword ptr [g_xformEntityIdx], edx
        mov     eax, dword ptr [eax*4]
        test    ecx, ecx
        je      L_isvc_install
        add     eax, 0x15
        mov     dword ptr [g_pendingNodeType], eax
        call    TripleSubVec3
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_isvc_done
        mov     ecx, dword ptr [g_currentNodeIdx]
        mov     dword ptr [g_walkCallback], 0xcccc
        mov     dword ptr [g_xformEntityIdx], ecx
        call    ThreeMul10Stores
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_isvc_done
        mov     edx, dword ptr [g_currentNodeIdx]
        mov     eax, dword ptr [g_eventQueueIdx]
        mov     dword ptr [g_xformEntityIdx], edx
        mov     ecx, dword ptr [eax*4]
        add     ecx, 0x1b
        mov     dword ptr [g_pendingNodeType], ecx
        call    TripleSubVec3
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_isvc_done
        mov     edx, dword ptr [g_currentNodeIdx]
        mov     dword ptr [g_walkCallback], 0x4ccc
        mov     dword ptr [g_xformEntityIdx], edx
        call    ThreeClampLoop
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_isvc_done
        mov     eax, dword ptr [g_currentNodeIdx]
        mov     ecx, dword ptr [g_eventQueueIdx]
        mov     dword ptr [g_xformEntityIdx], eax
        mov     eax, dword ptr [ecx*4]
        add     eax, 0x1b
        mov     dword ptr [g_pendingNodeType], eax
        mov     dword ptr [g_currentNodeIdx], eax
        call    TripleAddVec3
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_isvc_done
    L_isvc_install:
        mov     eax, 1
        mov     dword ptr [esi + 8], offset InstallSelf5CallVecChain
        mov     dword ptr [esi + 0x84], eax
        mov     dword ptr [g_pendingNodeType], 2
        mov     dword ptr [g_framePauseFlag], eax
    L_isvc_done:
        pop     esi
        ret
    }
}
