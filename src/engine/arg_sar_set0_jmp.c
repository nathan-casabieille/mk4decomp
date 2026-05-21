/**
 * Auto-split from misc_matches7.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x0049c6f0 (27b)
 *   mov     eax, [esp+4]
 *   mov     [g_eventQueueChild], 0
 *   sar     eax, 2
 *   mov     [g_eventQueueEnd], eax
 *   jmp     +5
 */
extern void func_0049c6fa_b(void);
void ArgSar_Set0_Jmp_0049c6f0(int arg) {
    g_eventQueueChild = 0;
    g_eventQueueEnd = (unsigned int)(arg >> 2);
    func_0049c6fa_b();
}
