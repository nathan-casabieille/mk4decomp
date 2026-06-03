/**
 * Auto-split from misc_matchesB.c
 */
#include "engine/scenegraph.h"

extern unsigned int g_currentNodeIdx;

/* @addr 0x0045e1d0 (11b)
 *   inc     dword ptr [g_currentNodeIdx]
 *   jmp     +5
 */
extern void EventGateCluster(void);
void IncJmp(void) {
    g_currentNodeIdx++;
    EventGateCluster();
}
