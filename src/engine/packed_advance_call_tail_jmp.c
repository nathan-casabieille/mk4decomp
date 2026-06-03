/**
 * Auto-split from misc_matchesPP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_currentNodeIdx;

/* @addr 0x004392c0 (78b)
 *   Tail-dispatch on packed table. eax = arg0>>2 → g_scaledInit;
 *   ecx = [eax*4+0] → walk; advance idx; call F; pause → ret;
 *   eax = (g_scaledInit + walk) → g_scaledInit; eax = [g_scaledInit*4];
 *   walk = eax; jmp eax.
 */
extern void StorePauseImulShr16(void);
void PackedAdvanceCallTailJmp(packed_ptr arg) {
    g_currentNodeIdx = (unsigned int)((int)arg >> 2);
    g_walkCallback = *(void (**)(void))(g_currentNodeIdx * 4);
    g_currentNodeIdx++;
    StorePauseImulShr16();
    if (g_framePauseFlag) return;
    g_currentNodeIdx += (unsigned int)g_walkCallback;
    g_currentNodeIdx = *(unsigned int *)(g_currentNodeIdx * 4);
    ((void (*)(void))g_currentNodeIdx)();
}
