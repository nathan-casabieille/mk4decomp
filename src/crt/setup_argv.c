/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;
extern unsigned int g_baseSel_00542060;
extern unsigned int g_acc_00542078;
extern unsigned int g_cj_0054205c;
extern unsigned int g_state_0053a718;
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
extern unsigned int g_stateCountdown_0053a3c0;
extern unsigned int g_installOwnerNode_00535cf8;
extern unsigned int g_cj_00542054;
extern unsigned int g_audioBoundNode_005437f0;
extern unsigned int g_data_00543598;
extern unsigned int g_data_0054358c;
extern unsigned int g_fightAxisNegX_00535e70;
extern unsigned int g_fightAxisNegY_00535e74;
extern unsigned int g_fightAxisPosX_00535e78;
extern unsigned int g_fightAxisPosY_00535e7c;

/* @addr 0x004cbc20 (158b crt) - argv[] setup from GetModuleFileNameA + ParseCommandLine.
 *   Frame: sub esp, 8; push esi, edi.
 *   GetModuleFileNameA(NULL, [0xf9faf0], MAX_PATH).
 *   edi = [0xfa0ee8]; [0xf9f830] = [0xf9faf0].
 *   if (*edi == 0): edi = [0xf9faf0] (use module path).
 *   Call CrtParseCommandLine_004cbcc0 (parse, count). Get char_size + arg_count.
 *   Call malloc/realloc-like LoadArgPushCall(total_bytes). esi = result.
 *   if (esi == 0): call CmpCallPushIATCall(8) (errno).
 *   Call CrtParseCommandLine_004cbcc0 again (this time storing args). [0xf9f818] = esi (argv array).
 *   [0xf9f814] = argc - 1.
 */
extern unsigned int g_GetModuleFileNameA_004d20a0;
extern unsigned int g_buf_00f9faf0;
extern unsigned int g_x_00f9f814;
extern unsigned int g_x_00f9f818;
extern unsigned int g_x_00f9f830;
extern char * g_cmdline;
extern void CmpCallPushIATCall_004c6e60(void);
extern void CrtParseCommandLine_004cbcc0(void);
extern void LoadArgPushCall_004c54b0(void);

__declspec(naked) void SetupArgv_004cbc20(void) {
    __asm {
        sub     esp, 8
        push    esi
        push    edi
        push    0x104
        push    offset g_buf_00f9faf0
        push    0
        call    dword ptr [g_GetModuleFileNameA_004d20a0]
        mov     edi, dword ptr [g_cmdline]
        mov     dword ptr [g_x_00f9f830], offset g_buf_00f9faf0
        cmp     byte ptr [edi], 0
        _emit   75h
        _emit   05h
        mov     edi, offset g_buf_00f9faf0
        lea     eax, [esp + 0x0c]
        lea     ecx, [esp + 8]
        push    eax
        push    ecx
        push    0
        push    0
        push    edi
        call    CrtParseCommandLine_004cbcc0
        mov     edx, [esp + 0x20]
        mov     eax, [esp + 0x1c]
        add     esp, 0x14
        lea     ecx, [edx + eax*4]
        push    ecx
        call    LoadArgPushCall_004c54b0
        mov     esi, eax
        add     esp, 4
        test    esi, esi
        _emit   75h
        _emit   0ah
        push    8
        call    CmpCallPushIATCall_004c6e60
        add     esp, 4
        mov     ecx, [esp + 8]
        lea     edx, [esp + 0x0c]
        push    edx
        lea     eax, [esp + 0x0c]
        lea     edx, [esi + ecx*4]
        push    eax
        push    edx
        push    esi
        push    edi
        call    CrtParseCommandLine_004cbcc0
        mov     eax, [esp + 0x1c]
        add     esp, 0x14
        dec     eax
        mov     dword ptr [g_x_00f9f818], esi
        pop     edi
        mov     dword ptr [g_x_00f9f814], eax
        pop     esi
        add     esp, 8
        ret
    }
}
