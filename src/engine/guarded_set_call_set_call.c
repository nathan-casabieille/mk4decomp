/**
 * Auto-split from misc_matchesPP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;

/* @addr 0x0047dee0 (67b)
 *   if g_xformScratch2088 == 1, jmp T0; else set walk=2; call F1;
 *   pause → ret; load lit 0xf; push OFFSET g_dispatchSave1305;
 *   set walk and g_phaseTimer = 0xf; call F2; add esp, 4; ret.
 */
extern unsigned int g_phaseTimer;
extern unsigned int g_dispatchSave1305;
extern void AggressorModeCluster(void);
extern void ScaledIndexConditionalAdd(void);
extern int ArgSarStoreJmp(unsigned int *p);
void GuardedSetCallSetCall(void) {
    if (g_xformScratch2088 == 1) {
        AggressorModeCluster();
        return;
    }
    g_walkCallback = (void(*)(void))2;
    ScaledIndexConditionalAdd();
    if (g_framePauseFlag) return;
    g_walkCallback = (void(*)(void))0x0f;
    g_phaseTimer = 0x0f;
    ArgSarStoreJmp(&g_dispatchSave1305);
}
