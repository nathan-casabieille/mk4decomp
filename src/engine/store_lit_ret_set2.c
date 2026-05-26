/**
 * Auto-split from misc_matchesN.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;
extern void func_0042c3d0(void);

/* @addr 0x0042c3b0 (24b): store OFFSET func_0042c3d0 (entry B at +0x20)
 * to g_scaledInit_00542044 and fightGroupHead chain[+0x44]. Entry A of
 * the original 48-byte packed block; entry B at +0x20 lives in
 * func_0042c3d0. The 8-byte nop gap is filled by 0x90-fill. */
void StoreLitRetSet2_0042c3b0(void) {
    unsigned int addr = (unsigned int)&func_0042c3d0;
    g_scaledInit_00542044 = addr;
    ((ScenegraphNode *)(g_fightGroupHead * 4))->child_c = addr;
}
