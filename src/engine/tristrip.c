/**
 * Triangle-strip vertex ring buffer.
 *
 * The renderer keeps two parallel 3-element rings (the "A" ring of
 * 32-bit indices and the "B" ring of likewise) plus three 16-bit
 * "x-coord" slots that get rotated forward each call.
 */
#include "types.h"

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern s32 g_triStripRingA[3];      /* 0x007af9b4..0x007af9bc */
extern s32 g_triStripRingB[3];      /* 0x007af984..0x007af98c */
extern s16 g_triStripX0;            /* 0x007af95c */
extern s16 g_triStripX1;            /* 0x007af962 */
extern s16 g_triStripX2;            /* 0x007af968 */
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_triStripRingA ((int *)MK4_VA(int, 0x7af9b4u))
#define g_triStripRingB ((int *)MK4_VA(int, 0x7af984u))
#define g_triStripX0 (*(short *)MK4_VA(short, 0x7af95cu))
#define g_triStripX1 (*(short *)MK4_VA(short, 0x7af962u))
#define g_triStripX2 (*(short *)MK4_VA(short, 0x7af968u))
#endif


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
