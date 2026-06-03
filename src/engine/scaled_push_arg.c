/**
 * 2 "push arg onto scaled stack" helpers (52 bytes each).
 *
 * Both stubs emit identical bytes.
 *
 * Pattern (decoded):
 *   mov     eax, [g_baseSel]
 *   mov     edx, [esp+4]                    ; arg
 *   mov     ecx, [eax*4 + 4]                ; load top
 *   lea     eax, [eax*4 + 4]                ; address of slot
 *   mov     [g_currentNodeIdx], ecx
 *   mov     [ecx*4 + 0], edx                ; store arg via SIB+0
 *   mov     ecx, [g_currentNodeIdx]    ; reload top
 *   inc     ecx
 *   mov     [g_currentNodeIdx], ecx
 *   mov     [eax], ecx                      ; persist new top
 *   ret
 */
#include "engine/scenegraph.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x00404b90 */
void ScaledPushArg_00404b90(unsigned int arg) {
    unsigned int *slot = (unsigned int *)(g_baseSel * 4 + 4);
    g_currentNodeIdx = *slot;
    *(unsigned int *)(g_currentNodeIdx * 4) = arg;
    g_currentNodeIdx++;
    *slot = g_currentNodeIdx;
}

/* @addr 0x00404c00 */
void ScaledPushArg_00404c00(unsigned int arg) {
    unsigned int *slot = (unsigned int *)(g_baseSel * 4 + 4);
    g_currentNodeIdx = *slot;
    *(unsigned int *)(g_currentNodeIdx * 4) = arg;
    g_currentNodeIdx++;
    *slot = g_currentNodeIdx;
}
