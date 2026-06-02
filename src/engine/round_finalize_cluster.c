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
extern void CopyJmp_0048ef90(void);
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

extern unsigned int g_dispatchSave799;
extern unsigned int g_dispatchSave800;
extern unsigned int g_dispatchSave801;
extern unsigned int g_dispatchSave802;
extern unsigned int g_eq;
extern void ArgSarStoreJmp(void);
extern void ArgSar_Set0_Jmp(void);
extern void CallSetPause(void);
extern void CondPickDualStore(void);
extern void CopyThreeFields(void);
extern void DualCmpSwapStore(void);
extern void MStackBracket2_TreeWalkRecursive(void);
extern void MStackBracket5_LinkedListUnlink(void);
extern void MStackPush2ChainPrepend(void);
extern void Phase1ContextSetup3Helpers(void);
extern void QuadBlockSoundInit(void);
extern void ScaledStackCallPause(void);
extern void TableLookupCall_00489ff0(void);
extern void ThreeChanPackClamp(void);

__declspec(naked) void RoundFinalizeCluster(void)
{
    __asm {
        /* === h1 (0x49b8b0): scan chain + 49b7c0 install === */
        mov      ecx, dword ptr [g_baseSel]
        mov      eax, dword ptr [ecx*4 + 0x68]
        test     eax, eax
        mov      dword ptr [g_walkCallback], eax
        jne      short L_b8d3
        mov      eax, dword ptr [g_xformDirtyFlags]
        or       al, 4
        mov      dword ptr [g_xformDirtyFlags], eax
        ret
    L_b8d3:
        mov      dword ptr [g_currentNodeIdx], eax
        mov      eax, dword ptr [eax*4]
        test     eax, eax
        mov      dword ptr [g_xformEntityIdx], eax
        jne      short L_b8f5
        mov      eax, dword ptr [g_xformDirtyFlags]
        or       al, 4
        mov      dword ptr [g_xformDirtyFlags], eax
        ret
    L_b8f5:
        mov      edx, dword ptr [eax*4 + 0x1c]
        cmp      edx, 3
        mov      dword ptr [g_walkCallback], edx
        je       short L_b909
        xor      eax, eax
    L_b909:
        mov      dword ptr [ecx*4 + 0x68], eax
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      edx, dword ptr [g_xformDirtyFlags]
        mov      ecx, 4
        mov      dword ptr [g_pendingNodeType], eax
        mov      dword ptr [g_xformEntityIdx], ecx
        mov      eax, dword ptr [eax*4]
        or       edx, ecx
        test     eax, eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [g_xformDirtyFlags], edx
        je       short L_b966
        xor      edx, ecx
        test     eax, eax
        mov      dword ptr [g_xformDirtyFlags], edx
        je       short L_b966
        call     MStackBracket5_LinkedListUnlink
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_b9f9
        mov      eax, dword ptr [g_currentNodeIdx]
    L_b966:
        mov      dword ptr [g_eventQueueTotal], eax
        mov      eax, dword ptr [g_pendingNodeType]
        mov      dword ptr [g_currentNodeIdx], eax
        call     MStackBracket2_TreeWalkRecursive
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_b9f9
        mov      eax, dword ptr [g_eventQueueTotal]
        xor      ecx, ecx
        test     eax, eax
        sete     cl
        mov      dword ptr [g_eq], ecx
        mov      ecx, 0xffff6b59
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [g_walkCallback], ecx
        mov      dword ptr [eax*4 + 0x38], ecx
        mov      edx, dword ptr [g_baseSel]
        mov      eax, dword ptr [edx*4 + 0x64]
        mov      dword ptr [g_xformEntityIdx], eax
        mov      eax, dword ptr [g_eq]
        test     eax, eax
        jne      short L_b9d5
        call     MStackPush2ChainPrepend
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_b9f9
    L_b9d5:
        call     ChainWalkInstall
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_b9f9
        mov      eax, dword ptr [g_xformDirtyFlags]
        mov      dword ptr [g_walkCallback], 1
        and      al, 0xfb
        mov      dword ptr [g_xformDirtyFlags], eax
    L_b9f9:
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        /* === h2 (0x49ba00): event 004f24a8 forwarder w/ 0x313 store === */
        mov      ecx, dword ptr [g_baseSel]
        mov      eax, 0x313
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x74], eax
        call     CondPickDualStore
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_ba32
        push     OFFSET g_dispatchSave799
        call     ArgSarStoreJmp
        add      esp, 4
    L_ba32:
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
        /* === h3 (0x49ba40): event 004f2540 forwarder + 0x11fff2 sub === */
        call     DualCmpSwapStore
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_baaa
        push     OFFSET g_dispatchSave800
        call     ScaledStackCallPause
        mov      eax, dword ptr [g_framePauseFlag]
        add      esp, 4
        test     eax, eax
        jne      short L_baaa
        test     byte ptr [g_xformDirtyFlags], 4
        jne      short L_baa5
        mov      eax, dword ptr [g_currentNodeIdx]
        push     0x11fff2
        mov      dword ptr [g_fightGroupHead], eax
        call     ThreeChanPackClamp
        mov      ecx, dword ptr [g_fightGroupHead]
        add      esp, 4
        push     ecx
        call     CopyThreeFields
        mov      edx, dword ptr [g_fightGroupHead]
        add      esp, 4
        mov      eax, dword ptr [edx*4 + 0x18]
        mov      dword ptr [g_currentNodeIdx], eax
    L_baa5:
        jmp      CallSetPause
    L_baaa:
        ret
        nop
        nop
        nop
        nop
        nop
        /* === h4 (0x49bab0): event 004f2550 forwarder + 2x 0x3333 alloc === */
        push     esi
        call     DualCmpSwapStore
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_bb51
        push     OFFSET g_dispatchSave801
        call     ScaledStackCallPause
        mov      eax, dword ptr [g_framePauseFlag]
        add      esp, 4
        test     eax, eax
        jne      short L_bb51
        test     byte ptr [g_xformDirtyFlags], 4
        je       short L_bae9
        call     CallSetPause
        pop      esi
        ret
    L_bae9:
        mov      ecx, dword ptr [g_currentNodeFlags]
        mov      eax, dword ptr [g_currentNodeIdx]
        push     ecx
        push     0x3333
        lea      esi, [eax*4]
        call     Mul10Tail
        mov      edx, dword ptr [g_xformScratch2088]
        add      esp, 8
        mov      dword ptr [g_currentNodeFlags], eax
        push     edx
        push     0x3333
        call     Mul10Tail
        mov      dword ptr [g_xformScratch2088], eax
        mov      eax, dword ptr [g_currentNodeFlags]
        mov      dword ptr [esi + 0x6c], eax
        mov      ecx, dword ptr [g_xformScratch2088]
        add      esp, 8
        mov      dword ptr [esi + 0x74], ecx
        mov      edx, dword ptr [g_currentNodeIdx]
        push     OFFSET g_dispatchSave802
        mov      dword ptr [g_fightGroupHead], edx
        call     ArgSar_Set0_Jmp
        add      esp, 4
    L_bb51:
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
        /* === h5 (0x49bb70): 489ff0+40d990 chain → tail-jmp 49bb90 === */
        mov      dword ptr [g_walkCallback], 0x5e
        call     TableLookupCall_00489ff0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_bb8b
        call     Phase1ContextSetup3Helpers
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_bb8b
        jmp      QuadBlockSoundInit
    L_bb8b:
        ret
    }
}
