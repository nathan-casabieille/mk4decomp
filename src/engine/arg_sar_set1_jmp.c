/**
 * Auto-split from misc_matches7.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x0049c6d0 (27b)
 *   mov     eax, [esp+4]
 *   mov     [g_eventQueueChild], 1
 *   sar     eax, 2
 *   mov     [g_eventQueueEnd], eax
 *   jmp     +0x25
 */
extern void InstallSelfBit2LoopIndirect(void);
void ArgSar_Set1_Jmp(int arg) {
    g_eventQueueChild = 1;
    g_eventQueueEnd = (unsigned int)(arg >> 2);
    InstallSelfBit2LoopIndirect();
}
