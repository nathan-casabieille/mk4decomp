/**
 * Auto-split from misc_matches5.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_currentNodeIdx;
extern unsigned int g_baseSel;

/* @addr 0x0045e0b0 (30b)
 *   mov     eax, [g_xformScratch2088]
 *   mov     [g_chainAccumCur], 4
 *   test    eax, eax
 *   je      ret
 *   mov     [g_chainAccumCur], 3
 *   ret
 */
extern unsigned int g_chainAccumCur;
void ConditionalAcc4or3(void) {
    g_chainAccumCur = 4;
    if (g_xformScratch2088) {
        g_chainAccumCur = 3;
    }
}
