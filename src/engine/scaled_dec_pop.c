/**
 * 2 "scaled-base + dec list + pop into slot" helpers (35 bytes each).
 *
 * Both stubs emit identical bytes (the compiler did not deduplicate
 * them); they share the body but live at distinct addresses.
 *
 * Pattern:
 *   mov     edx, [g_baseSel_00542060]
 *   mov     ecx, [edx*4 + 4]
 *   dec     ecx
 *   mov     [g_scaledInit_00542044], ecx
 *   mov     eax, [ecx*4 + 0]
 *   mov     [edx*4 + 4], eax
 *   ret
 */
#include "engine/scenegraph.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00404bd0 */
unsigned int ScaledDecPop_00404bd0(void) {
    unsigned int idx, n, v;
    idx = g_baseSel_00542060;
    n = *(unsigned int *)(idx * 4 + 4) - 1;
    g_scaledInit_00542044 = n;
    v = *(unsigned int *)(n * 4);
    *(unsigned int *)(idx * 4 + 4) = n;
    return v;
}

/* @addr 0x00404c40 */
unsigned int ScaledDecPop_00404c40(void) {
    unsigned int idx, n, v;
    idx = g_baseSel_00542060;
    n = *(unsigned int *)(idx * 4 + 4) - 1;
    g_scaledInit_00542044 = n;
    v = *(unsigned int *)(n * 4);
    *(unsigned int *)(idx * 4 + 4) = n;
    return v;
}
