/**
 * The fight camera: the three owner nodes StageParticleEmitterInit builds,
 * the per-frame chase tracker InstallSelf5CallVecChain, its two mode
 * thunks, and the 16.16 vec helpers they run on.
 *
 * StageParticleEmitterInit - 0x00464350 (781b game.fight): for each of
 *   the three owner globals (0x537f78 P1-cam, 0x541de0 P2-cam, 0x535e6c
 *   the shared emitter) still zero, allocate a node via
 *   BootPhaseGateBracketedInit, stamp FOV (+0x3c = 0xe666 / 0xf333),
 *   type (+0x30 = 0x11/0x12/0x13), position (+0x54..+0x5c), set kind
 *   bit 3, and prepend it into the scaled4 list. Every pause exit
 *   abandons the sequence (state machine re-runs it).
 *
 * FightCamMode1_00464560 / FightCamMode2_004645e0 (packed thunks after
 *   the init): stamp the camera node's +0x30/+0x34/+0x38 mode constants,
 *   point 0x542054/0x542058 at the P1 pair (&p1NodeIdx>>2, &ownerP1>>2)
 *   or - when the round word 0x54207c is not 1 - the P2 pair, and fall
 *   into the tracker. Dispatched as code pointers (codeptr_extras).
 *
 * InstallSelf5CallVecChain - 0x00464660 (386b): the per-frame chase-cam.
 *   Follows the target node's position (+0x54) through QuadInterpolatorV2
 *   (matrix*vec + add), takes the delta to the owner's position, scales
 *   by 0.8 (0xcccc), clamps each component to +/-0.3 (0x4ccc), and
 *   accumulates into the owner's +0x6c vector; then re-installs itself
 *   as the camera node's callback (+8 = 0x464660), re-arms +0x84 = 1
 *   and yields the frame (pause).
 *
 * TripleSubVec3 - 0x004250f0 (61b): [node] = [entity] - [pending], 3 words.
 * ThreeMul10Stores - 0x004252c0 (150b): [node] = [entity] * k >> 16.
 * ThreeClampLoop - 0x00425a80 (155b): clamp 3 words to +/-k; cursors
 *   advance and are restored; 0x53a1ac takes the spent inner counter (-1).
 * QuadInterpolatorV2 - 0x004255b0 (633b): r[i] = sum(M[3i+k]*V[k] >> 16)
 *   + A[i]; M = 9 words at entity, V = vec3 at pending, A = vec3 at
 *   0x542050, r -> node. Row sums staged in 0x542070/74/78.
 *
 * NATIVE-ONLY twins: the matching build synthesizes the original bytes.
 */
#ifdef NON_MATCHING

#include "portable/mem_model.h"

extern void BootPhaseGateBracketedInit(void);
extern void MStackCall_MStackPush2ChainPrepend_004063e0(void);
extern void TripleAddVec3(void);

#define g_currentNodeIdx  (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_xformEntityIdx  (*(unsigned int *)MK4_VA(unsigned int, 0x542048u))
#define g_pendingNodeType (*(unsigned int *)MK4_VA(unsigned int, 0x54204cu))
#define g_addVecIdx       (*(unsigned int *)MK4_VA(unsigned int, 0x542050u))
#define g_targetSlot      (*(unsigned int *)MK4_VA(unsigned int, 0x542054u))
#define g_ownerSlot       (*(unsigned int *)MK4_VA(unsigned int, 0x542058u))
#define g_baseSel         (*(unsigned int *)MK4_VA(unsigned int, 0x542060u))
#define g_walkSlot6c      (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_slot70          (*(unsigned int *)MK4_VA(unsigned int, 0x542070u))
#define g_slot74          (*(unsigned int *)MK4_VA(unsigned int, 0x542074u))
#define g_slot78          (*(unsigned int *)MK4_VA(unsigned int, 0x542078u))
#define g_roundWord7c     (*(unsigned int *)MK4_VA(unsigned int, 0x54207cu))
#define g_framePauseFlag  (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_ownerP1         (*(unsigned int *)MK4_VA(unsigned int, 0x537f78u))
#define g_ownerP2         (*(unsigned int *)MK4_VA(unsigned int, 0x541de0u))
#define g_emitterNode     (*(unsigned int *)MK4_VA(unsigned int, 0x535e6cu))
#define g_camScratch8c    (*(unsigned int *)MK4_VA(unsigned int, 0x541f8cu))
#define g_camScratch98    (*(unsigned int *)MK4_VA(unsigned int, 0x541f98u))
#define g_clampSpent      (*(unsigned int *)MK4_VA(unsigned int, 0x53a1acu))

void TripleSubVec3(void)
{
    unsigned int dst = g_currentNodeIdx;
    unsigned int a = g_xformEntityIdx, b = g_pendingNodeType;

    MK4_NODE_AT(unsigned int, dst, 0) =
        MK4_NODE_AT(unsigned int, a, 0) - MK4_NODE_AT(unsigned int, b, 0);
    MK4_NODE_AT(unsigned int, dst, 4) =
        MK4_NODE_AT(unsigned int, a, 4) - MK4_NODE_AT(unsigned int, b, 4);
    MK4_NODE_AT(unsigned int, dst, 8) =
        MK4_NODE_AT(unsigned int, a, 8) - MK4_NODE_AT(unsigned int, b, 8);
}

static int fixmul16(int a, int b)
{
    return (int)(((long long)a * b) >> 16);
}

void ThreeMul10Stores(void)
{
    unsigned int dst = g_currentNodeIdx, src = g_xformEntityIdx;
    int k = (int)g_walkSlot6c;
    int r0, r1;

    r0 = fixmul16(k, (int)MK4_NODE_AT(unsigned int, src, 0));
    g_slot70 = (unsigned int)r0;
    r1 = fixmul16(k, (int)MK4_NODE_AT(unsigned int, src, 4));
    g_slot74 = (unsigned int)r1;
    MK4_NODE_AT(unsigned int, dst, 0) = (unsigned int)r0;
    MK4_NODE_AT(unsigned int, dst, 4) = (unsigned int)r1;
    r0 = fixmul16((int)MK4_NODE_AT(unsigned int, src, 8), k);
    g_walkSlot6c = (unsigned int)r0;
    MK4_NODE_AT(unsigned int, dst, 8) = (unsigned int)r0;
}

void ThreeClampLoop(void)
{
    int lim = (int)g_walkSlot6c;
    int neg = -lim;
    int i, v;

    g_slot70 = (unsigned int)neg;
    for (i = 0; i < 3; i++) {
        v = (int)*(unsigned int *)MK4_PTR(g_xformEntityIdx * 4);
        g_slot74 = (unsigned int)v;
        g_xformEntityIdx += 1;
        if (v < 0) {
            if (v < neg) v = neg;
        } else {
            if (v > lim) v = lim;
        }
        g_slot74 = (unsigned int)v;
        *(unsigned int *)MK4_PTR(g_currentNodeIdx * 4) = (unsigned int)v;
        g_currentNodeIdx += 1;
    }
    g_clampSpent = (unsigned int)-1;
    g_currentNodeIdx -= 3;
    g_xformEntityIdx -= 3;
}

void QuadInterpolatorV2(void)
{
    unsigned int M = g_xformEntityIdx;   /* 9-word matrix cursor */
    unsigned int V = g_pendingNodeType;  /* vec3 */
    unsigned int A = g_addVecIdx;        /* vec3 to add */
    unsigned int dst = g_currentNodeIdx;
    int r0, r1, r2;

#define Mw(i) ((int)*(unsigned int *)MK4_PTR((M + (i)) * 4))
#define Vw(i) ((int)*(unsigned int *)MK4_PTR((V + (i)) * 4))
#define Aw(i) ((int)*(unsigned int *)MK4_PTR((A + (i)) * 4))
    r0 = fixmul16(Mw(0), Vw(0)) + fixmul16(Mw(1), Vw(1))
       + fixmul16(Mw(2), Vw(2)) + Aw(0);
    r1 = fixmul16(Mw(3), Vw(0)) + fixmul16(Mw(4), Vw(1))
       + fixmul16(Mw(5), Vw(2)) + Aw(1);
    r2 = fixmul16(Mw(6), Vw(0)) + fixmul16(Mw(7), Vw(1))
       + fixmul16(Mw(8), Vw(2)) + Aw(2);
#undef Mw
#undef Vw
#undef Aw
    g_slot70 = (unsigned int)r0;
    g_slot74 = (unsigned int)r1;
    g_slot78 = (unsigned int)r2;
    g_xformEntityIdx = M + 9;
    g_pendingNodeType = V + 1;           /* the original leaves V advanced */
    MK4_NODE_AT(unsigned int, dst, 0) = (unsigned int)r0;
    MK4_NODE_AT(unsigned int, dst, 4) = (unsigned int)r1;
    MK4_NODE_AT(unsigned int, dst, 8) = (unsigned int)r2;
}

void InstallSelf5CallVecChain(void)
{
    unsigned int cam = g_baseSel;
    unsigned int target, owner;

    MK4_NODE_AT(unsigned int, cam, 0x84) = 0;
    g_xformEntityIdx = g_camScratch8c;
    g_pendingNodeType = cam + 0xc;

    target = *(unsigned int *)MK4_PTR(g_targetSlot * 4);
    g_addVecIdx = target;
    if (target != 0) {
        g_addVecIdx = target + 0x15;                 /* target position */
        g_currentNodeIdx = g_camScratch98;
        QuadInterpolatorV2();
        if (g_framePauseFlag != 0)
            return;

        g_xformEntityIdx = g_currentNodeIdx;
        owner = *(unsigned int *)MK4_PTR(g_ownerSlot * 4);
        if (g_addVecIdx == 0)
            goto rearm;
        g_pendingNodeType = owner + 0x15;            /* owner position */
        TripleSubVec3();
        if (g_framePauseFlag != 0)
            return;

        g_xformEntityIdx = g_currentNodeIdx;
        g_walkSlot6c = 0xcccc;                       /* 0.8 */
        ThreeMul10Stores();
        if (g_framePauseFlag != 0)
            return;

        g_xformEntityIdx = g_currentNodeIdx;
        owner = *(unsigned int *)MK4_PTR(g_ownerSlot * 4);
        g_pendingNodeType = owner + 0x1b;            /* owner +0x6c vec */
        TripleSubVec3();
        if (g_framePauseFlag != 0)
            return;

        g_xformEntityIdx = g_currentNodeIdx;
        g_walkSlot6c = 0x4ccc;                       /* clamp 0.3 */
        ThreeClampLoop();
        if (g_framePauseFlag != 0)
            return;

        g_xformEntityIdx = g_currentNodeIdx;
        owner = *(unsigned int *)MK4_PTR(g_ownerSlot * 4);
        g_pendingNodeType = owner + 0x1b;
        g_currentNodeIdx = owner + 0x1b;
        TripleAddVec3();
        if (g_framePauseFlag != 0)
            return;
    }
rearm:
    MK4_NODE_AT(unsigned int, cam, 8) = 0x464660u;   /* self, via trampoline */
    MK4_NODE_AT(unsigned int, cam, 0x84) = 1;
    g_pendingNodeType = 2;
    g_framePauseFlag = 1;
}

static void stage_cam_pair(unsigned int mode30, unsigned int mode34,
                           unsigned int mode38)
{
    unsigned int cam = g_baseSel;

    MK4_NODE_AT(unsigned int, cam, 0x30) = mode30;
    MK4_NODE_AT(unsigned int, g_baseSel, 0x34) = mode34;
    g_walkSlot6c = mode38;
    MK4_NODE_AT(unsigned int, g_baseSel, 0x38) = mode38;
    g_targetSlot = 0x538158u >> 2;
    g_ownerSlot  = 0x537f78u >> 2;
    if (g_roundWord7c != 1) {
        g_targetSlot = 0x53815cu >> 2;
        g_ownerSlot  = 0x541de0u >> 2;
    }
    InstallSelf5CallVecChain();          /* jmp in the original */
}

void FightCamMode1_00464560(void)
{
    stage_cam_pair(0x8000u, 0xffff6667u, 0xffffd1ecu);
}

void FightCamMode2_004645e0(void)
{
    stage_cam_pair(0xffff6e15u, 0x12b85u, 0xffffd99au);
}

void StageParticleEmitterInit(void)
{
    g_walkSlot6c = g_ownerP1;
    if (g_ownerP1 == 0) {
        BootPhaseGateBracketedInit();
        if (g_framePauseFlag != 0)
            return;
        MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x3c) = 0xe666u;
        MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x30) = 0x11u;
        g_ownerP1 = g_currentNodeIdx;
        MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x54) = 0xffffb0a4u;
        MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x58) = 0xfffe0000u;
        g_walkSlot6c = 0xffffae15u;
        MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x5c) = 0xffffae15u;
        g_walkSlot6c = MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x34) | 8u;
        MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x34) = g_walkSlot6c;
        MStackCall_MStackPush2ChainPrepend_004063e0();
        if (g_framePauseFlag != 0)
            return;
    }
    g_walkSlot6c = g_ownerP2;
    if (g_ownerP2 == 0) {
        BootPhaseGateBracketedInit();
        if (g_framePauseFlag != 0)
            return;
        MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x3c) = 0xe666u;
        MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x30) = 0x12u;
        g_ownerP2 = g_currentNodeIdx;
        MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x54) = 0x4f5cu;
        MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x58) = 0xfffe0000u;
        g_walkSlot6c = 0xffffae15u;
        MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x5c) = 0xffffae15u;
        g_walkSlot6c = MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x34) | 8u;
        MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x34) = g_walkSlot6c;
        MStackCall_MStackPush2ChainPrepend_004063e0();
        if (g_framePauseFlag != 0)
            return;
    }
    g_walkSlot6c = g_emitterNode;
    if (g_emitterNode == 0) {
        BootPhaseGateBracketedInit();
        if (g_framePauseFlag != 0)
            return;
        MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x3c) = 0xf333u;
        MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x30) = 0x13u;
        g_emitterNode = g_currentNodeIdx;
        MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x54) = 0xffe80000u;
        MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x58) = 0xffd00000u;
        g_walkSlot6c = 0;
        MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x5c) = 0;
        g_walkSlot6c = MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x34) | 8u;
        MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x34) = g_walkSlot6c;
        MStackCall_MStackPush2ChainPrepend_004063e0();
    }
}

#endif /* NON_MATCHING */
