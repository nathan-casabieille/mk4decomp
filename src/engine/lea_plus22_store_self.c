/**
 * Auto-split from misc_matches3.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;

/* @addr 0x0048e4d0 (22b)
 *   mov     eax, [g_baseSel_00542060]
 *   lea     ecx, [eax + 0x22]
 *   mov     [g_walkCallback], ecx
 *   mov     [eax*4 + 4], ecx
 *   ret
 */
void LeaPlus22StoreSelf_0048e4d0(void) {
    u32 base = g_baseSel_00542060;
    u32 v = base + 0x22;
    g_walkCallback = (NodeHandlerFn)v;
    *(u32 *)(base * 4 + 4) = v;
}
