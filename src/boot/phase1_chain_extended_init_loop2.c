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
extern unsigned int g_audioBankSel_00537f94;
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
extern unsigned int g_rangeSqLimit_0053a180;
extern unsigned int g_zero_00541fa4;
extern unsigned int g_zero_00541fa8;
extern unsigned int g_dualBitGate_0053a7b0;
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
extern unsigned int g_stateCountdown_0053a3c0;
extern unsigned int g_player1NodeIdx;
extern unsigned int g_installOwnerNode_00535cf8;
extern unsigned int g_cj_00542054;
extern unsigned int g_audioBoundNode_005437f0;
extern unsigned int g_data_00543598;
extern unsigned int g_data_0054358c;
extern unsigned int g_fightAxisNegX_00535e70;
extern unsigned int g_fightAxisNegY_00535e74;
extern unsigned int g_fightAxisPosX_00535e78;
extern unsigned int g_fightAxisPosY_00535e7c;

extern unsigned int g_data_004d5fa0;
extern unsigned int g_framePauseFlag;
extern unsigned int g_currentNodeIdx;
extern unsigned int g_xformEntityIdx;
extern unsigned int g_eventQueueIdx;
extern unsigned int g_fightGroupHead;
extern unsigned int g_eventQueueWorkType;
extern void AudioMixerStep_004ab700(void);
extern void CmpDivJmp_0049d080(void);
extern void CopyThreeFields_00404df0(void);
extern void MStackCall_00406600(void);
extern void MStackPop8_004ab860(void);
extern void MStackPush8_004ab790(void);
extern void MStackPushNegMul10_0040a690(void);
extern void PushSetXfmMaskCallPop_00407140(void);
extern void SetJmp_00405420(void);
extern void SetJmp_00408d20(void);
extern void ThreeChanPackClamp_00404cc0(void);

__declspec(naked) void Phase1ChainExtendedInitLoop2_0040c760(void)
{
    __asm {
        push    ebx
        push    esi
        push    0x2010
        call    ThreeChanPackClamp_00404cc0
        mov     eax, dword ptr [g_fightGroupHead]
        add     esp, 4
        push    eax
        call    CopyThreeFields_00404df0
        add     esp, 4
        call    SetJmp_00405420
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p1cei2_ret
        mov     al, byte ptr [g_xformDirtyFlags]
        mov     ebx, 4
        test    al, bl
        je      L_p1cei2_ret
        call    MStackPush8_004ab790
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p1cei2_ret
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     edx, offset g_data_004d5fa0
        shr     edx, 2
        mov     dword ptr [g_eventQueueIdx], ecx
        mov     dword ptr [g_walkCallback], edx
        call    PushSetXfmMaskCallPop_00407140
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p1cei2_ret
        test    byte ptr [g_xformDirtyFlags], bl
        jne     L_p1cei2_tailjmp
        mov     eax, dword ptr [g_fightGroupHead]
        mov     dword ptr [eax*4 + 0x30], 0x42
        mov     dword ptr [g_walkCallback], 0x60000
        call    AudioMixerStep_004ab700
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p1cei2_ret
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     edx, dword ptr [g_walkCallback]
        mov     dword ptr [ecx*4 + 0x68], edx
        mov     eax, dword ptr [g_fightGroupHead]
        mov     dword ptr [eax*4 + 0x80], 0x1999
        mov     dword ptr [g_walkCallback], 0x41
        call    MStackPushNegMul10_0040a690
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p1cei2_ret
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     edx, dword ptr [g_eventQueueIdx]
        shl     edx, 2
        lea     eax, [ecx*4]
        mov     ecx, dword ptr [g_walkCallback]
        mov     dword ptr [eax + 0x6C], ecx
        mov     ecx, dword ptr [g_eventQueueCurrent]
        mov     dword ptr [eax + 0x74], ecx
        mov     ecx, dword ptr [g_walkCallback]
        lea     ecx, [ecx + ecx*2]
        lea     ecx, [ecx + ecx*4]
        shl     ecx, 3
        mov     dword ptr [g_walkCallback], ecx
        mov     esi, dword ptr [edx + 0x54]
        add     ecx, esi
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [eax + 0x54], ecx
        mov     ecx, dword ptr [g_eventQueueCurrent]
        lea     ecx, [ecx + ecx*2]
        lea     ecx, [ecx + ecx*4]
        shl     ecx, 3
        mov     dword ptr [g_eventQueueCurrent], ecx
        mov     esi, dword ptr [edx + 0x5C]
        add     ecx, esi
        mov     dword ptr [g_eventQueueCurrent], ecx
        mov     dword ptr [eax + 0x5C], ecx
        mov     edx, dword ptr [edx + 0x58]
        sub     edx, 0x3333
        mov     dword ptr [g_walkCallback], edx
        mov     dword ptr [eax + 0x58], edx
        call    SetJmp_00408d20
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p1cei2_ret
        mov     eax, dword ptr [g_xformEntityIdx]
        mov     edx, dword ptr [eax*4]
        or      edx, 8
        mov     dword ptr [eax*4], edx
        mov     edx, dword ptr [g_xformEntityIdx]
        mov     dword ptr [edx*4 + 0x48], 0xA666
        mov     eax, dword ptr [g_xformEntityIdx]
        mov     dword ptr [eax*4 + 0x14], 0xFF
        mov     ecx, dword ptr [g_xformEntityIdx]
        mov     eax, 0x004BA0E0
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x10], eax
        mov     eax, dword ptr [g_currentNodeIdx]
        mov     ecx, dword ptr [eax*4 + 0x20]
        or      ch, 0x40
        mov     dword ptr [eax*4 + 0x20], ecx
        mov     dword ptr [g_walkCallback], 1
        call    CmpDivJmp_0049d080
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p1cei2_ret
        test    byte ptr [g_xformDirtyFlags], bl
        jne     L_p1cei2_after_loop
        mov     dword ptr [g_eventQueueCurrent], 0
        mov     dword ptr [g_eventQueueWorkType], 0
        mov     esi, 0xFFFE8000
    L_p1cei2_loop_top:
        mov     edx, dword ptr [g_eventQueueIdx]
        mov     dword ptr [g_walkCallback], esi
        push    esi
        mov     eax, dword ptr [edx*4 + 0x6C]
        push    eax
        call    Mul10Tail_00404af0
        mov     edx, dword ptr [g_eventQueueCurrent]
        mov     ecx, dword ptr [g_eventQueueIdx]
        add     edx, eax
        add     esp, 8
        mov     dword ptr [g_eventQueueCurrent], edx
        mov     dword ptr [g_walkCallback], esi
        mov     edx, dword ptr [ecx*4 + 0x74]
        push    esi
        push    edx
        call    Mul10Tail_00404af0
        mov     ecx, dword ptr [g_eventQueueWorkType]
        mov     dword ptr [g_walkCallback], eax
        add     ecx, eax
        mov     eax, dword ptr [g_currentNodeIdx]
        mov     dword ptr [g_eventQueueWorkType], ecx
        mov     ecx, dword ptr [g_eventQueueCurrent]
        mov     dword ptr [eax*4 + 4], ecx
        mov     edx, dword ptr [g_currentNodeIdx]
        mov     eax, dword ptr [g_eventQueueWorkType]
        add     esp, 8
        mov     dword ptr [edx*4 + 0x0C], eax
        mov     ecx, dword ptr [g_currentNodeIdx]
        mov     edx, dword ptr [g_xformDirtyFlags]
        mov     eax, dword ptr [ecx*4]
        or      edx, ebx
        test    eax, eax
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [g_xformDirtyFlags], edx
        je      L_p1cei2_after_loop
        mov     ecx, edx
        xor     ecx, ebx
        test    eax, eax
        mov     dword ptr [g_xformDirtyFlags], ecx
        jne     L_p1cei2_loop_top
    L_p1cei2_after_loop:
        mov     edx, dword ptr [g_fightGroupHead]
        mov     dword ptr [g_currentNodeIdx], edx
        call    MStackCall_00406600
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p1cei2_ret
    L_p1cei2_tailjmp:
        call    MStackPop8_004ab860
    L_p1cei2_ret:
        pop     esi
        pop     ebx
        ret
    }
}
