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

extern void PendingMatch_00459510(void);
extern void ScaledIterStep_0045c020(void);

__declspec(naked) void MoveListCursorCluster(void)
{
    __asm {
    L_b420:
        /* H1 */
        call     ScaledIterStep_0045c020
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_b445
        mov      eax, dword ptr [g_baseSel]
        mov      ecx, dword ptr [g_walkCallback]
        mov      dword ptr [eax*4 + 0x48], ecx
        jmp      PendingMatch_00459510
    L_b445:
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
        /* H2 */
        mov      ecx, dword ptr [g_eventQueueCurrent]
        mov      eax, dword ptr [g_framePauseFlag]
        and      ecx, 0xff
        test     eax, eax
        mov      dword ptr [g_eventQueueCurrent], ecx
        jne      short L_b47c
        mov      eax, dword ptr [g_baseSel]
        mov      dword ptr [eax*4 + 0x78], ecx
        jmp      PendingMatch_00459510
    L_b47c:
        ret
        nop
        nop
        nop
        /* H3 */
        mov      ecx, dword ptr [g_baseSel]
        mov      eax, dword ptr [ecx*4 + 0x78]
        dec      eax
        mov      dword ptr [g_eventQueueCurrent], eax
        mov      dword ptr [ecx*4 + 0x78], eax
        jne      short L_b4a1
        jmp      PendingMatch_00459510
    L_b4a1:
        mov      edx, dword ptr [g_baseSel]
        mov      ecx, dword ptr [edx*4 + 0x48]
        dec      ecx
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      eax, dword ptr [ecx*4]
        shr      eax, 0x18
        cmp      eax, 0x3a
        mov      dword ptr [g_walkCallback], eax
        je       short L_b4e4
    L_b4c9:
        dec      ecx
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      eax, dword ptr [ecx*4]
        shr      eax, 0x18
        cmp      eax, 0x3a
        mov      dword ptr [g_walkCallback], eax
        jne      short L_b4c9
    L_b4e4:
        inc      ecx
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      dword ptr [edx*4 + 0x48], ecx
        jmp      PendingMatch_00459510
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        /* H4 */
        mov      edx, dword ptr [g_baseSel]
        mov      ecx, dword ptr [edx*4 + 0x48]
        mov      dword ptr [g_eventQueueTotal], ecx
        mov      eax, dword ptr [edx*4 + 0x34]
        cmp      eax, 0x10
        mov      dword ptr [g_walkCallback], eax
        jne      short L_b52e
        mov      eax, 2
        mov      dword ptr [g_walkCallback], eax
    L_b52e:
        cmp      eax, 0x11
        jne      short L_b53d
        mov      eax, 7
        mov      dword ptr [g_walkCallback], eax
    L_b53d:
        add      ecx, eax
        mov      dword ptr [g_eventQueueTotal], ecx
        mov      ecx, dword ptr [ecx*4]
        mov      dword ptr [g_walkCallback], ecx
        mov      dword ptr [edx*4 + 0x48], ecx
        jmp      PendingMatch_00459510
        nop
        nop
        /* H5 */
        cmp      dword ptr [g_xformScratch2088], 1
        jne      short L_b56e
        jmp      L_b420
    L_b56e:
        call     ScaledIterStep_0045c020
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_b581
        jmp      PendingMatch_00459510
    L_b581:
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
        nop
        nop
        nop
        /* H6 (L_b590): install state 1 */
    L_b590:
        mov      eax, dword ptr [g_baseSel]
        mov      ecx, 1
        shl      eax, 2
        mov      dword ptr [eax + 0x84], 0
        mov      dword ptr [eax + 8], OFFSET L_b590
        mov      dword ptr [eax + 0x84], ecx
        mov      dword ptr [g_pendingNodeType], 0x3c
        mov      dword ptr [g_framePauseFlag], ecx
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
        /* H7: combined call + dispatch */
        call     ScaledIterStep_0045c020
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_b614
        mov      eax, dword ptr [g_walkCallback]
        mov      dword ptr [g_currentNodeIdx], eax
        call     eax
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_b614
        test     byte ptr [g_xformDirtyFlags], 4
        je       short L_b601
        jmp      L_b420
    L_b601:
        call     ScaledIterStep_0045c020
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_b614
        jmp      PendingMatch_00459510
    L_b614:
        ret
    }
}
