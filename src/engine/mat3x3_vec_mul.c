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

/* @addr 0x004b3630 (142b engine.geo) - 3x3 fixed-point matrix * vec3:
 *   out[0] = (mat[0]*v.x + mat[1]*v.y + mat[2]*v.z) >> 12
 *   out[1] = (mat[3]*v.x + mat[4]*v.y + mat[5]*v.z) >> 12
 *   out[2] = (mat[6]*v.x + mat[7]*v.y + mat[8]*v.z) >> 12
 */
extern unsigned int g_mat3x3_007af990;
extern unsigned int g_mat3x3_007af992;
extern unsigned int g_mat3x3_007af994;
extern unsigned int g_mat3x3_007af996;
extern unsigned int g_mat3x3_007af998;
extern unsigned int g_mat3x3_007af99a;
extern unsigned int g_mat3x3_007af99c;
extern unsigned int g_mat3x3_007af99e;
extern unsigned int g_mat3x3_007af9a0;

__declspec(naked) void Mat3x3VecMul(void) {
    __asm {
        mov     edx, dword ptr [esp + 4]
        push    ebx
        push    esi
        push    edi
        movsx   edi, word ptr [g_mat3x3_007af994]
        movsx   esi, word ptr [g_mat3x3_007af992]
        mov     eax, dword ptr [edx]
        mov     ecx, dword ptr [edx + 4]
        mov     edx, dword ptr [edx + 8]
        imul    esi, ecx
        imul    edi, edx
        add     edi, esi
        movsx   esi, word ptr [g_mat3x3_007af990]
        imul    esi, eax
        add     edi, esi
        mov     esi, dword ptr [esp + 0x14]
        sar     edi, 0xc
        mov     dword ptr [esi], edi
        movsx   edi, word ptr [g_mat3x3_007af99a]
        movsx   ebx, word ptr [g_mat3x3_007af998]
        imul    edi, edx
        imul    ebx, ecx
        add     edi, ebx
        movsx   ebx, word ptr [g_mat3x3_007af996]
        imul    ebx, eax
        add     edi, ebx
        sar     edi, 0xc
        mov     dword ptr [esi + 4], edi
        movsx   edi, word ptr [g_mat3x3_007af9a0]
        imul    edi, edx
        movsx   edx, word ptr [g_mat3x3_007af99e]
        imul    edx, ecx
        movsx   ecx, word ptr [g_mat3x3_007af99c]
        imul    ecx, eax
        add     edi, edx
        add     edi, ecx
        sar     edi, 0xc
        mov     dword ptr [esi + 8], edi
        pop     edi
        pop     esi
        pop     ebx
        ret
    }
}
