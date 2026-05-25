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

/* @addr 0x004b9840 (367b engine.render) - alt-camera-matrix project pass.
 *   On arg [esp+8] non-zero (use-alt-matrix flag): snapshots current
 *   camera matrix at g_data_007af990..7af9a0 into local stack 0x10/0x14/
 *   0x18/0x1c (and high-bytes), loads alternate camera matrix from
 *   g_data_00ab4d58/5c/60/64/68 into g_data_007af990..7af9a0, then calls
 *   Mat3x3VecMul6Bit_004b3590(arg, &local_vec) to project the vertex
 *   buffer at [esp+0x40] through it.
 *
 *   On arg == 0: loads 4 dwords from [arg] (mat row 0..2) and the
 *   reflected vec at [arg+8] into local stack, populates the alt
 *   camera fields, then calls Mat3x3VecMul6Bit again.
 *
 *   Always restores the original camera matrix afterward if used,
 *   writes 0x1e0 into g_data_004f623c (screen pitch?), and clamps
 *   a derived value: takes local[0x14] (negated z), shl 9, idiv ecx,
 *   then computes `(eax * 15) << 13 >> 16 + 0xf0` and clamps to
 *   (0, 0x1e0) before storing into g_data_004f623c as a u16.
 */
extern unsigned int g_data_004f623c;
extern unsigned int g_data_007af990;
extern unsigned int g_data_007af994;
extern unsigned int g_data_007af998;
extern unsigned int g_data_007af99c;
extern unsigned int g_data_007af9a0;
extern unsigned int g_data_00ab4878;
extern unsigned int g_data_00ab487c;
extern unsigned int g_data_00ab4880;
extern unsigned int g_data_00ab4884;
extern unsigned int g_data_00ab4888;
extern unsigned int g_data_00ab4d58;
extern unsigned int g_data_00ab4d5c;
extern unsigned int g_data_00ab4d60;
extern unsigned int g_data_00ab4d64;
extern unsigned int g_data_00ab4d68;
extern unsigned int g_data_00ab4e24;
extern void Mat3x3VecMul6Bit_004b3590(void);

__declspec(naked) void AltCamMatrixProject_004b9840(void) {
    __asm {
        mov     eax, dword ptr [esp + 8]
        sub     esp, 0x2c
        test    eax, eax
        push    ebx
        push    ebp
        push    esi
        push    edi
        je      short L_acm_noAlt
        mov     eax, dword ptr [g_data_007af990]
        mov     ecx, dword ptr [g_data_00ab4d58]
        mov     ebx, dword ptr [g_data_007af998]
        mov     edi, dword ptr [g_data_007af99c]
        mov     edx, dword ptr [g_data_00ab4d5c]
        mov     ebp, dword ptr [g_data_007af994]
        mov     si, word ptr [g_data_007af9a0]
        mov     dword ptr [esp + 0x1c], eax
        mov     eax, dword ptr [g_data_00ab4d60]
        mov     dword ptr [g_data_007af990], ecx
        mov     ecx, dword ptr [g_data_00ab4d64]
        mov     dword ptr [g_data_007af998], eax
        mov     dword ptr [g_data_007af99c], ecx
        mov     ecx, dword ptr [esp + 0x40]
        lea     eax, [esp + 0x10]
        mov     dword ptr [g_data_007af994], edx
        mov     dx, word ptr [g_data_00ab4d68]
        push    eax
        push    ecx
        mov     word ptr [g_data_007af9a0], dx
        call    Mat3x3VecMul6Bit_004b3590
        add     esp, 8
        jmp     short L_acm_postCall
    L_acm_noAlt:
        mov     eax, dword ptr [esp + 0x40]
        mov     si, word ptr [esp + 0x2c]
        mov     edi, dword ptr [esp + 0x28]
        mov     ebx, dword ptr [esp + 0x24]
        mov     edx, dword ptr [eax]
        mov     eax, dword ptr [eax + 8]
        mov     ebp, dword ptr [esp + 0x20]
        mov     dword ptr [esp + 0x10], edx
        mov     dword ptr [esp + 0x18], eax
    L_acm_postCall:
        mov     ecx, dword ptr [g_data_00ab4e24]
        mov     edx, dword ptr [g_data_00ab4878]
        mov     eax, dword ptr [g_data_00ab487c]
        mov     dword ptr [g_data_007af990], edx
        mov     edx, dword ptr [g_data_00ab4884]
        mov     dword ptr [g_data_007af994], eax
        neg     ecx
        mov     ax, word ptr [g_data_00ab4888]
        mov     dword ptr [esp + 0x14], ecx
        mov     ecx, dword ptr [g_data_00ab4880]
        mov     dword ptr [g_data_007af99c], edx
        mov     dword ptr [g_data_007af998], ecx
        lea     ecx, [esp + 0x10]
        lea     edx, [esp + 0x10]
        push    ecx
        push    edx
        mov     word ptr [g_data_007af9a0], ax
        call    Mat3x3VecMul6Bit_004b3590
        mov     eax, dword ptr [esp + 0x4c]
        add     esp, 8
        test    eax, eax
        je      short L_acm_skipRestore
        mov     eax, dword ptr [esp + 0x1c]
        mov     dword ptr [g_data_007af994], ebp
        mov     dword ptr [g_data_007af990], eax
        mov     dword ptr [g_data_007af998], ebx
        mov     dword ptr [g_data_007af99c], edi
        mov     word ptr [g_data_007af9a0], si
    L_acm_skipRestore:
        mov     ecx, dword ptr [esp + 0x18]
        mov     word ptr [g_data_004f623c], 0x1e0
        test    ecx, ecx
        jle     short L_acm_done
        mov     eax, dword ptr [esp + 0x14]
        shl     eax, 9
        cdq
        idiv    ecx
        lea     eax, [eax + eax*2]
        lea     eax, [eax + eax*4]
        shl     eax, 0xd
        sar     eax, 0x10
        add     eax, 0xf0
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        jle     short L_acm_done
        cmp     eax, 0x1e0
        jge     short L_acm_done
        mov     word ptr [g_data_004f623c], ax
    L_acm_done:
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        add     esp, 0x2c
        ret
    }
}
