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

extern void BootInstallerPair_004101f0(void);
extern void SetWorkTypeScaledCallStoreCcc_0041aa80(void);
extern void DualCallPauseAddrSetRecurse_00419720(void);
extern void DualCallPauseAddrSetRecurse_00419b60(void);
extern void DualCallPauseAddrSetRecurse_00419aa0(void);
extern void DualCallPauseAddrSetRecurse_004199e0(void);
extern void DualCallPauseAddrSetRecurse_004197e0(void);
extern void DualCallPauseAddrSetRecurse_004198a0(void);
extern void TripleChainTailJmp_00419900(void);
extern void Phase1SlotLinkAndInit_00419470(void);
extern void GuardedScaled_0040cd20(void);
extern void BootOneShotMStackPush3_0040c100(void);
extern void Phase4FourPackedDispatch_0041b900(void);

extern void CallSetPause(void);
extern void FlagThunk4EntryDispatcher(void);

__declspec(naked) void Phase4DispatchMultiInit_0041b610(void)
{
    __asm {
        mov     eax, dword ptr [g_baseSel]
        push    esi
        lea     esi, [eax*4]
        mov     eax, dword ptr [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], 0
        sub     eax, 0
        je      L_p4dmi_A_phase0
        dec     eax
        je      L_p4dmi_A_phase1
        dec     eax
        je      L_p4dmi_A_phase2
        call    BootInstallerPair_004101f0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4dmi_A_exit
        call    SetWorkTypeScaledCallStoreCcc_0041aa80
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4dmi_A_exit
        call    DualCallPauseAddrSetRecurse_00419720
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4dmi_A_exit
        call    DualCallPauseAddrSetRecurse_00419b60
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4dmi_A_exit
        call    DualCallPauseAddrSetRecurse_00419aa0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4dmi_A_exit
        call    DualCallPauseAddrSetRecurse_004199e0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4dmi_A_exit
        call    DualCallPauseAddrSetRecurse_004197e0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4dmi_A_exit
        call    DualCallPauseAddrSetRecurse_004198a0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4dmi_A_exit
        call    TripleChainTailJmp_00419900
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4dmi_A_exit
        call    Phase1SlotLinkAndInit_00419470
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4dmi_A_exit
        mov     ecx, dword ptr [g_baseSel]
        mov     eax, dword ptr [ecx*4 + 4]
        dec     eax
        mov     dword ptr [g_currentNodeIdx], eax
        mov     edx, dword ptr [eax*4]
        mov     dword ptr [g_fightGroupHead], edx
        mov     dword ptr [ecx*4 + 4], eax
        call    StackPopDispatchTagged
        pop     esi
        ret
    L_p4dmi_A_phase2:
        call    GuardedScaled_0040cd20
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4dmi_A_exit
        mov     dword ptr [g_walkCallback], 8
        call    FlagThunk4EntryDispatcher
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4dmi_A_exit
        mov     eax, 1
        mov     dword ptr [esi + 8], 0x0041B610
        mov     dword ptr [esi + 0x84], 3
        mov     dword ptr [g_pendingNodeType], eax
        mov     dword ptr [g_framePauseFlag], eax
        pop     esi
        ret
    L_p4dmi_A_phase1:
        call    GuardedScaled_0040cd20
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4dmi_A_exit
        mov     dword ptr [esi + 8], 0x0041B610
        mov     dword ptr [esi + 0x84], 2
        mov     dword ptr [g_pendingNodeType], 3
        mov     dword ptr [g_framePauseFlag], 1
        pop     esi
        ret
    L_p4dmi_A_phase0:
        mov     eax, dword ptr [g_baseSel]
        mov     edx, dword ptr [g_fightGroupHead]
        mov     ecx, dword ptr [eax*4 + 4]
        lea     eax, [eax*4 + 4]
        mov     dword ptr [g_currentNodeIdx], ecx
        mov     dword ptr [ecx*4], edx
        mov     ecx, dword ptr [g_currentNodeIdx]
        inc     ecx
        mov     dword ptr [g_currentNodeIdx], ecx
        mov     dword ptr [eax], ecx
        mov     eax, dword ptr [g_baseSel]
        mov     ecx, dword ptr [eax*4 + 0x38]
        mov     dword ptr [g_walkCallback], 0
        mov     dword ptr [g_fightGroupHead], ecx
        call    FlagThunk4EntryDispatcher
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4dmi_A_exit
        call    BootOneShotMStackPush3_0040c100
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4dmi_A_exit
        call    BootInstallerPair_004101f0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4dmi_A_exit
        call    GuardedScaled_0040cd20
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4dmi_A_exit
        mov     eax, 1
        mov     dword ptr [esi + 8], 0x0041B610
        mov     dword ptr [esi + 0x84], eax
        mov     dword ptr [g_pendingNodeType], 3
        mov     dword ptr [g_framePauseFlag], eax
    L_p4dmi_A_exit:
        pop     esi
        ret
        nop
        nop
        nop
        nop
    L_p4dmi_B:
        mov     eax, dword ptr [g_baseSel]
        push    esi
        lea     esi, [eax*4]
        mov     eax, dword ptr [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], 0
        test    eax, eax
        je      L_p4dmi_B_phase0
        mov     eax, dword ptr [g_eventQueueEnd]
        dec     eax
        mov     dword ptr [g_eventQueueEnd], eax
        jns     L_p4dmi_B_call
        mov     dword ptr [g_eventQueueNotMask], 1
        call    Phase4FourPackedDispatch_0041b900
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4dmi_B_exit
        call    CallSetPause
        pop     esi
        ret
    L_p4dmi_B_phase0:
        mov     dword ptr [g_eventQueueEnd], 0x14
        mov     dword ptr [g_eventQueueNotMask], 0
    L_p4dmi_B_call:
        call    Phase4FourPackedDispatch_0041b900
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4dmi_B_exit
        mov     eax, 1
        mov     dword ptr [esi + 8], 0x0041B860
        mov     dword ptr [esi + 0x84], eax
        mov     dword ptr [g_pendingNodeType], 2
        mov     dword ptr [g_framePauseFlag], eax
    L_p4dmi_B_exit:
        pop     esi
        ret
    }
}
