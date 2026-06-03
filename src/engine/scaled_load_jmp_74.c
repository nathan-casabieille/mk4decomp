/**
 * Auto-split from misc_matches3.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_currentNodeIdx;
extern unsigned int g_baseSel;

/* @addr 0x0048e7b0 (23b)
 *   mov     eax, [g_baseSel]
 *   mov     ecx, [eax*4 + 0x74]
 *   mov     [g_walkCallback], ecx
 *   jmp     +9
 */
extern void WalkCallbackSetClearDirty(void);
void ScaledLoadJmp_74(void) {
    g_walkCallback = (void (*)(void))((ScenegraphNode *)(g_baseSel * 4))->fsm_state;
    WalkCallbackSetClearDirty();
}
