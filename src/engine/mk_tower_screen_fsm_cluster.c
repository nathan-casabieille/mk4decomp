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
extern void Wrapper_00436490(void);
extern void MoveFsmCluster(void);
extern void CallPauseTestByteJmpCalls(void);
extern void InstallSelfFullPath(void);
extern void InstallSelfCountdownChain(void);
extern void CopyJmp_0048ef90(void);
extern void DualTestDirtyToggle_004282c0(void);
extern void TripleVecAccCallStore(void);
extern void Thunk_004bd5c0(void);
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

extern unsigned int g_phaseCounter;
extern unsigned int g_phaseThunkVar_00541fb4;
extern unsigned int g_dispatchAcc_00541fb8;
extern void CallSetPause(void);
extern void MStackChainOrBitLoop(void);
extern void MStackPush2LLWalkCompare(void);
extern void MStackPush2ScaledChainLoop(void);
extern void Thunk_00427460(void);
extern void TripleEntryWordPushChain(void);
extern void func_00462ac0(void);

__declspec(naked) void MkTowerScreenFsmCluster(void)
{
    __asm {
        /* === Helper 1 (0x462560): row-process column-N w/ offset === */
        mov      eax, dword ptr [g_phaseCounter]
        mov      ecx, dword ptr [g_phaseThunkVar_00541fb4]
        add      ecx, eax
        push     ebx
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      ecx, dword ptr [ecx*4]
        test     ecx, ecx
        mov      dword ptr [g_eventQueueCurrent], ecx
        je       L_264f
        mov      edx, dword ptr [g_dispatchAcc_00541fb8]
        shl      eax, 2
        mov      dword ptr [g_walkCallback], eax
        add      eax, edx
        mov      dword ptr [g_pendingNodeType], eax
        mov      eax, dword ptr [eax*4]
        mov      dword ptr [g_walkCallback], eax
        call     MStackPush2LLWalkCompare
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_264f
        mov      al, byte ptr [g_xformDirtyFlags]
        mov      ebx, 4
        test     al, bl
        jne      short L_264f
        mov      eax, dword ptr [g_eventQueueCurrent]
        mov      edx, 0xfffe6de1
        dec      eax
        mov      dword ptr [g_walkCallback], edx
        mov      dword ptr [g_eventQueueCurrent], eax
        je       short L_25fd
        mov      ecx, eax
    L_25e8:
        sub      edx, 0x1921f
        dec      eax
        dec      ecx
        jne      short L_25e8
        mov      dword ptr [g_eventQueueCurrent], eax
        mov      dword ptr [g_walkCallback], edx
    L_25fd:
        call     Thunk_00427460
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_264f
        mov      eax, dword ptr [g_currentNodeIdx]
    L_2610:
        mov      ecx, dword ptr [g_walkCallback]
        mov      dword ptr [eax*4 + 0x64], ecx
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      eax, dword ptr [edx*4 + 0x40]
        mov      edx, dword ptr [g_xformDirtyFlags]
        or       edx, ebx
        mov      dword ptr [g_currentNodeIdx], eax
        test     eax, eax
        mov      dword ptr [g_xformDirtyFlags], edx
        je       short L_264f
        mov      ecx, edx
        xor      ecx, ebx
        test     eax, eax
        mov      dword ptr [g_xformDirtyFlags], ecx
        jne      short L_2610
    L_264f:
        pop      ebx
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
        /* === Helper 2 (0x462660): wait-2-tier countdown === */
    L_2660:
        mov      eax, dword ptr [g_baseSel]
        shl      eax, 2
        mov      ecx, dword ptr [eax + 0x84]
        mov      dword ptr [eax + 0x84], 0
        test     ecx, ecx
        je       short L_26ae
        mov      ecx, dword ptr [g_eventQueueIdx]
        dec      ecx
        mov      dword ptr [g_eventQueueIdx], ecx
        jne      short L_26c2
        mov      ecx, dword ptr [g_eventQueueEnd]
        dec      ecx
        mov      dword ptr [g_eventQueueEnd], ecx
        jne      short L_26b8
        push     0
        push     OFFSET func_00462ac0
        call     StoreTwoCall
        add      esp, 8
        jmp      CallSetPause
    L_26ae:
        mov      dword ptr [g_eventQueueEnd], 0xf
    L_26b8:
        mov      dword ptr [g_eventQueueIdx], 6
    L_26c2:
        mov      ecx, 1
        mov      dword ptr [eax + 8], OFFSET L_2660
        mov      dword ptr [eax + 0x84], ecx
        mov      dword ptr [g_pendingNodeType], 0xa
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
        /* === Helper 3 (0x4626f0): 2-state init dispatcher === */
    L_26f0:
        mov      eax, dword ptr [g_baseSel]
        push     esi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        sub      eax, 0
        je       short L_274b
        dec      eax
        jne      short L_274b
        call     MStackChainOrBitLoop
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_277a
        mov      dword ptr [esi + 8], OFFSET L_26f0
        mov      dword ptr [esi + 0x84], 2
        mov      dword ptr [g_pendingNodeType], 4
        mov      dword ptr [g_framePauseFlag], 1
        pop      esi
        ret
    L_274b:
        call     MStackPush2ScaledChainLoop
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_277a
        mov      eax, 1
        mov      dword ptr [esi + 8], OFFSET L_26f0
        mov      dword ptr [esi + 0x84], eax
        mov      dword ptr [g_pendingNodeType], 4
        mov      dword ptr [g_framePauseFlag], eax
    L_277a:
        pop      esi
        ret
        nop
        nop
        nop
        nop
        /* === Helper 4: flag-gated jmp 004627c0 (path A) === */
        mov      eax, dword ptr [g_active_0053a408]
        test     eax, eax
        mov      dword ptr [g_walkCallback], eax
        jne      short L_2793
        jmp      CallSetPause
    L_2793:
        jmp      TripleEntryWordPushChain
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        /* === Helper 5: flag-gated jmp 004627c0 (path B) === */
        mov      eax, dword ptr [g_active_00537e88]
        test     eax, eax
        mov      dword ptr [g_walkCallback], eax
        jne      short L_27b3
        jmp      CallSetPause
    L_27b3:
        jmp      TripleEntryWordPushChain
    }
}
