/**
 * Auto-split from misc_matches3.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;

/* @addr 0x004774d0 (25b)
 *   mov     eax, [g_pendingNodeType]
 *   mov     ecx, [eax*4 + 0]
 *   and     ecx, 0xff
 *   mov     [g_walkCallback], ecx
 *   ret
 */
void ScaledMaskByte_004774d0(void) {
    g_walkCallback = (void(*)(void))(*(unsigned int *)(g_pendingNodeType * 4) & 0xff);
}
