/**
 * Auto-split from misc_matches5.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;
extern unsigned int g_baseSel_00542060;

/* @addr 0x0048cc20 (25b)
 *   mov     [g_walkCallback], 0x71
 *   mov     [g_eventQueueCurrent], -1
 *   jmp     T
 */
extern void func_0048cbef(void);
void DualConstJmpNeg1_0048cc20(void) {
    g_walkCallback = (void(*)(void))0x71;
    g_eventQueueCurrent = 0xffffffff;
    func_0048cbef();
}
