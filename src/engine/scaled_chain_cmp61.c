/**
 * Auto-split from misc_matchesZ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00482740 (62b)
 *   3-level scaled chain (0x3c, 0x30, 0); cmp 0x61 → jmp T1; cmp 0x69 → jmp T2.
 */
extern void StageGameProgressCluster_00482780(void);
extern void Wrapper_0048a360(void);
void ScaledChainCmp61_00482740(void) {
    unsigned int v;
    v = *(unsigned int *)(g_baseSel_00542060 * 4 + 0x3c);
    g_scaledInit_00542044 = v;
    v = *(unsigned int *)(v * 4 + 0x30);
    g_scaledInit_00542044 = v;
    v = *(unsigned int *)(v * 4);
    g_walkCallback = (void (*)(void))v;
    if (v == 0x61) {
        StageGameProgressCluster_00482780();
        return;
    }
    if (v == 0x69) {
        return;
    }
    Wrapper_0048a360();
}
