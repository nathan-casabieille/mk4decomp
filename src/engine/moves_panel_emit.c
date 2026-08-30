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

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_installCountdownEnd;
extern unsigned int g_dispatchCmpEnd2;
extern unsigned int g_movesPanelEnd;
extern unsigned int g_dispatchCmpEnd;
extern u32 g_inLoopStep;
extern unsigned int g_dispatchSave1626[];
extern s16 g_vtxIn2_x;
extern unsigned int g_triStripX0;
extern s16 g_vtxIn1_y;
extern s16 g_vtxIn1_z;
extern unsigned int g_triStripX1;
extern s16 g_vtxIn2_y;
extern s16 g_vtxIn2_z;
extern unsigned int g_triStripX2;
extern unsigned int g_triStripRingB;
extern s32 g_vtxOut2_z;
extern s32 g_vtxOut_z;
extern s32 g_vtxValid;
extern unsigned int g_triStripRingA;
extern s16 g_vtxScreenP1Y;
extern s16 g_vtxScreenP2X;
extern s16 g_vtxScreenP2Y;
extern s16 g_vtxScreenX;
extern s16 g_vtxScreenY;
extern unsigned int g_dispatchSave1534;
extern unsigned int g_dispatchSave1536;
extern unsigned int g_dispatchSave1538;
extern unsigned int g_dispatchSave1540;
extern unsigned int g_dispatchSave1541;
extern unsigned int g_dispatchSave1542;
extern unsigned int g_dispatchSave1543;
extern unsigned int g_dispatchSave1544;
extern unsigned int g_dispatchSave1545;
extern unsigned int g_dispatchSave1546;
extern unsigned int g_dispatchSave1547;
extern unsigned int g_dispatchSave1548;
#endif
#ifndef NON_MATCHING   /* the twin declares these with their real signatures */
extern void GamepadSeqRecord(void);
extern void Helper_DrawCursor(void);
extern void ProjectTwoVertices(void);
extern void SunbeamSpriteEmit(void);
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
#define g_dispatchCmpEnd (*(unsigned int *)MK4_VA(unsigned int, 0x4ed060u))
#define g_dispatchCmpEnd2 (*(unsigned int *)MK4_VA(unsigned int, 0x4ed020u))
#define g_dispatchSave1534 (*(unsigned int *)MK4_VA(unsigned int, 0xab48b8u))
#define g_dispatchSave1536 (*(unsigned int *)MK4_VA(unsigned int, 0xab48bcu))
#define g_dispatchSave1538 (*(unsigned int *)MK4_VA(unsigned int, 0xab48c0u))
#define g_dispatchSave1540 (*(unsigned int *)MK4_VA(unsigned int, 0xab48c4u))
#define g_dispatchSave1541 (*(unsigned int *)MK4_VA(unsigned int, 0xab48c5u))
#define g_dispatchSave1542 (*(unsigned int *)MK4_VA(unsigned int, 0xab48c6u))
#define g_dispatchSave1543 (*(unsigned int *)MK4_VA(unsigned int, 0xab48c7u))
#define g_dispatchSave1544 (*(unsigned int *)MK4_VA(unsigned int, 0xab48c8u))
#define g_dispatchSave1545 (*(unsigned int *)MK4_VA(unsigned int, 0xab48c9u))
#define g_dispatchSave1546 (*(unsigned int *)MK4_VA(unsigned int, 0xab48cau))
#define g_dispatchSave1547 (*(unsigned int *)MK4_VA(unsigned int, 0xab48ccu))
#define g_dispatchSave1548 (*(unsigned int *)MK4_VA(unsigned int, 0xab48d2u))
#define g_dispatchSave1626 ((unsigned int *)MK4_VA(unsigned int, 0x7af958u))
#define g_dualBitGate (*(unsigned int *)MK4_VA(unsigned int, 0x53a7b0u))
#define g_eventArmReload (*(unsigned int *)MK4_VA(unsigned int, 0x53a770u))
#define g_eventQueueTotal (*(unsigned int *)MK4_VA(unsigned int, 0x542050u))
#define g_fightAxisNegX (*(unsigned int *)MK4_VA(unsigned int, 0x535e70u))
#define g_fightAxisNegY (*(unsigned int *)MK4_VA(unsigned int, 0x535e74u))
#define g_fightAxisPosX (*(unsigned int *)MK4_VA(unsigned int, 0x535e78u))
#define g_fightAxisPosY (*(unsigned int *)MK4_VA(unsigned int, 0x535e7cu))
#define g_fightStateProgress (*(unsigned int *)MK4_VA(unsigned int, 0x535ddcu))
#define g_gameCountdown (*(unsigned int *)MK4_VA(unsigned int, 0x53a718u))
#define g_inLoopStep (*(unsigned int *)MK4_VA(unsigned int, 0x7af92cu))
#define g_installCountdownEnd (*(unsigned int *)MK4_VA(unsigned int, 0x4ed000u))
#define g_installOwnerNode (*(unsigned int *)MK4_VA(unsigned int, 0x535cf8u))
#define g_lastGatedTick (*(unsigned int *)MK4_VA(unsigned int, 0x54358cu))
#define g_lastGatedValue (*(unsigned int *)MK4_VA(unsigned int, 0x543598u))
#define g_movesPanelEnd (*(unsigned int *)MK4_VA(unsigned int, 0x4ed040u))
#define g_rangeBase (*(unsigned int *)MK4_VA(unsigned int, 0x53a46cu))
#define g_rangeSqLimit (*(unsigned int *)MK4_VA(unsigned int, 0x53a180u))
#define g_stateCountdown (*(unsigned int *)MK4_VA(unsigned int, 0x53a3c0u))
#define g_tickCurMask (*(unsigned int *)MK4_VA(unsigned int, 0xab4e20u))
#define g_tickW1 (*(unsigned int *)MK4_VA(unsigned int, 0x543550u))
#define g_triStripRingA (*(unsigned int *)MK4_VA(unsigned int, 0x7af9b4u))
#define g_triStripRingB (*(unsigned int *)MK4_VA(unsigned int, 0x7af984u))
#define g_triStripX0 (*(short *)MK4_VA(short, 0x7af95cu))
#define g_triStripX1 (*(short *)MK4_VA(short, 0x7af962u))
#define g_triStripX2 (*(short *)MK4_VA(short, 0x7af968u))
#define g_vtxIn1_y (*(short *)MK4_VA(short, 0x7af95eu))
#define g_vtxIn1_z (*(short *)MK4_VA(short, 0x7af960u))
#define g_vtxIn2_x (*(short *)MK4_VA(short, 0x7af95au))
#define g_vtxIn2_y (*(short *)MK4_VA(short, 0x7af964u))
#define g_vtxIn2_z (*(short *)MK4_VA(short, 0x7af966u))
#define g_vtxOut2_z (*(int *)MK4_VA(int, 0x7af988u))
#define g_vtxOut_z (*(int *)MK4_VA(int, 0x7af98cu))
#define g_vtxScreenP1Y (*(short *)MK4_VA(short, 0x7af9b6u))
#define g_vtxScreenP2X (*(unsigned int *)MK4_VA(unsigned int, 0x7af9b8u))
#define g_vtxScreenP2Y (*(short *)MK4_VA(short, 0x7af9bau))
#define g_vtxScreenX (*(unsigned int *)MK4_VA(unsigned int, 0x7af9bcu))
#define g_vtxScreenY (*(short *)MK4_VA(short, 0x7af9beu))
#define g_vtxValid (*(int *)MK4_VA(int, 0x7af9b0u))
#define g_xformEntityIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542048u))
#define g_xformScratch94 (*(unsigned int *)MK4_VA(unsigned int, 0x542094u))
#endif


#ifdef NON_MATCHING
#include "portable/mem_model.h"

extern void SunbeamSpriteEmit(void);
extern void ProjectTwoVertices(void);
extern void GamepadSeqRecord(unsigned int va, int which);
extern void Helper_DrawCursor(void *entry);

/* Portable twin, written from the disassembly. The record this fills is a
 * PACKED draw-queue entry: three screen dwords at 0x00ab48b8, six colour BYTES
 * at +0xc, and three words behind those - the lift assigned every field as an
 * int, which is the same four-bytes-into-a-byte-field class the width audit
 * exists for. Every store here is spelled at the original's width.
 *
 * The edge sequence appears TWICE, expanded inline: the co-exec extractor
 * compiles the function body alone, so neither a static helper nor a macro
 * defined beside it survives extraction.
 *
 * The staging slots at 0x007af958 are nine s16: each source field is a packed
 * pair split as (v << 16 >> 19, v >> 19) - a 13-bit signed extract of each
 * half, not a shift of the whole.
 *
 * The four sentinel compares are against VAs: the original compares
 * `node * 4` to 0x4ed060/40/20/00 directly, so the twin keeps the VA form
 * rather than materialising pointers. GamepadSeqRecord's first argument is a
 * VA for the same reason - 750 bytes of it compare that argument to the same
 * table. */
void MovesPanelEmit(void)
{
    unsigned int node, va, u, w1, f;
    unsigned char col;
    int p1x, p1y, p2x, p2y, x, y, valid;

    node = MK4_NODE_AT(unsigned int, g_eventQueueTotal, 0x18);
    g_xformEntityIdx = node;
    if ((int)node < 8) {
        SunbeamSpriteEmit();
        return;
    }
    if (g_inLoopStep != 0)
        return;

    /* TWO different indices, easy to conflate: the sentinel compare is on the
     * PANEL's own VA (g_eventQueueTotal * 4), while the vertex fields and the
     * 0xa000 colour test read the NODE the panel's +0x18 names. My first
     * transcription tested node * 4 and the seeded run caught it. */
    va = g_eventQueueTotal * 4u;
    if (va != 0x4ed060u && va != 0x4ed040u && va != 0x4ed020u && va != 0x4ed000u)
        return;

    w1 = g_tickW1;
    if ((int)w1 < 0x10)
        u = 0;
    else
        u = (unsigned int)(((int)(w1 + ((w1 >> 31) & 7u)) >> 3) - 1);

    col = (unsigned char)(((*MK4_NODE(unsigned int, node) == 0xa000u
                            ? 0xffffffffu : 0u) & 0xf4u) + 0x16u);

    *MK4_VA(unsigned short, 0xab48cau) = (unsigned short)g_tickCurMask;
    *MK4_VA(unsigned short, 0xab48d2u) = 0xf;
    *MK4_VA(unsigned char, 0xab48c6u) = col;
    *MK4_VA(unsigned char, 0xab48c8u) = col;
    *MK4_VA(unsigned char, 0xab48c4u) = col;
    *MK4_VA(unsigned char, 0xab48c7u) = 0x64;
    *MK4_VA(unsigned char, 0xab48c9u) = 0x64;
    *MK4_VA(unsigned char, 0xab48c5u) = 0x64;
    *MK4_VA(unsigned short, 0xab48ccu) =
        (unsigned short)((((u << 5) | u) << 5) | u);

    f = MK4_NODE_AT(unsigned int, node, 4);
    *MK4_VA(short, 0x7af964u) = 0;
    *MK4_VA(short, 0x7af958u) = (short)((int)(f << 16) >> 19);
    *MK4_VA(short, 0x7af95eu) = (short)((int)f >> 19);

    f = MK4_NODE_AT(unsigned int, node, 0xc);
    *MK4_VA(short, 0x7af966u) = 0;
    *MK4_VA(short, 0x7af95au) = (short)((int)(f << 16) >> 19);
    *MK4_VA(short, 0x7af960u) = (short)((int)f >> 19);

    f = MK4_NODE_AT(unsigned int, node, 0x14);
    *MK4_VA(short, 0x7af968u) = 0;
    *MK4_VA(short, 0x7af95cu) = (short)((int)(f << 16) >> 19);
    *MK4_VA(short, 0x7af962u) = (short)((int)f >> 19);

    /* --- edge 0: project, winding, stash, submit -------------------- */
    ProjectTwoVertices();

    p1x = (int)*MK4_VA(short, 0x7af9b4u);
    p1y = (int)*MK4_VA(short, 0x7af9b6u);
    p2x = (int)*MK4_VA(short, 0x7af9b8u);
    p2y = (int)*MK4_VA(short, 0x7af9bau);
    x   = (int)*MK4_VA(short, 0x7af9bcu);
    y   = (int)*MK4_VA(short, 0x7af9beu);
    valid = ((y - p1y) * (p2x - p1x) - (p2y - p1y) * (x - p1x)) <= 0;

    *MK4_VA(unsigned int, 0xab48b8u) = *MK4_VA(unsigned int, 0x7af9b4u);
    *MK4_VA(unsigned int, 0xab48bcu) = *MK4_VA(unsigned int, 0x7af9b8u);
    *MK4_VA(unsigned int, 0xab48c0u) = *MK4_VA(unsigned int, 0x7af9bcu);
    *MK4_VA(unsigned int, 0x7af9b0u) = (unsigned int)valid;     /* g_vtxValid */
    *MK4_VA(unsigned short, 0xab48d2u) =
        (unsigned short)((*MK4_VA(unsigned short, 0xab48d2u) & 0xfbffu)
                         | ((unsigned)valid << 10));

    GamepadSeqRecord(g_eventQueueTotal * 4u, 0);

    if ((int)*MK4_VA(int, 0x7af984u) > 0 && (int)*MK4_VA(int, 0x7af988u) > 0
        && (int)*MK4_VA(int, 0x7af98cu) > 0)
        Helper_DrawCursor(MK4_VA(void, 0xab48b8u));

    /* the second edge replaces only the middle vertex */
    f = MK4_NODE_AT(unsigned int, node, 0x1c);
    *MK4_VA(short, 0x7af966u) = 0;
    *MK4_VA(short, 0x7af95au) = (short)((int)(f << 16) >> 19);
    *MK4_VA(short, 0x7af960u) = (short)((int)f >> 19);

    /* --- edge 1: project, winding, stash, submit -------------------- */
    ProjectTwoVertices();

    p1x = (int)*MK4_VA(short, 0x7af9b4u);
    p1y = (int)*MK4_VA(short, 0x7af9b6u);
    p2x = (int)*MK4_VA(short, 0x7af9b8u);
    p2y = (int)*MK4_VA(short, 0x7af9bau);
    x   = (int)*MK4_VA(short, 0x7af9bcu);
    y   = (int)*MK4_VA(short, 0x7af9beu);
    valid = ((y - p1y) * (p2x - p1x) - (p2y - p1y) * (x - p1x)) <= 0;

    *MK4_VA(unsigned int, 0xab48b8u) = *MK4_VA(unsigned int, 0x7af9b4u);
    *MK4_VA(unsigned int, 0xab48bcu) = *MK4_VA(unsigned int, 0x7af9b8u);
    *MK4_VA(unsigned int, 0xab48c0u) = *MK4_VA(unsigned int, 0x7af9bcu);
    *MK4_VA(unsigned int, 0x7af9b0u) = (unsigned int)valid;     /* g_vtxValid */
    *MK4_VA(unsigned short, 0xab48d2u) =
        (unsigned short)((*MK4_VA(unsigned short, 0xab48d2u) & 0xfbffu)
                         | ((unsigned)valid << 10));

    GamepadSeqRecord(g_eventQueueTotal * 4u, 1);

    if ((int)*MK4_VA(int, 0x7af984u) > 0 && (int)*MK4_VA(int, 0x7af988u) > 0
        && (int)*MK4_VA(int, 0x7af98cu) > 0)
        Helper_DrawCursor(MK4_VA(void, 0xab48b8u));
}
#else
__declspec(naked) void MovesPanelEmit(void)
{
    __asm {
        mov      eax, dword ptr [g_eventQueueTotal]
        push     ebx
        push     esi
        push     edi
        mov      ecx, dword ptr [eax*4 + 0x18]
        cmp      ecx, 8
        mov      dword ptr [g_xformEntityIdx], ecx
        jge      L_cf83
        call     SunbeamSpriteEmit
        pop      edi
        pop      esi
        pop      ebx
        ret
    L_cf83:
        mov      edx, dword ptr [g_inLoopStep]
        xor      edi, edi
        cmp      edx, edi
        jne      L_d260
        shl      eax, 2
        cmp      eax, OFFSET g_dispatchCmpEnd
        je       L_cfb6
        cmp      eax, OFFSET g_movesPanelEnd
        je       L_cfb6
        cmp      eax, OFFSET g_dispatchCmpEnd2
        je       L_cfb6
        cmp      eax, OFFSET g_installCountdownEnd
        jne      L_d260
    L_cfb6:
        mov      eax, dword ptr [g_tickW1]
        cmp      eax, 0x10
        jl       L_cfcc
        cdq
        and      edx, 7
        add      eax, edx
        sar      eax, 3
        dec      eax
        jmp      L_cfce
    L_cfcc:
        xor      eax, eax
    L_cfce:
        mov      edx, dword ptr [ecx*4]
        lea      esi, [ecx*4]
        xor      ecx, ecx
        cmp      edx, 0xa000
        sete     cl
        neg      cl
        sbb      ecx, ecx
        mov      dx, word ptr [g_tickCurMask]
        and      ecx, 0xfffffff4
        mov      word ptr [g_dispatchSave1546], dx
        add      ecx, 0x16
        mov      word ptr [g_dispatchSave1548], 0xf
        mov      byte ptr [g_dispatchSave1542], cl
        mov      byte ptr [g_dispatchSave1544], cl
        mov      byte ptr [g_dispatchSave1540], cl
        mov      cl, 0x64
        mov      byte ptr [g_dispatchSave1543], cl
        mov      byte ptr [g_dispatchSave1545], cl
        mov      byte ptr [g_dispatchSave1541], cl
        mov      ecx, eax
        shl      ecx, 5
        or       ecx, eax
        shl      ecx, 5
        or       ecx, eax
        mov      word ptr [g_dispatchSave1547], cx
        mov      eax, dword ptr [esi + 4]
        mov      ecx, eax
        mov      word ptr [g_vtxIn2_y], di
        shl      ecx, 0x10
        sar      ecx, 0x13
        sar      eax, 0x13
        mov      word ptr [g_dispatchSave1626], cx
        mov      word ptr [g_vtxIn1_y], ax
        mov      eax, dword ptr [esi + 0xc]
        mov      word ptr [g_vtxIn2_z], di
        mov      ecx, eax
        shl      ecx, 0x10
        sar      ecx, 0x13
        sar      eax, 0x13
        mov      word ptr [g_vtxIn2_x], cx
        mov      word ptr [g_vtxIn1_z], ax
        mov      eax, dword ptr [esi + 0x14]
        mov      word ptr [g_triStripX2], di
        mov      ecx, eax
        shl      ecx, 0x10
        sar      ecx, 0x13
        sar      eax, 0x13
        mov      word ptr [g_triStripX0], cx
        mov      word ptr [g_triStripX1], ax
        call     ProjectTwoVertices
        movsx    eax, word ptr [g_triStripRingA]
        movsx    ecx, word ptr [g_vtxScreenP1Y]
        movsx    edx, word ptr [g_vtxScreenY]
        movsx    ebx, word ptr [g_vtxScreenP2X]
        sub      edx, ecx
        sub      ebx, eax
        imul     edx, ebx
        movsx    ebx, word ptr [g_vtxScreenP2Y]
        sub      ebx, ecx
        push     edi
        movsx    ecx, word ptr [g_vtxScreenX]
        sub      ecx, eax
        xor      eax, eax
        imul     ebx, ecx
        mov      ecx, dword ptr [g_triStripRingA]
        sub      edx, ebx
        test     edx, edx
        mov      edx, dword ptr [g_vtxScreenP2X]
        mov      dword ptr [g_dispatchSave1534], ecx
        mov      cx, word ptr [g_dispatchSave1548]
        mov      dword ptr [g_dispatchSave1536], edx
        setle    al
        mov      dword ptr [g_vtxValid], eax
        mov      dl, byte ptr [g_vtxValid]
        mov      eax, dword ptr [g_vtxScreenX]
        and      edx, 1
        and      ecx, 0xfbff
        mov      dword ptr [g_dispatchSave1538], eax
        shl      edx, 0xa
        or       ecx, edx
        mov      word ptr [g_dispatchSave1548], cx
        mov      eax, dword ptr [g_eventQueueTotal]
        lea      ecx, [eax*4]
        push     ecx
        call     GamepadSeqRecord
        mov      eax, dword ptr [g_triStripRingB]
        add      esp, 8
        cmp      eax, edi
        jle      L_d172
        cmp      dword ptr [g_vtxOut2_z], edi
        jle      L_d172
        cmp      dword ptr [g_vtxOut_z], edi
        jle      L_d172
        push     OFFSET g_dispatchSave1534
        call     Helper_DrawCursor
        add      esp, 4
    L_d172:
        mov      esi, dword ptr [esi + 0x1c]
        mov      word ptr [g_vtxIn2_z], di
        mov      eax, esi
        shl      eax, 0x10
        sar      eax, 0x13
        sar      esi, 0x13
        mov      word ptr [g_vtxIn2_x], ax
        mov      word ptr [g_vtxIn1_z], si
        call     ProjectTwoVertices
        movsx    eax, word ptr [g_triStripRingA]
        movsx    ecx, word ptr [g_vtxScreenP1Y]
        movsx    edx, word ptr [g_vtxScreenY]
        movsx    esi, word ptr [g_vtxScreenP2X]
        sub      edx, ecx
        sub      esi, eax
        imul     edx, esi
        movsx    esi, word ptr [g_vtxScreenP2Y]
        sub      esi, ecx
        push     1
        movsx    ecx, word ptr [g_vtxScreenX]
        sub      ecx, eax
        xor      eax, eax
        imul     esi, ecx
        mov      ecx, dword ptr [g_triStripRingA]
        sub      edx, esi
        test     edx, edx
        mov      edx, dword ptr [g_vtxScreenP2X]
        mov      dword ptr [g_dispatchSave1534], ecx
        mov      cx, word ptr [g_dispatchSave1548]
        mov      dword ptr [g_dispatchSave1536], edx
        setle    al
        mov      dword ptr [g_vtxValid], eax
        mov      dl, byte ptr [g_vtxValid]
        mov      eax, dword ptr [g_vtxScreenX]
        and      edx, 1
        and      ecx, 0xfbff
        mov      dword ptr [g_dispatchSave1538], eax
        mov      eax, dword ptr [g_eventQueueTotal]
        shl      edx, 0xa
        or       ecx, edx
        mov      word ptr [g_dispatchSave1548], cx
        lea      ecx, [eax*4]
        push     ecx
        call     GamepadSeqRecord
        mov      eax, dword ptr [g_triStripRingB]
        add      esp, 8
        cmp      eax, edi
        jle      L_d260
        cmp      dword ptr [g_vtxOut2_z], edi
        jle      L_d260
        cmp      dword ptr [g_vtxOut_z], edi
        jle      L_d260
        push     OFFSET g_dispatchSave1534
        call     Helper_DrawCursor
        add      esp, 4
    L_d260:
        pop      edi
        pop      esi
        pop      ebx
        ret
    }
}
#endif
