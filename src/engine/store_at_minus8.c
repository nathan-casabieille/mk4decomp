/**
 * Auto-split from misc_matchesB.c
 */
#include "engine/scenegraph.h"

extern unsigned int g_scaledInit_00542044;

/* @addr 0x004b5b00 (12b)
 *   mov     ecx, [esp+4]
 *   mov     eax, [esp+8]
 *   mov     [ecx-8], eax
 *   ret
 */
void StoreAtMinus8_004b5b00(int *p, int v) {
    p[-2] = v;
}
