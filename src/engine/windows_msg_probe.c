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
extern void CopyJmp_0048ef90(void);
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
extern void DispatcherComplex260_00407030(void);
extern void ScaledLoadCmpStoreXfm(void);
extern void StackPopDispatchTagged(void);
extern unsigned int g_cj_00542058;
extern unsigned int g_rangeSqLimit;
extern unsigned int g_zero_00541fa4;
extern unsigned int g_zero_00541fa8;
extern unsigned int g_dualBitGate;
extern unsigned int g_eventArmReload;
extern unsigned int g_rangeBase;

extern void ScaledArrStore_004298c0(void);
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
extern void GuardedDispatch_0042b6c0(void);
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
extern void DispatcherComplex260_00407400(void);
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

/* @addr 0x004b4530 (196b engine.geo) - Windows message-queue probe (PeekMessageA-like indirect).
 *   Stack frame: sub esp, 0x14; save ebx/ebp/esi/edi (ebp = 0).
 *   Probe HWND ([0x7affe4]), arg1 ([esp+0x2c]), arg2 ([esp+0x30]),
 *   state ([0x7affe0] == 0), arg3 ([esp+0x34]); all must be non-zero.
 *   Build PeekMessage params on stack depending on [esp+0x28] (esi).
 *   Indirect call [0x7b003c].
 *   On success, verify [esp+0x14] != 0 and [esp+0x18] < 0x280;
 *   write result to *arg1, *arg2, *arg3=1; update [0x7affe0]; return 1.
 *   On any fail, return 0.
 */
extern unsigned int g_PeekMessageA;
extern int g_renderer1_busy;
extern int g_renderer1_active;

__declspec(naked) void WindowsMsgProbe(void) {
    __asm {
        sub     esp, 0x14
        mov     eax, dword ptr [g_renderer1_active]
        push    ebx
        push    ebp
        xor     ebp, ebp
        push    esi
        cmp     eax, ebp
        push    edi
        mov     dword ptr [esp + 0x10], 0x14
        mov     [esp + 0x14], ebp
        mov     [esp + 0x18], ebp
        mov     [esp + 0x1c], ebp
        mov     [esp + 0x20], ebp
        _emit   0fh
        _emit   84h
        _emit   8ch
        _emit   00h
        _emit   00h
        _emit   00h
        cmp     [esp + 0x2c], ebp
        _emit   0fh
        _emit   84h
        _emit   82h
        _emit   00h
        _emit   00h
        _emit   00h
        mov     ebx, [esp + 0x30]
        cmp     ebx, ebp
        _emit   74h
        _emit   7ah
        cmp     dword ptr [g_renderer1_busy], ebp
        _emit   75h
        _emit   72h
        mov     edi, [esp + 0x34]
        cmp     edi, ebp
        _emit   74h
        _emit   6ah
        mov     esi, [esp + 0x28]
        cmp     esi, ebp
        _emit   74h
        _emit   0eh
        lea     eax, [esp + 0x10]
        push    eax
        push    ebp
        push    ebp
        push    ebp
        push    1
        push    1
        _emit   0ebh
        _emit   0eh
        lea     ecx, [esp + 0x10]
        push    ecx
        push    ebp
        push    ebp
        push    0xff
        push    ebp
        push    ebp
        call    dword ptr [g_PeekMessageA]
        cmp     eax, ebp
        _emit   74h
        _emit   3ch
        mov     eax, [esp + 0x14]
        cmp     eax, ebp
        _emit   74h
        _emit   34h
        mov     ecx, [esp + 0x18]
        cmp     ecx, 0x00000280
        _emit   72h
        _emit   28h
        mov     edx, [esp + 0x2c]
        mov     [edx], eax
        xor     eax, eax
        cmp     esi, ebp
        mov     [ebx], ecx
        setne   al
        inc     eax
        mov     dword ptr [g_renderer1_busy], eax
        mov     dword ptr [edi], 1
        mov     eax, 1
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        add     esp, 0x14
        ret
        pop     edi
        pop     esi
        pop     ebp
        xor     eax, eax
        pop     ebx
        add     esp, 0x14
        ret
    }
}
