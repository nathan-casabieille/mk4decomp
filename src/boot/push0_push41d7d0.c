/**
 * Auto-split from misc_matches8.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x0041d550 (16b): push 0; push DATA_PTR; call F; add esp,8; ret */
extern int __cdecl func_0049eb40(void *, int);
extern void *g_dispatchSave1135_0041d7d0;
void Push0_Push41d7d0_0041d550(void) {
    func_0049eb40(&g_dispatchSave1135_0041d7d0, 0);
}
