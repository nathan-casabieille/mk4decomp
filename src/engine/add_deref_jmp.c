/**
 * Add two queue indices + dereference + indirect-jmp.
 */
#include "engine/scenegraph.h"

/* @addr 0x00433e70 (32b)
 *   mov     eax, [g_eventQueueChild]
 *   mov     ecx, [g_eventQueueCurrent]
 *   add     eax, ecx
 *   mov     [g_eventQueueChild], eax
 *   mov     eax, [eax*4 + 0]
 *   mov     [g_eventQueueChild], eax
 *   jmp     eax
 */
void AddDerefJmp_00433e70(void) {
    unsigned int v = g_eventQueueChild + g_eventQueueCurrent;
    g_eventQueueChild = v;
    v = *(unsigned int *)(v * 4);
    g_eventQueueChild = v;
    ((void (*)(void))v)();
}
