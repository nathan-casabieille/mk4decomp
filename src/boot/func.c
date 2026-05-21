/**
 * Auto-split from misc_matchesN.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004111f0 (18b): set g_eventQueueIdx = (0x004d5c20>>2); tail-jmp
 * func_00411202 (= PendingMatch_00411210). The 4-byte nop gap before this
 * entry is filled by 0x90-fill. Referenced from g_data_004d5818 in data.c. */
void func_004111f0(void) {
    g_eventQueueIdx = (unsigned int)&g_data_004d5c20 >> 2;
    func_00411202();
}
