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
extern unsigned int g_installOwnerNode_00535cf8;
extern unsigned int g_cj_00542054;
extern unsigned int g_audioBoundNode_005437f0;
extern unsigned int g_data_00543598;
extern unsigned int g_data_0054358c;
extern unsigned int g_fightAxisNegX_00535e70;
extern unsigned int g_fightAxisNegY_00535e74;
extern unsigned int g_fightAxisPosX_00535e78;
extern unsigned int g_fightAxisPosY_00535e7c;

extern unsigned int g_data_004d20b0;
extern unsigned int g_data_004d209c;
extern void Helper_ChkStk(void);
extern void LseekImpl_004c8e50(void);
extern void FileWriteWithLfToCrlf_004c9b60(void);
extern void Crt_errno_004c8ba0(void);
extern void Crt_doserrno_004c8bb0(void);

/* @addr 0x004cef10 (334b crt) - text-mode read-CRLF normalize, ~_lread-style.
 *   Big stack frame (4100b via Helper_ChkStk). Saves the current
 *   file position with LseekImpl(fd, 0, 1) and remembers it. Probes the
 *   file size via LseekImpl(fd, 0, 2). If size > 0, sets up a 4KB scratch
 *   buffer on the stack, switches the fd to binary via Setmode_004d0b50,
 *   then loops reading via FileWriteWithLfToCrlf_004c9b60 (read), decrementing remaining
 *   bytes by the amount returned. On EOF or error, dispatches via
 *   Crt_errno_004c8ba0 / Crt_doserrno_004c8bb0 to set errno=0xd (EBADF) if the
 *   underlying error code was 5. Finally restores binary→text via Setmode
 *   again. The smaller branch (size <= 0) makes two direct IAT calls
 *   [0x4d20b0] and [0x4d209c] (likely SetFilePointer / GetLastError or
 *   similar) to fall back to the OS handle. Returns ebp (success/-1).
 */
extern void CRTHandleLookup_004cd260(void);
extern void Setmode_004d0b50(void);

__declspec(naked) void TextModeReadStream_004cef10(void) {
    __asm {
        mov     eax, 0x1004
        call    Helper_ChkStk
        push    ebx
        mov     ebx, dword ptr [esp + 0x100c]
        push    ebp
        push    esi
        push    edi
        xor     ebp, ebp
        push    1
        push    ebp
        push    ebx
        call    LseekImpl_004c8e50
        mov     edi, eax
        add     esp, 0xc
        cmp     edi, -1
        mov     dword ptr [esp + 0x10], edi
        je      L_tmr_failEarly
        push    2
        push    ebp
        push    ebx
        call    LseekImpl_004c8e50
        add     esp, 0xc
        cmp     eax, -1
        je      L_tmr_failEarly
        mov     ecx, dword ptr [esp + 0x101c]
        mov     esi, ecx
        sub     esi, eax
        test    esi, esi
        jle     L_tmr_smallBranch
        mov     ecx, 0x400
        xor     eax, eax
        lea     edi, [esp + 0x14]
        push    0x8000
        rep stosd
        push    ebx
        call    Setmode_004d0b50
        add     esp, 8
        mov     edi, eax
    L_tmr_readLoop:
        cmp     esi, 0x1000
        mov     eax, 0x1000
        jge     short L_tmr_useFull
        mov     eax, esi
    L_tmr_useFull:
        push    eax
        lea     eax, [esp + 0x18]
        push    eax
        push    ebx
        call    FileWriteWithLfToCrlf_004c9b60
        add     esp, 0xc
        cmp     eax, -1
        je      short L_tmr_readErr
        sub     esi, eax
        test    esi, esi
        jle     short L_tmr_readDone
        jmp     short L_tmr_readLoop
    L_tmr_readErr:
        call    Crt_doserrno_004c8bb0
        cmp     dword ptr [eax], 5
        jne     short L_tmr_setErrTail
        call    Crt_errno_004c8ba0
        mov     dword ptr [eax], 0xd
    L_tmr_setErrTail:
        or      ebp, 0xffffffff
    L_tmr_readDone:
        push    edi
        push    ebx
        call    Setmode_004d0b50
        mov     edi, dword ptr [esp + 0x18]
        add     esp, 8
        push    0
        push    edi
        push    ebx
        call    LseekImpl_004c8e50
        add     esp, 0xc
        mov     eax, ebp
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        add     esp, 0x1004
        ret
    L_tmr_smallBranch:
        jge     short L_tmr_restoreOnly
        push    0
        push    ecx
        push    ebx
        call    LseekImpl_004c8e50
        add     esp, 0xc
        push    ebx
        call    CRTHandleLookup_004cd260
        add     esp, 4
        push    eax
        call    dword ptr [g_data_004d20b0]
        mov     ebp, eax
        neg     ebp
        sbb     ebp, ebp
        neg     ebp
        dec     ebp
        cmp     ebp, -1
        jne     short L_tmr_restoreOnly
        call    Crt_errno_004c8ba0
        mov     dword ptr [eax], 0xd
        call    dword ptr [g_data_004d209c]
        mov     esi, eax
        call    Crt_doserrno_004c8bb0
        mov     dword ptr [eax], esi
    L_tmr_restoreOnly:
        push    0
        push    edi
        push    ebx
        call    LseekImpl_004c8e50
        add     esp, 0xc
        mov     eax, ebp
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        add     esp, 0x1004
        ret
    L_tmr_failEarly:
        pop     edi
        pop     esi
        pop     ebp
        or      eax, 0xffffffff
        pop     ebx
        add     esp, 0x1004
        ret
    }
}
