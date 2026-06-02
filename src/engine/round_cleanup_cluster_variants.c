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

extern void StoreIncrMStackPush6(void);
extern void DispatcherComplex181_Push70CallScaleArith(void);
extern void RoundCleanupCluster_00427690(void);

/* @addr 0x00477920 (165b game) - poll-then-init pattern:
 *   poll: SaveCallRestore(0x22); SaveCallRestoreOrXor(0x22); while (state & 4): retry.
 *   walkCallback = max(g_gameCountdown, 0); call StoreIncrMStackPush6; pause? ret.
 *   set fixed state (walkCallback=2, g_eventQueueWorkType=0x22, g_eventQueueCurrent=2,
 *   g_acc_00542078=0, g_eventQueueNotMask=0xff960000, g_currentNodeFlags=2);
 *   call DispatcherComplex181; pause? ret; call RoundCleanupCluster_00427690.
 */
extern unsigned int g_dispatchSave689;
extern unsigned int g_dispatchSave690;
extern unsigned int g_dispatchSave691;
extern unsigned int g_dispatchSave692;
extern unsigned int g_dispatchSave59;
extern unsigned int g_gameCountdown;
extern void ArgSarStoreJmp(void);
extern void ChainGatedNegAccum(void);
extern void DualScaledStore(void);
extern void FiveCallGuardSetTail(void);
extern void InstallSelfPackedTailJmp(void);
extern void MStackPush2GlobalSwap(void);
extern void PendingMatch_00455bd0(void);
extern void SaveCallRestoreOrXor(void);
extern void SaveCallRestore(void);
extern void SetJmp_InstallSelfChainEsi(void);
extern void StoreLoadJmp(void);
extern void func_004569f0(void);

extern unsigned int g_dispatchSave583;
extern unsigned int g_dispatchSave582;
extern void DualEntryBitFlagDispatch(void);
extern void GameLoaderHandlerCluster(void);
extern void IterStepDualStore(void);
extern void MStackPush3CallCascade(void);
extern void MStackPush3CmpCall(void);
extern void MStackPushSet0004(void);
extern void RoundCleanupCluster_00487510(void);
extern void TableLookupCall_g_table_004ef998(void);

__declspec(naked) void PollThenInit(void) {
    __asm {
        push    ebx
        push    0x22
        call    SaveCallRestore
        add     esp, 4
        push    0x22
        call    SaveCallRestoreOrXor
        mov     al, byte ptr [g_xformDirtyFlags]
        mov     bl, 4
        add     esp, 4
        _emit   84h
        _emit   0c3h
        _emit   75h
        _emit   1dh
loopPoll:
        push    0x22
        call    SaveCallRestore
        add     esp, 4
        push    0x22
        call    SaveCallRestoreOrXor
        mov     al, byte ptr [g_xformDirtyFlags]
        add     esp, 4
        _emit   84h
        _emit   0c3h
        _emit   74h
        _emit   0e3h
        mov     eax, dword ptr [g_gameCountdown]
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        _emit   7dh
        _emit   0ah
        mov     dword ptr [g_walkCallback], 0
        call    StoreIncrMStackPush6
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   40h
        mov     eax, 2
        mov     dword ptr [g_eventQueueWorkType], 0x22
        mov     dword ptr [g_eventQueueCurrent], eax
        mov     dword ptr [g_acc_00542078], 0
        mov     dword ptr [g_eventQueueNotMask], 0xff960000
        mov     dword ptr [g_currentNodeFlags], eax
        call    DispatcherComplex181_Push70CallScaleArith
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   05h
        call    RoundCleanupCluster_00427690
        pop     ebx
        ret
    }
}


__declspec(naked) void RoundCleanupCluster_00487510(void)
{
    __asm {
        /* H1: installer */
        mov      eax, dword ptr [g_baseSel]
        mov      ecx, 1
        shl      eax, 2
        mov      dword ptr [eax + 0x84], 0
        mov      dword ptr [eax + 8], OFFSET RoundCleanupCluster_00487510
        mov      dword ptr [eax + 0x84], ecx
        mov      dword ptr [g_pendingNodeType], 0x28
        mov      dword ptr [g_framePauseFlag], ecx
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
        nop
        nop
        /* H2: animate + tail-jump */
        mov      dword ptr [g_walkCallback], 0x27
        call     TableLookupCall_g_table_004ef998
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_758b
        mov      dword ptr [g_eventQueueWorkType], 1
        mov      dword ptr [g_eventQueueNotMask], 2
        mov      dword ptr [g_walkCallback], 0x23d7
        jmp      MStackPush3CallCascade
    L_758b:
        ret
        nop
        nop
        nop
        nop
        /* H3: load + sound */
        push     OFFSET g_dispatchSave583
        call     IterStepDualStore
        mov      eax, dword ptr [g_framePauseFlag]
        add      esp, 4
        test     eax, eax
        jne      short L_75c1
        call     MStackPushSet0004
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_75c1
        push     OFFSET g_dispatchSave582
        call     ArgSarStoreJmp
        add      esp, 4
    L_75c1:
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
        nop
        nop
        nop
        nop
        nop
        /* H4 (L_75d0): big state dispatcher */
    L_75d0:
        mov      eax, dword ptr [g_baseSel]
        push     ebx
        push     esi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        sub      eax, 0
        je       L_76c8
        dec      eax
        je       short L_765f
        dec      eax
        mov      ebx, 1
        je       short L_763f
        call     DualEntryBitFlagDispatch
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_76ea
        test     byte ptr [g_xformDirtyFlags], bl
        je       short L_7637
        call     MStackPush3CmpCall
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_76ea
        test     byte ptr [g_xformDirtyFlags], bl
        jne      short L_763f
    L_7637:
        call     FiveCallGuardSetTail
        pop      esi
        pop      ebx
        ret
    L_763f:
        mov      dword ptr [esi + 8], OFFSET L_75d0
        mov      dword ptr [esi + 0x84], 3
        mov      dword ptr [g_pendingNodeType], ebx
        mov      dword ptr [g_framePauseFlag], ebx
        pop      esi
        pop      ebx
        ret
    L_765f:
        mov      ecx, dword ptr [g_baseSel]
        mov      eax, dword ptr [ecx*4 + 0x60]
        cmp      eax, 0x10a
        mov      dword ptr [g_walkCallback], eax
        jne      short L_768b
        call     GameLoaderHandlerCluster
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_76ea
        mov      eax, dword ptr [g_walkCallback]
    L_768b:
        cmp      eax, 0x10b
        jne      short L_76a0
        call     GameLoaderHandlerCluster
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_76ea
    L_76a0:
        mov      dword ptr [esi + 8], OFFSET L_75d0
        mov      dword ptr [esi + 0x84], 2
        mov      dword ptr [g_pendingNodeType], 5
        mov      dword ptr [g_framePauseFlag], 1
        pop      esi
        pop      ebx
        ret
    L_76c8:
        mov      ebx, 1
        mov      dword ptr [esi + 8], OFFSET L_75d0
        mov      dword ptr [esi + 0x84], ebx
        mov      dword ptr [g_pendingNodeType], 8
        mov      dword ptr [g_framePauseFlag], ebx
    L_76ea:
        pop      esi
        pop      ebx
        ret
    }
}

__declspec(naked) void RoundCleanupCluster_00455920(void)
{
    __asm {
        /* === Helper 1 (0x455920): event 004e7f40 forwarder === */
    L_5920:
        push     OFFSET g_dispatchSave689
        call     ArgSarStoreJmp
        add      esp, 4
        ret
        nop
        nop
        /* === Helper 2 (0x455930): counter loop calling helper 1 === */
        mov      eax, dword ptr [g_eventQueueIdx]
        dec      eax
        mov      dword ptr [g_eventQueueIdx], eax
        js       short L_5942
        /* force 5-byte NEAR jmp (orig is e9 de ff ff ff, not short jmp) */
        _emit    0xe9
        _emit    0xde
        _emit    0xff
        _emit    0xff
        _emit    0xff
    L_5942:
        push     OFFSET g_dispatchSave690
        call     ArgSarStoreJmp
        add      esp, 4
        ret
        /* === Helper 3 (0x455950): main FSM w/ jump table === */
    L_5950:
        mov      eax, dword ptr [g_baseSel]
        push     esi
        push     edi
        xor      edi, edi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], edi
        cmp      eax, 3
        ja       L_5abd
        jmp      dword ptr [eax*4 + L_jmptbl_5b28]
    L_597d:
        /* case 1: 4569f0 text dispatch */
        push     OFFSET func_004569f0
        call     StoreLoadJmp
        mov      dword ptr [esi + 8], OFFSET L_5950
        mov      dword ptr [esi + 0x84], 2
        add      esp, 4
        mov      dword ptr [g_pendingNodeType], 0x64
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        ret
    L_59b2:
        /* case 2: install + state 3 */
        mov      ecx, dword ptr [g_eventQueueEnd]
        mov      dword ptr [g_fightGroupHead], ecx
        mov      dword ptr [esi + 8], OFFSET L_5950
        mov      edx, dword ptr [g_baseSel]
        mov      ecx, OFFSET L_5950
        add      ecx, 0x3000000
        mov      dword ptr [edx*4 + 0x84], 3
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      edx, dword ptr [g_baseSel]
        mov      dword ptr [edx*4 + 0x84], edi
        call     InstallSelfPackedTailJmp
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        ret
    L_5a1d:
        /* case 3: install + state 4 */
        mov      eax, OFFSET g_dispatchSave59
        mov      edx, OFFSET L_5950
        shr      eax, 2
        mov      dword ptr [g_eventQueueEnd], eax
        mov      dword ptr [esi + 8], OFFSET L_5950
        mov      ecx, dword ptr [g_baseSel]
        add      edx, 0x4000000
        mov      dword ptr [ecx*4 + 0x84], 4
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], edx
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      eax, dword ptr [g_baseSel]
        mov      dword ptr [eax*4 + 0x84], edi
        call     SetJmp_InstallSelfChainEsi
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        ret
    L_5a88:
        /* case 0: pre-stage */
        call     DualScaledStore
        cmp      dword ptr [g_framePauseFlag], edi
        jne      short L_5b22
        mov      eax, 1
        mov      dword ptr [esi + 8], OFFSET L_5950
        mov      dword ptr [esi + 0x84], eax
        mov      dword ptr [g_pendingNodeType], 0x47
        mov      dword ptr [g_framePauseFlag], eax
        pop      edi
        pop      esi
        ret
    L_5abd:
        mov      ecx, dword ptr [g_eventQueueIdx]
        mov      dword ptr [g_acc_00542078], 0x16666
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      dword ptr [g_eventQueueNotMask], edi
        call     ChainGatedNegAccum
        cmp      dword ptr [g_framePauseFlag], edi
        jne      short L_5b22
        mov      edx, dword ptr [g_eventQueueEnd]
        mov      eax, dword ptr [g_acc_00542078]
        push     OFFSET g_dispatchSave691
        mov      dword ptr [edx*4 + 0x54], eax
        mov      ecx, dword ptr [g_eventQueueEnd]
        mov      edx, dword ptr [g_eventQueueNotMask]
        mov      dword ptr [ecx*4 + 0x5c], edx
        mov      eax, dword ptr [g_eventQueueEnd]
        mov      dword ptr [g_fightGroupHead], eax
        call     ArgSarStoreJmp
        add      esp, 4
    L_5b22:
        pop      edi
        pop      esi
        ret
        /* 3-byte align pad: lea ecx, [ecx] (8d 49 00) */
        _emit    0x8d
        _emit    0x49
        _emit    0x00
    L_jmptbl_5b28:
        /* 4 absolute-address entries */
        _emit 0x88
        _emit 0x5a
        _emit 0x45
        _emit 0x00
        _emit 0x7d
        _emit 0x59
        _emit 0x45
        _emit 0x00
        _emit 0xb2
        _emit 0x59
        _emit 0x45
        _emit 0x00
        _emit 0x1d
        _emit 0x5a
        _emit 0x45
        _emit 0x00
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        /* === Helper 4 (0x455b3b): set 0x10 bit + event 004e7f70 === */
        mov      eax, dword ptr [g_matrixStackTop]
        mov      ecx, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], ecx
        mov      edx, dword ptr [g_baseSel]
        mov      ecx, dword ptr [edx*4 + 0x64]
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      eax, dword ptr [ecx*4 + 0x34]
        or       ah, 0x10
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x34], eax
        mov      eax, dword ptr [g_matrixStackTop]
        mov      ecx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      dword ptr [g_matrixStackTop], eax
        call     MStackPush2GlobalSwap
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_5bb4
        push     OFFSET g_dispatchSave692
        call     ArgSarStoreJmp
        add      esp, 4
    L_5bb4:
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
        nop
        nop
        /* === Helper 5 (0x455bc0): init counter + jmp 00455bd0 === */
        mov      dword ptr [g_eventQueueIdx], 0x16
        jmp      PendingMatch_00455bd0
    }
}
