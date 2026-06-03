/**
 * Auto-split from misc_matchesPP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_currentNodeIdx;

/* @addr 0x00428bd0 (77b)
 *   call F1; pause → ret;
 *   edx = g_fightGroupHead; ecx = [edx*4+0x24] → g_scaledInit;
 *   eax = [edx*4+0x28] → walk; ecx = [ecx*4+4]; cmp eax, ecx;
 *   if eax >= ecx: eax = ecx - 1 → walk; store walk → [edx*4+0x28];
 *   jmp T.
 */
extern void CopyJmp_GuardedChainPushSetCallPop_g_currentNodeIdx(void);
void GuardedClampStoreJmp(void) {
    unsigned int scaled, walk;
    CopyJmp_GuardedChainPushSetCallPop_g_currentNodeIdx();
    if (g_framePauseFlag) return;
    scaled = ((ScenegraphNode *)(g_fightGroupHead * 4))->queue_end;
    g_currentNodeIdx = scaled;
    walk = ((ScenegraphNode *)(g_fightGroupHead * 4))->queue_idx;
    g_walkCallback = (void (*)(void))walk;
    scaled = *(unsigned int *)(scaled * 4 + 4);
    if ((int)walk >= (int)scaled) {
        walk = scaled - 1;
        g_walkCallback = (void (*)(void))walk;
    }
    ((ScenegraphNode *)(g_fightGroupHead * 4))->queue_idx = walk;
    GuardedChainCmpDualBitXor();
}
