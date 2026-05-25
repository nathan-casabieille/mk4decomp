/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;
extern unsigned int g_baseSel_00542060;
extern unsigned int g_acc_00542078;
extern unsigned int g_cj_0054205c;
extern unsigned int g_gameCountdown_0053a718;
extern unsigned int g_xformScratch94;
extern unsigned int g_table_00535ddc;
extern unsigned int g_active_00537e88;
extern unsigned int g_active_0053a408;
extern unsigned int g_audioBankSel_00537f94;

extern void StoreTwoCall_0049cb40(int, int);
extern void SetJmp_0049cb90(void);
extern void Thunk_0049cbd0(void);
extern void ScaledZeroFour_00490740(void);
extern void WalkCbSubMul10_00431d50(void);
extern void Mul10Tail_00404af0(unsigned int a, unsigned int b);
extern void BootMod6487eClampAndChainMul10_00407510(void);
extern void SpawnListBatchLoader_00477710(void);
extern void MStackPush2TableNot_00426230(void);
extern void GuardedChainCmpDualBitXor_004299a0(void);
extern void ScaledLoadDecJmp_00429710(void);
extern void ScaledStoreCurDirtyClear_004296f0(void);
extern void MStackBitmaskIncMod_00492450(void);
extern void MStackBitmaskUpdate_00492510(void);
extern void Push1eCallTestDirtyLoop_004923b0(void);
extern void MStackLoopFieldInit_00492280(void);
extern void TaggedSceneDispatch_004be690(void);
extern void CallPauseDirty4StackPushFn_004839d0(void);
extern void CallPauseDirty1JmpDirty4StackPush_00483a80(void);
extern void Cmp2CallDirtyCall_004398b0(void);
extern void QuadBlockArgInstallChain_0043a950(void);
extern void InstallSelfChainSet84_80CallW_004363f0(void);
extern void Wrapper_00436490(void);
extern void MoveFsmCluster_004364a0(void);
extern void CallPauseTestByteJmpCalls_004390f0(void);
extern void InstallSelfFullPath_0047a840(void);
extern void InstallSelfCountdownChain_0047a950(void);
extern void CopyJmp_0048ef90(void);
extern void DualTestDirtyToggle_004282c0(void);
extern void TripleVecAccCallStore_00476880(void);
extern void Thunk_004bd5c0(void);
extern void AllocSlotPushTripleGlobals_00427470(void);
extern void MStackPop4Rewrite_004274f0(void);
extern void Push70CallScaleArith_00457ad0(void);
extern void StreamChainStringInstall_00457900(void);
extern void MStackFrameCdeclDouble_004903f0(void);
extern void ChainTableWalkStore_004917e0(void);
extern void Push16Call_00489f50(void);
extern void DispatcherComplex260_00407030(void);
extern void ScaledLoadCmpStoreXfm_0048f2a0(void);
extern void StackPopDispatchTagged_0041f780(void);
extern unsigned int g_cj_00542058;
extern unsigned int g_rangeSqLimit_0053a180;
extern unsigned int g_zero_00541fa4;
extern unsigned int g_zero_00541fa8;
extern unsigned int g_dualBitGate_0053a7b0;
extern unsigned int g_eventArmReload_0053a770;
extern unsigned int g_rangeBase_0053a46c;

extern void ScaledArrStore_004298c0(void);
extern void DualFieldAddSubStore_00470340(void);
extern void IterStepDualStore_00490b40(int);
extern void ScaledXorStore_004900f0(void);
extern void ChainWalkInstall_0049b7c0(void);
extern void FpuSqrtMul_004ab350(void);
extern void PendingMatch_0042b930(void);
extern void MStackPush2RunCountdown_004089e0(void);
extern void MStackBracket7_DispatchAndChain_004b8fa0(void);
extern void MStackBracketed3StoreCall_00475990(void);
extern void ChainDirtyBitWalker_00408c10(void);
extern void Wrapper_0048a350(void);
extern void Wrapper_0048a3a0(void);
extern void Helper_DownloadSetup(void);
extern void MStackPush3CmpCall_0048eec0(void);
extern void Wrapper_0048ec20(void);
extern void FiveCallScaledChainTailJmp_0045f8d0(void);
extern void SetJmp_00438f50(void);
extern void SetJmp_00438f60(void);
extern void GuardedDispatch_0042b6c0(void);
extern void MStackPushZeroCallPop_00407d00(void);
extern void DirtyToggleByGate_0048f350(void);
extern void GameDispatchValidateState_004339c0(void);
extern void CrouchAttackFsmCluster_0046f7a0(void);
extern void MStackPushVec3Mul10_004767e0(void);
extern void LiteralPushCallEntZero_00488c00(void);
extern void LeaPlus22StoreSelf_0048e4d0(void);
extern void IterLoad_00491050(void);
extern void GuardedDualConst2AndToggle_0048eba0(void);
extern void CallPauseScaledStorePushCall_0045fca0(void);
extern void LoadGeoAsset_Default(void);
extern void DispatcherComplex260_00407400(void);
extern void PushSetCallPop_00406530(void);
extern unsigned int g_stateCountdown_0053a3c0;
extern unsigned int g_installOwnerNode_00535cf8;
extern unsigned int g_cj_00542054;
extern unsigned int g_audioBoundNode_005437f0;
extern unsigned int g_lastGatedValue_00543598;
extern unsigned int g_lastGatedTick_0054358c;
extern unsigned int g_fightAxisNegX_00535e70;
extern unsigned int g_fightAxisNegY_00535e74;
extern unsigned int g_fightAxisPosX_00535e78;
extern unsigned int g_fightAxisPosY_00535e7c;

extern unsigned int g_dispatchSave117_00522308;
extern unsigned int g_dispatchSave116_00522310;
extern unsigned int g_crtLocaleEnvVarTbl_00522314;
extern unsigned int g_dispatchSave115_00522318;
extern unsigned int g_crtTlsSlot_00522400;
extern unsigned int g_data_00f9f8c0;
extern unsigned int g_byte_00f9f8c1;
extern unsigned int g_data_00f9fac8;
extern unsigned int g_data_00f9facc;
extern unsigned int g_data_00f9fad0;
extern unsigned int g_data_00f9fad4;
extern unsigned int g_data_00f9fad8;
extern unsigned int g_data_00f9fadc;
extern unsigned int g_data_00fa0dc4;
extern unsigned int g_iat_004d2114;
extern void BuildCharacterCaseTables_004c9840(void);
extern void CRTSignalDispatch_004c9750(void);
extern void InitGlobalsAndZero_004c9800(void);
extern void Lock_004c6f50(void);
extern void TableLookupIatCall_004c6fd0(void);
extern void TranslateMsgId_004c97a0(void);

extern unsigned int g_dispatchSave114_00522320;

__declspec(naked) void CrtSetlocaleInstaller_004c9520(void)
{
    __asm {
        sub      esp, 0x14
        push     ebx
        push     ebp
        push     esi
        push     edi
        push     0x19
        call     Lock_004c6f50
        mov      eax, dword ptr [esp + 0x2c]
        add      esp, 4
        push     eax
        call     CRTSignalDispatch_004c9750
        mov      ecx, eax
        mov      eax, dword ptr [g_data_00f9fac8]
        add      esp, 4
        cmp      ecx, eax
        mov      dword ptr [esp + 0x28], ecx
        jne      short L_9561
        push     0x19
        call     TableLookupIatCall_004c6fd0
        add      esp, 4
        xor      eax, eax
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        add      esp, 0x14
        ret
    L_9561:
        test     ecx, ecx
        jne      short L_9583
        call     InitGlobalsAndZero_004c9800
        call     BuildCharacterCaseTables_004c9840
        push     0x19
        call     TableLookupIatCall_004c6fd0
        add      esp, 4
        xor      eax, eax
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        add      esp, 0x14
        ret
    L_9583:
        xor      edx, edx
        mov      eax, OFFSET g_dispatchSave116_00522310
    L_958a:
        cmp      dword ptr [eax], ecx
        je       L_96a0
        add      eax, 0x30
        inc      edx
        cmp      eax, OFFSET g_crtTlsSlot_00522400
        jb       short L_958a
        lea      edx, [esp + 0x10]
        push     edx
        push     ecx
        call     dword ptr [g_iat_004d2114]
        mov      esi, 1
        cmp      eax, esi
        jne      L_9664
        mov      ecx, 0x40
        xor      eax, eax
        mov      edi, OFFSET g_data_00f9f8c0
        rep stosd
        mov      ecx, dword ptr [esp + 0x10]
        stosb
        mov      edi, dword ptr [esp + 0x28]
        xor      eax, eax
        cmp      ecx, esi
        mov      dword ptr [g_data_00f9fac8], edi
        mov      dword ptr [g_data_00f9facc], eax
        jbe      short L_964c
        mov      al, byte ptr [esp + 0x16]
        test     al, al
        je       short L_961d
        lea      edx, [esp + 0x17]
    L_95ea:
        mov      cl, byte ptr [edx]
        test     cl, cl
        je       short L_961d
        xor      eax, eax
        and      ecx, 0xff
        mov      al, byte ptr [edx - 1]
        cmp      eax, ecx
        ja       short L_9613
    L_95ff:
        mov      bl, byte ptr [eax + g_byte_00f9f8c1]
        or       bl, 4
        mov      byte ptr [eax + g_byte_00f9f8c1], bl
        inc      eax
        cmp      eax, ecx
        jbe      short L_95ff
    L_9613:
        mov      al, byte ptr [edx + 1]
        add      edx, 2
        test     al, al
        jne      short L_95ea
    L_961d:
        mov      eax, esi
    L_961f:
        mov      bl, byte ptr [eax + g_byte_00f9f8c1]
        or       bl, 8
        mov      byte ptr [eax + g_byte_00f9f8c1], bl
        inc      eax
        cmp      eax, 0xff
        jb       short L_961f
        push     edi
        call     TranslateMsgId_004c97a0
        add      esp, 4
        mov      dword ptr [g_data_00f9facc], eax
        mov      dword ptr [g_data_00fa0dc4], esi
        jmp      short L_9651
    L_964c:
        mov      dword ptr [g_data_00fa0dc4], eax
    L_9651:
        xor      eax, eax
        mov      dword ptr [g_data_00f9fad0], eax
        mov      dword ptr [g_data_00f9fad4], eax
        mov      dword ptr [g_data_00f9fad8], eax
        jmp      short L_9672
    L_9664:
        mov      eax, dword ptr [g_data_00f9fadc]
        test     eax, eax
        je       short L_968b
        call     InitGlobalsAndZero_004c9800
    L_9672:
        call     BuildCharacterCaseTables_004c9840
        push     0x19
        call     TableLookupIatCall_004c6fd0
        add      esp, 4
        xor      eax, eax
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        add      esp, 0x14
        ret
    L_968b:
        push     0x19
        call     TableLookupIatCall_004c6fd0
        add      esp, 4
        or       eax, 0xffffffff
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        add      esp, 0x14
        ret
    L_96a0:
        mov      ecx, 0x40
        xor      eax, eax
        mov      edi, OFFSET g_data_00f9f8c0
        lea      ebx, [edx + edx*2]
        rep stosd
        stosb
        xor      edi, edi
        shl      ebx, 4
        lea      ebp, [ebx + g_dispatchSave114_00522320]
    L_96bd:
        mov      al, byte ptr [ebp]
        mov      esi, ebp
        test     al, al
        je       short L_96f6
    L_96c6:
        mov      cl, byte ptr [esi + 1]
        test     cl, cl
        je       short L_96f6
        xor      eax, eax
        and      ecx, 0xff
        mov      al, byte ptr [esi]
        cmp      eax, ecx
        ja       short L_96ec
        mov      dl, byte ptr [edi + g_dispatchSave117_00522308]
    L_96e1:
        or       byte ptr [eax + g_byte_00f9f8c1], dl
        inc      eax
        cmp      eax, ecx
        jbe      short L_96e1
    L_96ec:
        mov      al, byte ptr [esi + 2]
        add      esi, 2
        test     al, al
        jne      short L_96c6
    L_96f6:
        inc      edi
        add      ebp, 8
        cmp      edi, 4
        jb       short L_96bd
        mov      eax, dword ptr [esp + 0x28]
        mov      dword ptr [g_data_00fa0dc4], 1
        push     eax
        mov      dword ptr [g_data_00f9fac8], eax
        call     TranslateMsgId_004c97a0
        mov      ecx, dword ptr [ebx + g_crtLocaleEnvVarTbl_00522314]
        mov      edx, dword ptr [ebx + g_dispatchSave115_00522318]
        mov      dword ptr [g_data_00f9facc], eax
        lea      eax, [ebx + g_crtLocaleEnvVarTbl_00522314]
        add      esp, 4
        mov      dword ptr [g_data_00f9fad0], ecx
        mov      eax, dword ptr [eax + 8]
        mov      dword ptr [g_data_00f9fad4], edx
        mov      dword ptr [g_data_00f9fad8], eax
        jmp      L_9672
    }
}
