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
 * @addr 0x0041f710 (106b boot) - node unlink:
 *   If node is the current tail, just update tail to node->next (0xe4).
 *   Else walk a 0xe8-strided array at 0x53e44c, find the slot whose
 *   first dword == node, and unlink: copy node->next into that slot.
 *   Then clear node->prev (+0xd8) and node->next (+0xe4), decrement
 *   the alloc counter.
 */
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_nodeSlotsHdr;
extern unsigned int g_nodeUnlinkSlot;
#endif

#ifdef NON_MATCHING
#include "portable/mem_model.h"
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_nodeAllocCounter;
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
#define g_fightAxisNegX (*(unsigned int *)MK4_VA(unsigned int, 0x535e70u))
#define g_fightAxisNegY (*(unsigned int *)MK4_VA(unsigned int, 0x535e74u))
#define g_fightAxisPosX (*(unsigned int *)MK4_VA(unsigned int, 0x535e78u))
#define g_fightAxisPosY (*(unsigned int *)MK4_VA(unsigned int, 0x535e7cu))
#define g_fightStateProgress (*(unsigned int *)MK4_VA(unsigned int, 0x535ddcu))
#define g_gameCountdown (*(unsigned int *)MK4_VA(unsigned int, 0x53a718u))
#define g_installOwnerNode (*(unsigned int *)MK4_VA(unsigned int, 0x535cf8u))
#define g_lastGatedTick (*(unsigned int *)MK4_VA(unsigned int, 0x54358cu))
#define g_lastGatedValue (*(unsigned int *)MK4_VA(unsigned int, 0x543598u))
#define g_nodeAllocCounter (*(unsigned int *)MK4_VA(unsigned int, 0x541e64u))
#define g_nodeListTail (*(unsigned int *)MK4_VA(unsigned int, 0x52ab3cu))
#define g_nodeSlotsHdr (*(unsigned int *)MK4_VA(unsigned int, 0x53e44cu))
#define g_nodeSlotsHdr_nextLink (*(unsigned int *)MK4_VA(unsigned int, 0x53e44cu))
#define g_nodeUnlinkSlot (*(unsigned int *)MK4_VA(unsigned int, 0x541e4cu))
#define g_rangeBase (*(unsigned int *)MK4_VA(unsigned int, 0x53a46cu))
#define g_rangeSqLimit (*(unsigned int *)MK4_VA(unsigned int, 0x53a180u))
#define g_stateCountdown (*(unsigned int *)MK4_VA(unsigned int, 0x53a3c0u))
#define g_xformScratch94 (*(unsigned int *)MK4_VA(unsigned int, 0x542094u))
#endif


/* Portable twin. The walk is bounded by an ADDRESS compare against 0x541e4c,
 * which is exactly 64 slots past the 0xe8-strided base - so it is a fixed
 * 64-iteration search, and expressing it as a count keeps the bound correct
 * once the table is relocated into the arena.
 *
 * The `ret` at 0x41f742 is the not-found exit and it does NOT clear the node
 * or touch the counter, so the miss case has to return early rather than fall
 * through to the tail.
 *
 * The node arrives as a raw pointer in edx ([esp+4]), not a packed index; the
 * parameter is a host pointer here so that callers under the arena pass an
 * already-translated address. Under the identity model a VA IS the pointer,
 * so this is the same value the original passes. */
void NodeUnlink(void *node)
{
    unsigned char *n     = (unsigned char *)node;
    unsigned int  *slots = &g_nodeSlotsHdr_nextLink;   /* 0x0053e44c */
    unsigned int   next  = 0;
    unsigned int   i;

    if (g_nodeListTail == MK4_UNPTR(n)) {
        g_nodeListTail = *(unsigned int *)(n + 0xe4);
    } else {
        for (i = 0; i < 64; i++) {
            if (slots[i * (0xe8 / 4)] == MK4_UNPTR(n)) {
                next = *(unsigned int *)(n + 0xe4);
                slots[i * (0xe8 / 4)] = next;
                break;
            }
        }
        if (i == 64)
            return;                       /* not found: bare ret, no clearing */
    }
    *(unsigned int *)(n + 0xd8) = 0;
    *(unsigned int *)(n + 0xe4) = 0;
    g_nodeAllocCounter--;
}
#else
void NodeUnlink(void) {
    __asm {
        mov     edx, dword ptr [esp + 4]
        mov     eax, dword ptr [g_nodeListTail]
        cmp     eax, edx
        jne     walk
        mov     eax, dword ptr [edx + 0xe4]
        mov     dword ptr [g_nodeListTail], eax
        jmp     clear
walk:
        xor     ecx, ecx
        mov     eax, offset g_nodeSlotsHdr
loop_top:
        cmp     dword ptr [eax], edx
        je      hit
        add     eax, 0xe8
        inc     ecx
        cmp     eax, offset g_nodeUnlinkSlot
        jb      loop_top
        ret
hit:
        mov     eax, ecx
        shl     eax, 3
        sub     eax, ecx
        lea     ecx, [ecx + eax*4]
        mov     eax, dword ptr [edx + 0xe4]
        mov     dword ptr [ecx*8 + g_nodeSlotsHdr], eax
clear:
        mov     dword ptr [edx + 0xd8], 0
        mov     dword ptr [edx + 0xe4], 0
        mov     eax, dword ptr [g_nodeAllocCounter]
        dec     eax
        mov     dword ptr [g_nodeAllocCounter], eax
        }
}
#endif

