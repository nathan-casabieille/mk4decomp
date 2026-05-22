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

/* @addr 0x0049c710 (305b game) - install-self body with state-machine, bit2-loop, indirect-call dispatch.
 *   Load state; clear. state==0: call TripleBlockChainDiffMStackThunks; if pause ret.
 *   ebx=1. If g_state_00542080==0: call ScaledChain3c74; if pause ret.
 *     If g_x_0054206c==0x2001: jmp bit2-loop block.
 *   Else (state!=0 OR not 0x2001): mstack-push g_state_00542080; load chain[g_x_00542054*4+0] -> g_x_0054206c.
 *     Call AtanDualDeltaThreshold_0049c870; if pause ret. Mstack-pop into g_state_00542080.
 *     If bit0(0054208c): chain[g_x_00542054*4+8] -> g_scaledInit; indirect call; pop; ret.
 *   bit2-loop: eax = [g_x_00542054*4+4]; ecx=4; set bit2 of g_state_0054208c.
 *     If eax!=0: toggle bit2 off; call eax; if pause ret.
 *     Install-self at entry; state=1; g_x_0054204c=1; pause=1; pop esi/ebx; ret.
 */
extern unsigned int g_pause_00541e6c;
extern unsigned int g_x_0054204c;
extern unsigned int g_x_00542054;
extern unsigned int g_x_0054206c;
extern void AtanDualDeltaThreshold_0049c870(void);
extern void ScaledChain3c74_0048f910(void);
extern void TripleBlockChainDiffMStackThunks_0049ca10(void);

extern unsigned int g_data_004d57ac_arr;

__declspec(naked) void InstallSelfBit2LoopIndirect_0049c710(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel_00542060]
        push    ebx
        push    esi
        lea     esi, [eax*4 + 0]
        mov     eax, dword ptr [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], 0
        test    eax, eax
        _emit   75h
        _emit   12h
        call    TripleBlockChainDiffMStackThunks_0049ca10
        mov     eax, dword ptr [g_pause_00541e6c]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   0f9h
        _emit   00h
        _emit   00h
        _emit   00h
        mov     eax, dword ptr [g_state_00542080]
        mov     ebx, 1
        test    eax, eax
        _emit   75h
        _emit   1eh
        call    ScaledChain3c74_0048f910
        mov     eax, dword ptr [g_pause_00541e6c]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   0d9h
        _emit   00h
        _emit   00h
        _emit   00h
        cmp     dword ptr [g_x_0054206c], 0x2001
        _emit   74h
        _emit   74h
        mov     ecx, dword ptr [g_x_00542054]
        mov     eax, dword ptr [g_state_004d57ac]
        inc     eax
        mov     edx, dword ptr [ecx*4 + 0]
        mov     ecx, dword ptr [g_state_00542080]
        mov     dword ptr [g_x_0054206c], edx
        mov     dword ptr [g_state_004d57ac], eax
        mov     [eax*4 + g_data_004d57ac_arr], ecx
        call    AtanDualDeltaThreshold_0049c870
        mov     eax, dword ptr [g_pause_00541e6c]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   90h
        _emit   00h
        _emit   00h
        _emit   00h
        mov     eax, dword ptr [g_state_004d57ac]
        mov     edx, [eax*4 + g_data_004d57ac_arr]
        dec     eax
        mov     dword ptr [g_state_004d57ac], eax
        mov     al, byte ptr [g_state_0054208c]
        _emit   84h
        _emit   0c3h
        mov     dword ptr [g_state_00542080], edx
        _emit   74h
        _emit   16h
        mov     eax, dword ptr [g_x_00542054]
        mov     eax, dword ptr [eax*4 + 8]
        mov     dword ptr [g_scaledInit_00542044], eax
        call    eax
        pop     esi
        pop     ebx
        ret
        mov     ecx, dword ptr [g_x_00542054]
        mov     edx, dword ptr [g_state_0054208c]
        mov     eax, dword ptr [ecx*4 + 4]
        mov     ecx, 4
        or      edx, ecx
        mov     dword ptr [g_scaledInit_00542044], eax
        test    eax, eax
        mov     dword ptr [g_state_0054208c], edx
        _emit   74h
        _emit   0eh
        xor     edx, ecx
        test    eax, eax
        mov     dword ptr [g_state_0054208c], edx
        _emit   74h
        _emit   02h
        call    eax
        mov     eax, dword ptr [g_pause_00541e6c]
        test    eax, eax
        _emit   75h
        _emit   19h
        mov     dword ptr [esi + 8], offset InstallSelfBit2LoopIndirect_0049c710
        mov     dword ptr [esi + 0x84], ebx
        mov     dword ptr [g_x_0054204c], ebx
        mov     dword ptr [g_pause_00541e6c], ebx
        pop     esi
        pop     ebx
        ret
    }
}
