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

/* @addr 0x004c6ee0 (55b)
 *   call IAT [g_iat_004d216c](0, 0x1000, 0); store result;
 *   if (result == 0) return; call 0x4c70d0;
 *   if (eax == 0) call IAT [g_iat_004d2158](result); xor eax; ret;
 *   else return 1.
 */
extern void * (__stdcall *g_iat_004d216c)(int, int, int);
extern void (__stdcall *g_iat_004d2158)(void *);
extern void * g_state_00fa0ee4;
extern int VirtualHeapAlloc_004c70d0(void);
int CallIATIfThenCall_004c6ee0(void) {
    void *p = g_iat_004d216c(0, 0x1000, 0);
    g_state_00fa0ee4 = p;
    if (p == 0) return 0;
    if (VirtualHeapAlloc_004c70d0() == 0) {
        g_iat_004d2158(g_state_00fa0ee4);
        return 0;
    }
    return 1;
}
