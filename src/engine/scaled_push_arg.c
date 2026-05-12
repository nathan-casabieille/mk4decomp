/**
 * 2 "push arg onto scaled stack" helpers (52 bytes each).
 *
 * Both stubs emit identical bytes.
 *
 * Pattern (decoded):
 *   mov     eax, [g_baseSel_00542060]
 *   mov     edx, [esp+4]                    ; arg
 *   mov     ecx, [eax*4 + 4]                ; load top
 *   lea     eax, [eax*4 + 4]                ; address of slot
 *   mov     [g_scaledInit_00542044], ecx
 *   mov     [ecx*4 + 0], edx                ; store arg via SIB+0
 *   mov     ecx, [g_scaledInit_00542044]    ; reload top
 *   inc     ecx
 *   mov     [g_scaledInit_00542044], ecx
 *   mov     [eax], ecx                      ; persist new top
 *   ret
 */
#include "engine/scenegraph.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00404b90 */
void ScaledPushArg_00404b90(unsigned int arg) {
    unsigned int *slot = (unsigned int *)(g_baseSel_00542060 * 4 + 4);
    g_scaledInit_00542044 = *slot;
    *(unsigned int *)(g_scaledInit_00542044 * 4) = arg;
    g_scaledInit_00542044++;
    *slot = g_scaledInit_00542044;
}

/* @addr 0x00404c00 */
void ScaledPushArg_00404c00(unsigned int arg) {
    unsigned int *slot = (unsigned int *)(g_baseSel_00542060 * 4 + 4);
    g_scaledInit_00542044 = *slot;
    *(unsigned int *)(g_scaledInit_00542044 * 4) = arg;
    g_scaledInit_00542044++;
    *slot = g_scaledInit_00542044;
}
