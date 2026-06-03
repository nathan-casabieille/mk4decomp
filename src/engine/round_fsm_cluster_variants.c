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

/* ------------------------------------------------------------------ */
/* Cinematic FSM cluster (560b game, 4 packed helpers)                 */
/* ------------------------------------------------------------------ */
extern void ScaledChainJmp_00429470(void);
extern void TriPhaseDecCounterListAdvance(void);
extern void RoundFsmCluster_EsiEdiAliasDualMul10(void);
extern void MStackPushSet0008(void);
extern void IterStepDualStore(void);
extern void CmpEqInitCallElseJmp(void);
extern void ScaledIndexConditionalAdd(void);
extern unsigned int g_dispatchSave735;
extern unsigned int g_dispatchSave736;
extern unsigned int g_bootInitSaveSlot;

extern unsigned int g_dispatchSave924;
extern unsigned int g_load_0052ab10;
extern void ArgSarStoreJmp(void);
extern void Atan2QuadrantLookup(void);
extern void FiveCallGuardSetTail(void);
extern void GuardedArithDualCallChain(void);
extern void ScaledZero44(void);
extern void TripleScaledChainStore54(void);
extern void Wrapper_ScaledChainPushCall_004ef898(void);

__declspec(naked) void CinematicFsmCluster(void)
{
    __asm {
        /* === Helper 1 (0x47aaf0): tiny accumulator === */
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      eax, dword ptr [g_currentNodeFlags]
        add      eax, dword ptr [ecx*4 + 0x54]
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x54], eax
        ret
        nop
        /* === Helper 2: cinematic frame counter === */
        mov      eax, dword ptr [g_fightGroupHead]
        mov      edx, dword ptr [g_player1NodeIdx]
        mov      ecx, dword ptr [g_gtPlayerProbe2]
        cmp      eax, edx
        mov      dword ptr [g_currentNodeIdx], ecx
        je       short L_ab37
        mov      ecx, dword ptr [g_gtPlayerProbe1]
        mov      dword ptr [g_currentNodeIdx], ecx
    L_ab37:
        mov      eax, dword ptr [ecx*4 + 0x5c]
        dec      eax
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [g_bootInitSaveSlot], eax
        jne      short L_ab55
        mov      eax, 5
        mov      dword ptr [g_walkCallback], eax
    L_ab55:
        mov      dword ptr [ecx*4 + 0x5c], eax
        mov      eax, dword ptr [g_bootInitSaveSlot]
        test     eax, eax
        jne      short L_ab6a
        jmp      Wrapper_ScaledChainPushCall_004ef898
    L_ab6a:
        ret
        nop
        nop
        nop
        nop
        nop
        /* === Helper 3: 0x215 event + post-stage === */
        mov      dword ptr [g_walkCallback], 0xc
        call     ScaledIndexConditionalAdd
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_abac
        mov      ecx, dword ptr [g_baseSel]
        mov      eax, 0x215
        mov      dword ptr [g_walkCallback], eax
        push     OFFSET g_dispatchSave735
        mov      dword ptr [ecx*4 + 0x74], eax
        call     ArgSarStoreJmp
        add      esp, 4
    L_abac:
        ret
        nop
        nop
        nop
        /* === Helper 4 (0x47abb0): cinematic dispatcher === */
    L_abb0:
        mov      eax, dword ptr [g_baseSel]
        push     esi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        sub      eax, 0
        je       short L_ac89
        dec      eax
        je       short L_abe1
        call     FiveCallGuardSetTail
        pop      esi
        ret
    L_abe1:
        call     RoundFsmCluster_EsiEdiAliasDualMul10
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_ad1e
        mov      eax, dword ptr [g_eventQueueChild]
        dec      eax
        mov      dword ptr [g_eventQueueChild], eax
        jne      L_aca9
        call     MStackPushSet0008
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_ad1e
        call     ScaledZero44
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_ad1e
        mov      dword ptr [esi + 8], OFFSET L_abb0
        mov      ecx, dword ptr [g_baseSel]
        mov      edx, OFFSET L_abb0
        mov      dword ptr [ecx*4 + 0x84], 2
        mov      eax, dword ptr [esi + 4]
        add      edx, 0x2000000
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], edx
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      eax, dword ptr [g_baseSel]
        mov      dword ptr [eax*4 + 0x84], 0
        call     ScaledChainJmp_00429470
        mov      dword ptr [g_framePauseFlag], 1
        pop      esi
        ret
    L_ac89:
        push     OFFSET g_dispatchSave736
        call     IterStepDualStore
        mov      eax, dword ptr [g_framePauseFlag]
        add      esp, 4
        test     eax, eax
        jne      short L_ad1e
        mov      dword ptr [g_eventQueueChild], 0xf
    L_aca9:
        mov      eax, dword ptr [g_matrixStackTop]
        mov      ecx, dword ptr [g_eventQueueChild]
        inc      eax
        mov      dword ptr [g_walkCallback], 0x16
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], ecx
        call     CmpEqInitCallElseJmp
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_ad1e
        mov      eax, dword ptr [g_matrixStackTop]
        mov      cl, byte ptr [g_xformDirtyFlags]
        mov      edx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      eax, 1
        test     cl, al
        mov      dword ptr [g_eventQueueChild], edx
        je       short L_ad07
        call     TriPhaseDecCounterListAdvance
        pop      esi
        ret
    L_ad07:
        mov      dword ptr [esi + 8], OFFSET L_abb0
        mov      dword ptr [esi + 0x84], eax
        mov      dword ptr [g_pendingNodeType], eax
        mov      dword ptr [g_framePauseFlag], eax
    L_ad1e:
        pop      esi
        ret
    }
}

__declspec(naked) void RoundFsmCluster_Atan2QuadrantLookup(void)
{
    __asm {
    L_08a0:
        mov      eax, dword ptr [g_player1NodeIdx]
        mov      ecx, dword ptr [g_load_0052ab10]
        mov      dword ptr [g_eventQueueIdx], eax
        mov      dword ptr [g_fightGroupHead], ecx
        mov      edx, dword ptr [ecx*4 + 0x5c]
        push     esi
        mov      dword ptr [g_walkCallback], edx
        mov      esi, dword ptr [eax*4 + 0x5c]
        sub      esi, edx
        mov      dword ptr [g_eventQueueWorkType], esi
        mov      ecx, dword ptr [ecx*4 + 0x58]
        mov      dword ptr [g_walkCallback], ecx
        mov      eax, dword ptr [eax*4 + 0x58]
        sub      eax, ecx
        mov      dword ptr [g_acc_00542078], eax
        mov      dword ptr [g_eventQueueNotMask], eax
        call     Atan2QuadrantLookup
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_098f
        mov      edx, dword ptr [g_fightGroupHead]
        mov      ecx, dword ptr [g_walkCallback]
        mov      eax, 0x6487e
        sub      eax, ecx
        mov      ecx, dword ptr [g_eventQueueIdx]
        lea      esi, [edx*4]
        mov      dword ptr [g_eventQueueNotMask], eax
        shl      ecx, 2
        mov      dword ptr [esi + 0x60], eax
        mov      eax, dword ptr [esi + 0x5c]
        mov      dword ptr [g_walkCallback], eax
        mov      edx, dword ptr [ecx + 0x5c]
        sub      edx, eax
        mov      dword ptr [g_eventQueueWorkType], edx
        mov      eax, dword ptr [esi + 0x54]
        mov      dword ptr [g_walkCallback], eax
        mov      ecx, dword ptr [ecx + 0x54]
        sub      ecx, eax
        mov      dword ptr [g_acc_00542078], ecx
        call     Atan2QuadrantLookup
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_098f
        mov      edx, dword ptr [g_walkCallback]
        mov      dword ptr [esi + 0x64], edx
        mov      dword ptr [g_eventQueueNotMask], 0
        mov      dword ptr [esi + 0x60], 0
        mov      eax, dword ptr [g_eventQueueNotMask]
        mov      dword ptr [esi + 0x64], eax
        mov      ecx, dword ptr [g_eventQueueNotMask]
        mov      dword ptr [esi + 0x68], ecx
    L_098f:
        pop      esi
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
        nop
    L_09a0:
        mov      eax, dword ptr [g_baseSel]
        push     esi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        cmp      eax, 3
        ja       L_0b45
        jmp      dword ptr [eax*4 + L_jmptbl]
    L_09ce:
        mov      eax, dword ptr [g_xformScratch2088]
        mov      ecx, 0x10000
        cmp      eax, ecx
        jl       L_0b10
        mov      edx, dword ptr [g_fightGroupHead]
        mov      dword ptr [g_xformScratch2088], ecx
        mov      dword ptr [edx*4 + 0x74], ecx
        mov      eax, dword ptr [g_player1NodeIdx]
        mov      dword ptr [g_eventQueueIdx], eax
        jmp      L_0a36
    L_09ff:
        mov      ecx, dword ptr [g_eventQueueIdx]
        mov      edx, dword ptr [g_fightGroupHead]
        mov      ecx, dword ptr [ecx*4 + 0x5c]
        mov      dword ptr [g_walkCallback], ecx
        mov      eax, dword ptr [edx*4 + 0x5c]
        sub      eax, ecx
        mov      dword ptr [g_eventQueueCurrent], eax
        jns      L_0a2f
        neg      eax
        mov      dword ptr [g_eventQueueCurrent], eax
    L_0a2f:
        cmp      eax, 0x120000
        jle      L_0a58
    L_0a36:
        mov      eax, 1
        mov      dword ptr [esi + 8], OFFSET L_09a0
        mov      dword ptr [esi + 0x84], 2
        mov      dword ptr [g_pendingNodeType], eax
        mov      dword ptr [g_framePauseFlag], eax
        pop      esi
        ret      
    L_0a58:
        mov      dword ptr [g_currentNodeFlags], 0xd4f
        mov      dword ptr [g_xformScratch2088], 0x147a
        jmp      L_0aa3
    L_0a6e:
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      edx, dword ptr [g_currentNodeFlags]
        mov      eax, dword ptr [ecx*4 + 0x74]
        mov      dword ptr [g_walkCallback], eax
        sub      eax, edx
        mov      dword ptr [g_eventQueueCurrent], eax
        mov      dword ptr [ecx*4 + 0x74], eax
        mov      eax, dword ptr [g_xformScratch2088]
        mov      ecx, dword ptr [g_eventQueueCurrent]
        cmp      ecx, eax
        jle      L_0ac5
    L_0aa3:
        mov      eax, 1
        mov      dword ptr [esi + 8], OFFSET L_09a0
        mov      dword ptr [esi + 0x84], 3
        mov      dword ptr [g_pendingNodeType], eax
        mov      dword ptr [g_framePauseFlag], eax
        pop      esi
        ret      
    L_0ac5:
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      dword ptr [ecx*4 + 0x74], eax
        jmp      L_0b7c
    L_0ad7:
        push     OFFSET g_dispatchSave924
        call     TripleScaledChainStore54
        mov      eax, dword ptr [g_framePauseFlag]
        add      esp, 4
        test     eax, eax
        jne      L_0bb8
        call     L_08a0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_0bb8
        mov      edx, dword ptr [g_fightGroupHead]
        mov      eax, dword ptr [edx*4 + 0x74]
    L_0b10:
        mov      ecx, dword ptr [g_fightGroupHead]
        add      eax, 0x7ae
        mov      dword ptr [g_xformScratch2088], eax
        mov      dword ptr [ecx*4 + 0x74], eax
        mov      eax, 1
        mov      dword ptr [esi + 8], OFFSET L_09a0
        mov      dword ptr [esi + 0x84], eax
        mov      dword ptr [g_pendingNodeType], eax
        mov      dword ptr [g_framePauseFlag], eax
        pop      esi
        ret      
    L_0b45:
        mov      edx, dword ptr [g_eventQueueIdx]
        mov      ecx, dword ptr [edx*4 + 0x5c]
        mov      edx, dword ptr [g_fightGroupHead]
        mov      dword ptr [g_walkCallback], ecx
        mov      eax, dword ptr [edx*4 + 0x5c]
        sub      eax, ecx
        mov      dword ptr [g_eventQueueCurrent], eax
        jns      L_0b75
        neg      eax
        mov      dword ptr [g_eventQueueCurrent], eax
    L_0b75:
        cmp      eax, 0x70000
        jle      L_0b9e
    L_0b7c:
        mov      eax, 1
        mov      dword ptr [esi + 8], OFFSET L_09a0
        mov      dword ptr [esi + 0x84], 4
        mov      dword ptr [g_pendingNodeType], eax
        mov      dword ptr [g_framePauseFlag], eax
        pop      esi
        ret      
    L_0b9e:
        mov      dword ptr [g_walkCallback], 0
        mov      dword ptr [edx*4 + 0x74], 0
        call     StackPopDispatchTagged
    L_0bb8:
        pop      esi
        ret
        _emit 0x8b
        _emit 0xff
    L_jmptbl:
        _emit 0xd7
        _emit 0x0a
        _emit 0x43
        _emit 0x00
        _emit 0xce
        _emit 0x09
        _emit 0x43
        _emit 0x00
        _emit 0xff
        _emit 0x09
        _emit 0x43
        _emit 0x00
        _emit 0x6e
        _emit 0x0a
        _emit 0x43
        _emit 0x00
        nop
        nop
        nop
        nop
    L_0bd0:
        mov      eax, dword ptr [g_baseSel]
        push     esi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        sub      eax, 0
        je       L_0cec
        dec      eax
        je       L_0cac
        dec      eax
        je       L_0c3c
        mov      ecx, dword ptr [g_currentNodeFlags]
        push     ecx
        push     0xeb85
        call     Mul10Tail
        add      esp, 8
        cmp      eax, 0x24d
        mov      dword ptr [g_currentNodeFlags], eax
        jge      L_0c2b
        mov      eax, 0x24d
        mov      dword ptr [g_currentNodeFlags], eax
    L_0c2b:
        mov      ecx, dword ptr [g_xformScratch2088]
        test     ecx, ecx
        jg       L_0c72
        call     StackPopDispatchTagged
        pop      esi
        ret      
    L_0c3c:
        mov      edx, dword ptr [g_currentNodeFlags]
        push     edx
        push     0x1147a
        call     Mul10Tail
        add      esp, 8
        cmp      eax, 0xf5c
        mov      dword ptr [g_currentNodeFlags], eax
        jle      L_0c66
        mov      eax, 0xf5c
        mov      dword ptr [g_currentNodeFlags], eax
    L_0c66:
        cmp      dword ptr [g_xformScratch2088], 0xc924
        jg       L_0cb6
    L_0c72:
        sub      dword ptr [g_xformScratch2088], eax
        call     GuardedArithDualCallChain
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_0d25
        mov      eax, 1
        mov      dword ptr [esi + 8], OFFSET L_0bd0
        mov      dword ptr [esi + 0x84], 3
        mov      dword ptr [g_pendingNodeType], eax
        mov      dword ptr [g_framePauseFlag], eax
        pop      esi
        ret      
    L_0cac:
        mov      eax, 0x28f
        mov      dword ptr [g_currentNodeFlags], eax
    L_0cb6:
        sub      dword ptr [g_xformScratch2088], eax
        call     GuardedArithDualCallChain
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_0d25
        mov      eax, 1
        mov      dword ptr [esi + 8], OFFSET L_0bd0
        mov      dword ptr [esi + 0x84], 2
        mov      dword ptr [g_pendingNodeType], eax
        mov      dword ptr [g_framePauseFlag], eax
        pop      esi
        ret      
    L_0cec:
        mov      dword ptr [g_xformScratch2088], 0x1921f
        call     GuardedArithDualCallChain
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_0d25
        mov      eax, 1
        mov      dword ptr [esi + 8], OFFSET L_0bd0
        mov      dword ptr [esi + 0x84], eax
        mov      dword ptr [g_pendingNodeType], 0x16
        mov      dword ptr [g_framePauseFlag], eax
    L_0d25:
        pop      esi
        ret      
    }
}
