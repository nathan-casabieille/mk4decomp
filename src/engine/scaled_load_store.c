/**
 * Auto-split from misc_matches2.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_currentNodeIdx;
extern unsigned int g_baseSel;

/* @addr 0x00473ed0 (19b)
 *   mov     eax, [g_baseSel]
 *   mov     ecx, [eax*4 + 0x68]
 *   mov     [g_fightGroupHead], ecx
 *   ret
 */
void ScaledLoadStore(void) {
    g_fightGroupHead = *(unsigned int *)(g_baseSel * 4 + 0x68);
}
