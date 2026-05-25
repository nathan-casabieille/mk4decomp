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
extern unsigned int g_installOwnerNode_00535cf8;
extern unsigned int g_cj_00542054;
extern unsigned int g_data_005437f0;
extern unsigned int g_data_00543598;
extern unsigned int g_data_0054358c;
extern unsigned int g_fightAxisNegX_00535e70;
extern unsigned int g_fightAxisNegY_00535e74;
extern unsigned int g_fightAxisPosX_00535e78;
extern unsigned int g_fightAxisPosY_00535e7c;

/* ============================================================
 * Phase4StateInitWithHelpers_004143f0 - 626b boot.
 *
 * Three packed entries in one .text block:
 *
 *   - Main at 0x4143f0 (413b, ends at 0x41458c c3): 1-slot
 *     mstack-bracketed routine that calls into a state-walker
 *     loop. Sets up a slot's field [0x30]=0x9b, [0x48]=0x28f,
 *     installs callback 0x00414590 at [+0x10], then loops over
 *     pending work via mstack pop + ChainNodeAdvanceCallback_00408e70. Falls into
 *     a tail at 0x41453b on negative-stack or via the L_skip
 *     branch when bit 4 of g_xformDirtyFlags is already set.
 *
 *   - Helper A at 0x414590 (106b, ends with jmp ClampMulShiftStore_004ba0e0):
 *     bumps slot[+0x48] += 0xCCC (cap 0x10000) and
 *     slot[+0x14] += 6 (cap 0xC0); tail-jumps to ClampMulShiftStore_004ba0e0.
 *     Installed via the literal `mov [eax+0x10], 0x00414590`.
 *
 *   - Helper B at 0x414600 (98b, ends with jmp ClampMulShiftStore_004ba0e0):
 *     bumps slot[+0x48] += 0x28F (cap 0x14CCC) and
 *     slot[+0x14] -= 6 (floor 0); tail-jumps to ClampMulShiftStore_004ba0e0.
 *     Installed externally (SetDirty4XorScaledLoad_004147b0
 *     uses the literal `mov ecx, 0x00414600`).
 *
 * Padding between sections is `nop` (0x90) - 3 bytes after the
 * main's `ret`, 6 bytes after Helper A's `jmp` - matching MSVC
 * 5.0's 16-byte function alignment.
 *
 * The literal callback addresses (0x00414590) avoid a DIR32
 * reloc; the original is similarly a raw imm32, so the bytes
 * must match exactly.
 * ============================================================ */

extern unsigned int g_data_004d6a18;
extern unsigned int g_data_00543800;
extern unsigned int g_eventQueueEnd;
extern unsigned int g_fightGroupHead;
extern unsigned int g_framePauseFlag;
extern unsigned int g_currentNodeIdx;
extern unsigned int g_xformEntityIdx;
extern unsigned int g_pendingNodeType;
extern void ChainNodeAdvanceCallback_00408e70(void);
extern void MStackCall_00406600(void);
extern void PushSetXfmMaskCallPop_00407140(void);
extern void ZeroAndDirty4_00405430(void);
extern void ClampMulShiftStore_004ba0e0(void);

__declspec(naked) void Phase4StateInitWithHelpers_004143f0(void)
{
    __asm {
        mov     eax, dword ptr [g_state_004d57ac]
        mov     ecx, dword ptr [g_eventQueueEnd]
        inc     eax
        push    ebx
        mov     dword ptr [g_state_004d57ac], eax
        mov     dword ptr [eax*4], ecx
        mov     dword ptr [g_fightGroupHead], 0
        mov     dword ptr [g_walkCallback], 0xEB85
        call    ZeroAndDirty4_00405430
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4s_pop1
        mov     al, byte ptr [g_xformDirtyFlags]
        mov     ebx, 4
        test    al, bl
        je      L_p4s_skip_body
        mov     edx, offset g_data_004d6a18
        shr     edx, 2
        mov     dword ptr [g_walkCallback], edx
        call    PushSetXfmMaskCallPop_00407140
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4s_pop1
        test    byte ptr [g_xformDirtyFlags], bl
        jne     L_p4s_skip_body
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     eax, 0x9B
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x30], eax
        mov     edx, dword ptr [g_fightGroupHead]
        mov     eax, dword ptr [edx*4 + 0x18]
        mov     dword ptr [g_currentNodeIdx], eax
        mov     eax, dword ptr [eax*4 + 0x28]
        mov     dword ptr [g_xformEntityIdx], eax
        shl     eax, 2
        mov     dword ptr [eax + 0x10], 0x00414590
        mov     dword ptr [g_walkCallback], 0
        mov     edx, dword ptr [eax]
        mov     dword ptr [eax + 0x14], 0
        or      edx, 8
        mov     dword ptr [eax + 0x48], 0x28F
        mov     dword ptr [eax], edx
        mov     eax, dword ptr [g_pendingNodeType]
        dec     eax
        mov     dword ptr [g_pendingNodeType], eax
        mov     dword ptr [g_walkCallback], eax
        js      L_p4s_alt_tail
        mov     ecx, dword ptr [g_state_004d57ac]
        inc     ecx
        mov     dword ptr [g_state_004d57ac], ecx
        mov     dword ptr [ecx*4], eax
        call    ChainNodeAdvanceCallback_00408e70
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4s_pop1
    L_p4s_loop_top:
        mov     eax, dword ptr [g_state_004d57ac]
        mov     ecx, dword ptr [eax*4]
        dec     eax
        dec     ecx
        mov     dword ptr [g_state_004d57ac], eax
        mov     dword ptr [g_pendingNodeType], ecx
        js      L_p4s_alt_tail
        inc     eax
        mov     dword ptr [g_state_004d57ac], eax
        mov     dword ptr [eax*4], ecx
        call    ChainNodeAdvanceCallback_00408e70
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        je      L_p4s_loop_top
        pop     ebx
        ret
    L_p4s_alt_tail:
        mov     eax, dword ptr [g_fightGroupHead]
        mov     dword ptr [g_currentNodeIdx], eax
        call    MStackCall_00406600
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4s_pop1
    L_p4s_skip_body:
        mov     ecx, dword ptr [g_xformDirtyFlags]
        mov     eax, dword ptr [g_fightGroupHead]
        or      ecx, ebx
        test    eax, eax
        mov     dword ptr [g_xformDirtyFlags], ecx
        je      L_p4s_pop1_doit
        mov     eax, ecx
        xor     eax, ebx
        mov     dword ptr [g_xformDirtyFlags], eax
    L_p4s_pop1_doit:
        mov     eax, dword ptr [g_state_004d57ac]
        mov     ecx, dword ptr [eax*4]
        dec     eax
        mov     dword ptr [g_eventQueueEnd], ecx
        mov     dword ptr [g_state_004d57ac], eax
    L_p4s_pop1:
        pop     ebx
        ret
        nop
        nop
        nop
    L_p4s_helperA:
        mov     eax, dword ptr [g_data_00543800]
        test    eax, eax
        jne     L_p4s_helperA_tail
        mov     ecx, dword ptr [g_xformEntityIdx]
        mov     eax, dword ptr [ecx*4 + 0x48]
        add     eax, 0xCCC
        cmp     eax, 0x10000
        mov     dword ptr [g_walkCallback], eax
        jle     L_p4s_helperA_cap48_ok
        mov     eax, 0x10000
        mov     dword ptr [g_walkCallback], eax
    L_p4s_helperA_cap48_ok:
        mov     dword ptr [ecx*4 + 0x48], eax
        mov     ecx, dword ptr [g_xformEntityIdx]
        mov     eax, dword ptr [ecx*4 + 0x14]
        add     eax, 6
        cmp     eax, 0xC0
        mov     dword ptr [g_walkCallback], eax
        jle     L_p4s_helperA_cap14_ok
        mov     eax, 0xC0
        mov     dword ptr [g_walkCallback], eax
    L_p4s_helperA_cap14_ok:
        mov     dword ptr [ecx*4 + 0x14], eax
    L_p4s_helperA_tail:
        jmp     ClampMulShiftStore_004ba0e0
        nop
        nop
        nop
        nop
        nop
        nop
    L_p4s_helperB:
        mov     eax, dword ptr [g_data_00543800]
        test    eax, eax
        jne     L_p4s_helperB_tail
        mov     ecx, dword ptr [g_xformEntityIdx]
        mov     eax, dword ptr [ecx*4 + 0x48]
        add     eax, 0x28F
        cmp     eax, 0x14CCC
        mov     dword ptr [g_walkCallback], eax
        jle     L_p4s_helperB_cap48_ok
        mov     eax, 0x14CCC
        mov     dword ptr [g_walkCallback], eax
    L_p4s_helperB_cap48_ok:
        mov     dword ptr [ecx*4 + 0x48], eax
        mov     ecx, dword ptr [g_xformEntityIdx]
        mov     eax, dword ptr [ecx*4 + 0x14]
        sub     eax, 6
        mov     dword ptr [g_walkCallback], eax
        jns     L_p4s_helperB_cap14_ok
        xor     eax, eax
        mov     dword ptr [g_walkCallback], eax
    L_p4s_helperB_cap14_ok:
        mov     dword ptr [ecx*4 + 0x14], eax
    L_p4s_helperB_tail:
        jmp     ClampMulShiftStore_004ba0e0
    }
}
