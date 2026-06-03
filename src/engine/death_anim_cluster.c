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

extern unsigned int g_dispatchSave729;
extern unsigned int g_dispatchTableArr8;
extern u32 g_dlSomeFlag2;
extern s32 g_dlNalt1;
extern unsigned int g_bootHeavyState;
extern s32 g_dlNalt2;
extern unsigned int g_eventMusicSlot2;
extern u32 g_dlSomeFlag1;
extern unsigned int g_zerotriple_00541de8;
extern unsigned int g_zerotriple_00541dec;
extern unsigned int g_dispatchVar3;
extern unsigned int g_eventMusicSlot;
extern void CallSetPause(void);
extern void Cmp7CondStateUpdate(void);
extern void GameMusicState4Way(void);
extern void GuardedDualPushTailJmp(void);
extern void ScaledLoadOrSetJmp(void);

__declspec(naked) void DeathAnimCluster(void)
{
    __asm {
        /* === Helper 1 (0x42eaf0): death-pose install + post-rotation === */
        mov      eax, dword ptr [g_matrixStackTop]
        mov      ecx, dword ptr [g_xformEntityIdx]
        inc      eax
        push     esi
        mov      dword ptr [g_matrixStackTop], eax
        xor      esi, esi
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_matrixStackTop]
        mov      edx, dword ptr [g_zerotriple_00541dec]
        mov      ecx, dword ptr [g_zerotriple_00541de8]
        inc      eax
        mov      dword ptr [g_eventQueueCurrent], edx
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_matrixStackTop]
        mov      edx, dword ptr [g_eventQueueCurrent]
        inc      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], edx
        mov      eax, dword ptr [g_eventMusicSlot2]
        cmp      eax, 1
        mov      dword ptr [g_zerotriple_00541de8], esi
        mov      dword ptr [g_zerotriple_00541dec], esi
        je       short L_eb75
        mov      eax, dword ptr [g_dlNalt1]
        mov      ecx, dword ptr [g_dlSomeFlag1]
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [g_eventQueueWorkType], ecx
        jmp      short L_eb8b
    L_eb75:
        mov      edx, dword ptr [g_dlNalt2]
        mov      eax, dword ptr [g_dlSomeFlag2]
        mov      dword ptr [g_walkCallback], edx
        mov      dword ptr [g_eventQueueWorkType], eax
    L_eb8b:
        mov      dword ptr [g_eventQueueCurrent], esi
        call     GuardedDualPushTailJmp
        cmp      dword ptr [g_framePauseFlag], esi
        jne      L_ed0b
        mov      eax, dword ptr [g_matrixStackTop]
        mov      ecx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_eventQueueCurrent], ecx
        mov      dword ptr [g_matrixStackTop], eax
        mov      edx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_walkCallback], edx
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [g_zerotriple_00541de8], edx
        mov      dword ptr [g_zerotriple_00541dec], ecx
        call     GameMusicState4Way
        cmp      dword ptr [g_framePauseFlag], esi
        jne      L_ed0b
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      dword ptr [ecx*4 + 0x30], 0x23c
        mov      dword ptr [ecx*4 + 0x54], esi
        mov      dword ptr [ecx*4 + 0x58], esi
        mov      edx, dword ptr [ecx*4 + 0x34]
        lea      eax, [ecx*4]
        or       edx, 0x180000
        mov      dword ptr [eax + 0x34], edx
        mov      dword ptr [eax + 0x64], esi
        mov      dword ptr [eax + 0x68], esi
        mov      dword ptr [eax + 0x5c], 0xfffd0000
        mov      dword ptr [eax + 0x60], 0x4b333
        mov      ecx, dword ptr [g_audioBankSel]
        mov      eax, OFFSET g_dispatchSave729
        mov      edx, 0xf
        shr      eax, 2
        cmp      ecx, 2
        mov      dword ptr [g_walkCallback], eax
        jne      short L_ec66
        cmp      dword ptr [g_dlNalt1], edx
        jne      short L_ec66
        mov      eax, OFFSET g_dispatchTableArr8
        shr      eax, 2
        mov      dword ptr [g_walkCallback], eax
    L_ec66:
        cmp      ecx, 1
        jne      short L_ec80
        cmp      dword ptr [g_dlNalt2], edx
        jne      short L_ec80
        mov      eax, OFFSET g_dispatchTableArr8
        shr      eax, 2
        mov      dword ptr [g_walkCallback], eax
    L_ec80:
        mov      edx, dword ptr [g_fightGroupHead]
        mov      dword ptr [edx*4 + 0x24], eax
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      eax, dword ptr [g_walkCallback]
        mov      dword ptr [ecx*4 + 0x28], eax
        call     ScaledLoadOrSetJmp
        cmp      dword ptr [g_framePauseFlag], esi
        jne      short L_ed0b
        mov      eax, dword ptr [g_bootHeavyState]
        mov      dword ptr [g_xformEntityIdx], eax
        mov      dword ptr [eax*4 + 0x54], esi
        mov      edx, dword ptr [g_xformEntityIdx]
        mov      eax, 0xfff98000
        mov      dword ptr [edx*4 + 0x58], esi
        mov      ecx, dword ptr [g_xformEntityIdx]
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x5c], eax
        mov      eax, dword ptr [g_fightGroupHead]
        mov      edx, dword ptr [g_xformEntityIdx]
        mov      dword ptr [eax*4 + 0x3c], edx
        mov      eax, dword ptr [g_matrixStackTop]
        mov      ecx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_xformEntityIdx], ecx
        mov      dword ptr [g_matrixStackTop], eax
    L_ed0b:
        pop      esi
        ret
        nop
        nop
        nop
        /* === Helper 2: p1 death gate → 0042ed90 === */
        mov      ecx, dword ptr [g_active_0053a408]
        mov      eax, 1
        cmp      ecx, eax
        jne      short L_ed38
        mov      ecx, dword ptr [g_active_00537e88]
        test     ecx, ecx
        jne      short L_ed38
        mov      ecx, dword ptr [g_eventMusicSlot]
        test     ecx, ecx
        jge      short L_ed38
        jmp      CallSetPause
    L_ed38:
        mov      ecx, OFFSET g_active_0053a408
        mov      dword ptr [g_eventQueueCurrent], eax
        shr      ecx, 2
        mov      dword ptr [g_currentNodeIdx], ecx
        jmp      Cmp7CondStateUpdate
        /* === Helper 3: p2 death gate → 0042ed90 === */
        mov      eax, dword ptr [g_active_0053a408]
        test     eax, eax
        jne      short L_ed70
        cmp      dword ptr [g_active_00537e88], 1
        jne      short L_ed70
        mov      eax, dword ptr [g_dispatchVar3]
        test     eax, eax
        jge      short L_ed70
        jmp      CallSetPause
    L_ed70:
        mov      eax, OFFSET g_active_00537e88
        mov      dword ptr [g_eventQueueCurrent], 2
        shr      eax, 2
        mov      dword ptr [g_currentNodeIdx], eax
        jmp      Cmp7CondStateUpdate
    }
}
