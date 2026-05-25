/**
 * Auto-split from misc_matchesPP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;

/* @addr 0x004392c0 (78b)
 *   Tail-dispatch on packed table. eax = arg0>>2 → g_scaledInit;
 *   ecx = [eax*4+0] → walk; advance idx; call F; pause → ret;
 *   eax = (g_scaledInit + walk) → g_scaledInit; eax = [g_scaledInit*4];
 *   walk = eax; jmp eax.
 */
extern void StorePauseImulShr16_004ab630(void);
void PackedAdvanceCallTailJmp_004392c0(packed_ptr arg) {
    g_scaledInit_00542044 = (unsigned int)((int)arg >> 2);
    g_walkCallback = *(void (**)(void))(g_scaledInit_00542044 * 4);
    g_scaledInit_00542044++;
    StorePauseImulShr16_004ab630();
    if (g_framePauseFlag) return;
    g_scaledInit_00542044 += (unsigned int)g_walkCallback;
    g_scaledInit_00542044 = *(unsigned int *)(g_scaledInit_00542044 * 4);
    ((void (*)(void))g_scaledInit_00542044)();
}
