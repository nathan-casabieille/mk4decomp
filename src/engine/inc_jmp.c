/**
 * Auto-split from misc_matchesB.c
 */
#include "engine/scenegraph.h"

extern unsigned int g_scaledInit_00542044;

/* @addr 0x0045e1d0 (11b)
 *   inc     dword ptr [g_scaledInit_00542044]
 *   jmp     +5
 */
extern void EventGateCluster(void);
void IncJmp(void) {
    g_scaledInit_00542044++;
    EventGateCluster();
}
