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

extern unsigned int g_load_0052ab10;
extern unsigned int g_dispatchArr_00542188;
extern void AiAngleDistComputation_00431920(void);
extern void CameraAimSplineDriver_00430e60(void);
extern void DispatchOrInitFightGroup_0042f850(void);
extern void DualEntryInitDispatch_00431360(void);
extern void PendingMatch_00432110(void);
extern void PendingMatch_004326a0(void);
extern void ScaledInitWithCounterAndType_004314f0(void);

__declspec(naked) void PoseFsmTriHelpers_00431650(void)
{
    __asm {
        /* === h1 (0x431650): table-index wrapper, tail-jmp 31920 === */
        mov      ecx, dword ptr [g_eventQueueChild]
        mov      eax, OFFSET g_dispatchArr_00542188
        shr      eax, 2
        add      eax, ecx
        mov      dword ptr [g_currentNodeIdx], eax
        mov      eax, dword ptr [eax*4]
        mov      dword ptr [g_currentNodeIdx], eax
        jmp      AiAngleDistComputation_00431920
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
        /* === h2 (0x431680): pause-guarded chain → 4314f0 tail-jmp === */
        call     DualEntryInitDispatch_00431360
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_1700
        mov      eax, dword ptr [g_eventQueueEnd]
        mov      dword ptr [g_xformScratch2088], 0x10000
        mov      eax, dword ptr [eax*4 + 0x34]
        mov      dword ptr [g_walkCallback], eax
        and      eax, 1
        mov      dword ptr [g_xformScratch94], eax
        je       short L_16bd
        mov      dword ptr [g_xformScratch2088], 0xffff0000
    L_16bd:
        mov      ecx, dword ptr [g_eventQueueChild]
        mov      eax, OFFSET g_dispatchArr_00542188
        shr      eax, 2
        add      eax, ecx
        mov      dword ptr [g_currentNodeIdx], eax
        mov      ecx, dword ptr [eax*4]
        mov      dword ptr [g_currentNodeIdx], ecx
        call     AiAngleDistComputation_00431920
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_1700
        call     PendingMatch_004326a0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_1700
        jmp      ScaledInitWithCounterAndType_004314f0
    L_1700:
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
        nop
        /* === h3 (0x431710): 3-case pose-fn dispatcher === */
    L_1710:
        mov      eax, dword ptr [g_baseSel]
        push     esi
        push     edi
        xor      edi, edi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], edi
        sub      eax, edi
        je       L_1853
        dec      eax
        je       L_1823
        dec      eax
        je       short L_1747
        call     DispatchOrInitFightGroup_0042f850
        pop      edi
        pop      esi
        ret
    L_1747:
        mov      edx, dword ptr [g_baseSel]
        mov      ecx, dword ptr [g_load_0052ab10]
        mov      dword ptr [g_fightGroupHead], ecx
        mov      dword ptr [g_walkCallback], edi
        lea      eax, [edx*4]
        mov      dword ptr [eax + 0x40], edi
        mov      ecx, dword ptr [g_walkCallback]
        mov      dword ptr [eax + 0x48], ecx
        call     CameraAimSplineDriver_00430e60
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_191d
        mov      edx, dword ptr [g_baseSel]
        mov      ecx, dword ptr [g_walkCallback]
        mov      dword ptr [edx*4 + 0x44], ecx
        lea      eax, [edx*4]
        mov      edx, dword ptr [g_eventQueueNotMask]
        mov      dword ptr [eax + 0x34], edx
        mov      ecx, dword ptr [g_eventQueueChild]
        mov      dword ptr [eax + 0x3c], ecx
        mov      ecx, 0x28
        mov      dword ptr [eax + 0x38], 0xfffe8000
        mov      dword ptr [g_walkCallback], ecx
        mov      dword ptr [eax + 0x30], ecx
        mov      dword ptr [esi + 8], OFFSET L_1710
        mov      edx, dword ptr [g_baseSel]
        mov      ecx, OFFSET L_1710
        add      ecx, 0x3000000
        mov      dword ptr [edx*4 + 0x84], 3
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      edx, dword ptr [g_baseSel]
        mov      dword ptr [edx*4 + 0x84], edi
        call     PendingMatch_00432110
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        ret
    L_1823:
        mov      eax, dword ptr [g_baseSel]
        mov      ecx, dword ptr [eax*4 + 0x78]
        mov      dword ptr [g_pendingNodeType], ecx
        mov      dword ptr [esi + 8], OFFSET L_1710
        mov      dword ptr [esi + 0x84], 2
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        ret
    L_1853:
        call     DualEntryInitDispatch_00431360
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_191d
        mov      edx, dword ptr [g_eventQueueEnd]
        mov      dword ptr [g_xformScratch2088], 0x10000
        mov      eax, dword ptr [edx*4 + 0x34]
        mov      dword ptr [g_walkCallback], eax
        and      eax, 1
        mov      dword ptr [g_xformScratch94], eax
        je       short L_1894
        mov      dword ptr [g_xformScratch2088], 0xffff0000
    L_1894:
        mov      ecx, dword ptr [g_eventQueueChild]
        mov      eax, OFFSET g_dispatchArr_00542188
        shr      eax, 2
        add      eax, ecx
        mov      dword ptr [g_currentNodeIdx], eax
        mov      eax, dword ptr [eax*4]
        mov      dword ptr [g_currentNodeIdx], eax
        call     AiAngleDistComputation_00431920
        cmp      dword ptr [g_framePauseFlag], edi
        jne      short L_191d
        mov      dword ptr [esi + 8], OFFSET L_1710
        mov      ecx, dword ptr [g_baseSel]
        mov      edx, OFFSET L_1710
        mov      dword ptr [ecx*4 + 0x84], 1
        mov      eax, dword ptr [esi + 4]
        add      edx, 0x1000000
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], edx
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      eax, dword ptr [g_baseSel]
        mov      dword ptr [eax*4 + 0x84], edi
        call     PendingMatch_00432110
        mov      dword ptr [g_framePauseFlag], 1
    L_191d:
        pop      edi
        pop      esi
        ret
    }
}
