/**
 * Auto-split from misc_matchesY.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;
extern unsigned int g_phaseTimer_00537e94;

/* @addr 0x00446640 (61b)
 *   mov     eax, [g_baseSel_00542060]
 *   xor     ecx, ecx
 *   mov     eax, [eax*4 + 0x30]
 *   mov     [g_walkCallback], ecx
 *   mov     [g_scaledInit_00542044], eax
 *   mov     [eax*4 + 0x1c], ecx
 *   mov     ecx, [g_scaledInit_00542044]
 *   mov     eax, [ecx*4 + 0x20]
 *   and     ah, 0xfe
 *   mov     [g_walkCallback], eax
 *   mov     [ecx*4 + 0x20], eax
 *   ret
 */
void ScaledLoad1cZeroAndFE_00446640(void) {
    unsigned int s;
    unsigned int v;
    s = *(unsigned int *)(g_baseSel_00542060 * 4 + 0x30);
    g_walkCallback = 0;
    g_scaledInit_00542044 = s;
    *(unsigned int *)(s * 4 + 0x1c) = 0;
    s = g_scaledInit_00542044;
    v = *(unsigned int *)(s * 4 + 0x20) & 0xFFFFFEFFu;
    g_walkCallback = (void(*)(void))v;
    *(unsigned int *)(s * 4 + 0x20) = v;
}
