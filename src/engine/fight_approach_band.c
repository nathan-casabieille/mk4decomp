/**
 * The approach band - what DispatchOrInitFightGroup hands the frame to
 * once the arena intro is done, and the link whose absence made the
 * intro spin restart forever. With PhaseInstall2DInterpDispatch stubbed,
 * nothing ever replaced the spin's self-install on the camera node, so
 * the spin was re-dispatched from state 0 every time it finished,
 * resetting its own sweep. Everything downstream - the walk-in FSM, the
 * track installer, hence the poses - sat behind that loop.
 *
 * PhaseInstall2DInterpDispatch - 0x0042f8a0 (355b): on a command word of
 *   zero it just re-installs itself for one frame. Otherwise it runs the
 *   distance clamp, tests both fighters' +0x40 bit 6
 *   (ChainFieldTest2Branch), measures the heading deltas and the aim
 *   spline, and then routes on how far the pair still is:
 *     separation > 0xa3d      -> WalkTowardTargetFsm (the walk-in)
 *     distance   < 0x300000   -> EsiInstallChainCallCmpThreshold
 *     distance  >= 0x370000   -> pull the target in by 0x1999 and either
 *                                scale-store or sub-compare
 *     otherwise               -> Mul10Triple0xd999Interp (decay 0x6c /
 *                                0x74 by 0.85 and 0x7c by 0.6) or the
 *                                per-player sub-compare
 *
 * ChainFieldTest2Branch - 0x0042fbc0 (116b): if the node's +0x40 has bit
 *   6, take the heading delta to the OTHER fighter and route by whether
 *   it exceeds 0.3.
 * DualMul10ChainAcc7C - 0x00430020 (115b): squared 2D distance from the
 *   aim point to the group, left in 0x54207c.
 * EsiInstallChainCallCmpThreshold - 0x0042fad0 (163b): the settle state -
 *   while the distance stays under 0x300000 keep dispatching, else zero
 *   the group's +0x6c / +0x74 first.
 * Mul10Triple0xd999Interp - 0x0042fa10 (183b): decay the group's three
 *   velocity fields (0.85, 0.85, 0.6) and re-dispatch.
 * SubCmpCallPauseJmp - 0x0042fc40 (50b): step the threshold down 0xa3d
 *   and either scale-store or run PoseBlendDriver.
 *
 * NATIVE-ONLY twins: the matching build synthesizes the original bytes.
 */
#ifdef NON_MATCHING

#include "portable/mem_model.h"

extern void Distance2DSaturationClamp(void);
extern void LoadSetCallPauseStoreJmp(void);
extern void MStackPush4DualCallAbsPop4(void);
extern void WalkTowardTargetFsm(void);
extern void MStackSignedMod(void);
extern void PoseBlendDriver(void);
extern void DualMulScaleStore(void);
extern void GuardedSeq_DualMulScaleStore_then_PhaseInstall2DInterpDispatch_0042fb80(void);
extern void GuardedSeq_DualMulScaleStore_then_PhaseInstall2DInterpDispatch_0042fba0(void);

void PhaseInstall2DInterpDispatch(void);
void Mul10Triple0xd999Interp(void);
void SubCmpCallPauseJmp(void);
void DualMul10ChainAcc7C(void);
void EsiInstallChainCallCmpThreshold(void);

#define g_currentNodeIdx  (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_xformEntityIdx  (*(unsigned int *)MK4_VA(unsigned int, 0x542048u))
#define g_baseSel         (*(unsigned int *)MK4_VA(unsigned int, 0x542060u))
#define g_walkSlot6c      (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_slot70          (*(unsigned int *)MK4_VA(unsigned int, 0x542070u))
#define g_slot74          (*(unsigned int *)MK4_VA(unsigned int, 0x542074u))
#define g_slot78          (*(unsigned int *)MK4_VA(unsigned int, 0x542078u))
#define g_slot7c          (*(unsigned int *)MK4_VA(unsigned int, 0x54207cu))
#define g_slot80          (*(unsigned int *)MK4_VA(unsigned int, 0x542080u))
#define g_slot84          (*(unsigned int *)MK4_VA(unsigned int, 0x542084u))
#define g_scratch94       (*(unsigned int *)MK4_VA(unsigned int, 0x542094u))
#define g_groupHead       (*(unsigned int *)MK4_VA(unsigned int, 0x54205cu))
#define g_pendingNodeType (*(unsigned int *)MK4_VA(unsigned int, 0x54204cu))
#define g_framePauseFlag  (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_p1NodeIdxG      (*(unsigned int *)MK4_VA(unsigned int, 0x538158u))
#define g_p2NodeIdxG      (*(unsigned int *)MK4_VA(unsigned int, 0x53815cu))
#define g_camAimX         (*(unsigned int *)MK4_VA(unsigned int, 0x52ab04u))
#define g_camAimZ         (*(unsigned int *)MK4_VA(unsigned int, 0x52ab08u))

static int fa_fixmul16(int a, int b)
{
    return (int)(((long long)a * b) >> 16);
}

void DualMul10ChainAcc7C(void)
{
    unsigned int node = g_groupHead;
    int ax = (int)g_camAimX, az = (int)g_camAimZ;
    int dx, dz, d;

    g_slot78 = (unsigned int)ax;
    g_slot7c = (unsigned int)az;
    dx = (int)MK4_NODE_AT(unsigned int, node, 0x54);
    g_slot80 = (unsigned int)dx;
    dz = (int)MK4_NODE_AT(unsigned int, node, 0x5c);
    dx -= ax;
    dz -= az;
    g_slot80 = (unsigned int)dx;
    g_slot84 = (unsigned int)dz;
    d = fa_fixmul16(dx, dx);
    g_slot80 = (unsigned int)d;
    d = fa_fixmul16(dz, dz);
    g_slot84 = (unsigned int)d;
    g_slot7c = (unsigned int)(d + (int)g_slot80);
}

void Mul10Triple0xd999Interp(void)
{
    unsigned int node = g_groupHead;
    int a, b, c;

    g_walkSlot6c = 0xd999;
    a = (int)MK4_NODE_AT(unsigned int, node, 0x6c);
    g_slot70 = (unsigned int)a;
    b = (int)MK4_NODE_AT(unsigned int, node, 0x74);
    g_slot74 = (unsigned int)b;
    c = (int)MK4_NODE_AT(unsigned int, node, 0x7c);
    g_slot78 = (unsigned int)c;

    a = fa_fixmul16(0xd999, a);
    g_slot70 = (unsigned int)a;
    b = fa_fixmul16((int)g_walkSlot6c, b);
    g_slot74 = (unsigned int)b;
    c = fa_fixmul16(0x9999, c);
    g_slot78 = (unsigned int)c;

    MK4_NODE_AT(unsigned int, g_groupHead, 0x6c) = (unsigned int)a;
    MK4_NODE_AT(unsigned int, g_groupHead, 0x74) = (unsigned int)b;
    MK4_NODE_AT(unsigned int, g_groupHead, 0x7c) = (unsigned int)c;
    PhaseInstall2DInterpDispatch();      /* jmp in the original */
}

void SubCmpCallPauseJmp(void)
{
    int t = (int)g_slot74 - 0xa3d;

    g_slot74 = (unsigned int)t;
    if ((int)g_slot78 > t) {
        GuardedSeq_DualMulScaleStore_then_PhaseInstall2DInterpDispatch_0042fb80();
        return;
    }
    PoseBlendDriver();
    if (g_framePauseFlag != 0)
        return;
    PhaseInstall2DInterpDispatch();      /* jmp in the original */
}

void ChainFieldTest2Branch(void)
{
    unsigned int node = g_currentNodeIdx;
    unsigned int flags = MK4_NODE_AT(unsigned int, node, 0x40);

    g_walkSlot6c = flags;
    g_scratch94 = flags & 0x40;
    if (g_scratch94 == 0)
        return;
    g_xformEntityIdx = node;
    g_currentNodeIdx = g_p1NodeIdxG;
    if (node == g_p1NodeIdxG)
        g_currentNodeIdx = g_p2NodeIdxG;
    MStackSignedMod();
    if (g_framePauseFlag != 0)
        return;
    g_slot78 = 0;
    g_slot74 = 0x4ccc;
    if ((int)g_walkSlot6c > 0x4ccc) {
        SubCmpCallPauseJmp();            /* jmp in the original */
        return;
    }
    Mul10Triple0xd999Interp();           /* jmp in the original */
}

void EsiInstallChainCallCmpThreshold(void)
{
    unsigned int cam = g_baseSel;
    unsigned int cmd;

    cmd = MK4_NODE_AT(unsigned int, cam, 0x84);
    MK4_NODE_AT(unsigned int, cam, 0x84) = 0;

    if (cmd == 0) {
        DualMulScaleStore();
        if (g_framePauseFlag != 0)
            return;
        MK4_NODE_AT(unsigned int, cam, 8) = 0x42fad0u;
        MK4_NODE_AT(unsigned int, cam, 0x84) = 1;
        g_pendingNodeType = 1;
        g_framePauseFlag = 1;
        return;
    }
    DualMul10ChainAcc7C();
    if (g_framePauseFlag != 0)
        return;
    if ((int)g_slot7c >= 0x300000) {
        g_walkSlot6c = 0;
        MK4_NODE_AT(unsigned int, g_groupHead, 0x6c) = 0;
        MK4_NODE_AT(unsigned int, g_groupHead, 0x74) = g_walkSlot6c;
    }
    PhaseInstall2DInterpDispatch();
}

void PhaseInstall2DInterpDispatch(void)
{
    unsigned int cam = g_baseSel;
    unsigned int cmd;
    int d, lim, a, b, c;

    cmd = MK4_NODE_AT(unsigned int, cam, 0x84);
#ifdef TARGET_SDL
    /* MK4_TRACE_HANDOFF: the fight camera taking over from the arena
     * intro. Silence here means the intro never handed off and the
     * camera keeps its terminal intro pose. */
    { extern void SDL_Log(const char *, ...); extern char *getenv(const char *);
      static int f = -1; static int n;
      if (f < 0) f = getenv("MK4_TRACE_HANDOFF") != 0;
      if (f && n < 6) { n++;
          SDL_Log("HANDOFF fight camera, cmd=%u cam=%x", cmd, cam); } }
#endif
    MK4_NODE_AT(unsigned int, cam, 0x84) = 0;
    if (cmd == 0) {
        MK4_NODE_AT(unsigned int, cam, 8) = 0x42f8a0u;
        MK4_NODE_AT(unsigned int, cam, 0x84) = 1;
        g_pendingNodeType = 1;
        g_framePauseFlag = 1;
        return;
    }

    Distance2DSaturationClamp();
    if (g_framePauseFlag != 0) return;
    g_currentNodeIdx = g_p1NodeIdxG;
    ChainFieldTest2Branch();
    if (g_framePauseFlag != 0) return;
    g_currentNodeIdx = g_p2NodeIdxG;
    ChainFieldTest2Branch();
    if (g_framePauseFlag != 0) return;
    LoadSetCallPauseStoreJmp();
    if (g_framePauseFlag != 0) return;
    MStackPush4DualCallAbsPop4();
    if (g_framePauseFlag != 0) return;

#ifdef TARGET_SDL
    /* MK4_TRACE_HANDOFF: which way the fight camera routes, and on what
     * numbers. The camera's velocity stays zero, so one of these arms is
     * either never taken or never writes one. */
    { extern void SDL_Log(const char *, ...); extern char *getenv(const char *);
      static int f3 = -1; static int n3;
      if (f3 < 0) f3 = getenv("MK4_TRACE_HANDOFF") != 0;
      if (f3 && n3 < 10) { n3++;
          SDL_Log("CAMROUTE sep=%d (>%d ? walk) group=%x vel6c=%d",
                  (int)g_slot78, 0xa3d, g_groupHead,
                  MK4_NODE_AT(int, g_groupHead, 0x6c)); } }
#endif
    if ((int)g_slot78 > 0xa3d) {
        WalkTowardTargetFsm();           /* the walk-in takes over */
        return;
    }
    DualMul10ChainAcc7C();
    if (g_framePauseFlag != 0) return;

    d = (int)g_slot7c;
#ifdef TARGET_SDL
    { extern void SDL_Log(const char *, ...); extern char *getenv(const char *);
      static int f4 = -1; static int n4;
      if (f4 < 0) f4 = getenv("MK4_TRACE_HANDOFF") != 0;
      if (f4 && n4 < 10) { n4++;
          SDL_Log("CAMROUTE dist=%d thresholds 0x300000/0x370000", d); } }
#endif
    if (d < 0x300000) {
        EsiInstallChainCallCmpThreshold();
        return;
    }
    a = (int)g_slot74;
    b = (int)g_walkSlot6c;
    c = (int)g_slot70;
    if (d >= 0x370000) {
        lim = a - 0x1999;
        g_slot78 = (unsigned int)lim;
        if (b < lim) {
            GuardedSeq_DualMulScaleStore_then_PhaseInstall2DInterpDispatch_0042fba0();
            return;
        }
        if (c < lim) {
            GuardedSeq_DualMulScaleStore_then_PhaseInstall2DInterpDispatch_0042fba0();
            return;
        }
    }
    if (b < a) {
        if (c < a) {
            Mul10Triple0xd999Interp();
            return;
        }
        g_slot78 = (unsigned int)b;
        g_currentNodeIdx = g_p2NodeIdxG;
        SubCmpCallPauseJmp();
        return;
    }
    if (c > a) {
        GuardedSeq_DualMulScaleStore_then_PhaseInstall2DInterpDispatch_0042fb80();
        return;
    }
    g_slot78 = (unsigned int)c;
    SubCmpCallPauseJmp();
}

#endif /* NON_MATCHING */
