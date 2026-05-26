/**
 * Auto-split from misc_matches3.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;

/* @addr 0x0048bb40 (25b)
 *   mov     eax, [g_fightGroupHead]
 *   mov     ecx, [eax*4 + 0x40]
 *   shr     ecx, 0xc
 *   and     ecx, 3
 *   mov     [g_walkCallback], ecx
 *   ret
 */
void ScaledShrAnd_0048bb40(void) {
    g_walkCallback = (NodeHandlerFn)((((FightGroupNode *)(g_fightGroupHead * 4))->bits >> 12) & 3);
}
