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

/* @addr 0x004d0f50 (304b other) - CRT mbstowcs / mb-to-wide convert dispatcher.
 *   Caches result of GetCPInfo (or similar) in g_data_00f9fd9c (1/2 state).
 *   If state=1: simple passthrough call. If state=2: full conversion via
 *     IAT[0x4d2134] + IAT[0x4d20e4] (MultiByteToWideChar). Uses g_data_00f9fc20
 *     as default codepage when arg is 0.
 */
extern unsigned int g_data_00f9fc20;
extern unsigned int g_data_00f9fd9c;
extern unsigned int g_iat_004d20e4;
extern unsigned int g_iat_004d2130;
extern unsigned int g_iat_004d2134;
extern void FreeImpl_004c55f0(void);
extern void LoadArgPushCall_004c54b0(void);

__declspec(naked) void MbToWcsDispatcher_004d0f50(void) {
    __asm {
        mov     eax, dword ptr [g_data_00f9fd9c]
        push    ebx
        push    ebp
        push    esi
        mov     esi, dword ptr [g_iat_004d2130]
        push    edi
        test    eax, eax
        jne     short L_mw_haveState
        push    0
        push    0
        push    1
        push    0
        call    esi
        test    eax, eax
        jz      short L_mw_tryAlt
        mov     eax, 1
        jmp     short L_mw_setState
    L_mw_tryAlt:
        push    0
        push    0
        push    1
        push    0
        call    dword ptr [g_iat_004d2134]
        test    eax, eax
        jz      L_mw_returnZero
        mov     eax, 2
    L_mw_setState:
        mov     dword ptr [g_data_00f9fd9c], eax
    L_mw_haveState:
        cmp     eax, 1
        jne     short L_mw_state2
        mov     eax, [esp + 0x20]
        mov     ecx, [esp + 0x1c]
        mov     edx, [esp + 0x18]
        push    eax
        mov     eax, [esp + 0x18]
        push    ecx
        push    edx
        push    eax
        call    esi
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        ret
    L_mw_state2:
        cmp     eax, 2
        jne     L_mw_fail
        mov     eax, [esp + 0x24]
        test    eax, eax
        jne     short L_mw_haveCP
        mov     ecx, dword ptr [g_data_00f9fc20]
        mov     [esp + 0x24], ecx
    L_mw_haveCP:
        mov     ebx, [esp + 0x18]
        mov     ebp, [esp + 0x14]
        push    0
        push    0
        push    ebx
        push    ebp
        call    dword ptr [g_iat_004d2134]
        mov     esi, eax
        test    esi, esi
        jne     short L_mw_alloc
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        ret
    L_mw_alloc:
        push    esi
        call    LoadArgPushCall_004c54b0
        mov     edi, eax
        add     esp, 4
        test    edi, edi
        jne     short L_mw_doConv
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        ret
    L_mw_doConv:
        push    esi
        push    edi
        push    ebx
        push    ebp
        call    dword ptr [g_iat_004d2134]
        test    eax, eax
        jz      short L_mw_cleanupZero
        mov     eax, [esp + 0x20]
        test    eax, eax
        jne     short L_mw_useEax
        mov     edx, [esp + 0x24]
        push    eax
        push    eax
        push    -1
        push    edi
        push    1
        push    edx
        call    dword ptr [g_iat_004d20e4]
        mov     esi, eax
        test    esi, esi
        jz      short L_mw_cleanupZero
        push    edi
        call    FreeImpl_004c55f0
        add     esp, 4
        mov     eax, esi
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        ret
    L_mw_useEax:
        mov     ecx, [esp + 0x24]
        push    eax
        mov     eax, [esp + 0x20]
        push    eax
        push    -1
        push    edi
        push    1
        push    ecx
        call    dword ptr [g_iat_004d20e4]
        mov     esi, eax
        test    esi, esi
        jne     short L_mw_freeAndReturn
    L_mw_cleanupZero:
        push    edi
        call    FreeImpl_004c55f0
        add     esp, 4
    L_mw_returnZero:
        xor     eax, eax
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        ret
    L_mw_freeAndReturn:
        push    edi
        call    FreeImpl_004c55f0
        add     esp, 4
        mov     eax, esi
    L_mw_fail:
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        ret
    }
}
