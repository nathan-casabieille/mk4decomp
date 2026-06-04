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

extern void ChainListVecAdd(void);
extern void DualEntryRecursiveInstall(void);
extern void GuardedSeq_MStackCall_then_CallSetPause_00471670(void);
extern void TripleCallBitJmp(void);

__declspec(naked) void FsmPoseDualEntry(void)
{
    __asm {
    L_2560:
        mov      eax, dword ptr [g_baseSel]
        push     ebx
        push     esi
        push     edi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        test     eax, eax
        je       L_272d
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      edi, dword ptr [g_xformDirtyFlags]
        mov      eax, dword ptr [ecx*4 + 0x18]
        mov      ecx, 4
        or       edi, ecx
        mov      dword ptr [g_currentNodeIdx], eax
        test     eax, eax
        mov      dword ptr [g_xformDirtyFlags], edi
        je       L_2724
        mov      edx, edi
        xor      edx, ecx
        test     eax, eax
        mov      dword ptr [g_xformDirtyFlags], edx
        jne      short L_25cc
        call     GuardedSeq_MStackCall_then_CallSetPause_00471670
        pop      edi
        pop      esi
        pop      ebx
        ret
    L_25cc:
        mov      ecx, dword ptr [eax*4 + 0x20]
        or       ecx, 0x40
        mov      dword ptr [g_walkCallback], ecx
        mov      dword ptr [eax*4 + 0x20], ecx
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      eax, dword ptr [edx*4 + 0x2c]
        test     eax, eax
        mov      dword ptr [g_walkCallback], eax
        je       L_26b4
        mov      dword ptr [g_xformEntityIdx], eax
        mov      ecx, dword ptr [eax*4 + 0x14]
        lea      eax, [eax*4 + 0x14]
        mov      edx, 0x1ca
        add      ecx, edx
        mov      dword ptr [g_walkCallback], edx
        mov      dword ptr [g_eventQueueCurrent], ecx
        mov      dword ptr [eax], ecx
        mov      ecx, dword ptr [g_xformEntityIdx]
        mov      edi, dword ptr [g_fightGroupHead]
        mov      eax, dword ptr [ecx*4 + 8]
        mov      dword ptr [g_walkCallback], eax
        mov      ebx, dword ptr [edi*4 + 0x58]
        add      eax, ebx
        mov      dword ptr [g_walkCallback], eax
        mov      eax, dword ptr [ecx*4]
        test     eax, eax
        mov      dword ptr [g_walkCallback], eax
        je       short L_26b4
    L_265b:
        mov      dword ptr [g_xformEntityIdx], eax
        mov      ecx, dword ptr [eax*4 + 0x14]
        lea      eax, [eax*4 + 0x14]
        add      ecx, edx
        mov      dword ptr [g_walkCallback], edx
        mov      dword ptr [g_eventQueueCurrent], ecx
        mov      dword ptr [eax], ecx
        mov      ecx, dword ptr [g_xformEntityIdx]
        mov      edi, dword ptr [g_fightGroupHead]
        mov      eax, dword ptr [ecx*4 + 8]
        mov      dword ptr [g_walkCallback], eax
        mov      ebx, dword ptr [edi*4 + 0x58]
        add      eax, ebx
        mov      dword ptr [g_walkCallback], eax
        mov      eax, dword ptr [ecx*4]
        test     eax, eax
        mov      dword ptr [g_walkCallback], eax
        jne      short L_265b
    L_26b4:
        mov      eax, dword ptr [g_fightGroupHead]
        mov      eax, dword ptr [eax*4 + 0x18]
        mov      dword ptr [g_currentNodeIdx], eax
        mov      eax, dword ptr [eax*4 + 0x28]
        mov      dword ptr [g_xformEntityIdx], eax
        mov      eax, dword ptr [eax*4]
        mov      dword ptr [g_walkCallback], eax
        and      eax, 0x400
        mov      dword ptr [g_xformScratch94], eax
        je       short L_270e
        mov      ecx, dword ptr [g_baseSel]
        mov      eax, dword ptr [ecx*4 + 0x38]
        sub      eax, 0x33
        mov      dword ptr [g_walkCallback], eax
        jns      short L_2707
        xor      eax, eax
        mov      dword ptr [g_walkCallback], eax
    L_2707:
        mov      dword ptr [ecx*4 + 0x38], eax
    L_270e:
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      eax, dword ptr [ecx*4 + 0x18]
        test     eax, eax
        mov      dword ptr [g_walkCallback], eax
        jne      short L_272d
    L_2724:
        call     GuardedSeq_MStackCall_then_CallSetPause_00471670
        pop      edi
        pop      esi
        pop      ebx
        ret
    L_272d:
        mov      edx, dword ptr [g_fightGroupHead]
        mov      eax, dword ptr [edx*4 + 0x18]
        mov      dword ptr [g_currentNodeIdx], eax
        call     ChainListVecAdd
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_2769
        mov      eax, 1
        mov      dword ptr [esi + 8], OFFSET L_2560
        mov      dword ptr [esi + 0x84], eax
        mov      dword ptr [g_pendingNodeType], eax
        mov      dword ptr [g_framePauseFlag], eax
    L_2769:
        pop      edi
        pop      esi
        pop      ebx
        ret
        nop
        nop
        nop
    L_2770:
        mov      eax, dword ptr [g_baseSel]
        shl      eax, 2
        mov      ecx, dword ptr [eax + 0x84]
        mov      dword ptr [eax + 0x84], 0
        test     ecx, ecx
        je       short L_27b3
        mov      dword ptr [g_eventQueueCurrent], 0x1999
        mov      dword ptr [g_eventQueueWorkType], 0x9999
        call     DualEntryRecursiveInstall
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_2815
        jmp      L_2560
    L_27b3:
        mov      dword ptr [eax + 8], OFFSET L_2770
        mov      ecx, dword ptr [g_baseSel]
        mov      edx, OFFSET L_2770
        mov      dword ptr [ecx*4 + 0x84], 1
        mov      ecx, dword ptr [eax + 4]
        add      edx, 0x1000000
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      dword ptr [ecx*4], edx
        mov      ecx, dword ptr [g_currentNodeIdx]
        inc      ecx
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      dword ptr [eax + 4], ecx
        mov      eax, dword ptr [g_baseSel]
        mov      dword ptr [eax*4 + 0x84], 0
        call     TripleCallBitJmp
        mov      dword ptr [g_framePauseFlag], 1
    L_2815:
        ret
    }
}
