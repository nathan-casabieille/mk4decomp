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

/*
 * @addr 0x0042fbc0 (116b game) - chain field-test then 2-branch:
 *   walk = walk[+0x40]; g_xformScratch94 = walk & 0x40; if zero exit.
 *   Else: mov eax,ecx (copy old_scaled from ecx to eax); load g_dispatchSave1711_538158
 *   into ecx; cmp eax,ecx; store both (g_xformEntityIdx=eax a3, g_scaledInit=ecx
 *   89 0d) between cmp and jne; conditionally replace with g_dispatchSave1712_53815c.
 *   NON-COAXABLE: orig emits `mov eax,ecx` (2b) + `mov ecx,[g_x]` (6b) to get
 *   old_scaled into eax for a3-form store; MSVC SP3 /O2 instead loads g_x into
 *   eax (a1 5b) and keeps old_scaled in ecx, saving 3 bytes in the cmp block
 *   (compensated by 3 nop pads at end). Reg-allocation divergence; non-coaxable.
 */
extern void MStackSignedMod(void);
extern void Mul10Triple0xd999Interp(void);
extern void SubCmpCallPauseJmp(void);

__declspec(naked) void ChainFieldTest2Branch(void) {
    __asm {
        mov     ecx, dword ptr [g_currentNodeIdx]
        mov     eax, dword ptr [ecx*4 + 0x40]
        mov     dword ptr [g_walkCallback], eax
        and     eax, 0x40
        mov     dword ptr [g_xformScratch94], eax
        je      L_exit
        mov     eax, ecx
        mov     ecx, dword ptr [g_player1NodeIdx]
        cmp     eax, ecx
        mov     dword ptr [g_xformEntityIdx], eax
        mov     dword ptr [g_currentNodeIdx], ecx
        jne     L_notEqual
        mov     eax, dword ptr [g_player2NodeIdx]
        mov     dword ptr [g_currentNodeIdx], eax
    L_notEqual:
        call    MStackSignedMod
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_exit
        mov     ecx, dword ptr [g_walkCallback]
        mov     eax, 0x4ccc
        cmp     ecx, eax
        mov     dword ptr [g_chainAccumCur], 0
        mov     dword ptr [g_eventQueueWorkType], eax
        jle     L_mul10
        jmp     SubCmpCallPauseJmp
    L_mul10:
        jmp     Mul10Triple0xd999Interp
    L_exit:
        ret
    }
}
