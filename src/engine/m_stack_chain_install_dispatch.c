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

extern unsigned int g_audioBank2State_00537f98;
extern void DirtyFlagsManip(void);
extern void DualEntryBitFlagDispatch(void);
extern void MStackChainBit2Cascade(void);
extern void PendingMatch_0048d7b0(void);
extern void PushCjWalkDispatchPop(void);
extern void ScaledLitLoadCall_00480fe0(void);
extern void SfxAttenuateAndApply(void);

__declspec(naked) void MStackChainInstallDispatch(void)
{
    __asm {
        push     ebx
        push     esi
        call     PendingMatch_0048d7b0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_d7ad
        mov      al, byte ptr [g_xformDirtyFlags]
        mov      ebx, 1
        test     al, bl
        je       L_d7ad
        mov      eax, dword ptr [g_currentNodeIdx]
        xor      ecx, ecx
        mov      dword ptr [g_audioBank2State_00537f98], ebx
        mov      dword ptr [g_xformScratch2088], ecx
        mov      eax, dword ptr [eax*4 + 0x10]
        shr      eax, 0x18
        mov      dword ptr [g_walkCallback], eax
        and      eax, 2
        mov      dword ptr [g_xformScratch94], eax
        je       short L_d55d
        mov      ecx, 0x10
        mov      dword ptr [g_xformScratch2088], ecx
    L_d55d:
        mov      edx, dword ptr [g_baseSel]
        mov      edx, dword ptr [edx*4 + 0x38]
        mov      dword ptr [g_xformEntityIdx], edx
        mov      eax, dword ptr [edx*4 + 0x40]
        mov      esi, eax
        mov      dword ptr [g_walkCallback], eax
        and      esi, 0x20
        mov      dword ptr [g_xformScratch94], esi
        je       short L_d591
        call     DirtyFlagsManip
        pop      esi
        pop      ebx
        ret
    L_d591:
        and      al, 0xef
        or       eax, ecx
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [edx*4 + 0x40], eax
        mov      eax, dword ptr [g_baseSel]
        mov      eax, dword ptr [eax*4 + 0x38]
        mov      dword ptr [g_xformEntityIdx], eax
        mov      eax, dword ptr [eax*4 + 0x40]
        mov      dword ptr [g_eventQueueCurrent], eax
        and      eax, 8
        mov      dword ptr [g_xformScratch94], eax
        jne      L_d6a7
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      edx, OFFSET DualEntryBitFlagDispatch + 0x40
        mov      dword ptr [g_xformEntityIdx], OFFSET MStackChainBit2Cascade
        mov      dword ptr [g_pendingNodeType], edx
        mov      eax, dword ptr [ecx*4 + 0x10]
        shr      eax, 0x18
        mov      dword ptr [g_walkCallback], eax
        and      eax, ebx
        mov      dword ptr [g_xformScratch94], eax
        je       short L_d605
        mov      dword ptr [g_xformEntityIdx], edx
    L_d605:
        mov      eax, dword ptr [g_matrixStackTop]
        inc      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], ecx
        call     dword ptr [g_xformEntityIdx]
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_d7ad
        mov      ecx, dword ptr [g_matrixStackTop]
        mov      eax, dword ptr [ecx*4]
        dec      ecx
        mov      dword ptr [g_matrixStackTop], ecx
        mov      cl, byte ptr [g_xformDirtyFlags]
        test     cl, bl
        mov      dword ptr [g_currentNodeIdx], eax
        je       short L_d6ac
        mov      eax, dword ptr [eax*4 + 0x14]
        push     eax
        push     0x3333
        mov      dword ptr [g_walkCallback], eax
        call     Mul10Tail
        add      esp, 8
        mov      dword ptr [g_walkCallback], eax
        call     SfxAttenuateAndApply
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_d7ad
        mov      eax, dword ptr [g_xformScratch2088]
        test     eax, eax
        je       short L_d6a7
        mov      edx, dword ptr [g_currentNodeIdx]
        xor      ecx, ecx
        mov      dword ptr [g_xformScratch2088], ebx
        mov      cl, byte ptr [edx*4 + 0x12]
        mov      dword ptr [g_walkCallback], ecx
        jmp      short L_d763
    L_d6a7:
        mov      eax, dword ptr [g_currentNodeIdx]
    L_d6ac:
        mov      eax, dword ptr [eax*4 + 0x14]
        mov      dword ptr [g_walkCallback], eax
        call     SfxAttenuateAndApply
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_d7ad
        call     MStackPush3CmpCall
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_d7ad
        test     byte ptr [g_xformDirtyFlags], bl
        je       short L_d6ff
        mov      edx, dword ptr [g_currentNodeIdx]
        xor      ecx, ecx
        mov      dword ptr [g_xformScratch2088], 3
        mov      cl, byte ptr [edx*4 + 0x11]
        jmp      short L_d736
    L_d6ff:
        mov      eax, dword ptr [g_walkCallback]
        test     eax, eax
        je       short L_d71a
        call     PushCjWalkDispatchPop
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_d7ad
    L_d71a:
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      dword ptr [g_xformScratch2088], 2
        mov      ecx, dword ptr [eax*4 + 0x10]
        and      ecx, 0xff
    L_d736:
        mov      edx, dword ptr [g_baseSel]
        mov      dword ptr [g_walkCallback], ecx
        mov      ecx, dword ptr [edx*4 + 0x3c]
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      eax, dword ptr [ecx*4 + 0x7c]
        inc      eax
        mov      dword ptr [g_eventQueueCurrent], eax
        mov      dword ptr [ecx*4 + 0x7c], eax
    L_d763:
        mov      eax, dword ptr [g_matrixStackTop]
        mov      ecx, dword ptr [g_xformScratch2088]
        inc      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], ecx
        call     ScaledLitLoadCall_00480fe0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_d7ad
        mov      eax, dword ptr [g_matrixStackTop]
        mov      edx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      eax, dword ptr [g_xformDirtyFlags]
        or       eax, ebx
        mov      dword ptr [g_xformScratch2088], edx
        mov      dword ptr [g_xformDirtyFlags], eax
    L_d7ad:
        pop      esi
        pop      ebx
        ret
    }
}
