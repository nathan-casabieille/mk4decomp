/**
 * Auto-split from misc_matches7.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x0041f550 (18b)
 *   mov     ecx, [g_baseSel]
 *   mov     eax, [esp+4]
 *   mov     [ecx*4 + 0xe0], eax
 *   ret
 */
void ScaledStoreE0(int x) {
    ((ScenegraphNode *)(g_baseSel * 4))->work_type = (unsigned int)x;
}
