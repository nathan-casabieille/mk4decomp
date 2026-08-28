/**
 * Auto-split from misc_matchesEE.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;
#endif

/* @addr 0x004c6510 (45b)
 *   call F; mul-by-N pattern via lea/shl on [eax + 0x14];
 *   ((x * 13 << 4) + x) << 8 - x → effectively x * (13<<12 - 1) etc.
 *   adds 0x269ec3, stores back, returns shr 0x10 & 0x7fff.
 */
extern void *PendingMatch_004c9df0(void);
#ifndef NON_MATCHING /* stale QQ-split copy */
int Crt_rand(void) {
    unsigned char *p = (unsigned char *)PendingMatch_004c9df0();
    unsigned int v = *(unsigned int *)(p + 0x14) * 214013u + 0x269ec3u;
    *(unsigned int *)(p + 0x14) = v;
    return (int)((v >> 16) & 0x7fff);
}
#endif

/* @addr 0x004c67f0 (48b)
 *   if (g_fnptr_0051ffd8) (*g_fnptr_0051ffd8)();
 *   call 0x4c6940(0x4d501c, 0x4d5024); add esp 8;
 *   call 0x4c6940(0x4d5000, 0x4d5018); add esp 8; ret.
 */
extern void (*g_fnptr_0051ffd8)(void);
extern int IterFnPtrs(void *, void *);
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern void *g_dispatchSave550;
extern void *g_dispatchSave549;
extern void *g_dispatchSave548;
extern void *g_dispatchSave547;
#endif
/* CRT-style init pointers, used by ADDRESS - they stay native globals
 * rather than arena aliases. */
extern void *g_dispatchSave547;
extern void *g_dispatchSave548;
extern void *g_dispatchSave549;
extern void *g_dispatchSave550;
extern void (*g_fnptr_0051ffd8)(void);
void _init_premain(void) {
    if (g_fnptr_0051ffd8) g_fnptr_0051ffd8();
    IterFnPtrs(&g_dispatchSave548, &g_dispatchSave547);
    IterFnPtrs(&g_dispatchSave550, &g_dispatchSave549);
}

/* @addr 0x004bd890 (58b)
 *   walk table 0x00ab4e78..0x00ab5034 step 4;
 *   each non-zero entry's deref [eax*4+0] yields word at +4;
 *   if word == arg call F.
 */
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_texAssetIds_ee[];
#endif
extern void GeoLoadFixupLoop(void);
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_dispatchSave1579;
#endif


#ifdef NON_MATCHING
#include "portable/mem_model.h"

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_baseSel (*(unsigned int *)MK4_VA(unsigned int, 0x542060u))
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_dispatchSave1579 (*(unsigned int *)MK4_VA(unsigned int, 0xab5034u))
#define g_dispatchSave547 (*(unsigned int *)MK4_VA(unsigned int, 0x4d5024u))
#define g_dispatchSave548 (*(unsigned int *)MK4_VA(unsigned int, 0x4d501cu))
#define g_dispatchSave549 (*(unsigned int *)MK4_VA(unsigned int, 0x4d5018u))
#define g_dispatchSave550 (*(unsigned int *)MK4_VA(unsigned int, 0x4d5000u))
#define g_fnptr_0051ffd8 (*(unsigned int (**)())MK4_VA(unsigned int, 0x51ffd8u))
#define g_texAssetIds_ee ((unsigned int *)MK4_VA(unsigned int, 0xab4e78u))
#endif
/* NATIVE twin: same walk with the two seams applied - the entries of the
 * 0xab4e78 table are PACKED node indices (deref through MK4_NODE), and the
 * table bound is a VA, so the loop counts entries instead of comparing a
 * host pointer against one. */
void TableWalkBoundedCmp(int arg)
{
    unsigned int i, v, slot;

    for (i = 0; i < (0xab5034u - 0xab4e78u) / 4u; i++) {
        v = *MK4_VA(unsigned int, 0xab4e78u + i * 4u);
        g_currentNodeIdx = v;
        if ((int)v > 0) {
            slot = *MK4_NODE(unsigned int, v);
            if ((int)(unsigned int)*MK4_VA(unsigned short, slot + 4u) == arg)
                GeoLoadFixupLoop();
        }
    }
}
#else
void TableWalkBoundedCmp(int arg) {
    unsigned int *p = g_texAssetIds_ee;
    do {
        unsigned int v = *p;
        g_currentNodeIdx = v;
        if ((int)v > 0) {
            unsigned int slot = *(unsigned int *)(v * 4);
            unsigned int w = (unsigned int)*(unsigned short *)(slot + 4);
            if ((int)w == arg) {
                GeoLoadFixupLoop();
            }
        }
        p++;
    } while ((int)p < (int)&g_dispatchSave1579);
}
#endif

