/**
 * Auto-extracted during misc_matches reorganization.
 */
#include "engine/scenegraph.h"

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

