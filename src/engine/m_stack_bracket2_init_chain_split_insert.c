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

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_vertexInitFlag;
extern unsigned int g_vertexInitVar;
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
#define g_fightAxisNegX (*(unsigned int *)MK4_VA(unsigned int, 0x535e70u))
#define g_fightAxisNegY (*(unsigned int *)MK4_VA(unsigned int, 0x535e74u))
#define g_fightAxisPosX (*(unsigned int *)MK4_VA(unsigned int, 0x535e78u))
#define g_fightAxisPosY (*(unsigned int *)MK4_VA(unsigned int, 0x535e7cu))
#define g_fightStateProgress (*(unsigned int *)MK4_VA(unsigned int, 0x535ddcu))
#define g_framePauseFlag (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_gameCountdown (*(unsigned int *)MK4_VA(unsigned int, 0x53a718u))
#define g_installOwnerNode (*(unsigned int *)MK4_VA(unsigned int, 0x535cf8u))
#define g_lastGatedTick (*(unsigned int *)MK4_VA(unsigned int, 0x54358cu))
#define g_lastGatedValue (*(unsigned int *)MK4_VA(unsigned int, 0x543598u))
#define g_matrixStackTop (*(unsigned int *)MK4_VA(unsigned int, 0x4d57acu))
#define g_rangeBase (*(unsigned int *)MK4_VA(unsigned int, 0x53a46cu))
#define g_rangeSqLimit (*(unsigned int *)MK4_VA(unsigned int, 0x53a180u))
#define g_stateCountdown (*(unsigned int *)MK4_VA(unsigned int, 0x53a3c0u))
#define g_vertexInitFlag (*(unsigned int *)MK4_VA(unsigned int, 0x541e74u))
#define g_vertexInitVar (*(unsigned int *)MK4_VA(unsigned int, 0x541e78u))
#define g_walkCallback (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_xformDirtyFlags (*(unsigned int *)MK4_VA(unsigned int, 0x54208cu))
#define g_xformEntityIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542048u))
#define g_xformScratch94 (*(unsigned int *)MK4_VA(unsigned int, 0x542094u))
#endif

extern void MStackBracket5_LinkedListUnlink(void);
extern void MStackPush2ChainInsert(void);

#ifdef NON_MATCHING
#include "portable/mem_model.h"

extern void Helper_TickAlt(void);
extern void MStackBracket5_LinkedListUnlink(void);
extern void MStackPush2ChainInsert(void);

/* @addr 0x00425ba0 - the size predicate the walk below installs as its
 * callback. Packed inside DualEntryInitCmp's symbol with no name of its
 * own, so it is registered in config/codeptr_extras.yaml. Reports "fits"
 * by clearing dirty bit 0 when the block at the current node is at least
 * as large as the request, and sets it when it is not. */
void ChainSplit_SizeFits_00425ba0(void)
{
    unsigned int have = MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0xc) + 1;

    g_walkCallback = have;
    if ((int)g_eventQueueCurrent >= (int)have)
        g_xformDirtyFlags &= 0xfffffffeu;
    else
        g_xformDirtyFlags |= 1;
}

/* @addr 0x00425be0 (457b) - NATIVE twin; the matching build keeps the
 * __asm body below.
 *
 * The block allocator with a split. Brackets the entity and the element
 * counter, clamps the request to at least 4, and walks the free chain
 * from g_vertexInitFlag with the size predicate above. On a hit the block
 * is unlinked, re-inserted under g_vertexInitVar, and if the leftover is
 * 8 words or more it is SPLIT: the block keeps the requested size, and
 * the remainder (a fresh node four words past the request) is capped and
 * inserted back into the free chain. The caller gets the block index plus
 * four - the header the split leaves in front of the payload. Pause exits
 * leak the bracket, and the tail signals not-found only when the index
 * came back null. */
void MStackBracket2InitChainSplitInsert(void)
{
    unsigned int node, want, left, rest, saved;

    g_matrixStackTop++;
    *MK4_NODE(unsigned int, g_matrixStackTop) = g_xformEntityIdx;
    g_matrixStackTop++;
    *MK4_NODE(unsigned int, g_matrixStackTop) = g_eventQueueCurrent;

    g_eventQueueCurrent = g_walkCallback;
    if (g_walkCallback < 4u)
        g_eventQueueCurrent = 4;

    g_currentNodeIdx = g_vertexInitFlag;
    g_walkCallback = 0x425ba0u;
    Helper_TickAlt();
    if (g_framePauseFlag != 0) return;          /* bracket leaked */

    if ((g_xformDirtyFlags & 4u) == 0) {
        g_xformEntityIdx = 0;
        MStackBracket5_LinkedListUnlink();
        if (g_framePauseFlag != 0) return;
        g_xformEntityIdx = g_vertexInitVar;
        MStackPush2ChainInsert();
        if (g_framePauseFlag != 0) return;

        node = g_currentNodeIdx;
        want = g_eventQueueCurrent;
        left = MK4_NODE_AT(unsigned int, node, 0xc) - want;
        g_walkCallback = left;
        if (left >= 8u) {
            MK4_NODE_AT(unsigned int, node, 0xc) = want;
            g_matrixStackTop++;
            *MK4_NODE(unsigned int, g_matrixStackTop) = g_currentNodeIdx;

            rest = g_currentNodeIdx + g_eventQueueCurrent + 4;
            g_currentNodeIdx = rest;
            MK4_NODE_AT(unsigned int, rest, 0xc) = g_walkCallback - 4;
            g_walkCallback = 0;
            MK4_NODE_AT(unsigned int, g_currentNodeIdx, 4) = 0;
            g_xformEntityIdx = g_vertexInitFlag;
            MStackPush2ChainInsert();
            if (g_framePauseFlag != 0) return;

            node = *MK4_NODE(unsigned int, g_matrixStackTop);
            g_matrixStackTop--;
        }
        node += 4;
        g_currentNodeIdx = node;
    } else {
        node = g_currentNodeIdx;                /* not found: publish as is */
    }

    saved = g_eventQueueCurrent;
    g_walkCallback = saved;
    g_eventQueueCurrent = *MK4_NODE(unsigned int, g_matrixStackTop);
    g_matrixStackTop--;
    g_xformEntityIdx = *MK4_NODE(unsigned int, g_matrixStackTop);
    g_matrixStackTop--;
    g_xformDirtyFlags |= 4;
    if (node != 0) g_xformDirtyFlags ^= 4;
}
#else
__declspec(naked) void MStackBracket2InitChainSplitInsert(void)
{
    __asm
    {
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_xformEntityIdx]
        inc     eax
        push    ebx
        mov     dword ptr [g_matrixStackTop], eax
        mov     ebx, 4
        mov     dword ptr [eax*4], ecx
        mov     eax, dword ptr [g_matrixStackTop]
        mov     edx, dword ptr [g_eventQueueCurrent]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4], edx
        mov     eax, dword ptr [g_walkCallback]
        cmp     eax, ebx
        mov     dword ptr [g_eventQueueCurrent], eax
        jae     short L_mbsi_skip1
        mov     dword ptr [g_eventQueueCurrent], ebx
    L_mbsi_skip1:
        mov     eax, dword ptr [g_vertexInitFlag]
        mov     dword ptr [g_walkCallback], 0x425ba0
        mov     dword ptr [g_currentNodeIdx], eax
        call    Helper_TickAlt
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_mbsi_pop
        test    byte ptr [g_xformDirtyFlags], bl
        jne     L_mbsi_loadSav
        mov     dword ptr [g_xformEntityIdx], 0
        call    MStackBracket5_LinkedListUnlink
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_mbsi_pop
        mov     ecx, dword ptr [g_vertexInitVar]
        mov     dword ptr [g_xformEntityIdx], ecx
        call    MStackPush2ChainInsert
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_mbsi_pop
        mov     eax, dword ptr [g_currentNodeIdx]
        mov     edx, dword ptr [g_eventQueueCurrent]
        mov     ecx, dword ptr [eax*4 + 0xc]
        sub     ecx, edx
        cmp     ecx, 8
        mov     dword ptr [g_walkCallback], ecx
        jb      L_mbsi_combine
        mov     dword ptr [eax*4 + 0xc], edx
        mov     eax, dword ptr [g_matrixStackTop]
        mov     edx, dword ptr [g_currentNodeIdx]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4], edx
        mov     eax, dword ptr [g_eventQueueCurrent]
        mov     ecx, dword ptr [g_currentNodeIdx]
        mov     edx, dword ptr [g_walkCallback]
        add     edx, -4
        lea     eax, [ecx + eax + 4]
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [eax*4 + 0xc], edx
        mov     eax, dword ptr [g_currentNodeIdx]
        mov     dword ptr [g_walkCallback], 0
        mov     dword ptr [eax*4 + 4], 0
        mov     ecx, dword ptr [g_vertexInitFlag]
        mov     dword ptr [g_xformEntityIdx], ecx
        call    MStackPush2ChainInsert
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_mbsi_pop
        mov     ecx, dword ptr [g_matrixStackTop]
        mov     eax, dword ptr [ecx*4]
        dec     ecx
        mov     dword ptr [g_matrixStackTop], ecx
    L_mbsi_combine:
        add     eax, ebx
        mov     dword ptr [g_currentNodeIdx], eax
        jmp     short L_mbsi_loadCommon
    L_mbsi_loadSav:
        mov     eax, dword ptr [g_currentNodeIdx]
    L_mbsi_loadCommon:
        mov     edx, dword ptr [g_eventQueueCurrent]
        mov     ecx, dword ptr [g_matrixStackTop]
        mov     dword ptr [g_walkCallback], edx
        mov     edx, dword ptr [ecx*4]
        dec     ecx
        mov     dword ptr [g_eventQueueCurrent], edx
        mov     dword ptr [g_matrixStackTop], ecx
        mov     edx, dword ptr [ecx*4]
        dec     ecx
        mov     dword ptr [g_xformEntityIdx], edx
        mov     edx, dword ptr [g_xformDirtyFlags]
        or      edx, ebx
        mov     dword ptr [g_matrixStackTop], ecx
        test    eax, eax
        mov     dword ptr [g_xformDirtyFlags], edx
        je      short L_mbsi_pop
        mov     eax, edx
        xor     eax, ebx
        mov     dword ptr [g_xformDirtyFlags], eax
    L_mbsi_pop:
        pop     ebx
        ret
    }
}
#endif
