/**
 * Auto-split from misc_matches7.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x0049c6d0 (27b)
 *   mov     eax, [esp+4]
 *   mov     [g_eventQueueChild], 1
 *   sar     eax, 2
 *   mov     [g_eventQueueEnd], eax
 *   jmp     +0x25
 */
extern void func_0049c6fa(void);
void ArgSar_Set1_Jmp_0049c6d0(int arg) {
    g_eventQueueChild = 1;
    g_eventQueueEnd = (unsigned int)(arg >> 2);
    func_0049c6fa();
}
