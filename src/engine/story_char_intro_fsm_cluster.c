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
extern void GuardedDispatch_InstallSelfDualEsi(void);
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

extern unsigned int g_dispatchSave704;
extern unsigned int g_dispatchSave705;
extern unsigned int g_tickFlagF;
extern unsigned int g_byte_00538148;
extern unsigned int g_audioStreamState;
extern unsigned int g_installSelfCounter;
extern void ArgSarStoreJmp(void);
extern void CallPauseScaledStoreCopyJmp(void);
extern void DualSlotPropagateCall(void);
extern void DualWalkRange(void);
extern void EsiInstallChainCmpDualCall(void);
extern void GateDispatch6c(void);
extern void InstallSelf3WayChainCmp(void);
extern void LoadSetFpJmp_g_bootChainScaled1(void);
extern void MStackPush1MagicMod2(void);
extern void PendingMatch_0046b670(void);
extern void PoseFsmTriHelpers(void);
extern void PushCallPauseSetMaxThenCallPauseJmp(void);
extern void ScaledInitWithCounterAndType_004314f0(void);
extern void ScaledLoadJmp_00428d20(void);

__declspec(naked) void StoryCharIntroFsmCluster(void)
{
    __asm {
        mov      eax, dword ptr [g_baseSel]
        push     esi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        sub      eax, 0
        je       L_7f81
        dec      eax
        je       L_7f20
        call     LoadSetFpJmp_g_bootChainScaled1
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_8019
        push     OFFSET g_dispatchSave704
        call     ArgSarStoreJmp
        mov      eax, dword ptr [g_framePauseFlag]
        add      esp, 4
        pop      esi
        ret
    L_7f20:
        mov      dword ptr [esi + 8], OFFSET StoryCharIntroFsmCluster
        mov      ecx, dword ptr [g_baseSel]
        mov      edx, OFFSET StoryCharIntroFsmCluster
        mov      dword ptr [ecx*4 + 0x84], 2
        mov      eax, dword ptr [esi + 4]
        add      edx, 0x2000000
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], edx
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      eax, dword ptr [g_baseSel]
        mov      dword ptr [eax*4 + 0x84], 0
        call     PendingMatch_0046b670
        mov      dword ptr [g_framePauseFlag], 1
        pop      esi
        ret
    L_7f81:
        mov      al, byte ptr [g_gtModeFlag]
        mov      ecx, dword ptr [g_audioBankSel]
        cmp      al, 1
        jne      L_7f9b
        cmp      ecx, 1
        jne      L_7f9b
        inc      dword ptr [g_installSelfCounter]
    L_7f9b:
        cmp      al, 2
        jne      L_7faa
        cmp      ecx, 2
        jne      L_7faa
        inc      dword ptr [g_installSelfCounter]
    L_7faa:
        call     GateDispatch6c
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_8019
        mov      eax, 0x20
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [g_audioStreamState], eax
        call     PushCallPauseSetMaxThenCallPauseJmp
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_8019
        cmp      dword ptr [g_tickFlagF], 2
        jne      L_7fe5
        mov      byte ptr [g_byte_00538148], 1
    L_7fe5:
        push     0
        push     OFFSET L_8200
        call     StoreTwoCall
        mov      dword ptr [esi + 8], OFFSET StoryCharIntroFsmCluster
        mov      dword ptr [esi + 0x84], 1
        add      esp, 8
        mov      dword ptr [g_pendingNodeType], 0x1e
        mov      dword ptr [g_framePauseFlag], 1
    L_8019:
        pop      esi
        ret
        nop
        nop
        nop
        nop
        nop
    L_8020:
        mov      eax, dword ptr [g_baseSel]
        push     esi
        push     edi
        mov      ecx, 3
        lea      esi, [eax*4]
        xor      edi, edi
        mov      eax, dword ptr [esi + 0x84]
        mov      dword ptr [esi + 0x84], edi
        cmp      eax, ecx
        ja       L_81cb
        jmp      dword ptr [eax*4 + L_81ec_jmptbl]
    L_8050:
        mov      dword ptr [g_eventQueueChild], 8
        mov      dword ptr [esi + 8], OFFSET L_8020
        mov      ecx, dword ptr [g_baseSel]
        mov      edx, OFFSET L_8020
        add      edx, 0x2000000
        mov      dword ptr [ecx*4 + 0x84], 2
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], edx
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      eax, dword ptr [g_baseSel]
        mov      dword ptr [eax*4 + 0x84], edi
        call     InstallSelf3WayChainCmp
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        ret
    L_80b8:
        mov      eax, dword ptr [g_eventQueueNotMask]
        dec      eax
        mov      dword ptr [g_eventQueueNotMask], eax
        jne      L_8163
        mov      dword ptr [esi + 8], OFFSET L_8020
        mov      edx, dword ptr [g_baseSel]
        mov      dword ptr [edx*4 + 0x84], ecx
        mov      eax, dword ptr [esi + 4]
        mov      ecx, OFFSET L_8020
        mov      dword ptr [g_currentNodeIdx], eax
        add      ecx, 0x3000000
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      edx, dword ptr [g_baseSel]
        mov      dword ptr [edx*4 + 0x84], edi
        call     ScaledLoadJmp_00428d20
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        ret
    L_8124:
        call     CallPauseScaledStoreCopyJmp
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_81e7
        mov      dword ptr [esi + 8], OFFSET L_8020
        mov      dword ptr [esi + 0x84], 4
        mov      dword ptr [g_pendingNodeType], 0x1e
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        ret
    L_815d:
        mov      dword ptr [g_eventQueueNotMask], ecx
    L_8163:
        mov      dword ptr [g_eventQueueChild], 6
        mov      dword ptr [esi + 8], OFFSET L_8020
        mov      eax, dword ptr [g_baseSel]
        mov      ecx, OFFSET L_8020
        add      ecx, 0x1000000
        mov      dword ptr [eax*4 + 0x84], 1
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      edx, dword ptr [g_baseSel]
        mov      dword ptr [edx*4 + 0x84], edi
        call     EsiInstallChainCmpDualCall
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        ret
    L_81cb:
        mov      dword ptr [g_eventQueueWorkType], 0x3d
        call     Push16Call
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_81e7
        call     ScaledInitWithCounterAndType_004314f0
    L_81e7:
        pop      edi
        pop      esi
        ret
        /* 2-byte alignment nop before jump table: 8b ff (mov edi, edi) */
        _emit    0x8b
        _emit    0xff
    L_81ec_jmptbl:
        /* 4-entry jump table */
        _emit    0x5d  /* case 0 -> 0x46815d */
        _emit    0x81
        _emit    0x46
        _emit    0x00
        _emit    0x50  /* case 1 -> 0x468050 */
        _emit    0x80
        _emit    0x46
        _emit    0x00
        _emit    0xb8  /* case 2 -> 0x4680b8 */
        _emit    0x80
        _emit    0x46
        _emit    0x00
        _emit    0x24  /* case 3 -> 0x468124 */
        _emit    0x81
        _emit    0x46
        _emit    0x00
        nop
        nop
        nop
        nop
    L_8200:
        mov      eax, dword ptr [g_fightGroupHead]
        mov      dword ptr [g_xformScratch2088], 0x10000
        mov      dword ptr [g_eventQueueEnd], eax
        push     esi
        mov      eax, dword ptr [eax*4 + 0x34]
        mov      dword ptr [g_walkCallback], eax
        and      eax, 1
        mov      dword ptr [g_xformScratch94], eax
        je       L_8235
        mov      dword ptr [g_xformScratch2088], 0xffff0000
    L_8235:
        mov      dword ptr [g_eventQueueChild], 0x28
        call     PoseFsmTriHelpers
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_83d1
        mov      eax, dword ptr [g_baseSel]
        mov      ecx, dword ptr [eax*4 + 0x44]
        mov      dword ptr [g_eventQueueWorkType], ecx
        call     MStackPush1MagicMod2
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_83d1
        mov      edx, dword ptr [g_walkCallback]
        mov      dword ptr [g_eventQueueWorkType], 0x60000
        push     edx
        push     0x60000
        call     Mul10Tail
        mov      ecx, dword ptr [g_eventQueueWorkType]
        add      esp, 8
        mov      dword ptr [g_currentNodeFlags], eax
        mov      eax, dword ptr [g_eventQueueCurrent]
        push     eax
        push     ecx
        call     Mul10Tail
        mov      edx, dword ptr [g_walkCallback]
        add      esp, 8
        mov      dword ptr [g_xformScratch2088], eax
        push     edx
        push     0x11999
        call     Mul10Tail
        add      esp, 8
        mov      dword ptr [g_walkCallback], eax
        mov      eax, dword ptr [g_eventQueueCurrent]
        push     eax
        push     0x11999
        call     Mul10Tail
        mov      ecx, dword ptr [g_walkCallback]
        mov      esi, dword ptr [g_currentNodeFlags]
        mov      dword ptr [g_eventQueueCurrent], eax
        mov      dword ptr [g_eventQueueChild], ecx
        neg      eax
        mov      dword ptr [g_eventQueueNotMask], eax
        mov      eax, dword ptr [g_baseSel]
        add      esp, 8
        mov      edx, dword ptr [eax*4 + 0x34]
        add      esi, edx
        mov      edx, dword ptr [g_xformScratch2088]
        mov      dword ptr [g_currentNodeFlags], esi
        mov      eax, dword ptr [eax*4 + 0x3c]
        add      edx, eax
        push     ecx
        push     0x14ccc
        mov      dword ptr [g_xformScratch2088], edx
        call     Mul10Tail
        mov      ecx, dword ptr [g_eventQueueCurrent]
        add      esp, 8
        mov      dword ptr [g_walkCallback], eax
        push     ecx
        push     0x14ccc
        call     Mul10Tail
        mov      edx, dword ptr [g_baseSel]
        mov      dword ptr [g_eventQueueCurrent], eax
        mov      eax, dword ptr [g_walkCallback]
        add      esp, 8
        mov      dword ptr [edx*4 + 0x30], eax
        mov      ecx, dword ptr [g_baseSel]
        mov      edx, dword ptr [g_eventQueueCurrent]
        mov      dword ptr [ecx*4 + 0x34], edx
        mov      eax, dword ptr [g_baseSel]
        mov      ecx, dword ptr [g_currentNodeFlags]
        mov      dword ptr [eax*4 + 0x38], ecx
        mov      eax, dword ptr [g_baseSel]
        mov      edx, dword ptr [g_xformScratch2088]
        mov      dword ptr [eax*4 + 0x3c], edx
        call     DualWalkRange
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_83d1
        call     DualSlotPropagateCall
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_83d1
        call     DualSlotPropagateCall
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_83d1
        push     OFFSET g_dispatchSave705
        call     ArgSarStoreJmp
        add      esp, 4
    L_83d1:
        pop      esi
        ret
    }
}
