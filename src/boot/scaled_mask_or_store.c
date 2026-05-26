/**
 * Auto-split from misc_matchesN.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00405880 (49b)
 *   mov     ecx, [g_scaledInit_00542044]
 *   mov     edx, [g_walkCallback]
 *   mov     [g_eventQueueCurrent], 0xfffffff0
 *   mov     eax, [ecx*4 + 0x20]
 *   and     eax, 0xfffffff0
 *   or      eax, edx
 *   mov     [g_eventQueueCurrent], eax
 *   mov     [ecx*4 + 0x20], eax
 *   ret
 */
void ScaledMaskOrStore_00405880(void) {
    unsigned int idx = g_scaledInit_00542044;
    unsigned int walk = (unsigned int)g_walkCallback;
    unsigned int v;
    g_eventQueueCurrent = 0xf0ffffff;
    v = (((ScenegraphNode *)(idx * 4))->flags & 0xf0ffffff) | walk;
    g_eventQueueCurrent = v;
    ((ScenegraphNode *)(idx * 4))->flags = v;
}
