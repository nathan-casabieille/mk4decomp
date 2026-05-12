/**
 * 2 "scaled iterator step + persist" helpers (45 bytes each).
 *
 * Both stubs emit identical bytes.
 *
 * Pattern:
 *   mov     ecx, [g_baseSel_00542060]
 *   mov     eax, [ecx*4 + 0x48]              ; load packed_ptr
 *   mov     [g_eventQueueTotal], eax
 *   mov     edx, [eax*4 + 0]                 ; deref via SIB+0
 *   inc     eax                              ; advance packed
 *   mov     [g_walkCallback], edx
 *   mov     [g_eventQueueTotal], eax         ; persist advanced
 *   mov     [ecx*4 + 0x48], eax              ; persist into slot
 *   ret
 */
#include "engine/scenegraph.h"

extern unsigned int g_baseSel_00542060;

/* @addr 0x0045c020 */
void ScaledIterStep_0045c020(void) {
    unsigned int idx, p, v;
    idx = g_baseSel_00542060;
    p = *(unsigned int *)(idx * 4 + 0x48);
    g_eventQueueTotal = p;
    v = *(unsigned int *)(p * 4);
    p++;
    g_walkCallback = (void (*)(void))v;
    g_eventQueueTotal = p;
    *(unsigned int *)(idx * 4 + 0x48) = p;
}

/* @addr 0x0045c050 */
void ScaledIterStep_0045c050(void) {
    unsigned int idx, p, v;
    idx = g_baseSel_00542060;
    p = *(unsigned int *)(idx * 4 + 0x48);
    g_eventQueueTotal = p;
    v = *(unsigned int *)(p * 4);
    p++;
    g_walkCallback = (void (*)(void))v;
    g_eventQueueTotal = p;
    *(unsigned int *)(idx * 4 + 0x48) = p;
}
