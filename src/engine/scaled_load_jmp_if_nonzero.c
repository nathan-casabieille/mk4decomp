/**
 * Auto-split from misc_matchesP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"
#include "portable/mem_model.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x00490e00 (49b)
 *   mov     eax, [g_xformEntityIdx]
 *   xor     edx, edx
 *   mov     ecx, [eax*4 + 0x4c]
 *   cmp     ecx, edx
 *   mov     [g_pendingNodeType], ecx
 *   je      +0x18
 *   mov     [g_walkCallback], edx
 *   mov     [eax*4 + 0x4c], edx
 *   mov     eax, [g_pendingNodeType]
 *   cmp     eax, edx
 *   je      +2
 *   jmp     eax
 *   ret
 */
void ScaledLoadJmpIfNonzero(void) {
    unsigned int idx = g_xformEntityIdx;
    unsigned int v = *(unsigned int *)(idx * 4 + 0x4c);
    g_pendingNodeType = v;
    if (v == 0) return;
    g_walkCallback = (void (*)(void))0;
    *(unsigned int *)(idx * 4 + 0x4c) = 0;
    if (g_pendingNodeType != 0) {
        ((void (*)(void))MK4_ResolveCode(g_pendingNodeType))();
    }
}
