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

/* @addr 0x004c6a20 (187b boot) - lock-iter handler table with two dispatch paths.
 *   Reserve stack [esp+0x10] = 0; push 2; call Lock; load count = [0xfa0dc0].
 *   edi = arg; esi = 0; ebp = 0.
 *   loop while esi < count:
 *     bl = 0x83; eax = [0xf9fdb4][esi]; if (eax == 0 || ![eax+0xc] & 0x83) continue.
 *     push eax, esi; call TwoPathIATDispatch_004c7030; add esp, 8.
 *     eax = [0xf9fdb4][esi]; ecx = [eax+0xc]; if (!(ecx & 0x83)) goto next.
 *     if (edi == 1): push eax; call CallTestPushSubCall; if (result != -1) inc [esp+0x10].
 *     else: if (edi == 0 && (cl & 2)): push eax; call CallTestPushSubCall; if (result != -1) ebp |= eax.
 *     push [0xf9fdb4][esi], esi; call TwoPathIATDispatch_004c70a0; add esp, 8.
 *     next: inc esi; cmp esi, [0xfa0dc0]; if (<) goto loop.
 *   push 2; call TableLookupIatCall; eax = [esp+0x14] (saved 0).
 *   if (edi != 1): eax = ebp.
 *   pop all regs.
 */
extern unsigned int g_dispatchSave1465;
extern unsigned int g_dispatchSave1466;
extern void CallTestPushSubCall(void);
extern void Lock(void);
extern void TableLookupIatCall(void);
extern void TwoPathIATDispatch_004c7030(void);
extern void TwoPathIATDispatch_004c70a0(void);

__declspec(naked) void LockIterTwoPath(void) {
    __asm {
        push    ecx
        push    ebx
        push    ebp
        push    esi
        push    edi
        xor     esi, esi
        push    2
        mov     [esp + 0x14], esi
        xor     ebp, ebp
        call    Lock
        mov     eax, dword ptr [g_dispatchSave1466]
        mov     edi, [esp + 0x1c]
        add     esp, 4
        cmp     eax, esi
        _emit   7eh
        _emit   7ch
        mov     bl, 0x83
        mov     eax, dword ptr [g_dispatchSave1465]
        mov     eax, [eax + esi*4]
        test    eax, eax
        _emit   74h
        _emit   64h
        test    byte ptr [eax + 0xc], bl
        _emit   74h
        _emit   5fh
        push    eax
        push    esi
        call    TwoPathIATDispatch_004c7030
        mov     ecx, dword ptr [g_dispatchSave1465]
        add     esp, 8
        mov     eax, [ecx + esi*4]
        mov     ecx, [eax + 0x0c]
        _emit   84h
        _emit   0cbh
        _emit   74h
        _emit   32h
        cmp     edi, 1
        _emit   75h
        _emit   14h
        push    eax
        call    CallTestPushSubCall
        add     esp, 4
        cmp     eax, 0xffffffff
        _emit   74h
        _emit   1fh
        inc     dword ptr [esp + 0x10]
        _emit   0ebh
        _emit   19h
        test    edi, edi
        _emit   75h
        _emit   15h
        test    cl, 2
        _emit   74h
        _emit   10h
        push    eax
        call    CallTestPushSubCall
        add     esp, 4
        cmp     eax, 0xffffffff
        _emit   75h
        _emit   02h
        or      ebp, eax
        mov     edx, dword ptr [g_dispatchSave1465]
        mov     eax, [edx + esi*4]
        push    eax
        push    esi
        call    TwoPathIATDispatch_004c70a0
        add     esp, 8
        mov     eax, dword ptr [g_dispatchSave1466]
        inc     esi
        cmp     esi, eax
        _emit   7ch
        _emit   86h
        push    2
        call    TableLookupIatCall
        mov     eax, [esp + 0x14]
        add     esp, 4
        cmp     edi, 1
        _emit   74h
        _emit   02h
        mov     eax, ebp
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        pop     ecx
        ret
    }
}
