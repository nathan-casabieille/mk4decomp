/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_state_004d57ac;
extern unsigned int g_scaledInit_00542044;
extern packed_ptr g_xformEntityIdx;
extern u32 g_eventQueueEnd;
extern unsigned int g_baseSel_00542060;
extern u32 g_eventQueueWorkType;
extern unsigned int g_acc_00542078;
extern unsigned int g_cj_0054205c;
extern u32 g_framePauseFlag;
extern unsigned int g_state_0053a718;
extern unsigned int g_eventQueueTotal;
extern unsigned int g_eventQueueCurrent;
extern unsigned int g_currentNodeFlags;
extern unsigned int g_xformDirtyFlags;
extern unsigned int g_xformScratch2088;
extern unsigned int g_xformScratch94;
extern unsigned int g_table_00535ddc;
extern unsigned int g_active_00537e88;
extern unsigned int g_active_0053a408;
extern unsigned int g_audioBankSel_00537f94;
extern unsigned int g_eventQueueChild;
extern u32 g_pendingNodeType;

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
extern unsigned int g_eventQueueNotMask;
extern unsigned int g_cj_00542058;
extern unsigned int g_rangeSqLimit_0053a180;
extern unsigned int g_zero_00541fa4;
extern unsigned int g_zero_00541fa8;
extern unsigned int g_state_0053a7b0;
extern unsigned int g_data_0053a770;
extern unsigned int g_data_0053a46c;

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
extern unsigned int g_player1NodeIdx;
extern unsigned int g_installOwnerNode_00535cf8;
extern unsigned int g_cj_00542054;
extern unsigned int g_audioBoundNode_005437f0;
extern unsigned int g_data_00543598;
extern unsigned int g_data_0054358c;
extern unsigned int g_fightAxisNegX_00535e70;
extern unsigned int g_fightAxisNegY_00535e74;
extern unsigned int g_fightAxisPosX_00535e78;
extern unsigned int g_fightAxisPosY_00535e7c;

extern unsigned int g_data_00fa0de0;
extern unsigned int g_iat_004d209c;
extern unsigned int g_iat_004d2124;
extern void Crt_doserrno_004c8bb0(void);
extern void Crt_errno_004c8ba0(void);
extern void DosMapErr_004c8b20(void);
extern void LseekImpl_004c8e50(void);

__declspec(naked) void CrtReadCrlfDecode_004c9040(void)
{
    __asm {
        mov      eax, dword ptr [esp + 0xc]
        sub      esp, 0xc
        push     ebx
        push     ebp
        push     esi
        push     edi
        mov      edi, dword ptr [esp + 0x24]
        xor      ebp, ebp
        test     eax, eax
        mov      edx, edi
        je       L_925b
        mov      eax, dword ptr [esp + 0x20]
        mov      ecx, eax
        and      eax, 0x1f
        sar      ecx, 5
        lea      ebx, [eax + eax*8]
        mov      eax, dword ptr [ecx*4 + g_data_00fa0de0]
        lea      esi, [ecx*4 + g_data_00fa0de0]
        shl      ebx, 2
        mov      dword ptr [esp + 0x18], esi
        lea      ecx, [ebx + eax]
        mov      al, byte ptr [ebx + eax + 4]
        test     al, 2
        jne      L_925b
        test     al, 0x48
        je       short L_90b3
        mov      al, byte ptr [ecx + 5]
        cmp      al, 0xa
        je       short L_90b3
        mov      byte ptr [edi], al
        mov      eax, dword ptr [esp + 0x28]
        mov      ecx, dword ptr [esi]
        dec      eax
        lea      edx, [edi + 1]
        mov      ebp, 1
        mov      dword ptr [esp + 0x28], eax
        mov      byte ptr [ebx + ecx + 5], 0xa
    L_90b3:
        mov      ecx, dword ptr [esp + 0x28]
        lea      eax, [esp + 0x14]
        push     0
        push     eax
        push     ecx
        push     edx
        mov      edx, dword ptr [esi]
        mov      eax, dword ptr [ebx + edx]
        push     eax
        call     dword ptr [g_iat_004d2124]
        test     eax, eax
        jne      short L_9119
        call     dword ptr [g_iat_004d209c]
        cmp      eax, 5
        jne      short L_90fc
        call     Crt_errno_004c8ba0
        mov      dword ptr [eax], 9
        call     Crt_doserrno_004c8bb0
        mov      dword ptr [eax], 5
        or       eax, 0xffffffff
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        add      esp, 0xc
        ret
    L_90fc:
        cmp      eax, 0x6d
        je       L_925b
        push     eax
        call     DosMapErr_004c8b20
        add      esp, 4
        or       eax, 0xffffffff
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        add      esp, 0xc
        ret
    L_9119:
        mov      ecx, dword ptr [esi]
        mov      edx, dword ptr [esp + 0x14]
        add      ebp, edx
        mov      al, byte ptr [ebx + ecx + 4]
        lea      ecx, [ebx + ecx + 4]
        test     al, 0x80
        je       L_9251
        test     edx, edx
        je       short L_913e
        cmp      byte ptr [edi], 0xa
        jne      short L_913e
        or       al, 4
        jmp      short L_9140
    L_913e:
        and      al, 0xfb
    L_9140:
        mov      byte ptr [ecx], al
        mov      eax, dword ptr [esp + 0x24]
        add      ebp, eax
        mov      esi, edi
        cmp      eax, ebp
        mov      dword ptr [esp + 0x28], ebp
        jae      L_924b
    L_9156:
        mov      al, byte ptr [edi]
        cmp      al, 0x1a
        je       L_9235
        cmp      al, 0xd
        je       short L_916d
        mov      byte ptr [esi], al
        inc      esi
        inc      edi
        jmp      short L_9219
    L_916d:
        dec      ebp
        cmp      edi, ebp
        jae      short L_918d
        cmp      byte ptr [edi + 1], 0xa
        jne      short L_9183
        add      edi, 2
        mov      byte ptr [esi], 0xa
        jmp      short L_9218
    L_9183:
        mov      byte ptr [esi], 0xd
        inc      esi
        inc      edi
        jmp      short L_9219
    L_918d:
        mov      ecx, dword ptr [esp + 0x18]
        xor      ebp, ebp
        lea      edx, [esp + 0x14]
        push     ebp
        push     edx
        mov      edx, dword ptr [ecx]
        lea      eax, [esp + 0x1b]
        push     1
        push     eax
        mov      eax, dword ptr [ebx + edx]
        push     eax
        inc      edi
        call     dword ptr [g_iat_004d2124]
        test     eax, eax
        jne      short L_91b9
        call     dword ptr [g_iat_004d209c]
        mov      ebp, eax
    L_91b9:
        test     ebp, ebp
        jne      short L_9215
        mov      eax, dword ptr [esp + 0x14]
        test     eax, eax
        je       short L_9215
        mov      ecx, dword ptr [esp + 0x18]
        mov      edx, dword ptr [ecx]
        test     byte ptr [ebx + edx + 4], 0x48
        je       short L_91ea
        mov      al, byte ptr [esp + 0x13]
        cmp      al, 0xa
        jne      short L_91de
        mov      byte ptr [esi], al
        jmp      short L_9218
    L_91de:
        mov      byte ptr [esi], 0xd
        mov      ecx, dword ptr [ecx]
        inc      esi
        mov      byte ptr [ebx + ecx + 5], al
        jmp      short L_9219
    L_91ea:
        cmp      esi, dword ptr [esp + 0x24]
        jne      short L_91fc
        cmp      byte ptr [esp + 0x13], 0xa
        jne      short L_91fc
        mov      byte ptr [esi], 0xa
        jmp      short L_9218
    L_91fc:
        mov      edx, dword ptr [esp + 0x20]
        push     1
        push     -1
        push     edx
        call     LseekImpl_004c8e50
        mov      al, byte ptr [esp + 0x1f]
        add      esp, 0xc
        cmp      al, 0xa
        je       short L_9219
    L_9215:
        mov      byte ptr [esi], 0xd
    L_9218:
        inc      esi
    L_9219:
        mov      ebp, dword ptr [esp + 0x28]
        cmp      edi, ebp
        jb       L_9156
        sub      esi, dword ptr [esp + 0x24]
        mov      ebp, esi
        mov      eax, ebp
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        add      esp, 0xc
        ret
    L_9235:
        mov      eax, dword ptr [esp + 0x18]
        mov      ecx, dword ptr [eax]
        mov      al, byte ptr [ebx + ecx + 4]
        test     al, 0x40
        lea      ebx, [ebx + ecx + 4]
        jne      short L_924b
        or       al, 2
        mov      byte ptr [ebx], al
    L_924b:
        sub      esi, dword ptr [esp + 0x24]
        mov      ebp, esi
    L_9251:
        mov      eax, ebp
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        add      esp, 0xc
        ret
    L_925b:
        pop      edi
        pop      esi
        pop      ebp
        xor      eax, eax
        pop      ebx
        add      esp, 0xc
        ret
    }
}
