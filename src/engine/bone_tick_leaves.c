/**
 * The leaf helpers under the Phase4 bone-init band - the small pieces the
 * head block (0x4130c0) and the bone ticks call. All were weak stubs (or
 * absent) until now; each is a straight transcription of the original.
 *
 * ChainListVecAdd - 0x0049d200 (196b): the velocity integrator. Walks the
 *   record chain hanging off node+0x2c and adds each record's +0x10/+0x14/
 *   +0x18 (velocity) into its +4/+8/+0xc (position), bracketing
 *   g_xformEntityIdx on the mstack. Gated on the mode word 0x543800.
 *
 * MStackPushNegMul10 - 0x0040a690 (152b): launch-vector scaler. Takes the
 *   magnitude in 0x54206c, negates it into 0x542078, resolves the angle of
 *   the node at 0x52ab10 (its +0x64 field) through MStackPush1MagicMod2
 *   (sin -> 0x54206c, cos -> 0x542070), then scales both by the negated
 *   magnitude with Mul10Tail. Brackets g_currentNodeIdx on the mstack; the
 *   pause path leaks the push, as the originals do.
 *
 * MStackPush1MagicMod2 - 0x004244d0 (216b): angle wrap + sin/cos lookup.
 *   Wraps 0x542074 into [0, 2pi) in 16.16 (2pi = 0x6487e) using the
 *   0xa2f99905 >> 50 magic reciprocal, converts to a table index via
 *   Mul10Tail(0x145f305, ang) (2048/2pi in 16.16), then reads
 *   sin = table[0x542028 + i] into 0x54206c and
 *   cos = table[((i + 0x200) & 0x7ff) + 0x54202c] into 0x542070.
 *   The sin index is deliberately unmasked, as in the original.
 *
 * ThreeChanPackClamp - 0x00404cc0 (142b, cdecl int arg): unpacks a
 *   0xRRGGBB word into three 8.8 channels, adds them into the 16-bit
 *   accumulators at 0xab4e44/48/4c, clamps each to 0xfe00, and zeroes the
 *   dword vector at 0xab4e50/54/58. The accumulators are WORD-wide and
 *   the vector is DWORD-wide - the access widths below are the binary's.
 *
 * CopyThreeFields - 0x00404df0 (47b, cdecl int arg): copies the node's
 *   +0x54/+0x58/+0x5c position into the 0xab4e50/54/58 vector.
 *
 * NATIVE-ONLY twins: the matching build synthesizes the original bytes.
 */
#ifdef NON_MATCHING

#include "portable/mem_model.h"

extern int Mul10Tail(int a, int b);
extern void BootMod6487eClampAndChainMul10(void);

#define g_currentNodeIdx   (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_xformEntityIdx   (*(unsigned int *)MK4_VA(unsigned int, 0x542048u))
#define g_walkCallback     (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_eventQueueCur    (*(unsigned int *)MK4_VA(unsigned int, 0x542070u))
#define g_angle542074      (*(int *)MK4_VA(int, 0x542074u))
#define g_negMag542078     (*(int *)MK4_VA(int, 0x542078u))
#define g_sinBase542028    (*(unsigned int *)MK4_VA(unsigned int, 0x542028u))
#define g_cosBase54202c    (*(unsigned int *)MK4_VA(unsigned int, 0x54202cu))
#define g_framePauseFlag   (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_matrixStackTop   (*(unsigned int *)MK4_VA(unsigned int, 0x4d57acu))
#define g_gate543800       (*(unsigned int *)MK4_VA(unsigned int, 0x543800u))
#define g_xformDirtyFlags  (*(unsigned int *)MK4_VA(unsigned int, 0x54208cu))
#define g_launchSrc52ab10  (*(unsigned int *)MK4_VA(unsigned int, 0x52ab10u))
#define g_scale4d5318      (*(unsigned int *)MK4_VA(unsigned int, 0x4d5318u))

#define g_chanR            (*(unsigned short *)MK4_VA(unsigned short, 0xab4e44u))
#define g_chanG            (*(unsigned short *)MK4_VA(unsigned short, 0xab4e48u))
#define g_chanB            (*(unsigned short *)MK4_VA(unsigned short, 0xab4e4cu))
#define g_vec4e50          (*(unsigned int *)MK4_VA(unsigned int, 0xab4e50u))
#define g_vec4e54          (*(unsigned int *)MK4_VA(unsigned int, 0xab4e54u))
#define g_vec4e58          (*(unsigned int *)MK4_VA(unsigned int, 0xab4e58u))

#define W(i)               (*(unsigned int *)MK4_PTR((unsigned int)(i) * 4u))
#define NODE_W(n,off)      MK4_NODE_AT(unsigned int, (n), (off))

/* The second packed entry of BootMod6487eClampAndChainMul10's symbol
 * (0x00407560, inside the 261b at 0x407510) - the MOTION INTEGRATOR the
 * trace kept reporting as an unresolved code VA: position += velocity
 * (+0x54..+0x5c += +0x6c..+0x74), then heading += angular velocity
 * (+0x60..+0x68 += +0x78..+0x80) with each component wrapped into
 * [0, 2pi) by the first entry. Clears dirty bit 0 on the way out. */
void MotionIntegrate_00407560(void)
{
    unsigned int node = g_currentNodeIdx;
    int i;

    for (i = 0; i < 3; i++)
        MK4_NODE_AT(unsigned int, node, 0x54 + i * 4) +=
            MK4_NODE_AT(unsigned int, node, 0x6c + i * 4);

    node = g_currentNodeIdx;
    for (i = 0; i < 3; i++) {
        g_walkCallback = MK4_NODE_AT(unsigned int, node, 0x60 + i * 4)
                       + MK4_NODE_AT(unsigned int, node, 0x78 + i * 4);
        BootMod6487eClampAndChainMul10();
        MK4_NODE_AT(unsigned int, node, 0x60 + i * 4) = g_walkCallback;
    }
    g_xformDirtyFlags &= 0xfffffffeu;
}

void ChainListVecAdd(void)
{
    unsigned int rec, top;

    if (g_gate543800 != 0)
        return;
    rec = NODE_W(g_currentNodeIdx, 0x2c);
    g_walkCallback = rec;
    if (rec == 0)
        return;

    top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    W(top) = g_xformEntityIdx;

    do {
        g_xformEntityIdx = rec;
        NODE_W(rec, 4)   += NODE_W(rec, 0x10);
        NODE_W(rec, 8)   += NODE_W(rec, 0x14);
        NODE_W(rec, 0xc) += NODE_W(rec, 0x18);
        rec = W(rec);
        g_walkCallback = rec;
    } while (rec != 0);

    top = g_matrixStackTop;
    g_xformEntityIdx = W(top);
    g_matrixStackTop = top - 1;
}

void MStackPush1MagicMod2(void)
{
    unsigned int top, i, idx;
    int ang;

    top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    W(top) = g_currentNodeIdx;

    ang = g_angle542074;
    if (ang < 0) {
        unsigned int n = (unsigned int)
            (((unsigned long long)(0x6487du - (unsigned int)ang) *
              0xa2f99905ull) >> 50);
        ang += (int)(n * 0x6487eu);
        g_angle542074 = ang;
    }
    if (ang >= 0x6487e) {
        unsigned int n = (unsigned int)
            (((unsigned long long)(unsigned int)ang * 0xa2f99905ull) >> 50);
        do {
            ang -= 0x6487e;
        } while (--n != 0);
        g_angle542074 = ang;
    }

    g_walkCallback = (unsigned int)ang;
    idx = (unsigned int)Mul10Tail((int)g_scale4d5318, ang);
    g_walkCallback = idx;
    i = (unsigned int)((int)idx >> 16);

    g_currentNodeIdx = ((i + 0x200u) & 0x7ffu) + g_cosBase54202c;
    g_eventQueueCur = W(g_currentNodeIdx);
    g_currentNodeIdx = g_sinBase542028 + i;
    g_walkCallback = W(g_currentNodeIdx);

    top = g_matrixStackTop;
    g_currentNodeIdx = W(top);
    g_matrixStackTop = top - 1;
}

void MStackPushNegMul10(void)
{
    unsigned int top, src;
    int d;

    top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    W(top) = g_currentNodeIdx;

    d = -(int)g_walkCallback;
    g_negMag542078 = d;
    src = g_launchSrc52ab10;
    g_currentNodeIdx = src;
    g_angle542074 = (int)NODE_W(src, 0x64);
    MStackPush1MagicMod2();
    if (g_framePauseFlag != 0)
        return;                         /* abort: the push leaks */

    g_walkCallback = (unsigned int)Mul10Tail(g_negMag542078,
                                             (int)g_walkCallback);
    g_eventQueueCur = (unsigned int)Mul10Tail(g_negMag542078,
                                              (int)g_eventQueueCur);

    top = g_matrixStackTop;
    g_currentNodeIdx = W(top);
    g_matrixStackTop = top - 1;
}

void ThreeChanPackClamp(int arg)
{
    unsigned int r = ((unsigned int)(arg >> 8)) & 0xffffff00u;
    unsigned int g = (((unsigned int)(arg >> 8)) & 0xffu) << 8;
    unsigned int b = ((unsigned int)arg & 0xffu) << 8;

    r += g_chanR;
    g += g_chanG;
    b += g_chanB;
    if (r > 0xfe00u) r = 0xfe00u;
    if (g > 0xfe00u) g = 0xfe00u;
    if (b > 0xfe00u) b = 0xfe00u;
    g_chanG = (unsigned short)g;
    g_chanR = (unsigned short)r;
    g_chanB = (unsigned short)b;
    g_vec4e58 = 0;
    g_vec4e54 = 0;
    g_vec4e50 = 0;
}

void CopyThreeFields(int group)
{
    if (group != 0) {
        g_vec4e50 = NODE_W((unsigned int)group, 0x54);
        g_vec4e54 = NODE_W((unsigned int)group, 0x58);
        g_vec4e58 = NODE_W((unsigned int)group, 0x5c);
    }
}

#endif /* NON_MATCHING */
