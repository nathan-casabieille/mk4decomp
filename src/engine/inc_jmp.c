/**
 * Auto-split from misc_matchesB.c
 */
#include "engine/scenegraph.h"

extern unsigned int g_scaledInit_00542044;

/* @addr 0x0045e1d0 (11b)
 *   inc     dword ptr [g_scaledInit_00542044]
 *   jmp     +5
 */
extern void InputCheckCluster_0045e1e0(void);
void IncJmp_0045e1d0(void) {
    g_scaledInit_00542044++;
    InputCheckCluster_0045e1e0();
}
