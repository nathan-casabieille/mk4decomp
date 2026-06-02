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

extern void BitShiftMultiPrecision(void);
extern void BitsetReserve(void);
extern void Copy3Dwords(void);
extern void LinearSearchArray(void);
extern void ZeroThreeFromArg(void);

__declspec(naked) void FpExtendedToFloat(void)
{
    __asm {
        sub      esp, 0x18
        mov      ecx, dword ptr [esp + 0x1c]
        xor      eax, eax
        push     ebx
        push     ebp
        mov      ax, word ptr [ecx + 0xa]
        mov      edx, dword ptr [ecx + 2]
        mov      ebx, eax
        and      eax, 0x8000
        mov      ebp, eax
        mov      eax, dword ptr [ecx + 6]
        mov      dword ptr [esp + 8], eax
        xor      eax, eax
        mov      ax, word ptr [ecx]
        and      ebx, 0x7fff
        sub      ebx, 0x3fff
        push     esi
        shl      eax, 0x10
        push     edi
        mov      edi, dword ptr [esp + 0x34]
        cmp      ebx, 0xffffc001
        mov      dword ptr [esp + 0x14], edx
        mov      dword ptr [esp + 0x18], eax
        jne      short L_cb8a
        lea      ecx, [esp + 0x10]
        xor      esi, esi
        push     ecx
        call     LinearSearchArray
        add      esp, 4
        test     eax, eax
        jne      L_cc8f
        lea      edx, [esp + 0x10]
        push     edx
        call     ZeroThreeFromArg
        add      esp, 4
        mov      eax, 2
        jmp      L_cc91
    L_cb8a:
        lea      eax, [esp + 0x10]
        lea      ecx, [esp + 0x1c]
        push     eax
        push     ecx
        call     Copy3Dwords
        mov      edx, dword ptr [edi + 8]
        add      esp, 8
        lea      eax, [esp + 0x10]
        push     edx
        push     eax
        call     BitsetReserve
        add      esp, 8
        test     eax, eax
        je       short L_cbb2
        inc      ebx
    L_cbb2:
        mov      eax, dword ptr [edi + 4]
        mov      esi, dword ptr [edi + 8]
        mov      ecx, eax
        sub      ecx, esi
        cmp      ebx, ecx
        jge      short L_cbd9
        lea      edx, [esp + 0x10]
        push     edx
        call     ZeroThreeFromArg
        add      esp, 4
        xor      esi, esi
        mov      eax, 2
        jmp      L_cc91
    L_cbd9:
        cmp      ebx, eax
        jg       short L_cc2d
        sub      eax, ebx
        lea      ecx, [esp + 0x10]
        mov      esi, eax
        lea      eax, [esp + 0x1c]
        push     eax
        push     ecx
        call     Copy3Dwords
        add      esp, 8
        lea      edx, [esp + 0x10]
        push     esi
        push     edx
        call     BitShiftMultiPrecision
        mov      eax, dword ptr [edi + 8]
        add      esp, 8
        lea      ecx, [esp + 0x10]
        push     eax
        push     ecx
        call     BitsetReserve
        mov      edx, dword ptr [edi + 0xc]
        add      esp, 8
        inc      edx
        lea      eax, [esp + 0x10]
        push     edx
        push     eax
        call     BitShiftMultiPrecision
        add      esp, 8
        xor      esi, esi
        mov      eax, 2
        jmp      short L_cc91
    L_cc2d:
        cmp      ebx, dword ptr [edi]
        jl       short L_cc6b
        lea      ecx, [esp + 0x10]
        push     ecx
        call     ZeroThreeFromArg
        mov      ebx, dword ptr [esp + 0x14]
        mov      edx, dword ptr [edi + 0xc]
        add      esp, 4
        lea      eax, [esp + 0x10]
        or       ebx, 0x80000000
        push     edx
        push     eax
        mov      dword ptr [esp + 0x18], ebx
        call     BitShiftMultiPrecision
        mov      esi, dword ptr [edi + 0x14]
        mov      eax, dword ptr [edi]
        add      esp, 8
        add      esi, eax
        mov      eax, 1
        jmp      short L_cc91
    L_cc6b:
        mov      esi, dword ptr [edi + 0x14]
        mov      ecx, dword ptr [edi + 0xc]
        add      esi, ebx
        mov      ebx, dword ptr [esp + 0x10]
        lea      edx, [esp + 0x10]
        and      ebx, 0x7fffffff
        push     ecx
        push     edx
        mov      dword ptr [esp + 0x18], ebx
        call     BitShiftMultiPrecision
        add      esp, 8
    L_cc8f:
        xor      eax, eax
    L_cc91:
        mov      edx, dword ptr [edi + 0xc]
        mov      ecx, 0x1f
        sub      ecx, edx
        mov      edx, dword ptr [esp + 0x10]
        shl      esi, cl
        mov      edi, dword ptr [edi + 0x10]
        neg      ebp
        sbb      ebp, ebp
        and      ebp, 0x80000000
        or       esi, ebp
        or       esi, edx
        cmp      edi, 0x40
        jne      short L_cccc
        mov      ecx, dword ptr [esp + 0x30]
        mov      edx, dword ptr [esp + 0x14]
        mov      dword ptr [ecx + 4], esi
        mov      dword ptr [ecx], edx
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        add      esp, 0x18
        ret
    L_cccc:
        cmp      edi, 0x20
        jne      short L_ccd7
        mov      ecx, dword ptr [esp + 0x30]
        mov      dword ptr [ecx], esi
    L_ccd7:
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        add      esp, 0x18
        ret
    }
}
