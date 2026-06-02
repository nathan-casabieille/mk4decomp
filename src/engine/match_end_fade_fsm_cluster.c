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
extern void SetJmp_0049cb90(void);
extern void Thunk_0049cbd0(void);
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
extern void Wrapper_00436490(void);
extern void MoveFsmCluster(void);
extern void CallPauseTestByteJmpCalls(void);
extern void InstallSelfFullPath(void);
extern void InstallSelfCountdownChain(void);
extern void CopyJmp_0048ef90(void);
extern void DualTestDirtyToggle_004282c0(void);
extern void TripleVecAccCallStore(void);
extern void Thunk_004bd5c0(void);
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

extern void ScaledArrStore_004298c0(void);
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
extern void Wrapper_0048a350(void);
extern void Wrapper_0048a3a0(void);
extern void Helper_DownloadSetup(void);
extern void MStackPush3CmpCall(void);
extern void Wrapper_0048ec20(void);
extern void FiveCallScaledChainTailJmp(void);
extern void SetJmp_00438f50(void);
extern void SetJmp_00438f60(void);
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

extern void Chain2AxisDiffStoreTailJmp(void);
extern void DualPushAddCallDualPopJmp_0044cc50(void);
extern void GuardedSeq_00473f50(void);
extern void MStackPush3SideStore(void);
extern void PendingMatch_004492f0(void);
extern void StoreLoadJmp(void);
extern void Thunk_0049cbc0(void);

__declspec(naked) void MatchEndFadeFsmCluster_00449010(void)
{
    __asm {
        /* === h1 (0x449010): pre-fade init → tail-jmp 473f50 === */
        mov      eax, dword ptr [g_baseSel]
        mov      ecx, dword ptr [eax*4 + 0x64]
        mov      dword ptr [g_fightGroupHead], ecx
        call     MStackPush2RunCountdown
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_909c
        mov      dword ptr [g_walkCallback], 2
        call     ChainDirtyBitWalker
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_909c
        mov      eax, dword ptr [g_xformEntityIdx]
        mov      ecx, dword ptr [eax*4]
        or       ecx, 4
        mov      dword ptr [eax*4], ecx
        mov      edx, dword ptr [g_xformEntityIdx]
        mov      eax, 0xa0000
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [edx*4 + 0x34], eax
        call     MStackBracket7_DispatchAndChain
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_909c
        mov      dword ptr [g_walkCallback], 2
        mov      dword ptr [g_acc_00542078], 4
        jmp      GuardedSeq_00473f50
    L_909c:
        ret
        nop
        nop
        nop
        /* === h2 (0x4490a0): pose-fn 4-case FSM === */
    L_90a0:
        mov      eax, dword ptr [g_baseSel]
        push     esi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        cmp      eax, 3
        ja       L_92d3
        jmp      dword ptr [eax*4 + L_jmptbl_92dc]
    L_90ce:
        /* case 1: install state 2 */
        mov      dword ptr [g_eventQueueCurrent], 0xfffeb334
        mov      dword ptr [esi + 8], OFFSET L_90a0
        mov      ecx, dword ptr [g_baseSel]
        mov      edx, OFFSET L_90a0
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
        mov      dword ptr [eax*4 + 0x84], 0
        call     PendingMatch_004492f0
        mov      dword ptr [g_framePauseFlag], 1
        pop      esi
        ret
    L_9139:
        /* case 2: install state 3 (no work) */
        mov      dword ptr [esi + 8], OFFSET L_90a0
        mov      dword ptr [esi + 0x84], 3
        mov      dword ptr [g_pendingNodeType], 0x28
        mov      dword ptr [g_framePauseFlag], 1
        pop      esi
        ret
    L_9160:
        /* case 3: store fade params, call 44cc50, install state 4 */
        mov      ecx, dword ptr [g_baseSel]
        mov      dword ptr [g_eventQueueWorkType], 0xfffee667
        mov      edx, dword ptr [ecx*4 + 0x68]
        mov      dword ptr [g_eventQueueIdx], edx
        call     DualPushAddCallDualPopJmp_0044cc50
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_92d8
        mov      eax, dword ptr [g_eventQueueCurrent]
        mov      ecx, dword ptr [g_eventQueueWorkType]
        mov      dword ptr [g_currentNodeFlags], eax
        mov      dword ptr [g_xformScratch2088], ecx
        mov      dword ptr [g_eventQueueCurrent], 0xfffed99a
        mov      dword ptr [esi + 8], OFFSET L_90a0
        mov      edx, dword ptr [g_baseSel]
        mov      ecx, OFFSET L_90a0
        add      ecx, 0x4000000
        mov      dword ptr [edx*4 + 0x84], 4
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      edx, dword ptr [g_baseSel]
        mov      dword ptr [edx*4 + 0x84], 0
        call     PendingMatch_004492f0
        mov      dword ptr [g_framePauseFlag], 1
        pop      esi
        ret
    L_9211:
        /* case 0: full init - call 4493e0 helper via push/call, then chain */
        mov      eax, dword ptr [g_baseSel]
        mov      ecx, dword ptr [g_eventQueueEnd]
        push     0x4493e0
        mov      dword ptr [eax*4 + 0x64], ecx
        mov      edx, dword ptr [g_baseSel]
        mov      eax, dword ptr [g_eventQueueIdx]
        mov      dword ptr [edx*4 + 0x68], eax
        call     StoreLoadJmp
        add      esp, 4
        call     Chain2AxisDiffStoreTailJmp
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_92d8
        mov      dword ptr [g_eventQueueWorkType], 0xb333
        mov      dword ptr [g_walkCallback], 0xfffec000
        call     MStackPush3SideStore
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_92d8
        mov      dword ptr [g_eventQueueWorkType], 0x1999
        call     DualPushAddCallDualPopJmp_0044cc50
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_92d8
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      ecx, dword ptr [g_eventQueueCurrent]
        mov      edx, dword ptr [g_eventQueueWorkType]
        mov      dword ptr [g_fightGroupHead], eax
        mov      eax, 1
        mov      dword ptr [g_currentNodeFlags], ecx
        mov      dword ptr [g_xformScratch2088], edx
        mov      dword ptr [esi + 8], OFFSET L_90a0
        mov      dword ptr [esi + 0x84], eax
        mov      dword ptr [g_pendingNodeType], 0xc8
        mov      dword ptr [g_framePauseFlag], eax
        pop      esi
        ret
    L_92d3:
        call     Thunk_0049cbc0
    L_92d8:
        pop      esi
        ret
        /* 2-byte nop pad: 8b ff (mov edi, edi) */
        _emit    0x8b
        _emit    0xff
    L_jmptbl_92dc:
        /* 4-entry jump table */
        _emit    0x11  /* case 0 -> 0x449211 */
        _emit    0x92
        _emit    0x44
        _emit    0x00
        _emit    0xce  /* case 1 -> 0x4490ce */
        _emit    0x90
        _emit    0x44
        _emit    0x00
        _emit    0x39  /* case 2 -> 0x449139 */
        _emit    0x91
        _emit    0x44
        _emit    0x00
        _emit    0x60  /* case 3 -> 0x449160 */
        _emit    0x91
        _emit    0x44
        _emit    0x00
    }
}
