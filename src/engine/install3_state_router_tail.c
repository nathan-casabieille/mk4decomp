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

/* @addr 0x0046b4e0 (325b game) - 3-state install-self + dispatch state-1 (router) + tail thunk.
 *   state==0: call StateDispatchTable; if pause ret.
 *     g_eventQueueEnd=g_walkCallback; g_currentNodeFlags=0x1999; g_eventQueueNotMask=0.
 *     Install-self at entry+0x01000000; state=1; call EsiInstallClampAddCall; pause=1; ret.
 *   state==1 (dec,je): tail-call CallPauseScaledStoreCopyJmp; if pause ret.
 *     Install-self at entry; state=2; g_pendingNodeType=1; pause=1; ret.
 *   state>=2 (fall): cmp g_state_0052aac4_aa with 2: if neq tail-call CjInstallSelfRouter; pop+ret.
 *     Else: g_walkCallback=g_data_00541dc8; if zero jmp state=2 install; else tail-call CjInstallSelfRouter; pop+ret.
 *   Tail (+0x120, 2-NOP pad): chain[baseSel*4+0x74]=0x104; push 0x004eb008; call ArgSarStoreJmp; pop; ret.
 */
extern unsigned int g_data_00541dc8;
extern unsigned int g_state_0052aac4_aa;
extern void ArgSarStoreJmp_004594f0(void);
extern void CallPauseScaledStoreCopyJmp_00461220(void);
extern void CjInstallSelfRouter_00470480(void);
extern void EsiInstallClampAddCall_0048fe40(void);
extern void StateDispatchTable_00490fc0(void);

__declspec(naked) void Install3StateRouterTail_0046b4e0(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel_00542060]
        push    esi
        lea     esi, [eax*4 + 0]
        mov     eax, dword ptr [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], 0
        _emit   83h
        _emit   0e8h
        _emit   00h
        _emit   74h
        _emit   67h
        dec     eax
        _emit   74h
        _emit   2bh
        mov     eax, dword ptr [g_state_0052aac4_aa]
        cmp     eax, 2
        mov     dword ptr [g_walkCallback], eax
        _emit   75h
        _emit   07h
        call    CjInstallSelfRouter_00470480
        pop     esi
        ret
        mov     eax, dword ptr [g_data_00541dc8]
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        _emit   74h
        _emit   19h
        call    CjInstallSelfRouter_00470480
        pop     esi
        ret
        call    CallPauseScaledStoreCopyJmp_00461220
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   0b9h
        _emit   00h
        _emit   00h
        _emit   00h
        mov     dword ptr [esi + 8], offset Install3StateRouterTail_0046b4e0
        mov     dword ptr [esi + 0x84], 2
        mov     dword ptr [g_pendingNodeType], 1
        mov     dword ptr [g_framePauseFlag], 1
        pop     esi
        ret
        call    StateDispatchTable_00490fc0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   80h
        _emit   00h
        _emit   00h
        _emit   00h
        mov     ecx, dword ptr [g_walkCallback]
        mov     dword ptr [g_currentNodeFlags], 0x1999
        mov     dword ptr [g_eventQueueEnd], ecx
        mov     dword ptr [g_eventQueueNotMask], 0
        mov     dword ptr [esi + 8], offset Install3StateRouterTail_0046b4e0
        mov     edx, dword ptr [g_baseSel_00542060]
        mov     ecx, offset Install3StateRouterTail_0046b4e0
        mov     dword ptr [edx*4 + 0x84], 1
        mov     eax, dword ptr [esi + 4]
        add     ecx, 0x01000000
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     dword ptr [eax*4 + 0], ecx
        mov     eax, dword ptr [g_scaledInit_00542044]
        inc     eax
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     dword ptr [esi + 4], eax
        mov     edx, dword ptr [g_baseSel_00542060]
        mov     dword ptr [edx*4 + 0x84], 0
        call    EsiInstallClampAddCall_0048fe40
        mov     dword ptr [g_framePauseFlag], 1
        pop     esi
        ret
        _emit   90h
        _emit   90h
        mov     ecx, dword ptr [g_baseSel_00542060]
        mov     eax, 0x104
        mov     dword ptr [g_walkCallback], eax
        push    0x004eb008
        mov     dword ptr [ecx*4 + 0x74], eax
        call    ArgSarStoreJmp_004594f0
        add     esp, 4
        ret
    }
}
