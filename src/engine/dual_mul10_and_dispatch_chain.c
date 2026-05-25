/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;
extern unsigned int g_baseSel_00542060;
extern unsigned int g_acc_00542078;
extern unsigned int g_cj_0054205c;
extern unsigned int g_gameCountdown_0053a718;
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
extern unsigned int g_eventArmReload_0053a770;
extern unsigned int g_rangeBase_0053a46c;

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
extern unsigned int g_lastGatedValue_00543598;
extern unsigned int g_lastGatedTick_0054358c;
extern unsigned int g_fightAxisNegX_00535e70;
extern unsigned int g_fightAxisNegY_00535e74;
extern unsigned int g_fightAxisPosX_00535e78;
extern unsigned int g_fightAxisPosY_00535e7c;

/* @addr 0x0049c220 (274b game) - three adjacent blocks.
 *   B1 (0..0x7f): 2x Mul10Tail with 0x3333 mod for g_currentNodeFlags/g_xformScratch2088;
 *     store results to scaledInit[+0x6c/+0x74]; g_cj_0054205c = scaledInit;
 *     baseSel[+0x5c]=0x30; baseSel[+0x74]=1; ret.
 *   B2 (0x80..0xe3, +12 NOPs): dec baseSel[+0x74] (clamp to 3 if was 0); if
 *     orig was 0: call Phase1ChainExtendedInitLoop_0040c460. If !pause: dec baseSel[+0x5c]; if was 0:
 *     tail-jmp ScaledIndirectJmp_0049c850. ret.
 *   B3 (0xf0..0x111): call BootOneShotSetup_0040bde0; if !pause: call PendingMatch_0040a8d0;
 *     if !pause: tail-jmp GuardedSeq_0049c340; ret.
 */
extern unsigned int g_bootInitSaveSlot_00541dc4;
extern void BootOneShotSetup_0040bde0(void);
extern void GuardedSeq_0049c340(void);
extern void PendingMatch_0040a8d0(void);
extern void Phase1ChainExtendedInitLoop_0040c460(void);
extern void ScaledIndirectJmp_0049c850(void);

__declspec(naked) void DualMul10AndDispatchChain_0049c220(void) {
    __asm {
        mov     edx, dword ptr [g_currentNodeFlags]
        mov     eax, dword ptr [g_scaledInit_00542044]
        mov     ecx, dword ptr [g_baseSel_00542060]
        push    esi
        push    edi
        push    edx
        push    0x3333
        lea     esi, [eax*4 + 0]
        lea     edi, [ecx*4 + 0]
        call    Mul10Tail_00404af0
        add     esp, 8
        mov     dword ptr [g_currentNodeFlags], eax
        mov     eax, dword ptr [g_xformScratch2088]
        push    eax
        push    0x3333
        call    Mul10Tail_00404af0
        mov     ecx, dword ptr [g_currentNodeFlags]
        mov     dword ptr [g_xformScratch2088], eax
        mov     dword ptr [esi + 0x6c], ecx
        mov     edx, dword ptr [g_xformScratch2088]
        mov     dword ptr [esi + 0x74], edx
        mov     eax, dword ptr [g_scaledInit_00542044]
        mov     dword ptr [g_cj_0054205c], eax
        mov     eax, 1
        add     esp, 8
        mov     dword ptr [edi + 0x5c], 0x30
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [edi + 0x74], eax
        pop     edi
        pop     esi
        ret
        nop
        mov     ecx, dword ptr [g_baseSel_00542060]
        mov     eax, dword ptr [ecx*4 + 0x74]
        dec     eax
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [g_bootInitSaveSlot_00541dc4], eax
        _emit   75h
        _emit   0ah
        mov     eax, 3
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x74], eax
        mov     eax, dword ptr [g_bootInitSaveSlot_00541dc4]
        test    eax, eax
        _emit   75h
        _emit   0eh
        call    Phase1ChainExtendedInitLoop_0040c460
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   21h
        mov     ecx, dword ptr [g_baseSel_00542060]
        mov     eax, dword ptr [ecx*4 + 0x5c]
        dec     eax
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x5c], eax
        _emit   75h
        _emit   05h
        jmp     ScaledIndirectJmp_0049c850
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
        call    BootOneShotSetup_0040bde0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   13h
        call    PendingMatch_0040a8d0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   05h
        jmp     GuardedSeq_0049c340
        ret
    }
}
