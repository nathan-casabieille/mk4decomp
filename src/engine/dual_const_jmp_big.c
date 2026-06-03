/**
 * Auto-split from misc_matches5.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_currentNodeIdx;
extern unsigned int g_baseSel;

/* @addr 0x0048fbd0 (25b)
 *   mov     [g_walkCallback], 0x00010000
 *   mov     [g_eventQueueCurrent], 0x28
 *   jmp     T
 */
extern void GatedScaledSubSat(void);
void DualConstJmpBig(void) {
    g_walkCallback = (void(*)(void))0x00010000;
    g_eventQueueCurrent = 0x28;
    GatedScaledSubSat();
}
