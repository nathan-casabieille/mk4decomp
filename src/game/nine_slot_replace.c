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
extern void SetJmp_0049cb90(void);
extern void Thunk_0049cbd0(void);
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
extern void Wrapper_00436490(void);
extern void MoveFsmCluster(void);
extern void CallPauseTestByteJmpCalls(void);
extern void InstallSelfFullPath(void);
extern void InstallSelfCountdownChain(void);
extern void CopyJmp_0048ef90(void);
extern void DualTestDirtyToggle_004282c0(void);
extern void TripleVecAccCallStore(void);
extern void Thunk_004bd5c0(void);
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
extern void Wrapper_0048a350(void);
extern void Wrapper_0048a3a0(void);
extern void Helper_DownloadSetup(void);
extern void MStackPush3CmpCall(void);
extern void Wrapper_0048ec20(void);
extern void FiveCallScaledChainTailJmp(void);
extern void SetJmp_00438f50(void);
extern void SetJmp_00438f60(void);
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

/* @addr 0x004b7a40 (193b game.menu) - search 9-slot table; replace first match with eax.
 *   Caller passes (esi=&id, edx=new_id, ecx_idx=[esp+0x10]).
 *   eax = *esi; *esi = 0; if (edx == 0) goto end.
 *   For each slot (0..8): if (slot[ecx_idx] == edx) { slot[ecx_idx] = eax; eax = 0; }
 *   *esi = edx. pop esi; ret.
 */
extern unsigned int g_btnBind0_00543b20;
extern unsigned int g_btnBind1_00543b28;
extern unsigned int g_btnBind2_00543b30;
extern unsigned int g_btnBind3_00543b38;
extern unsigned int g_btnBind4_00543b40;
extern unsigned int g_btnBind5_00543b48;
extern unsigned int g_btnBind6_00543b50;
extern unsigned int g_btnBind7_00543b58;
extern unsigned int g_btnBind8_00543b60;

void Input_RebindButtonToAction(unsigned int *p, unsigned int val, unsigned int idx)
{
    unsigned int saved = *p;
    *p = 0;
    if (!val) return;
    if ((&g_btnBind0_00543b20)[idx] == val) { (&g_btnBind0_00543b20)[idx] = saved; saved = 0; }
    if ((&g_btnBind1_00543b28)[idx] == val) { (&g_btnBind1_00543b28)[idx] = saved; saved = 0; }
    if ((&g_btnBind2_00543b30)[idx] == val) { (&g_btnBind2_00543b30)[idx] = saved; saved = 0; }
    if ((&g_btnBind3_00543b38)[idx] == val) { (&g_btnBind3_00543b38)[idx] = saved; saved = 0; }
    if ((&g_btnBind4_00543b40)[idx] == val) { (&g_btnBind4_00543b40)[idx] = saved; saved = 0; }
    if ((&g_btnBind5_00543b48)[idx] == val) { (&g_btnBind5_00543b48)[idx] = saved; saved = 0; }
    if ((&g_btnBind6_00543b50)[idx] == val) { (&g_btnBind6_00543b50)[idx] = saved; saved = 0; }
    if ((&g_btnBind7_00543b58)[idx] == val) { (&g_btnBind7_00543b58)[idx] = saved; saved = 0; }
    if ((&g_btnBind8_00543b60)[idx] == val) { (&g_btnBind8_00543b60)[idx] = saved; }
    *p = val;
}
