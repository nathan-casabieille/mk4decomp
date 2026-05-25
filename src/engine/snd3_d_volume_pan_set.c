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
extern unsigned int g_state_00542094;
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
extern unsigned int g_data_0053a180;
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
extern unsigned int g_state_00538158;
extern unsigned int g_data_00535cf8;
extern unsigned int g_cj_00542054;
extern unsigned int g_data_005437f0;
extern unsigned int g_data_00543598;
extern unsigned int g_data_0054358c;
extern unsigned int g_data_00535e70;
extern unsigned int g_data_00535e74;
extern unsigned int g_data_00535e78;
extern unsigned int g_data_00535e7c;

extern void Helper_AudioRelease(void);
extern void Snd3DVolumePanSet_004c3d00(void);
extern unsigned int g_data_004d2a30[2];  /* double constant */
extern unsigned char g_table_004f7dc0[];

/* @addr 0x004be870 (216b engine.scenegraph) - effect-table walker.
 *   Reads param (ecx<47), computes table base = &g_table[idx*680], iterates
 *   170 4-byte entries: skip 0xffff; check filter via TableSearch_004be760;
 *   compute scaled idx (if ax>100 then ax*(2/5), else ax+0x7d0); random pick
 *   via Helper_AudioRelease; load short [esi+2] (factor), fild+fmul[g_data_004d2a30],
 *   DoubleToInt64 → byte clamp stored at [esp+8]; recompute scaled idx;
 *   apply effect via Snd3DVolumePanSet_004c3d00(idx, -1, byte, byte).
 */
extern void DoubleToInt64_004c57d0(void);
extern void TableSearch_004be760(void);

__declspec(naked) void EffectTableWalker_004be870(void) {
    __asm {
        push    ecx
        mov     ecx, [esp + 8]
        push    esi
        cmp     ecx, 0x2f
        push    edi
        jae     L_et_done
        mov     eax, ecx
        xor     edi, edi
        shl     eax, 4
        add     eax, ecx
        lea     eax, [eax + eax*4]
        lea     esi, [eax*8 + g_table_004f7dc0]
    L_et_loop:
        mov     ax, word ptr [esi]
        cmp     ax, 0xffff
        jz      L_et_done
        push    eax
        call    TableSearch_004be760
        add     esp, 4
        test    eax, eax
        jne     L_et_next
        mov     ax, word ptr [esi]
        cmp     ax, 100
        jg      short L_et_scaleA
        movsx   edx, ax
        add     edx, 0x7d0
        jmp     short L_et_callRandA
    L_et_scaleA:
        movsx   ecx, ax
        mov     eax, 0x66666667
        imul    ecx
        sar     edx, 1
        mov     ecx, edx
        shr     ecx, 31
        add     edx, ecx
    L_et_callRandA:
        push    edx
        call    Helper_AudioRelease
        movsx   edx, word ptr [esi + 2]
        mov     [esp + 0x14], edx
        add     esp, 4
        fild    dword ptr [esp + 0x10]
        fmul    qword ptr [g_data_004d2a30]
        call    DoubleToInt64_004c57d0
        mov     byte ptr [esp + 8], al
        mov     ax, word ptr [esi]
        cmp     ax, 100
        jg      short L_et_scaleB
        movsx   edx, ax
        add     edx, 0x7d0
        jmp     short L_et_callApply
    L_et_scaleB:
        movsx   ecx, ax
        mov     eax, 0x66666667
        imul    ecx
        sar     edx, 1
        mov     eax, edx
        shr     eax, 31
        add     edx, eax
    L_et_callApply:
        mov     eax, [esp + 8]
        push    eax
        push    eax
        push    -1
        push    edx
        call    Snd3DVolumePanSet_004c3d00
        add     esp, 0x10
    L_et_next:
        inc     edi
        add     esi, 4
        cmp     edi, 0xaa
        jl      L_et_loop
    L_et_done:
        pop     edi
        pop     esi
        pop     ecx
        ret
    }
}
