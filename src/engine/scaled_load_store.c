/**
 * Auto-split from misc_matches2.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;
extern unsigned int g_baseSel_00542060;

/* @addr 0x00473ed0 (19b)
 *   mov     eax, [g_baseSel_00542060]
 *   mov     ecx, [eax*4 + 0x68]
 *   mov     [g_fightGroupHead], ecx
 *   ret
 */
void ScaledLoadStore_00473ed0(void) {
    g_fightGroupHead = *(unsigned int *)(g_baseSel_00542060 * 4 + 0x68);
}
