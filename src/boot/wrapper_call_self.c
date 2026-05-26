/**
 * Auto-split from misc_matchesEE.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004c6510 (45b)
 *   call F; mul-by-N pattern via lea/shl on [eax + 0x14];
 *   ((x * 13 << 4) + x) << 8 - x → effectively x * (13<<12 - 1) etc.
 *   adds 0x269ec3, stores back, returns shr 0x10 & 0x7fff.
 */
extern void *PendingMatch_004c9df0(void);
int Crt_rand(void) {
    unsigned char *p = (unsigned char *)PendingMatch_004c9df0();
    unsigned int v = *(unsigned int *)(p + 0x14) * 214013u + 0x269ec3u;
    *(unsigned int *)(p + 0x14) = v;
    return (int)((v >> 16) & 0x7fff);
}

/* @addr 0x004c67f0 (48b)
 *   if (g_iat_0051ffd8) (*g_iat_0051ffd8)();
 *   call 0x4c6940(0x4d501c, 0x4d5024); add esp 8;
 *   call 0x4c6940(0x4d5000, 0x4d5018); add esp 8; ret.
 */
extern void (*g_iat_0051ffd8)(void);
extern int IterFnPtrs_004c6940(void *, void *);
extern void *g_dispatchSave550_004d5000;
extern void *g_dispatchSave549_004d5018;
extern void *g_dispatchSave548_004d501c;
extern void *g_dispatchSave547_004d5024;
void _init_premain(void) {
    if (g_iat_0051ffd8) g_iat_0051ffd8();
    IterFnPtrs_004c6940(&g_dispatchSave548_004d501c, &g_dispatchSave547_004d5024);
    IterFnPtrs_004c6940(&g_dispatchSave550_004d5000, &g_dispatchSave549_004d5018);
}

/* @addr 0x004c5d70 (55b)
 *   call F to get state; if !state ret;
 *   call 0x4c9200(arg1, arg2, arg3, state); store ret;
 *   call 0x4c7040(state); restore ret; ret.
 */
extern void * HeapScanInit_004c9440(void);
extern int FopenMode_004c9270(int, int, int, void *);
extern void RangePathIATDispatch_004c7060(void *);
int WrapperCallSelf_004c5d70(int a, int b, int c) {
    int ret;
    void *state = HeapScanInit_004c9440();
    if (state == 0) return (int)state;
    ret = FopenMode_004c9270(a, b, c, state);
    RangePathIATDispatch_004c7060(state);
    return ret;
}
