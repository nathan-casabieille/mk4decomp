/**
 * Auto-split from misc_matchesL.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004aa410 (32b)
 *   mov     eax, [esp+4]
 *   mov     ecx, eax
 *   sar     eax, 0x10
 *   and     ecx, 0xffff
 *   and     eax, 0xffff
 *   mov     [g_walkCallback], ecx
 *   mov     [g_eventQueueCurrent], eax
 *   ret
 */
void SplitInt32_004aa410(int arg) {
    g_walkCallback = (void (*)(void))((unsigned int)arg & 0xffff);
    g_eventQueueCurrent = ((unsigned int)(arg >> 16)) & 0xffff;
}
