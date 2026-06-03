/**
 * Auto-split from misc_matchesB.c
 */
#include "engine/scenegraph.h"

extern unsigned int g_currentNodeIdx;

/* @addr 0x004b5b00 (12b)
 *   mov     ecx, [esp+4]
 *   mov     eax, [esp+8]
 *   mov     [ecx-8], eax
 *   ret
 */
void StoreAtMinus8(int *p, int v) {
    p[-2] = v;
}
