/**
 * Auto-split from misc_matchesM.c
 */
#include "engine/scenegraph.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x004ab600 (39b)
 *   mov     eax, [0x004d5100]
 *   mov     ecx, [0x004d5104]
 *   add     eax, ecx
 *   mov     edx, eax
 *   mov     [0x004d5100], eax
 *   sar     edx, 0x1f
 *   add     edx, eax
 *   mov     [g_walkCallback], edx
 *   add     ecx, edx
 *   mov     [0x004d5104], ecx
 *   ret
 */
extern int g_dispatchSave1163;
extern int g_dispatchSave1164;
void DualAddSar(void) {
    int a = g_dispatchSave1163;
    int b = g_dispatchSave1164;
    int sum = a + b;
    int temp = (sum >> 31) + sum;
    g_dispatchSave1163 = sum;
    g_walkCallback = (void (*)(void))sum;
    g_dispatchSave1164 += temp;
}
