/**
 * Auto-split from misc_matches8.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x0041d550 (16b): push 0; push DATA_PTR; call F; add esp,8; ret */
extern int __cdecl StoreTwoCall(void *, int);
extern void *g_dispatchSave1135;
void Push0_Push41d7d0(void) {
    StoreTwoCall(&g_dispatchSave1135, 0);
}
