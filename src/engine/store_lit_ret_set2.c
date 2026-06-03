/**
 * Auto-split from misc_matchesN.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;
extern void StoreLitRetSet2_EntryB_SetWalk2Phase2_0042c3d0(void);

/* @addr 0x0042c3b0 (24b): store OFFSET StoreLitRetSet2_EntryB_SetWalk2Phase2_0042c3d0 (entry B at +0x20)
 * to g_currentNodeIdx and fightGroupHead chain[+0x44]. Entry A of
 * the original 48-byte packed block; entry B at +0x20 lives in
 * StoreLitRetSet2_EntryB_SetWalk2Phase2_0042c3d0. The 8-byte nop gap is filled by 0x90-fill. */
void StoreLitRetSet2(void) {
    unsigned int addr = (unsigned int)&StoreLitRetSet2_EntryB_SetWalk2Phase2_0042c3d0;
    g_currentNodeIdx = addr;
    ((ScenegraphNode *)(g_fightGroupHead * 4))->child_c = addr;
}
