/**
 * Auto-split from misc_matchesX.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"
#include "portable/mem_model.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;
extern void Mul10Tail(void);

/* @addr 0x00439520 (64b)
 *   inc g_matrixStackTop, store callback to stack[idx*4],
 *   call IAT [g_iatPtr], pause-test, restore
 */
extern void (*g_iatPtr)(void);
void IncStoreCallIATDec(void) {
    g_matrixStackTop++;
    *(unsigned int *)MK4_PTR((g_matrixStackTop * 4)) = g_eventQueueChild;
    g_iatPtr();
    if (g_framePauseFlag != 0) {
        return;
    }
    g_eventQueueChild = *(unsigned int *)MK4_PTR((g_matrixStackTop * 4));
    g_matrixStackTop--;
}
