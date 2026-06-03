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

extern unsigned int g_voicePoolTickFlag_005437f4;
extern unsigned int g_byte_00543724;
extern unsigned int g_byte_0054372c;
extern unsigned int g_byte_00543730;
extern void PendingMatch_004a2a80(void);
extern void DebugMenu_DrawUnlockToggles(void);
extern void ScaledByteIdxDualCopy(void);
extern void AudioState50b4BitDispatcher(void);
extern void TripleCallByteCheck(void);
extern int RetZero_004a1c40(void);
extern void Push16Call(void);
extern void InstallSelfPackedF80(void);
extern void FiveTableWalkInit(void);
extern void TripleCallSetCopy(void);
extern void AudioInitArgs3(void);
extern void AudioBindEntry(void);

__declspec(naked) void AudioStateInitMultiInstall(void)
{
    __asm
    {
        mov     eax, dword ptr [g_baseSel]
        push    ebx
        push    esi
        push    edi
        lea     edi, [eax*4]
        mov     eax, dword ptr [eax*4 + 0x84]
        mov     dword ptr [edi + 0x84], 0
        sub     eax, 0
        je      L_asimi_phase0
        dec     eax
        je      short L_asimi_phase1
        mov     dword ptr [g_voicePoolTickFlag_005437f4], 1
        call    PendingMatch_004a2a80
        pop     edi
        pop     esi
        pop     ebx
        ret
    L_asimi_phase1:
        call    DebugMenu_DrawUnlockToggles
        push    0x4f3830
        call    ScaledByteIdxDualCopy
        add     esp, 4
        push    0x4f3830
        call    AudioState50b4BitDispatcher
        add     esp, 4
        call    TripleCallByteCheck
        test    eax, eax
        mov     ebx, 1
        je      short L_asimi_skipDispatch
        mov     ecx, dword ptr [g_baseSel]
        mov     eax, dword ptr [ecx*4 + 0x30]
        lea     edx, [eax + eax*8]
        mov     eax, dword ptr [edx*4 + 0x4f383c]
        test    eax, eax
        mov     dword ptr [g_currentNodeIdx], eax
        je      short L_asimi_checkFlag
        call    eax
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_asimi_ret
    L_asimi_checkFlag:
        test    byte ptr [g_xformDirtyFlags], bl
        jne     short L_asimi_skipRetZero
    L_asimi_skipDispatch:
        call    RetZero_004a1c40
        test    eax, eax
        je      L_asimi_install2
    L_asimi_skipRetZero:
        mov     dword ptr [g_eventQueueWorkType], 0x32f
        call    Push16Call
        call    DebugMenu_DrawUnlockToggles
        mov     dword ptr [g_eventQueueCurrent], 0x20
        mov     dword ptr [edi + 8], offset AudioStateInitMultiInstall
        mov     eax, dword ptr [g_baseSel]
        mov     ecx, offset AudioStateInitMultiInstall
        add     ecx, 0x2000000
        mov     dword ptr [eax*4 + 0x84], 2
        mov     eax, dword ptr [edi + 4]
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [eax*4], ecx
        mov     eax, dword ptr [g_currentNodeIdx]
        inc     eax
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [edi + 4], eax
        mov     edx, dword ptr [g_baseSel]
        mov     dword ptr [edx*4 + 0x84], 0
        call    InstallSelfPackedF80
        mov     dword ptr [g_framePauseFlag], ebx
        pop     edi
        pop     esi
        pop     ebx
        ret
    L_asimi_phase0:
        mov     ebx, 1
        mov     byte ptr [g_byte_00543724], bl
        mov     byte ptr [g_byte_0054372c], bl
        mov     byte ptr [g_byte_00543730], bl
        call    FiveTableWalkInit
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_asimi_ret
        call    TripleCallSetCopy
        mov     esi, 0x4f384c
    L_asimi_loop:
        mov     ecx, dword ptr [esi]
        mov     eax, dword ptr [esi + 4]
        sub     ecx, 0x50000
        push    eax
        push    ecx
        push    0
        push    0x5159b8
        call    AudioInitArgs3
        movsx   edx, byte ptr [esi - 0xc]
        mov     eax, dword ptr [g_baseSel]
        add     esi, 0x24
        add     edx, eax
        add     esp, 0x10
        cmp     esi, 0x4f3924
        mov     dword ptr [edx*4], 0
        jb      short L_asimi_loop
        push    0x4f6358
        call    AudioBindEntry
        mov     eax, dword ptr [g_baseSel]
        add     esp, 4
        mov     dword ptr [eax*4 + 0x30], 5
    L_asimi_install2:
        mov     dword ptr [edi + 8], offset AudioStateInitMultiInstall
        mov     dword ptr [edi + 0x84], ebx
        mov     dword ptr [g_pendingNodeType], ebx
        mov     dword ptr [g_framePauseFlag], ebx
    L_asimi_ret:
        pop     edi
        pop     esi
        pop     ebx
        ret
    }
}
