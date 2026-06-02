/**
 * Auto-split from misc_matchesKK.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_scaledInit_00542044;

/* === ScaledInitOrSelfPtrSetType cluster (68b each) === */

/* @addr 0x00482be0 (68b): set 1, call F1, pause, set 0x9999, call F2, pause, call F3, pause, jmp T */
extern void TableLookupCall_0048a160(void);
extern void CmpP1DualInitStore_00482ab0(void);
extern void CjTableThresholdDispatch(void);
extern void CrouchFsmCluster(void);
void CallPauseFourSet(void) {
    g_walkCallback = (void (*)(void))1;
    TableLookupCall_0048a160();
    if (g_framePauseFlag != 0) return;
    g_walkCallback = (void (*)(void))0x9999;
    CmpP1DualInitStore_00482ab0();
    if (g_framePauseFlag != 0) return;
    CjTableThresholdDispatch();
    if (g_framePauseFlag != 0) return;
    CrouchFsmCluster();
}
