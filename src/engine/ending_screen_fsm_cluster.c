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

extern unsigned int g_dispatchSave683_004e5cc0;
extern unsigned int g_dispatchVar43_004e6070;
extern unsigned int g_dispatchVar2_0053a24c;
extern unsigned int g_dispatchVar8_0053a35c;
extern void AudioVolumeRescale(void);
extern void CmpDivJmp(void);
extern void GatedWordPushCall(void);
extern void IK_ChainPoseUpdate(void);
extern void MStackCall_00406600(void);
extern void PushSetXfmMaskCallPop(void);
extern void StoreLoadJmp(void);
extern void Thunk_0049cbc0(void);

__declspec(naked) void EndingScreenFsmCluster(void)
{
    __asm {
        mov      dword ptr [g_walkCallback], 0x200
        call     AudioVolumeRescale
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_44bf
        test     byte ptr [g_xformDirtyFlags], 1
        jne      L_43d0
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      eax, dword ptr [ecx*4 + 0x34]
        or       al, 1
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x34], eax
    L_43d0:
        mov      eax, dword ptr [g_eventQueueEnd]
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      eax, dword ptr [eax*4 + 0x54]
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x54], eax
        mov      edx, dword ptr [g_eventQueueEnd]
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      eax, dword ptr [edx*4 + 0x5c]
        mov      dword ptr [ecx*4 + 0x5c], eax
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      eax, 0xffff999a
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [edx*4 + 0x58], eax
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [g_eventQueueWorkType], 0x3333
        add      ecx, 0x15
        mov      dword ptr [g_currentNodeIdx], ecx
        call     TripleVecAccCallStore
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_44bf
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      dword ptr [g_walkCallback], 0
        sub      eax, 0x15
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4 + 0x6c], 0
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      eax, dword ptr [g_walkCallback]
        mov      dword ptr [ecx*4 + 0x74], eax
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      eax, 0xfffff0a4
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [edx*4 + 0x70], eax
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [g_eventQueueWorkType], 0x20c
        add      ecx, 0x1b
        mov      dword ptr [g_currentNodeIdx], ecx
        call     TripleVecAccCallStore
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_44bf
        sub      dword ptr [g_currentNodeIdx], 0x1b
    L_44bf:
        ret
        mov      eax, dword ptr [g_xformEntityIdx]
        mov      dword ptr [eax*4 + 0x10], 0
        mov      ecx, dword ptr [g_xformEntityIdx]
        mov      eax, OFFSET g_dispatchVar43_004e6070
        shr      eax, 2
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x14], eax
        ret
        nop
        nop
        nop
        nop
        nop
    L_44f0:
        mov      eax, dword ptr [g_baseSel]
        push     esi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        sub      eax, 0
        je       L_4553
        dec      eax
        mov      dword ptr [g_walkCallback], 0x11
        call     GatedWordPushCall
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_4574
        mov      dword ptr [esi + 8], OFFSET L_44f0
        mov      dword ptr [esi + 0x84], 2
        mov      dword ptr [g_pendingNodeType], 0x146
        mov      dword ptr [g_framePauseFlag], 1
        pop      esi
        ret
    L_4553:
        mov      eax, 1
        mov      dword ptr [esi + 8], OFFSET L_44f0
        mov      dword ptr [esi + 0x84], eax
        mov      dword ptr [g_pendingNodeType], 0x43
        mov      dword ptr [g_framePauseFlag], eax
    L_4574:
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
    L_4580:
        mov      eax, dword ptr [g_baseSel]
        push     esi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        test     eax, eax
        je       L_45cd
        mov      ecx, dword ptr [g_baseSel]
        mov      eax, dword ptr [g_eventQueueEnd]
        dec      eax
        mov      edx, dword ptr [ecx*4 + 0x68]
        mov      dword ptr [g_eventQueueEnd], eax
        mov      dword ptr [g_fightGroupHead], edx
        jns      L_46fc
        call     Thunk_0049cbc0
        pop      esi
        ret
    L_45cd:
        mov      eax, dword ptr [g_baseSel]
        mov      ecx, dword ptr [g_eventQueueEnd]
        push     OFFSET L_4770
        mov      dword ptr [eax*4 + 0x64], ecx
        mov      edx, dword ptr [g_baseSel]
        mov      eax, dword ptr [g_eventQueueIdx]
        mov      dword ptr [edx*4 + 0x68], eax
        mov      eax, 0x451e
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [g_dispatchVar2_0053a24c], eax
        call     StoreLoadJmp
        mov      ecx, OFFSET g_dispatchSave683_004e5cc0
        add      esp, 4
        shr      ecx, 2
        mov      dword ptr [g_dispatchVar8_0053a35c], 0
        mov      dword ptr [g_walkCallback], ecx
        call     PushSetXfmMaskCallPop
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_475f
        test     byte ptr [g_xformDirtyFlags], 4
        jne      L_46e6
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      edx, dword ptr [g_eventQueueIdx]
        mov      dword ptr [g_dispatchVar8_0053a35c], ecx
        mov      eax, dword ptr [edx*4 + 0x34]
        and      eax, 1
        mov      dword ptr [g_walkCallback], eax
        mov      edx, dword ptr [ecx*4 + 0x34]
        or       eax, edx
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x34], eax
        mov      eax, dword ptr [g_matrixStackTop]
        mov      ecx, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], ecx
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      eax, dword ptr [edx*4 + 0x18]
        mov      dword ptr [g_walkCallback], 2
        mov      dword ptr [g_currentNodeIdx], eax
        call     CmpDivJmp
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_475f
        mov      eax, dword ptr [g_matrixStackTop]
        mov      ecx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      dword ptr [g_matrixStackTop], eax
        call     MStackCall_00406600
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_475f
    L_46e6:
        mov      edx, dword ptr [g_eventQueueIdx]
        mov      dword ptr [g_eventQueueEnd], 0x2c
        mov      dword ptr [g_fightGroupHead], edx
    L_46fc:
        mov      eax, dword ptr [g_matrixStackTop]
        mov      ecx, dword ptr [g_eventQueueEnd]
        inc      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], ecx
        call     IK_ChainPoseUpdate
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_475f
        mov      eax, dword ptr [g_matrixStackTop]
        mov      edx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_eventQueueEnd], edx
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [esi + 8], OFFSET L_4580
        mov      dword ptr [esi + 0x84], 1
        mov      dword ptr [g_pendingNodeType], 1
        mov      dword ptr [g_framePauseFlag], 1
    L_475f:
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
    L_4770:
        mov      eax, dword ptr [g_baseSel]
        shl      eax, 2
        mov      ecx, dword ptr [eax + 0x84]
        mov      dword ptr [eax + 0x84], 0
        sub      ecx, 0
        je       L_4803
        dec      ecx
        mov      ecx, dword ptr [g_eventQueueEnd]
        je       L_47b3
        dec      ecx
        mov      dword ptr [g_eventQueueEnd], ecx
        jns      L_47c6
        mov      ecx, dword ptr [g_eventQueueIdx]
        dec      ecx
        mov      dword ptr [g_eventQueueIdx], ecx
        jns      L_4817
        jmp      Thunk_0049cbc0
    L_47b3:
        dec      ecx
        mov      dword ptr [g_eventQueueEnd], ecx
        jns      L_4821
        mov      dword ptr [g_eventQueueEnd], 0xa
    L_47c6:
        mov      ecx, dword ptr [g_xformScratch2088]
        mov      edx, dword ptr [g_dispatchVar2_0053a24c]
        add      ecx, edx
        mov      dword ptr [g_walkCallback], ecx
        mov      dword ptr [g_dispatchVar2_0053a24c], ecx
        mov      ecx, 1
        mov      dword ptr [eax + 8], OFFSET L_4770
        mov      dword ptr [eax + 0x84], 2
        mov      dword ptr [g_pendingNodeType], ecx
        mov      dword ptr [g_framePauseFlag], ecx
        ret
    L_4803:
        mov      dword ptr [g_xformScratch2088], 0xa3d
        mov      dword ptr [g_eventQueueIdx], 8
    L_4817:
        mov      dword ptr [g_eventQueueEnd], 0xa
    L_4821:
        mov      ecx, dword ptr [g_dispatchVar2_0053a24c]
        mov      edx, dword ptr [g_xformScratch2088]
        sub      ecx, edx
        mov      dword ptr [g_walkCallback], ecx
        mov      dword ptr [g_dispatchVar2_0053a24c], ecx
        mov      ecx, 1
        mov      dword ptr [eax + 8], OFFSET L_4770
        mov      dword ptr [eax + 0x84], ecx
        mov      dword ptr [g_pendingNodeType], ecx
        mov      dword ptr [g_framePauseFlag], ecx
        ret
    }
}
