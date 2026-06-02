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

extern unsigned int g_dispatchSave910;
extern unsigned int g_dispatchSave792;
extern unsigned int g_dispatchSave793;
extern unsigned int g_dispatchSave794;
extern unsigned int g_dispatchSave538;
extern unsigned int g_dispatchSave1703;
extern void ArgSarStoreJmp(void);
extern void ArgSar_Set0_Jmp(void);
extern void CallSetPause(void);
extern void CondPickDualStore(void);
extern void CopyThreeFields(void);
extern void DualCmpSwapStore(void);
extern void MStackPush8SlotInitPop8(void);
extern void PushSetXfmMaskCallPop(void);
extern void ScaledIndirectJmp_0049c850(void);
extern void ScaledStackCallPause(void);
extern void ThreeChanPackClamp(void);
extern void TripleEntry3Block(void);
extern void Vec3AccMul10ChainBlend(void);

__declspec(naked) void AiComboDispatcherCluster(void)
{
    __asm {
        /* === h1 (0x497470): main combo install === */
        mov      eax, dword ptr [g_baseSel]
        mov      ecx, dword ptr [g_currentNodeFlags]
        mov      dword ptr [eax*4 + 0x5c], ecx
        mov      edx, dword ptr [g_baseSel]
        mov      eax, dword ptr [g_xformScratch2088]
        mov      dword ptr [edx*4 + 0x60], eax
        mov      eax, dword ptr [g_matrixStackTop]
        mov      ecx, dword ptr [g_eventQueueChild]
        inc      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_matrixStackTop]
        mov      edx, dword ptr [g_fightGroupHead]
        inc      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], edx
        mov      eax, OFFSET g_dispatchSave910
        shr      eax, 2
        mov      dword ptr [g_walkCallback], eax
        call     PushSetXfmMaskCallPop
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_759d
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      eax, dword ptr [g_matrixStackTop]
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      edx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_fightGroupHead], edx
        mov      dl, byte ptr [g_xformDirtyFlags]
        mov      dword ptr [g_matrixStackTop], eax
        mov      ecx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_eventQueueChild], ecx
        test     dl, 4
        mov      dword ptr [g_matrixStackTop], eax
        je       short L_753d
        mov      ecx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      dword ptr [g_matrixStackTop], eax
        jmp      CallSetPause
    L_753d:
        inc      eax
        mov      edx, OFFSET g_dispatchSave538
        mov      dword ptr [g_matrixStackTop], eax
        shr      edx, 2
        mov      dword ptr [eax*4], ecx
        mov      dword ptr [g_eventQueueTotal], edx
        call     Vec3AccMul10ChainBlend
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_759d
        call     TripleEntry3Block
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      dword ptr [g_walkCallback], 0
        mov      dword ptr [eax*4 + 0x64], 0
        mov      eax, dword ptr [g_matrixStackTop]
        mov      ecx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_eventQueueChild], ecx
        mov      dword ptr [g_matrixStackTop], eax
    L_759d:
        ret
        nop
        nop
        /* === h2 (0x4975a0): event 004f2100 forwarder w/ 0x310 === */
        call     CondPickDualStore
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_75d2
        mov      ecx, dword ptr [g_baseSel]
        mov      eax, 0x310
        mov      dword ptr [g_walkCallback], eax
        push     OFFSET g_dispatchSave792
        mov      dword ptr [ecx*4 + 0x74], eax
        call     ArgSarStoreJmp
        add      esp, 4
    L_75d2:
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
        /* === h3 (0x4975e0): event 004f2158 chained w/ 0x3333 ratio === */
        push     esi
        call     DualCmpSwapStore
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_770d
        push     OFFSET g_dispatchSave793
        call     ScaledStackCallPause
        mov      eax, dword ptr [g_framePauseFlag]
        add      esp, 4
        test     eax, eax
        jne      L_770d
        test     byte ptr [g_xformDirtyFlags], 4
        je       short L_761d
        call     CallSetPause
        pop      esi
        ret
    L_761d:
        push     OFFSET g_dispatchSave1703
        call     ThreeChanPackClamp
        mov      eax, dword ptr [g_fightGroupHead]
        add      esp, 4
        push     eax
        call     CopyThreeFields
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [g_eventQueueWorkType], 0x9999
        add      esp, 4
        mov      eax, dword ptr [ecx*4 + 0x34]
        lea      esi, [ecx*4]
        mov      ecx, eax
        not      ecx
        and      ecx, 1
        mov      dword ptr [g_eventQueueCurrent], ecx
        je       short L_766f
        mov      dword ptr [g_eventQueueWorkType], 0xffff6667
    L_766f:
        and      al, 0xfe
        or       eax, ecx
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [esi + 0x34], eax
        mov      edx, dword ptr [g_eventQueueWorkType]
        mov      dword ptr [esi + 0x80], edx
        mov      eax, dword ptr [g_currentNodeFlags]
        push     eax
        push     0x3333
        call     Mul10Tail
        mov      ecx, dword ptr [g_xformScratch2088]
        add      esp, 8
        mov      dword ptr [g_currentNodeFlags], eax
        push     ecx
        push     0x3333
        call     Mul10Tail
        mov      edx, dword ptr [g_currentNodeFlags]
        mov      dword ptr [g_xformScratch2088], eax
        mov      dword ptr [esi + 0x6c], edx
        mov      eax, dword ptr [g_xformScratch2088]
        mov      dword ptr [esi + 0x74], eax
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      edx, dword ptr [g_baseSel]
        mov      dword ptr [g_fightGroupHead], ecx
        add      esp, 8
        mov      dword ptr [edx*4 + 0x5c], 0x30
        mov      eax, dword ptr [g_baseSel]
        mov      dword ptr [g_walkCallback], 1
        push     OFFSET g_dispatchSave794
        mov      dword ptr [eax*4 + 0x74], 1
        call     ArgSar_Set0_Jmp
        add      esp, 4
    L_770d:
        pop      esi
        ret
        nop
        /* === h4 (0x497720): combo state cycle 1→3, dec [+0x5c] === */
        push     0x100000
        call     ThreeChanPackClamp
        mov      eax, dword ptr [g_fightGroupHead]
        add      esp, 4
        push     eax
        call     CopyThreeFields
        mov      ecx, dword ptr [g_baseSel]
        add      esp, 4
        mov      eax, dword ptr [ecx*4 + 0x74]
        dec      eax
        mov      dword ptr [g_walkCallback], eax
        jne      short L_774a
        mov      eax, 3
        mov      dword ptr [g_walkCallback], eax
    L_774a:
        mov      dword ptr [ecx*4 + 0x74], eax
        mov      eax, dword ptr [g_walkCallback]
        test     eax, eax
        jne      short L_7768
        call     MStackPush8SlotInitPop8
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_7789
    L_7768:
        mov      ecx, dword ptr [g_baseSel]
        mov      eax, dword ptr [ecx*4 + 0x5c]
        dec      eax
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x5c], eax
        jne      short L_7789
        jmp      ScaledIndirectJmp_0049c850
    L_7789:
        ret
    }
}
