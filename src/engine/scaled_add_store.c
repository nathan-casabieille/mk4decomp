/**
 * Auto-split from misc_matchesN.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004406e0 (47b)
 *   mov     eax, [g_scaledInit_00542044]
 *   mov     ecx, [eax*4 + 0x70]
 *   mov     [g_walkCallback], ecx
 *   mov     edx, [eax*4 + 0x4c]
 *   add     ecx, edx
 *   mov     [g_eventQueueCurrent], ecx
 *   mov     [g_walkCallback], ecx
 *   mov     [eax*4 + 0x70], ecx
 *   ret
 */
void ScaledAddStore_004406e0(void) {
    unsigned int base = g_scaledInit_00542044;
    unsigned int v_70 = *(unsigned int *)(base * 4 + 0x70);
    g_walkCallback = (void (*)(void))v_70;
    {
        unsigned int v_4c = *(unsigned int *)(base * 4 + 0x4c);
        unsigned int sum = v_70 + v_4c;
        g_eventQueueCurrent = v_4c;
        g_walkCallback = (void (*)(void))sum;
        *(unsigned int *)(base * 4 + 0x70) = sum;
    }
}
