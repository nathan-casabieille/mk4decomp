/**
 * Auto-split from misc_matchesFF.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00421be0 (61b)
 *   load g_gameCountdown; set g_eventQueueChild = 0x28;
 *   eax = state - 1; if (eax < 0x14) return-tail; else set walk=0x32
 *   call F; pause-test; jmp T.
 */
extern unsigned int g_gameCountdown;
extern void TableLookupCall_g_table_004efa00(void);
extern void PollThenInit(void);
void DecBoundCheckCallJmp(void) {
    int s = (int)g_gameCountdown;
    g_eventQueueChild = 0x28;
    s--;
    g_walkCallback = (void(*)(void))s;
    g_gameCountdown = s;
    if (s < 0x14) {
        g_walkCallback = (void(*)(void))0x32;
        TableLookupCall_g_table_004efa00();
        if (g_framePauseFlag) return;
    }
    PollThenInit();
}
