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

extern unsigned int g_loaded_004f3608;
extern unsigned int g_clamp_0053a6dc;
extern unsigned int g_clamp_00537f2c;
extern void Thunk_0049cbd0(void);
extern void CallSetPause(void);
extern void StageEntityInitCluster(void);

extern unsigned int g_dst_00537ea4;
extern unsigned int g_dst_0053a6e0;

__declspec(naked) void TriDispatchSetupChain(void)
{
    __asm
    {
        mov     eax, dword ptr [g_dst_0053a6e0]
        mov     ecx, dword ptr [g_loaded_004f3608]
        cmp     eax, ecx
        mov     dword ptr [g_walkCallback], eax
        je      L_tdsc_ret
        mov     eax, dword ptr [g_dst_00537ea4]
        cmp     eax, ecx
        mov     dword ptr [g_walkCallback], eax
        je      L_tdsc_ret
        mov     eax, dword ptr [g_clamp_0053a6dc]
        mov     dword ptr [g_eventQueueWorkType], 0x26
        test    eax, eax
        mov     dword ptr [g_pendingNodeType], offset L_tdsc_sub2
        mov     dword ptr [g_walkCallback], eax
        jne     short L_tdsc_a1
        mov     dword ptr [g_eventQueueNotMask], 1
        call    AllocNode
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_tdsc_ret
    L_tdsc_a1:
        mov     eax, dword ptr [g_clamp_00537f2c]
        mov     dword ptr [g_pendingNodeType], offset L_tdsc_sub3
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        jne     short L_tdsc_a2
        mov     dword ptr [g_eventQueueChild], 1
        call    AllocNode
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_tdsc_ret
    L_tdsc_a2:
        mov     eax, dword ptr [g_eventQueueNotMask]
        mov     dword ptr [g_xformEntityIdx], 0x421830
        test    eax, eax
        jne     short L_tdsc_a3
        mov     eax, dword ptr [g_eventQueueChild]
        test    eax, eax
        je      short L_tdsc_a4
        mov     eax, dword ptr [g_gtPlayerProbe2]
        mov     dword ptr [g_currentNodeIdx], eax
        mov     eax, dword ptr [eax*4 + 0x74]
        cmp     eax, 0x2012
        mov     dword ptr [g_walkCallback], eax
        je      short L_tdsc_a3
        call    Thunk_0049cbd0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_tdsc_ret
    L_tdsc_a3:
        mov     eax, dword ptr [g_eventQueueChild]
        test    eax, eax
        jne     short L_tdsc_ret
    L_tdsc_a4:
        mov     eax, dword ptr [g_eventQueueNotMask]
        test    eax, eax
        je      short L_tdsc_ret
        mov     eax, dword ptr [g_gtPlayerProbe1]
        mov     dword ptr [g_currentNodeIdx], eax
        mov     eax, dword ptr [eax*4 + 0x74]
        cmp     eax, 0x2012
        mov     dword ptr [g_walkCallback], eax
        je      short L_tdsc_ret
        jmp     Thunk_0049cbd0
    L_tdsc_ret:
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
    L_tdsc_sub2:
        mov     eax, dword ptr [g_player2NodeIdx]
        mov     ecx, dword ptr [g_gtPlayerProbe1]
        mov     edx, dword ptr [g_player1NodeIdx]
        mov     dword ptr [g_currentNodeIdx], eax
        test    eax, eax
        mov     dword ptr [g_xformEntityIdx], ecx
        mov     dword ptr [g_fightGroupHead], edx
        je      short L_tdsc_sub2_fall
        test    ecx, ecx
        je      short L_tdsc_sub2_fall
        test    edx, edx
        je      short L_tdsc_sub2_fall
        jmp     StageEntityInitCluster
    L_tdsc_sub2_fall:
        jmp     CallSetPause
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
    L_tdsc_sub3:
        mov     eax, dword ptr [g_player1NodeIdx]
        mov     ecx, dword ptr [g_gtPlayerProbe2]
        mov     edx, dword ptr [g_player2NodeIdx]
        mov     dword ptr [g_currentNodeIdx], eax
        test    eax, eax
        mov     dword ptr [g_xformEntityIdx], ecx
        mov     dword ptr [g_fightGroupHead], edx
        je      short L_tdsc_sub3_fall
        test    ecx, ecx
        je      short L_tdsc_sub3_fall
        test    edx, edx
        je      short L_tdsc_sub3_fall
        jmp     StageEntityInitCluster
    L_tdsc_sub3_fall:
        jmp     CallSetPause
    }
}
