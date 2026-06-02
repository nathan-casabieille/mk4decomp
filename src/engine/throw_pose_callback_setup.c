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

extern unsigned int g_dispatchSave779_004f1300;
extern void ClampMulShiftStore(void);
extern void FramePauseScaledStore_00406c10(void);
extern void MStackBracket4_ListInsertZeroFill(void);
extern void MStackPush2ChainPrepend_00409970(void);
extern void MStackPush3LinkedListWalk(void);
extern void MStackPushComplexCallPop_00406430(void);
extern void ScaledOrStore_004903d0(void);

__declspec(naked) void ThrowPoseCallbackSetup_00491f10(void)
{
    __asm {
        mov      eax, dword ptr [g_walkCallback]
        push     ebx
        lea      ecx, [eax*4]
        mov      eax, OFFSET g_dispatchSave779_004f1300
        shr      eax, 2
        add      eax, ecx
        mov      dword ptr [g_walkCallback], ecx
        mov      dword ptr [g_pendingNodeType], eax
        mov      ecx, dword ptr [eax*4]
        inc      eax
        mov      dword ptr [g_xformEntityIdx], ecx
        mov      dword ptr [g_pendingNodeType], eax
        call     DispatcherComplex260_00407030
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_2131
        mov      al, byte ptr [g_xformDirtyFlags]
        mov      bl, 4
        test     al, bl
        jne      L_2131
        call     MStackPushComplexCallPop_00406430
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_2131
        mov      eax, dword ptr [g_eventQueueCurrent]
        mov      edx, dword ptr [g_currentNodeIdx]
        test     eax, eax
        mov      dword ptr [g_fightGroupHead], edx
        mov      dword ptr [g_walkCallback], eax
        je       short L_1fa4
        call     ScaledOrStore_004903d0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_2131
    L_1fa4:
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      ecx, dword ptr [eax*4 + 0x18]
        mov      eax, dword ptr [g_pendingNodeType]
        mov      dword ptr [g_eventQueueTotal], ecx
        mov      edx, dword ptr [eax*4]
        inc      eax
        mov      dword ptr [g_xformEntityIdx], edx
        mov      dword ptr [g_pendingNodeType], eax
        call     FramePauseScaledStore_00406c10
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_2131
        test     byte ptr [g_xformDirtyFlags], bl
        jne      L_2131
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      dword ptr [eax*4 + 0x1c], 2
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      eax, 0x1999
        mov      dword ptr [ecx*4 + 0x30], 0xfff70000
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [edx*4 + 0x34], 0xd0000
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x38], eax
        mov      edx, dword ptr [g_eventQueueTotal]
        mov      dword ptr [g_xformEntityIdx], edx
        call     MStackPush2ChainPrepend_00409970
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_2131
        mov      eax, dword ptr [g_pendingNodeType]
        mov      ecx, dword ptr [eax*4]
        inc      eax
        mov      dword ptr [g_pendingNodeType], eax
        mov      eax, dword ptr [g_eventQueueWorkType]
        push     ecx
        push     eax
        mov      dword ptr [g_walkCallback], ecx
        call     Mul10Tail
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      dword ptr [g_walkCallback], eax
        add      esp, 8
        mov      dword ptr [ecx*4 + 0x54], eax
        mov      eax, dword ptr [g_pendingNodeType]
        mov      edx, dword ptr [g_fightGroupHead]
        mov      ecx, dword ptr [eax*4]
        inc      eax
        mov      dword ptr [g_walkCallback], ecx
        mov      dword ptr [g_pendingNodeType], eax
        mov      dword ptr [edx*4 + 0x58], ecx
        mov      eax, dword ptr [g_fightGroupHead]
        mov      dword ptr [g_currentNodeIdx], eax
        call     MStackBracket4_ListInsertZeroFill
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_2131
        test     byte ptr [g_xformDirtyFlags], bl
        jne      short L_2131
        call     MStackPush3LinkedListWalk
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_2131
        test     byte ptr [g_xformDirtyFlags], bl
        jne      short L_2131
        mov      dword ptr [g_walkCallback], 2
        call     ChainDirtyBitWalker
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_2131
        mov      ecx, dword ptr [g_xformEntityIdx]
        mov      eax, OFFSET ClampMulShiftStore
        mov      dword ptr [ecx*4 + 0x14], 0x40
        mov      edx, dword ptr [g_xformEntityIdx]
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [edx*4 + 0x10], eax
        mov      eax, dword ptr [g_fightGroupHead]
        mov      dword ptr [g_xformEntityIdx], eax
    L_2131:
        pop      ebx
        ret
    }
}
