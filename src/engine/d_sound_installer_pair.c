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

/* @addr 0x004aede0 (241b engine.install) - DSound enumeration + open helper pair.
 *   First sub-function (0x4aede0, 62b): call DSCreate(g_data_0058c7ac, callback=L_fn2);
 *     store result; if [0x58c7ac] still null, retry via DSEnum(0, ptr, 0); ret bool.
 *   Second sub-function (0x4aee20, 177b): DSCreate(p): allocates 0x2dc-byte caps buffer
 *     on stack, queries device caps via vtbl[+0x2c], validates total memory >= 0x32c000;
 *     on success: stores object pointer; ret 0 success / 1 fail.
 *   Both are bundled as a single symbols.yaml entry (size 241 includes 2 nop pad).
 */
extern unsigned int g_data_0058c7ac;
extern unsigned int g_data_0058c7dc;
extern void DSCreateThunk_004d12d2(void);
extern void DSEnumeratorThunk_004d12cc(void);

__declspec(naked) void DSoundInstallerPair_004aede0(void) {
    __asm {
        /* sub-function 1 (0x4aede0 .. 0x4aee1d, plus 90h padding) */
        push    offset g_data_0058c7ac
        push    offset L_dsfn2
        call    DSCreateThunk_004d12d2
        mov     dword ptr [g_data_0058c7dc], eax
        mov     eax, dword ptr [g_data_0058c7ac]
        test    eax, eax
        jne     short L_dsr_done
        push    0
        push    offset g_data_0058c7ac
        push    0
        call    DSEnumeratorThunk_004d12cc
        mov     dword ptr [g_data_0058c7dc], eax
    L_dsr_done:
        mov     ecx, dword ptr [g_data_0058c7ac]
        xor     eax, eax
        test    ecx, ecx
        setne   al
        ret
        _emit   90h
        _emit   90h
    L_dsfn2:
        /* sub-function 2 (0x4aee20 .. 0x4aeed0) */
        mov     eax, [esp + 4]
        sub     esp, 0x2dc
        test    eax, eax
        push    edi
        jz      L_ds2_fail
        lea     ecx, [esp + 4]
        push    0
        push    ecx
        push    eax
        call    DSEnumeratorThunk_004d12cc
        test    eax, eax
        jl      L_ds2_fail
        mov     ecx, 0x5b
        xor     eax, eax
        lea     edi, [esp + 8]
        mov     edx, 0x16c
        rep     stosd
        mov     ecx, 0x5b
        lea     edi, [esp + 0x174]
        rep     stosd
        mov     eax, [esp + 4]
        mov     [esp + 8], edx
        test    eax, eax
        mov     [esp + 0x174], edx
        jz      short L_ds2_skipVtbl
        mov     edx, [eax]
        lea     ecx, [esp + 0x174]
        push    ecx
        lea     ecx, [esp + 0xc]
        push    ecx
        push    eax
        call    dword ptr [edx + 0x2c]
        test    eax, eax
        mov     eax, [esp + 4]
        jl      short L_ds2_releaseFail
    L_ds2_skipVtbl:
        test    byte ptr [esp + 0xc], 1
        jz      short L_ds2_releaseChk
        cmp     dword ptr [esp + 0x44], 0x32c000
        jb      short L_ds2_releaseChk
        mov     ecx, [esp + 0x2f0]
        mov     [ecx], eax
        xor     eax, eax
        pop     edi
        add     esp, 0x2dc
        ret     0x10
    L_ds2_releaseChk:
        test    eax, eax
        jz      short L_ds2_fail
    L_ds2_releaseFail:
        mov     edx, [eax]
        push    eax
        call    dword ptr [edx + 8]
    L_ds2_fail:
        mov     eax, 1
        pop     edi
        add     esp, 0x2dc
        ret     0x10
    }
}
