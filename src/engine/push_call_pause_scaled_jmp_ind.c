/**
 * Auto-split from misc_matchesZ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x0048e2f0 (60b)
 *   push lit; call F; pause-test → ret;
 *   load g_baseSel; copy [eax*4+0x7c]→g_walkCallback, [eax*4+0x80]→g_currentNodeFlags;
 *   jmp [g_scaledInit_00542044]; ret.
 */
extern void *g_dispatchSave1316_004f1290;
extern int ArgScaledLoadCmpP1_0048e550(void *);
void PushCallPauseScaledJmpInd_0048e2f0(void) {
    unsigned int base;
    ArgScaledLoadCmpP1_0048e550(&g_dispatchSave1316_004f1290);
    if (g_framePauseFlag) return;
    base = g_baseSel_00542060;
    g_walkCallback = (void (*)(void))*(unsigned int *)(base * 4 + 0x7c);
    g_currentNodeFlags = *(unsigned int *)(base * 4 + 0x80);
    (*(void (**)(void))&g_scaledInit_00542044)();
}
