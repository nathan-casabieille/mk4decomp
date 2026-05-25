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

extern void BitShiftMultiPrecision_004cca50(void);
extern void BitsetReserve_004cc960(void);
extern void Copy3Dwords_004cca00(void);
extern void LinearSearchArray_004cca30(void);
extern void ZeroThreeFromArg_004cca20(void);

__declspec(naked) void FpExtendedToFloat_004ccb10(void)
{
    __asm {
        sub      esp, 0x18
        mov      ecx, dword ptr [esp + 0x1c]
        xor      eax, eax
        push     ebx
        push     ebp
        mov      ax, word ptr [ecx + 0xa]
        mov      edx, dword ptr [ecx + 2]
        mov      ebx, eax
        and      eax, 0x8000
        mov      ebp, eax
        mov      eax, dword ptr [ecx + 6]
        mov      dword ptr [esp + 8], eax
        xor      eax, eax
        mov      ax, word ptr [ecx]
        and      ebx, 0x7fff
        sub      ebx, 0x3fff
        push     esi
        shl      eax, 0x10
        push     edi
        mov      edi, dword ptr [esp + 0x34]
        cmp      ebx, 0xffffc001
        mov      dword ptr [esp + 0x14], edx
        mov      dword ptr [esp + 0x18], eax
        jne      short L_cb8a
        lea      ecx, [esp + 0x10]
        xor      esi, esi
        push     ecx
        call     LinearSearchArray_004cca30
        add      esp, 4
        test     eax, eax
        jne      L_cc8f
        lea      edx, [esp + 0x10]
        push     edx
        call     ZeroThreeFromArg_004cca20
        add      esp, 4
        mov      eax, 2
        jmp      L_cc91
    L_cb8a:
        lea      eax, [esp + 0x10]
        lea      ecx, [esp + 0x1c]
        push     eax
        push     ecx
        call     Copy3Dwords_004cca00
        mov      edx, dword ptr [edi + 8]
        add      esp, 8
        lea      eax, [esp + 0x10]
        push     edx
        push     eax
        call     BitsetReserve_004cc960
        add      esp, 8
        test     eax, eax
        je       short L_cbb2
        inc      ebx
    L_cbb2:
        mov      eax, dword ptr [edi + 4]
        mov      esi, dword ptr [edi + 8]
        mov      ecx, eax
        sub      ecx, esi
        cmp      ebx, ecx
        jge      short L_cbd9
        lea      edx, [esp + 0x10]
        push     edx
        call     ZeroThreeFromArg_004cca20
        add      esp, 4
        xor      esi, esi
        mov      eax, 2
        jmp      L_cc91
    L_cbd9:
        cmp      ebx, eax
        jg       short L_cc2d
        sub      eax, ebx
        lea      ecx, [esp + 0x10]
        mov      esi, eax
        lea      eax, [esp + 0x1c]
        push     eax
        push     ecx
        call     Copy3Dwords_004cca00
        add      esp, 8
        lea      edx, [esp + 0x10]
        push     esi
        push     edx
        call     BitShiftMultiPrecision_004cca50
        mov      eax, dword ptr [edi + 8]
        add      esp, 8
        lea      ecx, [esp + 0x10]
        push     eax
        push     ecx
        call     BitsetReserve_004cc960
        mov      edx, dword ptr [edi + 0xc]
        add      esp, 8
        inc      edx
        lea      eax, [esp + 0x10]
        push     edx
        push     eax
        call     BitShiftMultiPrecision_004cca50
        add      esp, 8
        xor      esi, esi
        mov      eax, 2
        jmp      short L_cc91
    L_cc2d:
        cmp      ebx, dword ptr [edi]
        jl       short L_cc6b
        lea      ecx, [esp + 0x10]
        push     ecx
        call     ZeroThreeFromArg_004cca20
        mov      ebx, dword ptr [esp + 0x14]
        mov      edx, dword ptr [edi + 0xc]
        add      esp, 4
        lea      eax, [esp + 0x10]
        or       ebx, 0x80000000
        push     edx
        push     eax
        mov      dword ptr [esp + 0x18], ebx
        call     BitShiftMultiPrecision_004cca50
        mov      esi, dword ptr [edi + 0x14]
        mov      eax, dword ptr [edi]
        add      esp, 8
        add      esi, eax
        mov      eax, 1
        jmp      short L_cc91
    L_cc6b:
        mov      esi, dword ptr [edi + 0x14]
        mov      ecx, dword ptr [edi + 0xc]
        add      esi, ebx
        mov      ebx, dword ptr [esp + 0x10]
        lea      edx, [esp + 0x10]
        and      ebx, 0x7fffffff
        push     ecx
        push     edx
        mov      dword ptr [esp + 0x18], ebx
        call     BitShiftMultiPrecision_004cca50
        add      esp, 8
    L_cc8f:
        xor      eax, eax
    L_cc91:
        mov      edx, dword ptr [edi + 0xc]
        mov      ecx, 0x1f
        sub      ecx, edx
        mov      edx, dword ptr [esp + 0x10]
        shl      esi, cl
        mov      edi, dword ptr [edi + 0x10]
        neg      ebp
        sbb      ebp, ebp
        and      ebp, 0x80000000
        or       esi, ebp
        or       esi, edx
        cmp      edi, 0x40
        jne      short L_cccc
        mov      ecx, dword ptr [esp + 0x30]
        mov      edx, dword ptr [esp + 0x14]
        mov      dword ptr [ecx + 4], esi
        mov      dword ptr [ecx], edx
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        add      esp, 0x18
        ret
    L_cccc:
        cmp      edi, 0x20
        jne      short L_ccd7
        mov      ecx, dword ptr [esp + 0x30]
        mov      dword ptr [ecx], esi
    L_ccd7:
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        add      esp, 0x18
        ret
    }
}
