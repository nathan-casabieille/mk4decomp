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

extern unsigned int g_dispatchSave602_004e5808;
extern void MStackPush1MagicMod2_004244d0(void);
extern void MStackPush3CallChainBit2_004431e0(void);
extern void StoreDoubleNegPauseSubStore(void);

__declspec(naked) void SpawnFreezeProjectileChain_00442530(void)
{
    __asm {
        mov      eax, dword ptr [g_baseSel]
        push     ebx
        push     ebp
        push     esi
        mov      ecx, dword ptr [eax*4 + 0x64]
        push     edi
        mov      dword ptr [g_eventQueueEnd], ecx
        mov      edx, dword ptr [eax*4 + 0x68]
        mov      eax, OFFSET g_dispatchSave602_004e5808
        mov      dword ptr [g_eventQueueIdx], edx
        shr      eax, 2
        mov      dword ptr [g_eventQueueTotal], eax
        mov      eax, dword ptr [eax*4]
        test     eax, eax
        mov      dword ptr [g_walkCallback], eax
        je       L_2734
        mov      ebp, 0x3d7
        mov      edi, 0x1999
        mov      ebx, 0x7ae
    L_2583:
        call     MStackPush3CallChainBit2_004431e0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_2734
        test     byte ptr [g_xformDirtyFlags], 4
        jne      L_2734
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      dword ptr [eax*4 + 0x30], 0x7e
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [ecx*4 + 0x70], 0xffffe148
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [g_walkCallback], ebp
        mov      dword ptr [edx*4 + 0x4c], ebp
        mov      eax, dword ptr [g_eventQueueTotal]
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      eax, dword ptr [eax*4 + 4]
        mov      dword ptr [g_eventQueueWorkType], eax
        mov      edx, dword ptr [ecx*4 + 0x64]
        lea      eax, [eax + edx - 0x4b65f]
        mov      dword ptr [g_eventQueueWorkType], eax
        call     MStackPush1MagicMod2_004244d0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_2734
        mov      ecx, dword ptr [g_eventQueueCurrent]
        push     ecx
        push     0x28f5
        call     Mul10Tail
        mov      edx, dword ptr [g_walkCallback]
        add      esp, 8
        mov      dword ptr [g_eventQueueCurrent], eax
        push     edx
        push     0x28f5
        call     Mul10Tail
        mov      dword ptr [g_walkCallback], eax
        mov      eax, dword ptr [g_fightGroupHead]
        add      esp, 8
        mov      ecx, dword ptr [eax*4 + 0x34]
        mov      eax, dword ptr [g_eventQueueCurrent]
        and      ecx, 1
        mov      dword ptr [g_eventQueueWorkType], ecx
        je       short L_2667
        neg      eax
        mov      dword ptr [g_eventQueueCurrent], eax
    L_2667:
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [edx*4 + 0x6c], eax
        mov      eax, dword ptr [g_walkCallback]
        lea      esi, [edx*4]
        mov      dword ptr [esi + 0x74], eax
        mov      dword ptr [g_walkCallback], edi
        call     StoreDoubleNegPauseSubStore
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_2734
        mov      ecx, dword ptr [g_walkCallback]
        mov      dword ptr [esi + 0x78], ecx
        mov      dword ptr [g_walkCallback], edi
        call     StoreDoubleNegPauseSubStore
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_2734
        mov      edx, dword ptr [g_walkCallback]
        mov      dword ptr [esi + 0x7c], edx
        mov      dword ptr [g_walkCallback], edi
        call     StoreDoubleNegPauseSubStore
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_2734
        mov      eax, dword ptr [g_walkCallback]
        mov      dword ptr [esi + 0x80], eax
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      esi, 0x1b
        mov      dword ptr [g_eventQueueWorkType], ebx
        add      ecx, esi
        mov      dword ptr [g_currentNodeIdx], ecx
        call     TripleVecAccCallStore
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_2734
        mov      eax, dword ptr [g_currentNodeIdx]
        sub      eax, esi
        mov      dword ptr [g_currentNodeIdx], eax
        mov      eax, dword ptr [g_eventQueueTotal]
        add      eax, 9
        mov      dword ptr [g_eventQueueTotal], eax
        mov      eax, dword ptr [eax*4]
        test     eax, eax
        mov      dword ptr [g_walkCallback], eax
        jne      L_2583
    L_2734:
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        ret
    }
}
