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
extern unsigned int g_xformScratch94;
extern unsigned int g_table_00535ddc;
extern unsigned int g_active_00537e88;
extern unsigned int g_active_0053a408;
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
extern unsigned int g_zero_00541fa4;
extern unsigned int g_zero_00541fa8;
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
extern unsigned int g_player1NodeIdx;
extern unsigned int g_data_00535cf8;
extern unsigned int g_cj_00542054;
extern unsigned int g_data_005437f0;
extern unsigned int g_data_00543598;
extern unsigned int g_data_0054358c;
extern unsigned int g_fightAxisNegX_00535e70;
extern unsigned int g_fightAxisNegY_00535e74;
extern unsigned int g_fightAxisPosX_00535e78;
extern unsigned int g_fightAxisPosY_00535e7c;

extern unsigned int g_data_004d5324;
extern unsigned int g_data_004d7b88;
extern unsigned int g_data_004ec8f8;
extern unsigned int g_data_004f00d0;
extern unsigned int g_data_0052ab04;
extern unsigned int g_data_0052ab08;
extern unsigned int g_data_0053a51c;
extern unsigned int g_data_0053a7a0;
extern unsigned int g_framePauseFlag;
extern unsigned int g_currentNodeIdx;
extern unsigned int g_xformEntityIdx;
extern unsigned int g_pendingNodeType;
extern unsigned int g_eventQueueEnd;
extern unsigned int g_eventQueueIdx;
extern unsigned int g_fightGroupHead;
extern unsigned int g_baseSel_00542060;
extern unsigned int g_eventQueueNotMask;
extern unsigned int g_xformScratch2088;
extern unsigned int g_data_00542ce8;
extern void AudioMixerStep_004ab700(void);
extern void CallSetPause_0041f830(void);
extern void EsiInstallSetCbChainExtend_0048a810(void);
extern void MStackCall_00406600(void);
extern void MStackPushZeroCallPop_004066f0(void);
extern void StoreDoubleNegPauseSubStore_004ab750(void);
extern void StoreLoadJmp_00404ef0(void);
extern void StorePauseImulShr16_004ab630(void);
extern void Thunk_0049cbc0(void);

__declspec(naked) void Phase4ThreePackedInstallSelf_0041a610(void)
{
    __asm {
        mov     eax, dword ptr [g_baseSel_00542060]
        push    esi
        push    edi
        xor     edi, edi
        lea     esi, [eax*4]
        mov     eax, dword ptr [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], edi
        cmp     eax, edi
        jne     L_p4tpis_A_call_0049cbc0
        mov     ecx, offset g_data_004ec8f8
        shr     ecx, 2
        mov     dword ptr [g_xformEntityIdx], ecx
        call    DispatcherComplex260_00407030
        cmp     dword ptr [g_framePauseFlag], edi
        jne     L_p4tpis_A_ret
        test    byte ptr [g_xformDirtyFlags], 4
        je      L_p4tpis_A_continue
    L_p4tpis_A_call_0049cbc0:
        call    Thunk_0049cbc0
        pop     edi
        pop     esi
        ret
    L_p4tpis_A_continue:
        mov     eax, dword ptr [g_currentNodeIdx]
        push    0x0041A7D0
        mov     dword ptr [g_data_00535cf8], eax
        mov     dword ptr [eax*4 + 0x64], 0x0004B65F
        mov     eax, dword ptr [g_currentNodeIdx]
        mov     dword ptr [g_data_0053a7a0], eax
        mov     dword ptr [g_walkCallback], edi
        mov     dword ptr [eax*4 + 0x54], edi
        mov     eax, dword ptr [g_currentNodeIdx]
        mov     edx, dword ptr [g_walkCallback]
        mov     dword ptr [eax*4 + 0x5C], edx
        mov     ecx, dword ptr [g_currentNodeIdx]
        mov     eax, 0xFFFE4CCD
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x58], eax
        call    StoreLoadJmp_00404ef0
        mov     ecx, dword ptr [g_data_0053a51c]
        mov     eax, offset g_data_004d7b88
        shr     eax, 2
        add     eax, ecx
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [g_eventQueueIdx], eax
        add     esp, 4
        mov     edx, dword ptr [eax*4]
        mov     dword ptr [g_walkCallback], edx
        call    StorePauseImulShr16_004ab630
        cmp     dword ptr [g_framePauseFlag], edi
        jne     L_p4tpis_A_ret
        mov     ecx, dword ptr [g_walkCallback]
        mov     eax, offset g_data_00542ce8
        shr     eax, 2
        add     eax, ecx
        mov     dword ptr [g_eventQueueIdx], eax
        mov     eax, dword ptr [eax*4]
        mov     dword ptr [g_eventQueueIdx], eax
        mov     eax, dword ptr [g_data_0053a51c]
        cmp     eax, 3
        jne     L_p4tpis_A_after_3
        mov     ecx, offset g_data_004f00d0
        shr     ecx, 2
        mov     dword ptr [g_eventQueueIdx], ecx
    L_p4tpis_A_after_3:
        mov     edx, dword ptr [g_data_0053a7a0]
        mov     dword ptr [g_eventQueueNotMask], edi
        mov     dword ptr [g_eventQueueEnd], edx
        mov     dword ptr [g_walkCallback], 0xC4
        call    AudioMixerStep_004ab700
        cmp     dword ptr [g_framePauseFlag], edi
        jne     L_p4tpis_A_ret
        mov     eax, dword ptr [g_walkCallback]
        mov     edx, 0x0041A610
        add     eax, 0x189
        add     edx, 0x01000000
        mov     dword ptr [g_xformScratch2088], eax
        mov     dword ptr [esi + 8], 0x0041A610
        mov     ecx, dword ptr [g_baseSel_00542060]
        mov     dword ptr [ecx*4 + 0x84], 1
        mov     eax, dword ptr [esi + 4]
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [eax*4], edx
        mov     eax, dword ptr [g_currentNodeIdx]
        inc     eax
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [esi + 4], eax
        mov     eax, dword ptr [g_baseSel_00542060]
        mov     dword ptr [eax*4 + 0x84], edi
        call    EsiInstallSetCbChainExtend_0048a810
        mov     dword ptr [g_framePauseFlag], 1
    L_p4tpis_A_ret:
        pop     edi
        pop     esi
        ret
        nop
        nop
        nop
        nop
        nop
    L_p4tpis_B:
        mov     eax, dword ptr [g_baseSel_00542060]
        push    esi
        mov     dword ptr [eax*4 + 0x84], 0
        lea     esi, [eax*4]
        mov     eax, dword ptr [g_data_00535cf8]
        mov     dword ptr [g_eventQueueIdx], eax
        mov     eax, dword ptr [eax*4 + 0x54]
        push    eax
        push    0xCCCC
        mov     dword ptr [g_walkCallback], eax
        call    Mul10Tail_00404af0
        add     esp, 8
        mov     dword ptr [g_walkCallback], eax
        mov     eax, dword ptr [g_data_0052ab04]
        push    eax
        push    0x3333
        mov     dword ptr [g_eventQueueCurrent], eax
        call    Mul10Tail_00404af0
        mov     edx, dword ptr [g_walkCallback]
        mov     ecx, dword ptr [g_eventQueueIdx]
        add     eax, edx
        add     esp, 8
        mov     dword ptr [g_eventQueueCurrent], eax
        mov     dword ptr [ecx*4 + 0x54], eax
        mov     edx, dword ptr [g_eventQueueIdx]
        mov     eax, dword ptr [edx*4 + 0x5C]
        push    eax
        push    0xCCCC
        mov     dword ptr [g_walkCallback], eax
        call    Mul10Tail_00404af0
        add     esp, 8
        mov     dword ptr [g_walkCallback], eax
        mov     eax, dword ptr [g_data_0052ab08]
        push    eax
        push    0x3333
        mov     dword ptr [g_eventQueueCurrent], eax
        call    Mul10Tail_00404af0
        mov     ecx, dword ptr [g_walkCallback]
        add     esp, 8
        add     eax, ecx
        mov     ecx, dword ptr [g_eventQueueIdx]
        mov     dword ptr [g_eventQueueCurrent], eax
        mov     dword ptr [ecx*4 + 0x5C], eax
        mov     eax, 1
        mov     dword ptr [esi + 8], 0x0041A7D0
        mov     dword ptr [esi + 0x84], eax
        mov     dword ptr [g_pendingNodeType], eax
        mov     dword ptr [g_framePauseFlag], eax
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
    L_p4tpis_C:
        mov     eax, dword ptr [g_fightGroupHead]
        mov     dword ptr [g_currentNodeIdx], eax
        call    MStackPushZeroCallPop_004066f0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4tpis_C_ret
        call    MStackCall_00406600
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4tpis_C_ret
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     ecx, dword ptr [ecx*4 + 0x18]
        mov     dword ptr [g_currentNodeIdx], ecx
        mov     eax, dword ptr [ecx*4 + 0x20]
        or      al, 0x40
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x20], eax
        mov     edx, dword ptr [g_currentNodeIdx]
        mov     eax, dword ptr [edx*4 + 0x28]
        mov     dword ptr [g_xformEntityIdx], eax
        mov     ecx, dword ptr [eax*4]
        or      ecx, 0x0A
        mov     dword ptr [eax*4], ecx
        mov     eax, dword ptr [g_data_004d5324]
        mov     dword ptr [g_walkCallback], eax
        call    AudioMixerStep_004ab700
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4tpis_C_ret
        mov     edx, dword ptr [g_currentNodeIdx]
        mov     ecx, dword ptr [g_walkCallback]
        mov     dword ptr [edx*4 + 0x3C], ecx
        mov     eax, dword ptr [g_data_004d5324]
        mov     dword ptr [g_walkCallback], eax
        call    AudioMixerStep_004ab700
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4tpis_C_ret
        mov     edx, dword ptr [g_currentNodeIdx]
        mov     ecx, dword ptr [g_walkCallback]
        mov     dword ptr [edx*4 + 0x40], ecx
        mov     eax, dword ptr [g_data_004d5324]
        mov     dword ptr [g_walkCallback], eax
        call    AudioMixerStep_004ab700
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4tpis_C_ret
        mov     edx, dword ptr [g_currentNodeIdx]
        mov     ecx, dword ptr [g_walkCallback]
        mov     dword ptr [edx*4 + 0x44], ecx
        mov     dword ptr [g_walkCallback], 0x6666
        call    AudioMixerStep_004ab700
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4tpis_C_ret
        mov     eax, dword ptr [g_walkCallback]
        mov     ecx, dword ptr [g_xformEntityIdx]
        add     eax, 0x9999
        mov     dword ptr [ecx*4 + 0x48], eax
        mov     dword ptr [g_walkCallback], 0x6666
        call    StoreDoubleNegPauseSubStore_004ab750
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4tpis_C_ret
        mov     eax, dword ptr [g_xformEntityIdx]
        mov     edx, dword ptr [g_walkCallback]
        mov     dword ptr [eax*4 + 0x2C], edx
        mov     ecx, dword ptr [g_xformEntityIdx]
        mov     eax, 0x0049D200
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x10], eax
        jmp     CallSetPause_0041f830
    L_p4tpis_C_ret:
        ret
    }
}
