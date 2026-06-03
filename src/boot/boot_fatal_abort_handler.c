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

/* @addr 0x004c6860 (178b boot) - CRT abort/exit dispatcher with re-entry guard.
 *   Args: ebp=arg0 (push-thru), [esp+0x14]=arg1 flag, [esp+0x18] bl=arg2 flag.
 *   Calls PushConstCall_Lock_0xd to do beep/header msg, then on g_dispatchSave1429==1:
 *     ![0x4d2060](arg0); ![0x4d20a4](rv).
 *   Sets g_dispatchSave1428=1, g_byte_00f9f838 = bl.
 *   If arg1 == 0: walk fnptr-stack [g_dispatchSave1471..g_dispatchSave1472] calling each non-null fn,
 *     reloading head each iter; then push pair (0x4d5028, 0x4d5030) and IterFnPtrs.
 *   Push pair (0x4d5034, 0x4d5038), IterFnPtrs; if bl != 0 also call PushConstCall_TableLookupIatCall_0xd.
 *   Tail: pop esi/ebp/ebx; ret. Re-entry tail: push ebp; g_dispatchSave1429 = 1; ![0x4d2154]; pop+ret.
 */
extern unsigned int g_byte_00f9f838;
extern unsigned int g_dispatchSave1428;
extern unsigned int g_dispatchSave1429;
extern unsigned int g_dispatchSave1471;
extern unsigned int g_dispatchSave1472;
extern unsigned int g_iat_GetCurrentProcess;
extern unsigned int g_iat_TerminateProcess;
extern unsigned int g_iat_ExitProcess;
extern void IterFnPtrs(void);
extern void PushConstCall_Lock_0xd(void);
extern void PushConstCall_TableLookupIatCall_0xd(void);

__declspec(naked) void BootFatalAbortHandler(void) {
    __asm {
        push    ebx
        push    ebp
        push    esi
        call    PushConstCall_Lock_0xd
        mov     eax, dword ptr [g_dispatchSave1429]
        mov     ebp, dword ptr [esp + 0x10]
        cmp     eax, 1
        jne     short L_ab_set
        push    ebp
        call    dword ptr [g_iat_GetCurrentProcess]
        push    eax
        call    dword ptr [g_iat_TerminateProcess]
    L_ab_set:
        mov     eax, dword ptr [esp + 0x14]
        mov     ebx, dword ptr [esp + 0x18]
        test    eax, eax
        mov     dword ptr [g_dispatchSave1428], 1
        mov     byte ptr [g_byte_00f9f838], bl
        jne     short L_ab_skipwalk
        mov     ecx, dword ptr [g_dispatchSave1472]
        test    ecx, ecx
        jz      short L_ab_msg1
        mov     esi, dword ptr [g_dispatchSave1471]
        sub     esi, 4
        cmp     esi, ecx
        jb      short L_ab_msg1
    L_ab_walk:
        mov     eax, dword ptr [esi]
        test    eax, eax
        jz      short L_ab_nextiter
        call    eax
        mov     ecx, dword ptr [g_dispatchSave1472]
    L_ab_nextiter:
        sub     esi, 4
        cmp     esi, ecx
        jae     short L_ab_walk
    L_ab_msg1:
        push    0x004d5030
        push    0x004d5028
        call    IterFnPtrs
        add     esp, 8
    L_ab_skipwalk:
        push    0x004d5038
        push    0x004d5034
        call    IterFnPtrs
        add     esp, 8
        test    ebx, ebx
        jz      short L_ab_reentry
        call    PushConstCall_TableLookupIatCall_0xd
        pop     esi
        pop     ebp
        pop     ebx
        ret
    L_ab_reentry:
        push    ebp
        mov     dword ptr [g_dispatchSave1429], 1
        call    dword ptr [g_iat_ExitProcess]
        pop     esi
        pop     ebp
        pop     ebx
        ret
    }
}
