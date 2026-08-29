/**
 * The four position appliers GeoTransformDispatchAndApply picks between
 * (code-pointer table at 0x4ef800, index from the two > 0 tests it makes
 * on 0x52d74c and 0x538068). They are what actually MOVES a fighter:
 * every other piece of the fight band computes deltas into +0x6c/+0x74,
 * and these integrate them into the positions at +0x54/+0x5c.
 *
 * None of them carried a symbol, so none was in the code-pointer table
 * and the dispatcher's tail-call resolved to the no-op stub - which is
 * why nothing in the converted scene ever moved.
 *
 *   [0] Applier0_004898b0 (320b): push both nodes apart along the fight
 *       axis by 0.05 (0xccc) - node += axisNeg, entity += axisPos, on
 *       both x (+0x54) and z (+0x5c).
 *   [1] Applier1_004899f0 (59b): swap the node/entity roles and the
 *       0x542080/0x542084 limits, then fall into the clamp.
 *   [2] PositionClampCluster (572b): if the pair's squared separation
 *       has reached the limit at 0x53a180 (minus 0x40000), and applying
 *       both deltas would overshoot 0x542080, cancel the step
 *       (DualSubFromField on both); otherwise commit node's delta onto
 *       entity's position.
 *   [3] Applier3_00489ba0 (204b): move the ENTITY to the node's position
 *       biased 0.4 (0x6666) along the fight axis, then cancel both
 *       deltas.
 *
 * DualSubFromField (0x489c70, already native) is the "cancel": it
 * subtracts +0x6c from +0x54 and +0x74 from +0x5c on 0x54204c's node.
 *
 * NATIVE-ONLY twins: the matching build synthesizes the original bytes.
 */
#ifdef NON_MATCHING

#include "portable/mem_model.h"

extern void DualSubFromField(void);

#define g_currentNodeIdx  (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_xformEntityIdx  (*(unsigned int *)MK4_VA(unsigned int, 0x542048u))
#define g_pendingNodeType (*(unsigned int *)MK4_VA(unsigned int, 0x54204cu))
#define g_walkSlot6c      (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_slot70          (*(unsigned int *)MK4_VA(unsigned int, 0x542070u))
#define g_slot74          (*(unsigned int *)MK4_VA(unsigned int, 0x542074u))
#define g_slot78          (*(unsigned int *)MK4_VA(unsigned int, 0x542078u))
#define g_slot7c          (*(unsigned int *)MK4_VA(unsigned int, 0x54207cu))
#define g_limit80         (*(unsigned int *)MK4_VA(unsigned int, 0x542080u))
#define g_limit84         (*(unsigned int *)MK4_VA(unsigned int, 0x542084u))
#define g_framePauseFlag  (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_axisNegX        (*(unsigned int *)MK4_VA(unsigned int, 0x535e70u))
#define g_axisNegY        (*(unsigned int *)MK4_VA(unsigned int, 0x535e74u))
#define g_axisPosX        (*(unsigned int *)MK4_VA(unsigned int, 0x535e78u))
#define g_axisPosY        (*(unsigned int *)MK4_VA(unsigned int, 0x535e7cu))
#define g_sepLimit        (*(unsigned int *)MK4_VA(unsigned int, 0x53a180u))

static int pa_fixmul16(int a, int b)
{
    return (int)(((long long)a * b) >> 16);
}

void Applier0_004898b0(void)
{
    unsigned int node = g_currentNodeIdx, ent;
    int v, k;

    g_slot74 = 0xccc;

    /* node: x then z along the negative axis */
    v = (int)MK4_NODE_AT(unsigned int, node, 0x54);
    k = (int)g_axisNegX;
    g_walkSlot6c = (unsigned int)v;
    g_slot70 = (unsigned int)k;
    k = pa_fixmul16(0xccc, k);
    g_slot70 = (unsigned int)k;
    v += k;
    g_walkSlot6c = (unsigned int)v;
    MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x54) = (unsigned int)v;

    v = (int)MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x5c);
    k = (int)g_axisNegY;
    g_walkSlot6c = (unsigned int)v;
    g_slot70 = (unsigned int)k;
    k = pa_fixmul16((int)g_slot74, k);
    g_slot70 = (unsigned int)k;
    v += k;
    g_walkSlot6c = (unsigned int)v;
    MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x5c) = (unsigned int)v;

    /* entity: the same along the positive axis */
    ent = g_xformEntityIdx;
    v = (int)MK4_NODE_AT(unsigned int, ent, 0x54);
    k = (int)g_axisPosX;
    g_walkSlot6c = (unsigned int)v;
    g_slot70 = (unsigned int)k;
    k = pa_fixmul16((int)g_slot74, k);
    g_slot70 = (unsigned int)k;
    v += k;
    g_walkSlot6c = (unsigned int)v;
    MK4_NODE_AT(unsigned int, g_xformEntityIdx, 0x54) = (unsigned int)v;

    v = (int)MK4_NODE_AT(unsigned int, g_xformEntityIdx, 0x5c);
    k = (int)g_axisPosY;
    g_walkSlot6c = (unsigned int)v;
    g_slot70 = (unsigned int)k;
    k = pa_fixmul16((int)g_slot74, k);
    g_slot70 = (unsigned int)k;
    v += k;
    g_walkSlot6c = (unsigned int)v;
    MK4_NODE_AT(unsigned int, g_xformEntityIdx, 0x5c) = (unsigned int)v;
}

void PositionClampCluster(void)
{
    unsigned int ent = g_xformEntityIdx, node;
    int ex, ez, sep, lim, nx, nz, dx, dz, sep2;

    ex = (int)MK4_NODE_AT(unsigned int, ent, 0x54);
    ez = (int)MK4_NODE_AT(unsigned int, ent, 0x5c);
    g_walkSlot6c = (unsigned int)ex;
    g_slot70 = (unsigned int)ez;
    sep = pa_fixmul16(ex, ex);
    g_walkSlot6c = (unsigned int)sep;
    sep += pa_fixmul16(ez, ez);
    lim = (int)g_sepLimit - 0x40000;
    g_walkSlot6c = (unsigned int)sep;
    g_slot70 = (unsigned int)lim;

    if (sep >= lim) {
        node = g_currentNodeIdx;
        nx = (int)MK4_NODE_AT(unsigned int, node, 0x54);
        dx = (int)MK4_NODE_AT(unsigned int, node, 0x6c);
        nz = (int)MK4_NODE_AT(unsigned int, node, 0x5c);
        dz = (int)MK4_NODE_AT(unsigned int, node, 0x74);
        g_slot70 = (unsigned int)nx;
        g_slot74 = (unsigned int)dx;
        g_slot78 = (unsigned int)nz;
        g_slot7c = (unsigned int)dz;
        nx += dx;
        nz += dz;
        g_slot70 = (unsigned int)nx;
        g_slot78 = (unsigned int)nz;
        sep2 = pa_fixmul16(nx, nx);
        g_slot70 = (unsigned int)sep2;
        sep2 += pa_fixmul16(nz, nz);
        g_slot78 = (unsigned int)pa_fixmul16(nz, nz);
        g_slot70 = (unsigned int)sep2;
        if (sep2 >= (int)g_limit80) {
            /* the step would overshoot: cancel it on both nodes */
            g_pendingNodeType = g_currentNodeIdx;
            DualSubFromField();
            if (g_framePauseFlag != 0)
                return;
            g_pendingNodeType = g_xformEntityIdx;
            DualSubFromField();
            return;
        }
    }
    /* commit the node's delta onto the entity's position */
    node = g_currentNodeIdx;
    ent = g_xformEntityIdx;
    dx = (int)MK4_NODE_AT(unsigned int, node, 0x6c);
    g_slot74 = (unsigned int)dx;
    dx += (int)MK4_NODE_AT(unsigned int, ent, 0x54);
    g_slot78 = (unsigned int)dx;
    MK4_NODE_AT(unsigned int, ent, 0x54) = (unsigned int)dx;
    dz = (int)MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x74);
    ent = g_xformEntityIdx;
    g_slot74 = (unsigned int)dz;
    dz += (int)MK4_NODE_AT(unsigned int, ent, 0x5c);
    g_slot78 = (unsigned int)dz;
    MK4_NODE_AT(unsigned int, ent, 0x5c) = (unsigned int)dz;
}

void Applier1_004899f0(void)
{
    unsigned int node = g_currentNodeIdx, ent = g_xformEntityIdx;
    unsigned int l84 = g_limit84, l80 = g_limit80;

    g_pendingNodeType = node;
    g_xformEntityIdx = node;
    g_currentNodeIdx = ent;
    g_walkSlot6c = l80;
    g_limit80 = l84;
    g_limit84 = l80;
    PositionClampCluster();          /* jmp in the original */
}

void Applier3_00489ba0(void)
{
    unsigned int node = g_currentNodeIdx, ent;
    int nx, nz, ax, az;

    nx = (int)MK4_NODE_AT(unsigned int, node, 0x54);
    nz = (int)MK4_NODE_AT(unsigned int, node, 0x5c);
    ax = (int)g_axisPosX;
    az = (int)g_axisPosY;
    g_walkSlot6c = (unsigned int)nx;
    g_slot70 = (unsigned int)nz;
    g_slot74 = (unsigned int)ax;
    g_slot78 = (unsigned int)az;

    ax = pa_fixmul16(0x6666, ax);
    g_slot74 = (unsigned int)ax;
    az = pa_fixmul16(0x6666, az);
    g_slot78 = (unsigned int)az;

    nx += ax;
    nz += az;
    ent = g_xformEntityIdx;
    g_walkSlot6c = (unsigned int)nx;
    g_slot70 = (unsigned int)nz;
    MK4_NODE_AT(unsigned int, ent, 0x54) = (unsigned int)nx;
    MK4_NODE_AT(unsigned int, g_xformEntityIdx, 0x5c) = (unsigned int)nz;

    g_pendingNodeType = g_currentNodeIdx;
    DualSubFromField();
    if (g_framePauseFlag != 0)
        return;
    g_pendingNodeType = g_xformEntityIdx;
    DualSubFromField();              /* jmp in the original */
}

#endif /* NON_MATCHING */
