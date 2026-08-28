/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
#include "portable/ghidra_types.h"
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

/* @addr 0x004bc470 (294b engine.render) - per-tri vertex/UV building from indexed source.
 *   arg0 (esp+8): poly index. Reads [0x542048]+4 (base table); fetches 16-byte
 *   entry; reads bp = count (entry+0xe), ebx = entry+0xc. If ebp == 0, free slot
 *   in [edx*4 + 0x48] table and return.
 *   Allocates a vertex block via LeaScaledCall + Mem_Malloc; iterates
 *   `ebp` times copying UV (3 u16) + reading color index (byte) -> palette
 *   byte, masking into output.
 */
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_dispatchSave1572;
#endif
#ifdef NON_MATCHING
extern void LeaScaledCall(int);
extern s32  Mem_Malloc(void **out_ptr, s32 size, s32 tag);
#else
extern void LeaScaledCall(void);
extern void Mem_Malloc(void);
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
#define g_dispatchSave1572 (*(unsigned int *)MK4_VA(unsigned int, 0xab4e34u))
#define g_dualBitGate (*(unsigned int *)MK4_VA(unsigned int, 0x53a7b0u))
#define g_eventArmReload (*(unsigned int *)MK4_VA(unsigned int, 0x53a770u))
#define g_fightAxisNegX (*(unsigned int *)MK4_VA(unsigned int, 0x535e70u))
#define g_fightAxisNegY (*(unsigned int *)MK4_VA(unsigned int, 0x535e74u))
#define g_fightAxisPosX (*(unsigned int *)MK4_VA(unsigned int, 0x535e78u))
#define g_fightAxisPosY (*(unsigned int *)MK4_VA(unsigned int, 0x535e7cu))
#define g_fightGroupHead (*(unsigned int *)MK4_VA(unsigned int, 0x54205cu))
#define g_fightStateProgress (*(unsigned int *)MK4_VA(unsigned int, 0x535ddcu))
#define g_gameCountdown (*(unsigned int *)MK4_VA(unsigned int, 0x53a718u))
#define g_installOwnerNode (*(unsigned int *)MK4_VA(unsigned int, 0x535cf8u))
#define g_lastGatedTick (*(unsigned int *)MK4_VA(unsigned int, 0x54358cu))
#define g_lastGatedValue (*(unsigned int *)MK4_VA(unsigned int, 0x543598u))
#define g_pendingNodeType (*(unsigned int *)MK4_VA(unsigned int, 0x54204cu))
#define g_rangeBase (*(unsigned int *)MK4_VA(unsigned int, 0x53a46cu))
#define g_rangeSqLimit (*(unsigned int *)MK4_VA(unsigned int, 0x53a180u))
#define g_stateCountdown (*(unsigned int *)MK4_VA(unsigned int, 0x53a3c0u))
#define g_xformEntityIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542048u))
#define g_xformScratch94 (*(unsigned int *)MK4_VA(unsigned int, 0x542094u))
#endif


#ifdef NON_MATCHING
#include "portable/mem_model.h"

/* Portable twin, written from the disassembly. Builds the vertex block for one
 * mesh entry: 0x1c bytes per vertex, zeroed and then filled from a source
 * stream.
 *
 * g_xformEntityIdx is a RAW VA here, not a packed index - the original
 * dereferences it as `[ecx + 4]` with no scaling, unlike everywhere else in
 * the engine that indexes it as `[reg*4 + off]`.
 *
 * When `reuse` is set the existing block is kept if its header's low bits match
 * the wanted flags AND it is already big enough; otherwise the old one is
 * released and a fresh one allocated. Either failure - a zero vertex count, or
 * the allocator returning nothing - clears both the pending type and the node's
 * cache slot, which marks the node unbuilt so the next call retries.
 *
 * Two details are transcribed rather than tidied. The header packs the entry
 * address SHIFTED LEFT five and OR'd with the flags, which discards the top
 * bits of that address; and the per-vertex tail reads back the halfword it
 * just zeroed to mask it, so the mask is always against zero. */
void VertexQuadBuilder(int index, int reuse)
{
    unsigned int xe    = g_xformEntityIdx;                  /* a VA */
    unsigned int base  = *(unsigned int *)MK4_PTR(xe + 4);
    unsigned int entry = (unsigned)index * 0x10u + base + 0xc;
    unsigned int count = *(unsigned short *)MK4_PTR(entry + 2);
    unsigned int slot, flags, need, blk, dst, src, tbl;

    if (count == 0)
        goto fail;

    flags = (unsigned int)(((int)g_fightGroupHead >> 16) & 8) | g_dispatchSave1572;
    slot  = g_currentNodeIdx * 4u + 0x48u;
    need  = count * 0x1cu;                       /* (count << 3) - count, << 2 */

    if (reuse != 0) {
        blk = *(unsigned int *)MK4_PTR(slot);
        if ((*(unsigned int *)MK4_PTR(blk) & 9) == flags
            && (int)need <= (int)*(unsigned int *)MK4_PTR(blk + 4))
            goto have;
        LeaScaledCall(2);
    }

    blk = (unsigned int)Mem_Malloc((void **)MK4_PTR(slot), (s32)(need + 0xc), 2);
    if (blk == 0)
        goto fail;
    *(unsigned int *)MK4_PTR(blk + 4) = need;

have:
    g_pendingNodeType = blk;
    *(unsigned int *)MK4_PTR(blk) = (entry << 5) | flags;

    dst = blk + 8;
    src = entry + 0xc + *(unsigned int *)MK4_PTR(entry + 0xc);
    base = *(unsigned int *)MK4_PTR(xe + 4);
    tbl  = base + 8 + *(unsigned int *)MK4_PTR(base + 4);

    while (count != 0) {
        int shade;
        unsigned int i;

        for (i = 0; i < 7; i++)
            *(unsigned int *)MK4_PTR(dst + i * 4) = 0;

        *(unsigned short *)MK4_PTR(dst + 0xc)  = *(unsigned short *)MK4_PTR(src + 2);
        *(unsigned short *)MK4_PTR(dst + 0xe)  = *(unsigned short *)MK4_PTR(src + 4);
        *(unsigned short *)MK4_PTR(dst + 0x10) = *(unsigned short *)MK4_PTR(src + 6);

        /* signed byte index into the shade table */
        shade = (int)*(signed char *)MK4_PTR(src);
        *(unsigned short *)MK4_PTR(dst + 0x1a) = (unsigned short)
            ((*(unsigned char *)MK4_PTR(tbl + (unsigned)(shade * 4) + 2) & 0xf)
             | (*(unsigned short *)MK4_PTR(dst + 0x1a) & 0xfff0));

        dst += 0x1c;
        src += 8;
        count--;
    }
    return;

fail:
    g_pendingNodeType = 0;
    MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x48) = 0;
}
#else
__declspec(naked) void VertexQuadBuilder(void) {
    __asm {
        push    ecx
        mov     ecx, dword ptr [g_xformEntityIdx]
        mov     eax, [esp + 8]
        shl     eax, 4
        mov     edx, [ecx + 4]
        push    ebx
        push    ebp
        xor     ebp, ebp
        mov     bp, word ptr [eax + edx + 0xe]
        lea     ebx, [eax + edx + 0xc]
        push    esi
        push    edi
        test    ebp, ebp
        mov     [esp + 0x10], ecx
        jz      L_vqb_freeRet
        mov     esi, dword ptr [g_fightGroupHead]
        mov     edx, dword ptr [g_dispatchSave1572]
        mov     eax, dword ptr [g_currentNodeIdx]
        mov     edi, ebp
        sar     esi, 0x10
        and     esi, 8
        lea     eax, [eax*4 + 0x48]
        shl     edi, 3
        or      esi, edx
        mov     edx, [esp + 0x1c]
        sub     edi, ebp
        mov     [esp + 0x18], eax
        shl     edi, 2
        test    edx, edx
        jz      short L_vqb_directAlloc
        mov     eax, [eax]
        mov     edx, [eax]
        and     edx, 9
        cmp     edx, esi
        jne     short L_vqb_allocFallback
        cmp     edi, [eax + 4]
        jle     short L_vqb_useExisting
    L_vqb_allocFallback:
        push    2
        call    LeaScaledCall
        mov     eax, [esp + 0x1c]
        add     esp, 4
    L_vqb_directAlloc:
        lea     ecx, [edi + 0xc]
        push    2
        push    ecx
        push    eax
        call    Mem_Malloc
        add     esp, 0xc
        test    eax, eax
        jne     short L_vqb_store
    L_vqb_freeRet:
        mov     edx, dword ptr [g_currentNodeIdx]
        xor     eax, eax
        mov     dword ptr [g_pendingNodeType], eax
        mov     [edx*4 + 0x48], eax
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        pop     ecx
        ret
    L_vqb_store:
        mov     ecx, [esp + 0x10]
        mov     [eax + 4], edi
    L_vqb_useExisting:
        mov     edx, ebx
        mov     dword ptr [g_pendingNodeType], eax
        shl     edx, 5
        or      edx, esi
        mov     [eax], edx
        lea     edx, [eax + 8]
        mov     eax, [ebx + 0xc]
        test    ebp, ebp
        lea     esi, [eax + ebx + 0xc]
        mov     eax, [ecx + 4]
        mov     ecx, [eax + 4]
        lea     ebx, [ecx + eax + 8]
        jle     short L_vqb_done
    L_vqb_loop:
        mov     ecx, 7
        xor     eax, eax
        mov     edi, edx
        add     edx, 0x1c
        rep     stosd
        mov     ax, word ptr [esi + 2]
        add     esi, 8
        mov     word ptr [edx - 0x10], ax
        mov     cx, word ptr [esi - 4]
        mov     word ptr [edx - 0x0e], cx
        mov     ax, word ptr [esi - 2]
        mov     word ptr [edx - 0x0c], ax
        movsx   ecx, byte ptr [esi - 8]
        mov     al, byte ptr [ebx + ecx*4 + 2]
        xor     cx, cx
        and     al, 0x0f
        mov     cl, al
        mov     ax, word ptr [edx - 2]
        and     eax, 0xfff0
        or      ecx, eax
        dec     ebp
        mov     word ptr [edx - 2], cx
        jne     short L_vqb_loop
    L_vqb_done:
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        pop     ecx
        ret
    }
}
#endif
