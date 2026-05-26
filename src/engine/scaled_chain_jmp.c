/**
 * 2 "scaled chain + dec + tail-jmp" helpers (36 bytes each).
 *
 * Pattern:
 *   mov     eax, [g_fightGroupHead]
 *   mov     eax, [eax*4 + 0x24]
 *   mov     [g_scaledInit_00542044], eax
 *   mov     ecx, [eax*4 + 4]
 *   dec     ecx
 *   mov     [g_walkCallback], ecx
 *   jmp     Tail
 *
 * Walks one level deeper into the fight-group chain (offset 0x24),
 * caches the chained pointer in a scaled-base global, then loads
 * and decrements the per-chain counter at offset 4 before tail-
 * jumping into the dispatch handler.
 */
#include "engine/scenegraph.h"

extern unsigned int g_scaledInit_00542044;

extern void ScaledArrStore_004293b0(void);
extern void ScaledArrStore_00429960(void);

/* @addr 0x00429470 */
void ScaledChainJmp_00429470(void) {
    unsigned int p = ((ScenegraphNode *)(g_fightGroupHead * 4))->queue_end;
    g_scaledInit_00542044 = p;
    g_walkCallback = (void (*)(void))(*(unsigned int *)(p * 4 + 4) - 1);
    ScaledArrStore_004293b0();
}

/* @addr 0x004298e0 */
void ScaledChainJmp_004298e0(void) {
    unsigned int p = ((ScenegraphNode *)(g_fightGroupHead * 4))->queue_end;
    g_scaledInit_00542044 = p;
    g_walkCallback = (void (*)(void))(*(unsigned int *)(p * 4 + 4) - 1);
    ScaledArrStore_00429960();
}
