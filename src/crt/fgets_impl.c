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

/* @addr 0x004c9a30 (167b crt) - fgets-like string read with lock-iter implementation.
 *   if ([0xf9fac8] != 0): call Strncpy(dst, count, stream); return.
 *   else: Lock(0x19); count = arg2; if (count != 0): copy chars with class-table check.
 *   Reads char [src], stores to [dst]; if char's class (table[char] & 4) is set, treat as line-end.
 *   Otherwise continues to copy until count exhausted or NUL.
 *   On line-end: null-terminate. Pad remaining buffer with zeros (rep stosd + rep stosb).
 *   Unlock(0x19) (TableLookupIatCall); return dst.
 */
extern unsigned int g_byte_00f9f8c1;
extern unsigned int g_dispatchSave1435_00f9fac8;
extern void Lock(void);
extern void Strncpy(void);
extern void TableLookupIatCall(void);

__declspec(naked) void FgetsImpl(void) {
    __asm {
        mov     eax, dword ptr [g_dispatchSave1435_00f9fac8]
        push    esi
        push    edi
        mov     edi, [esp + 0x0c]
        test    eax, eax
        mov     esi, edi
        _emit   75h
        _emit   16h
        mov     eax, [esp + 0x14]
        mov     ecx, [esp + 0x10]
        push    eax
        push    ecx
        push    edi
        call    Strncpy
        add     esp, 0x0c
        pop     edi
        pop     esi
        ret
        push    ebp
        push    0x19
        call    Lock
        mov     edx, [esp + 0x1c]
        add     esp, 4
        test    edx, edx
        _emit   74h
        _emit   43h
        mov     eax, [esp + 0x14]
        mov     cl, [eax]
        dec     edx
        mov     ebp, ecx
        and     ebp, 0xff
        test    byte ptr [ebp + g_byte_00f9f8c1], 4
        mov     [edi], cl
        _emit   74h
        _emit   13h
        inc     edi
        inc     eax
        test    edx, edx
        _emit   74h
        _emit   19h
        mov     cl, [eax]
        dec     edx
        mov     [edi], cl
        inc     edi
        inc     eax
        test    cl, cl
        _emit   74h
        _emit   14h
        _emit   0ebh
        _emit   06h
        inc     edi
        inc     eax
        test    cl, cl
        _emit   74h
        _emit   10h
        test    edx, edx
        _emit   75h
        _emit   0cdh
        _emit   0ebh
        _emit   0ah
        mov     byte ptr [edi - 1], 0
        _emit   0ebh
        _emit   04h
        mov     byte ptr [edi - 2], 0
        mov     eax, edx
        dec     edx
        test    eax, eax
        _emit   74h
        _emit   13h
        lea     ecx, [edx + 1]
        xor     eax, eax
        mov     edx, ecx
        shr     ecx, 2
        rep stosd
        mov     ecx, edx
        and     ecx, 3
        rep stosb
        push    0x19
        call    TableLookupIatCall
        add     esp, 4
        mov     eax, esi
        pop     ebp
        pop     edi
        pop     esi
        ret
    }
}
