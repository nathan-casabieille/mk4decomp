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

/* @addr 0x004b7a40 (193b game.menu) - search 9-slot table; replace first match with eax.
 *   Caller passes (esi=&id, edx=new_id, ecx_idx=[esp+0x10]).
 *   eax = *esi; *esi = 0; if (edx == 0) goto end.
 *   For each slot (0..8): if (slot[ecx_idx] == edx) { slot[ecx_idx] = eax; eax = 0; }
 *   *esi = edx. pop esi; ret.
 */
extern unsigned int g_btnBind0;
extern unsigned int g_btnBind1;
extern unsigned int g_btnBind2;
extern unsigned int g_btnBind3;
extern unsigned int g_btnBind4;
extern unsigned int g_btnBind5;
extern unsigned int g_btnBind6;
extern unsigned int g_btnBind7;
extern unsigned int g_btnBind8;

/*
 * Input_RebindButtonToAction(slot, button, player) - 0x4b7a40 (193b).
 *
 * The joystick twin of Input_RebindKeyToAction, over ONE player's column of
 * the nine-action button map at 0x543b20 (action stride 8, player stride 4).
 * Clear the target cell, hand the first cell already holding `button` the
 * target's previous value and clear any further duplicate, then write
 * `button`. A `button` of zero just clears, which is what Enter does on a
 * bound row when no pad button is down.
 *
 * The matching body below indexes through nine separate C globals that .data
 * happens to lay out eight bytes apart; under the arena those are detached
 * copies, so the native twin indexes the map itself.
 */
#ifdef NON_MATCHING

#include "portable/mem_model.h"

#define JOYMAP_ACTIONS 9
#define g_joyButtonMap ((unsigned int *)MK4_VA(unsigned int, 0x00543b20u))

void Input_RebindButtonToAction(unsigned int *p, unsigned int val, unsigned int idx)
{
    unsigned int *map = g_joyButtonMap;
    unsigned int carried = *p;
    int i;

    *p = 0;
    if (val == 0)
        return;
    for (i = 0; i < JOYMAP_ACTIONS; i++) {
        unsigned int *cell = &map[i * 2 + idx];

        if (*cell == val) {
            *cell = carried;
            carried = 0;
        }
    }
    *p = val;
}

#else

void Input_RebindButtonToAction(unsigned int *p, unsigned int val, unsigned int idx)
{
    unsigned int saved = *p;
    *p = 0;
    if (!val) return;
    if ((&g_btnBind0)[idx] == val) { (&g_btnBind0)[idx] = saved; saved = 0; }
    if ((&g_btnBind1)[idx] == val) { (&g_btnBind1)[idx] = saved; saved = 0; }
    if ((&g_btnBind2)[idx] == val) { (&g_btnBind2)[idx] = saved; saved = 0; }
    if ((&g_btnBind3)[idx] == val) { (&g_btnBind3)[idx] = saved; saved = 0; }
    if ((&g_btnBind4)[idx] == val) { (&g_btnBind4)[idx] = saved; saved = 0; }
    if ((&g_btnBind5)[idx] == val) { (&g_btnBind5)[idx] = saved; saved = 0; }
    if ((&g_btnBind6)[idx] == val) { (&g_btnBind6)[idx] = saved; saved = 0; }
    if ((&g_btnBind7)[idx] == val) { (&g_btnBind7)[idx] = saved; saved = 0; }
    if ((&g_btnBind8)[idx] == val) { (&g_btnBind8)[idx] = saved; }
    *p = val;
}

#endif  /* NON_MATCHING */
