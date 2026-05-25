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

/* @addr 0x0042ee40 (370b game) - boot-init: clears slot 0x52ab10, seeds
 *   bookkeeping globals, and zero-fills a counted region.
 *   Calls BootInitGuardedCallChain_004265d0 first. On no-error: reads the
 *   slot index from g_data_0052ab10 into g_currentNodeIdx, calls
 *   ZeroThreeFields_00404ed0 then writes (0, 0, 0xfffc0000) into
 *   [slot+0x54/+0x58/+0x5c]. Mirrors with g_data_00535e6c slot getting
 *   (0, 0, 0x10000, 0). Then sets globals: 0x535de0=0, 0x541dd8=0,
 *   0x53a170=2, and 0x53a1ac=0xa (loop counter).
 *
 *   Inner loop: while 0x53a1ac >= 0, zeroes [0x542044*4] (advancing
 *   index each iteration) - counted zero-fill. After: stashes 0xa into
 *   0x52aabc.
 *
 *   Calls CopyGlobal_004ac1f0; on no-error pushes 2 onto
 *   TableWalkBoundedCmp_004bd890, sets byte 0x54371c=1, sets 0x54206c
 *   from g_data_00537f48, calls DownloadPlayerChar; on no-error sets
 *   0x542070=1 and 0x54206c from g_data_005380e0, calls DownloadPlayerChar
 *   again; on no-error sets 0x542044 = &g_data_0050b214>>2 (packed_ptr),
 *   clears 0x54371c, calls LoadGeoAsset_Default; on no-error reloads
 *   &g_data_0050b214>>2 and calls LoadGeoAsset_Default a second time.
 */
extern unsigned int g_data_0050b214;
extern unsigned int g_data_0052aabc;
extern unsigned int g_data_0052ab10;
extern unsigned int g_data_00535de0;
extern unsigned int g_data_00535e6c;
extern unsigned int g_data_00537f48;
extern unsigned int g_data_005380e0;
extern unsigned int g_data_0053a170;
extern unsigned int g_data_0053a1ac;
extern unsigned int g_data_00541dd8;
extern unsigned int g_framePauseFlag;
extern unsigned int g_data_00541fbc;
extern unsigned int g_currentNodeIdx;
extern unsigned int g_eventQueueEnd;
extern unsigned int g_data_0054371c;
extern void BootInitGuardedCallChain_004265d0(void);
extern void CopyGlobal_004ac1f0(void);
extern void DownloadPlayerChar(void);
extern void TableWalkBoundedCmp_004bd890(void);
extern void ZeroThreeFields_00404ed0(void);

__declspec(naked) void BootInitClearSlotSeed_0042ee40(void) {
    __asm {
        push    ebx
        push    esi
        push    edi
        call    BootInitGuardedCallChain_004265d0
        mov     eax, dword ptr [g_framePauseFlag]
        xor     ebx, ebx
        cmp     eax, ebx
        jne     L_bic_done
        mov     eax, dword ptr [g_data_0052ab10]
        mov     dword ptr [g_currentNodeIdx], eax
        lea     esi, [eax*4]
        call    ZeroThreeFields_00404ed0
        mov     dword ptr [esi + 0x54], ebx
        mov     dword ptr [esi + 0x58], ebx
        mov     dword ptr [esi + 0x5c], 0xfffc0000
        mov     eax, dword ptr [g_data_00535e6c]
        mov     dword ptr [g_eventQueueEnd], eax
        shl     eax, 2
        mov     dword ptr [eax + 0x54], ebx
        mov     dword ptr [eax + 0x58], ebx
        mov     dword ptr [eax + 0x5c], 0x10000
        mov     dword ptr [eax + 0x34], ebx
        mov     eax, dword ptr [g_data_00541fbc]
        mov     dword ptr [g_data_00535de0], ebx
        mov     dword ptr [g_currentNodeIdx], eax
        mov     eax, 0xa
        mov     dword ptr [g_data_00541dd8], ebx
        mov     dword ptr [g_data_0053a170], 2
        mov     dword ptr [g_walkCallback], ebx
        mov     dword ptr [g_data_0053a1ac], eax
    L_bic_zeroLoop:
        mov     edx, dword ptr [g_currentNodeIdx]
        mov     ecx, dword ptr [g_walkCallback]
        mov     dword ptr [edx*4], ecx
        mov     edx, dword ptr [g_currentNodeIdx]
        mov     ecx, dword ptr [g_data_0053a1ac]
        inc     edx
        dec     ecx
        mov     dword ptr [g_currentNodeIdx], edx
        mov     dword ptr [g_data_0053a1ac], ecx
        jns     short L_bic_zeroLoop
        mov     dword ptr [g_data_0052aabc], eax
        mov     dword ptr [g_walkCallback], ebx
        call    CopyGlobal_004ac1f0
        cmp     dword ptr [g_framePauseFlag], ebx
        jne     L_bic_done
        mov     esi, dword ptr [g_walkCallback]
        mov     edi, dword ptr [g_eventQueueCurrent]
        push    2
        call    TableWalkBoundedCmp_004bd890
        mov     eax, dword ptr [g_data_00537f48]
        add     esp, 4
        mov     byte ptr [g_data_0054371c], 1
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [g_eventQueueCurrent], ebx
        call    DownloadPlayerChar
        cmp     dword ptr [g_framePauseFlag], ebx
        jne     short L_bic_done
        mov     ecx, dword ptr [g_data_005380e0]
        mov     dword ptr [g_eventQueueCurrent], 1
        mov     dword ptr [g_walkCallback], ecx
        call    DownloadPlayerChar
        cmp     dword ptr [g_framePauseFlag], ebx
        jne     short L_bic_done
        mov     edx, offset g_data_0050b214
        mov     byte ptr [g_data_0054371c], bl
        shr     edx, 2
        mov     dword ptr [g_walkCallback], esi
        mov     dword ptr [g_eventQueueCurrent], edi
        mov     dword ptr [g_currentNodeIdx], edx
        call    LoadGeoAsset_Default
        cmp     dword ptr [g_framePauseFlag], ebx
        jne     short L_bic_done
        mov     eax, offset g_data_0050b214
        shr     eax, 2
        mov     dword ptr [g_currentNodeIdx], eax
        call    LoadGeoAsset_Default
    L_bic_done:
        pop     edi
        pop     esi
        pop     ebx
        ret
    }
}
