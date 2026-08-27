/**
 * 2 "scaled chain + dec + tail-jmp" helpers (36 bytes each).
 *
 * Pattern:
 *   mov     eax, [g_fightGroupHead]
 *   mov     eax, [eax*4 + 0x24]
 *   mov     [g_currentNodeIdx], eax
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

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_currentNodeIdx;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_fightGroupHead (*(unsigned int *)MK4_VA(unsigned int, 0x54205cu))
#define g_walkCallback (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#endif


extern void ScaledArrStore_EsiInstallBitCallChain_004293b0(void);
extern void ScaledArrStore_GuardedChainCmpDualBitXor_00429960(void);

/* @addr 0x00429470 */
void ScaledChainJmp_00429470(void) {
    unsigned int p = ((ScenegraphNode *)MK4_PTR((g_fightGroupHead * 4)))->queue_end;
    g_currentNodeIdx = p;
    g_walkCallback = (void (*)(void))(*(unsigned int *)MK4_PTR((p * 4 + 4)) - 1);
    ScaledArrStore_EsiInstallBitCallChain_004293b0();
}

/* @addr 0x004298e0 */
void ScaledChainJmp_004298e0(void) {
    unsigned int p = ((ScenegraphNode *)MK4_PTR((g_fightGroupHead * 4)))->queue_end;
    g_currentNodeIdx = p;
    g_walkCallback = (void (*)(void))(*(unsigned int *)MK4_PTR((p * 4 + 4)) - 1);
    ScaledArrStore_GuardedChainCmpDualBitXor_00429960();
}
