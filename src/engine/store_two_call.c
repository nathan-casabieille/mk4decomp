/**
 * Auto-split from misc_matches8.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00421c40 (16b): push 0x71; push DATA_PTR; call F; add esp,8; ret */
extern void StoreTwoCall_0049cb40(int, int);
extern void *g_dispatchSave1150_0048caa0;
void Push71_Push48caa0_00421c40(void) {
    StoreTwoCall_0049cb40(&g_dispatchSave1150_0048caa0, 0x71);
}
