/**
 * 2 "scaled pop + save deref + persist + tail-jmp" helpers (44b).
 *
 * Pattern:
 *   mov     ecx, [g_baseSel_00542060]
 *   mov     eax, [ecx*4 + 4]
 *   dec     eax
 *   mov     [g_scaledInit_00542044], eax     ; save dec'd top
 *   mov     edx, [eax*4 + 0]                 ; deref via SIB+0
 *   mov     [g_scaledInit_00542048], edx     ; save popped element
 *   mov     [ecx*4 + 4], eax                 ; persist new top
 *   jmp     Tail
 */
#include "engine/scenegraph.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;
extern unsigned int g_scaledInit_00542048;

extern void InstallSelfWithStateInit_00438060(void);
extern void MStackPush5Func_0043aa80(void);

/* @addr 0x00438440 */
void ScaledPopSaveJmp_00438440(void) {
    unsigned int idx = g_baseSel_00542060;
    unsigned int n = *(unsigned int *)(idx * 4 + 4) - 1;
    g_scaledInit_00542044 = n;
    g_scaledInit_00542048 = *(unsigned int *)(n * 4);
    *(unsigned int *)(idx * 4 + 4) = n;
    InstallSelfWithStateInit_00438060();
}

/* @addr 0x0043bb20 */
void ScaledPopSaveJmp_0043bb20(void) {
    unsigned int idx = g_baseSel_00542060;
    unsigned int n = *(unsigned int *)(idx * 4 + 4) - 1;
    g_scaledInit_00542044 = n;
    g_walkCallback = (void (*)(void))*(unsigned int *)(n * 4);
    *(unsigned int *)(idx * 4 + 4) = n;
    MStackPush5Func_0043aa80();
}
