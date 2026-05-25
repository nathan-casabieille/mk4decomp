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
extern unsigned int g_audioBoundNode_005437f0;
extern unsigned int g_data_00543598;
extern unsigned int g_data_0054358c;
extern unsigned int g_fightAxisNegX_00535e70;
extern unsigned int g_fightAxisNegY_00535e74;
extern unsigned int g_fightAxisPosX_00535e78;
extern unsigned int g_fightAxisPosY_00535e7c;

/* @addr 0x004b4530 (196b engine.geo) - Windows message-queue probe (PeekMessageA-like indirect).
 *   Stack frame: sub esp, 0x14; save ebx/ebp/esi/edi (ebp = 0).
 *   Probe HWND ([0x7affe4]), arg1 ([esp+0x2c]), arg2 ([esp+0x30]),
 *   state ([0x7affe0] == 0), arg3 ([esp+0x34]); all must be non-zero.
 *   Build PeekMessage params on stack depending on [esp+0x28] (esi).
 *   Indirect call [0x7b003c].
 *   On success, verify [esp+0x14] != 0 and [esp+0x18] < 0x280;
 *   write result to *arg1, *arg2, *arg3=1; update [0x7affe0]; return 1.
 *   On any fail, return 0.
 */
extern unsigned int g_PeekMessageA_007b003c;
extern unsigned int g_x_007afff0;
extern unsigned int g_x_007affe4;

__declspec(naked) void WindowsMsgProbe_004b4530(void) {
    __asm {
        sub     esp, 0x14
        mov     eax, dword ptr [g_x_007affe4]
        push    ebx
        push    ebp
        xor     ebp, ebp
        push    esi
        cmp     eax, ebp
        push    edi
        mov     dword ptr [esp + 0x10], 0x14
        mov     [esp + 0x14], ebp
        mov     [esp + 0x18], ebp
        mov     [esp + 0x1c], ebp
        mov     [esp + 0x20], ebp
        _emit   0fh
        _emit   84h
        _emit   8ch
        _emit   00h
        _emit   00h
        _emit   00h
        cmp     [esp + 0x2c], ebp
        _emit   0fh
        _emit   84h
        _emit   82h
        _emit   00h
        _emit   00h
        _emit   00h
        mov     ebx, [esp + 0x30]
        cmp     ebx, ebp
        _emit   74h
        _emit   7ah
        cmp     dword ptr [g_x_007afff0], ebp
        _emit   75h
        _emit   72h
        mov     edi, [esp + 0x34]
        cmp     edi, ebp
        _emit   74h
        _emit   6ah
        mov     esi, [esp + 0x28]
        cmp     esi, ebp
        _emit   74h
        _emit   0eh
        lea     eax, [esp + 0x10]
        push    eax
        push    ebp
        push    ebp
        push    ebp
        push    1
        push    1
        _emit   0ebh
        _emit   0eh
        lea     ecx, [esp + 0x10]
        push    ecx
        push    ebp
        push    ebp
        push    0xff
        push    ebp
        push    ebp
        call    dword ptr [g_PeekMessageA_007b003c]
        cmp     eax, ebp
        _emit   74h
        _emit   3ch
        mov     eax, [esp + 0x14]
        cmp     eax, ebp
        _emit   74h
        _emit   34h
        mov     ecx, [esp + 0x18]
        cmp     ecx, 0x00000280
        _emit   72h
        _emit   28h
        mov     edx, [esp + 0x2c]
        mov     [edx], eax
        xor     eax, eax
        cmp     esi, ebp
        mov     [ebx], ecx
        setne   al
        inc     eax
        mov     dword ptr [g_x_007afff0], eax
        mov     dword ptr [edi], 1
        mov     eax, 1
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        add     esp, 0x14
        ret
        pop     edi
        pop     esi
        pop     ebp
        xor     eax, eax
        pop     ebx
        add     esp, 0x14
        ret
    }
}
