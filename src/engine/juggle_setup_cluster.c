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

/* ------------------------------------------------------------------ */
/* Pose-copy + idle-decision cluster (560b game, falls through into  */
/* sibling 0x4539d0)                                                  */
/* ------------------------------------------------------------------ */
extern void MStackCall_004062f0(void);
extern void Chain2AxisDiffStoreTailJmp(void);
extern void MStackPush3SideStore(void);
extern void DualScaledStore(void);
extern void JuggleSetupCluster(void);
extern void func_00453a01(void);
extern void Thunk_ScaledNeg1SetPause(void);
extern unsigned int g_dispatchSave952;
extern unsigned int g_dispatchSave953;
extern unsigned int g_installOwner2;


__declspec(naked) void PoseCopyIdleCluster(void)
{
    __asm {
        /* === Helper 1: pose-copy from slot ECX to slot EAX === */
        call     MStackCall_004062f0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_38a4
        mov      ecx, dword ptr [g_eventQueueEnd]
        mov      eax, dword ptr [g_fightGroupHead]
        shl      ecx, 2
        shl      eax, 2
        mov      edx, dword ptr [ecx + 0x54]
        mov      dword ptr [eax + 0x54], edx
        mov      edx, 0xfffed3b7
        mov      dword ptr [g_walkCallback], edx
        mov      dword ptr [eax + 0x58], edx
        mov      edx, dword ptr [ecx + 0x5c]
        mov      dword ptr [g_walkCallback], edx
        mov      dword ptr [eax + 0x5c], edx
        mov      edx, dword ptr [ecx + 0x60]
        mov      dword ptr [g_walkCallback], edx
        mov      dword ptr [eax + 0x60], edx
        mov      edx, dword ptr [ecx + 0x64]
        mov      dword ptr [g_walkCallback], edx
        mov      dword ptr [eax + 0x64], edx
        mov      edx, dword ptr [ecx + 0x68]
        mov      dword ptr [g_walkCallback], edx
        mov      dword ptr [eax + 0x68], edx
        mov      ecx, dword ptr [ecx + 0x34]
        mov      dword ptr [g_eventQueueCurrent], ecx
        mov      eax, dword ptr [eax + 0x34]
        and      ecx, 1
        and      al, 0xfe
        mov      dword ptr [g_eventQueueCurrent], ecx
        or       eax, ecx
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x34], eax
        mov      edx, dword ptr [g_fightGroupHead]
        mov      eax, dword ptr [edx*4 + 0x18]
        mov      dword ptr [g_walkCallback], 0
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4 + 0x30], 0
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      eax, dword ptr [g_walkCallback]
        mov      dword ptr [ecx*4 + 0x34], eax
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      edx, dword ptr [g_walkCallback]
        mov      dword ptr [eax*4 + 0x38], edx
        mov      edx, dword ptr [g_xformDirtyFlags]
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      eax, 4
        or       edx, eax
        test     ecx, ecx
        mov      dword ptr [g_xformDirtyFlags], edx
        je       short L_38a4
        mov      ecx, edx
        xor      ecx, eax
        mov      dword ptr [g_xformDirtyFlags], ecx
    L_38a4:
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
        /* === Helper 2 (0x4538b0): idle/standup dispatcher === */
    L_38b0:
        mov      eax, dword ptr [g_baseSel]
        push     esi
        push     edi
        xor      edi, edi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], edi
        sub      eax, edi
        je       short L_3935
        dec      eax
        je       short L_38dc
        call     Thunk_ScaledNeg1SetPause
        pop      edi
        pop      esi
        ret
    L_38dc:
        mov      edx, dword ptr [g_installOwner2]
        mov      ecx, OFFSET g_dispatchSave953
        shr      ecx, 2
        mov      dword ptr [g_eventQueueIdx], ecx
        mov      dword ptr [g_eventQueueEnd], edx
        mov      dword ptr [g_eventQueueNotMask], edi
        mov      dword ptr [g_xformScratch2088], 0x20c
        mov      dword ptr [esi + 8], OFFSET L_38b0
        mov      eax, dword ptr [g_baseSel]
        mov      ecx, OFFSET L_38b0
        mov      dword ptr [eax*4 + 0x84], 2
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_currentNodeIdx], eax
        add      ecx, 0x2000000
        jmp      JuggleSetupCluster
    L_3935:
        call     DualScaledStore
        cmp      dword ptr [g_framePauseFlag], edi
        jne      func_00453a01
        call     Chain2AxisDiffStoreTailJmp
        cmp      dword ptr [g_framePauseFlag], edi
        jne      func_00453a01
        mov      dword ptr [g_eventQueueWorkType], 0xe666
        mov      dword ptr [g_walkCallback], 0xfffef334
        call     MStackPush3SideStore
        cmp      dword ptr [g_framePauseFlag], edi
        jne      func_00453a01
        mov      ecx, dword ptr [g_installOwner2]
        mov      eax, OFFSET g_dispatchSave952
        shr      eax, 2
        mov      dword ptr [g_eventQueueIdx], eax
        mov      dword ptr [g_eventQueueEnd], ecx
        mov      dword ptr [g_eventQueueNotMask], edi
        mov      dword ptr [g_xformScratch2088], 0x666
        mov      dword ptr [esi + 8], OFFSET L_38b0
        mov      edx, dword ptr [g_baseSel]
        mov      ecx, OFFSET L_38b0
        mov      dword ptr [edx*4 + 0x84], 1
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_currentNodeIdx], eax
        add      ecx, 0x1000000
        /* Fall-through to JuggleSetupCluster (sibling immediately after). */
    }
}
