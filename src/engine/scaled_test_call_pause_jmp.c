/**
 * Auto-split from misc_matchesI.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00487180 (41b)
 *   mov     eax, [g_baseSel_00542060]
 *   mov     eax, [eax*4 + 0x30]
 *   test    eax, eax
 *   mov     [g_walkCallback], eax
 *   je      +0x0e
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     +5
 *   jmp     T
 *   ret
 */
extern void Wrapper_0048a3a0(void);
extern void CmpJmpTwoBranch_004871d0(void);
void ScaledTestCallPauseJmp_00487180(void) {
    unsigned int v = *(unsigned int *)(g_baseSel_00542060 * 4 + 0x30);
    g_walkCallback = (void (*)(void))v;
    if (v != 0) {
        Wrapper_0048a3a0();
        if (g_framePauseFlag != 0) return;
    }
    CmpJmpTwoBranch_004871d0();
}
