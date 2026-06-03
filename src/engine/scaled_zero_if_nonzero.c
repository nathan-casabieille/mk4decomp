/**
 * Auto-split from misc_matches7.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x0049d430 (30b)
 *   mov     eax, [g_currentNodeIdx]
 *   xor     ecx, ecx
 *   cmp     eax, ecx
 *   mov     [g_walkCallback], eax
 *   je      .ret
 *   mov     [eax*4 + 8], ecx
 *   mov     [g_currentNodeIdx], ecx
 * .ret:
 *   ret
 */
void ScaledZeroIfNonzero(void) {
    unsigned int v = g_currentNodeIdx;
    g_walkCallback = (void (*)(void))v;
    if (v != 0) {
        *(unsigned int *)(v * 4 + 8) = 0;
        g_currentNodeIdx = 0;
    }
}
