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

extern unsigned int g_virtualHeapBase;
extern unsigned int g_heapShrinkPtr;
extern unsigned int g_heapTeardownSentinel;
extern unsigned int g_dispatchSave1470;
extern unsigned int g_iat_HeapAlloc;
extern unsigned int g_iat_VirtualAlloc;
extern unsigned int g_iat_HeapFree;
extern unsigned int g_iat_VirtualFree;

__declspec(naked) void VirtualHeapAlloc(void)
{
    __asm {
        mov      eax, dword ptr [g_heapTeardownSentinel]
        push     ebp
        push     esi
        cmp      eax, -1
        push     edi
        jne      short L_70e4
        mov      ebp, OFFSET g_virtualHeapBase
        jmp      short L_7101
    L_70e4:
        mov      eax, dword ptr [g_dispatchSave1470]
        push     0x2020
        push     0
        push     eax
        call     dword ptr [g_iat_HeapAlloc]
        mov      ebp, eax
        test     ebp, ebp
        je       L_722c
    L_7101:
        mov      edi, dword ptr [g_iat_VirtualAlloc]
        push     4
        push     0x2000
        push     0x400000
        push     0
        call     edi
        mov      esi, eax
        test     esi, esi
        je       L_7215
        push     4
        push     0x1000
        push     0x10000
        push     esi
        call     edi
        test     eax, eax
        je       L_7207
        cmp      ebp, OFFSET g_virtualHeapBase
        jne      short L_7168
        mov      eax, dword ptr [g_virtualHeapBase]
        test     eax, eax
        jne      short L_7153
        mov      dword ptr [g_virtualHeapBase], OFFSET g_virtualHeapBase
    L_7153:
        mov      eax, dword ptr [g_heapShrinkPtr]
        test     eax, eax
        jne      short L_7183
        mov      dword ptr [g_heapShrinkPtr], OFFSET g_virtualHeapBase
        jmp      short L_7183
    L_7168:
        mov      dword ptr [ebp], OFFSET g_virtualHeapBase
        mov      ecx, dword ptr [g_heapShrinkPtr]
        mov      dword ptr [ebp + 4], ecx
        mov      dword ptr [g_heapShrinkPtr], ebp
        mov      edx, dword ptr [ebp + 4]
        mov      dword ptr [edx], ebp
    L_7183:
        lea      eax, [esi + 0x400000]
        lea      ecx, [ebp + 0x18]
        lea      edx, [ebp + 0x98]
        mov      dword ptr [ebp + 0x14], eax
        mov      dword ptr [ebp + 0x10], esi
        mov      dword ptr [ebp + 8], ecx
        mov      dword ptr [ebp + 0xc], edx
        xor      eax, eax
        mov      edi, 0xf1
    L_71a5:
        xor      edx, edx
        cmp      eax, 0x10
        setge    dl
        dec      edx
        add      ecx, 8
        and      edx, edi
        dec      edx
        inc      eax
        mov      dword ptr [ecx - 8], edx
        mov      dword ptr [ecx - 4], edi
        cmp      eax, 0x400
        jl       short L_71a5
        mov      ecx, 0x4000
        xor      eax, eax
        mov      edi, esi
        rep stosd
        mov      eax, dword ptr [ebp + 0x10]
        add      eax, 0x10000
        cmp      esi, eax
        jae      short L_7201
        mov      ecx, 0xf0
        mov      al, 0xff
    L_71e0:
        lea      edx, [esi + 8]
        mov      dword ptr [esi + 4], ecx
        mov      dword ptr [esi], edx
        mov      byte ptr [esi + 0xf8], al
        mov      edx, dword ptr [ebp + 0x10]
        add      esi, 0x1000
        add      edx, 0x10000
        cmp      esi, edx
        jb       short L_71e0
    L_7201:
        mov      eax, ebp
        pop      edi
        pop      esi
        pop      ebp
        ret
    L_7207:
        push     0x8000
        push     0
        push     esi
        call     dword ptr [g_iat_VirtualFree]
    L_7215:
        cmp      ebp, OFFSET g_virtualHeapBase
        je       short L_722c
        mov      eax, dword ptr [g_dispatchSave1470]
        push     ebp
        push     0
        push     eax
        call     dword ptr [g_iat_HeapFree]
    L_722c:
        pop      edi
        pop      esi
        xor      eax, eax
        pop      ebp
        ret
    }
}
