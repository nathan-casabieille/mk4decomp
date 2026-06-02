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
extern void WalkCbSubMul10_00431d50(void);
extern void Mul10Tail(unsigned int a, unsigned int b);
extern void BootMod6487eClampAndChainMul10(void);
extern void SpawnListBatchLoader_00477710(void);
extern void MStackPush2TableNot(void);
extern void GuardedChainCmpDualBitXor(void);
extern void ScaledLoadDecJmp_00429710(void);
extern void ScaledStoreCurDirtyClear_004296f0(void);
extern void MStackBitmaskIncMod_00492450(void);
extern void MStackBitmaskUpdate_00492510(void);
extern void Push1eCallTestDirtyLoop_004923b0(void);
extern void MStackLoopFieldInit_00492280(void);
extern void TaggedSceneDispatch(void);
extern void CallPauseDirty4StackPushFn_004839d0(void);
extern void CallPauseDirty1JmpDirty4StackPush_00483a80(void);
extern void Cmp2CallDirtyCall(void);
extern void QuadBlockArgInstallChain(void);
extern void InstallSelfChainSet84_80CallW_004363f0(void);
extern void Wrapper_00436490(void);
extern void MoveFsmCluster_004364a0(void);
extern void CallPauseTestByteJmpCalls(void);
extern void InstallSelfFullPath(void);
extern void InstallSelfCountdownChain_0047a950(void);
extern void CopyJmp_0048ef90(void);
extern void DualTestDirtyToggle_004282c0(void);
extern void TripleVecAccCallStore(void);
extern void Thunk_004bd5c0(void);
extern void AllocSlotPushTripleGlobals(void);
extern void MStackPop4Rewrite(void);
extern void Push70CallScaleArith(void);
extern void StreamChainStringInstall(void);
extern void MStackFrameCdeclDouble(void);
extern void ChainTableWalkStore_004917e0(void);
extern void Push16Call(void);
extern void DispatcherComplex260_00407030(void);
extern void ScaledLoadCmpStoreXfm_0048f2a0(void);
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

extern unsigned int g_bootInitSaveSlot;
extern unsigned int g_dispatchVar36_00542bd4;
extern void CjInstallSelfRouter_00470480(void);
extern void DualCallPauseDirtyJmp_00490c30(void);
extern void FlagThunk4EntryDispatcher_0040a470(void);
extern void GateDispatch6c_00494580(void);
extern void GuardedPackedSlotInit_00428760(void);
extern void InstallSelfMStackIndirect_00487920(void);
extern void ScaledAndAlfb_00490370(void);
extern void ScaledAndAlfe_00490390(void);
extern void ScaledLoadOrSetJmp_00406b20(void);
extern void StateDispatchTable_00490fc0(void);
extern void TableLookupCall_0048a160(void);
extern void TripleEntryBitsetMStack_00487890(void);

__declspec(naked) void GameLoaderHandlerCluster_004876f0(void)
{
    __asm {
        /* Helper 1: simple guard over ScaledAndAlfb_00490370/ScaledAndAlfe_00490390. */
        call     ScaledAndAlfb_00490370
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_7703
        jmp      ScaledAndAlfe_00490390
    L_7703:
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
        /* Helper 2 (L_7710): per-entity state-clear. */
    L_7710:
        mov      eax, dword ptr [g_baseSel]
        push     esi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        test     eax, eax
        je       short L_7739
        call     CjInstallSelfRouter_00470480
        pop      esi
        ret
        /* Helper 3 (L_7739): advance-to-state-1. */
    L_7739:
        call     StateDispatchTable_00490fc0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_77a7
        mov      edx, dword ptr [g_fightGroupHead]
        mov      ecx, dword ptr [g_walkCallback]
        mov      dword ptr [edx*4 + 0x24], ecx
        mov      eax, dword ptr [g_fightGroupHead]
        mov      ecx, dword ptr [g_walkCallback]
        mov      dword ptr [eax*4 + 0x28], ecx
        mov      edx, dword ptr [g_fightGroupHead]
        mov      dword ptr [g_currentNodeIdx], edx
        call     ScaledLoadOrSetJmp_00406b20
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_77a7
        mov      eax, 1
        mov      dword ptr [esi + 8], OFFSET L_7710
        mov      dword ptr [esi + 0x84], eax
        mov      dword ptr [g_pendingNodeType], 0x28
        mov      dword ptr [g_framePauseFlag], eax
    L_77a7:
        pop      esi
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        /* Helper 4 (L_77b0): advance-to-state-2 + tail-jmp InstallSelfMStackIndirect_00487920. */
        call     GateDispatch6c_00494580
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_7812
        call     DualCallPauseDirtyJmp_00490c30
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_7812
        mov      ecx, dword ptr [g_baseSel]
        mov      eax, 1
        mov      dword ptr [g_walkCallback], eax
        push     OFFSET g_dispatchVar36_00542bd4
        mov      dword ptr [ecx*4 + 0x5c], eax
        call     GuardedPackedSlotInit_00428760
        mov      eax, dword ptr [g_framePauseFlag]
        add      esp, 4
        test     eax, eax
        jne      short L_7812
        mov      dword ptr [g_eventQueueNotMask], 0x201
        mov      dword ptr [g_eventQueueEnd], OFFSET L_7820
        jmp      InstallSelfMStackIndirect_00487920
    L_7812:
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
        /* Helper 5 (L_7820): periodic ticker with wrap+dispatch. */
    L_7820:
        mov      ecx, dword ptr [g_baseSel]
        mov      eax, dword ptr [ecx*4 + 0x5c]
        dec      eax
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [g_bootInitSaveSlot], eax
        jne      short L_7844
        mov      eax, 8
        mov      dword ptr [g_walkCallback], eax
    L_7844:
        mov      dword ptr [ecx*4 + 0x5c], eax
        mov      eax, dword ptr [g_bootInitSaveSlot]
        test     eax, eax
        je       short L_7859
        jmp      TripleEntryBitsetMStack_00487890
    L_7859:
        mov      dword ptr [g_walkCallback], 0xf
        call     FlagThunk4EntryDispatcher_0040a470
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_788e
        mov      dword ptr [g_walkCallback], 5
        call     TableLookupCall_0048a160
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_788e
        jmp      TripleEntryBitsetMStack_00487890
    L_788e:
        ret
    }
}
