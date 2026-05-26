/**
 * Auto-split from misc_matchesI.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00475790 (36b)
 *   mov     eax, [g_xformEntityIdx]
 *   mov     ecx, [eax*4 + 0x3c]
 *   mov     [g_walkCallback], ecx
 *   mov     edx, [eax*4 + 0x44]
 *   mov     [g_eventQueueCurrent], edx
 *   jmp     +0x0c
 */
extern void MStackBracket3PackedSlotInit_004757c0(void);
void DualScaledLoadStoreJmp_00475790(void) {
    unsigned int idx = g_xformEntityIdx;
    g_walkCallback = (void (*)(void))((ScenegraphNode *)(idx * 4))->child_a;
    g_eventQueueCurrent = ((ScenegraphNode *)(idx * 4))->child_c;
    MStackBracket3PackedSlotInit_004757c0();
}
