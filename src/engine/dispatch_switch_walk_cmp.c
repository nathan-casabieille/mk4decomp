/**
 * Auto-split from misc_matchesPP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_currentNodeIdx;

/* @addr 0x00438bf0 (72b)
 *   eax = baseSel*4+0x34; walk = eax;
 *   if eax == 0x10: walk = 2; if eax == 0x11: walk = 7;
 *   if eax == 5 or 6: jmp T1; else jmp T2.
 *   The `if==X then walk=N` arms keep eax intact for next cmp.
 */
extern unsigned int g_baseSel;
extern void Wrapper_CmpDualPatchScaledRangeJmp_004e4850(void);
extern void Wrapper_CmpDualPatchScaledRangeJmp_004e4990(void);
void DispatchSwitchWalkCmp(void) {
    unsigned int v = ((ScenegraphNode *)(g_baseSel * 4))->state_mask;
    g_walkCallback = (void (*)(void))v;
    if (v == 0x10) {
        v = 2;
        g_walkCallback = (void (*)(void))v;
    }
    if (v == 0x11) {
        v = 7;
        g_walkCallback = (void (*)(void))v;
    }
    if (v == 5) {
        Wrapper_CmpDualPatchScaledRangeJmp_004e4850();
        return;
    }
    if (v == 6) {
        Wrapper_CmpDualPatchScaledRangeJmp_004e4850();
        return;
    }
    Wrapper_CmpDualPatchScaledRangeJmp_004e4990();
}
