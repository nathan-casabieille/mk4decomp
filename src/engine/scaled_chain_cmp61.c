/**
 * Auto-split from misc_matchesZ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x00482740 (62b)
 *   3-level scaled chain (0x3c, 0x30, 0); cmp 0x61 → jmp T1; cmp 0x69 → jmp T2.
 */
extern void StageGameProgressCluster(void);
extern void Wrapper_ScaledChainPushCall_004ef868(void);
void ScaledChainCmp61(void) {
    unsigned int v;
    v = ((ScenegraphNode *)(g_baseSel * 4))->child_a;
    g_currentNodeIdx = v;
    v = *(unsigned int *)(v * 4 + 0x30);
    g_currentNodeIdx = v;
    v = *(unsigned int *)(v * 4);
    g_walkCallback = (void (*)(void))v;
    if (v == 0x61) {
        StageGameProgressCluster();
        return;
    }
    if (v == 0x69) {
        return;
    }
    Wrapper_ScaledChainPushCall_004ef868();
}
