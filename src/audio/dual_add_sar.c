/**
 * Auto-split from misc_matchesM.c
 */
#include "engine/scenegraph.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

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
extern int g_dispatchSave1163_004d5100;
extern int g_dispatchSave1164_004d5104;
void DualAddSar_004ab600(void) {
    int a = g_dispatchSave1163_004d5100;
    int b = g_dispatchSave1164_004d5104;
    int sum = a + b;
    int temp = (sum >> 31) + sum;
    g_dispatchSave1163_004d5100 = sum;
    g_walkCallback = (void (*)(void))sum;
    g_dispatchSave1164_004d5104 += temp;
}
