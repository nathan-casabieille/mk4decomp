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

/*
 * AudioState50b4BitDispatcher - 309b 4-bit dispatcher on g_byte_004d50b4 (cl/ch).
 *   edi = 0x1c20 (channel id?). For bits 0x01, 0x02 (movsx byte from table at esi[chain*9*4 + N]):
 *     if !=-1: store back at chain[+0x30]; SetJmp_Push16Call_004a1ad0. Then g_eventQueueChild = edi.
 *   For bits 0x04, 0x08 (dword load from esi[chain*9*4 + 4/+8] → g_currentNodeIdx): if !=0: clear
 *     g_xformDirtyFlags bit 0; call eax (indirect); if paused: pop+ret; test bit 1, if not set:
 *     call 0x004a1ac0 (sister). Then g_eventQueueChild = edi.
 *   Pop+ret.
 */
extern unsigned int g_byte_004d50b4;
extern void SetJmp_Push16Call_004a1ac0(void);
extern void SetJmp_Push16Call_004a1ad0(void);

__declspec(naked) void AudioState50b4BitDispatcher(void)
{
    __asm
    {
        mov     ecx, dword ptr [g_byte_004d50b4]
        push    esi
        mov     esi, dword ptr [esp + 8]
        push    edi
        test    cl, 1
        mov     edi, 0x1c20
        jne     short L_a32_b1_do
        test    ch, 1
        je      short L_a32_b1_outerSkip
    L_a32_b1_do:
        mov     edx, dword ptr [g_baseSel]
        mov     eax, dword ptr [edx*4 + 0x30]
        lea     eax, [eax + eax*8]
        movsx   eax, byte ptr [esi + eax*4]
        cmp     eax, -1
        mov     dword ptr [g_walkCallback], eax
        je      short L_a32_b1_innerSkip
        mov     dword ptr [edx*4 + 0x30], eax
        call    SetJmp_Push16Call_004a1ad0
        mov     ecx, dword ptr [g_byte_004d50b4]
    L_a32_b1_innerSkip:
        mov     dword ptr [g_eventQueueChild], edi
    L_a32_b1_outerSkip:
        test    cl, 2
        jne     short L_a32_b2_do
        test    ch, 2
        je      short L_a32_b2_outerSkip
    L_a32_b2_do:
        mov     edx, dword ptr [g_baseSel]
        mov     eax, dword ptr [edx*4 + 0x30]
        lea     eax, [eax + eax*8]
        movsx   eax, byte ptr [esi + eax*4 + 1]
        cmp     eax, -1
        mov     dword ptr [g_walkCallback], eax
        je      short L_a32_b2_innerSkip
        mov     dword ptr [edx*4 + 0x30], eax
        call    SetJmp_Push16Call_004a1ad0
        mov     ecx, dword ptr [g_byte_004d50b4]
    L_a32_b2_innerSkip:
        mov     dword ptr [g_eventQueueChild], edi
    L_a32_b2_outerSkip:
        test    cl, 4
        jne     short L_a32_b4_do
        test    ch, 4
        je      short L_a32_b4_outerSkip
    L_a32_b4_do:
        mov     edx, dword ptr [g_baseSel]
        mov     eax, dword ptr [edx*4 + 0x30]
        lea     eax, [eax + eax*8]
        mov     eax, dword ptr [esi + eax*4 + 4]
        test    eax, eax
        mov     dword ptr [g_currentNodeIdx], eax
        je      short L_a32_b4_innerSkip
        and     dword ptr [g_xformDirtyFlags], 0xfffffffe
        call    eax
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_a32_popRet
        test    byte ptr [g_xformDirtyFlags], 1
        jne     short L_a32_b4_skipSetJmp
        call    SetJmp_Push16Call_004a1ac0
    L_a32_b4_skipSetJmp:
        mov     ecx, dword ptr [g_byte_004d50b4]
    L_a32_b4_innerSkip:
        mov     dword ptr [g_eventQueueChild], edi
    L_a32_b4_outerSkip:
        test    cl, 8
        jne     short L_a32_b8_do
        test    ch, 8
        je      short L_a32_popRet
    L_a32_b8_do:
        mov     ecx, dword ptr [g_baseSel]
        mov     eax, dword ptr [ecx*4 + 0x30]
        lea     edx, [eax + eax*8]
        mov     eax, dword ptr [esi + edx*4 + 8]
        test    eax, eax
        mov     dword ptr [g_currentNodeIdx], eax
        je      short L_a32_b8_innerSkip
        and     dword ptr [g_xformDirtyFlags], 0xfffffffe
        call    eax
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_a32_popRet
        test    byte ptr [g_xformDirtyFlags], 1
        jne     short L_a32_b8_skipSetJmp
        call    SetJmp_Push16Call_004a1ac0
    L_a32_b8_skipSetJmp:
    L_a32_b8_innerSkip:
        mov     dword ptr [g_eventQueueChild], edi
    L_a32_popRet:
        pop     edi
        pop     esi
        ret
    }
}
