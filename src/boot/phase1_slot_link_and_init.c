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

extern unsigned int g_particleEmitterNode;
extern void BootChainBidirRecurseWalk(void);
extern void BootPhaseGateBracketedInit(void);
extern void GuardedChainPushSetCallPop(void);
extern void MStackCall_MStackPush2ChainPrepend_00406340(void);
extern void MStackInitCallToggle(void);
extern void ScaledLoadGuardedJmp(void);
extern void ScaledTestPauseStore(void);

__declspec(naked) void Phase1SlotLinkAndInit(void)
{
    __asm {
        mov     eax, dword ptr [g_fightGroupHead]
        mov     dword ptr [g_currentNodeIdx], eax
        call    GuardedChainPushSetCallPop
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p1sli_ret
        call    ScaledLoadGuardedJmp
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p1sli_ret
        mov     dword ptr [g_walkCallback], 0xFFFFFFFF
        call    MStackInitCallToggle
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p1sli_ret
        test    byte ptr [g_xformDirtyFlags], 4
        jne     L_p1sli_ret
        mov     ecx, dword ptr [g_currentNodeIdx]
        mov     dword ptr [g_eventQueueTotal], ecx
        call    ScaledTestPauseStore
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p1sli_ret
        test    byte ptr [g_xformDirtyFlags], 4
        jne     L_p1sli_ret
        call    BootPhaseGateBracketedInit
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p1sli_ret
        test    byte ptr [g_xformDirtyFlags], 4
        jne     L_p1sli_ret
        mov     eax, dword ptr [g_currentNodeIdx]
        mov     dword ptr [g_eventQueueEnd], eax
        mov     dword ptr [eax*4 + 0x30], 0x85
        mov     eax, dword ptr [g_particleEmitterNode]
        mov     edx, dword ptr [g_eventQueueEnd]
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [edx*4 + 0x3C], eax
        mov     eax, dword ptr [g_fightGroupHead]
        mov     dword ptr [g_eventQueueNotMask], 0x10000
        mov     eax, dword ptr [eax*4 + 0x34]
        and     eax, 1
        je      L_p1sli_after_select
        mov     dword ptr [g_eventQueueNotMask], 0xFFFF0000
    L_p1sli_after_select:
        mov     ecx, dword ptr [g_eventQueueEnd]
        or      ah, 0x40
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x34], eax
        mov     eax, dword ptr [g_xformEntityIdx]
        mov     ecx, dword ptr [eax*4]
        or      ecx, 8
        mov     dword ptr [eax*4], ecx
        mov     edx, dword ptr [g_xformEntityIdx]
        mov     eax, 0x00419040
        mov     dword ptr [edx*4 + 0x48], 0x11999
        mov     ecx, dword ptr [g_xformEntityIdx]
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x10], eax
        mov     edx, dword ptr [g_fightGroupHead]
        mov     ecx, dword ptr [g_eventQueueEnd]
        mov     eax, dword ptr [edx*4 + 0x54]
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x54], eax
        mov     edx, dword ptr [g_fightGroupHead]
        mov     ecx, dword ptr [g_eventQueueEnd]
        mov     eax, dword ptr [edx*4 + 0x58]
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x58], eax
        mov     edx, dword ptr [g_fightGroupHead]
        mov     ecx, dword ptr [g_eventQueueEnd]
        mov     eax, dword ptr [edx*4 + 0x5C]
        mov     dword ptr [ecx*4 + 0x5C], eax
        mov     edx, dword ptr [g_eventQueueEnd]
        mov     dword ptr [edx*4 + 0x6C], 0x666
        mov     eax, dword ptr [g_eventQueueEnd]
        mov     dword ptr [eax*4 + 0x70], 0xFFFFE3D8
        mov     ecx, dword ptr [g_eventQueueEnd]
        mov     eax, 0xFFFFFAE2
        mov     dword ptr [ecx*4 + 0x74], 0xCCC
        mov     edx, dword ptr [g_eventQueueEnd]
        mov     dword ptr [edx*4 + 0x7C], 0x3333
        mov     ecx, dword ptr [g_eventQueueEnd]
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x80], eax
        mov     edx, dword ptr [g_eventQueueTotal]
        mov     dword ptr [g_currentNodeIdx], edx
        call    BootChainBidirRecurseWalk
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p1sli_ret
        mov     eax, dword ptr [g_eventQueueEnd]
        mov     ecx, dword ptr [g_currentNodeIdx]
        mov     dword ptr [eax*4 + 0x18], ecx
        mov     eax, dword ptr [g_currentNodeIdx]
        mov     edx, dword ptr [g_eventQueueEnd]
        mov     dword ptr [eax*4 + 0x18], edx
        mov     ecx, dword ptr [g_eventQueueEnd]
        mov     dword ptr [g_currentNodeIdx], ecx
        jmp     MStackCall_MStackPush2ChainPrepend_00406340
    L_p1sli_ret:
        ret
    }
}
