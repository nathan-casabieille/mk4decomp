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
extern unsigned int g_player1NodeIdx;
extern unsigned int g_data_00535cf8;
extern unsigned int g_cj_00542054;
extern unsigned int g_data_005437f0;
extern unsigned int g_data_00543598;
extern unsigned int g_data_0054358c;
extern unsigned int g_data_00535e70;
extern unsigned int g_data_00535e74;
extern unsigned int g_data_00535e78;
extern unsigned int g_data_00535e7c;

/*
 * Audio11SlotInitLoop_004a5540 - 278b audio: zero an 11-slot table at 0x00543408, then iterate
 *   11 times calling GuardedSetupCallTailJmp(ptr_i, val_i). After each call, chain[+0x54]=0x190000;
 *   chain[+0x5c]=0x18000; store g_currentNodeIdx to (g_table_00543404)[i].
 *   Stack-frame: sub esp, 0x58. Holds 11 const ptrs (0x004d24bc..0x004d2578) and 11 const vals
 *   (0xff9c0000..0x00930000 step 0x190000-ish).
 */
extern unsigned int g_table_00543404;
extern unsigned int g_table_00543408;
extern unsigned int g_currentNodeIdx;
extern void GuardedSetupCallTailJmp_004a1fa0(void);

__declspec(naked) void Audio11SlotInitLoop_004a5540(void)
{
    __asm
    {
        sub     esp, 0x58
        push    ebx
        push    esi
        push    edi
        mov     ecx, 0xb
        xor     eax, eax
        mov     edi, offset g_table_00543408
        rep     stosd
        mov     dword ptr [esp + 0x38], 0x004d24bc
        mov     dword ptr [esp + 0x3c], 0x004d24c0
        mov     dword ptr [esp + 0x40], 0x004d24d0
        mov     dword ptr [esp + 0x44], 0x004d24e8
        mov     dword ptr [esp + 0x48], 0x004d24f8
        mov     dword ptr [esp + 0x4c], 0x004d2510
        mov     dword ptr [esp + 0x50], 0x004d2528
        mov     dword ptr [esp + 0x54], 0x004d2538
        mov     dword ptr [esp + 0x58], 0x004d2548
        mov     dword ptr [esp + 0x5c], 0x004d2560
        mov     dword ptr [esp + 0x60], 0x004d2578
        mov     dword ptr [esp + 0x0c], 0xff9c0000
        mov     dword ptr [esp + 0x10], 0xffb20000
        mov     dword ptr [esp + 0x14], 0xffcb0000
        mov     dword ptr [esp + 0x18], 0xffe40000
        mov     dword ptr [esp + 0x1c], 0xfffd0000
        mov     dword ptr [esp + 0x20], 0x00160000
        mov     dword ptr [esp + 0x24], 0x002f0000
        mov     dword ptr [esp + 0x28], 0x00480000
        mov     dword ptr [esp + 0x2c], 0x00610000
        mov     dword ptr [esp + 0x30], 0x007a0000
        mov     dword ptr [esp + 0x34], 0x00930000
        xor     esi, esi
        mov     ebx, 0x190000
        mov     edi, 0x18000
    L_a5_iter:
        mov     eax, dword ptr [esp + esi + 0x0c]
        mov     ecx, dword ptr [esp + esi + 0x38]
        push    eax
        push    ecx
        call    GuardedSetupCallTailJmp_004a1fa0
        mov     edx, dword ptr [g_currentNodeIdx]
        add     esi, 4
        add     esp, 8
        cmp     esi, 0x2c
        mov     dword ptr [edx*4 + 0x54], ebx
        mov     eax, dword ptr [g_currentNodeIdx]
        mov     dword ptr [eax*4 + 0x5c], edi
        mov     ecx, dword ptr [g_currentNodeIdx]
        mov     dword ptr [esi + g_table_00543404], ecx
        jb      short L_a5_iter
        pop     edi
        pop     esi
        pop     ebx
        add     esp, 0x58
        ret
    }
}
