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

extern unsigned int g_phase4SlotArr4_0050b3d4;
extern unsigned int g_phase4SlotArr3_0050b3f0;
extern unsigned int g_segPoseArr_0050b40c;
extern unsigned int g_phase4SlotArr2_0050b428;
extern void SetJmp_00405420(void);
extern void Vec3SetupQuadrupleMul10Sub_00442bc0(void);

__declspec(naked) void FourSegmentPoseWalk_00442880(void)
{
    __asm {
        mov      eax, dword ptr [g_baseSel]
        push     ebx
        push     esi
        mov      eax, dword ptr [eax*4 + 0x68]
        mov      dword ptr [g_eventQueueIdx], eax
        mov      dword ptr [g_fightGroupHead], eax
        call     MStackPush2RunCountdown
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_2bb9
        call     MStackBracket7_DispatchAndChain
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_2bb9
        mov      dword ptr [g_walkCallback], 0xa
        call     ChainDirtyBitWalker
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_2bb9
        mov      ecx, dword ptr [g_xformEntityIdx]
        mov      dword ptr [g_walkCallback], 9
        mov      dword ptr [g_eventQueueEnd], ecx
        call     ChainDirtyBitWalker
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_2bb9
        mov      edx, dword ptr [g_xformEntityIdx]
        mov      ecx, dword ptr [g_eventQueueEnd]
        mov      eax, dword ptr [edx*4 + 0x3c]
        mov      dword ptr [g_walkCallback], eax
        mov      ebx, dword ptr [ecx*4 + 0x3c]
        add      eax, ebx
        sar      eax, 1
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x3c], eax
        mov      eax, dword ptr [g_xformEntityIdx]
        mov      ecx, dword ptr [g_eventQueueEnd]
        mov      eax, dword ptr [eax*4 + 0x40]
        mov      dword ptr [g_walkCallback], eax
        mov      edx, dword ptr [ecx*4 + 0x40]
        add      eax, edx
        sar      eax, 1
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x40], eax
        mov      ecx, dword ptr [g_xformEntityIdx]
        mov      eax, dword ptr [ecx*4 + 0x44]
        mov      ecx, dword ptr [g_eventQueueEnd]
        mov      dword ptr [g_walkCallback], eax
        add      eax, dword ptr [ecx*4 + 0x44]
        sar      eax, 1
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x44], eax
        mov      dword ptr [g_eventQueueIdx], 2
        call     SetJmp_00405420
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_2bb9
        mov      al, byte ptr [g_xformDirtyFlags]
        mov      ebx, 4
        test     al, bl
        jne      short L_29be
        mov      dword ptr [g_eventQueueIdx], 1
    L_29be:
        mov      esi, OFFSET g_phase4SlotArr4_0050b3d4
        shr      esi, 2
        mov      dword ptr [g_xformEntityIdx], esi
        call     DispatcherComplex260_00407030
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_2bb9
    L_29de:
        test     byte ptr [g_xformDirtyFlags], bl
        jne      L_2bb9
        call     Vec3SetupQuadrupleMul10Sub_00442bc0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_2bb9
        mov      eax, dword ptr [g_eventQueueIdx]
        dec      eax
        mov      dword ptr [g_eventQueueIdx], eax
        js       short L_2a20
        mov      dword ptr [g_xformEntityIdx], esi
        call     DispatcherComplex260_00407030
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        je       short L_29de
        pop      esi
        pop      ebx
        ret
    L_2a20:
        mov      dword ptr [g_eventQueueIdx], 3
        call     SetJmp_00405420
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_2bb9
        test     byte ptr [g_xformDirtyFlags], bl
        jne      short L_2a4e
        mov      dword ptr [g_eventQueueIdx], 1
    L_2a4e:
        mov      esi, OFFSET g_phase4SlotArr3_0050b3f0
        shr      esi, 2
        mov      dword ptr [g_xformEntityIdx], esi
        call     DispatcherComplex260_00407030
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_2bb9
    L_2a6e:
        test     byte ptr [g_xformDirtyFlags], bl
        jne      L_2bb9
        call     Vec3SetupQuadrupleMul10Sub_00442bc0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_2bb9
        mov      eax, dword ptr [g_eventQueueIdx]
        dec      eax
        mov      dword ptr [g_eventQueueIdx], eax
        js       short L_2ab0
        mov      dword ptr [g_xformEntityIdx], esi
        call     DispatcherComplex260_00407030
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        je       short L_2a6e
        pop      esi
        pop      ebx
        ret
    L_2ab0:
        mov      dword ptr [g_eventQueueIdx], ebx
        call     SetJmp_00405420
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_2bb9
        test     byte ptr [g_xformDirtyFlags], bl
        jne      short L_2ada
        mov      dword ptr [g_eventQueueIdx], 2
    L_2ada:
        mov      esi, OFFSET g_segPoseArr_0050b40c
        shr      esi, 2
        mov      dword ptr [g_xformEntityIdx], esi
        call     DispatcherComplex260_00407030
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_2bb9
    L_2afa:
        test     byte ptr [g_xformDirtyFlags], bl
        jne      L_2bb9
        call     Vec3SetupQuadrupleMul10Sub_00442bc0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_2bb9
        mov      eax, dword ptr [g_eventQueueIdx]
        dec      eax
        mov      dword ptr [g_eventQueueIdx], eax
        js       short L_2b3c
        mov      dword ptr [g_xformEntityIdx], esi
        call     DispatcherComplex260_00407030
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        je       short L_2afa
        pop      esi
        pop      ebx
        ret
    L_2b3c:
        mov      dword ptr [g_eventQueueIdx], 3
        call     SetJmp_00405420
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_2bb9
        test     byte ptr [g_xformDirtyFlags], bl
        jne      short L_2b66
        mov      dword ptr [g_eventQueueIdx], 1
    L_2b66:
        mov      esi, OFFSET g_phase4SlotArr2_0050b428
        shr      esi, 2
        mov      dword ptr [g_xformEntityIdx], esi
        call     DispatcherComplex260_00407030
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_2bb9
    L_2b82:
        test     byte ptr [g_xformDirtyFlags], bl
        jne      short L_2bb9
        call     Vec3SetupQuadrupleMul10Sub_00442bc0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_2bb9
        mov      eax, dword ptr [g_eventQueueIdx]
        dec      eax
        mov      dword ptr [g_eventQueueIdx], eax
        js       short L_2bb9
        mov      dword ptr [g_xformEntityIdx], esi
        call     DispatcherComplex260_00407030
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        je       short L_2b82
    L_2bb9:
        pop      esi
        pop      ebx
        ret
    }
}
