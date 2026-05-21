/**
 * Auto-split from misc_matchesP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x0048f8e0 (48b)
 *   mov     eax, [g_baseSel_00542060]
 *   mov     ecx, [eax*4 + 0x3c]
 *   mov     [g_scaledInit_00542044], ecx
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     +0x0f
 *   mov     [g_scaledInit_00542044], 0x0048fa20
 *   jmp     T
 *   ret
 */
extern void Wrapper_0048fbc0(void);
extern void func_00498e3c(void);
void ScaledChainCallPauseSetJmp_0048f8e0(void) {
    g_scaledInit_00542044 = *(unsigned int *)(g_baseSel_00542060 * 4 + 0x3c);
    Wrapper_0048fbc0();
    if (g_framePauseFlag != 0) return;
    g_scaledInit_00542044 = 0x0048fa20;
    func_00498e3c();
}
