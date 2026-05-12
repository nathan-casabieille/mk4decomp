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
extern unsigned int g_baseSel_00542060;   /* 0x00542060 */
extern void func_00472fe0(void);
extern void func_00493ed0(void);

/* @addr 0x00472fc0 */
void ScaledLoadJmp30_00472fc0(void) {
    g_scaledInit_00542044 = *(unsigned int *)(g_eventQueueEnd * 4 + 0x30);
    func_00472fe0();
}

/* @addr 0x00493eb0 */
void ScaledLoadJmp30_00493eb0(void) {
    g_walkCallback = (void (*)(void))*(unsigned int *)(g_baseSel_00542060 * 4 + 0x30);
    func_00493ed0();
}
