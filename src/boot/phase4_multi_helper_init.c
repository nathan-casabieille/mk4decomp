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

extern unsigned int g_byte_004d5714;
extern unsigned int g_dispatchSave613_004d74d8;
extern unsigned int g_dispatchSave612_004d75a0;
extern unsigned int g_dispatchSave611_004d7610;
extern unsigned int g_dispatchSave95_0053a29c;
extern unsigned int g_phase4HelperSlot_0053a400;
extern void BootSetupWithMStackBody_00418e00(void);
extern void CallSetPause(void);
extern void ClampMulShiftStore_004ba0e0(void);
extern void Helper_MenuStub_8EB0(void);
extern void MStackCall_004062f0(void);
extern void MStackCall_00406600(void);
extern void MStackPop8_004ab860(void);
extern void MStackPush8_004ab790(void);
extern void PushSetXfmMaskCallPop_00407140(void);
extern void ScaledTripleCopy54_004ac040(void);
extern void SetJmp_00408d20(void);
extern void TableWalkBoundedCmp_004bd890(void);

__declspec(naked) void Phase4MultiHelperInit_00418af0(void)
{
    __asm {
        call    MStackPush8_004ab790
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4mh_A_ret
        mov     eax, dword ptr [g_fightGroupHead]
        mov     ecx, offset g_dispatchSave612_004d75a0
        shr     ecx, 2
        mov     dword ptr [g_eventQueueEnd], eax
        mov     dword ptr [g_walkCallback], ecx
        call    PushSetXfmMaskCallPop_00407140
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4mh_A_ret
        test    byte ptr [g_xformDirtyFlags], 4
        jne     L_p4mh_A_tailjmp
        call    SetJmp_00408d20
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4mh_A_ret
        mov     edx, dword ptr [g_xformEntityIdx]
        mov     dword ptr [edx*4 + 0x48], 0x3333
        mov     dword ptr [edx*4 + 0x14], 0xFF
        mov     ecx, dword ptr [edx*4]
        lea     eax, [edx*4]
        or      ecx, 8
        mov     dword ptr [eax], ecx
        mov     ecx, 0x00418BE0
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [eax + 0x10], ecx
        call    ScaledTripleCopy54_004ac040
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4mh_A_ret
        mov     eax, dword ptr [g_fightGroupHead]
        mov     ecx, dword ptr [eax*4 + 0x58]
        add     ecx, 0xFFFE4000
        mov     dword ptr [eax*4 + 0x58], ecx
        mov     eax, dword ptr [g_fightGroupHead]
        mov     ecx, dword ptr [eax*4 + 0x58]
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [g_walkCallback], ecx
        call    MStackCall_00406600
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4mh_A_ret
    L_p4mh_A_tailjmp:
        jmp     MStackPop8_004ab860
    L_p4mh_A_ret:
        ret
        nop
        nop
        nop
        nop
        nop
        nop
    L_p4mh_helperB:
        mov     eax, dword ptr [g_gameMode]
        test    eax, eax
        jne     L_p4mh_B_tail
        mov     ecx, dword ptr [g_xformEntityIdx]
        mov     eax, 0x10000
        mov     dword ptr [g_walkCallback], eax
        sub     eax, dword ptr [ecx*4 + 0x48]
        push    eax
        push    0x1999
        mov     dword ptr [g_walkCallback], eax
        call    Mul10Tail
        mov     ecx, dword ptr [g_xformEntityIdx]
        mov     dword ptr [g_walkCallback], eax
        add     esp, 8
        add     eax, dword ptr [ecx*4 + 0x48]
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x48], eax
    L_p4mh_B_tail:
        jmp     ClampMulShiftStore_004ba0e0
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
    L_p4mh_mainC:
        mov     eax, dword ptr [g_baseSel]
        push    esi
        lea     esi, [eax*4]
        mov     eax, dword ptr [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], 0
        sub     eax, 0
        je      L_p4mh_C_phase0
        dec     eax
        je      L_p4mh_C_phase1
        mov     eax, dword ptr [g_eventQueueEnd]
        mov     ecx, dword ptr [eax*4]
        test    ecx, ecx
        mov     dword ptr [g_walkCallback], ecx
        jne     L_p4mh_C_have_target
        call    CallSetPause
        pop     esi
        ret
    L_p4mh_C_phase1:
        mov     eax, dword ptr [g_phase4HelperSlot_0053a400]
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        je      L_p4mh_C_set_install
        mov     ecx, offset g_dispatchSave611_004d7610
        shr     ecx, 2
        mov     dword ptr [g_walkCallback], ecx
        call    PushSetXfmMaskCallPop_00407140
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4mh_C_exit
        test    byte ptr [g_xformDirtyFlags], 4
        jne     L_p4mh_C_after_init
        call    ScaledTripleCopy54_004ac040
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4mh_C_exit
        mov     edx, dword ptr [g_fightGroupHead]
        mov     eax, 0xFFFFE667
        mov     dword ptr [edx*4 + 0x58], 0x00190000
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x80], eax
        call    MStackCall_004062f0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4mh_C_exit
    L_p4mh_C_after_init:
        mov     dword ptr [g_eventQueueTotal], 6
        mov     dword ptr [g_eventQueueNotMask], 0x003C0000
        call    BootSetupWithMStackBody_00418e00
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4mh_C_exit
    L_p4mh_C_loop:
        mov     ecx, dword ptr [g_eventQueueNotMask]
        mov     eax, dword ptr [g_eventQueueTotal]
        sub     ecx, 0x0009FD70
        dec     eax
        mov     dword ptr [g_eventQueueNotMask], ecx
        mov     dword ptr [g_eventQueueTotal], eax
        js      L_p4mh_C_loop_done
        call    BootSetupWithMStackBody_00418e00
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        je      L_p4mh_C_loop
        pop     esi
        ret
    L_p4mh_C_loop_done:
        mov     eax, offset g_dispatchSave613_004d74d8
        shr     eax, 2
        mov     dword ptr [g_eventQueueEnd], eax
    L_p4mh_C_have_target:
        mov     ecx, dword ptr [eax*4]
        inc     eax
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [g_dispatchSave95_0053a29c], ecx
        mov     dword ptr [g_eventQueueEnd], eax
        mov     edx, dword ptr [eax*4]
        inc     eax
        mov     dword ptr [g_pendingNodeType], edx
        mov     dword ptr [g_eventQueueEnd], eax
        mov     dword ptr [esi + 8], 0x00418C40
        mov     dword ptr [esi + 0x84], 2
        mov     dword ptr [g_framePauseFlag], 1
        pop     esi
        ret
    L_p4mh_C_phase0:
        mov     byte ptr [g_byte_004d5714], 0
        call    Helper_MenuStub_8EB0
        push    7
        call    TableWalkBoundedCmp_004bd890
        add     esp, 4
        push    8
        call    TableWalkBoundedCmp_004bd890
        add     esp, 4
    L_p4mh_C_set_install:
        mov     eax, 1
        mov     dword ptr [esi + 8], 0x00418C40
        mov     dword ptr [esi + 0x84], eax
        mov     dword ptr [g_pendingNodeType], eax
        mov     dword ptr [g_framePauseFlag], eax
    L_p4mh_C_exit:
        pop     esi
        ret
    }
}
