/**
 * Auto-split from misc_matches2.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;
extern unsigned int g_baseSel_00542060;

/* @addr 0x004774b0 (19b)
 *   mov     eax, [g_pendingNodeType]
 *   mov     ecx, [g_eventQueueWorkType]
 *   mov     [eax*4 + 0], ecx          ; SIB+0 store
 *   ret
 */
void ScaledDerefStore_004774b0(void) {
    *(unsigned int *)(g_pendingNodeType * 4) = g_eventQueueWorkType;
}
