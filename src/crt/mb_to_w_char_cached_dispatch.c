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
extern void CopyJmp_0048ef90(void);
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

/* @addr 0x004cd950 (388b crt) - MultiByteToWideChar wrapper w/ probing.
 *   On first call, probes IAT [0x4d20b8] (MultiByteToWideChar-like) with
 *   "test 1" sample 0x4d2f24; if it works → g_dispatchSave1450_00f9fc2c = 1 (NT path).
 *   Else probes IAT [0x4d20bc] (CompareStringA-like) with 0x4d2f20;
 *   if that works → 2 (9x path). Else returns 0.
 *
 *   On subsequent calls (state cached at 0x00f9fc2c):
 *     state 1: direct call IAT [0x4d20b8] with (cp, flags, src, srclen).
 *     state 2: lookup string length via IAT [0x4d20e0] (LCMapStringA-like)
 *              with code-page 0x220; on failure return 0. Else
 *              calloc(len*2+2) via LoadArgPushCall, populate via
 *              [0x4d20e0] again with proper Unicode flags, verify the
 *              sentinel 0xffff at end+0, end-1 if intact, call CrtMemMove
 *              (likely WideCharToMultiByte). Free both bufs via FreeImpl.
 */
extern unsigned int g_iat_GetStringTypeW;
extern unsigned int g_iat_GetStringTypeA;
extern unsigned int g_iat_WideCharToMultiByte;
extern unsigned int g_crtMemMoveLo;
extern unsigned int g_crtMemMoveHi;
extern unsigned int g_dispatchSave1444_00f9fc10;
extern unsigned int g_dispatchSave1448_00f9fc20;
extern unsigned int g_dispatchSave1450_00f9fc2c;
extern void Calloc(void);
extern void CrtMemMove(void);
extern void FreeImpl(void);
extern void LoadArgPushCall(void);

__declspec(naked) void MBToWCharCachedDispatch(void) {
    __asm {
        push    ecx
        mov     eax, dword ptr [g_dispatchSave1450_00f9fc2c]
        push    ebx
        xor     ebx, ebx
        push    ebp
        push    esi
        mov     esi, dword ptr [g_iat_GetStringTypeW]
        cmp     eax, ebx
        push    edi
        jne     short L_mbw_haveState
        lea     eax, [esp + 0x10]
        push    eax
        push    1
        push    offset g_crtMemMoveHi
        push    1
        call    esi
        test    eax, eax
        je      short L_mbw_tryAlt
        mov     eax, 1
        jmp     short L_mbw_setCache
    L_mbw_tryAlt:
        lea     ecx, [esp + 0x10]
        push    ecx
        push    1
        push    offset g_crtMemMoveLo
        push    1
        push    ebx
        call    dword ptr [g_iat_GetStringTypeA]
        test    eax, eax
        je      L_mbw_zeroRet
        mov     eax, 2
    L_mbw_setCache:
        mov     dword ptr [g_dispatchSave1450_00f9fc2c], eax
    L_mbw_haveState:
        cmp     eax, 1
        jne     short L_mbw_state2
        mov     edx, dword ptr [esp + 0x24]
        mov     eax, dword ptr [esp + 0x20]
        mov     ecx, dword ptr [esp + 0x1c]
        push    edx
        mov     edx, dword ptr [esp + 0x1c]
        push    eax
        push    ecx
        push    edx
        call    esi
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        pop     ecx
        ret
    L_mbw_state2:
        cmp     eax, 2
        jne     L_mbw_simpleRet
        mov     eax, dword ptr [esp + 0x28]
        mov     dword ptr [esp + 0x10], ebx
        cmp     eax, ebx
        jne     short L_mbw_haveArg28
        mov     eax, dword ptr [g_dispatchSave1448_00f9fc20]
        mov     dword ptr [esp + 0x28], eax
    L_mbw_haveArg28:
        mov     edi, dword ptr [esp + 0x20]
        mov     ecx, dword ptr [esp + 0x1c]
        mov     edx, dword ptr [esp + 0x28]
        push    ebx
        push    ebx
        push    ebx
        push    ebx
        push    edi
        push    ecx
        push    0x220
        push    edx
        call    dword ptr [g_iat_WideCharToMultiByte]
        mov     esi, eax
        cmp     esi, ebx
        jne     short L_mbw_havelen
        xor     eax, eax
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        pop     ecx
        ret
    L_mbw_havelen:
        push    esi
        push    1
        call    Calloc
        mov     ebp, eax
        add     esp, 8
        test    ebp, ebp
        jne     short L_mbw_haveBuf1
    L_mbw_zeroRet:
        xor     eax, eax
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        pop     ecx
        ret
    L_mbw_haveBuf1:
        mov     eax, dword ptr [esp + 0x1c]
        mov     ecx, dword ptr [esp + 0x28]
        push    0
        push    0
        push    esi
        push    ebp
        push    edi
        push    eax
        push    0x220
        push    ecx
        call    dword ptr [g_iat_WideCharToMultiByte]
        test    eax, eax
        je      short L_mbw_freeAndExit
        lea     edx, [esi + esi + 2]
        push    edx
        call    LoadArgPushCall
        mov     ebx, eax
        add     esp, 4
        test    ebx, ebx
        je      short L_mbw_freeAndExit
        mov     eax, dword ptr [esp + 0x2c]
        test    eax, eax
        jne     short L_mbw_haveCp
        mov     eax, dword ptr [g_dispatchSave1444_00f9fc10]
    L_mbw_haveCp:
        mov     ecx, dword ptr [esp + 0x18]
        push    ebx
        add     edi, edi
        push    esi
        push    ebp
        push    ecx
        mov     word ptr [ebx + edi], 0xffff
        push    eax
        mov     word ptr [ebx + edi - 2], 0xffff
        call    dword ptr [g_iat_GetStringTypeA]
        /* MASM picks cmp r/m16, imm8 (66 83) for 0xffff sign-extension; orig
         * uses the full 7-byte imm16 form (66 81). Emit raw bytes to match. */
        _emit 0x66
        _emit 0x81
        _emit 0x7c
        _emit 0x3b
        _emit 0xfe
        _emit 0xff
        _emit 0xff
        mov     dword ptr [esp + 0x10], eax
        je      short L_mbw_zeroFinal
        _emit 0x66
        _emit 0x81
        _emit 0x3c
        _emit 0x3b
        _emit 0xff
        _emit 0xff
        jne     short L_mbw_zeroFinal
        mov     edx, dword ptr [esp + 0x24]
        push    edi
        push    ebx
        push    edx
        call    CrtMemMove
        add     esp, 0xc
        jmp     short L_mbw_freeAndExit
    L_mbw_zeroFinal:
        mov     dword ptr [esp + 0x10], 0
    L_mbw_freeAndExit:
        push    ebp
        call    FreeImpl
        add     esp, 4
        push    ebx
        call    FreeImpl
        mov     eax, dword ptr [esp + 0x14]
        add     esp, 4
    L_mbw_simpleRet:
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        pop     ecx
        ret
    }
}
