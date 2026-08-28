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

/*
 * @addr 0x004bd8e0 (127b engine.geo) - geometry-unload fixup loop, the
 * teardown counterpart of LoadGeoAsset_Textures: it frees the texture
 * slots a .geo asset claimed (g_texSlots[0x00ab4e00], g_texAssetIds,
 * g_texCount) before Mem_Free'ing the buffer.
 *
 *   mov ecx,[eax+4]; lea ecx,[ecx+eax+4]
 * is the same relative-offset-from-the-field-at-+4 fixup that geo_block
 * (include/engine/geo.h) and the texture-chunk reach in
 * LoadGeoAsset_Textures use - here it lands on the strip/texture index
 * word table. `mov dx,[eax+6]` then reads the node[0] header's u16 at
 * +6 (the same g_texCount index used by the loader).
 */
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern u16 g_texSlots[];
extern u32 g_curTexSlot;
extern unsigned int g_texAssetIds;
extern u32 g_texCount[];
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
#define g_curTexSlot (*(unsigned int *)MK4_VA(unsigned int, 0xab4e74u))
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
#define g_rangeBase (*(unsigned int *)MK4_VA(unsigned int, 0x53a46cu))
#define g_rangeSqLimit (*(unsigned int *)MK4_VA(unsigned int, 0x53a180u))
#define g_stateCountdown (*(unsigned int *)MK4_VA(unsigned int, 0x53a3c0u))
#define g_texAssetIds (*(unsigned int *)MK4_VA(unsigned int, 0xab4e78u))
#define g_texCount ((unsigned int *)MK4_VA(unsigned int, 0xab5038u))
#define g_texSlots ((unsigned short *)MK4_VA(unsigned short, 0xab4e00u))
#define g_xformScratch94 (*(unsigned int *)MK4_VA(unsigned int, 0x542094u))
#endif

extern void Helper_GeoLoadPost(void);
extern void Mem_Free(unsigned int);

#ifdef NON_MATCHING
/* NATIVE twin, transcribed from the original bytes (the Ghidra lift here
 * before it wrote dwords into the 16-bit slot table and mangled the
 * texCount pointer math).
 *
 * Unloads one geo record: walks the record's texture-id list (count word
 * at rec + [rec+4] + 4, ids every 4 bytes, -1 holes) clearing each 16-bit
 * slot entry, clears the group's node and count slots by the blob's id
 * word (+6), frees the record, and runs the post-load pass. */
void GeoLoadFixupLoop(void)
{
    unsigned int node, rec, blob, p, n;
    short id;
    unsigned short grp;

    node = g_currentNodeIdx;
    rec = MK4_NODE_AT(unsigned int, node, 4);
    if (rec == 0) return;

    p = *MK4_VA(unsigned int, rec + 4u) + rec + 4u;
    n = *MK4_VA(unsigned short, p);
    p += 4;
    for (; (int)n > 0; n--) {
        id = *MK4_VA(short, p);
        if (id != -1)
            *MK4_VA(unsigned short, 0xab4e00u + (unsigned int)id * 2u) = 0;
        p += 4;
    }

    blob = *MK4_NODE(unsigned int, node);
    grp = *MK4_VA(unsigned short, blob + 6u);
    *MK4_VA(unsigned int, 0xab4e78u + grp * 4u) = 0;
    grp = *MK4_VA(unsigned short, blob + 6u);
    *MK4_VA(unsigned int, 0xab5038u + grp * 4u) = 0;
    Mem_Free(MK4_NODE_AT(unsigned int, node, 4));
    g_curTexSlot = 0;
    Helper_GeoLoadPost();
}
#else
__declspec(naked) void GeoLoadFixupLoop(void) {
    __asm {
        push    esi
        push    edi
        mov     edi, dword ptr [g_currentNodeIdx]
        xor     esi, esi
        mov     eax, dword ptr [edi*4 + 4]
        cmp     eax, esi
        je      done
        mov     ecx, dword ptr [eax + 4]
        lea     ecx, [ecx + eax + 4]
        xor     eax, eax
        mov     ax, word ptr [ecx]
        add     ecx, 4
        cmp     eax, esi
        jle     skipInner
        mov     edx, eax
innerLoop:
        movsx   eax, word ptr [ecx]
        cmp     eax, -1
        je      skipStore
        mov     word ptr [eax*2 + g_texSlots], si
skipStore:
        add     ecx, 4
        dec     edx
        jne     innerLoop
skipInner:
        mov     eax, dword ptr [edi*4 + 0]
        xor     edx, edx
        xor     ecx, ecx
        mov     dx, word ptr [eax + 6]
        mov     dword ptr [edx*4 + g_texAssetIds], esi
        mov     cx, word ptr [eax + 6]
        mov     dword ptr [ecx*4 + g_texCount], esi
        mov     edx, dword ptr [edi*4 + 4]
        push    edx
        call    Mem_Free
        add     esp, 4
        mov     dword ptr [g_curTexSlot], esi
        call    Helper_GeoLoadPost
done:
        pop     edi
        pop     esi
        ret
    }
}
#endif
