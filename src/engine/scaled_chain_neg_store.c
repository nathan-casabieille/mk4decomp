/**
 * Auto-split from misc_matchesO.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00470310 (46b)
 *   mov     eax, [g_fightGroupHead]
 *   mov     eax, [eax*4 + 0x18]
 *   mov     [g_scaledInit_00542044], eax
 *   mov     eax, [eax*4 + 0x34]
 *   test    eax, eax
 *   mov     [g_walkCallback], eax
 *   je      +0x0c
 *   neg     eax
 *   mov     [g_walkCallback], eax
 *   jmp     +3
 *   ret
 */
extern void func_00470342(void);
void ScaledChainNegStore_00470310(void) {
    unsigned int s;
    unsigned int v;
    s = *(unsigned int *)(g_fightGroupHead * 4 + 0x18);
    g_scaledInit_00542044 = s;
    v = *(unsigned int *)(s * 4 + 0x34);
    g_walkCallback = (void (*)(void))v;
    if (v == 0) return;
    v = (unsigned int)-(int)v;
    g_walkCallback = (void (*)(void))v;
    func_00470342();
}
