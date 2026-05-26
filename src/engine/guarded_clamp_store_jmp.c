/**
 * Auto-split from misc_matchesPP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;

/* @addr 0x00428bd0 (77b)
 *   call F1; pause → ret;
 *   edx = g_fightGroupHead; ecx = [edx*4+0x24] → g_scaledInit;
 *   eax = [edx*4+0x28] → walk; ecx = [ecx*4+4]; cmp eax, ecx;
 *   if eax >= ecx: eax = ecx - 1 → walk; store walk → [edx*4+0x28];
 *   jmp T.
 */
extern void CopyJmp_00406ba0(void);
void GuardedClampStoreJmp_00428bd0(void) {
    unsigned int scaled, walk;
    CopyJmp_00406ba0();
    if (g_framePauseFlag) return;
    scaled = ((ScenegraphNode *)(g_fightGroupHead * 4))->queue_end;
    g_scaledInit_00542044 = scaled;
    walk = ((ScenegraphNode *)(g_fightGroupHead * 4))->queue_idx;
    g_walkCallback = (void (*)(void))walk;
    scaled = *(unsigned int *)(scaled * 4 + 4);
    if ((int)walk >= (int)scaled) {
        walk = scaled - 1;
        g_walkCallback = (void (*)(void))walk;
    }
    ((ScenegraphNode *)(g_fightGroupHead * 4))->queue_idx = walk;
    GuardedChainCmpDualBitXor_004299a0();
}
