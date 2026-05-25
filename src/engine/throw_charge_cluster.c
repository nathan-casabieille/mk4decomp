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

extern unsigned int g_data_004d5324;
extern unsigned int g_data_004d57ac;
extern unsigned int g_framePauseFlag;
extern unsigned int g_data_00542044;
extern unsigned int g_data_0054204c;
extern unsigned int g_data_00542054;
extern unsigned int g_data_00542058;
extern unsigned int g_data_00542060;
extern unsigned int g_data_0054206c;
extern unsigned int g_data_00542074;
extern unsigned int g_data_0054208c;
extern void AudioMixerStep_004ab700(void);
extern void DispatcherComplex138_004760f0(void);
extern void MStackPush1MagicMod2_004244d0(void);
extern void MStackPush2ChainLLInsert_00406790(void);
extern void SetupVecFsmCluster_0043e3e0(void);
extern void StoreDoubleNegPauseSubStore_004ab750(void);
extern void StoreLoadJmp_00404ef0(void);
extern void ThrowFsmCluster_0044eaf0(void);
extern void Thunk_0049cbc0(void);

__declspec(naked) void ThrowChargeCluster_0044e750(void)
{
    __asm {
        mov      eax, dword ptr [g_data_00542044]
        push     esi
        mov      dword ptr [eax*4 + 0x30], 0x75
        mov      dword ptr [g_data_0054206c], 0x2147
        lea      esi, [eax*4]
        call     StoreDoubleNegPauseSubStore_004ab750
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_e8df
        mov      ecx, dword ptr [g_data_0054206c]
        mov      dword ptr [esi + 0x78], ecx
        mov      dword ptr [g_data_0054206c], 0x2147
        call     StoreDoubleNegPauseSubStore_004ab750
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_e8df
        mov      edx, dword ptr [g_data_0054206c]
        mov      dword ptr [esi + 0x7c], edx
        mov      dword ptr [g_data_0054206c], 0x2147
        call     StoreDoubleNegPauseSubStore_004ab750
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_e8df
        mov      eax, dword ptr [g_data_0054206c]
        mov      dword ptr [esi + 0x80], eax
        mov      ecx, dword ptr [g_data_004d5324]
        mov      dword ptr [g_data_0054206c], ecx
        call     AudioMixerStep_004ab700
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_e8df
        mov      edx, dword ptr [g_data_0054206c]
        mov      dword ptr [g_data_00542074], edx
        call     MStackPush1MagicMod2_004244d0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_e8df
        mov      eax, dword ptr [g_data_0054206c]
        push     eax
        push     0x2b85
        call     Mul10Tail_00404af0
        mov      ecx, dword ptr [g_data_00542070]
        add      esp, 8
        mov      dword ptr [g_data_0054206c], eax
        mov      dword ptr [g_data_00542074], eax
        push     ecx
        push     0x2b85
        call     Mul10Tail_00404af0
        add      esp, 8
        mov      dword ptr [g_data_00542070], eax
        mov      dword ptr [g_data_0054206c], 0xb333
        call     AudioMixerStep_004ab700
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_e8df
        mov      eax, dword ptr [g_data_0054206c]
        mov      edx, dword ptr [g_data_00542074]
        add      eax, 0x4ccc
        push     edx
        push     eax
        mov      dword ptr [g_data_0054206c], eax
        call     Mul10Tail_00404af0
        mov      ecx, dword ptr [g_data_0054206c]
        add      esp, 8
        mov      dword ptr [g_data_00542074], eax
        mov      eax, dword ptr [g_data_00542070]
        push     eax
        push     ecx
        call     Mul10Tail_00404af0
        mov      edx, dword ptr [g_data_00542074]
        mov      dword ptr [g_data_00542070], eax
        mov      dword ptr [esi + 0x6c], edx
        mov      eax, dword ptr [g_data_00542070]
        add      esp, 8
        mov      dword ptr [esi + 0x74], eax
        mov      dword ptr [g_data_0054206c], 0x11eb
        call     AudioMixerStep_004ab700
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_e8df
        mov      ecx, dword ptr [g_data_0054206c]
        mov      eax, 0xffffe3d8
        sub      eax, ecx
        mov      dword ptr [g_data_0054206c], eax
        mov      dword ptr [esi + 0x70], eax
    L_e8df:
        pop      esi
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
    L_e8f0:
        mov      eax, dword ptr [g_data_00542060]
        push     ebx
        push     ebp
        push     esi
        lea      ebp, [eax*4]
        xor      esi, esi
        push     edi
        mov      eax, dword ptr [ebp + 0x84]
        mov      dword ptr [ebp + 0x84], esi
        cmp      eax, esi
        jne      L_e91f
        push     OFFSET SetupVecFsmCluster_0043e3e0 + 0x2c0
        call     StoreLoadJmp_00404ef0
        add      esp, 4
    L_e91f:
        mov      edi, 0x75
        mov      bl, 4
    L_e926:
        mov      dword ptr [g_data_00542044], esi
    L_e92c:
        mov      dword ptr [g_data_0054206c], edi
        call     DispatcherComplex138_004760f0
        cmp      dword ptr [g_framePauseFlag], esi
        jne      L_ea0f
        test     byte ptr [g_data_0054208c], bl
        jne      L_e9f3
        mov      eax, dword ptr [g_data_00542044]
        mov      ecx, dword ptr [eax*4 + 0x58]
        cmp      ecx, esi
        mov      dword ptr [g_data_0054206c], ecx
        jl       L_e92c
        mov      ecx, dword ptr [eax*4 + 0x54]
        mov      dword ptr [g_data_0054206c], ecx
        mov      edx, dword ptr [eax*4 + 0x5c]
        mov      eax, dword ptr [g_data_004d57ac]
        mov      dword ptr [g_data_00542070], edx
        inc      eax
        mov      dword ptr [g_data_004d57ac], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_data_004d57ac]
        mov      ecx, dword ptr [g_data_00542070]
        inc      eax
        mov      dword ptr [g_data_004d57ac], eax
        mov      dword ptr [eax*4], ecx
        call     MStackPush2ChainLLInsert_00406790
        cmp      dword ptr [g_framePauseFlag], esi
        jne      L_ea0f
        mov      eax, dword ptr [g_data_004d57ac]
        mov      edx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_data_00542070], edx
        mov      dword ptr [g_data_004d57ac], eax
        mov      ecx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_data_0054206c], ecx
        mov      dword ptr [g_data_004d57ac], eax
        call     MStackBracketed3StoreCall_00475990
        cmp      dword ptr [g_framePauseFlag], esi
        jne      L_ea0f
        jmp      L_e926
    L_e9f3:
        mov      eax, 1
        mov      dword ptr [ebp + 8], OFFSET L_e8f0
        mov      dword ptr [ebp + 0x84], eax
        mov      dword ptr [g_data_0054204c], eax
        mov      dword ptr [g_framePauseFlag], eax
    L_ea0f:
        pop      edi
        pop      esi
        pop      ebp
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
    L_ea20:
        mov      eax, dword ptr [g_data_00542060]
        push     esi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        sub      eax, 0
        je       L_ea94
        dec      eax
        je       L_ea5f
        call     ThrowFsmCluster_0044eaf0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_eae8
        call     Thunk_0049cbc0
        pop      esi
        ret      
    L_ea5f:
        call     ThrowFsmCluster_0044eaf0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_eae8
        mov      dword ptr [esi + 8], OFFSET L_ea20
        mov      dword ptr [esi + 0x84], 2
        mov      dword ptr [g_data_0054204c], 0xf
        mov      dword ptr [g_framePauseFlag], 1
        pop      esi
        ret      
    L_ea94:
        mov      ecx, dword ptr [g_data_00542060]
        mov      edx, dword ptr [g_data_00542054]
        mov      dword ptr [ecx*4 + 0x64], edx
        mov      eax, dword ptr [g_data_00542060]
        mov      ecx, dword ptr [g_data_00542058]
        mov      dword ptr [eax*4 + 0x68], ecx
        call     ThrowFsmCluster_0044eaf0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_eae8
        mov      eax, 1
        mov      dword ptr [esi + 8], OFFSET L_ea20
        mov      dword ptr [esi + 0x84], eax
        mov      dword ptr [g_data_0054204c], 0xf
        mov      dword ptr [g_framePauseFlag], eax
    L_eae8:
        pop      esi
        ret      
    }
}
