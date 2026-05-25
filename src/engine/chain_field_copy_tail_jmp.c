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

/* @addr 0x00466e70 (325b game) - quad-call chain + chain-field copy (g_eventQueueEnd -> g_cj_0054205c) + tail-jmp.
 *   g_walkCallback=2; call DirtyDoubleDeref. If pause ret.
 *   g_xformEntityIdx = [scaledInit*4 + 0x24]. Call MStackPushDispatchBitGate_00407330. If pause ret.
 *   If bit2(0054208c) ret. Call MStackPushTwoEntryChainCall_004058c0. If pause ret. Call MStackCall_004062f0. If pause ret.
 *   Copy chain entries from [g_eventQueueEnd*4]+offset to [g_cj_0054205c*4]+offset:
 *     +0x54 (raw), +0x58 (subtract 0x9999), +0x5c, +0x60, +0x64, +0x68 (raw).
 *   chain[+0x34] ^= 1; copy chain[+0x3c]. Load chain[+0x18] into g_scaledInit.
 *   Zero chain[scaledInit*4 + 0x30/+0x34/+0x38]. Tail-jmp SetupVecFsmCluster_0043e3e0. ret.
 */
extern unsigned int g_framePauseFlag;
extern unsigned int g_xformEntityIdx;
extern unsigned int g_eventQueueEnd;
extern void DirtyDoubleDeref_00408cb0(void);
extern void MStackCall_004062f0(void);
extern void MStackPushDispatchBitGate_00407330(void);
extern void MStackPushTwoEntryChainCall_004058c0(void);
extern void SetupVecFsmCluster_0043e3e0(void);

__declspec(naked) void ChainFieldCopyTailJmp_00466e70(void) {
    __asm {
        mov     dword ptr [g_walkCallback], 2
        call    DirtyDoubleDeref_00408cb0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   28h
        _emit   01h
        _emit   00h
        _emit   00h
        mov     eax, dword ptr [g_scaledInit_00542044]
        mov     ecx, dword ptr [eax*4 + 0x24]
        mov     dword ptr [g_xformEntityIdx], ecx
        call    MStackPushDispatchBitGate_00407330
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   04h
        _emit   01h
        _emit   00h
        _emit   00h
        test    byte ptr [g_xformDirtyFlags], 4
        _emit   0fh
        _emit   85h
        _emit   0f7h
        _emit   00h
        _emit   00h
        _emit   00h
        call    MStackPushTwoEntryChainCall_004058c0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   0e5h
        _emit   00h
        _emit   00h
        _emit   00h
        call    MStackCall_004062f0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   0d3h
        _emit   00h
        _emit   00h
        _emit   00h
        mov     ecx, dword ptr [g_eventQueueEnd]
        mov     edx, dword ptr [g_cj_0054205c]
        shl     ecx, 2
        lea     eax, [edx*4 + 0]
        mov     edx, dword ptr [ecx + 0x54]
        mov     dword ptr [g_walkCallback], edx
        mov     dword ptr [eax + 0x54], edx
        mov     edx, dword ptr [ecx + 0x58]
        sub     edx, 0x9999
        mov     dword ptr [g_walkCallback], edx
        mov     dword ptr [eax + 0x58], edx
        mov     edx, dword ptr [ecx + 0x5c]
        mov     dword ptr [g_walkCallback], edx
        mov     dword ptr [eax + 0x5c], edx
        mov     edx, dword ptr [ecx + 0x60]
        mov     dword ptr [g_walkCallback], edx
        mov     dword ptr [eax + 0x60], edx
        mov     edx, dword ptr [ecx + 0x64]
        mov     dword ptr [g_walkCallback], edx
        mov     dword ptr [eax + 0x64], edx
        mov     edx, dword ptr [ecx + 0x68]
        mov     dword ptr [g_walkCallback], edx
        mov     dword ptr [eax + 0x68], edx
        mov     ecx, dword ptr [ecx + 0x34]
        xor     ecx, 1
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [eax + 0x34], ecx
        mov     edx, dword ptr [g_eventQueueEnd]
        mov     ecx, dword ptr [edx*4 + 0x3c]
        mov     edx, dword ptr [g_cj_0054205c]
        mov     dword ptr [edx*4 + 0x3c], ecx
        mov     eax, dword ptr [eax + 0x18]
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     dword ptr [g_walkCallback], 0
        mov     dword ptr [eax*4 + 0x30], 0
        mov     ecx, dword ptr [g_scaledInit_00542044]
        mov     eax, dword ptr [g_walkCallback]
        mov     dword ptr [ecx*4 + 0x34], eax
        mov     eax, dword ptr [g_scaledInit_00542044]
        mov     edx, dword ptr [g_walkCallback]
        mov     dword ptr [eax*4 + 0x38], edx
        jmp     SetupVecFsmCluster_0043e3e0
        ret
    }
}
