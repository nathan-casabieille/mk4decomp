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

/* @addr 0x004c9440 (217b crt) - heap-region scan with per-slot init.
 *   Lock(2). For esi=0..[g_data_00fa0dc0]-1:
 *     slot = (*g_data_00f9fdb4)[esi]
 *     If slot == 0: allocate 0x38 bytes via LoadArgPushCall_004c54b0,
 *       store into slot; init critsec at slot+0x20 via IAT[0x4d215c],
 *       acquire via IAT[0x4d2140], reload slot ptr into edi, fall to finalize.
 *     Else:
 *       If [slot+0xc] & 0x83 == 0: call TwoPathIATDispatch_004c7030(esi, slot),
 *         reload slot, recheck [slot+0xc] & 0x83;
 *         if zero: edi = slot, jmp finalize;
 *         else: call TwoPathIATDispatch_004c70a0(esi, slot), continue iter.
 *       Else: skip helper, continue iter.
 *   Finalize: if edi != 0, init fields at edi (+0,+4,+8,+0xc,+0x1c = 0; +0x10 = -1).
 *   Unlock(2) via TableLookupIatCall_004c6fd0; return edi.
 */
extern unsigned int g_data_00f9fdb4;
extern unsigned int g_data_00fa0dc0;
extern unsigned int g_iat_004d2140;
extern unsigned int g_iat_004d215c;
extern void LoadArgPushCall_004c54b0(void);
extern void Lock_004c6f50(void);
extern void TableLookupIatCall_004c6fd0(void);
extern void TwoPathIATDispatch_004c7030(void);
extern void TwoPathIATDispatch_004c70a0(void);

__declspec(naked) void HeapScanInit_004c9440(void) {
    __asm {
        push    ebx
        push    ebp
        push    esi
        push    edi
        push    2
        xor     ebp, ebp
        xor     edi, edi
        call    Lock_004c6f50
        mov     eax, dword ptr [g_data_00fa0dc0]
        add     esp, 4
        xor     esi, esi
        cmp     eax, ebp
        jle     L_hsi_finalize
        mov     bl, 0x83
    L_hsi_loop:
        mov     eax, dword ptr [g_data_00f9fdb4]
        mov     eax, [eax + esi*4]
        cmp     eax, ebp
        jz      short L_hsi_alloc
        test    byte ptr [eax + 0xc], bl
        jne     short L_hsi_next
        push    eax
        push    esi
        call    TwoPathIATDispatch_004c7030
        mov     ecx, dword ptr [g_data_00f9fdb4]
        add     esp, 8
        mov     eax, [ecx + esi*4]
        test    byte ptr [eax + 0xc], bl
        jz      short L_hsi_setEdi
        push    eax
        push    esi
        call    TwoPathIATDispatch_004c70a0
        add     esp, 8
    L_hsi_next:
        mov     eax, dword ptr [g_data_00fa0dc0]
        inc     esi
        cmp     esi, eax
        jl      short L_hsi_loop
        jmp     L_hsi_finalize
    L_hsi_setEdi:
        mov     edi, [ecx + esi*4]
        jmp     L_hsi_finalize
    L_hsi_alloc:
        push    0x38
        shl     esi, 2
        call    LoadArgPushCall_004c54b0
        mov     ecx, dword ptr [g_data_00f9fdb4]
        add     esp, 4
        mov     [ecx + esi], eax
        mov     edx, dword ptr [g_data_00f9fdb4]
        mov     eax, [edx + esi]
        cmp     eax, ebp
        jz      short L_hsi_finalize
        add     eax, 0x20
        push    eax
        call    dword ptr [g_iat_004d215c]
        mov     eax, dword ptr [g_data_00f9fdb4]
        mov     ecx, [eax + esi]
        add     ecx, 0x20
        push    ecx
        call    dword ptr [g_iat_004d2140]
        mov     edx, dword ptr [g_data_00f9fdb4]
        mov     edi, [edx + esi]
    L_hsi_finalize:
        cmp     edi, ebp
        jz      short L_hsi_unlock
        mov     [edi + 4], ebp
        mov     [edi + 0xc], ebp
        mov     [edi + 8], ebp
        mov     [edi], ebp
        mov     [edi + 0x1c], ebp
        mov     dword ptr [edi + 0x10], -1
    L_hsi_unlock:
        push    2
        call    TableLookupIatCall_004c6fd0
        add     esp, 4
        mov     eax, edi
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        ret
    }
}
