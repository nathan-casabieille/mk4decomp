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

/* @addr 0x004cd950 (388b crt) - MultiByteToWideChar wrapper w/ probing.
 *   On first call, probes IAT [0x4d20b8] (MultiByteToWideChar-like) with
 *   "test 1" sample 0x4d2f24; if it works → g_data_00f9fc2c = 1 (NT path).
 *   Else probes IAT [0x4d20bc] (CompareStringA-like) with 0x4d2f20;
 *   if that works → 2 (9x path). Else returns 0.
 *
 *   On subsequent calls (state cached at 0x00f9fc2c):
 *     state 1: direct call IAT [0x4d20b8] with (cp, flags, src, srclen).
 *     state 2: lookup string length via IAT [0x4d20e0] (LCMapStringA-like)
 *              with code-page 0x220; on failure return 0. Else
 *              calloc(len*2+2) via LoadArgPushCall_004c54b0, populate via
 *              [0x4d20e0] again with proper Unicode flags, verify the
 *              sentinel 0xffff at end+0, end-1 if intact, call CrtMemMove_004c61c0
 *              (likely WideCharToMultiByte). Free both bufs via FreeImpl.
 */
extern unsigned int g_data_004d20b8;
extern unsigned int g_data_004d20bc;
extern unsigned int g_data_004d20e0;
extern unsigned int g_data_004d2f20;
extern unsigned int g_data_004d2f24;
extern unsigned int g_data_00f9fc10;
extern unsigned int g_data_00f9fc20;
extern unsigned int g_data_00f9fc2c;
extern void Calloc_004c6110(void);
extern void CrtMemMove_004c61c0(void);
extern void FreeImpl_004c55f0(void);
extern void LoadArgPushCall_004c54b0(void);

__declspec(naked) void MBToWCharCachedDispatch_004cd950(void) {
    __asm {
        push    ecx
        mov     eax, dword ptr [g_data_00f9fc2c]
        push    ebx
        xor     ebx, ebx
        push    ebp
        push    esi
        mov     esi, dword ptr [g_data_004d20b8]
        cmp     eax, ebx
        push    edi
        jne     short L_mbw_haveState
        lea     eax, [esp + 0x10]
        push    eax
        push    1
        push    offset g_data_004d2f24
        push    1
        call    esi
        test    eax, eax
        je      short L_mbw_tryAlt
        mov     eax, 1
        jmp     short L_mbw_setCache
    L_mbw_tryAlt:
        lea     ecx, [esp + 0x10]
        push    ecx
        push    1
        push    offset g_data_004d2f20
        push    1
        push    ebx
        call    dword ptr [g_data_004d20bc]
        test    eax, eax
        je      L_mbw_zeroRet
        mov     eax, 2
    L_mbw_setCache:
        mov     dword ptr [g_data_00f9fc2c], eax
    L_mbw_haveState:
        cmp     eax, 1
        jne     short L_mbw_state2
        mov     edx, dword ptr [esp + 0x24]
        mov     eax, dword ptr [esp + 0x20]
        mov     ecx, dword ptr [esp + 0x1c]
        push    edx
        mov     edx, dword ptr [esp + 0x1c]
        push    eax
        push    ecx
        push    edx
        call    esi
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        pop     ecx
        ret
    L_mbw_state2:
        cmp     eax, 2
        jne     L_mbw_simpleRet
        mov     eax, dword ptr [esp + 0x28]
        mov     dword ptr [esp + 0x10], ebx
        cmp     eax, ebx
        jne     short L_mbw_haveArg28
        mov     eax, dword ptr [g_data_00f9fc20]
        mov     dword ptr [esp + 0x28], eax
    L_mbw_haveArg28:
        mov     edi, dword ptr [esp + 0x20]
        mov     ecx, dword ptr [esp + 0x1c]
        mov     edx, dword ptr [esp + 0x28]
        push    ebx
        push    ebx
        push    ebx
        push    ebx
        push    edi
        push    ecx
        push    0x220
        push    edx
        call    dword ptr [g_data_004d20e0]
        mov     esi, eax
        cmp     esi, ebx
        jne     short L_mbw_havelen
        xor     eax, eax
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        pop     ecx
        ret
    L_mbw_havelen:
        push    esi
        push    1
        call    Calloc_004c6110
        mov     ebp, eax
        add     esp, 8
        test    ebp, ebp
        jne     short L_mbw_haveBuf1
    L_mbw_zeroRet:
        xor     eax, eax
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        pop     ecx
        ret
    L_mbw_haveBuf1:
        mov     eax, dword ptr [esp + 0x1c]
        mov     ecx, dword ptr [esp + 0x28]
        push    0
        push    0
        push    esi
        push    ebp
        push    edi
        push    eax
        push    0x220
        push    ecx
        call    dword ptr [g_data_004d20e0]
        test    eax, eax
        je      short L_mbw_freeAndExit
        lea     edx, [esi + esi + 2]
        push    edx
        call    LoadArgPushCall_004c54b0
        mov     ebx, eax
        add     esp, 4
        test    ebx, ebx
        je      short L_mbw_freeAndExit
        mov     eax, dword ptr [esp + 0x2c]
        test    eax, eax
        jne     short L_mbw_haveCp
        mov     eax, dword ptr [g_data_00f9fc10]
    L_mbw_haveCp:
        mov     ecx, dword ptr [esp + 0x18]
        push    ebx
        add     edi, edi
        push    esi
        push    ebp
        push    ecx
        mov     word ptr [ebx + edi], 0xffff
        push    eax
        mov     word ptr [ebx + edi - 2], 0xffff
        call    dword ptr [g_data_004d20bc]
        /* MASM picks cmp r/m16, imm8 (66 83) for 0xffff sign-extension; orig
         * uses the full 7-byte imm16 form (66 81). Emit raw bytes to match. */
        _emit 0x66
        _emit 0x81
        _emit 0x7c
        _emit 0x3b
        _emit 0xfe
        _emit 0xff
        _emit 0xff
        mov     dword ptr [esp + 0x10], eax
        je      short L_mbw_zeroFinal
        _emit 0x66
        _emit 0x81
        _emit 0x3c
        _emit 0x3b
        _emit 0xff
        _emit 0xff
        jne     short L_mbw_zeroFinal
        mov     edx, dword ptr [esp + 0x24]
        push    edi
        push    ebx
        push    edx
        call    CrtMemMove_004c61c0
        add     esp, 0xc
        jmp     short L_mbw_freeAndExit
    L_mbw_zeroFinal:
        mov     dword ptr [esp + 0x10], 0
    L_mbw_freeAndExit:
        push    ebp
        call    FreeImpl_004c55f0
        add     esp, 4
        push    ebx
        call    FreeImpl_004c55f0
        mov     eax, dword ptr [esp + 0x14]
        add     esp, 4
    L_mbw_simpleRet:
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        pop     ecx
        ret
    }
}
