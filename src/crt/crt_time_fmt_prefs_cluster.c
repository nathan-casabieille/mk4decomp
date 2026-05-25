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
extern unsigned int g_state_0053a3c0;
extern unsigned int g_player1NodeIdx;
extern unsigned int g_installOwnerNode_00535cf8;
extern unsigned int g_cj_00542054;
extern unsigned int g_data_005437f0;
extern unsigned int g_data_00543598;
extern unsigned int g_data_0054358c;
extern unsigned int g_fightAxisNegX_00535e70;
extern unsigned int g_fightAxisNegY_00535e74;
extern unsigned int g_fightAxisPosX_00535e78;
extern unsigned int g_fightAxisPosY_00535e7c;

extern unsigned int g_data_004f5924;
extern unsigned int g_data_00522bb4;
extern unsigned int g_data_00522bb8;
extern unsigned int g_data_005236b0;
extern unsigned int g_data_005236e8;
extern unsigned int g_data_00f9fc18;
extern unsigned int g_data_00f9fc68;
extern unsigned int g_data_00f9fc6c;
extern unsigned int g_data_00f9fc70;
extern unsigned int g_data_00f9fc9a;
extern void CrtGetLocaleInfo_004d0bc0(void);
extern void FreeImpl_004c55f0(void);
extern void LoadArgPushCall_004c54b0(void);
extern void StringStripSlotReplace_004d0140(void);

__declspec(naked) void CrtTimeFmtPrefsCluster_004cfe40(void)
{
    __asm {
        /* === h1 (0x4cfe40): time-format string builder === */
        sub      esp, 8
        push     esi
        lea      eax, [esp + 8]
        push     edi
        mov      edi, dword ptr [esp + 0x14]
        push     eax
        push     0x23
        push     edi
        push     0
        mov      dword ptr [esp + 0x1c], 0
        mov      dword ptr [esp + 0x18], 0
        call     CrtGetLocaleInfo_004d0bc0
        add      esp, 0x10
        lea      ecx, [esp + 8]
        mov      esi, eax
        push     ecx
        push     0x25
        push     edi
        push     0
        call     CrtGetLocaleInfo_004d0bc0
        add      esp, 0x10
        lea      edx, [esp + 0x14]
        or       esi, eax
        push     edx
        push     0x1e
        push     edi
        push     1
        call     CrtGetLocaleInfo_004d0bc0
        add      esp, 0x10
        or       esi, eax
        je       short L_fe9f
        mov      eax, esi
        pop      edi
        pop      esi
        add      esp, 8
        ret
    L_fe9f:
        push     0xd
        call     LoadArgPushCall_004c54b0
        mov      ecx, dword ptr [esp + 0x1c]
        add      esp, 4
        mov      dword ptr [ecx + 0xa8], eax
        mov      ecx, dword ptr [esp + 0xc]
        test     ecx, ecx
        je       short L_fecc
        mov      byte ptr [eax], 0x48
        mov      ecx, dword ptr [esp + 8]
        inc      eax
        test     ecx, ecx
        je       short L_fedc
        mov      byte ptr [eax], 0x48
        jmp      short L_fedb
    L_fecc:
        mov      byte ptr [eax], 0x68
        mov      ecx, dword ptr [esp + 8]
        inc      eax
        test     ecx, ecx
        je       short L_fedc
        mov      byte ptr [eax], 0x68
    L_fedb:
        inc      eax
    L_fedc:
        mov      edx, dword ptr [esp + 0x14]
        mov      cl, byte ptr [edx]
        test     cl, cl
        je       short L_fef1
    L_fee6:
        mov      byte ptr [eax], cl
        mov      cl, byte ptr [edx + 1]
        inc      eax
        inc      edx
        test     cl, cl
        jne      short L_fee6
    L_fef1:
        mov      byte ptr [eax], 0x6d
        mov      ecx, dword ptr [esp + 8]
        inc      eax
        test     ecx, ecx
        je       short L_ff01
        mov      byte ptr [eax], 0x6d
        inc      eax
    L_ff01:
        mov      edx, dword ptr [esp + 0x14]
        mov      cl, byte ptr [edx]
        test     cl, cl
        je       short L_ff16
    L_ff0b:
        mov      byte ptr [eax], cl
        mov      cl, byte ptr [edx + 1]
        inc      eax
        inc      edx
        test     cl, cl
        jne      short L_ff0b
    L_ff16:
        mov      byte ptr [eax], 0x73
        inc      eax
        mov      byte ptr [eax], 0x73
        mov      byte ptr [eax + 1], 0
        mov      edx, dword ptr [esp + 0x14]
        push     edx
        call     FreeImpl_004c55f0
        add      esp, 4
        xor      eax, eax
        pop      edi
        pop      esi
        add      esp, 8
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
        /* === h2 (0x4cff60): prefs save/reload === */
        mov      eax, dword ptr [g_data_00f9fc18]
        push     ebx
        push     esi
        xor      ebx, ebx
        xor      esi, esi
        cmp      eax, ebx
        mov      si, word ptr [g_data_00f9fc9a]
        push     edi
        je       L_0059
        push     OFFSET g_data_00f9fc68
        push     0xe
        push     esi
        push     1
        call     CrtGetLocaleInfo_004d0bc0
        add      esp, 0x10
        mov      edi, eax
        push     OFFSET g_data_00f9fc6c
        push     0xf
        push     esi
        push     1
        call     CrtGetLocaleInfo_004d0bc0
        add      esp, 0x10
        or       edi, eax
        push     OFFSET g_data_00f9fc70
        push     0x10
        push     esi
        push     1
        call     CrtGetLocaleInfo_004d0bc0
        add      esp, 0x10
        or       edi, eax
        mov      eax, dword ptr [g_data_00f9fc70]
        push     eax
        call     StringStripSlotReplace_004d0140
        add      esp, 4
        cmp      edi, ebx
        je       short L_ffee
        mov      ecx, dword ptr [g_data_00f9fc68]
        push     ecx
        call     FreeImpl_004c55f0
        mov      edx, dword ptr [g_data_00f9fc6c]
        add      esp, 4
        push     edx
        call     FreeImpl_004c55f0
        mov      eax, dword ptr [g_data_00f9fc70]
        add      esp, 4
        push     eax
        call     FreeImpl_004c55f0
        add      esp, 4
        mov      dword ptr [g_data_00f9fc68], ebx
        mov      dword ptr [g_data_00f9fc6c], ebx
        mov      dword ptr [g_data_00f9fc70], ebx
        or       eax, 0xffffffff
        pop      edi
        pop      esi
        pop      ebx
        ret
    L_ffee:
        mov      ecx, dword ptr [g_data_005236e8]
        mov      eax, dword ptr [ecx]
        cmp      eax, OFFSET g_data_005236b0
        je       short L_002a
        push     eax
        call     FreeImpl_004c55f0
        mov      edx, dword ptr [g_data_005236e8]
        add      esp, 4
        mov      eax, dword ptr [edx + 4]
        push     eax
        call     FreeImpl_004c55f0
        mov      ecx, dword ptr [g_data_005236e8]
        add      esp, 4
        mov      edx, dword ptr [ecx + 8]
        push     edx
        call     FreeImpl_004c55f0
        add      esp, 4
    L_002a:
        mov      ecx, dword ptr [g_data_005236e8]
        mov      eax, dword ptr [g_data_00f9fc68]
        mov      dword ptr [ecx], eax
        mov      edx, dword ptr [g_data_005236e8]
        mov      eax, dword ptr [g_data_00f9fc6c]
        mov      dword ptr [edx + 4], eax
        mov      ecx, dword ptr [g_data_005236e8]
        mov      edx, dword ptr [g_data_00f9fc70]
        mov      dword ptr [ecx + 8], edx
        jmp      L_0117
    L_0059:
        mov      eax, dword ptr [g_data_00f9fc68]
        push     eax
        call     FreeImpl_004c55f0
        mov      ecx, dword ptr [g_data_00f9fc6c]
        add      esp, 4
        push     ecx
        call     FreeImpl_004c55f0
        mov      edx, dword ptr [g_data_00f9fc70]
        add      esp, 4
        push     edx
        call     FreeImpl_004c55f0
        add      esp, 4
        mov      dword ptr [g_data_00f9fc68], ebx
        mov      dword ptr [g_data_00f9fc6c], ebx
        mov      dword ptr [g_data_00f9fc70], ebx
        push     2
        call     LoadArgPushCall_004c54b0
        mov      ecx, dword ptr [g_data_005236e8]
        add      esp, 4
        mov      dword ptr [ecx], eax
        mov      edx, dword ptr [g_data_005236e8]
        mov      eax, dword ptr [edx]
        cmp      eax, ebx
        jne      short L_00bc
        or       eax, 0xffffffff
        pop      edi
        pop      esi
        pop      ebx
        ret
    L_00bc:
        mov      cx, word ptr [g_data_004f5924]
        push     2
        mov      word ptr [eax], cx
        call     LoadArgPushCall_004c54b0
        mov      edx, dword ptr [g_data_005236e8]
        add      esp, 4
        mov      dword ptr [edx + 4], eax
        mov      eax, dword ptr [g_data_005236e8]
        mov      eax, dword ptr [eax + 4]
        cmp      eax, ebx
        jne      short L_00ec
        or       eax, 0xffffffff
        pop      edi
        pop      esi
        pop      ebx
        ret
    L_00ec:
        push     2
        mov      byte ptr [eax], bl
        call     LoadArgPushCall_004c54b0
        mov      ecx, dword ptr [g_data_005236e8]
        add      esp, 4
        mov      dword ptr [ecx + 8], eax
        mov      edx, dword ptr [g_data_005236e8]
        mov      eax, dword ptr [edx + 8]
        cmp      eax, ebx
        jne      short L_0115
        or       eax, 0xffffffff
        pop      edi
        pop      esi
        pop      ebx
        ret
    L_0115:
        mov      byte ptr [eax], bl
    L_0117:
        mov      eax, dword ptr [g_data_005236e8]
        pop      edi
        pop      esi
        pop      ebx
        mov      ecx, dword ptr [eax]
        xor      eax, eax
        mov      dl, byte ptr [ecx]
        mov      dword ptr [g_data_00522bb8], 1
        mov      byte ptr [g_data_00522bb4], dl
        ret
    }
}
