/**
 * Auto-split from misc_matches4.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x00439c40 (29b): same as above but mask=1, jne */
extern void CmpEqWalkSetCallToggleDirty(void);
extern void ScaledAddrInit_InstallSelfMStackPushDispatch(void);
void GDispatch1_CmpEqWalkSetCallToggleDirty_then_ScaledAddrInit_InstallSelfMStackPushDispatch(void) {
    CmpEqWalkSetCallToggleDirty();
    if (g_framePauseFlag) return;
    if (g_xformDirtyFlags & 1) return;
    ScaledAddrInit_InstallSelfMStackPushDispatch();
}

/* @addr 0x00488da0 (29b): mask=1, je (skip-then-jmp) */
extern void DualCondMatchSet(void);
extern void ScaledInitWithCounterAndType_004314f0(void);
void GDispatch1_DualCondMatchSet_then_ScaledInitWithCounterAndType(void) {
    DualCondMatchSet();
    if (g_framePauseFlag) return;
    if (!(g_xformDirtyFlags & 1)) return;
    ScaledInitWithCounterAndType_004314f0();
}
