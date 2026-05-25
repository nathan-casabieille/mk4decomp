/**
 * Auto-split from misc_matchesPP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;
extern unsigned int g_baseSel_00542060;

/* @addr 0x004463b0 (75b)
 *   Slot field swap: copies [g_baseSel*4+0x4c]→g_scaledInit;
 *   [g_eventQueueIdx*4+0x3c]→walk; copies into eax-slot+0x3c.
 *   Then re-reads idx slot's +0x3c → walk and back into ecx-slot.
 */
void SlotFieldSwap3c_004463b0(void) {
    unsigned int idx;
    unsigned int v;
    idx = *(unsigned int *)(g_baseSel_00542060 * 4 + 0x4c);
    g_scaledInit_00542044 = idx;
    v = *(unsigned int *)(g_eventQueueIdx * 4 + 0x3c);
    g_walkCallback = (void (*)(void))v;
    *(unsigned int *)(idx * 4 + 0x3c) = v;
    v = *(unsigned int *)(g_eventQueueIdx * 4 + 0x3c);
    g_walkCallback = (void (*)(void))v;
    *(unsigned int *)(g_scaledInit_00542044 * 4 + 0x3c) = v;
}
