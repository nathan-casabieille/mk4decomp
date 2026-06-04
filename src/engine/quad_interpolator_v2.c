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

extern void ScaledTestChainDispatch(void);
extern void NegateThree(void);
extern void QuadInterpolatorV2(void);

/* @addr 0x00408350 (349b boot) - mstack-push-4 scope with +0x18 cj advance.
 *   Pushes g_xformEntityIdx/4c/50/54 onto mstack, advances cj by 0x18, sets
 *   esi from local frame (lea [esp+4] then sar 2 - encodes "frame slot 1"),
 *   calls ScaledTestChainDispatch. On no-error: reads
 *   [g_fightGroupHead*4 + 0x34] into 0x54206c, mirrors low bit to 0x542094,
 *   conditionally calls NegateThree, then sets up a 2nd scope
 *   advancing cj by 0x15 and calls QuadInterpolatorV2. Finally pops the 4
 *   originals back to 0054204c/50/54/48 in reverse order.
 */
extern unsigned int g_phaseChainTbl;

__declspec(naked) void MStackBootPush4Init(void) {
    __asm {
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_xformEntityIdx]
        sub     esp, 0x24
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4 + g_phaseChainTbl], ecx
        mov     eax, dword ptr [g_matrixStackTop]
        mov     edx, dword ptr [g_pendingNodeType]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        push    esi
        mov     dword ptr [eax*4 + g_phaseChainTbl], edx
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_eventQueueTotal]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        lea     esi, [esp + 4]
        mov     dword ptr [eax*4 + g_phaseChainTbl], ecx
        mov     eax, dword ptr [g_matrixStackTop]
        mov     edx, dword ptr [g_eventQueueEnd]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4 + g_phaseChainTbl], edx
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     eax, dword ptr [g_currentNodeIdx]
        add     ecx, 0x18
        sar     esi, 2
        mov     dword ptr [g_eventQueueEnd], eax
        mov     dword ptr [g_xformEntityIdx], ecx
        mov     dword ptr [g_currentNodeIdx], esi
        call    ScaledTestChainDispatch
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_mp4i_cleanup
        mov     edx, dword ptr [g_fightGroupHead]
        mov     eax, dword ptr [edx*4 + 0x34]
        mov     dword ptr [g_walkCallback], eax
        and     eax, 1
        mov     dword ptr [g_xformScratch94], eax
        je      short L_mp4i_skipCall
        call    NegateThree
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_mp4i_cleanup
    L_mp4i_skipCall:
        mov     eax, dword ptr [g_eventQueueEnd]
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     dword ptr [g_pendingNodeType], eax
        mov     dword ptr [g_xformEntityIdx], esi
        lea     eax, [ecx + 0x15]
        mov     dword ptr [g_eventQueueTotal], eax
        mov     dword ptr [g_currentNodeIdx], eax
        call    QuadInterpolatorV2
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_mp4i_cleanup
        mov     edx, dword ptr [g_eventQueueEnd]
        mov     eax, dword ptr [g_matrixStackTop]
        mov     dword ptr [g_currentNodeIdx], edx
        mov     ecx, dword ptr [eax*4 + g_phaseChainTbl]
        dec     eax
        mov     dword ptr [g_eventQueueEnd], ecx
        mov     dword ptr [g_matrixStackTop], eax
        mov     edx, dword ptr [eax*4 + g_phaseChainTbl]
        dec     eax
        mov     dword ptr [g_eventQueueTotal], edx
        mov     dword ptr [g_matrixStackTop], eax
        mov     ecx, dword ptr [eax*4 + g_phaseChainTbl]
        dec     eax
        mov     dword ptr [g_pendingNodeType], ecx
        mov     dword ptr [g_matrixStackTop], eax
        mov     edx, dword ptr [eax*4 + g_phaseChainTbl]
        dec     eax
        mov     dword ptr [g_xformEntityIdx], edx
        mov     dword ptr [g_matrixStackTop], eax
    L_mp4i_cleanup:
        pop     esi
        add     esp, 0x24
        ret
    }
}
