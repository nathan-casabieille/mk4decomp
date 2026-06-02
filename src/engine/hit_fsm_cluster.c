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

/* ------------------------------------------------------------------ */
/* Move-FSM cluster (545b game, 5 packed move/transition helpers)      */
/* ------------------------------------------------------------------ */
extern void GuardedSeq_00433bb0(void);
extern void Wrapper_00436490(void);
extern void DualEntry5WayThreshold(void);
extern void InstallSelfMStackPushDispatch(void);
extern void HitFsmCluster(void);
extern void CallPauseConstStoreJmp_00438170(void);
extern void SetJmp_00438f70(void);
extern void PrefixThunkInstallSelf3State(void);
extern void InstallSelfDecBitCheck(void);
extern void MStackChainExtractCall(void);
extern void Cmp2CallDirtyCall(void);
extern void QuadBlockArgInstallChain(void);
extern void MstackPopScaledChainPlusThunks(void);
extern void State208cBit0Flag(void);
extern void ScaledChain3c74(void);
extern unsigned int g_dispatchSave925_004e46e0;
extern unsigned int g_dispatchSave926_004e4a14;


__declspec(naked) void MoveFsmCluster(void)
{
    __asm {
        /* === Main (0x4364a0): post move-pick dispatcher === */
        mov      eax, dword ptr [g_matrixStackTop]
        mov      dword ptr [g_walkCallback], 0xc
        inc      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], OFFSET L_64d0
        jmp      MstackPopScaledChainPlusThunks
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
        /* === Helper 2 (0x4364d0): two-branch transition === */
    L_64d0:
        mov      eax, dword ptr [g_baseSel]
        xor      edx, edx
        shl      eax, 2
        push     esi
        push     edi
        mov      ecx, dword ptr [eax + 0x84]
        mov      dword ptr [eax + 0x84], edx
        sub      ecx, edx
        je       short L_6570
        dec      ecx
        je       short L_64fb
        call     Wrapper_00436490
        pop      edi
        pop      esi
        ret
    L_64fb:
        mov      dword ptr [g_currentNodeFlags], 0x19999
        mov      dword ptr [g_eventQueueChild], 0x3c
        mov      dword ptr [eax + 8], OFFSET L_64d0
        mov      ecx, dword ptr [g_baseSel]
        mov      esi, OFFSET L_64d0
        mov      dword ptr [ecx*4 + 0x84], 2
        mov      ecx, dword ptr [eax + 4]
        add      esi, 0x2000000
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      dword ptr [ecx*4], esi
        mov      ecx, dword ptr [g_currentNodeIdx]
        inc      ecx
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      dword ptr [eax + 4], ecx
        mov      eax, dword ptr [g_baseSel]
        mov      dword ptr [eax*4 + 0x84], edx
        call     CallPauseConstStoreJmp_00438170
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        ret
    L_6570:
        mov      dword ptr [g_eventQueueChild], 0x78
        mov      dword ptr [eax + 8], OFFSET L_64d0
        mov      ecx, dword ptr [g_baseSel]
        mov      esi, 1
        mov      edi, OFFSET L_64d0
        mov      dword ptr [ecx*4 + 0x84], esi
        mov      ecx, dword ptr [eax + 4]
        add      edi, 0x1000000
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      dword ptr [ecx*4], edi
        mov      ecx, dword ptr [g_currentNodeIdx]
        inc      ecx
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      dword ptr [eax + 4], ecx
        mov      eax, dword ptr [g_baseSel]
        mov      dword ptr [eax*4 + 0x84], edx
        call     InstallSelfDecBitCheck
        mov      dword ptr [g_framePauseFlag], esi
        pop      edi
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
        /* === Helper 3 (0x436608): post-action dispatch === */
        push     OFFSET g_dispatchSave926_004e4a14
        call     QuadBlockArgInstallChain
        mov      eax, dword ptr [g_framePauseFlag]
        add      esp, 4
        test     eax, eax
        jne      short L_664f
        call     Cmp2CallDirtyCall
        test     eax, eax
        jne      short L_664f
        mov      eax, dword ptr [g_table_00535ddc]
        cmp      eax, 0x30000
        mov      dword ptr [g_walkCallback], eax
        jle      short L_6615
        jmp      GuardedSeq_00433bb0
    L_6615:
        cmp      eax, 0x1cccc
        jge      short L_6621
        jmp      SetJmp_00438f70
    L_6621:
        call     MStackChainExtractCall
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_664f
        test     byte ptr [g_xformDirtyFlags], 1
        je       short L_663d
        jmp      PrefixThunkInstallSelf3State
    L_663d:
        mov      eax, OFFSET g_dispatchSave925_004e46e0
        sar      eax, 2
        mov      dword ptr [g_eventQueueEnd], eax
        jmp      InstallSelfMStackPushDispatch
    L_664f:
        ret
        /* === Helper 4 (0x436650): special-result flag toggle === */
        call     ScaledChain3c74
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_667e
        mov      eax, dword ptr [g_walkCallback]
        cmp      eax, 0x1006
        mov      eax, dword ptr [g_xformDirtyFlags]
        je       short L_6677
        and      al, 0xfe
        mov      dword ptr [g_xformDirtyFlags], eax
        ret
    L_6677:
        or       al, 1
        mov      dword ptr [g_xformDirtyFlags], eax
    L_667e:
        ret
        nop
        /* === Helper 5 (0x436680): post-block dispatch === */
        call     Cmp2CallDirtyCall
        test     eax, eax
        jne      short L_66c0
        call     State208cBit0Flag
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_66c0
        test     byte ptr [g_xformDirtyFlags], 1
        je       short L_66a5
        jmp      DualEntry5WayThreshold
    L_66a5:
        mov      eax, dword ptr [g_table_00535ddc]
        cmp      eax, 0x40000
        mov      dword ptr [g_walkCallback], eax
        jle      short L_66bb
        jmp      HitFsmCluster
    L_66bb:
        jmp      GuardedSeq_00433bb0
    L_66c0:
        ret
    }
}
