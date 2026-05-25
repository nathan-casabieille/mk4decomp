/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;
extern unsigned int g_baseSel_00542060;
extern unsigned int g_acc_00542078;
extern unsigned int g_cj_0054205c;
extern unsigned int g_gameCountdown_0053a718;
extern unsigned int g_xformScratch94;
extern unsigned int g_table_00535ddc;
extern unsigned int g_active_00537e88;
extern unsigned int g_active_0053a408;
extern unsigned int g_audioBankSel_00537f94;

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
extern unsigned int g_cj_00542058;
extern unsigned int g_rangeSqLimit_0053a180;
extern unsigned int g_zero_00541fa4;
extern unsigned int g_zero_00541fa8;
extern unsigned int g_dualBitGate_0053a7b0;
extern unsigned int g_eventArmReload_0053a770;
extern unsigned int g_rangeBase_0053a46c;

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
extern unsigned int g_installOwnerNode_00535cf8;
extern unsigned int g_cj_00542054;
extern unsigned int g_audioBoundNode_005437f0;
extern unsigned int g_lastGatedValue_00543598;
extern unsigned int g_lastGatedTick_0054358c;
extern unsigned int g_fightAxisNegX_00535e70;
extern unsigned int g_fightAxisNegY_00535e74;
extern unsigned int g_fightAxisPosX_00535e78;
extern unsigned int g_fightAxisPosY_00535e7c;

/* @addr 0x004b31e0 (301b engine.app) - 2x3-vector × 3x3-matrix Q12 multiply.
 *   Calls Word9Reorder_004b3b30(0x007af990, &local) to pull 9 words into local
 *   stack buf. Computes 6 Q12 dot products:
 *     out[0..2] = M_row0 . v0,  M_row0 . v1
 *     out[3..5] = M_row1 . v0,  M_row1 . v1
 *   (where v0 is words at +0x18, v1 at +0x1c). Matrix is in
 *   g_arr_007af9c0..d4. Results stored to g_vtxLight0_x..ec.
 */
extern s16 g_vtxMat[];
extern unsigned int g_arr_007af9c0;
extern unsigned int g_arr_007af9c4;
extern unsigned int g_arr_007af9c8;
extern unsigned int g_data_007af9cc;
extern unsigned int g_data_007af9d0;
extern unsigned int g_data_007af9d4;
extern s32 g_vtxLight0_x;
extern s32 g_vtxLight0_y;
extern s32 g_vtxLight0_z;
extern s32 g_vtxLight1_x;
extern s32 g_vtxLight1_z;
extern s32 g_vtxLight1_y;
extern void Word9Reorder_004b3b30(void);

__declspec(naked) void MatVec2Multiply_004b31e0(void) {
    __asm {
        sub     esp, 0x20
        _emit   8dh
        _emit   44h
        _emit   24h
        _emit   0h
        push    ebx
        push    ebp
        push    esi
        push    edi
        push    eax
        push    offset g_vtxMat
        call    Word9Reorder_004b3b30
        movsx   esi, word ptr [esp + 0x18]
        movsx   edx, word ptr [esp + 0x1a]
        mov     eax, dword ptr [g_arr_007af9c0]
        mov     ecx, dword ptr [g_arr_007af9c4]
        mov     ebx, eax
        mov     ebp, ecx
        imul    ebx, esi
        imul    ebp, edx
        movsx   edi, word ptr [esp + 0x1c]
        mov     edx, dword ptr [g_arr_007af9c8]
        add     ebx, ebp
        mov     ebp, edx
        add     esp, 8
        imul    ebp, edi
        movsx   edi, word ptr [esp + 0x16]
        add     ebx, ebp
        mov     ebp, eax
        sar     ebx, 0x0c
        imul    ebp, edi
        mov     dword ptr [g_vtxLight0_x], ebx
        mov     edi, ecx
        movsx   ebx, word ptr [esp + 0x18]
        imul    edi, ebx
        add     ebp, edi
        mov     ebx, edx
        movsx   edi, word ptr [esp + 0x1a]
        imul    ebx, edi
        add     ebp, ebx
        movsx   ebx, word ptr [esp + 0x1c]
        sar     ebp, 0x0c
        imul    eax, ebx
        movsx   ebx, word ptr [esp + 0x1e]
        mov     dword ptr [g_vtxLight0_y], ebp
        imul    ecx, ebx
        movsx   ebp, word ptr [esp + 0x20]
        imul    edx, ebp
        add     eax, ecx
        mov     ecx, dword ptr [g_data_007af9d0]
        add     eax, edx
        movsx   edx, word ptr [esp + 0x12]
        sar     eax, 0x0c
        mov     dword ptr [g_vtxLight0_z], eax
        mov     eax, dword ptr [g_data_007af9cc]
        mov     ebx, eax
        imul    ebx, esi
        mov     esi, ecx
        imul    esi, edx
        mov     edx, dword ptr [g_data_007af9d4]
        add     ebx, esi
        movsx   esi, word ptr [esp + 0x14]
        mov     ebp, edx
        imul    ebp, esi
        movsx   esi, word ptr [esp + 0x16]
        add     ebx, ebp
        mov     ebp, ecx
        sar     ebx, 0x0c
        mov     dword ptr [g_vtxLight1_x], ebx
        mov     ebx, eax
        imul    ebx, esi
        movsx   esi, word ptr [esp + 0x18]
        imul    ebp, esi
        mov     esi, edx
        add     ebx, ebp
        imul    esi, edi
        add     ebx, esi
        movsx   esi, word ptr [esp + 0x1c]
        imul    eax, esi
        movsx   esi, word ptr [esp + 0x1e]
        imul    ecx, esi
        sar     ebx, 0x0c
        mov     dword ptr [g_vtxLight1_z], ebx
        add     eax, ecx
        movsx   ecx, word ptr [esp + 0x20]
        imul    edx, ecx
        add     eax, edx
        pop     edi
        sar     eax, 0x0c
        pop     esi
        pop     ebp
        mov     dword ptr [g_vtxLight1_y], eax
        pop     ebx
        add     esp, 0x20
        ret
    }
}
