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
extern unsigned int g_dualBitGate_0053a7b0;
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

/* @addr 0x00459030 (296b game) - table-walk match scan with triple-cmp + insert.
 *   eax = 0x004e8860>>2; edx = 0x005380b0>>2; g_scaledInit=eax, g_xformEntityIdx=edx.
 *   Loop: ecx = [eax*4]; if zero ret. cmp with [edx*4]; if neq jump_advance.
 *     cmp with [edx*4+4]; if neq jump_advance. cmp with [edx*4+8]; if eq jump_insert.
 *     advance: eax+=3, reload, loop while ecx!=0.
 *   Insert: g_walkCallback=3; call StorePauseImulShr16; if pause ret.
 *     eax = g_walkCallback*3 + (0x004e8948>>2); scaledInit=eax; copy 3 entries to [g_xformEntityIdx*4 +0/4/8]; pop esi; ret.
 */
extern unsigned int g_data_004e8860;
extern unsigned int g_data_004e8948;
extern unsigned int g_data_005380b0;
extern unsigned int g_framePauseFlag;
extern unsigned int g_xformEntityIdx;
extern void StorePauseImulShr16_004ab630(void);

__declspec(naked) void TableWalkMatchInsert_00459030(void) {
    __asm {
        mov     eax, offset g_data_004e8860
        mov     edx, offset g_data_005380b0
        shr     eax, 2
        shr     edx, 2
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     dword ptr [g_xformEntityIdx], edx
        mov     ecx, dword ptr [eax*4 + 0]
        push    esi
        test    ecx, ecx
        mov     dword ptr [g_walkCallback], ecx
        _emit   0fh
        _emit   84h
        _emit   0f5h
        _emit   00h
        _emit   00h
        _emit   00h
    loop_top:
        cmp     ecx, dword ptr [edx*4 + 0]
        _emit   75h
        _emit   30h
        mov     ecx, dword ptr [eax*4 + 4]
        mov     dword ptr [g_walkCallback], ecx
        mov     esi, dword ptr [edx*4 + 4]
        cmp     ecx, esi
        _emit   75h
        _emit   18h
        mov     ecx, dword ptr [eax*4 + 8]
        mov     dword ptr [g_walkCallback], ecx
        mov     esi, dword ptr [edx*4 + 8]
        cmp     ecx, esi
        _emit   74h
        _emit   1bh
        add     eax, 3
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     ecx, dword ptr [eax*4 + 0]
        test    ecx, ecx
        mov     dword ptr [g_walkCallback], ecx
        _emit   75h
        _emit   0aeh
        pop     esi
        ret
        mov     dword ptr [g_walkCallback], 3
        call    StorePauseImulShr16_004ab630
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   85h
        _emit   00h
        _emit   00h
        _emit   00h
        mov     eax, dword ptr [g_walkCallback]
        lea     ecx, [eax + eax*2]
        mov     eax, offset g_data_004e8948
        shr     eax, 2
        add     eax, ecx
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     ecx, dword ptr [eax*4 + 0]
        inc     eax
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     eax, dword ptr [g_xformEntityIdx]
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [eax*4 + 0], ecx
        mov     eax, dword ptr [g_scaledInit_00542044]
        mov     edx, dword ptr [g_xformEntityIdx]
        mov     ecx, dword ptr [eax*4 + 0]
        inc     eax
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     dword ptr [edx*4 + 4], ecx
        mov     eax, dword ptr [g_scaledInit_00542044]
        mov     ecx, dword ptr [eax*4 + 0]
        inc     eax
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     eax, dword ptr [g_xformEntityIdx]
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [eax*4 + 8], ecx
        pop     esi
        ret
    }
}
