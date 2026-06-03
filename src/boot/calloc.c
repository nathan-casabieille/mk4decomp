/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_currentNodeIdx;
extern unsigned int g_baseSel;
extern unsigned int g_acc_00542078;
extern unsigned int g_cj_0054205c;
extern unsigned int g_gameCountdown;
extern unsigned int g_xformScratch94;
extern unsigned int g_fightStateProgress;
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
extern void CallPauseDirty1JmpDirty4StackPush_GuardedDoubleIncCmpJmp(void);
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
extern void DispatcherComplex260_MStackBracket1_TreeWalkRecursive2(void);
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
extern void PendingMatch_StoreTwoCall_0042b930(void);
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
extern void GuardedDispatch_InstallSelfDualEsi(void);
extern void MStackPushZeroCallPop_PendingMatch(void);
extern void DirtyToggleByGate(void);
extern void GameDispatchValidateState(void);
extern void CrouchAttackFsmCluster(void);
extern void MStackPushVec3Mul10(void);
extern void LiteralPushCallEntZero(void);
extern void LeaPlus22StoreSelf(void);
extern void IterLoad_g_scaledInit_00542048_then_DualScaledStoreZero(void);
extern void GuardedDualConst2AndToggle(void);
extern void CallPauseScaledStorePushCall(void);
extern void LoadGeoAsset_Default(void);
extern void DispatcherComplex260_FramePauseScaledStore(void);
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

/* @addr 0x004c51f0 (171b boot) - aux audio reference-window probe.
 *   Frame: sub esp, 0x3c; push esi, edi.
 *   Init 15-dword reference window on stack: buf[0]=0, buf[1..8]=0x5c,
 *   buf[9]=0x7a, buf[10]=0x10, buf[11]=0x38, buf[12..14]=0x5c, buf[15]=0x5a.
 *   Clear g_demoModeFlag; call Helper_AuxAudio_PostInit.
 *   If success, call DSoundQueryProperty; require rv==0xf.
 *   Loop esi=1..14: rv=AuxAudioDevCapsQuery(esi); abs(rv - buf[esi-1]) must be <= 5.
 *   If all pass, set g_demoModeFlag = 1.
 */
extern unsigned int g_iat_GetStringTypeW;
extern unsigned int g_iat_GetStringTypeA;
extern unsigned int g_iat_MultiByteToWideChar;
extern u32 g_demoModeFlag;
extern void AuxAudioDevCapsQuery(void);
extern void DSoundQueryProperty(void);
extern void FreeImpl(void);
extern void Helper_AuxAudio_PostInit(void);

extern unsigned int g_dispatchSave529;
extern unsigned int g_dispatchSave528;
extern unsigned int g_dispatchSave515;
extern unsigned int g_dispatchSave566;
extern unsigned int g_crtMemMoveLo;
extern unsigned int g_crtMemMoveHi;
extern unsigned int g_crtMemMoveVar;
extern unsigned int g_dispatchVar40;
extern unsigned int g_renderer2_initVar;
extern unsigned int g_renderer2_initVar2;
extern unsigned int g_dispatchSave500;
extern unsigned int g_renderer2_initVar3;
extern unsigned int g_dispatchSave526;
extern unsigned int g_dispatchSave525;
extern unsigned int g_dispatchSave524;
extern unsigned int g_texturedTriVar;
extern unsigned int g_crtFilbufBase;
extern unsigned int g_crtDispatchEnd;
extern unsigned int g_crtCType;
extern unsigned int g_crtLocaleNumeric;
extern unsigned int g_crtFpuTbyteVar;
extern unsigned int g_crtFpuTbyteVar2;
extern unsigned int g_crtFpuStateBuf;
extern unsigned int g_crtFpuStack;
extern unsigned int g_dispatchPair;
extern unsigned int g_crtTimeFmtPrefs;
extern u8 g_renderer2_buf3[];
extern unsigned int g_installCountdownBase;
extern unsigned int g_dispatchInit1007;
extern unsigned int g_dispatchSave15;
extern unsigned int g_dispatchSave14;
extern unsigned int g_glideTileSize;
extern unsigned int g_glideMipInit;
extern u8 g_renderer2_buf2[];
extern unsigned int g_renderer2_baseB;
extern unsigned int g_renderer2_var3;
extern u8 g_renderer2_buf1[];
extern unsigned int g_comptr_0058c7ac;
extern unsigned int g_renderer2_obj;
extern unsigned int g_990_iface;
extern int g_renderer2_present_rc;
extern unsigned int g_dispatchTab60;
extern unsigned int g_dd3SurfaceCreate;
extern unsigned int g_dd3SurfaceSlot;
extern unsigned int g_dsmi_b70_main;
extern unsigned int g_dsmi_b70_ret;
extern unsigned int g_960_iface;
extern unsigned int g_renderer4_ifaceBase;
extern unsigned int g_renderer4_dispatchSlot;
extern unsigned int g_dsmi_3a0_main;
extern unsigned int g_dsmi_3a0_ret;
extern unsigned int g_190_iface;
extern unsigned int g_dispatchSave1609;
extern unsigned int g_dispatchSave1610;
extern unsigned int g_dispatchSave1611;
extern unsigned int g_dispatchSave1612;
extern unsigned int g_dispatchSave1613;
extern unsigned int g_dispatchSave1614;
extern unsigned int g_dispatchSave1615;
extern unsigned int g_dispatchSave1616;
extern unsigned int g_dispatchSave1617;
extern unsigned int g_dispatchSave1618;
extern unsigned int g_dispatchSave1619;
extern unsigned int g_byte_007af508;
extern unsigned int g_dispatchSave1620;
extern unsigned int g_dispatchSave1621;
extern unsigned int g_dispatchSave1622;
extern int g_renderer4_active;
extern unsigned int g_dispatchSave1623;
extern int g_renderer4_surface;
extern unsigned int g_dispatchSave1624;
extern unsigned int g_dispatchSave1572;
extern u16 g_texStripeBuf[];
extern unsigned int g_dispatchSave1348;
extern unsigned int g_dispatchSave1400;
extern unsigned int g_audioFrameTbl;
extern unsigned int g_dispatchSave1406;
extern u8 g_audioChannelTable[];
extern unsigned int g_flags_00f8fade;
extern unsigned int g_flags_00f8fadf;
extern unsigned int g_dispatchSave1409;
extern u16 g_audioChannelQueue[];
extern unsigned int g_dispatchSave1413;
extern unsigned int g_dispatchSave1414;
extern void * g_dsoundPrimary;
extern unsigned int g_dispatchSave1418;
extern unsigned int g_dispatchSave1419;
extern unsigned int g_dispatchSave1420;
extern unsigned int g_dispatchSave1421;
extern unsigned int g_dispatchSave1426;
extern u32 g_initRet;
extern unsigned int g_dispatchSave1444;
extern unsigned int g_dispatchSave1445;
extern unsigned int g_dispatchSave1447;
extern unsigned int g_dispatchSave1448;
extern unsigned int g_dispatchSave1451;
extern unsigned int g_dispatchSave1455;
extern unsigned int g_dispatchSave1459;
extern unsigned int g_dispatchSave1462;
extern unsigned int g_crtHandleTable;
extern unsigned int g_iid;
extern void Calloc(void);
extern void CfltcvtFormat(void);
extern void CmpCallPushIATCall(void);
extern void CrtCodepageDispatcher(void);
extern void CrtFreeLocaleInfo(void);
extern void CrtInitLocaleInfo(void);
extern void CrtLocaleInfoFreeAll(void);
extern void DSCreateThunk_004d12d2(void);
extern void DSEnumeratorThunk_004d12cc(void);
extern void DSoundSetAxisPan123_004aec10(void);
extern void DialogProbeDispatch640(void);
extern void FormatHelper(void);
extern void FpFormatRound(void);
extern void Helper_DrawCursor(void);
extern void Helper_TexUpload(void);
extern void IOWrapper_CritSecLazyEnter_004c8fc0(void);
extern void LeaScaledCall(void);
extern void LocaleInfoFill(void);
extern void PackDoubleFromInts(void);
extern void PaletteFillLineHybrid(void);
extern void PrintfStubSigned(void);
extern void RendererTeardownSW(void);
extern void Shl96By1(void);
extern void StreamAllocInit(void);
extern void TimeValAdd3(void);

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
        call    DSoundQueryProperty
        cmp     eax, 0x0f
        jne     short L_c51_done
        mov     esi, 1
        lea     edi, [esp + 0x0c]
    L_c51_loop:
        push    esi
        call    AuxAudioDevCapsQuery
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

extern void *g_iat_GetDC;
extern void *g_iat_CreateDIBSection;


extern s32 Mem_Malloc(void **out_ptr, s32 size, s32 tag);
/* extern void DialogProbeDispatch(void); */
extern void *g_iat_MapVirtualKeyA;
extern int FSYS_fopen(const char *path, const char *mode);
extern int FSYS_fclose(int fh);
extern int FSYS_fread(void *buf, u32 size, u32 count, int fh);
extern int FSYS_fseek(int fh, u32 off, int whence);
extern void *g_iat_GetLocaleInfoW;
extern void *g_iat_GetLocaleInfoA;
/* g_iat_MultiByteToWideChar/bc/b8 declared as unsigned int above */

/* @addr 0x004cdae0 (312b crt) - WideCharToMultiByte dispatcher (mbslen/wcsstr style).
 *   Caches state in g_dispatchSave1451 (1/2). Probes via IAT[0x4d20b8] with ".A"/".A0"
 *   buffers (0x4d2f20/0x4d2f24). State 2 fast path: direct IAT[0x4d20bc] call.
 *   State 1 conversion path: allocate via Calloc, WideCharToMultiByte via
 *   IAT[0x4d20e4], MultiByteToWideChar(?) via IAT[0x4d20b8], free temp via FreeImpl.
 */
__declspec(naked) void WcToMbDispatcher(void) {
    __asm {
        push    ecx
        mov     eax, dword ptr [g_dispatchSave1451]
        push    ebx
        push    ebp
        push    esi
        mov     esi, dword ptr [g_iat_GetStringTypeA]
        push    edi
        xor     edi, edi
        cmp     eax, edi
        jne     short L_wm_haveState
        lea     eax, [esp + 0x12]
        push    eax
        push    1
        push    offset g_crtMemMoveHi
        push    1
        call    dword ptr [g_iat_GetStringTypeW]
        test    eax, eax
        jz      L_wm_tryAlt
        mov     eax, 1
        mov     dword ptr [g_dispatchSave1451], eax
    L_wm_haveState:
        cmp     eax, 2
        jne     short L_wm_state1
        mov     eax, [esp + 0x2c]
        cmp     eax, edi
        jne     short L_wm_haveCP1
        mov     eax, dword ptr [g_dispatchSave1444]
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
        mov     ebx, dword ptr [g_dispatchSave1448]
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
        call    dword ptr [g_iat_MultiByteToWideChar]
        mov     esi, eax
        test    esi, esi
        jz      short L_wm_freeNul
        push    esi
        push    2
        call    Calloc
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
        call    dword ptr [g_iat_MultiByteToWideChar]
        test    eax, eax
        jz      short L_wm_freeNul
        mov     edx, [esp + 0x24]
        push    edx
        push    eax
        mov     eax, [esp + 0x20]
        push    edi
        push    eax
        call    dword ptr [g_iat_GetStringTypeW]
        push    edi
        mov     esi, eax
        call    FreeImpl
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
        call    FreeImpl
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
        push    offset g_crtMemMoveLo
        push    1
        push    edi
        call    esi
        test    eax, eax
        jz      short L_wm_returnZero
        mov     eax, 2
        mov     dword ptr [g_dispatchSave1451], eax
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
