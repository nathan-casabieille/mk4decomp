/**
 * Auto-split from misc_matchesPP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;

/* @addr 0x0047dee0 (67b)
 *   if g_xformScratch2088 == 1, jmp T0; else set walk=2; call F1;
 *   pause → ret; load lit 0xf; push OFFSET g_data_004ed4e0;
 *   set walk and g_x_00537e94_v2 = 0xf; call F2; add esp, 4; ret.
 */
extern unsigned int g_x_00537e94_v2;
extern unsigned int g_data_004ed4e0;
extern void AggressorModeCluster_0047df30(void);
extern void ScaledIndexConditionalAdd_0048e400(void);
extern int ArgSarStoreJmp_004594f0(unsigned int *p);
void GuardedSetCallSetCall_0047dee0(void) {
    if (g_xformScratch2088 == 1) {
        AggressorModeCluster_0047df30();
        return;
    }
    g_walkCallback = (void(*)(void))2;
    ScaledIndexConditionalAdd_0048e400();
    if (g_framePauseFlag) return;
    g_walkCallback = (void(*)(void))0x0f;
    g_x_00537e94_v2 = 0x0f;
    ArgSarStoreJmp_004594f0(&g_data_004ed4e0);
}
