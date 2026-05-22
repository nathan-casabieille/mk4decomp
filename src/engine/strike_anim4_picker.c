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

extern unsigned int g_data_004d57ac;
extern unsigned int g_data_0052ab40;
extern unsigned int g_data_00538038;
extern unsigned int g_data_0053a430;
extern unsigned int g_data_00541e6c;
extern unsigned int g_data_00541ec4;
extern unsigned int g_data_00541ec8;
extern unsigned int g_data_00542044;
extern unsigned int g_data_00542048;
extern unsigned int g_data_0054204c;
extern unsigned int g_data_0054205c;
extern unsigned int g_data_00542060;
extern unsigned int g_data_0054206c;
extern unsigned int g_data_0054208c;
extern unsigned int g_data_00542094;
extern unsigned int g_data_00543200;
extern unsigned int g_data_00543250;
extern unsigned int g_data_005432a0;
extern void DirtyDoubleDeref_00408cb0(void);
extern void MStackBracket1_TreeWalkRecursive2_00406dd0(void);
extern void MStackChainDecodeCall_004936f0(void);
extern void MStackPush2ChainPrepend_00409970(void);
extern void MStackPushCallCallPop_00405e20(void);
extern void PushSetCallCleanup_00408580(void);
extern void ScaledAddDeref_00494800(void);
extern void ScaledLoadJmp30_00493eb0(void);
extern void ScaledTestPauseStore_00408860(void);
extern void TestStoreConstJmp_004933b0(void);

void StrikeAnim4Picker_00493100(void) {
    __asm {
        mov      eax, dword ptr [g_data_0052ab40]
        mov      dword ptr [g_data_00542070], eax
        and      eax, 0x20
        mov      dword ptr [g_data_00542094], eax
        je       short L_3126
        call     TestStoreConstJmp_004933b0
        mov      eax, dword ptr [g_data_00541e6c]
        test     eax, eax
        jne      L_33a1
    L_3126:
        mov      eax, dword ptr [g_data_0053a430]
        mov      edx, dword ptr [g_data_00542060]
        test     eax, eax
        jne      short L_314d
        cmp      edx, dword ptr [g_data_00538038]
        jne      short L_3145
        mov      ecx, dword ptr [g_data_00541ec4]
        jmp      short L_314f
    L_3145:
        mov      ecx, dword ptr [g_data_00541ec8]
        jmp      short L_314f
    L_314d:
        xor      ecx, ecx
    L_314f:
        test     ecx, ecx
        je       short L_3158
        cmp      ecx, 1
        jne      short L_3162
    L_3158:
        mov      eax, OFFSET g_data_00543200
        shr      eax, 2
        jmp      short L_3167
    L_3162:
        mov      eax, dword ptr [g_data_00542044]
    L_3167:
        cmp      ecx, 2
        jne      short L_3174
        mov      eax, OFFSET g_data_00543250
        shr      eax, 2
    L_3174:
        cmp      ecx, 3
        jne      short L_3181
        mov      eax, OFFSET g_data_005432a0
        shr      eax, 2
    L_3181:
        add      eax, dword ptr [g_data_0054206c]
        mov      dword ptr [g_data_00542044], eax
        mov      eax, dword ptr [eax*4]
        mov      dword ptr [g_data_00542044], eax
        mov      dword ptr [edx*4 + 0x30], eax
        mov      dword ptr [g_data_0054206c], 1
        call     ScaledAddDeref_00494800
        mov      eax, dword ptr [g_data_00541e6c]
        test     eax, eax
        jne      L_33a1
        mov      eax, dword ptr [g_data_00542044]
        mov      dword ptr [g_data_0054206c], 2
        mov      dword ptr [g_data_00542048], eax
        call     ScaledAddDeref_00494800
        mov      eax, dword ptr [g_data_00541e6c]
        test     eax, eax
        jne      L_33a1
        mov      ecx, dword ptr [g_data_004d57ac]
        mov      eax, dword ptr [g_data_00542044]
        inc      ecx
        mov      dword ptr [g_data_0054204c], eax
        mov      dword ptr [g_data_004d57ac], ecx
        mov      dword ptr [ecx*4], eax
        mov      eax, dword ptr [g_data_004d57ac]
        mov      ecx, dword ptr [g_data_00542048]
        inc      eax
        mov      dword ptr [g_data_004d57ac], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_data_004d57ac]
        mov      edx, dword ptr [g_data_0054204c]
        inc      eax
        mov      dword ptr [g_data_004d57ac], eax
        mov      dword ptr [eax*4], edx
        mov      eax, dword ptr [g_data_004d57ac]
        mov      ecx, dword ptr [g_data_00542050]
        inc      eax
        mov      dword ptr [g_data_004d57ac], eax
        mov      dword ptr [eax*4], ecx
        call     MStackBracket1_TreeWalkRecursive2_00406dd0
        mov      eax, dword ptr [g_data_00541e6c]
        test     eax, eax
        jne      L_33a1
        test     byte ptr [g_data_0054208c], 4
        jne      L_3350
        mov      edx, dword ptr [g_data_00542044]
        mov      dword ptr [g_data_00542050], edx
        call     ScaledTestPauseStore_00408860
        mov      eax, dword ptr [g_data_00541e6c]
        test     eax, eax
        jne      L_33a1
        test     byte ptr [g_data_0054208c], 4
        jne      L_3342
        mov      eax, dword ptr [g_data_0054205c]
        mov      ecx, dword ptr [eax*4 + 0x1c]
        mov      dword ptr [g_data_00542048], ecx
        call     PushSetCallCleanup_00408580
        mov      eax, dword ptr [g_data_00541e6c]
        test     eax, eax
        jne      short L_33a1
        mov      edx, dword ptr [g_data_00542050]
        mov      dword ptr [g_data_00542044], edx
        call     MStackChainDecodeCall_004936f0
        mov      eax, dword ptr [g_data_00541e6c]
        test     eax, eax
        jne      short L_33a1
        mov      dword ptr [g_data_0054206c], 0xa
        call     DirtyDoubleDeref_00408cb0
        mov      eax, dword ptr [g_data_00541e6c]
        test     eax, eax
        jne      short L_33a1
        mov      eax, dword ptr [g_data_00542044]
        mov      ecx, dword ptr [g_data_00542050]
        mov      dword ptr [g_data_00542048], eax
        mov      dword ptr [g_data_00542044], ecx
        call     MStackPush2ChainPrepend_00409970
        mov      eax, dword ptr [g_data_00541e6c]
        test     eax, eax
        jne      short L_33a1
        call     ScaledLoadJmp30_00493eb0
        mov      eax, dword ptr [g_data_00541e6c]
        test     eax, eax
        jne      short L_33a1
        mov      ecx, dword ptr [g_data_0054205c]
        mov      eax, dword ptr [ecx*4 + 0x40]
        or       al, 2
        mov      dword ptr [g_data_00542070], eax
        mov      dword ptr [ecx*4 + 0x40], eax
        jmp      short L_3350
    L_3342:
        call     MStackPushCallCallPop_00405e20
        mov      eax, dword ptr [g_data_00541e6c]
        test     eax, eax
        jne      short L_33a1
    L_3350:
        mov      eax, dword ptr [g_data_004d57ac]
        mov      edx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_data_00542050], edx
        mov      dword ptr [g_data_004d57ac], eax
        mov      ecx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_data_0054204c], ecx
        mov      dword ptr [g_data_004d57ac], eax
        mov      edx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_data_00542048], edx
        mov      dword ptr [g_data_004d57ac], eax
        mov      ecx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_data_00542044], ecx
        mov      dword ptr [g_data_004d57ac], eax
    L_33a1:
        }
}

