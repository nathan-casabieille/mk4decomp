/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_state_004d57ac;
extern unsigned int g_scaledInit_00542044;
extern packed_ptr g_xformEntityIdx;
extern u32 g_eventQueueEnd;
extern unsigned int g_baseSel_00542060;
extern u32 g_eventQueueWorkType;
extern unsigned int g_acc_00542078;
extern unsigned int g_cj_0054205c;
extern u32 g_framePauseFlag;
extern unsigned int g_state_0053a718;
extern unsigned int g_eventQueueTotal;
extern unsigned int g_eventQueueCurrent;
extern unsigned int g_currentNodeFlags;
extern unsigned int g_xformDirtyFlags;
extern unsigned int g_xformScratch2088;
extern unsigned int g_state_00542094;
extern unsigned int g_state_00535ddc;
extern unsigned int g_state_00537e88;
extern unsigned int g_state_0053a408;
extern unsigned int g_state_00537f94;
extern unsigned int g_eventQueueChild;
extern u32 g_pendingNodeType;

extern void StoreTwoCall_0049cb40(int, int);
extern void SetJmp_0049cb90(void);
extern void Thunk_0049cbd0(void);
extern void ScaledZeroFour_00490740(void);
extern void WalkCbSubMul10_00431d50(void);
extern void Mul10Tail_00404af0(unsigned int a, unsigned int b);
extern void BootMod6487eClampAndChainMul10_00407510(void);
extern void SpawnListBatchLoader_00477710(void);
extern void MStackPush2TableNot_00426230(void);
extern void GuardedChainCmpDualBitXor_004299a0(void);
extern void ScaledLoadDecJmp_00429710(void);
extern void ScaledStoreCurDirtyClear_004296f0(void);
extern void MStackBitmaskIncMod_00492450(void);
extern void MStackBitmaskUpdate_00492510(void);
extern void Push1eCallTestDirtyLoop_004923b0(void);
extern void MStackLoopFieldInit_00492280(void);
extern void TaggedSceneDispatch_004be690(void);
extern void CallPauseDirty4StackPushFn_004839d0(void);
extern void CallPauseDirty1JmpDirty4StackPush_00483a80(void);
extern void Cmp2CallDirtyCall_004398b0(void);
extern void QuadBlockArgInstallChain_0043a950(void);
extern void InstallSelfChainSet84_80CallW_004363f0(void);
extern void Wrapper_00436490(void);
extern void MoveFsmCluster_004364a0(void);
extern void CallPauseTestByteJmpCalls_004390f0(void);
extern void InstallSelfFullPath_0047a840(void);
extern void InstallSelfCountdownChain_0047a950(void);
extern void CopyJmp_0048ef90(void);
extern void DualTestDirtyToggle_004282c0(void);
extern void TripleVecAccCallStore_00476880(void);
extern void Thunk_004bd5c0(void);
extern void AllocSlotPushTripleGlobals_00427470(void);
extern void MStackPop4Rewrite_004274f0(void);
extern void Push70CallScaleArith_00457ad0(void);
extern void StreamChainStringInstall_00457900(void);
extern void MStackFrameCdeclDouble_004903f0(void);
extern void ChainTableWalkStore_004917e0(void);
extern void Push16Call_00489f50(void);
extern void DispatcherComplex260_00407030(void);
extern void ScaledLoadCmpStoreXfm_0048f2a0(void);
extern void StackPopDispatchTagged_0041f780(void);
extern unsigned int g_eventQueueNotMask;
extern unsigned int g_cj_00542058;
extern unsigned int g_data_0053a180;
extern unsigned int g_state_00541fa4;
extern unsigned int g_state_00541fa8;
extern unsigned int g_state_0053a7b0;
extern unsigned int g_data_0053a770;
extern unsigned int g_data_0053a46c;

extern void ScaledArrStore_004298c0(void);
extern void DualFieldAddSubStore_00470340(void);
extern void IterStepDualStore_00490b40(int);
extern void ScaledXorStore_004900f0(void);
extern void ChainWalkInstall_0049b7c0(void);
extern void FpuSqrtMul_004ab350(void);
extern void PendingMatch_0042b930(void);
extern void MStackPush2RunCountdown_004089e0(void);
extern void MStackBracket7_DispatchAndChain_004b8fa0(void);
extern void MStackBracketed3StoreCall_00475990(void);
extern void ChainDirtyBitWalker_00408c10(void);
extern void Wrapper_0048a350(void);
extern void Wrapper_0048a3a0(void);
extern void Helper_DownloadSetup(void);
extern void MStackPush3CmpCall_0048eec0(void);
extern void Wrapper_0048ec20(void);
extern void FiveCallScaledChainTailJmp_0045f8d0(void);
extern void SetJmp_00438f50(void);
extern void SetJmp_00438f60(void);
extern void GuardedDispatch_0042b6c0(void);
extern void MStackPushZeroCallPop_00407d00(void);
extern void DirtyToggleByGate_0048f350(void);
extern void GameDispatchValidateState_004339c0(void);
extern void CrouchAttackFsmCluster_0046f7a0(void);
extern void MStackPushVec3Mul10_004767e0(void);
extern void LiteralPushCallEntZero_00488c00(void);
extern void LeaPlus22StoreSelf_0048e4d0(void);
extern void IterLoad_00491050(void);
extern void GuardedDualConst2AndToggle_0048eba0(void);
extern void CallPauseScaledStorePushCall_0045fca0(void);
extern void LoadGeoAsset_Default(void);
extern void DispatcherComplex260_00407400(void);
extern void PushSetCallPop_00406530(void);
extern unsigned int g_state_0053a3c0;
extern unsigned int g_state_00538158;
extern unsigned int g_data_00535cf8;
extern unsigned int g_cj_00542054;
extern unsigned int g_data_005437f0;
extern unsigned int g_data_00543598;
extern unsigned int g_data_0054358c;
extern unsigned int g_data_00535e70;
extern unsigned int g_data_00535e74;
extern unsigned int g_data_00535e78;
extern unsigned int g_data_00535e7c;

extern unsigned int g_data_004f3ee0;
extern unsigned int g_data_005157a4;
extern unsigned int g_data_00538038;
extern unsigned int g_framePauseFlag;
extern unsigned int g_currentNodeIdx;
extern unsigned int g_xformEntityIdx;
extern unsigned int g_pendingNodeType;
extern unsigned int g_eventQueueEnd;
extern unsigned int g_data_00542060;
extern unsigned int g_xformDirtyFlags;
extern unsigned int g_data_00543398;
extern unsigned int g_data_005433d8;
extern void AudioFlagDispatchAggregatorAH_004aa520(void);
extern void AudioFlagDispatchAggregator_004aa430(void);
extern void BootPhaseGateBracketedInit_004060c0(void);
extern void MStackBracket5_FieldClear_StateAdvance_00405630(void);
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
        call     BootPhaseGateBracketedInit_004060c0
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
        call     MStackBracket5_FieldClear_StateAdvance_00405630
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      dword ptr [eax*4 + 0x24], esi
        mov      dword ptr [edi*4 + 0x18], eax
        mov      dword ptr [eax*4 + 0x18], edi
        mov      dword ptr [g_walkCallback], ebx
        call     MStackPush3HelperCondToggle_0049cf70
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      ecx, OFFSET g_data_005157a4
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
        mov      eax, dword ptr [g_data_00542060]
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
        mov      edx, dword ptr [g_data_00538038]
        xor      eax, eax
    L_a77f:
        cmp      ecx, edx
        jne      short L_a78b
        mov      dword ptr [eax + g_data_00543398], esi
        jmp      short L_a791
    L_a78b:
        mov      dword ptr [eax + g_data_005433d8], esi
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
        mov      ecx, dword ptr [g_data_00542060]
        mov      edx, dword ptr [g_xformEntityIdx]
        mov      dword ptr [ecx*4 + 0x30], edx
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      dword ptr [eax*4 + 0x54], edi
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [ecx*4 + 0x58], 0x6e0000
    L_a7e2:
        mov      edx, dword ptr [g_eventQueueEnd]
        mov      eax, dword ptr [g_data_00538038]
        cmp      edx, eax
        jne      short L_a7f8
        call     AudioFlagDispatchAggregator_004aa430
        jmp      short L_a7fd
    L_a7f8:
        call     AudioFlagDispatchAggregatorAH_004aa520
    L_a7fd:
        mov      eax, dword ptr [g_data_00542060]
        mov      ecx, dword ptr [eax*4 + 0x30]
        mov      dword ptr [g_currentNodeIdx], ecx
    L_a80f:
        mov      edx, dword ptr [g_eventQueueEnd]
        mov      eax, dword ptr [g_data_00538038]
        cmp      edx, eax
        jne      short L_a827
        mov      eax, dword ptr [esi + g_data_00543398]
        push     eax
        jmp      short L_a82e
    L_a827:
        mov      ecx, dword ptr [esi + g_data_005433d8]
        push     ecx
    L_a82e:
        call     SplitInt32_004aa410
        mov      edx, dword ptr [g_eventQueueCurrent]
        mov      ecx, dword ptr [g_currentNodeIdx]
        add      esi, 4
        add      esp, 4
        mov      eax, dword ptr [edx*4 + g_data_004f3ee0]
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
