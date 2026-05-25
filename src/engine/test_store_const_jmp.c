/**
 * Auto-split from misc_matches9.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004933b0 (30b)
 *   mov     eax, [g_X]
 *   test    eax, eax
 *   mov     [g_eventQueueCurrent], eax
 *   jne     +0x0f
 *   mov     [g_walkCallback], 0x0e
 *   jmp     T
 *   ret
 */
extern unsigned int g_audioStreamState_0053a430;
extern void func_0049b619(void);
void TestStoreConstJmp_004933b0(void) {
    unsigned int s = g_audioStreamState_0053a430;
    g_eventQueueCurrent = s;
    if (s) return;
    g_walkCallback = (void(*)(void))0x0e;
    func_0049b619();
}
