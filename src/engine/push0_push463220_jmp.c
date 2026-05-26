/**
 * Auto-split from misc_matches8.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00463070 (20b): push 0; push 0x00463220; call F; add esp,8; jmp +0x0c */
extern int StoreTwoCall_0049cb40(int, void *);
extern void *g_dispatchSave1149_00463220;
extern void PoseFnInstallDualCluster_00463090(void);
void Push0_Push463220_Jmp_00463070(void) {
    StoreTwoCall_0049cb40((int)&g_dispatchSave1149_00463220, 0);
    PoseFnInstallDualCluster_00463090();
}
