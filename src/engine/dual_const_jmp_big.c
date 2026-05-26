/**
 * Auto-split from misc_matches5.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;
extern unsigned int g_baseSel_00542060;

/* @addr 0x0048fbd0 (25b)
 *   mov     [g_walkCallback], 0x00010000
 *   mov     [g_eventQueueCurrent], 0x28
 *   jmp     T
 */
extern void GatedScaledSubSat_0048fb40(void);
void DualConstJmpBig_0048fbd0(void) {
    g_walkCallback = (void(*)(void))0x00010000;
    g_eventQueueCurrent = 0x28;
    GatedScaledSubSat_0048fb40();
}
