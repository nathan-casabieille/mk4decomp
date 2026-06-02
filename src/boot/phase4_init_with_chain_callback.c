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

extern unsigned int g_const_0049db40;
extern unsigned int g_dispatchSave617_004d62a8;
extern unsigned int g_phaseChainArr2_004d62e8;
extern unsigned int g_alarmTriState_0053813c;
extern void CallSetPause(void);
extern void LinkedListFieldAdd_0049d450(void);
extern void MStackCall_00406600(void);
extern void MStackCall_00406740(void);
extern void MStackPop8_004ab860(void);
extern void MStackPush8_004ab790(void);
extern void MStackPushNegMul10Var_0040a730(void);
extern void MStackPushZeroCallPop_004066f0(void);
extern void StackPushAdd15CallPop_0040a7e0(void);
extern void StoreDoubleNegPauseSubStore_004ab750(void);
extern void ZeroThreeFields_0040a8b0(void);

__declspec(naked) void Phase4InitWithChainCallback_0040e860(void)
{
    __asm {
        call    MStackPush8_004ab790
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4iwcc_A_ret
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_eventQueueNotMask]
        inc     eax
        push    0xC0
        mov     dword ptr [g_matrixStackTop], eax
        push    offset g_const_0049db40
        mov     dword ptr [eax*4], ecx
        mov     edx, dword ptr [g_fightGroupHead]
        mov     eax, offset g_phaseChainArr2_004d62e8
        mov     dword ptr [g_eventQueueEnd], edx
        shr     eax, 2
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [g_alarmTriState_0053813c], eax
        mov     eax, offset g_dispatchSave617_004d62a8
        mov     dword ptr [g_eventQueueNotMask], 0xC1
        shr     eax, 2
        mov     dword ptr [g_eventQueueIdx], eax
        call    StoreTwoCall
        mov     al, byte ptr [g_xformDirtyFlags]
        add     esp, 8
        test    al, 1
        jne     L_p4iwcc_A_pop_tail
        call    StackPushAdd15CallPop_0040a7e0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4iwcc_A_ret
        call    ZeroThreeFields_0040a8b0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4iwcc_A_ret
    L_p4iwcc_A_pop_tail:
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [eax*4]
        dec     eax
        mov     dword ptr [g_eventQueueNotMask], ecx
        mov     dword ptr [g_matrixStackTop], eax
        jmp     MStackPop8_004ab860
    L_p4iwcc_A_ret:
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
    L_p4iwcc_B:
        mov     eax, dword ptr [g_baseSel]
        push    esi
        lea     esi, [eax*4]
        mov     eax, dword ptr [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], 0
        test    eax, eax
        je      L_p4iwcc_B_phase0
        call    MStackCall_00406740
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4iwcc_B_exit
        call    CallSetPause
        pop     esi
        ret
    L_p4iwcc_B_phase0:
        mov     ecx, dword ptr [g_alarmTriState_0053813c]
        mov     edx, dword ptr [g_fightGroupHead]
        mov     eax, 0x5C
        mov     dword ptr [g_xformEntityIdx], ecx
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [edx*4 + 0x30], eax
        mov     eax, dword ptr [g_fightGroupHead]
        mov     dword ptr [g_currentNodeIdx], eax
        call    MStackPushZeroCallPop_004066f0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4iwcc_B_exit
        call    MStackCall_00406600
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4iwcc_B_exit
        mov     dword ptr [g_eventQueueNotMask], 0x2E14
        mov     dword ptr [g_walkCallback], 0x4CCC
        call    StoreDoubleNegPauseSubStore_004ab750
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4iwcc_B_exit
        mov     eax, dword ptr [g_walkCallback]
        mov     ecx, dword ptr [g_eventQueueNotMask]
        add     eax, 0x10000
        push    ecx
        push    eax
        mov     dword ptr [g_walkCallback], eax
        call    Mul10Tail
        mov     edx, dword ptr [g_xformEntityIdx]
        add     esp, 8
        mov     dword ptr [g_eventQueueNotMask], eax
        mov     ecx, dword ptr [edx*4]
        push    ecx
        push    eax
        call    Mul10Tail
        mov     ecx, dword ptr [g_xformEntityIdx]
        mov     edx, dword ptr [g_fightGroupHead]
        add     esp, 8
        inc     ecx
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [g_xformEntityIdx], ecx
        mov     dword ptr [edx*4 + 0x70], eax
        mov     eax, dword ptr [g_xformEntityIdx]
        mov     edx, dword ptr [g_eventQueueNotMask]
        mov     ecx, dword ptr [eax*4]
        push    ecx
        push    edx
        call    Mul10Tail
        mov     ecx, dword ptr [g_xformEntityIdx]
        add     esp, 8
        inc     ecx
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [g_xformEntityIdx], ecx
        call    MStackPushNegMul10Var_0040a730
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4iwcc_B_exit
        mov     eax, dword ptr [g_fightGroupHead]
        mov     ecx, dword ptr [g_walkCallback]
        mov     dword ptr [eax*4 + 0x6C], ecx
        mov     edx, dword ptr [g_fightGroupHead]
        mov     eax, dword ptr [g_eventQueueCurrent]
        mov     dword ptr [edx*4 + 0x74], eax
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     edx, dword ptr [ecx*4 + 0x18]
        mov     ecx, dword ptr [g_xformEntityIdx]
        mov     dword ptr [g_currentNodeIdx], edx
        mov     eax, dword ptr [ecx*4]
        neg     eax
        inc     ecx
        add     eax, 0x4B5C2
        mov     dword ptr [g_xformEntityIdx], ecx
        mov     dword ptr [g_alarmTriState_0053813c], ecx
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [edx*4 + 0x44], eax
        mov     edx, dword ptr [g_currentNodeIdx]
        mov     eax, dword ptr [edx*4 + 0x28]
        mov     dword ptr [g_xformEntityIdx], eax
        mov     ecx, dword ptr [eax*4]
        or      ecx, 8
        mov     dword ptr [eax*4], ecx
        mov     eax, dword ptr [g_xformEntityIdx]
        mov     dword ptr [eax*4 + 0x48], 0x4000
        mov     ecx, dword ptr [g_xformEntityIdx]
        mov     eax, 0x0040E840
        mov     dword ptr [ecx*4 + 0x14], 0xFF
        mov     edx, dword ptr [g_xformEntityIdx]
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [edx*4 + 0x10], eax
        mov     eax, dword ptr [g_currentNodeIdx]
        mov     edx, dword ptr [g_fightGroupHead]
        mov     ecx, dword ptr [eax*4 + 0x2C]
        add     edx, 0x1B
        mov     dword ptr [g_currentNodeIdx], ecx
        mov     dword ptr [g_xformEntityIdx], edx
        call    LinkedListFieldAdd_0049d450
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4iwcc_B_exit
        mov     eax, 1
        mov     dword ptr [esi + 8], 0x0040E920
        mov     dword ptr [esi + 0x84], eax
        mov     dword ptr [g_pendingNodeType], 0x19
        mov     dword ptr [g_framePauseFlag], eax
    L_p4iwcc_B_exit:
        pop     esi
        ret
    }
}
