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

extern unsigned int g_byte_004f360c;
extern unsigned int g_dispatchSave74;
extern void AudioMixerStep(void);
extern void ChainGetterStateInstaller(void);
extern void ChainListVecAdd(void);
extern void GuardedSeq_MStackCall_then_CallSetPause_00471670(void);
extern void MStackPop8(void);
extern void MStackPush8(void);
extern void MStackPushCallPop(void);
extern void ZeroAndDirty4(void);
extern void ZeroThreeFields_0040a8b0(void);

__declspec(naked) void BootGatedInitInstallPair(void)
{
    __asm
    {
        mov     al, byte ptr [g_byte_004f360c]
        test    al, al
        je      L_bgip_ret1
        mov     dword ptr [g_walkCallback], 0x2666
        call    AudioMixerStep
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_bgip_ret1
        add     dword ptr [g_walkCallback], 0xd999
        call    ZeroAndDirty4
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_bgip_ret1
        test    byte ptr [g_xformDirtyFlags], 4
        je      short L_bgip_ret1
        call    MStackPush8
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_bgip_ret1
        mov     eax, dword ptr [g_currentNodeIdx]
        mov     ecx, offset g_dispatchSave74
        shr     ecx, 2
        push    0xc0
        push    0x49db40
        mov     dword ptr [g_eventQueueEnd], eax
        mov     dword ptr [g_eventQueueIdx], ecx
        mov     dword ptr [g_eventQueueNotMask], 0xc1
        call    StoreTwoCall
        mov     al, byte ptr [g_xformDirtyFlags]
        add     esp, 8
        test    al, 1
        jne     short L_bgip_tailPop
        call    MStackPushCallPop
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_bgip_ret1
        call    ZeroThreeFields_0040a8b0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_bgip_ret1
    L_bgip_tailPop:
        jmp     MStackPop8
    L_bgip_ret1:
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
    L_bgip_main:
        mov     eax, dword ptr [g_baseSel]
        push    esi
        lea     esi, [eax*4]
        mov     eax, dword ptr [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], 0
        test    eax, eax
        je      short L_bgip_phase0
        mov     eax, dword ptr [g_eventQueueNotMask]
        dec     eax
        test    eax, eax
        mov     dword ptr [g_eventQueueNotMask], eax
        jg      short L_bgip_skipToChain
        call    GuardedSeq_MStackCall_then_CallSetPause_00471670
        pop     esi
        ret
    L_bgip_phase0:
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     ecx, dword ptr [ecx*4 + 0x18]
        mov     dword ptr [g_currentNodeIdx], ecx
        mov     eax, dword ptr [ecx*4 + 0x20]
        or      al, 0x40
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x20], eax
        mov     edx, dword ptr [g_currentNodeIdx]
        mov     eax, dword ptr [edx*4 + 0x28]
        mov     dword ptr [g_xformEntityIdx], eax
        mov     ecx, dword ptr [eax*4]
        or      ecx, 8
        mov     dword ptr [eax*4], ecx
        mov     ecx, dword ptr [g_xformEntityIdx]
        mov     eax, 0x4000
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x48], eax
        mov     dword ptr [g_eventQueueNotMask], 0xb
    L_bgip_skipToChain:
        call    ChainGetterStateInstaller
        mov     eax, dword ptr [g_walkCallback]
        mov     edx, dword ptr [g_xformEntityIdx]
        sub     eax, 0x51e
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [edx*4 + 0x48], eax
        mov     ecx, dword ptr [g_xformEntityIdx]
        mov     eax, dword ptr [ecx*4]
        or      al, 8
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4], eax
        call    ChainListVecAdd
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_bgip_main_ret
        mov     eax, 1
        mov     dword ptr [esi + 8], offset L_bgip_main
        mov     dword ptr [esi + 0x84], eax
        mov     dword ptr [g_pendingNodeType], eax
        mov     dword ptr [g_framePauseFlag], eax
    L_bgip_main_ret:
        pop     esi
        ret
    }
}
