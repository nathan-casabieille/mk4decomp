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

/* @addr 0x00413b70 (359b boot) - MStack push-8 + slot init with callback addr.
 *   Pushes 0x1000 to ThreeChanPackClamp, then [g_fightGroupHead] to
 *   CopyThreeFields. Sets g_walkCallback=0x3333 and calls
 *   AudioMixerStep, on no-error adds 0xd999 to it and calls
 *   ZeroAndDirty4. On no-error AND bit 2 of g_xformDirtyFlags set:
 *   calls MStackPush8; if it returns OK loads
 *   g_eventQueueEnd = old g_fightGroupHead, g_walkCallback = &g_dispatchSave514>>2,
 *   calls PushSetXfmMaskCallPop. On no-error AND bit 2 NOT set,
 *   writes 0x9e into [g_fightGroupHead*4+0x30], calls
 *   ScaledTripleCopy54 then MStackPushNegMul10.
 *   Then for the resolved leaf slot writes 0xb333 at +0x48, OR's bit 3
 *   into +0x0, 0xff at +0x14, and 0x00413e60 (callback addr) at +0x10.
 *   Calls MStackCall_004065b0, tail-jmp MStackPop8.
 */
extern unsigned int g_dispatchSave514;
extern void AudioMixerStep(void);
extern void CopyThreeFields(void);
extern void MStackCall_004065b0(void);
extern void MStackPop8(void);
extern void MStackPush8(void);
extern void MStackPushNegMul10(void);
extern void PushSetXfmMaskCallPop(void);
extern void ScaledTripleCopy54(void);
extern void ThreeChanPackClamp(void);
extern void ZeroAndDirty4(void);
extern void func_00413e60(void);

__declspec(naked) void MStackPush8CallbackInit(void) {
    __asm {
        push    0x1000
        call    ThreeChanPackClamp
        mov     eax, dword ptr [g_fightGroupHead]
        add     esp, 4
        push    eax
        call    CopyThreeFields
        add     esp, 4
        mov     dword ptr [g_walkCallback], 0x3333
        call    AudioMixerStep
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_mp8c_ret
        add     dword ptr [g_walkCallback], 0xd999
        call    ZeroAndDirty4
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_mp8c_ret
        test    byte ptr [g_xformDirtyFlags], 4
        je      L_mp8c_ret
        call    MStackPush8
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_mp8c_ret
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     edx, offset g_dispatchSave514
        shr     edx, 2
        mov     dword ptr [g_eventQueueEnd], ecx
        mov     dword ptr [g_walkCallback], edx
        call    PushSetXfmMaskCallPop
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_mp8c_ret
        test    byte ptr [g_xformDirtyFlags], 4
        jne     L_mp8c_tailJmp
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     eax, 0x9e
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x30], eax
        call    ScaledTripleCopy54
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_mp8c_ret
        mov     dword ptr [g_walkCallback], 0xfffffeb9
        call    MStackPushNegMul10
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_mp8c_ret
        mov     edx, dword ptr [g_fightGroupHead]
        mov     ecx, dword ptr [g_walkCallback]
        mov     dword ptr [edx*4 + 0x6c], ecx
        lea     eax, [edx*4]
        mov     edx, dword ptr [g_eventQueueCurrent]
        mov     dword ptr [eax + 0x74], edx
        mov     eax, dword ptr [eax + 0x18]
        mov     dword ptr [g_currentNodeIdx], eax
        mov     eax, dword ptr [eax*4 + 0x28]
        mov     dword ptr [g_xformEntityIdx], eax
        shl     eax, 2
        mov     ecx, dword ptr [eax]
        mov     dword ptr [eax + 0x48], 0xb333
        or      ecx, 8
        mov     dword ptr [eax + 0x14], 0xff
        mov     dword ptr [eax], ecx
        mov     ecx, offset func_00413e60
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [eax + 0x10], ecx
        mov     eax, dword ptr [g_fightGroupHead]
        mov     dword ptr [g_currentNodeIdx], eax
        call    MStackCall_004065b0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_mp8c_ret
    L_mp8c_tailJmp:
        jmp     MStackPop8
    L_mp8c_ret:
        ret
    }
}
