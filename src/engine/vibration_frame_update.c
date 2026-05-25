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
extern unsigned int g_state_00537f94;
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

/* @addr 0x004b9640 (301b engine.render) - vibration/feedback frame update.
 *   Reads g_fightGroupHead & 0x180000; if both bits 0, skip. Else loads
 *   [esp+0x14] as `i`; if [i*4+0x1c]==-20, set i=2. Validate i in [1,0x18].
 *   Lookup pattern entry at [i*4 + g_data_004f6508]; bail if 0x10000.
 *   If i==2: load FP, fadd to g_data_004f6570, fcomp 0x004d2a00; if FP overflow,
 *     re-init constants to 0x3fec_cccccccd / 0x3f90_624d_d2f1_a9fc.
 *   Else: check fcomp 0x004d2a10; if outside range, re-init to 0x3ff1_9999_9999_999a
 *     / 0xbf78_9374_bc6a_7efa.
 *   Convert via DoubleToInt64, write to g_walkCallback, shift right by 4,
 *   call Transform9Words_004b3a90(esi, &local); OR bit 0x30 of high byte of g_xformDirtyFlags.
 */
extern unsigned int g_data_004d2a00;
extern unsigned int g_data_004d2a10;
extern unsigned int g_data_004f6508;
extern unsigned int g_data_004f6570;
extern unsigned int g_data_004f6574;
extern unsigned int g_data_004f6578;
extern unsigned int g_data_004f657c;
extern unsigned int g_pendingNodeType;
extern unsigned int g_fightGroupHead;
extern void DoubleToInt64_004c57d0(void);
extern void Transform9Words_004b3a90(void);

__declspec(naked) void VibrationFrameUpdate_004b9640(void) {
    __asm {
        mov     eax, dword ptr [g_fightGroupHead]
        sub     esp, 0x0c
        test    eax, 0x180000
        push    esi
        jz      L_vfu_done
        mov     eax, [esp + 0x14]
        mov     ecx, dword ptr [eax*4 + 0x1c]
        cmp     ecx, -0x14
        jne     short L_vfu_chk
        mov     ecx, 2
    L_vfu_chk:
        test    ecx, ecx
        jle     L_vfu_done
        cmp     ecx, 0x18
        jg      L_vfu_done
        mov     eax, dword ptr [ecx*4 + g_data_004f6508]
        cmp     eax, 0x10000
        mov     dword ptr [g_walkCallback], eax
        jz      L_vfu_done
        mov     edx, dword ptr [g_pendingNodeType]
        cmp     ecx, 2
        lea     esi, [edx*4]
        jne     L_vfu_pathB_sar
        fld     qword ptr [g_data_004f6578]
        fadd    qword ptr [g_data_004f6570]
        fst     qword ptr [g_data_004f6570]
        fcomp   qword ptr [g_data_004d2a00]
        fnstsw  ax
        test    ah, 1
        jz      short L_vfu_skipReinitA
        mov     dword ptr [g_data_004f6570], 0xcccccccd
        mov     dword ptr [g_data_004f6574], 0x3feccccc
        mov     dword ptr [g_data_004f6578], 0xd2f1a9fc
        mov     dword ptr [g_data_004f657c], 0x3f90624d
    L_vfu_skipReinitA:
        fld     qword ptr [g_data_004f6570]
        fcomp   qword ptr [g_data_004d2a10]
        fnstsw  ax
        test    ah, 0x41
        jne     short L_vfu_doConv
        mov     dword ptr [g_data_004f6570], 0x9999999a
        mov     dword ptr [g_data_004f6574], 0x3ff19999
        mov     dword ptr [g_data_004f6578], 0xbc6a7efa
        mov     dword ptr [g_data_004f657c], 0xbf789374
    L_vfu_doConv:
        fild    dword ptr [g_walkCallback]
        fmul    qword ptr [g_data_004f6570]
        call    DoubleToInt64_004c57d0
        mov     dword ptr [g_walkCallback], eax
    L_vfu_pathB_sar:
        sar     eax, 4
        mov     [esp + 0x0c], eax
        mov     [esp + 0x08], eax
        mov     [esp + 0x04], eax
        lea     eax, [esp + 4]
        push    eax
        push    esi
        call    Transform9Words_004b3a90
        mov     eax, dword ptr [g_xformDirtyFlags]
        add     esp, 8
        or      al, 0x30
        mov     dword ptr [g_xformDirtyFlags], eax
    L_vfu_pathB:
    L_vfu_done:
        pop     esi
        add     esp, 0x0c
        ret
    }
}
