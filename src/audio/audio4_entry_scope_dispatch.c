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

/* @addr 0x004a7e00 (333b audio) - 4-entry audio scope dispatcher.
 *   Entry 1 (offset 0): if g_data_005433c8 < g_data_004f3ae8 - 1, just bumps
 *     the counter; otherwise OR-sets bit 0 of g_xformDirtyFlags.
 *   (10b NOP padding to 0x4a7e30.)
 *   Entry 2 (offset 0x30): calls DecOrDirty_004a7d90, snapshots g_xformDirtyFlags
 *     into g_data_00541dc4, clears bit 0, calls DecOrDirty_004a7de0; if the
 *     slot[+0x30] == 3 restores from snapshot.
 *   (9b NOP padding to 0x4a7e70.)
 *   Entry 3 (offset 0x70): mirror of entry 2 but calls IncBoundedDirty_004a7db0
 *     first, then this function's own entry 1 (call -0x8b → 0x4a7e00); same
 *     +0x30==3 conditional restore tail.
 *   (9b NOP padding to 0x4a7eb0.)
 *   Entry 5 (offset 0xb0, big): calls SetJmp_004a1ac0 and DrainQueueCallEach_004a1ec0,
 *     walks 24-byte-stride records at 0x004f3c20..0x004f3d40 calling
 *     MStackPush2ChainLLInsert_00406790 for each; then iterates g_data_004f3ae4 records at +0x34
 *     stride 0x24, then g_data_004f3ae8 records at +0x48 stride 0x24, and
 *     finally calls CallSetMultiGlobalsJmp_004a9230.
 */
extern unsigned int g_data_004f3ae4;
extern unsigned int g_data_004f3ae8;
extern unsigned int g_data_00541dc4;
extern unsigned int g_currentNodeIdx;
extern unsigned int g_baseSel_00542060;
extern unsigned int g_xformDirtyFlags;
extern unsigned int g_data_005433c8;
extern void CallSetMultiGlobalsJmp_004a9230(void);
extern void DecOrDirty_004a7d90(void);
extern void DecOrDirty_004a7de0(void);
extern void DrainQueueCallEach_004a1ec0(void);
extern void IncBoundedDirty_004a7db0(void);
extern void MStackPush2ChainLLInsert_00406790(void);
extern void SetJmp_004a1ac0(void);

__declspec(naked) void Audio4EntryScopeDispatch_004a7e00(void) {
    __asm {
        /* entry 1 (offset 0) */
        mov     eax, dword ptr [g_data_004f3ae8]
        mov     ecx, dword ptr [g_data_005433c8]
        dec     eax
        cmp     ecx, eax
        jge     short L_a4s_setBit
        mov     eax, ecx
        inc     eax
        mov     dword ptr [g_data_005433c8], eax
        ret
    L_a4s_setBit:
        mov     eax, dword ptr [g_xformDirtyFlags]
        or      al, 1
        mov     dword ptr [g_xformDirtyFlags], eax
        ret
        /* 10b NOP pad to 0x4a7e30 */
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
        /* entry 2 (offset 0x30) */
    L_a4s_entry2:
        call    DecOrDirty_004a7d90
        mov     eax, dword ptr [g_xformDirtyFlags]
        mov     dword ptr [g_data_00541dc4], eax
        and     al, 0xfe
        mov     dword ptr [g_xformDirtyFlags], eax
        call    DecOrDirty_004a7de0
        mov     eax, dword ptr [g_baseSel_00542060]
        cmp     dword ptr [eax*4 + 0x30], 3
        jne     short L_a4s_e2End
        mov     ecx, dword ptr [g_data_00541dc4]
        mov     dword ptr [g_xformDirtyFlags], ecx
    L_a4s_e2End:
        ret
        /* 9b NOP pad to 0x4a7e70 */
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        /* entry 3 (offset 0x70) */
    L_a4s_entry3:
        call    IncBoundedDirty_004a7db0
        mov     eax, dword ptr [g_xformDirtyFlags]
        mov     dword ptr [g_data_00541dc4], eax
        and     al, 0xfe
        mov     dword ptr [g_xformDirtyFlags], eax
        call    Audio4EntryScopeDispatch_004a7e00
        mov     eax, dword ptr [g_baseSel_00542060]
        cmp     dword ptr [eax*4 + 0x30], 3
        jne     short L_a4s_e3End
        mov     ecx, dword ptr [g_data_00541dc4]
        mov     dword ptr [g_xformDirtyFlags], ecx
    L_a4s_e3End:
        ret
        /* 9b NOP pad to 0x4a7eb0 */
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        /* entry 5 (offset 0xb0) */
    L_a4s_entry5:
        push    esi
        call    SetJmp_004a1ac0
        call    DrainQueueCallEach_004a1ec0
        mov     esi, 0x004f3c20
    L_a4s_loop1:
        movsx   eax, byte ptr [esi]
        mov     ecx, dword ptr [g_baseSel_00542060]
        add     ecx, eax
        mov     edx, dword ptr [ecx*4]
        mov     dword ptr [g_currentNodeIdx], edx
        call    MStackPush2ChainLLInsert_00406790
        add     esi, 0x24
        cmp     esi, 0x004f3d40
        jb      short L_a4s_loop1
        mov     eax, dword ptr [g_data_004f3ae4]
        xor     esi, esi
        test    eax, eax
        jle     short L_a4s_skip2
    L_a4s_loop2:
        mov     eax, dword ptr [g_baseSel_00542060]
        lea     ecx, [esi + eax]
        mov     edx, dword ptr [ecx*4 + 0x34]
        mov     dword ptr [g_currentNodeIdx], edx
        call    MStackPush2ChainLLInsert_00406790
        mov     eax, dword ptr [g_data_004f3ae4]
        inc     esi
        cmp     esi, eax
        jl      short L_a4s_loop2
    L_a4s_skip2:
        mov     eax, dword ptr [g_data_004f3ae8]
        xor     esi, esi
        test    eax, eax
        jle     short L_a4s_skip3
    L_a4s_loop3:
        mov     eax, dword ptr [g_baseSel_00542060]
        lea     ecx, [esi + eax]
        mov     edx, dword ptr [ecx*4 + 0x48]
        mov     dword ptr [g_currentNodeIdx], edx
        call    MStackPush2ChainLLInsert_00406790
        mov     eax, dword ptr [g_data_004f3ae8]
        inc     esi
        cmp     esi, eax
        jl      short L_a4s_loop3
    L_a4s_skip3:
        call    CallSetMultiGlobalsJmp_004a9230
        pop     esi
        ret
    }
}
