/**
 * Auto-split from misc_matchesS.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x00429800 (52b)
 *   mov     eax, [g_fightGroupHead]
 *   mov     ecx, [eax*4 + 0x24]
 *   mov     [g_currentNodeIdx], ecx
 *   mov     eax, [eax*4 + 0x28]
 *   inc     eax
 *   mov     [g_walkCallback], eax
 *   mov     edx, [ecx*4 + 4]
 *   cmp     eax, edx
 *   jl      +5
 *   jmp     +0xb1
 *   jmp     +0x12c
 */
extern void ScaledChainJmp_004298e0(void);
extern void ScaledArrStore_GuardedChainCmpDualBitXor_00429960(void);
void ScaledIncCmpDualJmp(void) {
    unsigned int idx;
    unsigned int scaled;
    unsigned int v;
    int cmp_val;
    idx = g_fightGroupHead;
    scaled = ((ScenegraphNode *)(idx * 4))->queue_end;
    g_currentNodeIdx = scaled;
    v = ((ScenegraphNode *)(idx * 4))->queue_idx + 1;
    g_walkCallback = (void (*)(void))v;
    cmp_val = *(int *)(scaled * 4 + 4);
    if ((int)v >= cmp_val) {
        ScaledChainJmp_004298e0();
        return;
    }
    ScaledArrStore_GuardedChainCmpDualBitXor_00429960();
}
