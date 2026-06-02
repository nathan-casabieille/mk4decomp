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

extern unsigned int g_dispatchSave819_004f3ee0;
extern unsigned int g_dispatchSave121_005157a4;
extern unsigned int g_audioFlagAggBase2_00543398;
extern unsigned int g_audioFlagAggBase_005433d8;
extern void AudioFlagDispatchAggregatorAH_004aa520(void);
extern void AudioFlagDispatchAggregator_004aa430(void);
extern void BootPhaseGateBracketedInit(void);
extern void MStackBracket5_FieldClear_StateAdvance(void);
extern void MStackPush3HelperCondToggle_0049cf70(void);
extern void MStackPushComplexCallPop_00406430(void);
extern void SplitInt32_004aa410(void);

__declspec(naked) void SpawnListGlyphRender_004aa610(void)
{
    __asm {
        /* === Helper 1 (0x4aa610): linked-list walker w/ stride pos === */
    L_a610:
        push     ebx
        push     esi
        push     edi
        call     BootPhaseGateBracketedInit
        mov      al, byte ptr [g_xformDirtyFlags]
        mov      ebx, 4
        test     al, bl
        jne      L_a73d
        mov      edi, dword ptr [g_currentNodeIdx]
        or       dword ptr [edi*4 + 0x34], 0x20000
        call     MStackPushComplexCallPop_00406430
        mov      eax, dword ptr [g_framePauseFlag]
        xor      esi, esi
        cmp      eax, esi
        jne      short L_a73d
        call     MStackBracket5_FieldClear_StateAdvance
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      dword ptr [eax*4 + 0x24], esi
        mov      dword ptr [edi*4 + 0x18], eax
        mov      dword ptr [eax*4 + 0x18], edi
        mov      dword ptr [g_walkCallback], ebx
        call     MStackPush3HelperCondToggle_0049cf70
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      ecx, OFFSET g_dispatchSave121_005157a4
        shr      ecx, 2
        mov      dword ptr [g_eventQueueCurrent], 0xffffe667
        mov      dword ptr [g_xformEntityIdx], ecx
        mov      edx, eax
        mov      dword ptr [eax*4 + 0xc], ecx
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      ebx, dword ptr [g_eventQueueCurrent]
        mov      dword ptr [eax*4 + 4], ebx
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      ebx, 0xf5c
        mov      dword ptr [eax*4 + 8], esi
        mov      eax, dword ptr [g_eventQueueCurrent]
        add      eax, ebx
        mov      dword ptr [g_eventQueueCurrent], eax
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      eax, dword ptr [eax*4]
        cmp      eax, esi
        mov      dword ptr [g_currentNodeIdx], eax
        je       short L_a731
        push     ebp
    L_a6e4:
        mov      dword ptr [g_xformEntityIdx], ecx
        mov      dword ptr [eax*4 + 0xc], ecx
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      ebp, dword ptr [g_eventQueueCurrent]
        mov      dword ptr [eax*4 + 4], ebp
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      dword ptr [eax*4 + 8], esi
        mov      eax, dword ptr [g_eventQueueCurrent]
        add      eax, ebx
        mov      dword ptr [g_eventQueueCurrent], eax
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      eax, dword ptr [eax*4]
        cmp      eax, esi
        mov      dword ptr [g_currentNodeIdx], eax
        jne      short L_a6e4
        pop      ebp
    L_a731:
        mov      dword ptr [g_currentNodeIdx], edi
        mov      dword ptr [g_xformEntityIdx], edx
    L_a73d:
        pop      edi
        pop      esi
        pop      ebx
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
        /* === Helper 2 (0x4aa750): 4-glyph render loop === */
    L_a750:
        mov      eax, dword ptr [g_baseSel]
        push     ebx
        push     esi
        xor      esi, esi
        lea      ebx, [eax*4]
        push     edi
        mov      eax, dword ptr [ebx + 0x84]
        mov      dword ptr [ebx + 0x84], esi
        cmp      eax, esi
        jne      short L_a7e2
        mov      ecx, dword ptr [g_eventQueueEnd]
        mov      edx, dword ptr [g_gtPlayerProbe2]
        xor      eax, eax
    L_a77f:
        cmp      ecx, edx
        jne      short L_a78b
        mov      dword ptr [eax + g_audioFlagAggBase2_00543398], esi
        jmp      short L_a791
    L_a78b:
        mov      dword ptr [eax + g_audioFlagAggBase_005433d8], esi
    L_a791:
        add      eax, 4
        cmp      eax, 0x10
        jl       short L_a77f
        sub      ecx, edx
        neg      ecx
        sbb      ecx, ecx
        and      ecx, 0xf00000
        add      ecx, 0xff880000
        mov      edi, ecx
        call     L_a610
        mov      ecx, dword ptr [g_baseSel]
        mov      edx, dword ptr [g_xformEntityIdx]
        mov      dword ptr [ecx*4 + 0x30], edx
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      dword ptr [eax*4 + 0x54], edi
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [ecx*4 + 0x58], 0x6e0000
    L_a7e2:
        mov      edx, dword ptr [g_eventQueueEnd]
        mov      eax, dword ptr [g_gtPlayerProbe2]
        cmp      edx, eax
        jne      short L_a7f8
        call     AudioFlagDispatchAggregator_004aa430
        jmp      short L_a7fd
    L_a7f8:
        call     AudioFlagDispatchAggregatorAH_004aa520
    L_a7fd:
        mov      eax, dword ptr [g_baseSel]
        mov      ecx, dword ptr [eax*4 + 0x30]
        mov      dword ptr [g_currentNodeIdx], ecx
    L_a80f:
        mov      edx, dword ptr [g_eventQueueEnd]
        mov      eax, dword ptr [g_gtPlayerProbe2]
        cmp      edx, eax
        jne      short L_a827
        mov      eax, dword ptr [esi + g_audioFlagAggBase2_00543398]
        push     eax
        jmp      short L_a82e
    L_a827:
        mov      ecx, dword ptr [esi + g_audioFlagAggBase_005433d8]
        push     ecx
    L_a82e:
        call     SplitInt32_004aa410
        mov      edx, dword ptr [g_eventQueueCurrent]
        mov      ecx, dword ptr [g_currentNodeIdx]
        add      esi, 4
        add      esp, 4
        mov      eax, dword ptr [edx*4 + g_dispatchSave819_004f3ee0]
        shr      eax, 2
        mov      dword ptr [g_xformEntityIdx], eax
        mov      dword ptr [ecx*4 + 0xc], eax
        mov      edx, dword ptr [g_currentNodeIdx]
        cmp      esi, 0x10
        mov      eax, dword ptr [edx*4]
        mov      dword ptr [g_currentNodeIdx], eax
        jl       L_a80f
        mov      eax, 1
        pop      edi
        mov      dword ptr [ebx + 8], OFFSET L_a750
        mov      dword ptr [ebx + 0x84], eax
        pop      esi
        mov      dword ptr [g_pendingNodeType], eax
        mov      dword ptr [g_framePauseFlag], eax
        pop      ebx
        ret
    }
}
