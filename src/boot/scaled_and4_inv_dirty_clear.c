/**
 * Auto-split from misc_matchesD.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x00409350 (35b)
 *   mov     eax, [g_currentNodeIdx]
 *   mov     ecx, [eax*4 + 0x34]
 *   and     ecx, 0xfffffffb
 *   mov     [eax*4 + 0x34], ecx
 *   mov     eax, [g_xformDirtyFlags]
 *   and     al, 0xfe
 *   mov     [g_xformDirtyFlags], eax
 *   ret
 */
void ScaledAnd4InvDirtyClear(void) {
    ScenegraphNode *n = (ScenegraphNode *)(g_currentNodeIdx * 4);
    n->state_mask &= 0xFFFFFFFBu;
    g_xformDirtyFlags = g_xformDirtyFlags & 0xFFFFFFFEu;
}
