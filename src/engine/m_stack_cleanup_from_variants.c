/**
 * Auto-split from misc_matchesT.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x004384a0 (5b) packed mstack-pop-callback tail-jmp wrapper. */
void MStackCleanupFrom_StackPopDispatchTagged_004384a0(void) {
    StackPopDispatchTagged();
}

/* @addr 0x004384e0 (5b) packed mstack-pop-callback tail-jmp wrapper. */
void MStackCleanupFrom_StackPopDispatchTagged_004384e0(void) {
    StackPopDispatchTagged();
}

/* @addr 0x00438520 (5b) packed mstack-pop-callback tail-jmp wrapper. */
void MStackCleanupFrom_StackPopDispatchTagged_00438520(void) {
    StackPopDispatchTagged();
}
