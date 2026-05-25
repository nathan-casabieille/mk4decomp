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

extern unsigned int g_data_004eec10;
extern unsigned int g_data_004eec28;
extern unsigned int g_data_004eec40;
extern unsigned int g_data_004eec68;
extern unsigned int g_data_004eec90;
extern unsigned int g_data_004eecc0;
extern unsigned int g_data_004eece8;
extern unsigned int g_framePauseFlag;
extern unsigned int g_currentNodeIdx;
extern unsigned int g_pendingNodeType;
extern unsigned int g_data_00542060;
extern unsigned int g_eventQueueChild;
extern unsigned int g_xformDirtyFlags;
extern void ArgSarStoreJmp_004594f0(void);
extern void CmpP1DualInitStore_00482ab0(void);
extern void FiveCallGuardSetTail_0046f6b0(void);
extern void GateDispatch6c_00494580(void);
extern void Phase3Packed3EntryDispatch_00486130(void);
extern void QuadBlockDispatch_00483090(void);
extern void QuadBlockInstallChainThunks_00483c90(void);
extern void ScaledAndAlf7_00490310(void);
extern void ScaledCmpJlJmp_00488ed0(void);
extern void ScaledDecOrZero_00483b50(void);
extern void ScaledMove48to58_00490720(void);

__declspec(naked) void OutroEventForwarderCluster_00485e70(void)
{
    __asm {
    L_5e70:
        call     ScaledAndAlf7_00490310
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_5e8d
        mov      dword ptr [g_walkCallback], 3
        jmp      ScaledCmpJlJmp_00488ed0
    L_5e8d:
        ret
        nop
        nop
        call     ScaledDecOrZero_00483b50
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_5efc
        call     ScaledAndAlf7_00490310
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_5efc
        mov      eax, dword ptr [g_data_00542060]
        mov      ecx, dword ptr [eax*4 + 0x80]
        cmp      ecx, 0x3333
        mov      dword ptr [g_walkCallback], ecx
        jl       short L_5ecb
        jmp      QuadBlockInstallChainThunks_00483c90
    L_5ecb:
        mov      eax, dword ptr [eax*4 + 0x34]
        cmp      eax, 0xf
        mov      dword ptr [g_walkCallback], eax
        jne      short L_5ee1
        jmp      QuadBlockInstallChainThunks_00483c90
    L_5ee1:
        call     L_5e70
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_5efc
        push     OFFSET g_data_004eec10
        call     ArgSarStoreJmp_004594f0
        add      esp, 4
    L_5efc:
        ret
        nop
        nop
        nop
        call     ScaledDecOrZero_00483b50
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_5f54
        call     ScaledAndAlf7_00490310
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_5f54
        mov      eax, dword ptr [g_data_00542060]
        mov      eax, dword ptr [eax*4 + 0x80]
        cmp      eax, 0x3333
        mov      dword ptr [g_walkCallback], eax
        jl       short L_5f39
        jmp      QuadBlockInstallChainThunks_00483c90
    L_5f39:
        call     L_5e70
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_5f54
        push     OFFSET g_data_004eec28
        call     ArgSarStoreJmp_004594f0
        add      esp, 4
    L_5f54:
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
        push     OFFSET g_data_004eec40
        call     ArgSarStoreJmp_004594f0
        add      esp, 4
        ret
        nop
        nop
        call     GateDispatch6c_00494580
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_5fa7
        call     CopyJmp_0048ef90
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_5fa7
        test     byte ptr [g_xformDirtyFlags], 1
        je       short L_5f9a
        jmp      QuadBlockDispatch_00483090
    L_5f9a:
        push     OFFSET g_data_004eec68
        call     ArgSarStoreJmp_004594f0
        add      esp, 4
    L_5fa7:
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        call     GateDispatch6c_00494580
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_5fe2
        mov      ecx, dword ptr [g_data_00542060]
        mov      eax, 0x100a
        mov      dword ptr [g_walkCallback], eax
        push     OFFSET g_data_004eec90
        mov      dword ptr [ecx*4 + 0x74], eax
        call     ArgSarStoreJmp_004594f0
        add      esp, 4
    L_5fe2:
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
        call     GateDispatch6c_00494580
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_600b
        push     OFFSET g_data_004eecc0
        call     ArgSarStoreJmp_004594f0
        add      esp, 4
    L_600b:
        ret
        nop
        nop
        nop
        nop
        mov      dword ptr [g_walkCallback], 0x9999
        call     CmpP1DualInitStore_00482ab0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_6051
        call     ScaledMove48to58_00490720
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_6051
        call     GateDispatch6c_00494580
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_6051
        push     OFFSET g_data_004eece8
        call     ArgSarStoreJmp_004594f0
        add      esp, 4
    L_6051:
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
    L_6060:
        mov      eax, dword ptr [g_data_00542060]
        xor      edx, edx
        shl      eax, 2
        push     edi
        mov      ecx, dword ptr [eax + 0x84]
        mov      dword ptr [eax + 0x84], edx
        sub      ecx, edx
        je       short L_60bb
        dec      ecx
        je       short L_6085
        call     FiveCallGuardSetTail_0046f6b0
        pop      edi
        ret
    L_6085:
        mov      ecx, dword ptr [g_eventQueueChild]
        dec      ecx
        mov      dword ptr [g_eventQueueChild], ecx
        jne      short L_60c5
        mov      dword ptr [eax + 8], OFFSET L_6060
        mov      dword ptr [eax + 0x84], 2
        mov      dword ptr [g_pendingNodeType], 0xf
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        ret
    L_60bb:
        mov      dword ptr [g_eventQueueChild], 0xa
    L_60c5:
        mov      dword ptr [g_currentNodeFlags], 0x147a
        mov      dword ptr [eax + 8], OFFSET L_6060
        mov      ecx, dword ptr [g_data_00542060]
        mov      edi, OFFSET L_6060
        add      edi, 0x1000000
        mov      dword ptr [ecx*4 + 0x84], 1
        mov      ecx, dword ptr [eax + 4]
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      dword ptr [ecx*4], edi
        mov      ecx, dword ptr [g_currentNodeIdx]
        inc      ecx
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      dword ptr [eax + 4], ecx
        mov      eax, dword ptr [g_data_00542060]
        mov      dword ptr [eax*4 + 0x84], edx
        call     Phase3Packed3EntryDispatch_00486130
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        ret
    }
}
