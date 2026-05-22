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
extern unsigned int g_data_00542050;
extern unsigned int g_data_00542070;
extern unsigned int g_data_00542084;
extern unsigned int g_state_0054208c;
extern unsigned int g_state_00542088;
extern unsigned int g_state_00542094;
extern unsigned int g_state_00535ddc;
extern unsigned int g_state_00537e88;
extern unsigned int g_state_0053a408;
extern unsigned int g_state_00537f94;
extern unsigned int g_state_00542080;
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
extern unsigned int g_state_0054207c;
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

/* ------------------------------------------------------------------ */
/* Throw-grab pose-copy cluster (592b game, 2 packed helpers)          */
/* ------------------------------------------------------------------ */
extern void MStackPushTwoEntryChainCall_004058c0(void);
extern void MStackPush2ChainLLInsert_00406790(void);
extern void func_0047ef70(void);
extern void AerialBlockFsmCluster_0047f730(void);
extern void func_0047fa30(void);
/* extern void AllocNode(void); -- defined elsewhere with diff sig */
extern unsigned int g_data_004ed778;
extern unsigned int g_data_0050b8dc;

extern unsigned int g_data_004d57ac;
extern unsigned int g_data_0052ab10;
extern unsigned int g_data_00535ddc;
extern unsigned int g_data_00541e6c;
extern unsigned int g_data_00542044;
extern unsigned int g_data_00542048;
extern unsigned int g_data_0054204c;
extern unsigned int g_data_00542054;
extern unsigned int g_data_0054205c;
extern unsigned int g_data_00542060;
extern unsigned int g_data_0054206c;
extern unsigned int g_data_00542074;
extern unsigned int g_data_0054207c;
extern unsigned int g_data_0054208c;
extern void EntryThunkBodyStateMachine_00457bb0(void);
extern void InstallSelfIndirectJmp_0048f3f0(void);
extern void MStackPushDispatchBitGate_00407330(void);
extern void ScaledIndexConditionalAdd_0048e400(void);
extern void TripleScaledChainStore_004908f0(void);

__declspec(naked) void ThrowGrabPoseCopyCluster_0047f4e0(void)
{
    __asm {
        /* === Helper 1 (0x47f4e0): grab finalize event === */
        mov      dword ptr [g_data_0054207c], 0
        call     EntryThunkBodyStateMachine_00457bb0
        mov      eax, dword ptr [g_data_00541e6c]
        test     eax, eax
        jne      short L_f529
        push     OFFSET g_data_004ed778
        call     TripleScaledChainStore_004908f0
        mov      eax, dword ptr [g_data_00541e6c]
        add      esp, 4
        test     eax, eax
        jne      short L_f529
        mov      eax, dword ptr [g_data_004d57ac]
        inc      eax
        mov      dword ptr [g_data_004d57ac], eax
        mov      dword ptr [eax*4], OFFSET func_0047ef70
        jmp      InstallSelfIndirectJmp_0048f3f0
    L_f529:
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        /* === Helper 2: 0x405 anim w/ source-pose copy === */
        mov      dword ptr [g_data_0054206c], 6
        call     ScaledIndexConditionalAdd_0048e400
        mov      eax, dword ptr [g_data_00541e6c]
        test     eax, eax
        jne      L_f72f
        mov      eax, dword ptr [g_data_00542060]
        mov      dword ptr [eax*4 + 0x74], 0x406
        mov      eax, dword ptr [g_data_00535ddc]
        cmp      eax, 0x10000
        mov      dword ptr [g_data_0054206c], eax
        jge      short L_f572
        jmp      AerialBlockFsmCluster_0047f730
    L_f572:
        mov      ecx, dword ptr [g_data_00542060]
        mov      eax, 0x405
        mov      dword ptr [g_data_0054206c], eax
        mov      edx, OFFSET g_data_0050b8dc
        mov      dword ptr [ecx*4 + 0x74], eax
        mov      eax, dword ptr [g_data_004d57ac]
        mov      ecx, dword ptr [g_data_0054205c]
        shr      edx, 2
        inc      eax
        mov      dword ptr [g_data_00542048], edx
        mov      dword ptr [g_data_004d57ac], eax
        mov      dword ptr [eax*4], ecx
        call     MStackPushDispatchBitGate_00407330
        mov      eax, dword ptr [g_data_00541e6c]
        test     eax, eax
        jne      L_f72f
        mov      eax, dword ptr [g_data_004d57ac]
        mov      edx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_data_004d57ac], eax
        mov      al, byte ptr [g_data_0054208c]
        test     al, 4
        mov      dword ptr [g_data_0054205c], edx
        je       short L_f5e7
        jmp      AerialBlockFsmCluster_0047f730
    L_f5e7:
        call     MStackPushTwoEntryChainCall_004058c0
        mov      eax, dword ptr [g_data_00541e6c]
        test     eax, eax
        jne      L_f72f
        mov      eax, dword ptr [g_data_00542044]
        mov      ecx, dword ptr [g_data_0054205c]
        shl      eax, 2
        shl      ecx, 2
        mov      edx, dword ptr [eax + 0x1c]
        mov      dword ptr [g_data_00542048], edx
        mov      edx, dword ptr [edx*4 + 0x10]
        mov      dword ptr [g_data_00542048], edx
        mov      dword ptr [edx*4 + 0x34], 0
        mov      edx, 0x73
        mov      dword ptr [g_data_0054206c], edx
        mov      dword ptr [eax + 0x30], edx
        mov      edx, dword ptr [ecx + 0x54]
        mov      dword ptr [g_data_0054206c], edx
        mov      dword ptr [eax + 0x54], edx
        mov      edx, dword ptr [ecx + 0x58]
        mov      dword ptr [g_data_0054206c], edx
        mov      dword ptr [eax + 0x58], edx
        mov      edx, dword ptr [ecx + 0x5c]
        mov      dword ptr [g_data_0054206c], edx
        mov      dword ptr [eax + 0x5c], edx
        mov      edx, dword ptr [ecx + 0x60]
        mov      dword ptr [g_data_0054206c], edx
        mov      dword ptr [eax + 0x60], edx
        mov      edx, dword ptr [ecx + 0x64]
        mov      dword ptr [g_data_0054206c], edx
        mov      dword ptr [eax + 0x64], edx
        mov      edx, dword ptr [ecx + 0x68]
        mov      dword ptr [g_data_0054206c], edx
        mov      dword ptr [eax + 0x68], edx
        mov      edx, dword ptr [ecx + 0x34]
        mov      dword ptr [g_data_0054206c], edx
        mov      dword ptr [eax + 0x34], edx
        mov      edx, dword ptr [ecx + 0x24]
        mov      dword ptr [g_data_0054206c], edx
        mov      dword ptr [eax + 0x24], edx
        mov      edx, dword ptr [ecx + 0x28]
        mov      dword ptr [g_data_0054206c], edx
        mov      dword ptr [eax + 0x28], edx
        mov      edx, dword ptr [ecx + 0x3c]
        mov      dword ptr [eax + 0x3c], edx
        mov      ecx, dword ptr [g_data_0052ab10]
        mov      dword ptr [g_data_0054206c], ecx
        mov      dword ptr [eax + 0x3c], ecx
        mov      eax, dword ptr [g_data_00542044]
        mov      ecx, dword ptr [g_data_00542060]
        mov      dword ptr [g_data_00542054], eax
        mov      dword ptr [g_data_00542074], 0x45
        mov      eax, dword ptr [ecx*4 + 0xc]
        cmp      eax, 1
        mov      dword ptr [g_data_0054206c], eax
        je       short L_f6ef
        mov      dword ptr [g_data_00542074], 0x46
    L_f6ef:
        mov      dword ptr [g_data_0054204c], OFFSET func_0047fa30
        call     AllocNode
        mov      eax, dword ptr [g_data_00541e6c]
        test     eax, eax
        jne      short L_f72f
        mov      al, byte ptr [g_data_0054208c]
        mov      edx, dword ptr [g_data_00542054]
        test     al, 1
        mov      dword ptr [g_data_00542044], edx
        je       short L_f72a
        call     MStackPush2ChainLLInsert_00406790
        mov      eax, dword ptr [g_data_00541e6c]
        test     eax, eax
        jne      short L_f72f
    L_f72a:
        jmp      AerialBlockFsmCluster_0047f730
    L_f72f:
        ret
    }
}
