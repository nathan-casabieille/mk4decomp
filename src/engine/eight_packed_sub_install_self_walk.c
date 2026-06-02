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
extern void CopyJmp_SlotCmp3way_g_currentNodeIdx(void);
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
extern void GuardedDispatch_InstallSelfDualEsi(void);
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

extern void ArgSarStoreJmp(void);
extern void BootFrameSetup(void);
extern void FiveCallGuardSetTail(void);
extern void MStackPushCallPopDirtyJmp_0042cc90(void);
extern void ScaledChainCmpDispatch(void);
extern void State208cBit0Flag(void);
extern void StateDispatchTable(void);
extern void TwoCallTail_ScaledStore501Set8Jmp_then_Cascade3ChainInit_then_StoreLitRetSet2(void);

__declspec(naked) void EightPackedSubInstallSelfWalk(void)
{
    __asm
    {
        call    FiveCallScaledChainTailJmp
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_eps_sub1_ret
        push    0x4e2fa0
        call    ScaledChainCmpDispatch
        add     esp, 4
    L_eps_sub1_ret:
        ret
        nop
        nop
        nop
        nop
    L_eps_sub2:
        call    MStackPushCallPopDirtyJmp_0042cc90
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_eps_sub2_ret
        call    TwoCallTail_ScaledStore501Set8Jmp_then_Cascade3ChainInit_then_StoreLitRetSet2
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_eps_sub2_ret
        push    0x4e33b8
        call    ArgSarStoreJmp
        add     esp, 4
    L_eps_sub2_ret:
        ret
        nop
        nop
        nop
        nop
        nop
        nop
    L_eps_sub3:
        call    StateDispatchTable
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_eps_sub3_ret
        mov     eax, dword ptr [g_walkCallback]
        mov     dword ptr [g_walkCallback], 0
        mov     dword ptr [g_xformEntityIdx], eax
        call    BootFrameSetup
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_eps_sub3_ret
        jmp     FiveCallGuardSetTail
    L_eps_sub3_ret:
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
    L_eps_sub4:
        call    MStackPushCallPopDirtyJmp_0042cc90
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_eps_sub4_ret
        call    TwoCallTail_ScaledStore501Set8Jmp_then_Cascade3ChainInit_then_StoreLitRetSet2
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_eps_sub4_ret
        push    0x4e2fe0
        call    ArgSarStoreJmp
        add     esp, 4
    L_eps_sub4_ret:
        ret
        nop
        nop
        nop
        nop
        nop
        nop
    L_eps_sub5:
        call    StateDispatchTable
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_eps_sub5_ret
        mov     eax, dword ptr [g_walkCallback]
        mov     dword ptr [g_walkCallback], 0
        mov     dword ptr [g_xformEntityIdx], eax
        call    BootFrameSetup
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_eps_sub5_ret
        jmp     FiveCallGuardSetTail
    L_eps_sub5_ret:
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
    L_eps_sub6:
        call    TwoCallTail_ScaledStore501Set8Jmp_then_Cascade3ChainInit_then_StoreLitRetSet2
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_eps_sub6_ret
        push    0x4e3020
        call    ArgSarStoreJmp
        add     esp, 4
    L_eps_sub6_ret:
        ret
        nop
        nop
        nop
        nop
    L_eps_sub7:
        call    State208cBit0Flag
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_eps_sub7_ret
        test    byte ptr [g_xformDirtyFlags], 1
        je      short L_eps_sub7_skipCall
        call    PendingMatch_0042b930
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_eps_sub7_ret
    L_eps_sub7_skipCall:
        push    0x4e3048
        call    ArgSarStoreJmp
        add     esp, 4
    L_eps_sub7_ret:
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
    L_eps_sub8:
        mov     eax, dword ptr [g_baseSel]
        push    esi
        lea     esi, [eax*4]
        mov     eax, dword ptr [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], 0
        test    eax, eax
        je      short L_eps_sub8_phase0
        call    FiveCallGuardSetTail
        pop     esi
        ret
    L_eps_sub8_phase0:
        call    StateDispatchTable
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_eps_sub8_ret
        mov     ecx, dword ptr [g_walkCallback]
        mov     dword ptr [g_walkCallback], 0
        mov     dword ptr [g_xformEntityIdx], ecx
        call    BootFrameSetup
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_eps_sub8_ret
        mov     eax, 1
        mov     dword ptr [esi + 8], offset L_eps_sub8
        mov     dword ptr [esi + 0x84], eax
        mov     dword ptr [g_pendingNodeType], eax
        mov     dword ptr [g_framePauseFlag], eax
    L_eps_sub8_ret:
        pop     esi
        ret
    }
}
