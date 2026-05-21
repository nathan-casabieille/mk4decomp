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

extern void SkelAnimUpdaterCluster_0049d940(void);
extern unsigned int g_data_004d6948;
extern unsigned int g_data_0050bbb4;

__declspec(naked) void Phase4DualHelperTrampoline_00412900(void)
{
    __asm {
        push    0x8A
        push    0x00412920
        call    StoreTwoCall_0049cb40
        add     esp, 8
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
    L_p4dht_A:
        mov     eax, dword ptr [g_data_00542060]
        push    esi
        lea     esi, [eax*4]
        mov     eax, dword ptr [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], 0
        sub     eax, 0
        je      L_p4dht_A_phase0
        dec     eax
        je      L_p4dht_A_phase1
        call    SetJmp_00405420
        mov     eax, dword ptr [g_data_00541e6c]
        test    eax, eax
        jne     L_p4dht_A_exit
        test    byte ptr [g_state_0054208c], 4
        je      L_p4dht_A_install_p2
        push    0x8A
        push    0x00412AD0
        call    StoreTwoCall_0049cb40
        add     esp, 8
        call    CallSetPause_0041f830
        pop     esi
        ret
    L_p4dht_A_phase1:
        push    0x8A
        push    0x00412AD0
        call    StoreTwoCall_0049cb40
        mov     dword ptr [esi + 8], 0x00412920
        mov     dword ptr [esi + 0x84], 2
        add     esp, 8
        mov     dword ptr [g_data_0054204c], 0x0C
        mov     dword ptr [g_data_00541e6c], 1
        pop     esi
        ret
    L_p4dht_A_phase0:
        call    MStackPush2RunCountdown_004089e0
        mov     eax, dword ptr [g_data_00541e6c]
        test    eax, eax
        jne     L_p4dht_A_exit
        call    MStackBracket7_DispatchAndChain_004b8fa0
        mov     eax, dword ptr [g_data_00541e6c]
        test    eax, eax
        jne     L_p4dht_A_exit
        mov     dword ptr [g_data_0054206c], 0x0A
        call    ChainDirtyBitWalker_00408c10
        mov     eax, dword ptr [g_data_00541e6c]
        test    eax, eax
        jne     L_p4dht_A_exit
        test    byte ptr [g_state_0054208c], 4
        je      L_p4dht_A_continue
    L_p4dht_A_install_p2:
        call    CallSetPause_0041f830
        pop     esi
        ret
    L_p4dht_A_continue:
        mov     edx, dword ptr [g_data_00542060]
        mov     ecx, dword ptr [g_data_00542048]
        lea     eax, [edx*4]
        mov     edx, dword ptr [ecx*4 + 0x3C]
        mov     dword ptr [g_data_00542088], edx
        mov     ecx, dword ptr [ecx*4 + 0x44]
        mov     dword ptr [g_data_00542084], ecx
        mov     dword ptr [eax + 0x38], edx
        mov     edx, dword ptr [g_data_00542084]
        mov     ecx, 0xFFFFE667
        mov     dword ptr [eax + 0x40], edx
        mov     dword ptr [g_data_0054206c], ecx
        mov     dword ptr [eax + 0x3C], ecx
        mov     eax, dword ptr [g_data_00542060]
        mov     dword ptr [g_data_00542044], eax
        call    ZeroThreeFields_0040a8b0
        mov     eax, dword ptr [g_data_00541e6c]
        test    eax, eax
        jne     L_p4dht_A_exit
        mov     ecx, offset g_data_004d6948
        mov     dword ptr [g_data_0054207c], 0x99
        shr     ecx, 2
        mov     dword ptr [g_data_00542048], ecx
        call    SkelAnimUpdaterCluster_0049d940
        mov     eax, dword ptr [g_data_00541e6c]
        test    eax, eax
        jne     L_p4dht_A_exit
        push    0x8A
        push    0x00412AD0
        call    StoreTwoCall_0049cb40
        mov     eax, 1
        mov     dword ptr [esi + 8], 0x00412920
        mov     dword ptr [esi + 0x84], eax
        add     esp, 8
        mov     dword ptr [g_data_0054204c], 0x0C
        mov     dword ptr [g_data_00541e6c], eax
    L_p4dht_A_exit:
        pop     esi
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
    L_p4dht_B:
        mov     eax, dword ptr [g_data_00542060]
        push    esi
        lea     esi, [eax*4]
        mov     eax, dword ptr [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], 0
        sub     eax, 0
        je      L_p4dht_B_phase0
        dec     eax
        mov     eax, dword ptr [g_data_00542054]
        je      L_p4dht_B_alt
        mov     edx, dword ptr [eax*4 + 0x48]
        add     edx, 0xCCC
        mov     dword ptr [eax*4 + 0x48], edx
        mov     ecx, dword ptr [g_data_00542054]
        mov     eax, dword ptr [g_data_0054205c]
        mov     edx, dword ptr [ecx*4 + 0x48]
        mov     dword ptr [g_data_0054206c], edx
        mov     ecx, dword ptr [eax*4 + 0x58]
        add     ecx, 0x7AE
        mov     dword ptr [eax*4 + 0x58], ecx
        mov     eax, dword ptr [g_data_0054205c]
        mov     ecx, dword ptr [eax*4 + 0x58]
        mov     eax, dword ptr [g_data_00542058]
        dec     eax
        mov     dword ptr [g_data_0054206c], ecx
        mov     dword ptr [g_data_00542058], eax
        jns     L_p4dht_B_install
        call    MStackCall_00406740
        mov     eax, dword ptr [g_data_00541e6c]
        test    eax, eax
        je      L_p4dht_B_call_0041f830
        pop     esi
        ret
    L_p4dht_B_alt:
        mov     ecx, dword ptr [eax*4 + 0x48]
        add     ecx, 0xCCC
        mov     dword ptr [eax*4 + 0x48], ecx
        mov     edx, dword ptr [g_data_00542054]
        mov     eax, dword ptr [edx*4 + 0x48]
        mov     dword ptr [g_data_0054206c], eax
        mov     eax, dword ptr [g_data_00542058]
        dec     eax
        mov     dword ptr [g_data_00542058], eax
        jns     L_p4dht_B_after_06740
        mov     dword ptr [g_data_00542058], 7
    L_p4dht_B_install:
        mov     eax, 1
        mov     dword ptr [esi + 8], 0x00412AD0
        mov     dword ptr [esi + 0x84], 2
        mov     dword ptr [g_data_0054204c], eax
        mov     dword ptr [g_data_00541e6c], eax
        pop     esi
        ret
    L_p4dht_B_phase0:
        mov     ecx, offset g_data_0050bbb4
        shr     ecx, 2
        mov     dword ptr [g_data_00542048], ecx
        call    MStackPushDispatchBitGate_00407330
        mov     eax, dword ptr [g_data_00541e6c]
        test    eax, eax
        jne     L_p4dht_B_exit
        test    byte ptr [g_state_0054208c], 4
        je      L_p4dht_B_continue
    L_p4dht_B_call_0041f830:
        call    CallSetPause_0041f830
        pop     esi
        ret
    L_p4dht_B_continue:
        mov     edx, dword ptr [g_data_0054205c]
        mov     dword ptr [edx*4 + 0x30], 0x97
        mov     eax, dword ptr [g_data_0054205c]
        mov     ecx, dword ptr [g_data_00542088]
        mov     dword ptr [eax*4 + 0x54], ecx
        mov     edx, dword ptr [g_data_0054205c]
        mov     eax, dword ptr [g_data_00542084]
        mov     dword ptr [edx*4 + 0x5C], eax
        mov     ecx, dword ptr [g_data_0054205c]
        mov     eax, 0xFFFFF334
        mov     dword ptr [g_data_0054206c], eax
        mov     dword ptr [ecx*4 + 0x58], eax
        call    ScaledChainOr8_00404e50
        mov     edx, dword ptr [g_data_00542048]
        mov     eax, 0x28F
        mov     dword ptr [g_data_0054206c], eax
        mov     dword ptr [edx*4 + 0x48], eax
        mov     eax, dword ptr [g_data_00542048]
        mov     dword ptr [g_data_00542054], eax
        call    MStackCall_004062f0
        mov     eax, dword ptr [g_data_00541e6c]
        test    eax, eax
        jne     L_p4dht_B_exit
        mov     dword ptr [g_data_00542058], 0x0F
    L_p4dht_B_after_06740:
        mov     eax, 1
        mov     dword ptr [esi + 8], 0x00412AD0
        mov     dword ptr [esi + 0x84], eax
        mov     dword ptr [g_data_0054204c], eax
        mov     dword ptr [g_data_00541e6c], eax
    L_p4dht_B_exit:
        pop     esi
        ret
    }
}
