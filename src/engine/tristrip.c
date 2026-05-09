/**
 * Triangle-strip vertex ring buffer.
 *
 * The renderer keeps two parallel 3-element rings (the "A" ring of
 * 32-bit indices and the "B" ring of likewise) plus three 16-bit
 * "x-coord" slots that get rotated forward each call.
 */
#include "types.h"

extern s32 g_triStripRingA[3];      /* 0x007af9b4..0x007af9bc */
extern s32 g_triStripRingB[3];      /* 0x007af984..0x007af98c */
extern s16 g_triStripX0;            /* 0x007af95c */
extern s16 g_triStripX1;            /* 0x007af962 */
extern s16 g_triStripX2;            /* 0x007af968 */

/*
 * Shift both 3-slot rings forward by one (oldest is dropped, newest
 * stays, middle becomes oldest), then write the three caller-supplied
 * 16-bit values into the dedicated x-coord slots.
 *
 * @addr 0x004b2fa0
 */
void AdvanceTriStripRing(s16 v0, s16 v1, s16 v2)
{
    g_triStripRingA[0] = g_triStripRingA[1];
    g_triStripRingA[1] = g_triStripRingA[2];
    g_triStripRingB[0] = g_triStripRingB[1];
    g_triStripRingB[1] = g_triStripRingB[2];
    g_triStripX0 = v0;
    g_triStripX1 = v1;
    g_triStripX2 = v2;
}
