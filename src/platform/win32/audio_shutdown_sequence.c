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

/* @addr 0x004c4240 (168b platform.win32) - audio shutdown sequence:
 *   For i in [0, g_byte_00f9efec): if BuildMaskFromArray() nonzero:
 *     base = (*iat)(); Audio_UpdateChannels(); VtableArgClamp(i);
 *     used = (*iat)(); delta = 10 - used; total = base + delta;
 *     if total > 0: SleepEx(total).
 *   Then: g_dispatchSave1417 = 1; Loop1cBitMask; IterateCallSkip;
 *   Helper_DSI_post1(0); g_dispatchSave1417 = 0;
 *   if g_dsoundPrimary: vtbl[+8](.); clear. Same for g_dsoundContext.
 */
extern unsigned int g_byte_00f9efec;
extern unsigned int g_iat_Sleep;
extern unsigned int g_iat_timeGetTime;
extern void * g_dsoundContext;
extern void * g_dsoundPrimary;
extern unsigned int g_dispatchSave1417;
extern void Audio_UpdateChannels(void);
extern void BuildMaskFromArray(void);
extern void Helper_DSI_post1(void);
extern void Helper_TitleSetMaxVolume(void);
extern void IterateCallSkip(void);
extern void Loop1cBitMask(void);

__declspec(naked) void AudioShutdownSequence(void) {
    __asm {
        push    ebx
        push    esi
        push    edi
        movsx   edi, byte ptr [g_byte_00f9efec]
        test    edi, edi
        _emit   7eh
        _emit   3ch
        mov     ebx, dword ptr [g_iat_timeGetTime]
loopShutdown:
        call    BuildMaskFromArray
        test    eax, eax
        _emit   74h
        _emit   2dh
        call    ebx
        mov     esi, eax
        call    Audio_UpdateChannels
        push    edi
        call    Helper_TitleSetMaxVolume
        add     esp, 4
        call    ebx
        mov     ecx, 0xa
        sub     ecx, eax
        add     esi, ecx
        test    esi, esi
        _emit   7eh
        _emit   07h
        push    esi
        call    dword ptr [g_iat_Sleep]
        dec     edi
        test    edi, edi
        _emit   7fh
        _emit   0cah
        mov     dword ptr [g_dispatchSave1417], 1
        call    Loop1cBitMask
        call    IterateCallSkip
        push    0
        mov     dword ptr [g_dispatchSave1417], 0
        call    Helper_DSI_post1
        mov     eax, dword ptr [g_dsoundPrimary]
        add     esp, 4
        test    eax, eax
        _emit   74h
        _emit   10h
        mov     edx, dword ptr [eax]
        push    eax
        call    dword ptr [edx + 8]
        mov     dword ptr [g_dsoundPrimary], 0
        mov     eax, dword ptr [g_dsoundContext]
        test    eax, eax
        _emit   74h
        _emit   10h
        mov     ecx, dword ptr [eax]
        push    eax
        call    dword ptr [ecx + 8]
        mov     dword ptr [g_dsoundContext], 0
        pop     edi
        pop     esi
        pop     ebx
        ret
    }
}
