/**
 * The walk-in band: what runs between "FIGHT!" and the fighters standing
 * in their stances - the fight-group init, the pose blend that turns the
 * fighters toward each other, the chase-cam aim spline, and the fixed
 * point trig underneath (BAM angles, full circle = 0x6487e ~ 2*pi<<16).
 *
 * All packed entries join codeptr_extras; every function is the global
 * calling convention (staging words at 0x542044..0x542098). NATIVE-ONLY
 * twins: the matching build synthesizes the original bytes.
 */
#ifdef NON_MATCHING

#include "portable/mem_model.h"

extern void Cmp2DirtyToggle(void);
extern void TowerStageInitCluster(void);
extern void PhaseInstall2DInterpDispatch(void);
extern void Phase4ThreePackedInstallSelf(void);
extern void DivLongPushCall(void);
extern void ZeroThreeFields6c(void);
extern void ZeroThreeSlots_004ac010(void);
extern void GuardedChainCmpDualBitXor(void);
extern void MStackPushZeroCallPop_PendingMatch(void);
extern void PendingMatch_ThreeMul10Stores(void);
extern void ScaledClearJmp_EsiInstallBitCallChain(void);
extern void ArgSarStoreJmp(int);
extern void StackPopDispatchTagged(void);
extern void ScaledAndAlfe(void);
extern void FiveCallScaledChainTailJmp(void);
extern void Install3StateRouterTail(void);
extern void ChainNodeAdvanceCallback(void);
extern void Mul10Tail(unsigned int, unsigned int);
extern void BootMod6487eClampAndChainMul10(void);
void ArgScaledTestStore(int rec);

#define g_currentNodeIdx  (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_xformEntityIdx  (*(unsigned int *)MK4_VA(unsigned int, 0x542048u))
#define g_pendingNodeType (*(unsigned int *)MK4_VA(unsigned int, 0x54204cu))
#define g_slot50          (*(unsigned int *)MK4_VA(unsigned int, 0x542050u))
#define g_slot54          (*(unsigned int *)MK4_VA(unsigned int, 0x542054u))
#define g_slot58          (*(unsigned int *)MK4_VA(unsigned int, 0x542058u))
#define g_baseSel         (*(unsigned int *)MK4_VA(unsigned int, 0x542060u))
#define g_walkSlot6c      (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_slot70          (*(unsigned int *)MK4_VA(unsigned int, 0x542070u))
#define g_slot74          (*(unsigned int *)MK4_VA(unsigned int, 0x542074u))
#define g_slot78          (*(unsigned int *)MK4_VA(unsigned int, 0x542078u))
#define g_slot7c          (*(unsigned int *)MK4_VA(unsigned int, 0x54207cu))
#define g_slot80          (*(unsigned int *)MK4_VA(unsigned int, 0x542080u))
#define g_slot84          (*(unsigned int *)MK4_VA(unsigned int, 0x542084u))
#define g_slot88          (*(unsigned int *)MK4_VA(unsigned int, 0x542088u))
#define g_scratch94       (*(unsigned int *)MK4_VA(unsigned int, 0x542094u))
#define g_scratch98       (*(unsigned int *)MK4_VA(unsigned int, 0x542098u))
#define g_groupHead       (*(unsigned int *)MK4_VA(unsigned int, 0x54205cu))
#define g_framePauseFlag  (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_matrixStackTop  (*(unsigned int *)MK4_VA(unsigned int, 0x4d57acu))
#define g_stateBits8c     (*(unsigned int *)MK4_VA(unsigned int, 0x54208cu))
#define g_camRecIdx       (*(unsigned int *)MK4_VA(unsigned int, 0x52ab10u))
#define g_camAimX         (*(unsigned int *)MK4_VA(unsigned int, 0x52ab04u))
#define g_camAimZ         (*(unsigned int *)MK4_VA(unsigned int, 0x52ab08u))
#define g_tickFlagF       (*(unsigned int *)MK4_VA(unsigned int, 0x52aac4u))
#define g_p1NodeIdxG      (*(unsigned int *)MK4_VA(unsigned int, 0x538158u))
#define g_p2NodeIdxG      (*(unsigned int *)MK4_VA(unsigned int, 0x53815cu))
#define g_axisPosX        (*(unsigned int *)MK4_VA(unsigned int, 0x535e78u))
#define g_axisPosY        (*(unsigned int *)MK4_VA(unsigned int, 0x535e7cu))
#define g_progress535ddc  (*(unsigned int *)MK4_VA(unsigned int, 0x535ddcu))
#define g_bit53a7b4       (*(unsigned int *)MK4_VA(unsigned int, 0x53a7b4u))
#define g_dist541d68      (*(unsigned int *)MK4_VA(unsigned int, 0x541d68u))
#define g_saved541dc4     (*(unsigned int *)MK4_VA(unsigned int, 0x541dc4u))
#define g_camAngle4d517c  (*(unsigned int *)MK4_VA(unsigned int, 0x4d517cu))
#define g_stageArm53a3cc  (*(unsigned int *)MK4_VA(unsigned int, 0x53a3ccu))
#define g_byte538148      (*(unsigned char *)MK4_VA(unsigned char, 0x538148u))
#define g_stage53a51c     (*(unsigned int *)MK4_VA(unsigned int, 0x53a51cu))
#define g_atanTbl         (*(unsigned int *)MK4_VA(unsigned int, 0x542030u))
#define g_quadTbl         (*(unsigned int *)MK4_VA(unsigned int, 0x542034u))
#define g_loopSpent       (*(unsigned int *)MK4_VA(unsigned int, 0x53a1acu))

#define BAM_FULL 0x6487eu               /* 2*pi in 16.16 */

static int wt_fixmul16(int a, int b)
{
    return (int)(((long long)a * b) >> 16);
}

static int wt_fixdiv16(int num, int den)
{
    if (den == 0)
        return 0;
    return (int)(((long long)num << 16) / den);
}

static unsigned int mstack_push(unsigned int v)
{
    unsigned int top = g_matrixStackTop + 1;

    g_matrixStackTop = top;
    *(unsigned int *)MK4_PTR(top * 4) = v;
    return top;
}

static unsigned int mstack_pop(void)
{
    unsigned int top = g_matrixStackTop;
    unsigned int v = *(unsigned int *)MK4_PTR(top * 4);

    g_matrixStackTop = top - 1;
    return v;
}

/* BulkSlotInit - 0x004311e0 (127b): zero the camera record's 0x54..0x80. */
void BulkSlotInit(void)
{
    unsigned int cam = g_camRecIdx;
    static const unsigned char off[] = {0x54,0x58,0x5c,0x6c,0x70,0x74,
                                        0x60,0x64,0x68,0x78,0x7c,0x80};
    int i;

    g_currentNodeIdx = cam;
    g_walkSlot6c = 0;
    for (i = 0; i < 12; i++)
        MK4_NODE_AT(unsigned int, cam, off[i]) = 0;
}

/* LoadStoreScaled58 - 0x004314d0 (29b) */
void LoadStoreScaled58(void)
{
    g_groupHead = g_camRecIdx;
    g_walkSlot6c = 0xfffe8000u;
    MK4_NODE_AT(unsigned int, g_camRecIdx, 0x58) = 0xfffe8000u;
}

/* Atan2QuadrantLookup - 0x004245b0 (390b): BAM atan2 of the vec in
 * (0x542074, 0x542078). Octant from the signs and the axis-magnitude
 * swap; ratio = |min<<16/max| >> 7 indexes the table at [0x542030]; the
 * pair table at [0x542034] gives sign + offset per octant. Result to
 * 0x54206c; the 70/7c/44 staging words are mstack-bracketed. */
void Atan2QuadrantLookup(void)
{
    int x, y, oct, big, small, ratio, base, ang;
    unsigned int save44;

    mstack_push(g_slot70);
    mstack_push(g_slot7c);
    save44 = g_currentNodeIdx;
    mstack_push(save44);

    x = (int)g_slot74;
    y = (int)g_slot78;
    oct = (x < 0 ? 2 : 0) + (y < 0 ? 4 : 0);
    g_slot7c = (unsigned int)oct;
    big = x < 0 ? -x : x;
    small = y < 0 ? -y : y;
    if (small > big) {
        int t = big; big = small; small = x;
        (void)t;
        g_slot70 = (unsigned int)big;
        oct += 1;
        g_slot7c = (unsigned int)oct;
        ratio = wt_fixdiv16(x, (int)((y < 0) ? -y : y) == 0 ? 1 : (y < 0 ? -y : y));
        /* faithful form below - the swap means num = x, den = |y| */
        ratio = big == 0 ? 0 : wt_fixdiv16(x, big);
    } else {
        g_slot70 = (unsigned int)big;
        ratio = big == 0 ? 0 : wt_fixdiv16(y, big);
    }
    if (ratio < 0)
        ratio = -ratio;
    g_walkSlot6c = (unsigned int)(ratio << 9);
    ratio = (ratio << 9) >> 16;
    base = (int)g_atanTbl + ratio;
    g_currentNodeIdx = (unsigned int)base;
    ang = (int)*(unsigned int *)MK4_PTR((unsigned int)base * 4);
    g_walkSlot6c = (unsigned int)ang;

    {
        unsigned int q = g_quadTbl + (unsigned int)(oct * 2);
        g_currentNodeIdx = q;
        if ((int)*(unsigned int *)MK4_PTR(q * 4) < 0) {
            ang = -ang;
            g_walkSlot6c = (unsigned int)ang;
        }
        g_currentNodeIdx = q + 1;
        ang += (int)*(unsigned int *)MK4_PTR((q + 1) * 4);
        g_walkSlot6c = (unsigned int)ang;
    }

    g_currentNodeIdx = mstack_pop();
    g_slot7c = mstack_pop();
    g_slot70 = mstack_pop();
}

/* DualChainSubCallSubLoad - 0x00431c80 (112b): angle from the camera
 * record to the node in 0x542044, then mirrored (0x1921f - a). */
void DualChainSubCallSubLoad(void)
{
    unsigned int cam = g_camRecIdx, node = g_currentNodeIdx;
    int cx, cz;

    g_xformEntityIdx = cam;
    cx = (int)MK4_NODE_AT(unsigned int, cam, 0x54);
    g_walkSlot6c = (unsigned int)cx;
    cz = (int)MK4_NODE_AT(unsigned int, cam, 0x5c);
    g_slot70 = (unsigned int)cz;
    g_slot74 = MK4_NODE_AT(unsigned int, node, 0x54);
    g_slot74 = (unsigned int)((int)MK4_NODE_AT(unsigned int, node, 0x54) - cx);
    g_slot78 = (unsigned int)((int)MK4_NODE_AT(unsigned int, node, 0x5c) - cz);
    Atan2QuadrantLookup();
    if (g_framePauseFlag != 0)
        return;
    g_walkSlot6c = (unsigned int)(0x1921f - (int)g_walkSlot6c);
}

/* MStackSignedMod - 0x0042fee0 (184b): angle delta to the node's +0x64
 * heading, wrapped into [0, 2*pi) and folded to |delta| about pi. */
void MStackSignedMod(void)
{
    int a;

    mstack_push(g_slot70);
    mstack_push(g_slot74);
    DualChainSubCallSubLoad();
    if (g_framePauseFlag != 0)
        return;                     /* abort: the pushes leak */
    a = (int)g_walkSlot6c - (int)MK4_NODE_AT(unsigned int, g_xformEntityIdx, 0x64);
    if (a < (int)0xfffcdbc1)        /* < -2*pi + something: wrap up */
        a += (int)BAM_FULL;
    g_slot70 = 0;
    if (a >= 0x3243f) {             /* > pi: fold */
        g_slot70 = BAM_FULL;
        a -= (int)BAM_FULL;
    }
    g_walkSlot6c = (unsigned int)a;
    if (a < 0)
        g_walkSlot6c = (unsigned int)(-a);
    g_slot74 = mstack_pop();
    g_slot70 = mstack_pop();
}

/* LoadSetCallPauseStoreJmp - 0x0042fea0 (64b): heading deltas for P2
 * then P1 (results in 0x54206c / carried 0x542070). */
void LoadSetCallPauseStoreJmp(void)
{
    g_slot74 = 0x4ccc;
    g_currentNodeIdx = g_p2NodeIdxG;
    MStackSignedMod();
    if (g_framePauseFlag != 0)
        return;
    g_slot70 = g_walkSlot6c;
    g_currentNodeIdx = g_p1NodeIdxG;
    MStackSignedMod();                  /* jmp in the original */
}

/* PoseBlendDriver - 0x0042fc80 (544b): turn the node toward the camera
 * heading - nudge the position along the fight axis by 0.1, re-measure
 * the angle delta, restore the position, then blend the axis into the
 * node's +0x6c/+0x74 with weight |delta - 0.3| * (1/3.58) clamped to
 * at least 0.03, sign-picked by whether the nudge helped. */
void PoseBlendDriver(void)
{
    unsigned int node;
    int before, after, w, wx, wy;
    int sx, sz;

    MStackSignedMod();
    if (g_framePauseFlag != 0)
        return;
    before = (int)g_walkSlot6c;
    mstack_push((unsigned int)before);

    node = g_groupHead;
    g_slot7c = MK4_NODE_AT(unsigned int, node, 0x54);
    g_slot80 = MK4_NODE_AT(unsigned int, node, 0x5c);
    g_walkSlot6c = g_axisPosX;
    g_slot70 = g_axisPosY;
    sx = wt_fixmul16(0x1999, (int)g_axisPosX);
    g_walkSlot6c = (unsigned int)sx;
    sz = wt_fixmul16(0x1999, (int)g_axisPosY);
    g_slot70 = (unsigned int)sz;

    g_slot74 = MK4_NODE_AT(unsigned int, node, 0x54);
    g_slot74 = (unsigned int)((int)MK4_NODE_AT(unsigned int, node, 0x54) + sx);
    g_slot78 = (unsigned int)((int)MK4_NODE_AT(unsigned int, node, 0x5c) + sz);
    MK4_NODE_AT(unsigned int, node, 0x54) = g_slot74;
    MK4_NODE_AT(unsigned int, g_groupHead, 0x5c) = g_slot78;

    MStackSignedMod();
    if (g_framePauseFlag != 0)
        return;
    after = (int)g_walkSlot6c;
    before = (int)mstack_pop();
    g_slot70 = (unsigned int)before;
    /* setg dl; dec; and 0x20000; + 0xffff0000: helped -> +1.0, else -1.0
     * expressed as 0x10000 / 0xffff0000 */
    g_slot74 = (after > before) ? 0x10000u : 0xffff0000u;

    node = g_groupHead;
    MK4_NODE_AT(unsigned int, node, 0x54) = g_slot7c;
    MK4_NODE_AT(unsigned int, g_groupHead, 0x5c) = g_slot80;

    w = after - 0x4ccc;
    g_slot78 = (unsigned int)w;
    if (w < 0) {
        w = -w;
        g_slot78 = (unsigned int)w;
    }
    w = wt_fixmul16(0x44924, w);
    g_slot78 = (unsigned int)w;
    if (w < 0x7ae) {
        w = 0x7ae;
        g_slot78 = (unsigned int)w;
    }
    g_slot7c = g_axisPosX;
    g_slot80 = g_axisPosY;
    wx = wt_fixmul16(w, (int)g_axisPosX);
    g_slot7c = (unsigned int)wx;
    wy = wt_fixmul16((int)g_slot80, w);
    g_slot80 = (unsigned int)wy;
    wx = wt_fixmul16((int)g_slot74, wx);
    g_slot7c = (unsigned int)wx;
    wy = wt_fixmul16((int)g_slot80, (int)g_slot74);
    g_slot80 = (unsigned int)wy;
    node = g_groupHead;
    MK4_NODE_AT(unsigned int, node, 0x6c) = (unsigned int)wx;
    MK4_NODE_AT(unsigned int, g_groupHead, 0x74) = (unsigned int)wy;
}

/* Distance2DSaturationClamp - 0x004300a0 (312b): squared distance from
 * the aim point to the node; far -> pull the height to -1.5 and stop
 * (or keep 0x7ae rise); near -> rise picked by the lower player. */
void Distance2DSaturationClamp(void)
{
    unsigned int node = g_groupHead;
    int ax = (int)g_camAimX, az = (int)g_camAimZ;
    int dx, dz, d2, h;

    g_walkSlot6c = (unsigned int)ax;
    g_slot70 = (unsigned int)az;
    dx = (int)MK4_NODE_AT(unsigned int, node, 0x54) - ax;
    g_slot74 = (unsigned int)dx;
    dz = (int)MK4_NODE_AT(unsigned int, node, 0x5c) - az;
    g_slot78 = (unsigned int)dz;
    d2 = wt_fixmul16(dx, dx);
    g_slot74 = (unsigned int)d2;
    d2 += wt_fixmul16(dz, dz);
    g_slot78 = (unsigned int)d2;

    if (d2 <= 0x370000) {
        int h1, h2;
        g_currentNodeIdx = g_p1NodeIdxG;
        g_xformEntityIdx = g_p2NodeIdxG;
        h1 = (int)MK4_NODE_AT(unsigned int, g_p1NodeIdxG, 0x58);
        g_walkSlot6c = (unsigned int)h1;
        h2 = (int)MK4_NODE_AT(unsigned int, g_p2NodeIdxG, 0x58);
        g_slot70 = (unsigned int)h2;
        if (h1 > h2) {
            h1 = h2;
            g_walkSlot6c = (unsigned int)h1;
        }
        if (h1 <= (int)0xfffe0000) {
            node = g_groupHead;
            g_walkSlot6c = 0xfffff852u;
            h = (int)MK4_NODE_AT(unsigned int, node, 0x58);
            g_slot70 = (unsigned int)h;
            if (h < (int)0xfffe3334) {
                g_walkSlot6c = 0;
                MK4_NODE_AT(unsigned int, node, 0x70) = 0;
            } else {
                MK4_NODE_AT(unsigned int, node, 0x70) = 0xfffff852u;
            }
            return;
        }
    }
    node = g_groupHead;
    h = (int)MK4_NODE_AT(unsigned int, node, 0x58);
    g_slot70 = (unsigned int)h;
    if (h >= (int)0xfffe8000) {
        MK4_NODE_AT(unsigned int, node, 0x58) = 0xfffe8000u;
        g_walkSlot6c = 0;
        MK4_NODE_AT(unsigned int, g_groupHead, 0x70) = 0;
    } else {
        g_walkSlot6c = 0x7ae;
        MK4_NODE_AT(unsigned int, node, 0x70) = 0x7ae;
    }
}

/* CameraAimSplineDriver - 0x00430e60 (599b): the aim-point chooser.
 * Look-ahead = clamp(progress * 1.7625, [7.05, 10.5]); the two
 * candidates are aim +/- lookahead along the (0x53a7b4, 0x541d68)
 * direction; keep the FARTHER one from the node, then the BAM angle
 * from the kept point steers +0x64 through the wrap clamp. */
void CameraAimSplineDriver(void)
{
    unsigned int node;
    int la, dirx, dirz, px, pz, nx, nz, d1, d2;
    int cx, cz;

    mstack_push(g_slot84);
    mstack_push(g_slot88);

    g_walkSlot6c = g_progress535ddc;
    la = wt_fixmul16(0x1c333, (int)g_progress535ddc);
    g_walkSlot6c = (unsigned int)la;
    if (la < 0x70ccc) { la = 0x70ccc; g_walkSlot6c = (unsigned int)la; }
    if (la > 0xa8000) { la = 0xa8000; g_walkSlot6c = (unsigned int)la; }

    g_slot70 = g_bit53a7b4;
    g_slot74 = g_dist541d68;
    dirx = wt_fixmul16(la, (int)g_bit53a7b4);
    g_slot70 = (unsigned int)dirx;
    dirz = wt_fixmul16((int)g_dist541d68, la);

    px = (int)g_camAimX + dirx;
    pz = (int)g_camAimZ + dirz;
    g_slot7c = (unsigned int)px;
    g_slot80 = (unsigned int)pz;
    g_slot70 = (unsigned int)(-dirx);
    g_slot74 = (unsigned int)(-dirz);
    cx = (int)g_camAimX - dirx;
    cz = (int)g_camAimZ - dirz;
    g_walkSlot6c = (unsigned int)cx;
    g_slot78 = (unsigned int)cz;

    node = g_groupHead;
    nx = (int)MK4_NODE_AT(unsigned int, node, 0x54);
    g_slot70 = (unsigned int)nx;
    nz = (int)MK4_NODE_AT(unsigned int, node, 0x5c);
    g_slot70 = (unsigned int)(nx - px);
    g_slot74 = (unsigned int)(nz - pz);
    d1 = wt_fixmul16(nx - px, nx - px);
    g_slot70 = (unsigned int)d1;
    d1 += wt_fixmul16(nz - pz, nz - pz);
    g_slot74 = (unsigned int)d1;

    node = g_groupHead;
    nx = (int)MK4_NODE_AT(unsigned int, node, 0x54);
    g_slot70 = (unsigned int)nx;
    nz = (int)MK4_NODE_AT(unsigned int, node, 0x5c);
    g_slot70 = (unsigned int)(nx - cx);
    g_slot84 = (unsigned int)(nz - cz);
    d2 = wt_fixmul16(nx - cx, nx - cx);
    g_slot70 = (unsigned int)d2;
    d2 += wt_fixmul16(nz - cz, nz - cz);
    g_slot84 = (unsigned int)d2;

    if (d1 > d2) {                   /* keep the farther candidate */
        g_slot7c = g_walkSlot6c;     /* cx */
        g_slot80 = g_slot78;         /* cz */
    }
    g_slot74 = (unsigned int)((int)g_camAimX - (int)g_slot7c);
    g_slot78 = (unsigned int)((int)g_camAimZ - (int)g_slot80);
    Atan2QuadrantLookup();
    if (g_framePauseFlag != 0)
        return;                      /* abort: the pushes leak */
    {
        int a = (int)g_walkSlot6c + (int)0xfffe6de1;
        g_slot70 = (unsigned int)a;
        g_walkSlot6c = (unsigned int)((int)g_camAngle4d517c - a);
        BootMod6487eClampAndChainMul10();
        if (g_framePauseFlag != 0)
            return;
    }
    g_slot88 = mstack_pop();
    g_slot84 = mstack_pop();
}

/* MStackPush4DualCallAbsPop4 - 0x00430d30 (289b): bracketed heading
 * delta - aim spline, wrap both headings, |difference| into 0x542078. */
void MStackPush4DualCallAbsPop4(void)
{
    int a, b;

    mstack_push(g_slot80);
    mstack_push(g_walkSlot6c);
    mstack_push(g_slot70);
    mstack_push(g_slot74);
    CameraAimSplineDriver();
    if (g_framePauseFlag != 0)
        return;
    BootMod6487eClampAndChainMul10();
    if (g_framePauseFlag != 0)
        return;
    a = (int)g_walkSlot6c;
    g_slot70 = (unsigned int)a;
    g_walkSlot6c = MK4_NODE_AT(unsigned int, g_groupHead, 0x64);
    BootMod6487eClampAndChainMul10();
    if (g_framePauseFlag != 0)
        return;
    b = (int)g_walkSlot6c - a;
    g_walkSlot6c = (unsigned int)b;
    g_slot78 = (unsigned int)b;
    if (b < 0)
        g_slot78 = (unsigned int)(-b);
    g_slot74 = mstack_pop();
    g_slot70 = mstack_pop();
    g_walkSlot6c = mstack_pop();
    g_slot80 = mstack_pop();
}

/* StoreByteJmp - 0x0042f840 (12b) */
void StoreByteJmp(void)
{
    g_byte538148 = 0;
    Phase4ThreePackedInstallSelf();  /* jmp in the original */
}

/* DispatchOrInitFightGroup - 0x0042f850 (69b) */
void DispatchOrInitFightGroup(void)
{
    g_walkSlot6c = g_tickFlagF;
    if (g_tickFlagF == 2) {
        StoreByteJmp();              /* jmp in the original */
        return;
    }
    g_groupHead = g_camRecIdx;
    CameraAimSplineDriver();
    if (g_framePauseFlag != 0)
        return;
    MK4_NODE_AT(unsigned int, g_baseSel, 0x64) = g_walkSlot6c;
    PhaseInstall2DInterpDispatch();  /* jmp in the original */
}

/* StackPeekDispatchIndirect - 0x004304e0 (119b): pop the parked value;
 * bit 0 of the state -> park it in 0x541dc4 and enter the tower init,
 * else append it to the camera event queue and jump through 0x542048. */
void StackPeekDispatchIndirect(void)
{
    unsigned int v, q;

    Cmp2DirtyToggle();
    if (g_framePauseFlag != 0)
        return;
    v = mstack_pop();
    if ((g_stateBits8c & 1) != 0) {
        g_saved541dc4 = v;
        TowerStageInitCluster();     /* jmp in the original */
        return;
    }
    g_pendingNodeType = v;
    q = MK4_NODE_AT(unsigned int, g_baseSel, 4);
    g_currentNodeIdx = q;
    *(unsigned int *)MK4_PTR(q * 4) = v;
    g_currentNodeIdx = q + 1;
    MK4_NODE_AT(unsigned int, g_baseSel, 4) = q + 1;
    ((void (*)(void))MK4_ResolveCode(g_xformEntityIdx))();
}

/* the fight-group init entry at 0x430430 (packed in WalkTowardTargetFsm) */
void FightGroupInit_00430430(void)
{
    unsigned int slot;

    g_walkSlot6c = 0x12;
    MK4_NODE_AT(unsigned int, g_baseSel, 0xc) = 0x12;
    BulkSlotInit();
    if (g_framePauseFlag != 0)
        return;
    LoadStoreScaled58();
    if (g_framePauseFlag != 0)
        return;
    g_walkSlot6c = g_stage53a51c;
    slot = (0x4e3a30u >> 2) + g_stage53a51c;
    g_xformEntityIdx = slot;
    g_xformEntityIdx = *(unsigned int *)MK4_PTR(slot * 4);
#ifdef TARGET_SDL
    /* MK4_ARENA_INTRO=1 arms the per-stage camera intro (arena_intro_band.c).
     * It animates the camera correctly - a radius-7 arc with a decaying
     * spin - but the scene ends up out of frame, so the default keeps the
     * previous static viewpoint rather than regressing to a black screen.
     * See the fight-scene status note. */
    { extern char *getenv(const char *);
      if (!getenv("MK4_ARENA_INTRO")) g_xformEntityIdx = 0; }
    /* MK4_TRACE_INTRO: which stage index the fight picked and which intro
     * entry the table at 0x4e3a30 hands it. */
    { extern void SDL_Log(const char *, ...); extern char *getenv(const char *);
      static int f = -1; static int n;
      if (f < 0) f = getenv("MK4_TRACE_INTRO") != 0;
      if (f && n < 4) { n++;
          SDL_Log("INTRO stage=%u entry=%x", g_stage53a51c, g_xformEntityIdx); } }
#endif
    mstack_push(0x4304b0u);
    StackPeekDispatchIndirect();     /* jmp in the original */
}

/* the parked continuation at 0x4304b0 */
void FightGroupCont_004304b0(void)
{
    unsigned int cam = g_camRecIdx;

    g_stageArm53a3cc = 1;
    g_groupHead = cam;
    g_walkSlot6c = 0;
    MK4_NODE_AT(unsigned int, cam, 0x64) = 0;
    DispatchOrInitFightGroup();      /* jmp in the original */
}

/* WalkTowardTargetFsm - 0x004301e0 (760b): the camera walk-in driver.
 * cmd 0: measure and park; cmd 1: turn both players toward each other
 * (PoseBlendDriver when the delta says so), track the aim, count 10
 * frames of near-convergence, then hand the camera the follow state
 * (+0x34 mode, +0x38 = -1.5, +0x3c = countdown, type 0x28) and queue
 * its own tagged continuation; cmd 2+: DispatchOrInitFightGroup. */
void WalkTowardTargetFsm(void)
{
    unsigned int cam = g_baseSel;
    unsigned int cmd, q;
    int d;

    cmd = MK4_NODE_AT(unsigned int, cam, 0x84);
    MK4_NODE_AT(unsigned int, cam, 0x84) = 0;

    if (cmd == 0) {
        g_slot80 = 0xa;
        MStackPush4DualCallAbsPop4();
        if (g_framePauseFlag != 0)
            return;
        g_slot88 = g_slot78;
        MK4_NODE_AT(unsigned int, cam, 8) = 0x4301e0u;
        MK4_NODE_AT(unsigned int, cam, 0x84) = 1;
        g_pendingNodeType = 1;
        g_framePauseFlag = 1;
        return;
    }
    if (cmd != 1) {
        DispatchOrInitFightGroup();
        return;
    }

    mstack_push(g_slot80);
    LoadSetCallPauseStoreJmp();
    if (g_framePauseFlag != 0)
        return;
    if ((int)g_walkSlot6c > (int)g_slot74) {
        g_currentNodeIdx = g_p1NodeIdxG;
        PoseBlendDriver();
        if (g_framePauseFlag != 0)
            return;
    }
    LoadSetCallPauseStoreJmp();
    if (g_framePauseFlag != 0)
        return;
    if ((int)g_slot70 > (int)g_slot74) {
        g_currentNodeIdx = g_p2NodeIdxG;
        PoseBlendDriver();
        if (g_framePauseFlag != 0)
            return;
    }
    g_slot80 = mstack_pop();
    Distance2DSaturationClamp();
    if (g_framePauseFlag != 0)
        return;
    MStackPush4DualCallAbsPop4();
    if (g_framePauseFlag != 0)
        return;

    d = (int)g_slot78 - (int)g_slot88;
    g_slot70 = (unsigned int)d;
    if (d < 0) {
        d = -d;
        g_slot70 = (unsigned int)d;
    }
    g_slot74 = 0xc4;
    if (d > 0xc4)
        g_slot80 = 0xa;              /* still moving: reset the counter */
    g_slot80 -= 1;
    if (g_slot80 != 0) {
        g_slot88 = g_slot78;
        MK4_NODE_AT(unsigned int, cam, 8) = 0x4301e0u;
        MK4_NODE_AT(unsigned int, cam, 0x84) = 1;
        g_pendingNodeType = 1;
        g_framePauseFlag = 1;
        return;
    }

    /* converged: switch the camera to follow mode */
    CameraAimSplineDriver();
    if (g_framePauseFlag != 0)
        return;
    MK4_NODE_AT(unsigned int, g_baseSel, 0x44) = g_walkSlot6c;
    MK4_NODE_AT(unsigned int, g_baseSel, 0x34) = g_slot7c;
    MK4_NODE_AT(unsigned int, g_baseSel, 0x3c) = g_slot80;
    g_slot7c = 0xfffe8000u;
    MK4_NODE_AT(unsigned int, g_baseSel, 0x38) = 0xfffe8000u;
    g_walkSlot6c = 0;
    MK4_NODE_AT(unsigned int, g_baseSel, 0x40) = 0;
    MK4_NODE_AT(unsigned int, g_baseSel, 0x48) = g_walkSlot6c;
    g_walkSlot6c = 0x28;
    MK4_NODE_AT(unsigned int, g_baseSel, 0x30) = 0x28;
    MK4_NODE_AT(unsigned int, cam, 8) = 0x4301e0u;
    MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 2;
    q = MK4_NODE_AT(unsigned int, cam, 4);
    g_currentNodeIdx = q;
    *(unsigned int *)MK4_PTR(q * 4) = 0x4301e0u + 0x2000000u;
    g_currentNodeIdx = q + 1;
    MK4_NODE_AT(unsigned int, cam, 4) = q + 1;
    MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 0;
    PendingMatch_ThreeMul10Stores();
    g_framePauseFlag = 1;
}

/* GroupAnimListPump_00408de0 (packed in BootStateTriple): advance every
 * bone track in the node's +0x1c list unless kind bit 0xb is set. */
void GroupAnimListPump_00408de0(void)
{
    unsigned int node = g_currentNodeIdx;
    unsigned int list, cnt, entry;

    list = MK4_NODE_AT(unsigned int, node, 0x1c);
    if (list != 0) {
        g_groupHead = list;
        if ((MK4_NODE_AT(unsigned int, node, 0x34) & 0x800) == 0) {
            cnt = *(unsigned int *)MK4_PTR(list * 4);
            list += 1;
            g_groupHead = list;
            while ((int)--cnt >= 0) {
                g_groupHead = list;
                entry = *(unsigned int *)MK4_PTR(list * 4);
                list += 1;
                g_groupHead = list;
                if ((int)entry > 0) {
                    g_currentNodeIdx = entry;
                    g_xformEntityIdx = MK4_NODE_AT(unsigned int, entry, 0x28);
                    if (g_xformEntityIdx != 0) {
                        ChainNodeAdvanceCallback();
                        if (g_framePauseFlag != 0)
                            return;
                    }
                }
            }
        }
    }
    g_stateBits8c &= ~1u;
}

/* StateRemapPackedInstall - 0x0046b360 (374b, three entries): the head
 * remaps camera type 0x10/0x11 to set index 2/7 and applies the arg
 * record 0x542a70 (unless type 0xf); the FSM at 0x46b3b0 arms the +0x74
 * mode, applies 0x542a78, hangs the 0x5019d0 set off the group's +0x24,
 * queues its own tagged VA and runs the install chain; the tail at
 * 0x46b490 re-runs the five-call chain then re-applies by type. */
void StateRemapPackedInstall(void)
{
    unsigned int t;

    g_xformEntityIdx = 0x5019d0u >> 2;
    t = MK4_NODE_AT(unsigned int, g_baseSel, 0x34);
    g_walkSlot6c = t;
    if (t == 0x10) { t = 2; g_walkSlot6c = 2; }
    if (t == 0x11) { t = 7; g_walkSlot6c = 7; }
    if (t != 0xf)
        ArgScaledTestStore(0x542a70);
}

void StateRemapFsm_0046b3b0(void)
{
    unsigned int cam = g_baseSel;
    unsigned int cmd, q;

    cmd = MK4_NODE_AT(unsigned int, cam, 0x84);
    MK4_NODE_AT(unsigned int, cam, 0x84) = 0;
    if (cmd != 0) {
        StackPopDispatchTagged();    /* jmp in the original */
        return;
    }
    g_walkSlot6c = 0x2002;
    MK4_NODE_AT(unsigned int, g_baseSel, 0x74) = 0x2002;
    ScaledAndAlfe();
    if (g_framePauseFlag != 0)
        return;
    ArgScaledTestStore(0x542a78);
    if (g_framePauseFlag != 0)
        return;
    MK4_NODE_AT(unsigned int, g_groupHead, 0x24) = g_xformEntityIdx;
    MK4_NODE_AT(unsigned int, cam, 8) = 0x46b3b0u;
    MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 1;
    q = MK4_NODE_AT(unsigned int, cam, 4);
    g_currentNodeIdx = q;
    *(unsigned int *)MK4_PTR(q * 4) = 0x46b3b0u + 0x1000000u;
    g_currentNodeIdx = q + 1;
    MK4_NODE_AT(unsigned int, cam, 4) = q + 1;
    MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 0;
    ScaledClearJmp_EsiInstallBitCallChain();
    g_framePauseFlag = 1;
}

void StateRemapTail_0046b490(void)
{
    unsigned int t;

    FiveCallScaledChainTailJmp();
    if (g_framePauseFlag != 0)
        return;
    t = MK4_NODE_AT(unsigned int, g_baseSel, 0x34);
    g_walkSlot6c = t;
    if (t == 0x11) { t = 7; g_walkSlot6c = 7; }
    if (t == 0xf) {
        Install3StateRouterTail();   /* jmp in the original */
        return;
    }
    ArgSarStoreJmp(0x4eaee0);
}

/* PendingMatch_ZeroThreeFields6c_then_ZeroThreeSlots - 0x004326a0 (108b) */
void PendingMatch_ZeroThreeFields6c_then_ZeroThreeSlots(void)
{
    unsigned int cam = g_baseSel, node = g_groupHead;
    static const unsigned char src[] = {0x34,0x38,0x3c,0x40,0x44,0x48};
    static const unsigned char dst[] = {0x54,0x58,0x5c,0x60,0x64,0x68};
    int i;

    for (i = 0; i < 6; i++) {
        unsigned int v = MK4_NODE_AT(unsigned int, cam, src[i]);
        g_walkSlot6c = v;
        MK4_NODE_AT(unsigned int, node, dst[i]) = v;
    }
    ZeroThreeFields6c();
    if (g_framePauseFlag != 0)
        return;
    ZeroThreeSlots_004ac010();       /* jmp in the original */
}

/* EsiInstallClampAddCall - 0x0048fe40 (158b): ramp 0x542088 toward 1.0
 * by 0x542084 per visit; at 1.0 dispatch the parked queue entry. */
void EsiInstallClampAddCall(void)
{
    unsigned int cam = g_baseSel;
    unsigned int cmd;
    int v;

    cmd = MK4_NODE_AT(unsigned int, cam, 0x84);
    MK4_NODE_AT(unsigned int, cam, 0x84) = 0;
    if (cmd != 0) {
        if ((int)g_slot88 >= 0x10000) {
            StackPopDispatchTagged();
            return;
        }
        v = (int)g_slot88;
    } else {
        GuardedChainCmpDualBitXor();
        if (g_framePauseFlag != 0)
            return;
        v = 0;
    }
    v += (int)g_slot84;
    g_slot88 = (unsigned int)v;
    if (v >= 0x10000) {
        v = 0x10000;
        g_slot88 = 0x10000;
    }
    g_walkSlot6c = (unsigned int)v;
    g_slot70 = g_slot7c;
    MStackPushZeroCallPop_PendingMatch();
    if (g_framePauseFlag != 0)
        return;
    MK4_NODE_AT(unsigned int, cam, 8) = 0x48fe40u;
    MK4_NODE_AT(unsigned int, cam, 0x84) = 1;
    g_pendingNodeType = 1;
    g_framePauseFlag = 1;
}

/* TripleMod411262 - 0x00424740 (285b): wrap the vec3 at [0x542044]
 * into [0, 2*pi). */
void TripleMod411262(void)
{
    unsigned int base = g_currentNodeIdx;
    int i;

    for (i = 0; i < 3; i++) {
        int v = (int)*(unsigned int *)MK4_PTR((base + i) * 4);
        g_walkSlot6c = (unsigned int)v;
        while (v < 0)
            v += (int)BAM_FULL;
        while (v >= (int)BAM_FULL)
            v -= (int)BAM_FULL;
        g_walkSlot6c = (unsigned int)v;
        *(unsigned int *)MK4_PTR((base + i) * 4) = (unsigned int)v;
    }
}

/* DiffMul10Loop - 0x00432000 (264b): t = ((k - [pend]) << 16 + frac) /
 * span via DivLongPushCall, then dst[i] = src[i] * t for three words. */
void DiffMul10Loop(void)
{
    int v, i;

    v = (int)g_walkSlot6c - (int)*(unsigned int *)MK4_PTR(g_pendingNodeType * 4);
    g_walkSlot6c = (unsigned int)v;
    v -= (int)*(unsigned int *)MK4_PTR(g_slot50 * 4);
    v <<= 16;
    g_walkSlot6c = (unsigned int)v;
    v += (int)MK4_NODE_AT(unsigned int, g_pendingNodeType, 4);
    g_walkSlot6c = (unsigned int)v;
    v += (int)MK4_NODE_AT(unsigned int, g_slot50, 4);
    g_walkSlot6c = (unsigned int)v;
    DivLongPushCall();
    if (g_framePauseFlag != 0)
        return;
    for (i = 0; i < 3; i++) {
        int s = (int)*(unsigned int *)MK4_PTR(g_xformEntityIdx * 4);
        int r = wt_fixmul16((int)g_walkSlot6c, s);
        g_xformEntityIdx += 1;
        g_slot70 = (unsigned int)r;
        g_loopSpent = (unsigned int)(2 - i);
        *(unsigned int *)MK4_PTR(g_currentNodeIdx * 4) = (unsigned int)r;
        g_currentNodeIdx += 1;
    }
    g_currentNodeIdx -= 3;
    g_xformEntityIdx -= 4;           /* the original leaves ent one past */
}

/* TripleArrayDiffClamp - 0x004251f0 (207b): dst[i] = wrap-shortest
 * (src[i] - ref[i]) using the thresholds at 0x4d5320/24/28. */
void TripleArrayDiffClamp(void)
{
    int i;

    for (i = 0; i < 3; i++) {
        int a = (int)*(unsigned int *)MK4_PTR(g_xformEntityIdx * 4);
        int b = (int)*(unsigned int *)MK4_PTR(g_pendingNodeType * 4);
        int d = a - b, ad;
        int thr = (int)*MK4_VA(unsigned int, 0x4d5320u);
        int neg = (int)*MK4_VA(unsigned int, 0x4d5324u);
        int pos = (int)*MK4_VA(unsigned int, 0x4d5328u);

        g_xformEntityIdx += 1;
        g_pendingNodeType += 1;
        g_slot70 = (unsigned int)d;
        ad = d < 0 ? -d : d;
        g_scratch98 = (ad <= thr);
        g_walkSlot6c = (unsigned int)(d < 0 ? neg : pos);
        if (ad > thr) {
            d += (d < 0 ? neg : pos);
            g_slot70 = (unsigned int)d;
        }
        *(unsigned int *)MK4_PTR(g_currentNodeIdx * 4) = (unsigned int)d;
        g_currentNodeIdx += 1;
    }
    g_loopSpent = (unsigned int)-1;
    g_currentNodeIdx -= 3;
    g_xformEntityIdx -= 3;
    g_pendingNodeType -= 3;
}


/* ArgScaledTestStore - 0x00494140 (61b): rec arg is a VA; entity takes
 * rec[0], or rec[1] when the camera type at +0x30 is set. */
void ArgScaledTestStore(int rec)
{
    unsigned int r = ((unsigned int)rec) >> 2;
    unsigned int t;

    g_slot50 = r;
    t = MK4_NODE_AT(unsigned int, g_baseSel, 0x30);
    g_walkSlot6c = t;
    g_xformEntityIdx = *(unsigned int *)MK4_PTR(r * 4);
    if (t != 0)
        g_xformEntityIdx = MK4_NODE_AT(unsigned int, r, 4);
}

/* DivLongPushCall - 0x004ab320 (33b): 0x54206c = 0x10000 / x (signed),
 * 0 stays 0. */
void DivLongPushCall(void)
{
    int v = (int)g_walkSlot6c;

    if (v == 0)
        return;
    g_walkSlot6c = (unsigned int)(int)(0x100000000LL / v);
}

/* ScaledAndAlfe - 0x00490390 (28b) */
void ScaledAndAlfe(void)
{
    unsigned int v = MK4_NODE_AT(unsigned int, g_groupHead, 0x40) & ~1u;

    g_slot70 = v;
    MK4_NODE_AT(unsigned int, g_groupHead, 0x40) = v;
}

/* ScaledClearJmp_EsiInstallBitCallChain - 0x00428d60 (25b) */
extern void EsiInstallBitCallChain_CopyJmp_GuardedChainPushSetCallPop_g_currentNodeIdx_00429530(void);
void ScaledClearJmp_EsiInstallBitCallChain(void)
{
    g_walkSlot6c = 0;
    MK4_NODE_AT(unsigned int, g_groupHead, 0x28) = 0;
    EsiInstallBitCallChain_CopyJmp_GuardedChainPushSetCallPop_g_currentNodeIdx_00429530();
}

/* ZeroThreeFields6c - 0x004abfe0 (38b) */
void ZeroThreeFields6c(void)
{
    g_walkSlot6c = 0;
    MK4_NODE_AT(unsigned int, g_groupHead, 0x6c) = 0;
    MK4_NODE_AT(unsigned int, g_groupHead, 0x70) = 0;
    MK4_NODE_AT(unsigned int, g_groupHead, 0x74) = 0;
}

#endif /* NON_MATCHING */
