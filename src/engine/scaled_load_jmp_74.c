/**
 * Auto-split from misc_matches3.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;
extern unsigned int g_baseSel_00542060;

/* @addr 0x0048e7b0 (23b)
 *   mov     eax, [g_baseSel_00542060]
 *   mov     ecx, [eax*4 + 0x74]
 *   mov     [g_walkCallback], ecx
 *   jmp     +9
 */
extern void WalkCallbackSetClearDirty_0048e7d0(void);
void ScaledLoadJmp_74_0048e7b0(void) {
    g_walkCallback = (void (*)(void))((ScenegraphNode *)(g_baseSel_00542060 * 4))->fsm_state;
    WalkCallbackSetClearDirty_0048e7d0();
}
