/**
 * Auto-split from misc_matchesPP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;

/* @addr 0x0048fee0 (68b)
 *   call F1; pause → ret; swap g_walkCallback ↔ g_xformEntityIdx;
 *   call F2; pause → ret; call F3; pause → ret; jmp T.
 */
extern void StateDispatchTable(void);
extern void BootFrameSetup(void);
extern void GuardedChainCmpDualBitXor(void);
extern void ScaledMove48to58(void);
void GuardedTripleCallSwapJmp_0048fee0(void) {
    unsigned int saved;
    StateDispatchTable();
    if (g_framePauseFlag != 0) {
        return;
    }
    saved = (unsigned int)g_walkCallback;
    g_walkCallback = (void (*)(void))0;
    g_xformEntityIdx = saved;
    BootFrameSetup();
    if (g_framePauseFlag != 0) {
        return;
    }
    GuardedChainCmpDualBitXor();
    if (g_framePauseFlag != 0) {
        return;
    }
    ScaledMove48to58();
}
