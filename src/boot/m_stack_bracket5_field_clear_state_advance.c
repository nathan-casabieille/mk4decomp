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

extern void MStackBracket5_FieldClear_StateAdvance_00405630(void);

/* @addr 0x00406c10 (198b boot) - call F; pause? ret; (208c&4)? ret;
 *   chain[g_scaledInit + 0x24] = g_xformEntityIdx;
 *   mstack-push *g_xformEntityIdx;
 *   chain[g_scaledInit + 0x1c] = (val >> 20);
 *   chain[g_scaledInit + 0x20] = (mstack-pop & 0xfffff) | 0x08000000;
 *   g_xformDirtyFlags |= 4; if g_scaledInit == 0: ret; else: clear bit 2.
 */

extern unsigned int g_data_004d57ac_arr;

void FramePauseScaledStore_00406c10(void) {
    __asm {
        call    MStackBracket5_FieldClear_StateAdvance_00405630
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   0b3h
        _emit   00h
        _emit   00h
        _emit   00h
        mov     al, byte ptr [g_xformDirtyFlags]
        mov     edx, 4
        test    al, dl
        _emit   0fh
        _emit   85h
        _emit   0a1h
        _emit   00h
        _emit   00h
        _emit   00h
        mov     ecx, dword ptr [g_scaledInit_00542044]
        mov     eax, dword ptr [g_xformEntityIdx]
        mov     [ecx*4 + 0x24], eax
        mov     eax, dword ptr [g_xformEntityIdx]
        mov     ecx, dword ptr [g_matrixStackTop]
        mov     eax, [eax*4 + g_data_004d57ac_arr]
        inc     ecx
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [g_matrixStackTop], ecx
        mov     [ecx*4 + g_data_004d57ac_arr], eax
        mov     eax, dword ptr [g_walkCallback]
        mov     ecx, dword ptr [g_scaledInit_00542044]
        sar     eax, 0x14
        mov     dword ptr [g_walkCallback], eax
        mov     [ecx*4 + 0x1c], eax
        mov     ecx, dword ptr [g_matrixStackTop]
        mov     eax, [ecx*4 + g_data_004d57ac_arr]
        dec     ecx
        and     eax, 0x000fffff
        mov     dword ptr [g_matrixStackTop], ecx
        mov     ecx, dword ptr [g_scaledInit_00542044]
        or      eax, 0x08000000
        mov     dword ptr [g_walkCallback], eax
        mov     [ecx*4 + 0x20], eax
        mov     ecx, dword ptr [g_xformDirtyFlags]
        mov     eax, dword ptr [g_scaledInit_00542044]
        or      ecx, edx
        test    eax, eax
        mov     dword ptr [g_xformDirtyFlags], ecx
        _emit   74h
        _emit   09h
        mov     eax, ecx
        xor     eax, edx
        mov     dword ptr [g_xformDirtyFlags], eax
        }
}

