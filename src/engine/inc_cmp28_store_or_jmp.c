/**
 * Auto-split from misc_matchesN.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x00458880 (46b)
 *   mov     eax, [0x0053a278]
 *   mov     [g_chainAccumCur], eax
 *   inc     eax
 *   cmp     eax, 0x28
 *   mov     [g_walkCallback], eax
 *   jl      .skip
 *   mov     [g_walkCallback], 0
 *   mov     [g_eventQueueEnd], 1
 *   jmp     T
 */
extern unsigned int g_stateChangePair3;
extern unsigned int g_chainAccumCur;
extern void CinematicStageCluster(void);
void IncCmp28StoreOrJmp(void) {
    int v = (int)g_stateChangePair3;
    g_chainAccumCur = (unsigned int)v;
    v++;
    g_walkCallback = (void (*)(void))v;
    if (v >= 0x28) {
        g_walkCallback = 0;
    }
    g_eventQueueEnd = 1;
    CinematicStageCluster();
}
