/**
 * 2 "scaled-load (offset 0x30) + tail-jmp" wrappers (23 bytes each).
 *
 * Pattern:
 *   mov     eax, [g_A]
 *   mov     ecx, [eax*4 + 0x30]      ; offset 0x30 (vs 0x28 in ScaledLoadJmp)
 *   mov     [g_B], ecx
 *   jmp     Target
 */
#include "engine/scenegraph.h"

extern unsigned int g_scaledInit_00542044;
extern unsigned int g_baseSel;   /* 0x00542060 */
extern void InstallSelfMagicShift(void);
extern void LoadCmpAddrJmp(void);

/* @addr 0x00472fc0 */
void ScaledLoadJmp30_set_g_scaledInit_00542044_then_InstallSelfMagicShift(void) {
    g_scaledInit_00542044 = *(unsigned int *)(g_eventQueueEnd * 4 + 0x30);
    InstallSelfMagicShift();
}

/* @addr 0x00493eb0 */
void ScaledLoadJmp30_set_g_walkCallback_then_LoadCmpAddrJmp(void) {
    g_walkCallback = (void (*)(void))*(unsigned int *)(g_baseSel * 4 + 0x30);
    LoadCmpAddrJmp();
}
