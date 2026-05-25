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
extern void *g_data_004d5000;
extern void *g_data_004d5018;
extern void *g_data_004d501c;
extern void *g_data_004d5024;
void _init_premain(void) {
    if (g_iat_0051ffd8) g_iat_0051ffd8();
    IterFnPtrs_004c6940(&g_data_004d501c, &g_data_004d5024);
    IterFnPtrs_004c6940(&g_data_004d5000, &g_data_004d5018);
}

/* @addr 0x004bd890 (58b)
 *   walk table 0x00ab4e78..0x00ab5034 step 4;
 *   each non-zero entry's deref [eax*4+0] yields word at +4;
 *   if word == arg call F.
 */
extern unsigned int g_table_004ab4e78_ee[];
extern void GeoLoadFixupLoop_004bd8e0(void);
extern unsigned int g_data_00ab5034;
void TableWalkBoundedCmp_004bd890(int arg) {
    unsigned int *p = g_table_004ab4e78_ee;
    do {
        unsigned int v = *p;
        g_scaledInit_00542044 = v;
        if ((int)v > 0) {
            unsigned int slot = *(unsigned int *)(v * 4);
            unsigned int w = (unsigned int)*(unsigned short *)(slot + 4);
            if ((int)w == arg) {
                GeoLoadFixupLoop_004bd8e0();
            }
        }
        p++;
    } while ((int)p < (int)&g_data_00ab5034);
}
