/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;
extern unsigned int g_baseSel;
extern unsigned int g_acc_00542078;
extern unsigned int g_cj_0054205c;
extern unsigned int g_gameCountdown;
extern unsigned int g_xformScratch94;
extern unsigned int g_table_00535ddc;
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
extern void CallPauseDirty1JmpDirty4StackPush_00483a80(void);
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
extern void PendingMatch_0042b930(void);
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
extern void MStackPushZeroCallPop_00407d00(void);
extern void DirtyToggleByGate(void);
extern void GameDispatchValidateState(void);
extern void CrouchAttackFsmCluster(void);
extern void MStackPushVec3Mul10(void);
extern void LiteralPushCallEntZero(void);
extern void LeaPlus22StoreSelf(void);
extern void IterLoad_00491050(void);
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

/* @addr 0x004c5bb0 (316b boot) - CRT fread: read count*size bytes from buffered stream.
 *   Multiplies count*size, returns 0 if 0. Buffered path drains pending bytes via
 *   rep movsd/movsb. Direct path: large reads use IOWrapper chunks, small reads
 *   use Filbuf byte-by-byte. EOF sets flag 0x10, error sets 0x20. Returns
 *   bytes_read/element_size.
 */
extern void Filbuf(void);
extern void IOWrapper_004c8fc0(void);

__declspec(naked) void Fread(void) {
    __asm {
        push    ecx
        push    ebx
        push    ebp
        mov     ebp, [esp + 0x18]
        push    esi
        imul    ebp, dword ptr [esp + 0x18]
        push    edi
        mov     edi, [esp + 0x18]
        test    ebp, ebp
        mov     [esp + 0x18], edi
        mov     [esp + 0x10], ebp
        jne     short L_fread_init
        xor     eax, eax
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        pop     ecx
        ret
    L_fread_init:
        mov     ebx, [esp + 0x24]
        test    dword ptr [ebx + 0xc], 0x10c
        jz      short L_fread_defaultBufsz
        mov     esi, [ebx + 0x18]
        mov     [esp + 0x24], esi
        jmp     short L_fread_haveBufsz
    L_fread_defaultBufsz:
        mov     dword ptr [esp + 0x24], 0x1000
    L_fread_reloadBufsz:
        mov     esi, [esp + 0x24]
    L_fread_haveBufsz:
        test    dword ptr [ebx + 0xc], 0x10c
        jz      short L_fread_noBuf
        mov     eax, [ebx + 4]
        test    eax, eax
        jz      short L_fread_noBuf
        cmp     ebp, eax
        jae     short L_fread_useEax
        mov     eax, ebp
    L_fread_useEax:
        mov     esi, [ebx]
        mov     ecx, eax
        mov     edx, ecx
        sub     ebp, eax
        shr     ecx, 2
        rep     movsd
        mov     ecx, edx
        and     ecx, 3
        rep     movsb
        mov     esi, [ebx + 4]
        mov     edx, [ebx]
        mov     ecx, [esp + 0x18]
        sub     esi, eax
        add     edx, eax
        add     ecx, eax
        mov     [ebx + 4], esi
        mov     [ebx], edx
        mov     [esp + 0x18], ecx
        mov     edi, ecx
        jmp     short L_fread_checkDone
    L_fread_noBuf:
        cmp     ebp, esi
        jb      short L_fread_byteRead
        test    esi, esi
        mov     eax, ebp
        jz      short L_fread_doRead
        xor     edx, edx
        div     esi
        mov     eax, ebp
        sub     eax, edx
    L_fread_doRead:
        push    eax
        mov     eax, [ebx + 0x10]
        push    edi
        push    eax
        call    IOWrapper_004c8fc0
        add     esp, 0xc
        test    eax, eax
        jz      short L_fread_eof
        cmp     eax, -1
        jz      short L_fread_err
        sub     ebp, eax
        add     edi, eax
        mov     [esp + 0x18], edi
        jmp     short L_fread_testEbp
    L_fread_byteRead:
        push    ebx
        call    Filbuf
        add     esp, 4
        cmp     eax, -1
        jz      short L_fread_eofShort
        mov     [edi], al
        mov     ecx, [ebx + 0x18]
        inc     edi
        dec     ebp
        mov     [esp + 0x18], edi
        mov     [esp + 0x24], ecx
    L_fread_checkDone:
        mov     esi, [esp + 0x24]
    L_fread_testEbp:
        test    ebp, ebp
        jne     L_fread_haveBufsz
        mov     eax, [esp + 0x20]
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        pop     ecx
        ret
    L_fread_eof:
        mov     edx, [ebx + 0xc]
        mov     eax, [esp + 0x10]
        or      edx, 0x10
        sub     eax, ebp
        mov     [ebx + 0xc], edx
        xor     edx, edx
        div     dword ptr [esp + 0x1c]
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        pop     ecx
        ret
    L_fread_err:
        mov     edx, [ebx + 0xc]
        mov     eax, [esp + 0x10]
        or      edx, 0x20
        sub     eax, ebp
        mov     [ebx + 0xc], edx
        xor     edx, edx
        div     dword ptr [esp + 0x1c]
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        pop     ecx
        ret
    L_fread_eofShort:
        mov     eax, [esp + 0x10]
        xor     edx, edx
        sub     eax, ebp
        div     dword ptr [esp + 0x1c]
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        pop     ecx
        ret
    }
}
