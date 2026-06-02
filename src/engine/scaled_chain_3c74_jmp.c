/**
 * Auto-split from misc_matchesJ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x0048e780 (35b)
 *   mov     eax, [g_baseSel]
 *   mov     eax, [eax*4 + 0x3c]
 *   mov     [g_scaledInit_00542044], eax
 *   mov     ecx, [eax*4 + 0x74]
 *   mov     [g_walkCallback], ecx
 *   jmp     +0x2d
 */
extern void WalkCallbackSetClearDirty(void);
void ScaledChain3c74Jmp(void) {
    unsigned int v = ((ScenegraphNode *)(g_baseSel * 4))->child_a;
    g_scaledInit_00542044 = v;
    g_walkCallback = (void (*)(void))((ScenegraphNode *)(v * 4))->fsm_state;
    WalkCallbackSetClearDirty();
}
