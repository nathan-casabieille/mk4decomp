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

/* @addr 0x0045dd90 (202b game) - chain-pick + arg-based scaledInit setup.
 *   if (g_fightGroupHead == 0) jmp Thunk_Thunk_0049cbc0_0045e0f0.
 *   ecx = g_cj_00542058; clear g_xformScratch2088; load 0x54-field into g_walkCallback/70/74;
 *   3 nested tests; if min/max swap; check eax<>g_eventQueueChild.
 *   If lo: g_xformScratch2088 = 1.
 *   Store g_eventQueueTotal to [baseSel*4+0x64]; eax = arg0>>2; g_eventQueueEnd store at [baseSel*4+0x68];
 *   g_pendingNodeType=eax+0xf; scaledInit=eax+g_acc_00542078; eax=[scaledInit*4+0]; jmp 0x0045de60.
 */
extern unsigned int g_phaseThunkState;
extern void EventPacketDecoder(void);
extern void Thunk_Thunk_0049cbc0_0045e0f0(void);

__declspec(naked) void ChainPickArgScaledInit(void) {
    __asm {
        mov     eax, dword ptr [g_fightGroupHead]
        test    eax, eax
        _emit   75h
        _emit   05h
        jmp     Thunk_Thunk_0049cbc0_0045e0f0
        mov     ecx, dword ptr [g_cj_00542058]
        mov     dword ptr [g_xformScratch2088], 0
        mov     edx, dword ptr [ecx*4 + 0x54]
        mov     dword ptr [g_walkCallback], edx
        mov     ecx, dword ptr [eax*4 + 0x54]
        mov     eax, dword ptr [g_phaseThunkState]
        mov     dword ptr [g_eventQueueCurrent], ecx
        test    eax, eax
        mov     dword ptr [g_eventQueueWorkType], eax
        _emit   74h
        _emit   22h
        test    eax, eax
        mov     dword ptr [g_eventQueueChild], edx
        _emit   74h
        _emit   18h
        mov     edx, ecx
        test    eax, eax
        mov     dword ptr [g_walkCallback], edx
        _emit   74h
        _emit   0ch
        mov     ecx, dword ptr [g_eventQueueChild]
        mov     dword ptr [g_eventQueueCurrent], ecx
        cmp     edx, ecx
        _emit   7dh
        _emit   0ah
        mov     dword ptr [g_xformScratch2088], 1
        mov     edx, dword ptr [g_baseSel]
        mov     eax, dword ptr [g_eventQueueTotal]
        mov     dword ptr [edx*4 + 0x64], eax
        mov     eax, dword ptr [esp + 4]
        mov     ecx, dword ptr [g_baseSel]
        mov     edx, dword ptr [g_cj_00542054]
        sar     eax, 2
        mov     dword ptr [ecx*4 + 0x68], edx
        lea     ecx, [eax + 0x0f]
        mov     dword ptr [g_pendingNodeType], ecx
        mov     ecx, dword ptr [g_acc_00542078]
        add     eax, ecx
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     edx, dword ptr [eax*4 + 0]
        mov     dword ptr [g_scaledInit_00542044], edx
        jmp     EventPacketDecoder
    }
}
