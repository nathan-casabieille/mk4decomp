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
extern void SetJmp_Thunk_LinkedListBitMaskSearch(void);
extern void Thunk_ChainNodeInit(void);
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
extern void Wrapper_PackedAdvanceCallTailJmp_004e46d0(void);
extern void MoveFsmCluster(void);
extern void CallPauseTestByteJmpCalls(void);
extern void InstallSelfFullPath(void);
extern void InstallSelfCountdownChain(void);
extern void CopyJmp_SlotCmp3way_g_currentNodeIdx(void);
extern void DualTestDirtyToggle_004282c0(void);
extern void TripleVecAccCallStore(void);
extern void Thunk_LoadGeoAsset_Default(void);
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

extern void ScaledArrStore_ScaledChainJmp_004298c0(void);
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
extern void Wrapper_ScaledChainPushCall_004ef858(void);
extern void Wrapper_ScaledChainPushCall_004ef8b0(void);
extern void Helper_DownloadSetup(void);
extern void MStackPush3CmpCall(void);
extern void Wrapper_IterLoad_0048fd30_004f12a0(void);
extern void FiveCallScaledChainTailJmp(void);
extern void SetJmp_StateDispatchYield_00438f50(void);
extern void SetJmp_StateDispatchYield_00438f60(void);
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

extern unsigned int g_dispatchSave651;
extern unsigned int g_iat_GetLastError;
extern void Helper_ChkStk(void);
extern void LseekImpl(void);
extern void FileWriteWithLfToCrlf(void);
extern void Crt_errno(void);
extern void Crt_doserrno(void);

/* @addr 0x004cef10 (334b crt) - text-mode read-CRLF normalize, ~_lread-style.
 *   Big stack frame (4100b via Helper_ChkStk). Saves the current
 *   file position with LseekImpl(fd, 0, 1) and remembers it. Probes the
 *   file size via LseekImpl(fd, 0, 2). If size > 0, sets up a 4KB scratch
 *   buffer on the stack, switches the fd to binary via Setmode,
 *   then loops reading via FileWriteWithLfToCrlf (read), decrementing remaining
 *   bytes by the amount returned. On EOF or error, dispatches via
 *   Crt_errno / Crt_doserrno to set errno=0xd (EBADF) if the
 *   underlying error code was 5. Finally restores binary→text via Setmode
 *   again. The smaller branch (size <= 0) makes two direct IAT calls
 *   [0x4d20b0] and [0x4d209c] (likely SetFilePointer / GetLastError or
 *   similar) to fall back to the OS handle. Returns ebp (success/-1).
 */
extern void CRTHandleLookup(void);
extern void Setmode(void);

__declspec(naked) void TextModeReadStream(void) {
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
        call    LseekImpl
        mov     edi, eax
        add     esp, 0xc
        cmp     edi, -1
        mov     dword ptr [esp + 0x10], edi
        je      L_tmr_failEarly
        push    2
        push    ebp
        push    ebx
        call    LseekImpl
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
        call    Setmode
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
        call    FileWriteWithLfToCrlf
        add     esp, 0xc
        cmp     eax, -1
        je      short L_tmr_readErr
        sub     esi, eax
        test    esi, esi
        jle     short L_tmr_readDone
        jmp     short L_tmr_readLoop
    L_tmr_readErr:
        call    Crt_doserrno
        cmp     dword ptr [eax], 5
        jne     short L_tmr_setErrTail
        call    Crt_errno
        mov     dword ptr [eax], 0xd
    L_tmr_setErrTail:
        or      ebp, 0xffffffff
    L_tmr_readDone:
        push    edi
        push    ebx
        call    Setmode
        mov     edi, dword ptr [esp + 0x18]
        add     esp, 8
        push    0
        push    edi
        push    ebx
        call    LseekImpl
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
        call    LseekImpl
        add     esp, 0xc
        push    ebx
        call    CRTHandleLookup
        add     esp, 4
        push    eax
        call    dword ptr [g_dispatchSave651]
        mov     ebp, eax
        neg     ebp
        sbb     ebp, ebp
        neg     ebp
        dec     ebp
        cmp     ebp, -1
        jne     short L_tmr_restoreOnly
        call    Crt_errno
        mov     dword ptr [eax], 0xd
        call    dword ptr [g_iat_GetLastError]
        mov     esi, eax
        call    Crt_doserrno
        mov     dword ptr [eax], esi
    L_tmr_restoreOnly:
        push    0
        push    edi
        push    ebx
        call    LseekImpl
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
