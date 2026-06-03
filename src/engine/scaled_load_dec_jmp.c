/**
 * Auto-split from misc_matches3.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_currentNodeIdx;

/* @addr 0x00429710 (24b)
 *   mov     eax, [g_currentNodeIdx]
 *   mov     ecx, [eax*4 + 4]
 *   dec     ecx
 *   mov     [g_eventQueueCurrent], ecx
 *   jmp     +8
 */
extern void ScaledStoreCurDirtyOr1(void);
void ScaledLoadDecJmp(void) {
    g_eventQueueCurrent = *(unsigned int*)(g_currentNodeIdx * 4 + 4) - 1;
    ScaledStoreCurDirtyOr1();
}
