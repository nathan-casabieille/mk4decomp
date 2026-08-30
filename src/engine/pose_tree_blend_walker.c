/**
 * The FORWARD KINEMATICS band - what turns animated bone ANGLES into bone
 * POSITIONS, i.e. what stands between a rotating blob and a silhouette.
 *
 *   PoseTreeBlendWalker (0x49d680, 596b): walk the skeleton list. Per
 *       node: sum the three track deltas (+0x30/34/38) with the anim
 *       rotations (+0x3c/40/44) into the SAVED-NODE vec, sum the two
 *       static angle banks (+0x18..20 and +0x24..2c) through the mod-2pi
 *       clamp into the TRANSFORM vec, then Mul10HeavyTransform builds the
 *       bone matrix and QuadInterpolator applies it to the node's payload
 *       vec at cursor+4. Every non-zero source value first passes
 *       StoreDoubleNegPauseSubStore (the interp/decay helper). The walk
 *       follows *(cursor) links until zero.
 *
 *   Mul10HeavyTransform (0x424bf0, 1277b): three BAM angles at the
 *       xformEntityIdx cursor, each scaled by the blend weight at
 *       0x4d5318, looked up as sin (raw index) and cos (index+0x200
 *       masked 0x7ff) from the tables whose bases live at 0x542028 /
 *       0x54202c, staged as [s0 s1 s2 c0 c1 c2] in the scratch at
 *       *(0x541fa0); then the 3x3 Euler matrix is composed from thirteen
 *       fixmul16 products into the currentNodeIdx cursor (nine words,
 *       cursor rewound by 8 at the end, exactly like the original).
 *
 *   QuadInterpolator (0x425380, 552b): out[0..2] = mat3x3(entity) *
 *       vec3(pending -1..+1), nine fixmul16 in row sums.
 *
 * These were the last hollow pieces under PoseBlendDriver (REAL, called
 * by the approach band). The Ghidra lift of the walker sat OUT of the
 * native list in mul10_heavy_transform.c with raw VA derefs of the
 * (code **) family; this is a fresh arena-safe transcription from the
 * original bytes, statement by statement.
 *
 * NATIVE-ONLY twins: the matching build synthesizes the original bytes.
 */
#ifdef NON_MATCHING

#include "portable/mem_model.h"

extern void MStackPush8(void);
extern void MStackPop8(void);
extern void StoreDoubleNegPauseSubStore(void);
extern void BootMod6487eClampAndChainMul10(void);
extern int  Mul10Tail(int a, int b);

void Mul10HeavyTransform(void);
void QuadInterpolator(void);

#define g_dispatchVar10   (*(unsigned int *)MK4_VA(unsigned int, 0x542028u))
#define g_dispatchVar19   (*(unsigned int *)MK4_VA(unsigned int, 0x54202cu))
#define g_currentNodeIdx  (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_xformEntityIdx  (*(unsigned int *)MK4_VA(unsigned int, 0x542048u))
#define g_pendingNodeType (*(unsigned int *)MK4_VA(unsigned int, 0x54204cu))
#define g_eventQueueTotal (*(unsigned int *)MK4_VA(unsigned int, 0x542050u))
#define g_walkCallback    (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_eventQueueCur   (*(unsigned int *)MK4_VA(unsigned int, 0x542070u))
#define g_lit16_542074    (*(unsigned int *)MK4_VA(unsigned int, 0x542074u))
#define g_chainAccumCur   (*(unsigned int *)MK4_VA(unsigned int, 0x542078u))
#define g_framePauseFlag  (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_matrixStackTop  (*(unsigned int *)MK4_VA(unsigned int, 0x4d57acu))
#define g_dispatchArg     (*(unsigned int *)MK4_VA(unsigned int, 0x535e48u))
#define g_audioVoiceCtr   (*(unsigned int *)MK4_VA(unsigned int, 0x535e50u))
#define g_sincosScratch   (*(unsigned int *)MK4_VA(unsigned int, 0x541fa0u))
#define g_blendWeight     (*(unsigned int *)MK4_VA(unsigned int, 0x4d5318u))
#define g_xformLoopCtr    (*(unsigned int *)MK4_VA(unsigned int, 0x53a1acu))
#define g_dispatchSave6   (*(unsigned int *)MK4_VA(unsigned int, 0x4ffe74u))
#define g_savedNode       (*(unsigned int *)MK4_VA(unsigned int, 0x4ffe78u))
#define g_mul10Var        (*(unsigned int *)MK4_VA(unsigned int, 0x4ffe7cu))
#define g_eventQueueIdx   (*(unsigned int *)MK4_VA(unsigned int, 0x541e70u))
#define g_eventQueueEnd   (*(unsigned int *)MK4_VA(unsigned int, 0x541e74u))

#define MSTACK_AT(i)      (*(unsigned int *)MK4_PTR((i) * 4u))
#define W(i)              (*(unsigned int *)MK4_PTR((unsigned int)(i) * 4u))
#define SW(i)             (*(int *)MK4_PTR((unsigned int)(i) * 4u))

void QuadInterpolator(void)
{
    unsigned int ent = g_xformEntityIdx;
    unsigned int pnt = g_pendingNodeType;
    unsigned int out;
    int t;

    t = Mul10Tail(SW(pnt), SW(ent));
    g_walkCallback = (unsigned int)t;
    pnt++; ent++;
    g_pendingNodeType = pnt;
    g_xformEntityIdx = ent;
    t = Mul10Tail(SW(pnt), SW(ent)) + (int)g_walkCallback;
    ent++;
    g_xformEntityIdx = ent;
    g_lit16_542074 = (unsigned int)t;
    g_walkCallback = (unsigned int)Mul10Tail(*(int *)MK4_PTR(pnt * 4u + 4u), SW(ent));
    g_lit16_542074 = (unsigned int)((int)g_lit16_542074 + (int)g_walkCallback);

    ent++;
    g_xformEntityIdx = ent;
    g_walkCallback = (unsigned int)Mul10Tail(*(int *)MK4_PTR(pnt * 4u - 4u), SW(ent));
    ent++;
    g_xformEntityIdx = ent;
    t = Mul10Tail(SW(pnt), SW(ent)) + (int)g_walkCallback;
    g_chainAccumCur = (unsigned int)t;
    ent++;
    g_xformEntityIdx = ent;
    g_walkCallback = (unsigned int)Mul10Tail(*(int *)MK4_PTR(pnt * 4u + 4u), SW(ent));
    g_chainAccumCur = (unsigned int)((int)g_chainAccumCur + (int)g_walkCallback);

    ent++;
    g_xformEntityIdx = ent;
    g_walkCallback = (unsigned int)Mul10Tail(*(int *)MK4_PTR(pnt * 4u - 4u), SW(ent));
    ent++;
    g_xformEntityIdx = ent;
    t = Mul10Tail(*(int *)MK4_PTR(pnt * 4u + 4u),
                  *(int *)MK4_PTR(ent * 4u + 4u)) + (int)g_walkCallback;
    g_eventQueueCur = (unsigned int)t;
    g_walkCallback = (unsigned int)Mul10Tail(SW(pnt), SW(ent));
    g_eventQueueCur = (unsigned int)((int)g_eventQueueCur + (int)g_walkCallback);

    pnt--;
    g_pendingNodeType = pnt;
    out = g_currentNodeIdx;
    W(out) = g_lit16_542074;
    *(unsigned int *)MK4_PTR(out * 4u + 4u) = g_chainAccumCur;
    *(unsigned int *)MK4_PTR(out * 4u + 8u) = g_eventQueueCur;
}

void Mul10HeavyTransform(void)
{
    unsigned int top, ang, pnt, ent, idx, i, out;
    int t;

    top = g_matrixStackTop + 1; g_matrixStackTop = top; MSTACK_AT(top) = g_xformEntityIdx;
    top = g_matrixStackTop + 1; g_matrixStackTop = top; MSTACK_AT(top) = g_pendingNodeType;
    top = g_matrixStackTop + 1; g_matrixStackTop = top; MSTACK_AT(top) = g_dispatchArg;
    top = g_matrixStackTop + 1; g_matrixStackTop = top; MSTACK_AT(top) = g_audioVoiceCtr;

    g_pendingNodeType = g_sincosScratch;
    top = g_matrixStackTop + 1; g_matrixStackTop = top; MSTACK_AT(top) = g_currentNodeIdx;

    g_eventQueueCur = g_blendWeight;
    g_dispatchArg   = g_dispatchVar10;      /* sin table base (packed) */
    g_audioVoiceCtr = g_dispatchVar19;      /* cos table base (packed) */

    ang = g_xformEntityIdx;
    pnt = g_pendingNodeType;
    for (i = 0; i < 3u; i++) {
        t = Mul10Tail((int)g_eventQueueCur, SW(ang));
        ang++;
        g_xformEntityIdx = ang;
        g_walkCallback = (unsigned int)t;
        idx = (unsigned int)(t >> 16);
        g_currentNodeIdx = idx;
        g_walkCallback = W(idx + g_dispatchArg);           /* sin */
        W(pnt) = g_walkCallback;
        pnt++;
        g_pendingNodeType = pnt;
        idx = (idx + 0x200u) & 0x7ffu;
        g_currentNodeIdx = idx;
        g_walkCallback = W(idx + g_audioVoiceCtr);         /* cos */
        *(unsigned int *)MK4_PTR(pnt * 4u + 8u) = g_walkCallback;
        /* layout after three passes: [s0 s1 s2 c0 c1 c2] */
    }
    g_xformLoopCtr = 0;

    top = g_matrixStackTop;
    out = MSTACK_AT(top);                                 /* the OUT matrix */
    g_matrixStackTop = top - 1;
    g_currentNodeIdx = out;

    pnt -= 2;                                             /* -> s1 */
    g_pendingNodeType = pnt;
    ent = pnt + 3;                                        /* -> c1 */
    g_xformEntityIdx = ent;

#define VS(k)  (*(int *)MK4_PTR((pnt + (k)) * 4u))        /* s1-relative */
#define VC(k)  (*(int *)MK4_PTR((ent + (k)) * 4u))        /* c1-relative */
#define OUTW(v) do { W(out) = (unsigned int)(v); } while (0)

    /* The Euler composition, verified against the ORIGINAL BYTES run under
     * Unicorn with two synthetic angle sets (see the commit message): with
     * s=sin(a0,a1,a2), c=cos(...) the nine outputs are
     *   [ c1c2-s0s1s2   c1s2+s0s1c2   -c0s1 ]
     *   [ -c0s2         c0c2           s0   ]
     *   [ s0c1s2+s1c2   s1s2-s0c1c2    c0c1 ]
     * The scratch globals 0x54206c/70/74/78 are transient between the
     * products in the original; only the outputs and the restored cursors
     * are contractual. */
    {
        int s0 = VS(-1), s1 = VS(0), s2 = VS(1);
        int c0 = VC(-1), c1 = VC(0), c2 = VC(1);
        int s0c1 = Mul10Tail(s0, c1);
        int nc0  = -c0;   /* the original NEGATES BEFORE multiplying - with
                           * floor(>>16) arithmetic fixmul(-c0,s) differs from
                           * -fixmul(c0,s) by one on non-exact products */

        W(out) = (unsigned int)(Mul10Tail(c1, c2)
                                - Mul10Tail(Mul10Tail(s0, s1), s2));
        out++;
        W(out) = (unsigned int)(Mul10Tail(c1, s2)
                                + Mul10Tail(Mul10Tail(s0, s1), c2));
        out++;
        W(out) = (unsigned int)Mul10Tail(nc0, s1);
        out++;
        W(out) = (unsigned int)Mul10Tail(nc0, s2);
        out++;
        W(out) = (unsigned int)Mul10Tail(c0, c2);
        out++;
        W(out) = (unsigned int)s0;
        out++;
        W(out) = (unsigned int)(Mul10Tail(s0c1, s2) + Mul10Tail(s1, c2));
        out++;
        W(out) = (unsigned int)(Mul10Tail(s1, s2) - Mul10Tail(s0c1, c2));
        out++;
        W(out) = (unsigned int)Mul10Tail(c0, c1);
        g_currentNodeIdx = out;
        g_walkCallback = (unsigned int)Mul10Tail(s0c1, c2);
    }

    top = g_matrixStackTop;
    g_audioVoiceCtr = MSTACK_AT(top); top--; g_matrixStackTop = top;
    g_dispatchArg = MSTACK_AT(top); top--; g_matrixStackTop = top;
    g_pendingNodeType = MSTACK_AT(top); top--; g_matrixStackTop = top;
    g_xformEntityIdx = MSTACK_AT(top); top--; g_matrixStackTop = top;

    out -= 8;
    g_currentNodeIdx = out;
}

#undef VS
#undef VC
#undef OUTW

void PoseTreeBlendWalker(void)
{
    unsigned int bone, cur, outA, outB;
    unsigned int v;

    MStackPush8();
    if (g_framePauseFlag != 0)
        return;

    g_eventQueueIdx = g_xformEntityIdx;
    cur = g_currentNodeIdx;
    g_eventQueueEnd = cur;
    g_pendingNodeType = g_savedNode;
    g_eventQueueTotal = g_mul10Var;
    g_walkCallback = cur;
    if (cur == 0)
        goto tail;

    for (;;) {
        bone = g_eventQueueIdx;
        outA = g_pendingNodeType;
        outB = g_eventQueueTotal;

        v = MK4_NODE_AT(unsigned int, bone, 0x3c);
        g_walkCallback = v;
        if (v != 0) {
            StoreDoubleNegPauseSubStore();
            if (g_framePauseFlag != 0) return;
            v = g_walkCallback;
        }
        v += MK4_NODE_AT(unsigned int, bone, 0x30);
        g_walkCallback = v;
        W(outA) = v;

        v = MK4_NODE_AT(unsigned int, bone, 0x40);
        g_walkCallback = v;
        if (v != 0) {
            StoreDoubleNegPauseSubStore();
            if (g_framePauseFlag != 0) return;
            v = g_walkCallback;
        }
        v += MK4_NODE_AT(unsigned int, bone, 0x34);
        g_walkCallback = v;
        *(unsigned int *)MK4_PTR(outA * 4u + 4u) = v;

        v = MK4_NODE_AT(unsigned int, bone, 0x44);
        g_walkCallback = v;
        if (v != 0) {
            StoreDoubleNegPauseSubStore();
            if (g_framePauseFlag != 0) return;
            v = g_walkCallback;
        }
        v += MK4_NODE_AT(unsigned int, bone, 0x38);
        g_walkCallback = v;
        *(unsigned int *)MK4_PTR(outA * 4u + 8u) = v;

        v = MK4_NODE_AT(unsigned int, bone, 0x24);
        g_walkCallback = v;
        if (v != 0) {
            StoreDoubleNegPauseSubStore();
            if (g_framePauseFlag != 0) return;
            v = g_walkCallback;
        }
        g_walkCallback = v + MK4_NODE_AT(unsigned int, bone, 0x18);
        BootMod6487eClampAndChainMul10();
        if (g_framePauseFlag != 0) return;
        W(outB) = g_walkCallback;

        v = MK4_NODE_AT(unsigned int, bone, 0x28);
        g_walkCallback = v;
        if (v != 0) {
            StoreDoubleNegPauseSubStore();
            if (g_framePauseFlag != 0) return;
            v = g_walkCallback;
        }
        g_walkCallback = v + MK4_NODE_AT(unsigned int, bone, 0x1c);
        BootMod6487eClampAndChainMul10();
        if (g_framePauseFlag != 0) return;
        *(unsigned int *)MK4_PTR(outB * 4u + 4u) = g_walkCallback;

        v = MK4_NODE_AT(unsigned int, bone, 0x2c);
        g_walkCallback = v;
        if (v != 0) {
            StoreDoubleNegPauseSubStore();
            if (g_framePauseFlag != 0) return;
            v = g_walkCallback;
        }
        g_walkCallback = v + MK4_NODE_AT(unsigned int, bone, 0x20);
        BootMod6487eClampAndChainMul10();
        if (g_framePauseFlag != 0) return;
        *(unsigned int *)MK4_PTR(outB * 4u + 8u) = g_walkCallback;

        g_currentNodeIdx = g_dispatchSave6;
        g_xformEntityIdx = g_eventQueueTotal;
        Mul10HeavyTransform();
        if (g_framePauseFlag != 0) return;

        g_xformEntityIdx = g_currentNodeIdx;
        g_currentNodeIdx = g_eventQueueEnd + 4u;
        QuadInterpolator();
        if (g_framePauseFlag != 0) return;

        cur = W(g_eventQueueEnd);
        g_walkCallback = cur;
        g_eventQueueEnd = cur;
        if (cur == 0)
            break;
    }

tail:
    g_currentNodeIdx = cur = g_walkCallback;
    g_xformEntityIdx = g_eventQueueIdx;
    MStackPop8();
}

#endif /* NON_MATCHING */
