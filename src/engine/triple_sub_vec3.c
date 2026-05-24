/**
 * Auto-split from misc_matchesX.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;
extern u32 g_eventQueueWorkType;
extern packed_ptr g_xformEntityIdx;
extern u32 g_pendingNodeType;
extern const int g_sinTable[];
extern void Mul10Tail_00404af0(void);

/* @addr 0x004250f0 (61b)
 *   3-component vector subtract: out[i] = a[i] - b[i] across i=0,1,2
 *   a = [g_xformEntityIdx*4], b = [g_pendingNodeType*4],
 *   out = [g_currentNodeIdx*4]
 */
void TripleSubVec3_004250f0(void) {
    unsigned int op = g_scaledInit_00542044;
    unsigned int ap = g_xformEntityIdx;
    unsigned int bp = g_pendingNodeType;
    ap <<= 2;
    bp <<= 2;
    op <<= 2;
    *(int *)op = *(int *)ap - *(int *)bp;
    *((int *)op + 1) = *((int *)ap + 1) - *((int *)bp + 1);
    *((int *)op + 2) = *((int *)ap + 2) - *((int *)bp + 2);
}
