/**
 * Auto-split from misc_matchesE.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00425360 (31b)
 *   mov     eax, [g_scaledInit_00542044]
 *   shl     eax, 2
 *   mov     ecx, [eax]
 *   mov     edx, [eax + 4]
 *   neg     ecx
 *   mov     [eax], ecx
 *   mov     ecx, [eax + 8]
 *   neg     edx
 *   neg     ecx
 *   mov     [eax + 4], edx
 *   mov     [eax + 8], ecx
 *   ret
 */
void NegateThree_00425360(void) {
    int *base;
    int a, b, c;
    base = (int *)(g_scaledInit_00542044 * 4);
    a = base[0];
    b = base[1];
    a = -a;
    base[0] = a;
    c = base[2];
    b = -b;
    c = -c;
    base[1] = b;
    base[2] = c;
}
