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
extern void WalkCbSubMul10_00431d50(void);
extern void Mul10Tail(unsigned int a, unsigned int b);
extern void BootMod6487eClampAndChainMul10(void);
extern void SpawnListBatchLoader_00477710(void);
extern void MStackPush2TableNot(void);
extern void GuardedChainCmpDualBitXor(void);
extern void ScaledLoadDecJmp_00429710(void);
extern void ScaledStoreCurDirtyClear_004296f0(void);
extern void MStackBitmaskIncMod_00492450(void);
extern void MStackBitmaskUpdate_00492510(void);
extern void Push1eCallTestDirtyLoop_004923b0(void);
extern void MStackLoopFieldInit_00492280(void);
extern void TaggedSceneDispatch(void);
extern void CallPauseDirty4StackPushFn_004839d0(void);
extern void CallPauseDirty1JmpDirty4StackPush_00483a80(void);
extern void Cmp2CallDirtyCall(void);
extern void QuadBlockArgInstallChain(void);
extern void InstallSelfChainSet84_80CallW_004363f0(void);
extern void Wrapper_00436490(void);
extern void MoveFsmCluster_004364a0(void);
extern void CallPauseTestByteJmpCalls(void);
extern void InstallSelfFullPath(void);
extern void InstallSelfCountdownChain_0047a950(void);
extern void CopyJmp_0048ef90(void);
extern void DualTestDirtyToggle_004282c0(void);
extern void TripleVecAccCallStore(void);
extern void Thunk_004bd5c0(void);
extern void AllocSlotPushTripleGlobals(void);
extern void MStackPop4Rewrite(void);
extern void Push70CallScaleArith(void);
extern void StreamChainStringInstall(void);
extern void MStackFrameCdeclDouble(void);
extern void ChainTableWalkStore_004917e0(void);
extern void Push16Call(void);
extern void DispatcherComplex260_00407030(void);
extern void ScaledLoadCmpStoreXfm_0048f2a0(void);
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

/* @addr 0x004c8880 (293b crt) - bundled float-to-string dispatcher.
 *   sub-1 (~182b at 0x4c8880): performs digit conversion via TmFillStringCopy+0x60
 *     helper, then either FcvtFormatDecimal or CfltcvtFormat based on exponent range.
 *   sub-2 (~101b at 0x4c8940): format dispatch on 'e'/'E'/'f'/'g' char.
 *   Bundled into one 293-byte entry (with 10-byte nop pad between subs).
 */
extern void CfltcvtFormat_004c8650(void);
extern void FcvtFormatDecimal_004c87c0(void);
extern void FormatHelper_004c8750(void);
extern void FpFormatRound_004ccda0(void);
extern void PrintfStubSigned_004c85d0(void);

__declspec(naked) void FloatToStringBundle_004c8880(void) {
    __asm {
        /* sub-1: digit conversion + format dispatch */
        sub     esp, 0x28
        lea     eax, [esp + 0x10]
        _emit   8dh
        _emit   4ch
        _emit   24h
        _emit   0h
        push    ebx
        push    ebp
        push    esi
        push    edi
        push    eax
        mov     eax, [esp + 0x40]
        push    ecx
        mov     edx, [eax + 4]
        mov     eax, [eax]
        push    edx
        push    eax
        _emit   0e8h
        _emit   09fh
        _emit   045h
        _emit   000h
        _emit   000h
        mov     ecx, [esp + 0x24]
        mov     ebp, [esp + 0x50]
        mov     ebx, [esp + 0x54]
        add     esp, 0x10
        lea     edi, [ecx - 1]
        mov     ecx, [esp + 0x10]
        xor     edx, edx
        cmp     ecx, 0x2d
        sete    dl
        add     edx, ebp
        lea     eax, [esp + 0x10]
        mov     esi, edx
        push    eax
        push    ebx
        push    esi
        call    FpFormatRound_004ccda0
        mov     ecx, [esp + 0x20]
        add     esp, 0xc
        lea     eax, [ecx - 1]
        xor     ecx, ecx
        cmp     edi, eax
        setl    cl
        cmp     eax, -4
        jl      short L_fts_eform
        cmp     eax, ebx
        jge     short L_fts_eform
        test    cl, cl
        jz      short L_fts_fcvt
        mov     dl, [esi]
        inc     esi
        test    dl, dl
        jz      short L_fts_term
    L_fts_skip:
        mov     al, [esi]
        inc     esi
        test    al, al
        jne     short L_fts_skip
    L_fts_term:
        mov     byte ptr [esi - 2], 0
    L_fts_fcvt:
        lea     ecx, [esp + 0x10]
        push    1
        push    ecx
        push    ebx
        push    ebp
        call    FcvtFormatDecimal_004c87c0
        add     esp, 0x10
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        add     esp, 0x28
        ret
    L_fts_eform:
        mov     eax, [esp + 0x48]
        lea     edx, [esp + 0x10]
        push    1
        push    edx
        push    eax
        push    ebx
        push    ebp
        call    CfltcvtFormat_004c8650
        add     esp, 0x14
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        add     esp, 0x28
        ret
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        /* sub-2 at 0x4c8940: format selector */
        mov     eax, [esp + 0xc]
        cmp     eax, 0x65
        jz      short L_fts_eFmt
        cmp     eax, 0x45
        jz      short L_fts_eFmt
        cmp     eax, 0x66
        jne     short L_fts_gFmt
        mov     eax, [esp + 0x10]
        mov     ecx, [esp + 8]
        mov     edx, [esp + 4]
        push    eax
        push    ecx
        push    edx
        call    FormatHelper_004c8750
        add     esp, 0xc
        ret
    L_fts_gFmt:
        mov     eax, [esp + 0x14]
        mov     ecx, [esp + 0x10]
        mov     edx, [esp + 8]
        push    eax
        mov     eax, [esp + 8]
        push    ecx
        push    edx
        push    eax
        call    FloatToStringBundle_004c8880
        add     esp, 0x10
        ret
    L_fts_eFmt:
        mov     ecx, [esp + 0x14]
        mov     edx, [esp + 0x10]
        mov     eax, [esp + 8]
        push    ecx
        mov     ecx, [esp + 8]
        push    edx
        push    eax
        push    ecx
        call    PrintfStubSigned_004c85d0
        add     esp, 0x10
        ret
    }
}
