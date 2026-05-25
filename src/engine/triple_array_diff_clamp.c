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

/* @addr 0x004251f0 (207b game) - 3-iter loop computing |a-b| diffs then clamping
 * to thresholds in [004d5320..0x4d5328], storing to scaledInit table.
 *   esi=2, edi=3; loop iterates 3 times (jne after dec edi).
 *   per iter: a=arr1[i], b=arr2[j], diff=a-b; |diff|<=thr ? 1 : 0; clamp uses 004d5328;
 *   advance indices, write diff to scaledInit[k]*4, k++.
 *   end: store esi (=-1) to [0x0053a1ac]; rewind 3 indices.
 */
extern unsigned int g_data_004d5328;
extern unsigned int g_state_004d5324;
extern unsigned int g_x_004d5320;
extern unsigned int g_x_0053a1ac;
extern unsigned int g_x_00542048;
extern unsigned int g_x_0054204c;
extern unsigned int g_x_00542070;
extern unsigned int g_x_00542098;

__declspec(naked) void TripleArrayDiffClamp_004251f0(void) {
    __asm {
        push    ebx
        push    esi
        push    edi
        mov     esi, 2
        mov     edi, 3
loop_004251fd:
        mov     ecx, dword ptr [g_x_00542048]
        mov     edx, dword ptr [g_x_0054204c]
        mov     eax, dword ptr [ecx*4 + 0]
        mov     ebx, dword ptr [edx*4 + 0]
        sub     eax, ebx
        inc     edx
        inc     ecx
        mov     dword ptr [g_x_00542070], eax
        mov     dword ptr [g_x_00542048], ecx
        mov     dword ptr [g_x_0054204c], edx
        test    eax, eax
        mov     ecx, eax
        _emit   7dh
        _emit   02h
        neg     ecx
        mov     ebx, dword ptr [g_x_004d5320]
        xor     edx, edx
        cmp     ecx, ebx
        mov     ecx, dword ptr [g_state_004d5324]
        setle   dl
        test    eax, eax
        mov     dword ptr [g_x_00542098], edx
        mov     dword ptr [g_walkCallback], ecx
        _emit   7ch
        _emit   0ch
        mov     ecx, dword ptr [g_data_004d5328]
        mov     dword ptr [g_walkCallback], ecx
        test    edx, edx
        _emit   75h
        _emit   07h
        add     eax, ecx
        mov     dword ptr [g_x_00542070], eax
        mov     ecx, dword ptr [g_scaledInit_00542044]
        mov     dword ptr [ecx*4 + 0], eax
        mov     edx, dword ptr [g_scaledInit_00542044]
        inc     edx
        dec     esi
        dec     edi
        mov     dword ptr [g_scaledInit_00542044], edx
        jne     loop_004251fd
        mov     ecx, dword ptr [g_x_00542048]
        mov     eax, dword ptr [g_x_0054204c]
        mov     dword ptr [g_x_0053a1ac], esi
        sub     edx, 3
        sub     ecx, 3
        sub     eax, 3
        pop     edi
        pop     esi
        mov     dword ptr [g_scaledInit_00542044], edx
        mov     dword ptr [g_x_00542048], ecx
        mov     dword ptr [g_x_0054204c], eax
        pop     ebx
        ret
    }
}
