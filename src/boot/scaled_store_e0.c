/**
 * Auto-split from misc_matches7.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x0041f550 (18b)
 *   mov     ecx, [g_baseSel_00542060]
 *   mov     eax, [esp+4]
 *   mov     [ecx*4 + 0xe0], eax
 *   ret
 */
void ScaledStoreE0_0041f550(int x) {
    ((ScenegraphNode *)(g_baseSel_00542060 * 4))->work_type = (unsigned int)x;
}
