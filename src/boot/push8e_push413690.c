/**
 * Auto-split from misc_matches8.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x00413560 (19b): push 0x8e; push DATA_PTR; call F; add esp,8; ret */
extern void *g_dispatchSave1133;
void Push8e_Push413690(void) {
    StoreTwoCall(&g_dispatchSave1133, 0x8e);
}
