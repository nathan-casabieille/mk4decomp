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
extern unsigned int g_dispatchSave531;
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
extern s32 g_vtxTransX;
extern s32 g_vtxTransY;
extern s32 g_vtxTransZ;
extern s32 g_vtxValid;
extern unsigned int g_triStripRingA;
extern s16 g_vtxScreenP1Y;
extern s16 g_vtxScreenP2X;
extern s16 g_vtxScreenP2Y;
extern s16 g_vtxScreenX;
extern s16 g_vtxScreenY;
extern unsigned int g_dispatchSave1501;
extern unsigned int g_dispatchSave1502;
extern unsigned int g_dispatchSave1503;
extern unsigned int g_dispatchSave1559;
extern unsigned int g_dispatchSave1576;
#endif
#ifndef NON_MATCHING
extern void CopyArgs16ToGlobals(void);
#endif
#ifndef NON_MATCHING
extern void Helper_DrawCursor(void);
#endif
#ifndef NON_MATCHING
extern void MaxOfThree(void);
#endif
#ifndef NON_MATCHING
extern void ProjectTwoVertices(void);
#endif
#ifndef NON_MATCHING
extern void ProjectVertex(void);
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
#define g_currentNodeFlags (*(unsigned int *)MK4_VA(unsigned int, 0x542084u))
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_dispatchSave1501 (*(unsigned int *)MK4_VA(unsigned int, 0xab4398u))
#define g_dispatchSave1502 (*(unsigned int *)MK4_VA(unsigned int, 0xab439cu))
#define g_dispatchSave1503 (*(unsigned int *)MK4_VA(unsigned int, 0xab43a0u))
#define g_dispatchSave1559 (*(unsigned int *)MK4_VA(unsigned int, 0xab4d9cu))
#define g_dispatchSave1576 (*(unsigned int *)MK4_VA(unsigned int, 0xab4e60u))
#define g_dispatchSave1626 ((unsigned int *)MK4_VA(unsigned int, 0x7af958u))
#define g_dispatchSave531 (*(unsigned int *)MK4_VA(unsigned int, 0x4f6238u))
#define g_dualBitGate (*(unsigned int *)MK4_VA(unsigned int, 0x53a7b0u))
#define g_eventArmReload (*(unsigned int *)MK4_VA(unsigned int, 0x53a770u))
#define g_fightAxisNegX (*(unsigned int *)MK4_VA(unsigned int, 0x535e70u))
#define g_fightAxisNegY (*(unsigned int *)MK4_VA(unsigned int, 0x535e74u))
#define g_fightAxisPosX (*(unsigned int *)MK4_VA(unsigned int, 0x535e78u))
#define g_fightAxisPosY (*(unsigned int *)MK4_VA(unsigned int, 0x535e7cu))
#define g_fightGroupHead (*(unsigned int *)MK4_VA(unsigned int, 0x54205cu))
#define g_fightStateProgress (*(unsigned int *)MK4_VA(unsigned int, 0x535ddcu))
#define g_gameCountdown (*(unsigned int *)MK4_VA(unsigned int, 0x53a718u))
#define g_inLoopStep (*(unsigned int *)MK4_VA(unsigned int, 0x7af92cu))
#define g_installOwnerNode (*(unsigned int *)MK4_VA(unsigned int, 0x535cf8u))
#define g_lastGatedTick (*(unsigned int *)MK4_VA(unsigned int, 0x54358cu))
#define g_lastGatedValue (*(unsigned int *)MK4_VA(unsigned int, 0x543598u))
#define g_rangeBase (*(unsigned int *)MK4_VA(unsigned int, 0x53a46cu))
#define g_rangeSqLimit (*(unsigned int *)MK4_VA(unsigned int, 0x53a180u))
#define g_stateCountdown (*(unsigned int *)MK4_VA(unsigned int, 0x53a3c0u))
#define g_tickCurMask (*(unsigned int **)MK4_VA(unsigned int, 0xab4e20u))
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
#define g_vtxTransX (*(int *)MK4_VA(int, 0x7af9a4u))
#define g_vtxTransY (*(int *)MK4_VA(int, 0x7af9a8u))
#define g_vtxTransZ (*(int *)MK4_VA(int, 0x7af9acu))
#define g_vtxValid (*(int *)MK4_VA(int, 0x7af9b0u))
#define g_xformEntityIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542048u))
#define g_xformScratch94 (*(unsigned int *)MK4_VA(unsigned int, 0x542094u))
#endif


#ifdef NON_MATCHING
#include "portable/mem_model.h"

extern void ProjectTwoVertices(void);
extern void ProjectVertex(void);
extern int  MaxOfThree(void);
extern void CopyArgs16ToGlobals(unsigned short a, unsigned short b,
                                unsigned short c);
extern void Helper_DrawCursor(void *entry);

/* Portable twin of the last emitter, written from the disassembly. A sheet is
 * a rectangle emitted as TWO tris sharing an edge: the first from
 * ProjectTwoVertices over the corner pair, the second by shifting the third
 * vertex into slot two (CopyArgs16ToGlobals) and projecting the far corner.
 * Emitted once for the node itself, then once per node of the +0x2c chain,
 * each chain node's offset (its +4/+8/+0xc over 128) rotated through the s16
 * 3x3 at mat*4 (Q12) unless flag 0x4000 says raw, and applied to the SAVED
 * translate - per node, not cumulative.
 *
 * The two stack records' colour bytes differ on purpose: rec1 carries
 * (a,c,d,c,d,b), rec2 (a,c,d,b,a,b) - transcribed from the byte stores, not
 * assumed symmetric. Their flag words start from the same two-bit table value
 * but fold in DIFFERENT texture nibbles, and the first pair of tris collapses
 * to a single vertex-1-skipped submit when both share all three screen
 * points, which is what the 0x20 or/clear around the first Helper_DrawCursor
 * is.
 *
 * Under flag 0x40 the node's own sheet is not emitted at all - only the
 * chain's; flag 0x4000 keeps the chain offsets raw. Every record store is at the original's width by explicit VA.
 *
 * The sheet argument is a HOST POINTER (RenderSceneNode passes rec + 0x10);
 * mat is a PACKED INDEX whose nine s16 sit at mat*4. */
void BillboardSheetDualEmit(unsigned char *sheet_ptr, unsigned int mat)
{
    unsigned int sheet = MK4_UNPTR(sheet_ptr);
    unsigned int meshbase, textbl, u, f, t, ent;
    unsigned int rec1[7], rec2[7];
    unsigned short f1, f2, key;
    unsigned char ca, cc, cd, cb;
    int x0, y0, p1x, p1y, p2x, p2y, sx, sy, valid;
    int tx, ty, tz, cur;

    if (g_inLoopStep != 0)
        return;

    u = g_dispatchSave1576;
    if ((int)u < 0x10)
        u = 0;
    else
        u = (unsigned int)(((int)(u + ((u >> 31) & 7u)) >> 3) - 1);
    u = (((u << 5) | u) << 5) | u;

    if (g_fightGroupHead & 0x60u) {
        g_vtxTransX = (int)g_dispatchSave1501 >> 16;
        g_vtxTransY = (int)g_dispatchSave1502 >> 16;
        g_vtxTransZ = (int)g_dispatchSave1503 >> 7;
    } else {
        g_vtxTransX = (int)g_dispatchSave1501 >> 7;
        g_vtxTransY = (int)g_dispatchSave1502 >> 7;
        g_vtxTransZ = (int)g_dispatchSave1503 >> 7;
    }

    ent = g_xformEntityIdx;                        /* a VA */
    meshbase = *(unsigned int *)MK4_PTR(ent + 4);
    textbl = meshbase + *(unsigned int *)MK4_PTR(meshbase + 4) + 8;

    ((unsigned short *)rec1)[0xa] = (unsigned short)u;   /* +0x14 colour */
    ((unsigned short *)rec2)[0xa] = (unsigned short)u;

    f = (unsigned int)(unsigned short)((short)(signed char)
            (*MK4_VA(unsigned char, 0x4f6238u
                     + (*(unsigned char *)MK4_PTR(sheet + 1) & 3u)) & 3u) << 7);
    f1 = (unsigned short)(f & 0x180u);
    t = *(unsigned char *)MK4_PTR(textbl
            + (unsigned int)*(unsigned char *)MK4_PTR(sheet + 2) * 4u + 2);
    f2 = (unsigned short)(f ^ ((t ^ (f & 0xffu)) & 0xfu));
    f1 = (unsigned short)(f1 ^ (((f2 & 0xffu) ^ (f1 & 0xffu)) & 0xfu));

    ca = *(unsigned char *)MK4_PTR(sheet + 0xc);
    cc = *(unsigned char *)MK4_PTR(sheet + 0xd);
    cd = (unsigned char)(*(unsigned char *)MK4_PTR(sheet + 0xe) + ca);
    cb = (unsigned char)(*(unsigned char *)MK4_PTR(sheet + 0xf) + cc);
    ((unsigned char *)rec1)[0xc] = ca; ((unsigned char *)rec1)[0xd] = cc;
    ((unsigned char *)rec1)[0xe] = cd; ((unsigned char *)rec1)[0xf] = cc;
    ((unsigned char *)rec1)[0x10] = cd; ((unsigned char *)rec1)[0x11] = cb;
    ((unsigned char *)rec2)[0xc] = ca; ((unsigned char *)rec2)[0xd] = cc;
    ((unsigned char *)rec2)[0xe] = cd; ((unsigned char *)rec2)[0xf] = cb;
    ((unsigned char *)rec2)[0x10] = ca; ((unsigned char *)rec2)[0x11] = cb;

    x0 = (int)*(short *)MK4_PTR(sheet + 8);
    y0 = (int)*(short *)MK4_PTR(sheet + 0xa);

    *MK4_VA(short, 0x7af958u) = (short)x0;
    *MK4_VA(short, 0x7af95eu) = (short)y0;
    *MK4_VA(short, 0x7af964u) = 0;
    *MK4_VA(short, 0x7af95au) = (short)(x0 + *(short *)MK4_PTR(sheet + 4));
    *MK4_VA(short, 0x7af960u) = (short)y0;
    *MK4_VA(short, 0x7af966u) = 0;
    *MK4_VA(short, 0x7af95cu) = (short)(x0 + *(short *)MK4_PTR(sheet + 4));
    *MK4_VA(short, 0x7af962u) = (short)(y0 + *(short *)MK4_PTR(sheet + 6));
    *MK4_VA(short, 0x7af968u) = 0;
    ProjectTwoVertices();

    key = *MK4_VA(unsigned short, 0xab4e20u);      /* g_tickCurMask */
    if (key == 0)
        key = (unsigned short)(((MaxOfThree() << 16 >> 16) / 2)
                               + (int)(g_dispatchSave1559 << 5));
    ((unsigned short *)rec1)[9] = key;
    ((unsigned short *)rec2)[9] = key;

    /* `test byte ptr [flags], 0x40` - the LOW byte, so bit 6 */
    if ((g_currentNodeFlags & 0x40u) == 0) {
    p1x = (int)*MK4_VA(short, 0x7af9b4u);
    p1y = (int)*MK4_VA(short, 0x7af9b6u);
    p2x = (int)*MK4_VA(short, 0x7af9b8u);
    p2y = (int)*MK4_VA(short, 0x7af9bau);
    sx  = (int)*MK4_VA(short, 0x7af9bcu);
    sy  = (int)*MK4_VA(short, 0x7af9beu);
    valid = ((sy - p1y) * (p2x - p1x) - (p2y - p1y) * (sx - p1x)) <= 0;
    rec1[0] = *MK4_VA(unsigned int, 0x7af9b4u);
    rec1[1] = *MK4_VA(unsigned int, 0x7af9b8u);
    rec1[2] = *MK4_VA(unsigned int, 0x7af9bcu);
    *MK4_VA(unsigned int, 0x7af9b0u) = (unsigned int)valid;
    f1 = (unsigned short)((f1 & 0xfbffu)
                                 | ((unsigned)valid << 10));

        if ((int)*MK4_VA(int, 0x7af984u) > 0 && (int)*MK4_VA(int, 0x7af988u) > 0
        && (int)*MK4_VA(int, 0x7af98cu) > 0) {
            CopyArgs16ToGlobals((unsigned short)x0,
                (unsigned short)(y0 + *(short *)MK4_PTR(sheet + 6)), 0);
            ProjectVertex();
    p1x = (int)*MK4_VA(short, 0x7af9b4u);
        p1y = (int)*MK4_VA(short, 0x7af9b6u);
        p2x = (int)*MK4_VA(short, 0x7af9b8u);
        p2y = (int)*MK4_VA(short, 0x7af9bau);
        sx  = (int)*MK4_VA(short, 0x7af9bcu);
        sy  = (int)*MK4_VA(short, 0x7af9beu);
        valid = ((sy - p1y) * (p2x - p1x) - (p2y - p1y) * (sx - p1x)) <= 0;
        rec2[0] = *MK4_VA(unsigned int, 0x7af9b4u);
        rec2[1] = *MK4_VA(unsigned int, 0x7af9b8u);
        rec2[2] = *MK4_VA(unsigned int, 0x7af9bcu);
        *MK4_VA(unsigned int, 0x7af9b0u) = (unsigned int)valid;
        f2 = (unsigned short)((f2 & 0xfbffu)
                                     | ((unsigned)valid << 10));

            if ((int)*MK4_VA(int, 0x7af984u) > 0 && (int)*MK4_VA(int, 0x7af988u) > 0
        && (int)*MK4_VA(int, 0x7af98cu) > 0) {
                ((unsigned short *)rec1)[0xd] = f1;
                ((unsigned short *)rec2)[0xd] = f2;
                if (((unsigned short *)rec1)[1] == ((unsigned short *)rec1)[3]
                    && ((unsigned short *)rec1)[0] == ((unsigned short *)rec2)[4]
                    && ((unsigned short *)rec1)[4] == ((unsigned short *)rec1)[2]
                    && ((unsigned short *)rec1)[5] == ((unsigned short *)rec2)[5]) {
                    ((unsigned char *)rec1)[0x1a] |= 0x20;
                    Helper_DrawCursor(rec1);
                    ((unsigned short *)rec1)[0xd] &= 0xffdfu;
                } else {
                    Helper_DrawCursor(rec1);
                    Helper_DrawCursor(rec2);
                }
                f1 = ((unsigned short *)rec1)[0xd];
                f2 = ((unsigned short *)rec2)[0xd];
            }
        }
    }

    cur = (int)MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x2c);
    g_currentNodeIdx = (unsigned int)cur;
    if (cur == 0)
        return;
    tx = g_vtxTransX;
    ty = g_vtxTransY;
    tz = g_vtxTransZ;

    while (cur != 0) {
        int d = (int)MK4_NODE_AT(int, cur, 4) >> 7;
        int e = (int)MK4_NODE_AT(int, cur, 8) >> 7;
        int g = (int)MK4_NODE_AT(int, cur, 0xc) >> 7;

        /* `test bh, 0x40` - byte ONE of the dword, so bit 14 */
        if ((g_currentNodeFlags & 0x4000u) == 0) {
            int rd, re, rg;

            rd = ((int)*(short *)MK4_PTR(mat * 4u + 0) * d
                  + (int)*(short *)MK4_PTR(mat * 4u + 2) * e
                  + (int)*(short *)MK4_PTR(mat * 4u + 4) * g) >> 12;
            re = ((int)*(short *)MK4_PTR(mat * 4u + 6) * g
                  + (int)*(short *)MK4_PTR(mat * 4u + 0xa) * g
                  + (int)*(short *)MK4_PTR(mat * 4u + 8) * e) >> 12;
            rg = ((int)*(short *)MK4_PTR(mat * 4u + 0xe) * e
                  + (int)*(short *)MK4_PTR(mat * 4u + 0xc) * d
                  + (int)*(short *)MK4_PTR(mat * 4u + 0x10) * g) >> 12;
            d = rd; e = re; g = rg;
        }
        g_vtxTransX = tx + d;
        g_vtxTransY = ty + e;
        g_vtxTransZ = tz + g;

    *MK4_VA(short, 0x7af958u) = (short)x0;
        *MK4_VA(short, 0x7af95eu) = (short)y0;
        *MK4_VA(short, 0x7af964u) = 0;
        *MK4_VA(short, 0x7af95au) = (short)(x0 + *(short *)MK4_PTR(sheet + 4));
        *MK4_VA(short, 0x7af960u) = (short)y0;
        *MK4_VA(short, 0x7af966u) = 0;
        *MK4_VA(short, 0x7af95cu) = (short)(x0 + *(short *)MK4_PTR(sheet + 4));
        *MK4_VA(short, 0x7af962u) = (short)(y0 + *(short *)MK4_PTR(sheet + 6));
        *MK4_VA(short, 0x7af968u) = 0;
        ProjectTwoVertices();

    p1x = (int)*MK4_VA(short, 0x7af9b4u);
        p1y = (int)*MK4_VA(short, 0x7af9b6u);
        p2x = (int)*MK4_VA(short, 0x7af9b8u);
        p2y = (int)*MK4_VA(short, 0x7af9bau);
        sx  = (int)*MK4_VA(short, 0x7af9bcu);
        sy  = (int)*MK4_VA(short, 0x7af9beu);
        valid = ((sy - p1y) * (p2x - p1x) - (p2y - p1y) * (sx - p1x)) <= 0;
        rec1[0] = *MK4_VA(unsigned int, 0x7af9b4u);
        rec1[1] = *MK4_VA(unsigned int, 0x7af9b8u);
        rec1[2] = *MK4_VA(unsigned int, 0x7af9bcu);
        *MK4_VA(unsigned int, 0x7af9b0u) = (unsigned int)valid;
        f1 = (unsigned short)((f1 & 0xfbffu)
                                     | ((unsigned)valid << 10));

        ((unsigned short *)rec1)[0xd] = f1;
        if ((int)*MK4_VA(int, 0x7af984u) > 0 && (int)*MK4_VA(int, 0x7af988u) > 0
        && (int)*MK4_VA(int, 0x7af98cu) > 0)
            Helper_DrawCursor(rec1);

        CopyArgs16ToGlobals((unsigned short)x0,
            (unsigned short)(y0 + *(short *)MK4_PTR(sheet + 6)), 0);
        ProjectVertex();
    p1x = (int)*MK4_VA(short, 0x7af9b4u);
        p1y = (int)*MK4_VA(short, 0x7af9b6u);
        p2x = (int)*MK4_VA(short, 0x7af9b8u);
        p2y = (int)*MK4_VA(short, 0x7af9bau);
        sx  = (int)*MK4_VA(short, 0x7af9bcu);
        sy  = (int)*MK4_VA(short, 0x7af9beu);
        valid = ((sy - p1y) * (p2x - p1x) - (p2y - p1y) * (sx - p1x)) <= 0;
        rec2[0] = *MK4_VA(unsigned int, 0x7af9b4u);
        rec2[1] = *MK4_VA(unsigned int, 0x7af9b8u);
        rec2[2] = *MK4_VA(unsigned int, 0x7af9bcu);
        *MK4_VA(unsigned int, 0x7af9b0u) = (unsigned int)valid;
        f2 = (unsigned short)((f2 & 0xfbffu)
                                     | ((unsigned)valid << 10));

        ((unsigned short *)rec2)[0xd] = f2;
        if ((int)*MK4_VA(int, 0x7af984u) > 0 && (int)*MK4_VA(int, 0x7af988u) > 0
        && (int)*MK4_VA(int, 0x7af98cu) > 0)
            Helper_DrawCursor(rec2);

        cur = (int)*MK4_NODE(unsigned int, cur);
        g_currentNodeIdx = (unsigned int)cur;
    }
}
#else
__declspec(naked) void BillboardSheetDualEmit(void)
{
    __asm {
        mov      eax, dword ptr [g_inLoopStep]
        sub      esp, 0x58
        test     eax, eax
        push     ebx
        push     ebp
        push     esi
        push     edi
        jne      L_c45f
        mov      eax, dword ptr [g_dispatchSave1576]
        cmp      eax, 0x10
        jl       L_bdca
        cdq
        and      edx, 7
        add      eax, edx
        sar      eax, 3
        dec      eax
        jmp      L_bdcc
    L_bdca:
        xor      eax, eax
    L_bdcc:
        mov      ecx, eax
        shl      ecx, 5
        or       ecx, eax
        shl      ecx, 5
        or       eax, ecx
        mov      cl, byte ptr [g_fightGroupHead]
        test     cl, 0x60
        je       L_be12
        mov      edx, dword ptr [g_dispatchSave1501]
        mov      ecx, dword ptr [g_dispatchSave1502]
        sar      edx, 0x10
        mov      dword ptr [g_vtxTransX], edx
        mov      edx, dword ptr [g_dispatchSave1503]
        sar      ecx, 0x10
        sar      edx, 7
        mov      dword ptr [g_vtxTransY], ecx
        mov      dword ptr [g_vtxTransZ], edx
        jmp      L_be3f
    L_be12:
        mov      ecx, dword ptr [g_dispatchSave1501]
        mov      edx, dword ptr [g_dispatchSave1502]
        sar      ecx, 7
        mov      dword ptr [g_vtxTransX], ecx
        mov      ecx, dword ptr [g_dispatchSave1503]
        sar      edx, 7
        sar      ecx, 7
        mov      dword ptr [g_vtxTransY], edx
        mov      dword ptr [g_vtxTransZ], ecx
    L_be3f:
        mov      ecx, dword ptr [g_xformEntityIdx]
        mov      esi, dword ptr [esp + 0x6c]
        mov      ecx, dword ptr [ecx + 4]
        mov      bp, word ptr [esi + 0xa]
        mov      dword ptr [esp + 0x18], ebp
        mov      edx, dword ptr [ecx + 4]
        mov      word ptr [esp + 0x5c], ax
        mov      word ptr [esp + 0x3c], ax
        mov      al, byte ptr [esi + 1]
        and      eax, 3
        lea      edi, [edx + ecx + 8]
        xor      edx, edx
        mov      cl, byte ptr [eax + g_dispatchSave531]
        mov      dl, byte ptr [esi + 2]
        and      cl, 3
        movsx    ax, cl
        shl      eax, 7
        mov      word ptr [esp + 0x62], ax
        mov      ecx, dword ptr [esp + 0x62]
        mov      bl, byte ptr [esp + 0x62]
        and      ecx, 0x180
        mov      word ptr [esp + 0x42], cx
        mov      dl, byte ptr [edi + edx*4 + 2]
        xor      dl, bl
        mov      bl, byte ptr [esp + 0x42]
        and      edx, 0xf
        mov      di, word ptr [esi + 8]
        xor      ax, dx
        mov      dl, byte ptr [esi + 0xe]
        mov      word ptr [esp + 0x62], ax
        mov      al, byte ptr [esp + 0x62]
        xor      al, bl
        mov      bl, byte ptr [esi + 0xf]
        and      eax, 0xf
        xor      cx, ax
        mov      al, byte ptr [esi + 0xc]
        mov      word ptr [esp + 0x42], cx
        mov      cl, byte ptr [esi + 0xd]
        mov      byte ptr [esp + 0x35], cl
        mov      byte ptr [esp + 0x37], cl
        add      bl, cl
        mov      byte ptr [esp + 0x55], cl
        mov      cx, di
        add      dl, al
        mov      word ptr [g_dispatchSave1626], di
        mov      word ptr [g_vtxIn1_y], bp
        mov      word ptr [g_vtxIn2_y], 0
        add      cx, word ptr [esi + 4]
        mov      byte ptr [esp + 0x36], dl
        mov      byte ptr [esp + 0x38], dl
        mov      byte ptr [esp + 0x56], dl
        mov      dx, di
        mov      word ptr [g_vtxIn2_x], cx
        mov      word ptr [g_vtxIn1_z], bp
        mov      word ptr [g_vtxIn2_z], 0
        add      dx, word ptr [esi + 4]
        mov      byte ptr [esp + 0x34], al
        mov      byte ptr [esp + 0x54], al
        mov      byte ptr [esp + 0x58], al
        mov      ax, bp
        mov      word ptr [g_triStripX0], dx
        add      ax, word ptr [esi + 6]
        mov      byte ptr [esp + 0x39], bl
        mov      byte ptr [esp + 0x57], bl
        mov      byte ptr [esp + 0x59], bl
        mov      word ptr [g_triStripX1], ax
        mov      word ptr [g_triStripX2], 0
        call     ProjectTwoVertices
        mov      ax, word ptr [g_tickCurMask]
        test     ax, ax
        jne      L_bf84
        call     MaxOfThree
        mov      ecx, dword ptr [g_dispatchSave1559]
        movsx    eax, ax
        cdq
        sub      eax, edx
        sar      eax, 1
        shl      ecx, 5
        add      ax, cx
    L_bf84:
        mov      word ptr [esp + 0x3a], ax
        mov      word ptr [esp + 0x5a], ax
        test     byte ptr [g_currentNodeFlags], 0x40
        jne      L_c15a
        movsx    eax, word ptr [g_triStripRingA]
        movsx    ecx, word ptr [g_vtxScreenP1Y]
        movsx    edx, word ptr [g_vtxScreenY]
        movsx    ebx, word ptr [g_vtxScreenP2X]
        sub      edx, ecx
        sub      ebx, eax
        imul     edx, ebx
        movsx    ebx, word ptr [g_vtxScreenP2Y]
        sub      ebx, ecx
        movsx    ecx, word ptr [g_vtxScreenX]
        sub      ecx, eax
        xor      eax, eax
        imul     ebx, ecx
        mov      ecx, dword ptr [g_triStripRingA]
        sub      edx, ebx
        test     edx, edx
        mov      edx, dword ptr [g_vtxScreenP2X]
        mov      dword ptr [esp + 0x28], ecx
        mov      ecx, dword ptr [esp + 0x42]
        mov      dword ptr [esp + 0x2c], edx
        setle    al
        mov      dword ptr [g_vtxValid], eax
        mov      dl, byte ptr [g_vtxValid]
        mov      eax, dword ptr [g_vtxScreenX]
        and      edx, 1
        mov      dword ptr [esp + 0x30], eax
        mov      eax, dword ptr [g_triStripRingB]
        and      ecx, 0xfbff
        shl      edx, 0xa
        or       ecx, edx
        test     eax, eax
        mov      word ptr [esp + 0x42], cx
        jle      L_c15a
        mov      eax, dword ptr [g_vtxOut2_z]
        test     eax, eax
        jle      L_c15a
        mov      eax, dword ptr [g_vtxOut_z]
        test     eax, eax
        jle      L_c15a
        mov      ax, bp
        push     0
        add      ax, word ptr [esi + 6]
        push     eax
        push     edi
        call     CopyArgs16ToGlobals
        add      esp, 0xc
        call     ProjectVertex
        movsx    eax, word ptr [g_triStripRingA]
        movsx    ecx, word ptr [g_vtxScreenP1Y]
        movsx    edx, word ptr [g_vtxScreenY]
        movsx    ebx, word ptr [g_vtxScreenP2X]
        sub      edx, ecx
        sub      ebx, eax
        imul     edx, ebx
        movsx    ebx, word ptr [g_vtxScreenP2Y]
        sub      ebx, ecx
        movsx    ecx, word ptr [g_vtxScreenX]
        sub      ecx, eax
        xor      eax, eax
        imul     ebx, ecx
        mov      ecx, dword ptr [g_triStripRingA]
        sub      edx, ebx
        test     edx, edx
        mov      edx, dword ptr [g_vtxScreenP2X]
        mov      dword ptr [esp + 0x48], ecx
        mov      ecx, dword ptr [esp + 0x62]
        mov      dword ptr [esp + 0x4c], edx
        setle    al
        mov      dword ptr [g_vtxValid], eax
        mov      dl, byte ptr [g_vtxValid]
        mov      eax, dword ptr [g_vtxScreenX]
        and      edx, 1
        mov      dword ptr [esp + 0x50], eax
        mov      eax, dword ptr [g_triStripRingB]
        and      ecx, 0xfbff
        shl      edx, 0xa
        or       ecx, edx
        test     eax, eax
        mov      word ptr [esp + 0x62], cx
        jle      L_c15a
        mov      eax, dword ptr [g_vtxOut2_z]
        test     eax, eax
        jle      L_c15a
        mov      eax, dword ptr [g_vtxOut_z]
        test     eax, eax
        jle      L_c15a
        mov      ax, word ptr [esp + 0x2a]
        cmp      ax, word ptr [esp + 0x2e]
        jne      L_c140
        mov      cx, word ptr [esp + 0x28]
        cmp      cx, word ptr [esp + 0x50]
        jne      L_c140
        mov      dx, word ptr [esp + 0x30]
        cmp      dx, word ptr [esp + 0x2c]
        jne      L_c140
        mov      ax, word ptr [esp + 0x32]
        cmp      ax, word ptr [esp + 0x52]
        jne      L_c140
        or       byte ptr [esp + 0x42], 0x20
        lea      ecx, [esp + 0x28]
        push     ecx
        call     Helper_DrawCursor
        add      esp, 4
        /* MASM picks 6-byte 66 83 /4 sign-extended form for 0xffdf; orig uses 7-byte 66 81 /4 - force via _emit */
        _emit 0x66
        _emit 0x81
        _emit 0x64
        _emit 0x24
        _emit 0x42
        _emit 0xdf
        _emit 0xff
        jmp      L_c15a
    L_c140:
        lea      edx, [esp + 0x28]
        push     edx
        call     Helper_DrawCursor
        add      esp, 4
        lea      eax, [esp + 0x48]
        push     eax
        call     Helper_DrawCursor
        add      esp, 4
    L_c15a:
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      ecx, dword ptr [ecx*4 + 0x2c]
        test     ecx, ecx
        mov      dword ptr [g_currentNodeIdx], ecx
        je       L_c45f
        mov      edx, dword ptr [g_vtxTransX]
        mov      eax, dword ptr [g_vtxTransY]
        mov      dword ptr [esp + 0x1c], edx
        mov      edx, dword ptr [g_vtxTransZ]
        mov      dword ptr [esp + 0x20], eax
        mov      dword ptr [esp + 0x24], edx
    L_c192:
        mov      edx, dword ptr [ecx*4 + 4]
        mov      eax, dword ptr [ecx*4 + 8]
        mov      ecx, dword ptr [ecx*4 + 0xc]
        mov      ebx, dword ptr [g_currentNodeFlags]
        sar      edx, 7
        sar      eax, 7
        sar      ecx, 7
        test     bh, 0x40
        jne      L_c261
        mov      ebx, dword ptr [esp + 0x70]
        mov      dword ptr [esp + 0x6c], edx
        mov      dword ptr [esp + 0x10], eax
        movsx    ebp, word ptr [ebx*4 + 2]
        movsx    ebx, word ptr [ebx*4]
        imul     ebp, eax
        imul     ebx, edx
        mov      edx, dword ptr [esp + 0x70]
        add      ebp, ebx
        movsx    ebx, word ptr [edx*4 + 4]
        imul     ebx, ecx
        add      ebp, ebx
        movsx    ebx, word ptr [edx*4 + 6]
        imul     ebx, dword ptr [esp + 0x6c]
        sar      ebp, 0xc
        mov      dword ptr [esp + 0x14], ebp
        movsx    ebp, word ptr [edx*4 + 0xa]
        imul     ebp, ecx
        add      ebx, ebp
        movsx    ebp, word ptr [edx*4 + 8]
        imul     ebp, eax
        add      ebx, ebp
        mov      ebp, dword ptr [esp + 0x18]
        sar      ebx, 0xc
        mov      eax, ebx
        movsx    ebx, word ptr [edx*4 + 0xe]
        movsx    edx, word ptr [edx*4 + 0xc]
        imul     ebx, dword ptr [esp + 0x10]
        imul     edx, dword ptr [esp + 0x6c]
        add      ebx, edx
        mov      edx, dword ptr [esp + 0x70]
        movsx    edx, word ptr [edx*4 + 0x10]
        imul     edx, ecx
        add      ebx, edx
        mov      edx, dword ptr [esp + 0x14]
        sar      ebx, 0xc
        mov      ecx, ebx
    L_c261:
        mov      ebx, dword ptr [esp + 0x1c]
        mov      word ptr [g_dispatchSave1626], di
        add      edx, ebx
        mov      word ptr [g_vtxIn1_y], bp
        mov      dword ptr [g_vtxTransX], edx
        mov      edx, dword ptr [esp + 0x20]
        add      eax, edx
        mov      dx, di
        mov      dword ptr [g_vtxTransY], eax
        mov      eax, dword ptr [esp + 0x24]
        add      ecx, eax
        xor      eax, eax
        mov      dword ptr [g_vtxTransZ], ecx
        mov      cx, di
        mov      word ptr [g_vtxIn2_y], ax
        add      cx, word ptr [esi + 4]
        mov      word ptr [g_vtxIn1_z], bp
        mov      word ptr [g_vtxIn2_z], ax
        mov      word ptr [g_vtxIn2_x], cx
        add      dx, word ptr [esi + 4]
        mov      cx, bp
        mov      word ptr [g_triStripX0], dx
        add      cx, word ptr [esi + 6]
        mov      word ptr [g_triStripX2], ax
        mov      word ptr [g_triStripX1], cx
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
        movsx    ecx, word ptr [g_vtxScreenX]
        sub      ecx, eax
        xor      eax, eax
        imul     ebx, ecx
        mov      ecx, dword ptr [g_triStripRingA]
        sub      edx, ebx
        test     edx, edx
        mov      edx, dword ptr [g_vtxScreenP2X]
        mov      dword ptr [esp + 0x28], ecx
        mov      ecx, dword ptr [esp + 0x42]
        mov      dword ptr [esp + 0x2c], edx
        setle    al
        mov      dword ptr [g_vtxValid], eax
        mov      dl, byte ptr [g_vtxValid]
        mov      eax, dword ptr [g_vtxScreenX]
        and      edx, 1
        mov      dword ptr [esp + 0x30], eax
        mov      eax, dword ptr [g_triStripRingB]
        and      ecx, 0xfbff
        shl      edx, 0xa
        or       ecx, edx
        test     eax, eax
        mov      word ptr [esp + 0x42], cx
        jle      L_c384
        mov      eax, dword ptr [g_vtxOut2_z]
        test     eax, eax
        jle      L_c384
        mov      eax, dword ptr [g_vtxOut_z]
        test     eax, eax
        jle      L_c384
        lea      eax, [esp + 0x28]
        push     eax
        call     Helper_DrawCursor
        add      esp, 4
    L_c384:
        mov      cx, bp
        push     0
        add      cx, word ptr [esi + 6]
        push     ecx
        push     edi
        call     CopyArgs16ToGlobals
        add      esp, 0xc
        call     ProjectVertex
        movsx    eax, word ptr [g_triStripRingA]
        movsx    ecx, word ptr [g_vtxScreenP1Y]
        movsx    edx, word ptr [g_vtxScreenY]
        movsx    ebx, word ptr [g_vtxScreenP2X]
        sub      edx, ecx
        sub      ebx, eax
        imul     edx, ebx
        movsx    ebx, word ptr [g_vtxScreenP2Y]
        sub      ebx, ecx
        movsx    ecx, word ptr [g_vtxScreenX]
        sub      ecx, eax
        xor      eax, eax
        imul     ebx, ecx
        mov      ecx, dword ptr [g_triStripRingA]
        sub      edx, ebx
        test     edx, edx
        mov      edx, dword ptr [g_vtxScreenP2X]
        mov      dword ptr [esp + 0x48], ecx
        mov      ecx, dword ptr [esp + 0x62]
        mov      dword ptr [esp + 0x4c], edx
        setle    al
        mov      dword ptr [g_vtxValid], eax
        mov      dl, byte ptr [g_vtxValid]
        mov      eax, dword ptr [g_vtxScreenX]
        and      edx, 1
        mov      dword ptr [esp + 0x50], eax
        mov      eax, dword ptr [g_triStripRingB]
        and      ecx, 0xfbff
        shl      edx, 0xa
        or       ecx, edx
        test     eax, eax
        mov      word ptr [esp + 0x62], cx
        jle      L_c444
        mov      eax, dword ptr [g_vtxOut2_z]
        test     eax, eax
        jle      L_c444
        mov      eax, dword ptr [g_vtxOut_z]
        test     eax, eax
        jle      L_c444
        lea      eax, [esp + 0x48]
        push     eax
        call     Helper_DrawCursor
        add      esp, 4
    L_c444:
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      ecx, dword ptr [ecx*4]
        test     ecx, ecx
        mov      dword ptr [g_currentNodeIdx], ecx
        jne      L_c192
    L_c45f:
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        add      esp, 0x58
        ret
    }
}
#endif
