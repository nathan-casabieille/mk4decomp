/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;
extern unsigned int g_baseSel;
extern unsigned int g_acc_00542078;
extern unsigned int g_cj_0054205c;
extern unsigned int g_gameCountdown;
extern unsigned int g_xformScratch94;
extern unsigned int g_table_00535ddc;
extern unsigned int g_active_00537e88;
extern unsigned int g_active_0053a408;
extern unsigned int g_audioBankSel;

extern void StoreTwoCall(int, int);
extern void SetJmp_0049cb90(void);
extern void Thunk_0049cbd0(void);
extern void ScaledZeroFour(void);
extern void WalkCbSubMul10(void);
extern void Mul10Tail(unsigned int a, unsigned int b);
extern void BootMod6487eClampAndChainMul10(void);
extern void SpawnListBatchLoader(void);
extern void MStackPush2TableNot(void);
extern void GuardedChainCmpDualBitXor(void);
extern void ScaledLoadDecJmp(void);
extern void ScaledStoreCurDirtyClear(void);
extern void MStackBitmaskIncMod(void);
extern void MStackBitmaskUpdate(void);
extern void Push1eCallTestDirtyLoop(void);
extern void MStackLoopFieldInit(void);
extern void TaggedSceneDispatch(void);
extern void CallPauseDirty4StackPushFn(void);
extern void CallPauseDirty1JmpDirty4StackPush_00483a80(void);
extern void Cmp2CallDirtyCall(void);
extern void QuadBlockArgInstallChain(void);
extern void InstallSelfChainSet84_80CallW(void);
extern void Wrapper_00436490(void);
extern void MoveFsmCluster(void);
extern void CallPauseTestByteJmpCalls(void);
extern void InstallSelfFullPath(void);
extern void InstallSelfCountdownChain(void);
extern void CopyJmp_0048ef90(void);
extern void DualTestDirtyToggle_004282c0(void);
extern void TripleVecAccCallStore(void);
extern void Thunk_004bd5c0(void);
extern void AllocSlotPushTripleGlobals(void);
extern void MStackPop4Rewrite(void);
extern void Push70CallScaleArith(void);
extern void StreamChainStringInstall(void);
extern void MStackFrameCdeclDouble(void);
extern void ChainTableWalkStore(void);
extern void Push16Call(void);
extern void DispatcherComplex260_00407030(void);
extern void ScaledLoadCmpStoreXfm(void);
extern void StackPopDispatchTagged(void);
extern unsigned int g_cj_00542058;
extern unsigned int g_rangeSqLimit;
extern unsigned int g_zero_00541fa4;
extern unsigned int g_zero_00541fa8;
extern unsigned int g_dualBitGate;
extern unsigned int g_eventArmReload;
extern unsigned int g_rangeBase;

extern void ScaledArrStore_004298c0(void);
extern void DualFieldAddSubStore(void);
extern void IterStepDualStore(int);
extern void ScaledXorStore_004900f0(void);
extern void ChainWalkInstall(void);
extern void FpuSqrtMul(void);
extern void PendingMatch_0042b930(void);
extern void MStackPush2RunCountdown(void);
extern void MStackBracket7_DispatchAndChain(void);
extern void MStackBracketed3StoreCall(void);
extern void ChainDirtyBitWalker(void);
extern void Wrapper_0048a350(void);
extern void Wrapper_0048a3a0(void);
extern void Helper_DownloadSetup(void);
extern void MStackPush3CmpCall(void);
extern void Wrapper_0048ec20(void);
extern void FiveCallScaledChainTailJmp(void);
extern void SetJmp_00438f50(void);
extern void SetJmp_00438f60(void);
extern void GuardedDispatch_0042b6c0(void);
extern void MStackPushZeroCallPop_00407d00(void);
extern void DirtyToggleByGate(void);
extern void GameDispatchValidateState(void);
extern void CrouchAttackFsmCluster(void);
extern void MStackPushVec3Mul10(void);
extern void LiteralPushCallEntZero(void);
extern void LeaPlus22StoreSelf(void);
extern void IterLoad_00491050(void);
extern void GuardedDualConst2AndToggle(void);
extern void CallPauseScaledStorePushCall(void);
extern void LoadGeoAsset_Default(void);
extern void DispatcherComplex260_00407400(void);
extern void PushSetCallPop(void);
extern unsigned int g_stateCountdown;
extern unsigned int g_installOwnerNode;
extern unsigned int g_cj_00542054;
extern unsigned int g_audioBoundNode;
extern unsigned int g_lastGatedValue;
extern unsigned int g_lastGatedTick;
extern unsigned int g_fightAxisNegX;
extern unsigned int g_fightAxisNegY;
extern unsigned int g_fightAxisPosX;
extern unsigned int g_fightAxisPosY;

/* @addr 0x004c5fc0 (326b crt) - _fwrite_nolock.
 *   Stack args: size, count, buf, stream. Multiplies size*count into total
 *   bytes. Handles 3 cases on stream flags (FILE.flags @ +0xc):
 *     - dirty/text translation bits (0x10c): take the buffered fast path
 *       (rep movsd/movsb into [ebx], decrement remaining at [ebx+4]).
 *     - line-buffered/needs-flush bits (0x108): walk one byte at a time via
 *       Flsbuf (the slow path).
 *     - otherwise: chunk via IOWrapper_004c9ae0 (write syscall), passing the
 *       file descriptor at [ebx+0x10].
 *   On error sets the FILE error flag (or 0x20) and returns count of bytes
 *   transferred via div by 'size'.
 */
extern void FFlushImpl(void);
extern void Flsbuf(void);
extern void IOWrapper_004c9ae0(void);

__declspec(naked) void FWriteNoLock(void) {
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
        call    FFlushImpl
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
        call    Flsbuf
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
