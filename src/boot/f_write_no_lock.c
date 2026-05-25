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

/* @addr 0x004c5fc0 (326b crt) - _fwrite_nolock.
 *   Stack args: size, count, buf, stream. Multiplies size*count into total
 *   bytes. Handles 3 cases on stream flags (FILE.flags @ +0xc):
 *     - dirty/text translation bits (0x10c): take the buffered fast path
 *       (rep movsd/movsb into [ebx], decrement remaining at [ebx+4]).
 *     - line-buffered/needs-flush bits (0x108): walk one byte at a time via
 *       Flsbuf_004c77f0 (the slow path).
 *     - otherwise: chunk via IOWrapper_004c9ae0 (write syscall), passing the
 *       file descriptor at [ebx+0x10].
 *   On error sets the FILE error flag (or 0x20) and returns count of bytes
 *   transferred via div by 'size'.
 */
extern void FFlushImpl_004c69a0(void);
extern void Flsbuf_004c77f0(void);
extern void IOWrapper_004c9ae0(void);

__declspec(naked) void FWriteNoLock_004c5fc0(void) {
    __asm {
        push    ecx
        push    ebx
        push    ebp
        mov     ebp, dword ptr [esp + 0x18]
        push    esi
        imul    ebp, dword ptr [esp + 0x18]
        mov     esi, dword ptr [esp + 0x14]
        push    edi
        test    ebp, ebp
        mov     dword ptr [esp + 0x18], esi
        mov     dword ptr [esp + 0x10], ebp
        jne     short L_fwr_haveBytes
        xor     eax, eax
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        pop     ecx
        ret
    L_fwr_haveBytes:
        mov     ebx, dword ptr [esp + 0x24]
        test    dword ptr [ebx + 0xc], 0x10c
        je      short L_fwr_unbuffered
        mov     edi, dword ptr [ebx + 0x18]
        mov     dword ptr [esp + 0x24], edi
        jmp     short L_fwr_topLoop
    L_fwr_unbuffered:
        mov     dword ptr [esp + 0x24], 0x1000
    L_fwr_loopHead:
        mov     edi, dword ptr [esp + 0x24]
    L_fwr_topLoop:
        mov     ecx, dword ptr [ebx + 0xc]
        and     ecx, 0x108
        je      short L_fwr_noBufCase
        mov     eax, dword ptr [ebx + 4]
        test    eax, eax
        je      short L_fwr_noBufCase
        cmp     ebp, eax
        jae     short L_fwr_useEax
        mov     eax, ebp
    L_fwr_useEax:
        mov     edi, dword ptr [ebx]
        mov     ecx, eax
        mov     edx, ecx
        sub     ebp, eax
        shr     ecx, 2
        rep movsd
        mov     ecx, edx
        and     ecx, 3
        rep movsb
        mov     esi, dword ptr [ebx + 4]
        mov     edx, dword ptr [ebx]
        mov     ecx, dword ptr [esp + 0x18]
        sub     esi, eax
        add     edx, eax
        add     ecx, eax
        mov     dword ptr [ebx + 4], esi
        mov     dword ptr [ebx], edx
        mov     dword ptr [esp + 0x18], ecx
        mov     esi, ecx
        jmp     short L_fwr_loopBottom
    L_fwr_noBufCase:
        cmp     ebp, edi
        jb      short L_fwr_byteSlow
        test    ecx, ecx
        je      short L_fwr_doIO
        push    ebx
        call    FFlushImpl_004c69a0
        add     esp, 4
        test    eax, eax
        jne     L_fwr_errPath
    L_fwr_doIO:
        test    edi, edi
        je      short L_fwr_useEbp
        mov     eax, ebp
        xor     edx, edx
        div     edi
        mov     edi, ebp
        sub     edi, edx
        jmp     short L_fwr_callIO
    L_fwr_useEbp:
        mov     edi, ebp
    L_fwr_callIO:
        mov     eax, dword ptr [ebx + 0x10]
        push    edi
        push    esi
        push    eax
        call    IOWrapper_004c9ae0
        add     esp, 0xc
        cmp     eax, -1
        je      short L_fwr_setErr
        sub     ebp, eax
        add     esi, eax
        cmp     eax, edi
        mov     dword ptr [esp + 0x18], esi
        jb      short L_fwr_setErr
        jmp     short L_fwr_loopBottom
    L_fwr_byteSlow:
        movsx   ecx, byte ptr [esi]
        push    ebx
        push    ecx
        call    Flsbuf_004c77f0
        add     esp, 8
        cmp     eax, -1
        je      short L_fwr_errPath
        mov     eax, dword ptr [ebx + 0x18]
        inc     esi
        dec     ebp
        mov     dword ptr [esp + 0x18], esi
        test    eax, eax
        mov     dword ptr [esp + 0x24], eax
        jg      short L_fwr_loopBottom
        mov     dword ptr [esp + 0x24], 1
    L_fwr_loopBottom:
        test    ebp, ebp
        jne     L_fwr_loopHead
        mov     eax, dword ptr [esp + 0x20]
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        pop     ecx
        ret
    L_fwr_setErr:
        mov     edx, dword ptr [ebx + 0xc]
        mov     eax, dword ptr [esp + 0x10]
        or      edx, 0x20
        sub     eax, ebp
        mov     dword ptr [ebx + 0xc], edx
        xor     edx, edx
        div     dword ptr [esp + 0x1c]
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        pop     ecx
        ret
    L_fwr_errPath:
        mov     eax, dword ptr [esp + 0x10]
        xor     edx, edx
        sub     eax, ebp
        div     dword ptr [esp + 0x1c]
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        pop     ecx
        ret
    }
}
