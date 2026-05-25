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

/* @addr 0x004c51f0 (171b boot) - aux audio reference-window probe.
 *   Frame: sub esp, 0x3c; push esi, edi.
 *   Init 15-dword reference window on stack: buf[0]=0, buf[1..8]=0x5c,
 *   buf[9]=0x7a, buf[10]=0x10, buf[11]=0x38, buf[12..14]=0x5c, buf[15]=0x5a.
 *   Clear g_demoModeFlag; call Helper_AuxAudio_PostInit.
 *   If success, call DSoundQueryProperty; require rv==0xf.
 *   Loop esi=1..14: rv=AuxAudioDevCapsQuery(esi); abs(rv - buf[esi-1]) must be <= 5.
 *   If all pass, set g_demoModeFlag = 1.
 */
extern unsigned int g_iat_004d20b8;
extern unsigned int g_iat_004d20bc;
extern unsigned int g_iat_004d20e4;
extern u32 g_demoModeFlag;
extern void AuxAudioDevCapsQuery_004ac3f0(void);
extern void DSoundQueryProperty_004ac3a0(void);
extern void FreeImpl_004c55f0(void);
extern void Helper_AuxAudio_PostInit(void);

extern unsigned int g_data_004d29f8;
extern unsigned int g_data_004d29fc;
extern unsigned int g_data_004d2b90;
extern unsigned int g_data_004d2b94;
extern unsigned int g_data_004d2f20;
extern unsigned int g_data_004d2f24;
extern unsigned int g_data_004d2f28;
extern unsigned int g_data_004d505c;
extern unsigned int g_data_004f478c;
extern unsigned int g_data_004f47a0;
extern unsigned int g_data_004f47a8;
extern unsigned int g_data_004f47b0;
extern unsigned int g_data_004f5398;
extern unsigned int g_data_004f5798;
extern unsigned int g_data_004f613c;
extern unsigned int g_data_004ffd4c;
extern unsigned int g_data_005222e0;
extern unsigned int g_data_00522620;
extern unsigned int g_crtCType_00522998;
extern unsigned int g_crtLocaleNumeric_00522bb0;
extern unsigned int g_crtFpuTbyteVar_00522e58;
extern unsigned int g_data_00522e68;
extern unsigned int g_data_00523600;
extern unsigned int g_data_005236ac;
extern unsigned int g_dispatchPair_005236b8;
extern unsigned int g_crtTimeFmtPrefs_005236e8;
extern u8 g_renderer2_buf3[];
extern unsigned int g_installCountdownBase_00544298;
extern unsigned int g_dispatchInit1007_0054429c;
extern unsigned int g_data_005442a0;
extern unsigned int g_data_005442a4;
extern unsigned int g_data_005442e0;
extern unsigned int g_data_00544300;
extern u8 g_renderer2_buf2[];
extern unsigned int g_renderer2_baseB_0058c760;
extern unsigned int g_data_0058c764;
extern u8 g_renderer2_buf1[];
extern unsigned int g_comptr_0058c7ac;
extern unsigned int g_renderer2_obj;
extern unsigned int g_990_iface;
extern int g_renderer2_present_rc;
extern unsigned int g_data_0058c7dc_2;
extern unsigned int g_dd3SurfaceCreate_0058c858;
extern unsigned int g_data_0058c85c;
extern unsigned int g_dsmi_b70_main;
extern unsigned int g_dsmi_b70_ret;
extern unsigned int g_960_iface;
extern unsigned int g_renderer4_ifaceBase_0058c8d8;
extern unsigned int g_data_0058c8dc;
extern unsigned int g_dsmi_3a0_main;
extern unsigned int g_dsmi_3a0_ret;
extern unsigned int g_190_iface;
extern unsigned int g_data_007af4e8;
extern unsigned int g_data_007af4ea;
extern unsigned int g_data_007af4f0;
extern unsigned int g_data_007af4f2;
extern unsigned int g_data_007af4f4;
extern unsigned int g_data_007af4f5;
extern unsigned int g_data_007af4f8;
extern unsigned int g_data_007af4f9;
extern unsigned int g_data_007af4fa;
extern unsigned int g_data_007af4fc;
extern unsigned int g_data_007af502;
extern unsigned int g_byte_007af508;
extern unsigned int g_data_007af934;
extern unsigned int g_data_007af938;
extern unsigned int g_data_007af93c;
extern int g_renderer4_active;
extern unsigned int g_data_007af944;
extern int g_renderer4_surface;
extern unsigned int g_data_007af94c;
extern unsigned int g_data_00ab4e34;
extern u16 g_texStripeBuf[];
extern unsigned int g_data_00f6ce50;
extern unsigned int g_data_00f85b34;
extern unsigned int g_table_00f85b60;
extern unsigned int g_data_00f8fac4;
extern u8 g_audioChannelTable[];
extern unsigned int g_flags_00f8fade;
extern unsigned int g_flags_00f8fadf;
extern unsigned int g_data_00f9eb68;
extern u16 g_audioChannelQueue[];
extern unsigned int g_data_00f9ebc0;
extern unsigned int g_data_00f9ebc8;
extern void * g_dsoundPrimary;
extern unsigned int g_data_00f9eff4;
extern unsigned int g_data_00f9eff8;
extern unsigned int g_data_00f9effc;
extern unsigned int g_data_00f9f000;
extern unsigned int g_data_00f9f820;
extern u32 g_initRet;
extern unsigned int g_data_00f9fc10;
extern unsigned int g_data_00f9fc14;
extern unsigned int g_data_00f9fc1c;
extern unsigned int g_data_00f9fc20;
extern unsigned int g_data_00f9fc30;
extern unsigned int g_data_00f9fc64;
extern unsigned int g_data_00f9fc74;
extern unsigned int g_data_00f9fd9c;
extern unsigned int g_arr_00fa0de0;
extern unsigned int g_iid_004d28f0;
extern void Calloc_004c6110(void);
extern void CfltcvtFormat_004c8650(void);
extern void CmpCallPushIATCall_004c6e60(void);
extern void CrtCodepageDispatcher_004cd6f0(void);
extern void CrtFreeLocaleInfo_004d0400(void);
extern void CrtInitLocaleInfo_004cf880(void);
extern void CrtLocaleInfoFreeAll_004cfc00(void);
extern void DSCreateThunk_004d12d2(void);
extern void DSEnumeratorThunk_004d12cc(void);
extern void DSoundSetAxisPan123_004aec10(void);
extern void DialogProbeDispatch640_004b0670(void);
extern void FormatHelper_004c8750(void);
extern void FpFormatRound_004ccda0(void);
extern void Helper_DrawCursor(void);
extern void Helper_TexUpload(void);
extern void IOWrapper_004c8fc0(void);
extern void LeaScaledCall_004bd510(void);
extern void LocaleInfoFill_004d0270(void);
extern void PackDoubleFromInts_004cde40(void);
extern void PaletteFillLineHybrid_004b5ce0(void);
extern void PrintfStubSigned_004c85d0(void);
extern void RendererTeardownSW_004b2a40(void);
extern void Shl96By1_004ce290(void);
extern void StreamAllocInit_004cc250(void);
extern void TimeValAdd3_004ce220(void);

__declspec(naked) void AppInit_Misc8(void) {
    __asm {
        sub     esp, 0x3c
        push    esi
        xor     ecx, ecx
        mov     eax, 0x5c
        push    edi
        mov     dword ptr [esp + 0x08], ecx
        mov     dword ptr [esp + 0x0c], eax
        mov     dword ptr [esp + 0x10], eax
        mov     dword ptr [esp + 0x14], eax
        mov     dword ptr [esp + 0x18], eax
        mov     dword ptr [esp + 0x1c], eax
        mov     dword ptr [esp + 0x20], eax
        mov     dword ptr [esp + 0x24], eax
        mov     dword ptr [esp + 0x28], 0x7a
        mov     dword ptr [esp + 0x2c], 0x10
        mov     dword ptr [esp + 0x30], 0x38
        mov     dword ptr [esp + 0x34], eax
        mov     dword ptr [esp + 0x38], eax
        mov     dword ptr [esp + 0x3c], eax
        mov     dword ptr [esp + 0x40], 0x5a
        mov     dword ptr [g_demoModeFlag], ecx
        call    Helper_AuxAudio_PostInit
        test    eax, eax
        jz      short L_c51_done
        call    DSoundQueryProperty_004ac3a0
        cmp     eax, 0x0f
        jne     short L_c51_done
        mov     esi, 1
        lea     edi, [esp + 0x0c]
    L_c51_loop:
        push    esi
        call    AuxAudioDevCapsQuery_004ac3f0
        mov     edx, dword ptr [edi - 4]
        add     esp, 4
        sub     eax, edx
        cdq
        xor     eax, edx
        sub     eax, edx
        cmp     eax, 5
        jg      short L_c51_done
        inc     esi
        add     edi, 4
        cmp     esi, 0x0f
        jle     short L_c51_loop
        mov     dword ptr [g_demoModeFlag], 1
    L_c51_done:
        pop     edi
        pop     esi
        add     esp, 0x3c
        ret
    }
}

extern void *g_iat_004d21b8;
extern void *g_iat_004d202c;


extern s32 Mem_Malloc(void **out_ptr, s32 size, s32 tag);
/* extern void DialogProbeDispatch_004afe40(void); */
extern void *g_iat_004d21c4;
extern int FSYS_fopen(const char *path, const char *mode);
extern int FSYS_fclose(int fh);
extern int FSYS_fread(void *buf, u32 size, u32 count, int fh);
extern int FSYS_fseek(int fh, u32 off, int whence);
extern unsigned int g_iat_004d2130;
extern unsigned int g_iat_004d2134;

/* @addr 0x004cdae0 (312b crt) - WideCharToMultiByte dispatcher (mbslen/wcsstr style).
 *   Caches state in g_data_00f9fc30 (1/2). Probes via IAT[0x4d20b8] with ".A"/".A0"
 *   buffers (0x4d2f20/0x4d2f24). State 2 fast path: direct IAT[0x4d20bc] call.
 *   State 1 conversion path: allocate via Calloc_004c6110, WideCharToMultiByte via
 *   IAT[0x4d20e4], MultiByteToWideChar(?) via IAT[0x4d20b8], free temp via FreeImpl.
 */
__declspec(naked) void WcToMbDispatcher_004cdae0(void) {
    __asm {
        push    ecx
        mov     eax, dword ptr [g_data_00f9fc30]
        push    ebx
        push    ebp
        push    esi
        mov     esi, dword ptr [g_iat_004d20bc]
        push    edi
        xor     edi, edi
        cmp     eax, edi
        jne     short L_wm_haveState
        lea     eax, [esp + 0x12]
        push    eax
        push    1
        push    offset g_data_004d2f24
        push    1
        call    dword ptr [g_iat_004d20b8]
        test    eax, eax
        jz      L_wm_tryAlt
        mov     eax, 1
        mov     dword ptr [g_data_00f9fc30], eax
    L_wm_haveState:
        cmp     eax, 2
        jne     short L_wm_state1
        mov     eax, [esp + 0x2c]
        cmp     eax, edi
        jne     short L_wm_haveCP1
        mov     eax, dword ptr [g_data_00f9fc10]
    L_wm_haveCP1:
        mov     edx, [esp + 0x24]
        mov     ecx, [esp + 0x20]
        push    edx
        mov     edx, [esp + 0x20]
        push    ecx
        mov     ecx, [esp + 0x20]
        push    edx
        push    ecx
        push    eax
        call    esi
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        pop     ecx
        ret
    L_wm_state1:
        cmp     eax, 1
        jne     L_wm_popRet
        mov     ebx, [esp + 0x28]
        mov     [esp + 0x2c], edi
        cmp     ebx, edi
        jne     short L_wm_haveCP2
        mov     ebx, dword ptr [g_data_00f9fc20]
    L_wm_haveCP2:
        mov     eax, [esp + 0x30]
        mov     ebp, [esp + 0x20]
        mov     edx, [esp + 0x1c]
        push    edi
        neg     eax
        sbb     eax, eax
        push    edi
        and     eax, 8
        push    ebp
        inc     eax
        push    edx
        push    eax
        push    ebx
        call    dword ptr [g_iat_004d20e4]
        mov     esi, eax
        test    esi, esi
        jz      short L_wm_freeNul
        push    esi
        push    2
        call    Calloc_004c6110
        mov     edi, eax
        add     esp, 8
        test    edi, edi
        jz      short L_wm_freeNul
        mov     ecx, [esp + 0x1c]
        push    esi
        push    edi
        push    ebp
        push    ecx
        push    1
        push    ebx
        call    dword ptr [g_iat_004d20e4]
        test    eax, eax
        jz      short L_wm_freeNul
        mov     edx, [esp + 0x24]
        push    edx
        push    eax
        mov     eax, [esp + 0x20]
        push    edi
        push    eax
        call    dword ptr [g_iat_004d20b8]
        push    edi
        mov     esi, eax
        call    FreeImpl_004c55f0
        add     esp, 4
        mov     eax, esi
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        pop     ecx
        ret
    L_wm_freeNul:
        mov     esi, [esp + 0x2c]
        push    edi
        call    FreeImpl_004c55f0
        add     esp, 4
        mov     eax, esi
    L_wm_popRet:
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        pop     ecx
        ret
    L_wm_tryAlt:
        lea     ecx, [esp + 0x12]
        push    ecx
        push    1
        push    offset g_data_004d2f20
        push    1
        push    edi
        call    esi
        test    eax, eax
        jz      short L_wm_returnZero
        mov     eax, 2
        mov     dword ptr [g_data_00f9fc30], eax
        jmp     L_wm_haveState
    L_wm_returnZero:
        pop     edi
        pop     esi
        pop     ebp
        xor     eax, eax
        pop     ebx
        pop     ecx
        ret
    }
}
