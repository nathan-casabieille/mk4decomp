/**
 * Auto-split from misc_matchesI.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00475790 (36b)
 *   mov     eax, [g_eventQueueIdx]
 *   mov     ecx, [eax*4 + 0x3c]
 *   mov     [g_walkCallback], ecx
 *   mov     edx, [eax*4 + 0x44]
 *   mov     [g_eventQueueCurrent], edx
 *   jmp     +0x0c
 */
extern void func_004757a4(void);
void DualScaledLoadStoreJmp_00475790(void) {
    unsigned int idx = g_eventQueueIdx;
    g_walkCallback = (void (*)(void))*(unsigned int *)(idx * 4 + 0x3c);
    g_eventQueueCurrent = *(unsigned int *)(idx * 4 + 0x44);
    func_004757a4();
}
