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
extern void WalkCbSubMul10_00431d50(void);
extern void Mul10Tail(unsigned int a, unsigned int b);
extern void BootMod6487eClampAndChainMul10(void);
extern void SpawnListBatchLoader_00477710(void);
extern void MStackPush2TableNot(void);
extern void GuardedChainCmpDualBitXor(void);
extern void ScaledLoadDecJmp_00429710(void);
extern void ScaledStoreCurDirtyClear_004296f0(void);
extern void MStackBitmaskIncMod_00492450(void);
extern void MStackBitmaskUpdate_00492510(void);
extern void Push1eCallTestDirtyLoop_004923b0(void);
extern void MStackLoopFieldInit_00492280(void);
extern void TaggedSceneDispatch(void);
extern void CallPauseDirty4StackPushFn_004839d0(void);
extern void CallPauseDirty1JmpDirty4StackPush_00483a80(void);
extern void Cmp2CallDirtyCall(void);
extern void QuadBlockArgInstallChain(void);
extern void InstallSelfChainSet84_80CallW_004363f0(void);
extern void Wrapper_00436490(void);
extern void MoveFsmCluster_004364a0(void);
extern void CallPauseTestByteJmpCalls(void);
extern void InstallSelfFullPath(void);
extern void InstallSelfCountdownChain_0047a950(void);
extern void CopyJmp_0048ef90(void);
extern void DualTestDirtyToggle_004282c0(void);
extern void TripleVecAccCallStore(void);
extern void Thunk_004bd5c0(void);
extern void AllocSlotPushTripleGlobals(void);
extern void MStackPop4Rewrite(void);
extern void Push70CallScaleArith(void);
extern void StreamChainStringInstall(void);
extern void MStackFrameCdeclDouble(void);
extern void ChainTableWalkStore_004917e0(void);
extern void Push16Call(void);
extern void DispatcherComplex260_00407030(void);
extern void ScaledLoadCmpStoreXfm_0048f2a0(void);
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

/*
 * GameInstall2BodyMul10ScaledInit_00475590 - 347b 2-entry game state init.
 *   Entry 0x00475590: g_walkCallback = g_eventQueueEnd[+0x30]; call SetJmp_0049cb90; if paused: ret.
 *     edx = g_currentNodeIdx, eax = g_currentNodeFlags; chain[edx*4 + 0x1c] = eax; push 0x004ec890;
 *     call IterLoad_0048e680; pop; ret.
 *   Body 0x004755d0 (16b-padded): chain = g_baseSel<<2; saved=chain->state; chain->state=0.
 *     If state == 0: setup g_eventQueueWorkType = g_fightGroupHead+0x15; eax = chain[+0x38];
 *       g_currentNodeIdx = eax; g_pendingNodeType = eax+0x15. Call MStackPushMul10TailSqrt; if paused: ret.
 *       g_currentNodeFlags -= g_walkCallback; push (eax, 0x1999); g_xformScratch2088 = eax; Mul10Tail; restore;
 *       g_xformScratch2088 = result; g_eventQueueChild = 0xa. Fall through.
 *     If state == 1: decrement g_eventQueueChild; if !=0 jump to chain-step.
 *     Otherwise install-self at body; chain->state=2; g_pendingNodeType = 0x28; pause=1; ret.
 *     Chain-step: g_currentNodeFlags += g_xformScratch2088; g_eventQueueCurrent = 0; g_walkCallback = g_currentNodeFlags;
 *       call Wrapper_0048ff30; if paused: ret. Install-self; chain->state=1; g_pendingNodeType=1;
 *       pause=1; ret.
 */
extern void IterLoad_0048e680(void);
extern void MStackPushMul10TailSqrt_00424a90(void);
extern void Wrapper_0048ff30(void);

__declspec(naked) void GameInstall2BodyMul10ScaledInit_00475590(void)
{
    __asm
    {
        mov     eax, dword ptr [g_eventQueueEnd]
        mov     ecx, dword ptr [eax*4 + 0x30]
        mov     dword ptr [g_walkCallback], ecx
        call    SetJmp_0049cb90
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_e1_ret
        mov     edx, dword ptr [g_currentNodeIdx]
        mov     eax, dword ptr [g_currentNodeFlags]
        push    0x004ec890
        mov     dword ptr [edx*4 + 0x1c], eax
        call    IterLoad_0048e680
        add     esp, 4
    L_e1_ret:
        ret
    L_body2:
        mov     eax, dword ptr [g_baseSel]
        push    esi
        lea     esi, [eax*4]
        mov     eax, dword ptr [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], 0
        sub     eax, 0
        je      short L_state0
        dec     eax
        jne     short L_install2
        mov     eax, dword ptr [g_eventQueueChild]
        dec     eax
        mov     dword ptr [g_eventQueueChild], eax
        jne     L_chainStep
    L_install2:
        mov     dword ptr [esi + 8], offset L_body2
        mov     dword ptr [esi + 0x84], 2
        mov     dword ptr [g_pendingNodeType], 0x28
        mov     dword ptr [g_framePauseFlag], 1
        pop     esi
        ret
    L_state0:
        mov     ecx, dword ptr [g_baseSel]
        mov     edx, dword ptr [g_fightGroupHead]
        add     edx, 0x15
        mov     eax, dword ptr [ecx*4 + 0x38]
        mov     dword ptr [g_eventQueueWorkType], edx
        mov     dword ptr [g_currentNodeIdx], eax
        add     eax, 0x15
        mov     dword ptr [g_pendingNodeType], eax
        call    MStackPushMul10TailSqrt_00424a90
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_b2_ret
        mov     eax, dword ptr [g_currentNodeFlags]
        mov     ecx, dword ptr [g_walkCallback]
        sub     eax, ecx
        mov     dword ptr [g_currentNodeFlags], ecx
        push    eax
        push    0x1999
        mov     dword ptr [g_xformScratch2088], eax
        call    Mul10Tail
        add     esp, 8
        mov     dword ptr [g_xformScratch2088], eax
        mov     dword ptr [g_eventQueueChild], 0xa
    L_chainStep:
        mov     eax, dword ptr [g_currentNodeFlags]
        mov     ecx, dword ptr [g_xformScratch2088]
        add     eax, ecx
        mov     dword ptr [g_eventQueueCurrent], 0
        mov     dword ptr [g_currentNodeFlags], eax
        mov     dword ptr [g_walkCallback], eax
        call    Wrapper_0048ff30
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_b2_ret
        mov     eax, 1
        mov     dword ptr [esi + 8], offset L_body2
        mov     dword ptr [esi + 0x84], eax
        mov     dword ptr [g_pendingNodeType], eax
        mov     dword ptr [g_framePauseFlag], eax
    L_b2_ret:
        pop     esi
        ret
    }
}
