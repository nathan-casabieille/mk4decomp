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

extern unsigned int g_framePauseFlag;
extern unsigned int g_data_00542044;
extern unsigned int g_data_0054206c;
extern void AudioMixerStep_004ab700(void);
extern void EsiTripleMul10Vec_00440660(void);
extern void GatedWordPushCall_00489f90(void);
extern void ScaledAddStore_004406e0(void);
extern void SetJmp_00440720(void);
extern void StoreDoubleNegPauseSubStore_004ab750(void);

__declspec(naked) void CameraBounceUpdate_00440430(void)
{
    __asm {
        push     esi
        call     ScaledAddStore_004406e0
        mov      eax, dword ptr [g_framePauseFlag]
        xor      esi, esi
        cmp      eax, esi
        jne      L_0657
        mov      ecx, dword ptr [g_data_00542044]
        mov      eax, dword ptr [ecx*4 + 0x58]
        cmp      eax, esi
        mov      dword ptr [g_data_0054206c], eax
        jge      short L_0472
        cmp      eax, 0xfffff334
        jge      L_0527
        call     SetJmp_00440720
        mov      eax, dword ptr [g_framePauseFlag]
        pop      esi
        ret
    L_0472:
        je       L_0657
        mov      dword ptr [g_data_0054206c], esi
        mov      dword ptr [ecx*4 + 0x58], esi
        mov      eax, dword ptr [g_data_00542044]
        mov      eax, dword ptr [eax*4 + 0x70]
        push     eax
        push     0xffff999a
        mov      dword ptr [g_data_00542070], eax
        call     Mul10Tail_00404af0
        add      esp, 8
        cmp      eax, 0xfffffd71
        mov      dword ptr [g_data_00542070], eax
        jle      short L_052e
        mov      ecx, dword ptr [g_data_00542044]
        mov      dword ptr [g_data_0054206c], esi
        mov      dword ptr [ecx*4 + 0x6c], esi
        mov      edx, dword ptr [g_data_0054206c]
        lea      eax, [ecx*4]
        mov      dword ptr [eax + 0x70], edx
        mov      ecx, dword ptr [g_data_0054206c]
        mov      dword ptr [eax + 0x74], ecx
        mov      edx, dword ptr [g_data_0054206c]
        mov      dword ptr [eax + 0x78], edx
        mov      ecx, dword ptr [g_data_0054206c]
        mov      dword ptr [eax + 0x7c], ecx
        mov      edx, dword ptr [g_data_0054206c]
        mov      dword ptr [eax + 0x80], edx
        mov      ecx, dword ptr [g_data_0054206c]
        mov      dword ptr [eax + 0x4c], ecx
        mov      ecx, 0xfffffae2
        mov      dword ptr [g_data_0054206c], ecx
        mov      edx, dword ptr [eax + 0x54]
        mov      dword ptr [eax + 0x58], ecx
        mov      dword ptr [g_data_0054206c], edx
        mov      eax, dword ptr [eax + 0x5c]
        mov      dword ptr [g_data_00542070], eax
        call     MStackBracketed3StoreCall_00475990
    L_0527:
        mov      eax, dword ptr [g_framePauseFlag]
        pop      esi
        ret
    L_052e:
        mov      dword ptr [g_data_0054206c], 0x19
        call     GatedWordPushCall_00489f90
        cmp      dword ptr [g_framePauseFlag], esi
        jne      L_0657
        mov      dword ptr [g_data_0054206c], 0x20c
        call     StoreDoubleNegPauseSubStore_004ab750
        cmp      dword ptr [g_framePauseFlag], esi
        jne      L_0657
        mov      eax, dword ptr [g_data_00542070]
        mov      edx, dword ptr [g_data_0054206c]
        mov      ecx, dword ptr [g_data_00542044]
        add      eax, edx
        mov      dword ptr [g_data_00542070], eax
        mov      dword ptr [ecx*4 + 0x70], eax
        mov      edx, dword ptr [g_data_00542044]
        mov      eax, dword ptr [edx*4 + 0x6c]
        push     eax
        push     0x6666
        mov      dword ptr [g_data_00542070], eax
        call     Mul10Tail_00404af0
        add      esp, 8
        mov      dword ptr [g_data_00542070], eax
        mov      dword ptr [g_data_0054206c], 0x20000
        call     AudioMixerStep_004ab700
        cmp      dword ptr [g_framePauseFlag], esi
        jne      short L_0657
        mov      eax, dword ptr [g_data_00542070]
        mov      ecx, dword ptr [g_data_0054206c]
        push     eax
        push     ecx
        call     Mul10Tail_00404af0
        mov      edx, dword ptr [g_data_00542044]
        mov      dword ptr [g_data_00542070], eax
        add      esp, 8
        mov      dword ptr [edx*4 + 0x6c], eax
        mov      eax, dword ptr [g_data_00542044]
        mov      eax, dword ptr [eax*4 + 0x74]
        push     eax
        push     0x6666
        mov      dword ptr [g_data_00542070], eax
        call     Mul10Tail_00404af0
        add      esp, 8
        mov      dword ptr [g_data_00542070], eax
        mov      dword ptr [g_data_0054206c], 0x30000
        call     AudioMixerStep_004ab700
        cmp      dword ptr [g_framePauseFlag], esi
        jne      short L_0657
        mov      ecx, dword ptr [g_data_00542070]
        mov      edx, dword ptr [g_data_0054206c]
        push     ecx
        push     edx
        call     Mul10Tail_00404af0
        mov      ecx, dword ptr [g_data_00542044]
        add      esp, 8
        mov      dword ptr [ecx*4 + 0x74], eax
        mov      dword ptr [g_data_00542070], 0xffff0ccd
        call     EsiTripleMul10Vec_00440660
    L_0657:
        pop      esi
        ret
    }
}
