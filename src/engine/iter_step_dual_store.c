/**
 * Auto-split from misc_matchesK.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00490b40 (44b)
 *   mov     eax, [esp+4]
 *   sar     eax, 2
 *   mov     [g_eventQueueTotal], eax
 *   mov     ecx, [eax*4 + 0]
 *   inc     eax
 *   mov     [g_eventQueueTotal], eax
 *   mov     eax, [g_fightGroupHead]
 *   mov     [g_pendingNodeType], ecx
 *   mov     [eax*4 + 0x44], ecx
 *   ret
 */
void IterStepDualStore_00490b40(int arg) {
    unsigned int packed = (unsigned int)(arg >> 2);
    unsigned int v;
    g_eventQueueTotal = packed;
    v = *(unsigned int *)(packed * 4);
    packed++;
    g_eventQueueTotal = packed;
    g_pendingNodeType = v;
    *(unsigned int *)(g_fightGroupHead * 4 + 0x44) = v;
}
