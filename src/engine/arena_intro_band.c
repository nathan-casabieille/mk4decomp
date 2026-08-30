/**
 * The arena-intro band: the per-stage camera opening the fight dispatches
 * through the table at 0x4e3a30, and the leaves it runs on. Without it
 * FightGroupInit's tail-dispatch lands on the trampoline's no-op, the
 * camera never gets a shot, and the fight renders from a viewpoint sitting
 * in the fighters' own plane.
 *
 * The two symbols each pack several entries; every entry is a
 * self-installing state machine on the controller node's +0x84 command
 * word, and each joins codeptr_extras.
 *
 * TowerStageInitCluster (0x430560, 820b):
 *   0x430560  thunk: load the vec3 at 0x4e3910 into the camera record's
 *             +0x54..+0x5c, then DispatchOrInitFightGroup.
 *   0x430580  ArenaIntro_Tower (table entries [3],[5],[7]): state 0
 *             builds the intro node (the 0x4e3ac8 record through
 *             DispatcherComplex260, prepended into the pair1 list),
 *             stamps type 0x5b, seeds position/height (-1.5) and heading
 *             0x4b65f, loads the two vec3s at 0x4e3920 / 0x4e3930, and
 *             yields for 0x10 frames; state 1 arms the 0x15c2 ramp and
 *             queues its own tagged VA through
 *             EsiInstallSetCbChainExtend; state 2+ inserts the built
 *             node and hands over to DispatchOrInitFightGroup.
 *   0x430750  ArenaIntro_Sky (table entry [4]): state 0 loads 0x4e39b0
 *             and yields 8 frames; state 1 zeroes the camera's
 *             +0x34..+0x48, sets height -1.5, type 0x64, the -7.05 limit,
 *             queues its tagged VA and enters the follow interpolator;
 *             state 2+ pops the queue.
 *
 * RoundFsmCluster_Atan2QuadrantLookup (0x4308a0, 1159b):
 *   0x4308a0  CameraAimAtP1: two BAM angles from the camera record to
 *             P1 - pitch from the (z, height) delta into +0x60 (mirrored
 *             as 0x6487e - a), then yaw from the (z, x) delta into +0x64;
 *             both are then overwritten with zero, which the original
 *             does unconditionally (transcribed as written).
 *   0x4309a0  ArenaIntro_Approach (table entry [1]): a 4-state approach -
 *             ramp the camera's +0x74 toward 1.0, hold while the height
 *             delta to P1 exceeds 1.125, then decay by 0xd4f per frame
 *             until it drops under 0x147a, re-aim, and finish when the
 *             delta is under 0.4375.
 *   0x430bd0  ArenaIntro_Spin (table entries [0],[2],[6]): the spin-in -
 *             state 0 sets the sweep to pi/2 and enters the arc chain;
 *             state 1 sets the step to 0x28f; state 2 scales the step by
 *             0.92 with a 0x24d floor; state 3 scales it by 1.08 with a
 *             0xf5c ceiling; each subtracts the step from the sweep and
 *             re-enters GuardedArithDualCallChain until the sweep runs
 *             out.
 *
 * Leaves: TripleScaledChainStore54 / 60 (load a static vec3 into the
 * camera record at +0x54 / +0x60), GuardedArithDualCallChain (place the
 * camera on the arc: sin/cos of the sweep through the tables at
 * 0x54202c / 0x542028, times 7, into +0x54/+0x5c, heading into +0x64),
 * ModMagicMul10Index / MStackMagicModMul10 (the BAM sin and cos lookups,
 * wrap into [0, 2pi) then index), ZeroSixStores6c80.
 *
 * NATIVE-ONLY twins: the matching build synthesizes the original bytes.
 */
#ifdef NON_MATCHING

#include "portable/mem_model.h"

extern void DispatchOrInitFightGroup(void);
extern void DispatcherComplex260_MStackBracket1_TreeWalkRecursive2(void);
extern void MStackCall_MStackPush2ChainPrepend_00406340(void);
extern void MStackPush2ChainLLInsert(void);
extern void StackPopDispatchTagged(void);
extern void Atan2QuadrantLookup(void);
extern void PendingMatch_ThreeMul10Stores(void);
extern void SetJmp_Phase3InstallTableCheck(void);
void EsiInstallSetCbChainExtend_0048a970(void);

#define g_currentNodeIdx  (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_xformEntityIdx  (*(unsigned int *)MK4_VA(unsigned int, 0x542048u))
#define g_pendingNodeType (*(unsigned int *)MK4_VA(unsigned int, 0x54204cu))
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
#define g_groupHead       (*(unsigned int *)MK4_VA(unsigned int, 0x54205cu))
#define g_framePauseFlag  (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_matrixStackTop  (*(unsigned int *)MK4_VA(unsigned int, 0x4d57acu))
#define g_camRecIdx       (*(unsigned int *)MK4_VA(unsigned int, 0x52ab10u))
#define g_p1NodeIdxG      (*(unsigned int *)MK4_VA(unsigned int, 0x538158u))
#define g_installOwner    (*(unsigned int *)MK4_VA(unsigned int, 0x535cf8u))
#define g_sinTblBase      (*(unsigned int *)MK4_VA(unsigned int, 0x54202cu))
#define g_cosTblBase      (*(unsigned int *)MK4_VA(unsigned int, 0x542028u))
#define g_trigScale       (*(unsigned int *)MK4_VA(unsigned int, 0x4d5318u))

#define BAM_FULL 0x6487eu

static int ai_fixmul16(int a, int b)
{
    return (int)(((long long)a * b) >> 16);
}

static unsigned int ai_wrap(unsigned int v)
{
    int a = (int)v;

    while (a < 0)            a += (int)BAM_FULL;
    while (a >= (int)BAM_FULL) a -= (int)BAM_FULL;
    return (unsigned int)a;
}

/* queue this state's own tagged VA on the controller's event list */
static void ai_queue_self(unsigned int cam, unsigned int self_va,
                          unsigned int tag, unsigned int cmd)
{
    unsigned int q;

    MK4_NODE_AT(unsigned int, cam, 8) = self_va;
    MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = cmd;
    q = MK4_NODE_AT(unsigned int, cam, 4);
    g_currentNodeIdx = q;
    *(unsigned int *)MK4_PTR(q * 4) = self_va + tag;
    g_currentNodeIdx = q + 1;
    MK4_NODE_AT(unsigned int, cam, 4) = q + 1;
    MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 0;
}

static void ai_yield(unsigned int cam, unsigned int self_va,
                     unsigned int cmd, unsigned int pending)
{
    MK4_NODE_AT(unsigned int, cam, 8) = self_va;
    MK4_NODE_AT(unsigned int, cam, 0x84) = cmd;
    g_pendingNodeType = pending;
    g_framePauseFlag = 1;
}

/* --- the vec3 loaders -------------------------------------------------- */

void TripleScaledChainStore54(int rec)
{
    unsigned int p = ((unsigned int)rec) >> 2;
    unsigned int cam = g_camRecIdx;
    int i;
    static const unsigned char off[3] = {0x54, 0x58, 0x5c};

    g_groupHead = cam;
    g_currentNodeIdx = p;
    for (i = 0; i < 3; i++) {
        unsigned int v = *(unsigned int *)MK4_PTR(p * 4);
        p += 1;
        g_walkSlot6c = v;
        g_currentNodeIdx = p;
        MK4_NODE_AT(unsigned int, g_groupHead, off[i]) = v;
    }
}

void TripleScaledChainStore60(int rec)
{
    unsigned int p = ((unsigned int)rec) >> 2;
    unsigned int cam = g_camRecIdx;
    int i;
    static const unsigned char off[3] = {0x60, 0x64, 0x68};

    g_groupHead = cam;
    g_currentNodeIdx = p;
    for (i = 0; i < 3; i++) {
        unsigned int v = *(unsigned int *)MK4_PTR(p * 4);
        p += 1;
        g_walkSlot6c = v;
        g_currentNodeIdx = p;
        MK4_NODE_AT(unsigned int, g_groupHead, off[i]) = v;
    }
}

void ZeroSixStores6c80(void)
{
    static const unsigned char off[6] = {0x6c, 0x70, 0x74, 0x78, 0x7c, 0x80};
    int i;

    g_walkSlot6c = 0;
    for (i = 0; i < 6; i++)
        MK4_NODE_AT(unsigned int, g_groupHead, off[i]) = 0;
}

/* --- the BAM trig lookups ---------------------------------------------- */

void ModMagicMul10Index(void)
{
    unsigned int top = g_matrixStackTop + 1;
    unsigned int a;

    g_matrixStackTop = top;
    *(unsigned int *)MK4_PTR(top * 4) = g_currentNodeIdx;

    a = ai_wrap(g_slot74);
    g_slot74 = a;
    g_walkSlot6c = a;
    a = (unsigned int)ai_fixmul16((int)g_trigScale, (int)a);
    g_walkSlot6c = a;
    a = ((((int)a >> 16) + 0x200) & 0x7ff) + g_sinTblBase;
    g_currentNodeIdx = a;
    g_walkSlot6c = *(unsigned int *)MK4_PTR(a * 4);

    top = g_matrixStackTop;
    g_currentNodeIdx = *(unsigned int *)MK4_PTR(top * 4);
    g_matrixStackTop = top - 1;
}

void MStackMagicModMul10(void)
{
    unsigned int top = g_matrixStackTop + 1;
    unsigned int a;

    g_matrixStackTop = top;
    *(unsigned int *)MK4_PTR(top * 4) = g_currentNodeIdx;

    a = ai_wrap(g_slot74);
    g_slot74 = a;
    g_walkSlot6c = a;
    a = (unsigned int)ai_fixmul16((int)g_trigScale, (int)a);
    g_walkSlot6c = a;
    a = (unsigned int)((int)a >> 16) + g_cosTblBase;
    g_currentNodeIdx = a;
    g_walkSlot6c = *(unsigned int *)MK4_PTR(a * 4);

    top = g_matrixStackTop;
    g_currentNodeIdx = *(unsigned int *)MK4_PTR(top * 4);
    g_matrixStackTop = top - 1;
}

/* --- the arc placement ------------------------------------------------- */

void GuardedArithDualCallChain(void)
{
    int s, c, sweep;

    sweep = (int)0xfffe6de1 - (int)g_slot88;
    g_slot88 = (unsigned int)sweep;
    g_slot74 = (unsigned int)sweep;
    ModMagicMul10Index();
    if (g_framePauseFlag != 0)
        return;
    s = (int)g_walkSlot6c;
    g_slot78 = (unsigned int)s;
    MStackMagicModMul10();
    if (g_framePauseFlag != 0)
        return;
    c = (int)g_walkSlot6c;

    g_slot88 = (unsigned int)(-(int)g_slot88 - 0x1921f);
    s = (s << 3) - s;                    /* x7 */
    g_slot78 = (unsigned int)s;
    c = (c << 3) - c;
    g_walkSlot6c = (unsigned int)c;
    MK4_NODE_AT(unsigned int, g_groupHead, 0x54) = (unsigned int)s;
    MK4_NODE_AT(unsigned int, g_groupHead, 0x5c) = (unsigned int)c;
    MK4_NODE_AT(unsigned int, g_groupHead, 0x64) = g_slot88;
}

/* --- the camera aim ---------------------------------------------------- */

void CameraAimAtP1(void)
{
    unsigned int p1 = g_p1NodeIdxG, cam = g_camRecIdx;
    int cz, ch;

    g_slot58 = p1;
    g_groupHead = cam;
    cz = (int)MK4_NODE_AT(unsigned int, cam, 0x5c);
    g_walkSlot6c = (unsigned int)cz;
    g_slot74 = (unsigned int)((int)MK4_NODE_AT(unsigned int, p1, 0x5c) - cz);
    ch = (int)MK4_NODE_AT(unsigned int, cam, 0x58);
    g_walkSlot6c = (unsigned int)ch;
    g_slot78 = (unsigned int)((int)MK4_NODE_AT(unsigned int, p1, 0x58) - ch);
    g_slot7c = g_slot78;
    Atan2QuadrantLookup();
    if (g_framePauseFlag != 0)
        return;

    {
        unsigned int camn = g_groupHead;
        unsigned int a = BAM_FULL - g_walkSlot6c;
        unsigned int other = g_slot58;
        int v;

        g_slot7c = a;
        MK4_NODE_AT(unsigned int, camn, 0x60) = a;
        v = (int)MK4_NODE_AT(unsigned int, camn, 0x5c);
        g_walkSlot6c = (unsigned int)v;
        g_slot74 = (unsigned int)((int)MK4_NODE_AT(unsigned int, other, 0x5c) - v);
        v = (int)MK4_NODE_AT(unsigned int, camn, 0x54);
        g_walkSlot6c = (unsigned int)v;
        g_slot78 = (unsigned int)((int)MK4_NODE_AT(unsigned int, other, 0x54) - v);
        Atan2QuadrantLookup();
        if (g_framePauseFlag != 0)
            return;
        MK4_NODE_AT(unsigned int, camn, 0x64) = g_walkSlot6c;
        /* the original then clears all three unconditionally */
        g_slot7c = 0;
        MK4_NODE_AT(unsigned int, camn, 0x60) = 0;
        MK4_NODE_AT(unsigned int, camn, 0x64) = g_slot7c;
        MK4_NODE_AT(unsigned int, camn, 0x68) = g_slot7c;
    }
}

/* --- the three intro state machines ------------------------------------ */

void TowerStageInitCluster(void)
{
    TripleScaledChainStore54(0x4e3910);
    if (g_framePauseFlag != 0)
        return;
    DispatchOrInitFightGroup();      /* jmp in the original */
}

void ArenaIntro_Tower_00430580(void)
{
    unsigned int cam = g_baseSel;
    unsigned int cmd, node;

    cmd = MK4_NODE_AT(unsigned int, cam, 0x84);
    MK4_NODE_AT(unsigned int, cam, 0x84) = 0;

    if (cmd == 0) {
        g_xformEntityIdx = 0x4e3ac8u >> 2;
        DispatcherComplex260_MStackBracket1_TreeWalkRecursive2();
        if (g_framePauseFlag != 0) return;
        MStackCall_MStackPush2ChainPrepend_00406340();
        if (g_framePauseFlag != 0) return;

        node = g_currentNodeIdx;
        MK4_NODE_AT(unsigned int, node, 0x30) = 0x5b;
        MK4_NODE_AT(unsigned int, g_baseSel, 0x5c) = node;
        g_walkSlot6c = 0;
        MK4_NODE_AT(unsigned int, node, 0x60) = 0;
        MK4_NODE_AT(unsigned int, node, 0x68) = 0;
        MK4_NODE_AT(unsigned int, node, 0x54) = 0;
        MK4_NODE_AT(unsigned int, node, 0x5c) = 0;
        MK4_NODE_AT(unsigned int, node, 0x64) = 0x4b65fu;
        g_walkSlot6c = 0xfffe8000u;
        MK4_NODE_AT(unsigned int, node, 0x58) = 0xfffe8000u;
        g_slot54 = node;
        g_slot58 = 0x4e3a60u >> 2;
        g_installOwner = node;

        TripleScaledChainStore54(0x4e3920);
        if (g_framePauseFlag != 0) return;
        TripleScaledChainStore60(0x4e3930);
        if (g_framePauseFlag != 0) return;
        ai_yield(cam, 0x430580u, 1, 0x10);
        return;
    }
    if (cmd == 1) {
        g_slot7c = 0;
        g_slot88 = 0x15c2u;
        ai_queue_self(cam, 0x430580u, 0x2000000u, 2);
        EsiInstallSetCbChainExtend_0048a970();
        g_framePauseFlag = 1;
        return;
    }
    /* cmd >= 2 */
    g_currentNodeIdx = MK4_NODE_AT(unsigned int, g_baseSel, 0x5c);
    MStackPush2ChainLLInsert();
    if (g_framePauseFlag != 0) return;
    DispatchOrInitFightGroup();
}

void ArenaIntro_Sky_00430750(void)
{
    unsigned int cam = g_baseSel;
    unsigned int cmd;

    cmd = MK4_NODE_AT(unsigned int, cam, 0x84);
    MK4_NODE_AT(unsigned int, cam, 0x84) = 0;

    if (cmd == 0) {
        g_groupHead = g_camRecIdx;
        TripleScaledChainStore54(0x4e39b0);
        if (g_framePauseFlag != 0) return;
        ai_yield(cam, 0x430750u, 1, 8);
        return;
    }
    if (cmd != 1) {
        StackPopDispatchTagged();
        return;
    }
    g_groupHead = g_camRecIdx;
    g_walkSlot6c = 0;
    MK4_NODE_AT(unsigned int, g_baseSel, 0x40) = 0;
    MK4_NODE_AT(unsigned int, g_baseSel, 0x48) = 0;
    g_slot7c = 0;
    g_slot80 = 0xfff8f334u;
    MK4_NODE_AT(unsigned int, g_baseSel, 0x44) = 0;
    MK4_NODE_AT(unsigned int, g_baseSel, 0x34) = 0;
    MK4_NODE_AT(unsigned int, g_baseSel, 0x3c) = 0xfff8f334u;
    MK4_NODE_AT(unsigned int, g_baseSel, 0x38) = 0xfffe8000u;
    g_walkSlot6c = 0x64;
    MK4_NODE_AT(unsigned int, g_baseSel, 0x30) = 0x64;
    ai_queue_self(cam, 0x430750u, 0x2000000u, 2);
    PendingMatch_ThreeMul10Stores();
    g_framePauseFlag = 1;
}

void ArenaIntro_Approach_004309a0(void)
{
    unsigned int cam = g_baseSel;
    unsigned int cmd;
    int d;

    cmd = MK4_NODE_AT(unsigned int, cam, 0x84);
    MK4_NODE_AT(unsigned int, cam, 0x84) = 0;

    if (cmd > 3) {
        int cz = (int)MK4_NODE_AT(unsigned int, g_slot58, 0x5c);
        g_walkSlot6c = (unsigned int)cz;
        d = (int)MK4_NODE_AT(unsigned int, g_groupHead, 0x5c) - cz;
        g_slot70 = (unsigned int)d;
        if (d < 0) { d = -d; g_slot70 = (unsigned int)d; }
        if (d > 0x70000) {
            ai_yield(cam, 0x4309a0u, 4, 1);
            return;
        }
        g_walkSlot6c = 0;
        MK4_NODE_AT(unsigned int, g_groupHead, 0x74) = 0;
        StackPopDispatchTagged();
        return;
    }

    if (cmd == 0) {                       /* 0x430ad7 */
        TripleScaledChainStore54(0x4e39c0);
        if (g_framePauseFlag != 0) return;
        CameraAimAtP1();
        if (g_framePauseFlag != 0) return;
        g_slot88 = MK4_NODE_AT(unsigned int, g_groupHead, 0x74) + 0x7ae;
        MK4_NODE_AT(unsigned int, g_groupHead, 0x74) = g_slot88;
        ai_yield(cam, 0x4309a0u, 1, 1);
        return;
    }
    if (cmd == 1) {                       /* 0x4309ce - ramp toward 1.0 */
        if ((int)g_slot88 >= 0x10000) {
            g_slot88 = 0x10000u;
            MK4_NODE_AT(unsigned int, g_groupHead, 0x74) = 0x10000u;
            g_slot58 = g_p1NodeIdxG;
            ai_yield(cam, 0x4309a0u, 2, 1);
            return;
        }
        g_slot88 += 0x7ae;
        MK4_NODE_AT(unsigned int, g_groupHead, 0x74) = g_slot88;
        ai_yield(cam, 0x4309a0u, 1, 1);
        return;
    }
    if (cmd == 2) {                       /* 0x4309ff - hold while far */
        int cz = (int)MK4_NODE_AT(unsigned int, g_slot58, 0x5c);
        g_walkSlot6c = (unsigned int)cz;
        d = (int)MK4_NODE_AT(unsigned int, g_groupHead, 0x5c) - cz;
        g_slot70 = (unsigned int)d;
        if (d < 0) { d = -d; g_slot70 = (unsigned int)d; }
        if (d > 0x120000) {
            ai_yield(cam, 0x4309a0u, 2, 1);
            return;
        }
        g_slot84 = 0xd4f;
        g_slot88 = 0x147a;
        ai_yield(cam, 0x4309a0u, 3, 1);
        return;
    }
    /* cmd == 3 - decay 0x430a6e */
    {
        int v = (int)MK4_NODE_AT(unsigned int, g_groupHead, 0x74);
        g_walkSlot6c = (unsigned int)v;
        v -= (int)g_slot84;
        g_slot70 = (unsigned int)v;
        MK4_NODE_AT(unsigned int, g_groupHead, 0x74) = (unsigned int)v;
        if (v > (int)g_slot88) {
            ai_yield(cam, 0x4309a0u, 3, 1);
            return;
        }
        MK4_NODE_AT(unsigned int, g_groupHead, 0x74) = g_slot88;
        ai_yield(cam, 0x4309a0u, 4, 1);
    }
}

void ArenaIntro_Spin_00430bd0(void)
{
    unsigned int cam = g_baseSel;
    unsigned int cmd;
    int step;

    cmd = MK4_NODE_AT(unsigned int, cam, 0x84);
    MK4_NODE_AT(unsigned int, cam, 0x84) = 0;

    if (cmd == 0) {
        g_slot88 = 0x1921fu;              /* pi/2 sweep */
#ifdef TARGET_SDL
        /* MK4_TRACE_SWEEP: the arc's seed and the pose it produces. The
         * spin must END framed on the fighters, so the first placement
         * should be the FAR pose, not the framed one. */
        { extern void SDL_Log(const char *, ...); extern char *getenv(const char *);
          static int f = -1; static int n;
          if (f < 0) f = getenv("MK4_TRACE_SWEEP") != 0;
          if (f && n < 6) { n++;
              SDL_Log("SWEEP seed=%x group=%x", g_slot88, g_groupHead); } }
#endif
        GuardedArithDualCallChain();
#ifdef TARGET_SDL
        { extern void SDL_Log(const char *, ...); extern char *getenv(const char *);
          static int f2 = -1; static int n2;
          if (f2 < 0) f2 = getenv("MK4_TRACE_SWEEP") != 0;
          if (f2 && n2 < 6) { n2++;
              SDL_Log("SWEEP after: slot88=%x cam=[%d %d %d]", g_slot88,
                      MK4_NODE_AT(int, g_groupHead, 0x54),
                      MK4_NODE_AT(int, g_groupHead, 0x58),
                      MK4_NODE_AT(int, g_groupHead, 0x5c)); } }
#endif
        if (g_framePauseFlag != 0) return;
        ai_yield(cam, 0x430bd0u, 1, 0x16);
        return;
    }
    if (cmd == 1) {
        step = 0x28f;
        g_slot84 = (unsigned int)step;
        g_slot88 -= (unsigned int)step;
        GuardedArithDualCallChain();
        if (g_framePauseFlag != 0) return;
        ai_yield(cam, 0x430bd0u, 2, 1);
        return;
    }
    if (cmd == 2) {                        /* scale down, floor 0x24d */
        step = ai_fixmul16(0xeb85, (int)g_slot84);
        g_slot84 = (unsigned int)step;
        if (step < 0x24d) {
            step = 0x24d;
            g_slot84 = (unsigned int)step;
        }
        if ((int)g_slot88 <= 0) {
            StackPopDispatchTagged();
            return;
        }
        g_slot88 -= (unsigned int)step;
        GuardedArithDualCallChain();
        if (g_framePauseFlag != 0) return;
        ai_yield(cam, 0x430bd0u, 2, 1);
        return;
    }
    /* cmd == 3 - scale up, ceiling 0xf5c */
    step = ai_fixmul16(0x1147a, (int)g_slot84);
    g_slot84 = (unsigned int)step;
    if (step > 0xf5c) {
        step = 0xf5c;
        g_slot84 = (unsigned int)step;
    }
    if ((int)g_slot88 > 0xc924) {
        g_slot88 -= (unsigned int)step;
        GuardedArithDualCallChain();
        if (g_framePauseFlag != 0) return;
        ai_yield(cam, 0x430bd0u, 2, 1);
        return;
    }
    g_slot88 -= (unsigned int)step;
    GuardedArithDualCallChain();
    if (g_framePauseFlag != 0) return;
    ai_yield(cam, 0x430bd0u, 3, 1);
}

void EsiInstallSetCbChainExtend_0048a970(void)
{
    unsigned int cam = g_baseSel;
    unsigned int cmd;

    cmd = MK4_NODE_AT(unsigned int, cam, 0x84);
    MK4_NODE_AT(unsigned int, cam, 0x84) = 0;
    if (cmd != 0) {
        StackPopDispatchTagged();
        return;
    }
    g_groupHead = g_camRecIdx;
    ZeroSixStores6c80();
    g_slot80 = 0x48abc0u;
    ai_queue_self(cam, 0x48a970u, 0x1000000u, 1);
    SetJmp_Phase3InstallTableCheck();
    g_framePauseFlag = 1;
}

#endif /* NON_MATCHING */
