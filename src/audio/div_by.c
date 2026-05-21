/**
 * Auto-split from misc_matchesL.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004ab300 (31b)
 *   mov     ecx, [g_eventQueueCurrent]
 *   test    ecx, ecx
 *   jne     +7
 *   mov     [g_walkCallback], ecx
 *   ret
 *   mov     eax, [g_walkCallback]
 *   cdq
 *   idiv    ecx
 *   mov     [g_walkCallback], eax
 *   ret
 */
void DivBy_004ab300(void) {
    int divisor = (int)g_eventQueueCurrent;
    if (divisor == 0) {
        g_walkCallback = (void (*)(void))divisor;
        return;
    }
    g_walkCallback = (void (*)(void))((int)g_walkCallback / divisor);
}
