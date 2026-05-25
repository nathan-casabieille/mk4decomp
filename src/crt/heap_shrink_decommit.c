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

/* @addr 0x004c72a0 (205b crt) - heap shrink/decommit scan.
 *   Walks the heap-region list head [g_data_00520134]; for each region with
 *   handle != -1, scans its 2KB page-state array (1024 entries × 8 bytes)
 *   at +0x2010, looking for entries marked 0xf0 (free). Decommit each via
 *   IAT[0x4d2168] (VirtualFree); on success, mark slot 0xffffffff, decrement
 *   counter [g_data_00f9f8b8], update head ptr at [region+0xc]. Decrement
 *   target count [esp+0x14]; if region fully empty (all -1), call
 *   HeapRegionTeardown_004c7240(region).
 */
extern unsigned int g_data_00520134;
extern unsigned int g_data_00f9f8b8;
extern unsigned int g_iat_004d2168;
extern void HeapRegionTeardown_004c7240(void);

__declspec(naked) void HeapShrinkDecommit_004c72a0(void) {
    __asm {
        push    ebx
        push    ebp
        push    esi
        push    edi
        mov     edi, dword ptr [g_data_00520134]
    L_hs_check:
        cmp     dword ptr [edi + 0x10], -1
        jz      L_hs_outer_check
        xor     ebp, ebp
        lea     esi, [edi + 0x2010]
        mov     ebx, 0x003ff000
    L_hs_loop:
        cmp     dword ptr [esi], 0xf0
        jne     short L_hs_nextpage
        mov     eax, [edi + 0x10]
        push    0x4000
        add     eax, ebx
        push    0x1000
        push    eax
        call    dword ptr [g_iat_004d2168]
        test    eax, eax
        jz      short L_hs_nextpage
        mov     dword ptr [esi], 0xffffffff
        mov     edx, dword ptr [g_data_00f9f8b8]
        dec     edx
        mov     dword ptr [g_data_00f9f8b8], edx
        mov     eax, [edi + 0xc]
        test    eax, eax
        jz      short L_hs_setHead
        cmp     eax, esi
        jbe     short L_hs_after
    L_hs_setHead:
        mov     [edi + 0xc], esi
    L_hs_after:
        mov     eax, [esp + 0x14]
        inc     ebp
        dec     eax
        mov     [esp + 0x14], eax
        jz      short L_hs_done
    L_hs_nextpage:
        sub     ebx, 0x1000
        sub     esi, 8
        test    ebx, ebx
        jge     short L_hs_loop
    L_hs_done:
        mov     edx, edi
        mov     edi, [edi + 4]
        test    ebp, ebp
        jz      short L_hs_outer_check
        cmp     dword ptr [edx + 0x18], -1
        jne     short L_hs_outer_check
        mov     eax, 1
        lea     ecx, [edx + 0x20]
    L_hs_scanempty:
        cmp     dword ptr [ecx], -1
        jne     short L_hs_emptyCk
        inc     eax
        add     ecx, 8
        cmp     eax, 0x400
        jl      short L_hs_scanempty
    L_hs_emptyCk:
        cmp     eax, 0x400
        jne     short L_hs_outer_check
        push    edx
        call    HeapRegionTeardown_004c7240
        add     esp, 4
    L_hs_outer_check:
        cmp     edi, dword ptr [g_data_00520134]
        jz      short L_hs_ret
        mov     eax, [esp + 0x14]
        test    eax, eax
        jg      L_hs_check
    L_hs_ret:
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        ret
    }
}
