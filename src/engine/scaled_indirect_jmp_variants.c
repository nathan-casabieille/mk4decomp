/**
 * Auto-split from misc_matches2.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_currentNodeIdx;
extern unsigned int g_baseSel;

/* @addr 0x00433bf0 (19b)
 *   mov     eax, [g_baseSel]
 *   mov     eax, [eax*4 + 0x6c]
 *   mov     [g_currentNodeIdx], eax
 *   jmp     eax
 */
void ScaledIndirectJmp_00433bf0(void) {
    unsigned int v = *(unsigned int *)(g_baseSel * 4 + 0x6c);
    g_currentNodeIdx = v;
    ((void(*)(void))v)();
}

/* @addr 0x0049c850 (19b)
 *   mov     eax, [g_eventQueueEnd]
 *   mov     eax, [eax*4 + 0x0c]
 *   mov     [g_currentNodeIdx], eax
 *   jmp     eax
 */
void ScaledIndirectJmp_0049c850(void) {
    unsigned int v = ((ScenegraphNode *)(g_eventQueueEnd * 4))->alloc_work_type;
    g_currentNodeIdx = v;
    ((void(*)(void))v)();
}
