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

/* @addr 0x004cb700 (372b crt) - 3-entry CRT FILE table mgmt. */
extern unsigned int g_iat_004d209c;
extern unsigned int g_dispatchSave882_004d20f0;
extern unsigned int g_byte_00f9f838;
extern unsigned int g_dispatchSave1465_00f9fdb4;
extern unsigned int g_dispatchSave1466_00fa0dc0;
extern unsigned int g_arr_00fa0de0;
extern unsigned int g_dispatchSave1469_00fa0ee0;
extern void CRTHandleLookup_004cd260(void);
extern void Calloc_004c6110(void);
extern void CmpCallPushIATCall_004c6e60(void);
extern void CritSecLazyEnter_004cd2b0(void);
extern void Crt_doserrno_004c8bb0(void);
extern void Crt_errno_004c8ba0(void);
extern void DivMod32IAT_004cd320(void);
extern void PushConstCall_004c6a10(void);
extern void StreamCleanupLoop_004ce0b0(void);

__declspec(naked) void FileTableClose_004cb700(void) {
    __asm {
        mov     eax, dword ptr [g_dispatchSave1469_00fa0ee0]
        push    ebp
        push    esi
        push    edi
        mov     edi, dword ptr [esp + 0x10]
        cmp     edi, eax
        jae     short L_ftc_failEBADF
        mov     eax, edi
        sar     eax, 5
        lea     ebp, [eax*4 + g_arr_00fa0de0]
        mov     eax, edi
        and     eax, 0x1f
        mov     ecx, dword ptr [ebp]
        lea     esi, [eax + eax*8]
        shl     esi, 2
        test    byte ptr [ecx + esi + 4], 1
        je      short L_ftc_failEBADF
        push    edi
        call    CritSecLazyEnter_004cd2b0
        mov     edx, dword ptr [ebp]
        add     esp, 4
        test    byte ptr [edx + esi + 4], 1
        je      short L_ftc_setErr9
        push    edi
        call    CRTHandleLookup_004cd260
        add     esp, 4
        push    eax
        call    dword ptr [g_dispatchSave882_004d20f0]
        test    eax, eax
        jne     short L_ftc_clearErr
        call    dword ptr [g_iat_004d209c]
        mov     esi, eax
        jmp     short L_ftc_checkErr
    L_ftc_clearErr:
        xor     esi, esi
    L_ftc_checkErr:
        test    esi, esi
        je      short L_ftc_skipErr
        call    Crt_doserrno_004c8bb0
        mov     dword ptr [eax], esi
    L_ftc_setErr9:
        call    Crt_errno_004c8ba0
        mov     dword ptr [eax], 9
        or      esi, 0xffffffff
    L_ftc_skipErr:
        push    edi
        call    DivMod32IAT_004cd320
        add     esp, 4
        mov     eax, esi
        pop     edi
        pop     esi
        pop     ebp
        ret
    L_ftc_failEBADF:
        call    Crt_errno_004c8ba0
        pop     edi
        mov     dword ptr [eax], 9
        pop     esi
        or      eax, 0xffffffff
        pop     ebp
        ret
        nop
        nop
        /* entry 2 (offset 0xa0) */
    L_ftc_entry2:
        mov     eax, dword ptr [g_dispatchSave1466_00fa0dc0]
        push    esi
        test    eax, eax
        jne     short L_ftc_haveSize
        mov     eax, 0x200
        jmp     short L_ftc_doAlloc
    L_ftc_haveSize:
        cmp     eax, 0x14
        jge     short L_ftc_skipClamp
        mov     eax, 0x14
    L_ftc_doAlloc:
        mov     dword ptr [g_dispatchSave1466_00fa0dc0], eax
    L_ftc_skipClamp:
        push    4
        push    eax
        call    Calloc_004c6110
        add     esp, 8
        mov     dword ptr [g_dispatchSave1465_00f9fdb4], eax
        test    eax, eax
        jne     short L_ftc_initTable
        push    4
        push    0x14
        mov     dword ptr [g_dispatchSave1466_00fa0dc0], 0x14
        call    Calloc_004c6110
        add     esp, 8
        mov     dword ptr [g_dispatchSave1465_00f9fdb4], eax
        test    eax, eax
        jne     short L_ftc_initTable
        push    0x1a
        call    CmpCallPushIATCall_004c6e60
        mov     eax, dword ptr [g_dispatchSave1465_00f9fdb4]
        add     esp, 4
    L_ftc_initTable:
        xor     edx, edx
        mov     ecx, 0x522600
        jmp     short L_ftc_writeFirst
    L_ftc_writePtr:
        mov     eax, dword ptr [g_dispatchSave1465_00f9fdb4]
    L_ftc_writeFirst:
        mov     dword ptr [eax + edx], ecx
        add     ecx, 0x20
        add     edx, 4
        cmp     ecx, 0x522880
        jl      short L_ftc_writePtr
        xor     ecx, ecx
        mov     edx, 0x522610
    L_ftc_walkInit:
        mov     esi, ecx
        mov     eax, ecx
        sar     esi, 5
        and     eax, 0x1f
        mov     esi, dword ptr [esi*4 + g_arr_00fa0de0]
        lea     eax, [eax + eax*8]
        mov     eax, dword ptr [esi + eax*4]
        cmp     eax, -1
        je      short L_ftc_setNeg1
        test    eax, eax
        jne     short L_ftc_skipNeg1
    L_ftc_setNeg1:
        mov     dword ptr [edx], 0xffffffff
    L_ftc_skipNeg1:
        add     edx, 0x20
        inc     ecx
        cmp     edx, 0x522670
        jl      short L_ftc_walkInit
        pop     esi
        ret
        nop
        nop
        nop
        nop
        /* entry 3 (offset 0x160) */
    L_ftc_entry3:
        call    PushConstCall_004c6a10
        mov     al, byte ptr [g_byte_00f9f838]
        test    al, al
        je      short L_ftc_e3End
        jmp     StreamCleanupLoop_004ce0b0
    L_ftc_e3End:
        ret
    }
}
