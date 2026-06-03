/**
 * Auto-split from misc_matches9.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x004933b0 (30b)
 *   mov     eax, [g_X]
 *   test    eax, eax
 *   mov     [g_eventQueueCurrent], eax
 *   jne     +0x0f
 *   mov     [g_walkCallback], 0x0e
 *   jmp     T
 *   ret
 */
extern unsigned int g_audioStreamState;
extern void StorePauseImulShr16(void);
void TestStoreConstJmp(void) {
    unsigned int s = g_audioStreamState;
    g_eventQueueCurrent = s;
    if (s) return;
    g_walkCallback = (void(*)(void))0x0e;
    StorePauseImulShr16();
}
