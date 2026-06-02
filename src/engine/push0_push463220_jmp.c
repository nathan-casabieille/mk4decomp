/**
 * Auto-split from misc_matches8.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00463070 (20b): push 0; push 0x00463220; call F; add esp,8; jmp +0x0c */
extern int StoreTwoCall(int, void *);
extern void *g_dispatchSave1149;
extern void PoseFnInstallDualCluster(void);
void Push0_Push463220_Jmp(void) {
    StoreTwoCall((int)&g_dispatchSave1149, 0);
    PoseFnInstallDualCluster();
}
