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

extern unsigned int g_dispatchSave901_004d56d8;
extern unsigned int g_quadEntryGate_0052d724;
extern unsigned int g_clamp_00537f2c;
extern unsigned int g_clamp_0053a6dc;
extern void Cmp2DirtyToggle(void);
extern void DualAddSar_004ab600(void);
extern void SaveCallRestore(void);
extern void TableLookupCall_00489ff0(void);
extern void func_004214a0(void);

__declspec(naked) void MkIntroFsm_004218b0(void)
{
    __asm {
    L_18b0:
        mov      eax, dword ptr [g_baseSel]
        push     ebx
        push     esi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        sub      eax, 0
        je       L_19b0
        dec      eax
        je       L_196c
        dec      eax
        je       short L_1937
        call     Cmp2DirtyToggle
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1aa1
        mov      al, byte ptr [g_xformDirtyFlags]
        mov      ebx, 1
        test     al, bl
        je       L_1aa8
        mov      eax, dword ptr [g_player3NodeIdx]
        test     eax, eax
        mov      eax, dword ptr [g_player4NodeIdx]
        jne      L_1aa4
        test     eax, eax
        je       L_1aa8
    L_1920:
        mov      eax, 2
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [g_audioBankSel], eax
    L_192f:
        call     StackPopDispatchTagged
        pop      esi
        pop      ebx
        ret
    L_1937:
        push     0x24b
        call     SaveCallRestore
        mov      dword ptr [esi + 8], OFFSET L_18b0
        mov      dword ptr [esi + 0x84], 3
        add      esp, 4
        mov      dword ptr [g_pendingNodeType], 8
        mov      dword ptr [g_framePauseFlag], 1
        pop      esi
        pop      ebx
        ret
    L_196c:
        mov      dword ptr [g_walkCallback], 0x2d
        call     TableLookupCall_00489ff0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1aa1
        mov      dword ptr [esi + 8], OFFSET L_18b0
        mov      dword ptr [esi + 0x84], 2
        mov      dword ptr [g_pendingNodeType], 0x90
        mov      dword ptr [g_framePauseFlag], 1
        pop      esi
        pop      ebx
        ret
    L_19b0:
        mov      dword ptr [g_eventQueueWorkType], 0
        call     Push16Call
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_1aa1
        mov      ecx, dword ptr [g_gtPlayerProbe2]
        mov      ebx, 1
        mov      dword ptr [g_walkCallback], ebx
        mov      dword ptr [g_quadEntryGate_0052d724], ebx
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      dword ptr [g_xformEntityIdx], OFFSET func_004214a0
        call     Thunk_0049cbd0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_1aa1
        mov      edx, dword ptr [g_gtPlayerProbe1]
        mov      dword ptr [g_xformEntityIdx], OFFSET func_004214a0
        mov      dword ptr [g_currentNodeIdx], edx
        call     Thunk_0049cbd0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_1aa1
        mov      eax, OFFSET g_dispatchSave901_004d56d8
        mov      dword ptr [g_walkCallback], 0x24b
        shr      eax, 2
        mov      dword ptr [g_eventQueueCurrent], 4
        mov      dword ptr [g_acc_00542078], 0
        mov      dword ptr [g_eventQueueNotMask], 0xffc90000
        mov      dword ptr [g_xformEntityIdx], eax
        call     Push70CallScaleArith
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_1aa1
        mov      dword ptr [g_eventQueueWorkType], 0x48
        call     Push16Call
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_1aa1
        mov      dword ptr [esi + 8], OFFSET L_18b0
        mov      dword ptr [esi + 0x84], ebx
        mov      dword ptr [g_pendingNodeType], 0x10
        mov      dword ptr [g_framePauseFlag], ebx
    L_1aa1:
        pop      esi
        pop      ebx
        ret
    L_1aa4:
        test     eax, eax
        je       short L_1ae4
    L_1aa8:
        mov      eax, dword ptr [g_clamp_0053a6dc]
        mov      ecx, dword ptr [g_clamp_00537f2c]
        cmp      eax, ecx
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [g_eventQueueCurrent], ecx
        jg       short L_1ae4
        jl       L_1920
        cmp      eax, 0x10000
        je       L_192f
        call     DualAddSar_004ab600
        test     byte ptr [g_walkCallback], bl
        jne      L_1920
    L_1ae4:
        mov      dword ptr [g_walkCallback], ebx
        mov      dword ptr [g_audioBankSel], ebx
        call     StackPopDispatchTagged
        pop      esi
        pop      ebx
        ret
    }
}
