/**
 * Auto-split from misc_matchesA.c
 */
#include "engine/scenegraph.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004b3d70 (30b)
 *   mov     eax, [g_X1]
 *   mov     ecx, [g_X2]
 *   cmp     ecx, eax
 *   jge     +2
 *   mov     eax, ecx
 *   mov     ecx, [g_X3]
 *   cmp     ecx, eax
 *   jge     +2
 *   mov     eax, ecx
 *   ret
 */
extern int g_min_007af984;
extern int g_min_007af988;
extern int g_min_007af98c;
int MinOfThree_004b3d70(void) {
    int a = g_min_007af984;
    int b = g_min_007af988;
    if (b < a) a = b;
    b = g_min_007af98c;
    if (b < a) a = b;
    return a;
}
