/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
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
#endif

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
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_cj_00542058;
extern unsigned int g_rangeSqLimit;
extern unsigned int g_armedReloadA;
extern unsigned int g_armedReloadB;
extern unsigned int g_dualBitGate;
extern unsigned int g_eventArmReload;
extern unsigned int g_rangeBase;
#endif

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
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
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
#endif

/*
 * ChainStreamMatMulVecAdd - 208b engine.geo chain-stream MatMul+Vec3Add.
 *   stream = g_eventQueueTotal; advance: g_walkCallback = stream[0]; g_eventQueueCurrent = stream[1];
 *   g_eventQueueTotal = stream[2] (next stream ptr). Unpack g_xformEntityIdx base:
 *   load 4 dwords + 1 word into g_vtxMat..g_wtMatExtraWord.
 *   Push (g_pendingNodeType<<2, g_currentNodeIdx<<2); call Mat3x3VecMul6Bit; restore.
 *   Add g_walkCallback into target[0], g_eventQueueCurrent into target[1], g_eventQueueTotal into target[2].
 */
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_wtMatExtraWord;
extern s16 g_vtxMat[];
extern unsigned int g_mat3x3_007af994;
extern unsigned int g_mat3x3_007af998;
extern unsigned int g_mat3x3_007af99c;
#endif
#ifdef NON_MATCHING
extern void Mat3x3VecMul6Bit(int *src, int *dst);
#else
extern void Mat3x3VecMul6Bit(void);
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_active_00537e88 (*(unsigned int *)MK4_VA(unsigned int, 0x537e88u))
#define g_active_0053a408 (*(unsigned int *)MK4_VA(unsigned int, 0x53a408u))
#define g_armedReloadA (*(unsigned int *)MK4_VA(unsigned int, 0x541fa4u))
#define g_armedReloadB (*(unsigned int *)MK4_VA(unsigned int, 0x541fa8u))
#define g_audioBankSel (*(unsigned int *)MK4_VA(unsigned int, 0x537f94u))
#define g_audioBoundNode (*(unsigned int *)MK4_VA(unsigned int, 0x5437f0u))
#define g_baseSel (*(unsigned int *)MK4_VA(unsigned int, 0x542060u))
#define g_chainAccumCur (*(unsigned int *)MK4_VA(unsigned int, 0x542078u))
#define g_cj_00542054 (*(unsigned int *)MK4_VA(unsigned int, 0x542054u))
#define g_cj_00542058 (*(unsigned int *)MK4_VA(unsigned int, 0x542058u))
#define g_cj_0054205c (*(unsigned int *)MK4_VA(unsigned int, 0x54205cu))
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_dualBitGate (*(unsigned int *)MK4_VA(unsigned int, 0x53a7b0u))
#define g_eventArmReload (*(unsigned int *)MK4_VA(unsigned int, 0x53a770u))
#define g_eventQueueCurrent (*(unsigned int *)MK4_VA(unsigned int, 0x542070u))
#define g_eventQueueTotal (*(unsigned int *)MK4_VA(unsigned int, 0x542050u))
#define g_fightAxisNegX (*(unsigned int *)MK4_VA(unsigned int, 0x535e70u))
#define g_fightAxisNegY (*(unsigned int *)MK4_VA(unsigned int, 0x535e74u))
#define g_fightAxisPosX (*(unsigned int *)MK4_VA(unsigned int, 0x535e78u))
#define g_fightAxisPosY (*(unsigned int *)MK4_VA(unsigned int, 0x535e7cu))
#define g_fightStateProgress (*(unsigned int *)MK4_VA(unsigned int, 0x535ddcu))
#define g_gameCountdown (*(unsigned int *)MK4_VA(unsigned int, 0x53a718u))
#define g_installOwnerNode (*(unsigned int *)MK4_VA(unsigned int, 0x535cf8u))
#define g_lastGatedTick (*(unsigned int *)MK4_VA(unsigned int, 0x54358cu))
#define g_lastGatedValue (*(unsigned int *)MK4_VA(unsigned int, 0x543598u))
#define g_mat3x3_007af994 (*(short *)MK4_VA(short, 0x7af994u))
#define g_mat3x3_007af998 (*(short *)MK4_VA(short, 0x7af998u))
#define g_mat3x3_007af99c (*(short *)MK4_VA(short, 0x7af99cu))
#define g_pendingNodeType (*(unsigned int *)MK4_VA(unsigned int, 0x54204cu))
#define g_rangeBase (*(unsigned int *)MK4_VA(unsigned int, 0x53a46cu))
#define g_rangeSqLimit (*(unsigned int *)MK4_VA(unsigned int, 0x53a180u))
#define g_stateCountdown (*(unsigned int *)MK4_VA(unsigned int, 0x53a3c0u))
#define g_vtxMat ((short *)MK4_VA(short, 0x7af990u))
#define g_walkCallback (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_wtMatExtraWord (*(short *)MK4_VA(short, 0x7af9a0u))
#define g_xformEntityIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542048u))
#define g_xformScratch94 (*(unsigned int *)MK4_VA(unsigned int, 0x542094u))
#endif


#ifdef NON_MATCHING
#include "portable/mem_model.h"

/* Portable twin. TransformAccumulate's bigger sibling: same save-project-add
 * shape, but it refreshes the working 3x3 from the transform entity first, and
 * the third saved component lands in g_eventQueueTotal instead of
 * g_xformEntityIdx - so the source cursor is consumed by the same operation
 * that reads it.
 *
 * The 3x3 moves as four dwords plus a trailing halfword, the original access
 * width; g_vtxMat is declared s16[], so going through the array would be a
 * different one. */
void ChainStreamMatMulVecAdd(void)
{
    unsigned int src = g_eventQueueTotal;
    unsigned int m;

    g_walkCallback         = MK4_NODE_AT(unsigned int, src, 0);
    g_eventQueueCurrent = MK4_NODE_AT(unsigned int, src, 4);
    m                      = g_xformEntityIdx;
    g_eventQueueTotal      = MK4_NODE_AT(unsigned int, src, 8);

    *(unsigned int   *)MK4_VA(unsigned int,   0x7af990u) = MK4_NODE_AT(unsigned int, m, 0);
    *(unsigned int   *)MK4_VA(unsigned int,   0x7af994u) = MK4_NODE_AT(unsigned int, m, 4);
    *(unsigned int   *)MK4_VA(unsigned int,   0x7af998u) = MK4_NODE_AT(unsigned int, m, 8);
    *(unsigned int   *)MK4_VA(unsigned int,   0x7af99cu) = MK4_NODE_AT(unsigned int, m, 0xc);
    *(unsigned short *)MK4_VA(unsigned short, 0x7af9a0u) = MK4_NODE_AT(unsigned short, m, 0x10);

    Mat3x3VecMul6Bit(MK4_NODE(int, g_pendingNodeType),
                     MK4_NODE(int, g_currentNodeIdx));

    MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0) += g_walkCallback;
    MK4_NODE_AT(unsigned int, g_currentNodeIdx, 4) += g_eventQueueCurrent;
    MK4_NODE_AT(unsigned int, g_currentNodeIdx, 8) += g_eventQueueTotal;
}
#else
void ChainStreamMatMulVecAdd(void) {
    __asm {
        mov     eax, dword ptr [g_eventQueueTotal]
        mov     ecx, dword ptr [eax*4]
        mov     dword ptr [g_walkCallback], ecx
        mov     edx, dword ptr [eax*4 + 4]
        mov     ecx, dword ptr [g_xformEntityIdx]
        mov     dword ptr [g_eventQueueCurrent], edx
        mov     eax, dword ptr [eax*4 + 8]
        lea     edx, [ecx*4]
        mov     dword ptr [g_eventQueueTotal], eax
        mov     eax, dword ptr [edx]
        mov     dword ptr [g_vtxMat], eax
        mov     ecx, dword ptr [edx + 4]
        mov     dword ptr [g_mat3x3_007af994], ecx
        mov     eax, dword ptr [edx + 8]
        mov     dword ptr [g_mat3x3_007af998], eax
        mov     eax, dword ptr [g_currentNodeIdx]
        mov     ecx, dword ptr [edx + 0xc]
        mov     dword ptr [g_mat3x3_007af99c], ecx
        lea     ecx, [eax*4]
        mov     dx, word ptr [edx + 0x10]
        push    ecx
        mov     word ptr [g_wtMatExtraWord], dx
        mov     edx, dword ptr [g_pendingNodeType]
        lea     eax, [edx*4]
        push    eax
        call    Mat3x3VecMul6Bit
        mov     eax, dword ptr [g_currentNodeIdx]
        mov     ecx, dword ptr [g_walkCallback]
        add     esp, 8
        mov     edx, dword ptr [eax*4]
        add     edx, ecx
        mov     dword ptr [eax*4], edx
        mov     eax, dword ptr [g_currentNodeIdx]
        mov     edx, dword ptr [g_eventQueueCurrent]
        mov     ecx, dword ptr [eax*4 + 4]
        add     ecx, edx
        mov     dword ptr [eax*4 + 4], ecx
        mov     eax, dword ptr [g_currentNodeIdx]
        mov     ecx, dword ptr [g_eventQueueTotal]
        add     dword ptr [eax*4 + 8], ecx
        }
}

#endif
