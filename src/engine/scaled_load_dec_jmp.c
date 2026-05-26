/**
 * Auto-split from misc_matches3.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;

/* @addr 0x00429710 (24b)
 *   mov     eax, [g_scaledInit_00542044]
 *   mov     ecx, [eax*4 + 4]
 *   dec     ecx
 *   mov     [g_eventQueueCurrent], ecx
 *   jmp     +8
 */
extern void ScaledStoreCurDirtyOr1_00429730(void);
void ScaledLoadDecJmp_00429710(void) {
    g_eventQueueCurrent = *(unsigned int*)(g_scaledInit_00542044 * 4 + 4) - 1;
    ScaledStoreCurDirtyOr1_00429730();
}
