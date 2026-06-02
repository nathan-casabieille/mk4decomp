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
extern void SetJmp_0049cb90(void);
extern void Thunk_0049cbd0(void);
extern void ScaledZeroFour(void);
extern void WalkCbSubMul10_00431d50(void);
extern void Mul10Tail(unsigned int a, unsigned int b);
extern void BootMod6487eClampAndChainMul10(void);
extern void SpawnListBatchLoader_00477710(void);
extern void MStackPush2TableNot(void);
extern void GuardedChainCmpDualBitXor(void);
extern void ScaledLoadDecJmp_00429710(void);
extern void ScaledStoreCurDirtyClear_004296f0(void);
extern void MStackBitmaskIncMod_00492450(void);
extern void MStackBitmaskUpdate_00492510(void);
extern void Push1eCallTestDirtyLoop_004923b0(void);
extern void MStackLoopFieldInit_00492280(void);
extern void TaggedSceneDispatch(void);
extern void CallPauseDirty4StackPushFn_004839d0(void);
extern void CallPauseDirty1JmpDirty4StackPush_00483a80(void);
extern void Cmp2CallDirtyCall(void);
extern void QuadBlockArgInstallChain(void);
extern void InstallSelfChainSet84_80CallW_004363f0(void);
extern void Wrapper_00436490(void);
extern void MoveFsmCluster_004364a0(void);
extern void CallPauseTestByteJmpCalls(void);
extern void InstallSelfFullPath(void);
extern void InstallSelfCountdownChain_0047a950(void);
extern void CopyJmp_0048ef90(void);
extern void DualTestDirtyToggle_004282c0(void);
extern void TripleVecAccCallStore(void);
extern void Thunk_004bd5c0(void);
extern void AllocSlotPushTripleGlobals(void);
extern void MStackPop4Rewrite(void);
extern void Push70CallScaleArith(void);
extern void StreamChainStringInstall(void);
extern void MStackFrameCdeclDouble(void);
extern void ChainTableWalkStore_004917e0(void);
extern void Push16Call(void);
extern void DispatcherComplex260_00407030(void);
extern void ScaledLoadCmpStoreXfm_0048f2a0(void);
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
extern void Wrapper_0048a350(void);
extern void Wrapper_0048a3a0(void);
extern void Helper_DownloadSetup(void);
extern void MStackPush3CmpCall(void);
extern void Wrapper_0048ec20(void);
extern void FiveCallScaledChainTailJmp(void);
extern void SetJmp_00438f50(void);
extern void SetJmp_00438f60(void);
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

/* @addr 0x004c4240 (168b platform.win32) - audio shutdown sequence:
 *   For i in [0, g_byte_00f9efec): if BuildMaskFromArray() nonzero:
 *     base = (*iat)(); Audio_UpdateChannels(); VtableArgClamp(i);
 *     used = (*iat)(); delta = 10 - used; total = base + delta;
 *     if total > 0: SleepEx(total).
 *   Then: g_dispatchSave1417_00f9eff0 = 1; Loop1cBitMask; IterateCallSkip;
 *   Helper_DSI_post1(0); g_dispatchSave1417_00f9eff0 = 0;
 *   if g_dsoundPrimary: vtbl[+8](.); clear. Same for g_dsoundContext.
 */
extern unsigned int g_byte_00f9efec;
extern unsigned int g_iat_004d2074;
extern unsigned int g_iat_004d2240;
extern void * g_dsoundContext;
extern void * g_dsoundPrimary;
extern unsigned int g_dispatchSave1417_00f9eff0;
extern void Audio_UpdateChannels(void);
extern void BuildMaskFromArray_004c38d0(void);
extern void Helper_DSI_post1(void);
extern void Helper_TitleSetMaxVolume(void);
extern void IterateCallSkip_004c4210(void);
extern void Loop1cBitMask_004c4450(void);

__declspec(naked) void AudioShutdownSequence_004c4240(void) {
    __asm {
        push    ebx
        push    esi
        push    edi
        movsx   edi, byte ptr [g_byte_00f9efec]
        test    edi, edi
        _emit   7eh
        _emit   3ch
        mov     ebx, dword ptr [g_iat_004d2240]
loopShutdown:
        call    BuildMaskFromArray_004c38d0
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
        call    dword ptr [g_iat_004d2074]
        dec     edi
        test    edi, edi
        _emit   7fh
        _emit   0cah
        mov     dword ptr [g_dispatchSave1417_00f9eff0], 1
        call    Loop1cBitMask_004c4450
        call    IterateCallSkip_004c4210
        push    0
        mov     dword ptr [g_dispatchSave1417_00f9eff0], 0
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
