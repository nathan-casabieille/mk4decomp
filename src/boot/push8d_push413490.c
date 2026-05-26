/**
 * Auto-split from misc_matches8.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00413360 (19b): push 0x8d; push DATA_PTR; call F; add esp,8; ret */
extern int __cdecl StoreTwoCall_0049cb40(void *, int);
extern void *g_dispatchSave1132_00413490;
void Push8d_Push413490_00413360(void) {
    StoreTwoCall_0049cb40(&g_dispatchSave1132_00413490, 0x8d);
}
