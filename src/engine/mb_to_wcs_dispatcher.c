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
extern void GuardedDispatch_InstallSelfDualEsi(void);
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

/* @addr 0x004d0f50 (304b other) - CRT mbstowcs / mb-to-wide convert dispatcher.
 *   Caches result of GetCPInfo (or similar) in g_dispatchSave1462 (1/2 state).
 *   If state=1: simple passthrough call. If state=2: full conversion via
 *     IAT[0x4d2134] + IAT[0x4d20e4] (MultiByteToWideChar). Uses g_dispatchSave1448
 *     as default codepage when arg is 0.
 */
extern unsigned int g_dispatchSave1448;
extern unsigned int g_dispatchSave1462;
extern unsigned int g_iat_MultiByteToWideChar;
extern unsigned int g_iat_GetLocaleInfoW;
extern unsigned int g_iat_GetLocaleInfoA;
extern void FreeImpl(void);
extern void LoadArgPushCall(void);

__declspec(naked) void MbToWcsDispatcher(void) {
    __asm {
        mov     eax, dword ptr [g_dispatchSave1462]
        push    ebx
        push    ebp
        push    esi
        mov     esi, dword ptr [g_iat_GetLocaleInfoW]
        push    edi
        test    eax, eax
        jne     short L_mw_haveState
        push    0
        push    0
        push    1
        push    0
        call    esi
        test    eax, eax
        jz      short L_mw_tryAlt
        mov     eax, 1
        jmp     short L_mw_setState
    L_mw_tryAlt:
        push    0
        push    0
        push    1
        push    0
        call    dword ptr [g_iat_GetLocaleInfoA]
        test    eax, eax
        jz      L_mw_returnZero
        mov     eax, 2
    L_mw_setState:
        mov     dword ptr [g_dispatchSave1462], eax
    L_mw_haveState:
        cmp     eax, 1
        jne     short L_mw_state2
        mov     eax, [esp + 0x20]
        mov     ecx, [esp + 0x1c]
        mov     edx, [esp + 0x18]
        push    eax
        mov     eax, [esp + 0x18]
        push    ecx
        push    edx
        push    eax
        call    esi
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        ret
    L_mw_state2:
        cmp     eax, 2
        jne     L_mw_fail
        mov     eax, [esp + 0x24]
        test    eax, eax
        jne     short L_mw_haveCP
        mov     ecx, dword ptr [g_dispatchSave1448]
        mov     [esp + 0x24], ecx
    L_mw_haveCP:
        mov     ebx, [esp + 0x18]
        mov     ebp, [esp + 0x14]
        push    0
        push    0
        push    ebx
        push    ebp
        call    dword ptr [g_iat_GetLocaleInfoA]
        mov     esi, eax
        test    esi, esi
        jne     short L_mw_alloc
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        ret
    L_mw_alloc:
        push    esi
        call    LoadArgPushCall
        mov     edi, eax
        add     esp, 4
        test    edi, edi
        jne     short L_mw_doConv
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        ret
    L_mw_doConv:
        push    esi
        push    edi
        push    ebx
        push    ebp
        call    dword ptr [g_iat_GetLocaleInfoA]
        test    eax, eax
        jz      short L_mw_cleanupZero
        mov     eax, [esp + 0x20]
        test    eax, eax
        jne     short L_mw_useEax
        mov     edx, [esp + 0x24]
        push    eax
        push    eax
        push    -1
        push    edi
        push    1
        push    edx
        call    dword ptr [g_iat_MultiByteToWideChar]
        mov     esi, eax
        test    esi, esi
        jz      short L_mw_cleanupZero
        push    edi
        call    FreeImpl
        add     esp, 4
        mov     eax, esi
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        ret
    L_mw_useEax:
        mov     ecx, [esp + 0x24]
        push    eax
        mov     eax, [esp + 0x20]
        push    eax
        push    -1
        push    edi
        push    1
        push    ecx
        call    dword ptr [g_iat_MultiByteToWideChar]
        mov     esi, eax
        test    esi, esi
        jne     short L_mw_freeAndReturn
    L_mw_cleanupZero:
        push    edi
        call    FreeImpl
        add     esp, 4
    L_mw_returnZero:
        xor     eax, eax
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        ret
    L_mw_freeAndReturn:
        push    edi
        call    FreeImpl
        add     esp, 4
        mov     eax, esi
    L_mw_fail:
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        ret
    }
}
