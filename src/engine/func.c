/**
 * Auto-split from misc_matchesN.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x0042c3b0 (48b)
 *   mov     ecx, [g_fightGroupHead]
 *   mov     eax, 0x0042c3d0
 *   mov     [g_currentNodeIdx], eax
 *   mov     [ecx*4 + 0], eax
 *   ret
 *   nop * 8
 *   mov     eax, 2
 *   mov     [g_walkCallback], eax
 *   mov     [g_phaseTimer], eax
 *   ret
 */
extern unsigned int g_phaseTimer;
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

/* @addr 0x004bd5e0 (1b) one-byte ret stub packed after the wrapper. */
void EmptyRetStub_004bd5e0(void) {}

extern void OrDualStore_0048e4b0(void);

/* @addr 0x00461350 (15b) walk=2 entry */
void func_set_g_walkCallback_then_OrDualStore_00461350(void) {
    g_walkCallback = (void (*)(void))2;
    OrDualStore_0048e4b0();
}
