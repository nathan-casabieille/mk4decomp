/**
 * Add two queue indices + dereference + indirect-jmp.
 */
#include "engine/scenegraph.h"

/* @addr 0x00433e70 (32b)
 *   mov     eax, [g_xformEntityIdx]
 *   mov     ecx, [g_eventQueueCurrent]
 *   add     eax, ecx
 *   mov     [g_xformEntityIdx], eax
 *   mov     eax, [eax*4 + 0]
 *   mov     [g_xformEntityIdx], eax
 *   jmp     eax
 */
void AddDerefJmp_00433e70(void) {
    unsigned int v = g_xformEntityIdx + g_eventQueueCurrent;
    g_xformEntityIdx = v;
    v = *(unsigned int *)(v * 4);
    g_xformEntityIdx = v;
    ((void (*)(void))v)();
}
