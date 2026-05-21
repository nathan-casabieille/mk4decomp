/**
 * Auto-split from misc_matchesD.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00409350 (35b)
 *   mov     eax, [g_scaledInit_00542044]
 *   mov     ecx, [eax*4 + 0x34]
 *   and     ecx, 0xfffffffb
 *   mov     [eax*4 + 0x34], ecx
 *   mov     eax, [g_xformDirtyFlags]
 *   and     al, 0xfe
 *   mov     [g_xformDirtyFlags], eax
 *   ret
 */
void ScaledAnd4InvDirtyClear_00409350(void) {
    unsigned int idx = g_scaledInit_00542044;
    unsigned int v = *(unsigned int *)(idx * 4 + 0x34) & 0xFFFFFFFBu;
    *(unsigned int *)(idx * 4 + 0x34) = v;
    g_xformDirtyFlags = g_xformDirtyFlags & 0xFFFFFFFEu;
}
