/**
 * Auto-split from misc_matchesP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

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
extern u32 g_pendingNodeType;
void ScaledLoadJmpIfNonzero_00490e00(void) {
    unsigned int idx = g_xformEntityIdx;
    unsigned int v = *(unsigned int *)(idx * 4 + 0x4c);
    g_pendingNodeType = v;
    if (v == 0) return;
    g_walkCallback = (void (*)(void))0;
    *(unsigned int *)(idx * 4 + 0x4c) = 0;
    if (g_pendingNodeType != 0) {
        ((void (*)(void))g_pendingNodeType)();
    }
}
