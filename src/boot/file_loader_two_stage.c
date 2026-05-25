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

extern unsigned int g_data_004d5040;
extern unsigned int g_data_004d504c;
extern unsigned int g_data_004d505c;
extern unsigned int g_data_004d5060;
extern unsigned int g_data_004d506c;
extern unsigned int g_data_00524158;
extern unsigned int g_fileLoaderState_00524358;
extern void FSYS_fclose(void);
extern void FSYS_fopen(void);
extern void FSYS_fread(void);
extern void FSYS_fseek(void);
extern void FSYS_ftell(void);
extern void Helper_Sprintf(void);
extern void ListInitLoop_00401310(void);
extern void LoadArgPushCall_004c54b0(void);
extern void MemcpyByteN_004a5680(void);
extern void ShowErrorMessage(void);

__declspec(naked) void FileLoaderTwoStage_00401120(void)
{
    __asm {
        sub     esp, 0x100
        _emit   0x8D
        _emit   0x44
        _emit   0x24
        _emit   0x00
        push    ebx
        push    ebp
        push    esi
        mov     esi, dword ptr [esp + 0x110]
        push    edi
        push    esi
        push    offset g_data_004d506c
        push    offset g_data_004d5060
        push    eax
        call    Helper_Sprintf
        add     esp, 0x10
        lea     ecx, [esp + 0x10]
        push    offset g_data_004d505c
        push    ecx
        call    FSYS_fopen
        mov     ebx, eax
        add     esp, 8
        test    ebx, ebx
        jne     L_fl_have_f1
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        add     esp, 0x100
        ret
    L_fl_have_f1:
        push    2
        push    0
        push    ebx
        call    FSYS_fseek
        add     esp, 0xC
        push    ebx
        call    FSYS_ftell
        add     esp, 4
        mov     ebp, eax
        push    0
        push    0
        push    ebx
        call    FSYS_fseek
        add     esp, 0xC
        push    ebp
        call    LoadArgPushCall_004c54b0
        add     esp, 4
        mov     dword ptr [g_fileLoaderState_00524358], eax
        test    eax, eax
        jne     L_fl_have_buf
        push    offset g_data_004d504c
        call    ShowErrorMessage
        mov     eax, dword ptr [g_fileLoaderState_00524358]
        add     esp, 4
        test    eax, eax
        jne     L_fl_have_buf
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        add     esp, 0x100
        ret
    L_fl_have_buf:
        push    esi
        push    offset g_data_004d506c
        lea     edx, [esp + 0x98]
        push    offset g_data_004d5040
        push    edx
        call    Helper_Sprintf
        add     esp, 0x10
        lea     eax, [esp + 0x90]
        push    offset g_data_004d505c
        push    eax
        call    FSYS_fopen
        mov     esi, eax
        add     esp, 8
        test    esi, esi
        jne     L_fl_have_f2
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        add     esp, 0x100
        ret
    L_fl_have_f2:
        push    2
        push    0
        push    esi
        call    FSYS_fseek
        add     esp, 0xC
        push    esi
        call    FSYS_ftell
        mov     edi, eax
        add     esp, 4
        cmp     edi, ebp
        jle     L_fl_size_ok
        xor     eax, eax
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        add     esp, 0x100
        ret
    L_fl_size_ok:
        push    0
        push    0
        push    esi
        call    FSYS_fseek
        mov     ecx, dword ptr [g_fileLoaderState_00524358]
        add     esp, 0xC
        push    esi
        push    edi
        push    1
        push    ecx
        call    FSYS_fread
        add     esp, 0x10
        push    esi
        call    FSYS_fclose
        mov     edx, dword ptr [g_fileLoaderState_00524358]
        add     esp, 4
        push    0x200
        push    edx
        push    offset g_data_00524158
        call    MemcpyByteN_004a5680
        add     esp, 0xC
        call    ListInitLoop_00401310
        mov     esi, dword ptr [g_fileLoaderState_00524358]
        xor     eax, eax
        mov     ax, word ptr [esi + 0x200]
        lea     ecx, [esi + 0x200]
        mov     edx, eax
        add     ecx, 2
        and     edx, 0x8000
        cmp     eax, 0xFFFF
        je      L_fl_terminator
    L_fl_loop:
        and     eax, 0x7FFF
        add     ecx, 2
        add     ecx, 2
        lea     eax, [eax + eax*2]
        mov     dword ptr [eax*4 + 0x004FFDEC], esi
        mov     edi, dword ptr [eax*4 + 0x004FFDF4]
        and     edi, 0xFFFF7FFF
        add     edi, edx
        mov     dword ptr [eax*4 + 0x004FFDF4], edi
        xor     eax, eax
        mov     ax, word ptr [ecx - 4]
        add     esi, eax
        xor     eax, eax
        mov     ax, word ptr [ecx - 2]
        mov     edx, eax
        and     edx, 0x8000
        cmp     eax, 0xFFFF
        jne     L_fl_loop
        mov     esi, dword ptr [g_fileLoaderState_00524358]
    L_fl_terminator:
        push    ebx
        push    ebp
        push    1
        push    esi
        call    FSYS_fread
        add     esp, 0x10
        push    ebx
        call    FSYS_fclose
        mov     eax, dword ptr [g_fileLoaderState_00524358]
        add     esp, 4
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        add     esp, 0x100
        ret
    }
}
