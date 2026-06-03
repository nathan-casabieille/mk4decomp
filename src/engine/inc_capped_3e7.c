/**
 * Auto-split from misc_matchesK.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x00491920 (34b)
 *   mov     eax, [g_bootInitState]
 *   inc     eax
 *   cmp     eax, 0x3e7
 *   mov     [g_walkCallback], eax
 *   jle     +0x0a
 *   mov     eax, 0x3e7
 *   mov     [g_walkCallback], eax
 *   mov     [g_bootInitState], eax
 *   ret
 */
extern unsigned int g_bootInitState;
void IncCapped3e7(void) {
    int v = (int)g_bootInitState + 1;
    g_walkCallback = (void (*)(void))v;
    if (v > 0x03e7) {
        v = 0x03e7;
        g_walkCallback = (void (*)(void))v;
    }
    g_bootInitState = (unsigned int)v;
}
