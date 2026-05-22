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

extern unsigned int g_const_0049db40;
extern unsigned int g_data_004d57ac;
extern unsigned int g_data_004ec220;
extern unsigned int g_data_004ec270;
extern unsigned int g_data_004ec2c0;
extern unsigned int g_data_00541e6c;
extern unsigned int g_data_00542044;
extern unsigned int g_data_00542054;
extern unsigned int g_data_00542058;
extern unsigned int g_data_0054205c;
extern unsigned int g_data_0054206c;
extern unsigned int g_data_0054207c;
extern unsigned int g_data_0054208c;
extern void StoreDoubleNegPauseSubStore_004ab750(void);
extern void ZeroAndDirty4_00405430(void);

__declspec(naked) void SpawnImpactExplosion_00471be0(void)
{
    __asm {
        mov      eax, dword ptr [g_data_004d57ac]
        mov      ecx, dword ptr [g_data_0054207c]
        inc      eax
        push     esi
        mov      dword ptr [g_data_004d57ac], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_data_004d57ac]
        mov      edx, dword ptr [g_data_00542058]
        inc      eax
        mov      dword ptr [g_data_004d57ac], eax
        mov      dword ptr [eax*4], edx
        mov      eax, dword ptr [g_data_004d57ac]
        mov      ecx, dword ptr [g_data_00542044]
        inc      eax
        mov      dword ptr [g_data_004d57ac], eax
        mov      dword ptr [eax*4], ecx
        mov      edx, dword ptr [g_data_0054205c]
        mov      eax, OFFSET g_data_004ec220
        mov      dword ptr [g_data_00542054], edx
        shr      eax, 2
        mov      dword ptr [g_data_00542058], eax
        mov      dword ptr [g_data_0054206c], 0xc000
        call     ZeroAndDirty4_00405430
        mov      eax, dword ptr [g_data_00541e6c]
        xor      esi, esi
        cmp      eax, esi
        jne      L_1dfa
        test     byte ptr [g_data_0054208c], 4
        jne      short L_1ca9
        mov      ecx, OFFSET g_data_004ec270
        mov      dword ptr [g_data_0054206c], 0xd999
        shr      ecx, 2
        mov      dword ptr [g_data_00542058], ecx
        call     ZeroAndDirty4_00405430
        cmp      dword ptr [g_data_00541e6c], esi
        jne      L_1dfa
        test     byte ptr [g_data_0054208c], 4
        jne      short L_1ca9
        mov      edx, OFFSET g_data_004ec2c0
        shr      edx, 2
        mov      dword ptr [g_data_00542058], edx
    L_1ca9:
        push     0xc0
        push     OFFSET g_const_0049db40
        mov      dword ptr [g_data_0054207c], 0xc1
        call     StoreTwoCall_0049cb40
        mov      al, byte ptr [g_data_0054208c]
        add      esp, 8
        test     al, 1
        jne      L_1dbc
        mov      dword ptr [g_data_00542070], esi
        mov      dword ptr [g_data_0054206c], 0xc28f
        call     StoreDoubleNegPauseSubStore_004ab750
        cmp      dword ptr [g_data_00541e6c], esi
        jne      short L_1dfa
        mov      eax, dword ptr [g_data_0054206c]
        mov      ecx, dword ptr [g_data_00542070]
        mov      edx, dword ptr [g_data_00542044]
        add      ecx, eax
        mov      dword ptr [edx*4 + 0x38], ecx
        mov      dword ptr [g_data_00542070], 0xfffe0000
        mov      dword ptr [g_data_0054206c], 0xdc28
        call     StoreDoubleNegPauseSubStore_004ab750
        cmp      dword ptr [g_data_00541e6c], esi
        jne      short L_1dfa
        mov      eax, dword ptr [g_data_0054206c]
        mov      ecx, dword ptr [g_data_00542070]
        mov      edx, dword ptr [g_data_00542044]
        add      ecx, eax
        mov      dword ptr [edx*4 + 0x3c], ecx
        mov      dword ptr [g_data_00542070], 0xc4000
        mov      dword ptr [g_data_0054206c], 0x5c28
        call     StoreDoubleNegPauseSubStore_004ab750
        cmp      dword ptr [g_data_00541e6c], esi
        jne      short L_1dfa
        mov      eax, dword ptr [g_data_00542070]
        mov      ecx, dword ptr [g_data_0054206c]
        add      eax, ecx
        mov      ecx, dword ptr [g_data_00542044]
        mov      dword ptr [g_data_00542070], eax
        mov      dword ptr [ecx*4 + 0x40], eax
        mov      edx, dword ptr [g_data_00542044]
        mov      dword ptr [edx*4 + 0x44], esi
        mov      eax, dword ptr [g_data_00542044]
        mov      dword ptr [eax*4 + 0x48], esi
        mov      ecx, dword ptr [g_data_00542044]
        mov      dword ptr [g_data_0054206c], esi
        mov      dword ptr [ecx*4 + 0x4c], esi
    L_1dbc:
        mov      eax, dword ptr [g_data_004d57ac]
        mov      edx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_data_00542044], edx
        mov      dword ptr [g_data_004d57ac], eax
        mov      ecx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_data_00542058], ecx
        mov      dword ptr [g_data_004d57ac], eax
        mov      edx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_data_0054207c], edx
        mov      dword ptr [g_data_004d57ac], eax
    L_1dfa:
        pop      esi
        ret
    }
}
