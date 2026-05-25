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
extern unsigned int g_state_00542094;
extern unsigned int g_state_00535ddc;
extern unsigned int g_state_00537e88;
extern unsigned int g_state_0053a408;
extern unsigned int g_state_00537f94;
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

/* @addr 0x004cdee0 (259b crt) - _frexp-like double mantissa/exponent split.
 *   Arg: double x at [esp+4], int* exp at [esp+0x18].
 *   Compares x to 0.0 (g_data_004d2f28). If equal: *exp = 0, return 0.0.
 *   Else: extract exponent bits; if 0 (denormal/zero): denormal-renormalize
 *     loop, then compute fresh mantissa via PackDoubleFromInts; *exp = computed.
 *   Normal: pack 64-bit mantissa via PackDoubleFromInts, extract biased exp,
 *     store *exp = biased_exp - 0x3fe, return mantissa as double.
 */
extern unsigned int g_data_004d2f28;
extern void PackDoubleFromInts_004cde40(void);

__declspec(naked) void Frexp_004cdee0(void) {
    __asm {
        fld     qword ptr [esp + 4]
        fcomp   qword ptr [g_data_004d2f28]
        push    ebx
        push    esi
        push    edi
        fnstsw  ax
        test    ah, 0x40
        jz      short L_fx_nz
        mov     ecx, [esp + 0x18]
        mov     dword ptr [esp + 0x10], 0
        mov     dword ptr [esp + 0x14], 0
        xor     esi, esi
        fld     qword ptr [esp + 0x10]
        mov     [ecx], esi
        pop     edi
        pop     esi
        pop     ebx
        ret
    L_fx_nz:
        mov     esi, [esp + 0x16]
        mov     edx, [esp + 0x14]
        mov     ecx, [esp + 0x10]
        test    esi, 0x7ff0
        jne     L_fx_normal
        test    edx, 0xfffff
        jne     short L_fx_denorm
        test    ecx, ecx
        jz      L_fx_normal
    L_fx_denorm:
        fld     qword ptr [esp + 0x10]
        fcomp   qword ptr [g_data_004d2f28]
        mov     esi, -0x3fd
        fnstsw  ax
        test    ah, 1
        jz      short L_fx_dnoneg
        mov     edi, 1
        jmp     short L_fx_dnsetup
    L_fx_dnoneg:
        xor     edi, edi
    L_fx_dnsetup:
        mov     bl, byte ptr [esp + 0x16]
        mov     al, 0x10
        test    bl, al
        jne     short L_fx_dndone
    L_fx_dnloop:
        shl     edx, 1
        test    ecx, 0x80000000
        mov     [esp + 0x14], edx
        jz      short L_fx_dnsave
        or      edx, 1
        mov     [esp + 0x14], edx
    L_fx_dnsave:
        mov     bl, byte ptr [esp + 0x16]
        shl     ecx, 1
        dec     esi
        test    bl, al
        jz      short L_fx_dnloop
    L_fx_dndone:
        _emit   66h
        _emit   81h
        _emit   64h
        _emit   24h
        _emit   16h
        _emit   0efh
        _emit   0ffh
        test    edi, edi
        jz      short L_fx_dnPos
        or      byte ptr [esp + 0x17], 0x80
    L_fx_dnPos:
        mov     eax, dword ptr [esp + 0x14]
        push    0
        push    eax
        push    ecx
        call    PackDoubleFromInts_004cde40
        mov     ecx, [esp + 0x24]
        add     esp, 0xc
        fstp    qword ptr [esp + 0x10]
        fld     qword ptr [esp + 0x10]
        mov     [ecx], esi
        pop     edi
        pop     esi
        pop     ebx
        ret
    L_fx_normal:
        push    0
        push    edx
        push    ecx
        call    PackDoubleFromInts_004cde40
        mov     ecx, [esp + 0x24]
        add     esp, 0xc
        shr     esi, 4
        fstp    qword ptr [esp + 0x10]
        and     esi, 0x7ff
        pop     edi
        movsx   esi, si
        fld     qword ptr [esp + 0xc]
        sub     esi, 0x3fe
        mov     [ecx], esi
        pop     esi
        pop     ebx
        ret
    }
}
