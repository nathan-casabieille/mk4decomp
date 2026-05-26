/**
 * Auto-split from misc_matches4.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00439c40 (29b): same as above but mask=1, jne */
extern void CmpEqWalkSetCallToggleDirty_00439c60(void);
extern void ScaledAddrInit_004368f0(void);
void GDispatch1_00439c40(void) {
    CmpEqWalkSetCallToggleDirty_00439c60();
    if (g_framePauseFlag) return;
    if (g_xformDirtyFlags & 1) return;
    ScaledAddrInit_004368f0();
}

/* @addr 0x00488da0 (29b): mask=1, je (skip-then-jmp) */
extern void DualCondMatchSet_00488dc0(void);
extern void ScaledInitWithCounterAndType_004314f0(void);
void GDispatch1_00488da0(void) {
    DualCondMatchSet_00488dc0();
    if (g_framePauseFlag) return;
    if (!(g_xformDirtyFlags & 1)) return;
    ScaledInitWithCounterAndType_004314f0();
}
