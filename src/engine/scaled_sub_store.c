/**
 * Auto-split from misc_matchesJ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x0048ee90 (39b)
 *   mov     eax, [g_scaledInit_00542044]
 *   mov     ecx, [eax*4 + 0x48]
 *   mov     [g_walkCallback], ecx
 *   mov     eax, [eax*4 + 0x58]
 *   sub     ecx, eax
 *   mov     [g_eventQueueCurrent], eax
 *   mov     [g_walkCallback], ecx
 *   ret
 */
void ScaledSubStore_0048ee90(void) {
    __asm {
        mov     eax, dword ptr [g_scaledInit_00542044]
        mov     ecx, dword ptr [eax*4 + 0x48]
        mov     dword ptr [g_walkCallback], ecx
        mov     eax, dword ptr [eax*4 + 0x58]
        sub     ecx, eax
        mov     dword ptr [g_eventQueueCurrent], eax
        mov     dword ptr [g_walkCallback], ecx
        }
}
