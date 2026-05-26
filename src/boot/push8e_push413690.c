/**
 * Auto-split from misc_matches8.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00413560 (19b): push 0x8e; push DATA_PTR; call F; add esp,8; ret */
extern void *g_dispatchSave1133_00413690;
void Push8e_Push413690_00413560(void) {
    StoreTwoCall_0049cb40(&g_dispatchSave1133_00413690, 0x8e);
}
