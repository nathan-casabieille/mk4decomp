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

/* @addr 0x004c5e00 (369b crt) - _splitpath implementation.
 *   Splits the path string at [esp+0x10] into drive, dir, name, ext.
 *   Args: path (esp+0x10), drive_out (esp+0x1c), dir_out (esp+0x20),
 *   name_out (esp+0x24), ext_out (esp+0x28).
 *   1. Computes path length via repne scasb.
 *   2. If length >= 1 and path[1] == ':', extracts the 2-char drive
 *      to drive_out via FgetsImpl_004c9a30(out, src, 2), advances ebp
 *      past the drive. Else nulls drive_out if non-null.
 *   3. Walks the path identifying alphanumeric chars via the ctype
 *      table at g_data_00f9f8c1 (bit 4 = "valid path char"), records
 *      the LAST '/' or '\' position into ebp (for dir-end), and the
 *      LAST '.' position into esp+0x10 (for ext-start).
 *   4. Copies the dir (capped at 0xff) to dir_out, then name and ext
 *      similarly. Null-terminates each output as needed.
 *   Returns nothing (void).
 */
extern unsigned int g_data_00f9f8c1;
extern void FgetsImpl_004c9a30(void);

__declspec(naked) void SplitPath_004c5e00(void) {
    __asm {
        push    ecx
        push    ebx
        push    ebp
        mov     ebp, dword ptr [esp + 0x10]
        push    esi
        push    edi
        mov     edi, ebp
        or      ecx, 0xffffffff
        xor     eax, eax
        repne scasb
        not     ecx
        dec     ecx
        mov     dword ptr [esp + 0x10], 0
        cmp     ecx, 1
        jb      short L_sp_noDrive
        cmp     byte ptr [ebp + 1], 0x3a
        jne     short L_sp_noDrive
        mov     esi, dword ptr [esp + 0x1c]
        test    esi, esi
        je      short L_sp_skipDrive
        push    2
        push    ebp
        push    esi
        call    FgetsImpl_004c9a30
        add     esp, 0xc
        mov     byte ptr [esi + 2], 0
    L_sp_skipDrive:
        add     ebp, 2
        jmp     short L_sp_scanLoop
    L_sp_noDrive:
        mov     eax, dword ptr [esp + 0x1c]
        test    eax, eax
        je      short L_sp_scanLoop
        mov     byte ptr [eax], 0
    L_sp_scanLoop:
        mov     cl, byte ptr [ebp]
        xor     eax, eax
        test    cl, cl
        mov     dword ptr [esp + 0x1c], eax
        mov     esi, ebp
        je      short L_sp_afterScan
        mov     cl, 4
    L_sp_scanIter:
        mov     al, byte ptr [esi]
        mov     edx, eax
        and     edx, 0xff
        test    byte ptr [edx + g_data_00f9f8c1], cl
        je      short L_sp_checkSeps
        inc     esi
        jmp     short L_sp_scanNext
    L_sp_checkSeps:
        cmp     al, 0x2f
        je      short L_sp_isSep
        cmp     al, 0x5c
        je      short L_sp_isSep
        cmp     al, 0x2e
        jne     short L_sp_scanNext
        mov     dword ptr [esp + 0x10], esi
        jmp     short L_sp_scanNext
    L_sp_isSep:
        lea     eax, [esi + 1]
        mov     dword ptr [esp + 0x1c], eax
    L_sp_scanNext:
        mov     al, byte ptr [esi + 1]
        inc     esi
        test    al, al
        jne     short L_sp_scanIter
        mov     eax, dword ptr [esp + 0x1c]
    L_sp_afterScan:
        test    eax, eax
        je      short L_sp_dirNull
        mov     ebx, dword ptr [esp + 0x20]
        test    ebx, ebx
        je      short L_sp_skipDirCopy
        sub     eax, ebp
        cmp     eax, 0xff
        mov     edi, eax
        jb      short L_sp_dirOk
        mov     edi, 0xff
    L_sp_dirOk:
        push    edi
        push    ebp
        push    ebx
        call    FgetsImpl_004c9a30
        add     esp, 0xc
        mov     byte ptr [edi + ebx], 0
    L_sp_skipDirCopy:
        mov     ebp, dword ptr [esp + 0x1c]
        jmp     short L_sp_haveBase
    L_sp_dirNull:
        mov     eax, dword ptr [esp + 0x20]
        test    eax, eax
        je      short L_sp_haveBase
        mov     byte ptr [eax], 0
    L_sp_haveBase:
        mov     eax, dword ptr [esp + 0x10]
        test    eax, eax
        je      short L_sp_noExt
        cmp     eax, ebp
        jb      short L_sp_noExt
        mov     ebx, dword ptr [esp + 0x24]
        test    ebx, ebx
        je      short L_sp_nameOnly
        sub     eax, ebp
        cmp     eax, 0xff
        mov     edi, eax
        jb      short L_sp_nameOk
        mov     edi, 0xff
    L_sp_nameOk:
        push    edi
        push    ebp
        push    ebx
        call    FgetsImpl_004c9a30
        add     esp, 0xc
        mov     byte ptr [edi + ebx], 0
    L_sp_nameOnly:
        mov     edi, dword ptr [esp + 0x28]
        test    edi, edi
        je      short L_sp_done
        mov     eax, dword ptr [esp + 0x10]
        sub     esi, eax
        cmp     esi, 0xff
        jb      short L_sp_extOk
        mov     esi, 0xff
    L_sp_extOk:
        push    esi
        push    eax
        push    edi
        call    FgetsImpl_004c9a30
        add     esp, 0xc
        mov     byte ptr [esi + edi], 0
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        pop     ecx
        ret
    L_sp_noExt:
        mov     edi, dword ptr [esp + 0x24]
        test    edi, edi
        je      short L_sp_extNull
        sub     esi, ebp
        cmp     esi, 0xff
        jb      short L_sp_lastOk
        mov     esi, 0xff
    L_sp_lastOk:
        push    esi
        push    ebp
        push    edi
        call    FgetsImpl_004c9a30
        add     esp, 0xc
        mov     byte ptr [esi + edi], 0
    L_sp_extNull:
        mov     eax, dword ptr [esp + 0x28]
        test    eax, eax
        je      short L_sp_done
        mov     byte ptr [eax], 0
    L_sp_done:
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        pop     ecx
        ret
    }
}
