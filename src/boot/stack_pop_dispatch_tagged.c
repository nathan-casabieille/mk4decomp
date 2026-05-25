/**
 * Auto-split from misc_matchesPP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;
extern unsigned int g_baseSel_00542060;

/* @addr 0x0041f780 (77b)
 *   eax = [g_baseSel*4+4] - 1 → g_scaledInit; edx = [eax*4+0]
 *   → g_walkCallback; [g_baseSel*4+4] = eax (decrement);
 *   eax = walk; eax >>= 24; → [g_baseSel*4+0x84];
 *   eax = walk & 0xffffff → walk; jmp eax.
 *   Hand-rolled tail-dispatch: pops a 24-bit "next" + 8-bit "tag"
 *   from a stack-of-callbacks, invokes the next.
 */
void StackPopDispatchTagged_0041f780(void) {
    unsigned int base = g_baseSel_00542060;
    unsigned int top = *(unsigned int *)(base * 4 + 4) - 1;
    unsigned int walk;
    g_scaledInit_00542044 = top;
    g_walkCallback = (void (*)(void))*(unsigned int *)(top * 4);
    *(unsigned int *)(base * 4 + 4) = top;
    *(int *)(g_baseSel_00542060 * 4 + 0x84) = (int)g_walkCallback >> 24;
    walk = (unsigned int)g_walkCallback & 0xffffff;
    g_walkCallback = (void (*)(void))walk;
    ((void (*)(void))walk)();
}
