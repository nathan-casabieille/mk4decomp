/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;
extern unsigned int g_baseSel_00542060;
extern unsigned int g_acc_00542078;
extern unsigned int g_cj_0054205c;
extern unsigned int g_state_0053a718;
extern unsigned int g_xformScratch94;
extern unsigned int g_table_00535ddc;
extern unsigned int g_active_00537e88;
extern unsigned int g_active_0053a408;
extern unsigned int g_audioBankSel_00537f94;

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
extern unsigned int g_installOwnerNode_00535cf8;
extern unsigned int g_cj_00542054;
extern unsigned int g_audioBoundNode_005437f0;
extern unsigned int g_data_00543598;
extern unsigned int g_data_0054358c;
extern unsigned int g_fightAxisNegX_00535e70;
extern unsigned int g_fightAxisNegY_00535e74;
extern unsigned int g_fightAxisPosX_00535e78;
extern unsigned int g_fightAxisPosY_00535e7c;

/* @addr 0x00446980 (389b game) - 2-entry packed: vec-scale helper +
 *   mstack-push + 3-call rescale.
 *   Entry 1 (offset 0, 85b): scales a vec component. Pushes
 *     g_eventQueueCurrent onto Mul10Tail_00404af0 with 0x13333 weight, then
 *     0x54206c = 0xf5c → StoreDoubleNegPauseSubStore_004ab750. On
 *     no-error adds 0x10000 to 0x54206c, calls Mul10Tail again with that
 *     value, stores result in g_eventQueueCurrent.
 *   11b NOP align pad.
 *   Entry 2 (offset 0x60, 293b): pushes g_fightGroupHead onto mstack,
 *     calls ChainWalkPushPop_00405a40. On no-error sets 0x54206c=0x12c
 *     → AudioVolumeRescale_004ab690. If bit 0 of 0x54208c set also
 *     calls MStackPush2VolumeCascade_00444e00. Then for each of the
 *     3 components at [g_fightGroupHead*4 + 0x6c/0x70/0x74]:
 *       - copy into g_eventQueueCurrent
 *       - call entry 1 (the scaler)
 *       - store result back
 *     Then clamps the scaled +0x58 field at -0x2666 (0xffffd99a) and
 *     zeroes +0x70 when clamped. Sets g_xformEntityIdx-pointed slot's
 *     +0x10=0, +0x14=&g_data_004e6070>>2. Pops mstack and returns.
 */
extern unsigned int g_data_004e6070;
extern unsigned int g_table_004d57b0;
extern void AudioVolumeRescale_004ab690(void);
extern void ChainWalkPushPop_00405a40(void);
extern void MStackPush2VolumeCascade_00444e00(void);
extern void StoreDoubleNegPauseSubStore_004ab750(void);

__declspec(naked) void VecScaleMStackTripleCall_00446980(void) {
    __asm {
        mov     eax, dword ptr [g_eventQueueCurrent]
        push    eax
        push    0x13333
        call    Mul10Tail_00404af0
        add     esp, 8
        mov     dword ptr [g_eventQueueCurrent], eax
        mov     dword ptr [g_walkCallback], 0xf5c
        call    StoreDoubleNegPauseSubStore_004ab750
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_vsm_e1End
        mov     eax, dword ptr [g_walkCallback]
        mov     ecx, dword ptr [g_eventQueueCurrent]
        add     eax, 0x10000
        push    ecx
        push    eax
        mov     dword ptr [g_walkCallback], eax
        call    Mul10Tail_00404af0
        add     esp, 8
        mov     dword ptr [g_eventQueueCurrent], eax
    L_vsm_e1End:
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
        /* entry 2 (offset 0x60) */
    L_vsm_entry2:
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_fightGroupHead]
        inc     eax
        push    esi
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4 + g_table_004d57b0], ecx
        call    ChainWalkPushPop_00405a40
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_vsm_pop1
        mov     dword ptr [g_walkCallback], 0x12c
        call    AudioVolumeRescale_004ab690
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_vsm_pop1
        test    byte ptr [g_xformDirtyFlags], 1
        je      short L_vsm_doVecScale
        call    MStackPush2VolumeCascade_00444e00
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_vsm_pop1
    L_vsm_doVecScale:
        mov     edx, dword ptr [g_fightGroupHead]
        mov     eax, dword ptr [edx*4 + 0x6c]
        lea     esi, [edx*4]
        mov     dword ptr [g_eventQueueCurrent], eax
        call    VecScaleMStackTripleCall_00446980
        mov     ecx, dword ptr [g_eventQueueCurrent]
        mov     edx, dword ptr [esi + 0x70]
        mov     dword ptr [esi + 0x6c], ecx
        mov     dword ptr [g_eventQueueCurrent], edx
        call    VecScaleMStackTripleCall_00446980
        mov     eax, dword ptr [g_eventQueueCurrent]
        mov     ecx, dword ptr [esi + 0x74]
        mov     dword ptr [esi + 0x70], eax
        mov     dword ptr [g_eventQueueCurrent], ecx
        call    VecScaleMStackTripleCall_00446980
        mov     edx, dword ptr [g_eventQueueCurrent]
        mov     ecx, 0xffffd99a
        mov     dword ptr [esi + 0x74], edx
        mov     eax, dword ptr [g_fightGroupHead]
        cmp     dword ptr [eax*4 + 0x58], ecx
        jl      short L_vsm_skipClamp
        mov     dword ptr [eax*4 + 0x58], ecx
        mov     eax, dword ptr [g_fightGroupHead]
        mov     dword ptr [eax*4 + 0x70], 0
    L_vsm_skipClamp:
        mov     ecx, dword ptr [g_xformEntityIdx]
        mov     eax, offset g_data_004e6070
        shr     eax, 2
        mov     dword ptr [ecx*4 + 0x10], 0
        mov     edx, dword ptr [g_xformEntityIdx]
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [edx*4 + 0x14], eax
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [eax*4 + g_table_004d57b0]
        dec     eax
        mov     dword ptr [g_fightGroupHead], ecx
        mov     dword ptr [g_matrixStackTop], eax
    L_vsm_pop1:
        pop     esi
        ret
    }
}
