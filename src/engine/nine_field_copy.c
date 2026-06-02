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

/* @addr 0x0048f980 (148b game) - 9-field copy:
 *   src = &arr_src[cj];  dst = chain[sel].slot38 * 4 (treated as ptr).
 *   Copy fields at offsets 0x54, 0x58, 0x5c, 0x60, 0x64, 0x68, 0x78, 0x7c,
 *   0x80 from src to dst (with g_walkCallback used as scratch).
 */

extern unsigned int g_arr_48f980_src;
extern unsigned int g_chain_arr_4348f0;

void NineFieldCopy(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel]
        mov     edx, dword ptr [g_cj_0054205c]
        mov     ecx, [eax*4 + g_chain_arr_4348f0 + 0x38]
        lea     eax, [edx*4 + g_arr_48f980_src]
        mov     dword ptr [g_eventQueueEnd], ecx
        mov     edx, dword ptr [eax + 0x54]
        shl     ecx, 2
        mov     dword ptr [g_walkCallback], edx
        mov     dword ptr [ecx + 0x54], edx
        mov     edx, dword ptr [eax + 0x58]
        mov     dword ptr [g_walkCallback], edx
        mov     dword ptr [ecx + 0x58], edx
        mov     edx, dword ptr [eax + 0x5c]
        mov     dword ptr [g_walkCallback], edx
        mov     dword ptr [ecx + 0x5c], edx
        mov     edx, dword ptr [eax + 0x60]
        mov     dword ptr [g_walkCallback], edx
        mov     dword ptr [ecx + 0x60], edx
        mov     edx, dword ptr [eax + 0x64]
        mov     dword ptr [g_walkCallback], edx
        mov     dword ptr [ecx + 0x64], edx
        mov     edx, dword ptr [eax + 0x68]
        mov     dword ptr [g_walkCallback], edx
        mov     dword ptr [ecx + 0x68], edx
        mov     edx, dword ptr [eax + 0x78]
        mov     dword ptr [g_walkCallback], edx
        mov     dword ptr [ecx + 0x78], edx
        mov     edx, dword ptr [eax + 0x7c]
        mov     dword ptr [g_walkCallback], edx
        mov     dword ptr [ecx + 0x7c], edx
        mov     eax, dword ptr [eax + 0x80]
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx + 0x80], eax
        }
}

