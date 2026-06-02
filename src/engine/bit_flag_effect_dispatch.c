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
extern void CopyJmp_0048ef90(void);
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

extern unsigned int g_or;
extern void Helper_SetState_02(void);
extern void Helper_SetState_03(void);
extern void Helper_SetState_04(void);
extern void Helper_SetState_05(void);
extern void Helper_SetState_06(void);
extern void Helper_SetState_07(void);
extern void Helper_SetState_09(void);
extern void Helper_SetState_0B(void);
extern void Helper_SetState_0C(void);
extern void Helper_SetState_0E(void);
extern void Helper_SetState_0F(void);
extern void Helper_SetState_10(void);
extern void Helper_SetState_1A(void);
extern void TableWalk3StrideCall(void);
extern void TenThunkDualSave(void);
extern void TripleBlockInstallSelfThunk(void);

__declspec(naked) void BitFlagEffectDispatch(void)
{
    __asm {
        mov      eax, dword ptr [g_or]
        mov      ecx, eax
        mov      dword ptr [g_walkCallback], eax
        and      ecx, 0x4000
        mov      dword ptr [g_xformScratch94], ecx
        je       short L_13e1
        call     Helper_SetState_1A
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1631
        mov      eax, dword ptr [g_or]
    L_13e1:
        mov      edx, eax
        mov      dword ptr [g_walkCallback], eax
        and      edx, 0x1000
        mov      dword ptr [g_xformScratch94], edx
        je       short L_140d
        call     Helper_SetState_0E
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1631
        mov      eax, dword ptr [g_or]
    L_140d:
        mov      ecx, eax
        mov      dword ptr [g_walkCallback], eax
        and      ecx, 0x800
        mov      dword ptr [g_xformScratch94], ecx
        je       short L_1439
        call     Helper_SetState_0C
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1631
        mov      eax, dword ptr [g_or]
    L_1439:
        mov      edx, eax
        mov      dword ptr [g_walkCallback], eax
        and      edx, 0x200
        mov      dword ptr [g_xformScratch94], edx
        je       short L_1465
        call     TenThunkDualSave
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1631
        mov      eax, dword ptr [g_or]
    L_1465:
        mov      ecx, eax
        mov      dword ptr [g_walkCallback], eax
        and      ecx, 0x100
        mov      dword ptr [g_xformScratch94], ecx
        je       short L_1491
        call     Helper_SetState_09
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1631
        mov      eax, dword ptr [g_or]
    L_1491:
        mov      edx, eax
        mov      dword ptr [g_walkCallback], eax
        and      edx, 2
        mov      dword ptr [g_xformScratch94], edx
        je       short L_14ba
        call     TripleBlockInstallSelfThunk
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1631
        mov      eax, dword ptr [g_or]
    L_14ba:
        mov      ecx, eax
        mov      dword ptr [g_walkCallback], eax
        and      ecx, 4
        mov      dword ptr [g_xformScratch94], ecx
        je       short L_14e3
        call     Helper_SetState_03
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1631
        mov      eax, dword ptr [g_or]
    L_14e3:
        mov      edx, eax
        mov      dword ptr [g_walkCallback], eax
        and      edx, 0x400
        mov      dword ptr [g_xformScratch94], edx
        je       short L_150f
        call     Helper_SetState_0B
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1631
        mov      eax, dword ptr [g_or]
    L_150f:
        mov      ecx, eax
        mov      dword ptr [g_walkCallback], eax
        and      ecx, 8
        mov      dword ptr [g_xformScratch94], ecx
        je       short L_1538
        call     Helper_SetState_04
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1631
        mov      eax, dword ptr [g_or]
    L_1538:
        mov      edx, eax
        mov      dword ptr [g_walkCallback], eax
        and      edx, 0x10
        mov      dword ptr [g_xformScratch94], edx
        je       short L_1561
        call     Helper_SetState_05
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_1631
        mov      eax, dword ptr [g_or]
    L_1561:
        mov      ecx, eax
        mov      dword ptr [g_walkCallback], eax
        and      ecx, 0x20
        mov      dword ptr [g_xformScratch94], ecx
        je       short L_158a
        call     Helper_SetState_06
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_1631
        mov      eax, dword ptr [g_or]
    L_158a:
        mov      edx, eax
        mov      dword ptr [g_walkCallback], eax
        and      edx, 0x40
        mov      dword ptr [g_xformScratch94], edx
        je       short L_15b3
        call     Helper_SetState_07
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_1631
        mov      eax, dword ptr [g_or]
    L_15b3:
        mov      ecx, eax
        mov      dword ptr [g_walkCallback], eax
        and      ecx, 0x80
        mov      dword ptr [g_xformScratch94], ecx
        je       short L_15db
        call     TableWalk3StrideCall
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_1631
        mov      eax, dword ptr [g_or]
    L_15db:
        mov      ecx, eax
        and      ecx, 0x2001
        cmp      ecx, 0x2001
        mov      dword ptr [g_walkCallback], ecx
        je       short L_1632
        mov      edx, eax
        mov      dword ptr [g_walkCallback], eax
        and      edx, 1
        mov      dword ptr [g_xformScratch94], edx
        je       short L_1616
        call     Helper_SetState_02
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_1631
        mov      eax, dword ptr [g_or]
    L_1616:
        mov      dword ptr [g_walkCallback], eax
        and      eax, 0x2000
        mov      dword ptr [g_xformScratch94], eax
        je       short L_1631
        call     Helper_SetState_0F
        mov      eax, dword ptr [g_framePauseFlag]
    L_1631:
        ret
    L_1632:
        jmp      Helper_SetState_10
    }
}
