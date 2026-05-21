/**
 * Auto-split from misc_matches2.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;
extern unsigned int g_baseSel_00542060;

/* @addr 0x00461840 (23b)
 *   mov     eax, [g_eventQueueCurrent]
 *   mov     ecx, [g_walkCallback]
 *   mov     [g_X], eax
 *   mov     [g_Y], ecx
 *   ret
 */
extern unsigned int g_save_0053a7d8;
extern unsigned int g_save_0053a748;
void DualSave_00461840(void) {
    unsigned int a = g_eventQueueCurrent;
    unsigned int b = (unsigned int)g_walkCallback;
    g_save_0053a7d8 = a;
    g_save_0053a748 = b;
}
