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
extern unsigned int g_fpZeroCam;
extern unsigned int g_fpBam2PiScale;
extern s16 g_vtxMat[];
extern unsigned int g_mat3x3_007af994;
extern unsigned int g_mat3x3_007af998;
extern unsigned int g_mat3x3_007af99c;
extern unsigned int g_mat3x3_007af9a0;
extern unsigned int g_dispatchSave1504;
extern unsigned int g_dispatchSave1505;
extern unsigned int g_dispatchSave1506;
extern unsigned int g_dispatchSave1507;
extern unsigned int g_dispatchSave1508;
extern unsigned int g_dispatchSave1509;
extern unsigned int g_dispatchSave1510;
extern unsigned int g_dispatchSave1511;
extern unsigned int g_dispatchSave1512;
extern unsigned int g_camRotXBam;
extern unsigned int g_camRotYBam;
extern unsigned int g_camRotZBam;
extern unsigned int g_dispatchSave1519;
extern unsigned int g_dispatchSave1520;
extern unsigned int g_dispatchSave1521;
extern unsigned int g_dispatchSave1522;
extern unsigned int g_dispatchSave1523;
extern unsigned int g_dispatchSave1524;
extern unsigned int g_dispatchSave1525;
extern unsigned int g_dispatchSave1526;
extern unsigned int g_dispatchSave1527;
extern unsigned int g_dispatchSave1550;
extern unsigned int g_dispatchSave1554;
extern unsigned int g_dispatchSave1555;
extern unsigned int g_dispatchSave1556;
extern unsigned int g_dispatchSave1557;
extern unsigned int g_dispatchSave1558;
extern unsigned int g_dispatchSave1567;
extern unsigned int g_dispatchSave1574;
extern unsigned int g_pointPosX;
extern unsigned int g_pointPosY;
extern unsigned int g_pointPosZ;
extern unsigned int g_dispatchSave1575;
extern unsigned int g_dispatchSave1576;
extern unsigned int g_dispatchSave1577;
#endif

#ifndef NON_MATCHING   /* the twin declares these with their real signatures */
extern void Mat3x3VecMul6Bit(void);
extern void Vec3NormalizeScaleStore(void);
extern void Color15BitPacker(void);
extern void PackColor(void);
extern void AltCamMatrixProject(void);
extern void DoubleToInt64(void);
#endif

#ifdef NON_MATCHING
#include "portable/mem_model.h"

extern void Mat3x3VecMul6Bit(int *src, int *dst);
extern void Vec3NormalizeScaleStore(int which, int x, int y, int z);
extern void Color15BitPacker(int r, int g, int b);
extern void PackColor(int which, int r, int g, int b);
extern void AltCamMatrixProject(int *rec, int at);
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_pointColorR;   /* 0x00ab4e44 */
extern unsigned int g_pointColorG;   /* 0x00ab4e48 */
extern unsigned int g_pointColorB;   /* 0x00ab4e4c */
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
#define g_camRotXBam (*(unsigned int **)MK4_VA(unsigned int, 0xab47f8u))
#define g_camRotYBam (*(unsigned int **)MK4_VA(unsigned int, 0xab47fau))
#define g_camRotZBam (*(unsigned int **)MK4_VA(unsigned int, 0xab47fcu))
#define g_chainAccumCur (*(unsigned int *)MK4_VA(unsigned int, 0x542078u))
#define g_cj_00542054 (*(unsigned int *)MK4_VA(unsigned int, 0x542054u))
#define g_cj_00542058 (*(unsigned int *)MK4_VA(unsigned int, 0x542058u))
#define g_cj_0054205c (*(unsigned int *)MK4_VA(unsigned int, 0x54205cu))
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_dispatchSave1504 (*(unsigned int *)MK4_VA(unsigned int, 0xab44d8u))
#define g_dispatchSave1505 (*(unsigned int *)MK4_VA(unsigned int, 0xab44dau))
#define g_dispatchSave1506 (*(unsigned int *)MK4_VA(unsigned int, 0xab44dcu))
#define g_dispatchSave1507 (*(unsigned int *)MK4_VA(unsigned int, 0xab44deu))
#define g_dispatchSave1508 (*(unsigned int *)MK4_VA(unsigned int, 0xab44e0u))
#define g_dispatchSave1509 (*(unsigned int *)MK4_VA(unsigned int, 0xab44e2u))
#define g_dispatchSave1510 (*(unsigned int *)MK4_VA(unsigned int, 0xab44e4u))
#define g_dispatchSave1511 (*(unsigned int *)MK4_VA(unsigned int, 0xab44e6u))
#define g_dispatchSave1512 (*(unsigned int *)MK4_VA(unsigned int, 0xab44e8u))
#define g_dispatchSave1519 (*(unsigned int *)MK4_VA(unsigned int, 0xab47feu))
#define g_dispatchSave1520 (*(unsigned int *)MK4_VA(unsigned int, 0xab4800u))
#define g_dispatchSave1521 (*(unsigned int *)MK4_VA(unsigned int, 0xab4802u))
#define g_dispatchSave1522 (*(unsigned int *)MK4_VA(unsigned int, 0xab4804u))
#define g_dispatchSave1523 (*(unsigned int *)MK4_VA(unsigned int, 0xab4806u))
#define g_dispatchSave1524 (*(unsigned int *)MK4_VA(unsigned int, 0xab4808u))
#define g_dispatchSave1525 (*(unsigned int *)MK4_VA(unsigned int, 0xab4838u))
#define g_dispatchSave1526 (*(unsigned int *)MK4_VA(unsigned int, 0xab483cu))
#define g_dispatchSave1527 (*(unsigned int *)MK4_VA(unsigned int, 0xab4840u))
#define g_dispatchSave1550 (*(unsigned int *)MK4_VA(unsigned int, 0xab4cd8u))
#define g_dispatchSave1554 (*(unsigned int *)MK4_VA(unsigned int, 0xab4d58u))
#define g_dispatchSave1555 (*(unsigned int *)MK4_VA(unsigned int, 0xab4d5cu))
#define g_dispatchSave1556 (*(unsigned int *)MK4_VA(unsigned int, 0xab4d60u))
#define g_dispatchSave1557 (*(unsigned int *)MK4_VA(unsigned int, 0xab4d64u))
#define g_dispatchSave1558 (*(unsigned int *)MK4_VA(unsigned int, 0xab4d68u))
#define g_dispatchSave1567 (*(unsigned int *)MK4_VA(unsigned int, 0xab4dc4u))
#define g_dispatchSave1574 (*(unsigned int *)MK4_VA(unsigned int, 0xab4e3cu))
#define g_dispatchSave1575 (*(unsigned int *)MK4_VA(unsigned int, 0xab4e5cu))
#define g_dispatchSave1576 (*(unsigned int *)MK4_VA(unsigned int, 0xab4e60u))
#define g_dispatchSave1577 (*(unsigned int *)MK4_VA(unsigned int, 0xab4e6cu))
#define g_dualBitGate (*(unsigned int *)MK4_VA(unsigned int, 0x53a7b0u))
#define g_eventArmReload (*(unsigned int *)MK4_VA(unsigned int, 0x53a770u))
#define g_fightAxisNegX (*(unsigned int *)MK4_VA(unsigned int, 0x535e70u))
#define g_fightAxisNegY (*(unsigned int *)MK4_VA(unsigned int, 0x535e74u))
#define g_fightAxisPosX (*(unsigned int *)MK4_VA(unsigned int, 0x535e78u))
#define g_fightAxisPosY (*(unsigned int *)MK4_VA(unsigned int, 0x535e7cu))
#define g_fightGroupHead (*(unsigned int *)MK4_VA(unsigned int, 0x54205cu))
#define g_fightStateProgress (*(unsigned int *)MK4_VA(unsigned int, 0x535ddcu))
#define g_fpBam2PiScale (*(unsigned int *)MK4_VA(unsigned int, 0x4d2a28u))
#define g_fpZeroCam (*(unsigned int *)MK4_VA(unsigned int, 0x4d2a20u))
#define g_gameCountdown (*(unsigned int *)MK4_VA(unsigned int, 0x53a718u))
#define g_installOwnerNode (*(unsigned int *)MK4_VA(unsigned int, 0x535cf8u))
#define g_lastGatedTick (*(unsigned int *)MK4_VA(unsigned int, 0x54358cu))
#define g_lastGatedValue (*(unsigned int *)MK4_VA(unsigned int, 0x543598u))
#define g_mat3x3_007af994 (*(short *)MK4_VA(short, 0x7af994u))
#define g_mat3x3_007af998 (*(short *)MK4_VA(short, 0x7af998u))
#define g_mat3x3_007af99c (*(short *)MK4_VA(short, 0x7af99cu))
#define g_mat3x3_007af9a0 (*(short *)MK4_VA(short, 0x7af9a0u))
#define g_pendingNodeType (*(unsigned int *)MK4_VA(unsigned int, 0x54204cu))
#define g_pointColorB (*(unsigned int *)MK4_VA(unsigned int, 0xab4e4cu))
#define g_pointColorG (*(unsigned int *)MK4_VA(unsigned int, 0xab4e48u))
#define g_pointColorR (*(unsigned int *)MK4_VA(unsigned int, 0xab4e44u))
#define g_pointPosX (*(unsigned int *)MK4_VA(unsigned int, 0xab4e50u))
#define g_pointPosY (*(unsigned int *)MK4_VA(unsigned int, 0xab4e54u))
#define g_pointPosZ (*(unsigned int *)MK4_VA(unsigned int, 0xab4e58u))
#define g_rangeBase (*(unsigned int *)MK4_VA(unsigned int, 0x53a46cu))
#define g_rangeSqLimit (*(unsigned int *)MK4_VA(unsigned int, 0x53a180u))
#define g_stateCountdown (*(unsigned int *)MK4_VA(unsigned int, 0x53a3c0u))
#define g_tickFlagZ (*(unsigned int *)MK4_VA(unsigned int, 0xab4e40u))
#define g_tickW1 (*(unsigned int *)MK4_VA(unsigned int, 0x543550u))
#define g_tickX3 (*(unsigned int *)MK4_VA(unsigned int, 0xab4e68u))
#define g_vtxMat ((short *)MK4_VA(short, 0x7af990u))
#define g_walkCallback (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_xformEntityIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542048u))
#define g_xformScratch94 (*(unsigned int *)MK4_VA(unsigned int, 0x542094u))
#endif


/* Portable twin, written from the disassembly - the lift had every double as
 * an `unsigned int`, bare `__ftol()` calls with no argument, and host-pointer
 * arithmetic on `&g_dispatchSave571`-style table bases.
 *
 * This is the per-frame camera setup. The camera-to-target vector (the two
 * nodes' +0x15 blocks) is rotated through the wt 3x3, its direction is turned
 * into the three BAM rotation angles - the length as `fild/fsqrt`, then each
 * component scaled by g_fpBam2PiScale/len and truncated the way the CRT's
 * __ftol does - and the negated angles become g_camRot{X,Y,Z}Bam. The second
 * half does the same dance for the point light, with an intensity of
 * 0x180000/len2 clamped to 0x100, and folds it into the three colour words.
 *
 * The zero-length guards compare the SQUARE ROOT against the double at
 * 0x004d2a20 with `fcom`; only C3 is tested, so "equal" means skip. len2 is a
 * non-negative int, so the unordered case cannot happen.
 *
 * FOV clamping stores g_walkCallback at each step it takes, including the raw
 * value first - transcribed as written, since every store is observable.
 *
 * All the packed camera words (1504..1524 at 0x00ab44d8/0x00ab47f8/0x00ab4800)
 * are spelled at their real widths by explicit VA, the same discipline as
 * MovesPanelEmit; the width tables are not involved. __builtin_sqrt is the
 * fpu_sqrt_mul.c precedent - the harness compiles with -fno-math-errno so it
 * lowers to fsqrt with no libm call. */
void CameraSetupAndCullFan(void)
{
    unsigned int saved_pnt = g_pendingNodeType;
    unsigned int saved_cur = g_currentNodeIdx;
    unsigned int fov, w1, halfspan, span;
    int dx, dy, dz, x, y, z, len2;
    double len;

    g_walkCallback = ((g_tickX3 * 3u) << 5) >> 8;
    g_dispatchSave1575 = g_walkCallback;
    w1 = g_tickW1;
    g_dispatchSave1576 = w1;

    fov = (unsigned int)((int)MK4_NODE_AT(int, g_xformEntityIdx, 0x3c) >> 8);
    g_walkCallback = fov;
    if ((int)fov < 0x60) {
        fov = 0x60;
        g_walkCallback = fov;
    } else if ((int)fov > 0xa0) {
        fov = 0xa0;
        g_walkCallback = fov;
    }
    span = (unsigned int)((int)((w1 * fov) << 3) >> 8);
    if ((int)fov > 0x100) {
        fov = 0x100;
        g_walkCallback = fov;
    }
    g_dispatchSave1577 = (unsigned int)((int)(w1 * fov) >> 8);

    *MK4_VA(short, 0xab44d8u) = (short)span;             /* 1504 */
    *MK4_VA(short, 0xab44deu) = (short)span;             /* 1507 */
    *MK4_VA(short, 0xab44e4u) = (short)span;             /* 1510 */
    halfspan = (unsigned int)((int)span >> 1);
    *MK4_VA(short, 0xab44dau) = (short)-(int)halfspan;   /* 1505 */
    *MK4_VA(short, 0xab44e0u) = (short)-(int)halfspan;   /* 1508 */
    *MK4_VA(short, 0xab44e6u) = (short)-(int)halfspan;   /* 1511 */

    /* camera-to-target vector, then rotate it through the wt 3x3 in place */
    g_pendingNodeType = g_xformEntityIdx + 0x15;
    g_xformEntityIdx  = saved_cur + 0x15;
    *MK4_VA(int, 0xab4838u) =
        (int)(MK4_NODE_AT(unsigned int, g_xformEntityIdx, 0)
              - MK4_NODE_AT(unsigned int, g_pendingNodeType, 0)) >> 8;
    *MK4_VA(int, 0xab483cu) =
        (int)(MK4_NODE_AT(unsigned int, g_xformEntityIdx, 4)
              - MK4_NODE_AT(unsigned int, g_pendingNodeType, 4)) >> 8;
    *MK4_VA(int, 0xab4840u) =
        (int)(MK4_NODE_AT(unsigned int, g_xformEntityIdx, 8)
              - MK4_NODE_AT(unsigned int, g_pendingNodeType, 8)) >> 8;

    *MK4_VA(unsigned int, 0x7af990u) = *MK4_VA(unsigned int, 0xab4d58u);
    *MK4_VA(unsigned int, 0x7af994u) = *MK4_VA(unsigned int, 0xab4d5cu);
    *MK4_VA(unsigned int, 0x7af998u) = *MK4_VA(unsigned int, 0xab4d60u);
    *MK4_VA(unsigned int, 0x7af99cu) = *MK4_VA(unsigned int, 0xab4d64u);
    *MK4_VA(unsigned short, 0x7af9a0u) = *MK4_VA(unsigned short, 0xab4d68u);

    Mat3x3VecMul6Bit(MK4_VA(int, 0xab4838u), MK4_VA(int, 0xab4838u));

    *MK4_VA(short, 0xab4800u) = (short)*MK4_VA(int, 0xab483cu);  /* 1520 */
    x = (int)(short)*MK4_VA(int, 0xab4838u);
    y = (int)(short)*MK4_VA(int, 0xab483cu);
    z = (int)(short)*MK4_VA(int, 0xab4840u);
    len2 = x * x + y * y + z * z;
    *MK4_VA(short, 0xab47feu) = (short)x;                        /* 1519 */
    *MK4_VA(short, 0xab4802u) = (short)z;                        /* 1521 */

    len = __builtin_sqrt((double)len2);
    if (!(len == *MK4_VA(double, 0x4d2a20u))) {
        double scale = *MK4_VA(double, 0x4d2a28u) / len;

        x = (int)((double)x * scale);
        *MK4_VA(short, 0xab47feu) = (short)x;
        y = (int)((double)y * scale);
        *MK4_VA(short, 0xab4800u) = (short)y;
        z = (int)((double)z * scale);
        *MK4_VA(short, 0xab4802u) = (short)z;
    }

    *MK4_VA(short, 0xab47f8u) = (short)-(int)(short)x;   /* g_camRotXBam */
    *MK4_VA(short, 0xab47fau) =
        (short)-(int)*MK4_VA(short, 0xab4800u);          /* g_camRotYBam */
    *MK4_VA(short, 0xab47fcu) = (short)-(int)(short)z;   /* g_camRotZBam */

    Vec3NormalizeScaleStore(0, (int)(short)x,
                            (int)*MK4_VA(short, 0xab4800u),
                            -(int)(short)z);
    Color15BitPacker(0x50, 0x50, 0x50);
    PackColor(0, (int)halfspan, (int)halfspan, (int)halfspan);

    /* the point light, same shape */
    dx = (int)(g_pointPosX - MK4_NODE_AT(unsigned int, g_xformEntityIdx, 0)) >> 8;
    *MK4_VA(int, 0xab4838u) = dx;
    dy = (int)(g_pointPosY - MK4_NODE_AT(unsigned int, g_xformEntityIdx, 4)) >> 8;
    *MK4_VA(int, 0xab483cu) = dy;
    dz = (int)(g_pointPosZ - MK4_NODE_AT(unsigned int, g_xformEntityIdx, 8)) >> 8;
    len2 = ((dz * dz) >> 12) + ((dy * dy) >> 12) + ((dx * dx) >> 12);
    *MK4_VA(int, 0xab4840u) = dz;

    if (len2 != 0) {
        int inten = 0x180000 / len2;
        int r, g, b;

        *MK4_VA(short, 0xab4808u) = (short)dz;           /* 1524 */
        *MK4_VA(short, 0xab4804u) = (short)dx;           /* 1522 */
        *MK4_VA(short, 0xab4806u) = (short)dy;           /* 1523 */

        x = (int)(short)dx;
        y = (int)(short)dy;
        z = (int)(short)dz;
        len2 = x * x + y * y + z * z;
        inten >>= 8;

        len = __builtin_sqrt((double)len2);
        if (!(len == *MK4_VA(double, 0x4d2a20u))) {
            double scale = *MK4_VA(double, 0x4d2a28u) / len;

            x = (int)((double)x * scale);
            *MK4_VA(short, 0xab4804u) = (short)x;
            y = (int)((double)y * scale);
            *MK4_VA(short, 0xab4806u) = (short)y;
            z = (int)((double)z * scale);
            *MK4_VA(short, 0xab4808u) = (short)z;
        }

        if (inten > 0x100)
            inten = 0x100;
        inten = (int)(((unsigned int)(inten * (int)g_tickX3)) >> 8);

        r = (((int)(g_pointColorR & 0xffffu) - 0x8000) >> 8) * inten;
        g = (((int)(g_pointColorG & 0xffffu) - 0x8000) >> 8) * inten;
        b = (((int)(g_pointColorB & 0xffffu) - 0x8000) >> 8) * inten;
        *MK4_VA(short, 0xab44dcu) = (short)r;            /* 1506 */
        *MK4_VA(short, 0xab44e2u) = (short)g;            /* 1509 */
        *MK4_VA(short, 0xab44e8u) = (short)b;            /* 1512 */

        Vec3NormalizeScaleStore(1, (int)(short)x, (int)(short)y,
                                (int)*MK4_VA(short, 0xab4808u));
        PackColor(1, (int)*MK4_VA(short, 0xab44dcu),
                  (int)*MK4_VA(short, 0xab44e2u),
                  (int)*MK4_VA(short, 0xab44e8u));
    }

    if ((g_fightGroupHead & 0x180000u) && g_tickFlagZ != 0)
        *MK4_VA(unsigned int, 0xab4dc4u) += 0x2b85;      /* 1567 */
    if ((g_fightGroupHead & 0x100000u) && (int)g_dispatchSave1574 >= 0)
        AltCamMatrixProject(MK4_VA(int, 0xab4cd8u), 0);

    g_currentNodeIdx  = saved_cur;
    g_pendingNodeType = saved_pnt;
}
#else
__declspec(naked) void CameraSetupAndCullFan(void)
{
    __asm {
        sub      esp, 0x18
        mov      eax, dword ptr [g_pendingNodeType]
        push     ebx
        mov      dword ptr [esp + 0x18], eax
        mov      eax, dword ptr [g_tickX3]
        push     ebp
        push     esi
        lea      eax, [eax + eax*2]
        mov      edx, dword ptr [g_currentNodeIdx]
        shl      eax, 5
        shr      eax, 8
        push     edi
        mov      edi, dword ptr [g_xformEntityIdx]
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [g_dispatchSave1575], eax
        mov      eax, dword ptr [g_tickW1]
        mov      dword ptr [esp + 0x20], edx
        mov      dword ptr [g_dispatchSave1576], eax
        mov      ecx, dword ptr [edi*4 + 0x3c]
        sar      ecx, 8
        cmp      ecx, 0x60
        mov      dword ptr [g_walkCallback], ecx
        jge      L_9a0e
        mov      ecx, 0x60
        jmp      L_9a1b
    L_9a0e:
        cmp      ecx, 0xa0
        jle      L_9a21
        mov      ecx, 0xa0
    L_9a1b:
        mov      dword ptr [g_walkCallback], ecx
    L_9a21:
        mov      esi, eax
        imul     esi, ecx
        shl      esi, 3
        sar      esi, 8
        cmp      ecx, 0x100
        jle      L_9a3f
        mov      ecx, 0x100
        mov      dword ptr [g_walkCallback], ecx
    L_9a3f:
        imul     eax, ecx
        sar      eax, 8
        mov      word ptr [g_dispatchSave1504], si
        mov      word ptr [g_dispatchSave1507], si
        mov      word ptr [g_dispatchSave1510], si
        mov      dword ptr [g_dispatchSave1577], eax
        sar      esi, 1
        mov      eax, esi
        lea      ecx, [edx + 0x15]
        neg      eax
        mov      word ptr [g_dispatchSave1505], ax
        mov      word ptr [g_dispatchSave1508], ax
        mov      word ptr [g_dispatchSave1511], ax
        lea      eax, [edi + 0x15]
        mov      dword ptr [g_pendingNodeType], eax
        mov      dword ptr [g_xformEntityIdx], ecx
        mov      edx, dword ptr [ecx*4]
        mov      edi, dword ptr [eax*4]
        sub      edx, edi
        push     OFFSET g_dispatchSave1525
        sar      edx, 8
        mov      dword ptr [g_dispatchSave1525], edx
        mov      edx, dword ptr [ecx*4 + 4]
        mov      ebx, dword ptr [eax*4 + 4]
        push     OFFSET g_dispatchSave1525
        sub      edx, ebx
        sar      edx, 8
        mov      dword ptr [g_dispatchSave1526], edx
        mov      ecx, dword ptr [ecx*4 + 8]
        mov      edx, dword ptr [eax*4 + 8]
        mov      eax, dword ptr [g_dispatchSave1555]
        sub      ecx, edx
        mov      edx, dword ptr [g_dispatchSave1554]
        sar      ecx, 8
        mov      dword ptr [g_dispatchSave1527], ecx
        mov      ecx, dword ptr [g_dispatchSave1556]
        mov      dword ptr [g_vtxMat], edx
        mov      edx, dword ptr [g_dispatchSave1557]
        mov      dword ptr [g_mat3x3_007af994], eax
        mov      ax, word ptr [g_dispatchSave1558]
        mov      dword ptr [g_mat3x3_007af998], ecx
        mov      dword ptr [g_mat3x3_007af99c], edx
        mov      word ptr [g_mat3x3_007af9a0], ax
        call     Mat3x3VecMul6Bit
        mov      edi, dword ptr [g_dispatchSave1525]
        mov      ecx, dword ptr [g_dispatchSave1526]
        mov      ebx, dword ptr [g_dispatchSave1527]
        mov      word ptr [g_dispatchSave1520], cx
        movsx    eax, di
        movsx    ecx, cx
        mov      ebp, eax
        mov      dword ptr [esp + 0x18], eax
        movsx    edx, bx
        imul     ebp, eax
        mov      eax, ecx
        mov      dword ptr [esp + 0x1c], ecx
        imul     eax, ecx
        mov      ecx, edx
        add      ebp, eax
        imul     ecx, edx
        add      ebp, ecx
        add      esp, 8
        mov      dword ptr [esp + 0x1c], ebp
        mov      word ptr [g_dispatchSave1519], di
        fild     dword ptr [esp + 0x1c]
        mov      word ptr [g_dispatchSave1521], bx
        mov      dword ptr [esp + 0x18], edx
        fsqrt
        fcom     qword ptr [g_fpZeroCam]
        fnstsw   ax
        test     ah, 0x40
        jne      L_9bca
        fdivr    qword ptr [g_fpBam2PiScale]
        fild     dword ptr [esp + 0x10]
        fmul     st, st(1)
        call     DoubleToInt64
        fild     dword ptr [esp + 0x14]
        mov      di, ax
        mov      word ptr [g_dispatchSave1519], di
        fmul     st, st(1)
        call     DoubleToInt64
        fild     dword ptr [esp + 0x18]
        mov      word ptr [g_dispatchSave1520], ax
        fmul     st, st(1)
        call     DoubleToInt64
        mov      bx, ax
        fstp     st(0)
        mov      word ptr [g_dispatchSave1521], bx
        jmp      L_9bcc
    L_9bca:
        fstp     st(0)
    L_9bcc:
        mov      eax, dword ptr [g_dispatchSave1520]
        mov      dx, di
        neg      dx
        mov      word ptr [g_camRotXBam], dx
        mov      cx, bx
        neg      eax
        movsx    edx, bx
        neg      cx
        mov      word ptr [g_camRotYBam], ax
        mov      word ptr [g_camRotZBam], cx
        movsx    eax, word ptr [g_dispatchSave1520]
        neg      edx
        movsx    ecx, di
        push     edx
        push     eax
        push     ecx
        push     0
        call     Vec3NormalizeScaleStore
        add      esp, 0x10
        push     0x50
        push     0x50
        push     0x50
        call     Color15BitPacker
        add      esp, 0xc
        push     esi
        push     esi
        push     esi
        push     0
        call     PackColor
        mov      eax, dword ptr [g_xformEntityIdx]
        mov      ecx, dword ptr [g_pointPosX]
        mov      esi, dword ptr [g_pointPosY]
        add      esp, 0x10
        mov      edi, dword ptr [eax*4]
        sub      ecx, edi
        mov      edi, dword ptr [g_pointPosZ]
        sar      ecx, 8
        mov      dword ptr [g_dispatchSave1525], ecx
        mov      edx, dword ptr [eax*4 + 4]
        sub      esi, edx
        sar      esi, 8
        mov      dword ptr [g_dispatchSave1526], esi
        mov      ebx, dword ptr [eax*4 + 8]
        sub      edi, ebx
        mov      edx, esi
        sar      edi, 8
        imul     edx, esi
        mov      ebx, edi
        mov      eax, ecx
        imul     ebx, edi
        imul     eax, ecx
        sar      ebx, 0xc
        sar      edx, 0xc
        add      ebx, edx
        mov      dword ptr [g_dispatchSave1527], edi
        sar      eax, 0xc
        add      ebx, eax
        je       L_9df0
        mov      eax, 0x180000
        mov      bp, cx
        cdq
        idiv     ebx
        mov      word ptr [g_dispatchSave1524], di
        mov      word ptr [g_dispatchSave1522], bp
        movsx    edx, di
        mov      word ptr [g_dispatchSave1523], si
        mov      dword ptr [esp + 0x18], edx
        mov      ebx, eax
        movsx    eax, cx
        movsx    ecx, si
        mov      edi, eax
        mov      dword ptr [esp + 0x10], eax
        imul     edi, eax
        mov      eax, ecx
        mov      dword ptr [esp + 0x14], ecx
        imul     eax, ecx
        mov      ecx, edx
        add      edi, eax
        imul     ecx, edx
        add      edi, ecx
        mov      dword ptr [esp + 0x1c], edi
        fild     dword ptr [esp + 0x1c]
        sar      ebx, 8
        fsqrt
        fcom     qword ptr [g_fpZeroCam]
        fnstsw   ax
        test     ah, 0x40
        jne      L_9d42
        fdivr    qword ptr [g_fpBam2PiScale]
        fild     dword ptr [esp + 0x10]
        fmul     st, st(1)
        call     DoubleToInt64
        fild     dword ptr [esp + 0x14]
        mov      bp, ax
        mov      word ptr [g_dispatchSave1522], bp
        fmul     st, st(1)
        call     DoubleToInt64
        fild     dword ptr [esp + 0x18]
        mov      si, ax
        mov      word ptr [g_dispatchSave1523], si
        fmul     st, st(1)
        call     DoubleToInt64
        fstp     st(0)
        mov      word ptr [g_dispatchSave1524], ax
        jmp      L_9d44
    L_9d42:
        fstp     st(0)
    L_9d44:
        cmp      ebx, 0x100
        jle      L_9d51
        mov      ebx, 0x100
    L_9d51:
        imul     ebx, dword ptr [g_tickX3]
        mov      edx, dword ptr [g_gtAxisX]
        mov      eax, dword ptr [g_gtAxisY]
        mov      ecx, dword ptr [g_gtAxisZ]
        and      edx, 0xffff
        and      eax, 0xffff
        sub      edx, 0x8000
        and      ecx, 0xffff
        sub      eax, 0x8000
        shr      ebx, 8
        sar      edx, 8
        sub      ecx, 0x8000
        imul     edx, ebx
        sar      eax, 8
        sar      ecx, 8
        imul     eax, ebx
        imul     ecx, ebx
        mov      word ptr [g_dispatchSave1506], dx
        mov      word ptr [g_dispatchSave1509], ax
        movsx    edx, word ptr [g_dispatchSave1524]
        mov      word ptr [g_dispatchSave1512], cx
        push     edx
        movsx    eax, si
        movsx    ecx, bp
        push     eax
        push     ecx
        push     1
        call     Vec3NormalizeScaleStore
        movsx    edx, word ptr [g_dispatchSave1512]
        movsx    eax, word ptr [g_dispatchSave1509]
        movsx    ecx, word ptr [g_dispatchSave1506]
        add      esp, 0x10
        push     edx
        push     eax
        push     ecx
        push     1
        call     PackColor
        add      esp, 0x10
    L_9df0:
        mov      eax, dword ptr [g_fightGroupHead]
        test     eax, 0x180000
        je       L_9e10
        mov      ecx, dword ptr [g_tickFlagZ]
        test     ecx, ecx
        je       L_9e10
        add      dword ptr [g_dispatchSave1567], 0x2b85
    L_9e10:
        test     ah, 0x10
        je       L_9e2d
        mov      eax, dword ptr [g_dispatchSave1574]
        test     eax, eax
        jl       L_9e2d
        push     0
        push     OFFSET g_dispatchSave1550
        call     AltCamMatrixProject
        add      esp, 8
    L_9e2d:
        mov      edx, dword ptr [esp + 0x20]
        mov      eax, dword ptr [esp + 0x24]
        pop      edi
        pop      esi
        pop      ebp
        mov      dword ptr [g_currentNodeIdx], edx
        mov      dword ptr [g_pendingNodeType], eax
        pop      ebx
        add      esp, 0x18
        ret
    }
}
#endif
