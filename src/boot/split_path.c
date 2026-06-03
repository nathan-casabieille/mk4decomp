/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_currentNodeIdx;
extern unsigned int g_baseSel;
extern unsigned int g_acc_00542078;
extern unsigned int g_cj_0054205c;
extern unsigned int g_gameCountdown;
extern unsigned int g_xformScratch94;
extern unsigned int g_fightStateProgress;
extern unsigned int g_active_00537e88;
extern unsigned int g_active_0053a408;
extern unsigned int g_audioBankSel;

extern void StoreTwoCall(int, int);
extern void SetJmp_Thunk_LinkedListBitMaskSearch(void);
extern void Thunk_ChainNodeInit(void);
extern void ScaledZeroFour(void);
extern void WalkCbSubMul10(void);
extern void Mul10Tail(unsigned int a, unsigned int b);
extern void BootMod6487eClampAndChainMul10(void);
extern void SpawnListBatchLoader(void);
extern void MStackPush2TableNot(void);
extern void GuardedChainCmpDualBitXor(void);
extern void ScaledLoadDecJmp(void);
extern void ScaledStoreCurDirtyClear(void);
extern void MStackBitmaskIncMod(void);
extern void MStackBitmaskUpdate(void);
extern void Push1eCallTestDirtyLoop(void);
extern void MStackLoopFieldInit(void);
extern void TaggedSceneDispatch(void);
extern void CallPauseDirty4StackPushFn(void);
extern void CallPauseDirty1JmpDirty4StackPush_GuardedDoubleIncCmpJmp(void);
extern void Cmp2CallDirtyCall(void);
extern void QuadBlockArgInstallChain(void);
extern void InstallSelfChainSet84_80CallW(void);
extern void Wrapper_PackedAdvanceCallTailJmp_004e46d0(void);
extern void MoveFsmCluster(void);
extern void CallPauseTestByteJmpCalls(void);
extern void InstallSelfFullPath(void);
extern void InstallSelfCountdownChain(void);
extern void CopyJmp_SlotCmp3way_g_currentNodeIdx(void);
extern void DualTestDirtyToggle_004282c0(void);
extern void TripleVecAccCallStore(void);
extern void Thunk_LoadGeoAsset_Default(void);
extern void AllocSlotPushTripleGlobals(void);
extern void MStackPop4Rewrite(void);
extern void Push70CallScaleArith(void);
extern void StreamChainStringInstall(void);
extern void MStackFrameCdeclDouble(void);
extern void ChainTableWalkStore(void);
extern void Push16Call(void);
extern void DispatcherComplex260_MStackBracket1_TreeWalkRecursive2(void);
extern void ScaledLoadCmpStoreXfm(void);
extern void StackPopDispatchTagged(void);
extern unsigned int g_cj_00542058;
extern unsigned int g_rangeSqLimit;
extern unsigned int g_zero_00541fa4;
extern unsigned int g_zero_00541fa8;
extern unsigned int g_dualBitGate;
extern unsigned int g_eventArmReload;
extern unsigned int g_rangeBase;

extern void ScaledArrStore_ScaledChainJmp_004298c0(void);
extern void DualFieldAddSubStore(void);
extern void IterStepDualStore(int);
extern void ScaledXorStore_004900f0(void);
extern void ChainWalkInstall(void);
extern void FpuSqrtMul(void);
extern void PendingMatch_StoreTwoCall_0042b930(void);
extern void MStackPush2RunCountdown(void);
extern void MStackBracket7_DispatchAndChain(void);
extern void MStackBracketed3StoreCall(void);
extern void ChainDirtyBitWalker(void);
extern void Wrapper_ScaledChainPushCall_004ef858(void);
extern void Wrapper_ScaledChainPushCall_004ef8b0(void);
extern void Helper_DownloadSetup(void);
extern void MStackPush3CmpCall(void);
extern void Wrapper_IterLoad_0048fd30_004f12a0(void);
extern void FiveCallScaledChainTailJmp(void);
extern void SetJmp_StateDispatchYield_00438f50(void);
extern void SetJmp_StateDispatchYield_00438f60(void);
extern void GuardedDispatch_InstallSelfDualEsi(void);
extern void MStackPushZeroCallPop_PendingMatch(void);
extern void DirtyToggleByGate(void);
extern void GameDispatchValidateState(void);
extern void CrouchAttackFsmCluster(void);
extern void MStackPushVec3Mul10(void);
extern void LiteralPushCallEntZero(void);
extern void LeaPlus22StoreSelf(void);
extern void IterLoad_g_scaledInit_00542048_then_DualScaledStoreZero(void);
extern void GuardedDualConst2AndToggle(void);
extern void CallPauseScaledStorePushCall(void);
extern void LoadGeoAsset_Default(void);
extern void DispatcherComplex260_FramePauseScaledStore(void);
extern void PushSetCallPop(void);
extern unsigned int g_stateCountdown;
extern unsigned int g_installOwnerNode;
extern unsigned int g_cj_00542054;
extern unsigned int g_audioBoundNode;
extern unsigned int g_lastGatedValue;
extern unsigned int g_lastGatedTick;
extern unsigned int g_fightAxisNegX;
extern unsigned int g_fightAxisNegY;
extern unsigned int g_fightAxisPosX;
extern unsigned int g_fightAxisPosY;

/* @addr 0x004c5e00 (369b crt) - _splitpath implementation.
 *   Splits the path string at [esp+0x10] into drive, dir, name, ext.
 *   Args: path (esp+0x10), drive_out (esp+0x1c), dir_out (esp+0x20),
 *   name_out (esp+0x24), ext_out (esp+0x28).
 *   1. Computes path length via repne scasb.
 *   2. If length >= 1 and path[1] == ':', extracts the 2-char drive
 *      to drive_out via FgetsImpl(out, src, 2), advances ebp
 *      past the drive. Else nulls drive_out if non-null.
 *   3. Walks the path identifying alphanumeric chars via the ctype
 *      table at g_ctypeByteTable (bit 4 = "valid path char"), records
 *      the LAST '/' or '\' position into ebp (for dir-end), and the
 *      LAST '.' position into esp+0x10 (for ext-start).
 *   4. Copies the dir (capped at 0xff) to dir_out, then name and ext
 *      similarly. Null-terminates each output as needed.
 *   Returns nothing (void).
 */
extern unsigned int g_ctypeByteTable;
extern void FgetsImpl(void);

__declspec(naked) void SplitPath(void) {
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
        call    FgetsImpl
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
        test    byte ptr [edx + g_ctypeByteTable], cl
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
        call    FgetsImpl
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
        call    FgetsImpl
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
        call    FgetsImpl
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
        call    FgetsImpl
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
