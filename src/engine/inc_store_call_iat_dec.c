/**
 * Auto-split from misc_matchesX.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;
extern u32 g_eventQueueWorkType;
extern packed_ptr g_xformEntityIdx;
extern u32 g_pendingNodeType;
extern const int g_sinTable[];
extern void Mul10Tail_00404af0(void);

/* @addr 0x00439520 (64b)
 *   inc g_state_004d57ac, store callback to stack[idx*4],
 *   call IAT [g_iatPtr_00542058], pause-test, restore
 */
extern unsigned int g_state_004d57ac;
extern void (*g_iatPtr_00542058)(void);
void IncStoreCallIATDec_00439520(void) {
    g_state_004d57ac++;
    *(unsigned int *)(g_state_004d57ac * 4) = g_eventQueueChild;
    g_iatPtr_00542058();
    if (g_framePauseFlag != 0) {
        return;
    }
    g_eventQueueChild = *(unsigned int *)(g_state_004d57ac * 4);
    g_state_004d57ac--;
}
