/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_currentNodeIdx;
extern unsigned int g_baseSel;
extern unsigned int g_chainAccumCur;
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
extern unsigned int g_armedReloadA;
extern unsigned int g_armedReloadB;
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

extern unsigned int g_dispatchSave601;
extern unsigned int g_cj_00535df0;
extern void MStackCall_MStackPush2ChainPrepend_00406340(void);
extern void MStackPush2ChainLLInsert(void);
extern void PushSetXfmMaskCallPop(void);
extern void ScaledInitOrSelfPtr_NetEntityScanAndPunish(void);

__declspec(naked) void NetEntityScanAndPunish(void)
{
    __asm {
        mov      eax, dword ptr [g_cj_00535df0]
        push     ebx
        push     esi
        push     edi
        mov      dword ptr [g_currentNodeIdx], eax
        mov      edi, 0x147
        mov      ebx, 0x77
        mov      esi, 0xfffff852
    L_4b6c:
        mov      eax, dword ptr [eax*4]
    L_4b73:
        mov      edx, dword ptr [g_xformDirtyFlags]
        mov      ecx, 4
        or       edx, ecx
        mov      dword ptr [g_currentNodeIdx], eax
        test     eax, eax
        mov      dword ptr [g_xformDirtyFlags], edx
        je       L_4d2c
        xor      edx, ecx
        test     eax, eax
        mov      dword ptr [g_xformDirtyFlags], edx
        je       L_4d2c
        mov      ecx, dword ptr [eax*4 + 0x30]
        cmp      ecx, 0x95
        mov      dword ptr [g_eventQueueCurrent], ecx
        jne      short L_4b6c
        mov      ecx, dword ptr [eax*4 + 0x70]
        mov      dword ptr [g_walkCallback], edi
        add      ecx, edi
        mov      dword ptr [g_eventQueueCurrent], ecx
        mov      dword ptr [eax*4 + 0x70], ecx
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      ecx, dword ptr [eax*4 + 0x58]
        test     ecx, ecx
        mov      dword ptr [g_eventQueueCurrent], ecx
        jl       short L_4b6c
        mov      ecx, dword ptr [eax*4]
        mov      dword ptr [g_xformEntityIdx], ecx
        mov      ecx, dword ptr [g_matrixStackTop]
        mov      eax, dword ptr [eax*4 + 0x54]
        inc      ecx
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [g_matrixStackTop], ecx
        mov      dword ptr [ecx*4], eax
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      ecx, dword ptr [g_matrixStackTop]
        mov      eax, dword ptr [edx*4 + 0x5c]
        inc      ecx
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [g_matrixStackTop], ecx
        mov      dword ptr [ecx*4], eax
        call     MStackPush2ChainLLInsert
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_4d31
        mov      eax, OFFSET g_dispatchSave601
        shr      eax, 2
        mov      dword ptr [g_walkCallback], eax
        call     PushSetXfmMaskCallPop
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_4d31
        test     byte ptr [g_xformDirtyFlags], 4
        je       short L_4cac
        mov      eax, dword ptr [g_matrixStackTop]
        mov      ecx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_walkCallback], ecx
        mov      dword ptr [g_matrixStackTop], eax
        mov      edx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      eax, dword ptr [g_xformEntityIdx]
        mov      dword ptr [g_walkCallback], edx
        jmp      L_4b73
    L_4cac:
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      dword ptr [g_walkCallback], ebx
        mov      dword ptr [eax*4 + 0x30], ebx
        call     MStackCall_MStackPush2ChainPrepend_00406340
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_4d31
        mov      eax, dword ptr [g_matrixStackTop]
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      ecx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_walkCallback], ecx
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [edx*4 + 0x5c], ecx
        mov      eax, dword ptr [g_matrixStackTop]
        mov      ecx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      dword ptr [eax*4 + 0x54], ecx
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [g_walkCallback], esi
        mov      dword ptr [ecx*4 + 0x58], esi
        mov      eax, dword ptr [g_xformEntityIdx]
        jmp      L_4b73
    L_4d2c:
        call     ScaledInitOrSelfPtr_NetEntityScanAndPunish
    L_4d31:
        pop      edi
        pop      esi
        pop      ebx
        ret
    }
}
