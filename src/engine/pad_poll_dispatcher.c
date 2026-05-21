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

extern void PadPollDispatcher_004b5650(int player);
/* extern void Helper_JoyButtonInit(int key); -- defined elsewhere with diff sig */
extern unsigned int g_data_007af918;
extern unsigned int g_data_007af920;
extern unsigned int g_data_004d50a4;
extern unsigned int g_data_004d50a8;
extern unsigned int g_data_004d50ac;
extern unsigned int g_data_004d50b0;
extern unsigned int g_data_004f4e98;
extern unsigned int g_data_004f4dc8;
extern unsigned int g_data_004f4dcc;
extern unsigned int g_data_004f4dd0;
extern unsigned int g_data_004f4dd4;
extern unsigned int g_data_004f4dd8;
extern unsigned int g_data_004f4ddc;
extern unsigned int g_data_004f4de0;
extern unsigned int g_data_004f4de4;
extern unsigned int g_data_004f4de8;
extern unsigned int g_data_004f4dec;
extern unsigned int g_data_004f4df0;
extern unsigned int g_data_004f4df4;
extern unsigned int g_data_004f4df8;
extern unsigned int g_data_004f4dfc;
extern unsigned int g_data_004f4e00;
extern unsigned int g_data_004f4e04;
extern unsigned int g_data_00543368;
extern unsigned int g_data_0054336c;
extern unsigned int g_data_00543370;
extern unsigned int g_data_0054357c;

__declspec(naked) void GameStateMachineMaybeRebuild(void)
{
    __asm {
        mov     eax, dword ptr [g_data_004ffd7c]
        push    esi
        xor     esi, esi
        cmp     eax, esi
        mov     dword ptr [g_data_004d50b0], esi
        mov     dword ptr [g_data_004d50a4], esi
        mov     dword ptr [g_data_004d50a8], esi
        mov     dword ptr [g_data_004d50ac], esi
        je      L_idep_after_clear_masks
        cmp     dword ptr [g_data_007af918], esi
        jne     L_idep_after_clear_masks
        push    esi
        call    PadPollDispatcher_004b5650
        add     esp, 4
        push    1
        call    PadPollDispatcher_004b5650
        add     esp, 4
        push    esi
        call    InputBitMaskDispatcher_004b5470
        add     esp, 4
        push    1
        call    InputBitMaskDispatcher_004b5470
        mov     eax, dword ptr [g_data_004f4e98]
        add     esp, 4
        cmp     eax, esi
        je      L_idep_pause_gate2
        cmp     dword ptr [g_data_004d50b0], esi
        jne     L_idep_clear_loop
        cmp     dword ptr [g_data_004d50a4], esi
        jne     L_idep_clear_loop
        cmp     dword ptr [g_data_004d50a8], esi
        jne     L_idep_clear_loop
        cmp     dword ptr [g_data_004d50ac], esi
        jne     L_idep_clear_loop
        push    0x1B
        call    Helper_JoyButtonInit
        add     esp, 4
        test    eax, eax
        jne     L_idep_clear_loop
        push    0x20
        call    Helper_JoyButtonInit
        add     esp, 4
        test    eax, eax
        jne     L_idep_clear_loop
        push    0x0D
        call    Helper_JoyButtonInit
        add     esp, 4
        test    eax, eax
        jne     L_idep_clear_loop
        mov     dword ptr [g_data_004f4e98], esi
    L_idep_clear_loop:
        mov     dword ptr [g_data_004d50b0], esi
        mov     dword ptr [g_data_004d50a4], esi
        mov     dword ptr [g_data_004d50a8], esi
        mov     dword ptr [g_data_004d50ac], esi
    L_idep_pause_gate2:
        cmp     dword ptr [g_data_007af920], esi
        je      L_idep_after_clear_masks
        mov     eax, dword ptr [g_data_004f4dec]
        mov     ecx, dword ptr [g_data_004f4de8]
        not     ecx
        mov     edx, dword ptr [eax]
        and     edx, ecx
        mov     dword ptr [eax], edx
        mov     eax, dword ptr [g_data_004f4df4]
        mov     edx, dword ptr [g_data_004f4df0]
        mov     ecx, dword ptr [eax]
        not     edx
        and     ecx, edx
        mov     dword ptr [eax], ecx
    L_idep_after_clear_masks:
        mov     ecx, dword ptr [g_data_004f4dcc]
        mov     eax, dword ptr [g_data_004f4dc8]
        test    dword ptr [ecx], eax
        je      L_idep_skip1
        mov     eax, dword ptr [g_data_004f4ddc]
        mov     edx, dword ptr [g_data_004f4dd8]
        not     edx
        and     dword ptr [eax], edx
    L_idep_skip1:
        mov     ecx, dword ptr [g_data_004f4dd4]
        mov     eax, dword ptr [g_data_004f4dd0]
        test    dword ptr [ecx], eax
        je      L_idep_skip2
        mov     eax, dword ptr [g_data_004f4de4]
        mov     edx, dword ptr [g_data_004f4de0]
        not     edx
        and     dword ptr [eax], edx
    L_idep_skip2:
        mov     ecx, dword ptr [g_data_004f4dec]
        mov     eax, dword ptr [g_data_004f4de8]
        test    dword ptr [ecx], eax
        je      L_idep_skip3
        mov     eax, dword ptr [g_data_004f4dfc]
        mov     edx, dword ptr [g_data_004f4df8]
        not     edx
        and     dword ptr [eax], edx
    L_idep_skip3:
        mov     ecx, dword ptr [g_data_004f4df4]
        mov     eax, dword ptr [g_data_004f4df0]
        test    dword ptr [ecx], eax
        je      L_idep_skip4
        mov     eax, dword ptr [g_data_004f4e04]
        mov     edx, dword ptr [g_data_004f4e00]
        not     edx
        and     dword ptr [eax], edx
    L_idep_skip4:
        mov     esi, dword ptr [g_data_004d50ac]
        mov     eax, dword ptr [g_data_004d50b0]
        mov     ecx, dword ptr [g_data_004d50a4]
        mov     edx, dword ptr [g_data_004d50a8]
        not     esi
        not     eax
        not     ecx
        not     edx
        mov     dword ptr [g_data_004d50ac], esi
        mov     dword ptr [g_data_00543368], esi
        mov     dword ptr [g_data_004d50b0], eax
        mov     dword ptr [g_data_004d50a4], ecx
        mov     dword ptr [g_data_004d50a8], edx
        mov     dword ptr [g_data_0054357c], eax
        mov     dword ptr [g_data_0054336c], ecx
        mov     dword ptr [g_data_00543370], edx
        pop     esi
        ret
    }
}
